package main

import (
	"bufio"
	"fmt"
	"io"
	"math/rand"
	"os"
	"time"
)

//Suffixes is the data struct that wraps the slice of strings
type Suffixes []string

// Prefix is the data struct that wraps an array of size prefiSize of strings
type Prefix struct {
	vals [prefixSize]string
	size int
}

func (p *Prefix) push(val string) {
	p.vals[p.size] = val
	p.size++
}

func (p *Prefix) pop() {
	if p.size == 2 {
		p.vals[0] = p.vals[1]
		p.vals[1] = ""
	} else if p.size == 1 {
		p.vals[0] = ""
	}
	p.size--
}

const (
	prefixSize = 2
)

var (
	nonWord           = "\n"
	maxGeneratedWords = 10_000
	statemap          = make(map[[prefixSize]string]Suffixes)
)

func main() {
	var prefix Prefix

	for i := 0; i < prefixSize; i++ {
		add(&prefix, nonWord)
	}
	build(&prefix, os.Stdin)
	add(&prefix, nonWord)
	generate(maxGeneratedWords)
}

func add(p *Prefix, s string) {
	if p.size == prefixSize {
		statemap[p.vals] = append(statemap[p.vals], s)
		p.pop()
	}
	p.push(s)
}

func build(p *Prefix, in io.Reader) {
	scanner := bufio.NewScanner(in)
	scanner.Split(bufio.ScanWords)

	for scanner.Scan() {
		w := scanner.Text()
		add(p, w)
	}
}

func generate(words int) {
	var prefix Prefix

	for i := 0; i < prefixSize; i++ {
		add(&prefix, nonWord)
	}

	s := rand.NewSource(time.Now().Unix())
	random := rand.New(s)
	for i := 0; i < words; i++ {
		suf := statemap[prefix.vals]
		r := random.Intn(len(suf))
		w := suf[r%len(suf)]

		if w == nonWord {
			break
		}
		fmt.Printf("%s ", w)
		prefix.pop()
		prefix.push(w)
	}
}

package main

import (
	"fmt"
	"time"
)

func Timed(do func()) time.Duration {
	start := time.Now()
	do()

	return time.Now().Sub(start)
}

func main() {
	duration := Timed(func() {
		fmt.Println("Inside Timed, sleeping for 5 seconds")

		time.Sleep(5 * time.Second)
	})

	fmt.Printf("Execution took %s\n", duration.String())
}

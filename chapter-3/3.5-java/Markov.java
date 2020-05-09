package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.Random;
import java.util.Vector;
import java.util.stream.Collectors;

public class Markov {

    private static final Integer MAX_WORDS = 10_000;

    public static void main(String[] args) throws IOException {
        Chain chain = new Chain();
        chain.build(System.in);
        chain.generate(MAX_WORDS);
    }
}

class Chain {
    private static final Integer PREFIX_SIZE = 2;
    private static final String NON_WORD = "\n";

    private Map<Prefix, Vector<String>> statetab = new HashMap<>();
    private Prefix prefix = Prefix.from(PREFIX_SIZE, NON_WORD);
    private Random rand = new Random();

    public void build(InputStream in) throws IOException {
        Reader r = new BufferedReader(new InputStreamReader(in));
        StreamTokenizer st = new StreamTokenizer(r);

        st.resetSyntax();
        st.wordChars(0, Character.MAX_VALUE);
        st.whitespaceChars(0, ' ');

        while (st.nextToken() != StreamTokenizer.TT_EOF)
            this.add(st.sval);
        this.add(NON_WORD);
    }

    public void generate(int words) {
        this.prefix = Prefix.from(PREFIX_SIZE, NON_WORD);

        for (int i = 0; i < words; i++) {
            Vector<String> s = statetab.get(prefix);
            Integer r = Math.abs(rand.nextInt() % s.size());
            String suf = s.elementAt(r);
            if (suf.equals(NON_WORD))
                break;
            System.out.print(suf + " ");
            prefix.pref[0] = prefix.pref[1];
            prefix.pref[1] = suf;
        }
    }

    public void add(String word) {
        Vector<String> suf = statetab.get(prefix);
        if (suf == null) {
            suf = new Vector<>();
            statetab.put(prefix.clone(), suf);
        }
        suf.addElement(word);
        prefix.pref[0] = prefix.pref[1];
        prefix.pref[1] = word;
    }
}

class Prefix {

    private static final int MULTIPLIER = 31;

    public String[] pref;

    public static Prefix from(Integer size, String value) {
        Prefix p = new Prefix();
        p.pref = new String[size];
        for (int i = 0; i < size; i++)
            p.pref[i] = value;
        return p;
    }

    public Prefix clone() {
        Prefix n = new Prefix();
        n.pref = this.pref.clone();
        return n;
    }

    public int hashCode() {
        int h = 0;
        for (int i = 0; i < pref.length; i++)
            h = MULTIPLIER * h + pref[i].hashCode();
        return h;
    }

    public boolean equals(Object o) {
        Prefix p = (Prefix) o;
        for (int i = 0; i < pref.length; i++)
            if (!this.pref[i].equals(p.pref[i]))
                return false;
        return true;
    }
}
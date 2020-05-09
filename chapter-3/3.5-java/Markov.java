package main;

import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Hashtable;
import java.util.Random;
import java.util.Vector;

public class Markov {
    public static void main(String[] args) throws IOException {
        Chain chain = new Chain();
        chain.build(System.in);
        chain.generate(10000);
    }
}

class Chain {
    private static final int PREFIX_SIZE = 2;
    private static final String NON_WORD = "\n";
    Hashtable statetab = new Hashtable<>();
    Prefix prefix = new Prefix(PREFIX_SIZE, NON_WORD);
    Random rand = new Random();

    public void build(InputStream in) throws IOException {
        StreamTokenizer st = new StreamTokenizer(in);

        st.resetSyntax();
        st.wordChars(0, Character.MAX_VALUE);
        st.whitespaceChars(0, ' ');
        while (st.nextToken() != StreamTokenizer.TT_EOF)
            add(st.sval);
        add(NON_WORD);
    }

    public void generate(int words) {

        this.prefix = new Prefix(PREFIX_SIZE, NON_WORD);
        for (int i = 0; i < words; i++) {
            Vector s = (Vector) statetab.get(prefix);
            int r = Math.abs(rand.nextInt() % s.size());
            String suf = (String) s.elementAt(r);
            if (suf.equals(NON_WORD))
                break;
            System.out.print(suf + " ");
            prefix.pref.removeElementAt(0);
            prefix.pref.addElement(suf);
        }
    }

    public void add(String word) {
        Vector suf = (Vector) statetab.get(prefix);
        if (suf == null) {
            suf = new Vector();
            statetab.put(new Prefix(prefix), suf);
        }
        suf.addElement(word);
        prefix.pref.removeElementAt(0);
        prefix.pref.addElement(word);
    }
}

class Prefix {

    private static final int MULTIPLIER = 31;

    public Vector pref;

    public Prefix(int size, String value) {
        this.pref = new Vector();
        for (int i = 0; i < size; i++)
            this.pref.add(value);
    }

    public Prefix(Prefix p) {
        this.pref = (Vector) p.pref.clone();
    }

    public int hashCode() {
        int h = 0;
        for (int i = 0; i < pref.size(); i++)
            h = MULTIPLIER * h + pref.elementAt(i).hashCode();
        return h;
    }

    public boolean equals(Object o) {
        Prefix p = (Prefix) o;
        for (int i = 0; i < pref.size(); i++)
            if (!pref.elementAt(i).equals(p.pref.elementAt(i)))
                return false;
        return true;
    }
}
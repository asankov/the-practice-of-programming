# markov.pl: markov chain algorithm for 2-word prefixes

$MAXGEN = 10000;
$NONWORD - "\n";
$w1 = $w2 = $NONWORD; # initial state
while (<>) { # read each line of input
    foreach (split) {
        push(@{$statetab{$w1}{$w2}}, $_);
        ($w1, $w2) = ($w2, $_); # multiple assignment
    }
}
push(@{$statetab{$w1}{$w2}}, $NONWORD); # add tail
$w1 = $w2 = $NONWORD;
for ($i = 0; $i < $MAXGEN; $i++) {
    $suf = $statetab{$w1}{$w2}; # array reference
    $r = int(rand @$suf); # @$suf is number of elems
    exit if (($t = $suf->[$r]) eq $NONWORD);
    print "$t ";
    ($w1, $w2) = ($w2, $t); # advance chain
}
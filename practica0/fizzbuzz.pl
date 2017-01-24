#!/usr/bin/perl

for ($n=1;$n<=30;$n++) {
    !($n%3) ? print "Fizz":1;
    !($n%5) ? print "Buzz":1;
    (($n%3) && ($n%5)) ? print $n : 1;
    print "\n";
}

#!/usr/bin/env perl

open(DICT, "words") || die "Can't open the dictionary";

while(<DICT>)
	{
	chomp($word = $_);
	push(@{$wordHash{join('', sort split(//, $word))}}, $word);
	}

close(DICT);

foreach $key (sort keys %wordHash)
	{
	if($#{$wordHash{$key}} > 2)
		{
		print "$key\t=>\t", join(', ', @{$wordHash{$key}}), "\n";
		}
	}

anagram
=======

Examples of discovering anagrams in a dictionary, using various programming
languages.  The script run_all.sh executes all tests including timings.
For non-compiled languages it adds the overhead of launching a virtual machine
or an interpreter.

These results were produced on my old Centos box with:
	AMD Athlon(tm) XP 1800+
	1 GB RAM

The following command will run all language tests:
bash -x run_all.sh &> anagram.log


+ echo '### testing Ruby #######################'  
### testing Ruby #######################  
+ ruby anagram.rb  
aaclrs	=>	lascar, rascal, sacral, scalar  
abet	=>	abet, bate, beat, beta  
acert	=>	caret, carte, cater, crate, trace  
aeglr	=>	glare, lager, large, regal  
aelmnt	=>	lament, mantel, mantle, mental  
aelp	=>	leap, pale, peal, plea  
aelpt	=>	leapt, petal, plate, pleat  
aelst	=>	least, slate, stale, steal  
aemn	=>	amen, mane, mean, name  
aemt	=>	mate, meat, tame, team  
aepr	=>	pare, pear, rape, reap  
aet	=>	ate, eat, eta, tea  
ceersu	=>	cereus, recuse, rescue, secure  
deit	=>	diet, edit, tide, tied  
eilv	=>	evil, live, veil, vile  
eimt	=>	emit, item, mite, time  
einrs	=>	resin, rinse, risen, siren  
eiprst	=>	esprit, priest, sprite, stripe  
  
real	0m2.575s  
user	0m2.402s  
sys	0m0.038s  
+ echo '### testing Perl #######################'  
### testing Perl #######################  
+ perl anagram.pl  
aaclrs	=>	lascar, rascal, sacral, scalar  
abet	=>	abet, bate, beat, beta  
acert	=>	caret, carte, cater, crate, trace  
aeglr	=>	glare, lager, large, regal  
aelmnt	=>	lament, mantel, mantle, mental  
aelp	=>	leap, pale, peal, plea  
aelpt	=>	leapt, petal, plate, pleat  
aelst	=>	least, slate, stale, steal  
aemn	=>	amen, mane, mean, name  
aemt	=>	mate, meat, tame, team  
aepr	=>	pare, pear, rape, reap  
aet	=>	ate, eat, eta, tea  
ceersu	=>	cereus, recuse, rescue, secure  
deit	=>	diet, edit, tide, tied  
eilv	=>	evil, live, veil, vile  
eimt	=>	emit, item, mite, time  
einrs	=>	resin, rinse, risen, siren  
eiprst	=>	esprit, priest, sprite, stripe  
  
real	0m0.734s  
user	0m0.693s  
sys	0m0.028s  
+ echo '### testing Java #######################'  
### testing Java #######################  
+ java anagram  
aelmnt	=>	 lament mantel mantle mental  
aaclrs	=>	 lascar rascal sacral scalar  
abet	=>	 abet bate beat beta  
aepr	=>	 pare pear rape reap  
aelp	=>	 leap pale peal plea  
aemt	=>	 mate meat tame team  
aemn	=>	 amen mane mean name  
eimt	=>	 emit item mite time  
eilv	=>	 evil live veil vile  
aelpt	=>	 leapt petal plate pleat  
ceersu	=>	 cereus recuse rescue secure  
aelst	=>	 least slate stale steal  
eiprst	=>	 esprit priest sprite stripe  
deit	=>	 diet edit tide tied  
aeglr	=>	 glare lager large regal  
aet	=>	 ate eat eta tea  
acert	=>	 caret carte cater crate trace  
einrs	=>	 resin rinse risen siren  
  
real	0m0.687s  
user	0m0.570s  
sys	0m0.066s  
+ echo '### testing C++ ########################'  
### testing C++ ########################  
+ ./anagram.g++  
aaclrs	=>	 lascar rascal sacral scalar  
abet	=>	 abet bate beat beta  
acert	=>	 caret carte cater crate trace  
aeglr	=>	 glare lager large regal  
aelmnt	=>	 lament mantel mantle mental  
aelp	=>	 leap pale peal plea  
aelpt	=>	 leapt petal plate pleat  
aelst	=>	 least slate stale steal  
aemn	=>	 amen mane mean name  
aemt	=>	 mate meat tame team  
aepr	=>	 pare pear rape reap  
aet	=>	 ate eat eta tea  
ceersu	=>	 cereus recuse rescue secure  
deit	=>	 diet edit tide tied  
eilv	=>	 evil live veil vile  
eimt	=>	 emit item mite time  
einrs	=>	 resin rinse risen siren  
eiprst	=>	 esprit priest sprite stripe  
  
real	0m0.147s  
user	0m0.131s  
sys	0m0.016s  

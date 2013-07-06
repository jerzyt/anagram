#!/bin/bash

# run as:
# bash -x run_all.sh &> anagram.log
# to capture output with the timings

echo "### testing Ruby #######################"
time ruby anagram.rb
echo "### testing Perl #######################"
time perl anagram.pl
javac anagram.java
echo "### testing Java #######################"
time java anagram
g++ -O5 -o anagram.g++ anagram.cc
echo "### testing C++ ########################"
time ./anagram.g++

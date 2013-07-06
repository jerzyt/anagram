#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

//	compile command: g++ -O5 -o anagram.g++ anagram.cc

using namespace std;

const size_t minAnagramCnt = 3;

typedef set<string, less<string> > SetOfStrings;
typedef map<string, SetOfStrings, less<string> > Map_String_SetOfStrings;

int main()
	{
	unsigned wordCnt = 0u;
	string word;
	Map_String_SetOfStrings mapOfWords;
	ifstream inFile("words");

	if(!inFile)
		{
		cerr << "Failed to open the dictionary" << endl;
		exit(1);
		}

	while(inFile >> word)
		{
		string sortedWord = word;
		++wordCnt;
		sort(sortedWord.begin(), sortedWord.end());
		mapOfWords[sortedWord].insert(word);
		}

	for(Map_String_SetOfStrings::iterator j = mapOfWords.begin(); j != mapOfWords.end(); ++j)
		{
		SetOfStrings anagramsSet = (*j).second;

		if(anagramsSet.size() > minAnagramCnt)
			{
			cout << (*j).first << "\t=>\t";

			for(SetOfStrings::iterator k = anagramsSet.begin(); k != anagramsSet.end(); ++k)
				cout << " " << *k;
			cout << endl;
			}
		}

	return(0);
	}

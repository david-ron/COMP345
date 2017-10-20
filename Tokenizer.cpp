/*
 * tokenizer.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: David
 */

#include "tokenizer.h"

/*!
 *default constructor
 */
Tokenizer::Tokenizer(){
	fileName = "";
}
/*!
 *
 * @param fileName
 */
Tokenizer::Tokenizer(string fileName){
	this->fileName = fileName;
}
/*!
 *
 * @param word
 * @return
 */
vector<string> Tokenizer::stringTokenize(string word)
{
	//supposed to tokenize for ws
	vector<string> words;
	return words;
}
/*!
 *
 * @return
 */
vector<string> Tokenizer::tokentoDocument(){

	ifstream ifs(fileName);
	    string word;
	    string newWord;
	    vector<string> v2;
	    if(!ifs){
	        cerr << "Error! File not Found" << endl;
	    }
	    while(ifs>>word){
	        newWord = "";
	        remove_copy_if(word.begin(), word.end(),
	                       back_inserter(newWord),
	                       ptr_fun<int, int>(ispunct));

	        //Algorithm that converts everything to lower case
	        transform(newWord.begin(), newWord.end(), newWord.begin(),::tolower);

	        v2.push_back(newWord); //pushes in the fixed words into a vector passed by user.
	    }

	    return v2;
}
vector<string> Tokenizer::removeSpace (string  s) {

vector<string> tokens;
int i = 0;
int j = 0;

while (i != s.size() && j != s.size()) {

    while (i != s.size() && isspace(s[i])){
        ++i;
        j = i;
    }
    while (j != s.size() && !isspace(s[j])) {
        j++;
    }

    if (i != j) {
        tokens.push_back(s.substr(i, j - i));
        i = j;
    }
}
return tokens;
}

/*
 * sentence.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */
#include "sentence.h"

sentence::sentence():index_item(){
	pos = -1;
}
sentence::sentence(string sent,int npos):index_item(){
	sentence_token t = sentence_token();
	sentenceTokens = t.removeSpace(sent);
	for(unsigned int i = 0 ; i<sentenceTokens.size();++i){
	senWords[sentenceTokens[i]]=(senWords[sentenceTokens[i]]+1);}
	setSize(sentenceTokens.size());
	pos = npos;
}
void sentence::setSize(int size){
	size = sentenceTokens.size();
}
int sentence::getPos(){
	return 1;
}
unordered_map<string,int> sentence::getMap(){
	return senWords;
}
vector<string> sentence::getTokens(){

	return sentenceTokens;
}
string sentence::getSen(){
	return sen;
}


/*
 * sentence_indexer.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: David
 */

#include "sentence_indexer.h"
sentence_indexer & operator >> (sentence_indexer & left,string right)
{
sentence_token t = sentence_token(right);
	vector<string> tmpsentences;
	tmpsentences=t.sentencetoken();
	for(unsigned int i= 0; i <tmpsentences.size();++i){
		sentence tmp = sentence(tmpsentences[i],t.getPos()[i]);
	left.sentenceObj.push_back(tmp);
	}

	left.docCount++;
	return left;
}
sentence_indexer::sentence_indexer():docCount(0){}

void sentence_indexer::normalize()
{

}

vector<double> sentence_indexer::score(){
	vector<double> tmp;
	tmp.push_back(1.);
	return tmp;
}

void sentence_indexer::print(){
	for(unsigned int j = 0; j<sentenceObj.size();++j){
for(unsigned int i = 0; i<sentenceObj[j].getTokens().size();++i){
cout<<sentenceObj[j].getTokens()[i]<< "  ";}
	cout<<"\n";}
}
vector<query_result> sentence_indexer::query(string str, int x){
 vector<query_result> tmp;
 return tmp;
}

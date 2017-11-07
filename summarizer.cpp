/*
 * summarizer.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */

#include "sentence_indexer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	sentence_indexer t = sentence_indexer();
	t>>"FT923-5715";
	t.print();


//	sentence_token *pt = new sentence_token("q1.txt");
//	vector<string> test;
//
//	test= pt->sentencetoken();
//	vector<string> stringToken;
//	for(unsigned int i = 0 ;i<test.size();++i ){
//		stringToken = pt->removeSpace(test);
//
//	}
//	for(unsigned int i = 0 ; i<stringToken.size();++i){
//	cout<<stringToken[i]<<endl;}
	return 0;
}


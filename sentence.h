/*
 * sentence.h
 *
 *  Created on: Nov 5, 2017
 *      Author: David
 */

#ifndef SENTENCE_H_
#define SENTENCE_H_

#include "index_item.h"
#include "sentence_token.h"
#include "unordered_map"
class sentence : public index_item{
public:
	sentence();
	sentence(string sent,int pos);
    void setSize(int newsize);
    int getPos();
    vector<string> getTokens();
    unordered_map<string,int> getMap();
    string getSen();
private:
    string sen;
    unordered_map<string,int> senWords;
    int pos;
    vector<string> sentenceTokens;


};




#endif /* SENTENCE_H_ */

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
	sentence(vector<string> sent,int pos);
    void setSize(int newsize);
    int getPos();
private:
    vector<string> sen;
    unordered_map<string,int> senWords;
    int pos;


};




#endif /* SENTENCE_H_ */

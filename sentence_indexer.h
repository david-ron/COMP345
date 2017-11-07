/*
 * sentence_indexer.h
 *
 *  Created on: Nov 6, 2017
 *      Author: David
 */

#ifndef SENTENCE_INDEXER_H_
#define SENTENCE_INDEXER_H_
#include "sentence.h"
#include "index_item.h"
#include "index.h"

class sentence_indexer : public index{
	 friend sentence_indexer & operator >>(sentence_indexer & left, string right);
//	 friend sentence_indexer & operator <<(ostream & os , sentence_indexer & right);
public:
	sentence_indexer();
	void normalize();
	vector<double> score();
	void print();
	vector<query_result> query(string str, int x);
	index_item* operator[](int i);
private:
	vector<sentence> sentenceObj;
	vector<string> sentences;
	int docCount;
};




#endif /* SENTENCE_INDEXER_H_ */

/*
 * indexer.h
 *
 *  Created on: Oct 15, 2017
 *      Author: David
 */

#ifndef INDEXER_H_
#define INDEXER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>

#include "document.h"
#include "query_result.h"

class indexer{
	friend std::ostream & operator<<(std::ostream & os,
			indexer & idx);
	friend indexer & operator>>(indexer & left, document & right);

private:
    int docCount; //Document Count
    //Similar to our matrix in part 1 holds document that holds tokens of words
    vector<document> indexe;
    // to make our 2d matrix of frequency from part 1
    vector<vector<int>> tf;
    vector<int> df;
    vector<vector<double>> tf_idf_weights;
    document dictionary;
public:
    const document & operator[](const int i);
    indexer();
    int mySize(); //Returns number of documents
    void normalize(); //computes the tf-idf weights based on number of documents
//    to be implemented
//    vector<Query_result> query(string, int);
    void dftfFinder(document & dictionary);
    // not sure where to place this
    void dictionaryCreation();
    query_result & query(string str, int mode = 10);
    void indexer::dftfFinder(vector<string> str);

};

#endif /* INDEXER_H_ */

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
#include <complex>

#include "document.h"
#include "query_result.h"

class indexer{
    friend std::ostream & operator<<(std::ostream & os,
                                     indexer & idx);
    friend indexer & operator>>(indexer & left, Document & right);

private:
    double docCount; //Document Count
    //Similar to our matrix in part 1 holds document that holds tokens of words
    vector<Document> indexe;
    // to make our 2d matrix of frequency from part 1
    vector<vector<double>> tf;
    vector<double> df;
    vector<vector<double>> tf_idf_weights;
    vector<double> tfquery;
    vector<double> tfquery_idf_weight;
    Document dictionary;
public:
    const Document & operator[](const int i);
    indexer();
    int mySize(); //Returns number of documents
    void normalize(); //computes the tf-idf weights based on number of documents
//    to be implemented
//    vector<Query_result> query(string, int);
    void dftfFinder(Document & dictionary);
    // not sure where to place this
    void dictionaryCreation();
    vector<query_result> & query(string str, int mode = 10);
    vector<int> getdf();
    void normalizequery();
    void querytfFinder(vector<string> str);
    void indexDictionary(Document & diction);
    void print(Document & dictionary);
    void score();
};

#endif /* INDEXER_H_ */

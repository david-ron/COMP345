/*
 * document.h
 *
 *  Created on: Oct 13, 2017
 *      Author: David
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "tokenizer.h"
using namespace std;



class document {
friend std::ostream & operator<<(std::ostream & os,
		document & d);
private:
	vector<string> fileTokens;
	long fileSize;
	string fileName;
	long findSize();
public:

	document();
	document(string fileName);
	string name();
	int size();
	vector<string> content();
	//will return output stream saying if null or not
	void toCreateDictionary(document & doc);

    void duplicateRemove();
    void sorting();
};
#endif /* DOCUMENT_H_ */

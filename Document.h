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
#include <unordered_map>

#include "tokenizer.h"
using namespace std;



class Document {
friend std::ostream & operator<<(std::ostream & os,
		Document & d);
private:
	vector<string> fileTokens;
	long fileSize;
	string fileName;
	long findSize();
	vector<string> filtedTokens;
	double score;
	unordered_map<string,int> tokenMap;
public:
	Document();
	Document(string fileName);
	string name();
	int size();
	vector<string> content();
	//will return output stream saying if null or not
	void toCreateDictionary(Document & doc);
	void sorting();
	void duplicateRemove();

	void changeContent(vector<string> words);
	unordered_map<string,int> getMap();
	void compare(Document &dict);
	bool scorecomp(const Document &  left, const Document & right);

};
#endif /* DOCUMENT_H_ */

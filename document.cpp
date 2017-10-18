/*
 * document.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: David
 */

# include "document.h"

	document::document(){
		fileName = "";
		fileSize = -1;
	}

	document::document(string fileName){
		this->fileName = fileName;
		tokenizer *t = new tokenizer(fileName);

		fileTokens = t->tokentoDocument();
		sort(fileTokens.begin(), fileTokens.end());
		fileSize = findSize();
	}
	string document::name(){
		return fileName;
	}
	long document::findSize()
	{
	    long count=0;
	    for (unsigned int i = 0; i < fileTokens.size(); ++i) {
	        for (unsigned int j = 0; j < fileTokens[i].size(); ++j) {
	        	fileTokens[i].at(j); //Iterates through every character
	            count++; //keeps track of number of chars
	        }
	    }
	    return count;
	}
	vector<string> document::content(){
		return fileTokens;
	}
	void document::sorting()
	{
		sort(fileTokens.begin(), fileTokens.end());
	}
	void document::duplicateRemove()
	{
		 vector <string> fixedDictionary;
		    for (unsigned int i = 0; i < fileTokens.size()-1; ++i) {
		        if(fileTokens[i]==fileTokens[i+1]){

		        }
		        else
		            fixedDictionary.push_back(fileTokens[i]);
		    }
		    fileTokens = fixedDictionary;
	}
	void document::toCreateDictionary(document & doc)
	{
		vector<string> words = doc.fileTokens;
		for (unsigned int i = 0; i < words.size(); ++i)
		{
					fileTokens.push_back(words[i]);
		}
	}
	int document::size()
	{
		return fileSize;
	}
	void document::changeContent(vector<string> words){
		fileTokens = words;
	}
	ostream & operator << (ostream & os, document & d)
	{
	if(d.fileSize==-1)
	{
		os<<"error size seems to not be initialized "<<"\n";
	}
	else if(d.fileName=="")
	{
		os<<"seems like there is no file name !!!! :O";
	}
	os<<d.fileSize<< " is the amount of characters in this document\n";
	for ( vector<string>::iterator it = d.fileTokens.begin();it != d.fileTokens.end(); ++it )
	        {
	           os<<*it<<"\n";
	        }
	return os;
	}

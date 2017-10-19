/*
 * document.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: David
 */

# include "document.h"

/*!
 *default constructor
 */
	document::document(){
		fileName = "";
		fileSize = -1;
	}
/*!
 *
 * @param fileName
 * constructor that takes a string as parameter and returns a document
 */
	document::document(string fileName){
		this->fileName = fileName;
		tokenizer *t = new tokenizer(fileName);

		fileTokens = t->tokentoDocument();
		sort(fileTokens.begin(), fileTokens.end());
		fileSize = findSize();
	}
/*!
 *
 * @return
 * returning files name
 */
	string document::name(){
		return fileName;
	}
/*!
 *
 * @return
 */
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
/*!
 *
 * @return
 */
	vector<string> document::content(){
		return fileTokens;
	}
/*!
 *
 */
	void document::sorting()
	{
		sort(fileTokens.begin(), fileTokens.end());
	}
/*!
 *
 */
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
/*!
 *
 * @param doc
 */
	void document::toCreateDictionary(document & doc)
	{
		vector<string> words = doc.fileTokens;
		for (unsigned int i = 0; i < words.size(); ++i)
		{
					fileTokens.push_back(words[i]);
		}
	}
/*!
 *
 * @return
 */
	int document::size()
	{
		return fileSize;
	}
/*!
 *
 * @param words
 */
	void document::changeContent(vector<string> words)
	{
		fileTokens = words;
	}


vector<string> document::compare(document & dict){

vector<string> tmp = dict.content();
bool duplicated = false;

for (unsigned int i =0; i<dict.size(); ++i) {
    for (unsigned int j = 0; j < fileTokens.size(); ++j) {

        if (tmp[i] == fileTokens[j]) {
            duplicated = true;
        }
    }
    if (duplicated == false)
    {
        filtedTokens.push_back(tmp[i]);
    }
    duplicated = false;
}
return filtedTokens;
}

/*!
 *
 * @param os
 * @param d
 * @return
 */
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

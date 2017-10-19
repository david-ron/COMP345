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
	Document::Document(){
		fileName = "";
		fileSize = -1;
	}
/*!
 *
 * @param fileName
 * constructor that takes a string as parameter and returns a document
 */
	Document::Document(string fileName){
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
	string Document::name()
	{
		return fileName;
	}
/*!
 *
 * @return
 */
	long Document::findSize()
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
	vector<string> Document::content(){
		return fileTokens;
	}
/*!
 *
 */
	void Document::sorting()
	{
		sort(fileTokens.begin(), fileTokens.end());
	}
/*!
 *
 */
	void Document::duplicateRemove()
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
	void Document::toCreateDictionary(Document & doc)
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
	int Document::size()
	{
		return fileSize;
	}
/*!
 *
 * @param words
 */
	void Document::changeContent(vector<string> words)
	{
		fileTokens = words;
	}


void Document::compare(Document & dict){

    vector<string> olddict = dict.content();

    bool duplicated = false;
    for (unsigned int i = 0; i < olddict.size(); ++i) {
        for (unsigned int j = 0; j < fileTokens.size(); ++j) {
            if(olddict[i]==fileTokens[j]){
                duplicated = true;
            }
        }
        if (duplicated==false)
            fileTokens.push_back(olddict[i]);

        //Resest
        duplicated = false;
}

}

/*!
 *
 * @param os
 * @param d
 * @return
 */
ostream & operator << (ostream & os, Document & d)

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

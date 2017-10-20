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
		Tokenizer *t = new Tokenizer(fileName);

		fileTokens = t->tokentoDocument();
		sort(fileTokens.begin(), fileTokens.end());
		fileSize = findSize();
	}
/*!
 *
 * @return stirng
 * returning files name
 */
	string Document::name()
	{
		return fileName;
	}
/*!
 *
 * @return long
 * Find and return the size of a document
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
 * @return vector<string>
 * return the content of a given document
 */
	vector<string> Document::content(){
		return fileTokens;
	}
/*!
 *sorting method
 */
	void Document::sorting()
	{
		sort(fileTokens.begin(), fileTokens.end());
	}
/*!
 *removing the duplicate from a document
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
 * Creation of the fileTokens vector string of a document.
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
 * return the size of a document
 */
	int Document::size()
	{
		return fileSize;
	}
/*!
 *
 * @param words
 * Changing the content of a document using a given vector string
 */
	void Document::changeContent(vector<string> words)
	{
		fileTokens = words;
	}

/*!
 *
 * @param dict
 * Method that modify a document vector string according to the stopword file
 */
void Document::compare(Document & dict){

    vector<string> olddict = dict.content();
    vector<string> newdict;
    bool duplicated = false;
    for (unsigned int i = 0; i < olddict.size(); ++i) {
        for (unsigned int j = 0; j < fileTokens.size(); ++j) {
            if(olddict[i]==fileTokens[j]){
                duplicated = true;
            }
        }
        if (duplicated==false)
            newdict.push_back(olddict[i]);

        //Resest
        duplicated = false;
}
    fileTokens = newdict;
}

/*!
 *
 * @param os
 * @param d
 * @return
 * taking in ostream and a document
 * Overload of the operator <<
 * Output and appropriate message if the given document is not initialized properly.
 * Else, it displays the amount of characters in the document and its content.
 */
ostream & operator << (ostream & os, Document & d)

{
if(d.fileSize==-1)
{
os<<"Error, size seems to not be initialized."<<"\n";
}
else if(d.fileName=="")
{
os<<"Error, name seems to not be initialized.";
}
os<<d.fileSize<< " is the amount of characters in this document\n";
for ( vector<string>::iterator it = d.fileTokens.begin();it != d.fileTokens.end(); ++it )
    {
       os<<*it<<"\n";
    }
return os;
}

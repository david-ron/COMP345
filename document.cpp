/*
 * document.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: David
 */

# include "document.h"
//Default Constructor
document::document(){
    fileName = "";
    fileSize = -1;
}
//Parametrized Constructor
document::document(string fileName){
    this->fileName = fileName;
    tokenizer *t = new tokenizer(fileName);

    fileTokens = t->tokentoDocument();
    sort(fileTokens.begin(), fileTokens.end());
    fileSize = findSize();
}
//Function that returns the name
string document::name(){
    return fileName;
}
//Function that returns the size
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
//Function that returns the fileTokens vector
vector<string> document::content(){
    return fileTokens;
}

//Sorts the file tokens
void document::sorting()
{
    sort(fileTokens.begin(), fileTokens.end());
}
//Remove duplicates from file tokens
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

//pushes to the document elements
void document::toCreateDictionary(document & doc)
{
    vector<string> words = doc.fileTokens;
    for (unsigned int i = 0; i < words.size(); ++i)
    {
        fileTokens.push_back(words[i]);
    }
}

//returns file size
int document::size()
{
    return fileSize;
}

//An operator that checks if the name and size have been initialized
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

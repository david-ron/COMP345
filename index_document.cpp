//
// Created by Dabu on 2017-11-04.
//

#include "index_document.h"


/*!
 *default constructor
 */
index_document::index_document(): index_item(){
    score=0;
    fileName="";
    fileSize =-1 ;
}
index_document::~index_document(){}
/*!
 *
 * @param fileName
 * constructor that takes a string as parameter and returns a document
 */
index_document::index_document(string fileName){
    this->fileName = fileName;
    word_tokenizer *t = new word_tokenizer(fileName);
    fileTokens = t->tokentoDocument();
    sort(fileTokens.begin(),fileTokens.end());
    string tmpword =""; // needs a custom (private function to clean up :))
    int ctr=1;
    for(vector<string>::iterator it = fileTokens.begin(); it != fileTokens.end();++it)
    {
        if(*it==tmpword){
            ctr++;
            tokenMap.insert(make_pair(*it,ctr));
        }
        else{
            tmpword = *it;
            tokenMap.insert(make_pair(*it,ctr));
            ctr = 1;
        }
    }
    this->setSize(findSize());
}
/*!
 *
 * @return
 */
string index_document::name()
{
    return fileName;
}
/*!
 *
 * @return
 */
long index_document::findSize()
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
vector<string> index_document::content(){
    return fileTokens;
}
/*!
 *
 */
void index_document::sorting()
{
    sort(fileTokens.begin(), fileTokens.end());
}
/*!
 *
 */
void index_document::duplicateRemove()
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
void index_document::toCreateDictionary(index_document & doc)
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

/*!
 *
 * @param words
 */
void index_document::changeContent(vector<string> words)
{
    fileTokens = words;
}
unordered_map<string,int> index_document::getMap(){
    return tokenMap;
}

void index_document::compare(index_document & dict){

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
 */
ostream & operator << (ostream & os, index_document & d)

{
    if(d.getSize()==-1)
    {
        os<<"error size seems to not be initialized "<<"\n";
    }
    else if(d.fileName=="")
    {
        os<<"seems like there is no file name !!!! :O";
    }
    os  <<  d.getSize() << " is the amount of characters in this document\n";
    for ( vector<string>::iterator it = d.fileTokens.begin();it != d.fileTokens.end(); ++it )
    {
        os<<*it<<"\n";
    }
    return os;
}





//============================================================================
// Name        : indexer.cpp
// Author      : David Ronci
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "indexer.h"
indexer::indexer()
{
	docCount = 0;
}
int indexer::mySize()
{
	return docCount;
}
// needs logic df temporary equation to show how it may look like
//void indexer::normalize()
//{
//	int i=0,j=0;
//	double  tf_idf_weight;
//	int tf1 = tf[i][j];
//	int df1 = df[i];
//	tf_idf_weight = (1 + log(tf1) * log(docCount/df1));
//	tf_idf_weight = log(1);
//}

//Overload operator that pushes the documents into the index object
indexer & operator >> (indexer & left,document & right)
{
	left.indexe.push_back(right);
	left.docCount++;
	return left;
}

//Overload operator that checks if the size and name have been initialized once a document is created
ostream & operator << (ostream & os, indexer & idx)
{
	if(idx.indexe[1].size()==-1)
	{
		os<<"error size seems to not be initialized "<<"\n";
	}
	else if(idx.indexe[1].name()=="")
	{
		os<<"seems like there is no file name !!!! :O";
	}
	os<<idx.indexe[1].size()<< " is the amount of characters in this document\n";
	vector<string> tmpfile ;
	tmpfile = idx.indexe[1].content();
	for ( vector<string>::iterator it = tmpfile.begin();it != tmpfile.end(); ++it )
	{
		os<<*it<<"\n";
	}
	return os;
}

//Overload operator allows access to a document of an index
const document & indexer::operator[](const int i)
{
	return indexe[i];
}

//Calculates the termFrequency and documentFrequency
void indexer::dftfFinder(document & dictionary)
{
	int count=0;
	vector<int> counter;
	vector<int> empty;
	vector<string> diction = dictionary.content();
	vector<string> temp;
	for(unsigned int n0=0; n0 < indexe.size(); ++n0) {
		for (unsigned int n1 = 0; n1 < diction.size(); ++n1) {
			temp = indexe[n0].content();
			for (unsigned int n2 = 0; n2 < temp.size(); ++n2) {

				if (diction[n1] == temp[n2])
				{
					++count;
				}
			}
			counter.push_back(count);
			count = 0;
		}
		tf.push_back(counter);
		counter = empty;
	}
	int x = 0;
	for(unsigned int j=0; j<tf.size()-1;++j)
	{
		if(tf[j][0]==tf[j+1][1])
		{
			count++;
		}
		df.push_back(count);
		count = 0;
	}

	for(unsigned int i=0; i<tf[x].size();++i)
	{
		for(unsigned int j=0; j<tf.size();++j){
			if(tf[j][i] > 0)
			{
				count++;
			}
		}
		df.push_back(count);
		count = 0;
	}
}

//Prints out the documents along with the their frequencies
void indexer::print(document & dictionary) {

	string longWord;
	int longWordNum;

	string tempLong="";
	for (unsigned int i = 0; i < dictionary.content().size(); ++i) {
		if( dictionary.size() > tempLong.size())
		{
			tempLong = dictionary.content()[i];
		}

		longWord = tempLong;
		longWordNum = longWord.size();
	}


	string tmd ="DOC";
	string temps="";
	cout<<setw(longWordNum + 20) << "" <<" ";
	for (unsigned int a =0; a <tf.size(); ++a){
		temps= to_string(a);
		tmd = tmd + temps;
		cout << left << setw(longWordNum + 20) << tmd;
		tmd="DOC";
	}

	cout<<endl;

	cout<< "Dictionary";

	for (unsigned int k = 0; k < tf.size(); ++k) {

		if (k == 0) {
			cout << left << setw(longWordNum + 10) << "" << "TF";
			cout << left << setw(3) << "" << "DF";
		} else {
			cout << left << setw(19) << "" << "TF";
			cout << left << setw(3) << "" << "DF";
		}
	}


	cout<<endl;

	for (unsigned int i = 0; i < dictionary.content().size(); ++i) {

		for (unsigned int j = 0; j < tf.size(); ++j) {

			if(j==0)
				cout << left << setw(longWordNum + 20) << dictionary.content()[i] <<  "" << tf[j][i] << "    " <<  df[i] << setw(20) <<  "" << "";
			else{
				cout << "" << tf[j][i] << "    " << df[i] << setw(20) <<  "" <<  "";
			}


		}
		cout<<endl;

	}
}


int main() {
	document *doc1 = new document("file1.txt");

	document *doc0 = new document("file2.txt");
	document *doc2 = new document("file3.txt");

	indexer idx = indexer();
	idx>>*doc1;
	idx>>*doc0;
	idx>>*doc2;

	document *dictionary = new document();

	document *doc = new document();

	int i = 1;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);

	i = 0;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);

	i = 2;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);

	dictionary->sorting();
	dictionary->duplicateRemove();

	idx.dftfFinder(*dictionary);

	idx.print(*dictionary);

	//cout<<*dictionary;
	return 0;
}

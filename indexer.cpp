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
/*!
 *default constructor
 */
indexer::indexer()
{
	docCount = 0;
}
/*!
 *
 * @return
 */
int indexer::mySize()
{
	return docCount;
}
/*!
 *
 */
void indexer::normalize()
{
	int i=0,j=0;
	double weight;
	vector<double> d_weight;
	for(unsigned int i=0; i<tf[0].size();++i)
	{
		for(unsigned int j=0; j<tf.size();++j){
	int ttf = tf[j][i];
	int tdf = df[i];
	weight = (1 + log(ttf) * log(docCount/tdf));
	d_weight.push_back(weight);
		}
		tf_idf_weights.push_back(d_weight);
	}
}

/*!
 *
 * @param left
 * @param right
 * @return
 */
indexer & operator >> (indexer & left,document & right)
{
	left.indexe.push_back(right);
	left.docCount++;
	return left;
}

/*!
 *
 * @param os
 * @param idx
 * @return
 */
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

/*!
 *
 * @param i
 * @return
 */
const document & indexer::operator[](const int i)
{
	return indexe[i];
}

/*!
 *
 * @param dictionary
 */
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

	for(unsigned int i=0; i<tf[0].size();++i)
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

/*!
 *
 * @param str
 */
void indexer::dftfFinder(vector<string> str)
{
	int count=0;
	vector<int> counter;
	vector<int> empty;
	vector<string> diction = str;
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

	for(unsigned int i=0; i<tf[0].size();++i)
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
/*!
 *
 * @param str
 * @param mode
 * @return
 */

query_result & indexer::query(string str, int mode = 10) {
	vector<string> words;
	query_result qr = query_result();

	return query_result;
}

/*!
 *
 * @param dictionary
 */
void indexer::print(document & dictionary) {
	int x=0;
	for (unsigned int i = 0; i < dictionary.content().size(); ++i) {
		for (unsigned int j = 0; j < dictionary.content().size()-1; ++j) {

			cout << left << setw(10) << dictionary.content()[j+i] << tf[i+1][j];
			cout << left  << setw(10) << tf[i][j];
			cout<<endl;
		}
	}

}

int main() {
	document *doc1 = new document("file1.txt");
	vector<string> dummy;
	dummy = doc1->content();
	document *doc0 = new document("file2.txt");
	indexer idx2 = indexer();
	indexer idx = indexer();
	idx>>*doc0;
	idx>>*doc1;
	int i = 1;
	document *dictionary = new document();
	document *doc = new document();
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);
	i = 0;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);
	dictionary->sorting();
	dictionary->duplicateRemove();

	idx.dftfFinder(*dictionary);

	idx.normalize();
	idx.query("josh");

	idx.print((*dictionary));

	cout<<"stopwords printing"<<endl;
	document *docStop = new document ("stop.txt");
	indexer idxStop = indexer();
	idxStop >> *docStop;
	int j = 1;
	document *stopDict = new document ();

	stopDict->compare(dictionary,docStop->content() );
	stopDict->sorting();
	stopDict->duplicateRemove();

	idx.dftfFinder(*stopDict);
	idx.print(*stopDict);

	return 0;
}
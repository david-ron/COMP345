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
	cout<<df.size()<< "  ";
	cout<<tf[0].size();
	cout<<"\n \n \n";
	double tempidf = 0;
	double temptf = 0;
	float weight = 0.00;
	vector<double> d_weight;
	vector<double> empty;
	double doc = (double)(docCount);
	vector<string> diction = dictionary.content();
	for(unsigned int i=0; i<tf[0].size();++i)
	{
		for(unsigned int j=0; j<tf.size();++j)
		{
			double ttf = (double)(tf[j][i]);
			if(ttf != 0)
			{
				tempidf = log(doc/df[i]);
				temptf = (1+log((double)tf[j][i]));
				cout<<temptf*tempidf<<" tf is  "<<tf[j][i]<<endl;
				weight = tempidf*temptf;
				if(weight<=0.01||weight>5)
				{
					d_weight.push_back(0);
				}
				else
				{
					d_weight.push_back( floorf(weight * 100) / 100);
				}

			}
			else
			{
				cout<<0<<" tf is  "<<tf[j][i]<<endl;
				d_weight.push_back(0);
			}
		}
		tf_idf_weights.push_back(d_weight);
		d_weight = empty;
	}
//	for(unsigned int i=0; i<tf.size();++i)
//	{
//		for(unsigned int j=0; j<tf[0].size();++j)
//		{
//			if(tf_idf_weights[j][i]<0.001||tf_idf_weights[j][i]>5){
//			tf_idf_weights[j][i]=0;}
//			else{
//
//			}
//		}
//		}
	for(unsigned int i=0; i<tf.size();++i)
		{
			for(unsigned int j=0; j<tf[0].size();++j)
			{

				cout<<tf_idf_weights[i][j]<< "  ";
			}	cout<<endl;
			}

}

/*!
 *
 * @param left
 * @param right
 * @return
 */
indexer & operator >> (indexer & left,Document & right)
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
const Document & indexer::operator[](const int i)
{
	return indexe[i];
}

/*!
 *
 * @param dictionary
 */
void indexer::dftfFinder(Document & dictionary)
{
	double count=0;
	vector<double> counter;
	vector<double> empty;
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
 * @param mode
 * @return
 */
vector<query_result> & indexer::query(string str, int x) {
	vector<string> words;
	words.push_back(str);
	querytfFinder(words);
	normalize(words);
	vector<query_result> qrs;
	query_result qr = query_result();
	qrs.push_back(qr);
	return qrs;
}
void indexer::indexDictionary(Document & diction)
{
	dictionary = diction;
}
void indexer::normalize(vector<string> words)
{
	double weight;
	vector<double> d_weight;

	for(unsigned int i=0; i<tf.size();++i)
	{
	weight = (1 + log(tfquery[i]) * log(docCount/df[i]));
	tfquery_idf_weight.push_back(weight);
	}
}

void indexer::querytfFinder(vector<string> str)
{
	float count=0;
	vector<double> empty;
	vector<string> diction = dictionary.content();
	vector<string> temp;
	for(unsigned int j = 0; j<str.size();++j)
	{
			for (unsigned int i = 0; i < diction.size(); ++i) {

				if (str[j] == diction[i])
				{
					++count;
				}
			}

			tfquery.push_back(count);
				count = 0;
		}
}

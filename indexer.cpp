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
 * @return int
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

	double tempidf = 0;
	double temptf = 0;
	double weight = 0.00;
	vector<double> d_weight;
	vector<double> empty;
	double doc = docCount;
	vector<string> diction = dictionary.content();
	for(unsigned int i=0; i<tf[0].size();++i)
	{
		for(unsigned int j=0; j<tf.size();++j)
		{
			double ttf = (double)(tf[j][i]);
			if(ttf != 0&&df[i]!=doc)
			{
				tempidf = log(doc/df[i]);
				temptf = (1+log(tf[j][i]));
				weight = tempidf*temptf;

					d_weight.push_back( floorf(weight * 1000) / 1000);

			}
			else
			{
				d_weight.push_back(0);
			}
		}
		tf_idf_weights.push_back(d_weight);
		d_weight = empty;


	}

}

/*!
 *
 * @param left
 * @param right
+ * @return indexer
 + * Overload the operator >>, takes in a document and indexer as a parameter.
 + * Takes the given document and insert it into the indexer.
 + * Returns the updated indexer at the end.
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
 * @return ostream
  * Overload of the operator <<
  * Take in and ostream and indexer.
  * Output and appropriate message if the given indexer is not initialized properly.
- * Else, it displays the amount of charaters in the document and its content.
+ * Else, it displays the amount of characters in the document and its content.
  */
ostream & operator << (ostream & os, indexer & idx)
{
	if(idx.indexe[1].size()==-1)
	{

				os<<"Error, size seems to not be initialized. "<<"\n";
	}
	else if(idx.indexe[1].name()=="")
	{

				os<<"Error, name seems to not be initialized.";
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
+ * @return document
 + * Overload of the operator []
 + * Takes in an integer.
 + * Return the document at a given i index from the indexer.
 */
const Document & indexer::operator[](const int i)
{
	return indexe[i];
}

/*!
 *
 * @param dictionary
 *  * Takes in a document.
 + * This method compute the document frequency and the term frequency within a given document.
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
vector<query_result> & indexer::query(string str, int x)
{

	vector<string> words;
	Tokenizer t = Tokenizer();
	words = t.removeSpace(str);
	querytfFinder(words);
	normalizequery();
	score();
	vector<query_result> qrs;
	query_result qr = query_result();
	qrs.push_back(qr);
	return qrs;
}
/*!
 *
 */
void indexer::score()
{
	double accum = 0., norm = 0.;
	vector<double> norms;

	for(unsigned int i =0 ;i<tf_idf_weights.size();++i)
	{
		for(unsigned int j =0 ;j<tf_idf_weights[0].size();++j){
		accum = tf_idf_weights[i][j]*tf_idf_weights[i][j];
		}
		if(accum==0){
			norms.push_back(0);}
		else{
		norms.push_back(sqrt(accum));}
	}

	for(unsigned int i =0 ;i<tf_idf_weights.size();++i)
		{
	        accum += tfquery_idf_weight[i] * tfquery_idf_weight[i];
		}
	norm = sqrt(accum);
	double topdot=0;
	vector<double> total_top;
	double tmp1 = 0., tmp2 = 0.;
	for(unsigned int i =0 ;i<tf_idf_weights[0].size();++i)
		{
			for(unsigned int j =0 ;j<tf_idf_weights.size();++j)
			{
				tmp1 = tfquery_idf_weight[j];
				tmp2 = tf_idf_weights[j][i];
				topdot += tmp1*tmp2;
			}
			total_top.push_back(topdot);
		}
	double tmp3 = 0.;
	vector<double> results;
	for(unsigned int i =0 ;i<tf_idf_weights[0].size();++i)
		{
				tmp1 = norm;
				tmp2 = norms[i];
				tmp3 = total_top[i];
				if(tmp1==0||tmp2==0||tmp3==0){
					results.push_back(0);}
				else{
				results.push_back(tmp3/(tmp1*tmp2));}
		}
	for(unsigned int i =0 ;i<tf_idf_weights[0].size();++i)
			{cout<<results[i]<< "  ";}

}

/*!
 + * @param diction
 + */
void indexer::indexDictionary(Document & diction)
{
	dictionary = diction;
}
/*!
 + *
 + * @param words
 + */

void indexer::normalizequery()
{
	double weight=0;
	vector<double> d_weight;
	double tempidf=0,temptf=0;
	double tmp=0;
	double floor = 0;
	for(unsigned int i=0; i<tfquery.size();++i)
	{

		tmp = tfquery[i];
	if(tmp==0)
	{

	tfquery_idf_weight.push_back(0);
	}
	else
	{
		tempidf = log(docCount/df[i]);
		temptf = (1+log(tfquery[i]));
		weight = tempidf*temptf;
		floor =floorf(weight * 100) / 100;
		tfquery_idf_weight.push_back(floor);
	}
	}

}
/*!
 *
 * @param str
 */
void indexer::querytfFinder(vector<string> str)
{
	double count=0;
	vector<double> empty;
	vector<string> diction = dictionary.content();
	vector<string> temp;
	for (unsigned int i = 0; i < diction.size(); ++i) {

		for(unsigned int j = 0; j<str.size();++j) {

				if (str[j] == diction[i])
				{
					++count;
				}
			}

			tfquery.push_back(count);
				count = 0;
		}

}

/*!
 + * @param dictionary
 + * Printing out the result in the good format
 + */
void indexer::print(Document & dictionary)
{
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

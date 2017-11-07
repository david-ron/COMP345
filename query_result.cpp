/*
 * query_result.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */
#include "query_result.h"

/*!
 *
 */
void query_result::info()
{

	cout<<score<<" "<< doc.name();
}
/*!
 *default constructor
 */
query_result::query_result(){
	score = 0;
}
/*!
 *
 * @param docc
 * @param scoree
 */
query_result::query_result(index_document & docc,double scoree)
{
	score = scoree;
	doc = docc;
}

bool query_result::scorecomp(const query_result &  left, const query_result & right){
	return left.score < right.score;
}
double query_result::scoree(){
	return score;
}

query_result::~query_result(){}

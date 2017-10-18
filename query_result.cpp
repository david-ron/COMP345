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
query_result::query_result(document & docc,int scoree){
	score = scoree;
	doc = docc;
}


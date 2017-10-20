/*
 * query_result.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */
#include "query_result.h"

/*!
 *Displaying the info
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
 * Parametrized constructor
 */
query_result::query_result(Document & docc,double scoree)
{
	score = scoree;
	doc = docc;
}


/*!
 + *
 + * @param os
 + * @param qr
 + * @return
 + * Taking in ostream and a query_result
 + * Overload of the operator <<
 + * Output and appropriate message if the given query_result is not initialized properly.
 + *Else, it displays that the query result is properly initialized.
 + */

ostream & operator << (ostream & os, query_result & qr)

{
	if(qr.score==-1)
	{
		os<<"Error, score seems to not be initialized."<<"\n";
	}
	else if(doc.name() == "")
	{
		os<<"Error, name seems to not be initialized.";
	}
	else
	{
		os<<"Query_result seem to be initialized properly.";
	}
	return os;
}





/*
 * query_result.h
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */

#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include "document.h"

class query_result{
	friend std::ostream & operator << (ostream & os, query_result & qr);
private:
	Document doc;
	double score;

public:
	query_result();
	query_result(Document & docc,double scoree);
	void info();
	void uwtfFinder(vector<string> str, Document & dictionary);
};

#endif /* QUERY_RESULT_H_ */

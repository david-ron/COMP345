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
	friend bool scorecomp(const query_result &  left, const query_result & right);
private:
	Document doc;
	double score;

public:
	query_result();
	query_result(Document & docc,double scoree);
	void info();
	double scoree();
};

#endif /* QUERY_RESULT_H_ */

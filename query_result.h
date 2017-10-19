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
private:
	document doc;
	int score;
public:
	query_result();
	query_result(document & docc,int scoree);
	void info();
 //<< cout<<qr

};

#endif /* QUERY_RESULT_H_ */

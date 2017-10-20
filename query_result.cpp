
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
 * @param docc
 * @param scoree
 * Parametrized constructor

 */
query_result::query_result(Document & docc,double scoree)
{
	score = scoree;
	doc = docc;
}





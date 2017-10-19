/*
 * google.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: David
 */

#include "indexer.h"
#include "document.h"
#include "query_result.h"
#include "stopword.h"
#include "tokenizer.h"

int main()
{
	Document *doc1 = new Document("file1.txt");
	vector<string> dummy;
	dummy = doc1->content();
	Document *doc0 = new Document("file2.txt");
	Document *doc2 = new Document("file3.txt");
	indexer idx = indexer();
	idx>>*doc0;
	idx>>*doc1;
	idx>>*doc0;
	idx>>*doc2;
	int i = 1;
	Document *dictionary = new Document();
	Document *doc = new Document();
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);
	i = 0;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);
	i=2;
	*doc = idx[i];
	dictionary->toCreateDictionary(*doc);
	i=3;
	*doc = idx[i];
	for(i=4;i<12;++i){
	idx>>*doc2;
		dictionary->toCreateDictionary(*doc);
	}
	dictionary->toCreateDictionary(*doc);
	dictionary->sorting();
	dictionary->duplicateRemove();
	cout<<"stopwords printing"<<endl;
	Document *docStop = new Document ("stop.txt");
	indexer idxStop = indexer();
	idxStop >> *docStop;
	Document *stopDict = new Document ();
	stopDict->compare(*dictionary);
	stopDict->sorting();
	stopDict->duplicateRemove();
	idx.dftfFinder(*stopDict);
	idx.normalize();
	idx.indexDictionary(*dictionary);
	idx.query("josh");
}

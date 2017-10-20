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
//	indexer *idx2 = indexer();
	indexer *idx2 = new indexer();
	(*idx2)>>*doc0;
	(*idx2)>>*doc1;
	(*idx2)>>*doc0;
	(*idx2)>>*doc2;
	int i = 1;
	Document *dictionary = new Document();
	Document *doc = new Document();
	*doc = (*idx2)[i];
	dictionary->toCreateDictionary(*doc);
	i = 0;
	*doc = (*idx2)[i];
	dictionary->toCreateDictionary(*doc);
	i=2;
	*doc = (*idx2)[i];
	dictionary->toCreateDictionary(*doc);
	i=3;
	*doc = (*idx2)[i];
	dictionary->toCreateDictionary(*doc);
	dictionary->sorting();
	dictionary->duplicateRemove();
	Document *docStop = new Document ("stop.txt");
//	indexer idxStop = indexer();
//	idxStop >> *docStop;
	Document *stopDict = new Document ();
	stopDict->compare(*dictionary);
	stopDict->sorting();
	stopDict->duplicateRemove();
	idx2->dftfFinder(*stopDict);
	idx2->normalize();
	idx2->indexDictionary(*stopDict);
	vector<query_result> ranks;
	idx2->query("help you figure",ranks,5);
//	sort(ranks.begin(),ranks.end(),scorecomp);
	for(unsigned int i =0 ; i<ranks.size(); ++i){
	cout<<(ranks[i].scoree());}
}

//
// Created by Sai Shan on 2017-11-03.
//

//int main()
//{
//	Document *doc1 = new Document("file1.txt");
//
//	Document *doc0 = new Document("file2.txt");
//	Document *doc2 = new Document("file3.txt");
//
//	indexer *idx2 = new indexer();
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc1;
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc2;
//
//
//	Document *dictionary = new Document();
//	Document *doc = new Document();
//
//	int i = 1;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i = 0;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i=2;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i=3;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//
//	dictionary->sorting();
//	dictionary->duplicateRemove();
//
//
//	Document *docStop = new Document ("stop.txt");
//
//	Document *stopDict = new Document ();
//	stopDict->compare(*dictionary);
//	stopDict->sorting();
//
//	idx2->dftfFinder(*stopDict);
//	idx2->normalize();
//	idx2->indexDictionary(*stopDict);
//
//	idx2->print(*stopDict);
//}

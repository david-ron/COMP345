cmake_minimum_required(VERSION 3.8)
project(COMP345)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        textFiles/file1.txt
        textFiles/file2.txt
        textFiles/file3.txt
        textFiles/index.txt
        "textFiles/printing out weights.txt"
        textFiles/README.md
        textFiles/Readmeass1.txt
        textFiles/stop.txt
        textFiles/stopwords.txt
        document.cpp
        Document.h
        google.cpp
        indexer.cpp
        indexer.h
        query_result.cpp
        query_result.h
        stopword.cpp
        stopword.h
        Tokenizer.cpp
        Tokenizer.h summarizer.cpp index_item.cpp index_item.h sentence.cpp sentence.h abstract_tokenizer.cpp abstract_tokenizer.h word_tokenizer.cpp word_tokenizer.h sentence_tokenizer.cpp sentence_tokenizer.h indexing.cpp document_indexer.cpp document_indexer.h sentence_indexer.cpp sentence_indexer.h)

add_executable(COMP345 ${SOURCE_FILES})
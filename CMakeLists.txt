cmake_minimum_required(VERSION 3.8)
project(COMP345)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        google/src/document.cpp
        google/src/Document.h
        google/src/google.cpp
        google/src/indexer.cpp
        google/src/indexer.h
        google/src/query_result.cpp
        google/src/query_result.h
        google/src/stopword.cpp
        google/src/stopword.h
        google/src/tokenizer.cpp
        google/src/tokenizer.h
        document.cpp
        Document.h
        file1.txt
        file2.txt
        file3.txt
        index.txt
        indexer.cpp
        indexer.h
        "printing out weights.txt"
        query_result.cpp
        query_result.h
        README.md
        Readmeass1.txt
        stop.txt
        stopword.cpp
        stopword.h
        stopwords.txt
        Tokenizer.cpp
        Tokenizer.h)

add_executable(COMP345 ${SOURCE_FILES})
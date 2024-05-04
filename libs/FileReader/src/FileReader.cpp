#include "FileReader.h"

FileReader::FileReader(const std::string &path) : path(path){
    this->file.open(this->path, std::ios::in);
    if(!this->file.is_open()){
        throw except::FileNotFound((char *)this->path.c_str());
    }
    if(!this->file.good()){
        throw except::FileNotReadable((char *)this->path.c_str());
    }
}

bool FileReader::isEOF(){
    return this->file.eof();
}

FileReader::~FileReader(){
    this->file.close();
}
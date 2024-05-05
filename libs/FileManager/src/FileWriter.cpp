#include "FileWriter.h"

FileWriter::FileWriter(const std::string &path, bool append = true) : path(path){
    this->file.open(this->path, append ? std::ios::app : std::ios::out);
    if(!this->file.is_open()){
        throw except::FileNotFound((char *)this->path.c_str());
    }
}

bool FileWriter::isEOF(){
    return this->file.eof();
}

FileWriter::~FileWriter(){
    this->file.close();
}
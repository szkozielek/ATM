#include "FileWriter.h"

FileWriter::FileWriter(const std::string &path, bool append = true) : path(path)
{
    this->file.open(this->path, append ? std::ios::app | std::ios::in : std::ios::out | std::ios::in);
    if (!this->file.is_open())
    {
        throw except::FileNotFound((char *)this->path.c_str());
    }
}

bool FileWriter::isEOF()
{
    return this->file.eof();
}

bool FileWriter::isEmpty()
{
    std::streampos currentPos = this->file.tellg();
    if(currentPos == -1){
        return false;
    }
    bool result = false;
    this->file.seekg(std::ios::beg);
    result = this->file.peek() == std::fstream::traits_type::eof();
    this->file.seekg(currentPos);
    return result;
}

FileWriter::~FileWriter()
{
    this->file.close();
}
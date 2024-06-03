#include "FileWriter.h"

FileWriter::FileWriter(const std::string &path, bool append, bool createIfNotFound) : path(path)
{
    this->file.open(this->path, (append ? (std::fstream::app | std::fstream::in) : (std::fstream::out | std::fstream::in)) | (createIfNotFound ? std::fstream::trunc : std::fstream::in));

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
    bool result = false;
    std::streampos currentPos = this->file.tellg();
    if (currentPos == -1)
    {
        return result;
    }
    this->file.seekg(std::ios::beg);
    result = this->file.peek() == std::fstream::traits_type::eof();
    this->file.seekg(currentPos);
    return result;
}

FileWriter::~FileWriter()
{
    this->file.close();
}
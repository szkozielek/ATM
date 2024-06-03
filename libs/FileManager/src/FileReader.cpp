#include "FileReader.h"

FileReader::FileReader(const std::string &path) : path(path)
{
    this->file.open(this->path, std::fstream::in);
    if (!this->file.is_open())
    {
        throw except::FileNotFound((char *)this->path.c_str());
    }
    if (!this->file.good())
    {
        throw except::FileNotReadable((char *)this->path.c_str());
    }
}

bool FileReader::isEOF()
{
    return this->file.eof();
}

FileReader::operator bool()
{
    return !this->isEOF();
}

std::string FileReader::getLastLine()
{
    std::streampos curPos;
    std::string result;
    bool keepGoing = true;
    curPos = this->file.tellg();
    this->file.seekg(-1, std::ios_base::end);
    while (keepGoing)
    {
        char ch;
        this->file.get(ch);
        if ((int)this->file.tellg() <= 1)
        {
            this->file.seekg(0);
            keepGoing = false;
        }
        else if (ch == '\n')
        {
            keepGoing = false;
        }
        else
        {
            this->file.seekg(-2, std::ios_base::cur);
        }
    }
    std::getline(this->file, result);
    this->file.seekg(curPos);
    return result;
}

bool FileReader::isEmpty()
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

FileReader::~FileReader()
{
    this->file.close();
}
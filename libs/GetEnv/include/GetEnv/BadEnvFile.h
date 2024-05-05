#pragma once
#include <FileManager/FileNotReadable.h>

namespace except{
    class BadEnvFile: public FileNotReadable{
    public:
        BadEnvFile(): FileNotReadable((char *)".env"){}
        virtual const char* what() const noexcept{
            return "Plik .env zawiera bledy.";
        };
    };
}
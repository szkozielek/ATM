#include "GetEnv.h"

void GetEnv::getenv(){
    size_t delimeterPos;
    std::string line;
    FileReader envFile(".env");
    while(true){
        envFile >> line;
        if(envFile.isEOF()){
            break;
        }
        delimeterPos = line.find("=");
        if(delimeterPos == std::string::npos){
            throw except::BadEnvFile();
        }
        this->config.insert({ line.substr(0, delimeterPos), line.substr(delimeterPos + 1) });
    }
}

std::string GetEnv::env(const std::string & key, std::string _default = ""){
    return this->config.count(key) < 1 ? _default : this->config[key];
}
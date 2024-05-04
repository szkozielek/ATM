#include "App.h"

void App::initArgs(){
    colors::useColors = (this->env("USE_COLORS", "true")) == "true" ;
    menu::useConsoleClear = (this->env("USE_SPACES", "true")) == "true";
}

App::App(std::istream * in, std::ostream * out) : input(in), output(out){
    this->getenv();
    this->initArgs();
}

void App::getenv(){
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

std::string App::env(const std::string & key, std::string _default = ""){
    return this->config.count(key) < 1 ? _default : this->config[key];
}

void App::run(){
    layout::Index idx(this->output);
    layout::Exit ext(this->output);
    idx.show();
    this->input->get();
    ext.show();
}
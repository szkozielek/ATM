#include "BankAccount.h"

std::string BankAccount::filename = "";
std::string BankAccount::filedir = "";

BankAccount::BankAccount(const std::string &login, const std::string &password) : _login(login), _password(password)
{

}

BankAccount::BankAccount(unsigned long long id, const std::string &login, const std::string &password) : _id(id), _login(login), _password(password)
{

}

std::string BankAccount::getFilePath()
{
    return (filedir.size() > 0 ? (filedir + "/") : "") + filename;
}


bool BankAccount::checkIfExist(const std::string & myLogin)
{
    FileReader * bankAccountsResources;
    std::string login;
    unsigned long long id, hash;
    bool result = false;

    bankAccountsResources = new FileReader( getFilePath() );
    while(!bankAccountsResources->isEOF()){
        *bankAccountsResources >> id >> login >> hash;
        if(myLogin == login){
            result = true;
        }
    }
    delete bankAccountsResources;

    return result;
}

unsigned long long BankAccount::findID(const std::string & myLogin, const std::string & myPassword)
{   
    FileReader * bankAccountsResources;
    std::string login;
    unsigned long long id, hash, myHash, result = 0;

    myHash = hash::generate(myLogin + myPassword);
    bankAccountsResources = new FileReader( getFilePath() );

    while(!bankAccountsResources->isEOF()){
        *bankAccountsResources >> id >> login >> hash;
        if(myLogin == login && myHash == hash){
            result = id;
        }
    }

    delete bankAccountsResources;

    return result;
}

BankAccount * BankAccount::login(const std::string &login, const std::string &password)
{
    unsigned long long id = findID(login, password);
    if(id == 0){
        throw std::exception();
    }
    return new BankAccount(id, login, password);
}

BankAccount * BankAccount::make(const std::string &login, const std::string &password)
{
    BankAccount * account;
    if(checkIfExist(login)){
        throw std::exception();
    }
    account = new BankAccount(login, password);
    account->generateID();
    return account;
}

void BankAccount::generateID()
{
    std::string record, lastID;
    FileReader * bankAccountsResources;

    bankAccountsResources = new FileReader( this->getFilePath() );
    record = bankAccountsResources->getLastLine();
    delete bankAccountsResources;

    if(!record.size()){
        this->_id = 1;
    }
    else{
        lastID = record.substr(0, record.find(' '));
        this->_id = std::stoull(lastID) + 1;
    } 
}

unsigned long long BankAccount::store()
{
    FileWriter * bankAccountsResources = new FileWriter(this->getFilePath(), true);
    if(!bankAccountsResources->isEmpty()){
        *bankAccountsResources << '\n';
    }
    *bankAccountsResources << this->_id << " " << this->_login << " " << hash::generate(this->_login + this->_password);
    
    delete bankAccountsResources;

    return this->_id;
}

unsigned long long BankAccount::getID() const
{
    return this->_id;
}
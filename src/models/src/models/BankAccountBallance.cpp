#include "BankAccountBallance.h"

std::string BankAccountBallance::filedir = "";

std::string BankAccountBallance::getFilePath()
{
    return (filedir.size() > 0 ? (filedir + "/") : "") +  this->currency + ".txt" ;
}

BankAccountBallance::BankAccountBallance(unsigned long long accountID, const std::string &currency) : accountID(accountID), currency(currency)
{

}

void BankAccountBallance::store(unsigned int value, char operation)
{
    FileWriter * accountBallanceResources = new FileWriter(this->getFilePath(), true);
    if(!accountBallanceResources->isEmpty()){
        *accountBallanceResources << '\n';
    }
    *accountBallanceResources << this->accountID << " " << operation << " " << value;
    
    delete accountBallanceResources;
}

void BankAccountBallance::withdraw(unsigned int value)
{
    this->store(value, '-');
}
void BankAccountBallance::deposit(unsigned int value)
{
    this->store(value, '+');
}

unsigned long long BankAccountBallance::get()
{
    unsigned int value;
    char operation;
    unsigned long long accID, result = 0;
    FileReader * accountBallanceResources;
    accountBallanceResources = new FileReader( this->getFilePath() );
    if(!accountBallanceResources->isEmpty()){
        while(!accountBallanceResources->isEOF()){
            *accountBallanceResources >> accountID >> operation >> value;
            if(accountID == this->accountID){
                switch(operation)
                {
                    case '+':
                        result += value;
                        break;
                    case '-':
                        result -= value;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    delete accountBallanceResources;

    return result;
}
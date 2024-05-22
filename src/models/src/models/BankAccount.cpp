#include "BankAccount.h"

std::string BankAccount::filename = "";

BankAccount::BankAccount(const std::string &pin) : pin(pin), amount(0)
{
    this->generateCardID();
}

void BankAccount::generateCardID()
{
    bool findNextID;
    short iter;
    int digits[4];
    std::string lastCardID, record, tempDigits, tempPartOfCardID;
    FileReader * bankAccountsResources;

    bankAccountsResources = new FileReader(this->filename);
    record = bankAccountsResources->getLastLine();
    delete bankAccountsResources;
    std::cerr << "record: " << record << std::endl;
    if(!record.size()){
        this->cardID = "1000000000000000";
    }
    else{
        lastCardID = record.substr(0, record.find(' '));
        digits[0] = std::stoi(lastCardID.substr(0, 4));
        for(iter = 0; iter < 4; ++iter){
            digits[iter] = std::stoi(lastCardID.substr((4 * iter), 4));
        }
        findNextID = true;
        for(iter = 3; (iter >= 0) && findNextID; --iter){
            if((digits[iter] + 1) / 10000 <= 0){
                digits[iter] += 1;
                findNextID = false;
            }
            else{
                digits[iter] = 0;
            }
        }
        if(iter < 0){
            throw std::out_of_range("Brak wolnych numerow kart debetowych.");
        }
        this->cardID = "";
        for(iter = 0; iter < 4; ++iter){
            tempDigits = "0000";
            tempPartOfCardID = std::to_string(digits[iter]);
            tempDigits.replace(4 - tempPartOfCardID.size(), tempPartOfCardID.size(), tempPartOfCardID);
            this->cardID += tempDigits;
        }
    }
    
}

std::string BankAccount::getCardID(){
    return this->cardID;
}

void BankAccount::store(){
    FileWriter * bankAccountsResources = new FileWriter(this->filename, true);
    if(this->cardID != "1000000000000000"){
        *bankAccountsResources << '\n';
    }
    *bankAccountsResources << this->cardID << " " << this->amount;
    
    delete bankAccountsResources;
}
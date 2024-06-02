#include "DebitCard.h"

std::string DebitCard::filename = "";
std::string DebitCard::filedir = "";


DebitCard::DebitCard(unsigned long long accountID, const std::string &pin) : pin(pin), accountID(accountID)
{
    this->generateCardID();
}

DebitCard::DebitCard(const std::string & cardID, const std::string &pin) : pin(pin), cardID(cardID)
{
    unsigned long long id = findID(cardID, pin);
    if(id == 0){
        throw std::exception();
    }
    this->accountID = id;
}

unsigned long long DebitCard::findID(const std::string & myCardID, const std::string & myPin)
{   
    FileReader * debitCardsResources;
    std::string cardID, login;
    unsigned long long id, hash, myHash, result = 0;

    myHash = hash::generate(myCardID + myPin);
    debitCardsResources = new FileReader( getFilePath() );

    while(!debitCardsResources->isEOF()){
        *debitCardsResources >> cardID >> id >> hash;
        if(myCardID == cardID && myHash == hash){
            result = id;
        }
    }

    delete debitCardsResources;

    return result;
}

std::string DebitCard::getFilePath()
{
    return (filedir.size() > 0 ? (filedir + "/") : "") + filename;
}

DebitCard * DebitCard::make(unsigned long long accountID, const std::string &pin)
{
    return new DebitCard(accountID, pin);
}

DebitCard * DebitCard::login(const std::string &cardID, const std::string &pin)
{
    return new DebitCard(cardID, pin);
}

std::string DebitCard::store()
{
    FileWriter * debitCardsResources = new FileWriter(this->getFilePath(), true);
    if(!debitCardsResources->isEmpty()){
        *debitCardsResources << '\n';
    }
    *debitCardsResources << this->cardID << " " << this->accountID << " " << hash::generate(this->cardID + this->pin);
    
    delete debitCardsResources;

    return this->cardID;
}

void DebitCard::generateCardID()
{
    bool findNextID;
    short iter;
    int digits[4];
    std::string lastCardID, record, tempDigits, tempPartOfCardID;
    FileReader * debitCardsResources;

    debitCardsResources = new FileReader( this->getFilePath() );
    record = debitCardsResources->getLastLine();
    delete debitCardsResources;

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
            if(digits[iter] < 9999){
                digits[iter] += 1;
                findNextID = false;
            }
            else{
                digits[iter] = 0;
            }
        }
        if(iter <= -1){
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

unsigned long long DebitCard::getAccountID()
{
    return this->accountID;
}

// #include "BankAccount.h"

// std::string BankAccount::filename = "";
// std::string BankAccount::filedir = "";

// std::string BankAccount::getFilePath()
// {
//     return (filedir.size() > 0 ? (filedir + "/") : "") + filename;
// }

// BankAccount * BankAccount::login(const std::string &cardID, const std::string &pin)
// {
//     if(!checkIfValid(cardID, pin)){
//         throw std::exception();
//     }
//     return new BankAccount(cardID, pin);
// }

// BankAccount * BankAccount::make(const std::string &pin)
// {
//     return new BankAccount(pin);
// }

// BankAccount::BankAccount(const std::string &pin) : pin(pin)
// {
//     this->generateCardID();
// }

// BankAccount::BankAccount(const std::string &cardID, const std::string &pin) : pin(pin), cardID(cardID)
// {

// }

// bool BankAccount::checkIfValid(const std::string & myCardID, const std::string & myPin)
// {   
//     FileReader * bankAccountsResources;
//     std::string cardID;
//     unsigned long long hash, myHash;
//     bool result = false;

//     myHash = hash::generate(myCardID + myPin);
//     bankAccountsResources = new FileReader( getFilePath() );

//     while(!bankAccountsResources->isEOF()){
//         *bankAccountsResources >> cardID >> hash;
//         if(myCardID == cardID && hash == myHash){
//             result = true;
//         }
//     }

//     delete bankAccountsResources;

//     return result;
// }

// void BankAccount::generateCardID()
// {
//     bool findNextID;
//     short iter;
//     int digits[4];
//     std::string lastCardID, record, tempDigits, tempPartOfCardID;
//     FileReader * bankAccountsResources;

//     bankAccountsResources = new FileReader( this->getFilePath() );
//     record = bankAccountsResources->getLastLine();
//     delete bankAccountsResources;

//     if(!record.size()){
//         this->cardID = "1000000000000000";
//     }
//     else{
//         lastCardID = record.substr(0, record.find(' '));
//         digits[0] = std::stoi(lastCardID.substr(0, 4));
//         for(iter = 0; iter < 4; ++iter){
//             digits[iter] = std::stoi(lastCardID.substr((4 * iter), 4));
//         }
//         findNextID = true;
//         for(iter = 3; (iter >= 0) && findNextID; --iter){
//             if(digits[iter] < 9999){
//                 digits[iter] += 1;
//                 findNextID = false;
//             }
//             else{
//                 digits[iter] = 0;
//             }
//         }
//         if(iter <= -1){
//             throw std::out_of_range("Brak wolnych numerow kart debetowych.");
//         }
//         this->cardID = "";
//         for(iter = 0; iter < 4; ++iter){
//             tempDigits = "0000";
//             tempPartOfCardID = std::to_string(digits[iter]);
//             tempDigits.replace(4 - tempPartOfCardID.size(), tempPartOfCardID.size(), tempPartOfCardID);
//             this->cardID += tempDigits;
//         }
//     }
    
// }



// std::string BankAccount::store()
// {
//     FileWriter * bankAccountsResources = new FileWriter(this->getFilePath(), true);
//     if(!bankAccountsResources->isEmpty()){
//         *bankAccountsResources << '\n';
//     }
//     *bankAccountsResources << this->cardID << " " << hash::generate(this->cardID + this->pin);
    
//     delete bankAccountsResources;

//     return this->cardID;
// }
#include "ATM.h"

std::string ATM::filedir = "";

ATM::ATM(const std::string &uuid, const std::string &currency) : UUID(uuid), currency(currency)
{
    this->loadCash();
}

std::string ATM::getFilePath()
{
    return (filedir.size() > 0 ? (filedir + "/") : "") + (this->UUID + "_" + this->currency) + ".txt";
}

void ATM::loadCash()
{
    unsigned int currency, amount;
    std::map<unsigned int, unsigned int> *result = new std::map<unsigned int, unsigned int>();
    FileReader *cashResource = nullptr;
    try
    {
        cashResource = new FileReader(this->getFilePath());
        if (!cashResource->isEmpty())
        {
            while (!cashResource->isEOF())
            {
                *cashResource >> currency >> amount;
                result->insert(std::pair<unsigned int, unsigned int>(currency, amount));
            }
        }

        delete cashResource;
    }
    catch (const except::FileNotFound &e)
    {
        if(cashResource != nullptr)
        {
            delete cashResource;
        }
    }

    this->cash = result;
}

std::map<unsigned int, unsigned int> ATM::getCash()
{
    return *this->cash;
}

void ATM::insertCash(const std::map<unsigned int, unsigned int> &cash)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    for (iter = cash.begin(); iter != cash.end(); iter++)
    {
        if (this->cash->find(iter->first) == this->cash->end())
        {
            this->cash->insert(std::pair<unsigned int, unsigned int>(iter->first, iter->second));
        }
        else
        {
            (*this->cash)[iter->first] = (*this->cash)[iter->first] + iter->second;
        }
    }
}

void ATM::grabCash(const std::map<unsigned int, unsigned int> &cash)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    std::map<unsigned int, unsigned int>::iterator thisIter;

    for (iter = cash.begin(); iter != cash.end(); iter++)
    {
        if (this->cash->find(iter->first) == this->cash->end())
        {
            throw std::exception();
        }
        else
        {
            (*this->cash)[iter->first] = (*this->cash)[iter->first] - iter->second;
            if ((*this->cash)[iter->first] <= 0)
            {
                this->cash->erase(iter->first);
            }
        }
    }
}

void ATM::update()
{
    bool first = true;
    FileWriter *cashResource;
    std::map<unsigned int, unsigned int>::const_iterator iter;
    cashResource = new FileWriter(this->getFilePath(), false, true);
    for (iter = this->cash->begin(); iter != this->cash->end(); iter++)
    {
        *cashResource << iter->first << " " << iter->second;
        if (std::next(iter, 1) != this->cash->end())
        {
            *cashResource << '\n';
        }
    }
    delete cashResource;
}

ATM::~ATM()
{
    delete this->cash;
}
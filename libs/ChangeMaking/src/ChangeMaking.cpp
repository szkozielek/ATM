#include "ChangeMaking.h"

unsigned int changemaking::infinity = -1;

/**
 * @param availableCash - mapa w formacie [nominal => dostępne] oznaczająca ile jakich banknotów do wypłaty mamy dostępnych, np:
 * [
 *      100 => 2,
 *      200 => 4,
 *      500 => 10
 * ]
 *
 * @param amount - wartość, którą chcemy wypłacić
 * @return std::map<unsigned int, unsigned int> - mapa w formacie [nominal => do_wyplaty]
 */
std::map<unsigned int, unsigned int> changemaking::getCash(const std::map<unsigned int, unsigned int> &availableCash, unsigned int amount)
{
    std::map<unsigned int, unsigned int> result; // wynik - ile jakiego banknotu wyplacic
    std::map<unsigned int, unsigned int>::const_iterator iter;
    std::map<unsigned int, unsigned int>::const_reverse_iterator reversIter;
    unsigned int amountIter, cashIndex, currentAmount;
    unsigned int ***tableOfCash; // tablica dynamiczna z wynikami

    if (amount == changemaking::infinity)
    {
        throw except::TooLargeAmount();
    }
    tableOfCash = changemaking::__createCashTable(availableCash.size(), amount);

    for (iter = availableCash.begin(); iter != availableCash.end(); iter++)
    {
        for (amountIter = 0; amountIter <= amount; ++amountIter)
        {
            changemaking::__checkAmountForCurrentCash(tableOfCash, iter, std::distance(availableCash.begin(), iter) + 1, amountIter);
        }
    }

    // wyswietlanie dynamicznej tablicy (to_debug)
    // changemaking::__showTable(tableOfCash, availableCash, amount);

    if (tableOfCash[availableCash.size()][amount][0] == changemaking::infinity)
    {
        changemaking::__freeCashTable(tableOfCash, availableCash.size(), amount);
        throw except::ImpossibleToChange();
    }

    currentAmount = amount;
    for (reversIter = availableCash.rbegin(); reversIter != availableCash.rend(); reversIter++)
    {
        cashIndex = availableCash.size() - std::distance(availableCash.rbegin(), reversIter);
        if (tableOfCash[cashIndex][currentAmount][1] > 0)
        {
            result[reversIter->first] = tableOfCash[cashIndex][currentAmount][1];
            currentAmount -= tableOfCash[cashIndex][currentAmount][1] * reversIter->first;
        }
    }

    changemaking::__freeCashTable(tableOfCash, availableCash.size(), amount);

    return result;
};

void changemaking::__checkAmountForCurrentCash(unsigned int ***tableOfCash, const std::map<unsigned int, unsigned int>::const_iterator &cash, unsigned int cashIndex, unsigned int amount)
{
    unsigned int counter, maxCountToCheck;
    /**
     * Jeśli wartość mniejsza niż nominał, przepisz z góry
     */
    if (amount < cash->first)
    {
        tableOfCash[cashIndex][amount][0] = tableOfCash[cashIndex - 1][amount][0];
        return;
    }
    maxCountToCheck = std::min(cash->second, (amount / cash->first));
    for (counter = 0; counter <= maxCountToCheck; ++counter)
    {
        /**
         * sprawdź, czy wartość w wierszu wyżej przesuniętym w tył o (counter * wartość nominału) jest mniejsza od aktualnej
         * i nie jest nieskończona
         */
        if (
            tableOfCash[cashIndex - 1][amount - (counter * cash->first)][0] != changemaking::infinity &&
            (tableOfCash[cashIndex - 1][amount - (counter * cash->first)][0] + counter) < tableOfCash[cashIndex][amount][0])
        {
            tableOfCash[cashIndex][amount][0] = (tableOfCash[cashIndex - 1][amount - (counter * cash->first)][0] + counter);
            tableOfCash[cashIndex][amount][1] = counter;
        }
    }
}

unsigned int ***changemaking::__createCashTable(size_t cashSize, size_t amount)
{
    unsigned int iter, deepIter;
    unsigned int ***tableOfResults = new unsigned int **[cashSize + 1];
    for (iter = 0; iter <= cashSize; ++iter)
    {
        tableOfResults[iter] = new unsigned int *[amount + 1];
        for (deepIter = 0; deepIter <= amount; ++deepIter)
        {
            tableOfResults[iter][deepIter] = new unsigned int[2];
            tableOfResults[iter][deepIter][0] = (deepIter == 0 ? 0 : changemaking::infinity);
            tableOfResults[iter][deepIter][1] = 0;
        }
    }
    return tableOfResults;
}

void changemaking::__freeCashTable(unsigned int ***tableOfResults, size_t cashSize, size_t amount)
{
    unsigned int iter, deepIter;
    for (iter = 0; iter <= cashSize; ++iter)
    {
        for (deepIter = 0; deepIter <= amount; ++deepIter)
        {
            delete[] tableOfResults[iter][deepIter];
        }
        delete[] tableOfResults[iter];
    }
    delete[] tableOfResults;
}

void changemaking::__showTable(unsigned int ***tableOfCash, const std::map<unsigned int, unsigned int> &availableCash, size_t amount)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    std::cerr << std::setw(7) << "-" << "|";
    for (unsigned int i = 0; i <= amount; i++)
    {
        std::cerr << std::setw(3) << i << " ";
    }
    std::cerr << std::endl;
    std::cerr << std::setw(7) << 0 << "|";
    for (unsigned int i = 0; i <= amount; i++)
    {
        std::cerr << std::setw(3) << (tableOfCash[0][i][0] == changemaking::infinity ? "inf" : std::to_string(tableOfCash[0][i][0])) << " ";
    }
    std::cerr << std::endl;

    for (iter = availableCash.begin(); iter != availableCash.end(); iter++)
    {
        std::cerr << std::setw(7) << iter->first << "|";
        for (unsigned int i = 0; i <= amount; i++)
        {
            std::cerr << std::setw(3) << (tableOfCash[std::distance(availableCash.begin(), iter) + 1][i][0] == changemaking::infinity ? "inf" : std::to_string(tableOfCash[std::distance(availableCash.begin(), iter) + 1][i][0])) << " ";
        }
        std::cerr << std::endl;
    }
}

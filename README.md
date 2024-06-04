# ATM
Projekt na zaliczenie - "symulator" bankomatu.

## System requrement
- [make](https://www.gnu.org/software/make/),
- [cmake](https://cmake.odeleterg/download/) (wersja ^3.5.0),
- kompilator C++ (najlepiej [mingw32 GCC 9.2.0](https://osdn.net/projects/mingw/downloads/72211/gcc-c++-9.2.0-2-mingw32-bin.tar.xz/)).

## Compilation
Przy pierwszym uruchomieniu:

```bash
cmake --DCMAKE_BUILD_TYPE=Release -S . -B ./build
```

następnie:

```bash
cmake --build ./build
```

## Configuration

Po skompilowaniu konfiguracja aplikacji będzie znajdować się w pliku **.env**. 
Aplikacja zostanie wstępnie skonfigurowana na podstawie konfiguracji CMake. Ustawienia można zmieniać na przestrzeni wielu uruchomień aplikacji.

Opis poszczególnych zmiennych:

```
USE_COLORS=         // Użyj znaków ASCI do kolorowania tekstu (true / false)
USE_SPACES=         // Użyj znaku ASCI do "czyszczenia" ekranu konsoli (true / false)
USE_HIDE=           // Użyj znaków ASCI do ukrywania wprowadzanych haseł (true / false)
BANK_ACCOUNT_DIR=           // folder, w którym będą zapisywane pliki z informacjami o kontach bankowych
BANK_ACCOUNT_FILENAME=      // nazwa pliku z kontami bankowymi
DEBIT_CARD_DIR=             // folder, w którym będą zapisywane pliki dt. kart debetowych
DEBIT_CARD_FILENAME=        // plik z kartami debetowymi
ATM_ID_KEY=                 // ID bankomatu (jeśli zmienimy, będziemy używać innych "kaset" na gotówke)
ATM_CASHBOX_DIR=            // Folder z informacjami o kasetach bankomatów
ACCOUNT_BALANCE_DIR=        // Folder z informacjami o saldach kont bankowych
CURRENCIES=                 // Dostępne waluty (wymieniane po średnikach ciurkiem, bez spacji)
```

## Running

Po skompilowaniu w folderze *./build* (uruchomić należy w folderze, w którym znajduje się plik **.env**)

(Windows)
```bash
./ATM.exe
```

(Linux)
```bash
./ATM
```

## FAQ

### Pojawiają mi się dziwne znaczki w konsoli. Nic nie widzę co zrobić?

Jeśli występuje u Ciebie taki problem, to oznacza, że Twoja konsola nie obsługuje kodów ucieczki ANSI (eng. *ANSI escape codes*). W takiej sytuacji należy w pliku .env w katalogu build
ustawić opcje: 

- USE_COLORS,
- USE_SPACES,
- USE_HIDE

na wartość **false** (interface nie będzie wtedy tak ładny jak mógłby, ale będzie funkcjonalny).

## Source
Źródła, inspiracje:
- [CMake-project-template](https://github.com/Jamagas/CMake/blob/master/README.md)
- [ATM-Flowchart](https://www.softwareideas.net/a/395/atm-workflow-flowchart-)
- [Dynamic-Change-Algorithm](https://pl.wikipedia.org/wiki/Problem_wydawania_reszty)

#### TODO

Zadania odłożone na wieczne nigdy:

- README.md - dokończyć,
- wycieki pamięci gdy brakuje plików - poprawić,
- Własne błędy w miejsce std::exception i std::out_of_range,
- Refaktoryzacja kodu - większa separacja layoutu od kontrollerów i widoków,
- testy - aktualnie brak.
- wprowadzanie (opcjonalne) ID bankomatu jako parametr przy uruchomieniu aplikacji.

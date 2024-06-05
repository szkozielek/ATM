# ATM

"Symulator" bankomatu - projekt na zaliczenie przedmiotu Programowanie Obiektowe.

## System requrement

- [make](https://www.gnu.org/software/make/),
- [cmake](https://cmake.odeleterg/download/) (wersja ^3.5.0),
- kompilator C++ (testowany [mingw32 GCC 9.2.0](https://osdn.net/projects/mingw/downloads/72211/gcc-c++-9.2.0-2-mingw32-bin.tar.xz/)).

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

### Pojawiają mi się dziwne znaczki w konsoli. Nic nie widzę, co zrobić?

Jeśli występuje u Ciebie taki problem, to oznacza, że Twoja konsola nie obsługuje kodów ucieczki ANSI (eng. *ANSI escape codes*). W takiej sytuacji należy w pliku .env w katalogu build
ustawić opcje: 

- USE_COLORS,
- USE_SPACES,
- USE_HIDE

na wartość **false** (interface nie będzie wtedy tak ładny jak mógłby, ale będzie funkcjonalny).

### Otrzymuję komunikat "File not found: (...)", aplikacja nie działa!

Program może tworzyć pliki potrzebne do funkjconowania, nie może jednak tworzyć katalogów. Ścieżka podana po dwukropku zapewne nie istnieje, więc i plik w niej nie może zostać utworzony.

Utwórz ścieżkę folderów tak, aby zgadzała się z podaną w komunikacie, lub zmień konfigurację ścieżek do zasobów w pliku **.env**.

## Source

Źródła, inspiracje:

- [CMake-project-template](https://github.com/Jamagas/CMake/blob/master/README.md)
- [ATM-Flowchart](https://www.softwareideas.net/a/395/atm-workflow-flowchart-)
- [Dynamic-Change-Algorithm](https://pl.wikipedia.org/wiki/Problem_wydawania_reszty)

#### TODO

Zadania odłożone na wieczne nigdy:

- README.md - przetłumaczyć na j. angielski
- Refaktoryzacja kodu - większa separacja layoutu od kontrolerów i widoków,
- testy - aktualnie brak,
- wprowadzanie (opcjonalne) ID bankomatu jako parametr przy uruchomieniu aplikacji,
- Umożliwienie wykonania operacji na bankomacie bez używania interface-u (przez podanie odpowiednich parametrów przy uruchomieniu).

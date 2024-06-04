# ATM
Projekt na zaliczenie - "symulator" bankomatu.

## System requrement
- [make](https://www.gnu.org/software/make/),
- [cmake](https://cmake.org/download/) (wersja ^3.5.0),
- kompilator C++ (najlepiej [mingw32 GCC 9.2.0](https://osdn.net/projects/mingw/downloads/72211/gcc-c++-9.2.0-2-mingw32-bin.tar.xz/)).

## Compilation

## Running

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

#### TODO:

- README.md - dokończyć
- Własne błędy w miejsce std::exception i std::out_of_range,
- Refaktoryzacja kodu - większa separacja layoutu od kontrollerów i widoków,
- testy - aktualnie brak.
- wprowadzanie (opcjonalne) ID bankomatu jako parametr przy uruchomieniu aplikacji.

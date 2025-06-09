# Sprawozdanie lista 1

**Autor**: Patryk Kowalski 267671

## Opis wykonanych czynnosci
1. Sworzenie projektu zgodnie z wymaganiami. Struktura - biblioteka hello - lib/hello pliki glowne w src/prog1/main.cpp i src/prog2/main.cpp
2. Zbudowanie kodu recznie za wywolujac kompilator z wiersza polecen:
- g++ -c lib/hello/hello.cpp -o lib/hello/hello.o
- g++ -c src/prog1/main.cpp -o src/prog1/main.o
- g++ -c src/prog2/main.cpp -o src/prog2/main.o
- g++ -o prog1.exe src/prog1/main.o lib/hello/hello.o
- g++ -o prog2.exe src/prog2/main.o lib/hello/hello.o
Uzycie tych komend pozwolilo na stworzenie na poczatku plikow obiektowych komenda g++ -c ,a nastepnmie za pomoca g++ -o plik_wynikowy plik_obiektowy plik_obiektowy na zlinkowanmie i stworzenie pliku wykonywalnego.
3. Aby przespieszyc proces umieszczono plik build.sh jego struktura to wymienione powyzej komendy, ktore automatycznie wywolujemy wpisujac w terminalu ./build.sh efektem tego jest stworzenie pilkow obiektowych,linkowanie i pliku wykonywalnego tylko ze proces jest znacznie przyspieszony.
4. W kolejnej metodzie budowania projektu skorzystalismy z Makefile. Aby zbudowac projekt uzylismy nastepujacych dyrektyw:
- all: prog1 prog2
- prog1: src/prog1/main.o lib/hello/hello.o
    g++ -o prog1 src/prog1/main.o lib/hello/hello.o
- src/prog1/main.o: src/prog1/main.cpp
    g++ -c src/prog1/main.cpp -o src/prog1/main.o
- lib/hello/hello.o: lib/hello/hello.cpp
    g++ -c lib/hello/hello.cpp -o lib/hello/hello.o
 - g++ -o prog1 src/prog1/main.o lib/hello/hello.o
 - prog2: src/prog2/main.o lib/hello/hello.o
    g++ -o prog2 src/prog2/main.o lib/hello/hello.o
Wynikiem jest stworzeniu plikow obiektowych i wykonywanlnych
5. Ostatnia metoda bylo uzycie CMake.Jest to bardzo wygodna metoda. Konfiguracja CMake zawiera:
- Definicję projektu
- Budowę biblioteki za pomocą add_library
- Tworzenie programów wykonawczych z add_executable
- Linkowanie biblioteki z programami przez target_link_libraries.
Projekt zbudowalem poleceniami w terminalu:
- stworzylem katalog mkdir build
- cd build
- cmake ..
- make 
Wynikiem jest sworzenie folderu build w ktorym zawieraja sie pliki projektowe takie jak: Makefile, 
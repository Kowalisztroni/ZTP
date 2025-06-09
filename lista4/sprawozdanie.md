Zadanie 1 :
Przypomnieć sobie działanie funkcji wirtualnych.
Liskov Substitution Principle.


funkcja wirtualna zastepuje w funkcji dziedziczonej funkcje bazowa.
Przydatne jest to podczas polimorfizmu


zadanie 2:
Ile kosztują nas funkcje wirtualne ?
funkcja wirtualna zwieksa rozmiar obiektu o 8bajt. o Jeden wskaznik .


- czy istnienie funkcji wirtualnej ma wpływ na rozmiar obiektu ?



- jeśli tak, to czy zależy to od liczby funkcji wirtualnych ?



- jeśli tak, to czy dotyczy to typu bazowego czy pochodnego ?



- czy jest jaiś dodatkowy "koszt pamięciowy" ?



- ile kosztuje wywołanie funkcji wirtualnej



Należy wygenerować kod ASM (g++ -S ... ) dla dwóch sytuacji
- wywołanie zwykłej funkcji
- wywołanie funkcji wirtualnej


Bez funckji wirtualnych: 
- wywolanie statyczne call <adres> brak vtable, brak polimorfizmu . W func zawsze wywolywane jest Osoba::info() zamiast wywyolac dla danego obiektu na przyklad inny student .

- z funkcja wirtualna wywolania przez wskaznik , sa dynamiczne call *%rejestr, uzywany vtable co umozliwia polimorfizm.

- roznice assemblerowe kluczowa zmiana t osposob skoku w func - statyczny (call  ) vs dynamiczny (call *%rdx)



Eksperyment: spróbujcie użyć ChataGPT i/lub innych AI żeby Wam objaśnły co się dzieje w kodzie ASM ;

W sprawozdaniu proszę przeanalizować co się dzieje w każdym z tych przypadków (proszę pominąć wszelkie procedury "inicjalizacyjne" i to co będzie wspólne - interesuje nas tylko i wyłącznie samo wywołanie funkcji).



Zadanie 3 (w trakcie opracowania)
Tworzymy klasę bazową reprezentującą dowolną abstrakcyjną koncepcję (np. sterownik przetwornika A/C).
Następnie tworzymy dwie różne implementacje.
Sprawdzamy, że z punktu widzenia kodu korzystającego z klasy bazowej - nie ma znaczenia którą implementację dostarczymy.
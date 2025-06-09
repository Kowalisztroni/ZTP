#include <catch2/catch_test_macros.hpp>
#include "../lib/tokenizer/tokenizer.h"


// Minimalna lista testów:

//         Podział prostego zdania na słowa.

//         Podział napisu z wieloma separatorami.

//         Podział napisu zaczynającego się/kończącego separatorem.

//         Obsługa pustego napisu.

//         Obsługa napisu z Unicode.

//         Sprawdzenie poprawności zwróconych tokenów w trybie zachowania separatorów.





TEST_CASE("Podział prostego zdania na słowa","[Tokenizer]")
{
    auto r = tokenize("To jest test.", "  .", false);
    REQUIRE(r == std::vector<std::string>{"To", "jest", "test"});
}






TEST_CASE("Podział napisu z wieloma sepratorami","[Tokenizer]")
{
    auto r = tokenize("To jest test. To jest drugi test.", "  .", false);
    REQUIRE(r == std::vector<std::string>{"To", "jest", "test", "To", "jest", "drugi", "test"});
}





TEST_CASE("Podział napisu zaczynającego/kończącego separatorem","[Tokenizer]")
{
    auto r = tokenize(".To jest test.", "  .", false);
    REQUIRE(r == std::vector<std::string>{"To", "jest", "test"});
}





TEST_CASE("Obsługa pustego napisu","[Tokenizer]")
{
    auto r = tokenize("", "  .", false);
    REQUIRE(r == std::vector<std::string>{});
}





TEST_CASE("Obsługa napisu z Unicode","[Tokenizer]")
{
    auto r = tokenize("ćma żaba źrebak", "  .", false);
    REQUIRE(r == std::vector<std::string>{"ćma", "żaba", "źrebak"});
}





TEST_CASE("Sprawdzenie poprawności zwróconych tokenów w trybie zachowania separatorów","[Tokenizer]")
{
    auto r = tokenize("To jest test.", "  .", true);
    REQUIRE(r == std::vector<std::string>{"To", " ", "jest", " ", "test", "."});
}





#include <iostream>
#include <vector>
#include <string>
#include "../lib/tokenizer/tokenizer.h"





int main()
{


  std::string input_string = "Hello, World! This is a test string.";
  std::string separators = ",.!.?;: \t\n\r";
  bool keep_seperators = false;
  
  std::vector<std::string> tokens = tokenize(input_string,separators,keep_seperators);

    std::cout << "Tokens:" << std::endl;
    
    for(auto token : tokens)
    {
        std::cout << token << std::endl;
    }




    return 0;
}
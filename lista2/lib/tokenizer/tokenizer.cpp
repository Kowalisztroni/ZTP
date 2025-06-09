#include "tokenizer.h"
#include<vector>
#include<string>


std::vector<std::string> tokenize(const std::string& input, const std::string& separators,bool keep_separators)
{
std::vector<std::string> tokens;
size_t start = 0;
size_t end = input.find_first_of(separators);

while (end != std::string::npos) {
if (start != end)
tokens.push_back(input.substr(start, end - start));

if (keep_separators)
tokens.push_back(input.substr(end, 1));

start = end + 1;
end = input.find_first_of(separators, start);
}

if (start < input.length())
tokens.push_back(input.substr(start));

return tokens;
}



 
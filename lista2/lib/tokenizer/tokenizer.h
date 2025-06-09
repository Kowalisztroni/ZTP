#pragma once
#ifndef HELLO_H
#define HELLO_H

#include<vector>
#include<string>


std::vector<std::string> tokenize(const std::string &input_string, const std::string &separators, bool keep_separators);

#endif
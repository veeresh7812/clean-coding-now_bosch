/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//============================================================================
// Name        : cleancode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <sstream>
#include <cassert>

using namespace std;

std::function<bool(const string&)> startswithPredicateGenerator(char letter){

    function<bool(const string&)> startsWith= [letter](const string& item) { 
                 for (char ch : item) {
                    if (ch == letter) {
                        return true;
                    }
                }
                
            
    };
    return startsWith;
}

std::vector<std::string> findStrings(const std::vector<std::string>& strings,
		const std::function<bool(const std::string&)>& condition)
{
    std::vector<std::string> result;
    for (const std::string& str : strings) {
        if (condition(str)) {
            result.push_back(str);
        }
    }
    return result;
}


std::string FormattedString(const std::vector<std::string>& vec) {
    std::ostringstream oss;
    for (const std::string& str : vec) {
        oss << str << "\n";
    }
    return oss.str();
}

int main()
{
    std::vector<std::string> strings = {"apple", "banana", "cherry", "date", "elderberry"};

    char letter = 'a';
    // Create a std::function that checks for the specific letter
    std::function<bool(const std::string&)> letterCondition = startswithPredicateGenerator(letter);
    // Find strings that contain the specified letter
    std::vector<std::string> foundStrings = findStrings(strings, letterCondition);
    std::cout << "Strings containing the letter '" << letter << "':" << std::endl;
    std::cout << FormattedString(foundStrings);
    return 0;
}

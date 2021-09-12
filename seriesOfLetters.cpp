#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

/*
Write a function, named series_of_letters, that takes a reference to a vector of chars and returns nothing. 
The function should modify the vector to contain a series of letters increasing from the smallest letter 
(by ASCII value) in the vector. Note, the vector should not change in size, and the initial contents of the vector 
(excepting the smallest letter) do not matter.

You should be using the STL algorithms to achieve this, full credit is only possible if your solution doesn't have 
any looping constructs (no "while" or "for" keywords anywhere in the solution). If a URL you are citing has such 
a word, add an interupting space like: https://www.programiz.com/cpp-programming/fo r-loop
*/
char currentChar;
std::vector<char> charVec;

bool myFunction (char first, char second){
    int firstascii = int(first);
    int secondascii = int(second);
    if (firstascii<secondascii){
        return true;
    }
    return false;
}
void myFunction2 (char first){
    //std::cout<< "first: " << first << std::endl;
    first = int(currentChar)+1;
    charVec.push_back(first);
    currentChar=first;
    //std::cout<< "currentChar in function: " << currentChar << std::endl;

}

void series_of_letters(std::vector<char> &vec){
    sort(vec.begin(), vec.end(), myFunction);
    currentChar = *vec.begin();
    charVec.push_back(currentChar);
    //std::cout<< "current char: " << currentChar << std::endl;
    for_each(vec.begin()+1, vec.end(), myFunction2);
    vec = charVec;
    charVec = {};
    currentChar = '\0';
}

int main(){
    std::vector<char> vec = {'j', 'j', 'd', 'o'};
    series_of_letters(vec);
    for (auto myChar : vec){
        std::cout<< myChar;
    }
}
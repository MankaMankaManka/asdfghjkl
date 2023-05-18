#include <iostream>
#include <vector>
class Autocomplete
{
public:
    Autocomplete* children[26];
    bool isWordEnd;
    
    Autocomplete()
    {
        this->isWordEnd = false;
 
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    };
    
    std::vector<std::string> getSuggestions(std::string partialWord);  // return the known words that start with partialWord
    void suggestionsRec(std::vector<std::string> vect, Autocomplete* pCrawl, std::string partialWord); //recursion
    void insert(std::string word); // add a word to the known words
};

#include "Autocomplete.h"

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    std::vector<std::string> vect(10);
    
    Autocomplete* pCrawl = this;
    for (char c : partialWord) {
        int ind = (int)c - (int)'a';
        pCrawl = pCrawl->children[ind];
    }
    suggestionsRec(vect, pCrawl, partialWord);

    return vect;
}


// Recursive function to print auto-suggestions for given node.
void Autocomplete::suggestionsRec(std::vector<std::string> vect, Autocomplete* pCrawl, std::string partialWord)
{
    // found a string in Trie with the given prefix
    if (pCrawl->isWordEnd==true){
        //std::cout <<"found word! " <<partialWord << std::endl;
        vect.push_back(partialWord);
    }
    for (int i = 0; i < 26; i++){
        if (pCrawl->children[i]) {
            // child node character value
            char child = 'a' + i;
            //std::cout << partialWord + child << std::endl;
            suggestionsRec(vect, pCrawl->children[i], partialWord + child);
        }
    }
}


void Autocomplete::insert(std::string word){
  
  Autocomplete* pCrawl = this;
 
    for (int level = 0; level < word.length(); level++) 
    {
        // Converts word current character into index
        // use only 'a' through 'z' and lower case
        int index = (int)word[level] - (int)'a'; 
        if (pCrawl->children[index]==nullptr){
            pCrawl->children[index] = new Autocomplete;
        }
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isWordEnd = true;
    
}
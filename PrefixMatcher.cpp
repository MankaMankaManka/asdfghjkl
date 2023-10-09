
#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAddress){  // return the router with the longest matching prefix
// We've made this a string for ease of implementation, if you'd like to work with binary numbers in your implementation feel free but for testing you need to provide an interface that takes a string
    PrefixMatcher* pCrawl = this;
    int index;
    std::vector<int> vect;
    //call a function that tests if the pcrawl is equal to the adress bit at the level. for example
    // if target adress is 5 digits long, check if a network is 1 digit long, then 2, then 3 then 4 
    //then 5, then return the last number that matched
    for (int level=0; level<networkAddress.size(); level++){
        index=networkAddress[level];
        pCrawl=pCrawl->children[index];
        if (pCrawl->isWordEnd==true){
            vect.push_back(pCrawl->number);
        }
    }
    int routerWithLongestMatchingPrefix=vect.back();
    return routerWithLongestMatchingPrefix;
}


/*
std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    Autocomplete* pCrawl = this;
    for (int i=0; i<networkAddress.size(); i++)
    {
        int ind = partialWord[i]  - '0';
        pCrawl = pCrawl->children[ind];
    }
    std::vector<std::string> vect;
    suggestionsRec(vect, pCrawl, partialWord);
    
    return vect;
}

// Recursive function to print auto-suggestions for given node.
void Autocomplete::suggestionsRec(std::vector<std::string> &vect, Autocomplete* pCrawl, std::string partialWord)
{
    // found a string in Trie with the given prefix
    if (pCrawl->isWordEnd==true){
    
        vect.push_back(number);
        
    }
    for (int i = 0; i < 2; i++){
        if (pCrawl->children[i]) {
            suggestionsRec(vect, pCrawl->children[i], partialWord + child);
        }
    }
}
*/

 void PrefixMatcher::insert(std::string address, int routerNumber){
  
  PrefixMatcher* pCrawl = this;
 
    for (int level = 0; level < address.size(); level++) 
    {
        // Converts word current character into index
        // using only binary strings
        int index = address[level] - '0';
        if (pCrawl->children[index] == nullptr){
            pCrawl->children[index] = new PrefixMatcher;
        }
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isWordEnd = true;
    pCrawl->number = routerNumber;
    
}

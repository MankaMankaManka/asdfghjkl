
#include "PrefixMatcher.h"

int selectRouter(string networkAddress){  // return the router with the longest matching prefix
// We've made this a string for ease of implementation, if you'd like to work with binary numbers in your implementation feel free but for testing you need to provide an interface that takes a string
  

}


// Recursive function to print auto-suggestions for given node.
void Autocomplete::suggestionsRec(std::vector<std::string> &vect, Autocomplete* pCrawl, std::string partialWord)
{
    // found a string in Trie with the given prefix
    if (pCrawl->isWordEnd==true){
        vect.push_back(networkAddress);
    }
    for (int i = 0; i < 2; i++){
        if (pCrawl->children[i]) {
            suggestionsRec(vect, pCrawl->children[i], partialWord + child);
        }
    }
}

  void insert(string address, int routerNumber){ // add a router address
    number = routernumber;
    PrefixMatcher* pCrawl = this;
 
    for (int level = 0; level < address.size(); level++) 
    {
        if (pCrawl->children[level]==nullptr){
            pCrawl->children[level] = new PrefixMatcher;
        }
        pCrawl = pCrawl->children[level];
    }
 
    // mark last node as leaf
    pCrawl->isWordEnd = true;

  }

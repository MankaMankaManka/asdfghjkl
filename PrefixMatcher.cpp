
#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAddress){
   
    PrefixMatcher* pCrawl = this;
    
    int index;
    std::vector<int> vect;
    
    //call a function that tests if the pcrawl is equal to the adress bit at the level. for example
    // if target adress is 5 digits long, check if a network is 1 digit long, then 2, then 3 then 4 
    //then 5, then return the last number that matched
    
    for (int level=0; level<networkAddress.size(); level++){
        int index = networkAddress[level] - '0';
        if (pCrawl->children[index]!= nullptr){
            pCrawl=pCrawl->children[index];
            if (pCrawl->isWordEnd==true){
                vect.push_back(pCrawl->number);
            }
        }
    }
    int vSize=vect.size();
    int final = vect[vSize];
    return final;
}

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

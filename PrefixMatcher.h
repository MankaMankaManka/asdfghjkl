#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <iostream>
#include <vector>
class PrefixMatcher
{
public:
    PrefixMatcher* children[2];
    bool isWordEnd;
    int number = -1;
    
    PrefixMatcher()
    {
        this->isWordEnd = false;
 
        for (int i = 0; i < 2; i++) {
            this->children[i] = nullptr;
        }
    };
    
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);
    
};

#endif

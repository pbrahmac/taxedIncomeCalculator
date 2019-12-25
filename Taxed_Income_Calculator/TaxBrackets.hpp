#ifndef TaxBrackets_hpp
#define TaxBrackets_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class TaxBrackets {
public:
    struct Bracket {
        int bottom;
        int top;
        int range;
        double taxRate;
        double maxTaxedNum;
        
        Bracket(int b, int t, double tr) : bottom(b), top(t), taxRate(tr), range(t-b), maxTaxedNum(tr*range) {}
    };
    
    vector<Bracket> taxBrackets;
    
    //constructor
    TaxBrackets();
    TaxBrackets(vector<Bracket>);
    //get method
    vector<Bracket> getBrackets();
    //print
    void printBrackets();
};

#endif /* TaxBrackets_hpp */

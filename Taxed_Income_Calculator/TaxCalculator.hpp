#ifndef TaxCalculator_hpp
#define TaxCalculator_hpp

#include <stdio.h>
#include "TaxBrackets.hpp"

class TaxCalculator {
private:
    double requiredIncome;
    TaxBrackets tb;
    bool inRange(double value, TaxBrackets::Bracket b) {
        if (value > b.bottom && value <= b.top) {
            return true;
        }
        return false;
    }
    
public:
    
    TaxCalculator(double);
    TaxCalculator(TaxBrackets, double);
    
    double getIncome();
    double fixedRateCalc(double, double);
    double variableRateCalc(vector<TaxBrackets::Bracket>, double);
};

#endif /* TaxCalculator_hpp */

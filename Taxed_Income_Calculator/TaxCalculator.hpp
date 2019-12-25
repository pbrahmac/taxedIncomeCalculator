#ifndef TaxCalculator_hpp
#define TaxCalculator_hpp

#include <stdio.h>
#include "TaxBrackets.hpp"

class TaxCalculator {
private:
    double requiredIncome;
    TaxBrackets tb;
    bool inRange(double value, TaxBrackets::Bracket b) {
        return (value > b.bottom && value <= b.top);
    }
    
public:
    //contructor
    TaxCalculator(TaxBrackets);
    //getter
    double getIncome();
    // calculate income needed
    double fixedRateIncome(double, double);
    double variableRateIncome(double);
    // calculate taxes
    double fixedRateTax(double, double);
    double variableRateTax(double);
};

#endif /* TaxCalculator_hpp */

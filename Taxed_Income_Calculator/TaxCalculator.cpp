#include "TaxCalculator.hpp"

TaxCalculator::TaxCalculator(double expense) {
    this->requiredIncome = this->variableRateCalc(tb.getBrackets(), expense);
    printf("Expenses: $%.02f\nRequired Income: $%.02f\n", expense, requiredIncome);
}

TaxCalculator::TaxCalculator(TaxBrackets tBrackets, double expense) {
    this->tb = tBrackets;
    
    this->requiredIncome = this->variableRateCalc(tb.getBrackets(), expense);
    printf("Expenses: $%.02f\nRequired Income: $%.02f\n", expense, requiredIncome);
}

double TaxCalculator::getIncome() {
    return this->requiredIncome;
}

double TaxCalculator::fixedRateCalc(double expense, double taxRate) {
    return expense / (1 - taxRate);
}

double TaxCalculator::variableRateCalc(vector<TaxBrackets::Bracket> taxBrackets, double expense) {
    int minBracket = 0;
    double totalTax = 0;
    while (expense >= taxBrackets.at(minBracket).top) {
        totalTax += taxBrackets.at(minBracket++).maxTaxedNum;
    }
    
    double currentTax = 0;
    double totalIncome = 0;
    
    for (int i = minBracket; i < taxBrackets.size(); i++) {
        if (inRange((expense+totalTax), taxBrackets.at(i))) {
            totalIncome = fixedRateCalc(expense+totalTax-taxBrackets.at(i).bottom, taxBrackets.at(i).taxRate) + taxBrackets.at(i).bottom;
            if (totalIncome <= taxBrackets.at(i).top) {
                break;
            } else {
                currentTax = taxBrackets.at(i).maxTaxedNum;
            }
        } else {
            currentTax = taxBrackets.at(i).maxTaxedNum;
        }
        totalTax += currentTax;
        
        if ((expense+totalTax) <= taxBrackets.at(i).top) {
            totalIncome = expense + totalTax;
            break;
        }
    }
    
    return totalIncome;
}

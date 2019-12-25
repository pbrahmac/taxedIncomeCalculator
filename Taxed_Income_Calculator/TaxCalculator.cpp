#include "TaxCalculator.hpp"

TaxCalculator::TaxCalculator(TaxBrackets tBrackets) {
    this->tb = tBrackets;
}

double TaxCalculator::getIncome() {
    return this->requiredIncome;
}

double TaxCalculator::fixedRateIncome(double expense, double taxRate) {
    return expense / (1 - taxRate);
}

double TaxCalculator::variableRateIncome(double expense) {
    vector<TaxBrackets::Bracket> taxBrackets = this->tb.getBrackets();
    int minBracket = 0;
    double totalTax = 0;
    while (expense >= taxBrackets.at(minBracket).top) {
        totalTax += taxBrackets.at(minBracket++).maxTaxedNum;
    }
    
    double currentTax = 0;
    double totalIncome = 0;
    
    for (int i = minBracket; i < taxBrackets.size(); i++) {
        if (inRange((expense+totalTax), taxBrackets.at(i))) {
            totalIncome = fixedRateIncome(expense+totalTax-taxBrackets.at(i).bottom, taxBrackets.at(i).taxRate) + taxBrackets.at(i).bottom;
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
    
    this->requiredIncome = totalIncome;
    printf("Expenses: $%.02f\nRequired Income: $%.02f\n", expense, totalIncome);
    return totalIncome;
}

double TaxCalculator::fixedRateTax(double income, double taxRate) {
    double tax = (income * (1-taxRate));
    printf("Tax: $%.2f\n", tax);
    return tax;
}

double TaxCalculator::variableRateTax(double income) {
    int minBracket = 0;
    while (income > tb.getBrackets().at(minBracket).top) {
        minBracket++;
    }
    
    double totalTax = 0;
    
    for (int i = 0; i < minBracket; i++) {
        totalTax += tb.getBrackets().at(i).maxTaxedNum;
    }
    totalTax += (income - tb.getBrackets().at(minBracket).bottom) * tb.getBrackets().at(minBracket).taxRate;
    
    printf("Tax: $%.2f\n", totalTax);
    return totalTax;
}

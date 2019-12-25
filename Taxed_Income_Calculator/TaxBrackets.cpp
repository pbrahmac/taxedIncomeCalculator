#include "TaxBrackets.hpp"

TaxBrackets::TaxBrackets() {
    this->taxBrackets.push_back(Bracket(0,0,0));
}

TaxBrackets::TaxBrackets(vector<TaxBrackets::Bracket> brackets) {
    this->taxBrackets = brackets;
}

vector<TaxBrackets::Bracket> TaxBrackets::getBrackets() {
    return this->taxBrackets;
}

void TaxBrackets::printBrackets() {
    cout << "Bottom\t\tTop\t\t\tTax Rate\tMax Tax Num" << endl;
    for (int i = 0; i < taxBrackets.size(); i++) {
        //print bottom
        printf("%5d\t\t", taxBrackets.at(i).bottom);
        //print top
        if (taxBrackets.at(i).top == INT_MAX) {
            printf("inf.\t\t");
        } else {
            printf("%5d\t\t", taxBrackets.at(i).top);
        }
        //print tax rate
        printf("%5.5f\t\t", taxBrackets.at(i).taxRate);
        //print max tax num
        printf("%5.2f\n", taxBrackets.at(i).maxTaxedNum);
    }
    cout << endl;
}

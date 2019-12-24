#include "TaxBrackets.hpp"

TaxBrackets::TaxBrackets() {
    taxBrackets.push_back(Bracket(0,5,0.10));
    //second bracket
    taxBrackets.push_back(Bracket(5,10,0.12));
    //third bracket
    taxBrackets.push_back(Bracket(10,15,0.15));
    //fourth bracket
    taxBrackets.push_back(Bracket(15,20,0.18));
    //fifth bracket
    taxBrackets.push_back(Bracket(20,INT_MAX,0.2));
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

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
    cout << "Bottom\t\tTop\t\t\tTax Rate" << endl;
    for (int i = 0; i < taxBrackets.size(); i++) {
        //print bottom
        if (taxBrackets.at(i).bottom == 0) {
            cout << taxBrackets.at(i).bottom << "\t\t\t";
        } else {
            cout << taxBrackets.at(i).bottom << "\t\t";
        }
        //print top
        if (taxBrackets.at(i).top == INT_MAX) {
            cout << "inf." << "\t\t";
        } else {
            cout << taxBrackets.at(i).top << "\t\t";
        }
        //print tax rate
        cout << taxBrackets.at(i).taxRate << endl;
    }
    cout << endl;
}

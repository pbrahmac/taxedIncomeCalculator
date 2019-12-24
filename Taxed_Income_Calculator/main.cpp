// Programmer: Parjanya Brahmachari
// Programmer’s ID: 1726560

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TaxCalculator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    vector<TaxBrackets::Bracket> brackets;
//
//    ifstream federalBrackets("federal.txt");
//    string line;
//    string test, bottom, top, rate;
//    if (federalBrackets.is_open()) {
//        while (!federalBrackets.eof()) {
//            federalBrackets >> bottom;
//            federalBrackets >> top;
//            federalBrackets >> rate;
//
//            TaxBrackets::Bracket b(0,0,0);
//            if (top == "inf") {
//                b = TaxBrackets::Bracket(stoi(bottom), INT_MAX, stod(rate));
//            } else {
//                b = TaxBrackets::Bracket(stoi(bottom), stoi(top), stod(rate));
//            }
//            brackets.push_back(b);
//        }
//    } else {
//        cout << "Unable to open file." << endl;
//    }
//
//    TaxBrackets tb(brackets);
//    double expenses = 100000;
//    TaxCalculator(tb, expenses);
    
    // initialize tax bracket vector
    vector<TaxBrackets::Bracket> brackets;
    // populate vector
    brackets.push_back(TaxBrackets::Bracket(0, 19750, 0.1));
    brackets.push_back(TaxBrackets::Bracket(19750, 80250, 0.12));
    brackets.push_back(TaxBrackets::Bracket(80250, 171050, 0.22));
    brackets.push_back(TaxBrackets::Bracket(171050, 326000, 0.24));
    brackets.push_back(TaxBrackets::Bracket(326000, 414700, 0.32));
    brackets.push_back(TaxBrackets::Bracket(414700, 622050, 0.35));
    brackets.push_back(TaxBrackets::Bracket(622050, INT_MAX, 0.37));

    TaxBrackets tb(brackets);

    double expense = 100000;
    TaxCalculator(tb, expense);
}

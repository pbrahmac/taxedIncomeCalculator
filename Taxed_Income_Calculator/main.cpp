#include <iostream>
#include <fstream>
#include <string>
#include "TaxCalculator.hpp"

using namespace std;

vector<TaxBrackets::Bracket> fileReader(string);
vector<TaxBrackets::Bracket> combineBrackets(TaxBrackets, TaxBrackets);

int main(int argc, const char * argv[]) {
    
    
    TaxBrackets fb(fileReader("federal.txt")), sb(fileReader("california.txt")), cb(combineBrackets(fb, sb));
    TaxCalculator tc(cb);
    
    tc.variableRateIncome(200000);
    tc.variableRateTax(tc.getIncome());
}

vector<TaxBrackets::Bracket> fileReader(string fileName) {
    ifstream bracketsStream(fileName);
    vector<TaxBrackets::Bracket> brackets;
    string bottom, top, rate;
    
    if (bracketsStream.is_open()) {
        while (!bracketsStream.eof()) {
            bracketsStream >> bottom;
            bracketsStream >> top;
            bracketsStream >> rate;

            TaxBrackets::Bracket b(0,0,0);
            if (top == "inf") {
                b = TaxBrackets::Bracket(stoi(bottom), INT_MAX, stod(rate));
            } else {
                b = TaxBrackets::Bracket(stoi(bottom), stoi(top), stod(rate));
            }
            brackets.push_back(b);
        }
    } else {
        cout << "Unable to open file." << endl;
    }
    return brackets;
}

vector<TaxBrackets::Bracket> combineBrackets(TaxBrackets fb, TaxBrackets sb) {
    vector<TaxBrackets::Bracket> federal = fb.getBrackets(), state = sb.getBrackets(), combined;
    int bottom, top;
    double rate;

    for (int i = 0; i < federal.size(); i++) {
        for (int j = 0; j < state.size(); j++) {
            // get rid of erroneous ranges
            if (state[j].bottom > federal[i].top || state[j].top < federal[i].bottom) {
                continue;
            }
            // set bottom value
            if (state[j].bottom > federal[i].bottom) {
                bottom = state[j].bottom;
            } else {
                bottom = federal[i].bottom;
            }
            // set top value
            if (state[j].top < federal[i].top) {
                top = state[j].top;
            } else {
                top = federal[i].top;
            }
            // set rate
            rate = federal[i].taxRate + state[j].taxRate;
            // populate bracket and add to vector
            TaxBrackets::Bracket b(bottom, top, rate);
            combined.push_back(b);
        }
    }
    return combined;
}

#include <iostream>
#include <fstream>
#include <string>
#include "TaxCalculator.hpp"

using namespace std;

vector<TaxBrackets::Bracket> fileReader(string);
vector<TaxBrackets::Bracket> combineBrackets(TaxBrackets, TaxBrackets);

int main(int argc, const char * argv[]) {
    
    
    TaxBrackets fb(fileReader("federal.txt")), sb(fileReader("california.txt")), cb(combineBrackets(fb, sb));
    
//    vector<TaxBrackets::Bracket> combinedBrackets = combineBrackets(fb, sb);
//    combinedBrackets.push_back(TaxBrackets::Bracket(0, 16446, 0.11));
//    combinedBrackets.push_back(TaxBrackets::Bracket(16446, 19750, 0.12));
//    combinedBrackets.push_back(TaxBrackets::Bracket(19750, 38990, 0.14));
//    combinedBrackets.push_back(TaxBrackets::Bracket(38990, 61538, 0.16));
//    combinedBrackets.push_back(TaxBrackets::Bracket(61538, 80250, 0.18));
//    combinedBrackets.push_back(TaxBrackets::Bracket(80250, 85422, 0.28));
//    combinedBrackets.push_back(TaxBrackets::Bracket(85422, 107960, 0.30));
//    combinedBrackets.push_back(TaxBrackets::Bracket(107960, 171050, 0.313));
//    combinedBrackets.push_back(TaxBrackets::Bracket(171050, 326000, 0.333));
//    combinedBrackets.push_back(TaxBrackets::Bracket(326000, 414700, 0.413));
//    combinedBrackets.push_back(TaxBrackets::Bracket(414700, 551476, 0.443));
//    combinedBrackets.push_back(TaxBrackets::Bracket(551476, 622050, 0.453));
//    combinedBrackets.push_back(TaxBrackets::Bracket(622050, 661768, 0.473));
//    combinedBrackets.push_back(TaxBrackets::Bracket(661768, 1000000, 0.483));
//    combinedBrackets.push_back(TaxBrackets::Bracket(1000000, 1074996, 0.493));
//    combinedBrackets.push_back(TaxBrackets::Bracket(1074996, INT_MAX, 0.503));
    
    double expenses = 100000;
    TaxCalculator tc(cb, expenses);
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

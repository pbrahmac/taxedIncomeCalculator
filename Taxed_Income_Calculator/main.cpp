#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TaxCalculator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<TaxBrackets::Bracket> fBrackets;
    vector<TaxBrackets::Bracket> sBrackets;

    ifstream federalBrackets("federal.txt");
    string line;
    string bottom, top, rate;
    if (federalBrackets.is_open()) {
        while (!federalBrackets.eof()) {
            federalBrackets >> bottom;
            federalBrackets >> top;
            federalBrackets >> rate;

            TaxBrackets::Bracket b(0,0,0);
            if (top == "inf") {
                b = TaxBrackets::Bracket(stoi(bottom), INT_MAX, stod(rate));
            } else {
                b = TaxBrackets::Bracket(stoi(bottom), stoi(top), stod(rate));
            }
            fBrackets.push_back(b);
        }
    } else {
        cout << "Unable to open file." << endl;
    }
    
    ifstream stateBrackets("california.txt");
    if (stateBrackets.is_open()) {
        while (!stateBrackets.eof()) {
            stateBrackets >> bottom;
            stateBrackets >> top;
            stateBrackets >> rate;
            
            TaxBrackets::Bracket b(0,0,0);
            if (top == "inf") {
                b = TaxBrackets::Bracket(stoi(bottom), INT_MAX, stod(rate));
            } else {
                b = TaxBrackets::Bracket(stoi(bottom), stoi(top), stod(rate));
            }
            sBrackets.push_back(b);
        }
    }
    
    TaxBrackets fb(fBrackets), sb(sBrackets);
    cout << "Federal Brackets" << endl;
    fb.printBrackets();
    cout << endl << "State Brackets" << endl;
    sb.printBrackets();
    
    vector<TaxBrackets::Bracket> combinedBrackets;
    combinedBrackets.push_back(TaxBrackets::Bracket(0, 16446, 0.11));
    combinedBrackets.push_back(TaxBrackets::Bracket(16446, 19750, 0.12));
    combinedBrackets.push_back(TaxBrackets::Bracket(19750, 38990, 0.14));
    combinedBrackets.push_back(TaxBrackets::Bracket(38990, 61538, 0.16));
    combinedBrackets.push_back(TaxBrackets::Bracket(61538, 80250, 0.18));
    combinedBrackets.push_back(TaxBrackets::Bracket(80250, 85422, 0.28));
    combinedBrackets.push_back(TaxBrackets::Bracket(85422, 107960, 0.30));
    combinedBrackets.push_back(TaxBrackets::Bracket(107960, 171050, 0.313));
    combinedBrackets.push_back(TaxBrackets::Bracket(171050, 326000, 0.333));
    combinedBrackets.push_back(TaxBrackets::Bracket(326000, 414700, 0.413));
    combinedBrackets.push_back(TaxBrackets::Bracket(414700, 551476, 0.443));
    combinedBrackets.push_back(TaxBrackets::Bracket(551476, 622050, 0.453));
    combinedBrackets.push_back(TaxBrackets::Bracket(622050, 661768, 0.473));
    combinedBrackets.push_back(TaxBrackets::Bracket(661768, 1000000, 0.483));
    combinedBrackets.push_back(TaxBrackets::Bracket(1000000, 1074996, 0.493));
    combinedBrackets.push_back(TaxBrackets::Bracket(1074996, INT_MAX, 0.503));
    

    TaxBrackets tb(combinedBrackets);
    double expenses = 100000;
    TaxCalculator tc(tb, expenses);
}

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

bool processDFA(const string &input, int initialState, const set<int> &acceptStates, const map<pair<int, char>, int> &transitionTable) {
    int currentState = initialState;

    for (char symbol : input) {
        auto transition = transitionTable.find({currentState, symbol});
        if (transition == transitionTable.end()) {
            return false;
        }
        currentState = transition->second;
    }

    return acceptStates.find(currentState) != acceptStates.end();
}

int main() {
    int numStates = 4;
    int initialState = 1;
    set<int> acceptStates = {2};
    map<pair<int, char>, int> transitionTable = {
        {{1, 'a'}, 2},
        {{1, 'b'}, 3},
        {{2, 'a'}, 1},
        {{2, 'b'}, 4},
        {{3, 'a'}, 4},
        {{3, 'b'}, 1},
        {{4, 'a'}, 3},
        {{4, 'b'}, 2},
    };

    string input;
    cout << "Enter input string: ";
    cin >> input;

    if (processDFA(input, initialState, acceptStates, transitionTable)) {
        cout << "Valid string\n";
    } else {
        cout << "Invalid string\n";
    }

    cout << "\n--- Additional Tests ---\n";

    // Test 1
    string test1 = "011011011";
    bool isValid1 = true;
    for (size_t i = 0; i < test1.length(); ++i) {
        if (test1[i] == '0') {
            if (i + 2 >= test1.length() || test1[i + 1] != '1' || test1[i + 2] != '1') {
                isValid1 = false;
                break;
            }
        }
    }
    cout << "Test 1: " << (isValid1 ? "Valid" : "Invalid") << "\n";

    // Test 2
    string test2 = "abccba";
    bool isValid2 = (test2.front() == test2.back());
    cout << "Test 2: " << (isValid2 ? "Valid" : "Invalid") << "\n";

    // Test 3
    string test3 = "a1b2c3";
    bool isValid3 = islower(test3[0]);
    cout << "Test 3: " << (isValid3 ? "Valid" : "Invalid") << "\n";

    return 0;
}

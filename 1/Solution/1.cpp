#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {
    int f = 0;
    for (int i = 0; i < str.size(); i++) {
        f = 0;
        for (int j = 0; j < str.size(); j++) {
            if (str[i] == str[j] && i != j) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            return str[i];
        }
    }
    return str[0];
}
//
//  main.cpp
//  base_convertion
//
//  Created by Jakub Prokop on 08.11.2022.
//

#include <iostream>
#include <string>
#include <cmath>

#define BASE 16
typedef long long lint;

using namespace std;

string baseConvertion(lint n) {
    bool sign = false;
    if (n < 0) {
        n *= -1;
        sign = true;
    }
    lint k{n};
    int index{0};
    while (k/BASE) {
        k /= BASE;
        index++;
    }
    string str = "";
    if (sign)
        str += "-";
        
    for(int i = index; i >= 0; i--) {
        lint powe = pow(BASE, i);
        int coef = n / powe;
        n -= coef * powe;
        if(coef >= 10)
            str += '7' + coef;      //ASCII '7'=55, 'A'=65
        else
            str += coef + '0';
    }
    return str;
}

int main() {

    cout << "Enter number: ";
    lint n{};
    cin >> n;
    cout << baseConvertion(n) << "\n";
    
    return 0;
}

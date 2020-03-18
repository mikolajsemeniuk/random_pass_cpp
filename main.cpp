//
//  main.cpp
//  random_pass
//
//  Created by Mikołaj Semeniuk on 16/03/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <random>

using namespace std;

string random_password()
{
    int n = 14;
    printf("Podaj dlugosc hasla \n");
    cin >> n;
    if (n < 14)
        return "hasło powinno mieć conajmniej 14 znaków";
    
    string alphabet = "abcdefghij";
    string ALPHABET = "ABCDEFGHIJ";
    string s_symbol = "!@#$%^&*(";
    string numbers = "0123456789";
    
    char pass[n];
    for (int i = 0; i < n; i++)
    {
        int random_number = rand() % 4;
        
        char lower = alphabet[rand() % 10];
        char upper = ALPHABET[rand() % 10];
        char special = s_symbol[rand() % 10];
        char number = numbers[rand() % 10];
        
        if (random_number == 0)
            pass[i] = number;
        else if (random_number == 1)
            pass[i] = lower;
        else if (random_number == 2)
            pass[i] = special;
        else if (random_number == 3)
            pass[i] = upper;
    }
    // Shuffling our array
    unsigned seed = 0;
    shuffle(&pass[0], &pass[n - 1], default_random_engine(seed));
    
    return pass;
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << random_password() << "\n";
    return 0;
}

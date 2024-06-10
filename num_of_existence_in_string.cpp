#include <iostream>
#include <string>
#include <string.h>
#include "num_of_existence_in_string.h"
using namespace std;

int numExistenceInString(char c, std::string a) {                  
    int count = 0;
    for (int i=0; i<5; i++) {
        if ( a[i] == c ) {
            count += 1;
        }
    }
    return count;
}
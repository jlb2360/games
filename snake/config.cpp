#include "config.h"
#include <cstdio>
#include <iostream>


Config::Config(){
    printf("Enter your name\n");
    std::cin.getline(Name, 20);
    printf("Choose Difficulty:\n 1. Easy\n 2. Medium\n 3. Hard\n");
    std::cin>>Difficulty;

}

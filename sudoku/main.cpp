#include <iostream>
#include "config.h"

int main(){


    Config c = Config();

    std::cout<<"Hello "<<c.Name<<" You chose Difficulty "<<c.Difficulty<<std::endl;

    return 0;
}

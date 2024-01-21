#include "config.h"
#include <iostream>
#include "snake.h"




int main(){

    Config c = Config();

    std::cout<<"Your Name is: " << c.Name << " Difficulty Chosen: " << c.Difficulty << std::endl;


    Snake s = Snake();

    int fail = 0;
    int exit = 0;
    s.DrawBoard();
    while (fail == 0 && exit == 0){

        exit = s.Response();
        fail = s.Update();
        s.DrawBoard();

    }

    return 0;


}

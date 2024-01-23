#include "config.h"
#include <chrono>
#include <iostream>
#include "snake.h"
#include <thread>




int main(){

    Config c = Config();

    std::cout<<"Your Name is: " << c.Name << " Difficulty Chosen: " << c.Difficulty << std::endl;

    int time;


    switch (c.Difficulty) {
        case 1:
            time = 500;
            break;
        case 2:
            time = 350;
            break;
        case 3:
            time = 200;
            break;
        default:
            std::cout<<c.Difficulty<<std::endl;
            return 0;
            break;

    }



    Snake s = Snake();

    s.DrawBoard();
    int fail = 0;
    std::thread bt(&Snake::Response, &s);
    while (fail == 0){

        fail = s.Update();
        s.DrawBoard();

        std::cout<<c.Name<<" achieved a length of " << s.length << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(time));

    }
    std::cout<<"Game is Over press x-Enter"<<std::endl;
    s.SetExit();

    bt.join();



    return 0;


}

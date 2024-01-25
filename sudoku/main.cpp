#include <iostream>
#include "config.h"
#include "sudoku.h"

int main(){


    Config c = Config();

    std::cout<<"Hello "<<c.Name<<" You chose Difficulty "<<c.Difficulty<<std::endl;

    Puzzle puz = Puzzle(c.Difficulty);

    puz.Display();


    int solving = 1;
    int row;
    int col;
    int num;
    while (solving == 1){
        std::cout<<"Pick a row\n";
        std::cin>>row;
        std::cout<<"Pick a col\n";
        std::cin>>col;
        std::cout<<"Choose Number\n";
        std::cin>>num;


        int check = puz.Set(row, col, num);
        if (check ==1){
            std::cout<<"Answer was not valid\n";
        }

        check = puz.CheckSolve();
        if (check == 0){
            std::cout<<"Solved Puzzle!";
            break;
        }



    }

    return 0;
}

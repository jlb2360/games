#include "sudoku.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>


Puzzle::Puzzle(int g[9][9]){

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            grid[i][j] = g[i][j];
        }
    }
}

Puzzle::Puzzle(int Difficulty){
    srand(time(NULL));

    int init= 0;
    int rNum;
    int check = 1;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            grid[i][j] = init;
        }
    }

    int randr;
    int randc;
    int k;
    for (int i=0; i<17; i++){

        while (check==1){
            randr = rand()%9;
            randc = rand()%9;
            k = rand()%9+1;
            if (grid[randr][randc] ==0){
                grid[randr][randc] = k;
                check = CheckFail(randr, randc);
                if (check==1){
                    grid[randr][randc] = 0;
                }
            }
        }
        check = 1;
    }
    Display();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout<<"solving "<< std::endl;

    int solving = Solve(0,0);
    Display();
    if (solving==1){
        std::cout<<"No Solution"<<std::endl;
    } else {
        std::cout<<"Found Something"<<std::endl;
    }

}

void Puzzle::ProgressBar(int row, int col){
    int progress = (row*9)+col;
    std::cout<<"[";
    for (int i=0; i<progress; i++){
        std::cout<<"#";
    }

    for (int i=progress; i<81; i++){
        std::cout<<"-";
    }

    std::cout<<std::endl;
}

int Puzzle::Solve(int row, int col){
    //Display();
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (row == 9){
        return 0;
    } else if (col == 9){
        return Solve(row+1, 0);
    } else if (grid[row][col] != 0){
        return Solve(row, col+1);
    } else {
        for (int k=1; k<10; k++){
            grid[row][col] = k;
            if (CheckFail(row, col) == 0){
                if (Solve(row, col+1) == 0){
                    return 0;
                }
            }
            grid[row][col] = 0;
        }

        return 1;
    }

    return 1;

}

int Puzzle::CheckFail(int row, int col){


    int tCheck = grid[row][col];

    for (int j=0; j<9; j++){
        if (j==col){
            continue;
        }
        if (tCheck == grid[row][j]){
            return 1;
        }
    }

    for (int i=0; i<9; i++){
        if (i==row){
            continue;
        }
        if (tCheck == grid[i][col]){
            return 1;
        }
    }

    int secr = row/3;
    int secc = col/3;


    for (int i=secr*3; i<secr*3+3; i++){
        if (i == row){
            continue;
        }
        for (int j=secc*3; j<secc*3+3; j++){
            if (j==col){
                continue;
            }
            if (tCheck == grid[i][j]){
                return 1;
            }
        }
    }


    return 0;
}

void Puzzle::Display(){
    system("clear");

    for (int i=0; i<9; i++){
            if (i%3==0){
                std::cout<<"-----------------------"<<std::endl;
            }
            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"|";
        for (int j=0; j<9; j++){
            if (j%3 == 0){
                std::cout<<"|";
            }
            std::cout<<grid[i][j];
            std::cout<<"|";
        }
        std::cout<<"|";
        std::cout<<std::endl;
    }
    std::cout<<"-----------------------"<<std::endl;
}

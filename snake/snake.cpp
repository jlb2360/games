#include "snake.h"
#include <cstdlib>
#include <iostream>
#include <ctime>


Snake::Snake(){
    head = NULL;
    tail = NULL;
    length = 0;
    for (int i=0; i<20;i++){
        for (int j=0; j<20; j++){
            if (j == 0 || j == 19){
                Board[i][j] = '-';
            } else if (i == 0 || i == 19){
                Board[i][j] = '|';
            } else {
                Board[i][j] = ' ';
            }
        }
    }

    srand(time(NULL));

    int initx = rand()%18+1;
    int inity = rand()%18+1;
    int initdx = 0;
    int initdy = 0;
    int initPos[2] = {inity, initx};
    int initDir[2] = {initdy, initdx};
    std::cout<<head<<std::endl;
    InsertBody(initPos, initDir);

    CreateApple();
    exit = 0;
}


void Snake::ClearBoard(){
    for (int i=0; i<20;i++){
        for (int j=0; j<20; j++){
            if (j == 0 || j == 19){
                Board[i][j] = '-';
            } else if (i == 0 || i == 19){
                Board[i][j] = '|';
            } else {
                Board[i][j] = ' ';
            }
        }
    }
}

void Snake::CreateApple(){
    int initx = rand()%18+1;
    int inity = rand()%18+1;
    apple[0] = inity;
    apple[1] = initx;

}


void Snake::DrawBoard(){
    system("clear");
    ClearBoard();
    Node *p = head;
    while(p!=NULL){
        Board[p->pos[1]][p->pos[0]] = '0';
        p=p->next;
    }

    Board[apple[1]][apple[0]] = 'a';

    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++){
                std::cout << Board[j][i];
        }
        std::cout << std::endl;
    }

}



void Snake::InsertBody(int pos[2], int dir[2]){
    Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->pos[0] = pos[0];
    n->pos[1] = pos[1];
    n->dir[0] = dir[0];
    n->dir[1] = dir[1];
    std::cout<<head<<std::endl;
    if (head == NULL){
        head = n;
        tail = n;
        length++;
    } else{
       Node *temp;
       temp = tail;
       temp->next = n;
       n->prev = temp;
       tail = n;
       length++;
    }
}


int Snake::Update(){
    if (exit == 1){
        return 1;
    }
    Node *p = tail;

    while (p->prev != NULL){
        p->pos[0] = p->prev->pos[0];
        p->pos[1] = p->prev->pos[1];
        p->dir[0] = p->prev->dir[0];
        p->dir[1] = p->prev->dir[0];

        if (p->pos[0] == head->pos[0] + head->dir[0] && p->pos[1] == head->pos[1]+head->dir[1]){
            return 1;
        }

        p = p->prev;
    }

    p->pos[0] = p->pos[0] + p->dir[0];
    p->pos[1] = p->pos[1] + p->dir[1];

    //check if head hit apple or wall
    if (head->pos[0] == 0 || head->pos[0] == 19){
        return 1;
    } else if (head->pos[1] == 0 || head->pos[1] == 19){
        return 1;
    } else if (head->pos[0] == apple[0] && head->pos[1] == apple[1]){
        int uP[2] = {tail->pos[0]-tail->dir[0], tail->pos[1]-tail->dir[1]};
        int uD[2] = {tail->dir[0], tail->dir[1]};
        InsertBody(uP, uD);
        CreateApple();
    }

    return 0;
}


void Snake::Response(){

    while (exit == 0){
        char key;
        scanf("%s", &key);

        switch (key) {
            case 'w':
                head->dir[0]=-1;
                head->dir[1]=0;
                break;
            case 'a':
                head->dir[0]=0;
                head->dir[1]=-1;
                break;
            case 's':
                head->dir[0]=1;
                head->dir[1]=0;
                break;
            case 'd':
                head->dir[0]=0;
                head->dir[1]=1;
                break;
            case 'x':
                exit = 1;
                break;
            default:
                break;
        }
    }
}

void Snake::SetExit(){
    exit=1;
}

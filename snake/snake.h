
class Node{
public:
    int pos[2];
    int dir[2];
    Node *next;
    Node *prev;
};

class Snake{
    char Board[20][20];
    Node *head;
    Node *tail;
    int  apple[2];

public:
    Snake();
    void DrawBoard();
    void CreateApple();
    int Update();
    int Response();


private:
    void InsertBody(int pos[2], int dir[2]);
    void ClearBoard();



};

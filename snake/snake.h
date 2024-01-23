
class Node{
public:
    int pos[2];
    int dir[2];
    Node *next;
    Node *prev;
};

class Snake{
    Node *head;
    Node *tail;
    char Board[20][20];
    int  apple[2];
    int exit;

public:
    int length;
    Snake();
    void DrawBoard();
    void CreateApple();
    int Update();
    void Response();
    void SetExit();


private:
    void InsertBody(int pos[2], int dir[2]);
    void ClearBoard();



};

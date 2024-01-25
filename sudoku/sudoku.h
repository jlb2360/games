#include <cstdint>
class Puzzle{
    int grid[9][9];
    int solution[9][9];

    public:
        Puzzle(int difficulty);
        Puzzle(int g[9][9]);
        int Solve(int row, int col);
        int CheckFail(int row, int col);
        void Display();
        int Set(int row, int col, int num);
        int CheckSolve();

    private:
        void ProgressBar(int row, int col);
        void RemoveNum(int tG[9][9]);
        int CountNonZeros(int tG[9][9]);
};

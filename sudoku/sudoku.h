#include <cstdint>
class Puzzle{
    int grid[9][9];

    public:
        Puzzle(int difficulty);
        Puzzle(int g[9][9]);
        int Solve(int row, int col);
        int CheckFail(int row, int col);
        void Display();

    private:
        void ProgressBar(int row, int col);
};

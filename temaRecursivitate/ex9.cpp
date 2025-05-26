#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define MAXLINE 10
#define MAXCOL 10

struct KeyInfo 
{
    int lStart, cStart;
    int lFin, cFin; 
    int lineLength, colLength;
};


void getMaze(string fileName, int maze[MAXLINE][MAXCOL], KeyInfo &info);
bool solveMaze(int maze[MAXLINE][MAXCOL], int l, int c, vector<pair<int, int>> &path, int lineLength, int colLength);
//int findStart(int map[MAXLINE][MAXCOL]);

int main()
{
    
    //2 = poz initiala
    //3 = poz finala
    int n, m;
    int maze[MAXLINE][MAXCOL] = {};
    vector<pair<int, int>> path;
    KeyInfo info;
    getMaze("maze.txt", maze, info);
    solveMaze(maze, info.lStart, info.cStart, path, info.lineLength, info.colLength);
   
    for (int i = 0; i < path.size(); i++)
    {
        if (i == path.size() - 1)
        {
            cout << "(" << path[i].first << ", " << path[i].second << ")";    
        }
        else
            cout << "(" << path[i].first << ", " << path[i].second << "), ";
    }

    return 0;
}

// {1,1,1,1,1,1,1,1,1},
// {1,0,0,0,1,1,0,0,0},
// {1,1,1,2,1,1,1,1,0},
// {1,0,0,0,0,0,1,3,1},
// {1,1,1,0,1,0,0,0,1},
// {1,1,1,1,1,1,1,1,1}


void getMaze(string fileName, int maze[MAXLINE][MAXCOL], KeyInfo &info)
{
    ifstream mazeFile(fileName);
    char lLengthChar, cLengthChar;
    int k = 0;
    string aux;
    mazeFile.get(lLengthChar);
    mazeFile.get(cLengthChar);
    info.lineLength = lLengthChar - '0';
    info.colLength = cLengthChar - '0';
    
    

    for (int i = 0; i < info.lineLength; i++)
    {
        do {
            getline(mazeFile, aux);
        }   while (aux == "");
        k = 0;
        for (int j = 0; j < info.colLength; j++)
        {   
            if (aux[k] == -62 && aux[++k] == -79)
            {
                maze[i][j] = 1;
            }
            else if (aux[k] == 'I')
            {
                maze[i][j] = 2;
                info.lStart = i;
                info.cStart = j;
            }
            else if (aux[k] == 'F')
            {
                maze[i][j] = 3;
                info.lFin = i;
                info.cFin = j;
            }
            else if (aux[k] == ' ')
            {
                maze[i][j] = 0;
            }
            k++;
        }
    }
    mazeFile.close();
}

bool solveMaze(int maze[MAXLINE][MAXCOL], int l, int c, vector<pair<int, int>> &path, int lineLength, int colLength)
{
    if (l < 0 || c < 0 || l >= lineLength || c >= colLength || maze[l][c] == 1 || maze[l][c] == -1) //-1 = visited
    {
        return false;
    }

    if (maze[l][c] == 3)
    {
        path.push_back({l, c});
        return true;
    }

    path.push_back({l, c});

    int current = maze[l][c];
    maze[l][c] = -1; //-1 = visited

    if (solveMaze(maze, l, c - 1, path, lineLength, colLength) ||
        solveMaze(maze, l, c + 1, path, lineLength, colLength) ||
        solveMaze(maze, l - 1, c, path, lineLength, colLength) ||
        solveMaze(maze, l + 1, c, path, lineLength, colLength))
    {
        return true;
    }

    path.pop_back();
    maze[l][c] = current;
    return false;
}
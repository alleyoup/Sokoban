#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y;
int t_storageX[4], t_storageY[4];
int t_boxX[4], t_boxY[4];
int t_prevY[4], t_prevX[4];
int t_obstacleX[100], t_obstacleY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
bool xCountStart;
int iScore = 0;
bool xReloadLevel;
bool xleft, xright, xup, xdown;
int ilevels = 1;
const int iLevelsNumber = 3;
int iSumOfBoxes;
bool xLevelIsDone;
int  iBoxesDone;
int iSumofDone;
int iSumOfObstacles;
bool t_boxblocked[4];
bool t_xrightblocked[4];
bool t_xleftblocked[4];
bool t_xupblocked[4];
bool t_xdownblocked[4];
bool t_xrightclose[4];
bool t_xleftclose[4];
bool t_xupclose[4];
bool t_xdownclose[4];

void Setup()
{
    gameOver = false;
    xLevelIsDone = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    iBoxesDone = 0;
    iSumofDone = 0;
    xCountStart = false;
    gameOver = false;
    xReloadLevel = false;

    for (int k = 0; k < iSumOfBoxes; k++)
    {
        t_boxblocked[k] = false;
    }
}

void Levels()
{
    switch (ilevels)
    {
    case 1:
        iSumOfBoxes = 2;
        iSumOfObstacles = 9;
        t_storageX[0] = 0;
        t_storageY[0] = 10;
        t_storageX[1] = 0;
        t_storageY[1] = 11;
        t_boxX[0] = 15;
        t_boxY[0] = 7;
        t_boxX[1] = 15;
        t_boxY[1] = 15;
        t_obstacleX[0] = 3;
        t_obstacleY[0] = 9;
        t_obstacleX[1] = 3;
        t_obstacleY[1] = 10;
        t_obstacleX[2] = 3;
        t_obstacleY[2] = 11;
        t_obstacleX[3] = 3;
        t_obstacleY[3] = 12;
        t_obstacleX[4] = 3;
        t_obstacleY[4] = 13;
        t_obstacleX[5] = 4;
        t_obstacleY[5] = 9;
        t_obstacleX[6] = 5;
        t_obstacleY[6] = 9;
        t_obstacleX[7] = 4;
        t_obstacleY[7] = 13;
        t_obstacleX[8] = 5;
        t_obstacleY[8] = 13;
        break;

    case 2:
        iSumOfBoxes = 3;
        iSumOfObstacles = 27;
        t_storageX[0] = 10;
        t_storageY[0] = 10;
        t_storageX[1] = 12;
        t_storageY[1] = 11;
        t_storageX[2] = 14;
        t_storageY[2] = 12;
        t_boxX[0] = 18;
        t_boxY[0] = 2;
        t_boxX[1] = 18;
        t_boxY[1] = 4;
        t_boxX[2] = 18;
        t_boxY[2] = 6;
        t_obstacleX[0] = 6;
        t_obstacleY[0] = 9;
        t_obstacleX[1] = 7;
        t_obstacleY[1] = 9;
        t_obstacleX[2] = 8;
        t_obstacleY[2] = 9;
        t_obstacleX[3] = 9;
        t_obstacleY[3] = 9;
        t_obstacleX[4] = 10;
        t_obstacleY[4] = 9;
        t_obstacleX[5] = 11;
        t_obstacleY[5] = 9;
        t_obstacleX[6] = 12;
        t_obstacleY[6] = 9;
        t_obstacleX[7] = 13;
        t_obstacleY[7] = 9;
        t_obstacleX[8] = 14;
        t_obstacleY[8] = 9;
        t_obstacleX[9] = 15;
        t_obstacleY[9] = 9;
        t_obstacleX[10] = 6;
        t_obstacleY[10] = 10;
        t_obstacleX[11] = 6;
        t_obstacleY[11] = 11;
        t_obstacleX[12] = 6;
        t_obstacleY[12] = 12;
        t_obstacleX[13] = 6;
        t_obstacleY[13] = 13;
        t_obstacleX[14] = 7;
        t_obstacleY[14] = 13;
        t_obstacleX[15] = 8;
        t_obstacleY[15] = 13;
        t_obstacleX[16] = 9;
        t_obstacleY[16] = 13;
        t_obstacleX[17] = 10;
        t_obstacleY[17] = 13;
        t_obstacleX[18] = 11;
        t_obstacleY[18] = 13;
        t_obstacleX[19] = 12;
        t_obstacleY[19] = 13;
        t_obstacleX[20] = 13;
        t_obstacleY[20] = 13;
        t_obstacleX[21] = 14;
        t_obstacleY[21] = 13;
        t_obstacleX[22] = 15;
        t_obstacleY[22] = 13;
        t_obstacleX[23] = 16;
        t_obstacleY[23] = 13;
        t_obstacleX[24] = 17;
        t_obstacleY[24] = 13;
        t_obstacleX[25] = 11;
        t_obstacleY[25] = 11;
        t_obstacleX[26] = 17;
        t_obstacleY[26] = 12;

        break;


    case 3:
        iSumOfBoxes = 4;
        iSumOfObstacles = 8;
        t_storageX[0] = 10;
        t_storageY[0] = 10;
        t_storageX[1] = 10;
        t_storageY[1] = 11;
        t_storageX[2] = 12;
        t_storageY[2] = 10;
        t_storageX[3] = 12;
        t_storageY[3] = 11;
        t_boxX[0] = 2;
        t_boxY[0] = 5;
        t_boxX[1] = 6;
        t_boxY[1] = 5;
        t_boxX[2] = 10;
        t_boxY[2] = 5;
        t_boxX[3] = 14;
        t_boxY[3] = 5;
        t_obstacleX[0] = 3;
        t_obstacleY[0] = 10;
        t_obstacleX[1] = 4;
        t_obstacleY[1] = 10;
        t_obstacleX[2] = 5;
        t_obstacleY[2] = 10;
        t_obstacleX[3] = 6;
        t_obstacleY[3] = 10;
        t_obstacleX[4] = 3;
        t_obstacleY[4] = 16;
        t_obstacleX[5] = 4;
        t_obstacleY[5] = 16;
        t_obstacleX[6] = 5;
        t_obstacleY[6] = 16;
        t_obstacleX[7] = 6;
        t_obstacleY[7] = 16;

        break;

    default:

        break;
    }

}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";

            else
            {
                bool print = false;

                for (int k = 0; k < iSumOfBoxes; k++)
                {
                    if ((j == t_storageX[k]) && (i == t_storageY[k]))
                    {
                        cout << "x";
                        print = true;
                    }
                    if ((j == t_boxX[k]) && (i == t_boxY[k]))
                    {
                        cout << "X";
                        print = true;
                    }
                }
                for (int k = 0; k < iSumOfObstacles; k++)
                {
                    if ((j == t_obstacleX[k]) && (i == t_obstacleY[k]))
                    {
                        cout << "#";
                        print = true;
                    }
                }

                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:    " << iScore << "   " << "Level:   " << ilevels << endl;
    cout << "Reload Level : 'r'" << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'r':
            xReloadLevel = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = x;
    int prevY = y;

    for (int i = 0; i < iSumOfBoxes; i++)
    {
        t_prevY[i] = t_boxY[i];
        t_prevX[i] = t_boxX[i];
    }

    for (int i = 0; i < iSumOfBoxes; i++)
    {
        if (t_boxX[i] >= (width - 1)) t_boxX[i] = width - 1; else if (t_boxX[i] < 0) t_boxX[i] = 0;
        if (t_boxY[i] >= (height - 1))  t_boxY[i] = height - 1; else if (t_boxY[i] < 0)  t_boxY[i] = 0;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        xleft = true;

        break;
    case RIGHT:
        x++;
        xright = true;

        break;
    case UP:
        y--;
        xup = true;

        break;
    case DOWN:
        y++;
        xdown = true;

        break;
    default:
        break;
    }


    for (int i = 0; i < iSumOfBoxes; i++)
    {
        if (xright and (t_xrightblocked[i] or t_boxblocked[i]) and (t_xleftclose[i]))
        {
            x = prevX;
            xright = false;
        }
        if (xleft and (t_xleftblocked[i] or t_boxblocked[i]) and (t_xrightclose[i]))
        {
            x = prevX;
            xleft = false;
        }
        if (xdown and (t_xdownblocked[i] or t_boxblocked[i]) and (t_xupclose[i]))
        {
            y = prevY;
            xdown = false;
        }
        if (xup and (t_xupblocked[i] or t_boxblocked[i]) and (t_xdownclose[i]))
        {
            y = prevY;
            xup = false;
        }

    }


    if (x >= width)    x = prevX; else if (x < 0) x = prevX;
    if (y >= height)   y = prevY; else if (y < 0) y = prevY;


    for (int i = 0; i < iSumOfObstacles; i++)
    {
        if (x == t_obstacleX[i] and y == t_obstacleY[i])
        {
            x = prevX;
            y = prevY;
        }
    }
    for (int k = 0; k < iSumOfObstacles; k++)
    {
        for (int i = 0; i < iSumOfBoxes; i++)
        {
            if (((x == t_boxX[i]) && (y == t_boxY[i])) && (not t_boxblocked[i]) && (x < width - 1) && (y < height - 1) && (not (t_boxX[i] == t_obstacleX[k] and t_boxY[i] == t_obstacleY[k])))
            {
                if (xleft)
                {
                    t_boxX[i]--;
                    xleft = false;
                }
                else if (xright) {
                    t_boxX[i]++;
                    xright = false;
                }
                else if (xup)
                {
                    t_boxY[i]--;
                    xup = false;
                }
                else if (xdown)
                {
                    t_boxY[i]++;
                    xdown = false;
                }
            }
        }
    }


    for (int k = 0; k < iSumOfObstacles; k++)
    {
        for (int i = 0; i < iSumOfBoxes; i++)
        {
            if ((t_boxX[i] == t_obstacleX[k]) and (t_boxY[i] == t_obstacleY[k]))
            {
                t_boxY[i] = t_prevY[i];
                t_boxX[i] = t_prevX[i];
            }
        }
    }

    for (int k = 0; k < iSumOfObstacles; k++)
    {
        for (int i = 0; i < iSumOfBoxes; i++)
        {
            if (((t_boxX[i] == width - 1)) || ((t_boxX[i] == t_obstacleX[k] - 1) && (t_boxY[i]) == t_obstacleY[k]))  t_xrightblocked[i] = true; else  t_xrightblocked[i] = false;
            if ((t_boxX[i] == 0) || ((t_boxX[i] == t_obstacleX[k] + 1) && (t_boxY[i]) == t_obstacleY[k])) t_xleftblocked[i] = true; else  t_xleftblocked[i] = false;
            if ((t_boxY[i] == height - 1) || ((t_boxY[i] == t_obstacleY[k] - 1) && (t_boxX[i]) == t_obstacleX[k])) t_xdownblocked[i] = true; else  t_xdownblocked[i] = false;
            if ((t_boxY[i] == 0) || ((t_boxY[i] == t_obstacleY[k] + 1) && (t_boxX[i]) == t_obstacleX[k])) t_xupblocked[i] = true; else  t_xupblocked[i] = false;

            if ((x == t_boxX[i] - 1) and (y == t_boxY[i])) t_xleftclose[i] = true; else  t_xleftclose[i] = false;
            if ((x == t_boxX[i] + 1) and (y == t_boxY[i])) t_xrightclose[i] = true; else  t_xrightclose[i] = false;
            if ((y == t_boxY[i] + 1) and (x == t_boxX[i])) t_xdownclose[i] = true; else  t_xdownclose[i] = false;
            if ((y == t_boxY[i] - 1) and (x == t_boxX[i])) t_xupclose[i] = true; else  t_xupclose[i] = false;
        }
    }


    if (xLevelIsDone)
    {
        ilevels++;
        xLevelIsDone = false;
    }

    for (int i = 0; i < iSumOfBoxes; i++)
        for (int j = 0; j < iSumOfBoxes; j++)
        {
            if ((t_boxX[j] == t_storageX[i]) && (t_boxY[j] == t_storageY[i]))
            {
                t_boxblocked[j] = true;
                t_storageX[i] = width + j;
                t_storageY[i] = height + i;
                xCountStart = true;
            }
        }

    if (xCountStart)
    {
        iSumofDone = t_boxblocked[0] + t_boxblocked[1] + t_boxblocked[2] + t_boxblocked[3];
        iScore = iScore + 10;
        xCountStart = false;
    }
    if (iSumofDone == iSumOfBoxes)
    {
        gameOver = true;
        ilevels++;

    }
}

int main()
{
    for (int i = 0; i < iLevelsNumber; i++)
    {
        Setup();
        Levels();
        while (!gameOver)
        {
            if (xReloadLevel)
            {
                Levels();
                xReloadLevel = false;
            }

            Draw();
            Input();
            Logic();
            Sleep(5);
            dir = STOP;
            xleft = false;
            xright = false;
            xup = false;
            xdown = false;
        }
    }
    cout << "Game is over! Congratulations!" << endl;
    return 0;
}
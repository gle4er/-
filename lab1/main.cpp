#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

void zad1(int **arr, int clmn, int row)
{
//по правым диагоналям
    int *zad = new int [clmn * row];
    int i = clmn - 1, n = 0;
    for (int cnt = 0; cnt < clmn * row; cnt++) {
        if (i < clmn && n < row && i > -1 && n > -1) {
            zad[cnt] = arr[i][n];
            i++;
            n++;
        }
        else {
            int tmp = n;
            if (n > (i - 1)) {
                n = n - i + 1;
                i = clmn - tmp;
            }
            else {
                n = 0;
                i = clmn - 1 - tmp;
            }
            cnt--;
        }
    }
    free(zad);
    return;
}

void zad2(int **arr, int clmn, int row)
{
//по левым диагоналям
    int *zad = new int [clmn * row];
    int i = 0, tmp = 0, n = 0;
    for (int cnt = 0; cnt < clmn * row; cnt++) {
        if (i < clmn && n < row && i > -1 && n > -1) {
            zad[cnt] = arr[i][n];
            i--;
            n++;
        }
        else {
            if (tmp >= row) {
                n = tmp - row + 1;
                i = clmn - 1;
                tmp++;
            }
            else {
                i = n;
                tmp++;
                n = 0;
        }
            cnt--;
        }
    }
    free(zad);
    return;
}

void zad3(int **arr, int clmn, int row)
{
//по спирали от центра
    int *zad = new int [clmn * row];
    int dir = 0, m, i = (clmn - 1) / 2, n = (row - 1) / 2;
    double spur = 1;
    for (int cnt = 0; cnt < clmn * row;) {
        for (m = 0; m < floor(spur); m++) {
            zad[cnt] = arr[i][n];
            if (dir == 0 && i < clmn) 
                i++;
            if (dir == 1 && n < row) 
                n++;
            if (dir == 2 && i > -1)
                i--;
            if (dir == 3 && n > -1)
                n--;
            cnt++;
        }
        dir++;
        if (dir > 3)
            dir = 0;
        spur = spur + 0.5;
    }
    free(zad);
    return;
}

void zad4(int **arr, int clmn, int row)
{
//по спирали к центру
    int *zad = new int [clmn * row];
    int dir = 0, m, i = 0, n = 0;
    double spur = clmn - 1;
    for (int cnt = 0; cnt < clmn * row;) {
        for (m = 0; m < spur; m++) {
            zad[cnt] = arr[i][n];
            if (dir == 0 && i < clmn) 
                i++;
            if (dir == 1 && n < row) {
                n++;
                if (!m && spur != clmn - 1)
                    spur--;
            }
            if (dir == 2 && i > -1)
                i--;
            if (dir == 3 && n > -1) {
                n--;
                if (!m)
                    spur--;
            }
            cnt++;
        }
        dir++;
        if (dir > 3)
            dir = 0;
    }
    free(zad);
    return;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "enter correct nums of columns and rows" << endl;
        return 0;
    }
    int i, n;
    int **arr = new int* [atoi(argv[1])];
    for (i = 0; i < atoi(argv[1]); i++)
        arr[i] = new int [atoi(argv[2])];
    for (i = 0; i < atoi(argv[1]); i++)
        for (n = 0; n < atoi(argv[2]); n++)
            arr[i][n] = rand() % 10 + 1;
    zad1(arr, atoi(argv[1]), atoi(argv[2]));
    zad2(arr, atoi(argv[1]), atoi(argv[2]));
    zad3(arr, atoi(argv[1]), atoi(argv[2]));
    zad4(arr, atoi(argv[1]), atoi(argv[2]));
    return 0;
}


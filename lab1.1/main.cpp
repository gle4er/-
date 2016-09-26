#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout<<"entr a valid rand num of colums and rows (rnd)"<<endl;
        return 0;
    }
    srand(time(NULL));
    int i = rand() % atoi(argv[1]) + 1;
    int **arr = new int* [i];
    for (int tmp = 0; tmp < i; tmp++) {
        int n = rand() % atoi(argv[2]) + 1;
        arr[tmp] = new int [n];
        for (int tmp1 = 0; tmp1 < n; tmp1++) {
            arr[tmp][tmp1] = rand() % 10 + 1;
            cout<<arr[tmp][tmp1]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}


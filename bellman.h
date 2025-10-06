#include<iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>
#include <sstream>
#include <fstream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef BELLMAN_H
#define BELLMAN_H

void BF(int graph[][30], int Numver, char start, int BellmanFordValue[], int BellmanFordPrevious[]);
string BF_Path(int graph[][30], int num, char arv, char des);

#endif //BELLMAN_H
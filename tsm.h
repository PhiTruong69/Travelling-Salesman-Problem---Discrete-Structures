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
#ifndef TSM_H
#define TSM_H

void DP(int G[][30], int n, int start, vector<int> &path);
string Traveling(int G[][30], int n, char startVertex);
#endif
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include"Lib.h"

using namespace std;


int main(int argc, char* argv[])
{
	ReadFile(argv[1]);
	CountChar(argv[2]);
	CountWord(argv[2]);
	CountMainWord(argv[2]);
	return 0;
}
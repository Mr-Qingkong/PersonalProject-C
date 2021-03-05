#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include"Lib.h"

using namespace std;


int main(int argc, char* argv[])
{
	ReadFile("input.txt");
	CountChar("output.txt");
	CountWord("output.txt");
	CountMainWord("output.txt");
	return 0;
}
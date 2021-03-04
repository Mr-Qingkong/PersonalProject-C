#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int i;


void CountChar(string fName) //读取文件字符并统计
{
	char character;
	ifstream fin(fName);
	if (!fin)
	{
		cout << "open file error" << endl;//文件报错
	}
	else
	{
		while (fin.get(character))
		{
			++i;
		}
		cout << "characters：" << i << endl;//输出字符统计数
	}
}
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int i;


void CountChar(string fName) //��ȡ�ļ��ַ���ͳ��
{
	char character;
	ifstream fin(fName);
	if (!fin)
	{
		cout << "open file error" << endl;//�ļ�����
	}
	else
	{
		while (fin.get(character))
		{
			++i;
		}
		cout << "characters��" << i << endl;//����ַ�ͳ����
	}
}
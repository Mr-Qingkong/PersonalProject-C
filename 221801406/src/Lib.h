#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int charNum = 0;
int lineNum = 0;
string temp;
vector<string> str;
vector<string> words;
map<string, int> strmap;

void ReadFile(string fName) //读取文件并缓存
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
			temp += character;
			++charNum;
		}
	}
}


void CountChar(string fName) //统计文件字符
{
	ReadFile(fName);
	cout << "characters：" << charNum << endl;//输出字符统计数
}


void CountWord(string fName)//统计单词数以及行数函数
{
	string tempLetterNum;
	string tempLine;
	int j;

	for (j = 0; j < charNum; j++)
	{
		if (temp[j] == '\n')
		{
			for (int i = 0; i != temp.size(); i++)
			{
				if (tempLine[i] > 32)//根据题目要求认为ascii码大于32视为非空白字符，下同
				{
					++lineNum;
					break;
				}
			}
			tempLine.clear();
		}
		else
		{
			tempLine += temp[j];
		}

		if ((temp[j] >= '0' && temp[j] <= '9') ||
			(temp[j] >= 'A' && temp[j] <= 'Z') ||
			(temp[j] >= 'a' && temp[j] <= 'z'))//储存字母数字符号
		{
			tempLetterNum += temp[j];
		}
		else
		{
			if (tempLetterNum != "")
			{
				str.push_back(tempLetterNum);
				tempLetterNum.clear();
			}
		}
	}
	if (tempLetterNum != "")
	{
		bool unBlank;
		for (int i = 0; i < tempLetterNum.size(); i++)
		{//检验非空白字符行
			if (tempLetterNum[i] > 32)
				unBlank = true;
		}
		if (unBlank == true)
			++lineNum;

		str.push_back(tempLetterNum);
		tempLetterNum.clear();
	}

	for (j = 0; j < str.size(); j++)
	{//字符串开头四个字符均为字母才能视作单词
		bool unBlank = false, isLetter = false;
		for (int i = 0; i < str[j].size(); i++)
		{
			if (str[j][i] > 32)
				unBlank = true;
		}
		if ((str[j][0] >= 'a' && str[j][0] <= 'z')
			&& (str[j][1] >= 'a' && str[j][1] <= 'z')
			&& (str[j][2] >= 'a' && str[j][2] <= 'z')
			&& (str[j][3] >= 'a' && str[j][3] <= 'z'))
		{
			unBlank = true;
			isLetter = true;
		}

		if ((str[j].size() > 3) && (unBlank == true) && (isLetter == true))
		{
			words.push_back(str[j]);
		}
	}
	cout << "words: " << words.size() << endl;

	for (j = 0; j < words.size(); j++)
	{
		++strmap[words[j]];
	}


	cout << "lines: " << lineNum << endl;//输出

}



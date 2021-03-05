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
map<string, int>::iterator iter;
string mainWord;
int max;


void ReadFile(string fName) //��ȡ�ļ�������
{
	char character;
	ifstream fin(fName);
	if (!fin)
	{
		cout << "open file error" << endl;//�ļ��򿪷�������
	}
	else
	{
		while (fin.get(character))
		{
			if (character >= 'A' && character <= 'Z')
			{
				character += 32;
			}
			temp += character;
			++charNum;
		}
	}
	fin.close();
}


void CountChar(string foutName) //����ַ�ͳ����
{
	ofstream fout(foutName);
	fout << "characters��" << charNum << endl;
	fout.close();
}


void CountWord(string foutName)//ͳ�Ƶ������Լ���������
{
	ofstream fout(foutName, ios::app);//ע��Ҫʹ��׷�ӷ�ʽ���ļ�
	string tempLetterNum;
	string tempLine;
	int j;

	for (j = 0; j < charNum; j++)
	{
		if (temp[j] == '\n')
		{
			for (int i = 0; i != temp.size(); i++)
			{
				if (tempLine[i] > 32)//������ĿҪ����Ϊascii�����32��Ϊ�ǿհ��ַ�����ͬ
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
			(temp[j] >= 'a' && temp[j] <= 'z'))//������ĸ���ַ���
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
		{//����ǿհ��ַ���
			if (tempLetterNum[i] > 32)
				unBlank = true;
		}
		if (unBlank == true)
			++lineNum;

		str.push_back(tempLetterNum);
		tempLetterNum.clear();
	}

	for (j = 0; j < str.size(); j++)
	{//�ַ�����ͷ�ĸ��ַ���Ϊ��ĸ������������
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
	fout << "words: " << words.size() << endl;
	fout << "lines: " << lineNum << endl;
	fout.close();

	for (j = 0; j < words.size(); j++)
	{
		++strmap[words[j]];
	}
}


void CountMainWord(string foutName)//��Ƶͳ����Ƶ������ǰʮ�������
{
	ofstream fout(foutName, ios::app);
	int time;
	bool flag = true;
	iter = strmap.begin();
	int min_val = strmap.size() < 10 ? strmap.size() : 10;
	for (int s1 = 0; s1 < min_val; s1++)//���ñ���10�εĵķ�ʽ���������ʮ��boolֵ��false����ѭ��
	{
		if (flag == false)
		{
			break;
		}
		flag = true;
		time = -1;
		while (iter != strmap.end())//����map���д�ȡ����
		{
			if (iter->second > time)
			{
				time = iter->second;
				mainWord = iter->first;
			}
			iter++;
		}
		fout << mainWord << ": " << time << endl;
		iter = strmap.begin();
		strmap[mainWord] = -9;
	}
	fout.close();
}

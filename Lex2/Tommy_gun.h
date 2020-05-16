#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>



using namespace std;

ifstream in("Automate.txt");




class Tommy_gun
{
public:
	Tommy_gun() {}
	string tokenClass;
	set<string> alph; //входной алфавит
	set<string> start; //стартовые состояния
	set<string> All;//допустимые состояния алфавита
	set<string> end;//заключительные состояния
	map<string, map<string, set<string>>> ConversionTable; //таблица переходов
	string alphstring = "";
	int priority;


	void initAutomate()
	{
		int k = 0;
		string s;
		string tmp;
		if (in.peek() == '{')
		{
			do
			{
				in >> tmp;
			} while (in.peek() != '\n');

		}
		if (in.peek() != '{')
		{

			do
			{
				in >> s;
				priority = atoi(s.c_str());
			} while (in.peek() != '\n');

			do
			{
				in >> s;
				alphstring += s;
				alph.insert(s);
			} while (in.peek() != '\n');

			do
			{
				in >> s;
				All.insert(s);
			} while (in.peek() != '\n');

			do
			{
				in >> s;
				start.insert(s);
			} while (in.peek() != '\n');

			do
			{
				in >> s;
				end.insert(s);
			} while (in.peek() != '\n');

			string start, jump, end;

			do
			{
				in >> start >> jump;
				if (start != "}")
					in >> end;
				ConversionTable[start][jump].insert(end);
			} while (start != "}");

			tmp = "";

		}

	}


	pair<bool, int> maxString(Tommy_gun A, string str, int k)
	{
		pair<bool, int> result;
		result.first = false;
		result.second = 0;
		set<string> currentStates = A.start;
		set<string> ::iterator itCurSt, itEndSt;
		for (itCurSt = currentStates.begin(); itCurSt != currentStates.end(); itCurSt++)
		{
			for (itEndSt = A.end.begin(); itEndSt != A.end.end(); itEndSt++)
				if (*itCurSt == *itEndSt)
					result.first = true;
		}

		int i = k;
		int len = str.length();

		while (i < len)
		{
			set<string> ::iterator itAlph;
			bool flag = false;
			string tmp;
			tmp = str[i];
			for (itAlph = A.alph.begin(); itAlph != A.alph.end(); itAlph++)
				if (tmp == *itAlph)
					flag = true;
			if (!flag)
			{

				break;
			}
			else
			{
				set<string> newCurrentStates;
				set<string> ::iterator itSt;
				for (itSt = currentStates.begin(); itSt != currentStates.end(); itSt++)
				{
					for (auto it = A.ConversionTable[*itSt][tmp].begin(); it != A.ConversionTable[*itSt][tmp].end(); it++)
					{
						newCurrentStates.insert(*it);
					}
				}
				currentStates = newCurrentStates;
				for (itCurSt = currentStates.begin(); itCurSt != currentStates.end(); itCurSt++)
				{
					for (itEndSt = A.end.begin(); itEndSt != A.end.end(); itEndSt++)
						if (*itCurSt == *itEndSt)
						{
							result.first = true;
							result.second = i - k + 1;
						}
				}
				i++;
			}
		}
		return result;
	}
	
};


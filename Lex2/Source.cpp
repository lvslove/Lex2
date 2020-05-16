#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include"Token.h"
#include"Tommy_gun.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "RUS");

	vector<Tokens> tokens;
	while (tokIn.peek() != EOF)
	{
		Tokens T;
		T.initToken();
		tokens.push_back(T);
	}
	vector<Tommy_gun> machines;
	int amount = 0;
	while (in.peek() != EOF)
	{
		Tommy_gun A;
		A.initAutomate();
		for (int i = 0; i < tokens.size(); i++) //определяем к какому классу токенов относится данный автомат
			if (tokens[i].priorit == A.priority)
			{
				tokens[i].Automates.push_back(A);
				A.tokenClass = tokens[i].name;
			}
		machines.push_back(A);
		amount++;
	}
	
	
	string str;
	cout << endl << "Введите входную строку :" << endl;
	getline(cin, str);


	int lastPosSpace = 0, currentPosSpace = 0;
	int i = 0;
	while (i < str.size())
	{
		
		
		
			currentPosSpace = str.find(" ", lastPosSpace);//считываем их
			string newStr = str.substr(lastPosSpace, currentPosSpace - lastPosSpace);//вырезаем истроку до пробела
			vector< pair<bool, int>> results(machines.size());
			int index = 0, maxSize = 0;
			bool flag = false;
			//проходим по всем автоматам
			for (int j = 0; j < machines.size(); j++)
			{
				results[j] = machines[j].maxString(machines[j], newStr, 0); //вызываем Maxstring
				if (results[j].first && results[j].second == newStr.size()) //try и длина строки = длинне слова
				{
					flag = true; //если есть элементы 
					if (results[j].second > maxSize) //ищем максимальный результат и запоминаем этот автомат
					{
						maxSize = results[j].second;
						index = j;
					}
					else if (results[j].second == maxSize) //выбор с наибольшего приоритета
					{
						if (machines[j].priority > machines[index].priority)
						{
							index = j;
						}
					}
					
				}
			}

			if (flag) //если вырезаемая строка является заранее заданным автоматом
			{
				cout << "<" << machines[index].alphstring << ", " << machines[index].tokenClass << ">" << endl;
				
			}
			else 
			{
				cout << "<" << newStr << ", ";
				for (int i = 0; i < tokens.size(); i++)
					if (tokens[i].priorit == 0)
					{
						cout << tokens[i].name << ">" << endl;
						break;
					}
			}
			
			
			for (int i = 0; i < tokens.size(); i++) {
				
				cout << "< " ",space>" << endl;
				break;
			}
				


			
			
			
			
				
			lastPosSpace = currentPosSpace + 1; //запоминаем позицию пробела
			i += newStr.size() + 1;
		
	
	}
	system("pause");
}
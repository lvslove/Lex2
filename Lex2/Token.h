#pragma once
#include"Tommy_gun.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream tokIn("tok.txt");

class Tokens
{
public:
	vector<Tommy_gun> Automates;
	int priorit;
	string name;

	void initToken()
	{
		do
		{
			tokIn >> name >> priorit;
		} while (tokIn.peek() != '\n' && tokIn.peek() != EOF);
	}
};
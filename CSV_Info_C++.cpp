//
//Ricardo Martinez
// Description:
// This program will read a csv file that was given and will ask the user if they want
// information from 51 states, including Washington D.C. When they enter a state they
// will be given the percentages of Coal, Natural Gas, Petroleum, Nuclear, Renewable, and 
// the total that the state consumes. Details such as using the precision tool are used
// so the given information has two digits after the decimal point. When the user is done
// they can type 'q' to exit the program.  *I was able to fix the calculations*
#include<iostream>
#include <cstring>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Information
{
	double Coal,NatGas,Petroleum,Nuclear,Renewable,Total;
	string state;
};
void readData(ifstream &file, vector<Information>& DataNum, int InfoNum);
int main()
{
	std::ifstream file("2015Data.csv");
	vector<Information> DataNum;
	readData(file, DataNum, 51);
	string user;


	while (1)
	{
		cout << "Enter the name of a state or q to exit:\n";
		cin >> user;
		if (user == "q") break;
		for (int k = 0; k<DataNum.size(); k++)
		{
			Information info = DataNum[k];
			if (info.state == user)
			{
				std::cout << std::setprecision(2) << std::fixed;
				cout << "Coal : " << info.Coal *100.0 / info.Total << "%\n";
				cout << "NaturalGas : " << info.NatGas *100.0 / info.Total << "%\n";
				cout << "Petroleum : " << info.Petroleum *100.0 / info.Total << "%\n";
				cout << "Nuclear : " << info.Nuclear *100.0 / info.Total << "%\n";
				cout << "Renewable : " << info.Renewable *100.0 / info.Total << "%\n";
				break;
			}
		}
	}
	return 0;
}


void readData(ifstream &file, vector<Information>& DataNum, int InfoNum)
{

	std::string line = " ";
	int row = 0;
	while (getline(file, line))
	{
		row++;
		if (row == 1) continue;
		if (row - 1 > InfoNum) break;
		std::vector<std::string> vec;



		for(char *p = strtok((char*)line.c_str(), ", \n"); p != NULL; p = strtok(NULL, ", \n"))
		{
			vec.push_back(string(p));

		}


		Information info;
		info.state = vec[0];

		info.Coal = atof(vec[1].c_str());

		info.NatGas = atof(vec[2].c_str());

		info.Petroleum = atof(vec[3].c_str()) + atof(vec[4].c_str()) + atof(vec[5].c_str()) +
			atof(vec[6].c_str()) + atof(vec[7].c_str());

		info.Nuclear = atof(vec[8].c_str());

		info.Renewable = atof(vec[9].c_str()) + atof(vec[10].c_str()) + atof(vec[11].c_str())
			+ atof(vec[12].c_str()) + atof(vec[13].c_str()) + atof(vec[14].c_str());

		info.Total = info.Coal + info.NatGas + info.Petroleum + info.Nuclear + info.Renewable;
		DataNum.push_back(info);

	}



	file.close();
	system("pause");

}

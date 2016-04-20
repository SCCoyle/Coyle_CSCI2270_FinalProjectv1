#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "market.h"

using namespace std;


int menu()
{
	//visual menu
	cout << "======Main Menu======" << endl;
	cout << "1. Print Inventory" << endl;
	cout << "2. Time Statistics" << endl;
	cout << "3. Buy a Product" << endl;
	cout << "4. Quit" << endl; 
	
	//converting the users choice
	int choice;
	string choiceS;
	getline(cin,choiceS);
	stringstream choiceConvert(choiceS);
	choiceConvert >> choice;
	
	return choice;
}

void newSettings(market * coinMarket)
{
	//opening the settings file
	string settings = "settings.txt";
	ifstream settingsFile;
	settingsFile.open(settings.c_str());
	
	//If file opening doesn't work this happens 
	if(!settingsFile)
	{
		cout << "settings opening unsuccessful" << endl;
	}
	//parsing the file 
	
	//initalizing the variables
	double decay;
	string decayS;
	bool recency;
	string recencyS;
	bool max;
	string maxS;
	double maxP;
	string maxPS;
	
	//storing the settigns in the string versions of the settings
	getline(settingsFile,decayS);
	getline(settingsFile,decayS,':');
	getline(settingsFile,decayS);
	getline(settingsFile,recencyS,':');
	getline(settingsFile,recencyS);
	getline(settingsFile,maxS,':');
	getline(settingsFile,maxS);
	getline(settingsFile,maxPS,':');
	getline(settingsFile,maxPS);
	
	//Converting all of the strings to the appropriate type
	stringstream decayConvert(decayS);
	decayConvert >> decay;
	stringstream recencyConvert(recencyS);
	recencyConvert >> recency;
	stringstream maxConvert(maxS);
	maxConvert >> max;
	stringstream maxPConvert(maxPS);
	maxPConvert >> maxP;
	
	//Setting the settings values
	coinMarket->addSettings(decay,recency,max,maxP);
//	cout << "b" << endl;
	
}

void newProducts(market * coinMarket)
{
	//opening the products file
	string products = "Products.txt";
	ifstream productsFile;
	productsFile.open(products.c_str());
	
	//If file opening doesn't work this happens 
	if(!productsFile)
	{
		cout << "file opening unsuccessful " << endl;
	}
	string inLine;
	getline(productsFile,inLine);
	while(!productsFile.eof())
	{
		string name;
		//____s versions of names is where the getline of the variable is stored before being converted
		int quantity;
		string quantityS;
		double price;
		string priceS;
		double cost;
		string costS;
		
		//parsing the line
		getline(productsFile,name,',');
		getline(productsFile,quantityS,' ');
		getline(productsFile,priceS,' ');
		getline(productsFile,costS);
		
		//converting the varibles
		stringstream quantityConvert(quantityS);
		quantityConvert >> quantity;
		
		stringstream priceConvert(priceS);
		priceConvert >> price;
		
		stringstream costConvert(costS);
		costConvert >> cost;
		
		//giving it to the addProduct method
		if(name != "")
		{
			coinMarket->addProducts(name,quantity,price,cost);
		}
	}
}

void newUser(market *coinMarket)
{
	cout << "What is your name?" << endl;
	string userName;
	getline(cin,userName);	cout << "Enter a password" << endl;
	string password;
	getline(cin,password);	cout << "How much is in your wallet? " << endl;
	double wallet;
	string walletS;
	getline(cin,walletS);
	stringstream walletConvert(walletS);
	walletConvert >> wallet;
	coinMarket->addNewUser(userName,password, wallet);
}
int main(int argc, char **argv)
{
	market *coinMarket = new market();
	newSettings(coinMarket);
	newProducts(coinMarket);
	newUser(coinMarket);
	bool interfaceKill = 0;
	while(!interfaceKill)
	{
		int choice = menu();
		switch(choice)
		{
			case 1:
			{
				cout << "1. Print Inventory" << endl;
				coinMarket->printProductsSafe();
				break;
			}
			case 2:
			{
				cout << "2. Time Stats" << endl;
				coinMarket->timeStats();
				break;
			}
			case 3:
			{
				cout << "Enter a Coin:" << endl;
				string coinName;
				getline(cin,coinName);
				coinMarket->buyProduct(coinName);
				break;
			}
			case 4:
			{
				cout << "4. Quit" << endl;
				break;
			}
		}
		
	}
	
	return 0;
	
}

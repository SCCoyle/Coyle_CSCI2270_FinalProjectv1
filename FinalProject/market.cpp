#include "market.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>

market::market()
{
}

market::~market()
{
}

int market::checkNumber(std::string number)
{
	int length = number.length();
	int nonSNumber;
	bool nonNumberChar = 0;
	for(int numberIndex = 0; numberIndex < length; numberIndex++)
	{
		bool currentCharNaN = 1;
		for(int numberToCheck = 1; numberToCheck < 11; numberToCheck++)
		{
			if(number[numberIndex] == numberToCheck)
			{
				currentCharNaN == 0;
			}
		}
		if(currentCharNaN)
		{
			nonSNumber = -1;
		}
	}
	if(number.length() > 10)
	{
		nonSNumber = -1;
	}
	else
	{
		std::stringstream convert(number);
		convert >> nonSNumber;
	}
	/*return codes 
	 * -1 not a number
	 * non negative number the number is actual number
	*/
	return nonSNumber;
}

void market::addProducts(std::string name,int quantity, double price, double cost)
{
//	std::cout << name << " " << quantity << " " << price << " " << cost << std::endl;
	product *newProduct = new product(name,quantity,price,cost,time(&(settingsStorage.startTime)));
	product *temp = root;
	if(root == NULL)
	{
//		std::cout << "z" << std::endl;
		root = newProduct;
	}
	else
	{
		//while loop ender
		bool kill = 0;
		while(!kill)
		{
//			std::cout << "a" << std::endl;
			// if the title comes earlier in the alphabet
			if(newProduct->name < temp->name)
			{
//				std::cout << "b" << std::endl;
				//if there is no childe to the one compared to make the new one hte child
				if(temp->left == NULL)
				{
//					std::cout << "c" << std::endl;
					//linking the nodes to eachother
					temp->left = newProduct;
					newProduct->parent = temp;
					//end the while loop
					kill = 1;
				}
				// if there is a child there move down the tree
				else
				{
//					std::cout << "d" << std::endl;
					temp = temp->left;
				}
			}
			else //same execution as above on if it is greater
			{
///				std::cout << "d" << std::endl;
				if(temp->right == NULL)
				{
//					std::cout << "e" << std::endl;
					temp->right = newProduct;
					newProduct->parent = temp;
					kill = 1;
				}
				else
				{
//					std::cout << "f" << std::endl;
					temp = temp->right;
				}
			}
		}
	}
/*	std::cout  
		<< "Parent: " << newProduct->parent << " "
		<< "Address: " << newProduct << " "
		<< "Left: " << newProduct->left << " "
		<< "Right: " << newProduct->right
		<< " " << newProduct->name
		<< " " << newProduct->cost
		<< " " << newProduct->price
		<< std::endl;	
		std::cout  << "Root: "
		<< "Parent: " << root->parent << " "
		<< "Address: " << root << " "
		<< "Left: " << root->left << " "
		<< "Right: " << root->right
		<< " " << root->name
		<< " " << root->cost
		<< " " << root->price
		<< std::endl;
*/
}

void market::addSettings(double decay, double decayBase, bool recency, bool max, double maxP,double postMultiplier)
{
	settingsStorage.decayRate = -1 * decay;
	settingsStorage.decayRateBase = decayBase;
	settingsStorage.recencyDetection = recency;
	settingsStorage.maxPrice = max;
	settingsStorage.maxPriceMultiplier = maxP;
	time_t startTime;
	settingsStorage.startTime = time(&startTime);
	lastTimeCheck = startTime;
	settingsStorage.postBuyMultiplier = postMultiplier;
//	std::cout << "Start time: " << startTime << std::endl;
}

void market::buyProduct(std::string name)
{
	product *temp = findProduct(name);
	if(temp != NULL)
	{
		if(temp->quantity != 0)
		{
			(temp->quantity)--;
			if(currentUser->wallet > temp->price)
			{
				currentUser->wallet = currentUser->wallet - temp->price;
				double salePrice = temp->price;
				std::cout << "You have " << currentUser->wallet << " dollars left in your wallet." << std::endl;
				if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
				{
					temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
				}
				temp->lastSold = time(&settingsStorage.startTime);
				purchase *newPurchase = new purchase(time(&settingsStorage.startTime),currentUser,temp,salePrice);
				temp->price = temp->price*(settingsStorage.postBuyMultiplier);
				std::cout << "The new price is: " << temp->price << std::endl;
				purchaseBlockChain *newBlock = new purchaseBlockChain(newPurchase);
				personalPurchase *newPersonalPurchase = new personalPurchase(newPurchase);
				currentUser->purchases.push_back(newPersonalPurchase);
				blockChain.push_back(newBlock);
			}
			else
			{
				std::cout << "There is not enough money in your wallet" << std::endl;
			}
		}
		else
		{
			std::cout << "There are no " << name << "s left in stock" << std::endl;
		}
	}
	else
	{
		std::cout << "Product not found" << std::endl;
	}
}

void market::printProducts(product *node)
{
	product *temp = node;
//	std::cout << root->right << std::endl;
	if(temp->left != NULL)
	{
		printProducts(temp->left);
	}
	if(temp->name != "")
	{
		if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
		{
			temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
		}
		temp->lastSold = time(&settingsStorage.startTime);
		std::cout << "Name: "<< temp->name  << std::endl << "Price: "<< temp->price << std::endl; 
	}
	if(temp->right != NULL)
	{
		printProducts(temp->right);
	}
}

void market::printProductsSafe()
{
	printProducts(root);

}

product * market::findProduct(std::string name)
{
	//finding the product
	product * temp = root;
	int found = 0;
	while(!found)
	{
		if(temp->name == name)
		{
			found = 1;
		}
		else
		{
			if(temp->name > name)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					found = 2;
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					found = 2;
				}
			}
		}
	}
	if(found == 2)
	{
		temp = NULL;
	}
	return temp;
}

void market::timeStats()
{
	std::cout << "Current time: " << time(&settingsStorage.startTime) <<std::endl;  
	std::cout << "Last time check was  " << time(&settingsStorage.startTime) - lastTimeCheck << " seconds ago" <<std::endl;
	lastTimeCheck = time(&settingsStorage.startTime);
}

void market::addNewUser(std::string name, std::string password, double wallet)
{
	userInfo *newUser = new userInfo(name,password,wallet);
	if(!currentUser)
	{
		currentUser = newUser;
	}
//	std::cout << "test0" << std::endl;
	users.push_back(newUser);
	std::cout << "User Added" << std::endl;
}

void market::printProfit(product * node)
{
	product *temp = node;
//	std::cout << root->right << std::endl;
	if(temp->left != NULL)
	{
		printProfit(temp->left);
	}
	if(temp->name != "")
	{
		if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
		{
			temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
		}
		temp->lastSold = time(&settingsStorage.startTime);
		std::cout << "Name: "<< temp->name  << std::endl << "Profit: "<< temp->profit << std::endl; 
	}
	if(temp->right != NULL)
	{
		printProfit(temp->right);
	}
}
void market::totalProfit()
{
	totalProfit(blockChain);
}
void market::totalProfit(std::vector<purchaseBlockChain*> blockChain)
{	
	int blockChainSize = blockChain.size();
	for(int blockChainIndex = 0; blockChainIndex < blockChainSize; blockChainIndex++)
	{
		product *currentProduct = blockChain[blockChainIndex]->purchaseEvent->item;
		double salePrice = blockChain[blockChainIndex]->purchaseEvent->cost;
//		std::cout << currentProduct->cost << " " << salePrice << std::endl;
		currentProduct->profit = salePrice - currentProduct->cost;
	}
	printProfit(root);
}

void market::addMoney()
{
	std::cout << "How much would you like to add " << currentUser->name << "?" << std::endl;
	double money;
	std::string moneyS;
	getline(std::cin,moneyS);
	std::stringstream convertMoney(moneyS);
	convertMoney >> money;
	currentUser->wallet = currentUser->wallet + money;
}
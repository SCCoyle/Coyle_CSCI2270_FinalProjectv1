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

void market::addProducts(std::string name,int quantity, double price, double cost)
{
	std::cout << name << " " << quantity << " " << price << " " << cost << std::endl;
	product *newProduct = new product(name,quantity,price,cost);
	product *temp = root;
	if(root == NULL)
	{
		root = newProduct;
	}
	else
	{
		//while loop ender
		bool kill = 0;
		while(!kill)
		{
			// if the title comes earlier in the alphabet
			if(newProduct->name < temp->name)
			{
				//if there is no childe to the one compared to make the new one hte child
				if(temp->left == NULL)
				{
					//linking the nodes to eachother
					temp->left = newProduct;
					newProduct->parent = temp;
					//end the while loop
					kill = 1;
				}
				// if there is a child there move down the tree
				else
				{
					temp = temp->left;
				}
			}
			else //same execution as above on if it is greater
			{
				if(temp->right == NULL)
				{
					temp->right = newProduct;
					newProduct->parent = temp;
					kill = 1;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}

void market::addSettings(double decay, bool recency, bool max, double maxP)
{
	
}

void market::buyProduct(std::string name)
{
	
}

void market::printProducts(product *node)
{
	product *temp = node;
	temp->left;
	std::cout << "a" << std::endl;
	if(temp->left != NULL)
	{
		std::cout << "b" << std::endl;
		printProducts(temp->left);
	}
	if(temp->name != "")
	{	
		std::cout << "c" << std::endl;
		//std::cout << "Name: " << temp->name << std::endl;
	}
	if(temp->right != NULL)
	{
		printProducts(temp->right);
	}
}

void market::printProducts()
{
	printProducts(root);
}


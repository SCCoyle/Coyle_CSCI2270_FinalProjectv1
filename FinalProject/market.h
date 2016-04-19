#pragma once
#include <string>
#include <vector>
#include <ctime>

struct settings{
	double decayRate;
	bool recencyDetection;
	bool maxPrice;
	double maxPriceMultiplier;
	time_t startTime;
	
};

struct product{
	product *parent = NULL;
	std::string name;
	int quantity;
	int totalSold;
	double price;
	double cost;
	std::vector<int> soldChain;
	product *left = NULL;
	product *right = NULL;
	
	product(){};

    product(std::string in_name, int in_quantity, double in_price, double in_cost)
    {
        name = in_name;
        quantity = in_quantity;
        price = in_price;
		cost = in_cost;
    }
};




class market
{
	public:
		market();
		~market();
		void addSettings(double decay, bool recency, bool max, double maxP);
		void addProducts(std::string name, int quantity, double price, double cost);
		void buyProduct(std::string name);
		void printProductsSafe();
		void totalProfit();
		void timeStats();

		
	protected:
	private:
		settings settingsStorage;
		product *root = NULL;
		product *head = NULL;
		void printProducts(product * node);
		product* findProduct(std::string name);
		int checkNumber(std::string number);
		void setInitalTime();
		void totalProfit(product * root);
		time_t lastTimeCheck;

};


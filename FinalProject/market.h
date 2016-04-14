#pragma once
#include <string>
#include <vector>
#include <ctime>

struct settings{
	double decayRate;
	bool recencyDetection;
	bool maxPrice;
	double maxPriceMultiplier;
	double startTime;
	
};

struct product{
	product *parent = NULL;
	std::string name;
	int quantity;
	int totalSold;
	double price;
	std::vector<int> soldChain;
	product *left = NULL;
	product *right = NULL;
	
	product(){};

    product(std::string in_name, int in_quantity, double in_price)
    {
        name = in_name;
        quantity = in_quantity;
        price = in_price;
    }
};




class market
{
	public:
		market();
		~market();
		void addSettings(double decay, bool recency, bool max, double maxP);
		void addProducts(std::string name, int quantity, double price);
		void buyProduct(std::string name);
		void listProducts();
		
	protected:
	private:
		settings settingsStorage;
		product *root;
		product* findProduct(std::string name);
		void addSale(product *productAdd);
		void listProducts(product *root);
		int checkNumber(std::string number);
		void setInitalTime();

};


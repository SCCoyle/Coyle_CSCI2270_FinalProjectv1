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

struct personalPurchase;

struct userInfo{
	std::string name;
	std::string password;
	double wallet;
	std::vector<personalPurchase> *purchases;
	
	userInfo(std::string in_name, std::string in_password, double in_wallet)
	{
		name = in_name;
		password = in_password;
		wallet = in_wallet;
	}
	
};

struct purchase{
	time_t time;
	userInfo *buyer;
	product *item;
	
	purchase(time_t in_time, userInfo *in_buyer, product *in_item)
	{
		time = in_time;
		buyer = in_buyer;
		item = in_item;
	}
};

struct personalPurchase{
	purchase *purchaseEvent;
};

struct purchaseBlockChain{
	purchase *purchaseEvent;
};






class market
{
	public:
		market();
		~market();
		void addSettings(double decay, bool recency, bool max, double maxP);
		void addProducts(std::string name, int quantity, double price, double cost);
		void addNewUser(std::string name, std::string password, double wallet);
		void buyProduct(std::string name);
		void printProductsSafe();
		void totalProfit();
		void timeStats();

		
	protected:
	private:
		settings settingsStorage;
		product *root = NULL;
		std::vector<purchaseBlockChain> blockChain;
		std::vector<userInfo> *users;
		void printProducts(product * node);
		product* findProduct(std::string name);
		int checkNumber(std::string number);
		void setInitalTime();
		void totalProfit(product * root);
		time_t lastTimeCheck;
		userInfo *currentUser = NULL;

};


#pragma once
#include <string>
#include <vector>
#include <ctime>

struct settings{
	double decayRate;
	double decayRateBase;
	double postBuyMultiplier;
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
	double base;
	double cost;
	time_t lastSold;
	std::vector<int> soldChain;
	product *left = NULL;
	product *right = NULL;
	
	product(){};

    product(std::string in_name, int in_quantity, double in_price, double in_cost, time_t start_time)
    {
        name = in_name;
        quantity = in_quantity;
        price = in_price;
		base = in_price;
		cost = in_cost;
		lastSold = start_time;
    }
};

struct personalPurchase;

struct userInfo{
	std::string name;
	std::string password;
	double wallet;
	std::vector<personalPurchase*> purchases;
	
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
	double cost;
	
	purchase(time_t in_time, userInfo *in_buyer, product *in_item,double in_cost)
	{
		time = in_time;
		buyer = in_buyer;
		item = in_item;
		cost = in_cost;
	}
};

struct personalPurchase{
	purchase *purchaseEvent;
	
	personalPurchase(purchase *in_purchase)
	{
		purchaseEvent = in_purchase;
	}
};

struct purchaseBlockChain{
	purchase *purchaseEvent;
	
	purchaseBlockChain(purchase *in_purchase)
	{
		purchaseEvent = in_purchase;
	}
};






class market
{
	public:
		market();
		~market();
		void addSettings(double decay,double decayBase, bool recency, bool max, double maxP, double postMultiplier);
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
		std::vector<purchaseBlockChain*> blockChain;
		std::vector<userInfo*> users;
		void printProducts(product * node);
		product* findProduct(std::string name);
		int checkNumber(std::string number);
		void setInitalTime();
		void totalProfit(product * root);
		time_t lastTimeCheck;
		userInfo *currentUser = NULL;

};


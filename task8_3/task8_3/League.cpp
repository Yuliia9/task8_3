

/**
*@file		League.cpp
*@brief		Implements methods for League class and models the work of credit league
*/

#include "stdafx.h"
#include "League.h"

#define ERROR 0
#define SUCCESS 1
#define DEPOSIT 1
#define CREDIT 0

using std::cout;


/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
League::League(void)
{
}


/**
* @brief					Constructor for creating league with num clients and _money 
* @param	[unsigned int]	_money - cash for league
			[unsigned int]	num - number of clients
*/
League::League(unsigned int _money, unsigned int num) : money(_money), clients(num)
{

}

/**
* @brief				Destructor
* @param	void
*/
League::~League(void)
{
}


/**
* @brief					Method for modeling the credit league
* @param	[unsigned int]	cash - money that has the credit league
*			[unsigned int]  num - number of clients
*@return	bool			returns ERROR if all clients are in queue
							otherwise returns SUCCESS
*/
bool League::WorkCycle(unsigned int cash, unsigned int num)
{
	if (clientQueue.size() == num)
	{
		return ERROR;
	}
	srand(time(NULL));
	unsigned int nclient = rand() % clients.size();
	cout << "NUM of Client " << nclient << "\n\n";

	srand(time(NULL));
	for (unsigned int i = 0; i < nclient; ++i)
	{
		unsigned int index = rand() % clients.size();
		unsigned int action = rand() % 100;
		unsigned int cost = rand() % cash;
		
		cout << "Client " << index << "\n";
		cout << "Action " << action << "\n";
		cout << "Money " << cost << "\n";

		if ((action % 2) ==  DEPOSIT)
		{

			if (money == 0 && money < cost)
			{
				cout << "There is no enough money, client goes to queue\n\n";
				clientQueue.push(clients[index]);
				debt.push(money);
				clients.erase(clients.begin() + index);

			}
			else
			{
				unsigned int income = clients[index].getDeposit();
				if (income == 0 && cost < money)
				{
					cout << "Takes deposit\n\n";
					money -= cost;
					clients[index].addDeposit(cost);
				}
				else if (income != 0 )
				{
					if (income < cost)
					{
						money += income;
					}
					else
					{
						money += cost;
					}
					clients[index].returnDeposit();
				}
				else
				{
					cout << "There is no enough money, client goes to queue\n\n";
					clientQueue.push(clients[index]);
					debt.push(money);
					clients.erase(clients.begin() + index);
				}
			}
		}
		else if ((action % 2) == CREDIT)
		{
			unsigned int income = clients[index].getCredit();
			if (income == 0 && money > cost)
			{
				cout << "Takes CREDIT \n\n";

				money -= cost;
				clients[index].setCredit(cost);

			}
			else if (income != 0 )
			{
				cout << "Returns CREDIT \n\n";

				money += income;
				if (!debt.empty()  && money > debt.front())
				{
					money -= debt.front();
					clientQueue.front().setCredit(debt.front());
					clients.push_back(clientQueue.front());
					clientQueue.pop();
					debt.pop();

				}
			}
			else if (money < cost)
			{
				clientQueue.push(clients[index]);
				debt.push(money);
				clients.erase(clients.begin() + index);
			}
		}
	}
	cout << "The balance of  credit league: \t" << money << "\n";
}


/**
*@file		League.h
*@brief		Header file that describes class League and models the work of credit league
*/

#ifndef LEAGUE_H_
#define LEAGUE_H_
#include "Client.h"

class League
{
public:
	//life cycle
	League(void);
	~League(void);
	League(unsigned int _money, unsigned int num);

	bool WorkCycle(unsigned int cash, unsigned int num);

private:
	//fields
	unsigned int money;
	std::vector<Client> clients;
	std::queue<Client> clientQueue;
	std::queue<unsigned int> debt;

};

#endif
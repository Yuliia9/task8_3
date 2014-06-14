
/**
*@file		Client.h
*@brief		Header file that describes class Client that holds information about money that has client
*/

#ifndef CLENT_H_
#define CLENT_H_

class Client
{
public:
	//life cycle
	Client(void);
	~Client(void);

	void addDeposit(unsigned int _deposit);
	unsigned int getDeposit(void);
	unsigned int getCredit(void);
	void setCredit(unsigned int _credit);
	void returnDeposit(void);

private:
	//fields
	unsigned int deposit;
	unsigned int credit;
};

#endif
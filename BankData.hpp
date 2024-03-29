#ifndef BANK_DATA_H
#define BANK_DATA_H

#include <iostream>

class BankData
{
public:
	// Are the Big Five necessary?
	// How will this data work with the std::map?
	BankData();
	BankData(int acctNum, double savingsAmount, double checkingAmount);
	BankData(const BankData& other);
	BankData(BankData&& other);
	BankData& operator=(const BankData& other);
	BankData& operator=(BankData&& other);
	~BankData();

	int getAcctNum() const; // we do want to return a copy of the int, not the pointer
	double getSavingsAmount() const; // we do want to return a copy of the double, not the pointer
	double getCheckingAmount() const; // we do want to return a copy of the double, not the pointer

	void setAcctNum(const int& newAcctNum); // you need to implement
	void setSavingsAmount(const double& newSavingsAmount); // you need to implement
	void setCheckingAmount(const double& newCheckingAmount); // you need to implement

private:
	int* mpAcctNum;
	double* mpSavingsAmount, * mpCheckingAmount;
};

#endif


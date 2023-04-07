#include "BankData.hpp"

BankData::BankData() {
	mpAcctNum = new int(0);
	mpSavingsAmount = new double(0.0);
	mpCheckingAmount = new double(0.0);
}

BankData::BankData(const BankData& other) {
	mpAcctNum = new int(*(other.mpAcctNum));
	mpSavingsAmount = new double(*(other.mpSavingsAmount));
	mpCheckingAmount = new double(*(other.mpCheckingAmount));
}

BankData::BankData(BankData&& other) {
	mpAcctNum = other.mpAcctNum;
	mpSavingsAmount = other.mpSavingsAmount;
	mpCheckingAmount = other.mpCheckingAmount;

	other.mpAcctNum = nullptr;
	other.mpSavingsAmount = nullptr;
	other.mpCheckingAmount = nullptr;
}

BankData& BankData::operator=(const BankData& other) {
	if (this != &other) {
		*mpAcctNum = *(other.mpAcctNum);
		*mpSavingsAmount = *(other.mpSavingsAmount);
		*mpCheckingAmount = *(other.mpCheckingAmount);
	}

	return *this;
}

BankData& BankData::operator=(BankData&& other) {
	if (this != &other) {
		delete mpAcctNum;
		delete mpSavingsAmount;
		delete mpCheckingAmount;

		mpAcctNum = other.mpAcctNum;
		mpSavingsAmount = other.mpSavingsAmount;
		mpCheckingAmount = other.mpCheckingAmount;

		other.mpAcctNum = nullptr;
		other.mpSavingsAmount = nullptr;
		other.mpCheckingAmount = nullptr;
	}

	return *this;
}

int BankData::getAcctNum() const
{
	return *(this->mpAcctNum);
}

double BankData::getSavingsAmount() const
{
	return *(this->mpSavingsAmount);
}

double BankData::getCheckingAmount() const
{
	return *(this->mpCheckingAmount);
}

void BankData::setAcctNum(const int& newAcctNum)
{
	*mpAcctNum = newAcctNum;
}

void BankData::setSavingsAmount(const double& newSavingsAmount)
{
	*mpSavingsAmount = newSavingsAmount;
}

void BankData::setCheckingAmount(const double& newCheckingAmount)
{
	*mpCheckingAmount = newCheckingAmount;
}
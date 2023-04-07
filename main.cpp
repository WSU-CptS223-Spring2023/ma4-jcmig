#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "BankData.hpp"

int main(int argc, char* argv[])
{
	// Task 0 - we need a unordered map to store our key and mapped values
	// std::unordered_map<keyType, ValueType>; What should the key be? What about the value?
	std::unordered_map<int, BankData> bankAccounts;
	
    /*Tasks (c) and (d): parse and read all data from BankAccounts.csv;
	                    insert the data into the std::unordered_map */

	std::ifstream file("BankAccounts.csv");

	if (file.is_open()) {
		std::string line;
		std::getline(file, line);

		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string data;

			std::getline(ss, data, ',');
			int acctNum = std::stoi(data);

			std::getline(ss, data, ',');
			double savingsAmt = std::stod(data);

			std::getline(ss, data, ',');
			double checkingAmt = std::stod(data);

			BankData bankData;
			bankData.setAcctNum(acctNum);
			bankData.setSavingsAmount(savingsAmt);
			bankData.setCheckingAmount(checkingAmt);

			bankAccounts.emplace(acctNum, bankData);
		}

		file.close();
	}

	//Task (e): Print the bucket number for each of the mapped data
	for (const auto& element : bankAccounts) {
		const auto& key = element.first;
		const auto& value = element.second;

		std::cout << "Bucket number for key " << key << ": " << bankAccounts.bucket(key) << std::endl;
	}

    //Task (f): Print the number of buckets in the container - 1st print
	std::cout << "Number of buckets: " << bankAccounts.bucket_count() << std::endl;

	//Task (g): Print the max number of elements that can be stored in the container
	std::cout << "Maximum number of elements: " << bankAccounts.max_size() << std::endl;
	
	//Task (j): Print the key-value pairs - 1st print
	for (const auto& account : bankAccounts) {
    	std::cout << "Account Number: " << account.first << std::endl;
    	std::cout << "Savings Amount: " << account.second.getSavingsAmount() << std::endl;
    	std::cout << "Checking Amount: " << account.second.getCheckingAmount() << std::endl;
	}

	//Task (h) : Erase the item with key 11111111
	auto num_erased = bankAccounts.erase(11111111);
	if (num_erased > 0) {
    	std::cout << "Item with key 11111111 erased successfully." << std::endl;
	} else {
    	std::cout << "Item with key 11111111 not found in map." << std::endl;
	}

	/* Task(i) : Add the following BankData values to the container:
                 22222222,8000, 1100.5
                 65733773, 10000, 755.67  */
	BankData bankData1(22222222, 8000, 1100.5);
	BankData bankData2(65733773, 10000, 755.67);

	bankAccounts.insert({bankData1.getAcctNum(), bankData1});
	bankAccounts.insert({bankData2.getAcctNum(), bankData2});


	//Task (j): Print the key-value pairs - 2nd print
	for (const auto& account : bankAccounts) {
    	std::cout << "Account Number: " << account.first << std::endl;
    	std::cout << "Savings Amount: " << account.second.getSavingsAmount() << std::endl;
    	std::cout << "Checking Amount: " << account.second.getCheckingAmount() << std::endl;
	}
	
    //Task (f): Print the number of buckets in the container - 2nd print
	std::cout << "Number of buckets: " << bankAccounts.bucket_count() << std::endl;

    /* Task(k) : Insert 100 additional accounts to the unordered_map container. You should randomly generate the account numbers, checking and saving balances of each BankData object.  
        * For account number : randomly generate a number between 50000000 and 99999999
        * For checking and savings accounts: randomly generate balances between 500 and 19000. You can simply generate integers without decimal points. 
        * After inserting each account, check the number of buckets. If the bucket size has increased (i.e., the hash table is re-hashed), print the new bucket size. See appendix for example output. */
    std::srand(std::time(nullptr));

	int bucketsOld = bankAccounts.bucket_count();

	for (int i = 0; i < 50; i++) {
		int acctNum = std::rand() % 50000000 + 50000000;
		double savings = std::rand() % 18501 + 500;
		double checking = std::rand() % 18501 + 500;

		BankData data(acctNum, savings, checking);

		bankAccounts.emplace(acctNum, data);
	}
	
	return 0;

}
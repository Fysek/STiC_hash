#include "test.h"

const int LEN_TAB = 50;
std::list < std::string > lista;

void display()
{

	//system("CLS");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << " CONTENT OF THE LIST: " << std::endl;
	std::cout << "---------------------------" << std::endl;
	
	for (std::list<std::string>::iterator i = lista.begin(); i != lista.end(); ++i) {
			std::cout << *i << " " << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//-------- 1 ------------


void delEqual() {
	std::list<std::string >::iterator it1, it2;
	it1 = it2 = lista.begin();
	it2++;
	while (it1!=lista.end()) {
		if (it2 != lista.end()) {
			if (*it1 == *it2) {
				it2 = lista.erase(it2);//usuniecie i skok na nastpne
			}
			else {
				it2++;
			}
		}
		else {
			it1++;
			it2 = it1;
			if (it1 != lista.end())
				it2++;
		}
	}
}


void delWrongSize(int size) {
	std::string str;
	std::list<std::string >::iterator it;
	it = lista.begin();
	while (it != lista.end()) {
		 str = *it;
		if (str.size() != size)
			it = lista.erase(it);
		else
			it++;
	}

}

std::string generateRandomString(size_t length)
{
	const char* charmap =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	const size_t charmapLength = strlen(charmap);
	auto generator = [&]() { return charmap[rand() % charmapLength]; };
	std::string result;
	result.reserve(length);
	std::generate_n(std::back_inserter(result), length, generator);
	return result;
}

void test_random(unsigned int v, unsigned int n) {
	/* v = 1. 64B; 2. 96B; 3. 128B
	* n - how many hashes we generate
	* we need hash functions or table with hashes
	* if equal then we do sth
	* eff = n-retr/n
	*
	*/
	std::string strHash;
	float eff, sBefore, sAfter;
	float max = 100;
	if (v == 1)
	{
		for (unsigned int i = 1; i < n + 1; i++) {
			strHash = generateRandomString(64);
			strHash = SDBMHash(strHash);
			lista.push_back(strHash);
		}
		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(64);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore)*100 ;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;
		
	}
	else if (v == 2)
	{
		for (unsigned int i = 1; i < n + 1; i++) {
			strHash = generateRandomString(96);
			strHash = SDBMHash(strHash);//replace with your function from hashfunctions
			lista.push_back(strHash);
		}
		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(96);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore) * 100;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;

	}
	
	else if (v == 3)
	{
		for (unsigned int i = 1; i < n + 1; i++) {
			strHash = generateRandomString(128);
			strHash = SDBMHash(strHash);//replace with your function from hashfunctions
			lista.push_back(strHash);
		}
		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(128);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore) * 100;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;
	}
	else
	{
		std::cout << "Error, wrong length" << std::endl;
		//return 0;
	}
}

void test(unsigned int v, std::vector <std::string> &vec) {
   /* v = 1. 64B; 2. 96B; 3. 128B
	* n - how many hashes we generate
	* we need hash functions or table with hashes
	* if equal then we do sth
	* eff = n-retr/n
	*
	*/
	std::string strHash;

	float eff, sBefore, sAfter;
	float max = 100;

	if (v == 1)
	{
		for (int i = 0 ; i < vec.size(); i++) {
			strHash = SDBMHash(vec[i]);
			lista.push_back(strHash);
		}

		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(64);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore) * 100;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;
	}
	else if (v == 2)
	{
		for (int i = 0; i < vec.size(); i++) {
			strHash = SDBMHash(vec[i]);
			lista.push_back(strHash);
		}
		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(96);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore) * 100;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;

	}
	else if (v == 3)
	{
		for (int i = 0; i < vec.size(); i++) {
			strHash = SDBMHash(vec[i]);
			lista.push_back(strHash);
		}
		display();
		sBefore = lista.size();
		delEqual();
		delWrongSize(128);
		sAfter = lista.size();
		std::cout << "After deleting repeating and wrong hashes  " << std::endl;
		display();
		eff = (sAfter / sBefore) * 100;
		std::cout << "Conficts in: " << max - eff << "% hashes" << std::endl;
	}
	else
	{
		std::cout << "Error, wrong length" << std::endl;
		//return 0;
	}
}

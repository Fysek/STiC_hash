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

void push_front()
{
	std::string stringHash;
	std::vector< unsigned int > liczba;
	std::cout << "Podaj jaka liczbe wstawic na pocz\245tek listy: ";
	std::cin >> stringHash;
	lista.push_front(stringHash);
}

//--------- 2 -----------

void push_back()
{
	std::string stringHash;
	std::cout << "Podaj jaka liczbe wstawic na koniec listy: ";
	std::cin >> stringHash;
	lista.push_back(stringHash);
}

//---------- 3 ---------

void pop_front()
{
	std::cout << "Nast\245pi usuni\251cie liczby z pocz\245tku listy";
	Sleep(2000);
	lista.pop_front();
}

//---------- 4 ---------

void pop_back()
{
	std::cout << "Nast\245pi usuni\251cie liczby z konca listy";
	Sleep(2000);
	lista.pop_back();
}

//---------- 5 ----------

void size()
{
	std::cout << "Liczb na li\230cie: " << lista.size();
	Sleep(2000);
}

//---------- 6 ----------

void max_size()
{
	std::cout << "Max liczb na li\230cie: " << lista.max_size();
	Sleep(5000);
}

//---------- 7 ----------

void empty()
{
	std::cout << "Czy lista pusta? -> ";
	if (lista.empty() == 1) std::cout << "TRUE"; else std::cout << "FALSE";
	Sleep(2000);
}

//---------- 8 ----------

void reverse()
{
	std::cout << "Nastapi odwrocenie kolejnosci liczb!";
	lista.reverse();
	Sleep(2000);
}

//---------- 9 ----------

void exit()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << "Koniec programu!";
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
//------------------------

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




void test(unsigned int v, unsigned int n) {
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
		delWrongSize(96);
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


///////////////////////////////////////////////
/*   any sequence of 8-bit symbols on input  */
/* return sequence of 64, 96 or 128 bytes    */
///////////////////////////////////////////////

#include "hashfunctions.h"
#include "test.h"

std::vector <std::string> bufor(std::string input){
	int i;
	std::string x;
	std::vector < std::string > dane;
	for (i = 0;i<input.size();i = i + 16)
	{
		x = input.substr(i, 16);
		dane.push_back(x);
	}
	return dane;
}


int main(){
	std::string haslo = "Czy znacie historie o niemym michalku, ktory tak zul gume ze az oslepl";
	std::vector <std::string> wyjscie;
	wyjscie = bufor(haslo);


	test(1, wyjscie);
	//test_random(1, 2);


	system("pause");
	return 0;
	
}


///////////////////////////////////////////////
/* any sequence of 8-bit symbols on input    */
/* return sequence of 64, 96 or 128 bytes    */
///////////////////////////////////////////////
/*
* do zmiany:
* stringi o danej dlugosci musi zmieniac do hashu 64 bajty etc. xor operation
* test, dla roznicy przeklaman
* dopelnianie niepe³nych buforow
* opracowac schemat
* opracowanie wynikow
*
*/
#include "hashfunctions.h"
#include "test.h"

using namespace std;

std::vector <std::string> bufor(std::string input){
	int i;
	std::string x;
	std::string buff = "5678901234567890";
	std::vector < std::string > dane;
	for (i = 0;i<input.size();i = i + 16)
	{
		x = input.substr(i, 16);
		if (x.size() < 16) {
			for (int k = x.size(); k<16; k++){
				x.push_back((x[x.size()]-'0')^(buff[k]-'0') +'0');
			}
		}
		dane.push_back(x);
	}
	return dane;
}


int main(){
	std::vector <std::string> wyjscie;
	std::vector <std::string> wyjscie1;


	//wyjscie = bufor(haslo);
	//for (std::vector<std::string>::iterator i = wyjscie.begin(); i != wyjscie.end(); ++i) {
	//	std::cout << *i<< std::endl;
	//}
    string dane1 = "Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Woxna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia";
    string dane = "Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia";
    wyjscie = bufor(dane);
    wyjscie1 = bufor(dane1);
    SDBMHash(wyjscie,64);
    SDBMHash(wyjscie,128);
    SDBMHash(wyjscie,96);
    SDBMHash(wyjscie1,64);
    SDBMHash(wyjscie1,128);
    SDBMHash(wyjscie1,96);


	//test(1, wyjscie);
	//test_random(1, 2);
	system("pause");
	return 0;

}


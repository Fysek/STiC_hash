///////////////////////////////////////////////
/* Authors:									 */
/* Krzysztof Jania							 */
/* Grzegorz Janusz							 */
/* Mateusz Dyrdół							 */
///////////////////////////////////////////////
#include "hashfunctions.h"
#include "test.h"

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

    std::string dane1 = "abcdpedidualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia";
    std::string dane = "Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia Wikipediaualizację jej t: „Wolna encyklopedia";
	
	wyjscie = bufor(dane);
	wyjscie1 = bufor(dane1);

	SDBMHash(wyjscie,64);
	SDBMHash(wyjscie,96);
	SDBMHash(wyjscie,128);
	SDBMHash(wyjscie1,64);
	SDBMHash(wyjscie1,96);
	SDBMHash(wyjscie1,128);

	//uncomment to use tests
	//test(1, wyjscie);
	//test_random(64, 100000);

	system("pause");
	return 0;

}


///////////////////////////////////////////////
/*   any sequence of 8-bit symbols on input  */
/* return sequence of 64, 96 or 128 bytes    */
///////////////////////////////////////////////

#include "tests.h"
#include "hashfunctions.h"

int main()
{
	int x;
	std::cout << std::hex << SDBMHash("ty no nie wiem jak tam twoja szmaciura zrogowacia�a niedzwiedzica co sie kurwi pod mostem za wojaka") << std::endl;
	std::cout << std::hex << SDBMHash("ty no nie wiem jak tam twoja szmaciura zrogowacia�a niedziiedzica co sie kurwi pod mostem za wojaka") << std::endl;
	std::cout << std::hex << SDBMHash("tyjaka") << std::endl;
	std::cout << std::hex << SDBMHash("t") << std::endl;
	std::cin >> x;
	return 0;
}


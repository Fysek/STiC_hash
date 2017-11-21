#include "hashfunctions.h"



char FSTable(char s) {
	switch (s)
	{
	case '0':
		return 'k';
	case '1':
		return 'W';
	case '2':
		return 'L';
	case '3':
		return 'e';
	case '4':
		return 'A';
	case '5':
		return '9';
	case '6':
		return 'd';
	case '7':
		return 'Q';
	case '8':
		return '2';
	case '9':
		return 'l';
	case 'A':
		return 'v';
	case 'B':
		return '5';
	case 'C':
		return 'o';
	case 'D':
		return 's';
	case 'E':
		return '0';
	case 'F':
		return 'g';
	case 'G':
		return 'y';
	case 'H':
		return 'q';
	case 'I':
		return '4';
	case 'J':
		return 'F';
	case 'K':	
		return 'Y';	
	case 'L':	
		return 'm';	
	case 'M':	
		return '7';	
	case 'N':	
		return 'a';	
	case 'O':	
		return 'i';	
	case 'P':	
		return 'D';	
	case 'Q':	
		return 'J';	
	case 'R':	
		return 'u';	
	case 'S':	
		return 'C';	
	case 'T':
    	return 'w';	
	case 'U':	
		return 'M';	
	case 'V':	
		return 'b';	
	case 'W':	
		return 'S';	
	case 'X':	
		return 'p';	
	case 'Y':
    	return 'O';	
	case 'Z':
    	return 'H';		
	case 'a':
		return 'x';
	case 'b':
		return 'U';
	case 'c':
		return '6';
	case 'd':
		return 'R';
	case 'e':
		return 'G';
	case 'f':
		return '3';
	case 'g':
		return 'z';
	case 'h':
		return 'c';
	case 'i':
		return '1';
	case 'j':
		return 'K';
	case 'k':	
		return '8';	
	case 'l':	
		return 'n';	
	case 'm':	
		return 'T';	
	case 'n':	
		return 'I';	
	case 'o':	
		return 'N';	
	case 'p':	
		return 'r';	
	case 'q':	
		return 'E';	
	case 'r':	
		return 'n';	
	case 's':	
		return 'B';	
	case 't':
    	return 'P';	
	case 'u':	
		return 'h';	
	case 'v':	
		return 'Z';	
	case 'w':	
		return 'j';	
	case 'x':	
		return 'f';	
	case 'y':
    	return 'X';	
	case 'z':
    	return 'V';		
			
	}

}


unsigned int RSHash(const std::string& str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = hash * a + str[i];
		a = a * b;
	}

	return hash;
}
/* End Of RS Hash Function */


unsigned int JSHash(const std::string& str)
{
	unsigned int hash = 1315423911;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash ^= ((hash << 5) + str[i] + (hash >> 2));
	}

	return hash;
}
/* End Of JS Hash Function */


unsigned int PJWHash(const std::string& str)
{
	unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
	unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
	unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
	unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = (hash << OneEighth) + str[i];

		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return hash;
}
/* End Of  P. J. Weinberger Hash Function */


std::vector< unsigned int > ELFHash(const std::string& str)
{
	std::vector< unsigned int > hash(64);
	unsigned int x = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash.at(i) = (hash.at(i) << 4) + str[i];
		if ((x = hash.at(i) & 0xF0000000L) != 0)
		{
			hash.at(i) ^= (x >> 24);
		}
		hash.at(i) &= ~x;
	}

	return hash;
}
/* End Of ELF Hash Function */


unsigned int BKDRHash(const std::string& str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = (hash * seed) + str[i];
	}

	return hash;
}
/* End Of BKDR Hash Function */


/*hash function*/
std::string SDBMHash(const std::string& str)
{
	std::string hash;
	char subhash;

	for (size_t i = 0; i < str.length(); i++)
	{
		subhash = FSTable(str[i]);
		hash += subhash;//;+ (subhash << 6) + (subhash << 16);
	}

	return hash;
}


unsigned int DJBHash(const std::string& str)
{
	unsigned int hash = 5381;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = ((hash << 5) + hash) + str[i];
	}

	return hash;
}
/* End Of DJB Hash Function */


unsigned int DEKHash(const std::string& str)
{
	unsigned int hash = static_cast<unsigned int>(str.length());

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
	}

	return hash;
}
/* End Of DEK Hash Function */


unsigned int BPHash(const std::string& str)
{
	unsigned int hash = 0;
	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = hash << 7 ^ str[i];
	}

	return hash;
}
/* End Of BP Hash Function */


unsigned int FNVHash(const std::string& str)
{
	const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash *= fnv_prime;
		hash ^= str[i];
	}

	return hash;
}
/* End Of FNV Hash Function */


unsigned int APHash(const std::string& str)
{
	unsigned int hash = 0xAAAAAAAA;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash ^= ((i & 1) == 0) ? ((hash << 7) ^ str[i] * (hash >> 3)) :
			(~((hash << 11) + (str[i] ^ (hash >> 5))));
	}

	return hash;
}
/* End Of AP Hash Function */



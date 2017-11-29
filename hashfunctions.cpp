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

/*hash function*////////////////////////////////////
std::string SDBMHash(const std::string& str)
{
	std::string hash;
	char subhash;

	for (size_t i = 0; i < str.length(); i++)
	{
		subhash = FSTable(str[i]);
		hash += subhash + (subhash << 6) + (subhash << 16);
	}

	return hash;
}


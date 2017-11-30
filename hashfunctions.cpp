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
	default:
		return 'x';
	}
}

/*hash function*////////////////////////////////////

///inut vector of 16byte strings, time to do some shit 
//maybe int n for three different sizes
// 

std::string SDBMHash(std::vector <std::string>  &vec_str, unsigned int version)
{

	std::string hash;
	char subhash;


	if (version = 64) {
		//proponuje tutaj  wziac co 4 stringi 16bajtowe i porobic cos na nich a potem xorowac
		/*
			    vector string
		    po 16 bajtow na cztery
			\/    \/    \/    \/
			\/    \/    \/    \/
		   |  |  |  |  |  |  |  |
		   |  |  |  |  |  |  |  |
		   |  |  |  |  |  |  |  |
		     \     |    |     /
			  \  + |  + |  + /

				   64bajty	

			kazdy z tych czterech moze miec rozne operacje potem je laczymy w stringi 64 bajtowe 
			dla wiekszych hashy podobnie tylko uzywamu dla 96 6 blokow po 16 a 128 8 blokow po 16
		*/

		//////////pierwszy blok/////////////////
		for (int i = 0; i < vec_str.size(); i+4 )
		{
			hash = vec_str[i];
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
		}

		//////////drugi blok/////////////////
		for (int i = 1; i < vec_str.size(); i + 4)
		{
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
		}

		//////////trzeci blok/////////////////
		for (int i = 2; i < vec_str.size(); i + 4)
		{
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
		}

		//////////czwarty blok/////////////////
		for (int i = 3; i < vec_str.size(); i + 4)
		{
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
		}

		return hash;


	}else if (version = 96) {

		/*
			vector string
		    po 16 bajtow na szesc
			\/    \/    \/    \/    \/    \/
			\/    \/    \/    \/    \/    \/
		   |  |  |  |  |  |  |  |  |  |  |  |
		   |  |  |  |  |  |  |  |  |  |  |  |
		
		*/

		for (std::vector<std::string>::iterator i = vec_str.begin(); i != vec_str.end(); )
		{
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
		}

		return hash;
	}else if (version = 128) {

		return hash;
	}else {
		std::cout << "Error, wrong version value" << std::endl;
		return 0;
	}





	
}


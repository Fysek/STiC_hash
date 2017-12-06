///////////////////////////////////////////////
/* Authors:									 */
/* Krzysztof Jania							 */
/* Grzegorz Janusz							 */
/* Mateusz Dyrdó³							 */
///////////////////////////////////////////////
#include "hashfunctions.h"
#include <iostream>

using namespace std;

std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

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


std::string SDBMHash(std::vector <std::string>  &vec_str, unsigned int version)
{
	std::string hash;
	std::string blok1 = "1234567890123456";
	std::string blok2 = "4567890123456789";
	std::string blok3 = "6789012345678901";
	std::string blok4 = "9012345678901234";
	std::string blok5 = "5678901234567890";
	std::string blok6 = "2345678901234567";
	std::string blok7 = "7890123456789012";
	std::string blok8 = "8901234567890123";

	char subhash;

	if (version == 64) {
		//////////pierwszy blok/////////////////
		for (int i = 0; i < vec_str.size(); i=i+4 )
		{
		    hash = vec_str[i];
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
			for(int ii = 0; ii<15; ii++)
            {
                blok1[ii] = blok1[ii] ^ hash[ii];
            }
		}

		//////////drugi blok/////////////////
		for (int j = 1; j < vec_str.size(); j=j + 4)
		{
		    hash = vec_str[j];
            subhash = FSTable(hash[j]);
			hash += subhash + (subhash << 2) + (subhash << 13);
            for(int ii = 0; ii<15; ii++)
            {
                blok2[ii] = blok2[ii] ^ hash[ii];
            }

		}

		//////////trzeci blok/////////////////
		for (int k = 2; k < vec_str.size(); k=k + 4)
		{
		     hash = vec_str[k];
			subhash = FSTable(hash[k]);
			hash += subhash + (subhash << 5) + (subhash << 10);
            for(int ii = 0; ii<15; ii++)
            {
                blok3[ii] = blok3[ii] ^ hash[ii];
            }
		}

		//////////czwarty blok/////////////////
		for (int l = 3; l < vec_str.size(); l=l + 4)
		{
		     hash = vec_str[l];
			subhash = FSTable(hash[l]);
			hash += subhash + (subhash << 7) + (subhash << 12);
            for(int ii = 0; ii<15; ii++)
            {
                blok4[ii] = blok4[ii] ^ hash[ii];
            }
		}

        hash = blok1 + blok2 + blok3 + blok4;
        hash = string_to_hex(hash);
        cout<<hash.size()<<endl;
        cout<<hash<<endl<<endl;


		return hash;


	}else if (version == 96) {
        for (int i = 0; i < vec_str.size(); i=i+6 )
		{
		    hash = vec_str[i];
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
			for(int ii = 0; ii<15; ii++)
            {
                blok1[ii] = blok1[ii] ^ hash[ii];
            }
		}

		//////////drugi blok/////////////////
		for (int j = 1; j < vec_str.size(); j=j + 6)
		{
		     hash = vec_str[j];
            subhash = FSTable(hash[j]);
			hash += subhash + (subhash << 2) + (subhash << 13);
            for(int ii = 0; ii<15; ii++)
            {
                blok2[ii] = blok2[ii] ^ hash[ii];
            }

		}

		//////////trzeci blok/////////////////
		for (int k = 2; k < vec_str.size(); k=k + 6)
		{
		     hash = vec_str[k];
			subhash = FSTable(hash[k]);
			hash += subhash + (subhash << 5) + (subhash << 10);
            for(int ii = 0; ii<15; ii++)
            {
                blok3[ii] = blok3[ii] ^ hash[ii];
            }
		}

		//////////czwarty blok/////////////////
		for (int l = 3; l < vec_str.size(); l=l + 6)
		{
		     hash = vec_str[l];
			subhash = FSTable(hash[l]);
			hash += subhash + (subhash << 7) + (subhash << 12);
            for(int ii = 0; ii<15; ii++)
            {
                blok4[ii] = blok4[ii] ^ hash[ii];
            }
		}
		//////////piaty blok/////////////////
        for (int m = 4; m < vec_str.size(); m=m + 6)
		{
		     hash = vec_str[m];
			subhash = FSTable(hash[m]);
			hash += subhash + (subhash << 4) + (subhash << 18);
            for(int ii = 0; ii<15; ii++)
            {
                blok5[ii] = blok5[ii] ^ hash[ii];
            }
		}
		//////////szosty blok/////////////////
        for (int n = 5; n < vec_str.size(); n=n + 6)
		{
		     hash = vec_str[n];
			subhash = FSTable(hash[n]);
			hash += subhash + (subhash << 3) + (subhash << 15);
            for(int ii = 0; ii<15; ii++)
            {
                blok6[ii] = blok6[ii] ^ hash[ii];
            }
		}
        hash = blok1 + blok2 + blok3 + blok4 + blok5 + blok6;
        hash = string_to_hex(hash);
        cout<<hash.size()<<endl;
        cout<<hash<<endl<<endl;

        return hash;
	}else if (version == 128) {
            for (int i = 0; i < vec_str.size(); i=i+8 )
		{
		    hash = vec_str[i];
			subhash = FSTable(hash[i]);
			hash += subhash + (subhash << 6) + (subhash << 16);
			for(int ii = 0; ii<15; ii++)
            {
                blok1[ii] = blok1[ii] ^ hash[ii];
            }
		}

		//////////drugi blok/////////////////
		for (int j = 1; j < vec_str.size(); j=j + 8)
		{
		     hash = vec_str[j];
            subhash = FSTable(hash[j]);
			hash += subhash + (subhash << 2) + (subhash << 13);
            for(int ii = 0; ii<15; ii++)
            {
                blok2[ii] = blok2[ii] ^ hash[ii];
            }

		}

		//////////trzeci blok/////////////////
		for (int k = 2; k < vec_str.size(); k=k + 8)
		{
		     hash = vec_str[k];
			subhash = FSTable(hash[k]);
			hash += subhash + (subhash << 5) + (subhash << 10);
            for(int ii = 0; ii<15; ii++)
            {
                blok3[ii] = blok3[ii] ^ hash[ii];
            }
		}

		//////////czwarty blok/////////////////
		for (int l = 3; l < vec_str.size(); l=l + 8)
		{
		     hash = vec_str[l];
			subhash = FSTable(hash[l]);
			hash += subhash + (subhash << 7) + (subhash << 12);
            for(int ii = 0; ii<15; ii++)
            {
                blok4[ii] = blok4[ii] ^ hash[ii];
            }
		}
		//////////piaty blok/////////////////
        for (int m = 4; m < vec_str.size(); m=m + 8)
		{
		     hash = vec_str[m];
			subhash = FSTable(hash[m]);
			hash += subhash + (subhash << 4) + (subhash << 18);
            for(int ii = 0; ii<15; ii++)
            {
                blok5[ii] = blok5[ii] ^ hash[ii];
            }
		}
		//////////szosty blok/////////////////
        for (int n = 5; n < vec_str.size(); n=n + 8)
		{
		     hash = vec_str[n];
			subhash = FSTable(hash[n]);
			hash += subhash + (subhash << 3) + (subhash << 15);
            for(int ii = 0; ii<15; ii++)
            {
                blok6[ii] = blok6[ii] ^ hash[ii];
            }
		}
				//////////siodmy blok/////////////////
        for (int n = 6; n < vec_str.size(); n=n + 8)
		{
		     hash = vec_str[n];
			subhash = FSTable(hash[n]);
			hash += subhash + (subhash << 8) + (subhash << 8);
            for(int ii = 0; ii<15; ii++)
            {
                blok7[ii] = blok7[ii] ^ hash[ii];
            }
		}
				//////////osmy blok/////////////////
        for (int n = 7; n < vec_str.size(); n=n + 8)
		{
		     hash = vec_str[n];
			subhash = FSTable(hash[n]);
			hash += subhash + (subhash << 1) + (subhash << 11);
            for(int ii = 0; ii<15; ii++)
            {
                blok8[ii] = blok8[ii] ^ hash[ii];
            }
		}
        hash = blok1 + blok2 + blok3 + blok4 + blok5 + blok6 + blok7 + blok8;
        hash = string_to_hex(hash);
        cout<<hash.size()<<endl;
        cout<<hash<<endl<<endl;

		return hash;
	}else {
		std::cout << "Error, wrong version value" << std::endl;
		return 0;
	}
}


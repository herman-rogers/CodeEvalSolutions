#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
using namespace std;

typedef list<float> NumberList;
NumberList listOfSplitNumbers;
NumberList listOfUglyNumbers;
int uglyPrimes[4] = {2,3,5,7};
//int selectedNumber;

bool IsNumberUgly( int selectedNumber ){
	for( int i = 0; i < 4; i++ ){
		//add in a check if your the selectednumber IS
		// itself a uglyprime
		if ( selectedNumber / uglyPrimes[i] == 0 ){
			return true;
		}
	}
	return false;
}

void FindCombinations( ){
	//float lengthOfList = ( ( float )listOfSplitNumbers.size( ) - 1 );
	//float lengthOfCombinations = pow( 3, lengthOfList );
	int tempNumber = 0;
	for( NumberList::const_iterator cIter = listOfSplitNumbers.begin( );
		cIter != listOfSplitNumbers.end( ); cIter++ ){
			cout << ( *cIter );
			tempNumber = tempNumber + *cIter;
	}
	if ( IsNumberUgly( tempNumber ) ){
		listOfUglyNumbers.push_front( tempNumber );
	}
}

void SplitString( string selectedNumber ){
	float parseOutNumber = 0.0f;
	int stringToNumber = atoi( selectedNumber.c_str( ) );
	std::string myString = to_string( static_cast<long long>( stringToNumber ) );
	for( int i = 1; i <= stringToNumber; i*=10 ){
		parseOutNumber = ( stringToNumber / i ) % 10;
		listOfSplitNumbers.push_front( parseOutNumber );
	}
}

int main( int argc, char* argv[] ){
	//ifstream file;
	//stream lineBuffer;
	//file.open( argv[1] );
	//while( !file.eof( ) ){
	//	getline( file, lineBuffer );
	//	if( lineBuffer.length( ) == 0 ){
	//		continue;
	//	}
	//	//do something here
	//}
	string tempNumber;
	cout << "Insert a number >> ";
	cin >> tempNumber;

	//senPrimeNumber = atoi( lineBuffer.c_str( ) ) ;
	SplitString( tempNumber );
	//FindCombinations( );
	return 0;
}
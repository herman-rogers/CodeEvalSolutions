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
int selectedNumber;

bool IsNumberUgly( ){
	for( int i = 0; i < 4; i++ ){
		//add in a check if your the selectednumber IS
		// itself a uglyprime
		if ( selectedNumber / uglyPrimes[i] == 0 ){
			return false;
		}
	}
	return true;
}

void FindCombinations( ){
	float lengthOfList = ( ( float )listOfSplitNumbers.size( ) - 1 );
	float lengthOfCombinations = pow( 3, lengthOfList );
	for( NumberList::const_iterator cIter = listOfSplitNumbers.begin( );
		 cIter != listOfSplitNumbers.end( ); cIter++ ){
		cout << ( *cIter );
	}
}

void SplitNumber( ){
	float parseOutNumber  = 0.0f;
	for( int i = 1; i <= selectedNumber; i*=10 ){
		parseOutNumber = ( selectedNumber / i ) % 10;
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
	cout << "Insert a number >> ";
	cin >> selectedNumber;

	//senPrimeNumber = atoi( lineBuffer.c_str( ) ) ;
	SplitNumber( );
	FindCombinations( );
	return 0;
}


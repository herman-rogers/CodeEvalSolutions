#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

typedef list<int> PrimeNumberList;
PrimeNumberList primeList;
int chosenPrimeNumber;
int lastNumberInList;
string chosenFile;

void FormatOutput( int printNumber ){
	cout << printNumber;
	if ( printNumber < lastNumberInList ){
		cout << ",";
	} else {
		cout << "\n";
	}
}

void PrintPrimeList( ){
	for( PrimeNumberList::const_iterator cIterator = primeList.begin( ); 
		 cIterator != primeList.end( ); cIterator++){
			 FormatOutput( *cIterator );
	}
}

void DivideNumberByN( int numberToDivide ){
	for ( int n = 2; n < chosenPrimeNumber; n++ ){
		if ( ( numberToDivide != n ) && numberToDivide % ( n ) == 0 ){
			return;
		}
		if ( n > numberToDivide ){
			break;
		}
	}
	primeList.push_back( numberToDivide );
	lastNumberInList = numberToDivide;
}

void GetListOfPrimes( ){
	primeList.push_back( 2 );
	for ( int i = 3; i < chosenPrimeNumber; i++ ){
		if ( i % 2 == 0 ){
			continue;
		}
		DivideNumberByN( i );
	}
	PrintPrimeList( );
}

int main( int argc, char* argv[] ){
	ifstream file;
	string lineBuffer;
	file.open( argv[1] );
	if ( file.is_open( ) ){
		while( !file.eof( ) ){
			getline( file, lineBuffer );
			if( lineBuffer.length( ) == 0 ){
				continue;
			}
			primeList.clear( );
			chosenPrimeNumber = atoi( lineBuffer.c_str( ) ) ;
			GetListOfPrimes( );
		}
		file.close( );
	} else {
		cout << "Unable to find your file!";
	}
	return 0; 
}


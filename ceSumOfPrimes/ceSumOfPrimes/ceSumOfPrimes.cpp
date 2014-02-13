#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

typedef list<int> PrimeNumberList;
PrimeNumberList primeNumberList;
bool runFindPrimes;
int  totalSumOfPrimes;

int AddPrimesTogether( ){
	for ( PrimeNumberList::const_iterator cIterator = primeNumberList.begin( );
		  cIterator != primeNumberList.end( ); cIterator++ ){
	      totalSumOfPrimes = totalSumOfPrimes + *cIterator;
	}
	return totalSumOfPrimes;
}

void EndPrimeSearch( ){
	if ( primeNumberList.size( ) >= 1000 ){
		runFindPrimes = false;
		cout << AddPrimesTogether( );
	}
}

void IsNumberPrime( int number ){
	if ( number % 2 == 0 ){
		return;
	}
	for ( int i = 2; i < number; i++  ){
		if( number % i == 0 ){
			return;
		}
	}
	primeNumberList.push_back( number );
	return;
}

void SearchPrimeNumbers( ){
	int currentNumber = 6;
	while( runFindPrimes ){
		EndPrimeSearch( );
		IsNumberPrime( currentNumber );
		currentNumber++;
	}
}

void AddCommonPrimeNumbers( ){
	primeNumberList.push_back( 2 );
	primeNumberList.push_back( 3 );
	primeNumberList.push_back( 5 );
}

int main( ){
	runFindPrimes = true;
	AddCommonPrimeNumbers( );
	SearchPrimeNumbers( );
	return 0;
}


#ifndef MATRIX_HH
#define MATRIX_HH
#include <vector>

using namespace std;

struct Macierz{

	unsigned int wiersze;
	unsigned int kolumny;
	vector<unsigned int> wektor;
	
	Macierz(unsigned int wiersze = 1, unsigned int kolumny = 1){        //potrzebne do planszy

		this->wiersze = wiersze;
		this->kolumny = kolumny;
		this->wektor.resize(wiersze*kolumny, 0);
	}

	unsigned int & operator () (unsigned int i, unsigned int j){
		return wektor[i * this->kolumny + j];
	}	
};

#endif

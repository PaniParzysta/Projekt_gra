#include "Plansza"

void Plansza::wyswietl_plansze(Gracz gracz_1, Gracz gracz_2){

	cout << endl;

	for(unsigned int i = 0; i <= this->zwroc_rozmiar(); i++){
		for(unsigned int j = 0; j <= this->zwroc_rozmiar(); j++) {
            if (i == 0) {                           //wypisywanie w rzedzie
                if (j == 0) {
                    cout << "   " << j + 1;
                } else {
                    if (j != this->zwroc_rozmiar()) {
                        if (j < 10) cout << "  " << j + 1;
                        else cout << " " << j + 1;
                    }
                }
            }
			else{
				if(j == 0){
					if( i >= 10) cout << i << " ";
					else cout << i << "  ";				//wypisywanie w linii
				}
				else{
					if(this->pola(i-1,j-1) == gracz_1.id_gracza){
						cout << gracz_1.znak_gracza << "  ";
					}
					else{
						if(this->pola(i-1,j-1) == gracz_2.id_gracza) cout << gracz_2.znak_gracza << "  ";
						else cout << "_  ";
					}	
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Plansza::dodaj_ruch(unsigned int i, unsigned int j, Gracz gracz){          //dodaje ruchy i sprawdza czy nie jest dane pole zajete
	if(this->pola(i,j) == 0) this->pola(i,j) = gracz.id_gracza;
	else cout << "To pole jest zajęte"<<endl;
}

void Plansza::usun_ruch(unsigned int i, unsigned int j){
	this->pola(i,j) = 0;
}

bool Plansza::czy_mozliwy_ruch(unsigned int i, unsigned int j, Gracz gracz){

	if(i >= 0 and i < this->zwroc_rozmiar() and j >= 0 and j < this->zwroc_rozmiar() ){
		if(this->pola(i,j) == 0) return true;
		else
		    return false;
	}	
	else
		return false;
}

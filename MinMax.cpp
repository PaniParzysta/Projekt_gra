#include "MinMax.hh"

pair< int, pair<int, int> > MinMax(Plansza & plansza_w_grze, Gracz gracz_1, Gracz gracz_2, bool MIN_MAX, Warunek_wygranej warunek, int glebokosc){

	Macierz & pola = plansza_w_grze.zwroc_pola();

    unsigned int rozmiar_planszy = plansza_w_grze.zwroc_rozmiar();
	int glebia[11] = {0, 0, 0, 10, 5, 4, 3, 3, 3, 3, 2};
    int wartosc_MinMax = -2;
	int zwyciezca;

	int id_gracza_1 = gracz_1.id_gracza;
	int id_gracza_2 = gracz_2.id_gracza;
	int wynik = warunek.Zwyciezca(plansza_w_grze, gracz_1, gracz_2);

	pair <int, pair<int, int> > nextRecursion;
    pair<int,int> ruch;

	if(wynik == 0){
		zwyciezca = 0;
	}
	else{
		if(wynik == id_gracza_1){
			zwyciezca = 1;
		}
		else{
			if(wynik == id_gracza_2) zwyciezca = -1;
			else zwyciezca = 2;
		}	
	}

	if(zwyciezca != 2)
	        return {zwyciezca, {-1, -1} };

	if(rozmiar_planszy <= 10){
		if(glebokosc == glebia[rozmiar_planszy])
			return {0, {-1, -1}};
	}
	else{
		if(glebokosc == 2)
			return {0, {-1, -1}};
	}	

	for(unsigned int i = 0; i < rozmiar_planszy; i++){
		for(unsigned int j = 0; j < rozmiar_planszy; j++){
			if(pola(i,j) == 0){
				if(MIN_MAX){

                    plansza_w_grze.dodaj_ruch(i, j, gracz_1);
					nextRecursion = MinMax(plansza_w_grze, gracz_1, gracz_2, false, warunek, glebokosc+1);

					if(wartosc_MinMax == -2 or nextRecursion.first > wartosc_MinMax){

						wartosc_MinMax = nextRecursion.first;
						ruch = {i,j};
					}
				}
				else{

                    plansza_w_grze.dodaj_ruch(i, j, gracz_2);
					nextRecursion = MinMax(plansza_w_grze, gracz_1, gracz_2, true, warunek, glebokosc+1);

					if(wartosc_MinMax == -2 or nextRecursion.first < wartosc_MinMax){
						wartosc_MinMax = nextRecursion.first;
						ruch = {i,j};
					}
				}
                plansza_w_grze.usun_ruch(i, j);
			}
		}
	}
	return {wartosc_MinMax, ruch};
}


#include "Warunek_wygranej"

Warunek_wygranej::Warunek_wygranej(unsigned int nr_wygranej){
	this->numer_wygranej = nr_wygranej;
}

int Warunek_wygranej::Zwyciezca(Plansza &plansza_w_grze, Gracz gracz_1, Gracz gracz_2){

    unsigned int rozmiar_planszy = plansza_w_grze.zwroc_rozmiar();
    Macierz & plansz_2 = plansza_w_grze.zwroc_pola();
    int znacznik_1, znacznik_2;

    for(unsigned int i = 0; i < rozmiar_planszy; i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_1 = 1;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++){
                if(plansz_2(i,k) != gracz_1.id_gracza){

                    znacznik_1 = 0;
                    break;
                }
            }
            if (znacznik_1 == 1) return gracz_1.id_gracza;
        }
    }

    for(unsigned int i = 0; i < rozmiar_planszy; i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_2 = 1;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++){
                if(plansz_2(i,k) != gracz_2.id_gracza){

                    znacznik_2 = 0;
                    break;
                }
            }
            if (znacznik_2 == 1) return gracz_2.id_gracza;
        }
    }

    for(unsigned int i = 0; i < rozmiar_planszy; i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_1 = 1;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++){
                if(plansz_2(k, i) != gracz_1.id_gracza){

                    znacznik_1 = 0;
                    break;
                }
            }
            if (znacznik_1 == 1) return gracz_1.id_gracza;
        }
    }

    for(unsigned int i = 0; i < rozmiar_planszy; i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_2 = 1;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++)
            {
                if(plansz_2(k, i) != gracz_2.id_gracza){

                    znacznik_2 = 0;
                    break;
                }
            }
            if (znacznik_2 == 1) return gracz_2.id_gracza;
        }
    }

    unsigned int l;
    for(unsigned int i = 0; i <= (rozmiar_planszy - this->numer_wygranej); i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_1 = 1;
            l = i;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++){
                if(plansz_2(l,k) != gracz_1.id_gracza){

                    znacznik_1 = 0;
                    break;
                }
                l++;
            }
            if (znacznik_1 == 1) return gracz_1.id_gracza;
        }
    }

    for(unsigned int i = 0; i <= (rozmiar_planszy - this->numer_wygranej); i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_2 = 1;
            l = i;
            for(unsigned int k = j; k < (this->numer_wygranej + j); k++){
                if(plansz_2(l,k) != gracz_2.id_gracza){

                    znacznik_2 = 0;
                    break;
                }
                l++;
            }
            if (znacznik_2 == 1) return gracz_2.id_gracza;
        }
    }

    for(unsigned int i = 0; i <= (rozmiar_planszy - this->numer_wygranej); i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_1 = 1;
            l = i;
            for(unsigned int k = j + (this->numer_wygranej) - 1; k < rozmiar_planszy; k--){
                if(plansz_2(l,k) != gracz_1.id_gracza){

                    znacznik_1 = 0;
                    break;
                }
                l++;
            }
            if (znacznik_1 == 1) return gracz_1.id_gracza;
        }
    }

    for(unsigned int i = 0; i <= (rozmiar_planszy - this->numer_wygranej); i++){
        for(unsigned int j = 0; j <= (rozmiar_planszy - this->numer_wygranej); j++){

            znacznik_2 = 1;
            l = i;
            for(unsigned int k = j + (this->numer_wygranej) - 1; k < rozmiar_planszy; k--){
                if(plansz_2(l,k) != gracz_2.id_gracza){

                    znacznik_2 = 0;
                    break;
                }
                l++;
            }
            if (znacznik_2 == 1) return gracz_2.id_gracza;
        }
    }

    for(unsigned int i = 0; i < rozmiar_planszy; i++){
        for(unsigned int j = 0; j < rozmiar_planszy; j++){
            if (plansz_2(i,j) == 0) return -1;
        }
    }
    return 0;
}
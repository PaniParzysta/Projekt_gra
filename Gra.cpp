#include "Gra"

void Gra(){

    unsigned int numer_wygranej, rozmiar_planszy;
    char znak_AI, znak_gracza;
    pair<int, pair<int, int> > MIN_MAX;
    unsigned int wiersze, kolumny, licznik = 0;

    cout << "Podaj rozmiar planszy wiekszy od 3 i mniejszy od 50: ";
    cin >> rozmiar_planszy;
    while(rozmiar_planszy < 3 || rozmiar_planszy > 50){

        cout << "sprobuj ponownie: ";
        cin >> rozmiar_planszy;
    }

    Plansza plansza = Plansza(rozmiar_planszy);

    cout << "Podaj ile w rzedzie zeby wygrac: ";
    cin >> numer_wygranej;
    while(numer_wygranej <= 1 || numer_wygranej > rozmiar_planszy){

        cout << "sprobuj ponownie: ";
        cin >> numer_wygranej;
    }

    Warunek_wygranej win = Warunek_wygranej(numer_wygranej);

    cout << "Twoj znak? (x/o): ";
    cin >> znak_gracza;
    Gracz gracz = Gracz(1, znak_gracza);

    cout << "Znak AI: ";
    cin >> znak_AI;
    Gracz AI = Gracz(2, znak_AI);

    while(znak_AI == znak_gracza){

        cout << "Znak musi byc inny";
        cin >> znak_AI;
    }

    cout << "Kto zaczyna?" << endl << "Ty - wpisz 1" << endl << "AI - wpisz 2";
    cin >> licznik;
    while(licznik != 1 and licznik != 2){

        cout << "sprobuj ponownie: ";
        cin >> licznik;
    }

    int czy_zwycieztwo = win.Zwyciezca(plansza, gracz, AI);
    cout << "Podaj ruch - wiersz / kolumna" << endl;
    plansza.wyswietl_plansze(gracz, AI);

    while(czy_zwycieztwo == -1){
        if(licznik % 2 == 1){

            cout << "Twoj ruch: ";
            cin >> wiersze >> kolumny;
            while(plansza.czy_mozliwy_ruch(wiersze - 1, kolumny - 1, gracz) != true){

                cout << "sprobuj ponownie: ";
                cin >> wiersze >> kolumny;
            }
            plansza.dodaj_ruch(wiersze - 1, kolumny - 1, gracz);
        }
        else{

            cout << "AI's turn" <<endl;
            MIN_MAX = MinMax(plansza, gracz, AI, false, win, 0);
            plansza.dodaj_ruch(MIN_MAX.second.first, MIN_MAX.second.second, AI);
        }

        plansza.wyswietl_plansze(gracz, AI);
        licznik++;
        czy_zwycieztwo = win.Zwyciezca(plansza, gracz, AI);
    }

    if(czy_zwycieztwo == gracz.id_gracza){
        cout << "wygrales "<<endl;
    }
    else{

        if (czy_zwycieztwo == AI.id_gracza) cout << "przegrales" << endl;
        else cout << "rysuj" <<endl;
    }
}	


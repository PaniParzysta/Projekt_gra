#ifndef MINMAX_HH
#define MINMAX_HH
#include "Warunek_wygranej"

pair< int, pair<int, int> > MinMax(Plansza & plansza_w_grze, Gracz gracz_1, Gracz gracz_2, bool MIN_MAX, Warunek_wygranej warunek, int glebokosc);

#endif

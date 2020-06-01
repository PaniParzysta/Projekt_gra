#ifndef GRACZ_HH
#define GRACZ_HH

struct Gracz{

	unsigned int id_gracza;
	char znak_gracza;               //x/o

	Gracz(unsigned int id_gracza, char znak_gracza){

		this->id_gracza = id_gracza;
		this->znak_gracza = znak_gracza;
	}	
};

#endif

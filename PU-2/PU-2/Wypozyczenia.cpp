#include "Wypozyczenia.h"

Lista_wypozyczen::Lista_wypozyczen()
{
}

void Lista_wypozyczen::dodaj_wypozyczenie(int id_uzytkownika, const std::string & ISBN_ksiazki, int id_egzemplarza)
{
	m_lista.push_back(Wypozyczenie(ISBN_ksiazki, id_egzemplarza, id_uzytkownika));
}

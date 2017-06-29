#ifndef Wypozyczenia_h__
#define Wypozyczenia_h__

#include <string>
#include <vector>

class Wypozyczenie
{
public:

	Wypozyczenie(const std::string& ISBN, int id_egzemplarza, int id_uzytkownika) : m_id_egzemplarza(id_egzemplarza), m_ISBN(ISBN), m_id_uzytkownika(id_uzytkownika) {};
	std::string pobierz_ISBN_ksiazki() const { return m_ISBN; };
	int pobierz_id_egzemplarza() const { return m_id_egzemplarza; };
	int pobierz_id_uzytkownika() const { return m_id_uzytkownika; };

private:

	std::string m_ISBN;
	int  m_id_egzemplarza;
	int  m_id_uzytkownika;
};


class Lista_wypozyczen
{
public:

	Lista_wypozyczen();

	void dodaj_wypozyczenie(int id_uzytkownika, const std::string& ISBN_ksiazki, int id_egzemplarza);

private:

	std::vector<Wypozyczenie> m_lista;

};




#endif // Wypozyczenia_h__

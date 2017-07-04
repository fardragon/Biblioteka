#ifndef Ksiazki_h__
#define Ksiazki_h__

#include <vector>
#include <algorithm>

class Ksiazka;

class Egzemplarz
{

public:

	Egzemplarz(int id, int numer_wydania, const std::string& wydawnictwo) : m_id(id), m_numer_wydania(numer_wydania), m_wydawnictwo(wydawnictwo) {};
	int pobierz_id() const { return m_id; };

private:
	int m_id;
	int m_numer_wydania;
	std::string m_wydawnictwo;

	Ksiazka* m_ksiazka;

};


class Ksiazka
{

public:

	Ksiazka(const std::string& ISBN, const std::string& tytul, const std::string& autor) : m_ISBN(ISBN), m_tytul(tytul), m_autor(autor) {};
	bool dodaj_egzemplarz(int id, int numer_wydania, const std::string& wydawnictwo);
	std::string pobierz_ISBN() const { return m_ISBN; };
	std::string pobierz_tytul() const { return m_tytul; };


private:

	std::string m_ISBN;
	std::string m_tytul;
	std::string m_autor;


	std::vector<Egzemplarz> m_egzemplarze;

};


class Lista_ksiazek
{
public:

	Lista_ksiazek();
	bool dodaj_ksiazke(const std::string& ISBN, const std::string& tytul, const std::string& autor);
	bool dodaj_egzemplarz(const std::string& ISBN, int id, int numer_wydania, const std::string& wydawnictwo);
	std::string znajdz_tytul(const std::string& ISBN);

private:

	std::vector <Ksiazka> m_lista;


};

#endif // Ksiazki_h__

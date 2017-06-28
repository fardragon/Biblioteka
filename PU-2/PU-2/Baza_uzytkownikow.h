#ifndef Baza_uzytkownikow_h__
#define Baza_uzytkownikow_h__

#include <string>
#include <vector>
#include <tuple>
#include <map>

enum class login
{
	blad,
	uzytkownik,
	pracownik,
	admin
};


struct Dane_uzytkownika
{
	std::string Imie;
	std::string Nazwisko;
	std::string PESEL;
};

class Baza_uzytkownikow
{
public:

	Baza_uzytkownikow();
	std::pair<login,int> logowanie(const std::string& nazwa, const std::string& haslo);
	std::vector<std::pair<int,Dane_uzytkownika>> znajdz_id_uzytkownika(const std::string& imie, const std::string& nazwisko);

private:
	std::vector<std::tuple<int,std::string,std::string,login>> m_uzytkownicy;
	std::map<int, Dane_uzytkownika> m_dane_uzytkownikow;


private:

};




#endif // Baza_uzytkownikow_h__

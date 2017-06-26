#ifndef Baza_uzytkownikow_h__
#define Baza_uzytkownikow_h__

#include <string>
#include <vector>
#include <tuple>

enum class login
{
	blad,
	uzytkownik,
	pracownik,
	admin
};


class Baza_uzytkownikow
{
public:

	Baza_uzytkownikow();
	std::pair<login,int> logowanie(const std::string& nazwa, const std::string& haslo);

private:
	std::vector<std::tuple<int,std::string,std::string,login>> m_uzytkownicy;



private:

};




#endif // Baza_uzytkownikow_h__

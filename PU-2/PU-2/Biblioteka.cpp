#include "Biblioteka.h"

Biblioteka::Biblioteka(): m_status(status::zamknij), m_petla(true), m_uid(0)
{
	m_uzytkownik = std::make_unique<Gosc>(&m_baza_uzytkownikow, std::bind(&Biblioteka::zamknij, this), std::bind(&Biblioteka::loguj_pracownik, this,std::placeholders::_1));


}

void Biblioteka::start()
{
	
	while (m_petla)
	{
		m_uzytkownik->start();
		switch (m_status)
			{
			case status::loguj_uzytkownik:
				break;
			case status::loguj_pracownik:
				m_uzytkownik.reset(nullptr);
				m_uzytkownik = std::make_unique<Pracownik>(&m_baza_uzytkownikow, std::bind(&Biblioteka::zamknij, this), m_uid,&m_lista_rezerwacji, &m_lista_wypozyczen, &m_lista_ksiazek);
				break;
			case status::loguj_administrator:
				break;
			case status::zamknij:
				m_petla = false;
				break;
			default:
				break;
			}
	}

}

void Biblioteka::zamknij()
{
	m_status = status::zamknij;
}

void Biblioteka::loguj_pracownik(int id)
{
	m_uid = id;
	m_status = status::loguj_pracownik;
}

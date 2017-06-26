#include "Biblioteka.h"

Biblioteka::Biblioteka(): m_status(status::zamknij), m_loop(true)
{
	m_uzytkownik = std::make_unique<Gosc>(&m_baza_uzytkownikow, std::bind(&Biblioteka::zamknij, this));
}

void Biblioteka::start()
{
	
	while (m_loop)
	{
		m_uzytkownik->start();
		switch (m_status)
			{
			case status::loguj_uzytkownik:
				break;
			case status::loguj_pracownik:
				break;
			case status::loguj_administrator:
				break;
			case status::zamknij:
				m_loop = false;
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

#include "GUI.h"

GUI::GUI(std::function<void(void)> zamknij): 
	m_zamknij(zamknij), m_guzik_wys(50), m_guzik_szer(150), m_guzik_ilosc(0)
{
	m_window.create(sf::VideoMode(800, 600, 32), "Biblioteka",sf::Style::Titlebar|sf::Style::Close);
	m_window.setFramerateLimit(30);
	m_gui.setWindow(m_window);
}

void GUI::start()
{
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			m_gui.handleEvent(m_event);
			switch (m_event.type)
			{
			case sf::Event::Closed:
				this->koniec();
				m_zamknij();
				break;

			default:
				break;
			}


		}
		m_window.clear(sf::Color::Black);
		m_gui.draw();
		m_window.display();
	}


}

void GUI::czysc_gui()
{
	m_gui.removeAllWidgets();
	m_guzik_ilosc = 0;
}

void GUI::dodaj_guzik(std::string tresc, std::function<void(void)> akcja)
{
	auto guzik = tgui::Button::create(tresc);
	guzik->connect("pressed", akcja);
	guzik->setSize({ m_guzik_szer,m_guzik_wys });
	guzik->setPosition({0,m_guzik_ilosc*m_guzik_wys});
	m_gui.add(guzik);
	++m_guzik_ilosc;
}

void GUI::koniec()
{
	m_window.close();
}


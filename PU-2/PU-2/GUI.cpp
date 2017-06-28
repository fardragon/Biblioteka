#include "GUI.h"

GUI::GUI(std::function<void(void)> zamknij): 
	m_zamknij(zamknij), m_guzik_wys(50), m_guzik_szer(150), m_guzik_ilosc(0)
{
	m_window.create(sf::VideoMode(800, 600, 32), "Biblioteka",sf::Style::Titlebar|sf::Style::Close);
	m_window.setFramerateLimit(30);
	m_gui.setWindow(m_window);
}

GUI::~GUI()
{
	m_window.close();
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
		m_window.clear(sf::Color(0,0,100));
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
	guzik->setPosition({ "(parent.width - width)/2",m_guzik_ilosc*m_guzik_wys});
	m_gui.add(guzik);
	++m_guzik_ilosc;
}

void GUI::dodaj_tekst(std::string tresc)
{
	auto tekst = tgui::Label::create(tresc);
	tekst->setSize({ m_gui.getWindow()->getSize().x,m_guzik_wys });
	tekst->setPosition({ 0,m_guzik_ilosc*m_guzik_wys });
	tekst->getRenderer()->setBackgroundColor(sf::Color(200,200, 200));
	tekst->getRenderer()->setBorders(2);
	tekst->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
	tekst->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);

	m_gui.add(tekst);
	++m_guzik_ilosc;
}

tgui::EditBox::Ptr GUI::dodaj_editbox(std::string tresc, bool ukryj, bool id)
{
	auto editbox = tgui::EditBox::create();
	editbox->setSize({ 2*m_guzik_szer,m_guzik_wys });
	editbox->setPosition({ "(parent.width - width)/2",m_guzik_ilosc*m_guzik_wys });
	editbox->setDefaultText(tresc);
	if (ukryj)
	{
		editbox->setPasswordCharacter('*');
	}
	if (id)
	{
		editbox->setInputValidator(tgui::EditBox::Validator::UInt);
	}
	m_gui.add(editbox);
	++m_guzik_ilosc;
	return editbox;
}

tgui::ListBox::Ptr GUI::dodaj_listbox()
{
	auto listbox = tgui::ListBox::create();
	listbox->setSize({ 2 * m_guzik_szer,6*m_guzik_wys });
	listbox->setPosition({ "(parent.width - width)/2",m_guzik_ilosc*m_guzik_wys });
	m_gui.add(listbox);
	m_guzik_ilosc += 6;
	return listbox;
}

void GUI::koniec()
{
	m_window.close();
}


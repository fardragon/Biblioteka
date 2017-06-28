#ifndef GUI_h__
#define GUI_h__

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <functional>

class GUI
{
public:
	GUI(std::function<void(void)> zamknij);
	~GUI();
	void start();
	void czysc_gui();
	void dodaj_guzik(std::string tresc, std::function<void(void)> akcja);
	void dodaj_tekst(std::string tresc);
	tgui::EditBox::Ptr dodaj_editbox(std::string tresc, bool ukryj, bool id);
	tgui::ListBox::Ptr dodaj_listbox();
	void koniec();



private:
	sf::RenderWindow m_window;
	sf::Event m_event;

	tgui::Gui m_gui;

	std::function<void(void)> m_zamknij;

	int m_guzik_wys;
	int m_guzik_szer;
	int m_guzik_ilosc;


};


#endif // GUI_h__

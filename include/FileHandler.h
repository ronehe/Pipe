#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Macros.h"

class FileHandler{
	//--------------public--------functions-----------------------//
public:
	FileHandler();

	~FileHandler();

	

	char what_In_Location(const sf::Vector2u cur_Loc)const;// reuturns elemnt on board 

	sf::Vector2u get_Size() const;//returns size of the the vector for controller 

	bool rebuild_Map();

	void change_Map(sf::Vector2i change, char request);

	bool set_Size();

	void set_Map();	//sets the map on vector

	int get_Time()const { return m_Time; };
	void set_time(int time) { m_Time = time; };
	//--------------private--------functions-----------------------//
private:
	void file_close();


	//------------------members-----------------------//
private:
	sf::Vector2u m_Size;
	std::vector<std::string>m_fileHandler;
	std::ifstream m_Cf;
	int m_Time;
};
#pragma once

#include <iostream>
#include <string>
#include <vector>

class PlayingCard {

public:

	PlayingCard(char, std::string);

	void setType(char);
	void setSuit(std::string);

	char getType();
	std::string getSuit();

private:

	char _type;
	std::string _suit;
};

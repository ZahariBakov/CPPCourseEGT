#include "Player.h"

Player::Player() {
	this->_money = 100000;
	this->_score = 0;
	this->_bet = 100;
}

int Player::getMoney() const {
	return this->_money;
}

int Player::getScore() const {
	return this->_score;
}

int Player::getBet() const {
	return this->_bet;
}

void Player::increaseMoney(int profit) {
	this->_money += profit;
}

void Player::decreaseMoney(int loss) {
	this->_money -= loss;
}

void Player::resetScore() {
	this->_score = 0;
}

void Player::setBet(bool big) {
	if (big == true) {
		this->_bet = 1000;
	}
}

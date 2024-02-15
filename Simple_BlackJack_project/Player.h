#pragma once

/// Player class
class Player {
public:
	Player();/*!< Default constructor*/

	int getMoney() const;/*!< Function that return the value of money*/
	int getScore() const;/*!< Function that return the value of score*/
	int getBet() const;/*!< Function that return the value of bet*/

	void increaseMoney(int profit);/*!< Function that increase the value of money*/
	void decreaseMoney(int loss);/*!< Function that decrease the value of money*/
	void resetScore();/*!< Function that set the value of score to 0*/
	void increaseScore(int points);/*!< Function that increase the value of score*/
	void setBet(bool big);/*!< Function that set the value of bet*/

private:
	int _money;/*!< Private variable for money*/
	int _score;/*!< Private variable for score*/
	int _bet;/*!< Private variable for bet*/
};

#pragma once

class Player {
public:
	Player();

	int getMoney() const;
	int getScore() const;
	int getBet() const;

	void increaseMoney(int profit);
	void decreaseMoney(int loss);
	void resetScore();
	void setBet(bool big);

private:
	int _money;
	int _score;
	int _bet;
};

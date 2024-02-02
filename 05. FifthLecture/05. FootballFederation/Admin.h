#pragma once

#include <vector>
#include <map>

#include "User.h"
#include "Team.h"
#include "Fans.h"

class Admin : public User {
public:

	Admin(std::string, std::string);

	void addTeam(Team);
	void removeTeam(Team);
	void updateTeam(Team);

	std::vector<Team> getTeams();

private:

	std::vector<Team> _teams;
};

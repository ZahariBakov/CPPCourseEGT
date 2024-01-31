#include "User.h"
#include "Team.h"
#include"Admin.h"
#include "Schedule.h"
#include "Referee.h"
#include "Fans.h"

static void printRanking(Team* t1, Team* t2, Team* t3) {
    std::map<int, std::string, std::greater<int>> ranking;

    ranking[t1->getPoints()] = t1->getName();
    ranking[t2->getPoints()] = t2->getName();
    ranking[t3->getPoints()] = t3->getName();

    std::cout << "       ------ Ranking -----" << std::endl;
    for (auto& team : ranking) {
        std::cout << team.second << " - " << team.first << " points" << std::endl;
    }
}

int main() {
    // Create admin
    Admin a1("Zahari", "pass1");

    // Create teams
    Team team1("Real Madrid", "Madrid");
    Team team2("Inter", "Milan");
    Team team3("Liverpool", "Liverpool");

    // Add teams
    std::cout << "Number of teams: " << a1.getTeams().size() << std::endl;
    a1.addTeam(team1);
    a1.addTeam(team2);
    a1.addTeam(team3);
    std::cout << "\n" << "Number of teams: " << a1.getTeams().size() << std::endl;

    // remove team
    //a1.removeTeam(team2);
    //std::cout << "Number of teams: " << a1.getTeams().size() << std::endl;

    // Update team
    //Team team4("Slavia", "Plovdiv");
    //a1.updateTeam(team4);

    // Show all teams
    for (auto& t : a1.getTeams()) {
        std::cout << t.getName() << " - " << t.getCity() << std::endl;
    }

    std::cout << std::endl;

    Schedule schedule;
    schedule.addMatch(&a1, 1, &team1, &team2);
    schedule.addMatch(&a1, 1, &team1, &team3);
    schedule.addMatch(&a1, 5, &team3, &team2);
    schedule.addMatch(&a1, 0, &team2, &team1);
    schedule.addMatch(&a1, 4, &team3, &team1);
    schedule.addMatch(&a1, 6, &team2, &team3);
    schedule.printSchedule();

    schedule.updateMatch(&a1, 2, &team3, &team1);
    schedule.updateMatch(&a1, 5, &team1, &team3);

    schedule.deleteMatch(&a1, 2);

    schedule.addMatch(&a1, 7, &team3, &team1);
    schedule.printSchedule();

    Referee r1("First referee", "pass2");
    Referee r2("Second referee", "pass3");

    Fans f1("First Real Madrid fan", "pass4");
    Fans f2("First Inter fan", "pass5");
    Fans f3("First Liverpool fan", "pass6");
    Fans f4("Second Real Madrid fan", "pass7");
    Fans f5("Second Inter fan", "pass8");
    Fans f6("Second Liverpool fan", "pass9");

    schedule.buyTicket(&f1, 1);
    schedule.buyTicket(&f2, 1);
    schedule.buyTicket(&f3, 3);
    schedule.buyTicket(&f4, 7);
    schedule.buyTicket(&f1, 7);
    schedule.buyTicket(&f5, 6);

    schedule.printMoneyFromTicket(&a1);

    schedule.addReferee(&a1, 1, r1.getName());
    schedule.addReferee(&a1, 7, r2.getName());
    schedule.addReferee(&a1, 3, r1.getName());
    schedule.addReferee(&a1, 4, r2.getName());
    schedule.addReferee(&a1, 5, r1.getName());
    schedule.addReferee(&a1, 6, r2.getName());

    std::cout << "----------- The season begins -----------" << std::endl;

    schedule.addResult(&r1, &team1, &team2);
    schedule.addResult(&r2, &team1, &team3);
    schedule.addResult(&r1, &team3, &team2);
    schedule.addResult(&r2, &team2, &team1);
    schedule.addResult(&r1, &team3, &team1);
    schedule.addResult(&r2, &team2, &team3);

    printRanking(&team1, &team2, &team3);

    return 0;
}

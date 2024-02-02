#include <iostream>

#include "Screening.h"
#include "Hall.h"
#include "Cinema.h"

int main() {
    Screening sc1("Star Wars", 100);
    Screening sc2("The Godfather", 75);

    std::vector<Screening> screenings;
    screenings.push_back(sc1);
    screenings.push_back(sc2);

    Hall h1("Hall 8", 250, screenings);
    h1.print();


    Hall h2("Hall 2", 125, screenings);
    h2.print();

    Screening sc3("Indian Jones", 50);
    Screening sc4("Dune 2", 33);

    std::vector<Screening> screening2;
    screening2.push_back(sc3);
    screening2.push_back(sc4);


    Hall h3("Hall 10", 500, screening2);
    h3.print();

    Screening sc5("Nemo 2", 55);
    h3.addScreening(sc5);
    h3.print();

    std::vector<Hall> halls;
    halls.push_back(h1);
    halls.push_back(h2);

    Cinema cinema("Arena", "Sofia", halls);
    cinema.print();

    cinema.addHall(h3);
    cinema.print();

    halls.push_back(h3);

    std::string movieName;
    std::cout << "Enter the name of the movie you are looking for." << std::endl;
    std::getline(std::cin, movieName);

    for (int i = 0; i < halls.size(); ++i) {
        for (int j = 0; j < halls.at(i).getScreeningList().size(); ++j) {
            if (movieName == halls.at(i).getScreeningList().at(j).getMovieName()) {
                std::cout << " We found projection " << halls.at(i).getScreeningList().at(j).getMovieName() << std::endl;
                halls.at(i).getScreeningList().at(j).print();
                halls.at(i).print();
            }
        }
    }

    //for (int i = 0; i < halls.size(); i++) { // is for halls
    //    //        Hall h = halls.at(i); // current hall
    //    //        vector<Screening> scr = halls.at(i).getScreeningList();  // projection in the current hall
    //    for (int j = 0; j < halls.at(i).getScreeningList().size(); j++) {  // is for screening vector
    //        //            Screening scrObj = halls.at(i).getScreeningList().at(j); // current projection
    //        //            string currentMovieName = halls.at(i).getScreeningList().at(j).getMovieName();  // movie name from screening object

    //        if (movieName == halls.at(i).getScreeningList().at(j).getMovieName()) {
    //            cout << " We found projection " << halls.at(i).getScreeningList().at(j).getMovieName() << endl;
    //            halls.at(i).getScreeningList().at(j).print();
    //            halls.at(i).print();
    //        }
    //    }
    //}

    /*for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls.at(i).getScreeningList().size(); j++) {
            if (movieName == halls.at(i).getScreeningList().at(j).getMovieName()) {
                std::cout << " We found projection " << halls.at(i).getScreeningList().at(j).getMovieName() << std::endl;
                halls.at(i).getScreeningList().at(j).print();
                halls.at(i).print();
            }
        }
    }*/

    return 0;
}

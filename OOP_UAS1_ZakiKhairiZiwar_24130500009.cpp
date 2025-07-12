#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Abstract Person
class Person {
protected:
    string personId;
    string firstName;
    string lastName;
    string dateOfBirth;
    string nationality;

public:
    Person(string id, string fn, string ln, string dob, string nation)
        : personId(id), firstName(fn), lastName(ln), dateOfBirth(dob), nationality(nation) {}

    virtual string getFullName() const {
        return firstName + " " + lastName;
    }

    virtual ~Person() {}
};

// Player
class Player : public Person {
private:
    string playerId;
    string teamId;
    string position;
    int jerseyNumber;
    double marketValue;

public:
    Player(string id, string fn, string ln, string dob, string nat, string playerId,
           string teamId, string position, int jersey, double value)
        : Person(id, fn, ln, dob, nat), playerId(playerId), teamId(teamId), position(position),
          jerseyNumber(jersey), marketValue(value) {}

    void train() {
        cout << getFullName() << " is training." << endl;
    }

    void playMatch() {
        cout << getFullName() << " is playing a match." << endl;
    }
};

// Coach
class Coach : public Person {
private:
    string coachId;
    string teamId;
    string role;
    string licenseLevel;

public:
    Coach(string id, string fn, string ln, string dob, string nat,
          string coachId, string teamId, string role, string license)
        : Person(id, fn, ln, dob, nat), coachId(coachId), teamId(teamId),
          role(role), licenseLevel(license) {}

    void conductTraining() {
        cout << getFullName() << " is conducting a training session." << endl;
    }

    void selectSquad() {
        cout << getFullName() << " is selecting the squad." << endl;
    }
};

// Staff
class Staff : public Person {
private:
    string staffId;
    string clubId;
    string department;
    string role;

public:
    Staff(string id, string fn, string ln, string dob, string nat,
          string staffId, string clubId, string department, string role)
        : Person(id, fn, ln, dob, nat), staffId(staffId), clubId(clubId),
          department(department), role(role) {}

    void performDuties() {
        cout << getFullName() << " is performing duties as " << role << "." << endl;
    }
};

// Contract
class Contract {
public:
    string contractId;
    string startDate;
    string endDate;
    double salary;
    double clauses;
    string clubId;
    string personId;

    Contract(string id, string start, string end, double sal, double cls, string club, string person)
        : contractId(id), startDate(start), endDate(end), salary(sal), clauses(cls),
          clubId(club), personId(person) {}

    void renew() {
        cout << "Contract " << contractId << " has been renewed." << endl;
    }

    void terminate() {
        cout << "Contract " << contractId << " has been terminated." << endl;
    }
};

// Club
class Club {
private:
    string clubId;
    string name;
    string foundingDate;
    double budget;
    string league;
    string stadiumId;
    vector<string> teams;

public:
    Club(string id, string name, string date, double budget, string league, string stadium)
        : clubId(id), name(name), foundingDate(date), budget(budget), league(league),
          stadiumId(stadium) {}

    void addTeam(string team) {
        teams.push_back(team);
    }

    vector<string> getTeams() const {
        return teams;
    }

    void signSponsor(string sponsor) {
        cout << "Club " << name << " signed sponsor: " << sponsor << endl;
    }
};

// Team
class Team {
private:
    string teamId;
    string clubId;
    string league;
    string division;
    string name;
    vector<Player> players;

public:
    Team(string id, string club, string league, string div, string name)
        : teamId(id), clubId(club), league(league), division(div), name(name) {}

    void addPlayer(const Player& p) {
        players.push_back(p);
    }

    void scheduleTraining() {
        cout << "Training scheduled for team " << name << endl;
    }
};

class Sponsor {
public:
    void renewContract(string date, double newValue) {
        cout << "Sponsor contract renewed to " << date << " with value " << newValue << endl;
    }
};

class TrainingSession {
public:
    void recordAttendance(const Player& player, bool present) {
        cout << player.getFullName() << (present ? " hadir" : " tidak hadir") << " pada latihan." << endl;
    }
};

class Match {
public:
    void recordScore(int homeScore, int awayScore) {
        cout << "Match score recorded: " << homeScore << "-" << awayScore << endl;
    }

    map<string, string> generateReport() {
        return {{"report", "Match report generated"}};
    }
};

class Stadium {
public:
    void hostMatch(Match match) {
        cout << "Match hosted at stadium." << endl;
    }
};

class Season {
public:
    vector<Match> getMatches() {
        return {};
    }

    map<string, int> getStandings() {
        return {{"TeamA", 1}, {"TeamB", 2}};
    }
};

int main() {
    Player p("P001", "Lionel", "Messi", "1987-06-24", "Argentina", "PL001", "TM001", "Forward", 10, 50000000);
    Coach c("C001", "Pep", "Guardiola", "1971-01-18", "Spain", "CO001", "TM001", "Head Coach", "UEFA Pro");
    Staff s("S001", "Anna", "Smith", "1980-05-10", "England", "ST001", "CL001", "Medical", "Doctor");

    p.train();
    c.conductTraining();
    s.performDuties();

    return 0;
}

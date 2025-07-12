#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// === Superclass ===
class Person {
protected:
    string personId, firstName, lastName, dateOfBirth, nationality;

public:
    Person(string id, string fn, string ln, string dob, string nat)
        : personId(id), firstName(fn), lastName(ln), dateOfBirth(dob), nationality(nat) {}

    virtual string getFullName() const {
        return firstName + " " + lastName;
    }

    virtual ~Person() {}
};

// === Player ===
class Player : public Person {
private:
    string playerId, teamId, position, status;
    int jerseyNumber;
    double marketValue;

public:
    Player(string pid, string fn, string ln, string dob, string nat,
           string playerId, string teamId, string pos, int jersey, double value, string status)
        : Person(pid, fn, ln, dob, nat), playerId(playerId), teamId(teamId), position(pos),
          jerseyNumber(jersey), marketValue(value), status(status) {}

    void train() { cout << getFullName() << " is training.\n"; }
    void playMatch() { cout << getFullName() << " is playing a match.\n"; }
};

// === Coach ===
class Coach : public Person {
private:
    string coachId, teamId, role, licenseLevel;

public:
    Coach(string pid, string fn, string ln, string dob, string nat,
          string coachId, string teamId, string role, string license)
        : Person(pid, fn, ln, dob, nat), coachId(coachId), teamId(teamId),
          role(role), licenseLevel(license) {}

    void conductTraining() { cout << getFullName() << " is conducting training.\n"; }
    void selectSquad() { cout << getFullName() << " is selecting the squad.\n"; }
};

// === Staff ===
class Staff : public Person {
private:
    string staffId, clubId, department, role;

public:
    Staff(string pid, string fn, string ln, string dob, string nat,
          string staffId, string clubId, string dept, string role)
        : Person(pid, fn, ln, dob, nat), staffId(staffId), clubId(clubId),
          department(dept), role(role) {}

    void performDuties() { cout << getFullName() << " is performing duties as " << role << ".\n"; }
};

// === Contract ===
class Contract {
public:
    string contractId, startDate, endDate, clauses, personId, clubId;
    double salary;

    Contract(string id, string start, string end, double sal, string cls, string pid, string cid)
        : contractId(id), startDate(start), endDate(end), salary(sal), clauses(cls),
          personId(pid), clubId(cid) {}

    void renew() { cout << "Contract " << contractId << " renewed.\n"; }
    void terminate() { cout << "Contract " << contractId << " terminated.\n"; }
};

// === Sponsor ===
class Sponsor {
private:
    string sponsorId, name, contactPerson, phone, email;
    double contractValue;
    string contractStartDate, contractEndDate;

public:
    Sponsor(string id, string name, string contact, string phone, string email,
            double value, string start, string end)
        : sponsorId(id), name(name), contactPerson(contact), phone(phone), email(email),
          contractValue(value), contractStartDate(start), contractEndDate(end) {}

    void renewContract(string newEndDate, double newValue) {
        contractEndDate = newEndDate;
        contractValue = newValue;
        cout << "Sponsor contract renewed to " << newEndDate << " with value " << newValue << endl;
    }
};

// === Stadium ===
class Stadium {
public:
    string stadiumId, name, address;
    int capacity;

    Stadium(string id, string name, int cap, string addr)
        : stadiumId(id), name(name), capacity(cap), address(addr) {}

    void hostMatch() { cout << "Match hosted at " << name << ".\n"; }
};

// === Team ===
class Team {
private:
    string teamId, clubId, league, division, name;
    vector<Player> players;

public:
    Team(string id, string cid, string lg, string div, string nm)
        : teamId(id), clubId(cid), league(lg), division(div), name(nm) {}

    void addPlayer(const Player& p) {
        players.push_back(p);
        cout << "Added player to team " << name << endl;
    }

    void removePlayer(const string& playerName) {
        players.erase(remove_if(players.begin(), players.end(),
                                [&playerName](const Player& p) {
                                    return p.getFullName() == playerName;
                                }),
                      players.end());
        cout << "Removed player from team " << name << endl;
    }

    void scheduleTraining() {
        cout << "Training scheduled for team " << name << endl;
    }
};

// === Club ===
class Club {
private:
    string clubId, name, foundingDate, stadiumId;
    double budget;
    vector<Team> teams;

public:
    Club(string id, string nm, string date, double budg, string stadium)
        : clubId(id), name(nm), foundingDate(date), budget(budg), stadiumId(stadium) {}

    void addTeam(const Team& team) { teams.push_back(team); }

    void manageBudget(double value) {
        budget += value;
        cout << "Updated budget: " << budget << endl;
    }

    vector<Team> getTeams() { return teams; }
};

// === Training Session ===
class TrainingSession {
public:
    string sessionId, sessionDate, sessionTime, location, focusArea, teamId;

    void recordAttendance(const Player& p, bool present) {
        cout << p.getFullName() << (present ? " hadir" : " tidak hadir") << " pada latihan.\n";
    }
};

// === Match ===
class Match {
public:
    string matchId, matchDate, matchTime, competition;
    int homeScore = 0, awayScore = 0;
    string homeTeamId, awayTeamId, stadiumId, seasonId;

    void recordScore(int home, int away) {
        homeScore = home;
        awayScore = away;
        cout << "Recorded score: " << home << "-" << away << endl;
    }

    map<string, string> generateReport() {
        return {
            {"matchId", matchId},
            {"result", to_string(homeScore) + "-" + to_string(awayScore)}
        };
    }
};

// === Season ===
class Season {
public:
    string seasonId;
    int year;
    string league, startDate, endDate;
    vector<Match> matches;

    vector<Match> getMatches() { return matches; }

    map<string, int> getStandings() {
        return {
            {"TeamA", 12},
            {"TeamB", 10}
        };
    }
};

// === Main ===
int main() {
    Club club("CL001", "Garuda FC", "2001-01-01", 100000000, "ST001");
    Team team("TM001", "CL001", "Liga 1", "A", "Tim Senior");

    Player p("P001", "Zaki", "Ziwar", "2002-08-15", "Indonesia", "PL001", "TM001", "Forward", 9, 1e6, "Fit");
    team.addPlayer(p);

    Coach c("C001", "Imran", "Nasution", "1975-10-12", "Indonesia", "CH001", "TM001", "Head Coach", "A");
    c.conductTraining();

    Stadium s("ST001", "GBK", 80000, "Jakarta");
    s.hostMatch();

    Match m;
    m.recordScore(2, 1);

    TrainingSession ts;
    ts.recordAttendance(p, true);

    return 0;
}
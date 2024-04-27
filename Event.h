#ifndef EVENT_H
#define EVENT_H
using namespace std;

#include <string>
#include <vector>

class Event
{
private:
    int eventId;
    string title;
    string description;
    string date;
    string startTime;
    string endTime;
    //    string time;
    string location;
    vector<string> attendees;

public:
    //    Event(int id, string &t, string &desc, string &d, string &tme, string &loc);
    Event(int id, string &t, string &desc, string &d, string &startT, string &endT, string &loc);

    int getEventId();
    string getTitle();
    void setTitle(string &t);
    string getDescription();
    void setDescription(string &desc);
    string getDate();
    void setDate(string &d);
    string getStartTime();
    void setStartTime(string &startT);
    string getEndTime();
    void setEndTime(string &endT);
    string getLocation();
    void setLocation(string &loc);

    // Additional methods for managing attendees
    void addAttendee(string &attendee);
    void removeAttendee(string &attendee);
    bool isAttendee(string &attendee);
    void displayAttendees();

    // Method to display event details
    void displayEventDetails();

    // Method to check if an attendee is registered for the event
    bool hasAttendee(string &attendee);

    //new code ==================================================== for attendee
    vector<string>& getAttendees();
};

#endif // EVENT_H

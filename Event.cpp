#include "Event.h"
#include <iostream>
#include <algorithm>
using namespace std;

Event::Event(int id, string &t, string &desc, string &d, string &startT, string &endT, string &loc)
    : eventId(id), title(t), description(desc), date(d), startTime(startT), endTime(endT), location(loc) {}

//getter
int Event::getEventId()
{
    return eventId;
}

string Event::getTitle()
{
    return title;
}

string Event::getDescription()
{
    return description;
}

string Event::getDate()
{
    return date;
}

string Event::getStartTime()
{
    return startTime;
}

string Event::getEndTime()
{
    return endTime;
}

string Event::getLocation()
{
    return location;
}

//new code ============================================ getter for attendee
vector<string>& Event::getAttendees()
{
    return attendees;
}

//setter
void Event::setTitle(string &t) {
    title = t;
}

void Event::setDescription(string &desc) {
    description = desc;
}

void Event::setDate(string &d) {
    date = d;
}

void Event::setStartTime(string &startT) {
    startTime = startT;
}

void Event::setEndTime(string &endT) {
    endTime = endT;
}

void Event::setLocation(string &loc) {
    location = loc;
}


void Event::addAttendee(string &attendee)
{
    attendees.push_back(attendee);
}

void Event::removeAttendee(string &attendee)
{
    auto it = find(attendees.begin(), attendees.end(), attendee);
    if (it != attendees.end())
    {
        attendees.erase(it);
    }
}

bool Event::isAttendee(string &attendee)
{
    return find(attendees.begin(), attendees.end(), attendee) != attendees.end();
}

bool Event::hasAttendee(string &attendee)
{
    return find(attendees.begin(), attendees.end(), attendee) != attendees.end();
}

void Event::displayAttendees()
{
    if (attendees.empty())
    {
        cout << "No attendees for this event." << endl;
    }
    else
    {
        cout << "Attendees of Event ID " << eventId << ":" << endl;
        for (string &attendee : attendees)
        {
            cout << "- " << attendee << endl;
        }
    }
}

void Event::displayEventDetails()
{
    cout << "Event ID: " << eventId << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Location: " << location << endl;
    cout << "Attendees: ";
    for (auto &attendee : attendees)
    {
        cout << attendee << ", ";
    }
    cout << endl;
    cout << endl;
}
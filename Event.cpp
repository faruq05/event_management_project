#include "Event.h"
#include <iostream>
#include <algorithm>
using namespace std;

Event::Event(int id, string &t, string &desc, string &d, string &startT, string &endT, string &loc)
{
    this->eventId = id;
    this->title = t;
    this->description = desc;
    this->date = d;
    this->startTime = startT;
    this->endTime = endT;
    this->location = loc;
}

// getter
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

vector<string> &Event::getAttendees()
{
    return attendees;
}

// setters
void Event::setTitle(string &t)
{
    title = t;
}

void Event::setDescription(string &desc)
{
    description = desc;
}

void Event::setDate(string &d)
{
    date = d;
}

void Event::setStartTime(string &startT)
{
    startTime = startT;
}

void Event::setEndTime(string &endT)
{
    endTime = endT;
}

void Event::setLocation(string &loc)
{
    location = loc;
}

//add attendee  O(1)
void Event::addAttendee(string attendee)
{
    attendees.push_back(attendee);
}

// remove an attendee   O(n)
void Event::removeAttendee(string &attendee)
{
    auto it = find(attendees.begin(), attendees.end(), attendee);
    if (it != attendees.end())
    {
        attendees.erase(it);
    }
}

// is attendee      O(n)
bool Event::isAttendee(string& attendee)  {
    return find(attendees.begin(), attendees.end(), attendee) != attendees.end();
}

// display attendee     O(n)
void Event::displayAttendees()
{
    if (attendees.empty())
    {
        cout << "No attendees for this event." << endl;
    }
    else
    {
        cout << endl << "Attendees of " << title << ":";
        cout<<endl;
        for (string &attendee : attendees)
        {
            cout << "- " << attendee << endl;
        }
    }
}

// display event details    O(1)
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
    if (!attendees.empty())
    {
        // for ( auto &attendee : attendees)
        // {
        //     cout << attendee << ", ";
        // }
        cout<<attendees.front();
        for(auto it = next(attendees.begin()); it!= attendees.end(); ++it)
        {
            cout << ", " << *it;
        }
        cout << endl;
    }
    else
    {
        cout << "No attendees has been added for this event yet." << endl;
    }

    cout << endl;
}

// Function to show events attended by a specific attendee O(n)
void Event::attendeeVisited(const string& attendee)
{
    bool found = false;
    for (const string& att : attendees)
    {
        if (att == attendee)
        {
            if (!found)
            {
                cout << "Events attended by " << attendee << ": " << endl;
                found = true;
            }
            cout << "- " << title << endl; 
        }
    }
    if (!found)
    {
        cout << attendee << " has not attended any events." << endl;
    }
}
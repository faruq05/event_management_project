#include "EventLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// constructor
EventLinkedList::EventLinkedList() : head(nullptr) {}

// Destructor
EventLinkedList::~EventLinkedList()
{
    // Implement destructor to free memory (delete all nodes)
    EventNode *current = head;
    while (current != nullptr)
    {
        EventNode *next = current->next;
        delete current;
        current = next;
    }
}

// Insert a new event into the linked list
void EventLinkedList::insertEvent(Event &e)
{
    if (hasScheduleConflict(e))
    {
        return; // Do not insert the event if there's a conflict
    }
    EventNode *newNode = new EventNode(e);
    newNode->next = head;
    head = newNode;
}

// Delete an event from the linked list by event ID
void EventLinkedList::deleteEvent(int eventId)
{
    EventNode *current = head;
    EventNode *prev = nullptr;

    while (current != nullptr && current->event.getEventId() != eventId)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Event with ID " << eventId << " not found." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
    cout << "Event with ID " << eventId << " deleted successfully." << endl;
}

// Find an event in the linked list by event ID
EventLinkedList::EventNode *EventLinkedList::findEventById(int eventId)
{
    EventNode *current = head;
    while (current != nullptr)
    {
        if (current->event.getEventId() == eventId)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Event not found
}

// Display details of all events in the linked list
void EventLinkedList::displayAllEvents()
{
    EventNode *current = head;
    while (current != nullptr)
    {
        current->event.displayEventDetails(); // Display event details for current node
        current = current->next;
    }
}

// Search for an event in the linked list by title
void EventLinkedList::searchEventByTitle(string &title)
{
    EventNode *current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->event.getTitle() == title)
        {
            current->event.displayEventDetails();
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "Event with title '" << title << "' not found." << endl;
    }
}

// Update details of an event in the linked list
// void EventLinkedList::updateEvent(int eventId)
// {
//     EventNode *eventNode = findEventById(eventId);
//     if (eventNode == nullptr)
//     {
//         cout << "Event with ID " << eventId << " not found." << endl;
//         return;
//     }

//     // Prompt user for updated details
//     string title, desc, date, startT, endT, loc;
//     cout << "Enter updated title: ";
//     getline(cin >> ws, title);
//     cout << "Enter updated description: ";
//     getline(cin >> ws, desc);
//     cout << "Enter updated date (MM/DD/YYYY): ";
//     getline(cin >> ws, date);
//     cout << "Enter updated Start Time (HH:MM): ";
//     getline(cin >> ws, startT);
//     cout << "Enter updated End Time (HH:MM): ";
//     getline(cin >> ws, endT);
//     cout << "Enter updated location: ";
//     getline(cin >> ws, loc);

//     // Update event details
//     eventNode->event = Event(eventId, title, desc, date, startT, endT, loc);
//     cout << "Event with ID " << eventId << " updated successfully." << endl;
// }

void EventLinkedList::updateEvent(int eventId)
{
    EventNode *eventNode = findEventById(eventId);
    if (eventNode == nullptr)
    {
        cout << "Event with ID " << eventId << " not found." << endl;
        return;
    }

    Event &event = eventNode->event;
    string choice;
    bool updateMade = false;

    do
    {
        cout << endl;
        cout << "Which detail would you like to update for '" << event.getTitle() << "' ?" << endl;
        cout << "========================================================================" << endl;
        cout << "1. Update the Title" << endl;
        cout << "2. Update the Description" << endl;
        cout << "3. Update the Date" << endl;
        cout << "4. Update the Start Time" << endl;
        cout << "5. Update the End Time" << endl;
        cout << "6. Update the Location" << endl;
        cout << "7. Update the Attendees " << endl;
        cout << "0. Done Updating" << endl;
        cout << "Enter your choice: ";
        getline(cin >> ws, choice);

        if (choice == "1")
        {
            string newTitle;
            cout << "Enter new title: ";
            getline(cin >> ws, newTitle);
            event.setTitle(newTitle);
            updateMade = true;
        }
        else if (choice == "2")
        {
            string newDescription;
            cout << "Enter new description: ";
            getline(cin >> ws, newDescription);
            event.setDescription(newDescription);
            updateMade = true;
        }
        else if (choice == "3")
        {
            string newDate;
            cout << "Enter new date (MM/DD/YYYY): ";
            getline(cin >> ws, newDate);
            event.setDate(newDate);
            updateMade = true;
        }
        else if (choice == "4")
        {
            string newStartTime;
            cout << "Enter new start time (HH:MM): ";
            getline(cin >> ws, newStartTime);
            event.setStartTime(newStartTime);
            updateMade = true;
        }
        else if (choice == "5")
        {
            string newEndTime;
            cout << "Enter new end time (HH:MM): ";
            getline(cin >> ws, newEndTime);
            event.setEndTime(newEndTime);
            updateMade = true;
        }
        else if (choice == "6")
        {
            string newLocation;
            cout << "Enter new location: ";
            getline(cin >> ws, newLocation);
            event.setLocation(newLocation);
            updateMade = true;
        }
        else if (choice == "7")
        {
            cout << "Attendee management not implemented yet." << endl;
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != "0");

    if (updateMade)
    {
        cout << "Event updated successfully" << endl;
    }
    else
    {
        cout << "No changes made" << endl;
    }
}

// Implementation of manageAttendees method
void EventLinkedList::manageAttendees(int eventId)
{
    EventNode *eventNode = findEventById(eventId);
    if (eventNode == nullptr)
    {
        cout << "Event with ID " << eventId << " not found." << endl;
        return;
    }

    char choice;
    do
    {
        cout << "\nEvent ID: " << eventId << endl;
        cout << "Title: " << eventNode->event.getTitle() << endl;
        cout << "Description: " << eventNode->event.getDescription() << endl;
        cout << "Date: " << eventNode->event.getDate() << endl;
        cout << "Time: " << eventNode->event.getStartTime() << endl;
        cout << "Time: " << eventNode->event.getEndTime() << endl;
        cout << "Location: " << eventNode->event.getLocation() << endl;

        cout << "\n1. Add attendee" << endl;
        cout << "2. Remove attendee" << endl;
        cout << "3. Display attendees" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string attendeeName;
            cout << "Enter attendee names to add (enter 's' to stop): ";
            while (cin >> attendeeName && attendeeName != "s")
            {
                eventNode->event.addAttendee(attendeeName);
                cout << attendeeName << " added to attendees." << endl;
                cout << "Enter next attendee (or 's' to stop): ";
            }
            break;
        }
        case '2':
        {
            string attendeeName;
            cout << "Enter attendee name to remove: ";
            cin >> attendeeName;
            eventNode->event.removeAttendee(attendeeName);
            cout << attendeeName << " removed from attendees." << endl;
            break;
        }
        case '3':
            eventNode->event.displayAttendees(); // Display attendees of the event
            break;
        case '4':
            cout << "Exiting attendee management." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');
}

// Manage attendees of an event in the linked list
void EventLinkedList::manageEvent(int eventId)
{
    EventNode *eventNode = findEventById(eventId);
    if (eventNode == nullptr)
    {
        cout << "Event with ID " << eventId << " not found." << endl;
        return;
    }

    char choice;
    do
    {
        cout << "\nEvent ID: " << eventId << endl;
        cout << "Title: " << eventNode->event.getTitle() << endl;
        cout << "Description: " << eventNode->event.getDescription() << endl;
        cout << "Date: " << eventNode->event.getDate() << endl;
        cout << "Time: " << eventNode->event.getStartTime() << endl;
        cout << "Time: " << eventNode->event.getEndTime() << endl;
        cout << "Location: " << eventNode->event.getLocation() << endl;

        cout << "\n1. Add attendee" << endl;
        cout << "2. Remove attendee" << endl;
        cout << "3. Display attendees" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string attendeeName;
            cout << "Enter attendee name to add: ";
            cin >> attendeeName;
            eventNode->event.addAttendee(attendeeName);
            cout << attendeeName << " added to attendees." << endl;
            break;
        }
        case '2':
        {
            string attendeeName;
            cout << "Enter attendee name to remove: ";
            cin >> attendeeName;
            eventNode->event.removeAttendee(attendeeName);
            cout << attendeeName << " removed from attendees." << endl;
            break;
        }
        case '3':
            eventNode->event.displayEventDetails(); // Display event details including attendees
            break;
        case '4':
            cout << "Exiting event management." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');
}

// Check for schedule conflict with a new event
bool EventLinkedList::hasScheduleConflict(Event &newEvent)
{
    EventNode *current = head;
    while (current != nullptr)
    {
        // Check for overlap based on date and start time
        if (current->event.getDate() == newEvent.getDate() &&
            current->event.getStartTime() == newEvent.getStartTime() &&
            current->event.getLocation() == newEvent.getLocation())
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Save all events in the linked list to a file
void EventLinkedList::saveEventsToFile(string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    EventNode *current = head;
    while (current != nullptr)
    {
        outFile << current->event.getEventId() << ","
                << current->event.getTitle() << ","
                << current->event.getDescription() << ","
                << current->event.getDate() << ","
                << current->event.getStartTime() << ","
                << current->event.getEndTime() << ","
                << current->event.getLocation() << " ";

        // for attendess save for file
        auto &attendees = current->event.getAttendees();
        for (const auto &attendee : attendees)
        {
            outFile << "," << attendee;
        }
        outFile << endl;
        // ends
        current = current->next;
    }

    outFile.close();
}

// Load events from a file into the linked list
void EventLinkedList::loadEventsFromFile(string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        // Split the line into tokens using comma as the delimiter
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // Check if there are at least 7 tokens (event details)
        if (tokens.size() < 7)
        {
            continue;
        }

        int id = stoi(tokens[0]);
        string title = tokens[1];
        string desc = tokens[2];
        string date = tokens[3];
        string startT = tokens[4];
        string endT = tokens[5];
        string loc = tokens[6];

        // Create a new Event object
        Event event(id, title, desc, date, startT, endT, loc);

        // Add attendees to the event
        for (size_t i = 7; i < tokens.size(); ++i)
        {
            event.addAttendee(tokens[i]);
        }

        insertEvent(event);
    }

    cout << "Events loaded from " << filename << " successfully." << endl;
    inFile.close();
}
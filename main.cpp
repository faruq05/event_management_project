#include <iostream>
#include <string>
#include "Event.h"
#include "EventLinkedList.h"
#include "Event.cpp"
#include "EventLinkedList.cpp"
using namespace std;

void displayMenu()
{
    cout << "\n======= Campus Event Management System =======" << endl;
    cout << "1. Create Event" << endl;
    cout << "2. Update Event" << endl;
    cout << "3. Delete Event" << endl;
    cout << "4. Display All Events" << endl;
    cout << "5. Search Event by Title" << endl;
    cout << "6. Manage Attendees of an Event" << endl;
    cout << "7. Save Events to File" << endl;
    cout << "8. Load Events from File" << endl;
    cout << "9. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    EventLinkedList eventList; // Create an instance of EventLinkedList
    string filename = "events.txt";
    eventList.loadEventsFromFile(filename);
    char choice;
    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore any remaining newline characters in the input buffer

        switch (choice)
        {
        case '1':
        {
            int id;
            string title, desc, date, startT, endT, loc;
            cout << "Enter event ID: ";
            cin >> id;
            cin.ignore(); // Ignore newline character after reading integer input
            cout << "Enter event title: ";
            getline(cin, title);
            cout << "Enter event description: ";
            getline(cin, desc);
            cout << "Enter event date (MM/DD/YYYY): ";
            getline(cin, date);
            cout << "Enter event Start time (HH:MM): ";
            getline(cin, startT);
            cout << "Enter event End time (HH:MM): ";
            getline(cin, endT);
            cout << "Enter event location: ";
            getline(cin, loc);

            Event newEvent(id, title, desc, date, startT, endT, loc);
            eventList.insertEvent(newEvent);
            if (eventList.hasScheduleConflict(newEvent))
            {
                cout << "Schedule conflict with the following event"<<endl;
            }
            else
            {
                eventList.insertEvent(newEvent);
                cout << "Event created successfully." << endl;
            }
            break;
        }
        case '2':
        {
            int id;
            cout << "Enter event ID to update: ";
            cin >> id;
            eventList.updateEvent(id); // Call updateEvent method
            break;
        }
        case '3':
        {
            int id;
            cout << "Enter event ID to delete: ";
            cin >> id;
            eventList.deleteEvent(id);
            break;
        }
        case '4':
        {
            // Display all events
            eventList.displayAllEvents();
            break;
        }
        case '5':
        {
            string title;
            cout << "Enter event title to search: ";

            getline(cin, title);
            eventList.searchEventByTitle(title);
            break;
        }
        case '6':
        {
            int id;
            cout << "Enter event ID to manage attendees: ";
            cin >> id;
            eventList.manageAttendees(id); // Call manageAttendees method
            break;
        }
        case '7':
        {
            string filename;
            cout << "Enter filename to save events: ";
            cin >> filename;
            eventList.saveEventsToFile(filename);
            break;
        }
        case '8':
        {
            string filename;
            cout << "Enter filename to load events: ";
            cin >> filename;
            eventList.loadEventsFromFile(filename);
            break;
        }
        case '9':
            cout << "Exiting Campus Event Management System." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '9');

    return 0;
}

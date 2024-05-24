#include <iostream>
#include <string>
#include "Event.h"
#include "EventLinkedList.h"
#include "Event.cpp"
#include "EventLinkedList.cpp"
using namespace std;

void displayMenu()
{
    cout <<"\n======= Campus Event Management System =======" << endl;
    cout << "1. Create Event" << endl;
    cout << "2. Update Event" << endl;
    cout << "3. Delete Event" << endl;
    cout << "4. Display All Events" << endl;
    cout << "5. Search Event by Title" << endl;
    cout << "6. Manage Attendees of an Event" << endl;
    cout << "7. Save Events to File" << endl;
    // cout << "8. Load Events from File" << endl;
    cout << "8. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice:"<<endl ;
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
        cout << endl;
        cin.ignore();

        switch (choice)
        {
        case '1':
        {
            int id;
            string title, desc, date, startT, endT, loc;
            cout << "Enter event ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter event title: ";
            getline(cin >> ws, title);
            cout << "Enter event description: ";
            getline(cin >> ws, desc);
            cout << "Enter event date (MM/DD/YYYY): ";
            getline(cin >> ws, date);
            cout << "Enter event Start time (HH:MM): ";
            getline(cin >> ws, startT);
            cout << "Enter event End time (HH:MM): ";
            getline(cin >> ws, endT);
            cout << "Enter event location: ";
            getline(cin >> ws, loc);
            Event newEvent(id, title, desc, date, startT, endT, loc);

            // Check for schedule conflict
            if (eventList.hasScheduleConflict(newEvent))
            {
                cout << "Schedule conflict with the following event: " << newEvent.getTitle() << endl;
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
            eventList.updateEvent(id);
            break;
        }
        case '3':
        {
            int id;
            cout << "Enter event ID to delete: ";
            cin >> id;
            cout << endl;
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
            cout << endl;
            getline(cin, title);
            eventList.searchEventByTitle(title);
            break;
        }
        case '6':
        {
            int id;
            cout << "Enter event ID to manage attendees: ";
            cin >> id;
            eventList.manageAttendees(id);
            break;
        }
        case '7':
        {
            string filename;
            ifstream file_check("events.txt"); // Check if the file exists
            if (file_check.good())
            {
                filename = "events.txt"; // Use the default filename if it exists
                eventList.saveEventsToFile(filename);
                cout << "Events saved to " << filename << " successfully." << endl;
            }
            else
            {
                cout << "Enter filename to save events: ";
                cin >> filename;
                eventList.saveEventsToFile(filename);
            }
            break;
        }
        // case '8':
        // {
        //     string filename;
        //     cout << "Enter filename to load events: ";
        //     cin >> filename;
        //     eventList.loadEventsFromFile(filename);
        //     break;
        // }
        case '8':
            cout  << "Exiting Campus Event Management System." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '8');

    return 0;
}

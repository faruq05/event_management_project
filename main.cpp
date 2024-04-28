#include <iostream>
#include <string>
#include "Event.h"
#include "EventLinkedList.h"
#include "Event.cpp"
#include "EventLinkedList.cpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
using namespace std;

void displayMenu()
{
    cout << YELLOW <<"\n======= Campus Event Management System =======" << endl;
    cout << "1. Create Event" << endl;
    cout << "2. Update Event" << endl;
    cout << "3. Delete Event" << endl;
    cout << "4. Display All Events" << endl;
    cout << "5. Search Event by Title" << endl;
    cout << "6. Manage Attendees of an Event" << endl;
    cout << "7. Save Events to File" << endl;
    // cout << "8. Load Events from File" << endl;
    cout << "8. Exit" << endl;
    cout << "=============================================" << RESET << endl;
    cout << BLUE << "Enter your choice: "<< RESET;
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
            cout << BLUE << "Enter event ID: " << RESET;
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
                cout << GREEN << "Event created successfully." << RESET << endl;
            }
            break;
        }
        case '2':
        {
            int id;
            cout << BLUE << "Enter event ID to update: " << RESET;
            cin >> id;
            eventList.updateEvent(id);
            break;
        }
        case '3':
        {
            int id;
            cout << BLUE << "Enter event ID to delete: " << RESET;
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
            cout << BLUE << "Enter event title to search: " << RESET;
            cout << endl;
            getline(cin, title);
            eventList.searchEventByTitle(title);
            break;
        }
        case '6':
        {
            int id;
            cout << BLUE << "Enter event ID to manage attendees: " << RESET;
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
                cout << GREEN << "Events saved to " << filename << " successfully." << RESET << endl;
            }
            else
            {
                cout << BLUE << "Enter filename to save events: " << RESET;
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
            cout << YELLOW << "Exiting Campus Event Management System." << RESET << endl;
            break;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }
    } while (choice != '8');

    return 0;
}

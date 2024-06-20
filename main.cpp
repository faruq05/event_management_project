// #include <iostream>
// #include <string>
// #include "Event.h"
// #include "EventLinkedList.h"
// #include "Event.cpp"
// #include "EventLinkedList.cpp"

// using namespace std;

// void displayMenu(bool isAdmin)
// {
//     cout << "\n======= Campus Event Management System =======" << endl;
//     if (isAdmin)
//     {
//         cout << "1. Create Event" << endl;
//         cout << "2. Update Event" << endl;
//         cout << "3. Delete Event" << endl;
//         cout << "4. Display All Events" << endl;
//         cout << "5. Search Event by Title" << endl;
//         cout << "6. Manage Attendees of an Event" << endl;
//         cout << "7. Save Events to File" << endl;
//         cout << "8. Exit" << endl;
//     }
//     else
//     {
//         cout << "1. Display All Events" << endl;
//         cout << "2. Search Event by Title" << endl;
//         cout << "3. Exit" << endl;
//     }
//     cout << "=============================================" << endl;
//     cout << "Enter your choice:" << endl;
// }

// bool loginAsAdmin()
// {
//     string password;
//     cout << "Enter admin password: ";
//     cin >> password;
//     return password == "admin123";  // Predefined password
// }

// int main()
// {
//     EventLinkedList eventList; // Create an instance of EventLinkedList
//     string filename = "events.txt";
//     eventList.loadEventsFromFile(filename);
//     char choice;

//     cout << "Login as (1) Admin or (2) User: ";
//     int userType;
//     cin >> userType;
//     bool isAdmin = (userType == 1) ? loginAsAdmin() : false;
//     if (userType == 1 && !isAdmin)
//     {
//         cout << "Incorrect password. Access denied." << endl;
//         return 0;
//     }

//     do
//     {
//         displayMenu(isAdmin);
//         cin >> choice;
//         cout << endl;
//         cin.ignore();

//         if (isAdmin)
//         {
//             switch (choice)
//             {
//                 case '1':
//                 {
//                     int id;
//                     string title, desc, date, startT, endT, loc;
//                     cout << "Enter event ID: ";
//                     cin >> id;
//                     cin.ignore();
//                     cout << "Enter event title: ";
//                     getline(cin >> ws, title);
//                     cout << "Enter event description: ";
//                     getline(cin >> ws, desc);
//                     cout << "Enter event date (MM/DD/YYYY): ";
//                     getline(cin >> ws, date);
//                     cout << "Enter event Start time (HH:MM): ";
//                     getline(cin >> ws, startT);
//                     cout << "Enter event End time (HH:MM): ";
//                     getline(cin >> ws, endT);
//                     cout << "Enter event location: ";
//                     getline(cin >> ws, loc);
//                     Event newEvent(id, title, desc, date, startT, endT, loc);

//                     // Check for schedule conflict
//                     if (eventList.hasScheduleConflict(newEvent))
//                     {
//                         cout << "Schedule conflict with the following event: " << newEvent.getTitle() << endl;
//                     }
//                     else
//                     {
//                         eventList.insertEvent(newEvent);
//                         cout << "Event created successfully." << endl;
//                     }
//                     break;
//                 }
//                 case '2':
//                 {
//                     int id;
//                     cout << "Enter event ID to update: ";
//                     cin >> id;
//                     eventList.updateEvent(id);
//                     break;
//                 }
//                 case '3':
//                 {
//                     int id;
//                     cout << "Enter event ID to delete: ";
//                     cin >> id;
//                     cout << endl;
//                     eventList.deleteEvent(id);
//                     break;
//                 }
//                 case '4':
//                     eventList.displayAllEvents();
//                     break;
//                 case '5':
//                 {
//                     string title;
//                     cout << "Enter event title to search: ";
//                     cout << endl;
//                     getline(cin, title);
//                     eventList.searchEventByTitle(title);
//                     break;
//                 }
//                 case '6':
//                 {
//                     int id;
//                     cout << "Enter event ID to manage attendees: ";
//                     cin >> id;
//                     eventList.manageAttendees(id);
//                     break;
//                 }
//                 case '7':
//                 {
//                     string filename;
//                     ifstream file_check("events.txt"); // Check if the file exists
//                     if (file_check.good())
//                     {
//                         filename = "events.txt"; // Use the default filename if it exists
//                         eventList.saveEventsToFile(filename);
//                         cout << "Events saved to " << filename << " successfully." << endl;
//                     }
//                     else
//                     {
//                         cout << "Enter filename to save events: ";
//                         cin >> filename;
//                         eventList.saveEventsToFile(filename);
//                     }
//                     break;
//                 }
//                 case '8':
//                     cout << "Exiting Campus Event Management System." << endl;
//                     break;
//                 default:
//                     cout << "Invalid choice. Please try again." << endl;
//             }
//         }
//         else
//         {
//             switch (choice)
//             {
//                 case '1':
//                     eventList.displayAllEvents();
//                     break;
//                 case '2':
//                 {
//                     string title;
//                     cout << "Enter event title to search: ";
//                     cout << endl;
//                     getline(cin, title);
//                     eventList.searchEventByTitle(title);
//                     break;
//                 }
//                 case '3':
//                     cout << "Exiting Campus Event Management System." << endl;
//                     break;
//                 default:
//                     cout << "Invalid choice. Please try again." << endl;
//             }
//         }
//     } while ((isAdmin && choice != '8') || (!isAdmin && choice != '3'));

//     return 0;
// }

#include <iostream>
#include <string>
#include "Event.h"
#include "EventLinkedList.h"
#include "Event.cpp"
#include "EventLinkedList.cpp"

using namespace std;

void displayMenu(bool isAdmin)
{
    cout << "\n======= Campus Event Management System =======" << endl;
    if (isAdmin)
    {
        cout << "1. Create Event" << endl;
        cout << "2. Update Event" << endl;
        cout << "3. Delete Event" << endl;
        cout << "4. Display All Events" << endl;
        cout << "5. Search Event by Title" << endl;
        cout << "6. Manage Attendees of an Event" << endl;
        cout << "7. Save Events to File" << endl;
        cout << "8. Exit" << endl;
        cout << "9. Back to Login" << endl; // Adding back button for admin
    }
    else
    {
        cout << "1. Display All Events" << endl;
        cout << "2. Search Event by Title" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Back to Login" << endl; // Adding back button for user
    }
    cout << "=============================================" << endl;
    cout << "Enter your choice:" << endl;
}

bool loginAsAdmin()
{
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return password == "admin123";  // Predefined password
}

int main()
{
    EventLinkedList eventList; // Create an instance of EventLinkedList
    string filename = "events.txt";
    eventList.loadEventsFromFile(filename);
    char choice;
    bool isAdmin = false;

    while (true)
    {
        cout << "Log in as Admin (Press 1:)" <<endl << "Log in as User (Press 2:)" <<endl << "or Exit Programme (Press 3:)";
        int userType;
        cin >> userType;
        if (userType == 1)
        {
            isAdmin = loginAsAdmin();
            if (!isAdmin)
            {
                cout << "Incorrect password. Access denied." << endl;
                continue;
            }
        }
        else if (userType == 2)
        {
            isAdmin = false;
        }
        else if (userType == 3)
        {
            cout << "Exiting Campus Event Management System." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        bool exitMenu = false;
        do
        {
            displayMenu(isAdmin);
            cin >> choice;
            cout << endl;
            cin.ignore();

            if (isAdmin)
            {
                switch (choice)
                {
                    case '1':
                    {
                        while (true)
                        {
                            int id;
                            string title, desc, date, startT, endT, loc;
                            cout << "Enter event ID (or 'b' to go back): ";
                            string input;
                            cin >> input;
                            if (input == "b") break;
                            id = stoi(input);
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
                                break;
                            }
                        }
                        break;
                    }
                    case '2':
                    {
                        while (true)
                        {
                            int id;
                            cout << "Enter event ID to update (or 'b' to go back): ";
                            string input;
                            cin >> input;
                            if (input == "b") break;
                            id = stoi(input);
                            eventList.updateEvent(id);
                            break;
                        }
                        break;
                    }
                    case '3':
                    {
                        while (true)
                        {
                            int id;
                            cout << "Enter event ID to delete (or 'b' to go back): ";
                            string input;
                            cin >> input;
                            if (input == "b") break;
                            id = stoi(input);
                            cout << endl;
                            eventList.deleteEvent(id);
                            break;
                        }
                        break;
                    }
                    case '4':
                        eventList.displayAllEvents();
                        break;
                    case '5':
                    {
                        while (true)
                        {
                            string title;
                            cout << "Enter event title to search (or 'b' to go back): ";
                            cout << endl;
                            getline(cin, title);
                            if (title == "b") break;
                            eventList.searchEventByTitle(title);
                        }
                        break;
                    }
                    case '6':
                    {
                        while (true)
                        {
                            int id;
                            cout << "Enter event ID to manage attendees (or 'b' to go back): ";
                            string input;
                            cin >> input;
                            if (input == "b") break;
                            id = stoi(input);
                            eventList.manageAttendees(id);
                            break;
                        }
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
                            cout << "Enter filename to save events (or 'b' to go back): ";
                            string input;
                            cin >> input;
                            if (input == "b") break;
                            filename = input;
                            eventList.saveEventsToFile(filename);
                        }
                        break;
                    }
                    case '8':
                        cout << "Exiting Campus Event Management System." << endl;
                        exitMenu = true;
                        break;
                    case '9':
                        cout << "Going back to login menu." << endl;
                        exitMenu = true;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
            else
            {
                switch (choice)
                {
                    case '1':
                        eventList.displayAllEvents();
                        break;
                    case '2':
                    {
                        while (true)
                        {
                            string title;
                            cout << "Enter event title to search (or 'b' to go back): ";
                            cout << endl;
                            getline(cin, title);
                            if (title == "b") break;
                            eventList.searchEventByTitle(title);
                        }
                        break;
                    }
                    case '3':
                        cout << "Exiting Campus Event Management System." << endl;
                        exitMenu = true;
                        break;
                    case '4':
                        cout << "Going back to login menu." << endl;
                        exitMenu = true;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
        } while (!exitMenu);
    }

    return 0;
}

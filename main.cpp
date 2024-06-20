#include <iostream>
#include <string>
#include <ctime>
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
    return password == "admin123"; // Predefined password
}

bool isValidDate(const string &date)
{
    if (date.size() != 10 ||
        !isdigit(date[0]) || !isdigit(date[1]) ||
        date[2] != '/' ||
        !isdigit(date[3]) || !isdigit(date[4]) ||
        date[5] != '/' ||
        !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9]))
    {
        return false;
    }

    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2021)
    {
        return false;
    }

    return true;
}

bool isValidTime(const string &time)
{
    if (time.size() != 5 ||
        !isdigit(time[0]) || !isdigit(time[1]) ||
        time[2] != ':' ||
        !isdigit(time[3]) || !isdigit(time[4]))
    {
        return false;
    }

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return false;
    }

    return true;
}

bool isFutureDateTime(const string &date, const string &time)
{
    // Parse the date and time
    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    // Get current date and time
    time_t now = std::time(0);
    tm *ltm = std::localtime(&now);

    if (year < 1900 + ltm->tm_year)
        return false;
    if (year == 1900 + ltm->tm_year && month < 1 + ltm->tm_mon)
        return false;
    if (year == 1900 + ltm->tm_year && month == 1 + ltm->tm_mon && day < ltm->tm_mday)
        return false;
    if (year == 1900 + ltm->tm_year && month == 1 + ltm->tm_mon && day == ltm->tm_mday)
    {
        if (hour < ltm->tm_hour)
            return false;
        if (hour == ltm->tm_hour && minute <= ltm->tm_min)
            return false;
    }

    return true;
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
        cout << "\n======= Login Portal =======" << endl;
        cout << "1. Admin Panel" << endl;
        cout << "2. User Panel" << endl;
        cout << "3. Exit" << endl;
        cout << "=============================================" << endl;
        cout << "Enter your choice:" << endl;
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
                        if (input == "b")
                            break;
                        id = stoi(input);
                        cin.ignore();
                        cout << "Enter event title: ";
                        getline(cin >> ws, title);
                        cout << "Enter event description: ";
                        getline(cin >> ws, desc);

                        bool validDate = false;
                        while (!validDate)
                        {
                            cout << "Enter event date (MM/DD/YYYY): ";
                            getline(cin >> ws, date);
                            validDate = isValidDate(date);
                            if (!validDate)
                            {
                                cout << "Invalid date format. Please enter date in MM/DD/YYYY format." << endl;
                                continue;
                            }

                            cout << "Enter event Start time (HH:MM): ";
                            getline(cin >> ws, startT);
                            if (!isValidTime(startT))
                            {
                                cout << "Invalid start time format. Please enter time in HH:MM format." << endl;
                                validDate = false; // To repeat the loop
                                continue;
                            }

                            if (!isFutureDateTime(date, startT))
                            {
                                cout << "The event start time must be in the future." << endl;
                                validDate = false; // To repeat the loop
                            }
                        }

                        bool validEndTime = false;
                        while (!validEndTime)
                        {
                            cout << "Enter event End time (HH:MM): ";
                            getline(cin >> ws, endT);
                            validEndTime = isValidTime(endT);
                            if (!validEndTime)
                            {
                                cout << "Invalid end time format. Please enter time in HH:MM format." << endl;
                                continue;
                            }

                            if (!isFutureDateTime(date, endT))
                            {
                                cout << "The event end time must be in the future." << endl;
                                validEndTime = false;
                            }
                        }

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
                        if (input == "b")
                            break;
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
                        if (input == "b")
                            break;
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
                        if (title == "b")
                            break;
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
                        if (input == "b")
                            break;
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
                        if (input == "b")
                            break;
                        filename = input;
                        eventList.saveEventsToFile(filename);
                    }
                    break;
                }
                case '8':
                    cout << "Exiting Campus Event Management System." << endl;
                    cout << "Have a nice day!" << endl;
                    exit(0); // Terminates the program
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
                        if (title == "b")
                            break;
                        eventList.searchEventByTitle(title);
                    }
                    break;
                }
                case '3':
                    cout << "Exiting Campus Event Management System." << endl;
                    cout << "Have a nice day!" << endl;
                    exit(0); // Terminates the program
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

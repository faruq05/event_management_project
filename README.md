# event_management_project

**1. Introduction**
----------------------


a.	Project Overview:

In this project, we created an event management system using C++ with Linked List structure. The objective is to let the users manage their events easily. Our project allows users to create, update, delete and search for events. It also facilitates organizing attendees and save event details in one place.


b.	Project Objective:

Our goal of this project is:
1. Allow users to create events
2. Allow users to update their particular event
3. Allow users to search for an event
4. Allow users to see if their event conflicts with any existing event
5. Allow users to delete events
6. Allow users to add, delete and view attendees for their events
7. Allow user to save event information



**2. Methodology**
-------------------
This program has the following components: Event.h and EventLinkedList.h, associated with Event.cpp and EventLinkedList.cpp respective implementation files. Further, there is a main.cpp file containing the main function. The command line interface (CLI) approach is used for building the user interface.


a.	Event operation:

For this operation, the following methods are:
1. void EventLinkedList::insertEvent(Event &e)
2. void EventLinkedList::deleteEvent(int eventId)
3. void EventLinkedList::searchEventByTitle(string &title)
4. void EventLinkedList::updateEvent(int eventId)
5. void EventLinkedList::displayAllEvents()
6. void Event::displayEventDetails()
7. bool EventLinkedList::hasScheduleConflict(Event &newEvent)


b.	Attendee Management

For managing Attendee, the following methods are:
1. void Event::addAttendee(string attendee)
2. void Event::removeAttendee(string &attendee)
3. bool Event::hasAttendee(string &attendee)
4. void Event::displayAttendees()
5. void EventLinkedList::updateEvent(int eventId)
6. void EventLinkedList::manageAttendees(int eventId)


c.	Database management

In this program, we saved all the event information into the “events.txt” file. For this operation, the following methods are: 
1. void EventLinkedList::saveEventsToFile(string &filename)
2. void EventLinkedList::loadEventsFromFile(string &filename)

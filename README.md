# event_management_project

1. Introduction

1. a.	Project Overview:
In this project, we created an event management system using C++ with Linked List structure. The objective is to let the users manage their events easily. Our project allows users to create, update, delete and search for events. It also facilitates organizing attendees and save event details in one place.

1. b.	Project Objective:
Our goal of this project is:
•	Allow users to create events
•	Allow users to update their particular event
•	Allow users to search for an event
•	Allow users to see if their event conflicts with any existing event
•	Allow users to delete events
•	Allow users to add, delete and view attendees for their events
•	Allow user to save event information



2. Methodology

This program has the following components: Event.h and EventLinkedList.h, associated with Event.cpp and EventLinkedList.cpp respective implementation files. Further, there is a main.cpp file containing the main function. The command line interface (CLI) approach is used for building the user interface.

2. a.	Event operation:
For this operation, the following methods are:
•	void EventLinkedList::insertEvent(Event &e)
•	void EventLinkedList::deleteEvent(int eventId)
•	void EventLinkedList::searchEventByTitle(string &title)
•	void EventLinkedList::updateEvent(int eventId)
•	void EventLinkedList::displayAllEvents()
•	void Event::displayEventDetails()
•	bool EventLinkedList::hasScheduleConflict(Event &newEvent)

2. b.	Attendee Management
For managing Attendee, the following methods are:
•	void Event::addAttendee(string attendee)
•	void Event::removeAttendee(string &attendee)
•	bool Event::hasAttendee(string &attendee)
•	void Event::displayAttendees()
•	void EventLinkedList::updateEvent(int eventId)
•	void EventLinkedList::manageAttendees(int eventId)

2. c.	Database management
In this program, we saved all the event information into the “events.txt” file. For this operation, the following methods are: 
•	void EventLinkedList::saveEventsToFile(string &filename)
•	void EventLinkedList::loadEventsFromFile(string &filename)

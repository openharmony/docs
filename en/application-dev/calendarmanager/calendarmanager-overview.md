# Introduction to Calendar Kit

Calendar Kit provides calendar and event management capabilities, which usually refer to APIs that can be used to access and operate calendar data. These APIs allow you to integrate time-related event services (such as travel, catering, sports, and entertainment) in other applications with the system calendar to implement functions such as event management, creation, and query.

## Available Capabilities

Calendar Kit provides management capability for accounts and events.

- Create a calendar account.

  You can create a calendar account specific to your application, after which an account ID is returned. The account ID is the auto-increment primary key of the data table and is used as the unique identifier of the account.

- Obtain the calendar account.

  You can obtain information about a specified calendar account or all calendar accounts created by the current application.

- Delete a calendar account.

  You can delete a specified calendar account, after which all events associated with the calendar account will be deleted.

- Create a calendar event.

  After obtaining the calendar account information, you can create an event under the obtained calendar account. When creating an event, you can set an event reminder and its notification is displayed when the set time arrives.

  After a calendar account is created, an account ID is returned. The account ID is the auto-increment primary key of the data table and is used as the unique identifier of the account.

- Delete an event.

  You can delete one or more events with specified event IDs at a time.

- Update an event.

  You can update event information based on the event ID, including the event title, location, start time, end time, and reminder time.

- Query events.

  You can query events by event ID, event title, event start time, and event end time.

## Features

**One-click event service**: With the permanent authorization mechanism, after the user allows your application to read and write the system calendar, the corresponding event service can be written into the calendar in the form of deeplink. According to the reminder rules set by yourself, when an event is about to expire or expires, the corresponding service button will be displayed in the calendar application, notification, and widgets. Users can tap the button to redirect to the service landing page in one step.

## Working Principles

Calendar Kit provides a set of APIs for obtaining calendar accounts, and writing calendar events to or reading events from the obtained accounts. If an event has a reminder time set, the system sends a reminder to the user when the set time arrives.

## Constraints

- To use the capabilities of Calendar Kit, you need to obtain the **ohos.permission.READ_CALENDAR** and **ohos.permission.WRITE_CALENDAR** permissions to read or write calendars and events. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

- Currently, the capabilities and APIs of Calendar Kit can be used only in the stage model.

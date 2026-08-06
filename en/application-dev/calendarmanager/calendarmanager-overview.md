# About This Kit

<!--Kit: Calendar Kit-->
<!--Subsystem: Applications-->
<!--Owner: @qq_42718467-->
<!--Designer: @qq_42718467-->
<!--Tester: @z30055209-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=8852d3851a09566b1fcf279f3997e3c4a14b517f translatedAt=2026-07-25T11:27:27.733Z pushedAt=2026-07-25T11:27:39.488Z -->

Calendar Kit provides calendar and event management capabilities, which usually refer to APIs that can be used to access and operate calendar data. These APIs allow you to integrate time-related event services (such as travel, catering, sports, and entertainment) in other applications with the system calendar to implement functions such as event management, creation, and query.

## Available Capabilities

Calendar Kit provides management capability for accounts and events.

- Create a calendar account.

  You can create a calendar account specific to your application, after which an account ID is returned. The account ID is the auto-increment primary key of the data table and is used as the unique identifier of the account.

- Obtain a calendar account.

  You can obtain information about a specified calendar account or all calendar accounts created by the current application.

- Delete a calendar account.

  You can delete a specified calendar account, after which all events associated with the calendar account will be deleted.

- Create a calendar event.

  After obtaining the calendar account information, you can create an event under the obtained calendar account. When creating an event, you can set an event reminder and its notification is displayed when the set time arrives.

  After an event is created, an event ID is returned. The ID is the auto-increment primary key of the data table and is used as the unique identifier of the event.

- Delete an event.

  You can delete one or more events with specified event IDs at a time.

- Update an event.

  You can update event information based on the event ID, including the event title, location, start time, end time, and reminder time.

- Query events.

  You can query events by event ID, event title, event start time, and event end time.

## Features

**One-tap event service**: Through a persistent authorization mechanism, you can write a service DeepLink to a calendar event after the user grants the application permission to read and write the system calendar. Based on the configured reminder rules, a corresponding service button is displayed in the calendar application, calendar notifications, calendar widgets, and other entry points when the event is approaching or due. Users can tap this button to open the DeepLink and go directly to the target service page.

## Working Principles

Calendar Kit provides a set of APIs for obtaining calendar accounts, and writing calendar events to or reading events from the obtained accounts. If an event has a reminder time set, the system sends a reminder to the user when the set time arrives.

## Constraints

- The capabilities and APIs provided by Calendar Kit are currently supported only in the stage model.

- To use Calendar Kit capabilities, your application must obtain the permissions required to read or write calendars and events. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

  - To read calendars or events, request the **ohos.permission.READ_CALENDAR** or **ohos.permission.READ_WHOLE_CALENDAR** permission.

  - To add, delete, or modify calendars or events, request the **ohos.permission.WRITE_CALENDAR** or **ohos.permission.WRITE_WHOLE_CALENDAR** permission.

The operations supported after the corresponding permissions are granted are listed in the following table.

  | Requested Permission | Supported Calendar Account Operation | Supported Event Operation |
  | ------------------------------ | -------------------------------------------- | ------------------------------------------------------------ |
  | ohos.permission.READ_CALENDAR | - Read the system default calendar account.<br>- Read calendar accounts created by the current application. | - Read events created by the current application under the system default calendar account.<br/>- Read events created by the current application under calendar accounts created by the current application. |
  | ohos.permission.WRITE_CALENDAR | - Add, delete, or modify calendar accounts created by the current application. | - Add, delete, or modify events created by the current application under the system default calendar account.<br>- Add, delete, or modify events created by the current application under calendar accounts created by the current application. |
  | ohos.permission.READ_WHOLE_CALENDAR | - Read all calendar accounts. | - Read events created by all applications. |
  | ohos.permission.WRITE_WHOLE_CALENDAR | - Add, delete, or modify all calendar accounts. | - Add, delete, or modify events created by all applications. |

<!--RP1-->
<!--RP1End-->
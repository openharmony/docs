#   Event Error Codes

## 1500001 Want Action Is Null

**Error Message**
Want action is null

**Description**
This error code is reported when the **Action** attribute in the **want** is null for the event to send.

**Possible Causes**
The **Action** attribute in the **want** is null for the event to send.

**Solution**
Make sure the **Action** attribute in the **want** is not null.

##  1500002 Failed to Send Common Events from a Sandbox Application

**Error Message**
sandbox application can not send common event

**Description**
This error code is reported when an attempt is made to send a common event from a sandbox application.

**Possible Causes**
Common events from a sandbox application are blocked.

**Solution**
Check whether the application used to send a common event is a sandbox application. If so, switch to another application.

##  1500003 Event Sending Frequency Is Too High

**Error Message**
common event send frequency too high

**Description**
This error code is reported when the application sends common events too frequently.

**Possible Causes**
The number of common events sent by the application in a given time frame has reached the maximum.

**Solution**
Do not send common events too frequently.

##  1500004 Failed to Send System Common Events

**Error Message**
not System services or System app

**Description**
This error code is reported when the application cannot send system common events.

**Possible Causes**
The application is not a system application or system service.

**Solution**
Make sure the application to send system common events is a system application or system service.

##  1500005 Subscriber Not Found

**Error Message**
subscriber can not found

**Description**
This error code is reported when the subscriber cannot be found.

**Possible Causes**
The subscriber is deleted.

**Solution**
Check whether the subscription has already been canceled. If the subscription has been canceled, the subscriber is deleted.

##  1500006 Invalid User ID

**Error Message**
usreId is invalid

**Description**
This error code is reported when the user ID is invalid.

**Possible Causes**
The user ID is different from the system user ID, or the application is not a system application or subsystem process.

**Solution**
Check whether the current user ID is the same as the system user ID. If they are different, check whether the application is a system application or subsystem process

##  1500007 Failed to Send a Request Through IPC

**Error Message**
message send error

**Description**
This error code is reported when the attempt to send a request through IPC fails.

**Possible Causes**
The connection object fails to be created.

**Solution**
Do not set up connections frequently. Try again later.

##  1500008 Failed to Read Data

**Error Message**
CEMS error

**Description**
This error code is reported when an error occurs on the server.

**Possible Causes**
A service exception occurs when the server processes data.

**Solution**
Try again later.

##  1500009 System Error

**Error Message**
system error

**Description**
This error code is reported when an exception occurs in the system during service processing, for example, when the current system time fails to be obtained.

**Possible Causes**
A system fault occurs.

**Solution**
Try again later.

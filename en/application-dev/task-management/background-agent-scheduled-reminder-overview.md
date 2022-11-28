# Agent-Powered Scheduled Reminder Overview

According to the OpenHarmony background activity specifications, a third-party application will be suspended if it does not execute background tasks after switching to the background. In practice, an application may need to process certain work at specified moments, no matter what state it is in. For example, a shopping application needs to remind users of flash sale activities at some time points. Generally, a timer is used to achieve the preceding scenario. When the timer expires, the system starts the application to execute the task. However, some applications abuse the timer mechanism so they can be frequently waken up when running in the background. To avoid malicious background activities and meet service requirements of applications, OpenHarmony introduces the agent-powered scheduled reminder.
With the agent-powered scheduled reminder, the timing and pop-up notification functions of an application will be taken over by the reminder agent in the background, even when the application is suspended or exits. This prevents an application from being frequently woken up and helps reduce power consumption.

## Notification Instance Types

- **Countdown timers**: Applications can use this type to implement short-time timing notification services.

- **Calendar events**: Applications can use this type to implement long-time notification services.

- **Alarm clocks**: Applications can use this type to implement alarm-related services.

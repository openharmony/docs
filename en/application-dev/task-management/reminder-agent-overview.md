# Agent-Powered Reminder Overview


To deliver a better user experience, OpenHarmony manages background application processes in a more orderly manner. Applications cannot reside in the background randomly, and their background behavior is strictly managed to minimize malicious behavior. However, for some applications that are running in the background or have exited, notifications may need to be sent at a specified time. For example, a shopping application wants to remind users of flash sale activities at some time points. To meet these service requirements, OpenHarmony provides the agent-powered redminder feature. After an application switches to the background or exits, their timing and pop-up notification functions are taken over by the background agent.


OpenHarmony provides the following types of background agents:


- Countdown timers: Applications can use this type to implement short-time timing notification services.

- Calendar events: Applications can use this type to implement long-time notification services.

- Alarm clocks: Applications can use this type to implement alarm-related services.

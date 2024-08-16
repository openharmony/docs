# Introduction to HiAppEvent


HiAppEvent is a module that provides event logging for applications to log the fault, statistical, security, and user behavior events reported during running. Based on event information, you will be able to analyze how your application works. You will also be able to evaluate mission-critical information, for example, number of visits, number of daily active users, user operation habits, and key factors that affect application usage.


## Basic Concepts

**Logging**: a function that logs changes caused by user operations to provide service data for development, product, and O&M analysis.


## Event Design Specifications

- Event domain: identifies the domain of an event. You are advised to set this parameter to the service module name to differentiate service modules.

- Event name: specifies the name of an event. You are advised to set this parameter to a specific service name to differentiate services.

- Event type: specifies the type of an event. Four event types are supported:
  - Behavior event: used to record the daily operation behavior of a user, for example, button click and page redirection.
  - Fault event: used to locate and analyze application faults, for example, frame freezing, network disconnection, and call drop.
  - Statistical event: used to collect statistics on key application behaviors, for example, usage duration and number of visits.
  - Security event: used to record events related to application security, for example, password change and user authorization.

- Event parameter: specifies the parameters of an event. Each event can contain a group of parameters. You are advised to set this parameter to an event attribute or event context to depict the event details.

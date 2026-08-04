# Device Usage Statistics Overview (for System Applications Only)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=6268b04ebb521797f4d48c577491b7161be5f520 translatedAt=2026-07-29T03:30:04.153Z pushedAt=2026-07-29T03:31:34.471Z -->

Device usage statistics include app usage, notification usage, and system usage. Currently, only app usage statistics are supported. Application usage statistics are used to save and query application usage details (app usage), event log data (event log), and bundle group information. The application records (usage history statistics) cached by components are flushed to the database for persistent storage within 30 minutes after an event is reported.

## Introduction

Device usage statistics provide many APIs. Currently, only app usage statistics are supported. The following describes the logic of the app usage APIs.

- **Application usage statistics flushing**:
  1. Triggered once every 30 minutes.
  2. Triggered once when the system time changes.
  3. Triggered once at the beginning of the next day.

- **Application query APIs**:
  1. Query the event set of all applications based on the specified start time and end time.
  2. Query the application usage duration based on the specified start time and end time.
  3. Query the event set of the current application based on the specified start time and end time.
  4. Query the application usage duration based on the interval type (day, week, month, or year), start time, and end time.
  5. Query the priority group of the caller application.
  6. Check whether the specified application is currently in the idle state.
  7. Query FA usage records. FA usage records are sorted from most recent to oldest. If **maxNum** is set in the parameter, the maximum number returned is **maxNum**. If it is not set, the maximum number returned is **1000**.
  8. Query the number of notifications from applications based on the specified start time and end time.
  9. Query statistics about system events (hibernation, wakeup, unlock, and screen lock) based on the specified start time and end time.
  10. Query the priority group of the caller application or the specified application.

- **Setting APIs**

  Set the group of the application specified by **bundleName** to **newGroup**.

- **Registration APIs**

  Register a callback listener for application group changes. When an application group changes, change information is returned to all registered applications.

- **Unregistration APIs**

  Unregister the callback listener for application group changes.

## Required Permissions
- Device usage statistics APIs are system APIs. Before calling them, apply for the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

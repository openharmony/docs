# Device Usage Statistics Overview

Device usage statistics include the usage of applications, notifications, and the system. Currently, you can use device usage statistics APIs to access only statistics on the application usage. In application usage statistics, you can query the application usage, event logs, and bundle groups.

The application records (usage history statistics and event records) cached by components are flushed to the database for persistent storage within 30 minutes after an event is reported.

## Introduction

The application usage statistics are flushed:
- Every 30 minutes.
- Upon system time changes.
- Upon start of a new day.

You can use **query()** (including **isIdleState**) to obtain:
- Events of all applications based on the specified start time and end time.
- Application usage duration based on the specified start time and end time.
- Events of the caller application based on the specified start time and end time.
- Application usage duration in the specified time frame at the specified interval (daily, weekly, monthly, or annually).
- Priority group of the caller application.
- Whether an application is in the idle state.
- Feature Ability (FA) usage records sorted by time (most recent first). 

  **maxNum** specifies the maximum number of FA usage records returned. If **maxNum** is not specified, the default value **1000** will be used.
- Number of notifications from applications based on the specified start time and end time.
- System events (hibernation, wakeup, lock, and unlock) that occur between the specified start time and end time.
- Priority group of the caller application or a given application.

You can use **set()** to set the group for the application specified by **bundleName**.

You can use **register()** to register a callback for application group changes. When an application group of the user changes, the change is notified to all applications that have registered the callback.

You can use **unregister()** to deregister the callback for application group changes.

## Required Permissions
Only system applications can call the device usage statistics APIs. They must request the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to call these APIs.
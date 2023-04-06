# Device Usage Statistics Overview

With device usage statistics APIs, you can have a better understanding of the application, notification, and system usage. In application usage statistics, you can query the application usage, event log, and bundle group. The application records (usage history statistics and event records) cached by components are updated to the database for persistent storage within 30 minutes after an event is reported.

## Introduction

Currently you can have access to statistics on the application usage, and the notification and system usage statistics feature will be available for use in later versions.

- **The application usage statistics is updated**:
  1. Every 30 minutes
  2. Upon system time change
  3. Upon start of a new day

- **The application usage statistics can include the following**:
  1. Events of all applications based on the specified start time and end time
  2. Application usage duration statistics based on the specified start time and end time
  3. Events of the current application based on the specified start time and end time
  4. Application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually)
  5. Priority group of the current invoker application
  6. Whether a specific application is in the idle state
  7. Number of FA usage records specified by **maxNum**, sorted by time (most recent first). If **maxNum** is not specified, the default value **1000** will be used.
  8. Number of notifications from applications based on the specified start time and end time
  9. Statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time
  10. Priority group of the invoker application or a specified application

- **The setters can be used to:**

  Set the group for the application specified by **bundleName**.

- **The registration APIs can be used to:**

  Register a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback.

- **The deregistration APIs can be used to:**

  Deregister the callback for application group changes.

## Required Permissions
- Before calling the following system APIs, you must request the **ohos.permission.BUNDLE_ACTIVE_INFO** permission: **isIdleState**, **queryBundleEvents**, **queryBundleStatsInfos**, **queryBundleStatsInfoByInterval**, **queryDeviceEventStats**, **queryNotificationEventStats**, **queryAppGroup(bundleName)**, **setAppGroup**, **registerAppGroupCallBack**, **unregisterAppGroupCallBack**, **queryModuleUsageRecords**, and **queryModuleUsageRecords(maxnum)**.
- You do not need to request this permission before calling **queryCurrentBundleEvents** and **queryAppGroup()**, which are third-party APIs.

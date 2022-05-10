# Device Usage Statistics Overview

With device usage statistics APIs, you can have a better understanding of the application, notification, and system usage. In application usage statistics, you can query the application usage, event log, and bundle group. The application records (usage history statistics and event records) cached by components are updated to the database for persistent storage within 30 minutes after an event is reported.

## Introduction

Currently you can have access to statistics on the application usage, and notification and system usage statistics feature will be available for use in later versions.

- **The application usage statistics is updated**:
1.  Every 30 minutes
2.  Upon system time change
3.  Upon start of a new day

- **The application usage statistics can include the following**:
1. Events of all applications based on the specified start time and end time

2. Application usage duration statistics based on the specified start time and end time

3. Events of the current application based on the specified start time and end time

4. Application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually)

5. Priority group of the current invoker application

6. Whether a specific application is in the idle state

7. The number of FA usage records specified by **maxNum**, sorted by time (most recent first)

   If **maxNum** is not specified, the default value **1000** will be used.

### Required Permissions
- The **queryBundleActiveStates**, **queryBundleStateInfos**, and **queryBundleStateInfoByInterval** APIs used for device usage statistics are system APIs. Before calling these APIs, you need to apply for the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.
- This permission is not required for calling **queryCurrentBundleActiveStates**, **queryAppUsagePriorityGroup**, and **isIdleState**, which are third-party APIs.

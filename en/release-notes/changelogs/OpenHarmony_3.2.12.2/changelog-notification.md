# Notification Subsystem Changelog

Compared with OpenHarmony 3.2 Release, OpenHarmony 3.2.12.2 provides more detailed error code information for the APIs of the notification subsystem.

## cl.notification.1 Added and Optimized API Error Code Description

The error code description and all error codes that may be returned by the APIs are commented out. This helps developers control the error process more accurately.

**Change Impact**

The external declaration of the JS APIs of API version 9 is affected, but the API functionalities are not affected. You can determine whether to adapt to the JS APIs.

**Key API/Component Changes**

The comments of the following modules are updated. For details, see the corresponding external API declaration and API development guide.

| Module                       | Major Change                                              |
| --------------------------- | ------------------------------------------------------------ |
| @ohos.commonEventManager    | Added the description of error codes 801, 1500007, and 1500008.                   |
| @ohos.notificationManager   | Added the description of error codes 201, 202, 1600001, 1600002, 1600003, 1600004, 1600005, 1600007, 1600008, 1600009, 1600010, and 17700001, and adjusted the description of error code 401.|
| @ohos.notificationSubscribe | Added the description of error codes 201, 202, 1600001, 1600002, 1600003, 1600007, 1600008, and 17700001, and adjusted the description of error code 401.|

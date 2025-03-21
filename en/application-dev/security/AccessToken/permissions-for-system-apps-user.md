# user_grant Permissions for System Applications

Before requesting permissions for your application, read and understand the [permission request paths](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
>
> - The permissions listed in this topic are available to system_basic or system_core applications, but not to normal applications.
> - The authorization mode of these permissions is user_grant.
> - Applications of a lower APL can request these permissions via [Access Control List (ACL)](app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

For details about the process for requesting permissions, see [Workflow for Requesting Permissions](determine-application-mode.md).

## ohos.permission.READ_WHOLE_CALENDAR

Allows an application to read all calendar information.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

## ohos.permission.WRITE_WHOLE_CALENDAR

Allows an application to add, remove, or edit calendar events.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

## ohos.permission.GET_INSTALLED_BUNDLE_LIST

Allows an application to obtain the list of installed applications.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 10

## ohos.permission.ANSWER_CALL

Allows an application to answer incoming calls.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

## ohos.permission.MANAGE_VOICEMAIL

Allows an application to access messages in the voice mailbox.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.READ_CALL_LOG

Allows an application to read call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.READ_CELL_MESSAGES

Allows an application to read cell broadcast messages received by the device.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.READ_MESSAGES

Allows an application to read messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.RECEIVE_MMS

Allows an application to receive and process MMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.RECEIVE_SMS

Allows an application to receive and process SMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.RECEIVE_WAP_MESSAGES

Allows an application to receive and process WAP messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.SEND_MESSAGES

Allows an application to send messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.WRITE_CALL_LOG

Allows an application to add, remove, and edit call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

## ohos.permission.CUSTOM_SCREEN_CAPTURE

Allows an application to capture screen information.

With this permission, the application can perform operations such as taking screenshots and recording on-screen information. Currently, this permission is available only to applications running on tablets and 2-in-1 devices.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 14

# Application Access Control Subsystem Changelog

## cl.accessToken.1 Change of the Media and Files Permission Group
The original Media and File permission group contains the following permissions:
- ohos.permission.MEDIA_LOCATION
- ohos.permission.READ_MEDIA
- ohos.permission.WRITE_MEDIA

Changed the permission group as follows:
- Added **ohos.permission.MEDIA_LOCATION** to the Images and Video permission group.
- Added **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** to the Documents permission group.


**Change Impact**

The dialog box for requesting permissions is displayed by permission group.

- Before the change, if the three permissions are applied for an application, a dialog box for  requesting the media and file permissions will be displayed only once.
- After the change, if the three permissions are applied for an application, a dialog box for  requesting the image and video permissions and a dialog box for  requesting the document permission will be displayed.

**Key API/Component Changes**

Permission groups before the change:

| Permission  | Permission Group                        |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | Media and file|
| ohos.permission.READ_MEDIA | Media and file|
| ohos.permission.WRITE_MEDIA | Media and file|

Permission groups after the change:

| Permission  | Permission Group                        |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | Images and videos |
| ohos.permission.READ_MEDIA | Documents |
| ohos.permission.WRITE_MEDIA | Documents |


**Adaptation Guide**

N/A

## cl.accessToken.2 Change of the Permission Requesting Modes of the Telephony, Messaging, and Call Logs Permission Groups
The permissions of the Telephony, Messaging, and Call Logs permission groups are available only to system applications. The three permission groups contain the following permissions:
- ohos.permission.ANSWER_CALL
- ohos.permission.MANAGE_VOICEMAIL
- ohos.permission.READ_CELL_MESSAGES
- ohos.permission.READ_MESSAGES
- ohos.permission.RECEIVE_MMS
- ohos.permission.RECEIVE_SMS
- ohos.permission.RECEIVE_WAP_MESSAGES
- ohos.permission.SEND_MESSAGES
- ohos.permission.READ_CALL_LOG
- ohos.permission.WRITE_CALL_LOG
- ohos.permission.MEDIA_LOCATION

To enable third-party application developers to apply for these permissions, the method for requesting these permissions is changed to pre-authorization mode.


**Change Impact**

The system applications can obtain these permissions only in pre-authorization mode, rather than requesting these permissions through a pop-up window, .

**Key API/Component Changes**

N/A

**Adaptation Guide**

Apply for the preceding permissions in pre-authorization mode for system applications.

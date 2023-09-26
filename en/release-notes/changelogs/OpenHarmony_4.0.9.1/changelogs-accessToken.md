# Application Access Control Subsystem Changelog

## cl.accessToken.1 Change of the Media and Files Permission Group
The original **Media and File** permission group contains the following permissions:
- ohos.permission.MEDIA_LOCATION
- ohos.permission.READ_MEDIA
- ohos.permission.WRITE_MEDIA

Changed the permission group as follows:
- Moved **ohos.permission.MEDIA_LOCATION** to the **Images and Videos** permission group.
- Moved **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** to the **Documents** permission group.

**Change Impact**

The permission group rather than the permission is presented in the dialog box for requesting permissions.

- Before the change, if the three permissions are applied for an application, a dialog box for requesting the media and file permissions will be displayed only once.
- After the change, if the three permissions are applied for an application, a dialog box for requesting the **Images and Videos** permissions and a dialog box for requesting the **Documents** permission will be displayed.

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

## cl.accessToken.2 Change of the Permission Requesting Modes of the Phone, Messaging, and Call Logs Permission Groups
 The **Phone**, **Messaging**, and **Call logs** permission groups contain the following permissions:
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

These permissions can be pre-authorized only.


**Change Impact**

Instead of requesting these permissions through a pop-up window, the system applications can obtain the permissions only in pre-authorization mode.

**Key API/Component Changes**

N/A

**Adaptation Guide**

These permissions can be pre-authorized only.

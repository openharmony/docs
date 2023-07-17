# App Access Control Subsystem ChangeLog

## cl.accessToken.1 Change of the Media and File Permission Group
The original Media and File permission group contains the following permissions:
- ohos.permission.MEDIA_LOCATION
- ohos.permission.READ_MEDIA
- ohos.permission.WRITE_MEDIA

Changed the permission group as follows:
- Added **ohos.permission.MEDIA_LOCATION** to the Image and Video permission group.
- Added **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** to the File permission group.


**Change Impact**

The permission dialog boxes are displayed by permission group.

- Before the change, if the three permissions are applied for an application, a dialog box for applying for the media and file permissions will be displayed only once.
- After the change, if the three permissions are applied for an application, a dialog box for applying for the image and video permissions and a dialog box for applying for the file permission will be displayed.

**Key API/Component Changes**

Permission group before the change:

| Permission  | Permission Group                        |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | Media and File|
| ohos.permission.READ_MEDIA | Media and File|
| ohos.permission.WRITE_MEDIA | Media and File|

Permission groups after the change:

| Permission  | Permission Group                        |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | Image and Video|
| ohos.permission.READ_MEDIA | File|
| ohos.permission.WRITE_MEDIA | File|


**Adaptation Guide**

N/A


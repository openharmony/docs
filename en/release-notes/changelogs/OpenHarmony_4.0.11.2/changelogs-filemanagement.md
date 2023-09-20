# File Management Subsystem Changelog

## c1.filemanager.1 Change of the fileAccess Module

1. Changed the assets that can be managed by the file access framework. The assets managed by the media library cannot be accessed by using the file access framework APIs. Currently, the file access framework supports the following directories:
   - External storage directory
   - **Docs** directory
   - **Download** directory
   - **Desktop** directory
   - **Documents** directory
   - **Share** directory of the shared disk

   The **fileAccess** module does not support query of some attributes of thumbnails and media assets.

2. Changed the URI format, which eliminates the need for parsing the URI format.

**Change Impact**

For applications developed based on earlier versions, check whether the URI is obtained by using the media library API through **fileAccess**. If yes, the URI cannot be obtained.

**Key API/Component Changes**

The following API is deleted.

| Class          | API                                                |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

The following values are deleted from **FileKey**.

| Enum| Deleted Key Value|
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |

**Adaptation Guide**

The invocation of the **fileAccess** APIs remains unchanged, but the assets corresponding to the URI returned change.

To obtain attributes such as the file name and path, use [fileuri](../../../application-dev/reference/apis/js-apis-file-fileuri.md).

To obtain the URI via a file access framework interface, use [fs](../../../application-dev/reference/apis/js-apis-file-fs.md).

# File Management Subsystem Changelog
## c1.filemanager.1 Change of the fileAccess Module
The **fileAccess** module will no longer support operations for obtaining thumbnails and media assets.

**Change Impact**
1. Deleted **getThumbnail()**.
2. Deleted the **FILEKEY** of image and audio options.

**Key API/Component Changes**

Deleted APIs:

| Class          | API                                                |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size): Promise<image.PixelMap>;|
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

 Deleted options:
| Enum| Deleted Key Value|
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |

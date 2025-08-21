# User File Overview
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

User files are the private [images, videos](../media/medialibrary/photoAccessHelper-overview.md), audio clips, and documents of the user who has logged in to the device.

1. User files are stored in a directory, whose owner is the user who has logged in to the device.

2. User files can be stored in [built-in storage](#built-in-storage) and [external storage](#external-storage) of the device.

3. An application cannot access user files without user authorization, or the operations on user files must be performed by the user.

## User File Storage

### Built-in Storage

Built-in storage is the internal storage device (space) of a device. The built-in storage device cannot be removed. The following files can be stored in the built-in storage of a device:

- Files of a user: The files belong to the user who has logged in to the device. Different login users on a device can view their own files only.
    These user files can be classified into the following types based on file attributes and access habits of users/applications:
  - Image/Video files<br>
    The files have attributes, such as the shooting time, location, rotation angle, and file width and height information, and are stored in media file formats. Generally, these files are presented as media files or albums, without the specific storage location in the system.
  
  - Audio files<br>
    The files have attributes, such as the album, artist, and duration information, and are stored in media file formats. Generally, audio files are presented by file, album, or artist, without the specific storage location in the system.
  
  - Other files (documents)<br>
    The files are stored as common files, including common text files, compressed files, and images, videos and audio clips stored as common files. Generally, these files are presented in a directory tree.

- Files shared by users: The files are stored in a share directory to enable access from multiple users.
  The files in the share directory are stored as common files and presented in a directory tree.

### External Storage

External storage is not inside a device's main storage or memory. Common external storage devices include pluggable devices, such as SD cards and USB flash drives. Same as the files in the share directory of the built-in storage device, the files in an external storage device can be viewed by all the users who has logged in to the system.

External storage devices are pluggable. The system provides listening for the device insertion/removal events and mount/unmount of an external storage device. <!--RP1-->For details, see [Managing External Storage Devices (for System Applications Only)](manage-external-storage.md)<!--RP1End-->.

The files on external storage devices are presented as common files in a directory tree, like the documents in built-in storage.

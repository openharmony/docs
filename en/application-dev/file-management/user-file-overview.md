# User File Overview

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=a4bb221ea8dcccf781d5793faa6c8f62723e3e12 translatedAt=2026-08-01T07:28:33.839Z pushedAt=2026-08-01T11:25:15.146Z -->

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

Its characteristics include information such as the album, artist, and duration. Audio files are stored in the system as media files and are typically presented by categories such as all files, albums, and artists, without exposing their specific storage locations in the system.

  - Other files (documents)<br>

    The files are stored as common files, including common text files, compressed files, and images, videos and audio clips stored as common files. Generally, these files are presented in a directory tree.

### External Storage

External storage refers to user files stored on external pluggable devices (such as SD cards and USB drives). Files on an external storage device are visible to all users logged in to the system.

External storage devices are pluggable. The system provides listening for the device insertion/removal events and mount/unmount of an external storage device. <!--RP1-->For details, see [Managing External Storage Devices (for System Applications Only)](manage-external-storage-sys.md)<!--RP1End-->.

The files on external storage devices are presented as common files in a directory tree, like the documents in built-in storage.
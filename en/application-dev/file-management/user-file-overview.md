# User File Overview

User files are the private images, video and audio clips, and documents of the user who has logged in to the device.

- User files are stored in a directory, whose owner is the user who has logged in to the device.

- User files can be stored in [built-in storage](#built-in-storage) and [external storage](#external-storage) of the device.

- An application cannot access user files without user authorization, or the operations on user files must be performed by the user.

OpenHarmony provides the [user file access framework](#user-file-access-framework) for developers to access and manage user files.

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

External storage devices are pluggable. OpenHarmony provides listening for the device insertion/removal events and mount/unmount of an external storage device. For details, see [Managing External Storage Devices](manage-external-storage.md).

The files on external storage devices are presented as common files in a directory tree, like the documents in built-in storage.

## User File Access Framework

OpenHarmony provides the user file access framework for developers to access and manage user files. This framework leverages the ExtensionAbility of OpenHarmony to provide a set of methods and interfaces for accessing user files.

**Figure 1** User file access framework

![User file access framework](figures/user-file-access-framework.png)

- The file access client (a system application or third-party application) can access user files, for example, select a photo or save multiple documents, by starting the **FilePicker** application.

- OpenHarmony is prebuilt with the **FilePicker** and **FileManager** applications.
  - **FilePicker**: allows a file access client to select and save user files without any permission. For details, see [Selecting User Files](select-user-file.md).
  - **FileManager**: allows users to view and modify files, and delete, rename, move, and create files or directories.

  You can also develop your own file picker or file manager applications as required. File picker is a subset of file manager. For details about how to develop a file manager application, see [Developing a File Manager Application](dev-user-file-manager.md).

- The user file access framework consists of the following functional modules:
  - **File Access Helper**: provides APIs for the **FileManager** and **FilePicker** to access user files.
  - **File Access ExtensionAbility**: implements file access via the following services:
    - **UserFileManager**: implements management of the files on the built-in storage based on the File Access ExtensionAbility framework.
    - **ExternalFileManager**: implements management of the files on the external storage based on the File Access ExtensionAbility framework.

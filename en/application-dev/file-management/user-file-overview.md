# User File Overview

User files are the private images, video and audio clips, and documents of the user who logs in to the device. 

1. User files are stored in a directory, whose owner is the user who logs in to the device.

2. User files can be stored in [built-in storage](#built-in-storage) and [external storage](#external-storage).

3. An application cannot access user files without user authorization, or the operations on user files must be performed by the user.

OpenHarmony provides the [user file access framework](#user-file-access-framework) for developers to access and manage user files, which will be described in detail below.

## User File Storage

### Built-in Storage

Built-in storage refers to the internal storage device (space) of a device. The built-in storage device cannot be removed. The following files can be stored in the built-in storage of a device:

- Files owned by a user: The files belong to the user who logs in to the device. Different users who log in to a device can view only their own files.
    These user files can be classified into the following types based on file attributes and access habits of users/applications:
  - Image/Video files
    The files have attributes, such as the shooting time, location, rotation angle, and file width and height information, and are stored in media file formats. The files are usually presented as media files or albums, without the specific location in the system.
  
  - Audio files
    The files have attributes, such as the album, creator, and shooting duration information, and are stored in media file formats. Generally, the files are presented by file, album, or creator, without the specific location in the system.
  
  - Documents
    The files are stored as common files, including common text files, compressed files, and images, videos and audio clips stored as common files. These files are presented in a directory tree.

- Files shared by users: The files are stored in a directory for share and shared by multiple users.
  The files in the shared directory are stored as common files and presented in a directory tree.

### External Storage

External storage is not inside a device's main storage or memory. Common external storage devices include pluggable devices, such as SD cards and USB flash drives. Same as the files in the shared directory of the built-in storage device, the files in an external storage device can be viewed by all the users who log in to the system.

External storage devices are pluggable. OpenHarmony provides the functions of listening for the device insertion and removal events and mounting/unmounting an external storage device. For details, see [Managing External Storage Devices)](manage-external-storage.md).

The files on external storage devices are presented as common files in a directory tree, like the documents stored in built-in storage.

## User File Access Framework

OpenHarmony provides the user file access framework for developers to access and manage user files. This framework leverages the ExtensionAbility of OpenHarmony to provide a set of methods and interfaces for accessing user files.

**Figure 1** User file access framework 
![User file access framework](figures/user-file-access-framework.png)

- To access user files, for example, select a photo or save multiple documents, a system application or third-party application (file access client in **Figure 1**) starts the **FilePicker** application.

- OpenHarmony is prebuilt with the **FilePicker** and **FileManager** applications.
  - **FilePicker**: provides APIs for a file access client to select and save user files without any permission. For details, see [Selecting User Files](select-user-file.md).
  - **FileManager**: allows users to view and modify files, and delete, rename, move, and create files or directories by using a system FileManager.

  You can also develop your own FilePicker or FileManager applications as required. FilePicker is a subset of FileManager. For details about how to develop a FileManager application, see [Developing a FileManager Application)](dev-user-file-manager.md).

- The user file access framework provides the following functional modules:
  - **File Access Helper**: provides APIs for the **FileManager** and **FilePicker** to access user files.
  - **File Access ExtensionAbility**: provides a file access framework to implement file access functions. The **File Access ExtensionAbility** consists of the following:
    - **UserFileManager**: implements management of the files stored on the built-in storage.
    - **ExternalFileManager**: implements management of the files stored on the external storage.

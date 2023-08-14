# Application Sandbox Directory

The application sandbox is an isolation mechanism used to prevent malicious data access through path traversal. With this mechanism, only the application sandbox directory is visible to an application.

- The system has a dedicated application sandbox directory in the internal storage to map the directory of each application. The application sandbox directory holds [application files](app-file-overview.md) and the minimum system files required for running of the application.

- The application sandbox specifies the minimum data range visible to each application. In the application sandbox directory, an application can access only its own application files and the system files required for its running. The application cannot access files of other applications. This ensures application file security.

- In each application sandbox directory, the application can save and process its application files in the [application file directory](app-file-overview.md), and can only read the system files and directories. To access [user files](user-file-overview.md), the application need to call specific APIs and have authorization from the user.

The following figure illustrates the file access mechanism in an application sandbox.

**Figure 1** File access mechanism in an application sandbox

![Application sandbox file access relationship](figures/application-sandbox-file-access-relationship.png)

## Application Sandbox Directory and Application Sandbox Path

With the application sandbox mechanism, an application is not aware of the existence and location of other applications' directories and user file directories. Even the application directories visible to an application are isolated by permission and namespace to form an independent directory view and shield the real (physical) paths.

- As shown in the following figure, the sandbox mechanism minimizes the number of directories and files visible to a common application (third-party application). In addition, the directories and file paths visible to a common application are different from those visible to a system process. The path of a file or folder in the application sandbox directory visible to a common application is called the application sandbox path.

- You can view the real application paths (the directory view visible to a system process) in the HDC shell environment. For details about the mappings between the application sandbox paths and real application paths, see [Mappings Between Application Sandbox Paths and Physical Paths](send-file-to-app-sandbox.md#mappings-between-application-sandbox-paths-and-physical-paths).

- The application sandbox paths and physical paths are not in one-to-one mappings. The application sandbox paths are always less than the physical paths. You may not obtain the application sandbox path based on a physical path in certain cases, but you can obtain the physical path based on an application sandbox path.

**Figure 2** Different directory views to processes and applications

![Application sandbox path](figures/application-sandbox-path.png)

## Application File Directory and Application File Path

The application sandbox directory includes application file directories and system file directories.

The system file directories visible to an application are preset by OpenHarmony.

The following figure shows the application file directories. The path of a file or a folder in the application file directory is called the application file path. The sub-directories in the application file directory have different attributes.

**Figure 3** Application file directory structure

![Application file directory structure](figures/application-file-directory-structure.png)

1. Level 1 directory **data/** indicates the application file directory.

2. Level 2 directory **storage/** indicates a directory for persistent files of the application.

3. Level 3 directories **el1/** and **el2/** indicate directories for files of different encryption levels (els).
   - **el1**: directory for the data that can be accessed once the device starts. This directory contains device-focused files.
   - **el2**: directory for the data that can be accessed only after at lease one successful unlock operation (by PIN, fingerprint, or facial authentication, or password-free sign-in) upon the start of the device. This directory contains user-focused files.
   
   Unless otherwise required, application data is placed in the **el2** directory for security purposes. However, the data that needs to be accessed before the screen is unlocked (such as the clock, alarm, and wallpaper data) can be placed in the **el1** directory. For details about the operations on **el** directories, see [Obtaining and Modifying el Directories](../application-models/application-context-stage.md#obtaining-and-modifying-encryption-levels).
   
4. Level 4 and level 5 directories:
   The application's global data is stored in the **files**, **cache**, **preferences**, **temp**, and **distributedfiles** folders in **base**. You can use **ApplicationContext** to obtain the application file paths of these folders.

   You can use **UIAbilityContext**, **AbilityStageContext**, and **ExtensionContext** to obtain application file paths related to the OpenHarmony Ability Package (HAP). When the HAP is uninstalled, the files stored in these directories are automatically deleted, without affecting the files in app-level directories. An application in the development state has one or more HAPs. For details, see [Application Package Structure in Stage Mode](../quick-start/application-package-structure-stage.md).

   For details about how to obtain the context and application file paths, see [Context (Stage Model)](../application-models/application-context-stage.md).

   > **NOTE**
   >
   > - Do not use file paths made up by level 1 to level 4 directory names. Incompatibility problems may occur if the directory names are changed in later versions.
   > - Use **Context** to obtain the application file paths, including but are not limited to the directories highlighted in green in **Figure 3**.

   The following table describes the application file paths and lifecycle.

   **Table 1** Application file paths

   | Folder| Context Attribute Name| Type| Description|
   | -------- | -------- | -------- | -------- |
   | bundle | bundleCodeDir | Installation file directory| Directory for saving the HAPs after an application is installed.<br>This directory is cleared when the application is uninstalled.<br> Do not access resource files using concatenated paths. Use [@ohos.resourceManager](../reference/apis/js-apis-resource-manager.md) instead.|
   | base | NA | Directory for local device files| Directory for saving the application's persistent data on the device. Subdirectories include **files/**, **cache/**, **temp/**, and **haps/**.<br>This directory is cleared when the application is uninstalled.|
   | database | databaseDir | Database directory| Directory in **el1** for saving the files operated by the distributed database service.<br>This directory is cleared when the application is uninstalled.|
   | distributedfiles | distributedFilesDir | Distributed file directory| Directory in **el2** for saving the application files that can be directly accessed across devices.<br>This directory is cleared when the application is uninstalled.|
   | files | filesDir | Application file directory| Directory for saving the application's persistent files on the device.<br>This directory is cleared when the application is uninstalled.|
   | cache | cacheDir | Application cache file directory| Directory for caching the downloaded files of the application or saving the cache files regenerated on the device.<br>This directory is automatically cleared when the size of the **cache** directory reaches the quota or the system storage space reaches a certain threshold. The user can also clear this directory by using a system space management application. <br>The application needs to check whether the file still exists and determine whether to cache the file again.|
   | preferences | preferencesDir | Preferences file directory| Directory for saving common application configuration and user preference data managed by using database APIs.<br>This directory is cleared when the application is uninstalled. For details, see [Persisting Preferences Data](../database/data-persistence-by-preferences.md).|
   | temp | tempDir | Temporary file directory| Directory for saving the files generated and required during the application's runtime on the device. <br>This directory is cleared when the application exits.|

   The application scenarios of the application file directories are as follows:

   - Installation file directory<br>
      Used to store the code resource data of the application, including the HAPs of the application, reusable library files, and plug-ins. The code stored in this directory can be dynamically loaded.
   - Database directory<br>
      Used to store only the application's private database data, such as database files. This directory can be used to store distributed database data only.
   - Distributed file directory<br>
      Used to store the application's data used for distributed scenarios, including file sharing, file backup, and file processing across devices. The data stored in this directory enables the application to run smoothly on multiple devices.
   - Application file directory<br>
      Used to store private data of the application, including persistent files, images, media files, and log files. The data is stored in this directory to ensure privacy, security, and permanent validity.
   - Cache application file directory<br>
      Used to store cached data of the application, including offline data, cached images, database backup, and temporary files. Data stored in this directory may be automatically deleted by the system. Therefore, do not store important data in this directory.
   - Preferences file directory<br>
      Used to store application preferences data, including preference files and configuration files. This directory applied to storing only a small amount of data.
   - Temporary file directory<br>
      Used to store temporarily generated data of an application, including cached database data and images, temporary log files, downloaded application installation package. The data stored in this directory is deleted after being used.
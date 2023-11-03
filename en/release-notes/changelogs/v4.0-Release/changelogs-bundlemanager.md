# Bundle Manager Changelogs
## cl.bundlemanager.1 APP_ACCOUNT_AUTHORIZATION Deleted from ExtensionAbilityType

**APP_ACCOUNT_AUTHORIZATION** is deleted from this version.

You need to adapt your application.

**Change Impact**

The enumerated value can no longer be used after being deleted.

- Involved API:

  ```js
    export enum ExtensionAbilityType
  ```

- Before change:

  ```js
    export enum ExtensionAbilityType {
      FORM = 0,
      WORK_SCHEDULER = 1,
      INPUT_METHOD = 2,
      SERVICE = 3,
      ACCESSIBILITY = 4,
      DATA_SHARE = 5,
      FILE_SHARE = 6,
      STATIC_SUBSCRIBER = 7,
      WALLPAPER = 8,
      BACKUP = 9,
      WINDOW = 10,
      ENTERPRISE_ADMIN = 11,
      THUMBNAIL = 13,
      PREVIEW = 14,
      PRINT = 15,
      PUSH = 17,
      DRIVER = 18,
      APP_ACCOUNT_AUTHORIZATION = 19,
      UNSPECIFIED = 255
    }
  ```

- After change:

  ```js
    export enum ExtensionAbilityType {
      FORM = 0,
      WORK_SCHEDULER = 1,
      INPUT_METHOD = 2,
      SERVICE = 3,
      ACCESSIBILITY = 4,
      DATA_SHARE = 5,
      FILE_SHARE = 6,
      STATIC_SUBSCRIBER = 7,
      WALLPAPER = 8,
      BACKUP = 9,
      WINDOW = 10,
      ENTERPRISE_ADMIN = 11,
      THUMBNAIL = 13,
      PREVIEW = 14,
      PRINT = 15,
      PUSH = 17,
      DRIVER = 18,
      UNSPECIFIED = 255
    }
  ```

The definition of **APP_ACCOUNT_AUTHORIZATION** is deleted.


**Adaptation Guide**

Update the code so that the deleted enumerated value is not used in your code.

## cl.bundlemanager.2 Struct BusinessAbilityInfo Moved from bundleManager to application

The **BusinessAbilityInfo** struct is moved from the **bundleManager** folder to the **application** folder.


**Change Impact**

The file path of a level-2 module is changed. It has no impact on existing code.

**Key API/Component Changes**

The file path of the **BusinessAbilityInfo** struct is changed from **bundleManager/BusinessAbilityInfo** to **application/BusinessAbilityInfo**.

**Adaptation Guide**

N/A

## cl.bundlemanager.3 Bottom-Layer Capability Changed

When the SDK of API version 9 or an earlier version is used to compile the HAP, the resource files of the HAP are decompressed after the HAP is installed.

When the SDK of API version 10 or a later version is used to compile the HAP, the resource files of the HAP are not decompressed after the HAP is installed.

**Change Impact**

If the SDK of API version 9 or earlier is used, no adaptation is required.

If the SDK of API version 10 or a later version is used and your application accesses resource files by combining paths, adaptation is required. If your application does not access resource files by combining paths, no adaptation is required.

**Key API/Component Changes**

N/A

**Adaptation Guide**

The resource management subsystem provides JavaScript APIs for accessing resource files. For details, see [Accessing Resource Files](../../../application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9).


## cl.bundlemanager.4 Changed distroFilter to distributionFilter in the module.json File
The [distroFilter](../../../application-dev/quick-start/module-configuration-file.md) tag in the **module.json** file is changed to **distributionFilter**.

**Change Impact**

If the **distroFilter** tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**

Replace **distroFilter** with **distributionFilter** in the configuration file.
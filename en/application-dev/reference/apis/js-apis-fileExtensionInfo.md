# User File Extension Info

The **fileExtensionInfo** module defines attributes in **RootInfo** and **FileInfo** of the user file access and management module.

>**NOTE**
>
>- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs provided by this module are system APIs.

## Modules to Import

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

## fileExtensionInfo.DeviceType

Defines the values of **deviceType** used in **RootInfo**.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Value| Description|
| ----- | ------ | ------ |
| DEVICE_LOCAL_DISK | 1 | Local disk.|
| DEVICE_SHARED_DISK | 2 | Shared disk.|
| DEVICE_SHARED_TERMINAL | 3 | Distributed network device.|
| DEVICE_NETWORK_NEIGHBORHOODS | 4 | Network neighbor device.|
| DEVICE_EXTERNAL_MTP | 5 | MTP device.|
| DEVICE_EXTERNAL_USB | 6 | USB device.|
| DEVICE_EXTERNAL_CLOUD | 7 | Cloud disk.|

## fileExtensionInfo.DeviceFlag

Defines the values of **deviceFlags** used in **RootInfo**. **deviceFlags** is used to determine whether a capability is available through the AND operation.

**System capability**: SystemCapability.FileManagement.UserFileService

### Attributes

  | Name| Type  | Value| Readable| Writable| Description    |
  | ------ | ------ | ---- | ---- | ---- | -------- |
  | SUPPORTS_READ   | number | 0b1 | Yes  | No  | Read support.|
  | SUPPORTS_WRITE   | number | 0b10 | Yes  | No  | Write support.|

## fileExtensionInfo.DocumentFlag

Defines the values of **mode** used in **FileInfo**.

**System capability**: SystemCapability.FileManagement.UserFileService

### Attributes

  | Name| Type  | Value| Readable| Writable| Description    |
  | ------ | ------ | ---- | ---- | ---- | -------- |
  | REPRESENTS_FILE   | number | 0b1 | Yes  | No  | File.|
  | REPRESENTS_DIR   | number | 0b10 | Yes  | No  | Directory.|
  | SUPPORTS_READ   | number | 0b100 | Yes  | No  | Read support.|
  | SUPPORTS_WRITE   | number | 0b1000 | Yes  | No  | Write support.|

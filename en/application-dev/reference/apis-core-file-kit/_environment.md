# Environment


## Overview

Provides the capability of obtaining the root directory of user files.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_environment.h](oh__environment_8h.md) | Defines the native APIs used to obtain the sandbox paths of the user files. |


### Functions

| Name| Description|
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDownloadDir](#oh_environment_getuserdownloaddir) (char \*\*result) | Obtains the sandbox path of the **Download** root directory. This function is available only for 2-in-1 devices.|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDesktopDir](#oh_environment_getuserdesktopdir) (char \*\*result) | Obtains the sandbox path of the **Desktop** root directory. This function is available only for 2-in-1 devices.|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDocumentDir](#oh_environment_getuserdocumentdir) (char \*\*result) | Obtains the sandbox path of the **Documents** root directory. This function is available only for 2-in-1 devices.|


## Function Description


### OH_Environment_GetUserDesktopDir()

```
FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char ** result)
```
**Description**
Obtains the sandbox path of the **Desktop** root directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Pointer to the sandbox path of the **Desktop** root directory obtained. You also need to include **malloc.h** and use **free()** to release the memory allocated. |

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).


### OH_Environment_GetUserDocumentDir()

```
FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char ** result)
```
**Description**
Obtains the sandbox path of the **Documents** root directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Pointer to the sandbox path of the **Documents** root directory obtained. You also need to include **malloc.h** and use **free()** to release the memory allocated. |

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).


### OH_Environment_GetUserDownloadDir()

```
FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char ** result)
```
**Description**
Obtains the sandbox path of the **Download** root directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Pointer to the path of the **Download** root directory obtained. You also need to include **malloc.h** and use **free()** to release the memory allocated. |

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).

# oh_environment.h


## Overview

Defines the native APIs used to obtain the sandbox paths of the user files.

**Library**: **libohenvironment.so**

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Since**: 12

**Related module**: [Environment](_environment.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDownloadDir](_environment.md#oh_environment_getuserdownloaddir) (char \*\*result) | Obtains the sandbox path of the **Download** root directory. This function is available only for 2-in-1 devices. |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDesktopDir](_environment.md#oh_environment_getuserdesktopdir) (char \*\*result) | Obtains the sandbox path of the **Desktop** root directory. This function is available only for 2-in-1 devices. |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDocumentDir](_environment.md#oh_environment_getuserdocumentdir) (char \*\*result) | Obtains the sandbox path of the **Documents** root directory. This function is available only for 2-in-1 devices.|

# FileIO


## Overview

Provides capabilities of basic file operations.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [error_code.h](error__code_8h.md) | Defines the error codes for the **FileIO** module.| 
| [oh_fileio.h](oh__fileio_8h.md) | Defines the native APIs for basic file operations.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [FileManagement_ErrCode](#filemanagement_errcode-1) [FileManagement_ErrCode](#filemanagement_errcode) | Defines an enum for the error codes used in the **FileIO** module.| 
| typedef enum [FileIO_FileLocation](#fileio_filelocation-1) [FileIO_FileLocation](#fileio_filelocation) | Defines an enum for file locations.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](#filemanagement_errcode-1) {<br>ERR_OK = 0,<br>ERR_PERMISSION_ERROR = 201,<br>ERR_INVALID_PARAMETER = 401,<br>ERR_DEVICE_NOT_SUPPORTED = 801,<br>ERR_EPERM = 13900001,<br>ERR_ENOENT = 13900002,<br>ERR_ENOMEM = 13900011,<br>ERR_UNKNOWN = 13900042<br>} | Enumerates the error codes used in the **FileIO** module.| 
| [FileIO_FileLocation](#fileio_filelocation-1) {<br>LOCAL = 1,<br>CLOUD = 2,<br>LOCAL_AND_CLOUD = 3<br>} | Enumerates the file locations.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](#filemanagement_errcode) [OH_FileIO_GetFileLocation](#oh_fileio_getfilelocation) (char \*uri, int uriLength, [FileIO_FileLocation](#fileio_filelocation) \*location) | Obtains the location of a file.| 


## Type Description


### FileIO_FileLocation

```
typedef enum FileIO_FileLocation FileIO_FileLocation
```

**Description**

Defines an enum for file locations.

**Since**: 12


### FileManagement_ErrCode

```
typedef enum FileManagement_ErrCode FileManagement_ErrCode
```

**Description**

Defines an enum for the error codes used in the **FileIO** module.

**Since**: 12


## Enum Description


### FileIO_FileLocation

```
enum FileIO_FileLocation
```

**Description**

Enumerates the file locations.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| LOCAL | The file is stored in a local device.| 
| CLOUD | The file is stored in the cloud.| 
| LOCAL_AND_CLOUD | The file is stored in a local device and in the cloud.| 


### FileManagement_ErrCode

```
enum FileManagement_ErrCode
```

**Description**

Enumerates the error codes used in the **FileIO** module.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ERR_OK | The API is called successfully.| 
| ERR_PERMISSION_ERROR | The permission verification of the caller fails.| 
| ERR_INVALID_PARAMETER | Invalid parameter.| 
| ERR_DEVICE_NOT_SUPPORTED | The device does not support this interface.| 
| ERR_EPERM | The operation is not allowed.| 
| ERR_ENOENT | The file or folder does not exist.| 
| ERR_ENOMEM | A memory overflow occurs.| 
| ERR_UNKNOWN | Internal unknown error.| 


## Function Description


### OH_FileIO_GetFileLocation()

```
FileManagement_ErrCode OH_FileIO_GetFileLocation (char * uri, int uriLength, FileIO_FileLocation * location )
```

**Description**

Obtains the location of a file.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | Pointer to the URI of the file.| 
| uriLength | Length of the URI.| 
| location | Pointer to the location of the file obtained.| 

**Returns**

Returns [FileManagement_ErrCode](#filemanagement_errcode).

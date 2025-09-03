# oh_fileio.h

## Overview

Defines the native APIs for basic file operations.

**File to include**: <filemanagement/fileio/oh_fileio.h>

**Library**: libohfileio.so

**System capability**: SystemCapability.FileManagement.File.FileIO

**Since**: 12

**Related module**: [FileIO](capi-fileio.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [FileIO_FileLocation](#fileio_filelocation) | FileIO_FileLocation | Enumerates the file locations.|

### Functions

| Name| Description|
| -- | -- |
| [FileManagement_ErrCode OH_FileIO_GetFileLocation(char *uri, int uriLength,FileIO_FileLocation *location)](#oh_fileio_getfilelocation) | Obtains the location of a file.|

## Enum Description

### FileIO_FileLocation

```
enum FileIO_FileLocation
```

**Description**

Enumerates the file locations.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| LOCAL = 1 | The file is stored on the local device.|
| CLOUD = 2 | The file is stored on the cloud.|
| LOCAL_AND_CLOUD = 3 | The file is stored on the local device and cloud.|


## Function Description

### OH_FileIO_GetFileLocation()

```
FileManagement_ErrCode OH_FileIO_GetFileLocation(char *uri, int uriLength,FileIO_FileLocation *location)
```

**Description**

Obtains the location of a file.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char *uri | Pointer to the URI of the file.|
| int uriLength | Length of the URI.|
| [FileIO_FileLocation](capi-oh-fileio-h.md#fileio_filelocation) *location | Pointer to the location of the file obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).|

# Fileuri


## Overview

Provides APIs for operating a file Uniform Resource Identifier (URI), including performing URI-path conversion, obtaining a URI, and verifying a URI.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [oh_file_uri.h](oh__file__uri_8h.md) | Provides APIs for URI operations, including performing URI-path conversion, obtaining a URI, and verifying a URI.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetUriFromPath](#oh_fileuri_geturifrompath) (const char \*path, unsigned int length, char \*\*result) | Obtains the URI from a path.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetPathFromUri](#oh_fileuri_getpathfromuri) (const char \*uri, unsigned int length, char \*\*result) | Obtains the path from a URI.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFullDirectoryUri](#oh_fileuri_getfulldirectoryuri) (const char \*uri, unsigned int length, char \*\*result) | Obtains the URI of the directory, in which a URI is located. If the specified URI points to a file, the URI of the parent directory is returned. If the specified URI points to a folder, the URI of the folder is returned.| 
| bool [OH_FileUri_IsValidUri](#oh_fileuri_isvaliduri) (const char \*uri, unsigned int length) | Checks whether a URI is valid.| 


## Function Description


### OH_FileUri_GetFullDirectoryUri()

```
FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri (const char * uri, unsigned int length, char ** result )
```

**Description**

Obtains the URI of the directory, in which a URI is located. If the specified URI points to a file, the URI of the parent directory is returned. If the specified URI points to a folder, the URI of the folder is returned.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | Pointer to the target URI.| 
| length | Length of the URI, in bytes.| 
| result | Double pointer to the URI obtained. You also need to use **free()** of the standard library to release the memory allocated.| 

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).


### OH_FileUri_GetPathFromUri()

```
FileManagement_ErrCode OH_FileUri_GetPathFromUri (const char * uri, unsigned int length, char ** result )
```

**Description**

Obtains the path from a URI.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | Pointer to the URI to convert.| 
| length | Length of the URI to convert.| 
| result | Double pointer to the path obtained. You also need to use **free()** of the standard library to release the memory allocated.| 

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).


### OH_FileUri_GetUriFromPath()

```
FileManagement_ErrCode OH_FileUri_GetUriFromPath (const char * path, unsigned int length, char ** result )
```

**Description**

Obtains the URI from a path.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| path | Pointer to the path to convert.| 
| length | Length of the path to convert.| 
| result | Double pointer to the URI obtained. You also need to use **free()** of the standard library to release the memory allocated.| 

**Returns**

Returns [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode).


### OH_FileUri_IsValidUri()

```
bool OH_FileUri_IsValidUri (const char * uri, unsigned int length )
```

**Description**

Checks whether a URI is valid.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | Pointer to the URI to check.| 
| length | Length of the URI to check.| 

**Returns**

Returns **true** if the URI is valid; returns **false** otherwise.

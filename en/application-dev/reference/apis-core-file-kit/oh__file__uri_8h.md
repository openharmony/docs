# oh_file_uri.h


## Overview

Provides APIs for URI operations, including performing URI-path conversion, obtaining a URI, and verifying a URI.

**Library**: **libohfileuri.so**

**Since**: 12

**Related module**: [Fileuri](fileuri.md)


## Summary


### Functions

| Name                                                                                                                                                                                                | Description                                             | 
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetUriFromPath](fileuri.md#oh_fileuri_geturifrompath) (const char \*path, unsigned int length, char \*\*result)          | Obtains the URI from a path.                              | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetPathFromUri](fileuri.md#oh_fileuri_getpathfromuri) (const char \*uri, unsigned int length, char \*\*result)  | Obtains the path from a URI.                              | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFullDirectoryUri](fileuri.md#oh_fileuri_getfulldirectoryuri) (const char \*uri, unsigned int length, char \*\*result) | Obtains the URI of the directory, in which a URI is located. If the specified URI points to a file, the URI of the parent directory is returned. If the specified URI points to a folder, the URI of the folder is returned.| 
| bool [OH_FileUri_IsValidUri](fileuri.md#oh_fileuri_isvaliduri) (const char \*uri, unsigned int length)                                                                                             | Checks whether a URI is valid.                                  | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFileName](fileuri.md#oh_fileuri_getfilename) (const char \*uri, unsigned int length, char \*\*result)                 | Obtains the file name from the given URI.                                  | 

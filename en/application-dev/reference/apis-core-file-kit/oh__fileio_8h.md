# oh_fileio.h


## Overview

Defines the native APIs for basic file operations.

**Library**: **libohfileio.so**

**System capability**: SystemCapability.FileManagement.File.FileIO

**Since**: 12

**Related module**: [FileIO](_file_i_o.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) | Defines an enum for file locations.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) {<br>LOCAL = 1,<br>CLOUD = 2,<br>LOCAL_AND_CLOUD = 3<br>} | Enumerates the file locations.| 


### Functions

| API| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileIO_GetFileLocation](_file_i_o.md#oh_fileio_getfilelocation) (char \*uri, int uriLength, [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) \*location) | Obtains the location of a file.| 

# Rawfile


## Overview

Provides the function of operating rawfile directories and rawfiles.

These functions include traversing, opening, searching, reading, and closing rawfiles.

**Since:**
8


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [raw_dir.h](raw__dir_8h.md) | Provides functions for operating rawfile directories. <br>File to Include: <rawfile/raw_dir.h> | 
| [raw_file.h](raw__file_8h.md) | Provides functions for operating rawfiles.  <br>File to Include: <rawfile/raw_file.h>| 
| [raw_file_manager.h](raw__file__manager_8h.md) | Provides functions for managing rawfile resources.  <br>File to Include: <rawfile/raw_file_manager.h>| 


### Structs

| Name | Description | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | Provides rawfile descriptor information.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [RawDir](#rawdir) | Provides the function of accessing rawfile directories.  | 
| [RawFile](#rawfile) | Provides the function of accessing rawfiles.  | 
| [NativeResourceManager](#nativeresourcemanager) | Implements the resource manager.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename) ([RawDir](#rawdir) \*rawDir, int index) | Obtains the rawfile name via an index.  | 
| [OH_ResourceManager_GetRawFileCount](#oh_resourcemanager_getrawfilecount) ([RawDir](#rawdir) \*rawDir) |Obtains the number of rawfiles in [RawDir](#rawdir).  | 
| [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) ([RawDir](#rawdir) \*rawDir) | Closes an opened [RawDir](#rawdir) and releases all associated resources.  | 
| [OH_ResourceManager_ReadRawFile](#oh_resourcemanager_readrawfile) (const [RawFile](#rawfile) \*rawFile, void \*buf, size_t length) |Reads a rawfile.  | 
| [OH_ResourceManager_SeekRawFile](#oh_resourcemanager_seekrawfile) (const [RawFile](#rawfile) \*rawFile, long offset, int whence) |Seeks for the data read/write position in the rawfile based on the specified offset.  | 
| [OH_ResourceManager_GetRawFileSize](#oh_resourcemanager_getrawfilesize) ([RawFile](#rawfile) \*rawFile) | Obtains the length of a rawfile in int32_t.  | 
| [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) ([RawFile](#rawfile) \*rawFile) | Closes an opened [RawFile](#rawfile) and releases all associated resources.  | 
| [OH_ResourceManager_GetRawFileOffset](#oh_resourcemanager_getrawfileoffset) (const [RawFile](#rawfile) \*rawFile) | Obtains the current offset of the rawfile in int32_t.  | 
| [OH_ResourceManager_GetRawFileDescriptor](#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Opens a rawfile descriptor.  | 
| [OH_ResourceManager_ReleaseRawFileDescriptor](#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Closes a rawfile descriptor.  | 
| [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | Obtains the native resource manager based on JavaScipt resource manager.  | 
| [OH_ResourceManager_ReleaseNativeResourceManager](#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](#nativeresourcemanager) \*resMgr) | Releases a native resource manager.  | 
| [OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*dirName) | Opens a rawfile directory.  | 
| [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a rawfile.  | 


## Type Description


### NativeResourceManager

  
```
typedef struct NativeResourceManagerNativeResourceManager
```
**Description**<br>
Implements the resource manager.

This class encapsulates the native implementation of the JavaScript resource manager. You can obtain the pointer to **ResourceManager** by calling [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).


### RawDir

  
```
typedef struct RawDirRawDir
```
**Description**<br>
Provides the function of accessing rawfile directories.


### RawFile

  
```
typedef struct RawFileRawFile
```
**Description**<br>
Provides the function of accessing rawfiles.


## Function Description


### OH_ResourceManager_CloseRawDir()

  
```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```
**Description**<br>
Closes an opened [RawDir](#rawdir) and releases all associated resources.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawDir | Indicates the pointer to [RawDir](#rawdir).  | 

 **See**

[OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir)


### OH_ResourceManager_CloseRawFile()

  
```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```
**Description**<br>
Closes an opened [RawFile](#rawfile) and releases all associated resources.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 

 **See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileCount()

  
```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```
**Description**<br>
Obtains the number of rawfiles in [RawDir](#rawdir).

You can use this function to obtain available indexes in [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename).

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawDir | Indicates the pointer to [RawDir](#rawdir).  | 

 **See**

[OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename)


### OH_ResourceManager_GetRawFileDescriptor()

  
```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```
**Description**<br>
Opens a rawfile descriptor.

After the descriptor is opened, you can use it to read the rawfile based on the offset (in int32_t) and file length.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 
| descriptor | Indicates the rawfile descriptor, and the start position and length of the rawfile file in the HAP package.  | 

**Returns**

Returns **true** if the rawfile descriptor is opened successfully; returns **false** if the rawfile cannot be accessed.


### OH_ResourceManager_GetRawFileName()

  
```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```
**Description**<br>
Obtains the rawfile name via an index.

You can use this function to traverse a rawfile directory.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawDir | Indicates the pointer to [RawDir](#rawdir).  | 
| index | Indicates the index of the file in [RawDir](#rawdir).  | 

**Returns**

Returns the rawfile name via an index. The return value can be used as the input parameter of [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile). If no rawfile is found after all rawfiles are traversed, **NULL** will be returned.

 **See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileOffset()

  
```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```
**Description**<br>
Obtains the current offset of the rawfile in int32_t.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 

**Returns**

Returns the current offset of the rawfile.


### OH_ResourceManager_GetRawFileSize()

  
```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```
**Description**<br>
Obtains the length of a rawfile in int32_t.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 

**Returns**

Returns the total length of the rawfile.


### OH_ResourceManager_InitNativeResourceManager()

  
```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```
**Description**<br>
Obtains the native resource manager based on JavaScipt resource manager.

After obtaining a resource manager, you can use it complete various rawfile operations.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the pointer to the JavaScipt Native Interface (napi) environment.  | 
| jsResMgr | Indicates the JavaScipt resource manager.  | 

**Returns**

Returns the pointer to [NativeResourceManager](#nativeresourcemanager).


### OH_ResourceManager_OpenRawDir()

  
```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```
**Description**<br>
Opens a rawfile directory.

After opening a rawfile directory, you can traverse all the rawfile files in it.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| mgr | Indicates the pointer to [NativeResourceManager](#nativeresourcemanager). You can obtain this pointer by calling [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).  | 
| dirName | Indicates the name of the rawfile directory to open. If this field is left empty, the root directory of rawfile will be opened.  | 

**Returns**

Returns the pointer to [RawDir](#rawdir). If this pointer is no longer needed after use, call [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) to release it.

 **See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir)


### OH_ResourceManager_OpenRawFile()

  
```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```
**Description**<br>
Opens a rawfile.

After a rawfile is opened, you can read the data in it.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| mgr | Indicates the pointer to [NativeResourceManager](#nativeresourcemanager). You can obtain this pointer by calling [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).  | 
| fileName | Indicates the file name in the relative path of the rawfile root directory.  | 

**Returns**

Returns the pointer to [RawFile](#rawfile). If this pointer is no longer needed after use, call [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) to release it.

 **See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile)


### OH_ResourceManager_ReadRawFile()

  
```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```
**Description**<br>
Reads a rawfile.

You can use this function to read data of the specified length from the current position.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 
| buf | Indicates the pointer to the buffer for storing the read data.  | 
| length | Indicates the length of the read data, in bytes.  | 

**Returns**

Returns the length of the read data in bytes. If the length is beyond the end of the rawfile, **0** will be returned.


### OH_ResourceManager_ReleaseNativeResourceManager()

  
```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```
**Description**<br>
Releases a native resource manager.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| resMgr | Indicates the pointer to [NativeResourceManager](#nativeresourcemanager).  | 


### OH_ResourceManager_ReleaseRawFileDescriptor()

  
```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```
**Description**<br>
Closes a rawfile descriptor.

To prevent file descriptor leakage, you are advised to release a rawfile descriptor after use.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| descriptor | Indicates the rawfile descriptor, and the start position and length of the rawfile file in the HAP package.  | 

**Returns**

Returns **true** if the rawfile descriptor is closed successfully; returns **false** otherwise.


### OH_ResourceManager_SeekRawFile()

  
```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```
**Description**<br>
Seeks for the data read/write position in the rawfile based on the specified offset.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| rawFile | Indicates the pointer to [RawFile](#rawfile).  | 
| offset | Indicates the specified offset.  | 
| whence | Indicates the data read/write position. The options are as follows:<br/>**0**: The read/write position is **offset**.<br/>**1**: The read/write position is the current position plus **offset**.<br/>**2**: The read/write position is the end of the file (EOF) plus **offset**. | 

**Returns**

Returns the new data read/write position if the operation is successful; returns **(long) -1** otherwise.

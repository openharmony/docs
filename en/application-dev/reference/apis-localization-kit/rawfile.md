# Rawfile


## Overview

Provides the function of operating rawfile directories and rawfiles. You can use the APIs to traverse, open, search for, read, and close raw files. The **rawfile** APIs are non-thread-safe, and the **close** and **open** APIs are thread-safe.

**Since**: 8


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [raw_dir.h](raw__dir_8h.md) | Provides functions related to the **rawfile** directory.| 
| [raw_file.h](raw__file_8h.md) | Provides functions related to rawfiles, including searching for, reading, and closing rawfiles.| 
| [raw_file_manager.h](raw__file__manager_8h.md) | Provides file management functions for the **rawfile** directory. You can use the **ResourceManager** to open a rawfile and perform operations such as data search and reading.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[RawFileDescriptor](_raw_file_descriptor.md) | Defines the file descriptor information of a file in the **rawfile** directory.| 
| struct&nbsp;&nbsp;[RawFileDescriptor64](_raw_file_descriptor64.md) | Defines the file descriptor of a large rawfile.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [RawDir](#rawdir)[RawDir](#rawdir) | Provides access to the **rawfile** directory.| 
| typedef struct [RawFile](#rawfile)[RawFile](#rawfile) | Provides access to rawfiles.| 
| typedef struct [RawFile64](#rawfile64)[RawFile64](#rawfile64) | Provides access to large rawfiles.| 
| typedef struct [NativeResourceManager](#nativeresourcemanager)[NativeResourceManager](#nativeresourcemanager) | Represents the native **ResourceManager**.| 


### Functions

| Name| Description| 
| -------- | -------- |
| const char \* [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename) ([RawDir](#rawdir) \*rawDir, int index) | Obtains the name of a file in **rawfile** based on the index.| 
| int [OH_ResourceManager_GetRawFileCount](#oh_resourcemanager_getrawfilecount) ([RawDir](#rawdir) \*rawDir) | Obtains the number of files in a [RawDir](#rawdir).| 
| void [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) ([RawDir](#rawdir) \*rawDir) | Closes a [RawDir](#rawdir) and releases all associated resources.| 
| int [OH_ResourceManager_ReadRawFile](#oh_resourcemanager_readrawfile) (const [RawFile](#rawfile) \*rawFile, void \*buf, size_t length) | Reads data of the specified length from the current position in a rawfile.| 
| int [OH_ResourceManager_SeekRawFile](#oh_resourcemanager_seekrawfile) (const [RawFile](#rawfile) \*rawFile, long offset, int whence) | Searches for the data read/write position in a rawfile based on the specified offset.| 
| long [OH_ResourceManager_GetRawFileSize](#oh_resourcemanager_getrawfilesize) ([RawFile](#rawfile) \*rawFile) | Obtains the length of the rawfile, in long.| 
| long [OH_ResourceManager_GetRawFileRemainingLength](#oh_resourcemanager_getrawfileremaininglength) (const [RawFile](#rawfile) \*rawFile) | Obtains the remaining length of the rawfile, in long.| 
| void [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) ([RawFile](#rawfile) \*rawFile) | Closes a [RawFile](#rawfile) and releases all associated resources.| 
| long [OH_ResourceManager_GetRawFileOffset](#oh_resourcemanager_getrawfileoffset) (const [RawFile](#rawfile) \*rawFile) | Obtains the current offset of a rawfile, in long.| 
| bool [OH_ResourceManager_GetRawFileDescriptor](#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Opens a rawfile based on the specified offset (in long) and file length (in long) and obtains the file descriptor.| 
| bool [OH_ResourceManager_ReleaseRawFileDescriptor](#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Releases a file descriptor.| 
| int64_t [OH_ResourceManager_ReadRawFile64](#oh_resourcemanager_readrawfile64) (const [RawFile64](#rawfile64) \*rawFile, void \*buf, int64_t length) | Reads data of the specified length from the current position in a large rawfile.| 
| int [OH_ResourceManager_SeekRawFile64](#oh_resourcemanager_seekrawfile64) (const [RawFile64](#rawfile64) \*rawFile, int64_t offset, int whence) | Searches for the data read/write position in a large rawfile based on the specified offset.| 
| int64_t [OH_ResourceManager_GetRawFileSize64](#oh_resourcemanager_getrawfilesize64) ([RawFile64](#rawfile64) \*rawFile) | Obtains the length of a large rawfile, in int64_t.| 
| int64_t [OH_ResourceManager_GetRawFileRemainingLength64](#oh_resourcemanager_getrawfileremaininglength64) (const [RawFile64](#rawfile64) \*rawFile) | Obtains the remaining length of a large rawfile, in int64_t.| 
| void [OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64) ([RawFile64](#rawfile64) \*rawFile) | Closes a [RawFile64](#rawfile64) and releases all associated resources.| 
| int64_t [OH_ResourceManager_GetRawFileOffset64](#oh_resourcemanager_getrawfileoffset64) (const [RawFile64](#rawfile64) \*rawFile) | Obtains the offset of a large rawfile, in int64_t.| 
| bool [OH_ResourceManager_GetRawFileDescriptor64](#oh_resourcemanager_getrawfiledescriptor64) (const [RawFile64](#rawfile64) \*rawFile, [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | Opens a large rawfile based on the specified offset (in int64_t) and file length (in int64_t) and obtains the file descriptor.| 
| bool [OH_ResourceManager_ReleaseRawFileDescriptor64](#oh_resourcemanager_releaserawfiledescriptor64) (const [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | Releases a file descriptor.| 
| [NativeResourceManager](#nativeresourcemanager) \* [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | Obtains the native **ResourceManager** based on the JS **ResourceManager** to implement rawfile-specific functions.| 
| void [OH_ResourceManager_ReleaseNativeResourceManager](#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](#nativeresourcemanager) \*resMgr) | Releases the native **ResourceManager**.| 
| [RawDir](#rawdir) \* [OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*dirName) | Traverses all files in the **rawfile** directory.| 
| [RawFile](#rawfile) \* [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a rawfile and reads the data in it.| 
| [RawFile64](#rawfile64) \* [OH_ResourceManager_OpenRawFile64](#oh_resourcemanager_openrawfile64) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a large rawfile and reads the data in it.| 
| bool [OH_ResourceManager_IsRawDir](#oh_resourcemanager_israwdir) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*path) | Checks whether a path is a subdirectory in the **rawfile** directory.| 


## Type Description


### NativeResourceManager

```
typedef struct NativeResourceManagerNativeResourceManager
```

**Description**

Represents the native **ResourceManager**.

This class encapsulates the native implementation of the JavaScript resource manager. The **ResourceManager** pointer can be obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).

**Since**: 8


### RawDir

```
typedef struct RawDirRawDir
```

**Description**

Provides access to the **rawfile** directory.

**Since**: 8


### RawFile

```
typedef struct RawFileRawFile
```

**Description**

Provides access to rawfiles.

**Since**: 8


### RawFile64

```
typedef struct RawFile64RawFile64
```

**Description**

Provides access to large rawfiles.

**Since**: 11


## Function Description


### OH_ResourceManager_CloseRawDir()

```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```

**Description**

Closes a [RawDir](#rawdir) opened and releases all associated resources.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawDir | Pointer to the [RawDir](#rawdir).| 

**See**

[OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir)


### OH_ResourceManager_CloseRawFile()

```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```

**Description**

Closes a [RawFile](#rawfile) and releases all associated resources.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 

**See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_CloseRawFile64()

```
void OH_ResourceManager_CloseRawFile64 (RawFile64 * rawFile)
```

**Description**

Closes a [RawFile64](#rawfile64) and releases all associated resources.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 

**See**

[OH_ResourceManager_OpenRawFile64](#oh_resourcemanager_openrawfile64)


### OH_ResourceManager_GetRawFileCount()

```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```

**Description**

Obtains the number of files in a [RawDir](#rawdir).

You can use this function to obtain available indexes in [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename).

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawDir | Pointer to the [RawDir](#rawdir).| 

**See**

[OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename)

**Returns**

Number of files in **rawDir**. If **rawDir** is empty, **0** is returned.


### OH_ResourceManager_GetRawFileDescriptor()

```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```

**Description**

Opens a rawfile based on the specified offset (in long) and file length (in long) and obtains the file descriptor.

The file descriptor obtained can be used to read the file.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 
| descriptor | File descriptor of the rawfile, start position of the rawfile in the HAP, and length of the rawfile.| 

**Returns**

<b>true</b> if the file is opened; returns <b>false</b> if the access to the file is rejected.


### OH_ResourceManager_GetRawFileDescriptor64()

```
bool OH_ResourceManager_GetRawFileDescriptor64 (const RawFile64 * rawFile, RawFileDescriptor64 * descriptor )
```

**Description**

Opens a large rawfile based on the specified offset (in int64_t) and file length (in int64_t) and obtains the file descriptor.

The file descriptor obtained can be used to read the file.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 
| File descriptor of the rawfile, start position of the rawfile in the HAP, and length of the rawfile.|  | 

**Returns**

<b>true</b> if the file is opened; <b>false</b> if the access to the file is rejected.


### OH_ResourceManager_GetRawFileName()

```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```

**Description**

Obtain the name of the rawfile file through the index. You can use this method to traverse the rawfile directory.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawDir | Pointer to the [RawDir](#rawdir).| 
| index | Index of the file in the [RawDir](#rawdir).| 

**Returns**

File name obtained if the rawfile exists in the directory; returns **null** otherwise. The file name returned can be used as the input parameter of [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile).

**See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileOffset()

```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```

**Description**

Obtains the current offset of a rawfile, in long.

Current offset of the rawfile.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 

**Returns**

Current offset of the rawfile. If the rawfile is empty, **0** is returned.


### OH_ResourceManager_GetRawFileOffset64()

```
int64_t OH_ResourceManager_GetRawFileOffset64 (const RawFile64 * rawFile)
```

**Description**

Obtains the offset of a large rawfile, in int64_t.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 

**Returns**

Returns the current offset of the rawfile. If the rawfile is empty, 0 is returned.


### OH_ResourceManager_GetRawFileRemainingLength()

```
long OH_ResourceManager_GetRawFileRemainingLength (const RawFile * rawFile)
```

**Description**

Obtains the remaining length of the rawfile, in long.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 

**Returns**

Remaining length of the rawfile. If the rawfile is empty, **0** is returned.


### OH_ResourceManager_GetRawFileRemainingLength64()

```
int64_t OH_ResourceManager_GetRawFileRemainingLength64 (const RawFile64 * rawFile)
```

**Description**

Obtains the remaining length of a large rawfile, in int64_t.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 

**Returns**

Remaining length of the rawfile. If the rawfile is empty, **0** is returned.


### OH_ResourceManager_GetRawFileSize()

```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```

**Description**

Obtains the length of the rawfile, in long.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 

**Returns**

Overall length of the rawfile. If the rawfile is empty, **0** is returned.


### OH_ResourceManager_GetRawFileSize64()

```
int64_t OH_ResourceManager_GetRawFileSize64 (RawFile64 * rawFile)
```

**Description**

Obtains the length of a large rawfile, in int64_t.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 

**Returns**

Overall length of the rawfile. If the rawfile is empty, **0** is returned.


### OH_ResourceManager_InitNativeResourceManager()

```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```

**Description**

Obtains the native **ResourceManager** based on the JS **ResourceManager** to implement rawfile-specific functions.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the JS native API (napi) environment.| 
| jsResMgr | JS **ResourceManager**.| 

**Returns**

Pointer to [NativeResourceManager](#nativeresourcemanager). If the operation fails, a null pointer is returned.


### OH_ResourceManager_IsRawDir()

```
bool OH_ResourceManager_IsRawDir (const NativeResourceManager * mgr, const char * path )
```

**Description**

Checks whether a path is a subdirectory in the **rawfile** directory.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).| 
| path | Path of a rawfile.| 

**Returns**

**true** if the path is a subdirectory in the **rawfile** directory; **false** otherwise.


### OH_ResourceManager_OpenRawDir()

```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```

**Description**

Traverses all files in the **rawfile** directory.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).| 
| dirName | Pointer to the name of the directory to open. If this field is left empty, the root directory will be opened.| 

**Returns**

Pointer to the [RawDir](#rawdir). You can use [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) to close the directory and release resources. If the operation fails or **mgr** is empty, a null pointer is returned.

**See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir)


### OH_ResourceManager_OpenRawFile()

```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```

**Description**

Opens a rawfile and reads the data in it.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).| 
| fileName | Pointer to the name of the file in the relative path of the **rawfile** root directory.| 

**Returns**

Pointer to the [RawFile](#rawfile) opened. You can use [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) to close the rawfile and release resources. If the operation fails or **mgr** or **fileName** is empty, a null pointer is returned.

**See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile)


### OH_ResourceManager_OpenRawFile64()

```
RawFile64* OH_ResourceManager_OpenRawFile64 (const NativeResourceManager * mgr, const char * fileName )
```

**Description**

Opens a large rawfile and reads the data in it.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).| 
| fileName | Pointer to the name of the file in the relative path of the **rawfile** root directory.| 

**Returns**

Pointer to [RawFile64](#rawfile64). After this pointer is used, call [OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64) to release it. If the operation fails or **mgr** or **fileName** is empty, a null pointer is returned.

**See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64)


### OH_ResourceManager_ReadRawFile()

```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```

**Description**

Reads data of the specified length from the current position in a rawfile.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 
| buf | Pointer to the buffer for receiving the read data.| 
| length | Length of the data to read.| 

**Returns**

Number of read bytes. If the read length exceeds the length of the file end or rawfile is empty, **0** is returned.


### OH_ResourceManager_ReadRawFile64()

```
int64_t OH_ResourceManager_ReadRawFile64 (const RawFile64 * rawFile, void * buf, int64_t length )
```

**Description**

Reads data of the specified length from the current position in a large rawfile.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 
| buf | Pointer to the buffer for receiving the read data.| 
| length | Length of the data to read.| 

**Returns**

Number of read bytes. If the read length exceeds the length of the file end or rawfile is empty, **0** is returned.


### OH_ResourceManager_ReleaseNativeResourceManager()

```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```

**Description**

Releases the native **ResourceManager**.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| resMgr | Pointer to the [NativeResourceManager](#nativeresourcemanager) instance to release.| 


### OH_ResourceManager_ReleaseRawFileDescriptor()

```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```

**Description**

Releases the file descriptor of a file in **rawfile**.

To prevent file descriptor leakage, you are advised to release a rawfile descriptor immediately after use.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| descriptor | File descriptor of the rawfile. It contains the file descriptor, start position in the HAP, and file length.| 

**Returns**

Returns <b>true</b> if the file descriptor is released; returns <b>false</b> otherwise.


### OH_ResourceManager_ReleaseRawFileDescriptor64()

```
bool OH_ResourceManager_ReleaseRawFileDescriptor64 (const RawFileDescriptor64 * descriptor)
```

**Description**

Releases the file descriptor of a file in **rawfile**.

To prevent file descriptor leakage, you are advised to release a rawfile descriptor immediately after use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| descriptor | File descriptor of the rawfile. It contains the file descriptor, start position in the HAP, and file length.| 

**Returns**

<b>true</b> if the file descriptor is released; <b>false</b> otherwise.


### OH_ResourceManager_SeekRawFile()

```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```

**Description**

Searches for the data read/write position in a rawfile based on the specified offset.

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.| 
| offset | Specified offset.| 
| whence | Read/Write position. The options are as follows:<br>**0**: The read/write position is the start position of the file plus the offset.<br>**1**: The read/write position is the current position plus the offset.<br>**2**: The read/write position is the end position of the file plus the offset.| 

**Returns**

**0** if the search is successful; **-1** otherwise.


### OH_ResourceManager_SeekRawFile64()

```
int OH_ResourceManager_SeekRawFile64 (const RawFile64 * rawFile, int64_t offset, int whence )
```

**Description**

Searches for the data read/write position in a large rawfile based on the specified offset.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to [RawFile64](#rawfile64).| 
| offset | Specified offset.| 
| whence | Read/Write position. The options are as follows:<br>**0**: The read/write position is the start position of the file plus the offset.<br>**1**: The read/write position is the current position plus the offset.<br>**2**: The read/write position is the end position of the file plus the offset.| 

**Returns**

**0** if the search is successful; **-1** otherwise.

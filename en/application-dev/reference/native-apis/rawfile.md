# Rawfile


Provides APIs for operating the **rawfile** directory and its files, including traversing the **rawfile** directory and opening, searching for, reading, and closing a file in it.

**Since**


8


## Summary


### Files

| Name                                    | Description                |
| ---------------------------------------- | ------------------ |
| [raw_dir.h](raw__dir_8h.md)              | Provides functions related to the **rawfile** directory.<br>File to include: \<rawfile/raw_dir.h>  |
| [raw_file.h](raw__file_8h.md)            | Provides functions related to the files in the **rawfile** directory.<br>File to include: \<rawfile/raw_file.h> |
| [raw_file_manager.h](raw__file__manager_8h.md) | Provides file management functions for the **rawfile** directory.<br>File to import: \<rawfile/raw_file_manager.h>|


### Structs

| Name                                   | Description               |
| ---------------------------------------- | ----------------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | Defines the file descriptor (FD) information of a file in the **rawfile** directory. |


### Types

| Name                                  | Description                 |
| ---------------------------------------- | ------------------- |
| [RawDir](#rawdir)                        | Provides access to the **rawfile** directory.   |
| [RawFile](#rawfile)                      | Provides access to the files in **rawfile**.   |
| [NativeResourceManager](#nativeresourcemanager) | Represents the resource manager.|


### Functions

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename) ([RawDir](#rawdir) \*rawDir, int index) | Obtains the name of a file in **rawfile** based on the index. |
| [OH_ResourceManager_GetRawFileCount](#oh_resourcemanager_getrawfilecount) ([RawDir](#rawdir) \*rawDir) | Obtains the number of files in a [RawDir](#rawdir).          |
| [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) ([RawDir](#rawdir) \*rawDir) | Closes a [RawDir](#rawdir) and releases all associated resources. |
| [OH_ResourceManager_ReadRawFile](#oh_resourcemanager_readrawfile) (const [RawFile](#rawfile) \*rawFile, void \*buf, size_t length) | Reads data from a file in **rawfile**.                       |
| [OH_ResourceManager_SeekRawFile](#oh_resourcemanager_seekrawfile) (const [RawFile](#rawfile) \*rawFile, long offset, int whence) | Seeks for the data read/write position in a file in **rawfile** based on the specified offset. |
| [OH_ResourceManager_GetRawFileSize](#oh_resourcemanager_getrawfilesize) ([RawFile](#rawfile) \*rawFile) | Obtains the size of a file in **rawfile**.                   |
| [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) ([RawFile](#rawfile) \*rawFile) | Closes a [RawFile](#rawfile) and releases all associated resources. |
| [OH_ResourceManager_GetRawFileOffset](#oh_resourcemanager_getrawfileoffset) (const [RawFile](#rawfile) \*rawFile) | Obtains the current offset of a file in **rawfile**.         |
| [OH_ResourceManager_GetRawFileDescriptor](#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Opens a file in **rawfile** based on the offset and file length and obtains the FD. |
| [OH_ResourceManager_ReleaseRawFileDescriptor](#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Releases an FD.                                               |
| [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | Initializes a Native resource manager using the JavaScript resource manager. You can use the Native resource manager obtained to implement operations related to **rawfile**. |
| [OH_ResourceManager_ReleaseNativeResourceManager](#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](#nativeresourcemanager) \*resMgr) | Releases a Native resource manager instance.                 |
| [OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*dirName) | Opens a directory in the **rawfile** directory.              |
| [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a file in the **rawfile** directory.                   |


## Description


### Type Description


#### NativeResourceManager


```
typedef struct NativeResourceManager NativeResourceManager
```

**Description**

Represents the resource manager.

This class encapsulates the native implementation of the JavaScript resource manager. The **ResourceManager** pointer can be obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).

**Since**

8


#### RawDir


```
typedef struct RawDir RawDir
```

**Description**

Provides access to the **rawfile** directory.

**Since**

8


#### RawFile


```
typedef struct RawFile RawFile
```

**Description**

Provides access to the files in **rawfile**.

**Since**

8


### Function Description


#### OH_ResourceManager_CloseRawDir()


```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```

**Description**

Closes a [RawDir](#rawdir) opened and releases all associated resources.

**Parameters**

| Name   | Description                       |
| ------ | ------------------------- |
| rawDir | Pointer to the [RawDir](#rawdir) to close.|

**See**

[OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir)

**Since**

8


#### OH_ResourceManager_CloseRawFile()


```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```

**Description**

Closes a [RawFile](#rawfile) and releases all associated resources.

**Parameters**

| Name    | Description                         |
| ------- | --------------------------- |
| rawFile | Pointer to the [RawFile](#rawfile) to close.|

**See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)

**Since**

8


#### OH_ResourceManager_GetRawFileCount()


```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```

**Description**

Obtains the number of files in a [RawDir](#rawdir).

You can use this function to obtain available indexes in [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename).

**Parameters**

| Name   | Description                       |
| ------ | ------------------------- |
| rawDir | Pointer to the target [RawDir](#rawdir).|

**See**

[OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename)

**Since**

8


#### OH_ResourceManager_GetRawFileDescriptor()


```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```

**Description**

Opens a file in the **rawfile** directory based on the offset and file length and obtains the FD.

The FD obtained can be used to read the file.

**Parameters**

| Name       | Description                                                |
| ---------- | ---------------------------------------------------- |
| rawFile    | Pointer to the [RawFile](#rawfile).                 |
| descriptor | File descriptor of the file, start position of the file in the hAP, and length of the file.|

**Returns**

Returns <b>true</b> if the file is opened; returns <b>false</b> if the access to the file is rejected.

**Since**

8


#### OH_ResourceManager_GetRawFileName()


```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```

**Description**

Obtains the name of a file in **rawfile** based on the index.

You can use this function to traverse the **rawfile** directory.

**Parameters**

| Name   | Description                           |
| ------ | ----------------------------- |
| rawDir | Pointer to the [RawDir](#rawdir).    |
| index  | Index of the file in the [RawDir](#rawdir).|

**Returns**

Returns the file name obtained if the file exists in the directory; returns **null** otherwise. The file name returned can be used as the input parameter of [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile).

**See**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)

**Since**

8


#### OH_ResourceManager_GetRawFileOffset()


```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```

**Description**

Obtains the current offset of a file in **rawfile**.

The offset indicates the position of the file in the HAP.

**Parameters**

| Name    | Description                         |
| ------- | --------------------------- |
| rawFile | Pointer to the target [RawFile](#rawfile).|

**Returns**

Returns the file offset obtained.

**Since**

8


#### OH_ResourceManager_GetRawFileSize()


```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```

**Description**

Obtains the size of a file in **rawfile**.

**Parameters**

| Name    | Description                         |
| ------- | --------------------------- |
| rawFile | Pointer to the target [RawFile](#rawfile).|

**Returns**

Returns the file size obtained.

**Since**

8


#### OH_ResourceManager_InitNativeResourceManager()


```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```

**Description**

Initializes a Native resource manager using the JavaScript resource manager.

You can use the resource manager obtained to implement **rawfile** operations.

**Parameters**

| Name     | Description                                      |
| -------- | ---------------------------------------- |
| env      | Pointer to the JavaScript Native API (napi) environment.|
| jsResMgr | JavaScript resource manager.          |

**Returns**

Returns the pointer to the [NativeResourceManager](#nativeresourcemanager) obtained.

**Since**

8


#### OH_ResourceManager_OpenRawDir()


```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```

**Description**

Opens a directory in **rawfile**.

After opening the directory, you can traverse all files in it.

**Parameters**

| Name    | Description                                      |
| ------- | ---------------------------------------- |
| mgr     | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).|
| dirName | Pointer to the name of the directory to open. If this field is left empty, the root directory will be opened.|

**Returns**

Returns the pointer to the [RawDir](#rawdir) opened. You can use [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) to close the directory and release resources.

**See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir)

**Since**

8


#### OH_ResourceManager_OpenRawFile()


```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```

**Description**

Opens a file in **rawfile**.

After the file is opened, you can read data in it.

**Parameters**

| Name     | Description                                      |
| -------- | ---------------------------------------- |
| mgr      | Pointer to the [NativeResourceManager](#nativeresourcemanager), which is obtained by using [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager).|
| fileName | Pointer to the name of the file in the relative path of the **rawfile** root directory.              |

**Returns**

Returns the pointer to the [RawFile](#rawfile) opened. You can use [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) to close the file and release resources.

**See**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile)

**Since**

8


#### OH_ResourceManager_ReadRawFile()


```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```

**Description**

Reads a file in **rawfile**.

You can use this function to read data of the specified length from the current position.

**Parameters**

| Name    | Description                         |
| ------- | --------------------------- |
| rawFile | Pointer to the [RawFile](#rawfile) to read.|
| buf     | Pointer to the buffer for receiving the read data.            |
| length  | Length of the data to read.                 |

**Returns**

Returns the number of bytes read. If the read length exceeds the length of the file end, **0** will be returned.

**Since**

8


#### OH_ResourceManager_ReleaseNativeResourceManager()


```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```

**Description**

Releases a Native resource manager instance.

**Parameters**

| Name   | Description                                      |
| ------ | ---------------------------------------- |
| resMgr | Pointer to the [NativeResourceManager](#nativeresourcemanager) instance to release.|

**Since**

8


#### OH_ResourceManager_ReleaseRawFileDescriptor()


```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```

**Description**

Releases the FD of a file in **rawfile**.

To prevent FD leakage, you are advised to release an FD immediately after use.

**Parameters**

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| descriptor | File descriptor to close. It contains the FD, start position in the HAP, and file length. |

**Returns**

Returns <b>true</b> if the FD is released; returns <b>false</b> otherwise.

**Since**

8


#### OH_ResourceManager_SeekRawFile()


```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```

**Description**

Seeks for the data read/write position in a file in **rawfile** based on the specified offset.

**Parameters**

| Name    | Description                                      |
| ------- | ---------------------------------------- |
| rawFile | Pointer to the target [RawFile](#rawfile).             |
| offset  | Offset.                            |
| whence  | Read/Write position. The options are as follows:<br>**0**: The read/write position is the offset.<br>**1**: The read/write position is the current position plus the offset.<br>**2**: The read/write position is the end of the file (EOF) plus the offset.|

**Returns**

Returns the read/write position if the operation is successful; returns **(long) -1** otherwise.

**Since**

8

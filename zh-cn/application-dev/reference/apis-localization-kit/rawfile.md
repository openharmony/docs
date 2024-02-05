# Rawfile


## 概述

提供操作rawfile目录和rawfile文件的功能，包括遍历、打开、搜索、读取和关闭。

**起始版本：** 8

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [raw_dir.h](raw__dir_8h.md) | 提供rawfile目录相关功能 | 
| [raw_file.h](raw__file_8h.md) | 提供rawfile文件相关功能，包括搜索、读取和关闭。 | 
| [raw_file_manager.h](raw__file__manager_8h.md) | 提供资源管理rawfile相关功能，可以使用ResourceManager打开rawfile进行后续相关操作，包括搜索和读取等。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息 | 
| [RawFileDescriptor64](_raw_file_descriptor64.md) | 提供rawfile文件描述符信息<br/>**说明**：RawFile64是新增接口，新接口支持打开更大的rawfile文件，性能更优 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [RawDir](#rawdir) | 提供对rawfile目录的访问 | 
| [RawFile](#rawfile) | 提供对rawfile的访问功能 | 
| [RawFile64](#rawfile64) | 提供对rawfile的访问功能<br/>**说明**：RawFile64是新增接口，新接口支持打开更大的rawfile文件，性能更优 | 
| [NativeResourceManager](#nativeresourcemanager) | 代表native侧的ResourceManager | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename) ([RawDir](#rawdir) \*rawDir, int index) | 通过索引获取rawfile文件名称 | 
| [OH_ResourceManager_GetRawFileCount](#oh_resourcemanager_getrawfilecount) ([RawDir](#rawdir) \*rawDir) | 获取[RawDir](#rawdir)中的rawfile数量 | 
| [OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir) ([RawDir](#rawdir) \*rawDir) | 关闭已打开的[RawDir](#rawdir)并释放所有相关联资源 | 
| [OH_ResourceManager_ReadRawFile](#oh_resourcemanager_readrawfile) (const [RawFile](#rawfile) \*rawFile, void \*buf, size_t length) | 读取rawfile内容，从当前位置读取指定长度的数据 | 
| [OH_ResourceManager_SeekRawFile](#oh_resourcemanager_seekrawfile) (const [RawFile](#rawfile) \*rawFile, long offset, int whence) | 基于指定的偏移量，在rawfile文件内搜索读写数据的位置，单位为long | 
| [OH_ResourceManager_GetRawFileSize](#oh_resourcemanager_getrawfilesize) ([RawFile](#rawfile) \*rawFile) | 获取rawfile长度，单位为long | 
| [OH_ResourceManager_GetRawFileRemainingLength](#oh_resourcemanager_getrawfileremaininglength) (const [RawFile](#rawfile) \*rawFile) | 获取rawfile的剩余长度，单位为long | 
| [OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile) ([RawFile](#rawfile) \*rawFile) | 关闭已打开的[RawFile](#rawfile) 以及释放所有相关联的资源 | 
| [OH_ResourceManager_GetRawFileOffset](#oh_resourcemanager_getrawfileoffset) (const [RawFile](#rawfile) \*rawFile) | 获取rawfile当前的偏移量，单位为long | 
| [OH_ResourceManager_GetRawFileDescriptor](#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 基于偏移量和文件长度打开rawfile，并获取rawfile文件描述符 | 
| [OH_ResourceManager_ReleaseRawFileDescriptor](#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 关闭rawfile文件描述符 | 
| [OH_ResourceManager_ReadRawFile64](#oh_resourcemanager_readrawfile64) (const [RawFile64](#rawfile64) \*rawFile, void \*buf, int64_t length) | 读取rawfile文件内容，从当前位置读取指定长度的数据<br/>**说明**：RawFile64是新增接口，新接口支持打开更大的rawfile文件，性能更优 | 
| [OH_ResourceManager_SeekRawFile64](#oh_resourcemanager_seekrawfile64) (const [RawFile64](#rawfile64) \*rawFile, int64_t offset, int whence) | 基于指定的偏移量，在rawfile文件内搜索读写数据的位置，单位为int64_t | 
| [OH_ResourceManager_GetRawFileSize64](#oh_resourcemanager_getrawfilesize64) ([RawFile64](#rawfile64) \*rawFile) | 获取较大rawfile文件的长度，单位为int64_t | 
| [OH_ResourceManager_GetRawFileRemainingLength64](#oh_resourcemanager_getrawfileremaininglength64) (const [RawFile64](#rawfile64) \*rawFile) | 获取较大rawfile的剩余长度，单位为int64_t | 
| [OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64) ([RawFile64](#rawfile64) \*rawFile) | 关闭已打开的[RawFile64](#rawfile64) 以及释放所有相关联的资源 | 
| [OH_ResourceManager_GetRawFileOffset64](#oh_resourcemanager_getrawfileoffset64) (const [RawFile64](#rawfile64) \*rawFile) | 获取rawfile文件的偏移量，单位为int64_t | 
| [OH_ResourceManager_GetRawFileDescriptor64](#oh_resourcemanager_getrawfiledescriptor64) (const [RawFile64](#rawfile64) \*rawFile, [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | 基于偏移量和文件长度打开较大的rawfile，并获取rawfile文件描述符 | 
| [OH_ResourceManager_ReleaseRawFileDescriptor64](#oh_resourcemanager_releaserawfiledescriptor64) (const [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | 关闭rawfile文件描述符 | 
| [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | 基于JavaScipt侧的ResourceManager获取native侧的ResourceManager，用来完成rawfile相关功能 | 
| [OH_ResourceManager_ReleaseNativeResourceManager](#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](#nativeresourcemanager) \*resMgr) | 释放native侧ResourceManager | 
| [OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*dirName) | 打开rawfile目录，打开后可以遍历对应目录下的rawfile文件 | 
| [OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | 打开rawfile文件，读取文件数据 | 
| [OH_ResourceManager_OpenRawFile64](#oh_resourcemanager_openrawfile64) (const [NativeResourceManager](#nativeresourcemanager) \*mgr, const char \*fileName) | 打开较大的rawfile文件，读取文件数据 | 


## 类型定义说明


### NativeResourceManager

```
typedef struct NativeResourceManagerNativeResourceManager
```

**描述**

代表native侧的ResourceManager

此类封装了JavaScript resource manager的native实现 **ResourceManager**指针可以通过调用[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)方法获取

**起始版本：** 8


### RawDir

```
typedef struct RawDirRawDir
```

**描述**

提供对rawfile目录的访问

**起始版本：** 8


### RawFile

```
typedef struct RawFileRawFile
```

**描述**

提供对rawfile的访问功能

**起始版本：** 8


### RawFile64

```
typedef struct RawFile64RawFile64
```

**描述**

针对64位设备，提供对rawfile的访问功能

**起始版本：** 11


## 函数说明


### OH_ResourceManager_CloseRawDir()

```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```

**描述**

关闭已打开的[RawDir](#rawdir)并释放所有相关联资源

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针 | 

**参见：**

[OH_ResourceManager_OpenRawDir](#oh_resourcemanager_openrawdir)


### OH_ResourceManager_CloseRawFile()

```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```

**描述**

关闭已打开的[RawFile](#rawfile) 以及释放所有相关联的资源

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 

**参见：**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_CloseRawFile64()

```
void OH_ResourceManager_CloseRawFile64 (RawFile64 * rawFile)
```

**描述**

关闭已打开的[RawFile64](#rawfile64) 以及释放所有相关联的资源

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 

**参见：**

[OH_ResourceManager_OpenRawFile64](#oh_resourcemanager_openrawfile64)


### OH_ResourceManager_GetRawFileCount()

```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```

**描述**

获取[RawDir](#rawdir)中的rawfile数量

通过此方法可以获取[OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename)中可用的索引

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针 | 

**参见：**

[OH_ResourceManager_GetRawFileName](#oh_resourcemanager_getrawfilename)


### OH_ResourceManager_GetRawFileDescriptor()

```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```

**描述**

基于偏移量(单位为long)和文件长度(单位为long)打开rawfile，并获取rawfile文件描述符

打开的文件描述符被用于读取rawfile

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 
| descriptor | 显示rawfile文件描述符，以及在HAP包中的起始位置和长度 | 

**返回：**

返回true表示打开rawfile文件描述符成功，返回false表示rawfile不允许被访问


### OH_ResourceManager_GetRawFileDescriptor64()

```
bool OH_ResourceManager_GetRawFileDescriptor64 (const RawFile64 * rawFile, RawFileDescriptor64 * descriptor )
```

**描述**

基于偏移量(单位为int64_t)和文件长度(单位为int64_t)打开较大的rawfile，并获取e文件描述符

打开的文件描述符被用于读取rawfile

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 
| 显示rawfile文件描述符，以及在HAP包中的起始位置和长度 |  | 

**返回：**

返回true表示打开rawfile文件描述符成功，返回false表示rawfile不允许被访问


### OH_ResourceManager_GetRawFileName()

```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```

**描述**

通过索引获取rawfile文件名称

可以使用此方法遍历rawfile目录

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针 | 
| index | 表示文件在[RawDir](#rawdir)中的索引位置 | 

**返回：**

通过索引返回文件名称，此返回值可以作为[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)的输入参数， 如果遍历完所有文件仍未找到，则返回**NULL**

**参见：**

[OH_ResourceManager_OpenRawFile](#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileOffset()

```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```

**描述**

获取rawfile当前的偏移量，单位为long

rawfile当前的偏移量

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 

**返回：**

返回rawfile当前的偏移量


### OH_ResourceManager_GetRawFileOffset64()

```
int64_t OH_ResourceManager_GetRawFileOffset64 (const RawFile64 * rawFile)
```

**描述**

获取较大rawfile文件的偏移量，单位为int64_t

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 

**返回：**

返回rawfile当前的偏移量


### OH_ResourceManager_GetRawFileRemainingLength()

```
long OH_ResourceManager_GetRawFileRemainingLength (const RawFile * rawFile)
```

**描述**

获取rawfile的剩余长度，单位为long

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 

**返回：**

返回rawfile的剩余长度


### OH_ResourceManager_GetRawFileRemainingLength64()

```
int64_t OH_ResourceManager_GetRawFileRemainingLength64 (const RawFile64 * rawFile)
```

**描述**

获取较大rawfile的剩余长度，单位为int64_t.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 

**返回：**

返回rawfile的剩余长度


### OH_ResourceManager_GetRawFileSize()

```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```

**描述**

获取rawfile长度，单位为long

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 

**返回：**

返回rawfile的整体长度


### OH_ResourceManager_GetRawFileSize64()

```
int64_t OH_ResourceManager_GetRawFileSize64 (RawFile64 * rawFile)
```

**描述**

获取较大rawfile文件的长度，单位为int64_t

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 

**返回：**

返回rawfile的整体长度


### OH_ResourceManager_InitNativeResourceManager()

```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```

**描述**

基于JavaScipt侧的ResourceManager获取native侧的ResourceManager，用来完成rawfile相关功能

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表示JavaScipt Native Interface (napi)环境指针 | 
| jsResMgr | 表示JavaScipt resource manager | 

**返回：**

返回[NativeResourceManager](#nativeresourcemanager)指针


### OH_ResourceManager_OpenRawDir()

```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```

**描述**

打开rawfile目录，打开后可以遍历对应目录下的rawfile文件

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 表示指向[NativeResourceManager](#nativeresourcemanager)的指针，此指针是通过调用 [OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)方法获取的 | 
| dirName | 表示要打开的rawfile目录名称，当传递一个空字符串时表示打开rawfile根目录 | 

**返回：**

返回[RawDir](#rawdir)指针。使用完此指针后，调用[OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir)释放。

**参见：**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](#oh_resourcemanager_closerawdir)


### OH_ResourceManager_OpenRawFile()

```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```

**描述**

打开rawfile文件，打开后可以读取它的数据

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 表示指向[NativeResourceManager](#nativeresourcemanager)的指针，此指针通过调用[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)方法获取 | 
| fileName | 表示基于rawfile根目录的相对路径下的文件名称 | 

**返回：**

返回[RawFile](#rawfile)指针。当使用完此指针，调用[OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile)释放。

**参见：**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](#oh_resourcemanager_closerawfile)


### OH_ResourceManager_OpenRawFile64()

```
RawFile64* OH_ResourceManager_OpenRawFile64 (const NativeResourceManager * mgr, const char * fileName )
```

**描述**

打开较大的rawfile文件，打开后可以读取它的数据

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 表示指向[NativeResourceManager](#nativeresourcemanager)的指针，此指针通过调用[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)方法获取 | 
| fileName | 表示基于rawfile根目录的相对路径下的文件名称 | 

**返回：**

返回[RawFile64](#rawfile64)指针。当使用完此指针，调用[OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64)释放。

**参见：**

[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile64](#oh_resourcemanager_closerawfile64)


### OH_ResourceManager_ReadRawFile()

```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```

**描述**

读取rawfile内容，从当前位置读取指定长度的数据

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 
| buf | 用于接收读取数据的缓冲区指针 | 
| length | 读取数据的字节长度 | 

**返回：**

返回读取的字节数，如果读取长度超过文件末尾长度，则返回**0**


### OH_ResourceManager_ReadRawFile64()

```
int64_t OH_ResourceManager_ReadRawFile64 (const RawFile64 * rawFile, void * buf, int64_t length )
```

**描述**

读取较大的rawfile文件内容，从当前位置读取**指定长度**的数据

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 
| buf | 用于接收读取数据的缓冲区指针 | 
| length | 读取数据的字节长度 | 

**返回：**

返回读取的字节数，如果读取长度超过文件末尾长度，则返回**0**


### OH_ResourceManager_ReleaseNativeResourceManager()

```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```

**描述**

释放native侧ResourceManager

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resMgr | 表示[NativeResourceManager](#nativeresourcemanager)指针 | 


### OH_ResourceManager_ReleaseRawFileDescriptor()

```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```

**描述**

关闭rawfile文件描述符

已打开的文件描述符在使用完以后必须释放，防止文件描述符泄露

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 包含rawfile文件描述符，以及在HAP包中的起始位置和长度 | 

**返回：**

返回true表示关闭文件描述符成功，返回false表示关闭文件描述符失败


### OH_ResourceManager_ReleaseRawFileDescriptor64()

```
bool OH_ResourceManager_ReleaseRawFileDescriptor64 (const RawFileDescriptor64 * descriptor)
```

**描述**

关闭rawfile文件描述符

已打开的文件描述符在使用完以后必须释放，防止文件描述符泄露

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 包含rawfile文件描述符，以及在HAP包中的起始位置和长度 | 

**返回：**

返回true表示关闭文件描述符成功，返回false表示关闭文件描述符失败


### OH_ResourceManager_SeekRawFile()

```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```

**描述**

基于指定的偏移量，在rawfile文件内搜索读写数据的位置

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针 | 
| offset | 表示指定的偏移量 | 
| whence | 读写位置，有以下场景:<br/>**0**: 读写位置为文件起始位置加上**offset**<br/>**1**: 读写位置为当前位置加上**offset**<br/>**2**: 读写位置为文件末尾加上**offset** | 

**返回：**

如果搜索成功返回&lt;b&gt;(int) 0，如果发生错误返回 **(int) -1**


### OH_ResourceManager_SeekRawFile64()

```
int OH_ResourceManager_SeekRawFile64 (const RawFile64 * rawFile, int64_t offset, int whence )
```

**描述**

基于指定的偏移量，在较大的rawfile文件内搜索读写数据的位置

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile64](#rawfile64)的指针 | 
| offset | 表示指定的偏移量 | 
| whence | 读写位置，有以下场景:<br/>**0**: 读写位置为文件起始位置加上**offset**<br/>**1**: 读写位置为当前位置加上**offset**<br/>**2**: 读写位置为文件末尾加上**offset** | 

**返回：**

如果搜索成功返回 **(int) 0**，如果发生错误返回 **(int) -1** occurs.

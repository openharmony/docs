# Rawfile


提供操作rawfile目录和rawfile文件的功能。


功能包括遍历、打开、搜索、读取和关闭rawfile。


**自从：**


8


## 汇总


### 文件

  | 文件名称 | 描述 | 
| -------- | -------- |
| [raw_dir.h](raw__dir_8h.md) | 提供rawfile目录相关功能。 | 
| [raw_file.h](raw__file_8h.md) | 提供rawfile文件相关功能。 | 
| [raw_file_manager.h](raw__file__manager_8h.md) | 提供资源管理rawfile相关功能。 | 


### 结构体

  | 结构体名称 | 描述 | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息。 | 


### 类型定义

  | 类型定义名称 | 描述 | 
| -------- | -------- |
| [RawDir](#rawdir) | 提供对rawfile目录的访问。 | 
| [RawFile](#rawfile) | 提供对rawfile的访问功能。 | 
| [NativeResourceManager](#nativeresourcemanager) | 代表resource&nbsp;manager。 | 


### 函数

  | 函数名称 | 描述 | 
| -------- | -------- |
| [OH_ResourceManager_GetRawFileName](#ohresourcemanagergetrawfilename)&nbsp;([RawDir](#rawdir)&nbsp;\*rawDir,&nbsp;int&nbsp;index) | 通过索引获取rawfile文件名称。 | 
| [OH_ResourceManager_GetRawFileCount](#ohresourcemanagergetrawfilecount)&nbsp;([RawDir](#rawdir)&nbsp;\*rawDir) | 获取[RawDir](#rawdir)中的rawfile数量。 | 
| [OH_ResourceManager_CloseRawDir](#ohresourcemanagercloserawdir)&nbsp;([RawDir](#rawdir)&nbsp;\*rawDir) | 关闭已打开的[RawDir](#rawdir)并释放所有相关联资源。 | 
| [OH_ResourceManager_ReadRawFile](#ohresourcemanagerreadrawfile)&nbsp;(const&nbsp;[RawFile](#rawfile)&nbsp;\*rawFile,&nbsp;void&nbsp;\*buf,&nbsp;size_t&nbsp;length) | 读取rawfile。 | 
| [OH_ResourceManager_SeekRawFile](#ohresourcemanagerseekrawfile)&nbsp;(const&nbsp;[RawFile](#rawfile)&nbsp;\*rawFile,&nbsp;long&nbsp;offset,&nbsp;int&nbsp;whence) | 基于指定的offset，在rawfile文件内搜索读写数据的位置。 | 
| [OH_ResourceManager_GetRawFileSize](#ohresourcemanagergetrawfilesize)&nbsp;([RawFile](#rawfile)&nbsp;\*rawFile) | 获取rawfile长度，单位为int32_t。 | 
| [OH_ResourceManager_CloseRawFile](#ohresourcemanagercloserawfile)&nbsp;([RawFile](#rawfile)&nbsp;\*rawFile) | 关闭已打开的[RawFile](#rawfile)&nbsp;以及释放所有相关联资源。 | 
| [OH_ResourceManager_GetRawFileOffset](#ohresourcemanagergetrawfileoffset)&nbsp;(const&nbsp;[RawFile](#rawfile)&nbsp;\*rawFile) | 获取rawfile当前的offset，单位为int32_t。 | 
| [OH_ResourceManager_GetRawFileDescriptor](#ohresourcemanagergetrawfiledescriptor)&nbsp;(const&nbsp;[RawFile](#rawfile)&nbsp;\*rawFile,&nbsp;[RawFileDescriptor](_raw_file_descriptor.md)&nbsp;&amp;descriptor) | 基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符。 | 
| [OH_ResourceManager_ReleaseRawFileDescriptor](#ohresourcemanagerreleaserawfiledescriptor)&nbsp;(const&nbsp;[RawFileDescriptor](_raw_file_descriptor.md)&nbsp;&amp;descriptor) | 关闭rawfile文件描述符。 | 
| [OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)&nbsp;(napi_env&nbsp;env,&nbsp;napi_value&nbsp;jsResMgr) | 基于JavaScipt&nbsp;resource&nbsp;manager获取native&nbsp;resource&nbsp;manager。 | 
| [OH_ResourceManager_ReleaseNativeResourceManager](#ohresourcemanagerreleasenativeresourcemanager)&nbsp;([NativeResourceManager](#nativeresourcemanager)&nbsp;\*resMgr) | 释放native&nbsp;resource&nbsp;manager。 | 
| [OH_ResourceManager_OpenRawDir](#ohresourcemanageropenrawdir)&nbsp;(const&nbsp;[NativeResourceManager](#nativeresourcemanager)&nbsp;\*mgr,&nbsp;const&nbsp;char&nbsp;\*dirName) | 打开rawfile目录。 | 
| [OH_ResourceManager_OpenRawFile](#ohresourcemanageropenrawfile)&nbsp;(const&nbsp;[NativeResourceManager](#nativeresourcemanager)&nbsp;\*mgr,&nbsp;const&nbsp;char&nbsp;\*fileName) | 打开rawfile文件。 | 


## 详细描述


## 类型定义说明


### NativeResourceManager

  
```
typedef struct NativeResourceManager NativeResourceManager
```

**描述：**

代表resource manager。

此类封装了JavaScript resource manager的native实现 **ResourceManager**指针可以通过调用[OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)方法获取

**自从：**

8


### RawDir

  
```
typedef struct RawDir RawDir
```

**描述：**

提供对rawfile目录的访问。

**自从：**

8


### RawFile

  
```
typedef struct RawFile RawFile
```

**描述：**

提供对rawfile的访问功能。

**自从：**

8


## 函数说明


### OH_ResourceManager_CloseRawDir()

  
```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```

**描述：**

关闭已打开的[RawDir](#rawdir)并释放所有相关联资源。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针。 | 

**参见：**

[OH_ResourceManager_OpenRawDir](#ohresourcemanageropenrawdir)

**自从：**

8


### OH_ResourceManager_CloseRawFile()

  
```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```

**描述：**

关闭已打开的[RawFile](#rawfile) 以及释放所有相关联资源。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 

**参见：**

[OH_ResourceManager_OpenRawFile](#ohresourcemanageropenrawfile)

**自从：**

8


### OH_ResourceManager_GetRawFileCount()

  
```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```

**描述：**

获取[RawDir](#rawdir)中的rawfile数量。

通过此方法可以获取[OH_ResourceManager_GetRawFileName](#ohresourcemanagergetrawfilename)中可用的索引。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针。 | 

**参见：**

[OH_ResourceManager_GetRawFileName](#ohresourcemanagergetrawfilename)

**自从：**

8


### OH_ResourceManager_GetRawFileDescriptor()

  
```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```

**描述：**

基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符。

打开的文件描述符被用于读取rawfile。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 
| descriptor | 显示rawfile文件描述符，以及在HAP包中的起始位置和长度。 | 

**返回：**

返回true表示打开rawfile文件描述符成功，返回false表示rawfile不允许被访问。

**自从：**

8


### OH_ResourceManager_GetRawFileName()

  
```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```

**描述：**

通过索引获取rawfile文件名称。

可以使用此方法遍历rawfile目录。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawDir | 表示指向[RawDir](#rawdir)的指针。 | 
| index | 表示文件在[RawDir](#rawdir)中的索引位置。 | 

**返回：**

通过索引返回文件名称，此返回值可以作为[OH_ResourceManager_OpenRawFile](#ohresourcemanageropenrawfile)的输入参数， 如果遍历完所有文件仍未找到，则返回**NULL**。

**参见：**

[OH_ResourceManager_OpenRawFile](#ohresourcemanageropenrawfile)

**自从：**

8


### OH_ResourceManager_GetRawFileOffset()

  
```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```

**描述：**

获取rawfile当前的offset，单位为int32_t。

rawfile当前的offset。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 

**返回：**

返回rawfile当前的offset。

**自从：**

8


### OH_ResourceManager_GetRawFileSize()

  
```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```

**描述：**

获取rawfile长度，单位为int32_t。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 

**返回：**

Returns rawfile整体长度。

**自从：**

8


### OH_ResourceManager_InitNativeResourceManager()

  
```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```

**描述：**

基于JavaScipt resource manager获取native resource manager。

通过获取resource manager来完成rawfile相关功能。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| env | 表示JavaScipt&nbsp;Native&nbsp;Interface&nbsp;(napi)环境指针。 | 
| jsResMgr | 表示JavaScipt&nbsp;resource&nbsp;manager。 | 

**返回：**

返回[NativeResourceManager](#nativeresourcemanager)指针。

**自从：**

8


### OH_ResourceManager_OpenRawDir()

  
```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```

**描述：**

打开rawfile目录。

打开rawfile目录后，可以遍历对应目录下的rawfile文件。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| mgr | 表示指向[NativeResourceManager](#nativeresourcemanager)的指针，此指针是通过调用&nbsp;[OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)方法获取的。 | 
| dirName | 表示要打开的rawfile目录名称，当传递一个空字符串时表示打开rawfile根目录。 | 

**返回：**

返回[RawDir](#rawdir)指针。使用完此指针后，调用[OH_ResourceManager_CloseRawDir](#ohresourcemanagercloserawdir)释放。

**参见：**

[OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](#ohresourcemanagercloserawdir)

**自从：**

8


### OH_ResourceManager_OpenRawFile()

  
```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```

**描述：**

打开rawfile文件。

当打开rawfile以后，可以读取它的数据。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| mgr | 表示指向[NativeResourceManager](#nativeresourcemanager)的指针，此指针是通过调用&nbsp;[OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)方法获取的。 | 
| fileName | 表示基于rawfile根目录的相对路径下的文件名称。 | 

**返回：**

返回[RawFile](#rawfile)指针。当使用完此指针，调用[OH_ResourceManager_CloseRawFile](#ohresourcemanagercloserawfile)释放。

**参见：**

[OH_ResourceManager_InitNativeResourceManager](#ohresourcemanagerinitnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](#ohresourcemanagercloserawfile)

**自从：**

8


### OH_ResourceManager_ReadRawFile()

  
```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```

**描述：**

读取rawfile。

从当前位置读取**指定长度**的数据。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 
| buf | 用于接收读取数据的缓冲区指针。 | 
| length | 读取数据的字节长度。 | 

**返回：**

返回读取的字节数，如果读取长度超过文件末尾长度，则返回**0**。

**自从：**

8


### OH_ResourceManager_ReleaseNativeResourceManager()

  
```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```

**描述：**

释放native resource manager。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| resMgr | 表示[NativeResourceManager](#nativeresourcemanager)指针。 | 

**自从：**

8


### OH_ResourceManager_ReleaseRawFileDescriptor()

  
```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```

**描述：**

关闭rawfile文件描述符。

已打开的文件描述符在使用完以后必须释放，防止文件描述符泄露。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| descriptor | 包含rawfile文件描述符，以及在HAP包中的起始位置和长度。 | 

**返回：**

返回true表示关闭文件描述符成功，返回false表示关闭文件描述符失败。

**自从：**

8


### OH_ResourceManager_SeekRawFile()

  
```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```

**描述：**

基于指定的offset，在rawfile文件内搜索读写数据的位置。

**参数：**

  | Name | 描述 | 
| -------- | -------- |
| rawFile | 表示指向[RawFile](#rawfile)的指针。 | 
| offset | 表示指定的offset。 | 
| whence | 读写位置，有以下场景:<br/>**0**:&nbsp;读写位置为**offset**<br/>**1**:&nbsp;读写位置为当前位置加上**offset2**:&nbsp;读写位置为文件末尾(EOF)加上**offset**。 | 

**返回：**

如果搜索成功返回新的读写位置，如果发生错误返回 **(long) -1**。

**自从：**

8

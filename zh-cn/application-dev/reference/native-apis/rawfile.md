# Rawfile


## **Overview**

**Description:**

提供操作rawfile目录和rawfile文件的功能

提供操作rawfile目录和rawfile文件功能

功能包括遍历、打开、搜索、读取和关闭rawfile

**Since:**

8

**Version:**

1.0


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [raw_dir.h](raw__dir_8h.md) | 提供rawfile目录相关功能 | 
| [raw_file.h](raw__file_8h.md) | 提供rawfile文件相关功能 | 


### Classes

  | Classe&nbsp;Name | Description | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息 | 


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| RawDir | typedef&nbsp;struct&nbsp;RawDir<br/>提供对rawfile目录的访问 | 
| RawFile | typedef&nbsp;struct&nbsp;RawFile<br/>提供对rawfile的访问功能 | 
| NativeResourceManager | typedef&nbsp;struct&nbsp;NativeResourceManager<br/>代表resource&nbsp;manager | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_ResourceManager_GetRawFileName&nbsp;(RawDir&nbsp;\*rawDir,&nbsp;int&nbsp;index) | const&nbsp;char&nbsp;\*<br/>通过索引获取rawfile文件名称 | 
| OH_ResourceManager_GetRawFileCount&nbsp;(RawDir&nbsp;\*rawDir) | int<br/>获取RawDir中的rawfile数量 | 
| OH_ResourceManager_CloseRawDir&nbsp;(RawDir&nbsp;\*rawDir) | void<br/>关闭已打开的RawDir并释放所有相关联资源 | 
| OH_ResourceManager_ReadRawFile&nbsp;(const&nbsp;RawFile&nbsp;\*rawFile,&nbsp;void&nbsp;\*buf,&nbsp;size_t&nbsp;length) | int<br/>读取rawfile | 
| OH_ResourceManager_SeekRawFile&nbsp;(const&nbsp;RawFile&nbsp;\*rawFile,&nbsp;long&nbsp;offset,&nbsp;int&nbsp;whence) | int<br/>基于指定的offset，在rawfile文件内搜索读写数据的位置 | 
| OH_ResourceManager_GetRawFileSize&nbsp;(RawFile&nbsp;\*rawFile) | long<br/>获取rawfile长度，单位为int32_t | 
| OH_ResourceManager_CloseRawFile&nbsp;(RawFile&nbsp;\*rawFile) | void<br/>关闭已打开的RawFile&nbsp;以及释放所有相关联资源 | 
| OH_ResourceManager_GetRawFileOffset&nbsp;(const&nbsp;RawFile&nbsp;\*rawFile) | long<br/>获取rawfile当前的offset，单位为int32_t | 
| OH_ResourceManager_GetRawFileDescriptor&nbsp;(const&nbsp;RawFile&nbsp;\*rawFile,&nbsp;RawFileDescriptor&nbsp;&amp;descriptor) | bool<br/>基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符 | 
| OH_ResourceManager_ReleaseRawFileDescriptor&nbsp;(const&nbsp;RawFileDescriptor&nbsp;&amp;descriptor) | bool<br/>关闭rawfile文件描述符 | 
| OH_ResourceManager_InitNativeResourceManager&nbsp;(napi_env&nbsp;env,&nbsp;napi_value&nbsp;jsResMgr) | NativeResourceManager&nbsp;\*<br/>基于JavaScipt&nbsp;resource&nbsp;manager获取native&nbsp;resource&nbsp;manager | 
| OH_ResourceManager_ReleaseNativeResourceManager&nbsp;(NativeResourceManager&nbsp;\*resMgr) | void<br/>释放native&nbsp;resource&nbsp;manager | 
| OH_ResourceManager_OpenRawDir&nbsp;(const&nbsp;NativeResourceManager&nbsp;\*mgr,&nbsp;const&nbsp;char&nbsp;\*dirName) | RawDir&nbsp;\*<br/>打开rawfile目录 | 
| OH_ResourceManager_OpenRawFile&nbsp;(const&nbsp;NativeResourceManager&nbsp;\*mgr,&nbsp;const&nbsp;char&nbsp;\*fileName) | RawFile&nbsp;\*<br/>打开rawfile文件 | 


## **Details**


## **Typedef**


### NativeResourceManager

  
```
typedef struct NativeResourceManager NativeResourceManager
```

**Description:**

代表resource manager

此类封装了JavaScript resource manager的native实现 **ResourceManager**指针可以通过调用OH_ResourceManager_InitNativeResourceManager方法获取


### RawDir

  
```
typedef struct RawDir RawDir
```

**Description:**

提供对rawfile目录的访问


### RawFile

  
```
typedef struct RawFile RawFile
```

**Description:**

提供对rawfile的访问功能


## **Function**


### OH_ResourceManager_CloseRawDir()

  
```
void OH_ResourceManager_CloseRawDir (RawDir * rawDir)
```

**Description:**

关闭已打开的RawDir并释放所有相关联资源

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawDir | 表示指向RawDir的指针 | 

**See also:**

OH_ResourceManager_OpenRawDir


### OH_ResourceManager_CloseRawFile()

  
```
void OH_ResourceManager_CloseRawFile (RawFile * rawFile)
```

**Description:**

关闭已打开的RawFile 以及释放所有相关联资源

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 

**See also:**

OH_ResourceManager_OpenRawFile


### OH_ResourceManager_GetRawFileCount()

  
```
int OH_ResourceManager_GetRawFileCount (RawDir * rawDir)
```

**Description:**

获取RawDir中的rawfile数量

通过此方法可以获取OH_ResourceManager_GetRawFileName中可用的索引

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawDir | 表示指向RawDir的指针 | 

**See also:**

OH_ResourceManager_GetRawFileName


### OH_ResourceManager_GetRawFileDescriptor()

  
```
bool OH_ResourceManager_GetRawFileDescriptor (const RawFile * rawFile, RawFileDescriptor & descriptor )
```

**Description:**

基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符

打开的文件描述符被用于读取rawfile

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 
| descriptor | 显示rawfile文件描述符，以及在HAP包中的起始位置和长度 | 

**Returns:**

返回true表示打开rawfile文件描述符成功，返回false表示rawfile不允许被访问


### OH_ResourceManager_GetRawFileName()

  
```
const char* OH_ResourceManager_GetRawFileName (RawDir * rawDir, int index )
```

**Description:**

通过索引获取rawfile文件名称

可以使用此方法遍历rawfile目录

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawDir | 表示指向RawDir的指针 | 
| index | 表示文件在RawDir中的索引位置 | 

**Returns:**

通过索引返回文件名称，此返回值可以作为OH_ResourceManager_OpenRawFile的输入参数， 如果遍历完所有文件仍未找到，则返回**NULL**

**See also:**

OH_ResourceManager_OpenRawFile


### OH_ResourceManager_GetRawFileOffset()

  
```
long OH_ResourceManager_GetRawFileOffset (const RawFile * rawFile)
```

**Description:**

获取rawfile当前的offset，单位为int32_t

rawfile当前的offset

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 

**Returns:**

返回rawfile当前的offset


### OH_ResourceManager_GetRawFileSize()

  
```
long OH_ResourceManager_GetRawFileSize (RawFile * rawFile)
```

**Description:**

获取rawfile长度，单位为int32_t

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 

**Returns:**

Returns rawfile整体长度


### OH_ResourceManager_InitNativeResourceManager()

  
```
NativeResourceManager* OH_ResourceManager_InitNativeResourceManager (napi_env env, napi_value jsResMgr )
```

**Description:**

基于JavaScipt resource manager获取native resource manager

通过获取resource manager来完成rawfile相关功能

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| env | 表示JavaScipt&nbsp;Native&nbsp;Interface&nbsp;(napi)环境指针 | 
| jsResMgr | 表示JavaScipt&nbsp;resource&nbsp;manager | 

**Returns:**

返回NativeResourceManager指针


### OH_ResourceManager_OpenRawDir()

  
```
RawDir* OH_ResourceManager_OpenRawDir (const NativeResourceManager * mgr, const char * dirName )
```

**Description:**

打开rawfile目录

打开rawfile目录后，可以遍历对应目录下的rawfile文件

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| mgr | 表示指向NativeResourceManager的指针，此指针是通过调用&nbsp;OH_ResourceManager_InitNativeResourceManager方法获取的 | 
| dirName | 表示要打开的rawfile目录名称，当传递一个空字符串时表示打开rawfile根目录 | 

**Returns:**

返回RawDir指针。使用完此指针后，调用OH_ResourceManager_CloseRawDir释放。

**See also:**

OH_ResourceManager_InitNativeResourceManager

OH_ResourceManager_CloseRawDir


### OH_ResourceManager_OpenRawFile()

  
```
RawFile* OH_ResourceManager_OpenRawFile (const NativeResourceManager * mgr, const char * fileName )
```

**Description:**

打开rawfile文件

当打开rawfile以后，可以读取它的数据

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| mgr | 表示指向NativeResourceManager的指针，此指针是通过调用&nbsp;OH_ResourceManager_InitNativeResourceManager方法获取的 | 
| fileName | 表示基于rawfile根目录的相对路径下的文件名称 | 

**Returns:**

返回RawFile指针。当使用完此指针，调用OH_ResourceManager_CloseRawFile释放。

**See also:**

OH_ResourceManager_InitNativeResourceManager

OH_ResourceManager_CloseRawFile


### OH_ResourceManager_ReadRawFile()

  
```
int OH_ResourceManager_ReadRawFile (const RawFile * rawFile, void * buf, size_t length )
```

**Description:**

读取rawfile

从当前位置读取**指定长度**的数据

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 
| buf | 用于接收读取数据的缓冲区指针 | 
| length | 读取数据的字节长度 | 

**Returns:**

返回读取的字节数，如果读取长度超过文件末尾长度，则返回**0**


### OH_ResourceManager_ReleaseNativeResourceManager()

  
```
void OH_ResourceManager_ReleaseNativeResourceManager (NativeResourceManager * resMgr)
```

**Description:**

释放native resource manager

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| resMgr | 表示NativeResourceManager指针 | 


### OH_ResourceManager_ReleaseRawFileDescriptor()

  
```
bool OH_ResourceManager_ReleaseRawFileDescriptor (const RawFileDescriptor & descriptor)
```

**Description:**

关闭rawfile文件描述符

已打开的文件描述符在使用完以后必须释放，防止文件描述符泄露

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| descriptor | 包含rawfile文件描述符，以及在HAP包中的起始位置和长度 | 

**Returns:**

返回true表示关闭文件描述符成功，返回false表示关闭文件描述符失败


### OH_ResourceManager_SeekRawFile()

  
```
int OH_ResourceManager_SeekRawFile (const RawFile * rawFile, long offset, int whence )
```

**Description:**

基于指定的offset，在rawfile文件内搜索读写数据的位置

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| rawFile | 表示指向RawFile的指针 | 
| offset | 表示指定的offset | 
| whence | 读写位置，有以下场景:&nbsp;**0**:&nbsp;读写位置为**offset1**:&nbsp;读写位置为当前位置加上**offset2**:&nbsp;读写位置为文件末尾(EOF)加上**offset** | 

**Returns:**

如果搜索成功返回新的读写位置，如果发生错误返回 **(long) -1**

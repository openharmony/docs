# raw_file.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 概述

提供操作rawfile文件的能力，包括读取文件、获取文件长度、获取偏移位置、调整偏移位置、获取文件描述符，以及关闭文件描述符等。

**引用文件：** <rawfile/raw_file.h>

**库：** librawfile.z.so

**系统能力：** SystemCapability.Global.ResourceManager

**起始版本：** 8

**相关模块：** [rawfile](capi-rawfile.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [RawFileDescriptor](capi-rawfile-rawfiledescriptor.md) | RawFileDescriptor | 提供rawfile文件描述符信息，包含rawfile的文件描述符、在HAP包中的起始位置和文件长度。<br>通过[OH_ResourceManager_GetRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptordata)获取，使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptordata)释放文件描述符资源。 |
| [RawFileDescriptor64](capi-rawfile-rawfiledescriptor64.md) | RawFileDescriptor64 | 提供rawfile文件描述符信息，包含rawfile的文件描述符、在HAP包中的起始位置和文件长度。支持2GB以上的大文件。<br>通过[OH_ResourceManager_GetRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor64)获取，使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptor64)释放文件描述符资源。 |
| [RawFile64](capi-rawfile-rawfile64.md) | RawFile64 | RawFile64表示一个已打开的rawfile对象，用于访问2GB及以上的大文件。通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)函数获取，使用完后须调用[OH_ResourceManager_CloseRawFile64](capi-raw-file-h.md#oh_resourcemanager_closerawfile64)关闭并释放。 |
| [RawFile](capi-rawfile-rawfile.md) | RawFile | RawFile表示一个已打开的rawfile对象。通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)函数获取，使用完后须调用[OH_ResourceManager_CloseRawFile](capi-raw-file-h.md#oh_resourcemanager_closerawfile)关闭并释放。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int OH_ResourceManager_ReadRawFile(const RawFile *rawFile, void *buf, size_t length)](#oh_resourcemanager_readrawfile) | 从rawfile文件当前偏移位置读取指定长度的数据，同时偏移位置会跟随指定长度向后移动。如当前偏移位置为[0]，指定长度为10，读取数据后迁移位置为[10]。 |
| [int OH_ResourceManager_SeekRawFile(const RawFile *rawFile, long offset, int whence)](#oh_resourcemanager_seekrawfile) | 基于指定的偏移量和偏移方式，调整rawfile文件的偏移位置。 |
| [long OH_ResourceManager_GetRawFileSize(RawFile *rawFile)](#oh_resourcemanager_getrawfilesize) | 获取rawfile文件长度，单位为Byte。 |
| [long OH_ResourceManager_GetRawFileRemainingLength(const RawFile *rawFile)](#oh_resourcemanager_getrawfileremaininglength) | 获取rawfile文件从当前偏移位置到文件末尾的剩余长度，单位为Byte。 |
| [void OH_ResourceManager_CloseRawFile(RawFile *rawFile)](#oh_resourcemanager_closerawfile) | 关闭已打开的RawFile对象并释放所有相关资源。 |
| [long OH_ResourceManager_GetRawFileOffset(const RawFile *rawFile)](#oh_resourcemanager_getrawfileoffset) | 获取rawfile文件当前的偏移位置，单位为Byte。可用于在分段读取过程中跟踪进度，或在调整偏移位置后确认当前偏移位置。 |
| [bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor)](#oh_resourcemanager_getrawfiledescriptor) | 获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。(API12废弃) |
| [bool OH_ResourceManager_GetRawFileDescriptorData(const RawFile *rawFile, RawFileDescriptor *descriptor)](#oh_resourcemanager_getrawfiledescriptordata) | 获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。 |
| [bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor)](#oh_resourcemanager_releaserawfiledescriptor) | 释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。(API12废弃) |
| [bool OH_ResourceManager_ReleaseRawFileDescriptorData(const RawFileDescriptor *descriptor)](#oh_resourcemanager_releaserawfiledescriptordata) | 释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。 |
| [int64_t OH_ResourceManager_ReadRawFile64(const RawFile64 *rawFile, void *buf, int64_t length)](#oh_resourcemanager_readrawfile64) | 从rawfile文件当前偏移位置读取指定长度的数据，同时偏移位置会跟随指定长度向后移动。如当前偏移位置为[0]，指定长度为10，读取数据后迁移位置为[10]。<br> 支持2GB以上的大文件。 |
| [int OH_ResourceManager_SeekRawFile64(const RawFile64 *rawFile, int64_t offset, int whence)](#oh_resourcemanager_seekrawfile64) | 基于指定的偏移量和偏移方式，调整rawfile文件的偏移位置。支持2GB以上的大文件。 |
| [int64_t OH_ResourceManager_GetRawFileSize64(RawFile64 *rawFile)](#oh_resourcemanager_getrawfilesize64) | 获取rawfile文件长度，单位为Byte。支持2GB以上的大文件。 |
| [int64_t OH_ResourceManager_GetRawFileRemainingLength64(const RawFile64 *rawFile)](#oh_resourcemanager_getrawfileremaininglength64) | 获取rawfile文件从当前偏移位置到文件末尾的剩余长度，单位为Byte。支持2GB以上的大文件。 |
| [void OH_ResourceManager_CloseRawFile64(RawFile64 *rawFile)](#oh_resourcemanager_closerawfile64) | 关闭已打开的RawFile64对象并释放所有相关资源。 |
| [int64_t OH_ResourceManager_GetRawFileOffset64(const RawFile64 *rawFile)](#oh_resourcemanager_getrawfileoffset64) | 获取rawfile文件当前的偏移位置，单位为Byte。可用于在分段读取过程中跟踪进度，或在调整偏移位置后确认当前偏移位置。<br> 支持2GB以上的大文件。 |
| [bool OH_ResourceManager_GetRawFileDescriptor64(const RawFile64 *rawFile, RawFileDescriptor64 *descriptor)](#oh_resourcemanager_getrawfiledescriptor64) | 获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。支持2GB以上的大文件。 |
| [bool OH_ResourceManager_ReleaseRawFileDescriptor64(const RawFileDescriptor64 *descriptor)](#oh_resourcemanager_releaserawfiledescriptor64) | 释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。 |

## 函数说明

### OH_ResourceManager_ReadRawFile()

```c
int OH_ResourceManager_ReadRawFile(const RawFile *rawFile, void *buf, size_t length)
```

**描述**

从rawfile文件当前偏移位置读取指定长度的数据，同时偏移位置会跟随指定长度向后移动。如当前偏移位置为[0]，指定长度为10，读取数据后迁移位置为[10]。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |
| void *buf | 输出参数。指向接收读取数据的缓冲区的指针，由开发者自行分配内存，使用完后需自行释放。 |
| size_t length | 输入参数。期望读取的数据长度，单位为Byte。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回已读取的数据长度。若文件已读完，无数据可读时，或rawFile为NULL，返回0。 |

### OH_ResourceManager_SeekRawFile()

```c
int OH_ResourceManager_SeekRawFile(const RawFile *rawFile, long offset, int whence)
```

**描述**

基于指定的偏移量和偏移方式，调整rawfile文件的偏移位置。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |
| long offset | 输入参数。指定的偏移量，取值为整数，正数表示向后偏移，负数表示向前偏移。单位为Byte。 |
| int whence | 输入参数。偏移方式，取值包括0、1、2。<br>     0：从文件开头计算偏移位置。<br>     1：从当前位置计算偏移位置。<br>     2：从文件末尾计算偏移位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回定位结果。<br>     返回0，表示成功，文件的偏移位置移动到指定位置。<br>     返回-1，表示失败，文件的偏移位置不变。可能原因是rawFile为NULL、offset超出文件范围或whence值无效。 |

### OH_ResourceManager_GetRawFileSize()

```c
long OH_ResourceManager_GetRawFileSize(RawFile *rawFile)
```

**描述**

获取rawfile文件长度，单位为Byte。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| long | 返回rawfile文件长度。若rawFile为NULL，则返回0。 |

### OH_ResourceManager_GetRawFileRemainingLength()

```c
long OH_ResourceManager_GetRawFileRemainingLength(const RawFile *rawFile)
```

**描述**

获取rawfile文件从当前偏移位置到文件末尾的剩余长度，单位为Byte。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| long | 返回rawfile文件的剩余长度。若rawFile为NULL，则返回0。 |

### OH_ResourceManager_CloseRawFile()

```c
void OH_ResourceManager_CloseRawFile(RawFile *rawFile)
```

**描述**

关闭已打开的RawFile对象并释放所有相关资源。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。释放后该指针失效，不可再用于其他操作。 |

**参考：**

[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileOffset()

```c
long OH_ResourceManager_GetRawFileOffset(const RawFile *rawFile)
```

**描述**

获取rawfile文件当前的偏移位置，单位为Byte。可用于在分段读取过程中跟踪进度，或在调整偏移位置后确认当前偏移位置。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| long | 返回rawfile当前的偏移位置，若rawFile为NULL，则返回0。 |

### OH_ResourceManager_GetRawFileDescriptor()

```c
bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor)
```

**描述**

获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。

**起始版本：** 8

**废弃版本：** 12

**替代接口：** [OH_ResourceManager_GetRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptordata)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |
| descriptor | 输出参数。指向[RawFileDescriptor](capi-rawfile-rawfiledescriptor.md)对象的引用，用于返回文件描述符信息。使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptor](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptor)释放文件描述符，防止文件描述符泄露。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回获取结果。true表示获取成功。false表示获取失败，可能原因是rawFile为NULL、descriptor为NULL或rawfile文件访问被拒绝。 |

### OH_ResourceManager_GetRawFileDescriptorData()

```c
bool OH_ResourceManager_GetRawFileDescriptorData(const RawFile *rawFile, RawFileDescriptor *descriptor)
```

**描述**

获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile](capi-rawfile-rawfile.md) *rawFile | 输入参数。指向RawFile对象的指针，通过[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)获取。 |
| [RawFileDescriptor](capi-rawfile-rawfiledescriptor.md) *descriptor | 输出参数。指向RawFileDescriptor对象的指针，用于返回文件描述符信息。使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptordata)释放文件描述符，防止文件描述符泄露。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回获取结果。true表示获取成功。false表示获取失败，可能原因是rawFile为NULL、descriptor为NULL或rawfile文件访问被拒绝。 |

### OH_ResourceManager_ReleaseRawFileDescriptor()

```c
bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor)
```

**描述**

释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。

**起始版本：** 8

**废弃版本：** 12

**替代接口：** [OH_ResourceManager_ReleaseRawFileDescriptorData](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptordata)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| descriptor | 输入参数。指向要释放的[RawFileDescriptor](capi-rawfile-rawfiledescriptor.md)对象的引用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回释放结果。true表示释放成功，false表示释放失败，可能原因是descriptor为NULL或文件描述符已释放。 |

### OH_ResourceManager_ReleaseRawFileDescriptorData()

```c
bool OH_ResourceManager_ReleaseRawFileDescriptorData(const RawFileDescriptor *descriptor)
```

**描述**

释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFileDescriptor](capi-rawfile-rawfiledescriptor.md) *descriptor | 输入参数。指向要释放的[RawFileDescriptor](capi-rawfile-rawfiledescriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回释放结果。true表示释放成功，false表示释放失败，可能原因是descriptor为NULL或文件描述符已释放。 |

### OH_ResourceManager_ReadRawFile64()

```c
int64_t OH_ResourceManager_ReadRawFile64(const RawFile64 *rawFile, void *buf, int64_t length)
```

**描述**

从rawfile文件当前偏移位置读取指定长度的数据，同时偏移位置会跟随指定长度向后移动。如当前偏移位置为[0]，指定长度为10，读取数据后迁移位置为[10]。<br> 支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |
| void *buf | 输出参数。指向接收读取数据的缓冲区的指针，由开发者自行分配内存，使用完后需自行释放。 |
| int64_t length | 输入参数。期望读取的数据长度，单位为Byte。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回已读取的数据长度。若文件已读完，无数据可读时，或rawFile为NULL，返回0。 |

### OH_ResourceManager_SeekRawFile64()

```c
int OH_ResourceManager_SeekRawFile64(const RawFile64 *rawFile, int64_t offset, int whence)
```

**描述**

基于指定的偏移量和偏移方式，调整rawfile文件的偏移位置。支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |
| int64_t offset | 输入参数。指定的偏移量，取值为整数，正数表示向后偏移，负数表示向前偏移。单位为Byte。 |
| int whence | 输入参数。偏移方式，取值包括0、1、2。<br>     0：从文件开头计算偏移位置。<br>     1：从当前位置计算偏移位置。<br>     2：从文件末尾计算偏移位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回定位结果。<br>     返回0，表示成功，文件的偏移位置移动到指定位置。<br>     返回-1，表示失败，文件的偏移位置不变。可能原因是rawFile为NULL、offset超出文件范围或whence值无效。 |

### OH_ResourceManager_GetRawFileSize64()

```c
int64_t OH_ResourceManager_GetRawFileSize64(RawFile64 *rawFile)
```

**描述**

获取rawfile文件长度，单位为Byte。支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回rawfile文件长度。若rawFile为NULL，则返回0。 |

### OH_ResourceManager_GetRawFileRemainingLength64()

```c
int64_t OH_ResourceManager_GetRawFileRemainingLength64(const RawFile64 *rawFile)
```

**描述**

获取rawfile文件从当前偏移位置到文件末尾的剩余长度，单位为Byte。支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回rawfile文件的剩余长度。若rawFile为NULL，则返回0。 |

### OH_ResourceManager_CloseRawFile64()

```c
void OH_ResourceManager_CloseRawFile64(RawFile64 *rawFile)
```

**描述**

关闭已打开的RawFile64对象并释放所有相关资源。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。释放后该指针失效，不可再用于其他操作。 |

**参考：**

[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)


### OH_ResourceManager_GetRawFileOffset64()

```c
int64_t OH_ResourceManager_GetRawFileOffset64(const RawFile64 *rawFile)
```

**描述**

获取rawfile文件当前的偏移位置，单位为Byte。可用于在分段读取过程中跟踪进度，或在调整偏移位置后确认当前偏移位置。<br> 支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回rawfile当前的偏移位置，若rawFile为NULL，则返回0。 |

### OH_ResourceManager_GetRawFileDescriptor64()

```c
bool OH_ResourceManager_GetRawFileDescriptor64(const RawFile64 *rawFile, RawFileDescriptor64 *descriptor)
```

**描述**

获取rawfile文件描述符信息。获取文件描述符信息后，开发者可调用pread等函数读取rawfile文件。支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFile64](capi-rawfile-rawfile64.md) *rawFile | 输入参数。指向RawFile64对象的指针，通过[OH_ResourceManager_OpenRawFile64](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile64)获取。 |
| [RawFileDescriptor64](capi-rawfile-rawfiledescriptor64.md) *descriptor | 输出参数。指向RawFileDescriptor64对象的指针，用于返回文件描述符信息。使用完后须调用[OH_ResourceManager_ReleaseRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_releaserawfiledescriptor64)释放文件描述符，防止文件描述符泄露。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回获取结果。true表示获取成功。false表示获取失败，可能原因是rawFile为NULL、descriptor为NULL或rawfile文件访问被拒绝。 |

### OH_ResourceManager_ReleaseRawFileDescriptor64()

```c
bool OH_ResourceManager_ReleaseRawFileDescriptor64(const RawFileDescriptor64 *descriptor)
```

**描述**

释放rawfile文件描述符资源。释放成功后，descriptor中的fd失效，不可再使用。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const RawFileDescriptor64](capi-rawfile-rawfiledescriptor64.md) *descriptor | 输入参数。指向要释放的RawFileDescriptor64对象的指针，通过[OH_ResourceManager_GetRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor64)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回释放结果。true表示释放成功，false表示释放失败，可能原因是descriptor为NULL或文件描述符已释放。 |



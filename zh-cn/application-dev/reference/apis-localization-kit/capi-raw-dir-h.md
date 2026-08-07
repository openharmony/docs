# raw_dir.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 概述

提供rawfile目录操作相关的函数，包括遍历目录、获取文件数量、获取文件名称、关闭目录等功能。

**引用文件：** <rawfile/raw_dir.h>

**库：** librawfile.z.so

**系统能力：** SystemCapability.Global.ResourceManager

**起始版本：** 8

**相关模块：** [rawfile](capi-rawfile.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [RawDir](capi-rawfile-rawdir.md) | RawDir | RawDir表示一个已打开的rawfile目录对象，可用于遍历目录和目录下文件。通过[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)函数获取，使用完后须调用[OH_ResourceManager_CloseRawDir](capi-raw-dir-h.md#oh_resourcemanager_closerawdir)关闭并释放。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [const char *OH_ResourceManager_GetRawFileName(RawDir *rawDir, int index)](#oh_resourcemanager_getrawfilename) | 通过索引获取rawfile目录中的文件名称。当需要遍历rawfile目录时，可以与[OH_ResourceManager_GetRawFileCount](capi-raw-dir-h.md#oh_resourcemanager_getrawfilecount)搭配使用，通过循环遍历目录。 |
| [int OH_ResourceManager_GetRawFileCount(RawDir *rawDir)](#oh_resourcemanager_getrawfilecount) | 获取rawfile下子目录和文件数量。当需要遍历rawfile目录时，可以与[OH_ResourceManager_GetRawFileName](capi-raw-dir-h.md#oh_resourcemanager_getrawfilename)搭配使用，通过循环遍历目录。 |
| [void OH_ResourceManager_CloseRawDir(RawDir *rawDir)](#oh_resourcemanager_closerawdir) | 关闭已打开的RawDir对象并释放所有相关资源。遍历rawfile目录后，须调用此函数关闭目录和释放资源。 |

## 函数说明

### OH_ResourceManager_GetRawFileName()

```c
const char *OH_ResourceManager_GetRawFileName(RawDir *rawDir, int index)
```

**描述**

通过索引获取rawfile目录中的文件名称。当需要遍历rawfile目录时，可以与[OH_ResourceManager_GetRawFileCount](capi-raw-dir-h.md#oh_resourcemanager_getrawfilecount)搭配使用，通过循环遍历目录。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawDir](capi-rawfile-rawdir.md) *rawDir | 输入参数。指向RawDir对象的指针，通过[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)获取。 |
| int index | 输入参数。文件在rawfile目录中的索引，取值范围为[0, 文件总数量-1]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回文件名称字符串指针，可作为[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)的输入参数。<br>     失败时返回NULL，可能原因是rawDir为NULL、index超出有效范围或目录为空。<br>     调用[OH_ResourceManager_CloseRawDir](capi-raw-dir-h.md#oh_resourcemanager_closerawdir)后，该指针同时会被释放，若需保存文件名，开发者需及时复制字符串内容。 |

**参考：**

[OH_ResourceManager_OpenRawFile](capi-raw-file-manager-h.md#oh_resourcemanager_openrawfile)


### OH_ResourceManager_GetRawFileCount()

```c
int OH_ResourceManager_GetRawFileCount(RawDir *rawDir)
```

**描述**

获取rawfile下子目录和文件数量。当需要遍历rawfile目录时，可以与[OH_ResourceManager_GetRawFileName](capi-raw-dir-h.md#oh_resourcemanager_getrawfilename)搭配使用，通过循环遍历目录。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawDir](capi-rawfile-rawdir.md) *rawDir | 输入参数。指向RawDir对象的指针，通过[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回rawfile子目录和文件数量，不递归统计rawfile子目录下的文件和目录数量。若rawDir为NULL或目录为空，则返回0。 |

**参考：**

[OH_ResourceManager_GetRawFileName](capi-raw-dir-h.md#oh_resourcemanager_getrawfilename)


### OH_ResourceManager_CloseRawDir()

```c
void OH_ResourceManager_CloseRawDir(RawDir *rawDir)
```

**描述**

关闭已打开的RawDir对象并释放所有相关资源。遍历rawfile目录后，须调用此函数关闭目录和释放资源。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawDir](capi-rawfile-rawdir.md) *rawDir | 输入参数。指向RawDir对象的指针，通过[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)获取。关闭后，该指针失效，不可再用于其他操作。 |

**参考：**

[OH_ResourceManager_OpenRawDir](capi-raw-file-manager-h.md#oh_resourcemanager_openrawdir)



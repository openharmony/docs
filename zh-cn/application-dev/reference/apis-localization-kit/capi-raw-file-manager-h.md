# raw_file_manager.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 概述

通过本模块可以创建、释放NativeResourceManager对象，以及打开rawfile文件和目录。

**引用文件：** <rawfile/raw_file_manager.h>

**库：** librawfile.z.so

**系统能力：** SystemCapability.Global.ResourceManager

**起始版本：** 8

**相关模块：** [rawfile](capi-rawfile.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) | NativeResourceManager | 表示Native层的ResourceManager对象。NativeResourceManager对JavaScript ResourceManager的Native实现进行封装，可以通过[OH_ResourceManager_InitNativeResourceManager](#oh_resourcemanager_initnativeresourcemanager)函数获取。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr)](#oh_resourcemanager_initnativeresourcemanager) | 初始化NativeResourceManager对象。<br> |
| [void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr)](#oh_resourcemanager_releasenativeresourcemanager) | 释放NativeResourceManager对象及其关联资源。 |
| [RawDir *OH_ResourceManager_OpenRawDir(const NativeResourceManager *mgr, const char *dirName)](#oh_resourcemanager_openrawdir) | 打开rawfile目录。 |
| [RawFile *OH_ResourceManager_OpenRawFile(const NativeResourceManager *mgr, const char *fileName)](#oh_resourcemanager_openrawfile) | 打开rawfile文件并返回RawFile对象，用于读取rawfile文件内容。 |
| [RawFile64 *OH_ResourceManager_OpenRawFile64(const NativeResourceManager *mgr, const char *fileName)](#oh_resourcemanager_openrawfile64) | 打开rawfile文件并返回RawFile对象，用于读取rawfile文件内容。支持2GB以上的大文件。 |
| [bool OH_ResourceManager_IsRawDir(const NativeResourceManager *mgr, const char *path)](#oh_resourcemanager_israwdir) | 判断指定路径是否为rawfile的子目录。用于在遍历目录前，判断对应路径是否为目录，或在打开文件前，判断对应路径是否为文件。 |

## 函数说明

### OH_ResourceManager_InitNativeResourceManager()

```c
NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr)
```

**描述**

初始化NativeResourceManager对象。<br>

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 输入参数。指向JavaScript Native Interface（napi）环境的指针。 |
| napi_value jsResMgr | 输入参数。表示JavaScript ResourceManager对象的引用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NativeResourceManager *](capi-rawfile-nativeresourcemanager.md) | 返回NativeResourceManager对象的指针。若初始化失败，返回NULL，可能原因为参数env或jsResMgr无效。<br>     该指针由此函数分配内存，使用完后须调用[OH_ResourceManager_ReleaseNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_releasenativeresourcemanager)释放。 |

### OH_ResourceManager_ReleaseNativeResourceManager()

```c
void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr)
```

**描述**

释放NativeResourceManager对象及其关联资源。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *resMgr | 输入参数。指向要释放的NativeResourceManager对象的指针。释放后resMgr指针失效，不可用于其他操作。 |

### OH_ResourceManager_OpenRawDir()

```c
RawDir *OH_ResourceManager_OpenRawDir(const NativeResourceManager *mgr, const char *dirName)
```

**描述**

打开rawfile目录。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 输入参数。指向NativeResourceManager对象的指针。 |
| const char *dirName | 输入参数。待打开的目录路径。相对于rawfile根目录的路径，例如"images/icons"。当为空字符串时表示打开rawfile根目录。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [RawDir *](capi-rawfile-rawdir.md) | 返回指向RawDir对象的指针。若调用失败或mgr为空，则返回NULL。使用完后须调用[OH_ResourceManager_CloseRawDir](capi-raw-dir-h.md#oh_resourcemanager_closerawdir)释放。 |

**参考：**

[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawDir](capi-raw-dir-h.md#oh_resourcemanager_closerawdir)

### OH_ResourceManager_OpenRawFile()

```c
RawFile *OH_ResourceManager_OpenRawFile(const NativeResourceManager *mgr, const char *fileName)
```

**描述**

打开rawfile文件并返回RawFile对象，用于读取rawfile文件内容。

**起始版本：** 8

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 输入参数。指向NativeResourceManager对象的指针。 |
| const char *fileName | 输入参数。待打开的文件路径。相对于rawfile根目录的路径，例如"images/icons/1.png"。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [RawFile *](capi-rawfile-rawfile.md) | 返回指向RawFile对象的指针。若调用失败或输入参数为空，则返回NULL。使用完后须调用[OH_ResourceManager_CloseRawFile](capi-raw-file-h.md#oh_resourcemanager_closerawfile)释放。 |

**参考：**

[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile](capi-raw-file-h.md#oh_resourcemanager_closerawfile)

### OH_ResourceManager_OpenRawFile64()

```c
RawFile64 *OH_ResourceManager_OpenRawFile64(const NativeResourceManager *mgr, const char *fileName)
```

**描述**

打开rawfile文件并返回RawFile对象，用于读取rawfile文件内容。支持2GB以上的大文件。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 输入参数。指向NativeResourceManager对象的指针。 |
| const char *fileName | 输入参数。待打开的文件路径。相对于rawfile根目录的路径，例如"images/icons/1.png"。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [RawFile64 *](capi-rawfile-rawfile64.md) | 返回指向RawFile对象的指针。若调用失败或输入参数为空，则返回NULL。使用完后须调用[OH_ResourceManager_CloseRawFile64](capi-raw-file-h.md#oh_resourcemanager_closerawfile64)释放。 |

**参考：**

[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)

[OH_ResourceManager_CloseRawFile64](capi-raw-file-h.md#oh_resourcemanager_closerawfile64)

### OH_ResourceManager_IsRawDir()

```c
bool OH_ResourceManager_IsRawDir(const NativeResourceManager *mgr, const char *path)
```

**描述**

判断指定路径是否为rawfile的子目录。用于在遍历目录前，判断对应路径是否为目录，或在打开文件前，判断对应路径是否为文件。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 输入参数。指向NativeResourceManager对象的指针。 |
| const char *path | 待判断的路径。相对于rawfile根目录的路径，如"images/icons"。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示是rawfile下的目录，返回false表示不是rawfile下的目录。 |



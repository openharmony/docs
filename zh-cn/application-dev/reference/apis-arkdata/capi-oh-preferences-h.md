# oh_preferences.h

## 概述

提供访问Preferences对象的接口与数据结构。

**引用文件：** <database/preferences/oh_preferences.h>

**库：** libohpreferences.so

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13

**相关模块：** [Preferences](capi-preferences.md)

## 汇总

### 结构体

| 名称                                     | typedef关键字  | 描述                      |
| ---------------------------------------- | -------------- | ------------------------- |
| [OH_Preferences](capi-preferences-oh-preferences.md) | OH_Preferences | 定义Preferences对象类型。 |

### 函数

| 名称                                                         | typedef关键字              | 描述                                                         |
| ------------------------------------------------------------ | -------------------------- | ------------------------------------------------------------ |
| [typedef void (\*OH_PreferencesDataObserver)(void *context, const OH_PreferencesPair *pairs, uint32_t count)](#oh_preferencesdataobserver) | OH_PreferencesDataObserver | 定义数据变更触发的回调函数类型。                             |
| [OH_Preferences *OH_Preferences_Open(OH_PreferencesOption *option, int *errCode)](#oh_preferences_open) | -                          | 打开一个Preferences实例对象并创建指向它的指针。<br>当不再需要使用指针时，请使用[OH_Preferences_Close](capi-oh-preferences-h.md#oh_preferences_close)关闭实例对象。 |
| [int OH_Preferences_Close(OH_Preferences *preference)](#oh_preferences_close) | -                          | 关闭一个Preferences实例对象。                                |
| [int OH_Preferences_GetInt(OH_Preferences *preference, const char *key, int *value)](#oh_preferences_getint) | -                          | 获取Preferences实例对象中Key对应的整型值。                   |
| [int OH_Preferences_GetBool(OH_Preferences *preference, const char *key, bool *value)](#oh_preferences_getbool) | -                          | 获取Preferences实例对象中Key对应的布尔值。                   |
| [int OH_Preferences_GetString(OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen)](#oh_preferences_getstring) | -                          | 获取Preferences实例对象中Key对应的字符串。                   |
| [void OH_Preferences_FreeString(char *string)](#oh_preferences_freestring) | -                          | 释放从Preferences实例对象中获取的字符串。                    |
| [int OH_Preferences_SetInt(OH_Preferences *preference, const char *key, int value)](#oh_preferences_setint) | -                          | 根据Key设置Preferences实例对象中的整型值。                   |
| [int OH_Preferences_SetBool(OH_Preferences *preference, const char *key, bool value)](#oh_preferences_setbool) | -                          | 根据Key设置Preferences实例对象中的布尔值。                   |
| [int OH_Preferences_SetString(OH_Preferences *preference, const char *key, const char *value)](#oh_preferences_setstring) | -                          | 根据Key设置Preferences实例对象中的字符串。                   |
| [int OH_Preferences_Delete(OH_Preferences *preference, const char *key)](#oh_preferences_delete) | -                          | 在Preferences实例对象中删除Key对应的KV数据。                 |
| [int OH_Preferences_RegisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)](#oh_preferences_registerdataobserver) | -                          | 对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。 |
| [int OH_Preferences_UnregisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)](#oh_preferences_unregisterdataobserver) | -                          | 取消注册选取Key的数据变更订阅。                              |
| [int OH_Preferences_IsStorageTypeSupported(Preferences_StorageType type, bool *isSupported)](#oh_preferences_isstoragetypesupported) | -                          | 校验当前平台是否支持对应存储模式。                           |

## 函数说明

### OH_PreferencesDataObserver()

```
typedef void (*OH_PreferencesDataObserver)(void *context, const OH_PreferencesPair *pairs, uint32_t count)
```

**描述**

定义数据变更触发的回调函数类型。

**起始版本：** 13


**参数：**

| 参数项                                                       | 描述                     |
| ------------------------------------------------------------ | ------------------------ |
| void *context                                                | 应用上下文的指针。       |
| const [OH_PreferencesPair](capi-preferences-oh-preferencespair.md) *pairs | 发生变更的KV数据的指针。 |
| uint32_t count                                               | 发生变更的KV数据的数量。 |

### OH_Preferences_Open()

```
OH_Preferences *OH_Preferences_Open(OH_PreferencesOption *option, int *errCode)
```

**描述**

打开一个Preferences实例对象并创建指向它的指针。<br>当不再需要使用指针时，请使用[OH_Preferences_Close](capi-oh-preferences-h.md#oh_preferences_close)关闭实例对象。

**起始版本：** 13


**参数：**

| 参数项                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | 指向Preferences配置选项[OH_PreferencesOption](capi-preferences-oh-preferencesoption.md)的指针。 |
| int *errCode                                                 | 该参数作为出参使用，表示指向返回错误码的指针，详见[OH_Preferences_ErrCode](capi-oh-preferences-err-code-h.md#oh_preferences_errcode)。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_NOT_SUPPORTED，表示系统能力不支持。<br>若错误码为PREFERENCES_ERROR_DELETE_FILE，表示删除文件失败。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

**返回：**

| 类型                                     | 说明                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) | 当操作成功时，返回指向打开的Preferences对象[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针，失败返回空指针。 |

### OH_Preferences_Close()

```
int OH_Preferences_Close(OH_Preferences *preference)
```

**描述**

关闭一个Preferences实例对象。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向需要关闭的Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码，详见[OH_Preferences_ErrCode](capi-oh-preferences-err-code-h.md#oh_preferences_errcode)。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

### OH_Preferences_GetInt()

```
int OH_Preferences_GetInt(OH_Preferences *preference, const char *key, int *value)
```

**描述**

获取Preferences实例对象中Key对应的整型值。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 需要获取的Key的指针。                                        |
| int *value                                           | 该参数作为出参使用，表示指向获取到的整型值的指针。           |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。<br>若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的Key不存在。 |

### OH_Preferences_GetBool()

```
int OH_Preferences_GetBool(OH_Preferences *preference, const char *key, bool *value)
```

**描述**

获取Preferences实例对象中Key对应的布尔值。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 需要获取的Key的指针。                                        |
| bool *value                                          | 该参数作为出参使用，表示指向获取到的布尔值的指针。           |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。<br>若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的key不存在。 |

### OH_Preferences_GetString()

```
int OH_Preferences_GetString(OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen)
```

**描述**

获取Preferences实例对象中Key对应的字符串。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 需要获取的Key的指针。                                        |
| char **value                                         | 该参数作为出参使用，表示指向获取到的字符串的二级指针，使用完毕后需要调用释放函数[OH_Preferences_FreeString](capi-oh-preferences-h.md#oh_preferences_freestring)释放内存。 |
| uint32_t *valueLen                                   | 该参数作为出参使用，表示获取到的字符串长度的指针。           |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。<br>若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的Key不存在。 |

### OH_Preferences_FreeString()

```
void OH_Preferences_FreeString(char *string)
```

**描述**

释放从Preferences实例对象中获取的字符串。

**起始版本：** 13


**参数：**

| 参数项       | 描述                   |
| ------------ | ---------------------- |
| char *string | 需要释放的字符串指针。 |

### OH_Preferences_SetInt()

```
int OH_Preferences_SetInt(OH_Preferences *preference, const char *key, int value)
```

**描述**

根据Key设置Preferences实例对象中的整型值。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 指向需要设置的Key的指针。                                    |
| int value                                            | 需要设置的整型值。                                           |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

### OH_Preferences_SetBool()

```
int OH_Preferences_SetBool(OH_Preferences *preference, const char *key, bool value)
```

**描述**

根据Key设置Preferences实例对象中的布尔值。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 指向需要设置的Key的指针。                                    |
| bool value                                           | 需要设置的布尔值。                                           |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

### OH_Preferences_SetString()

```
int OH_Preferences_SetString(OH_Preferences *preference, const char *key, const char *value)
```

**描述**

根据Key设置Preferences实例对象中的字符串。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 指向需要设置的Key的指针。                                    |
| const char *value                                    | 指向需要设置的字符串指针。                                   |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

### OH_Preferences_Delete()

```
int OH_Preferences_Delete(OH_Preferences *preference, const char *key)
```

**描述**

在Preferences实例对象中删除Key对应的KV数据。

**起始版本：** 13


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| const char *key                                      | 指向需要删除的Key的指针。                                    |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

**参考：**

OH_Preferences_ErrCode

### OH_Preferences_RegisterDataObserver()

```
int OH_Preferences_RegisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)
```

**描述**

对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。

**起始版本：** 13


**参数：**

| 参数项                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference         | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| void *context                                                | 应用上下文的指针。                                           |
| [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer | 订阅数据变更关联的回调函数[OH_PreferencesDataObserver](capi-oh-preferences-h.md#oh_preferencesdataobserver)。 |
| const char *keys[]                                           | 需要订阅的Key数组。                                          |
| uint32_t keyCount                                            | 需要订阅的Key的数量。                                        |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。<br>若错误码为PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT，表示获取数据变更订阅服务失败。 |

### OH_Preferences_UnregisterDataObserver()

```
int OH_Preferences_UnregisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)
```

**描述**

取消注册选取Key的数据变更订阅。

**起始版本：** 13


**参数：**

| 参数项                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference         | 指向目标Preferences[OH_Preferences](capi-preferences-oh-preferences.md)实例对象的指针。 |
| void *context                                                | 应用上下文的指针。                                           |
| [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer | 订阅数据变更关联的回调函数[OH_PreferencesDataObserver](capi-oh-preferences-h.md#oh_preferencesdataobserver)。 |
| const char *keys[]                                           | 需要取消订阅的Key数组。                                      |
| uint32_t keyCount                                            | 需要取消订阅的Key的数量。                                    |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。<br>若错误码为PREFERENCES_OK，表示操作成功。<br>若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。<br>若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。<br>若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。 |

**参考：**

OH_Preferences_ErrCode

### OH_Preferences_IsStorageTypeSupported()

```
int OH_Preferences_IsStorageTypeSupported(Preferences_StorageType type, bool *isSupported)
```


**起始版本：** 18


**参数：**

| 参数项                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Preferences_StorageType](capi-oh-preferences-option-h.md#preferences_storagetype) type | 要校验是否支持的存储模式。                                   |
| bool *isSupported                                            | 校验结果的指针，作为出参使用。true表示当前平台支持当前校验的存储模式，false表示当前平台不支持当前校验的存储模式。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回接口操作执行的状态码。<br>PREFERENCES_OK，表示操作成功。<br>PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。 |


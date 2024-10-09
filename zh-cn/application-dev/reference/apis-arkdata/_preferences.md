# Preferences


## 概述

首选项模块（Preferences）提供Key-Value键值型数据（后续简称KV数据）的处理接口，实现对轻量级KV数据的查询、修改和持久化功能。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_preferences.h](oh__preferences_8h.md) | 提供访问Preferences对象的接口与数据结构。 | 
| [oh_preferences_option.h](oh__preferences__option_8h.md) | 提供访问Preferences配置选项（PreferencesOption）的接口与数据结构。 | 
| [oh_preferences_value.h](oh__preferences__value_8h.md) | 提供访问Preferences值（PreferencesValue）对象的接口、枚举类型与数据结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Preferences](#oh_preferences) [OH_Preferences](#oh_preferences) | 定义Preferences对象类型。 | 
| typedef void(\* [OH_PreferencesDataObserver](#oh_preferencesdataobserver)) (void \*context, const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t count) | 定义数据变更触发的回调函数类型。 | 
| typedef enum [OH_Preferences_ErrCode](#oh_preferences_errcode) [OH_Preferences_ErrCode](#oh_preferences_errcode) | 错误码信息。 | 
| typedef struct [OH_PreferencesOption](#oh_preferencesoption) [OH_PreferencesOption](#oh_preferencesoption) | 定义Preferences配置选项的数据结构。 | 
| typedef enum [Preference_ValueType](#preference_valuetype) [Preference_ValueType](#preference_valuetype) | 定义PreferencesValue的数据类型。 | 
| typedef struct [OH_PreferencesPair](#oh_preferencespair) [OH_PreferencesPair](#oh_preferencespair) | 定义Preferences使用的KV数据对象类型。 | 
| typedef struct [OH_PreferencesValue](#oh_preferencesvalue) [OH_PreferencesValue](#oh_preferencesvalue) | 定义PreferencesValue对象类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Preferences_ErrCode](#oh_preferences_errcode-1) {<br/>PREFERENCES_OK = 0, PREFERENCES_ERROR_INVALID_PARAM = 401, PREFERENCES_ERROR_NOT_SUPPORTED = 801, PREFERENCES_ERROR_BASE = 15500000,<br/>PREFERENCES_ERROR_DELETE_FILE = 15500010, PREFERENCES_ERROR_STORAGE = 15500011, PREFERENCES_ERROR_MALLOC = 15500012, PREFERENCES_ERROR_KEY_NOT_FOUND = 15500013,<br/>PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT = 15500019<br/>} | 错误码信息。 | 
| [Preference_ValueType](#preference_valuetype-1) {<br/>PREFERENCE_TYPE_NULL = 0, PREFERENCE_TYPE_INT, PREFERENCE_TYPE_BOOL, PREFERENCE_TYPE_STRING,<br/>PREFERENCE_TYPE_BUTT<br/>} | 定义PreferencesValue的数据类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Preferences](#oh_preferences) \* [OH_Preferences_Open](#oh_preferences_open) ([OH_PreferencesOption](#oh_preferencesoption) \*option, int \*errCode) | 打开一个Preferences实例对象并创建指向它的指针。 当不再需要使用指针时，请使用[OH_Preferences_Close](#oh_preferences_close)关闭实例对象。 | 
| int [OH_Preferences_Close](#oh_preferences_close) ([OH_Preferences](#oh_preferences) \*preference) | 关闭一个Preferences实例对象。 | 
| int [OH_Preferences_GetInt](#oh_preferences_getint) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, int \*value) | 获取Preferences实例对象中Key对应的整型值。 | 
| int [OH_Preferences_GetBool](#oh_preferences_getbool) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, bool \*value) | 获取Preferences实例对象中Key对应的布尔值。 | 
| int [OH_Preferences_GetString](#oh_preferences_getstring) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | 获取Preferences实例对象中Key对应的字符串。 | 
| void [OH_Preferences_FreeString](#oh_preferences_freestring) (char \*string) | 释放从Preferences实例对象中获取的字符串。 | 
| int [OH_Preferences_SetInt](#oh_preferences_setint) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, int value) | 根据Key设置Preferences实例对象中的整型值。 | 
| int [OH_Preferences_SetBool](#oh_preferences_setbool) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, bool value) | 根据Key设置Preferences实例对象中的布尔值。 | 
| int [OH_Preferences_SetString](#oh_preferences_setstring) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, const char \*value) | 根据Key设置Preferences实例对象中的字符串。 | 
| int [OH_Preferences_Delete](#oh_preferences_delete) ([OH_Preferences](#oh_preferences) \*preference, const char \*key) | 在Preferences实例对象中删除Key对应的KV数据。 | 
| int [OH_Preferences_RegisterDataObserver](#oh_preferences_registerdataobserver) ([OH_Preferences](#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | 对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。 | 
| int [OH_Preferences_UnregisterDataObserver](#oh_preferences_unregisterdataobserver) ([OH_Preferences](#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | 取消注册选取Key的数据变更订阅。 | 
| [OH_PreferencesOption](#oh_preferencesoption) \* [OH_PreferencesOption_Create](#oh_preferencesoption_create) (void) | 创建一个Preferences配置选项的[OH_PreferencesOption](#oh_preferencesoption)实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| int [OH_PreferencesOption_SetFileName](#oh_preferencesoption_setfilename) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*fileName) | 设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的文件名称。 | 
| int [OH_PreferencesOption_SetBundleName](#oh_preferencesoption_setbundlename) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*bundleName) | 设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的包名称。 | 
| int [OH_PreferencesOption_SetDataGroupId](#oh_preferencesoption_setdatagroupid) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*dataGroupId) | 设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的应用组ID。 | 
| int [OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy) ([OH_PreferencesOption](#oh_preferencesoption) \*option) | 销毁Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例。 | 
| const char \* [OH_PreferencesPair_GetKey](#oh_preferencespair_getkey) (const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t index) | 获取KV数据中索引对应数据的键。 | 
| const [OH_PreferencesValue](#oh_preferencesvalue) \* [OH_PreferencesPair_GetPreferencesValue](#oh_preferencespair_getpreferencesvalue) (const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t index) | 获取KV数据数组中索引对应的值。 | 
| [Preference_ValueType](#preference_valuetype) [OH_PreferencesValue_GetValueType](#oh_preferencesvalue_getvaluetype) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object) | 获取PreferencesValue对象的数据类型。 | 
| int [OH_PreferencesValue_GetInt](#oh_preferencesvalue_getint) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, int \*value) | 从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取一个整型值。 | 
| int [OH_PreferencesValue_GetBool](#oh_preferencesvalue_getbool) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, bool \*value) | 从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取一个布尔值。 | 
| int [OH_PreferencesValue_GetString](#oh_preferencesvalue_getstring) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, char \*\*value, uint32_t \*valueLen) | 从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取字符串。 | 


## 类型定义说明


### OH_Preferences

```
typedef struct OH_Preferences OH_Preferences
```

**描述**

定义Preferences对象类型。

**起始版本：** 13


### OH_Preferences_ErrCode

```
typedef enum OH_Preferences_ErrCode OH_Preferences_ErrCode
```

**描述**

错误码信息。

**起始版本：** 13


### OH_PreferencesDataObserver

```
typedef void(*OH_PreferencesDataObserver) (void *context, const OH_PreferencesPair *pairs, uint32_t count)
```

**描述**

定义数据变更触发的回调函数类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | 应用上下文的指针。 | 
| pairs | 发生变更的KV数据的指针。 | 
| count | 发生变更的KV数据的数量。 | 

**参见：**

[OH_PreferencesPair](#oh_preferencespair)


### OH_PreferencesOption

```
typedef struct OH_PreferencesOption OH_PreferencesOption
```

**描述**

定义Preferences配置选项的数据结构。

**起始版本：** 13


### OH_PreferencesPair

```
typedef struct OH_PreferencesPair OH_PreferencesPair
```

**描述**

定义Preferences使用的KV数据对象类型。

**起始版本：** 13


### OH_PreferencesValue

```
typedef struct OH_PreferencesValue OH_PreferencesValue
```

**描述**

定义PreferencesValue对象类型。

**起始版本：** 13


### Preference_ValueType

```
typedef enum Preference_ValueType Preference_ValueType
```

**描述**

定义PreferencesValue的数据类型。

**起始版本：** 13


## 枚举类型说明


### OH_Preferences_ErrCode

```
enum OH_Preferences_ErrCode
```

**描述**

错误码信息。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| PREFERENCES_OK | 操作执行成功 | 
| PREFERENCES_ERROR_INVALID_PARAM | 参数不合法 | 
| PREFERENCES_ERROR_NOT_SUPPORTED | 系统能力不支持 | 
| PREFERENCES_ERROR_BASE | 基准错误码 | 
| PREFERENCES_ERROR_DELETE_FILE | 删除文件失败 | 
| PREFERENCES_ERROR_STORAGE | 存储异常 | 
| PREFERENCES_ERROR_MALLOC | 申请内存失败 | 
| PREFERENCES_ERROR_KEY_NOT_FOUND | Key不存在 | 
| PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT | 获取数据变更订阅服务失败 | 


### Preference_ValueType

```
enum Preference_ValueType
```

**描述**

定义PreferencesValue的数据类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| PREFERENCE_TYPE_NULL | 空类型 | 
| PREFERENCE_TYPE_INT | 整型类型 | 
| PREFERENCE_TYPE_BOOL | 布尔类型 | 
| PREFERENCE_TYPE_STRING | 字符串类型 | 
| PREFERENCE_TYPE_BUTT | 结束类型 | 


## 函数说明


### OH_Preferences_Close()

```
int OH_Preferences_Close (OH_Preferences *preference)
```

**描述**

关闭一个Preferences实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向需要关闭的[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| option | 指向PreferencesOption[OH_PreferencesOption](#oh_preferencesoption)的指针。 | 

**返回：**

返回执行的错误码，详见[OH_Preferences_ErrCode](#oh_preferences_errcode)。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_Delete()

```
int OH_Preferences_Delete (OH_Preferences *preference, const char *key )
```

**描述**

在Preferences实例对象中删除Key对应的KV数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 指向需要删除的Key的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_FreeString()

```
void OH_Preferences_FreeString (char *string)
```

**描述**

释放从Preferences实例对象中获取的字符串。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| string | 需要释放的字符串指针。 | 

**参见：**

[OH_Preferences](#oh_preferences)


### OH_Preferences_GetBool()

```
int OH_Preferences_GetBool (OH_Preferences *preference, const char *key, bool *value )
```

**描述**

获取Preferences实例对象中Key对应的布尔值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 需要获取的Key的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的布尔值的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的key不存在。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_GetInt()

```
int OH_Preferences_GetInt (OH_Preferences *preference, const char *key, int *value )
```

**描述**

获取Preferences实例对象中Key对应的整型值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 需要获取的Key的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的整型值的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的Key不存在。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_GetString()

```
int OH_Preferences_GetString (OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen )
```

**描述**

获取Preferences实例对象中Key对应的字符串。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 需要获取的Key的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的字符串的二级指针，使用完毕后需要调用释放函数[OH_Preferences_FreeString](#oh_preferences_freestring)释放内存。 | 
| valueLen | 该参数作为出参使用，表示获取到的字符串长度的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

若错误码为PREFERENCES_ERROR_KEY_NOT_FOUND，表示查询的Key不存在。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_Open()

```
OH_Preferences* OH_Preferences_Open (OH_PreferencesOption *option, int *errCode )
```

**描述**

打开一个Preferences实例对象并创建指向它的指针。 当不再需要使用指针时，请使用[OH_Preferences_Close](#oh_preferences_close)关闭实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 指向Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)的指针。 | 
| errCode | 该参数作为出参使用，表示指向返回错误码的指针，详见[OH_Preferences_ErrCode](#oh_preferences_errcode)。 | 

**返回：**

当操作成功时，返回指向打开的Preferences对象[OH_Preferences](#oh_preferences)实例对象的指针，失败返回空指针。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_RegisterDataObserver()

```
int OH_Preferences_RegisterDataObserver (OH_Preferences *preference, void *context, OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount )
```

**描述**

对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| context | 应用上下文的指针。 | 
| observer | 订阅数据变更关联的回调函数[OH_PreferencesDataObserver](#oh_preferencesdataobserver)。 | 
| keys | 需要订阅的Key数组。 | 
| keyCount | 需要订阅的Key的数量。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

若错误码为PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT，表示获取数据变更订阅服务失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_PreferencesDataObserver](#oh_preferencesdataobserver)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetBool()

```
int OH_Preferences_SetBool (OH_Preferences *preference, const char *key, bool value )
```

**描述**

根据Key设置Preferences实例对象中的布尔值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 指向需要设置的Key的指针。 | 
| value | 需要设置的布尔值。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetInt()

```
int OH_Preferences_SetInt (OH_Preferences *preference, const char *key, int value )
```

**描述**

根据Key设置Preferences实例对象中的整型值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 指向需要设置的Key的指针。 | 
| value | 需要设置的整型值。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetString()

```
int OH_Preferences_SetString (OH_Preferences *preference, const char *key, const char *value )
```

**描述**

根据Key设置Preferences实例对象中的字符串。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| key | 指向需要设置的Key的指针。 | 
| value | 指向需要设置的字符串指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_UnregisterDataObserver()

```
int OH_Preferences_UnregisterDataObserver (OH_Preferences *preference, void *context, OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount )
```

**描述**

取消注册选取Key的数据变更订阅。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| preference | 指向目标[OH_Preferences](#oh_preferences)实例对象的指针。 | 
| context | 应用上下文的指针。 | 
| observer | 订阅数据变更关联的回调函数[OH_PreferencesDataObserver](#oh_preferencesdataobserver)。 | 
| keys | 需要取消订阅的Key数组。 | 
| keyCount | 需要取消订阅的Key的数量。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_Preferences](#oh_preferences)

[OH_PreferencesDataObserver](#oh_preferencesdataobserver)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_Create()

```
OH_PreferencesOption* OH_PreferencesOption_Create (void )
```

**描述**

创建一个Preferences配置选项的[OH_PreferencesOption](#oh_preferencesoption)实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

如果操作成功，返回指向Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的指针。失败返回空指针。

**参见：**

[OH_PreferencesOption](#oh_preferencesoption)


### OH_PreferencesOption_Destroy()

```
int OH_PreferencesOption_Destroy (OH_PreferencesOption *option)
```

**描述**

销毁Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的指针。 | 

**返回：**

返回执行的错误码。 若错误码为PREFERENCES_OK，表示操作成功。 若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

**参见：**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetBundleName()

```
int OH_PreferencesOption_SetBundleName (OH_PreferencesOption *option, const char *bundleName )
```

**描述**

设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的包名称。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的指针。 | 
| bundleName | 需要设置的包名称。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

**参见：**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetDataGroupId()

```
int OH_PreferencesOption_SetDataGroupId (OH_PreferencesOption *option, const char *dataGroupId )
```

**描述**

设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的应用组ID。

设置应用组ID后，会指定在此应用组ID对应的沙箱路径下创建Preferences实例。

应用组ID需要向应用市场获取，暂不支持。

当传入的应用组ID为空字符串时，默认在本应用沙箱目录下创建Preferences实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的指针。 | 
| dataGroupId | 需要设置的应用组ID。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

**参见：**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetFileName()

```
int OH_PreferencesOption_SetFileName (OH_PreferencesOption *option, const char *fileName )
```

**描述**

设置Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的文件名称。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 指向Preferences配置选项[OH_PreferencesOption](#oh_preferencesoption)实例对象的指针。 | 
| fileName | 需要设置的文件名称。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

**参见：**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesPair_GetKey()

```
const char* OH_PreferencesPair_GetKey (const OH_PreferencesPair *pairs, uint32_t index )
```

**描述**

获取KV数据中索引对应数据的键。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pairs | 目标KV数据[OH_PreferencesPair](#oh_preferencespair)的指针。 | 
| index | 目标KV数据[OH_PreferencesPair](#oh_preferencespair)的索引值。 | 

**返回：**

如果操作成功，返回获取到的键的指针。操作失败或传参不合法返回空指针。

**参见：**

[OH_PreferencesPair](#oh_preferencespair)


### OH_PreferencesPair_GetPreferencesValue()

```
const OH_PreferencesValue* OH_PreferencesPair_GetPreferencesValue (const OH_PreferencesPair *pairs, uint32_t index )
```

**描述**

获取KV数据数组中索引对应的值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pairs | 目标KV数据[OH_PreferencesPair](#oh_preferencespair)的指针。 | 
| index | 目标KV数据[OH_PreferencesPair](#oh_preferencespair)的索引值。 | 

**返回：**

如果操作成功，返回获取到的值对象的指针。操作失败或传参不合法返回空指针。

**参见：**

[OH_PreferencesValue](#oh_preferencesvalue)


### OH_PreferencesValue_GetBool()

```
int OH_PreferencesValue_GetBool (const OH_PreferencesValue *object, bool *value )
```

**描述**

从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取一个布尔值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| object | PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的布尔值的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetInt()

```
int OH_PreferencesValue_GetInt (const OH_PreferencesValue* object, int* value )
```

**描述**

从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取一个整型值。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| object | PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的整型值的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetString()

```
int OH_PreferencesValue_GetString (const OH_PreferencesValue *object, char **value, uint32_t *valueLen )
```

**描述**

从PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)中获取字符串。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| object | PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)的指针。 | 
| value | 该参数作为出参使用，表示指向获取到的字符串的二级指针，使用完毕后需要调用释放函数[OH_Preferences_FreeString](#oh_preferences_freestring)释放内存。 | 
| valueLen | 该参数作为出参使用，表示指向获取到的字符串长度的指针。 | 

**返回：**

返回执行的错误码。

若错误码为PREFERENCES_OK，表示操作成功。

若错误码为PREFERENCES_ERROR_INVALID_PARAM，表示参数不合法。

若错误码为PREFERENCES_ERROR_STORAGE，表示存储异常。

若错误码为PREFERENCES_ERROR_MALLOC，表示内存分配失败。

**参见：**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetValueType()

```
Preference_ValueType OH_PreferencesValue_GetValueType (const OH_PreferencesValue *object)
```

**描述**

获取PreferencesValue对象的数据类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| object | PreferencesValue对象[OH_PreferencesValue](#oh_preferencesvalue)的指针。 | 

**返回：**

返回获取到的数据类型枚举。若返回数据类型枚举为PREFERENCE_TYPE_NULL，代表传参不合法。

**参见：**

[OH_PreferencesValue](#oh_preferencesvalue)

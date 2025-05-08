# oh_preferences.h


## 概述

提供访问Preferences对象的接口与数据结构。

**引用文件：**&lt;database/preferences/oh_preferences.h&gt;

**库：** libohpreferences.so

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13

**相关模块：**[Preferences](_preferences.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Preferences](_preferences.md#oh_preferences) [OH_Preferences](_preferences.md#oh_preferences) | 定义Preferences对象类型。 | 
| typedef void(\* [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver)) (void \*context, const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t count) | 定义数据变更触发的回调函数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Preferences](_preferences.md#oh_preferences) \* [OH_Preferences_Open](_preferences.md#oh_preferences_open) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, int \*errCode) | 打开一个Preferences实例对象并创建指向它的指针。 当不再需要使用指针时，请使用[OH_Preferences_Close](_preferences.md#oh_preferences_close)关闭实例对象。 | 
| int [OH_Preferences_Close](_preferences.md#oh_preferences_close) ([OH_Preferences](_preferences.md#oh_preferences) \*preference) | 关闭一个Preferences实例对象。 | 
| int [OH_Preferences_GetInt](_preferences.md#oh_preferences_getint) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, int \*value) | 获取Preferences实例对象中Key对应的整型值。 | 
| int [OH_Preferences_GetBool](_preferences.md#oh_preferences_getbool) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, bool \*value) | 获取Preferences实例对象中Key对应的布尔值。 | 
| int [OH_Preferences_GetString](_preferences.md#oh_preferences_getstring) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | 获取Preferences实例对象中Key对应的字符串。 | 
| void [OH_Preferences_FreeString](_preferences.md#oh_preferences_freestring) (char \*string) | 释放从Preferences实例对象中获取的字符串。 | 
| int [OH_Preferences_SetInt](_preferences.md#oh_preferences_setint) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, int value) | 根据Key设置Preferences实例对象中的整型值。 | 
| int [OH_Preferences_SetBool](_preferences.md#oh_preferences_setbool) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, bool value) | 根据Key设置Preferences实例对象中的布尔值。 | 
| int [OH_Preferences_SetString](_preferences.md#oh_preferences_setstring) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, const char \*value) | 根据Key设置Preferences实例对象中的字符串。 | 
| int [OH_Preferences_Delete](_preferences.md#oh_preferences_delete) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key) | 在Preferences实例对象中删除Key对应的KV数据。 | 
| int [OH_Preferences_RegisterDataObserver](_preferences.md#oh_preferences_registerdataobserver) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | 对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。 | 
| int [OH_Preferences_UnregisterDataObserver](_preferences.md#oh_preferences_unregisterdataobserver) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | 取消注册选取Key的数据变更订阅。 | 
| int [OH_Preferences_IsStorageTypeSupported](_preferences.md#oh_preferences_isstoragetypesupported) ([Preferences_StorageType](_preferences.md#preferences_storagetype) type, bool \*isSupported) | 校验当前平台是否支持对应存储模式。  | 

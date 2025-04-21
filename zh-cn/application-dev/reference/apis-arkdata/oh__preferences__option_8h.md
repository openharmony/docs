# oh_preferences_option.h


## 概述

提供访问Preferences配置选项（PreferencesOption）的接口与数据结构。

**引用文件：**&lt;database/preferences/oh_preferences_option.h&gt;

**库：** libohpreferences.so

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13

**相关模块：**[Preferences](_preferences.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_PreferencesOption](_preferences.md#oh_preferencesoption) [OH_PreferencesOption](_preferences.md#oh_preferencesoption) | 定义Preferences配置选项的数据结构。 | 
| typedef enum [Preferences_StorageType](_preferences.md#preferences_storagetype) [Preferences_StorageType](_preferences.md#preferences_storagetype) | 首选项配置选项的存储模式枚举。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Preferences_StorageType](_preferences.md#preferences_storagetype-1) { PREFERENCES_STORAGE_XML = 0, PREFERENCES_STORAGE_GSKV } | 首选项配置选项的存储模式枚举。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_PreferencesOption_SetStorageType](_preferences.md#oh_preferencesoption_setstoragetype) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, [Preferences_StorageType](_preferences.md#preferences_storagetype) type) | 设置Preferences实例对象的存储模式。  | 
| [OH_PreferencesOption](_preferences.md#oh_preferencesoption) \* [OH_PreferencesOption_Create](_preferences.md#oh_preferencesoption_create) (void) | 创建一个Preferences配置选项的[OH_PreferencesOption](_preferences.md#oh_preferencesoption)实例对象以及指向它的指针。 当不再需要使用指针时，请使用[OH_PreferencesOption_Destroy](_preferences.md#oh_preferencesoption_destroy)销毁实例对象，否则会导致内存泄漏。 | 
| int [OH_PreferencesOption_SetFileName](_preferences.md#oh_preferencesoption_setfilename) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*fileName) | 设置Preferences配置选项[OH_PreferencesOption](_preferences.md#oh_preferencesoption)实例对象的文件名称。 | 
| int [OH_PreferencesOption_SetBundleName](_preferences.md#oh_preferencesoption_setbundlename) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*bundleName) | 设置Preferences配置选项[OH_PreferencesOption](_preferences.md#oh_preferencesoption)实例对象的包名称。 | 
| int [OH_PreferencesOption_SetDataGroupId](_preferences.md#oh_preferencesoption_setdatagroupid) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*dataGroupId) | 设置Preferences配置选项[OH_PreferencesOption](_preferences.md#oh_preferencesoption)实例对象的应用组ID。 | 
| int [OH_PreferencesOption_Destroy](_preferences.md#oh_preferencesoption_destroy) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option) | 销毁Preferences配置选项[OH_PreferencesOption](_preferences.md#oh_preferencesoption)实例。 | 

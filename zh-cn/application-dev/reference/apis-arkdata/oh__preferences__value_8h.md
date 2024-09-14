# oh_preferences_value.h


## 概述

提供访问Preferences值（PreferencesValue）对象的接口、枚举类型与数据结构。

**引用文件：**&lt;database/preferences/oh_preferences_value.h&gt;

**库：** libohpreferences.so

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13

**相关模块：**[Preferences](_preferences.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Preference_ValueType](_preferences.md#preference_valuetype) [Preference_ValueType](_preferences.md#preference_valuetype) | 定义PreferencesValue的数据类型。 | 
| typedef struct [OH_PreferencesPair](_preferences.md#oh_preferencespair) [OH_PreferencesPair](_preferences.md#oh_preferencespair) | 定义Preferences使用的KV数据对象类型。 | 
| typedef struct [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) | 定义PreferencesValue对象类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Preference_ValueType](_preferences.md#preference_valuetype-1) {<br/>PREFERENCE_TYPE_NULL = 0, PREFERENCE_TYPE_INT, PREFERENCE_TYPE_BOOL, PREFERENCE_TYPE_STRING,<br/>PREFERENCE_TYPE_BUTT<br/>} | 定义PreferencesValue的数据类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_PreferencesPair_GetKey](_preferences.md#oh_preferencespair_getkey) (const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t index) | 获取KV数据中索引对应数据的键。 | 
| const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \* [OH_PreferencesPair_GetPreferencesValue](_preferences.md#oh_preferencespair_getpreferencesvalue) (const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t index) | 获取KV数据数组中索引对应的值。 | 
| [Preference_ValueType](_preferences.md#preference_valuetype) [OH_PreferencesValue_GetValueType](_preferences.md#oh_preferencesvalue_getvaluetype) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object) | 获取PreferencesValue对象的数据类型。 | 
| int [OH_PreferencesValue_GetInt](_preferences.md#oh_preferencesvalue_getint) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, int \*value) | 从PreferencesValue对象[OH_PreferencesValue](_preferences.md#oh_preferencesvalue)中获取一个整型值。 | 
| int [OH_PreferencesValue_GetBool](_preferences.md#oh_preferencesvalue_getbool) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, bool \*value) | 从PreferencesValue对象[OH_PreferencesValue](_preferences.md#oh_preferencesvalue)中获取一个布尔值。 | 
| int [OH_PreferencesValue_GetString](_preferences.md#oh_preferencesvalue_getstring) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, char \*\*value, uint32_t \*valueLen) | 从PreferencesValue对象[OH_PreferencesValue](_preferences.md#oh_preferencesvalue)中获取字符串。 | 

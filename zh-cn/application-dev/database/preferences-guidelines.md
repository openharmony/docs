# 通过用户首选项实现数据持久化 (C/C++)

## 场景介绍
用户首选项（Preferences）模块主要提供轻量级Key-Value操作，支持本地存储少量数据，数据存储在文件和内存中，访问速度快。如果存在大量数据场景，请考虑使用键值型数据库或关系型数据库。

## 约束限制
- API version 18之前：ArkTS API仅支持XML格式存储；C API仅支持GSKV存储格式；存储模式互不兼容，不支持ArkTS和C API操作同一个Preferences实例。
- API version 18及之后：ArkTS和C API均支持XML和GSKV双模式；ArkTS和C API使用相同的存储模式时，可以正常操作同一Preferences实例；禁止ArkTS和C API选择不同的存储模式，来操作同一个Preferences实例。
- Key的最大长度限制为1024个字节，Value的最大长度限制为16MB。


## 接口说明

详细的接口说明请参考[Preferences接口文档](../reference/apis-arkdata/capi-preferences.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| OH_Preferences \* OH_Preferences_Open (OH_PreferencesOption \*option, int \*errCode) | 打开一个Preferences实例对象并创建指向它的指针。 当不再需要使用指针时，请使用OH_Preferences_Close关闭实例对象。 |
| int OH_Preferences_Close (OH_Preferences \*preference) | 关闭一个Preferences实例对象。 |
| int OH_Preferences_GetInt (OH_Preferences \*preference, const char \*key, int \*value) | 获取Preferences实例对象中Key对应的整型值。 |
| int OH_Preferences_GetBool (OH_Preferences \*preference, const char \*key, bool \*value) | 获取Preferences实例对象中Key对应的布尔值。 |
| int OH_Preferences_GetString (OH_Preferences \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | 获取Preferences实例对象中Key对应的字符串。 |
| void OH_Preferences_FreeString (char \*string) | 释放从Preferences实例对象中获取的字符串。 |
| int OH_Preferences_SetInt (OH_Preferences \*preference, const char \*key, int value) | 根据Key设置Preferences实例对象中的整型值。 |
| int OH_Preferences_SetBool (OH_Preferences \*preference, const char \*key, bool value) | 根据Key设置Preferences实例对象中的布尔值。 |
| int OH_Preferences_SetString (OH_Preferences \*preference, const char \*key, const char \*value) | 根据Key设置Preferences实例对象中的字符串。 |
| int OH_Preferences_Delete (OH_Preferences \*preference, const char \*key) | 在Preferences实例对象中删除Key对应的KV数据。 |
| int OH_Preferences_RegisterDataObserver (OH_Preferences \*preference, void \*context, OH_PreferencesDataObserver observer, const char \*keys[], uint32_t keyCount) | 对选取的Key注册数据变更订阅。订阅的Key的值发生变更后，在调用OH_Preferences_Close()后触发回调。 |
| int OH_Preferences_UnregisterDataObserver (OH_Preferences \*preference, void \*context, OH_PreferencesDataObserver observer, const char \*keys[], uint32_t keyCount) | 取消注册选取Key的数据变更订阅。 |
| int OH_Preferences_IsStorageTypeSupported (Preferences_StorageType type, bool \*isSupported) | 检查当前平台是否支持对应的存储模式。 |
| OH_PreferencesOption \* OH_PreferencesOption_Create (void) | 创建一个Preferences配置选项的OH_PreferencesOption实例对象以及指向它的指针。 当不再需要使用指针时，请使用OH_PreferencesOption_Destroy销毁实例对象，否则会导致内存泄漏。 |
| int OH_PreferencesOption_SetFileName (OH_PreferencesOption \*option, const char \*fileName) | 设置Preferences配置选项OH_PreferencesOption实例对象的文件名称。名称长度为0到255字节，其中不能包含'/'。 |
| int OH_PreferencesOption_SetBundleName (OH_PreferencesOption \*option, const char \*bundleName) | 设置Preferences配置选项OH_PreferencesOption实例对象的包名称。 |
| int OH_PreferencesOption_SetDataGroupId (OH_PreferencesOption \*option, const char \*dataGroupId) | 设置Preferences配置选项OH_PreferencesOption实例对象的应用组ID。 |
| int OH_PreferencesOption_SetStorageType (OH_PreferencesOption \*option, Preferences_StorageType type) | 设置Preferences配置选项 OH_PreferencesOption实例对象的存储模式。 |
| int OH_PreferencesOption_Destroy (OH_PreferencesOption \*option) | 销毁Preferences配置选项OH_PreferencesOption实例。 |
| const char \* OH_PreferencesPair_GetKey (const OH_PreferencesPair \*pairs, uint32_t index) | 获取KV数据中索引对应数据的键。 |
| const OH_PreferencesValue \* OH_PreferencesPair_GetPreferencesValue (const OH_PreferencesPair \*pairs, uint32_t index) | 获取KV数据数组中索引对应的值。 |
| Preference_ValueType OH_PreferencesValue_GetValueType (const OH_PreferencesValue \*object) | 获取PreferencesValue对象的数据类型。 |
| int OH_PreferencesValue_GetInt (const OH_PreferencesValue \*object, int \*value) | 从PreferencesValue对象OH_PreferencesValue中获取一个整型值。 |
| int OH_PreferencesValue_GetBool (const OH_PreferencesValue \*object, bool \*value) | 从PreferencesValue对象OH_PreferencesValue中获取一个布尔值。 |
| int OH_PreferencesValue_GetString (const OH_PreferencesValue \*object, char \*\*value, uint32_t \*valueLen) | 从PreferencesValue对象OH_PreferencesValue中获取字符串。 |


## 添加动态链接库

CMakeLists.txt中添加以下lib。

```txt
libohpreferences.so
```

## 引用头文件

```c
#include <cstring>
#include <database/preferences/oh_preferences.h>
#include <database/preferences/oh_preferences_err_code.h>
#include <database/preferences/oh_preferences_option.h>
#include <database/preferences/oh_preferences_value.h>
```

## 开发步骤
下列实例展示如何通过Preferences实现对键值数据的修改与持久化。
1. 创建Preferences配置选项（PreferencesOption）对象并设置配置选项成员（名称、应用组ID、包名、存储模式）。使用完毕后，调用OH_PreferencesOption_Destroy销毁配置选项实例。
2. 调用OH_Preferences_Open打开一个Preferences实例，该实例使用完后需要调用OH_Preferences_Close关闭。
3. 调用OH_Preferences_RegisterDataObserver注册3个Key的数据变更订阅，订阅回调函数为DataChangeObserverCallback。
4. 设置Preferences实例中的键值数据。
5. 获取Preferences实例中的键值数据。
6. 调用OH_Preferences_Close关闭Preferences实例，关闭后需要将实例指针置空。

```c
// 数据变更回调函数
void DataChangeObserverCallback(void *context, const OH_PreferencesPair *pairs, uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        // 获取索引i对应的PreferenceValue
        const OH_PreferencesValue *pValue = OH_PreferencesPair_GetPreferencesValue(pairs, i);
        // 获取PreferencesValue的数据类型
        Preference_ValueType type = OH_PreferencesValue_GetValueType(pValue);
        int ret = PREFERENCES_OK;
        if (type == PREFERENCE_TYPE_INT) {
            int intValue = 0;
            ret = OH_PreferencesValue_GetInt(pValue, &intValue);
            if (ret == PREFERENCES_OK) {
                // 业务逻辑
            }
        } else if (type == PREFERENCE_TYPE_BOOL) {
            bool boolValue = true;
            ret = OH_PreferencesValue_GetBool(pValue, &boolValue);
            if (ret == PREFERENCES_OK) {
                // 业务逻辑
            }
        } else if (type == PREFERENCE_TYPE_STRING) {
            char *stringValue = nullptr;
            uint32_t valueLen = 0;
            ret = OH_PreferencesValue_GetString(pValue, &stringValue, &valueLen);
            if (ret == PREFERENCES_OK) {
                // 业务逻辑
                OH_Preferences_FreeString(stringValue);
            }
        } else {
            // 无效类型
        }
    }
}

// 1. 创建Preferences配置选项。
OH_PreferencesOption *option = OH_PreferencesOption_Create();
if (option == nullptr) {
    // 错误处理
}
// 设置Preferences配置选项的文件名称。
int ret = OH_PreferencesOption_SetFileName(option, "testdb");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // 错误处理
}
// 设置Preferences配置选项的应用组ID。
ret = OH_PreferencesOption_SetDataGroupId(option, "");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // 错误处理
}
// 设置Preferences配置选项的包名称。
ret = OH_PreferencesOption_SetBundleName(option, "com.example");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // 错误处理
}

// 设置Preferences配置选项的存储模式，需要注意的是，设置之前需要调用OH_Preferences_IsStorageTypeSupported接口判断当前平台是否支持需要选择的模式。
bool isGskvSupported = false;
ret = OH_Preferences_IsStorageTypeSupported(Preferences_StorageType::PREFERENCES_STORAGE_GSKV, &isGskvSupported);
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // 错误处理
}
if (isGskvSupported) {
    ret = OH_PreferencesOption_SetStorageType(option, Preferences_StorageType::PREFERENCES_STORAGE_GSKV);
    if (ret != PREFERENCES_OK) {
        (void)OH_PreferencesOption_Destroy(option);
        // 错误处理
    }
} else {
    ret = OH_PreferencesOption_SetStorageType(option, Preferences_StorageType::PREFERENCES_STORAGE_XML);
    if (ret != PREFERENCES_OK) {
        (void)OH_PreferencesOption_Destroy(option);
        // 错误处理
    }
}

// 2. 打开一个Preferences实例。
int errCode = PREFERENCES_OK;
OH_Preferences *preference = OH_Preferences_Open(option, &errCode);
// option使用完毕后可直接释放，释放后需要将指针置空。
(void)OH_PreferencesOption_Destroy(option);
option = nullptr;
if (preference == nullptr || errCode != PREFERENCES_OK) {
    // 错误处理
}

// 3. 对key_int、key_bool和key_string注册数据变更订阅。
const char *keys[] = {"key_int", "key_bool", "key_string"};
ret = OH_Preferences_RegisterDataObserver(preference, nullptr, DataChangeObserverCallback, keys, 3);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // 错误处理
}

// 4. 设置Preferences实例中的KV数据。
ret = OH_Preferences_SetInt(preference, keys[0], 0);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // 错误处理
}
ret = OH_Preferences_SetBool(preference, keys[1], true);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // 错误处理
}
ret = OH_Preferences_SetString(preference, keys[2], "string value");
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // 错误处理
}

// 5. 获取Preferences实例中的KV数据。
int intValue = 0;
ret = OH_Preferences_GetInt(preference, keys[0], &intValue);
if (ret == PREFERENCES_OK) {
    // 业务逻辑
}

bool boolValue = false;
ret = OH_Preferences_GetBool(preference, keys[1], &boolValue);
if (ret == PREFERENCES_OK) {
    // 业务逻辑
}

char *stringValue = nullptr;
uint32_t valueLen = 0;
ret = OH_Preferences_GetString(preference, keys[2], &stringValue, &valueLen);
if (ret == PREFERENCES_OK) {
    // 业务逻辑
    // 使用完OH_Preferences_GetString接口后，需要对字符串进行释放。
    OH_Preferences_FreeString(stringValue);
    stringValue = nullptr;
}

// 6. 使用完Preferences实例后需要关闭实例，关闭后需要将指针置空。
(void)OH_Preferences_Close(preference);
preference = nullptr;

```

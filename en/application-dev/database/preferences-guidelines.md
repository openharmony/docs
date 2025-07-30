# Persisting User Preference Data (C/C++)

## When to Use
Use the **Preferences** module to store small amounts of data in key-value (KV) format. The data is stored in files and memory for fast access. If a large amount of data needs to be stored, consider using a KV store or RDB store.

## Constraints
- Prior to API version 18: ArkTS APIs support only the XML storage format, and C APIs support only the GSKV storage format. Due to incompatible formats, ArkTS and C APIs cannot operate the same **Preferences** instance.
- API version 18 and later: Both ArkTS and C APIs support the XML and GSKV storage formats. ArkTS and C APIs can operate the same **Preferences** instance if they use the same format.
- The maximum key length is 1024 bytes, and the maximum value length is 16 MB.


## Available APIs

For details about the APIs, see [Preferences](../reference/apis-arkdata/capi-preferences.md).

| API| Description|
| -------- | -------- |
| OH_Preferences \* OH_Preferences_Open (OH_PreferencesOption \*option, int \*errCode) | Opens a **Preferences** instance and creates a pointer to it. If the pointer is no longer required, use **OH_Preferences_Close** to close the instance.|
| int OH_Preferences_Close (OH_Preferences \*preference) | Closes a **Preferences** instance.|
| int OH_Preferences_GetInt (OH_Preferences \*preference, const char \*key, int \*value) | Obtains an integer corresponding to the specified key in a **Preferences** instance.|
| int OH_Preferences_GetBool (OH_Preferences \*preference, const char \*key, bool \*value) | Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.|
| int OH_Preferences_GetString (OH_Preferences \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | Obtains a string corresponding to the specified key in a **Preferences** instance.|
| void OH_Preferences_FreeString (char \*string) | Releases a string.|
| int OH_Preferences_SetInt (OH_Preferences \*preference, const char \*key, int value) | Sets an integer based on the specified key in a **Preferences** instance.|
| int OH_Preferences_SetBool (OH_Preferences \*preference, const char \*key, bool value) | Sets a Boolean value based on the specified key in a **Preferences** instance.|
| int OH_Preferences_SetString (OH_Preferences \*preference, const char \*key, const char \*value) | Sets a string based on the specified key in a **Preferences** instance.|
| int OH_Preferences_Delete (OH_Preferences \*preference, const char \*key) | Deletes the KV data corresponding to the specified key from a **Preferences** instance.|
| int OH_Preferences_RegisterDataObserver (OH_Preferences \*preference, void \*context, OH_PreferencesDataObserver observer, const char \*keys[], uint32_t keyCount) | Subscribes to data changes of the specified keys. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close()** is called.|
| int OH_Preferences_UnregisterDataObserver (OH_Preferences \*preference, void \*context, OH_PreferencesDataObserver observer, const char \*keys[], uint32_t keyCount) | Unsubscribes from data changes of the specified keys.|
| int OH_Preferences_IsStorageTypeSupported (Preferences_StorageType type, bool \*isSupported) | Checks whether the specified storage type is supported.|
| OH_PreferencesOption \* OH_PreferencesOption_Create (void) | Creates an **OH_PreferencesOption** instance and a pointer to it. If this pointer is no longer required, use **OH_PreferencesOption_Destroy** to destroy it. Otherwise, memory leaks may occur.|
| int OH_PreferencesOption_SetFileName (OH_PreferencesOption \*option, const char \*fileName) | Sets the file name for an **OH_PreferencesOption** instance. The file name cannot contain a slash (/) or exceed 255 bytes.|
| int OH_PreferencesOption_SetBundleName (OH_PreferencesOption \*option, const char \*bundleName) | Sets the bundle name for an OH_PreferencesOption instance.|
| int OH_PreferencesOption_SetDataGroupId (OH_PreferencesOption \*option, const char \*dataGroupId) | Sets the application group ID for an **OH_PreferencesOption** instance.|
| int OH_PreferencesOption_SetStorageType (OH_PreferencesOption \*option, Preferences_StorageType type) | Sets the storage type for an **OH_PreferencesOption** instance.|
| int OH_PreferencesOption_Destroy (OH_PreferencesOption \*option) | Destroys an **OH_PreferencesOption** instance.|
| const char \* OH_PreferencesPair_GetKey (const OH_PreferencesPair \*pairs, uint32_t index) | Obtains the key based on the specified index from the KV data.|
| const OH_PreferencesValue \* OH_PreferencesPair_GetPreferencesValue (const OH_PreferencesPair \*pairs, uint32_t index) | Obtains the value based on the specified index from the KV pairs.|
| Preference_ValueType OH_PreferencesValue_GetValueType (const OH_PreferencesValue \*object) | Obtains the data type of a **PreferencesValue** instance.|
| int OH_PreferencesValue_GetInt (const OH_PreferencesValue \*object, int \*value) | Obtains an integer value from an **OH_PreferencesValue** instance.|
| int OH_PreferencesValue_GetBool (const OH_PreferencesValue \*object, bool \*value) | Obtains a Boolean value from an **OH_PreferencesValue** instance.|
| int OH_PreferencesValue_GetString (const OH_PreferencesValue \*object, char \*\*value, uint32_t \*valueLen) | Obtains a string from an **OH_PreferencesValue** instance.|


## Adding Dynamic Link Libraries

Add the following library to **CMakeLists.txt**.

```txt
libohpreferences.so
```

## Including Header Files

```c
#include <cstring>
#include <database/preferences/oh_preferences.h>
#include <database/preferences/oh_preferences_err_code.h>
#include <database/preferences/oh_preferences_option.h>
#include <database/preferences/oh_preferences_value.h>
```

## How to Develop
The following example shows how to use **Preferences** APIs to modify and persist KV data.
1. Create a **PreferencesOption** instance and set the name, application group ID, bundle name, and storage type. If the **PreferencesOption** object is no longer required, call **OH_PreferencesOption_Destroy** to destroy it.
2. Call **OH_Preferences_Open** to open a **Preferences** instance. When the **Preferences** instance is not required, call **OH_Preferences_Close** to close it.
3. Call **OH_Preferences_RegisterDataObserver** to register a **DataChangeObserverCallback** callback to observe data changes of three keys.
4. Set KV data in the **Preferences** instance.
5. Obtain data in the **Preferences** instance.
6. Call **OH_Preferences_Close** to close the **Preferences** instance and set the instance pointer to null.

```c
// Callback used to return data changes.
void DataChangeObserverCallback(void *context, const OH_PreferencesPair *pairs, uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        // Obtain the value corresponding to index i.
        const OH_PreferencesValue *pValue = OH_PreferencesPair_GetPreferencesValue(pairs, i);
        // Obtain the data type of a value.
        Preference_ValueType type = OH_PreferencesValue_GetValueType(pValue);
        int ret = PREFERENCES_OK;
        if (type == PREFERENCE_TYPE_INT) {
            int intValue = 0;
            ret = OH_PreferencesValue_GetInt(pValue, &intValue);
            if (ret == PREFERENCES_OK) {
                // Service logic.
            }
        } else if (type == PREFERENCE_TYPE_BOOL) {
            bool boolValue = true;
            ret = OH_PreferencesValue_GetBool(pValue, &boolValue);
            if (ret == PREFERENCES_OK) {
                // Service logic.
            }
        } else if (type == PREFERENCE_TYPE_STRING) {
            char *stringValue = nullptr;
            uint32_t valueLen = 0;
            ret = OH_PreferencesValue_GetString(pValue, &stringValue, &valueLen);
            if (ret == PREFERENCES_OK) {
                // Service logic.
                OH_Preferences_FreeString(stringValue);
            }
        } else {
            // Invalid type.
        }
    }
}

// 1. Create a PreferencesOption instance.
OH_PreferencesOption *option = OH_PreferencesOption_Create();
if (option == nullptr) {
    // Error handling.
}
// Set the file name.
int ret = OH_PreferencesOption_SetFileName(option, "testdb");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // Error handling.
}
// Set the application group ID.
ret = OH_PreferencesOption_SetDataGroupId(option, "");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // Error handling.
}
// Set the bundle name.
ret = OH_PreferencesOption_SetBundleName(option, "com.example");
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // Error handling.
}

// Set the storage type for the PreferencesOption instance. Before the setting, call OH_Preferences_IsStorageTypeSupported to check whether the storage type is supported.
bool isGskvSupported = false;
ret = OH_Preferences_IsStorageTypeSupported(Preferences_StorageType::PREFERENCES_STORAGE_GSKV, &isGskvSupported);
if (ret != PREFERENCES_OK) {
    (void)OH_PreferencesOption_Destroy(option);
    // Error handling.
}
if (isGskvSupported) {
    ret = OH_PreferencesOption_SetStorageType(option, Preferences_StorageType::PREFERENCES_STORAGE_GSKV);
    if (ret != PREFERENCES_OK) {
        (void)OH_PreferencesOption_Destroy(option);
        // Error handling.
    }
} else {
    ret = OH_PreferencesOption_SetStorageType(option, Preferences_StorageType::PREFERENCES_STORAGE_XML);
    if (ret != PREFERENCES_OK) {
        (void)OH_PreferencesOption_Destroy(option);
        // Error handling.
    }
}

// 2. Open a Preferences instance.
int errCode = PREFERENCES_OK;
OH_Preferences *preference = OH_Preferences_Open(option, &errCode);
// Destroy the PreferencesOption instance that is no longer used, and set the instance pointer to null.
(void)OH_PreferencesOption_Destroy(option);
option = nullptr;
if (preference == nullptr || errCode != PREFERENCES_OK) {
    // Error handling.
}

// 3. Subscribe to data changes of key_int, key_bool, and key_string.
const char *keys[] = {"key_int", "key_bool", "key_string"};
ret = OH_Preferences_RegisterDataObserver(preference, nullptr, DataChangeObserverCallback, keys, 3);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // Error handling.
}

// 4. Set KV data in the Preferences instance.
ret = OH_Preferences_SetInt(preference, keys[0], 0);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // Error handling.
}
ret = OH_Preferences_SetBool(preference, keys[1], true);
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // Error handling.
}
ret = OH_Preferences_SetString(preference, keys[2], "string value");
if (ret != PREFERENCES_OK) {
    (void)OH_Preferences_Close(preference);
    // Error handling.
}

// 5. Obtain KV data from the Preferences instance.
int intValue = 0;
ret = OH_Preferences_GetInt(preference, keys[0], &intValue);
if (ret == PREFERENCES_OK) {
    // Service logic.
}

bool boolValue = false;
ret = OH_Preferences_GetBool(preference, keys[1], &boolValue);
if (ret == PREFERENCES_OK) {
    // Service logic.
}

char *stringValue = nullptr;
uint32_t valueLen = 0;
ret = OH_Preferences_GetString(preference, keys[2], &stringValue, &valueLen);
if (ret == PREFERENCES_OK) {
    // Service logic.
    // Release the string obtained by OH_Preferences_GetString.
    OH_Preferences_FreeString(stringValue);
    stringValue = nullptr;
}

// 6. Close the Preferences instance and set the pointer to null.
(void)OH_Preferences_Close(preference);
preference = nullptr;

```

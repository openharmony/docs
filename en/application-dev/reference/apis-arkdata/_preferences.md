# Preferences


## Overview

The **Preferences** module provides APIs for key-value (KV) data processing, including querying, modifying, and persisting KV data.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [oh_preferences.h](oh__preferences_8h.md) | Provides APIs and structs for accessing the **Preferences** object.| 
| [oh_preferences_err_code.h](oh__preferences__err__code_8h.md) | Defines the error codes used in the **Preferences** module. |
| [oh_preferences_option.h](oh__preferences__option_8h.md) | Provides APIs and structs for accessing the **PreferencesOption** object.| 
| [oh_preferences_value.h](oh__preferences__value_8h.md) | Provides APIs, enums, and structs for accessing the **PreferencesValue** object.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Preferences](#oh_preferences) [OH_Preferences](#oh_preferences) | Defines a struct for a **Preferences** object.| 
| typedef void(\* [OH_PreferencesDataObserver](#oh_preferencesdataobserver)) (void \*context, const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t count) | Defines a struct for the callback for data changes.| 
| typedef enum [OH_Preferences_ErrCode](#oh_preferences_errcode) [OH_Preferences_ErrCode](#oh_preferences_errcode) | Defines an enum for error codes.| 
| typedef struct [OH_PreferencesOption](#oh_preferencesoption) [OH_PreferencesOption](#oh_preferencesoption) | Defines a struct for **Preferences** configuration.| 
| typedef enum [Preference_ValueType](#preference_valuetype) [Preference_ValueType](#preference_valuetype) | Defines an enum for types of **PreferencesValue**.| 
| typedef struct [OH_PreferencesPair](#oh_preferencespair) [OH_PreferencesPair](#oh_preferencespair) | Defines a struct for the Preferences data in KV format.| 
| typedef struct [OH_PreferencesValue](#oh_preferencesvalue) [OH_PreferencesValue](#oh_preferencesvalue) | Defines the struct for a **PreferencesValue** object.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Preferences_ErrCode](#oh_preferences_errcode-1) {<br>PREFERENCES_OK = 0, PREFERENCES_ERROR_INVALID_PARAM = 401, PREFERENCES_ERROR_NOT_SUPPORTED = 801, PREFERENCES_ERROR_BASE = 15500000,<br>PREFERENCES_ERROR_DELETE_FILE = 15500010, PREFERENCES_ERROR_STORAGE = 15500011, PREFERENCES_ERROR_MALLOC = 15500012, PREFERENCES_ERROR_KEY_NOT_FOUND = 15500013,<br>PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT = 15500019<br>} | Enumerates the error codes.| 
| [Preference_ValueType](#preference_valuetype-1) {<br>PREFERENCE_TYPE_NULL = 0, PREFERENCE_TYPE_INT, PREFERENCE_TYPE_BOOL, PREFERENCE_TYPE_STRING,<br>PREFERENCE_TYPE_BUTT<br>} | Enumerates the types of **PreferencesValue**.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Preferences](#oh_preferences) \* [OH_Preferences_Open](#oh_preferences_open) ([OH_PreferencesOption](#oh_preferencesoption) \*option, int \*errCode) | Opens a **Preferences** instance and creates a pointer to it. If the pointer is no longer required, use [OH_Preferences_Close][OH_Preferences_Close](#oh_preferences_close) to close the instance.| 
| int [OH_Preferences_Close](#oh_preferences_close) ([OH_Preferences](#oh_preferences) \*preference) | Closes a **Preferences** instance.| 
| int [OH_Preferences_GetInt](#oh_preferences_getint) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, int \*value) | Obtains an integer corresponding to the specified key in a **Preferences** instance.| 
| int [OH_Preferences_GetBool](#oh_preferences_getbool) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, bool \*value) | Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.| 
| int [OH_Preferences_GetString](#oh_preferences_getstring) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | Obtains a string corresponding to the specified key in a **Preferences** instance.| 
| void [OH_Preferences_FreeString](#oh_preferences_freestring) (char \*string) | Releases a string.| 
| int [OH_Preferences_SetInt](#oh_preferences_setint) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, int value) | Sets an integer based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_SetBool](#oh_preferences_setbool) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, bool value) | Sets a Boolean value based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_SetString](#oh_preferences_setstring) ([OH_Preferences](#oh_preferences) \*preference, const char \*key, const char \*value) | Sets a string based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_Delete](#oh_preferences_delete) ([OH_Preferences](#oh_preferences) \*preference, const char \*key) | Deletes the KV data corresponding to the specified key from a **Preferences** instance.| 
| int [OH_Preferences_RegisterDataObserver](#oh_preferences_registerdataobserver) ([OH_Preferences](#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | Subscribes to data changes of the specified keys. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close ()** is called.| 
| int [OH_Preferences_UnregisterDataObserver](#oh_preferences_unregisterdataobserver) ([OH_Preferences](#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | Unsubscribes from data changes of the specified keys.| 
| [OH_PreferencesOption](#oh_preferencesoption) \* [OH_PreferencesOption_Create](#oh_preferencesoption_create) (void) | Creates an [OH_PreferencesOption](#oh_preferencesoption) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy) to destroy it. Otherwise, memory leaks may occur.| 
| int [OH_PreferencesOption_SetFileName](#oh_preferencesoption_setfilename) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*fileName) | Sets the file name for an [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_SetBundleName](#oh_preferencesoption_setbundlename) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*bundleName) | Sets the bundle name for an [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_SetDataGroupId](#oh_preferencesoption_setdatagroupid) ([OH_PreferencesOption](#oh_preferencesoption) \*option, const char \*dataGroupId) | Sets the application group ID for an [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy) ([OH_PreferencesOption](#oh_preferencesoption) \*option) | Destroys an [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| const char \* [OH_PreferencesPair_GetKey](#oh_preferencespair_getkey) (const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t index) | Obtains the key based on the specified index from the KV data.| 
| const [OH_PreferencesValue](#oh_preferencesvalue) \* [OH_PreferencesPair_GetPreferencesValue](#oh_preferencespair_getpreferencesvalue) (const [OH_PreferencesPair](#oh_preferencespair) \*pairs, uint32_t index) | Obtains the value based on the specified index from the KV pairs.| 
| [Preference_ValueType](#preference_valuetype) [OH_PreferencesValue_GetValueType](#oh_preferencesvalue_getvaluetype) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object) | Obtains the data type of a **PreferencesValue** instance.| 
| int [OH_PreferencesValue_GetInt](#oh_preferencesvalue_getint) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, int \*value) | Obtains an integer value from an [OH_PreferencesValue](#oh_preferencesvalue) instance.| 
| int [OH_PreferencesValue_GetBool](#oh_preferencesvalue_getbool) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, bool \*value) | Obtains a Boolean value from an [OH_PreferencesValue](#oh_preferencesvalue) instance.| 
| int [OH_PreferencesValue_GetString](#oh_preferencesvalue_getstring) (const [OH_PreferencesValue](#oh_preferencesvalue) \*object, char \*\*value, uint32_t \*valueLen) | Obtains a string from an [OH_PreferencesValue](#oh_preferencesvalue) instance.| 


## Type Description


### OH_Preferences

```
typedef struct OH_Preferences OH_Preferences
```

**Description**

Represents a **Preferences** object.

**Since**: 13


### OH_Preferences_ErrCode

```
typedef enum OH_Preferences_ErrCode OH_Preferences_ErrCode
```

**Description**

Defines an enum for error codes.

**Since**: 13


### OH_PreferencesDataObserver

```
typedef void(*OH_PreferencesDataObserver) (void *context, const OH_PreferencesPair *pairs, uint32_t count)
```

**Description**

Defines a struct for the callback used to return data changes.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| context | Pointer to the application context.| 
| pairs | Pointer to the changed KV data.| 
| count | Number of KV pairs changed.| 

**See**

[OH_PreferencesPair](#oh_preferencespair)


### OH_PreferencesOption

```
typedef struct OH_PreferencesOption OH_PreferencesOption
```

**Description**

Defines a struct for **Preferences** configuration.

**Since**: 13


### OH_PreferencesPair

```
typedef struct OH_PreferencesPair OH_PreferencesPair
```

**Description**

Defines a struct for the **Preferences** data in KV format.

**Since**: 13


### OH_PreferencesValue

```
typedef struct OH_PreferencesValue OH_PreferencesValue
```

**Description**

Defines the struct for a **PreferencesValue** object.

**Since**: 13


### Preference_ValueType

```
typedef enum Preference_ValueType Preference_ValueType
```

**Description**

Defines an enum for types of **PreferencesValue**.

**Since**: 13


## Enum Description


### OH_Preferences_ErrCode

```
enum OH_Preferences_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 13

| Enumerated Value| Description| 
| -------- | -------- |
| PREFERENCES_OK | The operation is successful.| 
| PREFERENCES_ERROR_INVALID_PARAM | Invalid parameter.| 
| PREFERENCES_ERROR_NOT_SUPPORTED | The system capability is not supported.| 
| PREFERENCES_ERROR_BASE | Base error code.| 
| PREFERENCES_ERROR_DELETE_FILE | Failed to delete the file.| 
| PREFERENCES_ERROR_STORAGE | The storage is abnormal.| 
| PREFERENCES_ERROR_MALLOC | Failed to allocate memory.| 
| PREFERENCES_ERROR_KEY_NOT_FOUND | The key does not exist.| 
| PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT | Failed to obtain the data change subscription service.| 


### Preference_ValueType

```
enum Preference_ValueType
```

**Description**

Enumerates the types of **PreferencesValue**.

**Since**: 13

| Enumerated Value| Description| 
| -------- | -------- |
| PREFERENCE_TYPE_NULL | Null.| 
| PREFERENCE_TYPE_INT | Integer.| 
| PREFERENCE_TYPE_BOOL | Boolean.| 
| PREFERENCE_TYPE_STRING | String.| 
| PREFERENCE_TYPE_BUTT | End type.| 


## Function Description


### OH_Preferences_Close()

```
int OH_Preferences_Close (OH_Preferences *preference)
```

**Description**

Closes a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the [OH_Preferences](#oh_preferences) instance to close.| 

**Returns**

Returns [OH_Preferences_ErrCode](#oh_preferences_errcode).

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_Delete()

```
int OH_Preferences_Delete (OH_Preferences *preference, const char *key )
```

**Description**

Deletes the KV data corresponding to the specified key from a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the KV pair to delete.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_FreeString()

```
void OH_Preferences_FreeString (char *string)
```

**Description**

Releases a string.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| string | Pointer to the string to release.| 

**See**

[OH_Preferences](#oh_preferences)


### OH_Preferences_GetBool()

```
int OH_Preferences_GetBool (OH_Preferences *preference, const char *key, bool *value )
```

**Description**

Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to obtain.| 
| value | Pointer to the Boolean value obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

Returns **PREFERENCES_ERROR_KEY_NOT_FOUND** if the specified key does not exist.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_GetInt()

```
int OH_Preferences_GetInt (OH_Preferences *preference, const char *key, int *value )
```

**Description**

Obtains an integer corresponding to the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to obtain.| 
| value | Pointer to the integer value obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

Returns **PREFERENCES_ERROR_KEY_NOT_FOUND** if the specified key does not exist.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_GetString()

```
int OH_Preferences_GetString (OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen )
```

**Description**

Obtains a string corresponding to the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to obtain.| 
| value | Double pointer to the string obtained. If the string is not required, you can use [OH_Preferences_FreeString](#oh_preferences_freestring) to free the string (release the memory occupied by the string).| 
| valueLen | Pointer to the length of the string obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

Returns **PREFERENCES_ERROR_KEY_NOT_FOUND** if the specified key does not exist.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_Open()

```
OH_Preferences* OH_Preferences_Open (OH_PreferencesOption *option, int *errCode )
```

**Description**

Opens a **Preferences** instance and creates a pointer to it. If the pointer is no longer required, use [OH_Preferences_Close](#oh_preferences_close) to close the instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| option | Pointer to the [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| errCode | Pointer to the error code returned. For details, see [OH_Preferences_ErrCode](#oh_preferences_errcode).| 

**Returns**

Returns the [OH_Preferences](#oh_preferences) instance opened if the operation is successful; returns a null pointer otherwise.

**See**

[OH_Preferences](#oh_preferences)

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_RegisterDataObserver()

```
int OH_Preferences_RegisterDataObserver (OH_Preferences *preference, void *context, OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount )
```

**Description**

Subscribes to data changes of the specified keys. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close ()** is called.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| context | Pointer to the application context.| 
| observer | [OH_PreferencesDataObserver](#oh_preferencesdataobserver) callback to be invoked when the data changes.| 
| keys | Pointer to the keys of the data to be observed.| 
| keyCount | Number of keys observed.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

Returns **PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT** if the data change subscription service fails to be obtained.

**See**

[OH_Preferences](#oh_preferences)

[OH_PreferencesDataObserver](#oh_preferencesdataobserver)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetBool()

```
int OH_Preferences_SetBool (OH_Preferences *preference, const char *key, bool value )
```

**Description**

Sets a Boolean value based on the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to set.| 
| value | Boolean value to be set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetInt()

```
int OH_Preferences_SetInt (OH_Preferences *preference, const char *key, int value )
```

**Description**

Sets an integer based on the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to set.| 
| value | Integer value to be set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_SetString()

```
int OH_Preferences_SetString (OH_Preferences *preference, const char *key, const char *value )
```

**Description**

Sets a string based on the specified key in a **Preferences** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| key | Pointer to the key of the value to set.| 
| value | Pointer to the string to set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_Preferences_UnregisterDataObserver()

```
int OH_Preferences_UnregisterDataObserver (OH_Preferences *preference, void *context, OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount )
```

**Description**

Unsubscribes from data changes of the specified keys.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| preference | Pointer to the target [OH_Preferences](#oh_preferences) instance.| 
| context | Pointer to the application context.| 
| observer | [OH_PreferencesDataObserver](#oh_preferencesdataobserver) callback to unregister.|
| keys | Pointer to the keys of the values whose changes are not observed.| 
| keyCount | Number of keys.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_Preferences](#oh_preferences)

[OH_PreferencesDataObserver](#oh_preferencesdataobserver)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_Create()

```
OH_PreferencesOption* OH_PreferencesOption_Create (void )
```

**Description**

Creates an [OH_PreferencesOption](#oh_preferencesoption) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_PreferencesOption_Destroy](#oh_preferencesoption_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

Returns a pointer to the [OH_PreferencesOption](#oh_preferencesoption) instance created if the operation is successful; returns a null pointer otherwise.

**See**

[OH_PreferencesOption](#oh_preferencesoption)


### OH_PreferencesOption_Destroy()

```
int OH_PreferencesOption_Destroy (OH_PreferencesOption *option)
```

**Description**

Destroys an [OH_PreferencesOption](#oh_preferencesoption) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| option | Pointer to the [OH_PreferencesOption](#oh_preferencesoption) instance to destroy.| 

**Returns**

Returns the error code. 
Returns **PREFERENCES_OK** if the operation is successful. 
Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

**See**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetBundleName()

```
int OH_PreferencesOption_SetBundleName (OH_PreferencesOption *option, const char *bundleName )
```

**Description**

Sets the bundle name for an [OH_PreferencesOption](#oh_preferencesoption) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| option | Pointer to the target [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| bundleName | Pointer to the bundle name to set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

**See**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetDataGroupId()

```
int OH_PreferencesOption_SetDataGroupId (OH_PreferencesOption *option, const char *dataGroupId )
```

**Description**

Sets the application group ID for an [OH_PreferencesOption](#oh_preferencesoption) instance.

After the application group ID is set, the **Preferences** instance will be created in the sandbox directory of the application group ID.

The application group ID must be obtained from AppGallery. This parameter is not supported currently.

If the application group ID is an empty string, the **Preferences** instance will be created in the sandbox directory of the current application.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| option | Pointer to the target [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| dataGroupId | Pointer to the application group ID to set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

**See**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesOption_SetFileName()

```
int OH_PreferencesOption_SetFileName (OH_PreferencesOption *option, const char *fileName )
```

**Description**

Sets the file name for an [OH_PreferencesOption](#oh_preferencesoption) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| option | Pointer to the target [OH_PreferencesOption](#oh_preferencesoption) instance.| 
| fileName | Pointer to the file name to set.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

**See**

[OH_PreferencesOption](#oh_preferencesoption)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesPair_GetKey()

```
const char* OH_PreferencesPair_GetKey (const OH_PreferencesPair *pairs, uint32_t index )
```

**Description**

Obtains the key based on the specified index from the KV data.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| pairs | Pointer to the target [OH_PreferencesPair](#oh_preferencespair).| 
| index | Index of the target [OH_PreferencesPair](#oh_preferencespair).| 

**Returns**

Returns the pointer to the key obtained if the operation is successful. 
Returns a null pointer if the operation fails or the input parameter is invalid.

**See**

[OH_PreferencesPair](#oh_preferencespair)


### OH_PreferencesPair_GetPreferencesValue()

```
const OH_PreferencesValue* OH_PreferencesPair_GetPreferencesValue (const OH_PreferencesPair *pairs, uint32_t index )
```

**Description**

Obtains the value based on the specified index from the KV pairs.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| pairs | Pointer to the target [OH_PreferencesPair](#oh_preferencespair).| 
| index | Index of the target [OH_PreferencesPair](#oh_preferencespair).| 

**Returns**

Returns the pointer to the value obtained if the operation is successful. 
Returns a null pointer if the operation fails or the input parameter is invalid.

**See**

[OH_PreferencesValue](#oh_preferencesvalue)


### OH_PreferencesValue_GetBool()

```
int OH_PreferencesValue_GetBool (const OH_PreferencesValue *object, bool *value )
```

**Description**

Obtains a Boolean value from an [OH_PreferencesValue](#oh_preferencesvalue) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| object | Pointer to the target [OH_PreferencesValue](#oh_preferencesvalue) instance.| 
| value | Pointer to the Boolean value obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetInt()

```
int OH_PreferencesValue_GetInt (const OH_PreferencesValue* object, int* value )
```

**Description**

Obtains an integer from an [OH_PreferencesValue](#oh_preferencesvalue) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| object | Pointer to the target [OH_PreferencesValue](#oh_preferencesvalue) instance.| 
| value | Pointer to the integer value obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetString()

```
int OH_PreferencesValue_GetString (const OH_PreferencesValue *object, char **value, uint32_t *valueLen )
```

**Description**

Obtains a string from an [OH_PreferencesValue](#oh_preferencesvalue) instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| object | Pointer to the target [OH_PreferencesValue](#oh_preferencesvalue) instance.| 
| value | Double pointer to the string obtained. If the string is not required, you can use [OH_Preferences_FreeString](#oh_preferences_freestring) to free the string (release the memory occupied by the string).| 
| valueLen | Pointer to the length of the string obtained.| 

**Returns**

Returns the error code.

Returns **PREFERENCES_OK** if the operation is successful.

Returns **PREFERENCES_ERROR_INVALID_PARAM** if invalid parameters are detected.

Returns **PREFERENCES_ERROR_STORAGE** if the storage is abnormal.

Returns **PREFERENCES_ERROR_MALLOC** if memory allocation fails.

**See**

[OH_PreferencesValue](#oh_preferencesvalue)

[OH_Preferences_ErrCode](#oh_preferences_errcode)


### OH_PreferencesValue_GetValueType()

```
Preference_ValueType OH_PreferencesValue_GetValueType (const OH_PreferencesValue *object)
```

**Description**

Obtains the data type of a **PreferencesValue** instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| object | Pointer to the target [OH_PreferencesValue](#oh_preferencesvalue) instance.| 

**Returns**

Returns the obtained data type. If **PREFERENCE_TYPE_NULL** is returned, invalid parameter is passed in.

**See**

[OH_PreferencesValue](#oh_preferencesvalue)

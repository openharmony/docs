# oh_preferences.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @yanhuii-->
<!--Designer: @houpengtao1-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Provides APIs and structs for accessing the **Preferences** object.

**File to include**: <database/preferences/oh_preferences.h>

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

**Related module**: [Preferences](capi-preferences.md)

## Summary

### Structs

| Name                                    | typedef Keyword | Description                     |
| ---------------------------------------- | -------------- | ------------------------- |
| [OH_Preferences](capi-preferences-oh-preferences.md) | OH_Preferences | Defines a struct for a **Preferences** object.|

### Functions

| Name                                                        | typedef Keyword             | Description                                                        |
| ------------------------------------------------------------ | -------------------------- | ------------------------------------------------------------ |
| [typedef void (\*OH_PreferencesDataObserver)(void *context, const OH_PreferencesPair *pairs, uint32_t count)](#oh_preferencesdataobserver) | OH_PreferencesDataObserver | Defines a struct for the callback for data changes.                            |
| [OH_Preferences *OH_Preferences_Open(OH_PreferencesOption *option, int *errCode)](#oh_preferences_open) | -                          | Opens a **Preferences** instance and creates a pointer to it.<br>If this pointer is no longer required, use [OH_Preferences_Close](capi-oh-preferences-h.md#oh_preferences_close) to close the instance.|
| [int OH_Preferences_Close(OH_Preferences *preference)](#oh_preferences_close) | -                          | Closes a **Preferences** instance.                               |
| [int OH_Preferences_GetInt(OH_Preferences *preference, const char *key, int *value)](#oh_preferences_getint) | -                          | Obtains an integer corresponding to the specified key in a **Preferences** instance.                  |
| [int OH_Preferences_GetBool(OH_Preferences *preference, const char *key, bool *value)](#oh_preferences_getbool) | -                          | Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.                  |
| [int OH_Preferences_GetString(OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen)](#oh_preferences_getstring) | -                          | Obtains a string corresponding to the specified key in a **Preferences** instance.                  |
| [void OH_Preferences_FreeString(char *string)](#oh_preferences_freestring) | -                          | Releases a string obtained from a **Preferences** instance.                   |
| [int OH_Preferences_SetInt(OH_Preferences *preference, const char *key, int value)](#oh_preferences_setint) | -                          | Sets an integer based on the specified key in a **Preferences** instance.                  |
| [int OH_Preferences_SetBool(OH_Preferences *preference, const char *key, bool value)](#oh_preferences_setbool) | -                          | Sets a Boolean value based on the specified key in a **Preferences** instance.                  |
| [int OH_Preferences_SetString(OH_Preferences *preference, const char *key, const char *value)](#oh_preferences_setstring) | -                          | Sets a string based on the specified key in a **Preferences** instance.                  |
| [int OH_Preferences_Delete(OH_Preferences *preference, const char *key)](#oh_preferences_delete) | -                          | Deletes the KV data corresponding to the specified key from a **Preferences** instance.                |
| [int OH_Preferences_RegisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)](#oh_preferences_registerdataobserver) | -                          | Subscribes to data changes of the specified keys. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close()** is called.|
| [int OH_Preferences_UnregisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)](#oh_preferences_unregisterdataobserver) | -                          | Unsubscribes from data changes of the specified keys.                             |
| [int OH_Preferences_IsStorageTypeSupported(Preferences_StorageType type, bool *isSupported)](#oh_preferences_isstoragetypesupported) | -                          | Checks whether the specified storage type is supported.                          |

## Function Description

### OH_PreferencesDataObserver()

```
typedef void (*OH_PreferencesDataObserver)(void *context, const OH_PreferencesPair *pairs, uint32_t count)
```

**Description**

Defines a struct for the callback for data changes.

**Since**: 13


**Parameters**

| Name                                                      | Description                    |
| ------------------------------------------------------------ | ------------------------ |
| void *context                                                | Pointer to the application context.      |
| const [OH_PreferencesPair](capi-preferences-oh-preferencespair.md) *pairs | Pointer to the changed KV data.|
| uint32_t count                                               | Number of KV pairs changed.|

### OH_Preferences_Open()

```
OH_Preferences *OH_Preferences_Open(OH_PreferencesOption *option, int *errCode)
```

**Description**

Opens a **Preferences** instance and creates a pointer to it.<br>If this pointer is no longer required, use [OH_Preferences_Close](capi-oh-preferences-h.md#oh_preferences_close) to close the instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| int *errCode                                                 | Pointer to the error code returned. For details, see [OH_Preferences_ErrCode](capi-oh-preferences-err-code-h.md#oh_preferences_errcode).<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_NOT_SUPPORTED** indicates the system capability is not supported.<br>**PREFERENCES_ERROR_DELETE_FILE** indicates the file fails to be deleted.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

**Returns**

| Type                                    | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) | Returns a pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance opened if the operation is successful; returns a null pointer otherwise.|

### OH_Preferences_Close()

```
int OH_Preferences_Close(OH_Preferences *preference)
```

**Description**

Closes a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance to close.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code. For details, see [OH_Preferences_ErrCode](capi-oh-preferences-err-code-h.md#oh_preferences_errcode).<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_Preferences_GetInt()

```
int OH_Preferences_GetInt(OH_Preferences *preference, const char *key, int *value)
```

**Description**

Obtains an integer corresponding to the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to obtain.                                       |
| int *value                                           | Pointer to the integer value obtained.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.<br>**PREFERENCES_ERROR_KEY_NOT_FOUND** indicates the specified key does not exist.|

### OH_Preferences_GetBool()

```
int OH_Preferences_GetBool(OH_Preferences *preference, const char *key, bool *value)
```

**Description**

Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to obtain.                                       |
| bool *value                                          | Pointer to the Boolean value obtained.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.<br>**PREFERENCES_ERROR_KEY_NOT_FOUND** indicates the specified key does not exist.|

### OH_Preferences_GetString()

```
int OH_Preferences_GetString(OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen)
```

**Description**

Obtains a string corresponding to the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to obtain.                                       |
| char **value                                         | Double pointer to the string obtained. If the string is not required, you can use [OH_Preferences_FreeString](capi-oh-preferences-h.md#oh_preferences_freestring) to free the string (release the memory occupied by the string).|
| uint32_t *valueLen                                   | Pointer to the length of the string obtained.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.<br>**PREFERENCES_ERROR_KEY_NOT_FOUND** indicates the specified key does not exist.|

### OH_Preferences_FreeString()

```
void OH_Preferences_FreeString(char *string)
```

**Description**

Releases a string obtained from a **Preferences** instance.

**Since**: 13


**Parameters**

| Name      | Description                  |
| ------------ | ---------------------- |
| char *string | Pointer to the string to release.|

### OH_Preferences_SetInt()

```
int OH_Preferences_SetInt(OH_Preferences *preference, const char *key, int value)
```

**Description**

Sets an integer based on the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to set.                                   |
| int value                                            | Integer value to be set.                                          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_Preferences_SetBool()

```
int OH_Preferences_SetBool(OH_Preferences *preference, const char *key, bool value)
```

**Description**

Sets a Boolean value based on the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to set.                                   |
| bool value                                           | Boolean value to be set.                                          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_Preferences_SetString()

```
int OH_Preferences_SetString(OH_Preferences *preference, const char *key, const char *value)
```

**Description**

Sets a string based on the specified key in a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the value to set.                                   |
| const char *value                                    | Pointer to the string to set.                                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_Preferences_Delete()

```
int OH_Preferences_Delete(OH_Preferences *preference, const char *key)
```

**Description**

Deletes the KV data corresponding to the specified key from a **Preferences** instance.

**Since**: 13


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| const char *key                                      | Pointer to the key of the KV pair to delete.                                   |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

**See**

OH_Preferences_ErrCode

### OH_Preferences_RegisterDataObserver()

```
int OH_Preferences_RegisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)
```

**Description**

Subscribes to data changes of the specified keys. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close()** is called.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference         | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| void *context                                                | Pointer to the application context.                                          |
| [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer | [OH_PreferencesDataObserver](capi-oh-preferences-h.md#oh_preferencesdataobserver) callback to be invoked when data changes.|
| const char *keys[]                                           | Pointer to the keys of the data to be observed.                                         |
| uint32_t keyCount                                            | Number of keys observed.                                       |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.<br>**PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT** indicates a failure in obtaining the data change subscription service.|

### OH_Preferences_UnregisterDataObserver()

```
int OH_Preferences_UnregisterDataObserver(OH_Preferences *preference, void *context,OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount)
```

**Description**

Unsubscribes from data changes of the specified keys.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Preferences](capi-preferences-oh-preferences.md) *preference         | Pointer to the [OH_Preferences](capi-preferences-oh-preferences.md) instance.|
| void *context                                                | Pointer to the application context.                                          |
| [OH_PreferencesDataObserver](#oh_preferencesdataobserver) observer | [OH_PreferencesDataObserver](capi-oh-preferences-h.md#oh_preferencesdataobserver) callback to unregister.|
| const char *keys[]                                           | Pointer to the keys whose changes are not observed.                                     |
| uint32_t keyCount                                            | Number of keys.                                   |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

**See**

OH_Preferences_ErrCode

### OH_Preferences_IsStorageTypeSupported()

```
int OH_Preferences_IsStorageTypeSupported(Preferences_StorageType type, bool *isSupported)
```


**Since**: 18


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Preferences_StorageType](capi-oh-preferences-option-h.md#preferences_storagetype) type | Storage type to check.                                  |
| bool *isSupported                                            | Pointer to the check result. The value **true** means the storage type is supported; the value **false** means the opposite.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Operation status code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

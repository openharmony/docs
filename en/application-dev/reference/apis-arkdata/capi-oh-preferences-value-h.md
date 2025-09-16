# oh_preferences_value.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @yanhuii-->
<!--Designer: @houpengtao1-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Provides APIs, enums, and structs for accessing the **PreferencesValue** object.

**File to include**: <database/preferences/oh_preferences_value.h>

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

**Related module**: [Preferences](capi-preferences.md)

## Summary

### Structs

| Name                                              | typedef Keyword      | Description                                 |
| -------------------------------------------------- | ------------------- | ------------------------------------- |
| [OH_PreferencesPair](capi-preferences-oh-preferencespair.md)   | OH_PreferencesPair  | Defines a struct for the **Preferences** data in KV format.|
| [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) | OH_PreferencesValue | Defines a struct for the **PreferencesValue** object.       |

### Enums

| Name                                         | typedef Keyword       | Description                            |
| --------------------------------------------- | -------------------- | -------------------------------- |
| [Preference_ValueType](#preference_valuetype) | Preference_ValueType | Enumerates the data types of **PreferencesValue**.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [const char *OH_PreferencesPair_GetKey(const OH_PreferencesPair *pairs, uint32_t index)](#oh_preferencespair_getkey) | Obtains the key based on the specified index from the KV data.                              |
| [const OH_PreferencesValue *OH_PreferencesPair_GetPreferencesValue(const OH_PreferencesPair *pairs, uint32_t index)](#oh_preferencespair_getpreferencesvalue) | Obtains the value based on the specified index from the KV pairs.                              |
| [Preference_ValueType OH_PreferencesValue_GetValueType(const OH_PreferencesValue *object)](#oh_preferencesvalue_getvaluetype) | Obtains the data type of an **OH_PreferencesValue** instance.                        |
| [int OH_PreferencesValue_GetInt(const OH_PreferencesValue *object, int *value)](#oh_preferencesvalue_getint) | Obtains an integer from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|
| [int OH_PreferencesValue_GetBool(const OH_PreferencesValue *object, bool *value)](#oh_preferencesvalue_getbool) | Obtains a Boolean value from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|
| [int OH_PreferencesValue_GetString(const OH_PreferencesValue *object, char **value, uint32_t *valueLen)](#oh_preferencesvalue_getstring) | Obtains a string from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|

## Enum Description

### Preference_ValueType

```
enum Preference_ValueType
```

**Description**

Enumerates the data types of **PreferencesValue**.

**Since**: 13

| Enum Item                  | Description        |
| ------------------------ | ------------ |
| PREFERENCE_TYPE_NULL = 0 | Null.    |
| PREFERENCE_TYPE_INT      | Integer.  |
| PREFERENCE_TYPE_BOOL     | Boolean.  |
| PREFERENCE_TYPE_STRING   | String.|
| PREFERENCE_TYPE_BUTT     | End type.  |


## Function Description

### OH_PreferencesPair_GetKey()

```
const char *OH_PreferencesPair_GetKey(const OH_PreferencesPair *pairs, uint32_t index)
```

**Description**

Obtains the key based on the specified index from the KV data.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesPair](capi-preferences-oh-preferencespair.md) *pairs | Pointer to the target [OH_PreferencesPair](capi-preferences-oh-preferencespair.md).|
| uint32_t index                                               | Index of the target [OH_PreferencesPair](capi-preferences-oh-preferencespair.md).|

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char * | Returns the pointer to the key obtained if the operation is successful; returns a null pointer if the operation fails or invalid parameters are specified.|

### OH_PreferencesPair_GetPreferencesValue()

```
const OH_PreferencesValue *OH_PreferencesPair_GetPreferencesValue(const OH_PreferencesPair *pairs, uint32_t index)
```

**Description**

Obtains the value based on the specified index from the KV pairs.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesPair](capi-preferences-oh-preferencespair.md) *pairs | Pointer to the target [OH_PreferencesPair](capi-preferences-oh-preferencespair.md).|
| uint32_t index                                               | Index of the target [OH_PreferencesPair](capi-preferences-oh-preferencespair.md).|

**Returns**

| Type                                                    | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| const [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) | Returns the pointer to the value obtained if the operation is successful; returns a null pointer if the operation fails or invalid parameters are specified.|


### OH_PreferencesValue_GetValueType()

```
Preference_ValueType OH_PreferencesValue_GetValueType(const OH_PreferencesValue *object)
```

**Description**

Obtains the data type of a **PreferencesValue** instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) *object | Pointer to the [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|

**Returns**

| Type                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [Preference_ValueType](#preference_valuetype) | Returns the obtained data type. If **PREFERENCE_TYPE_NULL** is returned, invalid parameters are passed in.|

### OH_PreferencesValue_GetInt()

```
int OH_PreferencesValue_GetInt(const OH_PreferencesValue *object, int *value)
```

**Description**

Obtains an integer from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) *object | Pointer to the [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|
| int *value                                                   | Pointer to the integer value obtained.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_PreferencesValue_GetBool()

```
int OH_PreferencesValue_GetBool(const OH_PreferencesValue *object, bool *value)
```

**Description**

Obtains a Boolean value from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) *object | Pointer to the [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|
| bool *value                                                  | Pointer to the Boolean value obtained.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

### OH_PreferencesValue_GetString()

```
int OH_PreferencesValue_GetString(const OH_PreferencesValue *object, char **value, uint32_t *valueLen)
```

**Description**

Obtains a string from an [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) *object | Pointer to the [OH_PreferencesValue](capi-preferences-oh-preferencesvalue.md) instance.|
| char **value                                                 | Double pointer to the string obtained. If the string is not required, you can use [OH_Preferences_FreeString](capi-oh-preferences-h.md#oh_preferences_freestring) to free the string (release the memory occupied by the string).|
| uint32_t *valueLen                                           | Pointer to the length of the string obtained.      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.<br>**PREFERENCES_ERROR_STORAGE** indicates the storage is abnormal.<br>**PREFERENCES_ERROR_MALLOC** indicates a failure in memory allocation.|

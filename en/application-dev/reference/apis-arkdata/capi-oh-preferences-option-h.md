# oh_preferences_option.h

## Overview

Provides APIs and structs for accessing the **PreferencesOption** object.

**File to include**: <database/preferences/oh_preferences_option.h>

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

**Related module**: [Preferences](capi-preferences.md)

## Summary

### Structs

| Name                                                | typedef Keyword       | Description                               |
| ---------------------------------------------------- | -------------------- | ----------------------------------- |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) | OH_PreferencesOption | Defines a struct for **Preferences** configuration.|

### Enums

| Name                                               | typedef Keyword          | Description                          |
| --------------------------------------------------- | ----------------------- | ------------------------------ |
| [Preferences_StorageType](#preferences_storagetype) | Preferences_StorageType | Enumerates the preferences storage types.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption *OH_PreferencesOption_Create(void)](#oh_preferencesoption_create) | Creates a [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_PreferencesOption_Destroy](capi-oh-preferences-option-h.md#oh_preferencesoption_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [int OH_PreferencesOption_SetFileName(OH_PreferencesOption *option, const char *fileName)](#oh_preferencesoption_setfilename) | Sets the file name for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| [int OH_PreferencesOption_SetBundleName(OH_PreferencesOption *option, const char *bundleName)](#oh_preferencesoption_setbundlename) | Sets the bundle name for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| [int OH_PreferencesOption_SetDataGroupId(OH_PreferencesOption *option, const char *dataGroupId)](#oh_preferencesoption_setdatagroupid) | Sets the application group ID for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.<br>After the application group ID is set, the **Preferences** instance will be created in the sandbox directory of the application group ID. The application group ID must be obtained from AppGallery. This parameter is not supported currently.<br>If the application group ID is an empty string, the **Preferences** instance will be created in the sandbox directory of the current application.|
| [int OH_PreferencesOption_SetStorageType(OH_PreferencesOption *option, Preferences_StorageType type)](#oh_preferencesoption_setstoragetype) | Sets the storage type for a **Preferences** instance.                         |
| [int OH_PreferencesOption_Destroy(OH_PreferencesOption *option)](#oh_preferencesoption_destroy) | Destroys an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|

## Enum Description

### Preferences_StorageType

```
enum Preferences_StorageType
```

**Description**

Enumerates the preferences storage types.

**Since**: 18

| Enum                     | Description                                                        |
| --------------------------- | ------------------------------------------------------------ |
| PREFERENCES_STORAGE_XML = 0 | XML. In this type is used, data operations are performed in the memory and data is persisted after [OH_Preferences_Close](capi-oh-preferences-h.md#oh_preferences_close) is called. This type does not multi-processes operations.|
| PREFERENCES_STORAGE_GSKV    | CLKV. If this type is used, data operations are flushed on a real-time basis. This type supports multi-process operations.            |


## Function Description

### OH_PreferencesOption_Create()

```
OH_PreferencesOption *OH_PreferencesOption_Create(void)
```

**Description**

Creates a [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_PreferencesOption_Destroy](capi-oh-preferences-option-h.md#oh_preferencesoption_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) | Returns a pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance created if the operation is successful; returns a null pointer otherwise.|

### OH_PreferencesOption_SetFileName()

```
int OH_PreferencesOption_SetFileName(OH_PreferencesOption *option, const char *fileName)
```

**Description**

Sets the file name for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| const char *fileName                                         | Pointer to the file name to set.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

**See**

OH_Preferences_ErrCode

### OH_PreferencesOption_SetBundleName()

```
int OH_PreferencesOption_SetBundleName(OH_PreferencesOption *option, const char *bundleName)
```

**Description**

Sets the bundle name for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| const char *bundleName                                       | Pointer to the bundle name to set.                                          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

### OH_PreferencesOption_SetDataGroupId()

```
int OH_PreferencesOption_SetDataGroupId(OH_PreferencesOption *option, const char *dataGroupId)
```

**Description**

Sets the application group ID for an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.<br>After the application group ID is set, the **Preferences** instance will be created in the sandbox directory of the application group ID. The application group ID must be obtained from AppGallery. This parameter is not supported currently.<br>If the application group ID is an empty string, the **Preferences** instance will be created in the sandbox directory of the current application.

**Since**: 13

**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|
| const char *dataGroupId                                      | Pointer to the application group ID to set.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

### OH_PreferencesOption_SetStorageType()

```
int OH_PreferencesOption_SetStorageType(OH_PreferencesOption *option, Preferences_StorageType type)
```

**Description**

Sets the storage type for a **Preferences** instance.

**Since**: 18


**Parameters**

| Name                                                      | Description                              |
| ------------------------------------------------------------ | ---------------------------------- |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the configuration whose storage type is to set.|
| [Preferences_StorageType](#preferences_storagetype) type     | Storage type to set.              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

### OH_PreferencesOption_Destroy()

```
int OH_PreferencesOption_Destroy(OH_PreferencesOption *option)
```

**Description**

Destroys an [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.

**Since**: 13


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) *option | Pointer to the [OH_PreferencesOption](capi-preferences-oh-preferencesoption.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Operation status code.<br>**PREFERENCES_OK** indicates the operation is successful.<br>**PREFERENCES_ERROR_INVALID_PARAM** indicates invalid parameters are specified.|

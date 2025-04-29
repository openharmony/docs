# oh_preferences_option.h


## Overview

Provides APIs and structs for accessing the **PreferencesOption** object.

**File to include**: &lt;database/preferences/oh_preferences_option.h&gt;

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

Related module: [Preferences](_preferences.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_PreferencesOption](_preferences.md#oh_preferencesoption) [OH_PreferencesOption](_preferences.md#oh_preferencesoption) | Defines a **PreferencesOption** object.| 
| typedef enum [Preferences_StorageType](_preferences.md#preferences_storagetype) [Preferences_StorageType](_preferences.md#preferences_storagetype) | Defines an enum for preferences storage types. | 

### Enums

| Name| Description| 
| -------- | -------- |
| [Preferences_StorageType](_preferences.md#preferences_storagetype-1) { PREFERENCES_STORAGE_XML = 0, PREFERENCES_STORAGE_GSKV } | Enumerates the preferences storage types. | 

### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_PreferencesOption_SetStorageType](_preferences.md#oh_preferencesoption_setstoragetype) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, [Preferences_StorageType](_preferences.md#preferences_storagetype) type) | Sets the storage type for a preferences instance. | 
| [OH_PreferencesOption](_preferences.md#oh_preferencesoption) \* [OH_PreferencesOption_Create](_preferences.md#oh_preferencesoption_create) (void) | Creates an [OH_PreferencesOption](_preferences.md#oh_preferencesoption) instance and a pointer to it. If this pointer is no longer required, use [OH_PreferencesOption_Destroy](_preferences.md#oh_preferencesoption_destroy) to destroy it. Otherwise, memory leaks may occur.| 
| int [OH_PreferencesOption_SetFileName](_preferences.md#oh_preferencesoption_setfilename) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*fileName) | Sets the file name for an [OH_PreferencesOption](_preferences.md#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_SetBundleName](_preferences.md#oh_preferencesoption_setbundlename) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*bundleName) | Sets the bundle name for an [OH_PreferencesOption](_preferences.md#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_SetDataGroupId](_preferences.md#oh_preferencesoption_setdatagroupid) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, const char \*dataGroupId) | Sets the application group ID for an [OH_PreferencesOption](_preferences.md#oh_preferencesoption) instance.| 
| int [OH_PreferencesOption_Destroy](_preferences.md#oh_preferencesoption_destroy) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option) | Destroys an [OH_PreferencesOption](_preferences.md#oh_preferencesoption) instance.| 

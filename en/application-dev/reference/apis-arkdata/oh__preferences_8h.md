# oh_preferences.h


## Overview

Provides APIs and structs for accessing the **Preferences** object.

**File to include**: &lt;database/preferences/oh_preferences.h&gt;

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

Related module: [Preferences](_preferences.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Preferences](_preferences.md#oh_preferences) [OH_Preferences](_preferences.md#oh_preferences) | Defines a **Preferences** object.| 
| typedef void(\* [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver)) (void \*context, const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t count) | Defines the callback to be invoked when data changes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Preferences](_preferences.md#oh_preferences) \* [OH_Preferences_Open](_preferences.md#oh_preferences_open) ([OH_PreferencesOption](_preferences.md#oh_preferencesoption) \*option, int \*errCode) | Opens a **Preferences** instance and creates a pointer to it. If this pointer is no longer required, use [OH_Preferences_Close](_preferences.md#oh_preferences_close) to close the instance.| 
| int [OH_Preferences_Close](_preferences.md#oh_preferences_close) ([OH_Preferences](_preferences.md#oh_preferences) \*preference) | Closes a **Preferences** instance.| 
| int [OH_Preferences_GetInt](_preferences.md#oh_preferences_getint) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, int \*value) | Obtains an integer corresponding to the specified key in a **Preferences** instance.| 
| int [OH_Preferences_GetBool](_preferences.md#oh_preferences_getbool) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, bool \*value) | Obtains a Boolean value corresponding to the specified key in a **Preferences** instance.| 
| int [OH_Preferences_GetString](_preferences.md#oh_preferences_getstring) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, char \*\*value, uint32_t \*valueLen) | Obtains a string corresponding to the specified key in a **Preferences** instance.| 
| void [OH_Preferences_FreeString](_preferences.md#oh_preferences_freestring) (char \*string) | Releases a string.| 
| int [OH_Preferences_SetInt](_preferences.md#oh_preferences_setint) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, int value) | Sets an integer value based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_SetBool](_preferences.md#oh_preferences_setbool) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, bool value) | Sets a Boolean value based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_SetString](_preferences.md#oh_preferences_setstring) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key, const char \*value) | Sets a string based on the specified key in a **Preferences** instance.| 
| int [OH_Preferences_Delete](_preferences.md#oh_preferences_delete) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, const char \*key) | Deletes a KV pair of the specified key from a **Preferences** object.| 
| int [OH_Preferences_RegisterDataObserver](_preferences.md#oh_preferences_registerdataobserver) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | Subscribes to data changes of the specified key. If the value of the specified key changes, a callback will be invoked after **OH_Preferences_Close ()** is called.| 
| int [OH_Preferences_UnregisterDataObserver](_preferences.md#oh_preferences_unregisterdataobserver) ([OH_Preferences](_preferences.md#oh_preferences) \*preference, void \*context, [OH_PreferencesDataObserver](_preferences.md#oh_preferencesdataobserver) observer, const char \*keys[], uint32_t keyCount) | Unsubscribes from data changes of the specified key.| 
| int [OH_Preferences_IsStorageTypeSupported](_preferences.md#oh_preferences_isstoragetypesupported) ([Preferences_StorageType](_preferences.md#preferences_storagetype) type, bool \*isSupported) | Checks whether the specified storage type is supported. | 

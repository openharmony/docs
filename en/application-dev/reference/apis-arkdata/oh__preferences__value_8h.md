# oh_preferences_value.h


## Overview

Provides APIs, enums, and structs for accessing the **PreferencesValue** object.

**File to include**: &lt;database/preferences/oh_preferences_value.h&gt;

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

Related module: [Preferences](_preferences.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Preference_ValueType](_preferences.md#preference_valuetype) [Preference_ValueType](_preferences.md#preference_valuetype) | Defines an enum for data types of **PreferencesValue**.| 
| typedef struct [OH_PreferencesPair](_preferences.md#oh_preferencespair) [OH_PreferencesPair](_preferences.md#oh_preferencespair) | Defines a Preferences data record in the key-value (KV) format.| 
| typedef struct [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) | Defines a **PreferencesValue** object.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Preference_ValueType](_preferences.md#preference_valuetype-1) {<br>PREFERENCE_TYPE_NULL = 0, PREFERENCE_TYPE_INT, PREFERENCE_TYPE_BOOL, PREFERENCE_TYPE_STRING,<br>PREFERENCE_TYPE_BUTT<br>} | Enumerates the data types of **PreferencesValue**.| 


### Functions

| Name| Description| 
| -------- | -------- |
| const char \* [OH_PreferencesPair_GetKey](_preferences.md#oh_preferencespair_getkey) (const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t index) | Obtains the key based on the specified index from the KV data.| 
| const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \* [OH_PreferencesPair_GetPreferencesValue](_preferences.md#oh_preferencespair_getpreferencesvalue) (const [OH_PreferencesPair](_preferences.md#oh_preferencespair) \*pairs, uint32_t index) | Obtains the value based on the specified index from the KV pairs.| 
| [Preference_ValueType](_preferences.md#preference_valuetype) [OH_PreferencesValue_GetValueType](_preferences.md#oh_preferencesvalue_getvaluetype) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object) | Obtains the data type of a **PreferencesValue** instance.| 
| int [OH_PreferencesValue_GetInt](_preferences.md#oh_preferencesvalue_getint) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, int \*value) | Obtains an integer value from an [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) instance.| 
| int [OH_PreferencesValue_GetBool](_preferences.md#oh_preferencesvalue_getbool) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, bool \*value) | Obtains a Boolean value from an [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) instance.| 
| int [OH_PreferencesValue_GetString](_preferences.md#oh_preferencesvalue_getstring) (const [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) \*object, char \*\*value, uint32_t \*valueLen) | Obtains a string from an [OH_PreferencesValue](_preferences.md#oh_preferencesvalue) instance.| 

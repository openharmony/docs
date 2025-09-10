# utd.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines APIs and structs related to the Uniform Type Descriptors (UTDs).

**File to include**: <database/udmf/utd.h>

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](capi-udmf.md)

## Summary

### Structs

| Name                    | typedef Keyword| Description                |
| ------------------------ | ------------- | -------------------- |
| [OH_Utd](capi-udmf-oh-utd.md) | OH_Utd        | Defines a struct for a UTD.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Utd* OH_Utd_Create(const char* typeId)](#oh_utd_create)  | Creates an [OH_Utd](capi-udmf-oh-utd.md) instance and a pointer to it.    |
| [void OH_Utd_Destroy(OH_Utd* pThis)](#oh_utd_destroy)        | Destroys an [OH_Utd](capi-udmf-oh-utd.md) instance.|
| [const char* OH_Utd_GetTypeId(OH_Utd* pThis)](#oh_utd_gettypeid) | Obtains the type ID from an [OH_Utd](capi-udmf-oh-utd.md) instance.        |
| [const char* OH_Utd_GetDescription(OH_Utd* pThis)](#oh_utd_getdescription) | Obtains the description from an [OH_Utd](capi-udmf-oh-utd.md) instance.      |
| [const char* OH_Utd_GetReferenceUrl(OH_Utd* pThis)](#oh_utd_getreferenceurl) | Obtains the URL from an [OH_Utd](capi-udmf-oh-utd.md) instance.       |
| [const char* OH_Utd_GetIconFile(OH_Utd* pThis)](#oh_utd_geticonfile) | Obtains the path of the default icon file from an [OH_Utd](capi-udmf-oh-utd.md) instance.|
| [const char** OH_Utd_GetBelongingToTypes(OH_Utd* pThis, unsigned int* count)](#oh_utd_getbelongingtotypes) | Obtains the relationships between the data from an [OH_Utd](capi-udmf-oh-utd.md) instance.|
| [const char** OH_Utd_GetFilenameExtensions(OH_Utd* pThis, unsigned int* count)](#oh_utd_getfilenameextensions) | Obtains the file name extensions associated with an [OH_Utd](capi-udmf-oh-utd.md) instance.|
| [const char** OH_Utd_GetMimeTypes(OH_Utd* pThis, unsigned int* count)](#oh_utd_getmimetypes) | Obtains the MIME types associated with an [OH_Utd](capi-udmf-oh-utd.md) instance.        |
| [const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count)](#oh_utd_gettypesbyfilenameextension) | Obtains the uniform data types based on the file name extensions.        |
| [const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count)](#oh_utd_gettypesbymimetype) | Obtains the uniform data types based on the MIME types.                |
| [bool OH_Utd_BelongsTo(const char* srcTypeId, const char* destTypeId)](#oh_utd_belongsto) | Checks whether a UTD belongs to the target UTD.                |
| [bool OH_Utd_IsLower(const char* srcTypeId, const char* destTypeId)](#oh_utd_islower) | Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.|
| [bool OH_Utd_IsHigher(const char* srcTypeId, const char* destTypeId)](#oh_utd_ishigher) | Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.|
| [bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2)](#oh_utd_equals) | Checks whether two UTDs are the same.                        |
| [void OH_Utd_DestroyStringList(const char** list, unsigned int count)](#oh_utd_destroystringlist) | Destroys a UTD list.                      |

## Function Description

### OH_Utd_Create()

```
OH_Utd* OH_Utd_Create(const char* typeId)
```

**Description**

Creates an [OH_Utd](capi-udmf-oh-utd.md) instance and a pointer to it.

**Since**: 12


**Parameters**

| Name            | Description                |
| ------------------ | -------------------- |
| const char* typeId | Pointer to the type ID of the instance to create.|

**Returns**

| Type                     | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* | Returns a pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance created if the operation is successful; returns **nullptr** otherwise.<br>If this pointer is no longer required, use [OH_Utd_Destroy](capi-utd-h.md#oh_utd_destroy) to destroy it. Otherwise, memory leaks may occur.|

### OH_Utd_Destroy()

```
void OH_Utd_Destroy(OH_Utd* pThis)
```

**Description**

Destroys an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                    |
| ------------------------------- | -------------------------------------------------------- |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|

### OH_Utd_GetTypeId()

```
const char* OH_Utd_GetTypeId(OH_Utd* pThis)
```

**Description**

Obtains the type ID from an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetDescription()

```
const char* OH_Utd_GetDescription(OH_Utd* pThis)
```

**Description**

Obtains the description from an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|

**Returns**

| Type       | Description                                                       |
| ----------- | ----------------------------------------------------------- |
| const char* | Returns a pointer to the description obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetReferenceUrl()

```
const char* OH_Utd_GetReferenceUrl(OH_Utd* pThis)
```

**Description**

Obtains the URL from an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|

**Returns**

| Type       | Description                                                      |
| ----------- | ---------------------------------------------------------- |
| const char* | Returns a pointer to the URL obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetIconFile()

```
const char* OH_Utd_GetIconFile(OH_Utd* pThis)
```

**Description**

Obtains the path of the default icon file from an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the path of the default icon file obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetBelongingToTypes()

```
const char** OH_Utd_GetBelongingToTypes(OH_Utd* pThis, unsigned int* count)
```

**Description**

Obtains the relationships between the data from an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|
| unsigned int* count             | Pointer to the number of data types obtained.          |

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char** | Returns a pointer to the relationship information obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetFilenameExtensions()

```
const char** OH_Utd_GetFilenameExtensions(OH_Utd* pThis, unsigned int* count)
```

**Description**

Obtains the file name extensions associated with an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|
| unsigned int* count             | Pointer to the number of file name extensions obtained.    |

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char** | Returns a pointer to the file name extensions obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetMimeTypes()

```
const char** OH_Utd_GetMimeTypes(OH_Utd* pThis, unsigned int* count)
```

**Description**

Obtains the MIME types associated with an [OH_Utd](capi-udmf-oh-utd.md) instance.

**Since**: 12


**Parameters**

| Name                         | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* pThis | Pointer to the [OH_Utd](capi-udmf-oh-utd.md) instance.|
| unsigned int* count             | Pointer to the number of MIME types obtained.      |

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char** | Returns a pointer to the MIME types obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Utd_GetTypesByFilenameExtension()

```
const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count)
```

**Description**

Obtains the uniform data types based on the file name extensions.

**Since**: 12


**Parameters**

| Name               | Description                                              |
| --------------------- | -------------------------------------------------- |
| const char* extension | Pointer to the file name extensions.                                  |
| unsigned int* count   | Pointer to the number of data types obtained.|

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char** | Returns a pointer to the uniform data types obtained.<br>If it is no longer required, use [OH_Utd_DestroyStringList](capi-utd-h.md#oh_utd_destroystringlist) to destroy it. Otherwise, memory leakage occurs.|

### OH_Utd_GetTypesByMimeType()

```
const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count)
```

**Description**

Obtains the uniform data types based on the MIME types.

**Since**: 12


**Parameters**

| Name              | Description                                              |
| -------------------- | -------------------------------------------------- |
| const char* mimeType | Pointer to the MIME types.                              |
| unsigned int* count  | Pointer to the number of data types obtained.|

**Returns**

| Type        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| const char** | Returns a pointer to the uniform data types obtained.<br>If it is no longer required, use [OH_Utd_DestroyStringList](capi-utd-h.md#oh_utd_destroystringlist) to destroy it. Otherwise, memory leakage occurs.|

### OH_Utd_BelongsTo()

```
bool OH_Utd_BelongsTo(const char* srcTypeId, const char* destTypeId)
```

**Description**

Checks whether a UTD belongs to the target UTD.

**Since**: 12


**Parameters**

| Name                | Description                    |
| ---------------------- | ------------------------ |
| const char* srcTypeId  | Pointer to the UTD to check.  |
| const char* destTypeId | Pointer to the target UTD.|

**Returns**

| Type| Description                                                       |
| ---- | ----------------------------------------------------------- |
| bool | Returns **true** if the UTD belongs to the target UTD; returns **false** otherwise.|

### OH_Utd_IsLower()

```
bool OH_Utd_IsLower(const char* srcTypeId, const char* destTypeId)
```

**Description**

Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.

**Since**: 12


**Parameters**

| Name                | Description                    |
| ---------------------- | ------------------------ |
| const char* srcTypeId  | Pointer to the UTD to check.  |
| const char* destTypeId | Pointer to the target UTD.|

**Returns**

| Type| Description                                                       |
| ---- | ----------------------------------------------------------- |
| bool | Returns **true** if the UTD is a lower-level type of the target UTD; returns **false** otherwise.|

### OH_Utd_IsHigher()

```
bool OH_Utd_IsHigher(const char* srcTypeId, const char* destTypeId)
```

**Description**

Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.

**Since**: 12


**Parameters**

| Name                | Description                    |
| ---------------------- | ------------------------ |
| const char* srcTypeId  | Pointer to the UTD to check.  |
| const char* destTypeId | Pointer to the target UTD.|

**Returns**

| Type| Description                                                       |
| ---- | ----------------------------------------------------------- |
| bool | Returns **true** if the UTD is a higher-level type of the target UTD; returns **false** otherwise.|

### OH_Utd_Equals()

```
bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2)
```

**Description**

Checks whether two UTDs are the same.

**Since**: 12


**Parameters**

| Name                        | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| [OH_Utd](capi-udmf-oh-utd.md)* utd1 | Pointer to an [OH_Utd](capi-udmf-oh-utd.md) instance.|
| [OH_Utd](capi-udmf-oh-utd.md)* utd2 | Pointer to another [OH_Utd](capi-udmf-oh-utd.md) instance.|

**Returns**

| Type| Description                                           |
| ---- | ----------------------------------------------- |
| bool | Returns **true** if the two instances are the same; returns **false** otherwise.|

### OH_Utd_DestroyStringList()

```
void OH_Utd_DestroyStringList(const char** list, unsigned int count)
```

**Description**

Destroys a UTD list.

**Since**: 12


**Parameters**

| Name            | Description                                |
| ------------------ | ------------------------------------ |
| const char** list  | Double pointer to the UTD list to destroy.                |
| unsigned int count | Length of the UTD list.|

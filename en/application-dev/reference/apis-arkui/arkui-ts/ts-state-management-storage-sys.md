# Storage (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=81b14b0ce9c5d9aa8689a7ca27d1b8bfcd42e6dc translatedAt=2026-08-13T07:01:45.928Z pushedAt=2026-08-14T03:10:39.530Z -->

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Storage

A background API for persistent storage, which provides data persistence capabilities based on key-value pairs, including data reading, writing, clearing, and deletion. PersistentStorage uses this API to implement local persistence of AppStorage data, making it suitable for scenarios where flexible local persistent storage of application data is required.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(needCrossThread?: boolean, file?: string)

A constructor for creating a **Storage** instance.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name            | Type    | Mandatory | Description                                   |
| --------------- | ------- | --------- | --------------------------------------------- |
| needCrossThread | boolean | No        | Whether to access the storage across threads. This parameter is reserved and does not provide specific functionality yet. |
| file            | string  | No        | Name of the storage file. This parameter is reserved and does not provide specific functionality yet. By default, **persistent_storage** in the application file directory is used as the storage file. |

### get

get(key: string): string \| undefined

Reads the stored data corresponding to the specified key from the disk.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ----------------------- | ---- | -------------------------------- |
| key | string | Yes | Key of the storage to obtain. |

**Return value**

| Type | Description |
| --------- | -------------------------------------------------------- |
| string \| undefined | Value corresponding to the key; **undefined** is returned if the key does not exist. |

### set

set(key: string, val: any): void

Stores the data corresponding to the specified key persistently to the disk.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ----------------------- | ---- | ------------------------------- |
| key | string | Yes | Name of the storage key to set. |
| val | any | Yes | Data to store. It supports basic types such as string, number, and boolean, as well as serializable objects and arrays. The data is serialized and then persisted to the storage file. |

### clear

clear(): void

Clears all stored data.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

### delete

delete(key: string): void

Deletes the stored data corresponding to the specified key.

**System API:** This is a system API.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | ----------------------- | ---- | ------------------------------- |
| key | string | Yes | Name of the storage key to delete. |
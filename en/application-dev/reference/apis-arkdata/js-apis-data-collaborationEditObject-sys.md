# @ohos.data.collaborationEditObject (Collaboration Edit Object) (System API)

The collaboration edit object is a data model that supports collaborative editing. It offers mechanisms for document data management and conflict resolution across devices. This model provides a range of shared data types (such as editing units, paragraphs, and text) and APIs for read and write operations of these data types. Users can read and write document data without worrying about conflict resolution during multi-device collaboration. This makes multi-device document editing simple and efficient.

The **collaborationEditObject** module provides the following functionalities:

- [CollaborationEditObject](#collaborationeditobject): provides APIs for managing the collaboration edit object.
- [EditUnit](#editunit): provides APIs for managing the editing units.
- [Node](#node): provides APIs for managing paragraphs.
- [Text](#text): provides APIs for managing the text object.
- [UndoRedoManager](#undoredomanager): provides APIs for performing undo and redo operations.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The current page contains only the system interfaces of this module.

## Modules to Import

```ts
import { collaborationEditObject } from '@kit.ArkData';
```

## collaborationEditObject.getCollaborationEditObject

getCollaborationEditObject(context: Context, config: CollaborationConfig): CollaborationEditObject

Obtains a **CollaborationEditObject** instance. You can set parameters for the **CollaborationEditObject** instance based on actual requirements and use the created **CollaborationEditObject** instance to perform document editing across devices.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type                                       | Mandatory| Description                                                        |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                     | Yes  | Application context. The stage model is recommended.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [CollaborationConfig](#collaborationconfig) | Yes  | Configuration of the collaboration edit object.                                    |

**Return value**

| Type                                               | Description                  |
| --------------------------------------------------- | ---------------------- |
| [CollaborationEditObject](#collaborationeditobject) | **CollaborationEditObject** instance obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.    |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**Example**

FA model:

<!--code_no_check_fa-->

```ts
import { featureAbility } from '@kit.AbilityKit';

let editObject: collaborationEditObject.CollaborationEditObject | undefined = undefined;
let context = featureAbility.getContext(); 

const DOC_CONFIG: collaborationEditObject.CollaborationConfig = {
  name: "test"
};

try {
  editObject = collaborationEditObject.getCollaborationEditObject(context, DOC_CONFIG);
} catch (err) {
  console.error(`Get edit object failed, code is ${err.code}, message is ${err.message}`);
}
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let editObject: collaborationEditObject.CollaborationEditObject | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const DOC_CONFIG: collaborationEditObject.CollaborationConfig = {
      name: "test"
    };

    try {
      editObject = collaborationEditObject.getCollaborationEditObject(this.context, DOC_CONFIG);
    } catch (err) {
      console.error(`Get edit object failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}
```




## collaborationEditObject.deleteCollaborationEditObject

deleteCollaborationEditObject(context: Context, config: CollaborationConfig): void

Deletes a collaboration edit object. After the deletion, you are advised to set the **CollaborationEditObject** instance to **null**.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type                                       | Mandatory| Description                                                       |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                     | Yes  | Application context. The stage model is recommended.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [CollaborationConfig](#collaborationconfig) | Yes  | Configuration of the collaboration edit object to delete.                                    |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**Example**

FA model:

<!--code_no_check_fa-->

```ts
import { featureAbility } from '@kit.AbilityKit';

let editObject: collaborationEditObject.CollaborationEditObject | undefined = undefined;
let context = featureAbility.getContext(); 

const DOC_CONFIG: collaborationEditObject.CollaborationConfig = {
  name: "test"
};

try {
  editObject = collaborationEditObject.getCollaborationEditObject(context, DOC_CONFIG);
  collaborationEditObject.deleteCollaborationEditObject(context, DOC_CONFIG);
} catch (err) {
  console.error(`Get edit object failed, code is ${err.code}, message is ${err.message}`);
}
```



Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let editObject: collaborationEditObject.CollaborationEditObject | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const DOC_CONFIG: collaborationEditObject.CollaborationConfig = {
      name: "test"
    };

    try {
      editObject = collaborationEditObject.getCollaborationEditObject(this.context, DOC_CONFIG);
      collaborationEditObject.deleteCollaborationEditObject(this.context, DOC_CONFIG);
    } catch (err) {
      console.error(`Delete edit object failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}
```



## CollaborationConfig

Represents the collaboration edit object configuration.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type  | Mandatory| Description                                                        |
| ---- | ------ | ---- | ------------------------------------------------------------ |
| name | string | Yes  | Document name.<br>The naming rules comply with the naming rules for the operating system files.<br>It is recommended that the value contain letters, digits, underscores (_), and hyphens (-). The value cannot contain slashes (/). Avoid using special characters such as $, @, and #.|



## CollaborationEditObject

Provides APis for managing the **CollaborationEditObject** instance.

Before calling any of the following APIs, you must use [getCollaborationEditObject](#collaborationeditobjectgetcollaborationeditobject) to create a **CollaborationEditObject** instance.

### getEditUnit

getEditUnit(editUnitName: string): EditUnit

Obtains an editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| editUnitName  | string               | Yes  | Name of the editing unit to obtain.<br>The editing unit name is case-insensitive, and cannot be an empty string or exceed 255 bytes.|

**Return value**

| Type                                     | Description                             |
| ----------------------------------------- | --------------------------------- |
| [EditUnit](#editunit) | Editing unit obtained. If the editing unit does not exist, an editing unit will be created.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
  } catch (err) {
    console.error(`Get edit unit failed, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getUndoRedoManager

getUndoRedoManager(editUnitName: string, config: UndoRedoConfig): UndoRedoManager

Obtains an **UndoRedoManager** instance for an editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| editUnitName | string | Yes  | Name of the target editing unit.<br>Generally, it is the same as that in [getEditUnit](#geteditunit).|
| config    | [UndoRedoConfig](#undoredoconfig) | Yes  | Configuration of the **UndoRedoManager** instance.                                        |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [UndoRedoManager](#undoredomanager) | **UndoRedoManager** instance obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;
let undoRedoManager: collaborationEditObject.UndoRedoManager | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    undoRedoManager = editObject.getUndoRedoManager("editUnit01", {captureTimeout: 500});
  } catch (err) {
    console.error(`Get undoRedoManager failed, code is ${err.code}, message is ${err.message}`);
  }
}
```




### deleteUndoRedoManager

deleteUndoRedoManager(editUnitName: string): void

Deletes the **UndoRedoManager** instance of an editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| editUnitName  | string                     | Yes  | Name of the target editing unit.<br>Generally, it is the same as that in [getEditUnit](#geteditunit).|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.    |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;
let undoRedoManager: collaborationEditObject.UndoRedoManager | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    undoRedoManager = editObject.getUndoRedoManager("editUnit01", {captureTimeout: 500});
    editObject.deleteUndoRedoManager("editUnit01");
  } catch (err) {
    console.error(`Delete undoRedoManager failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### getLocalId

getLocalId(): string

Obtains the local device ID.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type  | Description                                                       |
| ------ | ----------------------------------------------------------- |
| string | Local device ID obtained.<br>It is generated by the collaboration edit object.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**Example**

```ts
if (editObject != undefined) {
  try {
    let id: string = editObject.getLocalId();
  } catch (err) {
    console.error(`Get local id failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### applyUpdate

applyUpdate(): Array\<UpdatedNode>

Applies the local updates to this collaboration edit object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type                              | Description                                              |
| ---------------------------------- | -------------------------------------------------- |
| Array<[UpdatedNode](#updatednode)> | Array of the data changed.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**Example**

```ts
function syncCallback(progress: collaborationEditObject.ProgressDetail) {
  if (progress.code !== collaborationEditObject.ProgressCode.CLOUD_SYNC_SUCCESS) {
    return;
  }
  if (editObject != undefined) {
    try {
      let updatedNode: Array<collaborationEditObject.UpdatedNode> = editObject.applyUpdate();
    } catch (err) {
      console.error(`Apply update failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}

if (editObject != undefined) {
  try {
    editObject.cloudSync(collaborationEditObject.SyncMode.SYNC_MODE_PUSH, syncCallback);
  } catch (err) {
    console.error(`Cloud sync failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### writeUpdate

writeUpdate(update: EditObjectRecord): void

Writes the updates in the cloud to the device.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type                                 | Mandatory| Description                  |
| ------ | ------------------------------------- | ---- | ---------------------- |
| update | [EditObjectRecord](#editobjectrecord) | Yes  | Data to write.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**Example**

```ts
if (editObject != undefined) {
  try {
    let updatedRecords: Array<collaborationEditObject.EditObjectRecord> = new Array();
    for (let updatedRecord of updatedRecords) {
      editObject.writeUpdate(updatedRecord);
    }
  } catch (err) {
    console.error(`Write update failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### setCloudDB

setCloudDB(cloudDB: CloudDB): void

Sets the callbacks for device-cloud sync.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type               | Mandatory| Description                  |
| ------- | ------------------- | ---- | ---------------------- |
| cloudDB | [CloudDB](#clouddb) | Yes  | Callbacks to set.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**Example**

```ts
function uploadAssetHandler(config: collaborationEditObject.AssetOperationConfig): Promise<void> {
  return new Promise((resolve, reject) => {
    resolve();
  });
}

function downloadAssetHandler(config: collaborationEditObject.AssetOperationConfig): Promise<void> {
  return new Promise((resolve, reject) => {
    resolve();
  });
}

function deleteAssetHandler(config: collaborationEditObject.AssetOperationConfig): Promise<void> {
  return new Promise((resolve, reject) => {
    resolve();
  });
}

function deleteLocalAssetHandler(config: collaborationEditObject.AssetOperationConfig): Promise<void> {
  return new Promise((resolve, reject) => {
    resolve();
  });
}

function batchInsertHandler(updates: Array<collaborationEditObject.EditObjectRecord>): Promise<number> {
  return new Promise((resolve, reject) => {
    resolve(0);    
  });
}

function queryHandler(queryConditions: Array<collaborationEditObject.QueryCondition>): Promise<Array<collaborationEditObject.EditObjectRecord>> {
  return new Promise((resolve, reject) => {
    let res: Array<collaborationEditObject.EditObjectRecord> = new Array();
    resolve(res);
  });
}

const CLOUD_DB_FUNC: collaborationEditObject.CloudDB = {
  batchInsert: batchInsertHandler,
  query: queryHandler,
  downloadAsset: downloadAssetHandler,
  uploadAsset: uploadAssetHandler,
  deleteAsset: deleteAssetHandler,
  deleteLocalAsset: deleteLocalAssetHandler,
};

if (editObject != undefined) {
  try {
    editObject.setCloudDB(CLOUD_DB_FUNC);
  } catch (err) {
    console.error(`Set cloud db failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### cloudSync

cloudSync(syncMode: SyncMode, progress: Callback\<ProgressDetail>): void

Synchronizes data from the local device to the cloud.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| syncMode | [SyncMode](#syncmode)                       | Yes  | Sync mode.    |
| progress | Callback<[ProgressDetail](#progressdetail)> | Yes  | Callback used to return the sync result.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**Example**

```ts
function cloudSyncCallback(progress: collaborationEditObject.ProgressDetail) {
  console.log(`Cloud sync progress code is ${progress.code}`);
}

if (editObject != undefined) {
  try {
    editObject.cloudSync(collaborationEditObject.SyncMode.SYNC_MODE_PUSH, cloudSyncCallback);
  } catch (err) {
    console.error(`Cloud sync failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

## BatchInsertHandler

type BatchInsertHandler = (records: Array\<EditObjectRecord>) => Promise\<number>

Defines a callback used to upload data from the local device to the cloud.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| records | Array<[EditObjectRecord](#editobjectrecord)>  | Yes  |   Data to be uploaded to the cloud.    |

**Return value**
| Type                              | Description                                              |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<number> | Promise used to return the number of data records that are successfully uploaded.|

## QueryHandler

type QueryHandler = (queryConditions: Array\<QueryCondition>) => Promise\<Array\<EditObjectRecord>>

Defines a callback used to download data from the cloud to the local device.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| queryConditions | Array<[QueryCondition](#querycondition)>  | Yes  |   Conditions for matching the data to download.    |

**Return value**
| Type                              | Description                                              |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<Array<[EditObjectRecord](#editobjectrecord)>> | Promise used to return the cloud data downloaded.|

## AssetHandler

type AssetHandler = (config: AssetOperationConfig) => Promise\<void>

Defines a callback used to upload, download, or delete assets.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| config | [AssetOperationConfig](#assetoperationconfig)  | Yes  |   Configuration of the asset operation.    |

**Return value**
| Type                              | Description                                              |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

## CloudDB

Defines the callbacks used for device-cloud sync.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name | Type  | Read Only| Optional| Description  |
| ------- | ------ | ---- | ---- | ------ |
| batchInsert | [BatchInsertHandler](#batchinserthandler) | Yes| No|  Callback used to upload data from the local device to the cloud. You need to define the callback based on service requirements.|
| query | [QueryHandler](#queryhandler) | Yes| No|  Callback used to download data from the cloud to the local device. You need to define the callback based on service requirements.|
| downloadAsset | [AssetHandler](#assethandler) | Yes| No|  Callback used to download assets from the cloud to the local device. You need to define the callback based on service requirements.|
| uploadAsset | [AssetHandler](#assethandler) | Yes| No|  Callback used to upload assets from the local device to the cloud. You need to define the callback based on service requirements.|
| deleteAsset | [AssetHandler](#assethandler) | Yes| No|  Callback used to delete assets from the cloud. You need to define the callback based on service requirements.|
| deleteLocalAsset | [AssetHandler](#assethandler) | Yes| No|  Callback used to delete assets from the local device. You need to define the callback based on service requirements.|

## SyncMode
Enumerates the device-cloud sync modes.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Value  | Description|
| ---- | ---- | ---- |
| SYNC_MODE_PUSH | 0 |  Push data from the local device to the cloud. |
| SYNC_MODE_PULL |  1    | Pull data from the cloud to the local device.|
| SYNC_MODE_PULL_PUSH |  2  | Pull data from the cloud to the local device, and then push data to the cloud.|

## ProgressCode
Enumerates the device-cloud sync results.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Value  | Description|
| ---- | ---- | ---- |
| CLOUD_SYNC_SUCCESS | 0 |  The device-cloud sync is successful. |
| CLOUD_NOT_SET |  1    | The callback required for device-cloud sync is not configured.|
| INTERNAL_ERROR |  2  | An internal error occurs during the sync.|
| EXTERNAL_ERROR |  3  | An error occurs when a callback is invoked during the sync process.|

## ProgressDetail
Represents the device-cloud sync result.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name | Type  | Read Only| Optional| Description  |
| ------- | ------ | ---- | ---- | ------ |
| code | [ProgressCode](#progresscode) | Yes| No| Device-cloud sync result.|

## Predicate

Enumerates the predicates used to set the conditions for the data to be downloaded.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Value  | Description|
| ---- | ---- | ---- |
| EQUAL_TO | 0 |  Seeks data whose value equals the given value in the cloud. |
| NOT_EQUAL_TO |  1    | Seeks data whose value does not equal the given value in the cloud.|
| GREATER_THAN |  2  | Seeks data whose value is greater than the given value in the cloud.|
| LESS_THAN |  3  | Seeks data whose value is less than the given value in the cloud.|
| GREATER_THAN_OR_EQUAL_TO |  4    | Seeks data whose value is greater than or equal to the given value in the cloud.|
| LESS_THAN_OR_EQUAL_TO |  5  | Seeks data whose value is less than or equal to the given value in the cloud.|

## QueryCondition

Represents the condition for seeking the data to be download in the cloud.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name | Type  | Read Only| Optional| Description  |
| ------- | ------ | ---- | ---- | ------ |
| condition | [Predicate](#predicate) | Yes| No| Predicate to set.|
| fieldName | string | Yes| No| Field corresponding to the specified condition, generated internally by the collaboration edit object.|
| fieldValue | string \| number | Yes| No| Value corresponding to the specified condition, generated internally by the collaboration edit object.|


## AssetOperationConfig

Represents the configuration of the access operation.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name | Type  | Read Only| Optional| Description  |
| ------- | ------ | ---- | ---- | ------ |
| path | string | Yes| No| Path of the asset file. The value can be any non-empty string.|


## RelativePos

Represents the relative position of the cursor in an editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject


| Name         | Type               | Read Only              | Optional                   | Description                     |
| ------------------- | ------------------------- | ------------------- | ------------------- | ------------------- |
| parentId | [UniqueId](#uniqueid) \| null | Yes| No| Parent node. If the parent node is the editing unit, the value is **null**.|
| parentName | string \| null | Yes| No| Name of the parent node. If the parent node is the editing unit, the value is the name of the editing unit. Otherwise, the value is **null**.<br> **Constraints**: See the constraints for the **editUnitName** parameter in [getEditUnit](#geteditunit).|
| id | [UniqueId](#uniqueid) \| null | Yes| No| Left or right node. If there is no left or right node, the value is **null**.<br> **Constraints**: **parentId**, **parentName**, and **id** cannot be **null** at the same time.|
| pos | number | Yes| No| Offset of the character to the node. The value **0** indicates the current node; a value less than **0** indicates a character on the left side of the node; a value greater than **0** indicates a character on the right side of the node. The value must be an integer.|


## UndoRedoConfig

Represents the configuration of the **UndoRedoManager** instance.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name          | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| captureTimeout | number | Yes  | Operation capture time.<br>If the interval between any two operations is less than this value, an undo or redo operation will be triggered.<br>**Constraints**: The value must be a positive integer. If a decimal is passed in, the value will be rounded down.|

## UpdatedNode

Represents the node updated after the operation log is applied to the collaboration edit object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name        | Type                          | Read Only| Optional| Description                                                        |
| ------------ | ------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| editUnitName | string                         | Yes  | No  | Name of the editing unit where the updated node is located after the operation log is applied to the collaboration edit object. The value is returned by the collaboration edit object.<br> **Constraints**: See the constraints for the **editUnitName** parameter in [getEditUnit](#geteditunit).|
| node         | [Node](#node) \| [Text](#text) | Yes  | No  | Node updated.              |

## EditObjectRecord

Represents the data uploaded or downloaded.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name  | Type      | Read Only| Optional| Description                                                        |
| ------ | ---------- | ---- | ---- | ------------------------------------------------------------ |
| cursor | number     | Yes  | No  | Watermark information of the data.<br>It is a non-negative integer internally generated by the collaboration edit object in ascending order by 1.|
| id     | string     | Yes  | No  | Unique identifier of the device. For details, see **id** in [UniqueId](#uniqueid).|
| data   | Uint8Array | Yes  | No  | Data to upload or download.                                  |

## EditUnit

Provides APIs for managing the editing units.

Before calling any of the following APIs, you must use [getEditUnit](#geteditunit) to create a **EditUnit** instance.

### getName

getName(): string

Obtains the name of this object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| string | Object name obtained.<br>If the object is an editing unit instance, the return value is the same as the **editUnitName** value in [getEditUnit](#geteditunit). If the object is a paragraph instance, the return value is the same as the parameter value in the constructor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 202       | Not system application.   |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let name: string | undefined = editUnit.getName();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### insertNodes

insertNodes(index: number, nodes: Node[]): void

Inserts multiple paragraphs to the specified index in this object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Index from which the nodes are inserted.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>The value cannot exceed the index range of the object.|
| nodes    | [Node](#node)[] | Yes  | Nodes to insert.                                              |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |
| 15410002 | Index out of range. |
| 15410003 | Database error. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```

### delete

delete(index: number, length: number): void

Deletes a child node of the given length from the specified position.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Start position.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>If the value exceeds the index range of the object, error 15410002 will be thrown.|
| length    | number  | Yes  | Length of the child node to delete.<br>The value must be a positive integer. Any decimal passed in will be rounded down.<br>If the sum of **index** and **length** is greater than the object length, all the child nodes will be deleted from the start position.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(0, [node01, node02]);
    editUnit.delete (0, 1); // Delete the first paragraph.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getChildren

getChildren(start: number, end: number): Array<Node | Text>

Obtains the child nodes in a specified range in this object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| start | number | Yes  | Start position.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>The value cannot exceed the actual index range.|
| end    | number  | Yes  | End position.<br>The value must a non-negative integer and greater than the value of **start**. Any decimal passed in will be rounded down.<br>If the value is out of the index range, all child nodes from the start position will be returned.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Array<[Node](#node) \| [Text](#text)> | Child nodes obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(0, [node01, node02]);
    let children: Array<collaborationEditObject.Node | collaborationEditObject.Text> | undefined = editUnit.getChildren(0, 1); // Obtain the first child node.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getJsonResult

getJsonResult(): string

Obtains the JSON string of this object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| string | JSON string obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(0, [node01, node02]);
    let json: string | undefined = editUnit.getJsonResult();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```


### getRelativePos

getRelativePos(absolutePos: number): RelativePos

Obtains the relative position of the cursor in the editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| absolutePos | number | Yes| Absolute position of the cursor in the editing unit. The value must be a non-negative integer.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [RelativePos](#relativepos) | Relative position of the cursor obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert (0, "Hello");
    let relPos = editUnit.getRelativePos (2); // 2 is the absolute position of the cursor in the editor.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```

### getAbsolutePos

getAbsolutePos(relativePos: RelativePos): number

Obtains the absolute position of the cursor in the editing unit.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| relativePos | [RelativePos](#relativepos) | Yes| Relative position of the cursor in the editing unit.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| number | Absolute position of the cursor obtained. The value must be a non-negative integer.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "followRedone");

    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(1, [node02]);
    let pos = editUnit.getAbsolutePos({parentId: null, parentName: "top", id: null, pos: 0}); // Obtain the absolute position of node2 in the editor.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



## UniqueId
Represents the unique ID of a node.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name         | Type               | Read Only              | Optional                   | Description                     |
| ------------------- | ------------------------- | ------------------- | ------------------- | ------------------- |
| id | string | Yes| No| Identifier of the client, internally generated by the collaboration edit object.|
| clock | number | Yes| No| Clock number of the node.<br>The value is a non-negative integer internally generated by the collaboration edit object.|


## AttributesRecord
type AttributesRecord = Record<string, string | number | boolean>

Represents the [Node](#node) properties, stored in key-value (KV) pairs.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Type                                      | Description                                                        |
| ------------------------------------------ | ------------------------------------------------------------ |
| Record<string, string\| number \| boolean> | Types of the key and value in a KV pair. The key must be a string, and the value can be a string, number, or Boolean value.|


## Node
Provides APIs for managing paragraphs. This class is inherited from [EditUnit](#editunit).

### constructor
constructor(name: string)

A constructor used to create a paragraph instance.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| name | string | Yes  | Name of the paragraph, which<br>cannot be an empty string.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |

### getId
getId(): UniqueId

Obtains the unique identifier of this paragraph. This API can be called only after the paragraph is inserted into the collaboration edit object. Otherwise, the error code 15410001 will be thrown.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [UniqueId](#uniqueid) | Paragraph ID obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 202       | Not system application.   |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let id: collaborationEditObject.UniqueId | undefined = node01.getId();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### insertTexts

insertTexts(index: number, texts: Text[]): void

Inserts multiple text objects into this paragraph. This API can be called only after the paragraph is inserted into the collaboration edit object. Otherwise, the error code 15410001 will be thrown.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Index from which the text objects are inserted.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>The value cannot exceed the index range of the object.|
| texts | [Text](#text)[] | Yes  | Text objects to insert.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### setAttributes

setAttributes(attributes: AttributesRecord): void

Sets attributes for this paragraph. This API can be called only after the paragraph is inserted into the collaboration edit object. Otherwise, the error code 15410001 will be thrown.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| attributes | [AttributesRecord](#attributesrecord) | Yes  | Attribute names and values to set.             |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    node01.setAttributes({"align":"left", width:48});
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### removeAttributes

removeAttributes(attributeNames: string[]): void

Removes attributes of this paragraph.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| attributeNames | string[] | Yes  | Names of the attributes to remove.             |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    node01.removeAttributes(["align", "width"]);
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getAttributes

getAttributes(): AttributesRecord

Obtains all attributes of this paragraph.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [AttributesRecord](#attributesrecord) | All attributes of the current node.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    node01.setAttributes({"align":"left", width:48});
    let attrs: collaborationEditObject.AttributesRecord = node01.getAttributes();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```

### setAsset

setAsset(assetKey: string, assetValue: string): void

Sets an asset of this node.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| assetKey | string | Yes  | Key of the asset to set. The key is regarded as the asset. The value can be any non-empty string.             |
| assetValue | string | Yes  | Asset attribute value to be set. The value can be any non-empty string.             |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |


**Example**
```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    node01.setAsset("src", "/path/to/asset/asset.jpg");
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```


## FormatValueType

type FormatValueType = null | number | string | boolean

Defines the data types allowed for text object formatting.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Type   | Description                            |
| ------- | -------------------------------- |
| null    | The value is null.                |
| number  | The value is a number of any value.  |
| string  | The value is a string of any value.|
| boolean | The value is of Boolean type.            |

## TextFormat
type TextFormat = Record<string, FormatValueType>

Defines the format of a text object, in the form of a KV pair.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Type                                               | Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ |
| Record<string, [FormatValueType](#formatvaluetype)> | Types of the key and value in a KV pair. The key type is string, and the value type is [FormatValueType](#formatvaluetype).|

## Text

Provides APIs for managing the text objects.

### constructor

constructor()

A constructor used to create a text instance.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |

### getId
getId(): UniqueId

Obtains the ID of this text object. This API can be called only after the text object is inserted into the collaboration edit object. Otherwise, the error code 15410001 will be thrown.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [UniqueId](#uniqueid) | ID of the text object obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 202       | Not system application. |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    let id: collaborationEditObject.UniqueId | undefined = text01.getId();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```

### insert

insert(index: number, text: string, format?: TextFormat): void

Inserts text to the specified position of this text object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Index from which the text is inserted.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>The value cannot be greater than the length of the text object.|
| text | string | Yes  | Text to insert.           |
| format | [TextFormat](#textformat) | No| Format of the text inserted.             |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "abc");
    text01.insert(3, "def", {"color":"red"});
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### delete

delete(index: number, length: number): void

Deletes text of the given length from the specified position.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes  | Start position.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>If the value exceeds the index range of the object, error 15410002 will be thrown.|
| length | number | Yes  | Length of the text to delete.<br>The value must be a positive integer. Any decimal passed in will be rounded down.<br>If the sum of **index** and **length** is greater than the length of the text object, all the text content from the start position will be deleted.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "abc");
    text01.insert(3, "def", {"color":"red"});
    text01.delete (1, 2); // Characters b and c will be deleted.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### format

format(index: number, length: number, format: TextFormat): void

Formats the text of the given length from the specified position.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | Yes| Start position for formatting.<br>The value must be a non-negative integer. Any decimal passed in will be rounded down.<br>If the value exceeds the index range of the object, error 15410002 will be thrown.|
| length | number | Yes  | Length of the text to format.<br>The value must be a positive integer. Any decimal passed in will be rounded down.<br>If the sum of **index** and **length** is greater than the length of the text object, all the text content from the start position will be formatted.|
| format | [TextFormat](#textformat) | Yes  | Format to apply.             |

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "abc");
    text01.insert(3, "def", {"color":"red"});
    text01.format(0, 3, {"color":"green"});
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getPlainText

getPlainText(): string

Obtains the plain text content of this text object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| string | Plain text content obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "abc");
    text01.insert(3, "def", {"color":"red"});
    let content: string | undefined = text01.getPlainText(); // 'abcdef' is returned.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getJsonResult

getJsonResult(): string

Obtains the text in JSON string from this text object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| string | Text in JSON string obtained.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "abc");
    text01.insert(3, "def", {"color":"red"});
    let json: string | undefined = text01.getJsonResult();
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



## UndoRedoManager

Provides APIs for performing undo or redo operations.

The system distinguishes different operations based on **captureTimeout**, which can be set in the **UndoRedoManager** instance obtained by using [getUndoRedoManager](#getundoredomanager). An undo or redo operation will be triggered if the time interval between the operations does not exceed **captureTimeout**.

Before calling any of the following APIs, you must use [getUndoRedoManager](#getundoredomanager) to create an **UndoRedoManager** instance.

### undo
undo(): void

Reverses the most recent operation.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;
let undoRedoManager: collaborationEditObject.UndoRedoManager | undefined = undefined;

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function undoTest() {
  if (editObject != undefined) {
    try {
      editUnit = editObject.getEditUnit("editUnit01");
      undoRedoManager = editObject.getUndoRedoManager("editUnit01", {captureTimeout: 500});
      let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
      editUnit.insertNodes(0, [node01]);
      await sleep(500);
      node01.setAttributes({"align":"left", "width":48});
      undoRedoManager.undo();
      let attrs: collaborationEditObject.AttributesRecord = node01.getAttributes(); // attrs does not contain any attribute.
    } catch (err) {
      console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
    }
  }
}

undoTest()
```



### redo

redo(): void

Reapplies the operation that was previously undone.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [Collaboration Data Model Error Codes](errorcode-collaboration-edit-object.md).

| **ID**| **Error Message**           |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**Example**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;
let undoRedoManager: collaborationEditObject.UndoRedoManager | undefined = undefined;

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function redoTest() {
  if (editObject != undefined) {
    try {
      editUnit = editObject.getEditUnit("editUnit01");
      undoRedoManager = editObject.getUndoRedoManager("editUnit01", {captureTimeout: 500});
      let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
      editUnit.insertNodes(0, [node01]);
      await sleep(500);
      node01.setAttributes({"align":"left", "width":48});
      undoRedoManager.undo();
      let attrs: collaborationEditObject.AttributesRecord = node01.getAttributes(); // attrs does not contain any attribute.
      undoRedoManager.redo();
      attrs = node01.getAttributes(); // attrs contains the previously set attributes.
    } catch (err) {
      console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
    }
  }
}

redoTest()
```

# @ohos.data.collaborationEditObject (协作数据模型)(系统接口)

协作数据模型(Collaboration Edit Object)是一种支持协作编辑的数据模型。协作数据模型提供了一套用于多设备协同编辑的文档数据管理和冲突解决机制，对外提供了一系列共享数据类型（包含编辑单元、段落、文本等），以及各个共享数据类型支持的读、写等接口，用户可以通过这些共享数据类型完成文档数据的读写，而无需关注多设备协同时的冲突解决，从而很简单方便地完成文档内容的多端协同编辑。

该模块提供以下协作数据模型相关的常用功能：

- [CollaborationEditObject](#collaborationeditobject)：提供管理协作数据模型的方法。
- [EditUnit](#editunit)：提供管理协作数据模型编辑单元的方法。
- [Node](#node)：提供管理协作数据模型段落的方法。
- [Text](#text)：提供管理协作数据模型文本对象的方法。
- [UndoRedoManager](#undoredomanager)：提供用于撤销重做的方法。

> **说明：**
>
> - 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。

## 导入模块

```ts
import { collaborationEditObject } from '@kit.ArkData';
```

## collaborationEditObject.getCollaborationEditObject

getCollaborationEditObject(context: Context, config: CollaborationConfig): CollaborationEditObject

获得一个相关的协作数据模型实例。创建/打开文档时，可根据需要进行参数的配置，然后通过获取到的协作数据模型实例来操作文档内容。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型                                        | 必填 | 说明                                                         |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                     | 是   | 应用的上下文，推荐使用Stage模型。 <br/>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br/>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [CollaborationConfig](#collaborationconfig) | 是   | 协作数据模型的配置信息。                                     |

**返回值**：

| 类型                                                | 说明                   |
| --------------------------------------------------- | ---------------------- |
| [CollaborationEditObject](#collaborationeditobject) | 返回协作数据模型实例。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.    |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**示例：** 

FA模型示例：

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

Stage模型示例：

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

删除协作数据模型，删除成功后，建议将协作数据模型实例置为null。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型                                        | 必填 | 说 明                                                        |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                                     | 是   | 应用的上下文，推荐使用Stage模型。 <br/>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br/>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [CollaborationConfig](#collaborationconfig) | 是   | 协作数据模型的配置信息。                                     |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**示例：** 

FA模型示例：

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



Stage模型示例：

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

协作数据模型的相关配置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 类型   | 必填 | 说明                                                         |
| ---- | ------ | ---- | ------------------------------------------------------------ |
| name | string | 是   | 文档名称。<br/>命名限制跟随操作系统文件命名规则。<br/>建议使用字母、数字、下划线(_)、连字符(-)的组合；不能包含斜杠(/)；不建议使用$、@、#等特殊字符。 |



## CollaborationEditObject

提供管理协作数据模型的相关方法。

下列API示例中都需先使用[getCollaborationEditObject](#collaborationeditobjectgetcollaborationeditobject)方法获取到CollaborationEditObject实例，再通过此实例调用对应方法。

### getEditUnit

getEditUnit(editUnitName: string): EditUnit

获取文档对象的编辑单元。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| editUnitName  | string               | 是   | 文档对象中指定编辑单元的名称。<br/>不允许为空字符串，且长度不超过255个字节，大小写不敏感。 |

**返回值**：

| 类型                                      | 说明                              |
| ----------------------------------------- | --------------------------------- |
| [EditUnit](#editunit) | 表示在当前文档对象下的一个编辑单元，如不存在，则新建一个编辑单元。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**示例：**

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

获取文档对象下指定编辑单元相关的撤销重做管理器。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| editUnitName | string | 是   | 文档对象中指定编辑单元的名称。<br/>通常与[getEditUnit](#geteditunit)接口入参保持一致。 |
| config    | [UndoRedoConfig](#undoredoconfig) | 是   | 撤销重做管理器的配置。                                         |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [UndoRedoManager](#undoredomanager) | 指定编辑单元的撤销重做管理器。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**示例：**

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

删除文档对象下指定编辑单元相关的撤销重做管理器。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| editUnitName  | string                     | 是   | 文档对象中指定编辑单元的名称。<br/>通常与[getEditUnit](#geteditunit)接口入参保持一致。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.    |
| 15410000 | Internal Error. |
| 15410003 | Database Error. |

**示例：**

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

获取当前协作数据模型本设备的唯一性标识。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型   | 说明                                                        |
| ------ | ----------------------------------------------------------- |
| string | 当前协作数据模型本设备的唯一性标识。<br/>由本模型内部生成。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**示例：**

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

将本端的操作日志应用到协作数据模型中。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                               | 说明                                               |
| ---------------------------------- | -------------------------------------------------- |
| Array<[UpdatedNode](#updatednode)> | 将操作日志应用到协作数据模型中后，发生变化的结点。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**示例：**

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

将云侧操作日志数据推送到端侧。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名 | 类型                                  | 必填 | 说明                   |
| ------ | ------------------------------------- | ---- | ---------------------- |
| update | [EditObjectRecord](#editobjectrecord) | 是   | 待推送的操作日志数据。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**示例：**

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

设置端云同步所需要的相关回调函数。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名  | 类型                | 必填 | 说明                   |
| ------- | ------------------- | ---- | ---------------------- |
| cloudDB | [CloudDB](#clouddb) | 是   | 端云同步时的相关回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**示例：**

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

同步本端协作数据模型的数据到云侧。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| syncMode | [SyncMode](#syncmode)                       | 是   | 同步模式。     |
| progress | Callback<[ProgressDetail](#progressdetail)> | 是   | 同步结果回调函数，返回端云同步进度标识对象。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal Error.                                              |
| 15410003     | Database Error.                                              |

**示例：**

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

提供数据上行同步回调函数的定义。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| records | Array<[EditObjectRecord](#editobjectrecord)>  | 是   |   本端需要上行的数据。     |

**返回值**：
| 类型                               | 说明                                               |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<number> | Promise对象，返回成功上传的数据条数。 |

## QueryHandler

type QueryHandler = (queryConditions: Array\<QueryCondition>) => Promise\<Array\<EditObjectRecord>>

提供数据下行同步回调函数的定义。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| queryConditions | Array<[QueryCondition](#querycondition)>  | 是   |   查询条件数组，云侧返回的数据需要满足所有列出的条件。     |

**返回值**：
| 类型                               | 说明                                               |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<Array<[EditObjectRecord](#editobjectrecord)>> | Promise对象，返回查询到的云侧数据。 |

## AssetHandler

type AssetHandler = (config: AssetOperationConfig) => Promise\<void>

提供资产上行同步、下行同步和删除的回调函数的定义。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**： 

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| config | [AssetOperationConfig](#assetoperationconfig)  | 是   |   需要操作的资产配置项。     |

**返回值**：
| 类型                               | 说明                                               |
| ---------------------------------- | -------------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

## CloudDB

端云同步时所需要的相关回调。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称  | 类型   | 只读 | 可选 | 说明   |
| ------- | ------ | ---- | ---- | ------ |
| batchInsert | [BatchInsertHandler](#batchinserthandler) | 是 | 否 |  数据上行同步的回调函数，需要业务提供。|
| query | [QueryHandler](#queryhandler) | 是 | 否 |  数据下行同步的回调函数，需要业务提供。|
| downloadAsset | [AssetHandler](#assethandler) | 是 | 否 |  资产下行同步的回调函数，需要业务提供。|
| uploadAsset | [AssetHandler](#assethandler) | 是 | 否 |  资产上行同步的回调函数，需要业务提供。|
| deleteAsset | [AssetHandler](#assethandler) | 是 | 否 |  删除云侧资产的回调函数，需要业务提供。|
| deleteLocalAsset | [AssetHandler](#assethandler) | 是 | 否 |  删除本端资产的回调函数，需要业务提供。|

## SyncMode
端云同步操作的同步模式枚举。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| SYNC_MODE_PUSH | 0 |  表示上行同步，本端数据将上传至云侧。  |
| SYNC_MODE_PULL |  1    | 表示下行同步，云侧数据将下载至本端。 |
| SYNC_MODE_PULL_PUSH |  2  | 表示将依次进行下行和上行同步，先下载云侧数据，再上传本端数据。 |

## ProgressCode
端云同步操作的结果标识枚举。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| CLOUD_SYNC_SUCCESS | 0 |  表示端云同步的结果为成功。  |
| CLOUD_NOT_SET |  1    | 表示未设置端云同步所需要的相关回调。 |
| INTERNAL_ERROR |  2  | 表示同步过程中发生了内部错误。 |
| EXTERNAL_ERROR |  3  | 表示同步过程中在调用同步相关回调时发生了错误。 |

## ProgressDetail
端云同步结束后的进度标识。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称  | 类型   | 只读 | 可选 | 说明   |
| ------- | ------ | ---- | ---- | ------ |
| code | [ProgressCode](#progresscode) | 是 | 否 | 端云同步结果标识。 |

## Predicate

下行同步查询条件的谓语枚举类型。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| EQUAL_TO | 0 |  表示希望从云侧查询字段值等于给定值的数据。  |
| NOT_EQUAL_TO |  1    | 表示希望从云侧查询字段值不等于给定值的数据。 |
| GREATER_THAN |  2  | 表示希望从云侧查询字段值大于给定值的数据。 |
| LESS_THAN |  3  | 表示希望从云侧查询字段值小于给定值的数据。 |
| GREATER_THAN_OR_EQUAL_TO |  4    | 表示希望从云侧查询字段值大于或等于给定值的数据。 |
| LESS_THAN_OR_EQUAL_TO |  5  | 表示希望从云侧查询字段值小于或等于给定值的数据。 |

## QueryCondition

端云下行同步时对云侧数据的查询条件。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称  | 类型   | 只读 | 可选 | 说明   |
| ------- | ------ | ---- | ---- | ------ |
| condition | [Predicate](#predicate) | 是 | 否 | 条件谓语。 |
| fieldName | string | 是 | 否 | 查询条件对应的字段，由模型内部生成。 |
| fieldValue | string \| number | 是 | 否 | 查询条件对应字段的值，模型内部生成。 |


## AssetOperationConfig

端云资产同步相关配置项。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称  | 类型   | 只读 | 可选 | 说明   |
| ------- | ------ | ---- | ---- | ------ |
| path | string | 是 | 否 | 资产文件对应的路径。任意非空字符串。 |


## RelativePos

光标在编辑单元中的相对位置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject


| 名称          | 类型                | 只读               | 可选                    | 说明                      |
| ------------------- | ------------------------- | ------------------- | ------------------- | ------------------- |
| parentId | [UniqueId](#uniqueid) \| null | 是 | 否 | 相对位置的父结点，若父结点是编辑单元,则为null。 |
| parentName | string \| null | 是 | 否 | 相对位置的父结点的结点名，若父结点是编辑单元，则该字段为编辑单元名，否则为null。<br/> **使用约束：** 具体见[getEditUnit](#geteditunit)方法editUnitName参数约束。 |
| id | [UniqueId](#uniqueid) \| null | 是 | 否 | 相对位置的左或者右结点，若左或者右没有结点，则为null。<br/> **使用约束：** parentId，parentName和id三个参数不能同时为null。 |
| pos | number | 是 | 否 | 字符绑定到结点的偏移量，等于0则为此结点，小于0则为此结点左侧的字符，大于0则为此结点的右侧字符。必须为整数。 |


## UndoRedoConfig

撤销重做管理器相关配置信息。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称           | 类型   | 必填 | 说明                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| captureTimeout | number | 是   | 操作捕获时间。<br/>任意多个操作之间的时间间隔小于该值，则触发撤销重做时，视为一个操作。<br/>**使用约束：** 必须为正整型，传小数时向下取整。 |

## UpdatedNode

将操作日志应用到协作数据模型后，发生变化的结点。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称         | 类型                           | 只读 | 可选 | 说明                                                         |
| ------------ | ------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| editUnitName | string                         | 是   | 否   | 将操作日志应用到协作数据模型后，发生变化的结点所在的编辑单元名称，由模型返回。<br/> **使用约束：** 具体见[getEditUnit](#geteditunit)方法editUnitName参数约束。 |
| node         | [Node](#node) \| [Text](#text) | 是   | 否   | 将操作日志应用到协作数据模型后，发生变化的结点。               |

## EditObjectRecord

同步上行或下行时传输的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称   | 类型       | 只读 | 可选 | 说明                                                         |
| ------ | ---------- | ---- | ---- | ------------------------------------------------------------ |
| cursor | number     | 是   | 否   | 数据上行或下行时的水位信息。<br/>非负整数，自增，本模型内部生成。 |
| id     | string     | 是   | 否   | 本设备的唯一性标识符。具体见[UniqueId](#uniqueid)中的id字段。 |
| data   | Uint8Array | 是   | 否   | 上行或下行的同步数据内容。                                   |

## EditUnit

提供管理协作数据模型编辑单元的相关方法。

下列API示例中都需先使用[getEditUnit](#geteditunit)方法获取到EditUnit实例，再通过此实例调用对应方法。

### getName

getName(): string

获取当前对象的名称。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| string | 当前对象的名称。<br/>当前对象为编辑单元实例时，与[getEditUnit](#geteditunit)接口传参一致；当前对象为段落实例时，与其构造函数传参一致。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 202       | Not system application.   |

**示例：**

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

在当前对象中，插入一组段落到指定的索引位置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是   | 插入的位置。<br/>非负整数，传小数时向下取整。<br/>不能超出当前对象的实际索引范围。 |
| nodes    | [Node](#node)[] | 是   | 插入的新节点。                                               |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |
| 15410002 | Index out of range. |
| 15410003 | Database error. |

**示例：** 

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

从指定位置开始，删除指定长度的子结点。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是   | 删除的起始位置。<br/>非负整数，传小数时向下取整。<br/>不能超出实际索引范围，否则抛出15410002错误码。 |
| length    | number  | 是   | 删除子结点的长度。<br/>正整数，传小数时向下取整。<br/>如果index+length大于当前对象的实际长度，将删除起始位置及以后的全部子结点。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(0, [node01, node02]);
    editUnit.delete(0, 1);  // 删除第一个段落
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getChildren

getChildren(start: number, end: number): Array<Node | Text>

获取当前对象中指定范围内的子结点。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 起始位置。<br/>非负整数，传小数向下取整。<br/>不能超出实际索引范围。 |
| end    | number  | 是   | 结束位置。<br/>非负整数，且必须大于start，传小数时向下取整。<br/>如果超出索引范围，则返回起始位置及以后的所有子结点。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Array<[Node](#node) \| [Text](#text)> | 当前对象中指定范围内的子结点。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：** 

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    let node02: collaborationEditObject.Node = new collaborationEditObject.Node("p2");
    editUnit.insertNodes(0, [node01, node02]);
    let children: Array<collaborationEditObject.Node | collaborationEditObject.Text> | undefined = editUnit.getChildren(0, 1); // 获取第一个孩子结点
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getJsonResult

getJsonResult(): string

获取当前对象的JSON字符串。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| string | 当前对象的JSON字符串。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**示例：** 

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

获取光标在编辑单元中的相对位置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| absolutePos | number | 是 | 光标在编辑单元中的绝对位置，非负整数。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [RelativePos](#relativepos) | 光标在编辑单元中的相对位置。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**示例：**

```ts
let editUnit: collaborationEditObject.EditUnit | undefined = undefined;

if (editObject != undefined) {
  try {
    editUnit = editObject.getEditUnit("editUnit01");
    let node01: collaborationEditObject.Node = new collaborationEditObject.Node("p1");
    editUnit.insertNodes(0, [node01]);
    let text01: collaborationEditObject.Text = new collaborationEditObject.Text();
    node01.insertTexts(0, [text01]);
    text01.insert(0, "你好");
    let relPos = editUnit.getRelativePos(2); // 其中2是光标在编辑器中的绝对位置.
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```

### getAbsolutePos

getAbsolutePos(relativePos: RelativePos): number

获取光标在编辑单元中的绝对位置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| relativePos | [RelativePos](#relativepos) | 是 | 光标在编辑单元中的相对位置。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| number | 光标在编辑器中的绝对位置，非负整数。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**示例：**

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
    let pos = editUnit.getAbsolutePos({parentId: null, parentName: "top", id: null, pos: 0}); // 此处找的node2在编辑器中的绝对位置
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



## UniqueId
当前结点的唯一标识。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 名称          | 类型                | 只读               | 可选                    | 说明                      |
| ------------------- | ------------------------- | ------------------- | ------------------- | ------------------- |
| id | string | 是 | 否 | 用于区分不同客户端的标识，由本模型内部生成。 |
| clock | number | 是 | 否 | 当前结点的时钟编号。<br/>非负整数，由本模型内部生成。 |


## AttributesRecord
type AttributesRecord = Record<string, string | number | boolean>

[Node](#node)中的属性，以键值对的形式存储。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 类型                                       | 说明                                                         |
| ------------------------------------------ | ------------------------------------------------------------ |
| Record<string, string\| number \| boolean> | 表示键值对类型。键的类型为string，值的类型为字符串、数字或布尔值。 |


## Node
提供管理协作数据模型段落的相关方法，继承自[EditUnit](#editunit)。

### constructor
constructor(name: string)

创建一个段落的实例。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| name | string | 是   | 段落的名称。<br/>不能为空字符串。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202       | Not system application.   |

### getId
getId(): UniqueId

获取当前段落的唯一性标识。只有当前段落已插入到模型中后，才可调用此方法。否则抛出15410001错误码。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [UniqueId](#uniqueid) | 当前段落的唯一标识。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 202       | Not system application.   |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |

**示例：**

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

在当前段落中，插入一组文本对象到指定的索引位置。只有当前段落已插入到模型中后，才可调用此方法。否则抛出15410001错误码。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是   | 插入的位置。<br/>非负整数，传小数时向下取整。<br/>不能超出当前对象的实际索引范围。 |
| texts | [Text](#text)[] | 是   | 插入的文本对象列表。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例**

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

设置或更新当前段落的属性。只有当前段落已插入到模型中后，才可调用此方法。否则抛出15410001错误码。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| attributes | [AttributesRecord](#attributesrecord) | 是   | 需要设置的属性名和属性值。              |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

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

删除当前段落对应属性名称的属性。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| attributeNames | string[] | 是   | 需要删除的属性名。              |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

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

返回当前段落的所有属性名和对应的属性值。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [AttributesRecord](#attributesrecord) | 当前结点中的所有属性。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**示例：**

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

设置或更新当前结点的资产属性。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| assetKey | string | 是   | 资产标签，设置成功后该标签被视为资产。任意非空字符串。              |
| assetValue | string | 是   | 需要设置的资产属性值。任意非空字符串。              |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |


**示例：**
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

用于表示文本对象格式化允许的数据字段类型。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 类型    | 说明                             |
| ------- | -------------------------------- |
| null    | 表示值类型为空。                 |
| number  | 表示值类型为数字。可取任意值。   |
| string  | 表示值类型为字符串。可取任意值。 |
| boolean | 表示值类型为布尔值。             |

## TextFormat
type TextFormat = Record<string, FormatValueType>

用于表示文本对象的格式信息，键值对的形式。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

| 类型                                                | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ |
| Record<string, [FormatValueType](#formatvaluetype)> | 表示键值对类型。键的类型为string，值的类型为[FormatValueType](#formatvaluetype)。 |

## Text

提供管理协作数据模型文本对象的相关方法。

### constructor

constructor()

创建一个文本对象的实例。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |

### getId
getId(): UniqueId

获取当前文本对象的唯一性标识。只有当前文本对象已插入到模型中后，才可调用此方法。否则抛出15410001错误码。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [UniqueId](#uniqueid) | 当前文本对象的唯一标识。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 202       | Not system application. |
| 15410000 | Internal error. |
| 15410001 | Unsupported operation. |

**示例：**

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

将文本插入到当前文本对象中的指定位置。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是   | 插入的位置。<br/>非负整数，传小数时向下取整。<br/>不能大于当前文本对象的实际长度。 |
| text | string | 是   | 插入的文本内容。            |
| format | [TextFormat](#textformat) | 否 | 指示要应用于插入文本的格式信息。              |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

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

从指定位置开始，删除指定长度的目标文本。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是   | 删除的起始位置。<br/>非负整数，传小数时向下取整。<br/>不能超出实际索引范围，否则抛出15410002错误码。 |
| length | number | 是   | 删除的文本内容的长度。<br/>正整数，传小数时向下取整。<br>如果index+length大于当前文本对象的实际长度，将删除起始位置及以后的全部文本内容。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

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
    text01.delete(1, 2);  // 字符b和c会被删除
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### format

format(index: number, length: number, format: TextFormat): void

从指定位置开始，对指定长度的文本内容进行格式化。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**参数**：
| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| index | number | 是 | 要格式化的起始位置。<br/>非负整数，传小数时向下取整。<br/>不能超出实际索引范围，否则抛出15410002错误码。 |
| length | number | 是   | 要格式化的文本内容的长度。<br/>正整数，传小数时向下取整。<br/>如果index+length大于当前文本对象的实际长度，将格式化起始位置及以后的全部文本内容。 |
| format | [TextFormat](#textformat) | 是   | 指示要应用的格式化信息。              |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 202          | Not system application.                                      |
| 15410000     | Internal error.                                              |
| 15410001     | Unsupported operation.                                       |
| 15410002     | Index out of range.                                          |
| 15410003     | Database error.                                              |

**示例：**

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

获取当前文本对象不带格式化信息的纯文本内容。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| string | 表示当前文本对象的纯文本内容。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**示例：**

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
    let content: string | undefined = text01.getPlainText(); // 返回'abcdef'
  } catch (err) {
    console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
  }
}
```



### getJsonResult

getJsonResult(): string

获取当前文本对象带有格式化信息的json字符串结果。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| string | 表示当前文本对象带有格式化信息的json字符串。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410001     | Unsupported operation.  |
| 15410002     | Index out of range.     |
| 15410003     | Database error.         |

**示例：**

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

撤销重做管理器，用于撤销最近的操作，或重做最近撤销的操作。

针对操作，系统会通过操作捕获时间（即captureTimeout，可在通过[getUndoRedoManager](#getundoredomanager)接口获取撤销重做管理器时进行设置）来界定不同操作。即任意两个时间间隔不超过captureTimeout的操作，均会被视为一个操作，直至下一个操作的时间间隔超过captureTimeout。

下列API示例中都需先使用[getUndoRedoManager](#getundoredomanager)方法获取到UndoRedoManager实例，再通过此实例调用对应方法。

### undo
undo(): void

撤销最近的操作。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**示例：**

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
      let attrs: collaborationEditObject.AttributesRecord = node01.getAttributes(); // attrs不包含任何属性
    } catch (err) {
      console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
    }
  }
}

undoTest()
```



### redo

redo(): void

重做最近一次撤销的操作。

**系统能力：** SystemCapability.DistributedDataManager.DataObject.DistributedObject

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[协作数据模型错误码](errorcode-collaboration-edit-object.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 202          | Not system application. |
| 15410000     | Internal error.         |
| 15410003     | Database error.         |

**示例：**

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
      let attrs: collaborationEditObject.AttributesRecord = node01.getAttributes(); // attrs不包含任何属性
      undoRedoManager.redo();
      attrs = node01.getAttributes(); // attrs包含之前设置的属性
    } catch (err) {
      console.error(`Catch an error, code is ${err.code}, message is ${err.message}`);
    }
  }
}

redoTest()
```


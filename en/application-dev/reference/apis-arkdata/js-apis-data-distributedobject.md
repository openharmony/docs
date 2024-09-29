# @ohos.data.distributedDataObject (Distributed Data Object)

The **distributedDataObject** module provides basic data object management, including creating, querying, deleting, modifying, and subscribing to data objects, and distributed data object collaboration for the same application among multiple devices.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { distributedDataObject } from '@kit.ArkData';
```

## distributedDataObject.create<sup>9+</sup>

create(context: Context, source: object): DataObject

Creates a distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
  | source | object | Yes | Properties of the distributed data object. |

**Return value**

| Type| Description|
| -------- | -------- |
| [DataObject](#dataobject) | Distributed data object created.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

FA model:
<!--code_no_check_fa-->
```ts
// Import the module.
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
// Obtain the context.
let context = featureAbility.getContext();
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DataObject = distributedDataObject.create(context, source);
```

Stage model:

```ts
// Import the module.
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let g_object: distributedDataObject.DataObject|null = null;
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        let source: SourceObject = new SourceObject("jack", 18, false);
        g_object = distributedDataObject.create(this.context, source);
    }
}
```

## distributedDataObject.genSessionId

genSessionId(): string

Creates a random session ID.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Session ID created.|

**Example**

```ts
let sessionId: string = distributedDataObject.genSessionId();
```

## SaveSuccessResponse<sup>9+</sup>

Represents the information returned by the callback of [save](#save9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | Yes| Unique ID for multi-device collaboration.|
| version | number | Yes| Version of the distributed data object saved.|
| deviceId | string | Yes| ID of the device where the distributed data object is stored. The value **local** indicates the local device.|

## RevokeSaveSuccessResponse<sup>9+</sup>

Represents the information returned by the callback of [revokeSave](#revokesave9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | Yes| Unique ID for multi-device collaboration.|

## BindInfo<sup>11+</sup>

Represents the information about the joint asset in the RDB store to bind. Currently, only the RDB stores are supported.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
  | Name      | Type                                                              | Read-Only| Optional| Description                                |
  | ---------- | ------------------------------------------------------------------ | ---- | ---- | ------------------------------------ |
  | storeName  | string                                                             | No  | No  | RDB store to which the target asset (asset to bind) belongs.  |
  | tableName  | string                                                             | No  | No  | Table to which the target asset is located in the RDB store.  |
  | primaryKey | [commonType.ValuesBucket](js-apis-data-commonType.md#valuesbucket) | No  | No  | Primary key of the target asset in the RDB store.  |
  | field      | string                                                             | No  | No  | Column in which the target asset is located in the RDB store.  |
  | assetName  | string                                                             | No  | No  | Name of the target asset in the RDB store.|

## DataObject

Provides APIs for managing a distributed data object. Before using any API of this class, use [create()](#distributeddataobjectcreate9) to create a **DataObject** object.

### setSessionId<sup>9+</sup>

setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void

Sets a session ID. This API uses an asynchronous callback to return the result. For the devices in the collaboration state in a trusted network, data of the distributed objects with the same session ID can be automatically synced across devices.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name   | Type                     | Mandatory| Description                                                                                                          |
  | --------- | ------------------------- | ---- | -------------------------------------------------------------------------------------------------------------- |
  | sessionId | string                    | Yes  | ID of a distributed data object on a trusted network. The value can contain only letters, digits, and underscores (_), and cannot exceed 128 characters. If this parameter is set to "", the distributed data object exits the network.|
  | callback  | AsyncCallback&lt;void&gt; | Yes  | Asynchronous callback invoked when the session ID is successfully set.                                                                                       |

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Data Object Error Codes](errorcode-distributed-dataObject.md).

  | ID| Error Message                                                                                                                                                          |
  | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
  | 201      | Permission verification failed.                                                                                                                                    |
  | 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. The sessionId allows only letters, digits, and underscores(_), and cannot exceed 128 in length. |
  | 15400001 | Create table failed.                                                                                                                                               |

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedDataObject.genSessionId(), ()=>{
    console.info("join session");
});
// g_object exits the distributed network.
g_object.setSessionId("", ()=>{
    console.info("leave all session");
});
```

### setSessionId<sup>9+</sup>

setSessionId(callback: AsyncCallback&lt;void&gt;): void

Exits all sessions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the distributed data object exits all sessions.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Data Object Error Codes](errorcode-distributed-dataObject.md).

  | ID| Error Message|
  | -------- | -------- |
  | 201      | Permission verification failed. |
  | 401      | Parameter error. Incorrect parameter types. |
  | 15400001 | Create table failed. |

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedDataObject.genSessionId(), ()=>{
    console.info("join session");
});
// Exit the distributed network.
g_object.setSessionId(() => {
    console.info("leave all session.");
});
```

### setSessionId<sup>9+</sup>

setSessionId(sessionId?: string): Promise&lt;void&gt;

Sets a session ID. This API uses a promise to return the result. For the devices in the collaboration state in a trusted network, data of the distributed objects with the same session ID can be automatically synced across devices.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name   | Type  | Mandatory| Description                                                                                                                        |
  | --------- | ------ | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
  | sessionId | string | No  | ID of a distributed data object on a trusted network. The value can contain only letters, digits, and underscores (_), and cannot exceed 128 characters. To remove a distributed data object from the network, set this parameter to "" or leave it empty.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Data Object Error Codes](errorcode-distributed-dataObject.md).

  | ID| Error Message                                                                                                                                                          |
  | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
  | 201      | Permission verification failed.                                                                                                                                    |
  | 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. The sessionId allows only letters, digits, and underscores(_), and cannot exceed 128 in length. |
  | 15400001 | Create table failed.                                                                                                                                               |

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedDataObject.genSessionId()).then (()=>{
    console.info("join session.");
    }).catch((error: BusinessError)=>{
        console.info("error:" + error.code + error.message);
});
// Exit the distributed network.
g_object.setSessionId().then (()=>{
    console.info("leave all session.");
    }).catch((error: BusinessError)=>{
        console.info("error:" + error.code + error.message);
});
```

### on('change')<sup>9+</sup>

on(type: 'change', callback: (sessionId: string, fields: Array&lt;string&gt;) => void): void

Subscribes to data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | Yes | Callback used to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed properties of the distributed data object. |

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
g_object.on("change", (sessionId: string, fields: Array<string>) => {
    console.info("change" + sessionId);
    if (g_object != null && fields != null && fields != undefined) {
        for (let index: number = 0; index < fields.length; index++) {
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);
        }
    }
});
```

### off('change')<sup>9+</sup>

off(type: 'change', callback?: (sessionId: string, fields: Array&lt;string&gt;) => void): void

Unsubscribes from the data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | No | Callback to unregister. If this parameter is not specified, this API unregisters all data change callbacks of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed properties of the distributed data object. |

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
// Unregister the specified data change callback.
g_object.off("change", (sessionId: string, fields: Array<string>) => {
    console.info("change" + sessionId);
    if (g_object != null && fields != null && fields != undefined) {
        for (let index: number = 0; index < fields.length; index++) {
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);
        }
    }
});
// Unregister all data change callbacks.
g_object.off("change");
```

### on('status')<sup>9+</sup>

on(type: 'status', callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void): void

Subscribes to status changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Function | Yes| Callback used to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the device.<br>**status** indicates the object status, which can be online or offline.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
g_object.on("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {
    console.info("status changed " + sessionId + " " + status + " " + networkId);
});
```

### off('status')<sup>9+</sup>

off(type: 'status', callback?:(sessionId: string, networkId: string, status: 'online' \| 'offline') => void): void

Unsubscribes from the status change of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Function | No| Callback to unregister. If this parameter is not specified, this API unregisters all status change callbacks of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the distributed data object.<br>**status** indicates the object status, which can be online or offline.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
// Unregister the specified status change callback.
g_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {
    console.info("status changed " + sessionId + " " + status + " " + networkId);
});
// Unregister all status change callbacks.
g_object.off("status");
```

### save<sup>9+</sup>

save(deviceId: string, callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void

Saves a distributed data object. This API uses an asynchronous callback to return the result.

If the application is active, the saved data will not be released. When the application exits and restarts, the data saved on the device will be restored.

The saved data will be released in the following cases:

- The data is stored for more than 24 hours.
- The application has been uninstalled.
- Data is successfully restored.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| ID of the device where data is stored. The value **local** indicates a local device.|
  | callback | AsyncCallback&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | Yes| Callback used to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
  | 801      | Capability not supported. |

**Example**

```ts
g_object.setSessionId("123456");
g_object.save("local", (err: BusinessError, result:distributedDataObject.SaveSuccessResponse) => {
    if (err) {
        console.info("save failed, error code = " + err.code);
        console.info("save failed, error message: " + err.message);
        return;
    }
    console.info("save callback");
    console.info("save sessionId: " + result.sessionId);
    console.info("save version: " + result.version);
    console.info("save deviceId:  " + result.deviceId);
});
```

### save<sup>9+</sup>

save(deviceId: string): Promise&lt;SaveSuccessResponse&gt;

Saves a distributed data object. This API uses a promise to return the result.

If the application is active, the saved data will not be released. When the application exits and restarts, the data saved on the device will be restored.

The saved data will be released in the following cases:

- The data is stored for more than 24 hours.
- The application has been uninstalled.
- Data is successfully restored.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceId | string | Yes| ID of the device where the data is saved. The default value is **local**, which indicates a local device. |

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | Promise used to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
  | 801      | Capability not supported. |

**Example**

```ts
g_object.setSessionId("123456");
g_object.save("local").then((result: distributedDataObject.SaveSuccessResponse) => {
    console.info("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}).catch((err: BusinessError) => {
    console.info("save failed, error code = " + err.code);
    console.info("save failed, error message: " + err.message);
});
```

### revokeSave<sup>9+</sup>

revokeSave(callback: AsyncCallback&lt;RevokeSaveSuccessResponse&gt;): void

Revokes the data of this distributed data object saved. This API uses an asynchronous callback to return the result.

If the object is saved on the local device, the data saved on all trusted devices will be deleted.
If the object is stored on another device, the data on the local device will be deleted.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse9)&gt; | Yes| Callback used to return **RevokeSaveSuccessResponse**, which contains the session ID.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Incorrect parameter types. |
  | 801      | Capability not supported. |

**Example**

```ts
g_object.setSessionId("123456");
// Save data for persistence. 
g_object.save("local", (err: BusinessError, result: distributedDataObject.SaveSuccessResponse) => {
    if (err) {
        console.info("save failed, error code = " + err.code);
        console.info("save failed, error message: " + err.message);
        return;
    }
    console.info("save callback");
    console.info("save sessionId: " + result.sessionId);
    console.info("save version: " + result.version);
    console.info("save deviceId:  " + result.deviceId);
});
// Delete the persistence data.
g_object.revokeSave((err: BusinessError, result: distributedDataObject.RevokeSaveSuccessResponse) => {
    if (err) {
      console.info("revokeSave failed, error code = " + err.code);
      console.info("revokeSave failed, error message: " + err.message);
      return;
    }
    console.info("revokeSave callback");
    console.info("revokeSave sessionId " + result.sessionId);
});
```

### revokeSave<sup>9+</sup>

revokeSave(): Promise&lt;RevokeSaveSuccessResponse&gt;

Revokes the data of this distributed data object saved. This API uses a promise to return the result.

If the object is saved on the local device, the data saved on all trusted devices will be deleted.
If the object is stored on another device, the data on the local device will be deleted.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse9)&gt; | Promise used to return **RevokeSaveSuccessResponse**, which contains the session ID.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 801      | Capability not supported. |

**Example**

```ts
g_object.setSessionId("123456");
// Save data for persistence. 
g_object.save("local").then((result: distributedDataObject.SaveSuccessResponse) => {
    console.info("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}).catch((err: BusinessError) => {
    console.info("save failed, error code = " + err.code);
    console.info("save failed, error message: " + err.message);
});
// Delete the persistence data.
g_object.revokeSave().then((result: distributedDataObject.RevokeSaveSuccessResponse) => {
    console.info("revokeSave callback");
    console.info("sessionId" + result.sessionId);
}).catch((err: BusinessError)=> {
    console.info("revokeSave failed, error code = " + err.code);
    console.info("revokeSave failed, error message = " + err.message);
});
```

### bindAssetStore<sup>11+</sup>

bindAssetStore(assetKey: string, bindInfo: BindInfo, callback: AsyncCallback&lt;void&gt;): void

Binds joint assets. Currently, only the binding between an asset in a distributed data object and an asset in an RDB store is supported. This API uses an asynchronous callback to return the result.

When an asset in a distributed object and an asset in an RDB store point to the same entity asset file, that is, the URIs of the two assets are the same, a conflict occurs. Such assets are called joint assets. To resolve the conflict, bind the joint assets. The binding is automatically released when the application exits the session.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name  | Type                     | Mandatory| Description                                                                              |
  | -------- | ------------------------- | ---- | ---------------------------------------------------------------------------------- |
  | assetKey | string                    | Yes  | Key of the joint asset in the distributed data object.                                            |
  | bindInfo | [BindInfo](#bindinfo11)   | Yes  | Information about the joint asset in the RDB store, including the RDB store name, table name, primary key, column name, and asset name in the RDB store.|
  | callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                                |

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
  | 801      | Capability not supported. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { commonType } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

class Note {
  title: string | undefined
  text: string | undefined
  attachment: commonType.Asset | undefined

  constructor(title: string | undefined, text: string | undefined, attachment: commonType.Asset | undefined) {
    this.title = title;
    this.text = text;
    this.attachment = attachment;
  }
}

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let attachment: commonType.Asset = {
      name: 'test_img.jpg',
      uri: 'file://com.example.myapplication/data/storage/el2/distributedfiles/dir/test_img.jpg',
      path: '/dir/test_img.jpg',
      createTime: '2024-01-02 10:00:00',
      modifyTime: '2024-01-02 10:00:00',
      size: '5',
      status: commonType.AssetStatus.ASSET_NORMAL
    }
    let note: Note = new Note('test', 'test', attachment);
    let g_object: distributedDataObject.DataObject = distributedDataObject.create(this.context, note);
    g_object.setSessionId('123456');

    const bindInfo: distributedDataObject.BindInfo = {
      storeName: 'notepad',
      tableName: 'note_t',
      primaryKey: {
        'uuid': '00000000-0000-0000-0000-000000000000'
      },
      field: 'attachment',
      assetName: attachment.name as string
    }

    g_object.bindAssetStore('attachment', bindInfo, (err: BusinessError) => {
      if (err) {
        console.error('bindAssetStore failed.');
      }
      console.info('bindAssetStore success.');
    });
  }
}
```

### bindAssetStore<sup>11+</sup>

bindAssetStore(assetKey: string, bindInfo: BindInfo): Promise&lt;void&gt;

Binds joint assets. Currently, only the binding between an asset in a distributed data object and an asset in an RDB store is supported. This API uses a promise to return the result.

When an asset in a distributed object and an asset in an RDB store point to the same entity asset file, that is, the URIs of the two assets are the same, a conflict occurs. Such assets are called joint assets. To resolve the conflict, bind the joint assets. The binding is automatically released when the application exits the session.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name  | Type                   | Mandatory| Description                                                                              |
  | -------- | ----------------------- | ---- | ---------------------------------------------------------------------------------- |
  | assetKey | string                  | Yes  | Key of the joint asset in the distributed data object.                                            |
  | bindInfo | [BindInfo](#bindinfo11) | Yes  | Information about the joint asset in the RDB store, including the RDB store name, table name, primary key, column name, and asset name in the RDB store.|

**Return value**

  | Type               | Description         |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

  | ID| Error Message|
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
  | 801      | Capability not supported. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { commonType } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

class Note {
  title: string | undefined
  text: string | undefined
  attachment: commonType.Asset | undefined

  constructor(title: string | undefined, text: string | undefined, attachment: commonType.Asset | undefined) {
    this.title = title;
    this.text = text;
    this.attachment = attachment;
  }
}

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let attachment: commonType.Asset = {
      name: 'test_img.jpg',
      uri: 'file://com.example.myapplication/data/storage/el2/distributedfiles/dir/test_img.jpg',
      path: '/dir/test_img.jpg',
      createTime: '2024-01-02 10:00:00',
      modifyTime: '2024-01-02 10:00:00',
      size: '5',
      status: commonType.AssetStatus.ASSET_NORMAL
    }
    let note: Note = new Note('test', 'test', attachment);
    let g_object: distributedDataObject.DataObject = distributedDataObject.create(this.context, note);
    g_object.setSessionId('123456');

    const bindInfo: distributedDataObject.BindInfo = {
      storeName: 'notepad',
      tableName: 'note_t',
      primaryKey: {
        'uuid': '00000000-0000-0000-0000-000000000000'
      },
      field: 'attachment',
      assetName: attachment.name as string
    }

    g_object.bindAssetStore("attachment", bindInfo).then(() => {
      console.info('bindAssetStore success.');
    }).catch((err: BusinessError) => {
      console.error("bindAssetStore failed, error code = " + err.code);
    });
  }
}
```

## distributedDataObject.createDistributedObject<sup>(deprecated)</sup>

createDistributedObject(source: object): DistributedObject


Creates a distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [distributedDataObject.create](#distributeddataobjectcreate9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | source | object | Yes | Properties of the distributed data object. |

**Return value**

| Type| Description|
| -------- | -------- |
| [DistributedObject](#distributedobjectdeprecated) | Distributed data object created.|

**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);
```

## DistributedObject<sup>(deprecated)</sup>

Provides APIs for managing a distributed data object. Before using any API of this class, use [createDistributedObject()](#distributeddataobjectcreatedistributedobjectdeprecated) to create a **DistributedObject** object.

### setSessionId<sup>(deprecated)</sup>

setSessionId(sessionId?: string): boolean

Sets a session ID. For the devices in the collaboration state in a trusted network, data of the distributed objects with the same session ID can be automatically synced across devices.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setSessionId](#setsessionid9).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sessionId | string | No| ID of a distributed data object on a trusted network. To remove a distributed data object from the network, set this parameter to "" or leave it empty.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the session ID is set successfully;<br>returns **false** otherwise. |

**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);
// Add g_object to the distributed network.
g_object.setSessionId(distributedDataObject.genSessionId());
// Remove g_object from the distributed network.
g_object.setSessionId("");
```

### on('change')<sup>(deprecated)</sup>

on(type: 'change', callback: (sessionId: string, fields: Array&lt;string&gt;) => void): void

Subscribes to data changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('change')](#onchange9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | Yes | Callback used to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed properties of the distributed data object. |

**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);
g_object.on("change", (sessionId: string, fields: Array<string>) => {
    console.info("change" + sessionId);
    if (fields != null && fields != undefined) {
        for (let index: number = 0; index < fields.length; index++) {
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);
        }
    }
});
```

### off('change')<sup>(deprecated)</sup>

off(type: 'change', callback?: (sessionId: string, fields: Array&lt;string&gt;) => void): void

Unsubscribes from the data changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [off('change')](#offchange9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | No | Callback to unregister. If this parameter is not specified, this API unregisters all data change callbacks of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed properties of the distributed data object. |

**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);
// Unregister the specified data change callback.
g_object.off("change", (sessionId: string, fields: Array<string>) => {
    console.info("change" + sessionId);
    if (fields != null && fields != undefined) {
        for (let index: number = 0; index < fields.length; index++) {
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);
        }
    }
});
// Unregister all data change callbacks.
g_object.off("change");
```

### on('status')<sup>(deprecated)</sup>

on(type: 'status', callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void): void

Subscribes to status changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('status')](#onstatus9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Function | Yes| Callback used to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the device.<br>**status** indicates the object status, which can be online or offline.|

**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);

g_object.on("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {
    console.info("status changed " + sessionId + " " + status + " " + networkId);
});
```

### off('status')<sup>(deprecated)</sup>

off(type: 'status', callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void): void

Unsubscribes from the status change of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [off('status')](#offstatus9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Function | No| Callback to unregister. If this parameter is not specified, this API unregisters all status change callbacks of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the distributed data object.<br>**status** indicates the object status, which can be online or offline.|


**Example**

```ts
class SourceObject {
    name: string
    age: number
    isVis: boolean

    constructor(name: string, age: number, isVis: boolean) {
        this.name = name
        this.age = age
        this.isVis = isVis
    }
}

let source: SourceObject = new SourceObject("jack", 18, false);
let g_object: distributedDataObject.DistributedObject = distributedDataObject.createDistributedObject(source);
// Unregister the specified status change callback.
g_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {
    console.info("status changed " + sessionId + " " + status + " " + networkId);
});
// Unregister all status change callbacks.
g_object.off("status");
```

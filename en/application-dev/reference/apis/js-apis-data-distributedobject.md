# @ohos.data.distributedDataObject (Distributed Data Object)

The **distributedDataObject** module provides basic data object management, including creating, querying, deleting, modifying, and subscribing to data objects, and distributed data object collaboration for the same application among multiple devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>


## Modules to Import

```ts
import distributedObject from '@ohos.data.distributedDataObject';
```

## distributedObject.create<sup>9+</sup>

create(context: Context, source: object): DataObject

Creates a distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | Context | Yes| Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| source | object | Yes| Attributes of the distributed data object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DataObject](#dataobject) | Distributed data object created.|

**Example**

FA model:

```ts
// Import the module.
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DataObject = distributedObject.create(context, source);
```

Stage model:

```ts
// Import the module.
import distributedObject from '@ohos.data.distributedDataObject';
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

let g_object: distributedObject.DataObject|null = null;
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
        let source: SourceObject = new SourceObject("amy", 18, false);
        let g_object: distributedObject.DataObject = distributedObject.create(this.context, source);
    }
}
```

## distributedObject.genSessionId

genSessionId(): string

Creates a random session ID.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**

| Type| Description|
| -------- | -------- |
| string | Session ID created.|

**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
let sessionId: string = distributedObject.genSessionId();
```

## SaveSuccessResponse<sup>9+</sup>

Called when the **Save()** API is successfully called.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | Yes| Unique ID for multi-device collaboration.|
| version | number | Yes| Version of the distributed data object saved.|
| deviceId | string | Yes| ID of the device where the distributed data object is stored. The default value is **local**, which identifies a local device. You can set it as required.|

## RevokeSaveSuccessResponse<sup>9+</sup>

Called when the **revokeSave()** API is successfully called.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | Yes| Unique ID for multi-device collaboration.|

## DataObject

Provides APIs for managing a distributed data object. Before using any API of this class, use [create()](#distributedobjectcreate9) to create a **DataObject** object.

### setSessionId<sup>9+</sup>

setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void

Sets a session ID for synchronization. Automatic synchronization is performed for multiple devices with the same session ID on a trusted network.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | Yes| ID of a distributed data object on a trusted network.|
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback invoked when the session ID is successfully set.|

**Error codes**

  For details about the error codes, see [Distributed Data Object Error Codes](../errorcodes/errorcode-distributed-dataObject.md).

| ID| Error Message|
| -------- | -------- |
| 15400001 | Create table failed.|

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.info("join session");
});
```

### setSessionId<sup>9+</sup>

setSessionId(callback: AsyncCallback&lt;void&gt;): void

Exits all joined sessions.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback invoked when the distributed data object exits all joined sessions.|

**Error codes**

  For details about the error codes, see [Distributed Data Object Error Codes](../errorcodes/errorcode-distributed-dataObject.md).

| ID| Error Message|
| -------- | -------- |
| 15400001 | Create table failed.|

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.info("join session");
});
// Exit the distributed network.
g_object.setSessionId(() => {
    console.info("leave all session.");
});
```

### setSessionId<sup>9+</sup>

setSessionId(sessionId?: string): Promise&lt;void&gt;

Sets a session ID for synchronization. Automatic synchronization is performed for multiple devices with the same session ID on a trusted network.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sessionId | string | No| ID of a distributed data object on a trusted network. To remove a distributed data object from the network, set this parameter to "" or leave it empty.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

  For details about the error codes, see [Distributed Data Object Error Codes](../errorcodes/errorcode-distributed-dataObject.md).

| ID| Error Message|
| -------- | -------- |
| 15400001 | Create table failed.|

**Example**

```ts
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId()).then (()=>{
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

on(type: 'change', callback: (sessionId: string, fields: Array&lt;string&gt;) => void ): void

Subscribes to data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | Yes| Callback invoked to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**

```ts
g_object.on("change", (sessionId: string, fields: Array<string>) => {
    console.info("change" + sessionId);
    if (fields != null && fields != undefined) {
        for (let index: number = 0; index < fields.length; index++) {
            console.info("changed !" + fields[index] + " " + g_object[fields[index]]);
        }
    }
});
```

### off('change')<sup>9+</sup>

off(type: 'change', callback?: (sessionId: string, fields: Array&lt;string&gt;) => void ): void

Unsubscribes from the data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **change**, which indicates data changes.|
| callback | Function | No| Callback for data changes. If this parameter is not specified, all data change callbacks of this distributed data object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|


**Example**

```ts
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

### on('status')<sup>9+</sup>

on(type: 'status', callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void): void

Subscribes to status changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Function | Yes| Callback invoked to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the device.<br>**status** indicates the object status, which can be online or offline.|

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
| callback | Function | No| Callback for status changes. If this parameter is not specified, all status change callbacks of this distributed data object will be unsubscribed from.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the distributed data object.<br>**status** indicates the object status, which can be online or offline.|


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
| deviceId | string | Yes| ID of the device where data is stored. The value **local** indicates the local device.|
| callback | AsyncCallback&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | Yes| Callback invoked to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Example**

```ts
g_object.setSessionId("123456");
g_object.save("local", (err: BusinessError, result:distributedObject.SaveSuccessResponse) => {
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
| deviceId | string | Yes| ID of the device where the data is saved. The default value is **local**, which indicates the local device. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[SaveSuccessResponse](#savesuccessresponse9)&gt; | Promise used to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Example**

```ts
g_object.setSessionId("123456");
g_object.save("local").then((result: distributedObject.SaveSuccessResponse) => {
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
| callback | AsyncCallback&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse9)&gt; | Yes| Callback invoked to return **RevokeSaveSuccessResponse**, which contains the session ID.|

**Example**

```ts
g_object.setSessionId("123456");
// Save data for persistence. 
g_object.save("local", (err: BusinessError, result: distributedObject.SaveSuccessResponse) => {
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
g_object.revokeSave((err: BusinessError, result: distributedObject.RevokeSaveSuccessResponse) => {
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

**Example**

```ts
g_object.setSessionId("123456");
// Save data for persistence. 
g_object.save("local").then((result: distributedObject.SaveSuccessResponse) => {
    console.info("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}).catch((err: BusinessError) => {
    console.info("save failed, error code = " + err.code);
    console.info("save failed, error message: " + err.message);
});
// Delete the persistence data.
g_object.revokeSave().then((result: distributedObject.RevokeSaveSuccessResponse) => {
    console.info("revokeSave callback");
    console.info("sessionId" + result.sessionId);
}).catch((err: BusinessError)=> {
    console.info("revokeSave failed, error code = " + err.code);
    console.info("revokeSave failed, error message = " + err.message);
});
```

## distributedObject.createDistributedObject<sup>(deprecated)</sup>

createDistributedObject(source: object): DistributedObject


Creates a distributed data object.

> **NOTE**<br/>
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use **distributedObject.create**.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | object | Yes| Attributes of the distributed data object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [DistributedObject](#distributedobjectdeprecated) | Distributed data object created.|

**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);
```

## DistributedObject<sup>(deprecated)</sup>

Provides APIs for managing a distributed data object. Before using any API of this class, use [createDistributedObject()](#distributedobjectcreatedistributedobjectdeprecated) to create a **DistributedObject** object.

### setSessionId<sup>(deprecated)</sup>

setSessionId(sessionId?: string): boolean

Sets a session ID for synchronization. Automatic synchronization is performed for multiple devices with the same session ID on a trusted network.

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
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId());
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
| callback | Function | Yes| Callback invoked to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);
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
| callback | Function | No| Callback for data changes. If this parameter is not specified, all data change callbacks of this distributed data object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);
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
| callback | Function | Yes| Callback invoked to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the device.<br>**status** indicates the object status, which can be online or offline.|

**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);

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
| callback | Function | No| Callback for status changes. If this parameter is not specified, all status change callbacks of this distributed data object will be unsubscribed from.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** identifies the distributed data object.<br>**status** indicates the object status, which can be online or offline.|


**Example**

```ts
import distributedObject from '@ohos.data.distributedDataObject';
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

let source: SourceObject = new SourceObject("amy", 18, false);
let g_object: distributedObject.DistributedObject = distributedObject.createDistributedObject(source);
// Unregister the specified status change callback.
g_object.off("status", (sessionId: string, networkId: string, status: 'online' | 'offline') => {
    console.info("status changed " + sessionId + " " + status + " " + networkId);
});
// Unregister all status change callbacks.
g_object.off("status");
```

# @ohos.data.distributedDataObject (Distributed Data Object)

The **distributedDataObject** module provides basic data object management, including creating, querying, deleting, modifying, and subscribing to data objects, and distributed data object collaboration for the same application among multiple devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
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

```js
// Import the module.
import distributedObject from '@ohos.data.distributedDataObject';
import featureAbility from '@ohos.ability.featureAbility';
// Obtain the context.
let context = featureAbility.getContext();
// Create a distributed data object, which contains attributes of the string, number, boolean, and object types.
let g_object = distributedObject.create(context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
```

Stage model:

```ts
// Import the module.
import distributedObject from '@ohos.data.distributedDataObject';
import UIAbility from '@ohos.app.ability.UIAbility';

let g_object = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
        // Create a distributed data object, which has attributes of the string, number, boolean, and object types.
        g_object = distributedObject.create(this.context, {name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
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

```js
import distributedObject from '@ohos.data.distributedDataObject';
let sessionId = distributedObject.genSessionId();
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

```js
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

```js
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId(), ()=>{
    console.info("join session");
});
// Exit the distributed network.
g_object.setSessionId(() => {
    console.info("leave all lession.");
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

```js
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId()).then (()=>{
    console.info("join session.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
// Exit the distributed network.
g_object.setSessionId().then (()=>{
    console.info("leave all lession.");
    }).catch((error)=>{
        console.info("error:" + error.code + error.message);
});
```

### on('change')<sup>9+</sup>

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Subscribes to data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **change**, which indicates data changes.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | Yes| Callback invoked to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**

```js
globalThis.changeCallback = (sessionId, changeData) => {
    console.info("change" + sessionId);
    if (changeData != null && changeData != undefined) {
        changeData.forEach(element => {
        console.info("changed !" + element + " " + g_object[element]);
        });
    }
}
g_object.on("change", globalThis.changeCallback);
```

### off('change')<sup>9+</sup>

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Unsubscribes from the data changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **change**, which indicates data changes.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | No| Callback for data changes. If this parameter is not specified, all data change callbacks of this distributed data object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|


**Example**

```js
// Unregister the specified data change callback.
g_object.off("change", globalThis.changeCallback);
// Unregister all data change callbacks.
g_object.off("change");
```

### on('status')<sup>9+</sup>

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

Subscribes to status changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | Yes| Callback invoked to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** indicates the object device ID, that is, **deviceId**.<br>**status** indicates the object status, which can be online or offline.|

**Example**

```js
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
g_object.on("status", globalThis.statusCallback);
```

### off('status')<sup>9+</sup>

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void

Unsubscribes from the status change of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
  | callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | No| Callback for status changes. If this parameter is not specified, all status change callbacks of this distributed data object will be unsubscribed from.<br>**sessionId** indicates the session ID of the distributed data object.<br>**deviceId** indicates the device ID of the distributed data object.<br>**status** indicates the object status, which can be online or offline.|


**Example**

```js
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// Unregister the specified status change callback.
g_object.off("status",globalThis.statusCallback);
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
g_object.save("local", (err, result) => {
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

```js
g_object.setSessionId("123456");
g_object.save("local").then((result) => {
    console.info("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}).catch((err) => {
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

```js
g_object.setSessionId("123456");
// Save data for persistence. 
g_object.save("local", (err, result) => {
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
g_object.revokeSave((err, result) => {
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
g_object.save("local").then((result) => {
    console.info("save callback");
    console.info("save sessionId " + result.sessionId);
    console.info("save version " + result.version);
    console.info("save deviceId " + result.deviceId);
}).catch((err) => {
    console.info("save failed, error code = " + err.code);
    console.info("save failed, error message: " + err.message);
});
// Delete the persistence data.
g_object.revokeSave().then((result) => {
    console.info("revokeSave callback");
    console.info("sessionId" + result.sessionId);
}).catch((err)=> {
    console.info("revokeSave failed, error code = " + err.code);
    console.info("revokeSave failed, error message = " + err.message);
});
```

## distributedObject.createDistributedObject<sup>(deprecated)</sup>

createDistributedObject(source: object): DistributedObject


Creates a distributed data object.

> **NOTE**
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

```js
import distributedObject from '@ohos.data.distributedDataObject';
// Create a distributed data object, which contains attributes of the string, number, boolean, and object types.
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
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

```js
import distributedObject from '@ohos.data.distributedDataObject';
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});;
// Add g_object to the distributed network.
g_object.setSessionId(distributedObject.genSessionId());
// Remove g_object from the distributed network.
g_object.setSessionId("");
```

### on('change')<sup>(deprecated)</sup>

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Subscribes to data changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('change')](#onchange9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **change**, which indicates data changes.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | Yes| Callback invoked to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**

```js
import distributedObject from '@ohos.data.distributedDataObject';
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.changeCallback = (sessionId, changeData) => {
    console.info("change" + sessionId);
    if (changeData != null && changeData != undefined) {
        changeData.forEach(element => {
        console.info("changed !" + element + " " + g_object[element]);
        });
    }
}
g_object.on("change", globalThis.changeCallback);
```

### off('change')<sup>(deprecated)</sup>

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Unsubscribes from the data changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [off('change')](#offchange9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **change**, which indicates data changes.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | No| Callback for data changes. If this parameter is not specified, all data change callbacks of this distributed data object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|


**Example**

```js
import distributedObject from '@ohos.data.distributedDataObject';
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
// Unregister the specified data change callback.
g_object.off("change", globalThis.changeCallback);
// Unregister all data change callbacks.
g_object.off("change");
```

### on('status')<sup>(deprecated)</sup>

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

Subscribes to status changes of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('status')](#onstatus9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | Yes| Callback invoked to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** indicates the object device ID, that is, **deviceId**.<br>**status** indicates the object status, which can be online or offline.|

**Example**

```js
import distributedObject from '@ohos.data.distributedDataObject';
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
g_object.on("status", globalThis.statusCallback);
```

### off('status')<sup>(deprecated)</sup>

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void

Unsubscribes from the status change of this distributed data object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [off('status')](#offstatus9).

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | No| Callback for status changes. If this parameter is not specified, all status change callbacks of this distributed data object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**deviceId** indicates the device ID of the distributed data object.<br>**status** indicates the object status, which can be online or offline.|


**Example**

```js
import distributedObject from '@ohos.data.distributedDataObject';
let g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// Unregister the specified status change callback.
g_object.off("status",globalThis.statusCallback);
// Unregister all status change callbacks.
g_object.off("status");
```

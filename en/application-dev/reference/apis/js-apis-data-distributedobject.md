# Distributed Data Object

Provides basic data object management, including creating, querying, deleting, modifying, and subscribing to data objects, and distributed data object collaboration for the same application among multiple devices.

> **NOTE**<br/>
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import distributedObject from '@ohos.data.distributedDataObject';
```

## distributedDataObject.createDistributedObject

createDistributedObject(source: object): DistributedObject


Creates a distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | object | Yes| Attribute of the distributed data object to create.|

**Return value**
| Type| Description|
| -------- | -------- |
| [DistributedObject](#distributedobject) | Distributed data object created.|

**Example**
  ```js
  import distributedObject from '@ohos.data.distributedDataObject';
  // Create a distributed data object, which contains attributes of four types, namely, string, number, boolean, and object.
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
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
  var sessionId = distributedObject.genSessionId();
  ```

## SaveSuccessResponse<sup>9+</sup>

Called when the **Save()** API is successfully called.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Description|
| -------- | -------- | -------- |
| sessionId | string | Unique ID for multi-device collaboration.|
| version | number |Version of the distributed data object saved.|
| deviceId | string | ID of the device where the distributed data object is stored. The default value is **local**, which identifies a local device. You can set it as required.|

## RevokeSaveSuccessResponse<sup>9+</sup>

Called when the **revokeSave()** API is successfully called.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

| Name| Type| Description|
| -------- | -------- | -------- |
| sessionId | string | Unique ID for multi-device collaboration.|

## DistributedObject

Represents a distributed data object.

### setSessionId

setSessionId(sessionId?: string): boolean

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
| boolean | Returns **true** if the session ID is set successfully;<br>returns **false** otherwise. |

**Example**

  ```js
  import distributedObject from '@ohos.data.distributedDataObject';
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  // Add g_object to the distributed network.
  g_object.setSessionId(distributedObject.genSessionId());
  // Remove g_object from the distributed network.
  g_object.setSessionId("");
  ```


### on('change')

on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Subscribes to the changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to subscribe to. The value is **change**, which indicates data changes.|
| callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | Yes| Callback used to return the changes of the distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|

**Example**
```js
import distributedObject from '@ohos.data.distributedDataObject';  
var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false,parent:{mother:"jack mom",father:"jack Dad"}});
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

### off('change')

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Unsubscribes from the changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **change**, which indicates data changes.|
| callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | No| Callback to be unregistered. If this parameter is not set, all data change callbacks of the object will be unregistered.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|


**Example**
```js
import distributedObject from '@ohos.data.distributedDataObject';  
var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false,parent:{mother:"jack mom",father:"jack Dad"}});
// Unregister the specified data change callback.
g_object.off("change", globalThis.changeCallback);
// Unregister all data change callbacks.
g_object.off("change");
```

### on('status')

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

Subscribes to the status change (online or offline) of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to subscribe to. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | Yes| Callback used to return the status change.<br>**sessionId**: session ID of the distributed data object.<br>**networkId**: object device ID, that is, **deviceId**.<br>**status** indicates the object status, which can be online or offline. |

**Example**
```js
import distributedObject from '@ohos.data.distributedDataObject';
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false,parent:{mother:"jack mom",father:"jack Dad"}});
g_object.on("status", globalThis.statusCallback);
```

### off('status')

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void


Unsubscribes from the status change (online or offline) of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **status**, which indicates the status change (online or offline) of the distributed data object.|
| callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | No| Callback used to return the status change. If this parameter is not specified, this API unsubscribes from all callbacks of this distributed data object.<br>**sessionId**: session ID of the distributed data object.<br>**deviceId** indicates the device ID of the distributed data object.<br>**status** indicates the status, which can be online or offline.|


**Example**
```js
import distributedObject from '@ohos.data.distributedDataObject'; 
var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false,parent:{mother:"jack mom",father:"jack Dad"}});
globalThis.statusCallback = (sessionId, networkId, status) => {
    globalThis.response += "status changed " + sessionId + " " + status + " " + networkId;
}
// Unsubscribe from the specified status change callback for the distributed data object.
g_object.off("status",globalThis.statusCallback);
// Unsubscribe from all status change callbacks for the distributed data object.
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
| callback | AsyncCallback&lt;[SaveSuccessResponse](#savesuccessresponse)&gt; | Yes| Callback used to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Example**

  ```ts
  import distributedObject from '@ohos.data.distributedDataObject';
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false});
  g_object.setSessionId("123456");
  g_object.save("local", (result)=>{
      console.log("save callback");
      console.info("save sessionId " + result.sessionId);
      console.info("save version " + result.version);
      console.info("save deviceId " + result.deviceId);
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
| Promise&lt;[SaveSuccessResponse](#savesuccessresponse)&gt; | Promise used to return **SaveSuccessResponse**, which contains information such as session ID, version, and device ID.|

**Example**

  ```ts
  import distributedObject from '@ohos.data.distributedDataObject';
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false});
  g_object.setSessionId("123456");
  g_object.save("local").then((result)=>{
      console.log("save callback");
      console.info("save sessionId " + result.sessionId);
      console.info("save version " + result.version);
      console.info("save deviceId " + result.deviceId);
  }, ()=>{
      console.error("save failed");
  });
  ```

### revokeSave<sup>9+</sup>

revokeSave(callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void

Revokes the saving operation of a distributed data object. This API uses an asynchronous callback to return the result.

If the object is saved on the local device, the data saved on all trusted devices will be deleted.
If the object is stored on another device, the data on the local device will be deleted.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse)&gt; | No| Callback used to return **RevokeSaveSuccessResponse**, which contains the session ID.|

**Example**

  ```ts
  import distributedObject from '@ohos.data.distributedDataObject';
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false});
  g_object.setSessionId("123456");
  g_object.revokeSave((result, data) =>{
    console.log("revokeSave callback");
  });
  ```

### revokeSave<sup>9+</sup>

revokeSave(): Promise&lt;SaveSuccessResponse&gt;

Revokes the saving operation of a distributed data object. This API uses a promise to return the result.

If the object is saved on the local device, the data saved on all trusted devices will be deleted.
If the object is stored on another device, the data on the local device will be deleted.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

  **Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[RevokeSaveSuccessResponse](#revokesavesuccessresponse)&gt; | Promise used to return **RevokeSaveSuccessResponse**, which contains the session ID.|

**Example**

  ```ts
  import distributedObject from '@ohos.data.distributedDataObject';
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false});
  g_object.setSessionId("123456");
  g_object.revokeSave("local").then((result)=>{
      console.log("revokeSave callback");
      console.log("sessionId" + result.sessionId);
  }, ()=>{
      console.error("revokeSave failed");
  });
  ```

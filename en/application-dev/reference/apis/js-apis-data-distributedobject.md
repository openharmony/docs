# Distributed Data Object

> **NOTE**<br/>
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
  import distributedObject from '@ohos.data.distributedDataObject'
  // Create a distributed data object, which contains attributes of four types, namely, string, number, boolean, and object.
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  ```


## distributedObject.genSessionId()

genSessionId(): string

Creates a random session ID.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Return value**
  | Type| Description|
  | -------- | -------- |
  | string | Session ID created.|

**Example**
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var sessionId = distributedObject.genSessionId();
  ```


## DistributedObject

Represents a distributed data object.

### setSessionId

setSessionId(sessionId?: string): boolean

Sets a session ID for synchronization. Automatic synchronization is performed for multiple devices with the same session ID on a trusted network.

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
  import distributedObject from '@ohos.data.distributedDataObject'
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
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  g_object.on("change", function (sessionId, changeData) {
      console.info("change" + sessionId);  
      if (changeData != null && changeData != undefined) {
          changeData.forEach(element => {
              console.info("changed !" + element + " " + g_object[element]);
          });
      }
  });
  ```

### off('change')

off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void

Unsubscribes from the changes of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to unsubscribe from. The value is **change**, which indicates data changes.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | No| Callback used to return the changes of the distributed data object. If this parameter is not specified, this API unsubscribes from all callbacks for data changes of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**fields** indicates the changed attributes of the distributed data object.|


**Example**
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  g_object.on("change", function (sessionId, changeData) {
      console.info("change" + sessionId);
  });
  // Unsubscribe from the specified data change callback for the distributed data object.
  g_object.off("change", function (sessionId, changeData) {
      console.info("change" + sessionId);
  });
  // Unsubscribe from all data change callbacks for the distributed data object.
  g_object.off("change");
  ```

### on('status')

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

Subscribes to the status change (online or offline) of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **status**, which indicates the change in the status (online or offline) of the distributed data object.|
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | Yes| Callback used to return the status change.<br>**sessionId** indicates the session ID of the distributed data object.<br>**networkId** indicates the network ID of the device.<br>**status** indicates the status, which can be online or offline.|

**Example**
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  g_object.on("status", function (sessionId, networkid, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  });
  ```

### off('status')

off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>): void


Unsubscribes from the status change (online or offline) of this distributed data object.

**System capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to unsubscribe from. The value is **status**, which indicates the change in the status (online or offline) of the distributed data object.|
  | callback | Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }> | No| Callback used to return the status change. If this parameter is not specified, this API unsubscribes from all callbacks of this distributed data object.<br>**sessionId** indicates the session ID of the distributed data object.<br>**deviceId** indicates the device ID of the distributed data object.<br>**status** indicates the status, which can be online or offline.|


**Example**
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'  
  g_object.on("status", function (sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  });
  // Unsubscribe from the specified status change callback for the distributed data object.
  g_object.off("status", function (sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  });
  // Unsubscribe from all status change callbacks for the distributed data object.
  g_object.off("status");
  ```

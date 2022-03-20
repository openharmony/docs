# Distributed Object

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import distributedObject from '@ohos.data.distributedDataObject'
```



## distributedDataObject.createDistributedObject

createDistributedObject(source: object): DistributedObject


Creates a **distributedObject** instance. You can specify the attribute of the instance in **source**. This method returns the **distributedObject** instance created.

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | object | source | Yes| Attribute of the **distributedObject** instance to create.|
  
- Example
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  // Create a distributedObject instance. The attribute type of the object can be string, number, boolean, or Object.
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  ```


## distributedObject.genSessionId()

genSessionId(): string

Creates a session ID randomly.

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- Return value
  | Type| Description|
  | -------- | -------- |
  | string | Session ID created.|

- Example
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var sessionId = distributedObject.genSessionId();
  ```


## DistributedObject

Represents a **distributedObject** instance.
### setSessionId

setSessionId(sessionId?: string): boolean

Sets a session ID for synchronization. Automatic synchronization is performed for multiple devices with the same session ID on a trusted network. To remove a device from the distributed network, set this parameter to "" or leave it unspecified. If **true** is returned, the session ID is set successfully.

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sessionId | string | No| ID of a distributed object on a trusted network.|
  
- Example
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

Subscribes to the data changes of this distributed object.

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **change**, which indicates data change events.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | Yes| Callback used to return the data changes of the distributed object. In the callback, **sessionId** indicates the session ID of the distributed object, and **fields** indicates the attributes of the object.|

- Example
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

Unsubscribes from the data changes of this distributed object.

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to unsubscribe from. The value is **change**, which indicates data change events.|
  | callback | Callback<{ sessionId: string, fields: Array&lt;string&gt; }> | No| Callback used to return changes of the distributed object. If this parameter is not specified, all callbacks related to data changes will be unregistered.|


- Example
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'
  var g_object = distributedObject.createDistributedObject({name:"Amy", age:18, isVis:false, 
                 parent:{mother:"jack mom",father:"jack Dad"}});
  g_object.on("change", function (sessionId, changeData) {
      console.info("change" + sessionId);
  });
  // Unsubscribe from the data change callback for the specified distributed object.
  g_object.off("change", function (sessionId, changeData) {
      console.info("change" + sessionId);
  });
  // Unsubscribe from all data change callbacks.
  g_object.off("change");
  ```

### on('status')

on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>): void

Subscribes to the status changes (online or offline) of this distributed object. 

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is "status", which indicates the status (online or offline) change events.|
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | Yes| Callback used to return the status changes of the distributed object. In the callback, **sessionId** indicates the session ID of the distributed object, and **status** indicates the online or offline status of the distributed object.|

- Example
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


Unsubscribes from the status (online or offline) changes of the distributed object. 

** System Capability**: SystemCapability.DistributedDataManager.DataObject.DistributedObject

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is "status", which indicates the status (online or offline) change events.|
  | callback | Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }> | No| Callback used to return the status changes. If this parameter is not specified, all the status change callbacks will be unregistered.|


- Example
  ```js
  import distributedObject from '@ohos.data.distributedDataObject'  
  g_object.on("status", function (sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  });
  // Unsubscribe from the status change callback for the specified distributed object.
  g_object.off("status", function (sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
  });
  // Unsubscribe from all status change callbacks.
  g_object.off("status");
  ```

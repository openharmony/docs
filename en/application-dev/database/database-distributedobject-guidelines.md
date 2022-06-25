# Distributed Data Object Development

## When to Use

The distributed data objects allow data across devices to be processed like local variables by shielding complex data interaction between devices. For the devices that form a Super Device, when data in the distributed data object of an application is added, deleted, or modified on a device, the data for the same application is also updated on the other devices. The devices can listen for the data changes and online and offline status of other devices. The distributed data objects support basic data types, such as number, string, and Boolean, as well as complex data types, such as array and nested basic types.


## Available APIs

### Creating a Distributed Data Object Instance

Call **createDistributedObject()** to create a distributed data object instance. You can specify the attributes of the instance in **source**.


**Table 1** API for creating a distributed data object instance
 | Package | API | Description | 
 | -------- | -------- | -------- |
 | ohos.data.distributedDataObject | createDistributedObject(source: object): DistributedObject | Creates a distributed data object instance for data operations.<br>-&nbsp;**source**: attributes of the **distributedObject** set.<br>-&nbsp;**DistributedObject**: returns the distributed object created. | 

### Generating a Session ID

Call **genSessionId()** to generate a session ID randomly. The generated session ID can be used to set the session ID of a distributed data object.

**Table 2** API for generating a session ID randomly
 | Package | API | Description |
 | -------- | -------- | -------- |
 | ohos.data.distributedDataObject | genSessionId(): string | Generates a session ID, which can be used as the session ID of a distributed data object. |

### Setting a SessionID for Distributed Data Objects

Call **setSessionId()** to set a session ID for a distributed data object. The session ID is a unique identifier for one collaboration across devices. The distributed data objects to be synchronized must be associated with the same session ID.

**Table 3** API for setting a session ID
 | Class | API | Description |
 | -------- | -------- | -------- |
 | DistributedDataObject | setSessionId(sessionId?: string): boolean | Sets a session ID for distributed data objects.<br>**sessionId**: session ID of a distributed object in a trusted network. To remove a distributed data object from the network, set this parameter to "" or leave it empty. |

### Observing Data Changes

Call **on()** to subscribe to data changes of a distributed data object. When the data changes, a callback will be invoked to return the data changes. You can use **off()** to unsubscribe from the data changes.

**Table 4** APIs for observing data changes of a distributed data object
 | Class | API | Description | 
 | -------- | -------- | -------- |
 | DistributedDataObject | on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | Subscribes to data changes. | 
 | DistributedDataObject | off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | Unsubscribes from data changes. <br>**Callback**: specifies callback used to return changes of the distributed data object. If this parameter is not specified, all callbacks related to data changes will be unregistered. |

### Observing Online or Offline Status

Call **on()** to subscribe to status changes of a distributed data object. The status can be online or offline. When the status changes, a callback will be invoked to return the status. You can use **off()** to unsubscribe from the status changes.

**Table 5** APIs for observing status changes of a distributed data object
 | Class | API | Description |
 | -------- | -------- | -------- |
 | DistributedDataObject | on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' \ | 'offline' }>): void | Subscribes to the status changes of a distributed data object. |
 | DistributedDataObject | off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' \ | 'offline' }>): void | Unsubscribes from status changes of a distributed data object. |



## How to Develop

The following example shows how to implement a distributed data object synchronization.

1. Import the @ohos.data.distributedDataObject module to the development environment.

   ```js
   import distributedObject from '@ohos.data.distributedDataObject'
   ```

2. Obtain a distributed data object instance.

   ```js
   var local_object = distributedObject.createDistributedObject({name:undefined, age:undefined, isVis:true, 
                  parent:undefined, list:undefined});
   var sessionId = distributedObject.genSessionId();
   ```


3. Add the synchronization network. The data objects in the synchronization network include the local and remote objects.

   ```js
   // Local object
   var local_object = distributedObject.createDistributedObject({name:"jack", age:18, isVis:true, 
       parent:{mother:"jack mom",father:"jack Dad"},list:[{mother:"jack mom"}, {father:"jack Dad"}]});
   local_object.setSessionId(sessionId);
   
   // Remote object
   var remote_object = distributedObject.createDistributedObject({name:undefined, age:undefined, isVis:true, 
                  parent:undefined, list:undefined});
   remote_object.setSessionId(sessionId);
   // After learning that the device goes online, the remote object synchronizes data. That is, name changes to jack and age to 18.
   ```
   
4. Observe the data changes of the distributed data object. You can subscribe to data changes of the remote object. When the data in the remote object changes, a callback will be called to return the data changes.
 
   ```js
   function changeCallback(sessionId, changeData) {
        console.info("change" + sessionId);
   
        if (changeData != null && changeData != undefined) {
            changeData.forEach(element => {
                console.info("changed !" + element + " " + local_object[element]);
        });
        }
    } 
   
    // To refresh the page in changeCallback, correctly bind (this) to the changeCallback.
    local_object.on("change", this.changeCallback.bind(this));
   ```
   
5. Modify object attributes. The object attributes support basic data types (such as number, Boolean, and string) and complex data types (array and nested basic types).

   ```js
   local_object.name = "jack";
   local_object.age = 19;
   local_object.isVis = false;
   local_object.parent = {mother:"jack mom",father:"jack Dad"};
   local_object.list = [{mother:"jack mom"}, {father:"jack Dad"}];
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
   > For the distributed data object of the complex type, only the root attribute can be modified. The subordinate attributes cannot be modified. Example:
   ```js
   // Supported modification.
   local_object.parent = {mother:"mom", father:"dad"};
   // Modification not supported.
   local_object.parent.mother = "mom";
   ```

6. Access the distributed data object. Obtain the distributed data object attribute, which is the latest data on the network.

   ```js
   console.info("name " + local_object["name"]); 
   ```

7. Unsubscribe from data changes. You can specify the callback to unsubscribe from. If you do not specify the callback, all data change callbacks of the distributed data object will be unsubscribed from.

   ```js
   // Unsubscribe from the specified data change callback.
   local_object.off("change", changeCallback);
   // Unsubscribe from all data change callbacks. 
   local_object.off("change"); 
   ```

8. Subscribe to the status (online/offline) changes of the distributed data object. A callback will be invoked to report the status change when the target distributed data object goes online or offline.

   ```js
    function statusCallback(sessionId, networkId, status) {
      this.response += "status changed " + sessionId + " " + status + " " + networkId;
    }
   
    local_object.on("status", this.statusCallback);
   ```

9. Unsubscribe from the status changes of the distributed data object. You can specify the callback to unsubscribe from. If you do not specify the callback, this API unsubscribes from all callbacks of this distributed data object.

   ```js
   // Unsubscribe from the specified status change callback.
   local_object.off("status", statusCallback);
   // Unsubscribe from all status change callbacks.
   local_object.off("status");
   ```

10. Remove a distributed data object from the synchronization network. Data changes on the local object will not be synchronized to the removed distributed data object.

    ```js
    local_object.setSessionId("");
    ```
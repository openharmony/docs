# Distributed Data Object Development

## When to Use

The **distributedDataObject** module provides APIs to implement data collaboration of the same application across multiple devices. In addition, the devices that form a Super Device can listen for object status and data changes with each other.

For example, when the data of a distributed data object is added, deleted, or modified for application A on device 1, application A on device 2 can obtain the updated data. In addition, device 2 can listen for data changes and online/offline of the data objects on device 1.

## Available APIs

For details about the APIs, see [Distributed Data Object](../reference/apis/js-apis-data-distributedobject.md).

### Creating a Distributed Data Object Instance

Call **createDistributedObject()** to create a distributed data object instance. You can specify the attributes of the instance in **source**.


**Table 1** API for creating a distributed data object instance

| Bundle Name| API| Description|
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| createDistributedObject(source: object): DistributedObject | Creates a distributed data object instance for data operations.<br>- **source**: attributes of the distributed data object to create.<br>- **DistributedObject**: returns the distributed data object created.|

### Generating a Session ID

Call **genSessionId()** to generate a session ID randomly. The generated session ID can be used to set the session ID of a distributed data object.

**Table 2** API for generating a session ID randomly

| Bundle Name| API| Description|
| -------- | -------- | -------- |
| ohos.data.distributedDataObject| genSessionId(): string | Generates a session ID, which can be used as the session ID of a distributed data object.|

### Setting a Session ID for a Distributed Data Object

Call **setSessionId()** to set a session ID for a distributed data object. The session ID is a unique identifier for one collaboration across devices. The distributed data objects to be synchronized must be associated with the same session ID.

**Table 3** API for setting a session ID

| Class| API| Description|
| -------- | -------- | -------- |
| DistributedDataObject | setSessionId(sessionId?: string): boolean | Sets a session ID for this distributed data object.<br>**sessionId**: ID of the distributed data object on a trusted network. To remove a distributed data object from the network, set this parameter to "" or leave it empty.|

### Observing Data Changes

Call **on()** to subscribe to data changes of a distributed data object. When the data changes, a callback will be invoked to return the data changes. You can use **off()** to unsubscribe from the data changes.

**Table 4** APIs for observing data changes of a distributed data object

| Class| API| Description|
| -------- | -------- | -------- |
| DistributedDataObject| on(type: 'change', callback: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | Subscribes to data changes.|
| DistributedDataObject| off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array&lt;string&gt; }>): void | Unsubscribes from data changes. <br/>**Callback**: callback to unregister. If this parameter is not specified, all data changes of this distributed data object will be unsubscribed from. |

### Observing Online or Offline Status

Call **on()** to subscribe to status changes of a distributed data object. The status can be online or offline. When the status changes, a callback will be invoked to return the status. You can use **off()** to unsubscribe from the status changes.

**Table 5** APIs for observing status changes of a distributed data object

| Class| API| Description|
| -------- | -------- | -------- |
| DistributedDataObject| on(type: 'status', callback: Callback<{ sessionId: string, networkId: string, status: 'online' \| 'offline' }>): void | Subscribes to the status changes of a distributed data object.|
| DistributedDataObject| off(type: 'status', callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' \| 'offline' }>): void | Unsubscribes from status changes of a distributed data object.|

### Saving or Deleting a Distributed Data Object

Call **save()** to save a distributed data object. When the application is active, the saved data will not be released. When the application exits and restarts, the data saved on the device will be restored.

Call **revokeSave()** to delete a distributed data object that is no longer required. If the distributed data object is saved on the local device, **revokeSave()** will delete the data from all trusted devices. If the distributed data object is not saved on the local device, **revokeSave()** will delete the data from the local device.

The saved data will be released in the following cases:

- The data is stored for more than 24 hours.
- The application has been uninstalled.
- Data is successfully restored.

**Table 6** APIs for saving and deleting a distributed data object

| Class| API| Description|
| -------- | -------- | -------- |
| DistributedDataObject | save(deviceId: string): Promise&lt;SaveSuccessResponse&gt; | Saves a distributed data object.|
| DistributedDataObject| revokeSave(): Promise&lt;RevokeSaveSuccessResponse&gt; | Deletes a distributed data object. |

## How to Develop

The following example shows how to implement distributed data object synchronization.

1. Import the @ohos.data.distributedDataObject module to the development environment.

   ```js   
   import distributedObject from '@ohos.data.distributedDataObject';   
   ```
2. Apply for the permission.

   Add the required permission (FA model) to the **config.json** file.

   ```json
   {
       "module": {
           "reqPermissions": [
               {
                   "name": "ohos.permission.DISTRIBUTED_DATASYNC"
               }
           ]
       }
   }
   ```
   For the apps based on the stage model, see [Declaring Permissions](../security/accesstoken-guidelines.md#stage-model).

   This permission must also be granted by the user when the application is started for the first time.

   ```js
   // FA model
   import featureAbility from '@ohos.ability.featureAbility';

   function grantPermission() {
       console.info('grantPermission');
       let context = featureAbility.getContext();
       context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666, function (result) {
           console.info(`requestPermissionsFromUser CallBack`);

       })
       console.info('end grantPermission');
   }

   grantPermission();
   ```

   ```ts
   // Stage model
   import UIAbility from '@ohos.app.ability.UIAbility';

   let context = null;

   class EntryAbility  extends UIAbility  {
     onWindowStageCreate(windowStage) {
       context = this.context;
     }
   }

   function grantPermission() {
     let permissions = ['ohos.permission.DISTRIBUTED_DATASYNC'];
     context.requestPermissionsFromUser(permissions).then((data) => {
       console.info('success: ${data}');
     }).catch((error) => {
       console.error('failed: ${error}');
     });
   }

   grantPermission();
   ```
   
3. Obtain a distributed data object instance.

   ```js
   let localObject = distributedObject.createDistributedObject({
       name: undefined,
       age: undefined,
       isVis: true,
       parent: undefined,
       list: undefined
   });
   let sessionId = distributedObject.genSessionId();
   ```

4. Add the distributed data object instance to a network for data synchronization. The data objects in the synchronization network include the local and remote objects.

   ```js
   // Local object
   let localObject = distributedObject.createDistributedObject({
       name: "jack",
       age: 18,
       isVis: true,
       parent: { mother: "jack mom", father: "jack Dad" },
       list: [{ mother: "jack mom" }, { father: "jack Dad" }]
   });
   localObject.setSessionId(sessionId);
   
   // Remote object
   let remoteObject = distributedObject.createDistributedObject({
       name: undefined,
       age: undefined,
       isVis: true,
       parent: undefined,
       list: undefined
   });
   // After learning that the local device goes online, the remote object synchronizes data. That is, name changes to jack and age to 18.
   remoteObject.setSessionId(sessionId);
   ```

5. Observe the data changes of the distributed data object. You can subscribe to data changes of the remote object. When the data in the remote object changes, a callback will be invoked to return the data changes.
   
   ```js
   function changeCallback(sessionId, changeData) {
       console.info("change" + sessionId);
   
       if (changeData != null && changeData != undefined) {
           changeData.forEach(element => {
               console.info("changed !" + element + " " + localObject[element]);
           });
       }
   } 
   
   // To refresh the page in changeCallback, correctly bind (this) to the changeCallback.
   localObject.on("change", this.changeCallback.bind(this));
   ```
   
6. Modify attributes of the distributed data object. The object attributes support basic data types (such as number, Boolean, and string) and complex data types (array and nested basic types).

   ```js
   localObject.name = "jack";
   localObject.age = 19;
   localObject.isVis = false;
   localObject.parent = { mother: "jack mom", father: "jack Dad" };
   localObject.list = [{ mother: "jack mom" }, { father: "jack Dad" }];
   ```

   > **NOTE**<br>
   > For the distributed data object of the complex type, only the root attribute can be modified. The subordinate attributes cannot be modified.

   ```js
   // Supported modification.
   localObject.parent = { mother: "mom", father: "dad" };
   // Modification not supported.
   localObject.parent.mother = "mom";
   ```

7. Access the distributed data object.<br>Obtain the distributed data object attributes, which are the latest data on the network.

   ```js
   console.info("name " + localObject["name"]); 
   ```
8. Unsubscribe from data changes. You can specify the callback to unregister. If you do not specify the callback, all data change callbacks of the distributed data object will be unregistered.

   ```js
   // Unregister the specified data change callback.
   localObject.off("change", changeCallback);
   // Unregister all data change callbacks. 
   localObject.off("change"); 
   ```
9. Subscribe to status changes of this distributed data object. A callback will be invoked to report the status change when the target distributed data object goes online or offline.

   ```js
   function statusCallback(sessionId, networkId, status) {
       this.response += "status changed " + sessionId + " " + status + " " + networkId;
   }
   
   localObject.on("status", this.statusCallback);
   ```

10. Save a distributed data object and delete it.

    ```js
    // Save a distributed data object.
    localObject.save("local").then((result) => {
        console.info("save sessionId " + result.sessionId);
        console.info("save version " + result.version);
        console.info("save deviceId " + result.deviceId);
    }, (result) => {
        console.info("save local failed.");
    });
    // Revoke the data saving operation.
    localObject.revokeSave().then((result) => {
        console.info("revokeSave success.");
    }, (result) => {
        console.info("revokeSave failed.");
    });
    ```
11. Unsubscribe from the status changes of this distributed data object. You can specify the callback to unregister. If you do not specify the callback, this API unregisters all status change callbacks of this distributed data object.

    ```js
    // Unregister the specified status change callback.
    localObject.off("status", this.statusCallback);
    // Unregister all status change callbacks.
    localObject.off("status");
    ```
12. Remove the distributed data object from the synchronization network. The data changes on the local object will not be synchronized to the removed distributed data object.

    ```js
    localObject.setSessionId("");
    ```

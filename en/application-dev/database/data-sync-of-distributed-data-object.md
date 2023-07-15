# Cross-Device Synchronization of Distributed Data Objects


## When to Use

To implement traditional data synchronization between devices, you need to design the message processing logic, including setting up a communication link, sending, receiving, and processing messages, retry mechanism upon errors, and resolving data conflicts. The workload is heavy. In addition, the debugging complexity increases with the number of devices.

The device status, message sending progress, and data transmitted are variables. If these variables support global access, they can be accessed as local variables on difference devices. This simplifies data synchronization between multiple devices.

The distributed data object (**DataObject**) implements global access to variables. **DataObject** provides basic data object management capabilities and distributed capabilities. You can use the APIs to create, query, delete, and modify in-memory objects and subscribe to event notifications. OpenHarmony also provides easy-to-use JS APIs for distributed application scenarios to easily implement cross-device data collaboration for the same application. In addition, object status and data changes on different devices can be observed. This feature implements data object collaboration for the same application between multiple devices that form a Super Device. **DataObject** greatly reduces the development workloads compared with the traditional mode.


## Basic Concepts

- Distributed in-memory database<br>
  The distributed in-memory database caches data in the memory so that applications can quickly access data without persisting data. If the database is closed, the data is not retained.

- Distributed data object
  A distributed data object is an encapsulation of the JS object type. Each distributed data object instance creates a data table in the in-memory database. The in-memory databases created for different applications are isolated from each other. Reading data from and writing data to a distributed data object are mapped to the **get()** and **put()** operations in the corresponding database, respectively.

  The distributed data object can be in the following states in its lifecycle:

  - **Uninitialized**: The distributed data object is not instantiated or has been destroyed.
  - **Local**: The data table is created, but the data cannot be synchronized.
  - **Distributed**: The data table is created, and there are at least two online devices with the same session ID. In this case, data can be synchronized across devices. If a device is offline or the session ID is empty, the distributed data object changes to the local state.


## Working Principles

**Figure 1** Working mechanism

![distributedObject](figures/distributedObject.jpg)

The distributed data objects are encapsulated into JS objects in distributed in-memory databases. This allows the distributed data objects to be operated in the same way as local variables. The system automatically implements cross-device data synchronization.


### JS Object Storage and Encapsulation Mechanism

- An in-memory database is created for each distributed data object instance and identified by a session ID (**SessionId**). The in-memory databases created for different applications are isolated from each other.

- When a distributed data object is instantiated, all properties of the object are traversed recursively. **Object.defineProperty** is used to define the **set()** and **get()** methods of all properties. The **set()** and **get()** methods correspond to the **put** and **get** operations of a record in the database, respectively. **Key** specifies the property name, and **Value** specifies the property value.

- When a distributed data object is read or written, the **set()** and **get()** methods are automatically called to perform the related operations to the database.

**Table 1** Correspondence between a distributed data object and a distributed database
  
| Distributed Data Object Instance| Object Instance| Property Name| Property Value| 
| -------- | -------- | -------- | -------- |
| Distributed in-memory database| Database identified by **sessionID**| Key of a record in the database| Value of a record in the database| 


### Cross-Device Synchronization and Data Change Notification Mechanism

The distributed data object is used to implement data synchronization between objects. You can create a distributed data object and set **sessionID** for the devices on a trusted network. The distributed data objects with the same **sessionID** on different devices can synchronize data with each other.

As shown in the following figure, distributed data object 1 on device A and device B have the same session ID **session1**. The synchronization relationship of session1 is established between the two objects.

  **Figure 2** Object synchronization relationship 

![distributedObject_sync](figures/distributedObject_sync.jpg)

For each device, only one object can be added to a synchronization relationship. As shown in the preceding figure, distributed data object 2 of device A cannot be added to session 1 because distributed data object 1 of device A has been added to session 1.

After the synchronization relationship is established, each session has a copy of shared object data. The distributed data objects added to the same session support the following operations:

 (1) Reading or modifying the data in the session.

 (2) Listening for data changes made by other devices.

 (3) Listening for status changes, such as the addition and removal of other devices.


### Minimum Unit to Synchronize

Attribute is the minimum unit to synchronize in distributed data objects. For example, object 1 in the following figure has three attributes: name, age, and parents. If one of the attributes is changed, only the changed attribute needs to be synchronized.

**Figure 3** Synchronization of distributed data objects
 

![distributedObject_syncView](figures/distributedObject_syncView.jpg)


### Object Persistence Mechanism

Distributed data objects run in the process space of applications. When the data of a distributed data object is persisted in the distributed database, the data will not be lost after the application exits.

You need to persist distributed data objects in the following scenarios:

- Enable an application to retrieve the exact same data after it is opened again. In this case, you need to persist the distributed data object (for example, object 1). After the application is opened again, create a distributed data object (for example, object 2) and set the session ID of object 1 for object 2. Then, the application can retrieve the data of object 1.

- Enable an application opened on another device to retrieve the exact same data. In this case, you need to persist the distributed data object (for example, object 1) on device A and synchronize the data to device B. Then, create a distributed data object (for example, object 2) and set the session ID of object 1 for object 2. When the application is opened on device B, it can retrieve the same application data used on device A before the application is closed.


## Constraints

- Data synchronization can be implemented across devices only for the applications with the same **bundleName**.

- Data can be synchronized only for the distributed data objects with the same **sessionID** of the same application.

- Each distributed data object occupies 100 KB to 150 KB of memory. Therefore, you are advised not to create too many distributed data objects.

- The maximum size of a distributed data object is 500 KB.

- It takes about 50 ms from the time when 1 KB of data starts to be modified on a device to the time when another device receives a data change notification.

- A maximum of 16 distributed data object instances can be created for an application.

- For optimal performance and user experience, the maximum number of devices for data collaboration is 3.

- For the distributed data object of the complex type, only the root attribute can be modified. The subordinate attributes cannot be modified.

- Only JS APIs are supported.


## Available APIs

The following table lists the APIs for cross-device synchronization of distributed data objects. Most of the interfaces are executed asynchronously, using a callback or promise to return the result. The following table uses the callback-based APIs as an example. For more information about the APIs, see [Distributed Data Object](../reference/apis/js-apis-data-distributedobject.md).

| API| Description| 
| -------- | -------- |
| create(context: Context, source: object): DataObject | Creates a distributed data object instance.| 
| genSessionId(): string | Generates a session ID for distributed data objects.| 
| setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void | Sets a session ID for data synchronization. Automatic synchronization is performed for devices with the same session ID on a trusted network.| 
| setSessionId(callback: AsyncCallback&lt;void&gt;): void | Exits all sessions.| 
| on(type: 'change', callback: Callback&lt;{ sessionId: string, fields: Array&lt;string&gt; }&gt;): void | Subscribes to data changes of this distributed data object.| 
| on(type: 'status', callback: Callback&lt;{ sessionId: string, networkId: string, status: 'online' \| 'offline' }&gt;): void | Subscribes to status changes of this distributed data object.| 
| save(deviceId: string, callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void | Saves a distributed data object.| 
| revokeSave(callback: AsyncCallback&lt;RevokeSaveSuccessResponse&gt;): void | Revokes the save operation of the distributed data object.| 


## How to Develop

The following example demonstrates how to implement a distributed data object synchronization.

1. Import the **@ohos.data.distributedDataObject** module.
     
   ```js
   import distributedDataObject from '@ohos.data.distributedDataObject';
   ```

2. Request permissions.

   1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
   2. Display a dialog box to ask authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Creates a distributed data object instance.

   Stage model:
     
   ```js
   // Import the module.
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage) {
       // Create a distributed data object, which contains attributes of the string, number, boolean, and object types.
       let localObject = distributedDataObject.create(this.context, {
         name: 'jack',
         age: 18,
         isVis: false,
         parent: { mother: 'jack mom', father: 'jack Dad' },
         list: [{ mother: 'jack mom' }, { father: 'jack Dad' }]
       });
     }
   }
   ```

   FA model:

     
   ```js
   // Import the module.
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import featureAbility from '@ohos.ability.featureAbility';
   // Obtain the context.
   let context = featureAbility.getContext();
   // Create a distributed data object, which contains attributes of the string, number, boolean, and object types.
   let localObject = distributedDataObject.create(context, {
     name: 'jack',
     age: 18,
     isVis: false,
     parent: { mother: 'jack mom', father: 'jack Dad' },
     list: [{ mother: 'jack mom' }, { father: 'jack Dad' }]
   });
   ```

4. Set the same session ID for the distributed data objects for data synchronization. The data objects in the synchronization network include the local and remote objects.
     
   ```js
   // Set a session ID, for example, 123456, for device 1.
   let sessionId = '123456';
   
   localObject.setSessionId(sessionId);
   
   // Set the same session ID for device 2.
   
   // Create a distributed data object, which contains attributes of the string, number, boolean, and object types.
   let remoteObject = distributedDataObject.create(this.context, {
     name: undefined,
     age: undefined, // undefined indicates that the data comes from the peer end.
     isVis: true,
     parent: undefined,
     list: undefined
   });
   // After learning that the device goes online, the remote object synchronizes data. That is, name changes to jack and age to 18.
   remoteObject.setSessionId(sessionId);
   ```

5. Observe data changes of a distributed data object. You can subscribe to data changes of the remote object. When the data in the remote object changes, a callback will be invoked to return a data change event.
     
   ```js
   function changeCallback(sessionId, changeData) {
     console.info(`change: ${sessionId}`);
   
     if (changeData !== null && changeData !== undefined) {
       changeData.forEach(element => {
         console.info(`The element ${localObject[element]} changed.`);
       });
     }
   }
   
   // To refresh the page in changeCallback, correctly bind (this) to the changeCallback.
   localObject.on("change", this.changeCallback.bind(this));
   ```

6. Modify attributes of the distributed data object. The object attributes support basic data types (number, Boolean, and string) and complex data types (array and nested basic types).
     
   ```js
   localObject.name = 'jack1';
   localObject.age = 19;
   localObject.isVis = false;
   localObject.parent = { mother: 'jack1 mom', father: 'jack1 Dad' };
   localObject.list = [{ mother: 'jack1 mom' }, { father: 'jack1 Dad' }];
   ```

   > **NOTE**
   >
   > For the distributed data object of the complex type, only the root attribute can be modified. The subordinate attributes cannot be modified.

     
   ```js
   // Supported modification.
   localObject.parent = { mother: 'mom', father: 'dad' };
   // Modification not supported.
   localObject.parent.mother = 'mom';
   ```

7. Access a distributed data object. Obtain the distributed data object attributes, which are the latest data on the network.
     
   ```js
   console.info(`name:${localObject['name']}`); 
   ```

8. Unsubscribe from data changes. You can specify the callback to unregister. If you do not specify the callback, all data change callbacks of the distributed data object will be unregistered.
     
   ```js
   // Unregister this.changeCallback.
   localObject.off('change', this.changeCallback);
   // Unregister all data change callbacks. 
   localObject.off('change'); 
   ```

9. Subscribes to status changes of a distributed data object. A callback will be invoked to report the status change when the target distributed data object goes online or offline.
     
   ```js
   function statusCallback(sessionId, networkId, status) {
     // Service processing.
   }
   
   localObject.on('status', this.statusCallback);
   ```

10. Save a distributed data object and revoke the data saving operation.
     
    ```js
    // Save the data object if the device on the network needs to retrieve the object data after the application exits.
    localObject.save('local').then((result) => {
      console.info(`Succeeded in saving. SessionId:${result.sessionId},version:${result.version},deviceId:${result.deviceId}`);
    }).catch((err) => {
      console.error(`Failed to save. Code:${err.code},message:${err.message}`);
    });
   
    // Revoke the save of a distributed data object.
    localObject.revokeSave().then((result) => {
      console.info(`Succeeded in revokeSaving. Session:${result.sessionId}`);
    }).catch((err) => {
      console.error(`Failed to revokeSave. Code:${err.code},message:${err.message}`);
    });
    ```

11. Unsubscribe from the status changes of a distributed data object. You can specify the callback to unregister. If you do not specify the callback, this API unregisters all status change callbacks of this distributed data object.
     
    ```js
    // Unregister this.statusCallback.
    localObject.off('status', this.statusCallback);
    // Unregister all status change callbacks.
    localObject.off('status');
    ```

12. Remove a distributed data object from the synchronization network. The data of the removed distributed data object will not be synchronized to other devices.
     
    ```js
    localObject.setSessionId(() => {
        console.info('leave all lession.');
    });
    ```

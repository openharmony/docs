# Cross-Device Sync of Distributed Data Objects


## When to Use

The traditional implementation of data sync between devices involves heavy workload. You need to design the message processing logic for setting up a communication link, sending, receiving, and processing messages, and resolving data conflicts, as well as retry mechanism upon errors. In addition, the debugging complexity increases with the number of devices.

The device status, message sending progress, and data transmitted are variables. If these variables support global access, they can be accessed as local variables by difference devices. This simplifies data sync across devices.

The distributed data object (**distributedDataObject**) module implements global access to variables. It provides basic data object management capabilities, including creating, querying, deleting, and modifying in-memory objects and subscribing to data or status changes. It also provides distributed capabilities. OpenHarmony provides easy-to-use JS APIs for distributed application scenarios. With these APIs, you can easily implement data collaboration for an application across devices and listening for status and data changes between devices. The **distributedDataObject** module implements data object collaboration for the same application across multiple devices that form a Super Device. It greatly reduces the development workloads compared with the traditional implementation.


## Basic Concepts

- Distributed in-memory database<br>
  The distributed in-memory database caches data in the memory so that applications can quickly access data without persisting data. If the database is closed, the data is not retained.

- Distributed data object<br>
  A distributed data object is an encapsulation of the JS object type. Each distributed data object instance creates a data table in the in-memory database. The in-memory databases created for different applications are isolated from each other. Reading and writing a distributed data object are mapped to the **get** and **put** operations in the corresponding database, respectively.

  The distributed data object has the following states in its lifecycle:

  - **Uninitialized**: The distributed data object is not instantiated or is destroyed.
  - **Local**: A data table is created, but the data cannot be synced.
  - **Distributed**: A data table is created, and data can be synced (there are at least two online devices with the same session ID). If a device is offline or the session ID is empty, the distributed data object changes to the local state.


## Working Principles

**Figure 1** Working mechanism

![distributedObject](figures/distributedObject.jpg)

The distributed data objects are encapsulated JS objects in distributed in-memory databases, and can be operated in the same way as local variables. The system automatically implements data sync across devices.


### Encapsulation and Storage of JS Objects

- An in-memory database is created for each distributed data object instance and identified by a session ID (**SessionId**). The in-memory databases created for different applications are isolated from each other.

- When a distributed data object is instantiated, all properties of the object are traversed recursively. **Object.defineProperty** is used to define the **set()** and **get()** methods for all properties. The **set()** and **get()** methods correspond to the **put** and **get** operations of a record in the database, respectively. **Key** specifies the property name, and **Value** specifies the property value.

- When a distributed data object is read or written, the **get()** or **set()** method is automatically called to perform the related operation on data in the database.

**Table 1** Correspondence between a distributed data object and a distributed database

| Distributed Data Object Instance| Object Instance| Property Name| Property Value| 
| -------- | -------- | -------- | -------- |
| Distributed in-memory database| Database identified by **sessionID**| Key of a record in the database| Value of a record in the database| 


### Cross-Device Sync and Data Change Notification

One of the most important functions of distributed data objects is to implement data sync between objects. Distributed data objects are created locally for the devices on a trusted network. If the distributed data objects on different devices are set with the same **sessionID**, data can be synced between them.

As shown in the following figure, distributed data object 1 of device A and distributed data object 1 of device B are set with the same session ID **session1**, and sync relationship of session 1 is established between the two objects.

  **Figure 2** Object sync relationship 

![distributedObject_sync](figures/distributedObject_sync.jpg)

For each device, only one distributed data object can be added to a sync relationship. As shown in the preceding figure, distributed data object 2 of device A cannot be added to session 1 because distributed data object 1 of device A has been added to session 1.

After the sync relationship is established, each session has a copy of shared object data. The distributed data objects added to a session support the following operations:

- Reading or modifying the data in the session.

- Listening for data changes made by other devices.

- Listening for status changes, such as the addition and removal of other devices.


### Minimum Sync Unit

Property is the minimum unit to synchronize in distributed data objects. For example, object 1 in the following figure has three properties: name, age, and parents. If one of the properties is changed, only the changed property needs to be synced.

**Figure 3** Sync of distributed data objects


![distributedObject_syncView](figures/distributedObject_syncView.jpg)


### Persistence of Distributed Data Objects

Distributed data objects run in the process space of applications. After the data of a distributed data object is persisted in the distributed database, the data will not be lost after the application exits.

You need to persist distributed data objects in the following scenarios:

- Enable an application to retrieve the exact same data after it starts again. In this case, you need to persist the distributed data object (for example, object 1 with session ID 1). After the application starts again, create a distributed data object (for example, object 2) and set the session ID to 1. Then, the application can retrieve the data of object 1.

- Enable an application started on another device to retrieve the exact same data. In this case, you need to persist the distributed data object (for example, object 1 with session ID 1) on device A and synchronize the data to device B. Then, create a distributed data object (for example, object 2) and set the session ID to 1. When the application is started on device B, it can retrieve the same application data used on device A before the application is closed.

### Asset Sync Mechanism

In a distributed object, [asset](../reference/apis-arkdata/js-apis-data-commonType.md#asset) is used to describe a local entity asset file. When the distributed object is synced across devices, the file is also synced to other devices with it. Currently, only asset is supported. The type [assets](../reference/apis-arkdata/js-apis-data-commonType.md#assets) is not supported. To synchronize multiple assets, use each asset as a root property of the distributed object.

### Resolution of Joint Asset Conflicts 

When an asset in a distributed object and an asset in an RDB store point to the same entity asset file, that is, the URIs of the two assets are the same, a conflict occurs. Such assets are called joint assets. To resolve the conflict of joint assets, bind the asset and the RDB store. The binding is automatically released when the application exits the session.

## Constraints

- Only the data of the same application can be synced across devices, that is, the devices must have the same **bundleName**.

- Data can be synced for the distributed data objects with the same session ID.

- Each distributed data object occupies 100 KB to 150 KB of memory. Therefore, you are advised not to create too many distributed data objects.

- The maximum size of a distributed data object is 500 KB.

- If data of 1 KB data is modified on device A, device B can complete data update within 50 ms after receiving a data change notification.

- A maximum of 16 distributed data object instances can be created for an application.

- For the sake of performance and user experience, the maximum number of devices for data collaboration is 3.

- For the distributed data object of the complex type, only the root property can be modified. The subordinate properties cannot be modified. In [asset sync mechanism](#asset-sync-mechanism), the data of the asset type must support modification of its lower-level properties.

- Currently, only JS APIs are supported.

## Available APIs

Most of the APIs for cross-device sync of distributed data objects are executed asynchronously in callback or promise mode. The following table uses the callback-based APIs as an example. For more information about the APIs, see [Distributed Data Object](../reference/apis-arkdata/js-apis-data-distributedobject.md).



| API| Description|
| -------- | -------- |
| create(context: Context, source: object): DataObject | Creates a distributed data object instance.|
| genSessionId(): string | Generates a session ID for distributed data objects.|
| setSessionId(sessionId: string, callback: AsyncCallback&lt;void&gt;): void | Sets a session ID for data sync. Automatic sync is performed for devices with the same session ID on a trusted network.|
| setSessionId(callback: AsyncCallback&lt;void&gt;): void | Exits all sessions.|
| on(type: 'change', callback: (sessionId: string, fields: Array&lt;string&gt;) => void): void | Subscribes to data changes of the distributed data object.|
| off(type: 'change', callback?: (sessionId: string, fields: Array&lt;string&gt;) => void): void | Unsubscribes from data changes of the distributed data object.|
| on(type: 'status', callback: (sessionId: string, networkId: string, status: 'online' \| 'offline' ) => void): void | Subscribes to status changes of the distributed data object.|
| off(type: 'status', callback?: (sessionId: string, networkId: string, status: 'online' \|'offline' ) => void): void | Unsubscribes from status changes of the distributed data object.|
| save(deviceId: string, callback: AsyncCallback&lt;SaveSuccessResponse&gt;): void | Saves a distributed data object.|
| revokeSave(callback: AsyncCallback&lt;RevokeSaveSuccessResponse&gt;): void | Revokes the saving of the distributed data object.|
| bindAssetStore(assetKey: string, bindInfo: BindInfo, callback: AsyncCallback&lt;void&gt;): void | Binds an asset and its RDB store.|


## How to Develop

### Data Sync Across Devices

The following example demonstrates how to implement sync of distributed data objects.

1. Import the **@ohos.data.distributedDataObject** module.

   ```ts
   import distributedDataObject from '@ohos.data.distributedDataObject';
   ```

2. Apply for permissions.

   1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).
   2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. Create a distributed data object instance.

   Stage model:
   
   ```ts
   // Import the module.
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import { BusinessError } from '@ohos.base';
   import window from '@ohos.window';

   class ParentObject {
     mother: string
     father: string

     constructor(mother: string, father: string) {
       this.mother = mother
       this.father = father
     }
   }
   class SourceObject {
     name: string | undefined
     age: number | undefined
     isVis: boolean | undefined
     parent: Object | undefined

     constructor(name: string | undefined, age: number | undefined, isVis: boolean | undefined, parent: ParentObject | undefined) {
       this.name = name
       this.age = age
       this.isVis = isVis
       this.parent = parent
     }
   }

   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       let parentSource: ParentObject = new ParentObject('jack mom', 'jack Dad');
       let source: SourceObject = new SourceObject("jack", 18, false, parentSource);
       let localObject: distributedDataObject.DataObject = distributedDataObject.create(this.context, source);
     }
   }
   ```

   FA model:

   ```ts
   // Import the module.
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import featureAbility from '@ohos.ability.featureAbility';
   // Obtain the context.
   let context = featureAbility.getContext();
   class ParentObject {
     mother: string
     father: string
     constructor(mother: string, father: string) {
       this.mother = mother
       this.father = father
     }
   }
   class SourceObject {
     name: string | undefined
     age: number | undefined
     isVis: boolean | undefined
     parent: ParentObject | undefined
     constructor(name: string | undefined, age: number | undefined, isVis: boolean | undefined, parent: ParentObject | undefined) {
       this.name = name
       this.age = age
       this.isVis = isVis
       this.parent = parent
     }
   }
   let parentSource: ParentObject = new ParentObject('jack mom', 'jack Dad');
   let source: SourceObject = new SourceObject("jack", 18, false, parentSource);
   // Create a distributed data object, which has properties of the string, number, boolean, and object types.
   let localObject: distributedDataObject.DataObject = distributedDataObject.create(context, source);
   ```

4. Set the same session ID for the distributed data objects for data sync. The data objects in the sync network include the local and remote objects.

   > **NOTE**
   > 
   > If the data of a distributed data object added to the network is different from that in the network, the data of the other distributed data objects will be synced with that of the newly added distributed data object. To enable the newly added distributed data object to sync data with the distributed data object in the network, set its attributes to **undefined**.

   ```ts
   // Set a session ID, for example, 123456, for device 1.
   let sessionId: string = '123456';
   
   localObject.setSessionId(sessionId);
   
   // Set the same session ID for device 2.
   
   // Create a distributed data object, which has properties of the string, number, boolean, and object types.
   let remoteSource: SourceObject = new SourceObject(undefined, undefined, undefined, undefined);
   let remoteObject: distributedDataObject.DataObject = distributedDataObject.create(this.context, remoteSource);
   // After receiving the message indicating the device goes online, the remote object synchronizes data. That is, name is changed to jack and age is changed to 18.
   remoteObject.setSessionId(sessionId);
   ```

5. Observe data changes of a distributed data object. You can subscribe to data changes of the remote object. When the data in the remote object changes, a callback will be invoked to return a data change event.

   ```ts
   localObject.on("change", (sessionId: string, fields: Array<string>) => {
     console.info("change" + sessionId);
     if (fields != null && fields != undefined) {
       for (let index: number = 0; index < fields.length; index++) {
         console.info(`The element ${localObject[fields[index]]} changed.`);
       }
     }
   });
   ```

6. Modify properties of the distributed data object. The object properties support basic data types (number, Boolean, and string) and complex data types (array and nested basic types).

   ```ts
   localObject["name"] = 'jack1';
   localObject["age"] = 19;
   localObject["isVis"] = false;
   let parentSource1: ParentObject = new ParentObject('jack1 mom', 'jack1 Dad');
   localObject["parent"] = parentSource1;
   ```

   > **NOTE**
   >
   > For the distributed data object of the complex type, only the root property can be modified. The subordinate properties cannot be modified.


   ```ts
   // Supported modification.
   let parentSource1: ParentObject = new ParentObject('mom', 'Dad');
   localObject["parent"] = parentSource1;
   // Modification not supported.
   localObject["parent"]["mother"] = 'mom';
   ```

7. Access a distributed data object. Obtain the distributed data object properties, which are the latest data on the network.

   ```ts
   console.info(`name:${localObject['name']}`); 
   ```

8. Unsubscribe from data changes. You can specify the callback to unregister. If you do not specify the callback, this API unregisters all data change callbacks of the distributed data object.

   ```ts
   // Unregister the callback for data changes.
   localObject.off('change', (sessionId: string, fields: Array<string>) => {
     console.info("change" + sessionId);
     if (fields != null && fields != undefined) {
       for (let index: number = 0; index < fields.length; index++) {
         console.info("changed !" + fields[index] + " " + localObject[fields[index]]);
       }
     }
   });
   // Unregister all data change callbacks. 
   localObject.off('change'); 
   ```

9. Subscribe to status changes of a distributed data object. A callback will be invoked to report the status change when the target distributed data object goes online or offline.

   ```ts
   localObject.on('status', (sessionId: string, networkId: string, status: 'online' | 'offline') => {
     console.info("status changed " + sessionId + " " + status + " " +  networkId);
     // Service processing.
   });
   ```

10. Save a distributed data object and revoke the data saved.

    ```ts
    // Save the data object if the device on the network needs to retrieve the object data after the application exits.
    localObject.save("local").then((result: distributedDataObject.SaveSuccessResponse) => {
      console.info(`Succeeded in saving. SessionId:${result.sessionId},version:${result.version},deviceId:${result.deviceId}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to save. Code:${err.code},message:${err.message}`);
    });
   
    // Revoke the data saved.
    localObject.revokeSave().then((result: distributedDataObject.RevokeSaveSuccessResponse) => {
      console.info(`Succeeded in revokeSaving. Session:${result.sessionId}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to revokeSave. Code:${err.code},message:${err.message}`);
    });
    ```

11. Unsubscribe from the status changes of a distributed data object. You can specify the callback to unregister. If you do not specify the callback, this API unregisters all status change callbacks of this distributed data object.

    ```ts
    // Unregister the callback of status changes.
    localObject.off('status', (sessionId: string, networkId: string, status: 'online' | 'offline') => {
      console.info("status changed " + sessionId + " " + status + " " + networkId);
      // Service processing.
    });
    // Unregister all status change callbacks.
    localObject.off('status');
    ```

12. Remove a distributed data object from the sync network. The data of the removed distributed data object will not be synced to other devices.

    ```ts
    localObject.setSessionId(() => {
      console.info('leave all session.');
    });
    ```

### Asset Sync Across Devices

The asset type allows the file described by **asset** to be synced across devices with its distributed data object. The device that holds the asset file is the source device, and the device that obtains the asset file is the destination device.

1. Import the **@ohos.data.distributedDataObject** and **@ohos.data.commonType** modules.

   ```ts
   import distributedDataObject from '@ohos.data.distributedDataObject';
   import commonType from '@ohos.data.commonType';
   ```

2. Apply for permissions.

   1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).
   2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. Create a distributed data object that contains the asset for the source device and add the device to the network.

    ```ts
    import UIAbility from '@ohos.app.ability.UIAbility';
    import type window from '@ohos.window';
    import distributedDataObject from '@ohos.data.distributedDataObject';
    import commonType from '@ohos.data.commonType';
    import type { BusinessError } from '@ohos.base';

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
        // Create a custom note type that contains an image asset.
        let note: Note = new Note('test', "test", attachment);
        let localObject: distributedDataObject.DataObject = distributedDataObject.create(this.context, note);
        localObject.setSessionId('123456');
      }
    }
    ```

4. Create a distributed data object for the destination device and add the device to the network.

    ```ts
    let note: Note = new Note(undefined, undefined, undefined);
    let receiverObject: distributedDataObject.DataObject = distributedDataObject.create(this.context, note);
    receiverObject.on('change', (sessionId: string, fields: Array<string>) => {
      if (fields.includes('attachment')) {
        // When the destination device detects the change in the data of the asset type, the sync of the asset file is complete.
        console.info('attachment synchronization completed');
      }
    });
    receiverObject.setSessionId('123456');
    ```

5. If the asset is a joint asset, bind the asset and its RDB store to resolve the conflict.

    ```ts
    const bindInfo: distributedDataObject.BindInfo = {
      storeName: 'notepad',
      tableName: 'note_t',
      primaryKey: {
        'uuid': '00000000-0000-0000-0000-000000000000'
      },
      field: 'attachment',
      assetName: attachment.name
    }

    localObject.bindAssetStore('attachment', bindInfo, (err: BusinessError) => {
      if (err) {
        console.error('bindAssetStore failed.');
      }
      console.info('bindAssetStore success.');
    });
    ```

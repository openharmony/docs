# Sharing Data via Unified Data Channels


## When to Use

In many-to-many data sharing across applications, a data channel needs to be provided to access data of different applications and share the data with other applications.

The Unified Data Management Framework (UDMF) provides unified data channels and standard data access interfaces for different service scenarios of many-to-many cross-application data sharing.

## Definition and Implementation of Unified Data Channels

The unified data channel provides cross-application data access for various service scenarios. It can temporarily store the unified data objects to be shared by an application, and manage the data modification and deletion permissions and lifecycle of the data according to certain policies.

The unified data channel is implemented by the system ability provided by the UDMF. When an application (data provider) needs to share data, it calls the **insertData()** method provided by the UDMF to write the data to the UDMF data channel, and calls UDMF **updateData()** or **deleteData()** to update or delete the data saved by the application. The target application (data consumer) can access the data by the APIs provided by the UDMF. The UDMF manages the data lifecycle in a unified manner and deletes the data that has been stored for more than one hour every hour.

Avoid using **unifiedDataChannel** APIs in multi-threaded calls.

The unified data object (**UnifiedData**) is uniquely identified by a URI in the UDMF data channel. The URI is in the **udmf://*intention*/*bundleName*/*groupId*** format, where:

+ **udmf**: protocol used to provide the data channel.

+ *intention*: an enum of the data channel types supported by the UDMF.

+ *bundleName*: bundle name of the data source application.

+ *groupId*: group ID used for batch data management.

Currently, the UDMF provides the public data channel for cross-application data sharing.

The public data channel allows all applications to write data into it. When data is written, a unique identifier is generated. Then, the unique identifier can be used to update, delete, query, and retrieve the specified data, and perform a full query. To read all data in the public data channel, set **Intention** to **DATA_HUB**. The public data channel is used only to transmit process data between applications and cannot be used to transmit permission-controlled data, such as files in sandbox directories.

## Available APIs

The following table lists the UDMF APIs. All of them are executed asynchronously in callback or promise mode. In the following table, callback-based APIs are used as an example. For details about more APIs and their usage, see [Unified Data Channel](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md) and [Standard Data Definition and Description](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md).

| API                                                                                   | Description                                         | 
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void | Inserts data to the UDMF public data channel. A unique data identifier is returned.| 
| updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void   | Updates the data in the UDMF public data channel.          | 
| queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void        | Queries data in the UDMF public data channel.              | 
| deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void       | Deletes data from the UDMF public data channel. The deleted data set is returned.|


## How to Develop

The following example walks you through on how to implement many-to-many sharing of PlainText, HTML, and PixelMap data. The data provider calls **insertData()** provided by the UMDF to write data to the public data channel. The return value (unique identifier of the data written) can be used to update or delete the data. The data consumer uses the query() APIs provided by the UDMF to obtain full data of the public data channel.

### Data Provider

1. Import the **unifiedDataChannel**, **uniformTypeDescriptor**, and **uniformDataStruct** modules.

   ```ts
   import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
   ```
2. Create a **UnifiedData** object and insert it into the UDMF public data channel.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { image } from '@kit.ImageKit';
   // Create plaintext data.
   let plainTextObj : uniformDataStruct.PlainText = {
     uniformDataType: 'general.plain-text',
     textContent : 'Hello world',
     abstract : 'This is abstract',
   }
   let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextObj);
   // Create HTML data.
   let htmlObj : uniformDataStruct.HTML = {
     uniformDataType :'general.html',
     htmlContent : '<div><p>Hello world</p></div>',
     plainContent : 'Hello world',
   }
   // Add a new entry to the data record, storing the same data in another format.
   record.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlObj);
   let unifiedData = new unifiedDataChannel.UnifiedData(record);

   // Create pixelMap data.
   let arrayBuffer = new ArrayBuffer(4*3*3);
   let opt : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 3, width: 3 }, alphaType: 3 };
   let pixelMap : uniformDataStruct.PixelMap = {
     uniformDataType : 'openharmony.pixel-map',
     pixelMap : image.createPixelMapSync(arrayBuffer, opt),
   }
   unifiedData.addRecord(new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP, pixelMap));
   // Specify the type of the data channel to which the data is to be inserted.
   let options: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   }
   try {
     unifiedDataChannel.insertData(options, unifiedData, (err, key) => {
       if (err === undefined) {
         console.info(`Succeeded in inserting data. key = ${key}`);
       } else {
         console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
3. Update the **UnifiedData** object inserted.

   ```ts
   let plainTextUpdate : uniformDataStruct.PlainText = {
     uniformDataType: 'general.plain-text',
     textContent : 'How are you',
     abstract : 'This is abstract',
   }
   let recordUpdate = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextUpdate);
   let htmlUpdate : uniformDataStruct.HTML = {
     uniformDataType :'general.html',
     htmlContent : '<div><p>How are you</p></div>',
     plainContent : 'How are you',
   }
   recordUpdate.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlUpdate);
   let unifiedDataUpdate = new unifiedDataChannel.UnifiedData(recordUpdate);
   
   // Specify the URI of the UnifiedData object to update.
   let optionsUpdate: unifiedDataChannel.Options = {
     //The key here is an example and cannot be directly used. Use the value in the callback of insertData().
     key: 'udmf://DataHub/com.ohos.test/0123456789'
   };
   
   try {
     unifiedDataChannel.updateData(optionsUpdate, unifiedDataUpdate, (err) => {
       if (err === undefined) {
         console.info('Succeeded in updating data.');
       } else {
         console.error(`Failed to update data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Update data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
4. Delete the **UnifiedData** object from the UDMF public data channel.

   ```ts
   // Specify the type of the data channel whose data is to be deleted.
   let optionsDelete: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   };

   try {
     unifiedDataChannel.deleteData(optionsDelete, (err, data) => {
       if (err === undefined) {
         console.info(`Succeeded in deleting data. size = ${data.length}`);
         for (let i = 0; i < data.length; i++) {
           let records = data[i].getRecords();
           for (let j = 0; j < records.length; j++) {
             let types = records[j].getTypes();
             // Obtain data of the specified format from the record based on service requirements.
             if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
               let text = records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
               console.info(`${i + 1}.${text.textContent}`);
             }
             if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
               let html = records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
               console.info(`${i + 1}.${html.htmlContent}`);
             }
           }
         }
       } else {
         console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Delete data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
   
### Data Consumer

1. Import the **unifiedDataChannel**, **uniformTypeDescriptor**, and **uniformDataStruct** modules.

   ```ts
   import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
   ```
2. Query the full data in the UDMF public data channel.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   // Specify the type of the data channel whose data is to be queried.
   let options: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   };

   try {
     unifiedDataChannel.queryData(options, (err, data) => {
       if (err === undefined) {
         console.info(`Succeeded in querying data. size = ${data.length}`);
         for (let i = 0; i < data.length; i++) {
           let records = data[i].getRecords();
           for (let j = 0; j < records.length; j++) {
             let types = records[j].getTypes();
             // Obtain data of the specified format from the record based on service requirements.
             if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
               let text = records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
               console.info(`${i + 1}.${text.textContent}`);
             }
             if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
               let html = records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
               console.info(`${i + 1}.${html.htmlContent}`);
             }
           }
         }
       } else {
         console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch(e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```

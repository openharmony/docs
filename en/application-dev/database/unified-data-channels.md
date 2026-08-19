# Sharing Data via Unified Data Channels (ArkTS)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=98721b0592f0d00391dc249e0b65c6685c8906af translatedAt=2026-08-15T01:43:46.234Z pushedAt=2026-08-15T06:27:48.012Z -->

## When to Use

In many-to-many cross-application data sharing, a data channel needs to be provided to write data of different apps and share the data with other apps for querying.

The Unified Data Management Framework (UDMF) provides standardized data channels and standard data write and query interfaces for different service scenarios of many-to-many cross-application data sharing.

## Definition and Implementation of Unified Data Channels

The standardized data channel provides cross-application data write and query channels for various service scenarios. It can temporarily store the unified data objects that conform to the standardized data definition and are to be shared by an app, provide them to other apps for access, and manage the modification and deletion permissions and lifecycle of the temporarily stored data according to certain policies.

The standardized data channel is implemented by the system service provided by UDMF. When an app (data provider) needs to share public data, it can call the **insertData()** API provided by UDMF to write the data to the UDMF data channel, and call the **updateData()** or **deleteData()** API provided by UDMF to update or delete the data already stored by the app. The target app (data accessor) can access the data through the **queryData()** API provided by UDMF.

Avoid using **unifiedDataChannel** APIs in multi-threaded calls.

The unified data object (**UnifiedData**) is uniquely identified by a URI in the UDMF data channel. The URI is in the **udmf://*intention*/*bundleName*/*groupId*** format, where:

+ **udmf**: protocol used to provide the data channel.

+ ***intention***: an enum of the data channel types supported by UDMF.

+ ***bundleName***: bundle name of the data source application.

+ ***groupId***: group ID used for batch data management.

Currently, UDMF provides the public data channel for cross-application data sharing.

**Public data channel**: a public data sharing channel for apps. All apps can write data to the channel. The writer can use the unique data identifier generated when writing data to update, delete, query by the specified data identifier, and perform a full query. The data accessor can query the specified data by the unique identifier, or set the Intention enumeration to DATA_HUB to query all data in the current data channel. The public data channel is usually used only to transmit process data between apps, and cannot be used to transmit permission-controlled data such as files in sandbox directories. UDMF manages the data lifecycle in a unified manner and periodically cleans up data that has been stored for more than one hour every hour.

## Available APIs

The following are APIs related to UDMF unified data channels. For more APIs and their usage, see [@ohos.data.unifiedDataChannel (Unified Data Channel)](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md) and [@ohos.data.uniformTypeDescriptor (Uniform Data Definition and Description)](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md).

| API                                                                                   | Description                                         | 
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void | Inserts data to the UDMF public data channel. This API uses an asynchronous callback to return a unique data identifier.| 
| updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void   | Updates the data in the UDMF public data channel. This API uses an asynchronous callback to return the result.          | 
| queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void        | Queries data in the UDMF public data channel. This API uses an asynchronous callback to return the result.              | 
| deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void       | Deletes data from the UDMF public data channel. This API uses an asynchronous callback to return the deleted data set.|

## How to Develop

The following example walks you through on how to implement many-to-many sharing of [PlainText](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#plaintext), [HTML](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#html), and [PixelMap](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#pixelmap15) data. The data provider calls **insertData()** provided by UDMF to write data to the public data channel. The return value (unique identifier of the data written) can be used to update or delete the data. The data consumer uses the query() APIs provided by UDMF to obtain full data of the public data channel.

### Data Provider

1. Import the **unifiedDataChannel**, **uniformTypeDescriptor**, and **uniformDataStruct** modules.

    <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

    ``` TypeScript
    import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. Create a **UnifiedData** object and insert it to the UDMF public data channel.

   1. Import the corresponding data object modules.

      <!-- @[import_unifiedData_object_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

      ``` TypeScript
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';
      ```

   2. Create and insert data.

      <!-- @[unified_data_channels_insert_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

      ``` TypeScript
      // Create plaintext data.
      let plainTextObj: uniformDataStruct.PlainText = {
        uniformDataType: 'general.plain-text',
        textContent: 'Hello world',
        abstract: 'This is abstract'
      }
      let record =
        new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextObj);
      // Create HTML data.
      let htmlObj: uniformDataStruct.HTML = {
        uniformDataType: 'general.html',
        htmlContent: '<div><p>Hello world</p></div>',
        plainContent: 'Hello world'
      }
      // Add a new entry to the data record, storing the same data in another format.
      record.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlObj);
      let unifiedData = new unifiedDataChannel.UnifiedData(record);

      // Create pixelMap data.
      let arrayBuffer = new ArrayBuffer(4 * 3 * 3);
      let opt: image.InitializationOptions = {
        editable: true,
        pixelFormat: 3,
        size: { height: 3, width: 3 },
        alphaType: 3
      };
      let pixelMap: uniformDataStruct.PixelMap = {
        uniformDataType: 'openharmony.pixel-map',
        pixelMap: image.createPixelMapSync(arrayBuffer, opt)
      }
      unifiedData.addRecord(new unifiedDataChannel.UnifiedRecord(
        uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP, pixelMap));
      // Specify the type of the data channel to which the data is to be inserted.
      let options: unifiedDataChannel.Options = {
        intention: unifiedDataChannel.Intention.DATA_HUB
      }
      try {
        unifiedDataChannel.insertData(options, unifiedData, (err, key) => {
          if (err === undefined) {
            hilog.info(0xFF00, '[Sample_Udmf]', `Succeeded in inserting data. key = ${key}`);
          } else {
            hilog.error(0xFF00, '[Sample_Udmf]', `Failed to insert data. code is ${err.code}, message is ${err.message}`);
          }
        });
      } catch (e) {
        let error: BusinessError = e as BusinessError;
        hilog.error(0xFF00, '[Sample_Udmf]',
          `Insert data throws an exception. code is ${error.code}, message is ${error.message}`);
      }
      ```

3. Update the **UnifiedData** object inserted.

    <!-- @[unified_data_channels_update_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

    ``` TypeScript
    let plainTextUpdate: uniformDataStruct.PlainText = {
      uniformDataType: 'general.plain-text',
      textContent: 'How are you',
      abstract: 'This is abstract'
    }
    let recordUpdate =
      new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextUpdate);
    let htmlUpdate: uniformDataStruct.HTML = {
      uniformDataType: 'general.html',
      htmlContent: '<div><p>How are you</p></div>',
      plainContent: 'How are you'
    }
    recordUpdate.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlUpdate);
    let unifiedDataUpdate = new unifiedDataChannel.UnifiedData(recordUpdate);

    // Specify the URI of the UnifiedData object to update.
    let optionsUpdate: unifiedDataChannel.Options = {
      // The key here is an example and cannot be directly used. Use the value in the callback of insertData().
      key: 'udmf://DataHub/com.ohos.test/0123456789'
    };

    try {
      unifiedDataChannel.updateData(optionsUpdate, unifiedDataUpdate, (err) => {
        if (err === undefined) {
          hilog.info(0xFF00, '[Sample_Udmf]', `Succeeded in updating data.`);
        } else {
          hilog.error(0xFF00, '[Sample_Udmf]', `Failed to update data. code is ${err.code}, message is ${err.message}`);
        }
      });
    } catch (e) {
      let error: BusinessError = e as BusinessError;
      hilog.error(0xFF00, '[Sample_Udmf]',
        `Update data throws an exception. code is ${error.code}, message is ${error.message}`);
    }
    ```

4. Delete the **UnifiedData** object from the UDMF public data channel.

    <!-- @[unified_data_channels_delete_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

    ``` TypeScript
    // Specify the type of the data channel whose data is to be deleted.
    let optionsDelete: unifiedDataChannel.Options = {
      intention: unifiedDataChannel.Intention.DATA_HUB
    };

    try {
      unifiedDataChannel.deleteData(optionsDelete, (err, data) => {
        if (err === undefined) {
          hilog.info(0xFF00, '[Sample_Udmf]', `Succeeded in deleting data. size = ${data.length}`);
          for (let i = 0; i < data.length; i++) {
            let records = data[i].getRecords();
            for (let j = 0; j < records.length; j++) {
              let types = records[j].getTypes();
              // Obtain data of the specified format from the record based on service requirements.
              if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
                let text =
                  records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
                hilog.info(0xFF00, '[Sample_Udmf]', `${i + 1}.${text.textContent}`);
              }
              if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
                let html =
                  records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
                hilog.info(0xFF00, '[Sample_Udmf]', `${i + 1}.${html.htmlContent}`);
              }
            }
          }
        } else {
          hilog.error(0xFF00, '[Sample_Udmf]', `Failed to delete data. code is ${err.code}, message is ${err.message}`);
        }
      });
    } catch (e) {
      let error: BusinessError = e as BusinessError;
      hilog.error(0xFF00, '[Sample_Udmf]',
        `Delete data throws an exception. code is ${error.code}, message is ${error.message}`);
    }
    ```

### Data Consumer

1. Import the **unifiedDataChannel**, **uniformTypeDescriptor**, and **uniformDataStruct** modules.

    <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

    ``` TypeScript
    import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. Query the full data in the UDMF public data channel.

    <!-- @[unified_data_channels_query_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UnifiedDataChannels/entry/src/main/ets/pages/UdmfInterface.ets) -->

    ``` TypeScript
    // Specify the type of the data channel whose data is to be queried.
    let options: unifiedDataChannel.Options = {
      intention: unifiedDataChannel.Intention.DATA_HUB
    };

    try {
      unifiedDataChannel.queryData(options, (err, data) => {
        if (err === undefined) {
          hilog.info(0xFF00, '[Sample_Udmf]', `Succeeded in querying data. size = ${data.length}`);
          for (let i = 0; i < data.length; i++) {
            let records = data[i].getRecords();
            for (let j = 0; j < records.length; j++) {
              let types = records[j].getTypes();
              // Obtain data of the specified format from the record based on service requirements.
              if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
                let text =
                  records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
                hilog.info(0xFF00, '[Sample_Udmf]', `${i + 1}.${text.textContent}`);
              }
              if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
                let html =
                  records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
                hilog.info(0xFF00, '[Sample_Udmf]', `${i + 1}.${html.htmlContent}`);
              }
            }
          }
        } else {
          hilog.error(0xFF00, '[Sample_Udmf]', `Failed to query data. code is ${err.code}, message is ${err.message}`);
        }
      });
    } catch (e) {
      let error: BusinessError = e as BusinessError;
      hilog.error(0xFF00, '[Sample_Udmf]',
        `Query data throws an exception. code is ${error.code}, message is ${error.message}`);
    }
    ```
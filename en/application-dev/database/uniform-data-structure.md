# Uniform Data Structs


## When to Use

Uniform data structs are provided to define data of common [uniform data types](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md#uniformdatatype). For example, the data struct for the system-defined home screen icon (the uniform data type is **openharmony.app-item**) is provided to help you easily define the data.

Applications can directly use the uniform data structs in certain scenarios. For example, in the drag-and-drop operation across applications, you can write the data (encapsulated in a uniform struct) to be dragged to [DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent). The target application (application requesting the data) reads the data from **DragEvent** and parses the data in the uniform data struct. Using uniform data structs for data interaction between applications effectively reduces the development workload in your app experience.

## Uniform Data Structs

The following table lists the uniform data structs provided by the UDMF.

| Data Struct                                                                                               |       Data Type       | Description  |
|-----------------------------------------------------------------------------------------------------| :-------------------: |------|
| [PlainText](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#plaintext)                  |      'general.plain-text'        | Plain text |
| [Hyperlink](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#hyperlink)                  |       'general.hyperlink'       | Hyperlink |
| [HTML](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#html)                            |         'general.html'          | HyperText Markup Language (HTML) |
| [OpenHarmonyAppItem](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#openharmonyappitem) | 'openharmony.app-item'    | Icon  |
| [ContentForm](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#contentform14)            | 'general.content-form'    | Content widget|

## How to Develop

The following describes how to use the uniform data structs to define a hyperlink and a plaint text.

  ```ts
  // 1. Import the unifiedDataChannel and uniformTypeDescriptor modules.
  import { uniformDataStruct, uniformTypeDescriptor, unifiedDataChannel } from '@kit.ArkData';
  
  // 2. Create a data record for a hyperlink.
  let hyperlinkDetails : Record<string, string> = {
    'attr1': 'value1',
    'attr2': 'value2',
  }
  let hyperlink : uniformDataStruct.Hyperlink = {
    uniformDataType:'general.hyperlink',
    url : 'www.XXX.com',
    description : 'This is the description of this hyperlink',
    details : hyperlinkDetails,
  }
  
  hyperlink.description = '...'; // Set description of the hyperlink.
  
  console.info(`hyperlink url = ${hyperlink.url}`); // Access object attributes.
  
  // 3. Create a data record for a plain text and add it to the UnifiedData instance created.
  let plainTextDetails : Record<string, string> = {
    'attr1': 'value1',
    'attr2': 'value2',
  }
  let plainText : uniformDataStruct.PlainText = {
    uniformDataType: 'general.plain-text',
    textContent : 'This is plainText textContent example',
    abstract : 'this is abstract',
    details : plainTextDetails,
  }
  // 4. Create a UnifiedData instance.
  let unifiedData = new unifiedDataChannel.UnifiedData();
  let hyperlinkRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, hyperlink);
  let plainTextRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
  
  // 5. Add a plainText data record.
  unifiedData.addRecord(hyperlinkRecord);
  unifiedData.addRecord(plainTextRecord);
  
  // 6. Obtain all data records in this UnifiedData instance.
  let records = unifiedData.getRecords();
  
  // 7. Traverse all records, determine the data type of the record, and convert the record into a child class object to obtain the original data record.
  for (let i = 0; i < records.length; i ++) {
    let unifiedDataRecord = records[i] as unifiedDataChannel.UnifiedRecord;
    let record = unifiedDataRecord.getValue() as object;
    if (record != undefined) {
      // Obtain the type of each data record.
      let type : string = record["uniformDataType"];
      switch (type) {
        case uniformTypeDescriptor.UniformDataType.HYPERLINK:
          Object.keys(record).forEach(key => {
            console.info('show records: ' + key + ', value:' + record[key]);
          });
          break;
        case uniformTypeDescriptor.UniformDataType.PLAIN_TEXT:
          Object.keys(record).forEach(key => {
            console.info('show records: ' + key + ', value:' + record[key]);
          });
          break;
        default:
          break;
      }
    }
  }
  ```

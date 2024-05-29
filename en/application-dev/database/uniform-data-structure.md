# Uniform Data Structs


## When to Use

The Unified Data Management Framework (UDMF) provides uniform data structs for some uniform data types, for example the widget type (**openharmony.form**) used on the home screen.

Applications can directly use the uniform data structs in certain scenarios. For example, in the drag-and-drop operation across applications, you can write the data (encapsulated in a uniform struct) to be dragged to [DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent). The target application (application requesting the data) reads the data from **DragEvent** and parses the data in the uniform data struct. Using uniform data structs for data interaction between applications effectively reduces the development workload in your app experience.

## Uniform Data Structs

The following table lists the uniform data structs provided by the UDMF.

| Data Type               |       Data Struct       | Description      |
| ----------------------- | :-------------------: | ---------- |
| 'general.text'          |         Text          | Text      |
| 'general.plain-text'    |       PlainText       | Plain text    |
| 'general.hyperlink'     |       Hyperlink       | Hyperlink    |
| 'general.html'          |         HTML          | HyperText Markup Language (HTML)    |
| 'general.file'          |         File          | File      |
| 'general.image'         |         Image         | Image      |
| 'general.video'         |         Video         | Video      |
| 'general.audio'         |         Audio         | Audio      |
| 'general.folder'        |        Folder         | Folder    |
| 'openharmony.form'      |   SystemDefinedForm   | Widget      |
| 'openharmony.app-item'  | SystemDefinedAppItem  | Icon      |
| 'openharmony.pixel-map' | SystemDefinedPixelMap | Pixel map|

## Constraints

The UDMF supports management of batch data records. Each data set cannot exceed 200 MB. The maximum size of a single attribute in **PlainText**, **Hyperlink**, or **HTML** is 20 MB.

## Available APIs

The UDMF provides a **UnifiedData** object to encapsulate multiple **UnifiedRecord**s. **UnifiedRecord** is an abstract definition of data supported by the UDMF, for example, a text or an image. The data records in a **UnifiedRecord** object are of the **UniformDataType** type.

The following table lists the commonly used APIs for managing uniform data structs. For more information, see [Unified Data Channel](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md) and [Uniform Type Descriptor](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md).

| Class       | API                              | Description                                                        |
| ------------- | -------------------------------------- | ------------------------------------------------------------ |
| UnifiedRecord | getType(): string                      | Obtains the type of this data record.                        |
| UnifiedData   | constructor(record: UnifiedRecord)     | A constructor used to create a **UnifiedData** object with a data record.                    |
| UnifiedData   | addRecord(record: UnifiedRecord): void | Adds a data record to this **UnifiedRecord** object.                      |
| UnifiedData   | getRecords(): Array\<UnifiedRecord>    | Obtains all data records from this **UnifiedData** object. The data obtained is of the **UnifiedRecord** type. Before using the data, you need to obtain the data type by using **getType** and convert the data type to a child class.|


## How to Develop

The following describes how to encapsulate an image and a plaint text into an object in a uniform data struct and manage the data.

1. Import the **@ohos.data.unifiedDataChannel** and **@ohos.data.uniformTypeDescriptor** modules.

   ```ts
   import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
   import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
   ```
2. Create an image object and create a **UnifiedData** instance with the image object.

   - Create an image object.

      ```ts
      let image = new unifiedDataChannel.Image();
      ```

   - Modify the image object attributes.

      ```ts
      // The image object has the imageUri attribute.
      image.imageUri = '...';
      ```

   - Access the image object attribute.

      ```ts
      console.info(`imageUri = ${image.imageUri}`);
      ```

   - Create a **UnifiedData** instance with the image object.

      ```ts
      let unifiedData = new unifiedDataChannel.UnifiedData(image);
      ```
3. Create a plain text data record and add it to the **UnifiedData** instance created.

   ```ts
   let plainText = new unifiedDataChannel.PlainText();
   plainText.textContent = 'this is textContent of plainText';
   plainText.abstract = 'abstract of plainText';
   plainText.details = {
     plainKey1: 'plainValue1',
     plainKey2: 'plainValue2',
   };
   unifiedData.addRecord(plainText);
   ```
4. Obtain all data records in this **UnifiedData** instance.

   ```ts
   let records = unifiedData.getRecords();
   ```
5. Traverse each record, determine the data type, and convert the data type into a child class object to obtain the original data.

   ```ts
   for (let i = 0; i < records.length; i ++) {
     // Obtain the type of each data record.
     let type = records[i].getType();
     switch (type) {
       case uniformTypeDescriptor.UniformDataType.IMAGE:
         // Convert the data type to obtain the image.
         let image = records[i] as unifiedDataChannel.Image;
         break;
       case uniformTypeDescriptor.UniformDataType.PLAIN_TEXT:
         // Convert the data to obtain the plain text.
         let plainText = records[i] as unifiedDataChannel.PlainText;
         break;
       default:
         break;
     }
   }
   ```


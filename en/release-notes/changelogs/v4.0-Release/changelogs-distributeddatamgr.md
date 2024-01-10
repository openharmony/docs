
# Distributed Data Management Changelog

## cl.distributeddatamgr.1 Split of @ohos.data.UDMF.d.ts into @ohos.data.unifiedDataChannel.d.ts and @ohos.data.uniformTypeDescriptor.d.ts

**Change Impact**

The @ohos.data.UDMF.d.ts is divided into @ohos.data.unifiedDataChannel.d.ts and @ohos.data.uniformTypeDescriptor.d.ts.
The **UnifiedDataType** defined in @ohos.data.UDMF.d.ts is moved to @ohos.data.uniformTypeDescriptor.d.ts and renamed **UniformDataType**.
Other interface definitions are moved to @ohos.data.unifiedDataChannel.d.ts.

**Key API/Component Changes**

**UnifiedDataType** before the change:

| Name                        | Value                           | Description       |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'Text'                       | Text.    |
| PLAIN_TEXT                 | 'Text.PlainText'             | Plaintext.   |
| HYPERLINK                  | 'Text.Hyperlink'             | Hyperlink.   |
| HTML                       | 'Text.HTML'                  | HyperText Markup Language (HTML).   |
| FILE                       | 'File'                       | File.    |
| IMAGE                      | 'File.Media.Image'           | Image.    |
| VIDEO                      | 'File.Media.Video'           | Video.    |
| AUDIO                      | 'File.Media.Audio'           | Audio.    |
| FOLDER                     | 'File.Folder'                | Folder.   |
| SYSTEM_DEFINED_RECORD      | 'SystemDefinedType'          | System service data.|
| SYSTEM_DEFINED_FORM        | 'SystemDefinedType.Form'     | Widget.    |
| SYSTEM_DEFINED_APP_ITEM    | 'SystemDefinedType.AppItem'  | Icon.    |
| SYSTEM_DEFINED_PIXEL_MAP   | 'SystemDefinedType.PixelMap' | Pixel map. |
| APPLICATION_DEFINED_RECORD | 'ApplicationDefinedType'     | Application-defined type. |

From this version, **UnifiedDataType** is renamed **UniformDataType** with the following changes: 
- Deleted the enum values **SYSTEM_DEFINED_RECORD** and **APPLICATION_DEFINED_RECORD**. 
- Changed the enum value **SYSTEM_DEFINED_FORM** to **OPENHARMONY_FORM**, **SYSTEM_DEFINED_APP_ITEM** to **OPENHARMONY_APP_ITEM**, and **SYSTEM_DEFINED_PIXEL_MAP** to **OPENHARMONY_PIXEL_MAP**. 
- Changed the string definitions of the enum values.

| Name                        | Value                           | Description       |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'general.text'                   | Text.    |
| PLAIN_TEXT                 | 'general.plain-text'             | Plaintext.   |
| HYPERLINK                  | 'general.hyperlink'              | Hyperlink.   |
| HTML                       | 'general.html'                   | HTML.   |
| FILE                       | 'general.file'                   | File.    |
| IMAGE                      | 'general.image'                  | Image.    |
| VIDEO                      | 'general.video'                  | Video.    |
| AUDIO                      | 'general.audio'                  | Audio.    |
| FOLDER                     | 'general.folder'                 | Folder.   |
| OPENHARMONY_FORM           | 'openharmony.form'               | Widget.    |
| OPENHARMONY_APP_ITEM       | 'openharmony.app-item'           | Icon.    |
| OPENHARMONY_PIXEL_MAP      | 'openharmony.pixel-map'          | Pixel map. |

**Adaptation Guide**

Perform the following operations: 
1. Change the enum values. 
2. Import @ohos.data.unifiedDataChannel and @ohos.data.uniformTypeDescriptor modules. 
3. Replace the namespace **UDMF** with the module name imported and replace **UnifiedDataType** with **UniformDataType**.

Code before change:

```
// Import the **@ohos.data.UDMF** module.
import UDMF from '@ohos.data.UDMF';

// Create a UnifiedData instance.
let unifiedData = new UDMF.UnifiedData(image);

// Create a plain text data record and add it to the UnifiedData instance created.
let plainText = new UDMF.PlainText();
plainText.textContent = 'this is textContent of plainText';
unifiedData.addRecord(plainText);

// Traverse all records, determine the data type of the record, and convert the record into a child class object to obtain the original data record.
let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i ++) {
  // Read the type of the data record.
  let type = records[i].getType();
  switch (type) {
    case UDMF.UnifiedDataType.IMAGE:
      // Convert the data to obtain the original image data record.
      let image = <UDMF.Image>(records[i]);
      break;
    case UDMF.UnifiedDataType.PLAIN_TEXT:
      // Convert the data to obtain the original text record.
      let plainText = <UDMF.PlainText>(records[i]);
      break;
    default:
      break;
  }
}
```

Code after change:

```
// Import the @ohos.data.unifiedDataChannel and @ohos.data.uniformTypeDescriptor modules.
import UDC from '@ohos.data.unifiedDataChannel';
import UTD from '@ohos.data.uniformTypeDescriptor';

// Create a UnifiedData instance.
let unifiedData = new UDC.UnifiedData(image);

// Create a plain text data record and add it to the UnifiedData instance created.
let plainText = new UDC.PlainText();
plainText.textContent = 'this is textContent of plainText';
unifiedData.addRecord(plainText);

// Traverse all records, determine the data type of the record, and convert the record into a child class object to obtain the original data record.
let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i ++) {
  // Read the type of the data record.
  let type = records[i].getType();
  switch (type) {
    case UTD.UniformDataType.IMAGE:
      // Convert the data to obtain the original image data record.
      let image = <UDC.Image>(records[i]);
      break;
    case UTD.UniformDataType.PLAIN_TEXT:
      // Convert the data to obtain the original text record.
      let plainText = <UDC.PlainText>(records[i]);
      break;
    default:
      break;
  }
}
```

## cl.distributeddatamgr.2 Change of data.DistributedObject.on Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Changed the parameters of two **on()** methods.

Before change:

 ```ts
 on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
 on(
   type: 'status',
   callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
 ): void;
 
 ```

After change:

 ```ts
 on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
 on(
    type: 'status',
    callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
 ): void;
 ```

**Adaptation Guide**

The application does not need to adapt to the change.



## cl.distributeddatamgr.3 Change of data.DistributedObject.off Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Changed the parameters of two **off()** methods.

Before change:

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

The application does not need to adapt to the change.



## cl.distributeddatamgr.4 Change of data.DataObject.on Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Changed the parameters of two **on()** methods.

Before change:

 ```ts
on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
on(
  type: 'status',
  callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
on(
   type: 'status',
   callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

The application does not need to adapt to the change.



## cl.distributeddatamgr.5 Change of data.DataObject.off Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Changed the parameters of two **off()** methods.

Before change:

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

The application does not need to adapt to the change.



## cl.distributeddatamgr.6 Change of data.preferences.on Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Before change:

 ```ts
on(type: 'multiProcessChange', callback: Callback<{ key : string }>): void
on(type: 'change', callback: Callback<{ key : string }>): void
 ```

After change:

 ```ts
on(type: 'multiProcessChange', callback: ( key : string ) => void): void
on(type: 'change', callback: ( key : string ) => void): void
 ```

**Adaptation Guide**

The application does not need to adapt to the change.



## cl.distributeddatamgr.7 Change of data.preferences.off Parameters

**Change Impact**

The application does not need to adapt to the change.

**Key API/Component Changes**

Before change:

 ```ts
off(type: 'multiProcessChange', callback?: Callback<{ key : string }>): void
off(type: 'change', callback?: Callback<{ key : string }>): void
 ```

After change:

 ```ts
off(type: 'multiProcessChange', callback?: ( key : string ) => void): void
off(type: 'change', callback?: ( key : string ) => void): void
 ```

**Adaptation Guide**

The application does not need to adapt to the change.

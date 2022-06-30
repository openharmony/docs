# Resource Management

The resource management module provides APIs to obtain information about the current device configuration (including the language, region, screen direction, and MCC/MNC) and device capability (including the device type and resolution).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import resourceManager from '@ohos.resourceManager';
```

## Usage

Since API version 9, the stage model allows an application to obtain a **ResourceManager** object based on **context** and call its APIs without first importing the required bundle. This method, however, is not applicable to the FA model.

```
this.context.resourceManager;
```

## resourceManager.getResourceManager

getResourceManager(callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of this application. This API uses an asynchronous callback to return the result.

This API is used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description                           |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      if (error != null) {
          console.log("error is " + error);
          return; 
      }
      mgr.getString(0x1000000, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let str = value;
          }
      });
  });
  ```


## resourceManager.getResourceManager

getResourceManager(bundleName: string, callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of an application based on the specified bundle name. This API uses an asynchronous callback to return the result.

This API is used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name       | Type                                      | Mandatory  | Description                           |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | Yes   | Bundle name of the target application.                |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```


## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of this application. This API uses a promise to return the result.

This API is used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                      | Description               |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager().then(mgr => {
      mgr.getString(0x1000000, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let str = value;
          }
      });
  }).catch(error => {
      console.log("error is " + error);
  });
  ```


## resourceManager.getResourceManager

getResourceManager(bundleName: string): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of an application based on the specified bundle name. This API uses a promise to return the result.

This API is used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | Yes   | Bundle name of the target application.|

**Return value**
| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager("com.example.myapplication").then(mgr => {

  }).catch(error => {

  });
  ```


## Direction

Enumerates the screen directions.

**System capability**: SystemCapability.Global.ResourceManager

| Name                  | Default Value | Description  |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | Portrait.  |
| DIRECTION_HORIZONTAL | 1    | Landscape.  |


## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.Global.ResourceManager

| Name                  | Default Value | Description  |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_PHONE    | 0x00 | Phone.  |
| DEVICE_TYPE_TABLET   | 0x01 | Tablet.  |
| DEVICE_TYPE_CAR      | 0x02 | Head unit.  |
| DEVICE_TYPE_PC       | 0x03 | PC.  |
| DEVICE_TYPE_TV       | 0x04 | TV.  |
| DEVICE_TYPE_WEARABLE | 0x06 | Wearable.  |


## ScreenDensity

Enumerates the screen density types.

**System capability**: SystemCapability.Global.ResourceManager

| Name            | Default Value | Description        |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | Screen density with small-scale dots per inch (SDPI).  |
| SCREEN_MDPI    | 160  | Screen density with medium-scale dots per inch (MDPI).  |
| SCREEN_LDPI    | 240  | Screen density with large-scale dots per inch (LDPI).  |
| SCREEN_XLDPI   | 320  | Screen density with extra-large-scale dots per inch (XLDPI). |
| SCREEN_XXLDPI  | 480  | Screen density with extra-extra-large-scale dots per inch (XXLDPI). |
| SCREEN_XXXLDPI | 640  | Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI).|


## Configuration

Defines the device configuration.

**System capability**: SystemCapability.Global.ResourceManager


| Name       | Type                   | Readable  | Writable  | Description      |
| --------- | ----------------------- | ---- | ---- | -------- |
| direction | [Direction](#direction) | Yes   | No   | Screen direction of the device.|
| locale    | string                  | Yes   | No   | Current system language.  |

**Example**

  ```
resourceManager.getResourceManager((error, mgr) => {
      mgr.getConfiguration((error, value) => {
          let direction = value.direction;
          let locale = value.locale;
      });
  });
  ```

## DeviceCapability

Defines the device capability.

**System capability**: SystemCapability.Global.ResourceManager


| Name           | Type                           | Readable  | Writable  | Description      |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | Yes   | No   | Screen density of the device.|
| deviceType    | [DeviceType](#devicetype)       | Yes   | No   | Type of the device.  |

**Example**

  ```
resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability((error, value) => {
          let screenDensity = value.screenDensity;
          let deviceType = value.deviceType;
      });
  });
  ```

## RawFileDescriptor<sup>8+</sup>

Defines the descriptor information of the raw file.<br>
**System capability**: SystemCapability.Global.ResourceManager

| Name    | Type    | Description                |
| ------ | ------ | ------------------ |
| fd     | number | Descriptor of a raw file.|
| offset | number | Offset to the start position of the raw file.     |
| length | number | Length of the raw file.      |


## ResourceManager

Defines the capability of accessing application resources.

> **NOTE**<br>
> - The methods involved in **ResourceManager** are applicable only to the TypeScript-based declarative development paradigm.
>
> - Resource files are defined in the **resources** directory of the project. You can obtain the resource ID using **$r(resource address).id**, for example, **$r('app.string.test').id**.


### getString

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let str = value;
          }
      });
  });
  ```


### getString

getString(resId: number): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id).then(value => {
          let str = value;
      }).catch(error => {
          console.log("getstring promise error is " + error);
      });
  });
  ```


### getStringArray

getStringArray(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getStringArray($r('app.strarray.test').id, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let strArray = value;
          }
      });
  });
  ```


### getStringArray

getStringArray(resId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the string array corresponding to the specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                                | Description           |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
       mgr.getStringArray($r('app.strarray.test').id).then(value => {
          let strArray = value;
      }).catch(error => {
          console.log("getStringArray promise error is " + error);
      });
  });
  ```


### getMedia

getMedia(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let media = value;
          }
      });
  });
  ```


### getMedia

getMedia(resId: number): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id).then(value => {
          let media = value;
      }).catch(error => {
          console.log("getMedia promise error is " + error);
      });
  });
  ```


### getMediaBase64

getMediaBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let media = value;
          }
      });
  });
  ```


### getMediaBase64

getMediaBase64(resId: number): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id).then(value => {
          let media = value;
      }).catch(error => {
          console.log("getMediaBase64 promise error is " + error);
      });
  });
  ```


### getConfiguration

getConfiguration(callback: AsyncCallback&lt;Configuration&gt;): void

Obtains the device configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description                       |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getConfiguration((error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let direction = value.direction;
              let locale = value.locale;
          }
      });
  });
  ```


### getConfiguration

getConfiguration(): Promise&lt;Configuration&gt;

Obtains the device configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                      | Description              |
| ---------------------------------------- | ---------------- |
| Promise&lt;[Configuration](#configuration)&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getConfiguration().then(value => {
          let direction = value.direction;
          let locale = value.locale;
      }).catch(error => {
          console.log("getConfiguration promise error is " + error);
      });
  });
  ```


### getDeviceCapability

getDeviceCapability(callback: AsyncCallback&lt;DeviceCapability&gt;): void

Obtains the device capability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description                          |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability((error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let screenDensity = value.screenDensity;
              let deviceType = value.deviceType;
          }
      });
  });
  ```


### getDeviceCapability

getDeviceCapability(): Promise&lt;DeviceCapability&gt;

Obtains the device capability. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability().then(value => {
          let screenDensity = value.screenDensity;
          let deviceType = value.deviceType;
      }).catch(error => {
          console.log("getDeviceCapability promise error is " + error);
      });
  });
  ```


### getPluralString

getPluralString(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Number that determines the plural or singular form.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let str = value;
          }
      });
  });
  ```


### getPluralString

getPluralString(resId: number, num: number): Promise&lt;string&gt;

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number that determines the plural or singular form.  |

**Return value**
| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1).then(value => {
          let str = value;
      }).catch(error => {
          console.log("getPluralString promise error is " + error);
      });
  });
  ```

### getRawFile<sup>8+</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.xml", (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let rawFile = value;
          }
      });
  });
  ```

### getRawFile<sup>8+</sup>

getRawFile(path: string): Promise&lt;Uint8Array&gt;

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**
| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.xml").then(value => {
          let rawFile = value;
      }).catch(error => {
          console.log("getRawFile promise error is " + error);
      });
  });
  ```

### getRawFileDescriptor<sup>8+</sup>

getRawFileDescriptor(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                     |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.xml", (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let fd = value.fd;
              let offset = value.offset;
              let length = value.length;
          }
      });
  });
  ```

### getRawFileDescriptor<sup>8+</sup>

getRawFileDescriptor(path: string): Promise&lt;RawFileDescriptor&gt;

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**
| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.xml").then(value => {
          let fd = value.fd;
          let offset = value.offset;
          let length = value.length;
      }).catch(error => {
          console.log("getRawFileDescriptor promise error is " + error);
      });
  });
  ```

### closeRawFileDescriptor<sup>8+</sup>

closeRawFileDescriptor(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Asynchronous callback used to return the result.       |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.xml", (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          }
      });
  });
  ```

### closeRawFileDescriptor<sup>8+</sup>

closeRawFileDescriptor(path: string): Promise&lt;void&gt;

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**
| Type                 | Description  |
| ------------------- | ---- |
| Promise&lt;void&gt; | No value is returned.|

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.xml").then(value => {
          let result = value;
      }).catch(error => {
          console.log("closeRawFileDescriptor promise error is " + error);
      });
  });
  ```

### release<sup>7+</sup>

release()

Releases the created **resourceManager**.

**System capability**: SystemCapability.Global.ResourceManager

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.release();
  });
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | Yes  | Resource name.       |
| callback | AsyncCallback&lt;string&gt; | Yes  | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getStringByName("test", (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let string = value;
      }
  });
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ---- |
| resName | string | Yes  | Resource name.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;string&gt; | String corresponding to the resource name.|

**Example**
  ```
  resourceManager.getStringByName("test").then(value => {
      let string = value;
  }).catch(error => {
      console.log("getStringByName promise error is " + error);
  });
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | Yes   | Resource name.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getStringArrayByName("test", (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let strArray = value;
      }
  });
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains the string array corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| resName | string | Yes  | Resource name.|

**Return value**
| Type                                | Description           |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getStringArrayByName("test").then(value => {
      let strArray = value;
  }).catch(error => {
      console.log("getStringArrayByName promise error is " + error);
  });
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getMediaByName("test", (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let media = value;
      }
  });
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| -----   | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|

**Return value**
| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getMediaByName("test").then(value => {
      let media = value;
  }).catch(error => {
      console.log("getMediaByName promise error is " + error);
  });
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getMediaBase64ByName("test", (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let media = value;
      }
  });
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| resName | string | Yes  | Resource name.|

**Return value**
| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getMediaByName("test").then(value => {
      let media = value;
  }).catch(error => {
      console.log("getMediaBase64ByName promise error is " + error);
  });
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the plural string corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resName  | string                      | Yes   | Resource name.                          |
| num      | number                      | Yes   | Number that determines the plural or singular form.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Asynchronous callback used to return the result.|

**Example**
  ```
  resourceManager.getPluralStringByName("test", 1, (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let str = value;
      }
  });
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number): Promise&lt;string&gt;

Obtains the plural string corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|
| num     | number | Yes   | Number that determines the plural or singular form.  |

**Return value**
| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```
  resourceManager.getPluralStringByName("test", 1).then(value => {
      let str = value;
  }).catch(error => {
      console.log("getPluralStringByName promise error is " + error);
  });
  ```

### getStringSync<sup>9+</sup>

getStringSync(resId: number): string

Obtains the string corresponding to the specified resource ID. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| string | String corresponding to the specified resource ID.|

**Example**
  ```
  resourceManager.getStringSync($r('app.string.test').id);
  ```

### getStringByNameSync<sup>9+</sup>

getStringByNameSync(resName: string): string

Obtains the string corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| string | String corresponding to the resource name.|

**Example**
  ```
  resourceManager.getStringByNameSync("test");
  ```

 ### getBoolean<sup>9+</sup>

getBoolean(resId: number): boolean

Obtains the Boolean result corresponding to the specified resource ID. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| boolean | Boolean result corresponding to the specified resource ID.|

**Example**
  ```
  resourceManager.getBoolean($r('app.boolean.boolean_test').id);
  ```

### getBooleanByName<sup>9+</sup>

getBooleanByName(resName: string): boolean

Obtains the Boolean result corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ------- | ------ | ---- | ----- |
| resName | string | Yes  | Resource name.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| boolean | Boolean result corresponding to the specified resource name.|

**Example**
  ```
  resourceManager.getBooleanByName("boolean_test");
  ```

 ### getNumber<sup>9+</sup>

getNumber(resId: number): number

Obtains the integer or float value corresponding to the specified resource ID. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| number | Integer or float value corresponding to the specified resource ID.|

**Example**
  ```
  resourceManager.getNumber($r('app.integer.integer_test').id);
  resourceManager.getNumber($r('app.float.float_test').id);
  ```

### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

Obtains the integer or float value corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|

**Return value**
| Type                   | Description         |
| --------------------- | ----------- |
| number | Integer or float value corresponding to the specified resource name.|

**Example**
  ```
  resourceManager.getNumberByName("integer_test");
  resourceManager.getNumberByName("float_test");
  ```

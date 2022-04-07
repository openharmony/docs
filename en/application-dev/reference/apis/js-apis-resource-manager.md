# Resource Management

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import resourceManager from '@ohos.resourceManager';
```

## resourceManager.getResourceManager

getResourceManager(callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of this application. This method uses a callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes       | Callback used to return the **ResourceManager** object obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      if (error != null) {
          console.log("error occurs" + error);
          return; 
      }
      mgr.getString(0x1000000, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


## resourceManager.getResourceManager

getResourceManager(bundleName: string, callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of an application. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name       | Type                                     | Mandatory | Description                              |
| ---------- | ---------------------------------------- | --------- | ---------------------------------------- |
| bundleName | string                                   | Yes       | Bundle name of the target application.   |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes       | Callback used to return the **ResourceManager** object obtained. |

**Example**
  ```
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```


## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of this application. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the **ResourceManager** object obtained. |

**Example**
  ```
  resourceManager.getResourceManager().then(mgr => {
      mgr.getString(0x1000000, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  }).catch(error => {
      console.log(error);
  });
  ```


## resourceManager.getResourceManager

getResourceManager(bundleName: string): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of an application. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name       | Type   | Mandatory | Description                            |
| ---------- | ------ | --------- | -------------------------------------- |
| bundleName | string | Yes       | Bundle name of the target application. |

**Return value**
| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the **ResourceManager** object obtained. |

**Example**
  ```
  resourceManager.getResourceManager("com.example.myapplication").then(mgr => {

  }).catch(error => {

  });
  ```


## Direction

Enumerates the screen directions.

**System capability**: SystemCapability.Global.ResourceManager

| Name                 | Default Value | Description |
| -------------------- | ------------- | ----------- |
| DIRECTION_VERTICAL   | 0             | Portrait    |
| DIRECTION_HORIZONTAL | 1             | Landscape   |


## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.Global.ResourceManager

| Name                 | Default Value | Description   |
| -------------------- | ------------- | ------------- |
| DEVICE_TYPE_PHONE    | 0x00          | Mobile phone. |
| DEVICE_TYPE_TABLET   | 0x01          | Tablet.       |
| DEVICE_TYPE_CAR      | 0x02          | Automobile.   |
| DEVICE_TYPE_PC       | 0x03          | Computer.     |
| DEVICE_TYPE_TV       | 0x04          | TV.           |
| DEVICE_TYPE_WEARABLE | 0x06          | Wearable.     |


## ScreenDensity

Enumerates the screen density types.

**System capability**: SystemCapability.Global.ResourceManager

| Name           | Default Value | Description                              |
| -------------- | ------------- | ---------------------------------------- |
| SCREEN_SDPI    | 120           | Screen density with small-scale dots per inch (SDPI). |
| SCREEN_MDPI    | 160           | Screen density with medium-scale dots per inch (MDPI). |
| SCREEN_LDPI    | 240           | Screen density with large-scale dots per inch (LDPI). |
| SCREEN_XLDPI   | 320           | Screen density with extra-large-scale dots per inch (XLDPI). |
| SCREEN_XXLDPI  | 480           | Screen density with extra-extra-large-scale dots per inch (XXLDPI). |
| SCREEN_XXXLDPI | 640           | Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI). |


## Configuration

Defines the device configuration.

**System capability**: SystemCapability.Global.ResourceManager


| Name      | Type                    | Readable | Writable | Description                     |
| --------- | ----------------------- | -------- | -------- | ------------------------------- |
| direction | [Direction](#direction) | Yes      | No       | Screen direction of the device. |
| locale    | string                  | Yes      | No       | Current system language.        |


## DeviceCapability

Defines the device capability.

**System capability**: SystemCapability.Global.ResourceManager


| Name          | Type                            | Readable | Writable | Description                   |
| ------------- | ------------------------------- | -------- | -------- | ----------------------------- |
| screenDensity | [ScreenDensity](#screendensity) | Yes      | No       | Screen density of the device. |
| deviceType    | [DeviceType](#devicetype)       | Yes      | No       | Type of the device.           |


## RawFileDescriptor<sup>8+</sup>

Defines the descriptor information of the raw file.<br>
**System capability**: SystemCapability.Global.ResourceManager

| Name   | Type   | Description                              |
| ------ | ------ | ---------------------------------------- |
| fd     | number | Descriptor of a raw file.                |
| offset | number | Offset to the start position of the raw file. |
| length | number | Length of the raw file.                  |


## ResourceManager

Defines the capability of accessing application resources.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> - The methods involved in **ResourceManager** are applicable only to the TypeScript-based declarative development paradigm.
>
> - Resource files are defined in the **resources** directory of the project. You can obtain the resource ID using **$r(resource address).id**, for example, **$r('app.string.test').id**.


### getString

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource ID. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                        | Mandatory | Description                              |
| -------- | --------------------------- | --------- | ---------------------------------------- |
| resId    | number                      | Yes       | Resource ID.                             |
| callback | AsyncCallback&lt;string&gt; | Yes       | Callback used to return the string obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getString

getString(resId: number): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource ID. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type   | Mandatory | Description  |
| ----- | ------ | --------- | ------------ |
| resId | number | Yes       | Resource ID. |

**Return value**
| Type                  | Description                              |
| --------------------- | ---------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the string obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id).then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getStringArray

getStringArray(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the array of strings corresponding to the specified resource ID. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| resId    | number                                   | Yes       | Resource ID.                             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes       | Callback used to return the obtained array of strings. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getStringArray($r('app.strarray.test').id, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getStringArray

getStringArray(resId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the array of strings corresponding to the specified resource ID. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type   | Mandatory | Description  |
| ----- | ------ | --------- | ------------ |
| resId | number | Yes       | Resource ID. |

**Return value**
| Type                               | Description                              |
| ---------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the array of strings obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
       mgr.getStringArray($r('app.strarray.test').id).then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getMedia

getMedia(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource ID. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                            | Mandatory | Description                              |
| -------- | ------------------------------- | --------- | ---------------------------------------- |
| resId    | number                          | Yes       | Resource ID.                             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes       | Callback used to return the content of the media file obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getMedia

getMedia(resId: number): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource ID. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type   | Mandatory | Description  |
| ----- | ------ | --------- | ------------ |
| resId | number | Yes       | Resource ID. |

**Return value**
| Type                      | Description                              |
| ------------------------- | ---------------------------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the content of the media file obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id).then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getMediaBase64

getMediaBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource ID. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                        | Mandatory | Description                              |
| -------- | --------------------------- | --------- | ---------------------------------------- |
| resId    | number                      | Yes       | Resource ID.                             |
| callback | AsyncCallback&lt;string&gt; | Yes       | Callback used to return the Base64 code of the image obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getMediaBase64

getMediaBase64(resId: number): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource ID. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type   | Mandatory | Description  |
| ----- | ------ | --------- | ------------ |
| resId | number | Yes       | Resource ID. |

**Return value**
| Type                  | Description                              |
| --------------------- | ---------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id).then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getConfiguration

getConfiguration(callback: AsyncCallback&lt;Configuration&gt;): void

Obtains the device configuration. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | Yes       | Callback used to return the obtained device configuration. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getConfiguration((error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getConfiguration

getConfiguration(): Promise&lt;Configuration&gt;

Obtains the device configuration. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;[Configuration](#configuration)&gt; | Promise used to return the device configuration. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getConfiguration().then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getDeviceCapability

getDeviceCapability(callback: AsyncCallback&lt;DeviceCapability&gt;): void

Obtains the device capability. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | Yes       | Callback used to return the obtained device capability. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability((error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getDeviceCapability

getDeviceCapability(): Promise&lt;DeviceCapability&gt;

Obtains the device capability. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**
| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | Promise used to return the obtained device capability. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability().then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```


### getPluralString

getPluralString(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                        | Mandatory | Description                              |
| -------- | --------------------------- | --------- | ---------------------------------------- |
| resId    | number                      | Yes       | Resource ID.                             |
| num      | number                      | Yes       | Number that determines the plural or singular form. |
| callback | AsyncCallback&lt;string&gt; | Yes       | Callback used to return the singular-plural string obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1, (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```


### getPluralString

getPluralString(resId: number, num: number): Promise&lt;string&gt;

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name  | Type   | Mandatory | Description                              |
| ----- | ------ | --------- | ---------------------------------------- |
| resId | number | Yes       | Resource ID.                             |
| num   | number | Yes       | Number that determines the plural or singular form. |

**Return value**
| Type                  | Description                              |
| --------------------- | ---------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the singular-plural string obtained. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1).then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getstring promise " + error);
      });
  });
  ```

### getRawFile<sup>8+</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the specified path. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                            | Mandatory | Description                              |
| -------- | ------------------------------- | --------- | ---------------------------------------- |
| path     | string                          | Yes       | Path of the raw file.                    |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes       | Callback used to return the raw file content, in byte arrays. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.xml", (error, value) => {
          if (error != null) {
              console.log(value);
          } else {
              console.log(value);
          }
      });
  });
  ```

### getRawFile<sup>8+</sup>

getRawFile(path: string): Promise&lt;Uint8Array&gt;

Obtains the content of the raw file in the specified path. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type   | Mandatory | Description           |
| ---- | ------ | --------- | --------------------- |
| path | string | Yes       | Path of the raw file. |

**Return value**
| Type                      | Description                              |
| ------------------------- | ---------------------------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the raw file content, in byte arrays. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.xml").then(value => {
          console.log(value);
      }).catch(error => {
          console.log("getrawfile promise " + error);
      });
  });
  ```

### getRawFileDescriptor<sup>8+</sup>

getRawFileDescriptor(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the raw file in the specified path. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| path     | string                                   | Yes       | Path of the raw file.                    |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8+</sup)&gt; | Yes       | Callback used to return the raw file descriptor. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.xml", (error, value) => {
          if (error != null) {
              console.log(value);
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

Obtains the descriptor of the raw file in the specified path. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type   | Mandatory | Description           |
| ---- | ------ | --------- | --------------------- |
| path | string | Yes       | Path of the raw file. |

**Return value**
| Type                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Promise used to return the raw file descriptor. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.xml").then(value => {
          let fd = value.fd;
          let offset = value.offset;
          let length = value.length;
      }).catch(error => {
          console.log("getRawFileDescriptor promise " + error);
      });
  });
  ```

### closeRawFileDescriptor<sup>8+</sup>

closeRawFileDescriptor(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the raw file in the specified path. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| path     | string                    | Yes       | Path of the raw file.               |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.xml", (error, value) => {
          if (error != null) {
              console.log(value);
          }
      });
  });
  ```

### closeRawFileDescriptor<sup>8+</sup>

closeRawFileDescriptor(path: string): Promise&lt;void&gt;

Closes the descriptor of the raw file in the specified path. This method uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**
| Name | Type   | Mandatory | Description           |
| ---- | ------ | --------- | --------------------- |
| path | string | Yes       | Path of the raw file. |

**Return value**
| Type                | Description           |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | No value is returned. |

**Example**
  ```
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.xml").then(value => {
          console.log(value);
      }).catch(error => {
          console.log("closeRawFileDescriptor promise " + error);
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
      mgr.release((error, value) => {
          if (error != null) {
              console.log(value);
          }
      });
  });
  ```

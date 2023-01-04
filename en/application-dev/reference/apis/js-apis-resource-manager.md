# Resource Manager

The Resource Manager module provides APIs to obtain information about application resources based on the current configuration, including the language, region, screen direction, MCC/MNC, as well as device capability and density.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import resourceManager from '@ohos.resourceManager';
```

## Instruction

Since API version 9, the stage model allows an application to obtain a **ResourceManager** object based on **context** and call its resource management APIs without first importing the required bundle. This approach, however, is not applicable to the FA model. For the FA model, you need to import the required bundle and then call the [getResourceManager](#resourcemanagergetresourcemanager) API to obtain a **ResourceManager** object.

For details about how to reference **context** in the stage model, see Context in the Stage Model.


```ts
import Ability from '@ohos.application.Ability';
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let resourceManager = context.resourceManager;
    }
}
```

## resourceManager.getResourceManager

getResourceManager(callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of this application. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                           |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Callback used to return the result.|

**Example**
  ```js
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

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name       | Type                                      | Mandatory  | Description                           |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | Yes   | Bundle name of the application.                |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Callback used to return the result.|

**Example**
  ```js
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```


## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of this application. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description               |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result.|

**Example**
  ```js
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

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result.|

**Example**
  ```js
  resourceManager.getResourceManager("com.example.myapplication").then(mgr => {
  }).catch(error => {
  });
  ```


## Direction

Enumerates the screen directions.

**System capability**: SystemCapability.Global.ResourceManager

| Name                  | Value | Description  |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | Portrait.  |
| DIRECTION_HORIZONTAL | 1    | Landscape.  |


## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.Global.ResourceManager

| Name                  | Value | Description  |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_PHONE    | 0x00 | Phone  |
| DEVICE_TYPE_TABLET   | 0x01 | Tablet  |
| DEVICE_TYPE_CAR      | 0x02 | Head unit  |
| DEVICE_TYPE_PC       | 0x03 | PC  |
| DEVICE_TYPE_TV       | 0x04 | TV  |
| DEVICE_TYPE_WEARABLE | 0x06 | Wearable  |


## ScreenDensity

Enumerates the screen density types.

**System capability**: SystemCapability.Global.ResourceManager

| Name            | Value | Description        |
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

**Parameters**

| Name       | Type                   | Readable  | Writable  | Description      |
| --------- | ----------------------- | ---- | ---- | -------- |
| direction | [Direction](#direction) | Yes   | No   | Screen direction of the device.|
| locale    | string                  | Yes   | No   | Current system language.  |

**Example**

  ```js
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

**Parameters**

| Name           | Type                           | Readable  | Writable  | Description      |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | Yes   | No   | Screen density of the device.|
| deviceType    | [DeviceType](#devicetype)       | Yes   | No   | Type of the device.  |

**Example**

  ```js
resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability((error, value) => {
          let screenDensity = value.screenDensity;
          let deviceType = value.deviceType;
      });
  });
  ```

## RawFileDescriptor<sup>8+</sup>

Defines the descriptor of the raw file.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type   | Readable  | Writable | Description          |
| ------ | ------  | ---- | ---- | ------------------ |
| fd     | number  | Yes   | No| Descriptor of the raw file.|
| offset | number  | Yes   | No| Start offset of the raw file.     |
| length | number  | Yes   | No| Length of the raw file.      |

## Resource<sup>9+</sup>

Defines the resource information of an application.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name        | Type    | Readable  | Writable |Description         |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | Yes   | No| Bundle name of the application.|
| moduleName | string | Yes   | No| Module name of the application.|
| id         | number | Yes   | No| Resource ID.     |


## ResourceManager

Defines the capability of accessing application resources.

> **NOTE**
>
> - The APIs involved in **ResourceManager** are applicable only to the TypeScript-based declarative development paradigm.
>
> - Resource files are defined in the **resources** directory of the project. You can obtain the resource ID using **$r(resource address).id**, for example, **$r('app.string.test').id**.

### getStringValue<sup>9+</sup>

getStringValue(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the module resId invalid.             |
| 9001002  | If the resource not found by resId.      |
| 9001006  | If the resource re-ref too much.         |

**Example (stage)**
  ```ts
    try {
        this.context.resourceManager.getStringValue($r('app.string.test').id, (error, value) => {
          if (error != null) {
              console.log("error is " + error);
          } else {
              let str = value;
          }
      });
    } catch (error) {
        console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`)
    }
  ```


### getStringValue<sup>9+</sup>

getStringValue(resId: number): Promise&lt;string&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringValue($r('app.string.test').id).then(value => {
        let str = value;
    }).catch(error => {
        console.log("getStringValue promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getStringValue<sup>9+</sup>

getStringValue(resource: Resource, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | Yes   | Resource object.           |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringValue(resource, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let str = value;
        }
    });
  } catch (error) {
    console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  
  ```


### getStringValue<sup>9+</sup>

getStringValue(resource: Resource): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource object. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description              |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringValue(resource).then(value => {
      let str = value;
    }).catch(error => {
      console.log("getStringValue promise error is " + error);
    });
  } catch (error) {
    console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let strArray = value;
        }
    });
  } catch (error) {
    console.error(`callback getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number): Promise&lt;Array&lt;string&gt;&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id).then(value => {
        let strArray = value;
    }).catch(error => {
        console.log("getStringArrayValue promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | Yes   | Resource object.             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValue(resource, (error, value) => {
      if (error != null) {
          console.log("error is " + error);
      } else {
          let strArray = value;
      }
    });
  } catch (error) {
    console.error(`callback getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource): Promise&lt;Array&lt;string&gt;&gt;

Obtains the string array corresponding to the specified resource object. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                                | Description                |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValue(resource).then(value => {
      let strArray = value;
    }).catch(error => {
        console.log("getStringArray promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getMediaContent<sup>9+</sup>

getMediaContent(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let media = value;
        }
    });
  } catch (error) {
    console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getMediaContent<sup>9+</sup>

getMediaContent(resId: number): Promise&lt;Uint8Array&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  try {
      this.context.resourceManager.getMediaContent($r('app.media.test').id).then(value => {
          let media = value;
      }).catch(error => {
          console.log("getMediaContent promise error is " + error);
      });
  } catch (error) {
    console.error(`promise getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resource: Resource, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | Yes   | Resource object.              |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, (error, value) => {
        if (error != null) {
          console.log("error is " + error);
        } else {
          let media = value;
        }
    });
  } catch (error) {
    console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resource: Resource): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource object. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                       | Description                 |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource).then(value => {
      let media = value;
    }).catch(error => {
      console.log("getMediaContent promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let media = value;
        }
    });       
  } catch (error) {
    console.error(`callback getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number): Promise&lt;string&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id).then(value => {
        let media = value;
    }).catch(error => {
        console.log("getMediaContentBase64 promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`)
  } 
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resource: Resource, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                    |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let media = value;
        }
    });
  } catch (error) {
    console.error(`promise getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resource: Resource): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource object. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; |  Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource).then(value => {
        let media = value;
    }).catch(error => {
        console.log("getMediaContentBase64 promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getConfiguration

getConfiguration(callback: AsyncCallback&lt;Configuration&gt;): void

Obtains the device configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                       |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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
  ```ts
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
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getDeviceCapability().then(value => {
          let screenDensity = value.screenDensity;
          let deviceType = value.deviceType;
      }).catch(error => {
          console.log("getDeviceCapability promise error is " + error);
      });
  });
  ```


### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the singular-plural string corresponding to the specified resource ID based on the specified number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Number.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let str = value;
        }
    });
  } catch (error) {
    console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }   
  ```


### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resId: number, num: number): Promise&lt;string&gt;

Obtains the singular-plural string corresponding to the specified resource ID based on the specified number. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number.  |

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1).then(value => {
        let str = value;
    }).catch(error => {
        console.log("getPluralStringValue promise error is " + error);
    });
  } catch (error) {
    console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }  
  ```

### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resource: Resource, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the singular-plural string corresponding to the specified resource object based on the specified number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                                  |
| -------- | --------------------------- | ---- | ------------------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                                |
| num      | number                      | Yes   | Number.                                 |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralStringValue(resource, 1, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let str = value;
        }
    });
  } catch (error) {
    console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }  
  
  ```

### getPluralString<sup>9+</sup>

getPluralString(resource: Resource, num: number): Promise&lt;string&gt;

Obtains the singular-plural string corresponding to the specified resource object based on the specified number. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| num      | number                 | Yes   | Number. |

**Return value**

| Type                   | Description                            |
| --------------------- | ------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralString(resource, 1).then(value => {
        let str = value;
    }).catch(error => {
        console.log("getPluralString promise error is " + error);
    });
  } catch (error) {
    console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getRawFileContent<sup>9+</sup>

getRawFileContent(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.getRawFileContent("test.xml", (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let rawFile = value;
        }
    });
  } catch (error) {
    console.error(`callback getRawFileContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
      
  ```

### getRawFileContent<sup>9+</sup>

getRawFileContent(path: string): Promise&lt;Uint8Array&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.getRawFileContent("test.xml").then(value => {
        let rawFile = value;
    }).catch(error => {
        console.log("getRawFileContent promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getRawFileContent failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getRawFd<sup>9+</sup>

getRawFd(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                     |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.getRawFd("test.xml", (error, value) => {
        if (error != null) {
            console.log(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);
        } else {
            let fd = value.fd;
            let offset = value.offset;
            let length = value.length;
        }
    });
  } catch (error) {
      console.error(`callback getRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  };
  ```

### getRawFd<sup>9+</sup>

getRawFd(path: string): Promise&lt;RawFileDescriptor&gt;

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

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.getRawFd("test.xml").then(value => {
        let fd = value.fd;
        let offset = value.offset;
        let length = value.length;
    }).catch(error => {
        console.log(`promise getRawFd error error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    console.error(`promise getRawFd failed, error code: ${error.code}, message: ${error.message}.`);
  };
  ```

### closeRawFileDescriptor<sup>8+</sup>

closeRawFileDescriptor(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.       |

**Example**
  ```ts
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
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.xml").then(value => {
          let result = value;
      }).catch(error => {
          console.log("closeRawFileDescriptor promise error is " + error);
      });
  });
  ```


### closeRawFd<sup>9+</sup>

closeRawFd(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.       |

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | The resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.closeRawFd("test.xml", (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        }
    });
  } catch (error) {
    console.error(`callback closeRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  }
      
  ```

### closeRawFd<sup>8+</sup>

closeRawFd(path: string): Promise&lt;void&gt;

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                 | Description  |
| ------------------- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**Example**
  ```ts
  try {
    this.context.resourceManager.closeRawFd("test.xml").then(value => {
        let result = value;
    }).catch(error => {
        console.log("closeRawFd promise error is " + error);
    });
  } catch (error) {
    console.error(`promise closeRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### release<sup>7+</sup>

release()

Releases a created **resourceManager** object.

**System capability**: SystemCapability.Global.ResourceManager

**Example**
  ```ts
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
| resName  | string                      | Yes   | Resource name.           |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringByName("test", (error, value) => {
        if (error != null) {
             console.log("error is " + error);
        } else {
            let string = value;
        }
    });
  } catch (error) {
    console.error(`callback getStringByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | String corresponding to the resource name.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringByName("test").then(value => {
        let string = value;
    }).catch(error => {
        console.log("getStringByName promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getStringByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | Yes   | Resource name.             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringArrayByName("test", (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let strArray = value;
        }
    });
  } catch (error) {
    console.error(`callback getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains the string array corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                                | Description          |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringArrayByName("test").then(value => {
        let strArray = value;
    }).catch(error => {
        console.log("getStringArrayByName promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.              |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaByName("test", (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let media = value;
        }
    });
  } catch (error) {
    console.error(`callback getMediaByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                       | Description           |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaByName("test").then(value => {
        let media = value;
    }).catch(error => {
        console.log("getMediaByName promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getMediaByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                    |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaBase64ByName("test", (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let media = value;
        }
    });
  } catch (error) {
    console.error(`callback getMediaBase64ByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource name. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getMediaBase64ByName("test").then(value => {
        let media = value;
    }).catch(error => {
        console.log("getMediaBase64ByName promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getMediaBase64ByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the plural string corresponding to the specified resource name based on the specified number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                           |
| -------- | --------------------------- | ---- | ----------------------------- |
| resName  | string                      | Yes   | Resource name.                         |
| num      | number                      | Yes   | Number.                          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getPluralStringByName("test", 1, (error, value) => {
        if (error != null) {
            console.log("error is " + error);
        } else {
            let str = value;
        }
    });
  } catch (error) {
    console.error(`callback getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number): Promise&lt;string&gt;

Obtains the plural string corresponding to the specified resource name based on the specified number. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| num     | number | Yes   | Number. |

**Return value**

| Type                   | Description                    |
| --------------------- | ---------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getPluralStringByName("test", 1).then(value => {
      let str = value;
    }).catch(error => {
      console.log("getPluralStringByName promise error is " + error);
    });
  } catch (error) {
    console.error(`promise getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
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

| Type    | Description         |
| ------ | ----------- |
| string | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringSync($r('app.string.test').id);
  } catch (error) {
    console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringSync<sup>9+</sup>

getStringSync(resource: Resource): string

Obtains the string corresponding to the specified resource object. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description              |
| ------ | ---------------- |
| string | Promise used to return the result.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringSync(resource);
  } catch (error) {
    console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getStringByNameSync<sup>9+</sup>

getStringByNameSync(resName: string): string

Obtains the string corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | String corresponding to the specified resource name.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringByNameSync("test");
  } catch (error) {
    console.error(`getStringByNameSync failed, error code: ${error.code}, message: ${error.message}.`)
  }
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

| Type     | Description          |
| ------- | ------------ |
| boolean | Boolean result corresponding to the specified resource ID.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);
  } catch (error) {
    console.error(`getBoolean failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```
### getBoolean<sup>9+</sup>

getBoolean(resource: Resource): boolean

Obtains the Boolean result corresponding to the specified resource object. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| boolean | Boolean result corresponding to the specified resource object.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.boolean.boolean_test').id
  };
  try {
    this.context.resourceManager.getBoolean(resource);
  } catch (error) {
    console.error(`getBoolean failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getBooleanByName<sup>9+</sup>

getBooleanByName(resName: string): boolean

Obtains the Boolean result corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Boolean result corresponding to the specified resource name.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getBooleanByName("boolean_test");
  } catch (error) {
    console.error(`getBooleanByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
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

| Type    | Description        |
| ------ | ---------- |
| number | Integer or float value corresponding to the specified resource ID.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getNumber($r('app.integer.integer_test').id);
  } catch (error) {
    console.error(`getNumber failed, error code: ${error.code}, message: ${error.message}.`)
  }

  try {
    this.context.resourceManager.getNumber($r('app.float.float_test').id);
  } catch (error) {
    console.error(`getNumber failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resource: Resource): number

Obtains the integer or float value corresponding to the specified resource object. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description             |
| ------ | --------------- |
| number | Integer or float value corresponding to the specified resource object.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  let resource = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      id: $r('app.integer.integer_test').id
  };
  try {
    this.context.resourceManager.getNumber(resource);
  } catch (error) {
    console.error(`getNumber failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```

### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

Obtains the integer or float value corresponding to the specified resource name. This API returns the result synchronously.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Integer or float value corresponding to the specified resource name.|

For details about the error codes, see [Resource Manager Error Codes](../errorcodes/errorcode-resource-manager.md).

**Error codes**

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getNumberByName("integer_test");
  } catch (error) {
    console.error(`getNumberByName failed, error code: ${error.code}, message: ${error.message}.`)
  }

  try {
    this.context.resourceManager.getNumberByName("float_test");
  } catch (error) {
    console.error(`getNumberByName failed, error code: ${error.code}, message: ${error.message}.`)
  }
  ```


### getString<sup>(deprecated)</sup>

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the string corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getString<sup>(deprecated)</sup>

getString(resId: number): Promise&lt;string&gt;

Obtains the string corresponding to the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9-1) instead.

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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id).then(value => {
          let str = value;
      }).catch(error => {
          console.log("getstring promise error is " + error);
      });
  });
  ```


### getStringArray<sup>(deprecated)</sup>

getStringArray(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the string array corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getStringArray<sup>(deprecated)</sup>

getStringArray(resId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the string array corresponding to the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9-1) instead.

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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
       mgr.getStringArray($r('app.strarray.test').id).then(value => {
          let strArray = value;
      }).catch(error => {
          console.log("getStringArray promise error is " + error);
      });
  });
  ```


### getMedia<sup>(deprecated)</sup>

getMedia(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the media file corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getMedia<sup>(deprecated)</sup>

getMedia(resId: number): Promise&lt;Uint8Array&gt;

Obtains the content of the media file corresponding to the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9-1) instead.

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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id).then(value => {
          let media = value;
      }).catch(error => {
          console.log("getMedia promise error is " + error);
      });
  });
  ```


### getMediaBase64<sup>(deprecated)</sup>

getMediaBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of the image corresponding to the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getMediaBase64<sup>(deprecated)</sup>

getMediaBase64(resId: number): Promise&lt;string&gt;

Obtains the Base64 code of the image corresponding to the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649-1) instead.

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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id).then(value => {
          let media = value;
      }).catch(error => {
          console.log("getMediaBase64 promise error is " + error);
      });
  });
  ```


### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number): Promise&lt;string&gt;

Obtains the singular-plural string corresponding to the specified resource ID based on the specified number. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getPluralStringValue](#getpluralstringvalue9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number.  |

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1).then(value => {
          let str = value;
      }).catch(error => {
          console.log("getPluralString promise error is " + error);
      });
  });
  ```


### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the singular-plural string corresponding to the specified resource ID based on the specified number. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getPluralStringValue](#getpluralstringvalue9-1) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Number.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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


### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string): Promise&lt;Uint8Array&gt;

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9-1) instead.

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
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.xml").then(value => {
          let rawFile = value;
      }).catch(error => {
          console.log("getRawFile promise error is " + error);
      });
  });
  ```


### getRawFileDescriptor<sup>(deprecated)</sup>

getRawFileDescriptor(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                     |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Yes   | Callback used to return the result.|

**Example**
  ```ts
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

### getRawFileDescriptor<sup>(deprecated)</sup>

getRawFileDescriptor(path: string): Promise&lt;RawFileDescriptor&gt;

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9-1) instead.

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
  ```ts
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

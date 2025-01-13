# @ohos.resourceManager (Resource Management)

The **resourceManager** module provides APIs to obtain information about application resources based on the current configuration, including the language, region, screen direction, MCC/MNC, as well as device capability and density.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## How to Use

Since API version 9, the stage model allows an application to obtain a **ResourceManager** object based on **context** and call its resource management APIs without first importing the required bundle.
For the FA model, you need to import the required bundle and then call the [getResourceManager](#resourcemanagergetresourcemanager) API to obtain a **ResourceManager** object.
For details about how to reference context in the stage model, see [Context in the Stage Model](../../application-models/application-context-stage.md).

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let context = this.context;
    let resourceManager = context.resourceManager;
  }
}
```

## resourceManager.getResourceManager

getResourceManager(callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the FA model.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                           |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   |Callback used to return the result, which is a **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  resourceManager.getResourceManager((error, mgr) => {
    if (error != null) {
      console.error("error is " + error);
      return;
    }
    mgr.getStringValue($r('app.string.test').id, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  });
  ```

## resourceManager.getResourceManager

getResourceManager(bundleName: string, callback: AsyncCallback&lt;ResourceManager&gt;): void

Obtains the **ResourceManager** object of the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the FA model.

**Parameters**

| Name       | Type                                      | Mandatory  | Description                           |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | Yes   | Bundle name of an application.                |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Callback used to return the result, which is a **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```

## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the FA model.

**Return value**

| Type                                      | Description               |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result, which is a **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager().then((mgr: resourceManager.ResourceManager) => {
    mgr.getStringValue($r('app.string.test').id, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  }).catch((error: BusinessError) => {
    console.error("error is " + error);
  });
  ```

## resourceManager.getResourceManager

getResourceManager(bundleName: string): Promise&lt;ResourceManager&gt;

Obtains the **ResourceManager** object of the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the FA model.

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | Yes   | Bundle name of an application.|

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the result, which is a **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager("com.example.myapplication").then((mgr: resourceManager.ResourceManager) => {
  }).catch((error: BusinessError) => {
  });
  ```

## resourceManager.getSystemResourceManager<sup>10+</sup>

getSystemResourceManager(): ResourceManager

Obtains a **ResourceManager** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| [Resourcemanager](#resourcemanager) | **ResourceManager** object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001009  | Failed to access the system resource.which is not mapped to application sandbox, This error code will be thrown. |

**Example**
  ```js
import { resourceManager } from '@kit.LocalizationKit'
import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let systemResourceManager = resourceManager.getSystemResourceManager();
    systemResourceManager.getStringValue($r('sys.string.ohos_lab_vibrate').id).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("systemResourceManager getStringValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`systemResourceManager getStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

## Direction

Enumerates the screen directions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name                  | Value | Description  |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | Portrait  |
| DIRECTION_HORIZONTAL | 1    | Landscape  |


## DeviceType

Enumerates the device types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager
<!--RP1-->
| Name                  | Value | Description  |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_PHONE    | 0x00 | Phone  |
| DEVICE_TYPE_TABLET   | 0x01 | Tablet  |
| DEVICE_TYPE_CAR      | 0x02 | Automobile  |
| DEVICE_TYPE_TV       | 0x04 | TV |
| DEVICE_TYPE_WEARABLE | 0x06 | Wearable  |
| DEVICE_TYPE_2IN1<sup>11+</sup>     | 0x07 | 2-in-1  |
<!--RP1End-->

## ScreenDensity

Enumerates the screen density types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name            | Value | Description        |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | Screen density with small-scale dots per inch (SDPI). |
| SCREEN_MDPI    | 160  | Screen density with medium-scale dots per inch (MDPI).  |
| SCREEN_LDPI    | 240  | Screen density with large-scale dots per inch (LDPI).  |
| SCREEN_XLDPI   | 320  | Screen density with extra-large-scale dots per inch (XLDPI). |
| SCREEN_XXLDPI  | 480  | Screen density with extra-extra-large-scale dots per inch (XXLDPI). |
| SCREEN_XXXLDPI | 640  | Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI).|


## ColorMode<sup>12+</sup>

Defines the color mode of the current device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

| Name | Value  | Description      |
| ----- | ---- | ---------- |
| DARK  | 0    | Dark mode.|
| LIGHT | 1    | Light mode.|


## Configuration

Defines the device configuration.

**System capability**: SystemCapability.Global.ResourceManager

| Name                       | Type                           | Readable| Writable| Description              |
| --------------------------- | ------------------------------- | ---- | ---- | ------------------ |
| direction                   | [Direction](#direction)         | Yes  | Yes  | Screen orientation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| locale                      | string                          | Yes  | Yes  | Country or region.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| deviceType<sup>12+</sup>    | [DeviceType](#devicetype)       | Yes  | Yes  | Device type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| screenDensity<sup>12+</sup> | [ScreenDensity](#screendensity) | Yes  | Yes  | Screen density.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| colorMode<sup>12+</sup>     | [ColorMode](#colormode12)       | Yes  | Yes  | Color mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.       |
| mcc<sup>12+</sup>           | number                          | Yes  | Yes  | Mobile country code.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| mnc<sup>12+</sup>           | number                          | Yes  | Yes  | Mobile network code (MNC).<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |



## DeviceCapability

Defines the device capability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name           | Type                           | Readable  | Writable  | Description      |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | Yes   | No   | Screen density of the device.|
| deviceType    | [DeviceType](#devicetype)       | Yes   | No   | Device type.  |


## RawFileDescriptor<sup>8+</sup>

type RawFileDescriptor = _RawFileDescriptor

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Type   | Description  |
| ------  | ---- | 
|[_RawFileDescriptor](rawFileDescriptor.md#rawfiledescriptor-1)|Defines the descriptor of the HAP where the raw file is located.|

## Resource<sup>9+</sup>

type Resource = _Resource

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Type   | Description  |
| ------  | ---- | 
|[_Resource](resource.md#resource-1)|Resource information of an application.|

## ResourceManager

Defines the capability of accessing application resources.

> **NOTE**
>
> - The methods involved in **ResourceManager** are applicable only to the TypeScript-based declarative development paradigm.
>
> - Resource files are defined in the **resources** directory of the project. You can obtain the corresponding strings and string arrays based on the specified resource ID, resource name, or resource object. You can use **$r(resource address).id**, for example, **$r('app.string.test').id**, to obtain the resource ID.
>
> - Use the resource object for cross-package access in a multi-project application. It works by creating the context of the corresponding module to obtain required resources. Therefore, it takes a longer time than using the resource ID or resource name.
>
> - For details about intra-HAP and cross-HAP/HSP resource access modes, see [Resource Access](../../quick-start/resource-categories-and-access.md#resource-access).
>
> - For details about the content of the test files used in the sample code, see [Appendix](#appendix).

### getStringSync<sup>9+</sup>

getStringSync(resId: number): string

Obtains a string based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| string | String corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringSync($r('app.string.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>10+</sup>

getStringSync(resId: number, ...args: Array<string | number>): string

Obtains a string based on the specified resource ID and formats the string based on **args**. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| args | Array<string \| number> | No   | Arguments for formatting strings.<br>Supported value types include %d, %f, %s, %%, %number\\$d, %number\\$f, and %number\\$s.<br>Note: %% is escaped to %. % number\\$d indicates the sequence number of the parameter to be used.<br>For example, %%d is converted to a %d string after formatting, and %1\\$d indicates that the first parameter is used.|

**Return value**

| Type    | Description         |
| ------ | ---------------------------- |
| string | Formatted string corresponding to the specified resource ID.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                               |
| 9001002  | No matching resource is found based on the resource ID.                 |
| 9001006  | The resource is referenced cyclically.                    |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 10, 98.78);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>9+</sup>

getStringSync(resource: Resource): string

Obtains a string based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description              |
| ------ | ---------------- |
| string | String corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringSync(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>10+</sup>

getStringSync(resource: Resource, ...args: Array<string | number>): string

Obtains a string based on the specified resource object and formats the string based on **args**. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| args | Array<string \| number> | No   | Arguments for formatting strings.<br>Supported value types include %d, %f, %s, %%, %number\\$d, %number\\$f, and %number\\$s.<br>Note: %% is escaped to %. % number\\$d indicates the sequence number of the parameter to be used.<br>For example, %%d is converted to a %d string after formatting, and %1\\$d indicates that the first parameter is used.|

**Return value**

| Type    | Description         |
| ------ | ---------------------------- |
| string | Formatted string corresponding to the specified resource object.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringSync(resource, "format string", 10, 98.78);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
 ```

### getStringByNameSync<sup>9+</sup>

getStringByNameSync(resName: string): string

Obtains a string based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | String corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringByNameSync("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByNameSync<sup>10+</sup>

getStringByNameSync(resName: string, ...args: Array<string | number>): string

Obtains a string based on the specified resource name and formats the string based on **args**. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| args | Array<string \| number> | No   | Arguments for formatting strings.<br>Supported value types include %d, %f, %s, %%, %number\\$d, %number\\$f, and %number\\$s.<br>Note: %% is escaped to %. % number\\$d indicates the sequence number of the parameter to be used.<br>For example, %%d is converted to a %d string after formatting, and %1\\$d indicates that the first parameter is used.|

**Return value**

| Type    | Description         |
| ------ | ---------------------------- |
| string | Formatted string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |
| 9001008  | Failed to format the resource obtained based on the resource Name. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringByNameSync("test", "format string", 10, 98.78);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
 ```

### getStringValue<sup>9+</sup>

getStringValue(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**Example (stage)**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringValue($r('app.string.test').id, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringValue<sup>9+</sup>

getStringValue(resId: number): Promise&lt;string&gt;

Obtains a string based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringValue($r('app.string.test').id).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getStringValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringValue<sup>9+</sup>

getStringValue(resource: Resource, callback: AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | Yes   | Resource object.           |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringValue(resource, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringValue<sup>9+</sup>

getStringValue(resource: Resource): Promise&lt;string&gt;

Obtains a string based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description              |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringValue(resource).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getStringValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string, callback: AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | Yes   | Resource name.           |
| callback | AsyncCallback&lt;string&gt; | Yes   |Callback used to return the result, which is the string corresponding to the specified resource ID.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringByName("test", (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string): Promise&lt;string&gt;

Obtains a string based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringByName("test").then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getStringByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValueSync<sup>10+</sup>

getStringArrayValueSync(resId: number): Array&lt;string&gt;

Obtains a string array based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Array&lt;string&gt; | String array corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringArrayValueSync($r('app.strarray.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValueSync<sup>10+</sup>

getStringArrayValueSync(resource: Resource): Array&lt;string&gt;

Obtains a string array based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Array&lt;string&gt; | String array corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValueSync(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayByNameSync<sup>10+</sup>

getStringArrayByNameSync(resName: string): Array&lt;string&gt;

Obtains a string array based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Array&lt;string&gt; | String array corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  try {
    this.context.resourceManager.getStringArrayByNameSync("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result, which is the string array corresponding to the specified resource ID.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id, (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let strArray = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringArrayValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains a string array based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                                | Description           |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result, which is the string array corresponding to the specified resource ID.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id).then((value: Array<string>) => {
      let strArray = value;
    }).catch((error: BusinessError) => {
      console.error("getStringArrayValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringArrayValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | Yes   | Resource object.             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result, which is the string array corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValue(resource, (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let strArray = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringArrayValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource): Promise&lt;Array&lt;string&gt;&gt;

Obtains a string array based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                                | Description                |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result, which is the string array corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValue(resource).then((value: Array<string>) => {
      let strArray = value;
    }).catch((error: BusinessError) => {
      console.error("getStringArray promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringArrayValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | Yes   | Resource name.             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result, which is the string array corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringArrayByName("test", (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let strArray = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getStringArrayByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains a string array based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                                | Description          |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result, which is the string array corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getStringArrayByName("test").then((value: Array<string>) => {
      let strArray = value;
    }).catch((error: BusinessError) => {
      console.error("getStringArrayByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getStringArrayByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>10+</sup>

getPluralStringValueSync(resId: number, num: number): string

Obtains a singular-plural string by the specified number based on the specified resource ID. This API returns the result synchronously.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number.  |

**Return value**

| Type                   | Description         |
| -------- | ----------- |
| string   | Singular-plural string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>10+</sup>

getPluralStringValueSync(resource: Resource, num: number): string

Obtains a singular-plural string by the specified number based on the specified resource object. This API returns the result synchronously.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| num      | number                 | Yes   | Number.  |

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| string | Singular-plural string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralStringValueSync(resource, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringByNameSync<sup>10+</sup>

getPluralStringByNameSync(resName: string, num: number): string

Obtains a singular-plural string by the specified number based on the specified resource name. This API returns the result synchronously.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|
| num      | number                 | Yes   | Number.  |

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| string | Singular-plural string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringByNameSync("test", 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a singular-plural string by the specified number based on the specified resource ID. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Number.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the singular-plural string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getPluralStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resId: number, num: number): Promise&lt;string&gt;

Obtains a singular-plural string by the specified number based on the specified resource ID. This API uses a promise to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number. |

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the singular-plural string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getPluralStringValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getPluralStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resource: Resource, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a singular-plural string by the specified number based on the specified resource object. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description                                  |
| -------- | --------------------------- | ---- | ------------------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                                |
| num      | number                      | Yes   | Number.                                 |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the singular-plural string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralStringValue(resource, 1, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getPluralStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>9+</sup>

getPluralStringValue(resource: Resource, num: number): Promise&lt;string&gt;

Obtains a singular-plural string by the specified number based on the specified resource object. This API uses a promise to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| num      | number                 | Yes   | Number. |

**Return value**

| Type                   | Description                            |
| --------------------- | ------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result, which is the singular-plural string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.                |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralStringValue(resource, 1).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getPluralStringValue promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getPluralStringValue failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a singular-plural string by the specified number based on the specified resource name. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                           |
| -------- | --------------------------- | ---- | ----------------------------- |
| resName  | string                      | Yes   | Resource name.                         |
| num      | number                      | Yes   | Number.                          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the singular-plural string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringByName("test", 1, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getPluralStringByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringByName<sup>9+</sup>

getPluralStringByName(resName: string, num: number): Promise&lt;string&gt;

Obtains a singular-plural string by the specified number based on the specified resource name. This API uses a promise to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| num     | number | Yes   | Number. |

**Return value**

| Type                   | Description                    |
| --------------------- | ---------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the singular-plural string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getPluralStringByName("test", 1).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getPluralStringByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getPluralStringByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentSync<sup>10+</sup>

getMediaContentSync(resId: number, density?: number): Uint8Array

Obtains the content of a media file with the default or specified screen density based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| -------- | ----------- |
| Uint8Array   | Content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentSync<sup>10+</sup>

getMediaContentSync(resource: Resource, density?: number): Uint8Array

Obtains the content of a media file with the default or specified screen density based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Uint8Array | Content of the media file corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentSync(resource); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentSync(resource, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByNameSync<sup>10+</sup>

getMediaByNameSync(resName: string, density?: number): Uint8Array

Obtains the content of a media file with the default or specified screen density based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Uint8Array | Content of the media file corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByNameSync("test"); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaByNameSync("test", 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.              | 
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>10+</sup>

getMediaContent(resId: number, density: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file with the specified screen density based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, 120, (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resId: number): Promise&lt;Uint8Array&gt;

Obtains the content of a media file based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id).then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaContent promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>10+</sup>

getMediaContent(resId: number, density: number): Promise&lt;Uint8Array&gt;

Obtains the content of a media file with the specified screen density based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, 120).then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaContent failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resource: Resource, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | Yes   | Resource object.              |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>10+</sup>

getMediaContent(resource: Resource, density: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file with the specified screen density based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | Yes   | Resource object.              |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, 120, (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resource: Resource): Promise&lt;Uint8Array&gt;

Obtains the content of a media file based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                       | Description                 |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource).then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaContent promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>10+</sup>

getMediaContent(resource: Resource, density: number): Promise&lt;Uint8Array&gt;

Obtains the content of a media file with the specified screen density based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                       | Description                 |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, 120).then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaContent failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.              |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**
For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByName("test", (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByName<sup>10+</sup>

getMediaByName(resName: string, density: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file with the specified screen density based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.              |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByName("test", 120, (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error(`callback getMediaByName failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string): Promise&lt;Uint8Array&gt;

Obtains the content of a media file based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                       | Description           |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByName("test").then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByName<sup>10+</sup>

getMediaByName(resName: string, density: number): Promise&lt;Uint8Array&gt;

Obtains the content of a media file with the specified screen density based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                       | Description           |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByName("test", 120).then((value: Uint8Array) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64Sync<sup>10+</sup>

getMediaContentBase64Sync(resId: number, density?: number): string

Obtains the Base64 code of an image with the default or specified screen density based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| -------- | ----------- |
| string   | Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64Sync<sup>10+</sup>

getMediaContentBase64Sync(resource: Resource, density?: number): string

Obtains the Base64 code of an image with the default or specified screen density based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| string | Base64 code of the image corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64Sync(resource); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentBase64Sync(resource, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByNameSync<sup>10+</sup>

getMediaBase64ByNameSync(resName: string, density?: number): string

Obtains the Base64 code of an image with the default or specified screen density based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resName | string | Yes   | Resource name.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| string | Base64 code of the image corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByNameSync("test"); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaBase64ByNameSync("test", 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resId: number, density: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image with the specified screen density based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, 120, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number): Promise&lt;string&gt;

Obtains the Base64 code of an image based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id).then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaContentBase64 promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resId: number, density: number): Promise&lt;string&gt;

Obtains the Base64 code of an image with the specified screen density based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, 120).then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resource: Resource, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                    |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resource: Resource, density: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image with the specified screen density based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                    |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, 120, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resource: Resource): Promise&lt;string&gt;

Obtains the Base64 code of an image based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource).then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaContentBase64 promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resource: Resource, density: number): Promise&lt;string&gt;

Obtains the Base64 code of an image with the specified screen density based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, 120).then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                    |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByName("test", (error: BusinessError, value: string) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByName<sup>10+</sup>

getMediaBase64ByName(resName: string, density: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image with the specified screen density based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                    |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByName("test", 120, (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getMediaBase64ByName failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let media = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string): Promise&lt;string&gt;

Obtains the Base64 code of an image based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByName("test").then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error("getMediaBase64ByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByName<sup>10+</sup>

getMediaBase64ByName(resName: string, density: number): Promise&lt;string&gt;

Obtains the Base64 code of an image with the specified screen density based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByName("test", 120).then((value: string) => {
      let media = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getMediaBase64ByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptor<sup>10+</sup>

getDrawableDescriptor(resId: number, density?: number, type?: number): DrawableDescriptor

Obtains a **DrawableDescriptor** object for icon display based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|
| type<sup>11+</sup> | number | No   | Resource type. The value **1** indicates the layered icon resource of the application in the theme resource package, and the value **0** or the default value indicates the icon resource of the application.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | **DrawableDescriptor** object corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptor<sup>10+</sup>

getDrawableDescriptor(resource: Resource, density?: number, type?: number): DrawableDescriptor

Obtains a **DrawableDescriptor** object for icon display based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|
| type<sup>11+</sup> | number | No   | Resource type. The value **1** indicates the layered icon resource of the application in the theme resource package, and the value **0** or the default value indicates the icon resource of the application.|

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | **DrawableDescriptor** object corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.icon').id
  };
  try {
    this.context.resourceManager.getDrawableDescriptor(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptor(resource, 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptor(resource, 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptorByName<sup>10+</sup>

getDrawableDescriptorByName(resName: string, density?: number, type?: number): DrawableDescriptor

Obtains a **DrawableDescriptor** object for icon display based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|
| type<sup>11+</sup> | number | No   | Resource type. The value **1** indicates the layered icon resource of the application in the theme resource package, and the value **0** or the default value indicates the icon resource of the application.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | **DrawableDescriptor** object corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getDrawableDescriptorByName('icon');
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptorByName('icon', 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    this.context.resourceManager.getDrawableDescriptorByName('icon', 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBoolean<sup>9+</sup>

getBoolean(resId: number): boolean

Obtains a Boolean result based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Boolean result corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getBoolean<sup>9+</sup>

getBoolean(resource: Resource): boolean

Obtains a Boolean result based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type     | Description               |
| ------- | ----------------- |
| boolean | Boolean result corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.boolean.boolean_test').id
  };
  try {
    this.context.resourceManager.getBoolean(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBooleanByName<sup>9+</sup>

getBooleanByName(resName: string): boolean

Obtains a Boolean result based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Boolean result corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getBooleanByName("boolean_test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBooleanByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resId: number): number

Obtains an integer or float value based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description        |
| ------ | ---------- | 
| number | Integer or float value corresponding to the specified resource ID. An integer indicates the original value, and a float number indicates the actual pixel value. For details, see the sample code.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getNumber($r('app.integer.integer_test').id); // integer refers to the original value.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getNumber($r('app.float.float_test').id); // float refers to the actual pixel value.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resource: Resource): number

Obtains an integer or float value based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> If this API is used to obtain the float value whose unit is vp, the value obtained through **resId** is different from that obtained through **resource**. In this case, the value obtained through **resId** is correct. This issue will be rectified in future versions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description             |
| ------ | --------------- |
| number | Integer or float value corresponding to the specified resource name.<br>An integer indicates the original value, and a float number without a unit indicates the original value and a float number with the unit of vp or fp indicates the px value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.integer.integer_test').id
  };
  try {
    this.context.resourceManager.getNumber(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

Obtains an integer or float value based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Integer or float value corresponding to the specified resource name.<br>An integer indicates the original value, and a float number without a unit indicates the original value and a float number with the unit of vp or fp indicates the px value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getNumberByName("integer_test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getNumberByName("float_test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resId: number) : number;

Obtains a color value based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Color value (decimal) corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColorSync($r('app.color.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resource: Resource): number

Obtains a color value based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description              |
| ------ | ---------------- |
| number | Color value (decimal) corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  try {
    this.context.resourceManager.getColorSync(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorByNameSync<sup>10+</sup>

getColorByNameSync(resName: string) : number;

Obtains a color value based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| number | Color value (decimal) corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColorByNameSync("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resId: number, callback: AsyncCallback&lt;number&gt;): void;

Obtains a color value based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result, which is the color value (decimal) corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**Example (stage)**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColor($r('app.color.test').id, (error: BusinessError, value: number) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getColor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resId: number): Promise&lt;number&gt;

Obtains a color value based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the color value (decimal) corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColor($r('app.color.test').id).then((value: number) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getColor promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getColor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resource: Resource, callback: AsyncCallback&lt;number&gt;): void;

Obtains a color value based on the specified resource object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | Yes   | Resource object.           |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result, which is the color value (decimal) corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  try {
    this.context.resourceManager.getColor(resource, (error: BusinessError, value: number) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getColor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resource: Resource): Promise&lt;number&gt;;

Obtains a color value based on the specified resource object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type                   | Description              |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the color value (decimal) corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  try {
    this.context.resourceManager.getColor(resource).then((value: number) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error("getColor promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getColor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorByName<sup>10+</sup>

getColorByName(resName: string, callback: AsyncCallback&lt;number&gt;): void

Obtains a color value based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | Yes   | Resource name.           |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result, which is the color value (decimal) corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColorByName("test", (error: BusinessError, value: number) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let string = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getColorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorByName<sup>10+</sup>

getColorByName(resName: string): Promise&lt;number&gt;

Obtains a color value based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the color value (decimal) corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getColorByName("test").then((value: number) => {
      let string = value;
    }).catch((error: BusinessError) => {
      console.error("getColorByName promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getColorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileContentSync<sup>10+</sup>

getRawFileContentSync(path: string): Uint8Array

Obtains the content of the raw file in the **resources/rawfile** directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Uint8Array | Content of the raw file.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getRawFileContentSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileContent<sup>9+</sup>

getRawFileContent(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the raw file.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getRawFileContent("test.txt", (error: BusinessError, value: Uint8Array) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let rawFile = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getRawFileContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileContent<sup>9+</sup>

getRawFileContent(path: string): Promise&lt;Uint8Array&gt;

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the raw file.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getRawFileContent("test.txt").then((value: Uint8Array) => {
      let rawFile = value;
    }).catch((error: BusinessError) => {
      console.error("getRawFileContent promise error is " + error);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getRawFileContent failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileListSync<sup>10+</sup>

getRawFileListSync(path: string): Array\<string>

Obtains the list of folders and files in the **resources/rawfile** directory. This API returns the result synchronously.

>**NOTE**
>
> If there is no folder or file in the directory, no information is returned. If there are folders and files in the directory, the list of folders and files is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | **rawfile** directory.            |

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Array\<string> | List of folders and files in the **rawfile** directory.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // Passing "" means to obtain the list of files in the root directory of the raw file.
    this.context.resourceManager.getRawFileListSync("")
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileListSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string, callback: AsyncCallback&lt;Array\<string\>&gt;): void;

Obtains the list of folders and files in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> If there is no folder or file in the directory, no information is returned. If there are folders and files in the directory, the list of folders and files is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | **rawfile** directory.            |
| callback | AsyncCallback&lt;Array\<string\>&gt; | Yes| Callback used to return the result, which is the list of folders and files in the **rawfile** directory.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // Passing "" means to obtain the list of files in the root directory of the raw file.
    this.context.resourceManager.getRawFileList("", (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error(`callback getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        let rawFile = value;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getRawFileList failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string): Promise&lt;Array\<string\>&gt;

Obtains the list of folders and files in the **resources/rawfile** directory. This API uses a promise to return the result.

>**NOTE**
>
> If there is no folder or file in the directory, no information is returned. If there are folders and files in the directory, the list of folders and files is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | **rawfile** directory.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Array\<string\>&gt; | Promise used to return the result, which is the list of folders and files in the **rawfile** directory.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // Passing "" means to obtain the list of files in the root directory of the raw file.
    this.context.resourceManager.getRawFileList("").then((value: Array<string>) => {
      let rawFile = value;
    }).catch((error: BusinessError) => {
      console.error(`promise getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getRawFileList failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFdSync<sup>10+</sup>

getRawFdSync(path: string): RawFileDescriptor

Obtains the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                    |

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| [RawFileDescriptor](#rawfiledescriptor8) | Descriptor of the HAP where the raw file is located.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getRawFdSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFdSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFd<sup>9+</sup>

getRawFd(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                     |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Yes   | Callback used to return the result, which is the descriptor of the HAP where the raw file is located.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getRawFd("test.txt", (error: BusinessError, value: resourceManager.RawFileDescriptor) => {
      if (error != null) {
        console.error(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);
      } else {
        let fd = value.fd;
        let offset = value.offset;
        let length = value.length;
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback getRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFd<sup>9+</sup>

getRawFd(path: string): Promise&lt;RawFileDescriptor&gt;

Obtains the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Descriptor of the HAP where the raw file is located.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getRawFd("test.txt").then((value: resourceManager.RawFileDescriptor) => {
      let fd = value.fd;
      let offset = value.offset;
      let length = value.length;
    }).catch((error: BusinessError) => {
      console.error(`promise getRawFd error error code: ${error.code}, message: ${error.message}.`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise getRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### closeRawFdSync<sup>10+</sup>

closeRawFdSync(path: string): void

Closes the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | The resource not found by path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.closeRawFdSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`closeRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### closeRawFd<sup>9+</sup>

closeRawFd(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.       |

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | The resource not found by path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.closeRawFd("test.txt", (error: BusinessError) => {
      if (error != null) {
        console.error("error is " + error);
      }
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`callback closeRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### closeRawFd<sup>9+</sup>

closeRawFd(path: string): Promise&lt;void&gt;

Closes the descriptor of the HAP where the raw file is located in the **resources/rawfile** directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                 | Description  |
| ------------------- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.closeRawFd("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise closeRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getConfigurationSync<sup>10+</sup>

getConfigurationSync(): Configuration

Obtains the device configuration. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description              |
| ---------------------------------------- | ---------------- |
| [Configuration](#configuration) | Device configuration.|

**Example**
  ```ts
  try {
    let value = this.context.resourceManager.getConfigurationSync();
    let direction = value.direction;
    let locale = value.locale;
  } catch (error) {
    console.error("getConfigurationSync error is " + error);
  }
  ```

### getConfiguration

getConfiguration(callback: AsyncCallback&lt;Configuration&gt;): void

Obtains the device configuration. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                       |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | Yes   | Callback used to return the result, which is the device configuration.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getConfiguration((error: BusinessError, value: resourceManager.Configuration) => {
      if (error != null) {
        console.error("getConfiguration callback error is " + error);
      } else {
        let direction = value.direction;
        let locale = value.locale;
      }
    });
  } catch (error) {
    console.error("getConfiguration callback error is " + error);
  }
  ```

### getConfiguration

getConfiguration(): Promise&lt;Configuration&gt;

Obtains the device configuration. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description              |
| ---------------------------------------- | ---------------- |
| Promise&lt;[Configuration](#configuration)&gt; | Promise used to return the result, which is the device configuration.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getConfiguration().then((value: resourceManager.Configuration) => {
      let direction = value.direction;
      let locale = value.locale;
    }).catch((error: BusinessError) => {
      console.error("getConfiguration promise error is " + error);
    });
  } catch (error) {
    console.error("getConfiguration promise error is " + error);
  }
  ```

### getDeviceCapabilitySync<sup>10+</sup>

getDeviceCapabilitySync(): DeviceCapability

Obtains the device capability. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| [DeviceCapability](#devicecapability) | Device capability.|

**Example**
  ```ts
  try {
    let value = this.context.resourceManager.getDeviceCapabilitySync();
    let screenDensity = value.screenDensity;
    let deviceType = value.deviceType;
  } catch (error) {
    console.error("getDeviceCapabilitySync error is " + error);
  }
  ```

### getDeviceCapability

getDeviceCapability(callback: AsyncCallback&lt;DeviceCapability&gt;): void

Obtains the device capability. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                          |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | Yes   | Callback used to return the result, which is the device capability.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getDeviceCapability((error: BusinessError, value: resourceManager.DeviceCapability) => {
      if (error != null) {
        console.error("getDeviceCapability callback error is " + error);
      } else {
        let screenDensity = value.screenDensity;
        let deviceType = value.deviceType;
      }
    });
  } catch (error) {
    console.error("getDeviceCapability callback error is " + error);
  }
  ```

### getDeviceCapability

getDeviceCapability(): Promise&lt;DeviceCapability&gt;

Obtains the device capability. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | Promise used to return the result, which is the device capability.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    this.context.resourceManager.getDeviceCapability().then((value: resourceManager.DeviceCapability) => {
      let screenDensity = value.screenDensity;
      let deviceType = value.deviceType;
    }).catch((error: BusinessError) => {
      console.error("getDeviceCapability promise error is " + error);
    });
  } catch (error) {
    console.error("getDeviceCapability promise error is " + error);
  }
  ```

### addResource<sup>10+</sup>

addResource(path: string) : void

Loads resources from the specified path.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| path | string | Yes   | Resource path.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let path = getContext().bundleCodeDir + "/library1-default-signed.hsp";
  try {
    this.context.resourceManager.addResource(path);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`addResource failed, error code: ${code}, message: ${message}.`);
  }
  ```

### removeResource<sup>10+</sup>

removeResource(path: string) : void

Removes the resources loaded from the specified path to restore the original resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type           | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| path | string | Yes   | Resource path.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let path = getContext().bundleCodeDir + "/library1-default-signed.hsp";
  try {
    this.context.resourceManager.removeResource(path);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`removeResource failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getLocales<sup>11+</sup>

getLocales(includeSystem?: boolean): Array\<string>

Obtains the language list of an application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name        | Type   | Mandatory  | Description      |
| -------------- | ------- | ------ | -------------------- |
| includeSystem  | boolean |  No   | Whether system resources are included. The default value is **false**.<br> **false**: Only application resources are included.<br>**true**: Both system and application resources are included.<br>If the value of **includeSystem** is invalid, the language list of system resources will be returned.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Array\<string> | Language list. The strings in the list are comprised of the language, script (optional), and region (optional), which are connected by a hyphen (-).|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getLocales(); // Obtain only the language list of application resources.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }

  try {
    resourceManager.getSystemResourceManager().getLocales(); // Obtain only the language list of system resources.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getLocales(true); // Obtain the language list of application resources and resources.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbol<sup>11+</sup>

getSymbol(resId: number):number

Obtains a symbol value based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Symbol value (decimal) corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getSymbol($r('app.symbol.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbol<sup>11+</sup>
getSymbol(resource: Resource): number

Obtains a symbol value based on the specified resource object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Symbol value (decimal) corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.symbol.test').id
  };
  try {
    this.context.resourceManager.getSymbol(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbolByName<sup>11+</sup>

getSymbolByName(resName: string) : number;

Obtains a symbol value based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| number | Symbol value (decimal) corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getSymbolByName("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbolByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### isRawDir<sup>12+</sup>

isRawDir(path: string) : bool

Checks whether a path is a subdirectory in the **rawfile** directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| path | string | Yes   | Path of a rawfile.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| bool |Whether the path is a subdirectory in the **rawfile** directory.<br>**true**: The path is a subdirectory in the **rawfile** directory.<br>**false**: The path is not a subdirectory in the **rawfile** directory.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.isRawDir("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`isRawDir failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getOverrideResourceManager<sup>12+</sup>

getOverrideResourceManager(configuration?: Configuration) : ResourceManager

Obtains a **ResourceManager** object for loading differentiated resources. This API returns the result synchronously.

The style (including the language, color mode, resolution, and orientation) of the resources obtained by a common **ResourceManager** object is determined by the system. With this API, an application can obtain the style of differentiated resources, for example, dark color resources in light color mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name       | Type                           | Mandatory| Description                                                        |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | No  | Configuration of differentiated resources.<br>After obtaining the configuration of differentiated resources through [getOverrideConfiguration](#getoverrideconfiguration12), modify the configuration items as required, and then pass these items as input parameters to the API.<br>If this parameter is not specified, the system obtains resources that best match the current system.|

**Return value**

| Type           | Description                              |
| --------------- | ---------------------------------- |
| ResourceManager | **ResourceManager** object for loading differentiated resources.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    let resMgr = this.context.resourceManager
    let overrideConfig = resMgr.getOverrideConfiguration()
    overrideConfig.colorMode = resourceManager.ColorMode.DARK
    let overrideResMgr = resMgr.getOverrideResourceManager(overrideConfig)
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getOverrideResourceManager failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getOverrideConfiguration<sup>12+</sup>

getOverrideConfiguration() : Configuration

Obtains the configuration of differentiated resources. This API returns the result synchronously. This API allows a common **ResourceManager** object and a **ResourceManager** object obtained through [getOverrideResourceManager](#getoverrideresourcemanager12) to obtain the configuration of differentiated resources.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                           | Description            |
| ------------------------------- | ---------------- |
| [Configuration](#configuration) | Configuration of differentiated resources.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  let overrideConfig = this.context.resourceManager.getOverrideConfiguration()
  ```

### updateOverrideConfiguration<sup>12+</sup>

updateOverrideConfiguration(configuration: Configuration) : void

Updated configuration of differentiated resources. This API allows a common **ResourceManager** object and a **ResourceManager** object obtained through [getOverrideResourceManager](#getoverrideresourcemanager12) to update the configuration of differentiated resources.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name       | Type                           | Mandatory| Description                                                        |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | Yes  | Configuration of differentiated resources. After obtaining the configuration of differentiated resources through [getOverrideConfiguration](#getoverrideconfiguration12), modify the configuration items as required, and then pass these items as input parameters to the API.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  try {
    let resMgr = this.context.resourceManager
    let overrideConfig = resMgr.getOverrideConfiguration()
    overrideConfig.colorMode = resourceManager.ColorMode.DARK
    let overrideResMgr = resMgr.updateOverrideConfiguration(overrideConfig)
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`updateOverrideConfiguration failed, error code: ${code}, message: ${message}.`);
  }
  ```

### release<sup>(deprecated)</sup>

release()

Releases a **ResourceManager** object. This API is not supported currently.

This API is supported since API version 7 and is deprecated since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Example**
  ```ts
  try {
    this.context.resourceManager.release();
  } catch (error) {
    console.error("release error is " + error);
  }
  ```

### getString<sup>(deprecated)</sup>

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the string corresponding to the specified resource ID.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id, (error: Error, value: string) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let str = value;
          }
      });
  });
  ```


### getString<sup>(deprecated)</sup>

getString(resId: number): Promise&lt;string&gt;

Obtains a string based on the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the string corresponding to the specified resource ID.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id).then((value: string) => {
          let str = value;
      }).catch((error: BusinessError) => {
          console.error("getstring promise error is " + error);
      });
  });
  ```


### getStringArray<sup>(deprecated)</sup>

getStringArray(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the result, which is the string array corresponding to the specified resource ID.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getStringArray($r('app.strarray.test').id, (error: Error, value: Array<string>) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let strArray = value;
          }
      });
  });
  ```


### getStringArray<sup>(deprecated)</sup>

getStringArray(resId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains a string array based on the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                                | Description           |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result, which is the string array corresponding to the specified resource ID.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
       mgr.getStringArray($r('app.strarray.test').id).then((value: Array<string>) => {
          let strArray = value;
      }).catch((error: BusinessError) => {
          console.error("getStringArray promise error is " + error);
      });
  });
  ```


### getMedia<sup>(deprecated)</sup>

getMedia(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a media file based on the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id, (error: Error, value: Uint8Array) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let media = value;
          }
      });
  });
  ```

### getMedia<sup>(deprecated)</sup>

getMedia(resId: number): Promise&lt;Uint8Array&gt;

Obtains the content of a media file based on the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the media file corresponding to the specified resource ID.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id).then((value: Uint8Array) => {
          let media = value;
      }).catch((error: BusinessError) => {
          console.error("getMedia promise error is " + error);
      });
  });
  ```


### getMediaBase64<sup>(deprecated)</sup>

getMediaBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the Base64 code of an image based on the specified resource ID. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id, ((error: Error, value: string) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let media = value;
          }
      });
  });
  ```


### getMediaBase64<sup>(deprecated)</sup>

getMediaBase64(resId: number): Promise&lt;string&gt;

Obtains the Base64 code of an image based on the specified resource ID. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the Base64 code of the image corresponding to the specified resource ID.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id).then((value: string) => {
          let media = value;
      }).catch((error: BusinessError) => {
          console.error("getMediaBase64 promise error is " + error);
      });
  });
  ```


### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number): Promise&lt;string&gt;

Obtains a singular-plural string by the specified number based on the specified resource ID. This API uses a promise to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

This API is deprecated since API version 9. You are advised to use [getPluralStringValue](#getpluralstringvalue9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Number.  |

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the result, which is the singular-plural string corresponding to the specified resource ID.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1).then((value: string) => {
          let str = value;
      }).catch((error: BusinessError) => {
          console.error("getPluralString promise error is " + error);
      });
  });
  ```


### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number, callback: AsyncCallback&lt;string&gt;): void

Obtains a singular-plural string by the specified number based on the specified resource ID. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> Singular and plural forms are available for English, but not Chinese.

This API is deprecated since API version 9. You are advised to use [getPluralStringValue](#getpluralstringvalue9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Number.                            |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result, which is the singular-plural string corresponding to the specified resource ID.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1, (error: Error, value: string) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let str = value;
          }
      });
  });
  ```


### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the raw file.            |
| callback | AsyncCallback&lt;Uint8Array&gt; | Yes   | Callback used to return the result, which is the content of the raw file.|

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.txt", (error: Error, value: Uint8Array) => {
          if (error != null) {
              console.error("error is " + error);
          } else {
              let rawFile = value;
          }
      });
  });
  ```


### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string): Promise&lt;Uint8Array&gt;

Obtains the content of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result, which is the content of the raw file.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.txt").then((value: Uint8Array) => {
          let rawFile = value;
      }).catch((error: BusinessError) => {
          console.error("getRawFile promise error is " + error);
      });
  });
  ```


### getRawFileDescriptor<sup>(deprecated)</sup>

getRawFileDescriptor(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the raw file.                     |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Yes   | Callback used to return the result, which is the descriptor of the raw file.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.txt", (error: Error, value: resourceManager.RawFileDescriptor) => {
          if (error != null) {
              console.error("error is " + error);
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

This API is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the raw file.|

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | Promise used to return the result, which is the descriptor of the raw file.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.txt").then((value: resourceManager.RawFileDescriptor) => {
          let fd = value.fd;
          let offset = value.offset;
          let length = value.length;
      }).catch((error: BusinessError) => {
          console.error("getRawFileDescriptor promise error is " + error);
      });
  });
  ```

### closeRawFileDescriptor<sup>(deprecated)</sup>

closeRawFileDescriptor(path: string, callback: AsyncCallback&lt;void&gt;): void

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [closeRawFd](#closerawfd9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**



| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the raw file.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.       |

**Example**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt", (error: Error) => {
          if (error != null) {
              console.error("error is " + error);
          }
      });
  });
  ```

### closeRawFileDescriptor<sup>(deprecated)</sup>

closeRawFileDescriptor(path: string): Promise&lt;void&gt;

Closes the descriptor of the raw file in the **resources/rawfile** directory. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [closeRawFd](#closerawfd9-1).

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
      mgr.closeRawFileDescriptor("test.txt");
  });
  ```

### Appendix

- Content of the **app.string.test** file:

    ```json
    {
    "string": [
        {
        "name": "test",
        "value": "10"
        }
    ]
    }
    ```

    ```json
    {
    "string": [
     {
        "name": "test",
        "value": "%s %d %f"
        }
    ]
    }
    ```

- Content of the **app.strarray.test** file:

    ```json
    {
    "strarray": [
        {
        "name": "test",
        "value": [
    ```  

- Content of the **app.plural.test** file:
    ```json
    {
      "plural": [
        {
        "name": "test",
        "value": [
            {
            "quantity": "one",
            "value": "%d apple"
            },
            {
            "quantity": "other",
            "value": "%d apples"
            }
        ]
        }
    ]
    }
    ``` 

- Content of the **app.boolean.boolean_test** file:
    ```json
    {
    "boolean": [
        {
        "name": "boolean_test",
        "value": true
        }
    
    }
    ``` 

- Content of the **integer_test** and **float_test** files:
    ```json
    {
      "integer": [
        {
          "name": "integer_test",
          "value": 100
        }
      ]
    }
    ``` 

    ```json
    {
      "float": [
        {
          "name": "float_test",
          "value": "30.6"
        }
      ]
    }
    ``` 
- Content of the **app.color.test** file:
    ```json
    {
      "color": [
        {
          "name": "test",
          "value": "#FFFFFF"
       }
      ]
    }
    ``` 

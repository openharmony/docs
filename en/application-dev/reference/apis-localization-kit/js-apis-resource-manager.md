# @ohos.resourceManager (Resource Management)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

The **resourceManager** module provides the resource management functionality. It allows an application to obtain the best matched application resources or system resources based on the specified [configuration](#configuration). For details about the matching rules, see [Matching Resources](../../quick-start/resource-categories-and-access.md#matching-resources).

The configuration includes language, region, screen orientation, mobile country code (MCC), mobile network code (MNC), device capability, and density.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { resourceManager } from '@kit.LocalizationKit';
```

## How to Use

Since API version 9, the stage model allows an application to obtain a **ResourceManager** object via **Context**. You do not need to import the module.
In the FA model, you need to import the module and then call [getResourceManager](#resourcemanagergetresourcemanager) to obtain a **ResourceManager** object.
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
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Callback used to return the **ResourceManager** object.|

**Example**

  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager((error, mgr) => {
    if (error != null) {
      console.error("error is " + error);
      return;
    }
    // Replace 'app.string.test' with the actual resource.
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
| bundleName | string                                   | Yes   | Bundle name of the application.                |
| callback   | [AsyncCallback](#asynccallbackdeprecated)&lt;[ResourceManager](#resourcemanager)&gt; | Yes   | Callback used to return the **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "com.example.myapplication" with the actual package name.
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
    if (error != null) {
      console.error("error is " + error);
      return;
    }
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
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager().then((mgr: resourceManager.ResourceManager) => {
    // Replace 'app.string.test' with the actual resource.
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
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise used to return the **ResourceManager** object.|

**Example**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "com.example.myapplication" with the actual package name.
  resourceManager.getResourceManager("com.example.myapplication").then((mgr: resourceManager.ResourceManager) => {
  }).catch((error: BusinessError) => {
    console.error("error is " + error);
  });
  ```

## resourceManager.getSysResourceManager<sup>20+</sup>

getSysResourceManager(): ResourceManager

Obtains a **ResourceManager** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| [ResourceManager](#resourcemanager) | **ResourceManager** object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001009  | Failed to access the system resource. which is not mapped to application sandbox, This error code will be thrown. |

**Example**
  ```js
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let systemResourceManager = resourceManager.getSysResourceManager();
    // Replace 'sys.string.ohos_lab_vibrate' with the actual resource.
    systemResourceManager.getStringValue($r('sys.string.ohos_lab_vibrate').id).then((value: string) => {
      let str = value;
    }).catch((error: BusinessError) => {
      console.error(`systemResourceManager getStringValue promise error: ${error}`);
    });
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSysResourceManager failed, error code: ${code}, message: ${message}.`);
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
| DEVICE_TYPE_CAR      | 0x02 | Head unit  |
| DEVICE_TYPE_TV       | 0x04 | Smart TV |
| DEVICE_TYPE_WEARABLE | 0x06 | Wearable  |
| DEVICE_TYPE_2IN1<sup>11+</sup>     | 0x07 | PC/2-in-1 device  |
<!--RP1End-->

## ScreenDensity

Enumerates the screen density types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name            | Value | Description        |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | Small-scale DPI. |
| SCREEN_MDPI    | 160  | Medium-scale DPI.  |
| SCREEN_LDPI    | 240  | Large-scale DPI.  |
| SCREEN_XLDPI   | 320  | Extra-large-scale DPI.  |
| SCREEN_XXLDPI  | 480  | Extra-extra-large-scale DPI.  |
| SCREEN_XXXLDPI | 640  | Extra-extra-extra-large-scale DPI.|


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

| Name                       | Type                           | Read-Only| Optional| Description              |
| --------------------------- | ------------------------------- | ---- | ---- | ------------------ |
| direction                   | [Direction](#direction)         | No  | No  | Screen orientation modes.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| locale                      | string                          | No  | No  | Language locale.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| deviceType<sup>12+</sup>    | [DeviceType](#devicetype)       | No  | No  | Device type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| screenDensity<sup>12+</sup> | [ScreenDensity](#screendensity) | No  | No  | Screen density<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| colorMode<sup>12+</sup>     | [ColorMode](#colormode12)       | No  | No  | Color mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.       |
| mcc<sup>12+</sup>           | number                          | No  | No  | Mobile country code (MCC).<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| mnc<sup>12+</sup>           | number                          | No  | No  | Mobile network code (MNC).<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |



## DeviceCapability

Defines the device capability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name           | Type                           | Read-Only  | Optional  | Description      |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | No   | No   | Screen density of the device.|
| deviceType    | [DeviceType](#devicetype)       | No   | No   | Device type.  |


## RawFileDescriptor<sup>9+</sup>

type RawFileDescriptor = _RawFileDescriptor

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Type   | Description  |
| ------  | ---- | 
|[_RawFileDescriptor](js-apis-rawFileDescriptor.md#rawfiledescriptor-1)|File descriptor (fd) of the HAP where the rawfile is located.|

## Resource<sup>9+</sup>

type Resource = _Resource

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Type   | Description  |
| ------  | ---- | 
|[_Resource](js-apis-resource.md#resource-1)|Resource information, including the resource ID, application package name, and module name. Generally, you can use **$r** to obtain the resource information.|

## ResourceManager

Provides APIs for accessing application resources and system resources.

> **NOTE**
>
> - The methods involved in **ResourceManager** are applicable only to the TypeScript-based declarative development paradigm.
>
> - Resource files are defined in the **resources** directory of the project. You can obtain resource values such as strings, string arrays, and colors based on the specified **resName**, **resId**, or **Resource** object. **resName** indicates the resource name, **resId** indicates the resource ID, which can be obtained through `$r(*resource-address*).id`, for example, `$r('app.string.test').id`.
>
> - No matter whether resources are in the same HAP or different HAPs or HSPs, you are advised to use the API with **resName** or **resId** specified. Using the **Resource** object will take a longer time. If the resources are in different HAPs or HSPs, you first need to use [createModuleContext](../apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12) to create the context of the corresponding module and then call the API with **resName** or **resId** specified. For details, see [Accessing Resources](../../quick-start/resource-categories-and-access.md#accessing-resources).
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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace 'app.string.test' with the actual resource.
    let testStr = this.context.resourceManager.getStringSync($r('app.string.test').id);
    console.log(`getStringSync, result: ${testStr}`);
    // Print the output result: getStringSync, result: I'm a test string resource.
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
| ...args | Array<string \| number> | No| Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a %1$s, format int: %2$d, format float: %3$f."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace 'app.string.test' with the actual resource.
    let testStr = this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 10, 98.78);
    console.log(`getStringSync, result: ${testStr}`);
    // Print the output result: getStringSync, result: I'm a format string, format int: 10, format float: 98.78.
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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    let testStr = this.context.resourceManager.getStringByNameSync("test");
    console.log(`getStringByNameSync, result: ${testStr}`);
    // Print the output result: getStringByNameSync, result: I'm a test string resource.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByNameSync<sup>10+</sup>

getStringByNameSync(resName: string, ...args: Array<string | number>): string

Obtains a string based on the specified resource ame and formats the string based on **args**. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|
| ...args | Array<string \| number> | No   | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a %1$s, format int: %2$d, format float: %3$f."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    let testStr = this.context.resourceManager.getStringByNameSync("test", "format string", 10, 98.78);
    console.log(`getStringByNameSync, result: ${testStr}`);
    // Print the output result: getStringByNameSync, result: I'm a format string, format int: 10, format float: 98.78.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringValue<sup>9+</sup>

getStringValue(resId: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the obtained string.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**Example (stage)**
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.string.test' with the actual resource.
  this.context.resourceManager.getStringValue($r('app.string.test').id, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringValue, result: ${value}`);
      // Print the output result: getStringValue, result: I'm a test string resource.
    }
  });
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
| Promise&lt;string&gt; | Promise used to return the obtained string.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.string.test' with the actual resource.
  this.context.resourceManager.getStringValue($r('app.string.test').id).then((value: string) => {
    console.log(`getStringValue, result: ${value}`);
    // Print the output result: getStringValue, result: I'm a test string resource.
  }).catch((error: BusinessError) => {
    console.error(`promise getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
  });
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string, callback: _AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | Yes   | Resource name.           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   |Callback used to return the result, which is the string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getStringByName("test", (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringByName, result: ${value}`);
      // Print the output result: getStringByName, result: I'm a test string resource.
    }
  });
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
| Promise&lt;string&gt; | Promise used to return the obtained string.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getStringByName("test").then((value: string) => {
    console.log(`getStringByName, result: ${value}`);
    // Print the output result: getStringByName, result: I'm a test string resource.
  }).catch((error: BusinessError) => {
    console.error(`promise getStringByName failed, error code: ${error.code}, message: ${error.message}.`);
  });
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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace 'app.strarray.test' with the actual resource.
    let strArray: Array<string> = this.context.resourceManager.getStringArrayValueSync($r('app.strarray.test').id);
    console.log(`getStringArrayValueSync, result: ${strArray[0]}`);
    // Print the output result: getStringArrayValueSync, result: I'm one of the array's values.
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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    let strArray: Array<string> = this.context.resourceManager.getStringArrayByNameSync("test");
    console.log(`getStringArrayByNameSync, result: ${strArray[0]}`);
    // Print the output result: getStringArrayByNameSync, result: I'm one of the array's values.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.strarray.test' with the actual resource.
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id,
    (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error(`callback getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getStringArrayValue, result: ${value[0]}`);
        // Print the output result: getStringArrayValue, result: I'm one of the array's values.
      }
    });
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
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.strarray.test' with the actual resource.
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id)
    .then((value: Array<string>) => {
      console.log(`getStringArrayValue, result: ${value[0]}`);
      // Print the output result: getStringArrayValue, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | Yes   | Resource name.             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getStringArrayByName("test", (error: BusinessError, value: Array<string>) => {
    if (error != null) {
      console.error(`callback getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      let strArray = value;
      console.log(`getStringArrayByName, result: ${value[0]}`);
      // Print the output result: getStringArrayByName, result: I'm one of the array's values.
    }
  });
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
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getStringArrayByName("test")
    .then((value: Array<string>) => {
      console.log(`getStringArrayByName, result: ${value[0]}`);
      // Print the output result: getStringArrayByName, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getIntPluralStringValueSync<sup>18+</sup>

getIntPluralStringValueSync(resId: number, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource ID and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type                   | Mandatory| Description                                                        |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resId   | number                  | Yes  | Resource ID.                                                  |
| num     | number                  | Yes  | Integer number used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| string | Formatted string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    // Replace 'app.plural.format_test' with the actual resource.
    let pluralStr = this.context.resourceManager.getIntPluralStringValueSync($r('app.plural.format_test').id, 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringValueSync, result: ${pluralStr}`);
    // Print the output result: getIntPluralStringValueSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getIntPluralStringByNameSync<sup>18+</sup>

getIntPluralStringByNameSync(resName: string, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource name and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type                   | Mandatory| Description                                                        |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resName | string                  | Yes  | Resource name.                                                  |
| num     | number                  | Yes  | Integer number used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Formatted string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |
| 9001008  | Failed to format the resource obtained based on the resource name. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    // Replace "format_test" with the actual resource.
    let pluralStr = this.context.resourceManager.getIntPluralStringByNameSync("format_test", 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringByNameSync, result: ${pluralStr}`);
    // Print the output result: getIntPluralStringByNameSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringValueSync<sup>18+</sup>

getDoublePluralStringValueSync(resId: number, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource ID and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type                   | Mandatory| Description                                                        |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resId   | number                  | Yes  | Resource ID.                                                  |
| num     | number                  | Yes  | Quantity value (a floating point number), used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | Formatted string corresponding to the specified resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 2.1, the single/plural type is other in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is other is obtained.
    // Replace 'app.plural.format_test' with the actual resource.
    let pluralStr = this.context.resourceManager.getDoublePluralStringValueSync($r('app.plural.format_test').id, 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringValueSync, result: ${pluralStr}`);
    // Print the output result: getDoublePluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringByNameSync<sup>18+</sup>

getDoublePluralStringByNameSync(resName: string, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource name and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type                   | Mandatory| Description                                                        |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resName | string                  | Yes  | Resource name.                                                  |
| num     | number                  | Yes  | Quantity value (a floating point number), used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | Formatted string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |
| 9001008  | Failed to format the resource obtained based on the resource name. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 2.1, the single/plural type is other in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is other is obtained.
    // Replace "format_test" with the actual resource.
    let pluralStr = this.context.resourceManager.getDoublePluralStringByNameSync("format_test", 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringByNameSync, result: ${pluralStr}`);
    // Print the output result: getIntPluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentSync<sup>10+</sup>

getMediaContentSync(resId: number, density?: number): Uint8Array

Obtains the media file content for the default or specified screen density based on the specified resource ID. This API returns the result synchronously.

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
    // Replace 'app.media.test' with the actual resource.
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // Replace 'app.media.test' with the actual resource.
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByNameSync<sup>10+</sup>

getMediaByNameSync(resName: string, density?: number): Uint8Array

Obtains the media file content for the default or specified screen density based on the specified resource name. This API returns the result synchronously.

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
| Uint8Array | Promise used to return the result, which is the content of the media file corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    this.context.resourceManager.getMediaByNameSync("test"); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // Replace "test" with the actual resource.
    this.context.resourceManager.getMediaByNameSync("test", 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resId: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains media file content based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

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
    // Replace 'app.media.test' with the actual resource.
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

getMediaContent(resId: number, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains the media file content for the specified screen density based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| [density](#screendensity)  | number                          | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

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
    // Replace 'app.media.test' with the actual resource.
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

Obtains media file content based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

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
    // Replace 'app.media.test' with the actual resource.
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

Obtains the media file content for the specified screen density based on the specified resource ID. This API uses a promise to return the result.

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
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

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
    // Replace 'app.media.test' with the actual resource.
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

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains media file content based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.              |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

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
    // Replace "test" with the actual resource.
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

getMediaByName(resName: string, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains the media file content for the specified screen density based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | Yes   | Resource name.              |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

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
    // Replace "test" with the actual resource.
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

Obtains media file content based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                       | Description           |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

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
    // Replace "test" with the actual resource.
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

Obtains the media file content for the specified screen density based on the specified resource name. This API uses a promise to return the result.

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
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

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
    // Replace "test" with the actual resource.
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

Obtains an image's Base64 code for the default or specified screen density based on the specified resource ID. This API returns the result synchronously.

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
    // Replace 'app.media.test' with the actual resource.
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // Replace 'app.media.test' with the actual resource.
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id, 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByNameSync<sup>10+</sup>

getMediaBase64ByNameSync(resName: string, density?: number): string

Obtains an image's Base64 code for the default or specified screen density based on the specified resource name. This API returns the result synchronously.

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    this.context.resourceManager.getMediaBase64ByNameSync("test"); // Default screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // Replace "test" with the actual resource.
    this.context.resourceManager.getMediaBase64ByNameSync("test", 120); // Specified screen density
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

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
    // Replace 'app.media.test' with the actual resource.
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

getMediaContentBase64(resId: number, density: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code for the specified screen density based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

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
    // Replace 'app.media.test' with the actual resource.
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

Obtains an image's Base64 code based on the specified resource ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

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
    // Replace 'app.media.test' with the actual resource.
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

Obtains an image's Base64 code for the specified screen density based on the specified resource ID. This API uses a promise to return the result.

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
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

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
    // Replace 'app.media.test' with the actual resource.
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

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

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
    // Replace "test" with the actual resource.
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

getMediaBase64ByName(resName: string, density: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code for the specified screen density based on the specified resource name. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You are advised to use [getMediaBase64ByName](#getmediacontentbase6410) or [getMediaContentBase64](#getmediacontentbase6410). For details, see [ResourceManager](#resourcemanager).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | Yes   | Resource name.                    |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

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
    // Replace "test" with the actual resource.
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

Obtains an image's Base64 code based on the specified resource name. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

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
    // Replace "test" with the actual resource.
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

Obtains an image's Base64 code for the specified screen density based on the specified resource name. This API uses a promise to return the result.

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
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

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
    // Replace "test" with the actual resource.
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
| type<sup>11+</sup> | number | No   | - **1**: Layered icon resource of the application in the theme resource package.<br> - **0** or default value: Icon resource of the application.|

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
  import { DrawableDescriptor } from '@kit.ArkUI';

  try {
    // Replace 'app.media.icon' with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    // Replace 'app.media.icon' with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    // Replace 'app.media.icon' with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 0, 1);
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
| type<sup>11+</sup> | number | No   | - **1**: Layered icon resource of the application in the theme resource package.<br> - **0** or default value: Icon resource of the application.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | **DrawableDescriptor** object.|

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
  import { DrawableDescriptor } from '@kit.ArkUI';

  try {
    // Replace "icon" with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon');
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    // Replace "icon" with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon', 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    // Replace "icon" with the actual resource.
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon', 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBoolean<sup>9+</sup>

getBoolean(resId: number): boolean

Obtains a Boolean value based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Boolean value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/boolean.json
  {
    "boolean": [
      {
        "name": "boolean_test",
        "value": true
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace 'app.boolean.boolean_test' with the actual resource.
    let boolTest = this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);
    console.log(`getBoolean, result: ${boolTest}`);
    // Print the output result: getBoolean, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBooleanByName<sup>9+</sup>

getBooleanByName(resName: string): boolean

Obtains a Boolean value based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type     | Description         |
| ------- | ----------- |
| boolean | Boolean value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/boolean.json
  {
    "boolean": [
      {
        "name": "boolean_test",
        "value": true
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "boolean_test" with the actual resource.
    let boolTest = this.context.resourceManager.getBooleanByName("boolean_test");
    console.log(`getBooleanByName, result: ${boolTest}`);
    // Print the output result: getBooleanByName, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBooleanByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resId: number): number

Obtains an integer or float number based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description        |
| ------ | ---------- | 
| number | Integer or float value corresponding to the specified resource ID.<br>An integer indicates the original value, and a float number without a unit indicates the original value and a float number with the unit of vp or fp indicates the px value. For details, see the sample code.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/integer.json
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
  // Resource file path: src/main/resources/base/element/float.json
  {
    "float": [
      {
        "name": "float_test",
        "value": "30.6vp"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { display } from '@kit.ArkUI';

  try {
    // An integer refers to the original value.
    // Replace 'app.integer.integer_test' with the actual resource.
    let intValue = this.context.resourceManager.getNumber($r('app.integer.integer_test').id);
    console.log(`getNumber, int value: ${intValue}`);
    // Print the output result: getNumber, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // A float number without a unit indicates the original value, and a float number with the unit of vp or fp indicates the px value (float number with the unit of vp or fp = original value x densityPixels).
    // Replace 'app.float.float_test' with the actual resource.
    let floatValue = this.context.resourceManager.getNumber($r('app.float.float_test').id);
    console.log(`getNumber, densityPixels: ${display.getDefaultDisplaySync().densityPixels}, float value: ${floatValue}`);
    // Print the output result: getNumber, densityPixels: 3.25, float value: 99.45000457763672
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```


### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

Obtains an integer or float number based on the specified resource name. This API returns the result synchronously.

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
  ```json
  // Resource file path: src/main/resources/base/element/integer.json
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
  // Resource file path: src/main/resources/base/element/float.json
  {
    "float": [
      {
        "name": "float_test",
        "value": "30.6vp"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { display } from '@kit.ArkUI';

  try {
    // An integer refers to the original value.
    // Replace "integer_test" with the actual resource.
    let intValue = this.context.resourceManager.getNumberByName("integer_test");
    console.log(`getNumberByName, int value: ${intValue}`);
    // Print the output result: getNumberByName, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // A float number without a unit indicates the original value, and a float number with the unit of vp or fp indicates the px value (float number with the unit of vp or fp = original value x densityPixels).
    // Replace "float_test" with the actual resource.
    let floatValue = this.context.resourceManager.getNumberByName("float_test");
    console.log(`getNumberByName, densityPixels: ${display.getDefaultDisplaySync().densityPixels}, float value: ${floatValue}`);
    // Print the output result: getNumberByName, densityPixels: 3.25, float value: 99.45000457763672
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resId: number) : number

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace 'app.color.test' with the actual resource.
    let colorValue = this.context.resourceManager.getColorSync($r('app.color.test').id);
    console.log(`getColorSync, result: ${colorValue}`);
    // Print the output result: getColorSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```


### getColorByNameSync<sup>10+</sup>

getColorByNameSync(resName: string) : number

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Replace "test" with the actual resource.
    let colorValue = this.context.resourceManager.getColorByNameSync("test");
    console.log(`getColorByNameSync, result: ${colorValue}`);
    // Print the output result: getColorByNameSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resId: number, callback: _AsyncCallback&lt;number&gt;): void

Obtains a color value based on the specified resource ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | Yes   | Callback used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**Example (stage)**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.color.test' with the actual resource.
  this.context.resourceManager.getColor($r('app.color.test').id, (error: BusinessError, value: number) => {
    if (error != null) {
      console.error(`callback getColor failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getColor, result: ${value}`);
      // Print the output result: getColor, result: 4294967295
    }
  });
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
| Promise&lt;number&gt; | Promise used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace 'app.color.test' with the actual resource.
  this.context.resourceManager.getColor($r('app.color.test').id)
    .then((value: number) => {
      console.log(`getColor, result: ${value}`);
      // Print the output result: getColor, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColor failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```


### getColorByName<sup>10+</sup>

getColorByName(resName: string, callback: _AsyncCallback&lt;number&gt;): void

Obtains a color value based on the specified resource name. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | Yes   | Resource name.           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | Yes   | Callback used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getColorByName("test", (error: BusinessError, value: number) => {
    if (error != null) {
      console.error(`callback getColorByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getColorByName, result: ${value}`);
      // Print the output result: getColorByName, result: 4294967295
    }
  });
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
| Promise&lt;number&gt; | Promise used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "test" with the actual resource.
  this.context.resourceManager.getColorByName("test")
    .then((value: number) => {
      console.log(`getColorByName, result: ${value}`);
      // Print the output result: getColorByName, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColorByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getRawFileContentSync<sup>10+</sup>

getRawFileContentSync(path: string): Uint8Array

Obtains the content of a rawfile in the **resources/rawfile** directory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the rawfile.            |

**Return value**

| Type                   | Description        |
| --------------------- | ---------- |
| Uint8Array | Content of the rawfile.|

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
    // Replace "test.txt" with the actual resource.
    this.context.resourceManager.getRawFileContentSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileContent<sup>9+</sup>

getRawFileContent(path: string, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a rawfile in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the rawfile.            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the content of the rawfile.|

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
    // Replace "test.txt" with the actual resource.
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

Obtains the content of a rawfile in the **resources/rawfile** directory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the content of the rawfile.|

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
    // Replace "test.txt" with the actual resource.
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
> If there is no folder or file in the directory, an exception is thrown. If there are folders and files in the directory, the list of the folders and files is returned.

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Passing "" means to obtain the list of files in the root directory (that is, /rawfile). Assume that the test.txt file exists in the root directory.
    // Replace "" with the actual file path in the rawfile directory.
    let fileList: Array<string> = this.context.resourceManager.getRawFileListSync("");
    console.log(`getRawFileListSync, result: ${JSON.stringify(fileList)}`);
    // Print the output result: getRawFileListSync, result: ["test.txt"]
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileListSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string, callback: _AsyncCallback&lt;Array\<string\>&gt;): void

Obtains the list of folders and files in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

>**NOTE**
>
> If there is no folder or file in the directory, an exception is thrown. If there are folders and files in the directory, the list of the folders and files is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | **rawfile** directory.            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array\<string\>&gt; | Yes| Callback used to return the list of folders and files.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Passing "" means to obtain the list of files in the root directory (that is, /rawfile). Assume that the test.txt file exists in the root directory.
  // Replace "" with the actual file path in the rawfile directory.
  this.context.resourceManager.getRawFileList("", (error: BusinessError, value: Array<string>) => {
    if (error != null) {
      console.error(`callback getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getRawFileListSync, result: ${JSON.stringify(value)}`);
      // Print the output result: getRawFileListSync, result: ["test.txt"]
    }
  });
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string): Promise&lt;Array\<string\>&gt;

Obtains the list of folders and files in the **resources/rawfile** directory. This API uses a promise to return the result.

>**NOTE**
>
> If there is no folder or file in the directory, an exception is thrown. If there are folders and files in the directory, the list of the folders and files is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | **rawfile** directory.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Array\<string\>&gt; | Promise used to return the list of folders and files.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Passing "" means to obtain the list of files in the root directory (that is, /rawfile). Assume that the test.txt file exists in the root directory.
  // Replace "" with the actual file path in the rawfile directory.
  this.context.resourceManager.getRawFileList("")
    .then((value: Array<string>) => {
      console.log(`getRawFileListSync, result: ${JSON.stringify(value)}`);
      // Print the output result: getRawFileListSync, result: ["test.txt"]
    })
    .catch((error: BusinessError) => {
      console.error(`promise getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getRawFdSync<sup>10+</sup>

getRawFdSync(path: string): RawFileDescriptor

Obtains the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located.

> **NOTE**
>
> To prevent resource leakage, call [closeRawFdSync](#closerawfdsync10) or [closeRawFd](#closerawfd9) to close the fd after use.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the rawfile.                    |

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| [RawFileDescriptor](#rawfiledescriptor9) | fd of the HAP where the rawfile is located.|

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
    // Replace "test.txt" with the actual resource.
    this.context.resourceManager.getRawFdSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFdSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFd<sup>9+</sup>

getRawFd(path: string, callback: _AsyncCallback&lt;RawFileDescriptor&gt;): void

Obtains the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located.

> **NOTE**
>
> To prevent resource leakage, call [closeRawFdSync](#closerawfdsync10) or [closeRawFd](#closerawfd9) to close the fd after use.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the rawfile.                     |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Yes   | Callback used to return the fd of the HAP.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

  try {
    // Replace "test.txt" with the actual resource.
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

Obtains the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located.

> **NOTE**
>
> To prevent resource leakage, call [closeRawFdSync](#closerawfdsync10) or [closeRawFd](#closerawfd9) to close the fd after use.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Promise used to return the fd of the HAP.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

  try {
    // Replace "test.txt" with the actual resource.
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

Closes the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the rawfile.|

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
    // Replace "test.txt" with the actual resource.
    this.context.resourceManager.closeRawFdSync("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`closeRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### closeRawFd<sup>9+</sup>

closeRawFd(path: string, callback: _AsyncCallback&lt;void&gt;): void

Closes the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the rawfile.|
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
    // Replace "test.txt" with the actual resource.
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

Closes the fd of the HAP where a specific rawfile in the **resources/rawfile** directory is located. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

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
    // Replace "test.txt" with the actual resource.
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

getConfiguration(callback: _AsyncCallback&lt;Configuration&gt;): void

Obtains the device configuration. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                       |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[Configuration](#configuration)&gt; | Yes   | Callback used to return the device configuration.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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
| Promise&lt;[Configuration](#configuration)&gt; | Promise used to return the device configuration.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

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

getDeviceCapability(callback: _AsyncCallback&lt;DeviceCapability&gt;): void

Obtains the device capability. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                          |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[DeviceCapability](#devicecapability)&gt; | Yes   | Callback used to return the device capability.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | Promise used to return the device capability.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

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

addResource(path: string): void

Loads resources from the specified path.

> **NOTE**
>
> Resource overwriting is not supported for the **/rawfile** and **/resfile** directories.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| path | string | Yes   | Resource path.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "/library1-default-signed.hsp" with the actual file path.
  let path = this.context.bundleCodeDir + "/library1-default-signed.hsp";
  try {
    this.context.resourceManager.addResource(path);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`addResource failed, error code: ${code}, message: ${message}.`);
  }
  ```

### removeResource<sup>10+</sup>

removeResource(path: string): void

Removes the resources loaded from the specified path to restore the original resources.

> **NOTE**
>
> Resource overwriting is not supported for the **/rawfile** and **/resfile** directories.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type           | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| path | string | Yes   | Resource path.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Replace "/library1-default-signed.hsp" with the actual file path.
  let path = this.context.bundleCodeDir + "/library1-default-signed.hsp";
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
| includeSystem  | boolean |  No   | Whether system resources are included. The default value is **false**.<br> - **false**: Only application resources are included.<br> - **true**: Both system and application resources are included.<br>If the value of **includeSystem** is invalid, the language list of system resources will be returned.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Array\<string> | Language list. The strings in the list are comprised of the language, script (optional), and region (optional), which are connected by a hyphen (-).|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getLocales(); // Obtain only the language list of application resources.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }

  try {
    resourceManager.getSysResourceManager().getLocales(); // Obtain only the language list of system resources.
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

getSymbol(resId: number): number

Obtains the Unicode of a [symbol](https://developer.huawei.com/consumer/en/design/harmonyos-symbol) based on the specified resource ID. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Unicode code (decimal) of the symbol.|

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
    // Replace 'sys.symbol.message' with the actual resource.
    let symbolValue = this.context.resourceManager.getSymbol($r('sys.symbol.message').id);
    console.log(`getSymbol, result: ${symbolValue}`);
    // Print the output result: getSymbol, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```


### getSymbolByName<sup>11+</sup>

getSymbolByName(resName: string): number

Obtains the Unicode of a [symbol](https://developer.huawei.com/consumer/en/design/harmonyos-symbol) based on the specified resource name. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name    | Type    | Mandatory  | Description  |
| ------- | ------ | ---- | ---- |
| resName | string | Yes   | Resource name.|

**Return value**

| Type    | Description        |
| ------ | ---------- |
| number | Unicode code (decimal) of the symbol.|

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
    // Replace "message" with the actual resource.
    let symbolValue = this.context.resourceManager.getSymbolByName("message");
    console.log(`getSymbolByName, result: ${symbolValue}`);
    // Print the output result: getSymbolByName, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbolByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### isRawDir<sup>12+</sup>

isRawDir(path: string): boolean

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
| boolean |Whether the path is a subdirectory in the **rawfile** directory.<br> - **true**: The path is a subdirectory in the **rawfile** directory.<br> - **false**: The path is not a subdirectory in the **rawfile** directory.|

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
    // Assume that a non-empty folder named sub exists in the root directory (that is, /rawfile). The value of isRawDir is true in the return result.
    // Replace "sub" with the actual directory.
    let isRawDir = this.context.resourceManager.isRawDir("sub");
    // Print the output result: sub isRawDir, result: true
    console.log(`sub isRawDir, result: ${isRawDir}`);

    // If the test.txt file exists in the root directory, the value of isRawDir is false.
    // Replace "test.txt" with the actual resource.
    isRawDir = this.context.resourceManager.isRawDir("test.txt");
    // Print the output result: test.txt isRawDir, result: false
    console.log(`test.txt isRawDir, result: ${isRawDir}`);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`isRawDir failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getOverrideResourceManager<sup>12+</sup>

getOverrideResourceManager(configuration?: Configuration): ResourceManager

Obtains a **ResourceManager** object for loading differentiated resources. This API returns the result synchronously.

The resource configuration (including the language, color mode, resolution, and orientation) obtained by a common **ResourceManager** object is determined by the system. With this API, an application can obtain resources of the specified configuration (that is, differentiated resources), for example, dark color resources in light color mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name       | Type                           | Mandatory| Description                                                        |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | No  | Resource configuration.<br>After obtaining the configuration of differentiated resources through [getOverrideConfiguration](#getoverrideconfiguration12), modify the configuration items as required, and then pass these items as input parameters to the API.<br>If no configuration is specified, the current system configuration is used.|

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
  import { resourceManager } from '@kit.LocalizationKit';

  try {
    let resMgr = this.context.resourceManager;
    let overrideConfig = resMgr.getOverrideConfiguration();
    overrideConfig.colorMode = resourceManager.ColorMode.DARK;
    let overrideResMgr = resMgr.getOverrideResourceManager(overrideConfig);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getOverrideResourceManager failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getOverrideConfiguration<sup>12+</sup>

getOverrideConfiguration(): Configuration

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
  import { resourceManager } from '@kit.LocalizationKit';

  try {
    let resMgr = this.context.resourceManager;
    let overrideConfig = resMgr.getOverrideConfiguration();
    overrideConfig.colorMode = resourceManager.ColorMode.DARK;
    let overrideResMgr = resMgr.getOverrideResourceManager(overrideConfig);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getOverrideResourceManager failed, error code: ${code}, message: ${message}.`);
  }
  ```

### updateOverrideConfiguration<sup>12+</sup>

updateOverrideConfiguration(configuration: Configuration): void

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
  import { resourceManager } from '@kit.LocalizationKit';

  try {
    let resMgr = this.context.resourceManager;
    let overrideConfig = resMgr.getOverrideConfiguration();
    overrideConfig.colorMode = resourceManager.ColorMode.DARK;
    let overrideResMgr = resMgr.updateOverrideConfiguration(overrideConfig);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`updateOverrideConfiguration failed, error code: ${code}, message: ${message}.`);
  }
  ```

### release<sup>(deprecated)</sup>

release()

Releases a **ResourceManager** object. This API is not supported currently.

> **NOTE**
>
> This API is supported since API version 7 and is deprecated since API version 12.

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

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | Yes   | Resource ID.          |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | Yes   | Callback used to return the obtained string.|

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

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getStringValue](#getstringvalue9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description         |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise used to return the obtained string.|

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
### getStringSync<sup>(deprecated)</sup>

getStringSync(resource: Resource): string

Obtains a string based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getStringByNameSync](#getstringbynamesync9) or [getStringSync](#getstringsync9) instead.

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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    let testStr = this.context.resourceManager.getStringSync(resource);
    console.log(`getStringSync, result: ${testStr}`);
    // Print the output result: getStringSync, result: I'm a test string resource.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>(deprecated)</sup>

getStringSync(resource: Resource, ...args: Array<string | number>): string

Obtains a string based on the specified resource object and formats the string based on **args**. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getStringByNameSync](#getstringbynamesync10) or [getStringSync](#getstringsync10) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| ...args | Array<string \| number> | No   | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

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
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a %1$s, format int: %2$d, format float: %3$f."
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    let testStr = this.context.resourceManager.getStringSync(resource, "format string", 10, 98.78);
    console.log(`getStringSync, result: ${testStr}`);
    // Print the output result: getStringSync, result: I'm a format string, format int: 10, format float: 98.78.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getStringValue<sup>(deprecated)</sup>

getStringValue(resource: Resource, callback: _AsyncCallback&lt;string&gt;): void

Obtains a string based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getStringByName](#getstringbyname9) or [getStringValue](#getstringvalue9) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | Yes   | Resource object.           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the obtained string.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  this.context.resourceManager.getStringValue(resource, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringValue, result: ${value}`);
      // Print the output result: getStringValue, result: I'm a test string resource.
    }
  });
  ```

### getStringValue<sup>(deprecated)</sup>

getStringValue(resource: Resource): Promise&lt;string&gt;

Obtains a string based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getStringByName](#getstringbyname9-1) or [getStringValue](#getstringvalue9-1) instead.

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
| Promise&lt;string&gt; | Promise used to return the obtained string.|

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
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  this.context.resourceManager.getStringValue(resource, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringValue, result: ${value}`);
      // Print the output result: getStringValue, result: I'm a test string resource.
    }
  });
  ```

### getStringArray<sup>(deprecated)</sup>

getStringArray(resId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | Yes   | Resource ID.            |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the obtained string array.|

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

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getStringArrayValue](#getstringarrayvalue9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                                | Description           |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the obtained string array.|

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

### getStringArrayValueSync<sup>(deprecated)</sup>

getStringArrayValueSync(resource: Resource): Array&lt;string&gt;

Obtains a string array based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This method is supported since API version 10 and is deprecated since API version 20. You are advised to use [getStringArrayByNameSync](#getstringarraybynamesync10) or [getStringArrayValueSync](#getstringarrayvaluesync10) instead.

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  try {
    let strArray: Array<string> = this.context.resourceManager.getStringArrayValueSync(resource);
    console.log(`getStringArrayValueSync, result: ${strArray[0]}`);
    // Print the output result: getStringArrayValueSync, result: I'm one of the array's values.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getStringArrayValue<sup>(deprecated)</sup>

getStringArrayValue(resource: Resource, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains a string array based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This method is supported since API version 9 and is deprecated since API version 20. You are advised to use [getStringArrayByName](#getstringarraybyname9) or [getStringArrayValue](#getstringarrayvalue9) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                      | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | Yes   | Resource object.             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  this.context.resourceManager.getStringArrayValue(resource, (error: BusinessError, value: Array<string>) => {
    if (error != null) {
      console.error(`callback getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringArrayValue, result: ${value[0]}`);
      // Print the output result: getStringArrayValue, result: I'm one of the array's values.
    }
  });
  ```

### getStringArrayValue<sup>(deprecated)</sup>

getStringArrayValue(resource: Resource): Promise&lt;Array&lt;string&gt;&gt;

Obtains a string array based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This method is supported since API version 9 and is deprecated since API version 20. You are advised to use [getStringArrayByName](#getstringarraybyname9-1) or [getStringArrayValue](#getstringarrayvalue9-1) instead.

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
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the obtained string array.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/strarray.json
  {
    "strarray": [
      {
        "name": "test",
        "value": [
          {
            "value": "I'm one of the array's values."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  this.context.resourceManager.getStringArrayValue(resource)
    .then((value: Array<string>) => {
      console.log(`getStringArrayValue, result: ${value[0]}`);
      // Print the output result: getStringArrayValue, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getMedia<sup>(deprecated)</sup>

getMedia(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains media file content based on the specified resource ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | Yes   | Resource ID.             |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

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

Obtains media file content based on the specified resource ID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getMediaContent](#getmediacontent9-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                       | Description            |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

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

### getMediaContentSync<sup>(deprecated)</sup>

getMediaContentSync(resource: Resource, density?: number): Uint8Array

Obtains the media file content for the default or specified screen density based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getMediaByNameSync](#getmediabynamesync10) or [getMediaContentSync](#getmediacontentsync10) instead.


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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContent<sup>(deprecated)</sup>

getMediaContent(resource: Resource, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains media file content based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getMediaByName](#getmediabyname9) or [getMediaContent](#getmediacontent9) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | Yes   | Resource object.              |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContent<sup>(deprecated)</sup>

getMediaContent(resource: Resource, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

Obtains media file content for the specified screen density based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This method is supported since API version 10 and is deprecated since API version 20. You are advised to use [getMediaByName](#getmediabyname10) or [getMediaContent](#getmediacontent10) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                             | Mandatory  | Description                |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | Yes   | Resource object.              |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | Yes   | Callback used to return the media file content.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContent<sup>(deprecated)</sup>

getMediaContent(resource: Resource): Promise&lt;Uint8Array&gt;

Obtains media file content based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getMediaByName](#getmediabyname9-1) or [getMediaContent](#getmediacontent9-1) instead.

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
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContent<sup>(deprecated)</sup>

getMediaContent(resource: Resource, density: number): Promise&lt;Uint8Array&gt;

Obtains media file content for the specified screen density based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getMediaByName](#getmediabyname10-1) or [getMediaContent](#getmediacontent10-1) instead.

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
| Promise&lt;Uint8Array&gt; | Promise used to return the media file content.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaBase64<sup>(deprecated)</sup>

getMediaBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code based on the specified resource ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | Yes   | Resource ID.                   |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

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

Obtains an image's Base64 code based on the specified resource ID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getMediaContentBase64](#getmediacontentbase649-1).

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|

**Return value**

| Type                   | Description                  |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

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
### getMediaContentBase64Sync<sup>(deprecated)</sup>

getMediaContentBase64Sync(resource: Resource, density?: number): string

Obtains an image's Base64 code for the default or specified screen density based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getMediaBase64ByNameSync](#getmediabase64bynamesync10) or [getMediaContentBase64Sync](#getmediacontentbase64sync10) instead.

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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
### getMediaContentBase64<sup>(deprecated)</sup>

getMediaContentBase64(resource: Resource, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getMediaBase64ByName](#getmediabase64byname9) or [getMediaContentBase64](#getmediacontentbase649) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContentBase64<sup>(deprecated)</sup>

getMediaContentBase64(resource: Resource, density: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains an image's Base64 code for the specified screen density based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getMediaBase64ByName](#getmediabase64byname10) or [getMediaContentBase64](#getmediacontentbase6410) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description                      |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | Yes   | Resource object.                    |
| [density](#screendensity)  | number        | Yes   | Screen density. The value **0** indicates the default screen density.   |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes   | Callback used to return the Base64 code of the image.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContentBase64<sup>(deprecated)</sup>

getMediaContentBase64(resource: Resource): Promise&lt;string&gt;

Obtains an image's Base64 code based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getMediaBase64ByName](#getmediabase64byname9-1) or [getMediaContentBase64](#getmediacontentbase649-1).

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
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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

### getMediaContentBase64<sup>(deprecated)</sup>

getMediaContentBase64(resource: Resource, density: number): Promise&lt;string&gt;

Obtains an image's Base64 code for the specified screen density based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> Supports versions from API version 10 and is deprecated in API version 20. You are advised to use [getMediaBase64ByName](#getmediabase64byname10-1) or [getMediaContentBase64](#getmediacontentbase6410-1) instead.

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
| Promise&lt;string&gt; | Promise used to return the Base64 code of the image.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
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
### getDrawableDescriptor<sup>(deprecated)</sup>

getDrawableDescriptor(resource: Resource, density?: number, type?: number): DrawableDescriptor

Obtains a **DrawableDescriptor** object for icon display based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getDrawableDescriptorByName](#getdrawabledescriptorbyname10) or [getDrawableDescriptor] (#getdrawabledescriptor10) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                    | Mandatory  | Description  |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | Yes   | Resource object.|
| [density](#screendensity) | number | No   | Screen density. The default value or value **0** indicates the default screen density.|
| type<sup>11+</sup> | number | No   | - **1**: Layered icon resource of the application in the theme resource package.<br> - **0** or default value: Icon resource of the application.|

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
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { DrawableDescriptor } from '@kit.ArkUI';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.icon').id
  };
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor(resource);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor(resource, 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor(resource, 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getIntPluralStringValueSync<sup>(deprecated)</sup>

getIntPluralStringValueSync(resource: Resource, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource object and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> - This API is supported since API version 18 and is deprecated since API version 20. You are advised to use [getIntPluralStringByNameSync](#getintpluralstringbynamesync18) or [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.
>
> - Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)  | Yes  | Resource object.                                                  |
| num      | number                  | Yes  | Integer number used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args  | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Formatted string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.format_test').id
  };

  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    let pluralStr = this.context.resourceManager.getIntPluralStringValueSync(resource, 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringValueSync, result: ${pluralStr}`);
    // Print the output result: getIntPluralStringValueSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringValueSync<sup>(deprecated)</sup>

getDoublePluralStringValueSync(resource: Resource, num: number, ...args: Array<string | number>): string

Obtains a [singular/plural](../../internationalization/l10n-singular-plural.md) string based on the specified resource object and formats the string based on the **args** parameter. This API returns the result synchronously.

> **NOTE**
>
> - This API is supported since API version 18 and is deprecated since API version 20. You are advised to use [getDoublePluralStringByNameSync](#getdoublepluralstringbynamesync18) or [getDoublePluralStringValueSync](#getdoublepluralstringvaluesync18) instead.
>
> - Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)  | Yes  | Resource object.                                                  |
| num      | number                  | Yes  | Quantity value (a floating point number), used to obtain the corresponding string representation based on the current language's [plural rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| ...args  | Array<string \| number> | No  | Arguments for formatting strings.<br>Supported value types include `%d`, `%f`, `%s`, `%%`, `%number$d`, `%number$f`, and `%number$s`.<br>Note: `%%` is converted to `%`. **number** in `%number$d` indicates the sequence number of the parameter in **args**.<br>For example, `%%d` is converted to `%d` after formatting, and `%1$d` indicates that the first parameter is used.|

**Return value**

| Type  | Description                                    |
| ------ | ---------------------------------------- |
| string | Formatted string corresponding to the specified resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
  {
    "plural": [
      {
        "name": "format_test",
        "value": [
          {
            "quantity": "one",
            "value": "There is %d apple in the %s, the total amount is %f kg."
          },
          {
            "quantity": "other",
            "value": "There are %d apples in the %s, the total amount is %f kg."
          }
        ]
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.format_test').id
  };

  try {
    // If num is 2.1, the single/plural type is other in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is other is obtained.
    let pluralStr = this.context.resourceManager.getDoublePluralStringValueSync(resource, 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringValueSync, result: ${pluralStr}`);
    // Print the output result: getIntPluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>(deprecated)</sup>

getPluralStringValueSync(resId: number, num: number): string

Obtains singular/plural strings based on the specified resource ID and quantity. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 10 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| resId  | number | Yes  | Resource ID.                                                  |
| num    | number | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type  | Description                                            |
| ------ | ------------------------------------------------ |
| string | Singular/plural string corresponding to the specified quantity and resource ID.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    let pluralValue = this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);
    console.log(`getPluralStringValueSync, result: ${pluralValue}`);
    // Print the output result: getPluralStringValueSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>(deprecated)</sup>

getPluralStringValueSync(resource: Resource, num: number): string

Obtains singular/plural strings based on the specified quantity and resource object. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 10 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9) | Yes  | Resource object.                                                  |
| num      | number                 | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type  | Description                                                |
| ------ | ---------------------------------------------------- |
| string | Singular/plural string corresponding to the specified quantity and resource object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    let pluralValue = this.context.resourceManager.getPluralStringValueSync(resource, 1);
    console.log(`getPluralStringValueSync, result: ${pluralValue}`);
    // Print the output result: getPluralStringValueSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringByNameSync<sup>(deprecated)</sup>

getPluralStringByNameSync(resName: string, num: number): string

Obtains singular/plural strings based on the specified quantity and resource name. This API returns the result synchronously.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 10 and is deprecated since API version 18. You are advised to use [getIntPluralStringByNameSync](#getintpluralstringbynamesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| resName | string | Yes  | Resource name.                                                  |
| num     | number | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type  | Description                                            |
| ------ | ------------------------------------------------ |
| string | Singular/plural string corresponding to the specified quantity and resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // If num is 1, the single/plural type is one in the English environment.
    // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
    let pluralValue = this.context.resourceManager.getPluralStringByNameSync("test", 1);
    console.log(`getPluralStringByNameSync, result: ${pluralValue}`);
    // Print the output result: getPluralStringByNameSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resId: number, num: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains singular/plural strings based on the specified quantity and resource ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resId    | number                      | Yes  | Resource ID.                                                  |
| num      | number                      | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes  | Callback used to return the obtained singular/plural string.          |

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1,
    (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getPluralStringValue, result: ${value}`);
        // Print the output result: getPluralStringValue, result: 1 apple
      }
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resId: number, num: number): Promise&lt;string&gt;

Obtains singular/plural strings based on the specified quantity and resource ID. This API uses a promise to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| resId  | number | Yes  | Resource ID.                                                  |
| num    | number | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type                 | Description                                                |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the obtained singular/plural string.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1)
    .then((value: string) => {
      console.log(`getPluralStringValue, result: ${value}`);
      // Print the output result: getPluralStringValue, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains singular/plural strings based on the specified quantity and resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)      | Yes  | Resource object.                                                  |
| num      | number                      | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes  | Callback used to return the obtained singular/plural string.      |

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringValue(resource, 1,
    (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getPluralStringValue, result: ${value}`);
        // Print the output result: getPluralStringValue, result: 1 apple
      }
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resource: Resource, num: number): Promise&lt;string&gt;

Obtains singular/plural strings based on the specified quantity and resource object. This API uses a promise to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9) | Yes  | Resource object.                                                  |
| num      | number                 | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type                 | Description                                                    |
| --------------------- | -------------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the obtained singular/plural string. |

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringValue(resource, 1)
    .then((value: string) => {
      console.log(`getPluralStringValue, result: ${value}`);
      // Print the output result: getPluralStringValue, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralStringByName<sup>(deprecated)</sup>

getPluralStringByName(resName: string, num: number, callback: _AsyncCallback&lt;string&gt;): void

Obtains singular/plural strings based on the specified quantity and resource name. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringByNameSync](#getintpluralstringbynamesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resName  | string                      | Yes  | Resource name.                                                  |
| num      | number                      | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | Yes  | Callback used to return the obtained singular/plural string.            |

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringByName("test", 1, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getPluralStringByName, result: ${value}`);
      // Print the output result: getPluralStringByName, result: 1 apple
    }
  });
  ```

### getPluralStringByName<sup>(deprecated)</sup>

getPluralStringByName(resName: string, num: number): Promise&lt;string&gt;

Obtains singular/plural strings based on the specified quantity and resource name. This API uses a promise to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 9 and is deprecated since API version 18. You are advised to use [getIntPluralStringByNameSync](#getintpluralstringbynamesync18) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| resName | string | Yes  | Resource name.                                                  |
| num     | number | Yes  | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type                 | Description                                            |
| --------------------- | ------------------------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result, which is the singular/plural string corresponding to the specified resource name.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/plural.json
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
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // If num is 1, the single/plural type is one in the English environment.
  // The quantity field in the resource file indicates the single/plural type. Therefore, the string whose quantity is one is obtained.
  this.context.resourceManager.getPluralStringByName("test", 1)
    .then((value: string) => {
      console.log(`getPluralStringByName, result: ${value}`);
      // Print the output result: getPluralStringByName, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number): Promise&lt;string&gt;

Obtains singular/plural strings based on the specified quantity and resource ID. This API uses a promise to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| resId | number | Yes   | Resource ID.|
| num   | number | Yes   | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|

**Return value**

| Type                   | Description                       |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the obtained singular/plural string.|

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

Obtains singular/plural strings based on the specified quantity and resource ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Strings distinguish between singular and plural forms in all languages except Chinese. For details, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [getIntPluralStringValueSync](#getintpluralstringvaluesync18) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | Yes   | Resource ID.                          |
| num      | number                      | Yes   | Quantity value, which is used to obtain the corresponding string representation based on the current language's plural rules. For details about the plural rules of a language, see [Language Plural Rules](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html).|
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | Yes   | Callback used to return the obtained singular/plural string.|

**Example**

  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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
### getBoolean<sup>(deprecated)</sup>

getBoolean(resource: Resource): boolean

Obtains a Boolean value based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getBooleanByName](#getbooleanbyname9) or [getBoolean](#getboolean9) instead.

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
| boolean | Boolean value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/boolean.json
  {
    "boolean": [
      {
        "name": "boolean_test",
        "value": true
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.boolean.boolean_test').id
  };
  try {
    let boolTest = this.context.resourceManager.getBoolean(resource);
    console.log(`getBoolean, result: ${boolTest}`);
    // Print the output result: getBoolean, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getNumber<sup>(deprecated)</sup>

getNumber(resource: Resource): number

Obtains an integer or float number based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 9 and is deprecated since API version 20. You are advised to use [getNumberByName](#getnumberbyname9) or [getNumber](#getnumber9) instead.

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
| number | Integer or float number.<br>An integer indicates the original value, and a float number without a unit indicates the original value and a float number with the unit of vp or fp indicates the px value.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/integer.json
  {
    "integer": [
      {
        "name": "integer_test",
        "value": 100
      }
    ]
  }
  ```

  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.integer.integer_test').id
  };

  try {
    let intValue = this.context.resourceManager.getNumber(resource);
    console.log(`getNumber, int value: ${intValue}`);
    // Print the output result: getNumber, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getColorSync<sup>(deprecated)</sup>

getColorSync(resource: Resource): number

Obtains a color value based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getColorByNameSync](#getcolorbynamesync10) or [getColorSync](#getcolorsync10) instead.

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

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  try {
    let colorValue = this.context.resourceManager.getColorSync(resource);
    console.log(`getColorSync, result: ${colorValue}`);
    // Print the output result: getColorSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getColor<sup>(deprecated)</sup>

getColor(resource: Resource, callback: _AsyncCallback&lt;number&gt;): void

Obtains a color value based on the specified resource object. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getColorByName](#getcolorbyname10) or [getColor](#getcolor10) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | Yes   | Resource object.           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | Yes   | Callback used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  this.context.resourceManager.getColor(resource, (error: BusinessError, value: number) => {
    if (error != null) {
      console.error(`callback getColor failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getColor, result: ${value}`);
      // Print the output result: getColor, result: 4294967295
    }
  });
  ```

### getColor<sup>(deprecated)</sup>

getColor(resource: Resource): Promise&lt;number&gt;

Obtains a color value based on the specified resource object. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [getColorByName] (#getcolorbyname10-1) or [getColor] (#getcolor10-1) instead.

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
| Promise&lt;number&gt; | Promise used to return the color value (decimal).|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**Example**
  ```json
  // Resource file path: src/main/resources/base/element/color.json
  {
    "color": [
      {
        "name": "test",
        "value": "#FFFFFF"
      }
    ]
  }
  ```
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  this.context.resourceManager.getColor(resource)
    .then((value: number) => {
      console.log(`getColor, result: ${value}`);
      // Print the output result: getColor, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColor failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```
### getSymbol<sup>(deprecated)</sup>
getSymbol(resource: Resource): number

Obtains the Unicode of a [symbol](https://developer.huawei.com/consumer/en/design/harmonyos-symbol) based on the specified resource object. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 11 and is deprecated since API version 20. You are advised to use [getSymbolByName](#getsymbolbyname11) or [getSymbol](#getsymbol11) instead.

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
| number | Unicode code (decimal) of the symbol.|

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
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('sys.symbol.message').id
  };
  try {
    let symbolValue = this.context.resourceManager.getSymbol(resource);
    console.log(`getSymbol, result: ${symbolValue}`);
    // Print the output result: getSymbol, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

Obtains the content of a rawfile in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                             | Mandatory  | Description                     |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | Yes   | Path of the rawfile.            |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Uint8Array&gt; | Yes   | Callback used to return the rawfile content.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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

Obtains the content of a rawfile in the **resources/rawfile** directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getRawFileContent](#getrawfilecontent9-1) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

**Return value**

| Type                       | Description         |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the rawfile content.|

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

Obtains the fd of the rawfile in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | Yes   | Path of the rawfile.                     |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Yes   | Callback used to return the obtained fd.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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

Obtains the fd of the rawfile in the **resources/rawfile** directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [getRawFd](#getrawfd9-1) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Promise used to return the obtained fd.|

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

Closes the fd of the rawfile in the **resources/rawfile** directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [closeRawFd](#closerawfd9) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**



| Name     | Type                       | Mandatory  | Description         |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | Yes   | Path of the rawfile.|
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

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

Closes the fd of the rawfile in the **resources/rawfile** directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 9. You are advised to use [closeRawFd](#closerawfd9-1) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| path | string | Yes   | Path of the rawfile.|

**Return value**

| Type                 | Description  |
| ------------------- | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt");
  });
  ```

## resourceManager.getSystemResourceManager<sup>(deprecated)</sup>

getSystemResourceManager(): ResourceManager

Obtains a **ResourceManager** object.

> **NOTE**
>
> The **Configuration** field in the **ResourceManager** object obtained via this API uses the default value, which is as follows:
> {"locale": "", "direction": -1, "deviceType": -1, "screenDensity": 0, "colorMode": 1, "mcc": 0, "mnc": 0}.
> 
> This API is supported since API version 10 and is deprecated since API version 20. You are advised to use [resourceManager.getSysResourceManager](#resourcemanagergetsysresourcemanager20) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

**Return value**

| Type                                      | Description                |
| ---------------------------------------- | ------------------ |
| [ResourceManager](#resourcemanager) | **ResourceManager** object.|

**Error codes**

For details about the error codes, see [Resource Manager Error Codes](errorcode-resource-manager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 9001009  | Failed to access the system resource. which is not mapped to application sandbox, This error code will be thrown. |

**Example**
  ```js
import { resourceManager } from '@kit.LocalizationKit';
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
    console.error(`getSystemResourceManager failed, error code: ${code}, message: ${message}.`);
  }
  ```

## AsyncCallback<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback) instead.

### (err: Error, data: T)<sup>(deprecated)</sup>

(err: Error, data: T): void;

Defines an asynchronous callback that carries an error parameter and asynchronous return value.

> **NOTE**
>
> This API is supported since API version 6 and is deprecated since API version 9. You are advised to use [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback) instead.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name| Type                                                        | Mandatory| Description                        |
| ---- | ------------------------------------------------------------ | ---- | ---------------------------- |
| err  | Error | Yes  | Error message returned when the API fails to be called.|
| data | T     | Yes  | Callback invoked when the API is called.|

## Appendix

- Content of the **app.string.test** file:

    ```json
    // Resource file path: src/main/resources/base/element/string.json
    {
      "string": [
        {
          "name": "test",
          "value": "I'm a test string resource."
        }
      ]
    }
    ```

    ```json
    // Resource file path: src/main/resources/base/element/string.json
    {
      "string": [
        {
          "name": "test",
          "value": "I'm a %1$s, format int: %2$d, format float: %3$f."
        }
      ]
    }
    ```

- Content of the **app.strarray.test** file:

    ```json
    // Resource file path: src/main/resources/base/element/strarray.json
    {
      "strarray": [
        {
          "name": "test",
          "value": [
            {
              "value": "I'm one of the array's values."
            }
          ]
        }
      ]
    }
    ```

- Content of the **app.plural.test** file:
    ```json
    // Resource file path: src/main/resources/base/element/plural.json
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

- Content of the **app.plural.format_test** file:

    ```json
    // Resource file path: src/main/resources/base/element/plural.json
    {
      "plural": [
        {
          "name": "format_test",
          "value": [
            {
              "quantity": "one",
              "value": "There is %d apple in the %s, the total amount is %f kg."
            },
            {
              "quantity": "other",
              "value": "There are %d apples in the %s, the total amount is %f kg."
            }
          ]
        }
      ]
    }
    ```

- Content of the **app.boolean.boolean_test** file:
    ```json
    // Resource file path: src/main/resources/base/element/boolean.json
    {
      "boolean": [
        {
          "name": "boolean_test",
          "value": true
        }
      ]
    }
    ```

- Content of the **integer_test** and **float_test** files:
    ```json
    // Resource file path: src/main/resources/base/element/integer.json
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
    // Resource file path: src/main/resources/base/element/float.json
    {
      "float": [
        {
          "name": "float_test",
          "value": "30.6vp"
        }
      ]
    }
    ```
- Content of the **app.color.test** file:
    ```json
    // Resource file path: src/main/resources/base/element/color.json
    {
      "color": [
        {
          "name": "test",
          "value": "#FFFFFF"
        }
      ]
    }
    ```

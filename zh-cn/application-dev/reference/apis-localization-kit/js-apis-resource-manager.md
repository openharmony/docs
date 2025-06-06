# @ohos.resourceManager (资源管理)

本模块提供资源获取能力。根据当前的[Configuration](#configuration)配置，获取最匹配的应用资源或系统资源。具体匹配规则参考[资源匹配](../../quick-start/resource-categories-and-access.md#资源匹配)。

Configuration配置包括语言、区域、横竖屏、Mcc（移动国家码）和Mnc（移动网络码）、Device capability（设备类型）、Density（分辨率）。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { resourceManager } from '@kit.LocalizationKit';
```

## 使用说明

从API version 9开始，Stage模型支持通过Context获取资源管理resourceManager对象，无需再导入模块。
FA模型仍需要先导入模块，再调用[getResourceManager](#resourcemanagergetresourcemanager)接口获取资源管理对象。 
Stage模型下Context的引用方法请参考[Stage模型的Context详细介绍](../../application-models/application-context-stage.md)。

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

获取当前应用的资源管理对象，使用callback异步回调。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在FA模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                            |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;[ResourceManager](#resourcemanager)&gt; | 是    | 回调函数，返回资源管理ResourceManager对象。 |

**示例：**

  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

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

获取指定应用的资源管理对象，使用callback异步回调。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型                                       | 必填   | 说明                            |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | 是    | 应用包名。                 |
| callback   | [AsyncCallback](#asynccallbackdeprecated)&lt;[ResourceManager](#resourcemanager)&gt; | 是    | 回调函数，返回应用包名对应的资源管理ResourceManager对象。 |

**示例：**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
    if (error != null) {
      console.error("error is " + error);
      return;
    }
  });
  ```

## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

获取当前应用的资源管理对象，使用Promise异步回调。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在FA模型下使用。

**返回值：**

| 类型                                       | 说明                |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise对象，返回资源管理ResourceManager对象。 |

**示例：**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
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

获取指定应用的资源管理对象，使用Promise异步回调。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | 是    | 应用包名。 |

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise对象，返回应用包名对应的资源管理ResourceManager对象。 |

**示例：**
  <!--code_no_check_fa-->
  ```js
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  resourceManager.getResourceManager("com.example.myapplication").then((mgr: resourceManager.ResourceManager) => {
  }).catch((error: BusinessError) => {
    console.error("error is " + error);
  });
  ```

## resourceManager.getSystemResourceManager<sup>10+</sup>

getSystemResourceManager(): ResourceManager

获取系统资源管理ResourceManager对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| [ResourceManager](#resourcemanager) | 系统资源管理对象。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001009  | Failed to access the system resource. which is not mapped to application sandbox, This error code will be thrown. |

**示例：**
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

## Direction

用于表示设备屏幕方向。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | 竖屏。   |
| DIRECTION_HORIZONTAL | 1    | 横屏。   |


## DeviceType

用于表示当前设备类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager
<!--RP1-->
| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_PHONE    | 0x00 | 手机。   |
| DEVICE_TYPE_TABLET   | 0x01 | 平板。   |
| DEVICE_TYPE_CAR      | 0x02 | 车机。   |
| DEVICE_TYPE_TV       | 0x04 | 智慧屏。  |
| DEVICE_TYPE_WEARABLE | 0x06 | 智能手表。   |
| DEVICE_TYPE_2IN1<sup>11+</sup>     | 0x07 | PC/2in1。   |
<!--RP1End-->

## ScreenDensity

用于表示当前设备屏幕密度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称             | 值  | 说明         |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | 低屏幕密度。  |
| SCREEN_MDPI    | 160  | 中屏幕密度。   |
| SCREEN_LDPI    | 240  | 高屏幕密度。   |
| SCREEN_XLDPI   | 320  | 特高屏幕密度。  |
| SCREEN_XXLDPI  | 480  | 超高屏幕密度。  |
| SCREEN_XXXLDPI | 640  | 超特高屏幕密度。 |


## ColorMode<sup>12+</sup>

用于表示当前设备颜色模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称  | 值   | 说明       |
| ----- | ---- | ---------- |
| DARK  | 0    | 深色模式。 |
| LIGHT | 1    | 浅色模式。 |


## Configuration

表示当前设备的状态。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称                        | 类型                            | 可读 | 可写 | 说明               |
| --------------------------- | ------------------------------- | ---- | ---- | ------------------ |
| direction                   | [Direction](#direction)         | 是   | 是   | 屏幕方向。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| locale                      | string                          | 是   | 是   | 语言文字国家地区。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| deviceType<sup>12+</sup>    | [DeviceType](#devicetype)       | 是   | 是   | 设备类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| screenDensity<sup>12+</sup> | [ScreenDensity](#screendensity) | 是   | 是   | 屏幕密度。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| colorMode<sup>12+</sup>     | [ColorMode](#colormode12)       | 是   | 是   | 颜色模式。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。        |
| mcc<sup>12+</sup>           | number                          | 是   | 是   | 移动国家码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| mnc<sup>12+</sup>           | number                          | 是   | 是   | 移动网络码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |



## DeviceCapability

表示设备支持的能力。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称            | 类型                            | 可读   | 可写   | 说明       |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | 是    | 否    | 当前设备屏幕密度。 |
| deviceType    | [DeviceType](#devicetype)       | 是    | 否    | 当前设备类型。   |


## RawFileDescriptor<sup>9+</sup>

type RawFileDescriptor = _RawFileDescriptor

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_RawFileDescriptor](js-apis-rawFileDescriptor.md#rawfiledescriptor-1)|表示rawfile文件所在HAP的文件描述符（fd）。|

## Resource<sup>9+</sup>

type Resource = _Resource

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_Resource](js-apis-resource.md#resource-1)|表示资源信息，包含资源ID值、应用包名、模块名称等信息，一般可使用$r方式获取。|

## ResourceManager

提供访问应用资源和系统资源的能力。

> **说明：**
>
> - ResourceManager涉及到的方法，仅限基于TS扩展的声明式开发范式使用。
>
> - 资源文件在工程的resources目录中定义，通过resId、resName、resource对象等可以获取对应的字符串、字符串数组、颜色等资源值，resId可通过`$r(资源地址).id`的方式获取，例如`$r('app.string.test').id`。
>
> - [resource](#resource9)对象适用于多工程应用内的跨包访问，因resource对象需创建对应module的context获取资源，故相比于入参为resId、resName的接口耗时更长。
>
> - 单HAP包获取自身资源，推荐使用参数为resId或resName的接口。跨HAP/HSP包获取资源，推荐使用[createModuleContext](../apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12)创建对应module的context，再调用参数为resId或resName的接口。
>
> - 单HAP包和跨HAP/HSP包资源的访问方式具体请参考[资源访问](../../quick-start/resource-categories-and-access.md#资源访问)。
>
> - 示例代码中test文件的具体内容请参考[附录](#附录)。

### getStringSync<sup>9+</sup>

getStringSync(resId: number): string

获取指定资源ID对应的字符串，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 资源ID值对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    let testStr = this.context.resourceManager.getStringSync($r('app.string.test').id);
    console.log(`getStringSync, result: ${testStr}`);
    // 打印输出结果: getStringSync, result: I'm a test string resource.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>10+</sup>

getStringSync(resId: number, ...args: Array<string | number>): string

获取指定资源ID对应的字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| ...args | Array<string \| number> | 否 | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | 资源ID值对应的格式化字符串。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                               |
| 9001002  | No matching resource is found based on the resource ID.                 |
| 9001006  | The resource is referenced cyclically.                    |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    let testStr = this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 10, 98.78);
    console.log(`getStringSync, result: ${testStr}`);
    // 打印输出结果: getStringSync, result: I'm a format string, format int: 10, format float: 98.78.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>9+</sup>

getStringSync(resource: Resource): string

获取指定resource对象对应的字符串，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明               |
| ------ | ---------------- |
| string | resource对象对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    // 打印输出结果: getStringSync, result: I'm a test string resource.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringSync<sup>10+</sup>

getStringSync(resource: Resource, ...args: Array<string | number>): string

获取指定resource对象对应的字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| ...args | Array<string \| number> | 否    | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。|

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | resource对象对应的格式化字符串。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    // 打印输出结果: getStringSync, result: I'm a format string, format int: 10, format float: 98.78.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByNameSync<sup>9+</sup>

getStringByNameSync(resName: string): string

获取指定资源名称对应的字符串，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 资源名称对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    let testStr = this.context.resourceManager.getStringByNameSync("test");
    console.log(`getStringByNameSync, result: ${testStr}`);
    // 打印输出结果: getStringByNameSync, result: I'm a test string resource.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringByNameSync<sup>10+</sup>

getStringByNameSync(resName: string, ...args: Array<string | number>): string

获取指定资源名称对应的字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| ...args | Array<string \| number> | 否    | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。|

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | 资源名称对应的格式化字符串。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |
| 9001008  | Failed to format the resource obtained based on the resource Name. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
    let testStr = this.context.resourceManager.getStringByNameSync("test", "format string", 10, 98.78);
    console.log(`getStringByNameSync, result: ${testStr}`);
    // 打印输出结果: getStringByNameSync, result: I'm a format string, format int: 10, format float: 98.78.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringValue<sup>9+</sup>

getStringValue(resId: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源ID对应的字符串，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回获取的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**示例Stage：** 
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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

  this.context.resourceManager.getStringValue($r('app.string.test').id, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringValue, result: ${value}`);
      // 打印输出结果: getStringValue, result: I'm a test string resource.
    }
  });
  ```

### getStringValue<sup>9+</sup>

getStringValue(resId: number): Promise&lt;string&gt;

获取指定资源ID对应的字符串，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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

  this.context.resourceManager.getStringValue($r('app.string.test').id).then((value: string) => {
    console.log(`getStringValue, result: ${value}`);
    // 打印输出结果: getStringValue, result: I'm a test string resource.
  }).catch((error: BusinessError) => {
    console.error(`promise getStringValue failed, error code: ${error.code}, message: ${error.message}.`);
  });
  ```

### getStringValue<sup>9+</sup>

getStringValue(resource: Resource, callback: _AsyncCallback&lt;string&gt;): void

获取指定resource对象对应的字符串，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息。            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回resource对象对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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
      // 打印输出结果: getStringValue, result: I'm a test string resource.
    }
  });
  ```

### getStringValue<sup>9+</sup>

getStringValue(resource: Resource): Promise&lt;string&gt;

获取指定resource对象对应的字符串，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | Promise对象，返回resource对象对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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
      // 打印输出结果: getStringValue, result: I'm a test string resource.
    }
  });
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源名称对应的字符串，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称。            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    |返回获取的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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

  this.context.resourceManager.getStringByName("test", (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getStringByName, result: ${value}`);
      // 打印输出结果: getStringByName, result: I'm a test string resource.
    }
  });
  ```

### getStringByName<sup>9+</sup>

getStringByName(resName: string): Promise&lt;string&gt;

获取指定资源名称对应的字符串，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;string&gt; | Promise对象，返回资源名称对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
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

  this.context.resourceManager.getStringByName("test").then((value: string) => {
    console.log(`getStringByName, result: ${value}`);
    // 打印输出结果: getStringByName, result: I'm a test string resource.
  }).catch((error: BusinessError) => {
    console.error(`promise getStringByName failed, error code: ${error.code}, message: ${error.message}.`);
  });
  ```

### getStringArrayValueSync<sup>10+</sup>

getStringArrayValueSync(resId: number): Array&lt;string&gt;

获取指定资源ID对应的字符串数组，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 资源ID值对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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
    let strArray: Array<string> = this.context.resourceManager.getStringArrayValueSync($r('app.strarray.test').id);
    console.log(`getStringArrayValueSync, result: ${strArray[0]}`);
    // 打印输出结果: getStringArrayValueSync, result: I'm one of the array's values.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValueSync<sup>10+</sup>

getStringArrayValueSync(resource: Resource): Array&lt;string&gt;

获取指定resource对象对应的字符串数组，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | resource对象对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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
    // 打印输出结果: getStringArrayValueSync, result: I'm one of the array's values.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayByNameSync<sup>10+</sup>

getStringArrayByNameSync(resName: string): Array&lt;string&gt;

获取指定资源名称对应的字符串数组，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 对应资源名称的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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
    let strArray: Array<string> = this.context.resourceManager.getStringArrayByNameSync("test");
    console.log(`getStringArrayByNameSync, result: ${strArray[0]}`);
    // 打印输出结果: getStringArrayByNameSync, result: I'm one of the array's values.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定资源ID对应的字符串数组，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值。             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | 是    | 回调函数，返回资源ID值对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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

  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id,
    (error: BusinessError, value: Array<string>) => {
      if (error != null) {
        console.error(`callback getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getStringArrayValue, result: ${value[0]}`);
        // 打印输出结果: getStringArrayValue, result: I'm one of the array's values.
      }
    });
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定资源ID对应的字符串数组，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回资源ID值对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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

  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id)
    .then((value: Array<string>) => {
      console.log(`getStringArrayValue, result: ${value[0]}`);
      // 打印输出结果: getStringArrayValue, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定resource对象对应的字符串数组，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | 是    | 资源信息。              |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | 是    | 回调函数，返回resource对象对应的字符串数组。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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
      // 打印输出结果: getStringArrayValue, result: I'm one of the array's values.
    }
  });
  ```

### getStringArrayValue<sup>9+</sup>

getStringArrayValue(resource: Resource): Promise&lt;Array&lt;string&gt;&gt;

获取指定resource对象对应的字符串数组，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                                 | 说明                 |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回resource对象对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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
      // 打印输出结果: getStringArrayValue, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string, callback: _AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定资源名称对应的字符串数组，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | 是    | 资源名称。              |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array&lt;string&gt;&gt; | 是    | 回调函数，返回资源名称对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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

  this.context.resourceManager.getStringArrayByName("test", (error: BusinessError, value: Array<string>) => {
    if (error != null) {
      console.error(`callback getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      let strArray = value;
      console.log(`getStringArrayByName, result: ${value[0]}`);
      // 打印输出结果: getStringArrayByName, result: I'm one of the array's values.
    }
  });
  ```

### getStringArrayByName<sup>9+</sup>

getStringArrayByName(resName: string): Promise&lt;Array&lt;string&gt;&gt;

获取指定资源名称对应的字符串数组，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                                 | 说明           |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回资源名称对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/strarray.json
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

  this.context.resourceManager.getStringArrayByName("test")
    .then((value: Array<string>) => {
      console.log(`getStringArrayByName, result: ${value[0]}`);
      // 打印输出结果: getStringArrayByName, result: I'm one of the array's values.
    })
    .catch((error: BusinessError) => {
      console.error(`promise getStringArrayByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getIntPluralStringValueSync<sup>18+</sup>

getIntPluralStringValueSync(resId: number, num: number, ...args: Array<string | number>): string

获取指定资源ID对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型                    | 必填 | 说明                                                         |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resId   | number                  | 是   | 资源ID值。                                                   |
| num     | number                  | 是   | 数量值（整数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| string | 资源ID值对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralStr = this.context.resourceManager.getIntPluralStringValueSync($r('app.plural.format_test').id, 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringValueSync, result: ${pluralStr}`);
    // 打印输出结果: getIntPluralStringValueSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getIntPluralStringValueSync<sup>18+</sup>

getIntPluralStringValueSync(resource: Resource, num: number, ...args: Array<string | number>): string

获取指定resource对象对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)  | 是   | 资源信息。                                                   |
| num      | number                  | 是   | 数量值（整数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args  | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | resource对象对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralStr = this.context.resourceManager.getIntPluralStringValueSync(resource, 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringValueSync, result: ${pluralStr}`);
    // 打印输出结果: getIntPluralStringValueSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getIntPluralStringByNameSync<sup>18+</sup>

getIntPluralStringByNameSync(resName: string, num: number, ...args: Array<string | number>): string

获取指定资源名称对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型                    | 必填 | 说明                                                         |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resName | string                  | 是   | 资源名称。                                                   |
| num     | number                  | 是   | 数量值（整数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 资源名称对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |
| 9001008  | Failed to format the resource obtained based on the resource name. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralStr = this.context.resourceManager.getIntPluralStringByNameSync("format_test", 1, 1, "basket", 0.3);
    console.log(`getIntPluralStringByNameSync, result: ${pluralStr}`);
    // 打印输出结果: getIntPluralStringByNameSync, result: There is 1 apple in the basket, the total amount is 0.3 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getIntPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringValueSync<sup>18+</sup>

getDoublePluralStringValueSync(resId: number, num: number, ...args: Array<string | number>): string

获取指定资源ID对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型                    | 必填 | 说明                                                         |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resId   | number                  | 是   | 资源ID值。                                                   |
| num     | number                  | 是   | 数量值（浮点数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 资源ID值对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为2.1，英文环境下对应单复数类别为other
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为other的字符串
    let pluralStr = this.context.resourceManager.getDoublePluralStringValueSync($r('app.plural.format_test').id, 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringValueSync, result: ${pluralStr}`);
    // 打印输出结果: getDoublePluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringValueSync<sup>18+</sup>

getDoublePluralStringValueSync(resource: Resource, num: number, ...args: Array<string | number>): string

获取指定resource对象对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)  | 是   | 资源信息。                                                   |
| num      | number                  | 是   | 数量值（浮点数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args  | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                                     |
| ------ | ---------------------------------------- |
| string | resource对象对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |
| 9001007  | Failed to format the resource obtained based on the resource ID. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为2.1，英文环境下对应单复数类别为other
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为other的字符串
    let pluralStr = this.context.resourceManager.getDoublePluralStringValueSync(resource, 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringValueSync, result: ${pluralStr}`);
    // 打印输出结果: getIntPluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDoublePluralStringByNameSync<sup>18+</sup>

getDoublePluralStringByNameSync(resName: string, num: number, ...args: Array<string | number>): string

获取指定资源名称对应的[单复数](../../internationalization/l10n-singular-plural.md)字符串，并根据args参数对字符串进行格式化，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型                    | 必填 | 说明                                                         |
| ------- | ----------------------- | ---- | ------------------------------------------------------------ |
| resName | string                  | 是   | 资源名称。                                                   |
| num     | number                  | 是   | 数量值（浮点数）。根据当前语言的[单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)获取该数量值对应的字符串。 |
| ...args | Array<string \| number> | 否   | 格式化字符串资源参数。<br>支持参数类型：`%d`、`%f`、`%s`、`%%`、`%数字$d`、`%数字$f`、`%数字$s`。<br>说明：`%%`转义为`%`; `%数字$d`中的数字表示使用args中的第几个参数。<br>举例：`%%d`格式化后为`%d`字符串; `%1$d`表示使用第一个参数。 |

**返回值：**

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 资源名称对应的格式化单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |
| 9001008  | Failed to format the resource obtained based on the resource name. |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为2.1，英文环境下对应单复数类别为other
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为other的字符串
    let pluralStr = this.context.resourceManager.getDoublePluralStringByNameSync("format_test", 2.1, 2, "basket", 0.6);
    console.log(`getDoublePluralStringByNameSync, result: ${pluralStr}`);
    // 打印输出结果: getIntPluralStringValueSync, result: There are 2 apples in the basket, the total amount is 0.6 kg.
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDoublePluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentSync<sup>10+</sup>

getMediaContentSync(resId: number, density?: number): Uint8Array

获取指定资源ID对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| Uint8Array   | 资源ID对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentSync($r('app.media.test').id, 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentSync<sup>10+</sup>

getMediaContentSync(resource: Resource, density?: number): Uint8Array

获取指定resource对象对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Uint8Array | resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentSync(resource); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentSync(resource, 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaByNameSync<sup>10+</sup>

getMediaByNameSync(resName: string, density?: number): Uint8Array

获取指定资源名称对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Uint8Array | 资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaByNameSync("test"); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaByNameSync("test", 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContent<sup>9+</sup>

getMediaContent(resId: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定资源ID对应的媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回资源ID对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.              | 
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

getMediaContent(resId: number, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定资源ID对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回资源ID对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

获取指定资源ID对应的媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回资源ID值对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

获取指定资源ID对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回资源ID值对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

getMediaContent(resource: Resource, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定resource对象对应的媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息。               |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContent<sup>10+</sup>

getMediaContent(resource: Resource, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定resource对象对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息。               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContent<sup>9+</sup>

getMediaContent(resource: Resource): Promise&lt;Uint8Array&gt;

获取指定resource对象对应的媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContent<sup>10+</sup>

getMediaContent(resource: Resource, density: number): Promise&lt;Uint8Array&gt;

获取指定resource对象对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaByName<sup>9+</sup>

getMediaByName(resName: string, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定资源名称对应的媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称。               |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

getMediaByName(resName: string, density: number, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取指定资源名称对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称。               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源名称对应的媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源名称对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源ID对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| string   | 资源ID对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id, 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64Sync<sup>10+</sup>

getMediaContentBase64Sync(resource: Resource, density?: number): string

获取指定resource对象对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64Sync(resource); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaContentBase64Sync(resource, 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaBase64ByNameSync<sup>10+</sup>

getMediaBase64ByNameSync(resName: string, density?: number): string

获取指定资源名称对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 资源名称对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getMediaBase64ByNameSync("test"); // 默认屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getMediaBase64ByNameSync("test", 120); // 指定屏幕密度
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resId: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源ID对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回资源ID值对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

getMediaContentBase64(resId: number, density: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回资源ID值对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

获取指定资源ID对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

getMediaContentBase64(resource: Resource, callback: _AsyncCallback&lt;string&gt;): void

获取指定resource对象对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息。                     |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resource: Resource, density: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息。                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContentBase64<sup>9+</sup>

getMediaContentBase64(resource: Resource): Promise&lt;string&gt;

获取指定resource对象对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaContentBase64<sup>10+</sup>

getMediaContentBase64(resource: Resource, density: number): Promise&lt;string&gt;

获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getMediaBase64ByName<sup>9+</sup>

getMediaBase64ByName(resName: string, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源名称对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称。                     |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回资源名称的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

getMediaBase64ByName(resName: string, density: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称。                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是    | 回调函数，返回资源名称的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源名称对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源名称对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源名称对应的图片资源Base64编码。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
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

获取指定资源ID对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | - 1表示获取主题资源包中应用的分层图标资源。<br> - 0或缺省表示获取应用自身图标资源。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 资源ID值对应的DrawableDescriptor对象。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { DrawableDescriptor } from '@kit.ArkUI';

  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptor<sup>10+</sup>

getDrawableDescriptor(resource: Resource, density?: number, type?: number): DrawableDescriptor

获取指定resource对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | - 1表示获取主题资源包中应用的分层图标资源。<br> - 0或缺省表示获取应用自身图标资源。 |

**返回值：**

| 类型      | 说明                |
| ------- | ----------------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 资源ID值对应的DrawableDescriptor对象。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
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

### getDrawableDescriptorByName<sup>10+</sup>

getDrawableDescriptorByName(resName: string, density?: number, type?: number): DrawableDescriptor

获取指定资源名称对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | - 1表示获取主题资源包中应用的分层图标资源。<br> - 0或缺省表示获取应用自身图标资源。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 资源名称对应的DrawableDescriptor对象。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { DrawableDescriptor } from '@kit.ArkUI';

  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon');
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon', 120);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  try {
    let drawableDescriptor:DrawableDescriptor = this.context.resourceManager.getDrawableDescriptorByName('icon', 0, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBoolean<sup>9+</sup>

getBoolean(resId: number): boolean

获取指定资源ID值对应的布尔值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 资源ID值对应的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/boolean.json
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
    let boolTest = this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);
    console.log(`getBoolean, result: ${boolTest}`);
    // 打印输出结果: getBoolean, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getBoolean<sup>9+</sup>

getBoolean(resource: Resource): boolean

获取指定resource对象对应的布尔值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型      | 说明                |
| ------- | ----------------- |
| boolean | resource对象对应的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/boolean.json
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
    // 打印输出结果: getBoolean, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBooleanByName<sup>9+</sup>

getBooleanByName(resName: string): boolean

获取指定资源名称对应的布尔值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型      | 说明          |
| ------- | ----------- |
| boolean | 资源名称对应的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/boolean.json
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
    let boolTest = this.context.resourceManager.getBooleanByName("boolean_test");
    console.log(`getBooleanByName, result: ${boolTest}`);
    // 打印输出结果: getBooleanByName, result: true
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBooleanByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resId: number): number

获取指定资源ID对应的integer数值或者float数值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- | 
| number | 资源ID值对应的数值。<br>integer对应的是原数值，float不带单位时对应的是原数值，带"vp","fp"单位时对应的是px值，具体参考示例代码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/integer.json
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
  // 资源文件路径: src/main/resources/base/element/float.json
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
    // integer对应返回的是原数值
    let intValue = this.context.resourceManager.getNumber($r('app.integer.integer_test').id);
    console.log(`getNumber, int value: ${intValue}`);
    // 打印输出结果: getNumber, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // float对应返回的是真实像素点值，带"vp","fp"单位的像素值 = 原数值 * densityPixels
    let floatValue = this.context.resourceManager.getNumber($r('app.float.float_test').id);
    console.log(`getNumber, densityPixels: ${display.getDefaultDisplaySync().densityPixels}, float value: ${floatValue}`);
    // 打印输出结果: getNumber, densityPixels: 3.25, float value: 99.45000457763672
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resource: Resource): number

获取指定resource对象对应的integer数值或者float数值，使用同步方式返回。

> **说明**
>
> 该接口获取单位为"vp"的float值时，与参数为resId的接口获取到的值不一致，通过resId获取的值是准确的。该问题正在优化改进，推荐优先使用[getNumber](#getnumber9)或[getNumberByName](#getnumberbyname9)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明              |
| ------ | --------------- |
| number | resource对象对应的数值。<br>integer对应的是原数值，float不带单位时对应的是原数值，带"vp","fp"单位时对应的是px值。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/integer.json
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
  // 资源文件路径: src/main/resources/base/element/float.json
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
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { display } from '@kit.ArkUI';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.integer.integer_test').id
  };

  try {
    let intValue = this.context.resourceManager.getNumber(resource);
    // integer对应返回的是原数值
    console.log(`getNumber, int value: ${intValue}`);
    // 打印输出结果: getNumber, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }

  let resource2: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.float.float_test').id
  };

  try {
    // float对应返回的是真实像素点值，带"vp","fp"单位的像素值 = 原数值 * densityPixels
    // resource对象获取到的值不一致，resId获取的值是准确的。该问题正在优化改进。
    let floatValue = this.context.resourceManager.getNumber(resource2);
    console.log(`getNumber, densityPixels: ${display.getDefaultDisplaySync().densityPixels}, float value: ${floatValue}`);
    // 打印输出结果: getNumber, densityPixels: 3.25, float value: 30.600000381469727
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

获取指定资源名称对应的integer数值或者float数值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 资源名称对应的数值。<br>integer对应的是原数值，float不带单位时对应的是原数值，带"vp","fp"单位时对应的是px值。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/integer.json
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
  // 资源文件路径: src/main/resources/base/element/float.json
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
    // integer对应返回的是原数值
    let intValue = this.context.resourceManager.getNumberByName("integer_test");
    console.log(`getNumberByName, int value: ${intValue}`);
    // 打印输出结果: getNumberByName, int value: 100
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }

  try {
    // float对应返回的是真实像素点值，带"vp","fp"单位的像素值 = 原数值 * densityPixels
    let floatValue = this.context.resourceManager.getNumberByName("float_test");
    console.log(`getNumberByName, densityPixels: ${display.getDefaultDisplaySync().densityPixels}, float value: ${floatValue}`);
    // 打印输出结果: getNumberByName, densityPixels: 3.25, float value: 99.45000457763672
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resId: number) : number

获取指定资源ID对应的颜色值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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
    let colorValue = this.context.resourceManager.getColorSync($r('app.color.test').id);
    console.log(`getColorSync, result: ${colorValue}`);
    // 打印输出结果: getColorSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resource: Resource): number

获取指定resource对象对应的颜色值，使用同步方式返回。

> **说明**
>
> 该接口在深色模式下会返回浅色资源，与参数为resId的接口返回值不一致。该问题正在优化改进，推荐优先使用[getColorSync](#getcolorsync10)或[getColorByNameSync](#getcolorbynamesync10)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明               |
| ------ | ---------------- |
| number | resource对象对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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
    // 打印输出结果: getColorSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorByNameSync<sup>10+</sup>

getColorByNameSync(resName: string) : number

获取指定资源名称对应的颜色值，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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
    let colorValue = this.context.resourceManager.getColorByNameSync("test");
    console.log(`getColorByNameSync, result: ${colorValue}`);
    // 打印输出结果: getColorByNameSync, result: 4294967295
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resId: number, callback: _AsyncCallback&lt;number&gt;): void

获取指定资源ID对应的颜色值，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | 是    | 回调函数，返回资源ID值对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**示例Stage：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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

  this.context.resourceManager.getColor($r('app.color.test').id, (error: BusinessError, value: number) => {
    if (error != null) {
      console.error(`callback getColor failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getColor, result: ${value}`);
      // 打印输出结果: getColor, result: 4294967295
    }
  });
  ```

### getColor<sup>10+</sup>

getColor(resId: number): Promise&lt;number&gt;

获取指定资源ID对应的颜色值，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;number&gt; | Promise对象，返回资源ID值对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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

  this.context.resourceManager.getColor($r('app.color.test').id)
    .then((value: number) => {
      console.log(`getColor, result: ${value}`);
      // 打印输出结果: getColor, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColor failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getColor<sup>10+</sup>

getColor(resource: Resource, callback: _AsyncCallback&lt;number&gt;): void

获取指定resource对象对应的颜色值，使用callback异步回调。

> **说明**
>
> 该接口在深色模式下会返回浅色资源，与参数为resId的接口返回值不一致。该问题正在优化改进，推荐优先使用[getColor](#getcolor10)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息。            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | 是    | 回调函数，返回resource对象对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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
      // 打印输出结果: getColor, result: 4294967295
    }
  });
  ```

### getColor<sup>10+</sup>

getColor(resource: Resource): Promise&lt;number&gt;

获取指定resource对象对应的颜色值，使用Promise异步回调。

> **说明**
>
> 该接口在深色模式下会返回浅色资源，与参数为resId的接口返回值不一致。该问题正在优化改进，推荐优先使用[getColor](#getcolor10-1)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | Promise对象，返回resource对象对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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
      // 打印输出结果: getColor, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColor failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getColorByName<sup>10+</sup>

getColorByName(resName: string, callback: _AsyncCallback&lt;number&gt;): void

获取指定资源名称对应的颜色值，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称。            |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;number&gt; | 是    | 回调函数，返回资源名称对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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

  this.context.resourceManager.getColorByName("test", (error: BusinessError, value: number) => {
    if (error != null) {
      console.error(`callback getColorByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getColorByName, result: ${value}`);
      // 打印输出结果: getColorByName, result: 4294967295
    }
  });
  ```

### getColorByName<sup>10+</sup>

getColorByName(resName: string): Promise&lt;number&gt;

获取指定资源名称对应的颜色值，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;number&gt; | Promise对象，返回资源名称对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/color.json
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

  this.context.resourceManager.getColorByName("test")
    .then((value: number) => {
      console.log(`getColorByName, result: ${value}`);
      // 打印输出结果: getColorByName, result: 4294967295
    })
    .catch((error: BusinessError) => {
      console.error(`promise getColorByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getRawFileContentSync<sup>10+</sup>

getRawFileContentSync(path: string): Uint8Array

获取resources/rawfile目录下对应的rawfile文件内容，使用同步形式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径。             |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Uint8Array | 返回获取的rawfile文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

getRawFileContent(path: string, callback: _AsyncCallback&lt;Uint8Array&gt;): void

获取resources/rawfile目录下对应的rawfile文件内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径。             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Uint8Array&gt; | 是    | 回调函数，返回获取的rawfile文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

获取resources/rawfile目录下对应的rawfile文件内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回获取的rawfile文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

获取resources/rawfile目录下文件夹及文件列表，使用同步形式返回。

>**说明**
>
> 若文件夹中无文件，则抛出异常；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件夹路径。             |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Array\<string> | rawfile文件目录下的文件夹及文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // 传入""表示获取rawfile根目录下的文件列表，假设rawfile根目录下存在test.txt文件
    let fileList: Array<string> = this.context.resourceManager.getRawFileListSync("");
    console.log(`getRawFileListSync, result: ${JSON.stringify(fileList)}`);
    // 打印输出结果: getRawFileListSync, result: ["test.txt"] 
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileListSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string, callback: _AsyncCallback&lt;Array\<string\>&gt;): void

获取resources/rawfile目录下文件夹及文件列表，使用callback异步回调。

>**说明**
>
> 若文件夹中无文件，则抛出异常；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件夹路径。             |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;Array\<string\>&gt; | 是 | 回调函数，返回rawfile文件目录下的文件夹及文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 传入""表示获取rawfile根目录下的文件列表，假设rawfile根目录下存在test.txt文件
  this.context.resourceManager.getRawFileList("", (error: BusinessError, value: Array<string>) => {
    if (error != null) {
      console.error(`callback getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getRawFileListSync, result: ${JSON.stringify(value)}`);
      // 打印输出结果: getRawFileListSync, result: ["test.txt"]
    }
  });
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string): Promise&lt;Array\<string\>&gt;

获取resources/rawfile目录下文件夹及文件列表，使用Promise异步回调。

>**说明**
>
> 若文件夹中无文件，则抛出异常；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件夹路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Array\<string\>&gt; | Promise对象，返回rawfile文件目录下的文件夹及文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // 传入""表示获取rawfile根目录下的文件列表，假设rawfile根目录下存在test.txt文件
  this.context.resourceManager.getRawFileList("")
    .then((value: Array<string>) => {
      console.log(`getRawFileListSync, result: ${JSON.stringify(value)}`);
      // 打印输出结果: getRawFileListSync, result: ["test.txt"]
    })
    .catch((error: BusinessError) => {
      console.error(`promise getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getRawFdSync<sup>10+</sup>

getRawFdSync(path: string): RawFileDescriptor

获取resources/rawfile目录下rawfile文件所在HAP的文件描述符（fd）。

> **说明**
>
> 文件描述符（fd）使用完毕后需调用[closeRawFdSync](#closerawfdsync10)或[closeRawFd](#closerawfd9)关闭fd，避免资源泄露。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                     |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| [RawFileDescriptor](#rawfiledescriptor9) | rawfile文件所在HAP的文件描述符（fd）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

getRawFd(path: string, callback: _AsyncCallback&lt;RawFileDescriptor&gt;): void

获取resources/rawfile目录下对应rawfile文件所在HAP的文件描述符（fd）。

> **说明**
>
> 文件描述符（fd）使用完毕后需调用[closeRawFdSync](#closerawfdsync10)或[closeRawFd](#closerawfd9)关闭fd，避免资源泄露。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                      |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | 是    | 回调函数，返回的rawfile文件所在HAP的文件描述符（fd）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

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

获取resources/rawfile目录下rawfile文件所在HAP的文件描述符（fd）。

> **说明**
>
> 文件描述符（fd）使用完毕后需调用[closeRawFdSync](#closerawfdsync10)或[closeRawFd](#closerawfd9)关闭fd，避免资源泄露。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Promise对象，返回rawfile文件所在HAP的文件描述符（fd）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit';

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

关闭resources/rawfile目录下rawfile文件所在HAP的文件描述符（fd）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径 。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | The resource not found by path.          |

**示例：**
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

closeRawFd(path: string, callback: _AsyncCallback&lt;void&gt;): void

关闭resources/rawfile目录下rawfile文件所在HAP的文件描述符（fd），使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径。 |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;void&gt; | 是    | 回调函数。当关闭rawfile所在HAP的文件描述符（fd）成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | The resource not found by path.          |

**示例：**
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

关闭resources/rawfile目录下rawfile文件所在HAP的文件描述符（fd），使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

获取设备的Configuration，使用同步形式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| [Configuration](#configuration) | 设备的Configuration。 |

**示例：**
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

获取设备的Configuration，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                        |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[Configuration](#configuration)&gt; | 是    | 回调函数，返回设备的Configuration。 |

**示例：**
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

获取设备的Configuration，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise&lt;[Configuration](#configuration)&gt; | Promise对象，返回设备的Configuration。 |

**示例：**
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

获取设备的DeviceCapability，使用同步形式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| [DeviceCapability](#devicecapability) | 设备的DeviceCapability。 |

**示例：**
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

获取设备的DeviceCapability，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                           |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;[DeviceCapability](#devicecapability)&gt; | 是    | 回调函数，返回设备的DeviceCapability。 |

**示例：**
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

获取设备的DeviceCapability，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | Promise对象，返回设备的DeviceCapability。 |

**示例：**
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

应用运行时加载指定的资源路径，实现资源覆盖。

> **说明**
>
> rawfile和resfile目录不支持资源覆盖。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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

应用运行时移除指定的资源路径，还原被覆盖前的资源。

> **说明**
>
> rawfile和resfile目录不支持资源覆盖。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型            | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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

获取应用的语言列表。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名         | 类型    | 必填   | 说明       |
| -------------- | ------- | ------ | -------------------- |
| includeSystem  | boolean |  否    | 是否包含系统资源，默认值为false。 <br> - false：表示仅获取应用资源的语言列表。 <br> - true：表示获取系统资源和应用资源的语言列表。 <br>当使用系统资源管理对象获取语言列表时，includeSystem值无效，始终返回系统资源语言列表。|

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Array\<string> | 返回获取的语言列表，列表中的字符串由语言、脚本（可选）、地区（可选），按照顺序使用中划线“-”连接组成。|

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    this.context.resourceManager.getLocales(); // 仅获取应用资源语言列表
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }

  try {
    resourceManager.getSystemResourceManager().getLocales(); // 仅获取系统资源语言列表
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getLocales(true); // 获取应用资源和系统资源语言列表
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getLocales failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbol<sup>11+</sup>

getSymbol(resId: number): number

获取指定资源ID对应的[Symbol字符](https://developer.huawei.com/consumer/cn/design/harmonyos-symbol)Unicode码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的Symbol字符Unicode码（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let symbolValue = this.context.resourceManager.getSymbol($r('sys.symbol.message').id);
    console.log(`getSymbol, result: ${symbolValue}`);
    // 打印输出结果: getSymbol, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbol<sup>11+</sup>
getSymbol(resource: Resource): number

获取指定resource对象对应的[Symbol字符](https://developer.huawei.com/consumer/cn/design/harmonyos-symbol)Unicode码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | resource对象对应的Symbol字符Unicode码（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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
    // 打印输出结果: getSymbol, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbolByName<sup>11+</sup>

getSymbolByName(resName: string): number

获取指定资源名称对应的[Symbol字符](https://developer.huawei.com/consumer/cn/design/harmonyos-symbol)Unicode码，使用同步方式返回。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的Symbol字符Unicode码（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                     |
| 9001004  | No matching resource is found based on the resource name.       |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let symbolValue = this.context.resourceManager.getSymbolByName("message");
    console.log(`getSymbolByName, result: ${symbolValue}`);
    // 打印输出结果: getSymbolByName, result: 983183
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbolByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### isRawDir<sup>12+</sup>

isRawDir(path: string): boolean

判断指定路径是否为rawfile下的目录，使用同步方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| path | string | 是    | rawfile路径。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| boolean |是否为rawfile下的目录。<br> - true：表示是rawfile下的目录。 <br> - false：表示非rawfile下的目录。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // 假设rawfile根目录下存在非空文件夹sub，则isRawDir返回结果为true
    let isRawDir = this.context.resourceManager.isRawDir("sub");
    // 打印输出结果: sub isRawDir, result: true
    console.log(`sub isRawDir, result: ${isRawDir}`);

    // 假设rawfile根目录下存在test.txt文件，则isRawDir返回结果为false
    isRawDir = this.context.resourceManager.isRawDir("test.txt");
    // 打印输出结果: test.txt isRawDir, result: false
    console.log(`test.txt isRawDir, result: ${isRawDir}`);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`isRawDir failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getOverrideResourceManager<sup>12+</sup>

getOverrideResourceManager(configuration?: Configuration): ResourceManager

获取可以加载差异化资源的资源管理对象，使用同步方式返回。

普通的资源管理对象获取的资源的配置（语言、深浅色、分辨率、横竖屏等）是由系统决定的，而通过该接口返回的对象，应用可以获取符合指定配置的资源，即差异化资源，比如在浅色模式时可以获取深色资源。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名        | 类型                            | 必填 | 说明                                                         |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | 否   | 指定想要获取的资源配置。<br>通过[getOverrideConfiguration](#getoverrideconfiguration12)获取差异化配置后，根据需求修改配置项，再作为参数传入该函数。<br>若缺省则表示使用当前系统的configuration。 |

**返回值：**

| 类型            | 说明                               |
| --------------- | ---------------------------------- |
| ResourceManager | 可以加载差异化资源的资源管理对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types |

**示例：**

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

获取差异化资源的配置，使用同步方式返回。普通资源管理对象与通过它的[getOverrideResourceManager](#getoverrideresourcemanager12)接口获取的差异化资源管理对象调用该方法可获得相同的返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| [Configuration](#configuration) | 差异化资源的配置。 |

**示例：**

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

更新差异化资源配置。普通资源管理对象与通过它的[getOverrideResourceManager](#getoverrideresourcemanager12)接口获取的差异化资源管理对象调用该方法均可更新差异化资源管理对象的配置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名        | 类型                            | 必填 | 说明                                                         |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | 是   | 指定差异化资源的配置。通过[getOverrideConfiguration](#getoverrideconfiguration12)获取差异化配置后，根据需求修改配置项，再作为参数传入。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types |

**示例：**

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

释放创建的resourceManager, 此接口暂不支持。

> **说明**
>
> 从API version 7开始支持，从API version 12开始废弃。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**示例：**
  ```ts
  try {
    this.context.resourceManager.release();
  } catch (error) {
    console.error("release error is " + error);
  }
  ```

### getString<sup>(deprecated)</sup>

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

获取指定资源ID对应的字符串，使用callback异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getStringValue](#getstringvalue9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | 是    | 回调函数，返回资源ID值对应的字符串。 |

**示例：**
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

获取指定资源ID对应的字符串，使用Promise异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getStringValue](#getstringvalue9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的字符串。 |

**示例：**
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

获取指定资源ID对应的字符串数组，使用callback异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getStringArrayValue](#getstringarrayvalue9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值。             |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Array&lt;string&gt;&gt; | 是    | 回调函数，返回资源ID值对应的字符串数组。 |

**示例：**
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

获取指定资源ID对应的字符串数组，使用Promise异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getStringArrayValue](#getstringarrayvalue9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回资源ID值对应的字符串数组。 |

**示例：**
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

获取指定资源ID对应的媒体文件内容，使用callback异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getMediaContent](#getmediacontent9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Uint8Array&gt; | 是    | 回调函数，返回资源ID值对应的媒体文件内容。 |

**示例：**
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

获取指定资源ID对应的媒体文件内容，使用Promise异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getMediaContent](#getmediacontent9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回资源ID值对应的媒体文件内容。 |

**示例：**
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

获取指定资源ID对应的图片资源Base64编码，使用callback异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getMediaContentBase64](#getmediacontentbase649)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | 是    | 回调函数，返回资源ID值对应的图片资源Base64编码。 |

**示例：**
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

获取指定资源ID对应的图片资源Base64编码，使用Promise异步回调。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getMediaContentBase64](#getmediacontentbase649-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的图片资源Base64编码。 |

**示例：**
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

### getPluralStringValueSync<sup>(deprecated)</sup>

getPluralStringValueSync(resId: number, num: number): string

获取指定资源ID，指定资源数量的单复数字符串，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 10开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| resId  | number | 是   | 资源ID值。                                                   |
| num    | number | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型   | 说明                                             |
| ------ | ------------------------------------------------ |
| string | 根据指定数量获取指定ID字符串表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralValue = this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);
    console.log(`getPluralStringValueSync, result: ${pluralValue}`);
    // 打印输出结果: getPluralStringValueSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>(deprecated)</sup>

getPluralStringValueSync(resource: Resource, num: number): string

获取指定资源信息，指定资源数量的单复数字符串，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 10开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18-1)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9) | 是   | 资源信息。                                                   |
| num      | number                 | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型   | 说明                                                 |
| ------ | ---------------------------------------------------- |
| string | 根据指定数量获取指定resource对象表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralValue = this.context.resourceManager.getPluralStringValueSync(resource, 1);
    console.log(`getPluralStringValueSync, result: ${pluralValue}`);
    // 打印输出结果: getPluralStringValueSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringByNameSync<sup>(deprecated)</sup>

getPluralStringByNameSync(resName: string, num: number): string

获取指定资源名称，指定资源数量的单复数字符串，使用同步方式返回。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 10开始支持，从API version 18开始废弃，建议使用[getIntPluralStringByNameSync](#getintpluralstringbynamesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| resName | string | 是   | 资源名称。                                                   |
| num     | number | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型   | 说明                                             |
| ------ | ------------------------------------------------ |
| string | 根据指定数量获取指定资源名称表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
    // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
    // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
    let pluralValue = this.context.resourceManager.getPluralStringByNameSync("test", 1);
    console.log(`getPluralStringByNameSync, result: ${pluralValue}`);
    // 打印输出结果: getPluralStringByNameSync, result: 1 apple
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resId: number, num: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源ID，指定资源数量的单复数字符串，使用callback异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resId    | number                      | 是   | 资源ID值。                                                   |
| num      | number                      | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是   | 回调函数，返回资源ID值对应的指定数量的单复数字符串。           |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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

  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1,
    (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getPluralStringValue, result: ${value}`);
        // 打印输出结果: getPluralStringValue, result: 1 apple
      }
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resId: number, num: number): Promise&lt;string&gt;

获取指定资源ID，指定资源数量的单复数字符串，使用Promise异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| resId  | number | 是   | 资源ID值。                                                   |
| num    | number | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型                  | 说明                                                 |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的指定数量的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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

  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1)
    .then((value: string) => {
      console.log(`getPluralStringValue, result: ${value}`);
      // 打印输出结果: getPluralStringValue, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源信息，指定资源数量的单复数字符串，使用callback异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18-1)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9)      | 是   | 资源信息。                                                   |
| num      | number                      | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是   | 回调函数，返回resource对象对应的指定数量的单复数字符串。       |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringValue(resource, 1,
    (error: BusinessError, value: string) => {
      if (error != null) {
        console.error(`callback getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
      } else {
        console.log(`getPluralStringValue, result: ${value}`);
        // 打印输出结果: getPluralStringValue, result: 1 apple
      }
    });
  ```

### getPluralStringValue<sup>(deprecated)</sup>

getPluralStringValue(resource: Resource, num: number): Promise&lt;string&gt;

获取指定资源信息，指定资源数量的单复数字符串，使用Promise异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18-1)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| resource | [Resource](#resource9) | 是   | 资源信息。                                                   |
| num      | number                 | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型                  | 说明                                                     |
| --------------------- | -------------------------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回resource对象对应的指定数量的单复数字符串。  |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001001  | Invalid resource ID.                                         |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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
  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringValue(resource, 1)
    .then((value: string) => {
      console.log(`getPluralStringValue, result: ${value}`);
      // 打印输出结果: getPluralStringValue, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringValue failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralStringByName<sup>(deprecated)</sup>

getPluralStringByName(resName: string, num: number, callback: _AsyncCallback&lt;string&gt;): void

获取指定资源名称，指定资源数量的单复数字符串，使用callback异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringByNameSync](#getintpluralstringbynamesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| resName  | string                      | 是   | 资源名称。                                                   |
| num      | number                      | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |
| callback | [_AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;string&gt; | 是   | 回调函数，返回资源名称对应的指定数量的单复数字符串。             |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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

  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringByName("test", 1, (error: BusinessError, value: string) => {
    if (error != null) {
      console.error(`callback getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    } else {
      console.log(`getPluralStringByName, result: ${value}`);
      // 打印输出结果: getPluralStringByName, result: 1 apple
    }
  });
  ```

### getPluralStringByName<sup>(deprecated)</sup>

getPluralStringByName(resName: string, num: number): Promise&lt;string&gt;

获取指定资源名称，指定资源数量的单复数字符串，使用Promise异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 9开始支持，从API version 18开始废弃，建议使用[getIntPluralStringByNameSync](#getintpluralstringbynamesync18)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| resName | string | 是   | 资源名称。                                                   |
| num     | number | 是   | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型                  | 说明                                             |
| --------------------- | ------------------------------------------------ |
| Promise&lt;string&gt; | 根据传入的数量值，获取资源名称对应的字符串资源。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types. |
| 9001003  | Invalid resource name.                                       |
| 9001004  | No matching resource is found based on the resource name.    |
| 9001006  | The resource is referenced cyclically.                       |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/plural.json
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

  // 根据语言单复数规则，参数num取值为1，英文环境下对应单复数类别为one
  // 在资源文件中用quantity字段表示单复数类别，因此会获取quantity为one的字符串
  this.context.resourceManager.getPluralStringByName("test", 1)
    .then((value: string) => {
      console.log(`getPluralStringByName, result: ${value}`);
      // 打印输出结果: getPluralStringByName, result: 1 apple
    })
    .catch((error: BusinessError) => {
      console.error(`promise getPluralStringByName failed, error code: ${error.code}, message: ${error.message}.`);
    });
  ```

### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number): Promise&lt;string&gt;

获取指定资源ID，指定资源数量的单复数字符串，使用Promise异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| num   | number | 是    | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回资源ID值对应的指定数量的单复数字符串。 |

**示例：**

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

获取指定资源ID，指定资源数量的单复数字符串，使用callback异步回调。

> **说明**
>
> 中文环境下，字符串不区分单复数；其他语言环境下，字符串区分单复数，具体规则参考[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getIntPluralStringValueSync](#getintpluralstringvaluesync18)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | 是    | 资源ID值。                           |
| num      | number                      | 是    | 数量值。根据当前语言的复数规则获取该数量值对应的字符串数字，语言的复数规则参见[语言单复数规则](https://www.unicode.org/cldr/charts/45/supplemental/language_plural_rules.html)。 |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;string&gt; | 是    | 回调函数，返回资源ID值对应的指定数量的单复数字符串。 |

**示例：**

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


### getRawFile<sup>(deprecated)</sup>

getRawFile(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

获取resources/rawfile目录下对应的rawfile文件内容，使用callback异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getRawFileContent](#getrawfilecontent9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径。             |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;Uint8Array&gt; | 是    | 回调函数，返回rawfile文件内容。 |

**示例：**
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

获取resources/rawfile目录下对应的rawfile文件内容，使用Promise异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getRawFileContent](#getrawfilecontent9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回rawfile文件内容。 |

**示例：**
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

获取resources/rawfile目录下对应rawfile文件的文件描述符（fd），使用callback异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getRawFd](#getrawfd9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                      |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | 是    | 回调函数，返回rawfile文件的文件描述符（fd）。 |

**示例：**
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

获取resources/rawfile目录下对应rawfile文件的文件描述符（fd），使用Promise异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getRawFd](#getrawfd9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor9)&gt; | Promise对象，返回rawfile文件的文件描述符（fd）。 |

**示例：**
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

关闭resources/rawfile目录下rawfile文件的文件描述符（fd），使用callback异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[closeRawFd](#closerawfd9)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 



| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径。 |
| callback | [AsyncCallback](#asynccallbackdeprecated)&lt;void&gt; | 是    | 回调函数。当关闭rawfile文件的文件描述符（fd）成功，err为undefined，否则为错误对象。|

**示例：**
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

关闭resources/rawfile目录下rawfile文件的文件描述符（fd），使用Promise异步回调。

> **说明**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[closeRawFd](#closerawfd9-1)替代。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit';

  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt");
  });
  ```

## AsyncCallback<sup>(deprecated)</sup>

  ```ts
  AsyncCallback<T> {
    (err: Error, data: T): void;
  }
  ```

异步回调函数，携带错误参数和异步返回值。

> **说明**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)替代。

**系统能力：** SystemCapability.Global.ResourceManager

| 参数名 | 类型                                                         | 必填 | 说明                         |
| ---- | ------------------------------------------------------------ | ---- | ---------------------------- |
| err  | Error | 是   | 接口调用失败的错误信息。 |
| data | T     | 是   | 接口调用时的回调信息。|

## 附录

- 示例代码中用到的'app.string.test'文件内容如下：

    ```json
    // 资源文件路径: src/main/resources/base/element/string.json
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
    // 资源文件路径: src/main/resources/base/element/string.json
    {
      "string": [
        {
          "name": "test",
          "value": "I'm a %1$s, format int: %2$d, format float: %3$f."
        }
      ]
    }
    ```

- 示例代码中用到的'app.strarray.test'文件内容如下：

    ```json
    // 资源文件路径: src/main/resources/base/element/strarray.json
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

- 示例代码中用到的'app.plural.test'文件内容如下：
    ```json
    // 资源文件路径: src/main/resources/base/element/plural.json
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

- 示例代码中用到的'app.plural.format_test'文件内容如下：

    ```json
    // 资源文件路径: src/main/resources/base/element/plural.json
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

- 示例代码中用到的'app.boolean.boolean_test'文件内容如下：
    ```json
    // 资源文件路径: src/main/resources/base/element/boolean.json
    {
      "boolean": [
        {
          "name": "boolean_test",
          "value": true
        }
      ]
    }
    ```

- 示例代码中用到的"integer_test"和"float_test"文件内容如下：
    ```json
    // 资源文件路径: src/main/resources/base/element/integer.json
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
    // 资源文件路径: src/main/resources/base/element/float.json
    {
      "float": [
        {
          "name": "float_test",
          "value": "30.6vp"
        }
      ]
    }
    ```
- 示例代码中用到的'app.color.test'文件内容如下：
    ```json
    // 资源文件路径: src/main/resources/base/element/color.json
    {
      "color": [
        {
          "name": "test",
          "value": "#FFFFFF"
        }
      ]
    }
    ```
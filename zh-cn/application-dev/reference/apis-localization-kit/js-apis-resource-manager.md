# @ohos.resourceManager (资源管理)

资源管理模块，根据当前configuration：语言、区域、横竖屏、Mcc（移动国家码）和Mnc（移动网络码）、Device capability（设备类型）、Density（分辨率）提供获取应用资源信息读取接口。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## 使用说明

从API Version9开始，Stage模型通过context获取resourceManager对象的方式后，可直接调用其内部获取资源的接口，无需再导入包。
FA模型仍需要先导入包，再调用[getResourceManager](#resourcemanagergetresourcemanager)接口获取资源对象。 
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

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                            |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | 是    |返回资源管理ResourceManager对象。 |

**示例：** 
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

获取指定应用的资源管理对象，使用callback异步回调。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型                                       | 必填   | 说明                            |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | 是    | 应用的Bundle名称。                 |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | 是    | 返回资源管理ResourceManager对象。 |

**示例：** 
  <!--code_no_check_fa-->
  ```js
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```

## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

获取当前应用的资源管理对象，使用Promise异步回调。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**返回值：**

| 类型                                       | 说明                |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | 返回资源管理ResourceManager对象。 |

**示例：** 
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

获取指定应用的资源管理对象，使用Promise异步回调。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | 是    | 应用的Bundle名称。 |

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | 返回资源管理ResourceManager对象。 |

**示例：** 
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

获取系统资源管理对象，返回系统资源的ResourceManager对象。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| [Resourcemanager](#resourcemanager) | 返回系统资源的管理对象。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001009  | Failed to access the system resource.which is not mapped to application sandbox, This error code will be thrown. |

**示例：**
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

用于表示设备屏幕方向。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | 竖屏。   |
| DIRECTION_HORIZONTAL | 1    | 横屏。   |


## DeviceType

用于表示当前设备类型。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager
<!--RP1-->
| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_PHONE    | 0x00 | 手机。   |
| DEVICE_TYPE_TABLET   | 0x01 | 平板。   |
| DEVICE_TYPE_CAR      | 0x02 | 汽车。   |
| DEVICE_TYPE_TV       | 0x04 | 电视。  |
| DEVICE_TYPE_WEARABLE | 0x06 | 穿戴。   |
| DEVICE_TYPE_2IN1<sup>11+</sup>     | 0x07 | 2in1。   |
<!--RP1End-->

## ScreenDensity

用于表示当前设备屏幕密度。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称             | 值  | 说明         |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | 小规模的屏幕密度。  |
| SCREEN_MDPI    | 160  | 中规模的屏幕密度。   |
| SCREEN_LDPI    | 240  | 大规模的屏幕密度。   |
| SCREEN_XLDPI   | 320  | 特大规模的屏幕密度。  |
| SCREEN_XXLDPI  | 480  | 超大规模的屏幕密度。  |
| SCREEN_XXXLDPI | 640  | 超特大规模的屏幕密度。 |


## ColorMode<sup>12+</sup>

用于表示当前设备颜色模式。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称  | 值   | 说明       |
| ----- | ---- | ---------- |
| DARK  | 0    | 深色模式。 |
| LIGHT | 1    | 浅色模式。 |


## Configuration

表示当前设备的状态。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称                        | 类型                            | 可读 | 可写 | 说明               |
| --------------------------- | ------------------------------- | ---- | ---- | ------------------ |
| direction                   | [Direction](#direction)         | 是   | 是   | 屏幕方向。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。         |
| locale                      | string                          | 是   | 是   | 语言文字国家地区。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| deviceType<sup>12+</sup>    | [DeviceType](#devicetype)       | 是   | 是   | 设备类型。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。         |
| screenDensity<sup>12+</sup> | [ScreenDensity](#screendensity) | 是   | 是   | 屏幕密度。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。         |
| colorMode<sup>12+</sup>     | [ColorMode](#colormode12)       | 是   | 是   | 颜色模式。 <br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。        |
| mcc<sup>12+</sup>           | number                          | 是   | 是   | 移动国家码。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |
| mnc<sup>12+</sup>           | number                          | 是   | 是   | 移动网络码。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |



## DeviceCapability

表示设备支持的能力。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称            | 类型                            | 可读   | 可写   | 说明       |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | 是    | 否    | 当前设备屏幕密度。 |
| deviceType    | [DeviceType](#devicetype)       | 是    | 否    | 当前设备类型。   |


## RawFileDescriptor<sup>8+</sup>

type RawFileDescriptor = _RawFileDescriptor

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_RawFileDescriptor](rawFileDescriptor.md#rawfiledescriptor-1)|表示rawfile文件所在hap的descriptor信息。|

## Resource<sup>9+</sup>

type Resource = _Resource

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_Resource](resource.md#resource-1)|表示资源信息。|

## ResourceManager

提供访问应用资源的能力。

> **说明：**
>
> - ResourceManager涉及到的方法，仅限基于TS扩展的声明式开发范式使用。
>
> - 资源文件在工程的resources目录中定义，通过resId、resName、resource对象等可以获取对应的字符串、字符串数组等，resId可通过`$r(资源地址).id`的方式获取，例如`$r('app.string.test').id`。
>
> - resource对象适用于多工程应用内的跨包访问，因resource对象需创建对应module的context获取资源，故相比于入参为resId、resName的接口耗时长。
>
> - 单HAP包和跨HAP/HSP包资源的访问方式具体请参考[资源访问](../../quick-start/resource-categories-and-access.md#资源访问)。
>
> - 示例代码中test文件的具体内容请参考[附录](#附录)。

### getStringSync<sup>9+</sup>

getStringSync(resId: number): string

用户获取指定资源ID对应的字符串，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

用户获取指定资源ID对应的字符串，根据args参数进行格式化，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| ...args | Array<string \| number> | 否    | 格式化字符串资源参数。<br>支持参数类型：%d、%f、%s、%%、%数字`$d`、%数字`$f`、%数字`$s`。<br>说明：%%转义为%; %数字`$d`表示使用第几个参数。<br>举例：%%d格式化后为%d字符串; %1`$d`表示使用第一个参数。|

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

用户获取指定resource对象对应的字符串，使用同步方式返回字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

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

用户获取指定resource对象对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| ...args | Array<string \| number> | 否    | 格式化字符串资源参数。<br>支持参数类型：%d、%f、%s、%%、%数字`$d`、%数字`$f`、%数字`$s`。<br>说明：%%转义为%; %数字`$d`表示使用第几个参数。<br>举例：%%d格式化后为%d字符串; %1`$d`表示使用第一个参数。|

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

用户获取指定资源名称对应的字符串，使用同步方式返回字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

用户获取指定资源名称对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| ...args | Array<string \| number> | 否    | 格式化字符串资源参数。<br>支持参数类型：%d、%f、%s、%%、%数字`$d`、%数字`$f`、%数字`$s`。<br>说明：%%转义为%; %数字`$d`表示使用第几个参数。<br>举例：%%d格式化后为%d字符串; %1`$d`表示使用第一个参数。|

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

用户获取指定资源ID对应的字符串，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**示例Stage：** 
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

用户获取指定资源ID对应的字符串，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | 资源ID值对应的字符串。 |

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

用户获取指定resource对象对应的字符串，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息。            |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定resource对象对应的字符串，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | resource对象对应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定资源名称对应的字符串，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称。            |
| callback | AsyncCallback&lt;string&gt; | 是    |返回获取的字符串。 |

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

用户获取指定资源名称对应的字符串，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;string&gt; | 资源名称对应的字符串。 |

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

用户获取指定资源ID对应的字符串数组，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 资源ID值对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getStringArrayValueSync($r('app.strarray.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getStringArrayValueSync<sup>10+</sup>

getStringArrayValueSync(resource: Resource): Array&lt;string&gt;

用户获取指定resource对象对应的字符串数组，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | resource对象对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定资源名称对应的字符串数组，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 对应资源名称的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定资源ID对应的字符串数组，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值。             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 返回获取的字符串数组。 |

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

用户获取指定资源ID对应的字符串数组，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | 资源ID值对应的字符串数组。 |

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

用户获取指定resource对象对应的字符串数组，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | 是    | 资源信息。              |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 返回获取的字符串数组。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定resource对象对应的字符串数组，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                                 | 说明                 |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | resource对象对应的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

用户获取指定资源名称对应的字符串数组，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | 是    | 资源名称。              |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 返回获取的字符串数组。 |

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

用户获取指定资源名称对应的字符串数组，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                                 | 说明           |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;string&gt;&gt; | 资源名称对应的字符串数组。 |

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

根据指定数量获取指定ID字符串表示的单复数字符串，使用同步方式返回。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| num   | number | 是    | 数量值。   |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| string   | 根据指定数量获取指定ID字符串表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getPluralStringValueSync<sup>10+</sup>

getPluralStringValueSync(resource: Resource, num: number): string

根据指定数量获取指定resource对象表示的单复数字符串，使用同步方式返回。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| num      | number                 | 是    | 数量值。   |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 根据指定数量获取指定resource对象表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

根据指定数量获取指定资源名称表示的单复数字符串，使用同步方式返回。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |
| num      | number                 | 是    | 数量值。   |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 根据指定数量获取指定资源名称表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001003  | Invalid resource name.                       |
| 9001004  | No matching resource is found based on the resource name.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

根据指定数量获取指定ID字符串表示的单复数字符串，使用callback异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | 是    | 资源ID值。                           |
| num      | number                      | 是    | 数量值。                             |
| callback | AsyncCallback&lt;string&gt; | 是    | 根据指定数量，获取指定ID字符串表示的单复数字符串。 |

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

根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| num   | number | 是    | 数量值。  |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | 根据提供的数量，获取对应ID字符串表示的单复数字符串。 |

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

根据指定数量获取指定resource对象表示的单复数字符串，使用callback异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                                   |
| -------- | --------------------------- | ---- | ------------------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息。                                 |
| num      | number                      | 是    | 数量值。                                  |
| callback | AsyncCallback&lt;string&gt; | 是    | 根据指定数量，获取指定resource对象表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

根据指定数量获取对指定resource对象表示的单复数字符串，使用Promise异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| num      | number                 | 是    | 数量值。  |

**返回值：**

| 类型                    | 说明                             |
| --------------------- | ------------------------------ |
| Promise&lt;string&gt; | 根据提供的数量，获取对应resource对象表示的单复数字符串。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.                |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：** 
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

根据传入的数量值，获取资源名称对应的字符串资源，使用callback异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                            |
| -------- | --------------------------- | ---- | ----------------------------- |
| resName  | string                      | 是    | 资源名称。                          |
| num      | number                      | 是    | 数量值。                           |
| callback | AsyncCallback&lt;string&gt; | 是    | 根据传入的数量值，获取资源名称对应的字符串资源。 |

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

根据传入的数量值，获取资源名称对应的字符串资源，使用Promise异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| num     | number | 是    | 数量值。  |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;string&gt; | 根据传入的数量值，获取资源名称对应的字符串资源。 |

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

用户获取指定资源ID对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定resource对象对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
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

用户获取指定资源名称对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Uint8Array | 对应资源名称的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getMediaContent(resId: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

用户获取指定资源ID对应的媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

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

getMediaContent(resId: number, density: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

用户获取指定资源ID对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

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

用户获取指定资源ID对应的媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容。 |

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

用户获取指定资源ID对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getMediaContent(resource: Resource, callback: AsyncCallback&lt;Uint8Array&gt;): void

用户获取指定resource对象对应的媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息。               |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息。               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | resource对象对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定资源名称对应的媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称。               |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

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

getMediaByName(resName: string, density: number, callback: AsyncCallback&lt;Uint8Array&gt;): void

用户获取指定资源名称对应的指定屏幕密度媒体文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称。               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源名称对应的媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | 资源名称对应的媒体文件内容。 |

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

用户获取指定资源名称对应的指定屏幕密度媒体文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | 资源名称对应的媒体文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源ID对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定resource对象对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
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

用户获取指定资源名称对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getMediaContentBase64(resId: number, callback: AsyncCallback&lt;string&gt;): void

用户获取指定资源ID对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** Content

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的图片资源Base64编码。 |

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

getMediaContentBase64(resId: number, density: number, callback: AsyncCallback&lt;string&gt;): void

用户获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;string&gt; | 是    | 获取的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源ID对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码。 |

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

用户获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getMediaContentBase64(resource: Resource, callback: AsyncCallback&lt;string&gt;): void

用户获取指定resource对象对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息。                     |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息。                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;string&gt; | 是    | 获取的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | resource对象对应的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |

**示例：** 
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

用户获取指定资源名称对应的图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称。                     |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的图片资源Base64编码。 |

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

getMediaBase64ByName(resName: string, density: number, callback: AsyncCallback&lt;string&gt;): void

用户获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称。                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的图片资源Base64编码。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源名称对应的图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | 资源名称对应的图片资源Base64编码。 |

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

用户获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度。    |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | 资源名称对应的图片资源Base64编码 。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源ID对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源。 |

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

用户获取指定resource对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源。 |

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
  import { resourceManager } from '@kit.LocalizationKit'
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

用户获取指定资源名称对应的DrawableDescriptor对象，用于图标的显示，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度。 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 资源ID值对应的DrawableDescriptor对象。 |

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

使用同步方式，返回获取指定资源ID对应的布尔结果。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 资源ID值对应的布尔结果。 |

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
    this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);
  }
  ```
### getBoolean<sup>9+</sup>

getBoolean(resource: Resource): boolean

使用同步方式，返回获取指定resource对象对应的布尔结果。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型      | 说明                |
| ------- | ----------------- |
| boolean | resource对象对应的布尔结果。 |

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

使用同步方式，返回获取指定资源名称对应的布尔结果。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型      | 说明          |
| ------- | ----------- |
| boolean | 资源名称对应的布尔结果。 |

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
    this.context.resourceManager.getBooleanByName("boolean_test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getBooleanByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resId: number): number

用户获取指定资源ID对应的integer数值或者float数值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- | 
| number | 资源ID值对应的数值。integer对应的是原数值，float对应的是真实像素点值，具体参考示例代码。 |

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
    this.context.resourceManager.getNumber($r('app.integer.integer_test').id); // integer对应返回的是原数值
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }

  try {
    this.context.resourceManager.getNumber($r('app.float.float_test').id); // float对应返回的是真实像素点值
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumber<sup>9+</sup>

getNumber(resource: Resource): number

用户获取指定resource对象对应的integer数值或者float数值，使用同步方式返回。

> **说明**
>
> 使用接口获取单位为"vp"的float值时，通过resId和resource对象获取到的值不一致，resId获取的值是准确的。该问题正在优化改进。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明              |
| ------ | --------------- |
| number | 资源名称对应的数值。<br>integer对应的是原数值，float不带单位时对应的是原数值，带"vp","fp"单位时对应的是px值。 |

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

用户获取指定资源名称对应的integer数值或者float数值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

用户获取指定资源ID对应的颜色值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getColorSync($r('app.color.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColorSync<sup>10+</sup>

getColorSync(resource: Resource): number

用户获取指定resource对象对应的颜色值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明               |
| ------ | ---------------- |
| number | resource对象对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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

用户获取指定资源名称对应的颜色值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getColorByNameSync("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getColorByNameSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getColor<sup>10+</sup>

getColor(resId: number, callback: AsyncCallback&lt;number&gt;): void;

用户获取指定资源ID对应的颜色值，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | AsyncCallback&lt;number&gt; | 是    | 返回获取的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | If the module resId invalid.             |
| 9001002  | No matching resource is found based on the resource ID.      |
| 9001006  | The resource is referenced cyclically.         |

**示例Stage：**
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

用户获取指定资源ID对应的颜色值，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;number&gt; | 资源ID值对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定resource对象对应的颜色值，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息。            |
| callback | AsyncCallback&lt;number&gt; | 是    | 返回获取的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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

用户获取指定resource对象对应的颜色值，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | resource对象对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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

用户获取指定资源名称对应的颜色值，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称。            |
| callback | AsyncCallback&lt;number&gt; | 是    | 异步回调，用于返回获取的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取指定资源名称对应的颜色值，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;number&gt; | 资源名称对应的颜色值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用同步形式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getRawFileContent(path: string, callback: AsyncCallback&lt;Uint8Array&gt;): void

用户获取resources/rawfile目录下对应的rawfile文件内容，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径。             |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的rawfile文件内容。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |

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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | rawfile文件内容。 |

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

用户获取resources/rawfile目录下文件夹及文件列表，使用同步形式返回。

>**说明**
>
> 若文件夹中无文件，则不返回；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // 传入""表示获取rawfile根目录下的文件列表
    this.context.resourceManager.getRawFileListSync("")
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getRawFileListSync failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getRawFileList<sup>10+</sup>

getRawFileList(path: string, callback: AsyncCallback&lt;Array\<string\>&gt;): void;

用户获取resources/rawfile目录下文件夹及文件列表，使用callback异步回调。

>**说明**
>
> 若文件夹中无文件，则不返回；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件夹路径。             |
| callback | AsyncCallback&lt;Array\<string\>&gt; | 是 | rawfile文件目录下的文件夹及文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.       |

**示例：** 
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // 传入""表示获取rawfile根目录下的文件列表
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

用户获取resources/rawfile目录下文件夹及文件列表，使用Promise异步回调。

>**说明**
>
> 若文件夹中无文件，则不返回；若文件夹中有文件，则返回文件夹及文件列表。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件夹路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Array\<string\>&gt; | rawfile文件目录下的文件夹及文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try { // 传入""表示获取rawfile根目录下的文件列表
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

用户获取resources/rawfile目录下rawfile文件所在hap的descriptor信息。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                     |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| [RawFileDescriptor](#rawfiledescriptor8) | rawfile文件所在hap的descriptor信息。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

getRawFd(path: string, callback: AsyncCallback&lt;RawFileDescriptor&gt;): void

用户获取resources/rawfile目录下对应rawfile文件所在hap的descriptor信息，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                      |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | 是    | 返回获取的rawfile文件所在hap的descriptor信息。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：** 
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

用户获取resources/rawfile目录下rawfile文件所在hap的descriptor信息，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | rawfile文件所在hap的descriptor信息。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：** 
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

用户关闭resources/rawfile目录下rawfile文件所在hap的descriptor信息。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径 。|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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

closeRawFd(path: string, callback: AsyncCallback&lt;void&gt;): void

用户关闭resources/rawfile目录下rawfile文件所在hap的descriptor信息，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 异步回调。        |

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

用户关闭resources/rawfile目录下rawfile文件所在hap的descriptor信息，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

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

用户获取设备的Configuration，使用同步形式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

getConfiguration(callback: AsyncCallback&lt;Configuration&gt;): void

用户获取设备的Configuration，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                        |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | 是    | 返回设备的Configuration。 |

**示例：** 
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

用户获取设备的Configuration，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise&lt;[Configuration](#configuration)&gt; | 设备的Configuration。 |

**示例：** 
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

用户获取设备的DeviceCapability，使用同步形式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

getDeviceCapability(callback: AsyncCallback&lt;DeviceCapability&gt;): void

用户获取设备的DeviceCapability，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                           |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | 是    | 返回设备的DeviceCapability。 |

**示例：** 
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

用户获取设备的DeviceCapability，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | 设备的DeviceCapability。 |

**示例：** 
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

应用运行时，加载指定的资源路径，实现资源覆盖。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**示例：**
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

用户运行时，移除指定的资源路径，还原被覆盖前的资源。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型            | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001010  | Invalid overlay path.            |

**示例：**
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

获取应用的语言列表。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名         | 类型    | 必填   | 说明       |
| -------------- | ------- | ------ | -------------------- |
| includeSystem  | boolean |  否    | 是否包含系统资源，默认值为false。 <br> false：表示仅获取应用资源的语言列表。 <br>true：表示获取系统资源和应用资源的语言列表。 <br>当系统资源管理对象获取语言列表时，includeSystem值无效，返回获取系统资源语言列表 。|

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Array\<string> | 返回获取的语言列表，列表中的字符串由语言、脚本(可选)、地区(可选)，按照顺序使用中划线"-"连接组成。|

**示例：**
  ```ts
  import { resourceManager } from '@kit.LocalizationKit'
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

getSymbol(resId: number):number

用户获取指定资源ID对应的符号值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的符号值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getSymbol($r('app.symbol.test').id);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbol failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getSymbol<sup>11+</sup>
getSymbol(resource: Resource): number

用户获取指定resource对象对应的符号值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | resource对象对应的符号值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001001  | Invalid resource ID.                       |
| 9001002  | No matching resource is found based on the resource ID.         |
| 9001006  | The resource is referenced cyclically.            |

**示例：**
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

用户获取指定资源名称对应的符号值，使用同步方式返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的符号值（十进制）。 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

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
    this.context.resourceManager.getSymbolByName("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbolByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### isRawDir<sup>12+</sup>

isRawDir(path: string) : bool

用户判断指定路径是否是rawfile下的目录，使用同步方式返回。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| path | string | 是    | rawfile路径。 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| bool |是否是rawfile下的目录。<br>true：表示是rawfile下的目录 <br>false：表示不是rawfile下的目录|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: Incorrect parameter types.               |
| 9001005  | Invalid relative path.          |

**示例：**
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

获取可以加载差异化资源的资源管理对象，使用同步方式返回。

普通的资源管理对象获取的资源的样式（语言、深浅色、分辨率、横竖屏等）是由系统决定的，而通过该接口返回的对象，应用可以获取符合指定配置的资源，即差异化资源，比如浅色模式时可以获取深色资源。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名        | 类型                            | 必填 | 说明                                                         |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | 否   | 指定想要获取的资源样式。<br>通过[getOverrideConfiguration](#getoverrideconfiguration12)获取差异化配置后，根据需求修改配置项，再作为参数传入该函数。<br>若缺省则获取与当前系统最匹配的资源。 |

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

获取差异化资源的配置，使用同步方式返回。普通资源管理对象与通过它的[getOverrideResourceManager](#getoverrideresourcemanager12)接口获取的差异化资源管理对象调用该方法可获得相同的返回值。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| [Configuration](#configuration) | 差异化资源的配置。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { resourceManager } from '@kit.LocalizationKit'

  let overrideConfig = this.context.resourceManager.getOverrideConfiguration()
  ```

### updateOverrideConfiguration<sup>12+</sup>

updateOverrideConfiguration(configuration: Configuration) : void

更新差异化资源配置。普通资源管理对象与通过它的[getOverrideResourceManager](#getoverrideresourcemanager12)接口获取的差异化资源管理对象调用该方法均可更新差异化资源管理对象的配置。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名        | 类型                            | 必填 | 说明                                                         |
| ------------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| configuration | [Configuration](#configuration) | 是   | 指定差异化资源的配置项。通过[getOverrideConfiguration](#getoverrideconfiguration12)获取差异化配置后，根据需求修改配置项，再作为参数传入。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | If the input parameter invalid. Possible causes: Incorrect parameter types |

**示例：**

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

用户释放创建的resourceManager, 此接口暂不支持。

从API version 7开始支持，API version 12开始不再维护。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

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

用户获取指定资源ID对应的字符串，使用callback异步回调。

从API version 9开始不再维护，建议使用[getStringValue](#getstringvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值。           |
| callback | AsyncCallback&lt;string&gt; | 是    | 返回获取的字符串。 |

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

用户获取指定资源ID对应的字符串，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getStringValue](#getstringvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | 资源ID值对应的字符串。 |

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

用户获取指定资源ID对应的字符串数组，使用callback异步回调。

从API version 9开始不再维护，建议使用[getStringArrayValue](#getstringarrayvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值。             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 返回获取的字符串数组。 |

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

用户获取指定资源ID对应的字符串数组，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getStringArrayValue](#getstringarrayvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | 资源ID值对应的字符串数组。 |

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

用户获取指定资源ID对应的媒体文件内容，使用callback异步回调。

从API version 9开始不再维护，建议使用[getMediaContent](#getmediacontent9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值。              |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 返回获取的媒体文件内容。 |

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

用户获取指定资源ID对应的媒体文件内容，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getMediaContent](#getmediacontent9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容。 |

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

用户获取指定资源ID对应的图片资源Base64编码，使用callback异步回调。

从API version 9开始不再维护，建议使用[getMediaContentBase64](#getmediacontentbase649)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值。                    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码。 |

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

用户获取指定资源ID对应的图片资源Base64编码，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getMediaContentBase64](#getmediacontentbase649-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码。 |

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


### getPluralString<sup>(deprecated)</sup>

getPluralString(resId: number, num: number): Promise&lt;string&gt;

根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

从API version 9开始不再维护，建议使用[getPluralStringValue](#getpluralstringvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值。 |
| num   | number | 是    | 数量值。   |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | 根据提供的数量获取对应ID字符串表示的单复数字符串。 |

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

根据指定数量获取指定ID字符串表示的单复数字符串，使用callback异步回调。

>**说明**
>
> 中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

从API version 9开始不再维护，建议使用[getPluralStringValue](#getpluralstringvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | 是    | 资源ID值。                           |
| num      | number                      | 是    | 数量值。                             |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串。 |

**示例：** 
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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用callback异步回调。

从API version 9开始不再维护，建议使用[getRawFileContent](#getrawfilecontent9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径。             |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的rawfile文件内容。 |

**示例：** 
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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getRawFileContent](#getrawfilecontent9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | rawfile文件内容。 |

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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用callback异步回调。

从API version 9开始不再维护，建议使用[getRawFd](#getrawfd9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径。                      |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | 是    | 异步回调，用于返回获取的rawfile文件的descriptor。 |

**示例：** 
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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用Promise异步回调。

从API version 9开始不再维护，建议使用[getRawFd](#getrawfd9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | rawfile文件descriptor。 |

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

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用callback异步回调。

从API version 9开始不再维护，建议使用[closeRawFd](#closerawfd9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 



| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 异步回调。        |

**示例：** 
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

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用Promise异步回调。

从API version 9开始不再维护，建议使用[closeRawFd](#closerawfd9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径。 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | 无返回值。 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt");
  });
  ```

### 附录

- 示例代码中用到的'app.string.test'文件内容如下：

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

- 示例代码中用到的'app.strarray.test'文件内容如下：

    ```json
    {
    "strarray": [
        {
        "name": "test",
        "value": [
          {
            "value": "strarray_test"
          }
        ]
        }
    ]
    }
    ```  

- 示例代码中用到的'app.plural.test'文件内容如下：
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

- 示例代码中用到的'app.boolean.boolean_test'文件内容如下：
    ```json
    {
    "boolean": [
        {
        "name": "boolean_test",
        "value": true
        }
    
    }
    ``` 

- 示例代码中用到的"integer_test"和"float_test"文件内容如下：
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
- 示例代码中用到的'app.color.test'文件内容如下：
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
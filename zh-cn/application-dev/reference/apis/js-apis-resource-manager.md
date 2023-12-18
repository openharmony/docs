# @ohos.resourceManager (资源管理)

资源管理模块，根据当前configuration：语言、区域、横竖屏、Mcc（移动国家码）和Mnc（移动网络码）、Device capability（设备类型）、Density（分辨率）提供获取应用资源信息读取接口。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import resourceManager from '@ohos.resourceManager';
```

## 使用说明

从API Version9开始，Stage模型通过context获取resourceManager对象的方式后，可直接调用其内部获取资源的接口，无需再导入包。此方式FA模型不适用，FA模型还需要先导入包，再调用[getResourceManager](#resourcemanagergetresourcemanager)接口获取资源对象。
Stage模型下Context的引用方法请参考[Stage模型的Context详细介绍](../../application-models/application-context-stage.md)。

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let context = this.context;
    let resourceManager = context.resourceManager;
  }
}
```

## resourceManager.getResourceManager

getResourceManager(callback: AsyncCallback&lt;ResourceManager&gt;): void

获取当前应用的资源管理对象，使用callback形式返回ResourceManager对象。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                            |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | 是    | callback方式返回ResourceManager对象 |

**示例：** 
  ```js
  resourceManager.getResourceManager((error, mgr) => {
    if (error != null) {
      console.error("error is " + error);
      return;
    }
    mgr.getStringValue(0x1000000, (error, value) => {
      if (error != null) {
        console.error("error is " + error);
      } else {
        let str = value;
      }
    });
  });
  ```
注：示例代码中的0x1000000表示资源对应的id, 其可在编译后的文件ResourceTable.txt中找到。


## resourceManager.getResourceManager

getResourceManager(bundleName: string, callback: AsyncCallback&lt;ResourceManager&gt;): void

获取指定应用的资源管理对象，使用callback形式返回ResourceManager对象。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型                                       | 必填   | 说明                            |
| ---------- | ---------------------------------------- | ---- | ----------------------------- |
| bundleName | string                                   | 是    | 指定应用的Bundle名称                 |
| callback   | AsyncCallback&lt;[ResourceManager](#resourcemanager)&gt; | 是    | callback方式返回ResourceManager对象 |

**示例：** 
  ```js
  resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
  });
  ```


## resourceManager.getResourceManager

getResourceManager(): Promise&lt;ResourceManager&gt;

获取当前应用的资源管理对象，使用Promise形式返回ResourceManager对象。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**返回值：**

| 类型                                       | 说明                |
| ---------------------------------------- | ----------------- |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise方式返回资源管理对象 |

**示例：** 
  ```js
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  resourceManager.getResourceManager().then((mgr: resourceManager.ResourceManager) => {
    mgr.getStringValue(0x1000000, (error, value) => {
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
注：示例代码中的0x1000000表示资源对应的id, 其可在编译后的文件ResourceTable.txt中找到。


## resourceManager.getResourceManager

getResourceManager(bundleName: string): Promise&lt;ResourceManager&gt;

获取指定应用的资源管理对象，使用Promise形式返回ResourceManager对象。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在FA模型下使用。

**参数：** 

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| bundleName | string | 是    | 指定应用的Bundle名称 |

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| Promise&lt;[ResourceManager](#resourcemanager)&gt; | Promise方式返回的资源管理对象 |

**示例：** 
  ```js
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  resourceManager.getResourceManager("com.example.myapplication").then((mgr: resourceManager.ResourceManager) => {
  }).catch((error: BusinessError) => {
  });
  ```

## resourceManager.getSystemResourceManager<sup>10+</sup>

getSystemResourceManager(): ResourceManager

获取系统资源管理对象，返回系统资源的ResourceManager对象。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                 |
| ---------------------------------------- | ------------------ |
| [Resourcemanager](#resourcemanager) | 返回系统资源的管理对象 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001009  | If application can't access system resource.                       |

**示例：**
  ```js
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';

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

**系统能力**：SystemCapability.Global.ResourceManager

| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DIRECTION_VERTICAL   | 0    | 竖屏   |
| DIRECTION_HORIZONTAL | 1    | 横屏   |


## DeviceType

用于表示当前设备类型。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称                   | 值  | 说明   |
| -------------------- | ---- | ---- |
| DEVICE_TYPE_TABLET   | 0x01 | 平板   |
| DEVICE_TYPE_CAR      | 0x02 | 汽车   |
| DEVICE_TYPE_TV       | 0x04 | 电视   |
| DEVICE_TYPE_WEARABLE | 0x06 | 穿戴   |


## ScreenDensity

用于表示当前设备屏幕密度。

**系统能力**：SystemCapability.Global.ResourceManager

| 名称             | 值  | 说明         |
| -------------- | ---- | ---------- |
| SCREEN_SDPI    | 120  | 小规模的屏幕密度   |
| SCREEN_MDPI    | 160  | 中规模的屏幕密度   |
| SCREEN_LDPI    | 240  | 大规模的屏幕密度   |
| SCREEN_XLDPI   | 320  | 特大规模的屏幕密度  |
| SCREEN_XXLDPI  | 480  | 超大规模的屏幕密度  |
| SCREEN_XXXLDPI | 640  | 超特大规模的屏幕密度 |


## Configuration

表示当前设备的状态。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 名称        | 类型                    | 可读   | 可写   | 说明       |
| --------- | ----------------------- | ---- | ---- | -------- |
| direction | [Direction](#direction) | 是    | 否    | 当前设备屏幕方向 |
| locale    | string                  | 是    | 否    | 当前系统语言   |


## DeviceCapability

表示设备支持的能力。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 名称            | 类型                            | 可读   | 可写   | 说明       |
| ------------- | ------------------------------- | ---- | ---- | -------- |
| screenDensity | [ScreenDensity](#screendensity) | 是    | 否    | 当前设备屏幕密度 |
| deviceType    | [DeviceType](#devicetype)       | 是    | 否    | 当前设备类型   |


## RawFileDescriptor<sup>8+</sup>

表示rawfile的descriptor信息。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 名称     | 类型    | 可读   | 可写  | 说明           |
| ------ | ------  | ---- | ---- | ------------------ |
| fd     | number  | 是    | 否 | rawfile所在hap的文件描述符 |
| offset | number  | 是    | 否 | rawfile的起始偏移量      |
| length | number  | 是    | 否 | rawfile的文件长度       |

## Resource<sup>9+</sup>

表示的资源信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Global.ResourceManager

**参数：**

| 名称         | 类型     | 可读   | 可写  |说明          |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | 是    | 否 | 应用的bundle名称 |
| moduleName | string | 是    | 否 | 应用的module名称 |
| id         | number | 是    | 否 | 资源的id值      |
| params     | any[] | 是    | 否 | 其他资源参数（可选）      |
| type       | number | 是    | 否 | 资源的类型（可选）      |


## ResourceManager

提供访问应用资源的能力。

> **说明：**
>
> - ResourceManager涉及到的方法，仅限基于TS扩展的声明式开发范式使用。
>
> - 资源文件在工程的resources目录中定义，id可通过$r(资源地址).id的方式获取，例如$r('app.string.test').id。
>
> - 对于本应用包资源，通过指定资源ID或资源名称进行访问。对于应用内跨包资源，通过指定[resource对象](#resource9)或对应包的[context](../../application-models/application-context-stage.md#创建其他应用或其他module的context)进行访问，通过对应包context访问跨包资源与访问本应用包资源的逻辑一致，推荐开发者使用对应包的context方法。

### getStringSync<sup>9+</sup>

getStringSync(resId: number): string

用户获取指定资源ID对应的字符串，使用同步方式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| string | 资源ID值对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| args | Array<string \| number> | 否    | 格式化字符串资源参数 <br> 支持参数类型：<br> %d、%f、%s、%% <br> 说明：%%转译符，转译%<br>举例：%%d格式化后为%d字符串|

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | 资源ID值对应的格式化字符串|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------- |
| 9001001  | If the resId invalid.                               |
| 9001002  | If the resource not found by resId.                 |
| 9001006  | If the resource re-ref too much.                    |
| 9001007  | If the resource obtained by resId formatting error. |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的字符串，使用同步方式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型     | 说明               |
| ------ | ---------------- |
| string | resource对象对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| args | Array<string \| number> | 否    | 格式化字符串资源参数 <br> 支持参数类型：<br /> %d、%f、%s、%% <br> 说明：%%转译符，转译%<br>举例：%%d格式化后为%d字符串|

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | resource对象对应的格式化字符串|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |
| 9001007  | If the resource obtained by resId formatting error. |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 资源名称对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |
| args | Array<string \| number> | 否    | 格式化字符串资源参数 <br> 支持参数类型：<br /> %d、%f、%s、%% <br> 说明：%%转译符，转译%<br>举例：%%d格式化后为%d字符串|

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| string | 资源名称对应的格式化字符串|

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |
| 9001008  | If the resource obtained by resName formatting error. |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的字符串，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值           |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the module resId invalid.             |
| 9001002  | If the resource not found by resId.      |
| 9001006  | If the resource re-ref too much.         |

**示例Stage：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getStringValue($r('app.string.test').id, (error, value) => {
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

用户获取指定资源ID对应的字符串，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | 资源ID值对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的字符串，使用callback形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息            |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.string.test').id
  };
  try {
    this.context.resourceManager.getStringValue(resource, (error, value) => {
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

用户获取指定resource对象对应的字符串，使用Promise形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | resource对象对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的字符串，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称            |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getStringByName("test", (error, value) => {
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

用户获取指定资源名称对应的字符串，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;string&gt; | 资源名称对应的字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的字符串数组，使用同步方式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 资源ID值对应的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的字符串数组，使用同步方式返回字符串数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | resource对象对应的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的字符串数组，使用同步方式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Array&lt;string&gt; | 对应资源名称的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                       |
| 9001004  | If the resource not found by resName.         |
| 9001006  | If the resource re-ref too much.            |

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

用户获取指定资源ID对应的字符串数组，使用callback形式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回获取的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id, (error, value) => {
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

用户获取指定资源ID对应的字符串数组，使用Promise形式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | 资源ID值对应的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的字符串数组，使用callback形式返回回字符串数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。
**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resource | [Resource](#resource9)                   | 是    | 资源信息              |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回获取的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.strarray.test').id
  };
  try {
    this.context.resourceManager.getStringArrayValue(resource, (error, value) => {
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

用户获取指定resource对象对应的字符串数组，使用Promise形式返回字符串数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                                 | 说明                 |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | resource对象对应的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的字符串数组，使用callback形式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resName  | string                                   | 是    | 资源名称              |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回获取的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getStringArrayByName("test", (error, value) => {
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

用户获取指定资源名称对应的字符串数组，使用Promise形式返回字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                                 | 说明           |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;string&gt;&gt; | 资源名称对应的字符串数组 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定ID字符串表示的单复数字符串，使用同步方式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| num   | number | 是    | 数量值   |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| string   | 根据指定数量获取指定ID字符串表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定resource对象表示的单复数字符串，使用同步方式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| num      | number                 | 是    | 数量值   |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 根据指定数量获取指定resource对象表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定资源名称表示的单复数字符串，使用同步方式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称 |
| num      | number                 | 是    | 数量值   |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 根据指定数量获取指定资源名称表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                       |
| 9001004  | If the resource not found by resName.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定ID字符串表示的单复数字符串，使用callback形式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | 是    | 资源ID值                           |
| num      | number                      | 是    | 数量值                             |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1, (error, value) => {
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

根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise形式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| num   | number | 是    | 数量值   |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | 根据提供的数量获取对应ID字符串表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定resource对象表示的单复数字符串，使用callback形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                                   |
| -------- | --------------------------- | ---- | ------------------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息                                 |
| num      | number                      | 是    | 数量值                                  |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，返回根据指定数量获取指定resource对象表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.plural.test').id
  };
  try {
    this.context.resourceManager.getPluralStringValue(resource, 1, (error, value) => {
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

根据指定数量获取对指定resource对象表示的单复数字符串，使用Promise形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| num      | number                 | 是    | 数量值  |

**返回值：**

| 类型                    | 说明                             |
| --------------------- | ------------------------------ |
| Promise&lt;string&gt; | 根据提供的数量获取对应resource对象表示的单复数字符串 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

根据传入的数量值，获取资源名称对应的字符串资源，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                            |
| -------- | --------------------------- | ---- | ----------------------------- |
| resName  | string                      | 是    | 资源名称                          |
| num      | number                      | 是    | 数量值                           |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，返回根据传入的数量值获取资源名称对应的字符串资源 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getPluralStringByName("test", 1, (error, value) => {
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

根据传入的数量值，获取资源名称对应的字符串资源，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |
| num     | number | 是    | 数量值  |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;string&gt; | 根据传入的数量值获取资源名称对应的字符串资源 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| Uint8Array   | 资源ID对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Uint8Array | resource对象对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Uint8Array | 对应资源名称的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                       |
| 9001004  | If the resource not found by resName.         |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的媒体文件内容，使用callback形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值              |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, (error, value) => {
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

用户获取指定资源ID对应的指定屏幕密度媒体文件内容，使用callback形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值              |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaContent($r('app.media.test').id, 120, (error, value) => {
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

用户获取指定资源ID对应的媒体文件内容，使用Promise形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的指定屏幕密度媒体文件内容，使用Promise形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的媒体文件内容，使用callback形式返回字节数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息               |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, (error, value) => {
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

用户获取指定resource对象对应的指定屏幕密度媒体文件内容，使用callback形式返回字节数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resource | [Resource](#resource9)          | 是    | 资源信息               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContent(resource, 120, (error, value) => {
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

用户获取指定resource对象对应的媒体文件内容，使用Promise形式返回字节数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | resource对象对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的指定屏幕密度媒体文件内容，使用Promise形式返回字节数组。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                        | 说明                  |
| ------------------------- | ------------------- |
| Promise&lt;Uint8Array&gt; | resource对象对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的媒体文件内容，使用callback形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称               |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaByName("test", (error, value) => {
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

用户获取指定资源ID对应的指定屏幕密度媒体文件内容，使用callback形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resName  | string                          | 是    | 资源名称               |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaByName("test", 120, (error, value) => {
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

用户获取指定资源名称对应的媒体文件内容，使用Promise形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | 资源名称对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的指定屏幕密度媒体文件内容，使用Promise形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                        | 说明            |
| ------------------------- | ------------- |
| Promise&lt;Uint8Array&gt; | 资源名称对应的媒体文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| -------- | ----------- |
| string   | 资源ID对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | resource对象对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resName | string | 是    | 资源名称 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| string | 资源名称对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                       |
| 9001004  | If the resource not found by resName.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的图片资源Base64编码，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** Content

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值                    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, (error, value) => {
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

用户获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值                    |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, 120, (error, value) => {
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

用户获取指定资源ID对应的图片资源Base64编码，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的指定屏幕密度图片资源Base64编码，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的图片资源Base64编码，使用callback形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息                     |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, (error, value) => {
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

用户获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用callback形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resource | [Resource](#resource9)      | 是    | 资源信息                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
  };
  try {
    this.context.resourceManager.getMediaContentBase64(resource, 120, (error, value) => {
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

用户获取指定resource对象对应的图片资源Base64编码，使用Promise形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | resource对象对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的指定屏幕密度图片资源Base64编码，使用Promise形式返回字符串。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | resource对象对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的图片资源Base64编码，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称                     |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaBase64ByName("test", (error, value) => {
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

用户获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用callback形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resName  | string                      | 是    | 资源名称                     |
| [density](#screendensity)  | number        | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getMediaBase64ByName("test", 120, (error, value) => {
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

用户获取指定资源名称对应的图片资源Base64编码，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | 资源名称对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的指定屏幕密度图片资源Base64编码，使用Promise形式返回字符串。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |
| [density](#screendensity)  | number                          | 是    | 资源获取需要的屏幕密度，0表示默认屏幕密度    |

**返回值：**

| 类型                    | 说明                  |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | 资源名称对应的图片资源Base64编码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

getDrawableDescriptor(resId: number, density?: number, type?: number): DrawableDescriptor;

用户获取指定资源ID对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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
    this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, null, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptor<sup>10+</sup>

getDrawableDescriptor(resource: Resource, density?: number, type?: number): DrawableDescriptor;

用户获取指定resource对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源 |

**返回值：**

| 类型      | 说明                |
| ------- | ----------------- |
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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
    this.context.resourceManager.getDrawableDescriptor(resource, null, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getDrawableDescriptorByName<sup>10+</sup>

getDrawableDescriptorByName(resName: string, density?: number, type?: number): DrawableDescriptor;

用户获取指定资源名称对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |
| [density](#screendensity) | number | 否    | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |
| type<sup>11+</sup> | number | 否    | 1表示用于取主题资源包中应用的分层图标资源，0或缺省表示取应用自身图标资源 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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
    this.context.resourceManager.getDrawableDescriptorByName('icon', null, 1);
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getBoolean<sup>9+</sup>

getBoolean(resId: number): boolean

使用同步方式，返回获取指定资源ID对应的布尔结果。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 资源ID值对应的布尔结果 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

使用同步方式，返回获取指定resource对象对应的布尔结果。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型      | 说明                |
| ------- | ----------------- |
| boolean | resource对象对应的布尔结果 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

使用同步方式，返回获取指定资源名称对应的布尔结果

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型      | 说明          |
| ------- | ----------- |
| boolean | 资源名称对应的布尔结果 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的integer数值或者float数值，使用同步方式返回资源对应的数值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- | 
| number | 资源ID值对应的数值。Integer对应的是原数值，float对应的是真实像素点值，具体参考示例代码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的integer数值或者float数值，使用同步方式返回资源对应的数值。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：** 

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型     | 说明              |
| ------ | --------------- |
| number | resource对象对应的数值。Integer对应的是原数值，float对应的是真实像素点值, 具体参考示例代码 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.integer.integer_test').id
  };
  try {
    this.context.resourceManager.getNumber(resource);// integer对应返回的是原数值, float对应返回的是真实像素点值
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getNumber failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getNumberByName<sup>9+</sup>

getNumberByName(resName: string): number

用户获取指定资源名称对应的integer数值或者float数值，使用同步方式资源对应的数值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 资源名称对应的数值 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的颜色值，使用同步方式返回其对应的颜色值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的颜色值，使用同步方式返回其对应的颜色值。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型     | 说明               |
| ------ | ---------------- |
| number | resource对象对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的颜色值，使用同步方式返回其对应的颜色值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的颜色值，使用callback形式返回其对应的颜色值。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值           |
| callback | AsyncCallback&lt;number&gt; | 是    | 异步回调，用于返回获取的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the module resId invalid.             |
| 9001002  | If the resource not found by resId.      |
| 9001006  | If the resource re-ref too much.         |

**示例Stage：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getColor($r('app.color.test').id, (error, value) => {
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

用户获取指定资源ID对应的颜色值，使用Promise形式返回对应其对应的颜色值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;number&gt; | 资源ID值对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的颜色值，使用callback形式返回其对应的颜色值。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力：** SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resource | [Resource](#resource9)      | 是    | 资源信息            |
| callback | AsyncCallback&lt;number&gt; | 是    | 异步回调，用于返回获取的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

  let resource: resourceManager.Resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.color.test').id
  };
  try {
    this.context.resourceManager.getColor(resource, (error, value) => {
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

用户获取指定resource对象对应的颜色值，使用Promise形式返回其对应的颜色值。此接口用于多工程应用内跨包访问，会创建对应module的context进而获取资源。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型                    | 说明               |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | resource对象对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的颜色值，使用callback形式返回其对应的颜色值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resName  | string                      | 是    | 资源名称            |
| callback | AsyncCallback&lt;number&gt; | 是    | 异步回调，用于返回获取的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getColorByName("test", (error, value) => {
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

用户获取指定资源名称对应的颜色值，使用Promise形式返回其对应的颜色值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Promise&lt;number&gt; | 资源名称对应的颜色值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用同步形式返回字节数组。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径             |

**返回值：**

| 类型                    | 说明         |
| --------------------- | ---------- |
| Uint8Array | 返回获取的rawfile文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用callback形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径             |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的rawfile文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getRawFileContent("test.txt", (error, value) => {
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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用Promise形式返回字节数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | rawfile文件内容 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

getRawFileListSync(path: string): Array\<string\>

用户获取resources/rawfile目录下文件夹及文件列表，使用同步形式返回文件列表的字符串数组。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件夹路径             |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Array\<string\> | rawfile文件夹下的列表（包含子文件夹和文件） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.       |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下文件夹及文件列表，使用callback形式返回文件列表的字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件夹路径             |
| callback | AsyncCallback&lt;Array\<string\>&gt; | 是 | 异步回调，用于返回获取rawfile文件目录下的文件列表 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.       |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try { // 传入""表示获取rawfile根目录下的文件列表
    this.context.resourceManager.getRawFileList("", (error, value) => {
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

用户获取resources/rawfile目录下文件夹及文件列表，使用Promise形式返回文件列表字符串数组。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件夹路径 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Array\<string\>&gt; | rawfile文件目录下的文件列表 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下对应rawfile文件的descriptor。

**系统能力：** SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径                      |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| [RawFileDescriptor](#rawfiledescriptor8) | rawfile文件的descriptor |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用callback形式返回。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径                      |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | 是    | 异步回调，用于返回获取的rawfile文件的descriptor |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getRawFd("test.txt", (error, value) => {
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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用Promise形式返回。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | rawfile文件descriptor |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户关闭resources/rawfile目录下rawfile文件的descriptor。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | The resource not found by path.          |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用callback形式返回。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径 |
| callback | AsyncCallback&lt;void&gt; | 是    | 异步回调        |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | The resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.closeRawFd("test.txt", (error, value) => {
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

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用Promise形式返回。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | 无返回值 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001005  | If the resource not found by path.          |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.closeRawFd("test.txt");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`promise closeRawFd failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getConfigurationSync

getConfigurationSync(): Configuration

用户获取设备的Configuration，使用同步形式返回Configuration对象。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| [Configuration](#configuration) | 设备的Configuration |

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

用户获取设备的Configuration，使用callback形式返回Configuration对象。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                        |
| -------- | ---------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;[Configuration](#configuration)&gt; | 是    | 异步回调，用于返回设备的Configuration |

**示例：** 
  ```ts
  try {
    this.context.resourceManager.getConfiguration((error, value) => {
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

用户获取设备的Configuration，使用Promise形式返回Configuration对象。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise&lt;[Configuration](#configuration)&gt; | 设备的Configuration |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

### getDeviceCapabilitySync

getDeviceCapabilitySync(): DeviceCapability

用户获取设备的DeviceCapability，使用同步形式返回DeviceCapability对象。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| [DeviceCapability](#devicecapability) | 设备的DeviceCapability |

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

用户获取设备的DeviceCapability，使用callback形式返回DeviceCapability对象。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                           |
| -------- | ---------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[DeviceCapability](#devicecapability)&gt; | 是    | 异步回调，用于返回设备的DeviceCapability |

**示例：** 
  ```ts
  try {
    this.context.resourceManager.getDeviceCapability((error, value) => {
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

用户获取设备的DeviceCapability，使用Promise形式返回DeviceCapability对象。

**系统能力**：SystemCapability.Global.ResourceManager

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[DeviceCapability](#devicecapability)&gt; | 设备的DeviceCapability |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

### release<sup>7+</sup>

release()

用户释放创建的resourceManager, 此接口暂不支持。

**系统能力**：SystemCapability.Global.ResourceManager

**示例：** 
  ```ts
  try {
    this.context.resourceManager.release();
  } catch (error) {
    console.error("release error is " + error);
  }
  ```

### addResource<sup>10+</sup>

addResource(path: string) : void;

应用运行时，加载指定的资源路径，实现资源覆盖。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001010  | If the overlay path is invalid.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

removeResource(path: string) : void;

用户运行时，移除指定的资源路径，还原被覆盖前的资源。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名      | 类型            | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| path | string | 是    | 资源路径 |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001010  | If the overlay path is invalid.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名         | 类型    | 必填   | 说明       |
| -------------- | ------- | ------ | -------------------- |
| includeSystem  | boolean |  否    | 是否包含系统资源，默认值为false <br> false：表示仅获取应用资源的语言列表 <br>true：表示获取系统资源和应用资源的语言列表 <br>当系统资源管理对象获取语言列表时，includeSystem值无效，返回获取系统资源语言列表 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Array\<string> | 返回获取的语言列表，列表中的字符串由语言、脚本(可选)、地区(可选)，按照顺序使用中划线"-"连接组成|

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的符号值，是用同步方式返回其对应的符号值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 资源ID值对应的符号值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定resource对象对应的符号值，是用同步方式返回其对应的符号值。

**系统能力**：SystemCapability.Global.ResourceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                     | 必填   | 说明   |
| -------- | ---------------------- | ---- | ---- |
| resource | [Resource](#resource9) | 是    | 资源信息 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | resource对象对应的符号值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001001  | If the resId invalid.                       |
| 9001002  | If the resource not found by resId.         |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源名称对应的符号值，使用同步方式返回其对应的符号值。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：**

| 参数名     | 类型     | 必填   | 说明   |
| ------- | ------ | ---- | ---- |
| resName | string | 是    | 资源名称 |

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| number | 资源名称对应的符号值（十进制） |

**错误码：**

以下错误码的详细介绍请参见[资源管理错误码](../errorcodes/errorcode-resource-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 9001003  | If the resName invalid.                     |
| 9001004  | If the resource not found by resName.       |
| 9001006  | If the resource re-ref too much.            |

**示例：**
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    this.context.resourceManager.getSymbolByName("test");
  } catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`getSymbolByName failed, error code: ${code}, message: ${message}.`);
  }
  ```

### getString<sup>(deprecated)</sup>

getString(resId: number, callback: AsyncCallback&lt;string&gt;): void

用户获取指定资源ID对应的字符串，使用callback形式返回字符串。

从API version 9开始不再维护，建议使用[getStringValue](#getstringvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| resId    | number                      | 是    | 资源ID值           |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的字符串 |

**示例：**
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getString($r('app.string.test').id, (error, value) => {
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

用户获取指定资源ID对应的字符串，使用Promise形式返回字符串。

从API version 9开始不再维护，建议使用[getStringValue](#getstringvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明          |
| --------------------- | ----------- |
| Promise&lt;string&gt; | 资源ID值对应的字符串 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的字符串数组，使用callback形式返回字符串数组。

从API version 9开始不再维护，建议使用[getStringArrayValue](#getstringarrayvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| resId    | number                                   | 是    | 资源ID值             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回获取的字符串数组 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getStringArray($r('app.strarray.test').id, (error, value) => {
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

用户获取指定资源ID对应的字符串数组，使用Promise形式返回字符串数组。

从API version 9开始不再维护，建议使用[getStringArrayValue](#getstringarrayvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                                 | 说明            |
| ---------------------------------- | ------------- |
| Promise&lt;Array&lt;string&gt;&gt; | 资源ID值对应的字符串数组 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的媒体文件内容，使用callback形式返回字节数组。

从API version 9开始不再维护，建议使用[getMediaContent](#getmediacontent9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                 |
| -------- | ------------------------------- | ---- | ------------------ |
| resId    | number                          | 是    | 资源ID值              |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的媒体文件内容 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMedia($r('app.media.test').id, (error, value) => {
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

用户获取指定资源ID对应的媒体文件内容，使用Promise形式返回字节数组。

从API version 9开始不再维护，建议使用[getMediaContent](#getmediacontent9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                        | 说明             |
| ------------------------- | -------------- |
| Promise&lt;Uint8Array&gt; | 资源ID值对应的媒体文件内容 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取指定资源ID对应的图片资源Base64编码，使用callback形式返回字符串。

从API version 9开始不再维护，建议使用[getMediaContentBase64](#getmediacontentbase649)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                       |
| -------- | --------------------------- | ---- | ------------------------ |
| resId    | number                      | 是    | 资源ID值                    |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回获取的图片资源Base64编码 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getMediaBase64($r('app.media.test').id, (error, value) => {
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

用户获取指定资源ID对应的图片资源Base64编码，使用Promise形式返回字符串。

从API version 9开始不再维护，建议使用[getMediaContentBase64](#getmediacontentbase649-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |

**返回值：**

| 类型                    | 说明                   |
| --------------------- | -------------------- |
| Promise&lt;string&gt; | 资源ID值对应的图片资源Base64编码 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise形式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

从API version 9开始不再维护，建议使用[getPluralStringValue](#getpluralstringvalue9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| resId | number | 是    | 资源ID值 |
| num   | number | 是    | 数量值   |

**返回值：**

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | 根据提供的数量获取对应ID字符串表示的单复数字符串 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

根据指定数量获取指定ID字符串表示的单复数字符串，使用callback形式返回字符串。

**说明**
>
>中文环境下，字符串不区分单复数；英文环境下，字符串区分单复数。

从API version 9开始不再维护，建议使用[getPluralStringValue](#getpluralstringvalue9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| resId    | number                      | 是    | 资源ID值                           |
| num      | number                      | 是    | 数量值                             |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getPluralString($r("app.plural.test").id, 1, (error, value) => {
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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用callback形式返回字节数组。

从API version 9开始不再维护，建议使用[getRawFileContent](#getrawfilecontent9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                              | 必填   | 说明                      |
| -------- | ------------------------------- | ---- | ----------------------- |
| path     | string                          | 是    | rawfile文件路径             |
| callback | AsyncCallback&lt;Uint8Array&gt; | 是    | 异步回调，用于返回获取的rawfile文件内容 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFile("test.txt", (error, value) => {
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

用户获取resources/rawfile目录下对应的rawfile文件内容，使用Promise形式返回字节数组。

从API version 9开始不再维护，建议使用[getRawFileContent](#getrawfilecontent9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                        | 说明          |
| ------------------------- | ----------- |
| Promise&lt;Uint8Array&gt; | rawfile文件内容 |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用callback形式返回。

从API version 9开始不再维护，建议使用[getRawFd](#getrawfd9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| path     | string                                   | 是    | rawfile文件路径                      |
| callback | AsyncCallback&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | 是    | 异步回调，用于返回获取的rawfile文件的descriptor |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.getRawFileDescriptor("test.txt", (error, value) => {
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

用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用Promise形式返回。

从API version 9开始不再维护，建议使用[getRawFd](#getrawfd9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[RawFileDescriptor](#rawfiledescriptor8)&gt; | rawfile文件descriptor |

**示例：** 
  ```ts
  import { BusinessError } from '@ohos.base';

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

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用callback形式返回。

从API version 9开始不再维护，建议使用[closeRawFd](#closerawfd9)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                        | 必填   | 说明          |
| -------- | ------------------------- | ---- | ----------- |
| path     | string                    | 是    | rawfile文件路径 |
| callback | AsyncCallback&lt;void&gt; | 是    | 异步回调        |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt", (error, value) => {
          if (error != null) {
              console.error("error is " + error);
          }
      });
  });
  ```

### closeRawFileDescriptor<sup>(deprecated)</sup>

closeRawFileDescriptor(path: string): Promise&lt;void&gt;

用户关闭resources/rawfile目录下rawfile文件的descriptor，使用Promise形式返回。

从API version 9开始不再维护，建议使用[closeRawFd](#closerawfd9-1)代替。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| path | string | 是    | rawfile文件路径 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| Promise&lt;void&gt; | 无返回值 |

**示例：** 
  ```ts
  resourceManager.getResourceManager((error, mgr) => {
      mgr.closeRawFileDescriptor("test.txt");
  });
  ```
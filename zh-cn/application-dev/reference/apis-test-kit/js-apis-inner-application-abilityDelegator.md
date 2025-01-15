# AbilityDelegator

AbilityDelegator提供添加用于监视指定Ability的生命周期状态更改的[AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)对象的能力，包括对AbilityMonitor实例的添加、删除、等待Ability到达OnCreate生命周期、设置等待时间等、获取指定Ability的生命周期状态、获取当前应用顶部Ability、启动指定Ability等。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在<!--RP1-->[自动化测试框架arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->中使用。

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## 使用说明

通过abilityDelegatorRegistry中getAbilityDelegator方法获取。
```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## AbilityDelegator

### addAbilityMonitor<sup>9+</sup>

addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void

添加AbilityMonitor实例。使用callback异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是       | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |
| callback | AsyncCallback\<void>                                         | 是       | 回调函数。当添加AbilityMonitor实例成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info(`onAbilityCreateCallback, data: ${JSON.stringify(data)}`);
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (error: BusinessError) => {
  console.error(`addAbilityMonitor fail, error: ${JSON.stringify(error)}`);
});
```

### addAbilityMonitor<sup>9+</sup>

addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>

添加AbilityMonitor实例。使用Promise异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> |Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};
let abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();

abilityDelegator.addAbilityMonitor(monitor).then(() => {
  console.info('addAbilityMonitor promise');
});
```

### addAbilityMonitorSync<sup>10+</sup>

addAbilityMonitorSync(monitor: AbilityMonitor): void

同步添加AbilityMonitor实例。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityMonitorSync failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitorSync(monitor);
```

### removeAbilityMonitor<sup>9+</sup>

removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void

删除已经添加的AbilityMonitor实例。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当删除已经添加的AbilityMonitor实例成功，err为undefined，否则为错误对象。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

function onAbilityCreateCallback(data: UIAbility) {
    console.info('onAbilityCreateCallback');
}

let monitor: abilityDelegatorRegistry.AbilityMonitor = {
    abilityName: 'abilityname',
    onAbilityCreate: onAbilityCreateCallback
};

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor, (error: BusinessError) => {
    console.error(`removeAbilityMonitor fail, error: ${JSON.stringify(error)}`);
});
```

### removeAbilityMonitor<sup>9+</sup>

removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>

删除已经添加的AbilityMonitor实例。使用Promise异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityMonitor failed. |

- 示例

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor).then(() => {
  console.info('removeAbilityMonitor promise');
});
```

### removeAbilityMonitorSync<sup>10+</sup>

removeAbilityMonitorSync(monitor: AbilityMonitor): void

同步删除已经添加的AbilityMonitor实例。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityMonitorSync failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitorSync(monitor);
```

### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void

等待与AbilityMonitor实例匹配的Ability到达OnCreate生命周期，并返回Ability实例。使用callback异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |
| callback | AsyncCallback\<[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)> | 是   | 回调函数。当等待与AbilityMonitor实例匹配的Ability到达OnCreate生命周期成功，err为undefined，data为获取到的Ability实例，否则为错误对象。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, (error: BusinessError, data: UIAbility) => {
  if (error) {
    console.error(`waitAbilityMonitor fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`waitAbilityMonitor success, data: ${JSON.stringify(data)}`);
  }
});
```

### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void

设置等待时间，等待与AbilityMonitor实例匹配的Ability到达OnCreate生命周期，并返回Ability实例。使用callback异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |
| timeout  | number                                                       | 是   | 最大等待时间，单位毫秒（ms）。                                 |
| callback | AsyncCallback\<[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)> | 是   | 表示指定的回调方法。                                           |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let timeout = 100;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, timeout, (error: BusinessError, data: UIAbility) => {
  if (error && error.code !== 0) {
    console.error(`waitAbilityMonitor fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`waitAbilityMonitor success, data: ${JSON.stringify(data)}`);
  }
});
```



### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>

设置等待时间，等待与AbilityMonitor实例匹配的Ability到达OnCreate生命周期，并返回Ability实例。使用Promise异步回调。不支持多线程并发调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1) | 是   | [AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)实例。 |
| timeout | number                                                       | 否   | 最大等待时间，单位毫秒（ms）。                                 |

**返回值：**

| 类型                                                        | 说明                       |
| ----------------------------------------------------------- | -------------------------- |
| Promise\<[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)> | Promise对象，返回Ability实例。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  onAbilityCreate: onAbilityCreateCallback
};

function onAbilityCreateCallback(data: UIAbility) {
  console.info('onAbilityCreateCallback');
}

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor).then((data: UIAbility) => {
  console.info('waitAbilityMonitor promise');
});
```

### getAppContext<sup>9+</sup>

getAppContext(): Context

获取应用Context。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                  | 说明                                        |
| ------------------------------------- | ------------------------------------------- |
| [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 应用[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();

let context = abilityDelegator.getAppContext();
```

### getAbilityState<sup>9+</sup>

getAbilityState(ability: UIAbility): number

获取指定ability的生命周期状态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                              | 必填 | 说明            |
| ------- | ------------------------------------------------- | ---- | --------------- |
| ability | [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) | 是   | 指定Ability对象。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 指定ability的生命周期状态。状态枚举值使用AbilityLifecycleState。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
  let state = abilityDelegator.getAbilityState(ability);
  console.info('getAbilityState ${state}');
});
```

### getCurrentTopAbility<sup>9+</sup>

getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void

获取当前应用顶部Ability。使用callback异步回调。不支持Worker线程调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)> | 是   | 回调函数。当获取当前应用顶部Ability成功，err为undefined，data为获取到的Ability实例；否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling GetCurrentTopAbility failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
});
```

### getCurrentTopAbility<sup>9+</sup>

getCurrentTopAbility(): Promise\<UIAbility>

获取当前应用顶部Ability。使用Promise异步回调。不支持Worker线程调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                        | 说明                                   |
| ----------------------------------------------------------- | -------------------------------------- |
| Promise\<[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)> | Promise对象，返回前应用顶部Ability。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000100 | Calling GetCurrentTopAbility failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility().then((data: UIAbility) => {
  console.info('getCurrentTopAbility promise');
  ability = data;
});
```

### startAbility<sup>9+</sup>

startAbility(want: Want, callback: AsyncCallback\<void>): void

启动指定Ability。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明               |
| -------- | -------------------------------------- | ---- | ------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 启动Ability参数。    |
| callback | AsyncCallback\<void>                   | 是   | 回调函数。当启动指定Ability成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let want: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName'
};

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want, (err: BusinessError, data: void) => {
  console.info('startAbility callback');
});
```

### startAbility<sup>9+</sup>

startAbility(want: Want): Promise\<void>

启动指定Ability。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型                                   | 必填 | 说明            |
| ------ | -------------------------------------- | ---- | --------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 启动Ability参数。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { Want } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let want: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName'
};

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want).then((data: void) => {
  console.info('startAbility promise');
});
```

### doAbilityForeground<sup>9+</sup>

doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void

调度指定Ability生命周期状态到Foreground状态。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility               | 是   | 指定Ability对象。                                         |
| callback | AsyncCallback\<void>    | 是   | 回调函数。当调度指定Ability生命周期状态到Foreground状态成功，err为undefined，否则为错误对象。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling DoAbilityForeground failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
  abilityDelegator.doAbilityForeground(ability, (err: BusinessError) => {
    console.info("doAbilityForeground callback");
  });
});
```

### doAbilityForeground<sup>9+</sup>

doAbilityForeground(ability: UIAbility): Promise\<void>

调度指定Ability生命周期状态到Foreground状态。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | 是   | 指定Ability对象。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。         |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling DoAbilityForeground failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
  abilityDelegator.doAbilityForeground(ability).then(() => {
    console.info("doAbilityForeground promise");
  });
});
```

### doAbilityBackground<sup>9+</sup>

doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void

调度指定Ability生命周期状态到Background状态。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility                 | 是   | 指定Ability对象。                                         |
| callback | AsyncCallback\<void> | 是   | 回调函数。当调度指定Ability生命周期状态到Background状态成功，err为undefined，否则为错误对象。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling DoAbilityBackground failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
  abilityDelegator.doAbilityBackground(ability, (err: BusinessError) => {
    console.info("doAbilityBackground callback");
  });
});
```

### doAbilityBackground<sup>9+</sup>

doAbilityBackground(ability: UIAbility): Promise\<void>

调度指定Ability生命周期状态到Background状态。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | 是   | 指定Ability对象。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。                            |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling DoAbilityBackground failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let ability: UIAbility;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err: BusinessError, data: UIAbility) => {
  console.info('getCurrentTopAbility callback');
  ability = data;
  abilityDelegator.doAbilityBackground(ability).then(() => {
    console.info("doAbilityBackground promise");
  });
});
```

### printSync<sup>9+</sup>

printSync(msg: string): void

打印日志信息到单元测试终端控制台。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let msg = 'msg';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.printSync(msg);
```

### print

print(msg: string, callback: AsyncCallback\<void>): void

打印日志信息到单元测试终端控制台。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | 是   | 日志字符串。         |
| callback | AsyncCallback\<void> | 是   | 回调函数。当打印日志信息到单元测试终端控制台成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let msg = 'msg';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg, (err: BusinessError) => {
  console.info('print callback');
});
```

### print

print(msg: string): Promise\<void>

打印日志信息到单元测试终端控制台。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> |Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let msg = 'msg';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg).then(() => {
  console.info('print promise');
});
```

### executeShellCommand

executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void

执行指定的shell命令。使用callback异步回调。

仅支持如下shell命令：aa, bm, cp, mkdir, rm, uinput, hilog, ppwd, echo, uitest, acm, hidumper, wukong, pkill, ps, pidof

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| cmd      | string                                                       | 是   | shell命令字符串。    |
| callback | AsyncCallback\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#shellcmdresult)> | 是   | 回调函数。当执行指定的shell命令成功，err为undefined，data为获取到的执行结果；否则为错误对象。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err: BusinessError, data: abilityDelegatorRegistry.ShellCmdResult) => {
  console.info('executeShellCommand callback');
});
```

### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void

指定超时时间，并执行指定的shell命令。使用callback异步回调。

仅支持如下shell命令：aa, bm, cp, mkdir, rm, uinput, hilog, ppwd, echo, uitest, acm, hidumper, wukong, pkill, ps, pidof

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                          |
| ----------- | ------------------------------------------------------------ | ---- | ----------------------------- |
| cmd         | string                                                       | 是   | shell命令字符串。               |
| timeoutSecs | number                                                       | 是   | 设定命令超时时间，单位秒（s）。 |
| callback    | AsyncCallback\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#shellcmdresult)> | 是   | 回调函数。当执行指定的shell命令成功，err为undefined，data为获取到的执行结果；否则为错误对象。   |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';
let timeout = 100;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout, (err: BusinessError, data: abilityDelegatorRegistry.ShellCmdResult) => {
  console.info('executeShellCommand callback');
});
```

### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>

指定超时时间，并执行指定的shell命令。使用Promise异步回调。

仅支持如下shell命令：aa, bm, cp, mkdir, rm, uinput, hilog, ppwd, echo, uitest, acm, hidumper, wukong, pkill, ps, pidof

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                          |
| ----------- | ------ | ---- | ----------------------------- |
| cmd         | string | 是   | shell命令字符串。               |
| timeoutSecs | number | 否   | 设定命令超时时间，单位秒（s）。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#shellcmdresult)> | Promise对象，返回Shell命令执行结果[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#shellcmdresult)对象。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';
let timeout = 100;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data) => {
  console.info('executeShellCommand promise');
});
```

### finishTest<sup>9+</sup>

finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void

结束测试并打印日志信息到单元测试终端控制台。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | 是   | 日志字符串。         |
| code     | number               | 是   | 日志码。             |
| callback | AsyncCallback\<void> | 是   | 回调函数。当结束测试并打印日志信息到单元测试终端控制台成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling FinishTest failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let msg = 'msg';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0, (err: BusinessError) => {
  console.info('finishTest callback');
});
```

### finishTest<sup>9+</sup>

finishTest(msg: string, code: number): Promise\<void>

结束测试并打印日志信息到单元测试终端控制台。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串。 |
| code   | number | 是   | 日志码。     |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling FinishTest failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let msg = 'msg';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0).then(() => {
  console.info('finishTest promise');
});
```

### addAbilityStageMonitor<sup>9+</sup>

addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void

添加一个AbilityStageMonitor对象，用于监视指定AbilityStage的生命周期状态更改。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是       | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |
| callback | AsyncCallback\<void>                                         | 是       | 回调函数。当添加一个用于监视指定AbilityStage的生命周期状态更改的AbilityStageMonitor对象成功，err为undefined，否则为错误对象。     |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}, (err: BusinessError) => {
  console.info('addAbilityStageMonitor callback');
});
```

### addAbilityStageMonitor<sup>9+</sup>

addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>

添加一个AbilityStageMonitor对象，用于监视指定AbilityStage的生命周期状态更改。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是   | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}).then(() => {
  console.info('addAbilityStageMonitor promise');
});
```

### addAbilityStageMonitorSync<sup>10+</sup>

addAbilityStageMonitorSync(monitor: AbilityStageMonitor): void

同步添加一个AbilityStageMonitor对象，用于监视指定AbilityStage的生命周期状态更改。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是       | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling AddAbilityStageMonitorSync failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityStageMonitorSync({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
});
```

### removeAbilityStageMonitor<sup>9+</sup>

removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void

从应用程序内存中删除指定的AbilityStageMonitor对象。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是       | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |
| callback | AsyncCallback\<void>                                         | 是       | 回调函数。当从应用程序内存中删除指定的AbilityStageMonitor对象成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}, (err: BusinessError) => {
  console.info('removeAbilityStageMonitor callback');
});
```

### removeAbilityStageMonitor<sup>9+</sup>

removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>

从应用程序内存中删除指定的AbilityStageMonitor对象。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是   | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}).then(() => {
  console.info('removeAbilityStageMonitor promise');
});
```

### removeAbilityStageMonitorSync<sup>10+</sup>

removeAbilityStageMonitorSync(monitor: AbilityStageMonitor): void

同步从应用程序内存中删除指定的AbilityStageMonitor对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是       | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling RemoveAbilityStageMonitorSync failed. |


**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityStageMonitorSync({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
});
```

### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是       | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |
| callback | AsyncCallback\<AbilityStage>                                         | 是       | 回调函数。当等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象的操作成功，err为undefined，data为获取到的[AbilityStage](../apis-ability-kit/js-apis-app-ability-abilityStage.md)对象；否则为错误对象。    |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { AbilityStage } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}, (err: BusinessError, data: AbilityStage) => {
  console.info('waitAbilityStageMonitor callback');
});
```

### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是   | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |
| timeout | number | 否   | 超时最大等待时间，以毫秒为单位。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<AbilityStage> | Promise对象，返回[AbilityStage](../apis-ability-kit/js-apis-app-ability-abilityStage.md)对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { AbilityStage } from '@kit.AbilityKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}).then((data: AbilityStage) => {
  console.info('waitAbilityStageMonitor promise');
});
```

### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | 是   | [AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) 实例。 |
| timeout | number | 是   | 超时最大等待时间，以毫秒为单位。 |
| callback | AsyncCallback\<AbilityStage>                                         | 是       | 回调函数。当等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象的操作成功，err为undefined，data为获取到的[AbilityStage](../apis-ability-kit/js-apis-app-ability-abilityStage.md)对象；否则为错误对象。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000100 | Calling WaitAbilityStageMonitor failed. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { AbilityStage } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let timeout = 100;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor({
  moduleName: 'moduleName',
  srcEntrance: 'srcEntrance',
}, timeout, (err: BusinessError, data: AbilityStage) => {
  console.info('waitAbilityStageMonitor callback');
});
```

### setMockList<sup>11+</sup>

setMockList(mockList: Record\<string, string>): void

设置模块的mock替换关系。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| mockList | Record\<string, string> | 是   | 模块mock替换关系的键值对象，其中key为待替换的目标路径，value为用于替换的mock实现文件的路径。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let mockList: Record<string, string> = {
  '@ohos.router': 'src/main/mock/ohos/router.mock',
  'common.time': 'src/main/mock/common/time.mock',
};
let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.setMockList(mockList);
```

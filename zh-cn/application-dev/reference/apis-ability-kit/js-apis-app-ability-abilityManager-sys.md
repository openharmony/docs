# @ohos.app.ability.abilityManager (AbilityManager)(系统接口)

AbilityManager模块提供获取、新增、修改Ability相关信息和状态信息进行的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityState

Ability的状态，该类型为枚举，可配合[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)返回Ability的状态。

**系统接口**: 该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示ability为初始化状态。| 
| FOCUS | 2 | 表示ability为获焦状态。 |
| FOREGROUND | 9 | 表示ability为前台状态。  | 
| BACKGROUND | 10 | 表示ability为后台状态。  | 
| FOREGROUNDING | 11 | 表示ability为前台调度中状态。  | 
| BACKGROUNDING | 12 | 表示ability为后台调度中状态。  | 

## UserStatus<sup>12+</sup>

用户操作的断言调试结果，该类型为枚举。

**系统接口**: 该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ASSERT_TERMINATE | 0 | 表示用户点击终止的操作的断言调试结果。 |
| ASSERT_CONTINUE | 1 | 表示用户点击继续的操作的断言调试结果。 |
| ASSERT_RETRY | 2 | 表示用户点击重试的操作的断言调试结果。 |

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

通过传入修改的配置项来更新配置（callback形式）。

**系统接口**：该接口为系统接口。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core
 
**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | 是    | 新的配置项，仅需配置需要更新的项。 |
| callback  | AsyncCallback\<void>                   | 是    | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager, Configuration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const config: Configuration = {
  language: 'Zh-Hans',                 // 简体中文
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // 浅色模式
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // 垂直方向
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // 屏幕像素密度为'sdpi'
  displayId: 1,                        // 应用在Id为1的物理屏上显示
  hasPointerDevice: true,              // 指针类型设备已连接
};

try {
  abilityManager.updateConfiguration(config, (err: BusinessError) => {
    if (err) {
      console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log('updateConfiguration success.');
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

通过修改配置来更新配置（Promise形式）。

**系统接口**：该接口为系统接口。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | 是    | 新的配置项，仅需配置需要更新的项。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<void> | 以Promise方式返回接口运行结果息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager, Configuration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';;

const config: Configuration = {
  language: 'Zh-Hans',                 // 简体中文
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // 浅色模式
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // 垂直方向
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // 屏幕像素密度为'sdpi'
  displayId: 1,                        // 应用在Id为1的物理屏上显示
  hasPointerDevice: true,              // 指针类型设备已连接
};

try {
  abilityManager.updateConfiguration(config).then(() => {
    console.log('updateConfiguration success.');
  }).catch((err: BusinessError) => {
    console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

获取UIAbility运行相关信息（callback形式）。

**系统接口**：该接口为系统接口。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)>>  | 是    | 以回调方式返回接口运行结果及运行中的ability信息，可进行错误处理或其他自定义处理。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos((err: BusinessError, data: Array<abilityManager.AbilityRunningInfo>) => {
    if (err) {
      console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(err)}`);
    } else {
      console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void

获取关于运行扩展能力的信息（callback形式）。

**系统接口**：该接口为系统接口。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | 是 | 获取消息数量的最大限制，最大为2<sup>31</sup>-1。 |
| callback  | AsyncCallback\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo-sys.md)>>  | 是    | 以回调方式返回接口运行结果及运行中的extension信息，可进行错误处理或其他自定义处理。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let upperLimit = 10;

try {
  abilityManager.getExtensionRunningInfos(upperLimit, (err: BusinessError, data: Array<abilityManager.ExtensionRunningInfo>) => {
    if (err) {
      console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>

获取关于运行扩展能力的信息（Promise形式）。

**系统接口**：该接口为系统接口。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | 是 | 获取消息数量的最大限制，最大为2<sup>31</sup>-1。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo-sys.md)>> | 以Promise方式返回接口运行结果及运行中的extension信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let upperLimit = 10;

try {
  abilityManager.getExtensionRunningInfos(upperLimit).then((data: Array<abilityManager.ExtensionRunningInfo>) => {
    console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getTopAbility

getTopAbility(callback: AsyncCallback\<ElementName>): void

获取窗口焦点的ability接口（callback形式）。

**系统接口**：该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)>  | 是    | 以回调方式返回接口运行结果及应用名，可进行错误处理或其他自定义处理。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getTopAbility((err: BusinessError, data) => {
  if (err) {
    console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);
  } else {
    console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);
  }
});
```

## getTopAbility

getTopAbility(): Promise\<ElementName>

获取窗口焦点的ability接口（Promise形式）。

**系统接口**：该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)>| 以Promise方式返回接口运行结果及应用名，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getTopAbility().then((data) => {
  console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);
});
```

## acquireShareData<sup>10+</sup>

acquireShareData(missionId: number, callback: AsyncCallback\<Record\<string, Object>>): void

系统弹框通过该接口发起原子化服务分享，调用到目标UIAbility的onShare，返回分享数据（callback形式）。

**系统接口**：该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| missionId | number                                   | 是 | 目标应用的missionId，最大为2<sup>31</sup>-1。 |
| callback  | AsyncCallback\<Record\<string, Object>>  | 是    | 以回调方式返回接口运行结果及分享得到的数据，可进行错误处理或其他自定义处理。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.acquireShareData(1, (err: BusinessError, wantParam: Record<string, Object>) => {
    if (err) {
      console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## acquireShareData<sup>10+</sup>

acquireShareData(missionId: number): Promise\<Record\<string, Object>>

系统弹框通过该接口发起原子化服务分享，调用到目标UIAbility的onShare，返回分享数据（Promise形式）。

**系统接口**：该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| missionId | number                                   | 是 | 目标应用的missionId，最大为2<sup>31</sup>-1。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Record\<string, Object>>| 以Promise方式返回接口运行结果及分享数据，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.acquireShareData(1).then((wantParam: Record<string, Object>) => {
    console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);
  }).catch((err: BusinessError) => {
    console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## notifySaveAsResult<sup>10+</sup>

notifySaveAsResult(parameter: AbilityResult, requestCode: number, callback: AsyncCallback\<void>): void

该接口仅供[DLP](../apis-data-protection-kit/js-apis-dlppermission.md)（Data Loss Prevention, 数据丢失防护）管理应用使用，其他应用禁止使用，DLP管理应用通过该接口通知沙箱应用另存为结果。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| requestCode | number                                        | 是 | DLP管理应用传入的请求代码。          |
| callback  | AsyncCallback<void\>                             | 是 | 回调函数。当另存为结果通知成功，err为undefined，否则为错误对象。         |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// 返回给另存为行为发起方AbilityResult信息
let abilityResult: common.AbilityResult = {
  want,
  resultCode
};
let requestCode = 1;
try {
  abilityManager.notifySaveAsResult(abilityResult, requestCode, (err: BusinessError) => {
    if (err && err.code != 0) {
      console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`notifySaveAsResult success`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## notifySaveAsResult<sup>10+</sup>

notifySaveAsResult(parameter: AbilityResult, requestCode: number): Promise\<void>

该接口仅供[DLP](../apis-data-protection-kit/js-apis-dlppermission.md)（Data Loss Prevention, 数据丢失防护）管理应用使用，其他应用禁止使用，DLP管理应用通过该接口通知沙箱应用另存为结果。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| requestCode | number                                        | 是 | DLP管理应用传入的请求代码。          |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise<void\>| Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// 返回给另存为行为发起方AbilityResult信息
let abilityResult: common.AbilityResult = {
  want,
  resultCode
};
let requestCode = 1;
try {
  abilityManager.notifySaveAsResult(abilityResult, requestCode).then(() => {
    console.log(`notifySaveAsResult success`);
  }).catch((err: BusinessError) => {
    console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## abilityManager.on('abilityForegroundState')<sup>11+</sup>

on(type: 'abilityForegroundState', observer: AbilityForegroundStateObserver): void

注册Ability的启动和退出的观测器。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填'abilityForegroundState'字符串。 |
| observer | [AbilityForegroundStateObserver](js-apis-inner-application-abilityForegroundStateObserver-sys) | 是 | Ability状态观测器，用于观测Ability的启动和退出。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## abilityManager.off('abilityForegroundState')<sup>11+</sup>

off(type: 'abilityForegroundState', observer?: AbilityForegroundStateObserver): void

取消注册Ability启动和退出的观测器。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填'abilityForegroundState'字符串。 |
| observer | [AbilityForegroundStateObserver](js-apis-inner-application-abilityForegroundStateObserver-sys) | 否 | Ability状态观测器，用于观测Ability的启动和退出。如果未配置该参数，则取消当前应用注册的所有observer。如果配置了该参数，则取消该observer。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer_: abilityManager.AbilityForegroundStateObserver | undefined;
// 1.注册应用启动和退出的监听器
let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData: abilityManager.AbilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
  observer_ = observer;
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}

// 2.注销监听器
try {
  abilityManager.off('abilityForegroundState',  observer_);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## abilityManager.getForegroundUIAbilities<sup>11+</sup>

getForegroundUIAbilities(callback: AsyncCallback\<Array\<AbilityStateData>>): void

获取前台正在运行的应用Ability的信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<Array\<[AbilityStateData](js-apis-inner-application-abilityStateData.md)>>  | 是 |以回调方式返回接口运行结果及有关前台Ability的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getForegroundUIAbilities((err: BusinessError, data: Array<abilityManager.AbilityStateData>) => {
  if (err) {
    console.error(`Get foreground ui abilities failed, error: ${JSON.stringify(err)}`);
  } else {
    console.log(`Get foreground ui abilities data is: ${JSON.stringify(data)}`);
  }
});
```

## abilityManager.getForegroundUIAbilities<sup>11+</sup>

getForegroundUIAbilities(): Promise\<Array\<AbilityStateData>>

获取前台正在运行的应用Ability的信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[AbilityStateData](js-apis-inner-application-abilityStateData.md)>> | 以Promise方式返回接口运行结果及有关前台Ability的信息，可进行错误处理或其他自定义处理。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getForegroundUIAbilities().then((data: Array<abilityManager.AbilityStateData>) => {
  console.log(`Get foreground ui abilities data is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`Get foreground ui abilities failed, error: ${JSON.stringify(error)}`);
});
```

## abilityManager.notifyDebugAssertResult<sup>12+</sup>

notifyDebugAssertResult(sessionId: string, status: UserStatus): Promise\<void>

将断言调试结果通知应用程序。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.NOTIFY_DEBUG_ASSERT_RESULT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| ------- | -------- | -------- | -------- |
| sessionId | string | 是 | 指示AssertFault的请求ID。 |
| status | [UserStatus](#userstatus12) | 是 | 用户的操作状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, UIExtensionAbility, wantConstant, Want, UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UiExtAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let sessionId: string = '';
    if (want.parameters) {
      sessionId = want.parameters[wantConstant.Params.ASSERT_FAULT_SESSION_ID] as string;
    }
    let status = abilityManager.UserStatus.ASSERT_TERMINATE;
    abilityManager.notifyDebugAssertResult(sessionId, status).then(() => {
      console.log('notifyDebugAssertResult success.');
    }).catch((err: BusinessError) => {
      console.error(`notifyDebugAssertResult failed, error: ${JSON.stringify(err)}`);
    });
  }
}
```

## abilityManager.isEmbeddedOpenAllowed<sup>12</sup>

isEmbeddedOpenAllowed(context: Context, appId: string): Promise\<boolean>

判断是否允许嵌入式拉起[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| ------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 嵌入式拉起EmbeddableUIAbility的调用方Context。 |
| appId | string | 是 | 应用的唯一标识，由云端统一分配。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<boolean> | Promise对象。返回true表示允许嵌入式启动，返回false表示不允许嵌入式启动。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { abilityManager, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let appId: string = '6918661953712445909';
    try {
      abilityManager.isEmbeddedOpenAllowed(this.context, appId).then((data) => {
        console.info(`isEmbeddedOpenAllowed data: ${JSON.stringify(data)}`);
      }).catch((err: BusinessError) => {
        console.error(`isEmbeddedOpenAllowed failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // 处理入参错误异常
      console.error(`param is invalid, code is ${err.code}, message is ${err.message}`);
    }
  }
}
```

## abilityManager.setResidentProcessEnabled<sup>12+</sup>

setResidentProcessEnabled(bundleName: string, enable: boolean): Promise\<void>

常驻进程支持按需启停。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| ------- | -------- | -------- | -------- |
| bundleName | string | 是 | 常驻进程的包名。 |
| enable | boolean | 是 | 常驻进程的使能状态。 true：表示该进程为常驻进程。 false：表示该进程为普通进程，不会进行保活。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not a system application. |
| 401 | Parameter error. Possible cause: 1.Non empty package name needs to be provided, 2.The second parameter needs to provide a Boolean type setting value |
| 16000050 | Internal error. |
| 16200006 | The caller application can only set the resident status of the configured process |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let residentProcessBundleName: string = 'com.xxx.xxxxxx';
  let enable: boolean = false;
  abilityManager.setResidentProcessEnabled(residentProcessBundleName, enable)
    .then(() => {
      console.log('setResidentProcessEnabled success.');
    })
    .catch((err: BusinessError) => {
      console.error(`setResidentProcessEnabled fail, err: ${JSON.stringify(err)}`);
    });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`setResidentProcessEnabled failed, code is ${code}, message is ${message}`);
}
```

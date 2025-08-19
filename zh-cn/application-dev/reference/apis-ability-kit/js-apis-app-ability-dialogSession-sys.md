# @ohos.app.ability.dialogSession (dialogSession)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

dialogSession模块用于支持系统应用弹框功能。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块为系统接口。

## 导入模块

```ts
import { dialogSession } from '@kit.AbilityKit';
```

## DialogAbilityInfo

提供会话组件信息，包括包名、模块名、组件名等信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | 否 | 否 | 表示包名。 |
| moduleName | string | 否 | 否 | 表示模块名。 |
| abilityName | string | 否 | 否 | 表示组件名。 |
| abilityIconId | number | 否 | 否 | 表示Ability图标ID。 |
| abilityLabelId | number | 否 | 否 | 表示Ability标签ID。 |
| bundleIconId | number | 否 | 否 | 表示Bundle图标ID。 |
| bundleLabelId | number | 否 | 否 | 表示Bundle标签ID。 |
| visible<sup>12+</sup> | boolean | 否 | 否 | 表示Ability是否可见。true表示Ability可见，false表示Ability不可见。 |
| appIndex<sup>12+</sup> | number | 否 | 否 | 表示应用的分身索引。 |
| multiAppMode<sup>12+</sup> | [MultiAppMode](./js-apis-bundleManager-applicationInfo.md#multiappmode12) | 否 | 否 | 表示应用的多开模式。|

## DialogSessionInfo

提供会话信息，包括请求方信息、目标应用列表信息、其他参数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| callerAbilityInfo | [DialogAbilityInfo](#dialogabilityinfo)| 是 | 否 | 表示请求方组件信息。 |
| targetAbilityInfos | Array\<[DialogAbilityInfo](#dialogabilityinfo)\> | 是 | 否 | 表示目标应用列表信息。 |
| parameters | Record<string, Object> | 是 | 是 | 表示其他参数。 |

## getDialogSessionInfo

getDialogSessionInfo(dialogSessionId: string): [DialogSessionInfo](#dialogsessioninfo)

根据dialogSessionId获取会话信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | 是 | 用户请求会话ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | [DialogSessionInfo](#dialogsessioninfo) | 同步返回会话信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

**示例：**

```ts
import { dialogSession, Want } from '@kit.AbilityKit';

// want由系统内部指定，dialogSessionId为内置参数
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// 查询DialogSessionInfo
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);
```

## sendDialogResult

sendDialogResult(dialogSessionId: string, targetWant: Want, isAllowed: boolean, callback: AsyncCallback\<void\>): void

发送用户请求。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | 是 | 用户请求会话ID。 |
  | targetWant | Want | 是 | 用户请求目标。 |
  | isAllowed | boolean | 是 | 是否允许拉起目标Ability。true表示允许，false表示不允许。 |
  | callback | AsyncCallback\<void\> | 是 | 回调函数。当发送用户请求成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

**示例：**

```ts
import { dialogSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// want由系统内部指定，dialogSessionId为内置参数
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// 查询DialogSessionInfo
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);

let isAllow: boolean = true;

// isAllow为true时，用户请求结果targetWant为dialogSessionInfo.targetAbilityInfos之一
let targetWant: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  dialogSession.sendDialogResult(dialogSessionId, targetWant, isAllow, (err, data) => {
    if (err) {
      console.error(`sendDialogResult error, errorCode: ${err.code}`);
    } else {
      console.log(`sendDialogResult success`);
    }
  });
} catch (err) {
  console.error(`sendDialogResult error, errorCode: ${(err as BusinessError).code}`);
}
```

## sendDialogResult

sendDialogResult(dialogSessionId: string, targetWant: Want, isAllowed: boolean): Promise\<void\>

发送用户请求。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | 是 | 用户请求会话ID。 |
  | targetWant | Want | 是 | 用户请求目标。 |
  | isAllowed | boolean | 是 | 是否允许拉起目标Ability。true表示允许，false表示不允许。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

**示例：**

```ts
import { dialogSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// want由系统内部指定，dialogSessionId为内置参数
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// 查询DialogSessionInfo
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);

let isAllow: boolean = true;

// isAllow为true时，用户请求结果targetWant为dialogSessionInfo.targetAbilityInfos之一
let targetWant: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  dialogSession.sendDialogResult(dialogSessionId, targetWant, isAllow)
    .then((data) => {
      console.log(`startChildProcess success, pid: ${data}`);
    }, (err: BusinessError) => {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    })
} catch (err) {
  console.error(`sendDialogResult error, errorCode: ${(err as BusinessError).code}`);
}
```
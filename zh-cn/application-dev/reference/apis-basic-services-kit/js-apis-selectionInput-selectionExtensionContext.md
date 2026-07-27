# @ohos.selectionInput.SelectionExtensionContext (划词扩展上下文)

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

SelectionExtensionContext是[SelectionExtensionAbility](./js-apis-selectionInput-selectionExtensionAbility.md)的上下文，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

每个SelectionExtensionAbility组件实例化时，系统都会自动创建对应的SelectionExtensionContext。开发者可以通过SelectionExtensionContext拉起同应用内其他Ability。适用于在划词扩展场景中需要跳转至应用内其他Ability的情况，帮助用户在划词操作后快速获取与划词内容关联的功能或信息。

> **说明：**
>
> - 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块仅支持PC/2in1设备。开发者可通过canIUse('SystemCapability.SelectionInput.Selection')判断当前设备是否支持该功能。

## 导入模块

```ts
import { SelectionExtensionContext } from '@kit.BasicServicesKit';
```

## SelectionExtensionContext

**系统能力：** SystemCapability.SelectionInput.Selection

**模型约束：** 此接口仅可在Stage模型下使用。

### startAbility

startAbility(want: Want): Promise\<void>

拉起同应用内的目标Ability，适用于在划词扩展场景中需要跳转至应用内其他Ability的情况。系统根据Want对象中指定的bundleName和abilityName匹配并调度启动目标Ability。使用Promise异步回调。关于Ability启动机制，请参见[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

**系统能力：** SystemCapability.SelectionInput.Selection

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | 是   | 需要拉起的目标应用信息。主要字段包括bundleName（目标应用的Bundle名称）和abilityName（目标Ability名称）。设置后系统将根据其中指定的bundleName和abilityName查找并拉起对应的Ability。仅支持拉起同应用内的Ability。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)，未标明的通用错误码请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 16000001 | The specified ability does not exist.                   |
| 16000002 | Incorrect ability type.                                 |
| 16000004 | Cannot start an invisible component.                    |
| 16000005 | The specified process does not have the permission.     |
| 16000006 | Cross-user operations are not allowed.                  |
| 16000008 | The crowdtesting application expires.                   |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.       |
| 16000011 | The context does not exist.                             |
| 16000012 | The application is controlled.                          |
| 16000013 | The application is controlled by EDM.                   |
| 16000019 | No matching ability is found.                            |
| 16000050 | Internal error.                                         |
| 16000053 | The ability is not on the top of the UI.                |
| 16000055 | Installation-free timed out.                            |
| 16000061 | Operation not supported.                                |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service.                 |
| 16000083 | The ExtensionAbility cannot start the ability due to system control.                 |
| 16200001 | The caller has been released.                           |

**示例：**

```ts
import { SelectionExtensionAbility, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    console.info(`onRemoteMessageRequest code: ${code}`);
    return true;
  }
}

class SelectionExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    try {
      // 构造Want对象，指定要拉起的目标Ability信息
      let wantAbility: Want = {
        bundleName: 'com.selection.selectionapplication',
        abilityName: 'EntryAbility',
      };
      // 拉起目标Ability，this.context由SelectionExtensionAbility实例自动提供，无需额外获取
      this.context.startAbility(wantAbility).then(() => {
        console.info(`startAbility success`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to startAbility. Error code: ${err.code}, error message: ${err.message}`);
      });
    } catch (err) {
      console.error(`Failed to startAbility. Error code: ${err.code}, error message: ${err.message}`);
    }
    return new SelectionAbilityStub('remote');
  }
}
```
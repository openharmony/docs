# @ohos.selectionInput.SelectionExtensionContext (划词扩展上下文)

SelectionExtensionContext是[SelectionExtensionAbility](./js-apis-selectionInput-selectionExtensionAbility.md)的上下文，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

每个SelectionExtensionAbility组件实例化时，系统都会自动创建对应的SelectionExtensionContext。开发者可以通过SelectionExtensionContext拉起其他Ability。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { SelectionExtensionContext } from '@kit.BasicServicesKit';
```

## SelectionExtensionContext

### startAbility

startAbility(want: Want): Promise\<void>

拉起目标应用。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 想要被拉起的应用信息，包括Ability名称、Bundle名称等。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[元能力错误码](../apis-ability-kit/errorcode-ability.md)。

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
  constructor(des) {
    if (typeof des === 'string') {
      super(des);
    } else {
      return null;
    }
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    console.error(`onRemoteMessageRequest error: ${error.code} ${error.message}`);
    return true;
  }
}

class SelectionExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    try {
      let wantAbility: Want = {
        bundleName: "com.selection.selectionapplication",
        abilityName: "EntryAbility",
      };
      this.context.startAbility(wantAbility).then(() => {
        console.info(`startAbility success`);
      }).catch((err: BusinessError) => {
        let error = err as BusinessError;
        console.error(`startAbility error: ${error.code} ${error.message}`);
      })
    } catch (err) {
      let error = err as BusinessError;
      console.error(`startAbility error: ${error.code} ${error.message}`);
    }
    return new SelectionAbilityStub('remote');
  }
}
```
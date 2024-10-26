# @ohos.app.ability.ActionExtensionAbility (自定义服务扩展能力)

ActionExtensionAbility是为开发者提供的自定义操作业务模板，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。ActionExtension主要用于查看宿主应用中的内容以及对其进行对应处理。例如，添加一个书签、将选中的文本翻译成其他语言、在当前页面编辑图像等。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 场景介绍

以翻译文本为例。首先需要创建请求发起方，再创建出ActionExtension，请求发起方需要将翻译的文本发送给ActionExtension，ActionExtension接收到文本后，需要将接收的文本进行翻译，翻译后的文本再发送给请求发起方。

## 导入模块

```ts
import { ActionExtensionAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | 否 | 否 | 上下文。 |

## ActionExtensionAbility.onCreate

onCreate(): void

ActionExtensionAbility创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## ActionExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

当ActionExtensionAbility界面内容对象创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前ActionExtensionAbility的Want类型信息，包括ability名称、bundle名称等。 |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | ActionExtensionAbility界面内容相关信息。 |

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## ActionExtensionAbility.onForeground

onForeground(): void

ActionExtensionAbility生命周期回调，当ActionExtensionAbility从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## ActionExtensionAbility.onBackground

onBackground(): void

ActionExtensionAbility生命周期回调，当ActionExtensionAbility从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## ActionExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

当ActionExtensionAbility界面内容对象销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | ActionExtensionAbility界面内容相关信息。 |

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## ActionExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

ActionExtensionAbility生命周期回调，在ActionExtensionAbility销毁时回调，执行资源清理等操作。
在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型                                  | 说明                            |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回结果或无返回结果的Promise对象。 |

**示例：**

参见[创建ActionExtensionAbility](#创建actionextensionability)。

## 创建ActionExtensionAbility

在DevEco Studio工程中手动新建一个ActionExtensionAbility，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为ActionExtAbility。

2. 在actionextability目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为ActionExtAbility.ets。

    ```text
    ├── ets
    │ ├── actionextability
    │ │   ├── ActionExtAbility.ets
    └
    ```

3. ActionExtAbility.ets文件中，增加导入ActionExtensionAbility的依赖包，自定义类继承ActionExtensionAbility并实现生命周期回调。

    ```ts
    import { ActionExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';

    const TAG: string = "[ActionExtAbility]";

    export default class ActionExtAbility extends ActionExtensionAbility {
      onCreate() {
        console.info(TAG, `onCreate`);
      }
      onSessionCreate(want: Want, session: UIExtensionContentSession) {
        console.info(TAG, `onSessionCreate, want: ${want.abilityName}`);
        if (want.parameters) {
          let obj: Record<string, UIExtensionContentSession | object> = {
            'session': session,
            'messages': want.parameters.shareMessages
          };
          let storage: LocalStorage = new LocalStorage(obj);
          session.loadContent('pages/Index', storage);
        }
      }
      onForeground() {
        console.info(TAG, `ononForeground`);
      }
      onBackground() {
        console.info(TAG, `onBackground`);
      }
      onSessionDestroy(session: UIExtensionContentSession) {
        console.info(TAG, `onSessionDestroy`);
      }
      onDestroy() {
        console.info(TAG, `onDestroy`);
      }
    }
    ```

4. 在工程Module对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中注册ActionExtensionAbility，type标签需要设置为“action”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "name": "ActionExtAbility",
           "icon": "$media:icon",
           "description": "action",
           "type": "action",
           "exported": true,
           "srcEntry": "./ets/actionextability/ActionExtAbility.ets"
         }
       ]
     }
   }
   ```

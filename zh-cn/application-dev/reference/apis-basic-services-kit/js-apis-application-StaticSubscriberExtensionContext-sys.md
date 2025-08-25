# @ohos.application.StaticSubscriberExtensionContext (StaticSubscriberExtensionContext)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

StaticSubscriberExtensionContext模块是StaticSubscriberExtensionAbility的上下文环境，继承自ExtensionContext。

StaticSubscriberExtensionContext模块提供StaticSubscriberExtensionAbility具有的接口和能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { StaticSubscriberExtensionContext } from '@kit.BasicServicesKit';
```

## 使用说明

在使用StaticSubscriberExtensionContext的功能前，需要通过StaticSubscriberExtensionAbility获取。

```ts
import { StaticSubscriberExtensionAbility, StaticSubscriberExtensionContext } from '@kit.BasicServicesKit';
```

## StaticSubscriberExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

拉起一个静态订阅所属的同应用的Ability。使用callback异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限

**需要权限**：ohos.permission.START_ABILITIES_FROM_BACKGROUND

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                       |
| -------- | ----------------------------------- | ---- | -------------------------- |
| want     | [Want](../apis-ability-kit/js-apis-wantAgent.md) | 是   | 启动Ability的want信息。    |
| callback | AsyncCallback&lt;void&gt;           | 是   | callback形式返回启动结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.      |
| 16000001 | The specified ability does not exist.                        |
| 16000002 | Incorrect ability type.                                      |
| 16000004 | Cannot start an invisible component.                           |
| 16000005 | The specified process does not have the permission.          |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |
| 16000053 | The ability is not on the top of the UI.                     |
| 16000055 | Installation-free timed out.                                 |
| 16200001 | The caller has been released.                                |
| 16300003 | The target application is not the current application.       |

**示例：**

  ```ts
import { commonEventManager, BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  bundleName: "com.example.myapp",
  abilityName: "MyAbility"
};

class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
  onReceiveEvent(event: commonEventManager.CommonEventData) {
    console.info(`onReceiveEvent, event: ${JSON.stringify(event)}`);

    try {
      this.context.startAbility(want, (error: BusinessError) => {
        if (error) {
          // 处理业务逻辑错误
          console.error(`startAbility failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}.`);
          return;
        }
        // 执行正常业务
        console.info('startAbility succeed');
      });
    } catch (paramError) {
      // 处理入参错误异常
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`startAbility failed, error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}.`);
    }
  }
}
  ```

## StaticSubscriberExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

拉起一个静态订阅所属的同应用的Ability。使用Promise异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限

**需要权限**：ohos.permission.START_ABILITIES_FROM_BACKGROUND

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型                                | 必填 | 说明                    |
| ------ | ----------------------------------- | ---- | ----------------------- |
| want   | [Want](../apis-ability-kit/js-apis-wantAgent.md) | 是   | 启动Ability的want信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.      |
| 16000001 | The specified ability does not exist.                        |
| 16000002 | Incorrect ability type.                                      |
| 16000004 | Cannot start an invisible component.                           |
| 16000005 | The specified process does not have the permission.          |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |
| 16000053 | The ability is not on the top of the UI.                     |
| 16000055 | Installation-free timed out.                                 |
| 16200001 | The caller has been released.                                |
| 16300003 | The target application is not the current application.       |

**示例：**

  ```ts
import { commonEventManager, BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  bundleName: "com.example.myapp",
  abilityName: "MyAbility"
};

class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
  onReceiveEvent(event: commonEventManager.CommonEventData) {
    console.info(`onReceiveEvent, event: ${JSON.stringify(event)}`);
    try {
      this.context.startAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startAbility failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}.`);
        });
    } catch (paramError) {
      // 处理入参错误异常
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`startAbility failed, error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}.`);
    }
  }
}
  ```
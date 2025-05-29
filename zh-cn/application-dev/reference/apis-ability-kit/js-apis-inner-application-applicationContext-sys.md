# ApplicationContext(系统接口)

ApplicationContext模块继承自[Context](js-apis-inner-application-context.md)，提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[ApplicationContext](js-apis-inner-application-applicationContext.md)。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

## ApplicationContext.preloadUIExtensionAbility<sup>12+</sup>

preloadUIExtensionAbility(want: Want): Promise\<void\>

预加载指定UIExtensionAbility实例。
被预加载的UIExtensionAbility实例会执行到UIExtensionAbility的OnCreate生命周期，然后等待被当前应用正式加载。支持多次预加载UIExtensionAbility实例，每次正式加载时，会使一个预加载的UIExtensionAbility实例从OnCreate继续完成UIExtensionAbility的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 预加载UIExtensionAbility的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16200011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    let want: Want = {
      bundleName: 'com.ohos.uiextensionprovider',
      abilityName: 'UIExtensionProvider',
      moduleName: 'entry',
      parameters: {
        //与UIExtensionAbility在module.json5中"type"字段配置一致
        'ability.want.params.uiExtensionType': 'sys/commonUI'
      }
    };
    try {
      let applicationContext = this.context.getApplicationContext();
      applicationContext.preloadUIExtensionAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('preloadUIExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error('preloadUIExtensionAbility failed');
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`preloadUIExtensionAbility failed. code: ${code}, msg: ${message}`);
    }
  }
}
```

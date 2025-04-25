# @ohos.app.ability.UIExtensionContentSession (带界面扩展能力界面操作类)(系统接口)

UIExtensionContentSession是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象，当UIExtensionComponent控件拉起指定的UIExtensionAbility时，UIExtensionAbility会创建UIExtensionContentSession对象，并通过[onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate)回调传递给开发者。一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，提供界面加载，结果通知等方法。每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.UIExtensionContentSession (带界面扩展能力界面操作类)](js-apis-app-ability-uiExtensionContentSession.md)。

## 导入模块

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
```

## UIExtensionContentSession.sendData

sendData(data: Record\<string, Object>): void

发送数据给UIExtensionComponent控件。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | Record\<string,&nbsp;Object> | 是 | 发送给UIExtensionComponent控件的数据参数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  private storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SendData')
        .onClick(() => {
          let data: Record<string, Object> = {
            'number': 123456,
            'message': 'test'
          };

          try {
            this.session?.sendData(data);
          } catch (err) {
            console.log('sendData err:' + JSON.stringify(err));
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## UIExtensionContentSession.setReceiveDataCallback

setReceiveDataCallback(callback: (data: Record\<string, Object>) => void): void

设置从UIExtensionComponent控件接收数据的回调方法。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | (data: Record\<string, Object>) => void | 是 | 回调函数，返回接收的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SendData')
        .onClick(() => {
          this.session?.setReceiveDataCallback((data: Record<string, Object>) => {
            console.info(`Succeeded in setReceiveDataCallback, data: ${JSON.stringify(data)}`);
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## UIExtensionContentSession.setReceiveDataForResultCallback<sup>11+</sup>

setReceiveDataForResultCallback(callback: (data: Record<string, Object>) => Record<string, Object>): void

设置从UIExtensionComponent控件接收数据带返回值的回调方法。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core


**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| -------- | -------- | -------- |----------------|
| callback | (data: { [key: string]: Object }) => { [key: string]: Object } | 是 | 回调函数，返回带返回值的接收的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SetReceiveDataForResultCallback')
        .onClick(() => {
          this.session?.setReceiveDataForResultCallback((data: Record<string, Object>) => {
            console.info(`Succeeded in setReceiveDataCallback, data: ${JSON.stringify(data)}`);
            return data;
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## UIExtensionContentSession.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    session.startAbility(want, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbility`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbility(want, starOptions, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbility`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动Ability。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbility(want, starOptions)
      .then(() => {
        console.info(`Succeeded in startAbility`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability，在Ability终止后返回结果给调用方。使用callback异步回调。

Ability的终止方式包括以下几种情况：
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式，不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其他调用方返回异常信息，异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数。当Ability启动并终止成功，err为undefined，data为获取到的结果码和数据；否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    session.startAbilityForResult(want, (err: BusinessError, data: common.AbilityResult) => {
      if (err) {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability，在Ability终止后返回结果给调用方。使用callback异步回调。

Ability的终止方式包括以下几种情况：
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式，不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其他调用方返回异常信息，异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数。当Ability启动并终止成功，err为undefined，data为获取到的结果码和数据；否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityForResult(want, starOptions, (err: BusinessError, data: common.AbilityResult) => {
      if (err) {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

启动一个Ability，在Ability终止后返回结果给调用方。使用Promise异步回调。

Ability的终止方式包括以下几种情况：
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式，不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其他调用方返回异常信息，异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
> 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise对象，返回结果码和数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityForResult(want, starOptions)
      .then((data: common.AbilityResult) => {
        console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

## UIExtensionContentSession.setWindowBackgroundColor

setWindowBackgroundColor(color: string): void

设置UIExtensionAbility加载界面的背景色。该接口需要在[loadContent()](js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionloadcontent)调用生效后使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| color | string | 是 | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('session', session);

    try {
      session.loadContent('pages/Extension', storage);
    } catch (err) {
      console.log('loadContent err:' + JSON.stringify(err));
    }

    try {
      session.setWindowBackgroundColor('#00FF00');
    } catch (err) {
      console.log('setWindowBackgroundColor err:' + JSON.stringify(err));
    }
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, callback: AsyncCallback\<void>): void

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionAbility。当ExtensionAbility通过该接口拉起另外一个Ability，被拉起的Ability可以从onCreate生命周期获取到初始Ability的caller信息。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    session.startAbilityAsCaller(localWant, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityAsCaller`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionAbility。当ExtensionAbility通过该接口拉起另外一个Ability，被拉起的Ability可以从onCreate生命周期获取到初始Ability的caller信息。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let startOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityAsCaller(localWant, startOptions, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityAsCaller`);
    })
  }

  // ...
}
```

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options?: StartOptions): Promise\<void>

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionAbility。当ExtensionAbility通过该接口拉起另外一个Ability，被拉起的Ability可以从onCreate生命周期获取到初始Ability的caller信息。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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
| 16000082 | The UIAbility is being started. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let startOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityAsCaller(localWant, startOptions)
      .then(() => {
        console.info(`Succeeded in startAbilityAsCaller`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

## UIExtensionContentSession.getUIExtensionHostWindowProxy<sup>11+</sup>

getUIExtensionHostWindowProxy(): uiExtensionHost.UIExtensionHostWindowProxy

获取当前UIExtension对应的窗口对象，用于通知宽高、位置、避让信息等。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [uiExtensionHost.UIExtensionHostWindowProxy](../apis-arkui/js-apis-uiExtensionHost-sys.md) | 宿主应用窗口信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { uiExtensionHost } from '@kit.ArkUI';

const TAG: string = '[UIExtAbility]';

export default class UIExtAbility extends UIExtensionAbility {
  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`);
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`);
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`);
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    let extensionHostWindow = session.getUIExtensionHostWindowProxy();
    let data: Record<string, UIExtensionContentSession | uiExtensionHost.UIExtensionHostWindowProxy> = {
      'session': session,
      'extensionHostWindow': extensionHostWindow
    };
    let storage: LocalStorage = new LocalStorage(data);

    try {
      session.loadContent('pages/Extension', storage);
    } catch (err) {
      console.log('loadContent err:' + JSON.stringify(err));
    }
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`);
  }
}
```

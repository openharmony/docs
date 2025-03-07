# FormExtensionContext (系统接口)

FormExtensionContext模块是[FormExtensionAbility](js-apis-app-form-formExtensionAbility.md)的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

FormExtensionContext模块提供FormExtensionAbility具有的接口和能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
> 本模块接口为系统接口。



## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## FormExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

拉起一个应用的Ability。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |
| callback| AsyncCallback&lt;void&gt;       | 是  | 回调函数。当拉起一个应用的Ability成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // 当触发卡片message事件时，执行startAbility
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    this.context.startAbility(want, (error: BusinessError) => {
      if (error) {
        console.error(`FormExtensionContext startAbility, error:${JSON.stringify(error)}`);
      } else {
        console.log('FormExtensionContext startAbility success');
      }
    });
  }
};
```

## FormExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

拉起一个应用的Ability。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // 当触发卡片message事件时，执行startAbility
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    this.context.startAbility(want).then(() => {
      console.info('StartAbility Success');
    }).catch((error: BusinessError) => {
      console.error(`StartAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
    });
  }
};
```

## FormExtensionContext.connectServiceExtensionAbility<sup>10+</sup>

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

将一个Ability与服务类型的Ability绑定。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| options | [ConnectOptions](../apis-ability-kit/js-apis-inner-ability-connectOptions.md) | 是 | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回一个connectId，后续根据此connectId断开连接。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permissions denied.             |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';
import { FormExtensionAbility } from '@kit.FormKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let commRemote: rpc.IRemoteObject | null = null;

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // 当触发卡片message事件时，执行connectServiceExtensionAbility
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote; // remote 用于与ServiceExtensionAbility进行通信
        console.log('----------- onConnect -----------');
      },
      onDisconnect(elementName) {
        console.log('----------- onDisconnect -----------')
      },
      onFailed(code) {
        console.error('----------- onFailed -----------')
      }
    };

    let connection: number | null = null;
    try {
      connection = this.context.connectServiceExtensionAbility(want, options);
    } catch (paramError) {
      // 处理入参错误异常
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```

## FormExtensionContext.disconnectServiceExtensionAbility<sup>10+</sup>

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback&lt;void&gt;): void

将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 在[connectServiceExtensionAbility](#formextensioncontextconnectserviceextensionability10)中返回的number。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当Ability与绑定的服务类型的Ability解绑成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

// commRemote为onConnect回调内返回的remote对象，此处定义为null无任何实际意义，仅作示例
let commRemote: rpc.IRemoteObject | null = null;
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // 实际使用时，connection为connectServiceExtensionAbility中的返回值，此处定义为1无任何实际意义，仅作示例
    let connection: number = 1;

    try {
      this.context.disconnectServiceExtensionAbility(connection, (error: BusinessError) => {
        commRemote = null;
        if (error.code) {
          // 处理业务逻辑错误
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
          return;
        }
        // 执行正常业务
        console.log('disconnectServiceExtensionAbility succeed');
      });
    } catch (paramError) {
      commRemote = null;
      // 处理入参错误异常
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```

## FormExtensionContext.disconnectServiceExtensionAbility<sup>10+</sup>

disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;

将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空(Promise形式返回结果)。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 在[connectServiceExtensionAbility](#formextensioncontextconnectserviceextensionability10)中返回的number。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

// commRemote为onConnect回调内返回的remote对象，此处定义为null无任何实际意义，仅作示例
let commRemote: rpc.IRemoteObject | null = null;
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // 实际使用时，connection为connectServiceExtensionAbility中的返回值，此处定义为1无任何实际意义，仅作示例
    let connection: number = 1;

    try {
      this.context.disconnectServiceExtensionAbility(connection)
        .then(() => {
          commRemote = null;
          // 执行正常业务
          console.log('disconnectServiceExtensionAbility succeed');
        })
        .catch((error: BusinessError) => {
          commRemote = null;
          // 处理业务逻辑错误
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      commRemote = null;
      // 处理入参错误异常
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```

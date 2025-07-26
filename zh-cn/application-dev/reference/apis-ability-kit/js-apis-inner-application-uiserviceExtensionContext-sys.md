# UIServiceExtensionContext (系统接口)

UIServiceExtensionContext模块是[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

UIServiceExtensionContext模块提供访问[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)特定资源以及具有的能力，包括启动、停止、绑定、解绑Ability。

> **说明：**
>
>  - 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。
>  - 本模块接口为系统接口。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 使用说明

在使用UIServiceExtensionContext的功能前，需要通过[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)子类实例获取上下文环境。

**示例：**

```ts
import { common, UIServiceExtensionAbility } from '@kit.AbilityKit';

class UIServiceExtAbility extends UIServiceExtensionAbility {
  onCreate() {
    let context:common.UIServiceExtensionContext = this.context ; // 获取UIServiceExtensionContext
  }
}
```


## UIServiceExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动Ability，结果以Promise的形式返回。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 否 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 |是 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000019 | Can not match any component.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIServiceExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class UIEntryAbility extends UIServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MyAbility'
    };
    let options: StartOptions = {
      windowMode: 0,
    };

    try {
      this.context.startAbility(want, options)
        .then((data: void) => {
          // 执行正常业务
          console.log('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      // 处理入参错误异常
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```


## UIServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;

销毁[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

无。

**示例：**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class UIEntryAbility extends UIServiceExtensionAbility {
  onCreate() {
    this.context.terminateSelf().then(() => {
      // 执行正常业务
      console.log('terminateSelf succeed');
    }).catch((error: BusinessError) => {
      // 处理业务逻辑错误
      console.error(`terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}`);
    });
  }
}
```

## UIServiceExtensionContext.startAbilityByType

startAbilityByType(type: string, wantParam: Record&lt;string, Object&gt;,
    abilityStartCallback: AbilityStartCallback): Promise&lt;void&gt;

按目标ability的类型启动[UIAbility](js-apis-app-ability-uiAbility.md)或[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。仅支持处于前台的应用调用。


> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |  -------- |
| type | string  | 是 | 否 |  目标ability类型。 |
| wantParam | Record&lt;string, Object&gt;| 是 | 否 | want 参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md)| 是 | 否| 回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050  | Internal error.                                                                                         |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension_Sub] ';

@Entry
@Component
struct SubIndex {
  build() {
    Row() {
      Column() {
        Button("startAbilityByType")
          .fontSize(10)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIServiceExtensionContext;
            let startWant: Record<string, Object> = {
              'sceneType': 1,
              'email': [encodeURI('xxx@example.com'),
                encodeURI('xxx@example.com')], // 收件人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
              'cc': [encodeURI('xxx@example.com'),
                encodeURI('xxx@example.com')], // 抄收人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
              'bcc': [encodeURI('xxx@example.com'),
                encodeURI('xxx@example.com')], // 密送人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
              'subject': encodeURI('邮件主题'), // 邮件主题，对内容使用encodeURI()方法进行url编码
              'body': encodeURI('邮件正文'), // 邮件正文，对内容使用encodeURI()方法进行url编码
              'ability.params.stream': [encodeURI('附件uri1'),
                encodeURI('附件uri2')], // 附件uri，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
              'ability.want.params.uriPermissionFlag': 1
            };
            let abilityStartCallback: common.AbilityStartCallback = {
              onError: (code: number, name: string, message: string) => {
                console.error(TAG + `code: ${code}  name:${name}  message:${message}`);
              }
            };
            try {
              // 按目标ability的类型启动UIAbility或UIExtensionAbility
              context.startAbilityByType("mail", startWant, abilityStartCallback)
                .then(() => {
                  console.log(TAG + `Succeeded in windows starting ability`);
                }).catch((err: BusinessError) => {
                console.error(TAG +
                  `Failed to windows starting ability, Code is ${err.code}, message is ${err.message}.`);
              })
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(TAG + `Failed to windows starting ability, Code is ${code}, message is ${msg}.`);
            }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## UIServiceExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

连接到[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，返回连接id。


> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名               | 类型                     | 只读 | 可选 | 说明              |
| -------------------- | ------------------------ | ---- | ---- |----------------- |
| want                 | [Want](js-apis-app-ability-want.md) | 是  | 否 | Want 参数。       |
| options              | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是 |是   | 连接选项。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回连接id。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息  |
| -------- | --- |
| 201     | Not system application.   |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001  | The specified ability does not exist.         |
| 16000002   | Incorrect ability type.         |
| 16000004   | Cannot start an invisible component.         |
| 16000005   | The specified process does not have the permission.         |
| 16000006   | Cross-user operations are not allowed.         |
| 16000008   | The crowdtesting application expires.        |
| 16000011   | The context does not exist.         |
| 16000050   | Internal error.        |
| 16000053   | The ability is not on the top of the UI.        |
| 16000055   | Installation-free timed out.         |


**示例：**

```ts
import { common, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
// The client needs to import idl_service_ext_proxy.ts provided by the server to the local project.
import IdlServiceExtProxy from '../IdlServiceExt/idl_service_ext_proxy';

const TAG: string = '[Page_ServiceExtensionAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

let connectionId: number;
let want: Want = {
  deviceId: '',
  bundleName: 'com.samples.stagemodelabilitydevelop',
  abilityName: 'ServiceExtAbility'
};

let options: common.ConnectOptions = {
  onConnect(elementName, remote: rpc.IRemoteObject): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onConnect callback');
    if (remote === null) {
      hilog.info(DOMAIN_NUMBER, TAG, `onConnect remote is null`);
      return;
    }
    let serviceExtProxy: IdlServiceExtProxy = new IdlServiceExtProxy(remote);
    // Communication is carried out by API calling, without exposing RPC details.
    serviceExtProxy.processData(1, (errorCode: number, retVal: number) => {
      hilog.info(DOMAIN_NUMBER, TAG, `processData, errorCode: ${errorCode}, retVal: ${retVal}`);
    });
    serviceExtProxy.insertDataToMap('theKey', 1, (errorCode: number) => {
      hilog.info(DOMAIN_NUMBER, TAG, `insertDataToMap, errorCode: ${errorCode}`);
    })
  },
  onDisconnect(elementName): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
  },
  onFailed(code: number): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback', JSON.stringify(code));
  }
};
@Entry
@Component
struct Page_UIServiceExtensionAbility {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let context: common.UIServiceExtensionContext = this.getUIContext().getHostContext() as common.UIServiceExtensionContext;
            // The ID returned after the connection is set up must be saved. The ID will be used for disconnection.
            connectionId = context.connectServiceExtensionAbility(want, options);
            // The background service is connected.
            this.getUIContext().getPromptAction().showToast({
              message: $r('app.string.SuccessfullyConnectBackendService')
            });
            // connectionId = context.connectAbility(want, options);
            hilog.info(DOMAIN_NUMBER, TAG, `connectionId is : ${connectionId}`);
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```

## UIServiceExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connectionId: number): Promise&lt;void&gt;

断开与[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)的连接，与[connectServiceExtensionAbility](#uiserviceextensioncontextconnectserviceextensionability)功能相反。


**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名                | 类型                     | 只读 | 可选 | 说明              |
| -------------------- | ------------------------ | ---- | ----------------- | ----------------- |
| connectionId         | number                   | 是  | 否 | 从[connectServiceExtensionAbility](#uiserviceextensioncontextconnectserviceextensionability)接口返回的连接Id。 |


**返回值：**

| 类型                | 说明                              |
| ------------------- | ---------------------------------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011  | The context does not exist.      |
| 16000050 | Internal error.      |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_ServiceExtensionAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

let connectionId: number;
@Entry
@Component
struct Page_UIServiceExtensionAbility {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let context: common.UIServiceExtensionContext = this.getUIContext().getHostContext() as common.UIServiceExtensionContext;
            // connectionId为调用connectServiceExtensionAbility接口时的返回值，需开发者自行维护
            context.disconnectServiceExtensionAbility(connectionId).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'disconnectServiceExtensionAbility success');
              // 成功断连后台服务
              this.getUIContext().getPromptAction().showToast({
                message: $r('app.string.SuccessfullyDisconnectBackendService')
              });
            }).catch((error: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, 'disconnectServiceExtensionAbility failed');
            });
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```

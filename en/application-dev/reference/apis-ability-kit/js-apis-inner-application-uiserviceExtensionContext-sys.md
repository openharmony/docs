# UIServiceExtensionContext (System API)

The UIServiceExtensionContext module, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for a [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md).

UIServiceExtensionContext provides access to a UIServiceExtensionAbility and APIs for operating the ability, for example, starting, terminating, connecting, and disconnecting ability.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## How to Use

Before using the APIs of UIServiceExtensionContext, you must obtain the context through a child class instance [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md).

**Example**

```ts
import { common, UIServiceExtensionAbility } from '@kit.AbilityKit';

class UIServiceExtAbility extends UIServiceExtensionAbility {
  onCreate() {
    let context:common.UIServiceExtensionContext = this.context; // Obtain the UIServiceExtensionContext.
  }
}
```


## UIServiceExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| No| Want information about the target ability, such as the ability name and bundle name.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes|Yes| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
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
| 16000019 | Can not match any component.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

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
          // Carry out normal service processing.
          console.log('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error(`startAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```


## UIServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;

Terminates this [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

N/A

**Example**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class UIEntryAbility extends UIServiceExtensionAbility {
  onCreate() {
    this.context.terminateSelf().then(() => {
      // Carry out normal service processing.
      console.log('terminateSelf succeed');
    }).catch((error: BusinessError) => {
      // Process service logic errors.
      console.error(`terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}`);
    });
  }
}
```

## UIServiceExtensionContext.startAbilityByType

startAbilityByType(type: string, wantParam: Record&lt;string, Object&gt;,
    abilityStartCallback: AbilityStartCallback): Promise&lt;void&gt;

Starts a [UIAbility](js-apis-app-ability-uiAbility.md) or [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) based on the type of the target ability. This API can be called only by applications running in the foreground.


> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- |  -------- |
| type | string  | Yes| No|  Type of the target ability.|
| wantParam | Record&lt;string, Object&gt;| Yes| No| Want parameter.|
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md)| Yes| No| Callback.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050  | Internal error.                                                                                         |

**Example**

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
            let context = getContext(this) as common.UIServiceExtensionContext;
            let startWant: Record<string, Object> = {
              'sceneType': 1,
              'email': [encodeURI('xxx@example.com'), encodeURI('xxx@example.com')], // Email address of the recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
              'cc': [encodeURI('xxx@example.com'), encodeURI('xxx@example.com')], // Email address of the CC recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
              'bcc': [encodeURI('xxx@example.com'), encodeURI('xxx@example.com')], // Email address of the BCC recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
              'subject': encodeURI('Email subject'), // Email subject. The content is URL encoded using encodeURI().
              'body': encodeURI('Email body'), // Email body. The content is URL encoded using encodeURI().
              'ability.params.stream':[encodeURI('attachment uri1'), encodeURI('attachment uri2')], // Attachment URIs. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
              'ability.want.params.uriPermissionFlag': 1
            };
            let abilityStartCallback: common.AbilityStartCallback = {
              onError: (code: number, name: string, message: string) => {
                console.log(TAG + `code: ${code}  name:${name}  message:${message}`);
              }
            };
            try {
              // Start a UIAbility or UIExtensionAbility based on the type of the target ability.
              context.startAbilityByType("mail", startWant, abilityStartCallback)
                .then(() => {
                  console.log(TAG + `Successed in windows starting ability`);
                }).catch((err: BusinessError) => {
                console.log(TAG + `Failed to windows starting ability, Code is ${err.code}, message is ${err.message}`);
              })
            } catch (err) {
              console.log(TAG + `Failed to windows starting ability, Code is ${err.code}, message is ${err.message}`);
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

Connects to a [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) and returns the connection ID.


> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name              | Type                    | Read Only| Optional| Description             |
| -------------------- | ------------------------ | ---- | ---- |----------------- |
| want                 | [Want](js-apis-app-ability-want.md) | Yes | No| Want parameter.      |
| options              | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes|Yes  | Connection options.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Connection ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message |
| -------- | --- |
| 201     | Not system application.   |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001  | The specified ability does not exist.         |
| 16000002   | Incorrect ability type.         |
| 16000004   | Failed to start the invisible ability.         |
| 16000005   | The specified process does not have the permission.         |
| 16000006   | Cross-user operations are not allowed.         |
| 16000008   | The crowdtesting application expires.        |
| 16000011   | The context does not exist.         |
| 16000050   | Internal error.        |
| 16000053   | The ability is not on the top of the UI.        |
| 16000055   | Installation-free timed out.         |


**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { promptAction } from '@kit.ArkUI';
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
            let context: common.UIServiceExtensionContext = getContext(this) as common.UIServiceExtensionContext;
            // The ID returned after the connection is set up must be saved. The ID will be used for disconnection.
            connectionId = context.connectServiceExtensionAbility(want, options);
            // The background service is connected.
            promptAction.showToast({
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

Disconnects from a [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). This API is opposite to [connectServiceExtensionAbility](#uiserviceextensioncontextconnectserviceextensionability).


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name               | Type                    | Read Only| Optional| Description             |
| -------------------- | ------------------------ | ---- | ----------------- | ----------------- |
| connectionId         | number                   | Yes | No| Connection ID returned by [connectServiceExtensionAbility](#uiserviceextensioncontextconnectserviceextensionability).|


**Return value**

| Type               | Description                             |
| ------------------- | ---------------------------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | --------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011  | The context does not exist.      |
| 16000050 | Internal error.      |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { promptAction } from '@kit.ArkUI';
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
            let context: common.UIServiceExtensionContext = getContext(this) as common.UIServiceExtensionContext;
            // connectionId is returned when connectServiceExtensionAbility is called and needs to be manually maintained.
            context.disconnectServiceExtensionAbility(connectionId).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'disconnectServiceExtensionAbility success');
              // The background service is disconnected.
              promptAction.showToast({
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

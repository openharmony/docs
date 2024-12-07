# UIExtensionComponent (System API)

**UIExtensionComponent** is used to embed UIs provided by other applications in the local application UI. The embedded content runs in another process, and the local application does not participate in its layout and rendering.

This component is usually used in modular development scenarios where process isolation is required.

> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this component are system APIs.

## Restrictions

This component does not support preview.

The ability to be started must be a UIExtensionAbility, an extension ability with UI. For details about how to implement a UIExtensionAbility, see [@ohos.app.ability.UIExtensionAbility (Base Class for ExtensionAbilities with UI)](../../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md).

The width and height of the component must be set to non-zero valid values.

## Child Components

Not supported

## APIs

UIExtensionComponent(want: Want, options?: UIExtensionOptions)

**Parameters**

| Name               | Type                                                  | Mandatory| Description          |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| want                  | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Ability to start. |
| options<sup>11+</sup> | [UIExtensionOptions](#uiextensionoptions11)                | No  | Construction parameters to be transferred.|

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## Events

The [universal events](ts-universal-events-click.md) are not supported.

The events are passed to the remote UIExtensionAbility for processing after coordinate conversion.

The following events are supported:

### onRemoteReady

onRemoteReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<UIExtensionProxy>)

Invoked when the connection to the remote UIExtensionAbility is set up, that is, the UIExtensionAbility is ready to receive data through the proxy.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| proxy                        | UIExtensionProxy | Proxy used to send data to the remote UIExtensionAbility.                         |

### onReceive

onReceive(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<{ [key: string]: Object }>)

Invoked when the data sent by the started UIExtensionAbility is received.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| data                        | { [key: string]: Object } | Data from the remote UIExtensionAbility.                |

### onResult<sup>(deprecated)</sup>

onResult(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<{code: number; want?: Want}>)

Invoked when the started UIExtensionAbility calls **terminateSelfWithResult**. After this callback is invoked, **OnRelease** is invoked.

The result data of the remote UIExtensionAbility can be processed in this callback. For details, see [AbilityResult](../../apis-ability-kit/js-apis-inner-ability-abilityResult.md).

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [onTerminated](#onterminated12) instead.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| code                        | number | Result code from the remote UIExtensionAbility.                         |
| want                        | Want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) of the result from the remote UIExtensionAbility.|

### onRelease<sup>(deprecated)</sup>

onRelease(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number>)

Invoked when the started UIExtensionAbility is destroyed.

If the UIExtensionAbility is destroyed correctly by calling **terminateSelfWithResult** or **terminateSelf**, the value of **releaseCode** is **0**.

If the UIExtensionAbility is destroyed because it crashes or is forced stopped, the value of **releaseCode** is **1**.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [onTerminated](#onterminated12) or [onError](#onerror) instead.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| releaseCode                        | number | Code that indicates how the remote UIExtensionAbility is destroyed. The value **0** means normal destruction, and **1** means abnormal destruction.                         |

### onError

onError(callback:[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback))

Invoked when an exception occurs during the running of the UIExtensionAbility. You can obtain the error information based on the **code**, **name**, and **message** parameters in the callback and rectify the exception accordingly.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| err                        | [BusinessError](../../apis-basic-services-kit/js-apis-base.md#businesserror) | Error information.   |

### onTerminated<sup>12+<sup>

onTerminated(callback: Callback&lt;TerminationInfo&gt;)

Called when the started UIExtensionAbility is terminated by calling **terminateSelfWithResult** or **terminateSelf**.

**Parameters**

| Name  | Type  | Description                                                                                    |
| -------  | ------ | ---------------------------------------------------------------------------------------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo12)> | Callback used to return the result from the UIExtensionAbility.|

> **NOTE**
>
> - If the UIExtensionAbility is terminated by calling **terminateSelfWithResult**, the carried information is passed as arguments into the callback function.
> - If the UIExtensionAbility is terminated by calling **terminateSelf**, the input parameters **code** and **want** in the callback function are at their default values: **0** and **undefined**, respectively.

### TerminationInfo<sup>12+<sup>

Represents the result returned when the UIExtensionAbility that has been started exits properly by calling **terminateSelfWithResult** or **terminateSelf**.

| Name | Type  | Description                                                |
| ------- | ------ | ---------------------------------------------------  |
| code    | number | Result code returned when the UIExtensionAbility exits.|
| want    | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)   | Data returned when the UIExtensionAbility exits.  |

## UIExtensionOptions<sup>11+</sup>
Describes the optional construction parameters during **UIExtensionComponent** construction.

**Parameters**

| Name              | Type                                | Mandatory| Description                                                                                                     |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| isTransferringCaller | boolean                                  | No  | Whether the UIExtensionComponent forwards the upper-level caller information when it is used for nesting.<br> Default value: **false**|
| placeholder<sup>12+<sup> | [ComponentContent](../js-apis-arkui-ComponentContent.md)       | No  | Placeholder to be displayed before the UIExtensionComponent establishes a connection with the UIExtensionAbility.|
| dpiFollowStrategy<sup>12+<sup> | [DpiFollowStrategy](ts-container-ui-extension-component-sys.md#dpifollowstrategy12)                  | No  | Whether the DPI settings follow the host or UIExtensionAbility.<br> Default value: **FOLLOW_UI_EXTENSION_ABILITY_DPI**|

## DpiFollowStrategy<sup>12+</sup>

| Name                            | Description            |
| -------------------------------- | --------------- |
| FOLLOW_HOST_DPI                  | The DPI settings follow the host.|
| FOLLOW_UI_EXTENSION_ABILITY_DPI  | The DPI settings follow the UIExtensionAbility.|

## UIExtensionProxy

Implements a **UIExtensionProxy** instance for the component host to send data to, subscribe to, or unsubscribe from the started UIExtensionAbility through the connection established between the two parties.

### send

send(data: { [key: string]: Object }): void

Asynchronously sends data from the component host to the started UIExtensionAbility through the connection established between the two parties.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                    | Mandatory  | Description           |
| ---- | ---------------------------------------- | ---- | --------------- |
| data | { [key: string]: Object } | Yes   | Data to be asynchronously sent to the started UIExtensionAbility.|

### sendSync<sup>11+</sup>

sendSync(data: { [key: string]: Object }): { [key: string]: Object }

Synchronously sends data from the component host to the started UIExtensionAbility through the connection established between the two parties.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                    | Mandatory  | Description           |
| ---- | ---------------------------------------- | ---- | --------------- |
| data | { [key: string]: Object } | Yes   | Data to be synchronously sent to the started UIExtensionAbility.|

**Return value**

| Type| Description|
| ---- | ----|
|{ [key: string]: Object } | Data returned by the UIExtensionAbility.|

**Error codes**

| ID| Description|
| ---- | ----|
| 100011 | UIExtensionAbility not registered.|
| 100012 | Failed to send data.|

### on('asyncReceiverRegister')<sup>11+</sup>

on(type: 'asyncReceiverRegister', callback: (proxy: UIExtensionProxy) => void): void

Subscribes to asynchronous registration of the started UIExtensionAbility through the connection established between the component host and UIExtensionAbility.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type|Mandatory| Description|
| ------ | -------- |---- | ------- |
| type   | string | Yes| Event type. The value is fixed at **'asyncReceiverRegister'**.|
| callback   | (proxy: UIExtensionProxy) => void | Yes| Callback used to return the result.|

### on('syncReceiverRegister')<sup>11+</sup>

on(type: 'syncReceiverRegister', callback: (proxy: UIExtensionProxy) => void): void

Subscribes to synchronous registration of the started UIExtensionAbility through the connection established between the component host and UIExtensionAbility.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type|Mandatory| Description|
| ------ | -------- |---- | ------- |
| type   | string | Yes| Event type. The value is fixed at **'syncReceiverRegister'**.|
| callback   | (proxy: UIExtensionProxy) => void | Yes| Callback used to return the result.|

### off('asyncReceiverRegister')<sup>11+</sup>

off(type: 'asyncReceiverRegister', callback?: (proxy: UIExtensionProxy) => void): void

Unsubscribes from asynchronous registration of the started UIExtensionAbility through the connection established between the component host and UIExtensionAbility.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type| Mandatory| Description|
| ------ | -------- | ----- | ------- |
| type   | string | Yes| Event type. The value is fixed at **'asyncReceiverRegister'**.|
| callback | (proxy: UIExtensionProxy) => void | No| Callback used for unsubscription.<br> If this parameter is not set, this API unsubscribes from all callbacks corresponding to **type**.|

### off('syncReceiverRegister')<sup>11+</sup>

off(type: 'syncReceiverRegister', callback?: (proxy: UIExtensionProxy) => void): void

Unsubscribes from synchronous registration of the started UIExtensionAbility through the connection established between the component host and UIExtensionAbility.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type| Mandatory| Description|
| ------ | -------- | ----- | ------- |
| type   | string | Yes| Event type. The value is fixed at **'syncReceiverRegister'**.|
| callback | (proxy: UIExtensionProxy) => void | No| Callback used for unsubscription.<br> If this parameter is not set, this API unsubscribes from all callbacks corresponding to **type**.|

## Example

This example shows only the method used by the component and the UIExtensionAbility. For the code to run properly, you need to install the ability whose **bundleName** is **"com.example.uiextensionprovider"** and **abilityName** is **"UIExtensionProvider"** on the device.

```ts
// Component usage example:
import { ComponentContent } from '@kit.ArkUI';
class Params {
}
@Builder
function LoadingBuilder(params: Params) {
  Column() {
   LoadingProgress()
      .color(Color.Blue)
  }
}
@Entry
@Component
struct Second {
  @State message1: string = 'Hello World 1'
  @State message2: string = 'Hello World 2'
  @State message3: string = 'Hello World 3'
  @State visible: Visibility = Visibility.Hidden
  @State wid: number = 300
  @State hei: number = 300
  private proxy: UIExtensionProxy | null = null;
  private contentNode = new ComponentContent(this.getUIContext(), wrapBuilder(LoadingBuilder), new Params);


  build() {
    Row() {
      Column() {
        Text(this.message1).fontSize(30)
        Text(this.message2).fontSize(30)
        Text(this.message3).fontSize(30)
        UIExtensionComponent({
          bundleName : "com.example.newdemo",
          abilityName: "UIExtensionProvider",
          parameters: {
            "ability.want.params.uiExtensionType": "dialog"
          }},
          {
            placeholder: this.contentNode
          })
          .width(this.wid)
          .height(this.hei)
          .border({width: 5, color: Color.Blue})
          .onReceive((data) => {
            console.info('Lee onReceive, for test')
            this.message3 = JSON.stringify(data['data'])
          })
          .onTerminated((info) => {
            console.info('onTerminated: code =' + info.code + ', want = ' + JSON.stringify(info.want));
          })
          .onRemoteReady((proxy) => {
            console.info('onRemoteReady, for test')
            this.proxy = proxy

            this.proxy.on("syncReceiverRegister", syncRegisterCallback1);
            // this.proxy.on("syncReceiverRegister", syncRegisterCallback2);


            // this.proxy.off("syncReceiverRegister");

            // this.proxy.off("syncReceiverRegister", (proxy) => {
            //   console.info("off invoke for test, type is syncReceiverRegister");
            // });

            this.proxy.on("asyncReceiverRegister", (proxy1) => {
              console.info("on invoke for test, type is asyncReceiverRegister");
            });
            //
            // this.proxy.off("asyncReceiverRegister");
          })

        Button ("Send to UIExtensionAbility").onClick(() => {
          if (this.proxy != undefined) {
            this.proxy.send({data: "Hello 1"})

            try {
              let re = this.proxy.sendSync({data: "Hello 2"})
              console.info("for test, re=" + JSON.stringify(re));
            } catch (err) {
              console.error(`sendSync failed for test. errCode=${err.code}, msg=${err.message}`);
            }
          }
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}

function syncRegisterCallback1(proxy: UIExtensionProxy) {
  console.info("on invoke for test, syncRegisterCallback1, type is syncReceiverRegister");
}

function syncRegisterCallback2(proxy: UIExtensionProxy) {
  console.info("on invoke for test, syncRegisterCallback2, type is syncReceiverRegister");
}
```

```ts
// Extension entry point file UIExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[UIExtAbility]'
export default class UIExtAbility extends UIExtensionAbility {
  
  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`)
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`)
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`)
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`)
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionCreate, want: ${JSON.stringify(want)}`)
    let param: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(param);
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)
  }
}
```

```ts
// Entry page file of the Extension Ability: extension.ets
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { router } from '@kit.ArkUI';

let storage = LocalStorage.getShared()
AppStorage.setOrCreate('message', 'UIExtensionAbility')

@Entry(storage)
@Component
struct Extension {
  @StorageLink('message') storageLink: string = '';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');

  onPageShow() {
    if (this.session != undefined) {
      this.session.setReceiveDataCallback((data)=> {
        this.storageLink = JSON.stringify(data)
        console.info("invoke for test, handle callback set by setReceiveDataCallback successfully");
      })

      this.session.setReceiveDataForResultCallback(func1)
    }
  }

  build() {
    Row() {
      Column() {
        Text(this.storageLink)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Send to Component").onClick(()=>{
          if (this.session != undefined) {
            this.session.sendData({"data": 543321})
            console.info('send 543321, for test')
          }
        })
        Button("terminate").onClick(()=> {
          if (this.session != undefined) {
            this.session.terminateSelf();
          }
          storage.clear()
        })
        Button("terminate with result").onClick(()=>{
          if (this.session != undefined) {
            this.session.terminateSelfWithResult({
              resultCode: 0,
              want: {
                bundleName: "myBundleName",
                parameters: { "result": 123456 }
              }
            })
          }
          storage.clear()
        })

        Button("Redirect").onClick(()=> {
          router.pushUrl({url: 'pages/hello'})
        })
      }
    }
    .height('100%')
  }
}
function func1(data: Record<string, Object>): Record<string, Object> {
  let linkToMsg: SubscribedAbstractProperty<string> = AppStorage.link('message');
  linkToMsg.set(JSON.stringify(data))
  console.info("invoke for test, handle callback set by setReceiveDataForResultCallback successfully");
  return data;
}

```

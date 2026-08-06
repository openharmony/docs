# SecurityUIExtensionComponent (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

SecurityUIExtensionComponent用于支持在本页面内嵌入其他应用提供的UI，展示的内容在另一个进程中运行，本应用并不参与其中的布局和渲染。

通常用于有进程隔离诉求的模块化开发场景，SecurityUIExtensionComponent当前仅支持拉起[PhotoPicker](../../apis-media-library-kit/ohos-file-PhotoPickerComponent.md)类型的UIExtensionAbility。

> **说明：**
>
> - 本模块接口为系统接口。
>
> - 本模块接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

## 子组件

无

## 接口

SecurityUIExtensionComponent(want: Want, options?: SecurityUIExtensionOptions)

创建SecurityUIExtensionComponent组件，用于嵌入显示远程[UIExtensionAbility](../../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)提供的UI。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md#want) | 是 | 要加载的Ability信息。通过bundleName和abilityName共同确定被拉起的UIExtensionAbility，同时需要在parameters中配置ability.want.params.uiExtensionType字段指定UIExtensionAbility的类型，当前仅支持'sysPicker/photoPicker'。 |
| options | [SecurityUIExtensionOptions](#securityuiextensionoptions) | 否 | 用于构造SecurityUIExtensionComponent的参数。不填时各字段使用默认值。 |

## SecurityUIExtensionOptions

用于构造SecurityUIExtensionComponent时传递参数。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isTransferringCaller | boolean | 否 | 是 | 在使用SecurityUIExtensionComponent嵌套时，设置当前组件是否转发上一级调用方的Caller信息（即发起调用的Ability身份信息），用于支持多级嵌套场景下的调用链传递。<br>true：转发上一级的Caller信息；false：不转发上一级的Caller信息。<br>默认值：false |
| placeholder | [ComponentContent](../js-apis-arkui-ComponentContent.md#componentcontent-1) | 否 | 是 | 设置占位符，在SecurityUIExtensionComponent与UIExtensionAbility建立连接前显示。未设置时不显示占位符。 |
| dpiFollowStrategy | [SecurityDpiFollowStrategy](#securitydpifollowstrategy) | 否 | 是 | 设置SecurityUIExtensionComponent内容分辨率跟随策略，用于控制嵌入的UIExtensionAbility内容是跟随宿主应用的分辨率还是使用自身的分辨率。<br/>默认值：FOLLOW_UI_EXTENSION_ABILITY_DPI |

## SecurityDpiFollowStrategy

定义SecurityUIExtensionComponent内容分辨率跟随策略的枚举。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOLLOW_HOST_DPI | 0 | 表示分辨率跟随宿主。 |
| FOLLOW_UI_EXTENSION_ABILITY_DPI | 1 | 表示分辨率跟随UIExtensionAbility。 |

## 属性

支持[通用属性](ts-component-general-attributes.md)。

## 事件

支持以下事件：

### onRemoteReady

onRemoteReady(callback: Callback\<SecurityUIExtensionProxy\>)

UIExtensionAbility连接完成时触发的回调，使用callback异步回调。之后可通过返回的[SecurityUIExtensionProxy](#securityuiextensionproxy)向被拉起的Ability发送数据。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[SecurityUIExtensionProxy](#securityuiextensionproxy)\> | 是 | 回调函数，入参为SecurityUIExtensionProxy，可用于向对端Ability发送数据及事件订阅。 |

### onReceive

onReceive(callback: Callback\<Record\<string, Object\>\>)

收到被拉起的Ability发送的数据时触发的回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record\<string, Object\>\> | 是 | 回调函数，入参为收到的来自对端Ability的数据。数据为Record<string, Object>键值对，具体字段由发送方（被拉起的Ability）通过sendData方法自定义。 |

### onError

onError(callback: ErrorCallback)

被拉起的UIExtensionAbility在运行过程中发生异常时触发的回调，不包含与UIExtensionAbility断开连接场景。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是 | 回调函数，入参用于接收异常信息。 |

### onTerminated

onTerminated(callback: Callback\<TerminationInfo\>)

被拉起的UIExtensionAbility通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)或[terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)正常退出时触发此回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo)\> | 是 | 回调函数，入参用于接收UIExtensionAbility的返回结果。 |

## TerminationInfo

用于表示被拉起的UIExtensionAbility正常退出时的返回结果。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 被拉起的UIExtensionAbility退出时返回的结果码，0表示正常退出，非0表示异常退出。具体结果码含义由被拉起的UIExtensionAbility定义。 |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md#want) | 否 | 是 | 被拉起UIExtensionAbility退出时返回的数据。未返回数据时该字段为空。 |

## SecurityUIExtensionProxy

用于在双方建立连接成功后，向被拉起的Ability发送数据，以及订阅和取消订阅事件回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### send

send(data: Record\<string, Object\>): void

用于在双方建立连接成功后，向被拉起的Ability发送数据，提供异步发送能力。数据将被扩展Ability通过[setReceiveDataCallback](../../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession-sys.md#setreceivedatacallback)接收处理。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | Record\<string, Object\> | 是 | 异步发送给被拉起的Ability的数据。 |

### sendSync

sendSync(data: Record\<string, Object\>): Record\<string, Object\>

用于在双方建立连接成功后，向被拉起的Ability同步发送数据，数据将被拉起的Ability通过setReceiveDataForResultCallback处理并返回结果。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | Record\<string, Object\> | 是 | 同步发送给被拉起的Ability的数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Record\<string, Object\> | 被拉起的Ability对同步发送请求处理后返回的响应数据。 |

**错误码：**

以下错误码的详细介绍请参见[UIExtension错误码](../errorcode-uiextension.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 100011 | No callback has been registered to respond to this request. |
| 100012 | Transferring data failed. |

### on('asyncReceiverRegister')

on(type: 'asyncReceiverRegister', callback: Callback\<UIExtensionProxy\>): void

在双方建立连接成功后，订阅被拉起的Ability异步注册时触发的回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填'asyncReceiverRegister'，代表订阅被拉起的Ability异步注册时触发的回调。 |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[UIExtensionProxy](../../apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#uiextensionproxy)\> | 是 | 回调函数。订阅被拉起的Ability注册[setReceiveDataCallback](../../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession-sys.md#setreceivedatacallback)后触发的回调。 |

### on('syncReceiverRegister')

on(type: 'syncReceiverRegister', callback: Callback\<UIExtensionProxy\>): void

在双方建立连接成功后，订阅被拉起的Ability同步注册时触发的回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填'syncReceiverRegister'，代表订阅被拉起的Ability同步注册时触发的回调。 |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[UIExtensionProxy](../../apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#uiextensionproxy)\> | 是 | 回调函数。被拉起的Ability注册[setReceiveDataForResultCallback](../../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession-sys.md#setreceivedataforresultcallback11)后触发的回调。 |

### off('asyncReceiverRegister')

off(type: 'asyncReceiverRegister', callback?: Callback\<UIExtensionProxy\>): void

取消订阅被拉起的Ability异步注册时触发的回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填'asyncReceiverRegister'，取消订阅被拉起的Ability异步注册时触发的回调。 |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[UIExtensionProxy](../../apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#uiextensionproxy)\> | 否 | 回调函数。为空时取消订阅所有异步注册的回调。非空时取消订阅指定的异步注册回调。 |

### off('syncReceiverRegister')

off(type: 'syncReceiverRegister', callback?: Callback\<UIExtensionProxy\>): void

取消订阅被拉起的Ability同步注册时触发的回调。使用callback异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填'syncReceiverRegister'，取消订阅被拉起的Ability同步注册时触发的回调。 |
| callback | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[UIExtensionProxy](../../apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#uiextensionproxy)\> | 否 | 回调函数。为空时取消订阅所有同步注册的回调。非空时取消订阅指定的同步注册回调。 |

## 示例

### 示例1（SecurityUIExtensionComponent拉起远程UIExtensionAbility并进行双向数据通信）

本示例展示了SecurityUIExtensionComponent的使用方法，包括通过配置[Want](../../apis-ability-kit/js-apis-app-ability-want.md#want)拉起指定的UIExtensionAbility，通过[onRemoteReady](#onremoteready)获取[SecurityUIExtensionProxy](#securityuiextensionproxy)，使用[send](#send)或[sendSync](#sendsync)发送数据，以及通过[onReceive](#onreceive)、[onError](#onerror)、[onTerminated](#onterminated)等回调处理事件。

从API版本26.0.0开始，新增[onRemoteReady](#onremoteready)、[onReceive](#onreceive)、[onError](#onerror)、[onTerminated](#onterminated)事件。

**组件使用方**

``` TypeScript
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State receiveData: string = '';
  private want: Want = {
    bundleName: 'com.example.securityUIExtProvider',
    abilityName: 'SecurityUIExtProvider',
    parameters: {
      'ability.want.params.uiExtensionType': 'sysPicker/photoPicker',
    },
  };
  private proxy: SecurityUIExtensionProxy | null = null;

  build() {
    Column() {
      Text(this.message).fontSize(20).margin(10)
      Text('收到数据: ' + this.receiveData).fontSize(16).margin(10)

      SecurityUIExtensionComponent(this.want)
        .width('90%')
        .height('60%')
        .backgroundColor(Color.Green)
        .onRemoteReady((proxy: SecurityUIExtensionProxy) => {
          hilog.info(0x0000, 'SUECDemo', 'onRemoteReady');
          this.proxy = proxy;

          this.proxy.on('asyncReceiverRegister', asyncRegisterCallback);
          this.proxy.on('syncReceiverRegister', syncRegisterCallback);
        })
        .onReceive((data: Record<string, Object>) => {
          this.receiveData = JSON.stringify(data['data']);
          hilog.info(0x0000, 'SUECDemo', 'onReceive: ' + this.receiveData);
        })
        .onError((error: BusinessError) => {
          this.message = `Error: ${JSON.stringify(error)}`;
          hilog.error(0x0000, 'SUECDemo', `onError. Code: ${error.code}, message: ${error.message}`);
        })
        .onTerminated((info: TerminationInfo) => {
          hilog.info(0x0000, 'SUECDemo', 'onTerminated: code=' + info.code);
        })

      Button('发送异步数据')
        .margin(5)
        .onClick(() => {
          if (this.proxy) {
            this.proxy.send({ data: '来自使用方的异步消息' });
          }
        })

      Button('发送同步数据')
        .margin(5)
        .onClick(() => {
          if (this.proxy) {
            try {
              let result = this.proxy.sendSync({ data: '来自使用方的同步消息' });
              hilog.info(0x0000, 'SUECDemo', 'sendSync result: ' + JSON.stringify(result));
            } catch (err) {
              hilog.error(0x0000, 'SUECDemo', `sendSync failed. Code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
            }
          }
        })


      Button('取消同步注册监听')
        .margin(5)
        .onClick(() => {
          if (this.proxy) {
            this.proxy.off('syncReceiverRegister');
            hilog.info(0x0000, 'SUECDemo', `offSyncReceiverRegister`);
          }
        })

      Button('取消异步注册监听')
        .margin(5)
        .onClick(() => {
          if (this.proxy) {
            this.proxy.off('asyncReceiverRegister');
            hilog.info(0x0000, 'SUECDemo', `offAsyncReceiverRegister`);
          }
        })
    }
    .height('90%')
    .width('90%')
  }
}


const asyncRegisterCallback = (proxy: UIExtensionProxy) => {
  hilog.info(0x0000, 'SUECDemo', 'onAsyncReceiverRegister');
};

const syncRegisterCallback = (proxy: UIExtensionProxy) => {
  hilog.info(0x0000, 'SUECDemo', 'onSyncReceiverRegister');
};
```

**组件提供方**

提供方需要修改以下三个文件。

- 提供方新增扩展入口文件`/src/main/ets/uiextensionability/SecurityUIExtProvider.ets`。
  
  ```ts
  import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = '[SecurityUIExtAbility]';
  
  export default class SecurityUIExtProvider extends UIExtensionAbility {
    onCreate() {
      hilog.info(0x0000, TAG, 'onCreate');
    }
  
    onForeground() {
      hilog.info(0x0000, TAG, 'onForeground');
    }
  
    onBackground() {
      hilog.info(0x0000, TAG, 'onBackground');
    }
  
    onDestroy() {
      hilog.info(0x0000, TAG, 'onDestroy');
    }
  
    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      hilog.info(0x0000, TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
      let param: Record<string, UIExtensionContentSession> = {
        'session': session
      };
      let storage: LocalStorage = new LocalStorage(param);
      try {
        session.loadContent('pages/SecurityExtension', storage);
      } catch (error) {
        hilog.error(0x0000, TAG, `onSessionCreate loadContent failed. Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
      }
    }
  
    onSessionDestroy(session: UIExtensionContentSession) {
      hilog.info(0x0000, TAG, 'onSessionDestroy');
    }
  }
  ```

- 提供方扩展Ability入口页面文件`/src/main/ets/pages/SecurityExtension.ets`。
  
  ```ts
  import { UIExtensionContentSession } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  let storage = LocalStorage.getShared();
  AppStorage.setOrCreate('message', 'UIExtensionAbility');
  
  @Entry(storage)
  @Component
  struct SecurityExtension {
    @StorageLink('message') storageLink: string = '';
    private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  
    build() {
      Scroll() {
        Column() {
          Text(this.storageLink)
            .fontSize(10)
            .fontWeight(FontWeight.Bold)
            .width('80%')
            .height('10%')
  
          Button('点击向Component发送数据')
            .fontSize(12)
            .width('80%')
            .height('10%')
            .margin(1)
            .onClick(() => {
              hilog.info(0x0000, 'SecurityExtension', 'send 543321, for test start');
              if (this.session != undefined) {
                this.session.sendData({ 'data': 'Component应该接收到的数据' });
                hilog.info(0x0000, 'SecurityExtension', 'send for test');
              }
            })
  
          Button('terminate')
            .fontSize(12)
            .width('80%')
            .height('10%')
            .margin(1)
            .onClick(() => {
              hilog.info(0x0000, 'SecurityExtension', 'terminate');
              if (this.session != undefined) {
                this.session.terminateSelf();
              }
              storage.clear();
            })
  
          Button('terminate with result')
            .fontSize(12)
            .width('80%')
            .height('10%')
            .margin(1)
            .onClick(() => {
              hilog.info(0x0000, 'SecurityExtension', 'terminateSelfWithResult');
              if (this.session != undefined) {
                this.session.terminateSelfWithResult({
                  resultCode: 0,
                  want: {
                    bundleName: 'myBundleName',
                    parameters: { 'result': 123456 }
                  }
                });
              }
              storage.clear();
            })

          Button('setReceiveDataCallback')
            .fontSize(12)
            .width('80%')
            .height('10%')
            .margin(1)
            .onClick(() => {
              this.session?.setReceiveDataCallback((data) => {
                this.storageLink = JSON.stringify(data);
                hilog.info(0x0000, 'SecurityExtension', 'test setReceiveDataCallback successfully: ' + this.storageLink);
              })
            })
  
          Button('setReceiveDataForResultCallback')
            .fontSize(12)
            .width('80%')
            .height('10%')
            .margin(1)
            .onClick(() => {
              this.session?.setReceiveDataForResultCallback(receiveDataForResultCallback);
            })
        }
      }
      .id('providerScroll')
      .width('100%')
      .height('100%')
    }
  }
  
  const receiveDataForResultCallback = (data: Record<string, Object>): Record<string, Object> => {
    let linkToMsg: SubscribedAbstractProperty<string> = AppStorage.link('message');
    linkToMsg.set(JSON.stringify(data));
    hilog.info(0x0000, 'SecurityExtension',
      'invoke for test, handle callback set by setReceiveDataForResultCallback successfully');
    return data;
  }
  ```

- 提供方module.json5配置。
  
  ```json
  "extensionAbilities": [
        {
          "name": "SecurityUIExtProvider",
          "srcEntry": "./ets/uiextensionability/SecurityUIExtProvider.ets",
          "description": "$string:module_desc",
          "label": "$string:EntryAbility_desc",
          "type": "sysPicker/photoPicker",
          "exported": true,
          "metadata" : [{
            "name" : "supportUIInteraction",
            "value": "false"
          }]
        }
      ]
  ```

# 多端协同


## 功能描述

多端协同主要包括如下场景：

- [多端协同](#多端协同)
  - [功能描述](#功能描述)
  - [多端协同流程](#多端协同流程)
  - [约束限制](#约束限制)
  - [通过跨设备启动UIAbility和ServiceExtensionAbility组件实现多端协同（无返回数据）](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)
    - [接口说明](#接口说明)
    - [开发步骤](#开发步骤)
  - [通过跨设备启动UIAbility组件实现多端协同（获取返回数据）](#通过跨设备启动uiability组件实现多端协同获取返回数据)
    - [接口说明](#接口说明-1)
    - [开发步骤](#开发步骤-1)
  - [通过跨设备连接ServiceExtensionAbility组件实现多端协同](#通过跨设备连接serviceextensionability组件实现多端协同)
    - [接口说明](#接口说明-2)
    - [开发步骤](#开发步骤-2)
  - [通过跨设备Call调用实现多端协同](#通过跨设备call调用实现多端协同)
    - [接口说明](#接口说明-3)
    - [开发步骤](#开发步骤-3)


## 多端协同流程

多端协同流程如下图所示。

  **图1** 多端协同流程图  
![hop-multi-device-collaboration](figures/hop-multi-device-collaboration.png)


## 约束限制

- 由于“多端协同任务管理”能力尚未具备，开发者当前只能通过开发系统应用获取设备列表，不支持三方应用接入。

- 多端协同需遵循[分布式跨设备组件启动规则](component-startup-rules.md#分布式跨设备组件启动规则)。

- 为了获得最佳体验，使用want传输的数据建议在100KB以下。


## 通过跨设备启动UIAbility和ServiceExtensionAbility组件实现多端协同（无返回数据）

在设备A上通过发起端应用提供的启动按钮，启动设备B上指定的UIAbility与ServiceExtensionAbility。


### 接口说明

  **表1** 跨设备启动API接口功能介绍

| **接口名** | **描述** |
| -------- | -------- |
| startAbility(want:&nbsp;Want,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | 启动UIAbility和ServiceExtensionAbility（callback形式）。 |
| stopServiceExtensionAbility(want:&nbsp;Want,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | 退出启动的ServiceExtensionAbility（callback形式）。 |
| stopServiceExtensionAbility(want:&nbsp;Want):&nbsp;Promise&lt;void&gt;; | 退出启动的ServiceExtensionAbility（Promise形式）。 |


### 开发步骤

1. 需要申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/AccessToken/request-user-authorization.md)。

3. 获取目标设备的设备ID。

   ```ts
   import deviceManager from '@ohos.distributedDeviceManager';
   import hilog from '@ohos.hilog';
   import promptAction from '@ohos.promptAction'
   
   const TAG: string = '[Page_CollaborateAbility]';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   let dmClass: deviceManager.DeviceManager;
   
   function initDmClass(): void {
     // 其中createDeviceManager接口为系统API
     try {
       dmClass = deviceManager.createDeviceManager('com.samples.stagemodelabilitydevelop');
       hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass) ?? '');
       promptAction.showToast({
         message: $r('app.string.InitializedSuccessfully')
       });
     } catch (err) {
       hilog.error(DOMAIN_NUMBER, TAG, 'createDeviceManager err: ' + JSON.stringify(err));
     };
   }
   
   function getRemoteDeviceId(): string | undefined {
     if (typeof dmClass === 'object' && dmClass !== null) {
       let list = dmClass.getAvailableDeviceListSync();
       hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
       if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
         hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
         return;
       }
       if (list.length === 0) {
         hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
         return;
       }
       return list[0].networkId;
     } else {
       hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
       return;
     }
   }
   ```

4. 设置目标组件参数，调用[`startAbility()`](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口，启动UIAbility或ServiceExtensionAbility。

   ```ts
   import { BusinessError } from '@ohos.base';
   import hilog from '@ohos.hilog';
   import Want from '@ohos.app.ability.Want';
   
   const TAG: string = '[Page_CollaborateAbility]';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   let want: Want = {
     deviceId: getRemoteDeviceId(),
     bundleName: 'com.samples.stagemodelabilityinteraction',
     abilityName: 'CollaborateAbility'
   }
   this.context.startAbility(want).then(() => {
     promptAction.showToast({
       message: $r('app.string.SuccessfulCollaboration')
     });
   }).catch((err: BusinessError) => {
     hilog.error(DOMAIN_NUMBER, TAG, `startAbility err: ` + JSON.stringify(err));
   });
   ```

5. 当设备A发起端应用不需要设备B上的ServiceExtensionAbility时，可调用[stopServiceExtensionAbility](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstopserviceextensionability)接口退出。（该接口不支持UIAbility的退出，UIAbility由用户手动通过任务管理退出）

   ```ts
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   let want: Want = {
       deviceId: getRemoteDeviceId(),
       bundleName: 'com.example.myapplication',
       abilityName: 'FuncAbility',
       moduleName: 'module1', // moduleName非必选
   }
   // 退出由startAbility接口启动的ServiceExtensionAbility
   this.context.stopServiceExtensionAbility(want).then(() => {
       console.info("stop service extension ability success")
   }).catch((err: BusinessError) => {
       console.info("stop service extension ability err is " + JSON.stringify(err))
   })
   ```

## 通过跨设备启动UIAbility组件实现多端协同（获取返回数据）

在设备A上通过应用提供的启动按钮，启动设备B上指定的UIAbility，当设备B上的UIAbility退出后，会将返回值发回设备A上的发起端应用。


### 接口说明

  **表2** 跨设备启动，返回结果数据API接口功能描述

| 接口名 | 描述 |
| -------- | -------- |
| startAbilityForResult(want:&nbsp;Want,&nbsp;callback:&nbsp;AsyncCallback&lt;AbilityResult&gt;):&nbsp;void; | 启动UIAbility并在该Ability退出的时候返回执行结果（callback形式）。 |
| terminateSelfWithResult(parameter:&nbsp;AbilityResult,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | 停止UIAbility，配合startAbilityForResult使用，返回给接口调用方AbilityResult信息（callback形式）。 |
| terminateSelfWithResult(parameter:&nbsp;AbilityResult):&nbsp;Promise&lt;void&gt;; | 停止UIAbility，配合startAbilityForResult使用，返回给接口调用方AbilityResult信息（promise形式）。 |


### 开发步骤

1. 需要申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/AccessToken/request-user-authorization.md)。

3. 在发起端设置目标组件参数，调用startAbilityForResult()接口启动目标端UIAbility，异步回调中的data用于接收目标端UIAbility停止自身后返回给调用方UIAbility的信息。getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。

   ```ts
   import common from '@ohos.app.ability.common';
   import hilog from '@ohos.hilog';
   import { BusinessError } from '@ohos.base';
   
   const DOMAIN_NUMBER: number = 0xFF00;
   const TAG: string = '[Page_CollaborateAbility]';
   
   @Entry
   @Component
   struct Page_CollaborateAbility {
      private context = getContext(this) as common.UIAbilityContext;
     
      build() {
        // ...
        Button('多端协同有返回数据')
          .onClick(()=>{
            let want: Want = {
              deviceId: getRemoteDeviceId(),
              bundleName: 'com.samples.stagemodelabilityinteraction',
              abilityName: 'CollaborateAbility',
              moduleName: 'entry' // moduleName非必选
            };
           // context为发起端UIAbility的AbilityContext
           this.context.startAbilityForResult(want).then((data) => {
               // ...
           }).catch((error: BusinessError) => {
               hilog.error(DOMAIN_NUMBER, TAG, `startAbilityForResult err: ` + JSON.stringify(error));
           })
          }
        )
      }
   }
   ```

4. 在目标端UIAbility任务完成后，调用terminateSelfWithResult()方法，将数据返回给发起端的UIAbility。

   ```ts
   import common from '@ohos.app.ability.common';
   import hilog from '@ohos.hilog';
   import { BusinessError } from '@ohos.base';
   
   const DOMAIN_NUMBER: number = 0xFF00;
   const TAG: string = '[Page_CollaborateAbility]';
   
   @Entry
   @Component
   struct PageName {
     
      private context = getContext(this) as common.UIAbilityContext;
     
      build() {
        // ...
        Button('关闭多设备协同界面并返回数据')
          .onClick(()=>{
          const RESULT_CODE: number = 1001;
          // context为目标端UIAbility的AbilityContext
          this.context.terminateSelfWithResult(
            {
              resultCode: RESULT_CODE,
              want: {
                bundleName: 'ohos.samples.stagemodelabilitydevelop',
                abilityName: 'CollaborateAbility',
                moduleName: 'entry',
                parameters: {
                  info: '来自Page_CollaborateAbility页面'
                }
              }
            },
            (err: BusinessError) => {
              hilog.info(DOMAIN_NUMBER, TAG, `terminateSelfWithResult err: ` + JSON.stringify(err));
            });
        })
      }
   }
   ```

5. 发起端UIAbility接收到目标端UIAbility返回的信息，对其进行处理。

   ```ts
   import common from '@ohos.app.ability.common';
   import deviceManager from '@ohos.distributedDeviceManager';
   import hilog from '@ohos.hilog';
   import promptAction from '@ohos.promptAction'
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   
   const TAG: string = '[Page_CollaborateAbility]';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   @Entry
   @Component
   struct PageName {
     
      private context = getContext(this) as common.UIAbilityContext;
     
      build() {
        // ...
        Button('多端协同有返回数据')
          .onClick(()=>{
             let want: Want = {
               deviceId: getRemoteDeviceId(),
               bundleName: 'com.samples.stagemodelabilityinteraction',
               abilityName: 'CollaborateAbility',
               moduleName: 'entry' // moduleName非必选
             };
            const RESULT_CODE: number = 1001;
            // ...
            // context为调用方UIAbility的UIAbilityContext
            this.context.startAbilityForResult(want).then((data) => {
                if (data?.resultCode === RESULT_CODE) {
                    // 解析目标端UIAbility返回的信息
                    let info = data.want?.parameters?.info;
                    // ...
                }
            }).catch((error: BusinessError) => {
                // ...
            })
          }
        )
      }
   }
   ```


## 通过跨设备连接ServiceExtensionAbility组件实现多端协同

系统应用可以通过[connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextconnectserviceextensionability)跨设备连接一个服务，实现跨设备远程调用。比如：分布式游戏场景，平板作为遥控器，智慧屏作为显示器。


### 接口说明

  **表3** 跨设备连接API接口功能介绍

| 接口名 | 描述 |
| -------- | -------- |
| connectServiceExtensionAbility(want:&nbsp;Want,&nbsp;options:&nbsp;ConnectOptions):&nbsp;number; | 连接ServiceExtensionAbility。 |
| disconnectServiceExtensionAbility(connection:&nbsp;number,&nbsp;callback:AsyncCallback&lt;void&gt;):&nbsp;void; | 断开连接（callback形式）。 |
| disconnectServiceExtensionAbility(connection:&nbsp;number):&nbsp;Promise&lt;void&gt;; | 断开连接（promise形式）。 |


### 开发步骤

1. 需要申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/AccessToken/request-user-authorization.md)。

3. 如果已有后台服务，请直接进入下一步；如果没有，则[实现一个后台服务](serviceextensionability.md#实现一个后台服务（仅对系统应用开放）)。

4. 连接一个后台服务。
   - 实现IAbilityConnection接口。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常终止的回调，onFailed()是用来处理连接Service失败的回调。
   - 设置目标组件参数，包括目标设备ID、Bundle名称、Ability名称。
   - 调用connectServiceExtensionAbility发起连接。
   - 连接成功，收到目标设备返回的服务句柄。
   - 进行跨设备调用，获得目标端服务返回的结果。
     
      ```ts
      import common from '@ohos.app.ability.common';
      import deviceManager from '@ohos.distributedDeviceManager';
      import hilog from '@ohos.hilog';
      import Logger from '../../utils/Logger';
      import promptAction from '@ohos.promptAction';
      import rpc from '@ohos.rpc';
      import Want from '@ohos.app.ability.Want';
      import { BusinessError } from '@ohos.base';
      import { Caller } from '@ohos.app.ability.UIAbility';
      
      const TAG: string = '[Page_CollaborateAbility]';
      const DOMAIN_NUMBER: number = 0xFF00;
      const REQUEST_CODE = 1;
      
      let connectionId: number;
      let options: common.ConnectOptions = {
        onConnect(elementName, remote) {
          Logger.info('onConnect callback');
          if (remote === null) {
            hilog.info(DOMAIN_NUMBER, TAG, `onConnect remote is null`);
            return;
          }
          let option = new rpc.MessageOption();
          let data = new rpc.MessageSequence();
          let reply = new rpc.MessageSequence();
          data.writeInt(99);
          // 开发者可发送data到目标端应用进行相应操作
          // @param code 表示客户端发送的服务请求代码。
          // @param data 表示客户端发送的{@link MessageSequence}对象。
          // @param reply 表示远程服务发送的响应消息对象。
          // @param options 指示操作是同步的还是异步的。
          //
          // @return 如果操作成功返回{@code true}； 否则返回 {@code false}。
          remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
            let errCode = reply.readInt(); // 在成功连接的情况下，会收到来自目标端返回的信息（100）
            let msg: number = 0;
            if (errCode === 0) {
              msg = reply.readInt();
            }
            hilog.info(DOMAIN_NUMBER, TAG, `sendRequest msg:${msg}`);
            // 成功连接后台服务
            promptAction.showToast({
              message: `sendRequest msg:${msg}`
            })
          }).catch((error: BusinessError) => {
            hilog.info(DOMAIN_NUMBER, TAG, `sendRequest failed, ${JSON.stringify(error)}`);
          });
        },
        onDisconnect(elementName) {
          hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
        },
        onFailed(code) {
          hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback');
        }
      };
      
      @Entry
      @Component
      struct PageName {
        private context = getContext(this) as common.UIAbilityContext;
        build() {
          // ...
          Button('connectServiceExtensionAbility')
            .onClick(()=>{
            let want: Want = {
              'deviceId': getRemoteDeviceId(),
              'bundleName': 'com.samples.stagemodelabilityinteraction',
              'abilityName': 'ServiceExtAbility'
            };
            // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
            connectionId = this.context.connectServiceExtensionAbility(want, options);
          })
        }
      }
      ```

      getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。

5. 断开连接。调用disconnectServiceExtensionAbility()断开与后台服务的连接。

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   @Entry
   @Component
   struct PageName {
     private context = getContext(this) as common.UIAbilityContext;
     build() {
       // ...
       Button('disconnectServiceExtensionAbility')
         .onClick(()=>{
         this.context.disconnectServiceExtensionAbility(connectionId).then(() => {
           Logger.info('disconnectServiceExtensionAbility success');
           // 成功断连后台服务
           promptAction.showToast({
             message: $r('app.string.SuccessfullyDisconnectBackendService')
           })
         }).catch((error: BusinessError) => {
           Logger.error('disconnectServiceExtensionAbility failed');
         })
       })
     }
   }
   ```


## 通过跨设备Call调用实现多端协同

跨设备Call调用的基本原理与设备内Call调用相同，请参见[通过Call调用实现UIAbility交互（仅对系统应用开放）](uiability-intra-device-interaction.md#通过call调用实现uiability交互仅对系统应用开放)。

下面介绍跨设备Call调用实现多端协同的方法。


### 接口说明

  **表4** Call API接口功能介绍

| 接口名 | 描述 |
| -------- | -------- |
| startAbilityByCall(want:&nbsp;Want):&nbsp;Promise&lt;Caller&gt;; | 启动指定UIAbility至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。 |
| on(method:&nbsp;string,&nbsp;callback:&nbsp;CalleeCallBack):&nbsp;void | 通用组件Callee注册method对应的callback方法。 |
| off(method:&nbsp;string):&nbsp;void | 通用组件Callee解注册method的callback方法。 |
| call(method:&nbsp;string,&nbsp;data:&nbsp;rpc.Parcelable):&nbsp;Promise&lt;void&gt; | 向通用组件Callee发送约定序列化数据。 |
| callWithResult(method:&nbsp;string,&nbsp;data:&nbsp;rpc.Parcelable):&nbsp;Promise&lt;rpc.MessageSequence&gt; | 向通用组件Callee发送约定序列化数据,&nbsp;并将Callee返回的约定序列化数据带回。 |
| release():&nbsp;void | 释放通用组件的Caller通信接口。 |
| on(type:&nbsp;"release",&nbsp;callback:&nbsp;OnReleaseCallback):&nbsp;void | 注册通用组件通信断开监听通知。 |


### 开发步骤

1. 需要申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/AccessToken/request-user-authorization.md)。

3. 创建被调用端UIAbility。
     被调用端UIAbility需要实现指定方法的数据接收回调函数、数据的序列化及反序列化方法。在需要接收数据期间，通过on接口注册监听，无需接收数据时通过off接口解除监听。

     1. 配置UIAbility的启动模式。
         配置module.json5，将CalleeAbility配置为单实例"singleton"。

         | Json字段 | 字段说明 |
         | -------- | -------- |
         | “launchType” | Ability的启动模式，设置为"singleton"类型。 |

         UIAbility配置标签示例如下：

         
         ```json
         "abilities":[{
             "name": ".CalleeAbility",
             "srcEntry": "./ets/CalleeAbility/CalleeAbility.ts",
             "launchType": "singleton",
             "description": "$string:CalleeAbility_desc",
             "icon": "$media:icon",
             "label": "$string:CalleeAbility_label",
             "exported": true
         }]
         ```
     2. 导入UIAbility模块。
        
         ```ts
         import UIAbility from '@ohos.app.ability.UIAbility';
         ```
     3. 定义约定的序列化数据。
         调用端及被调用端发送接收的数据格式需协商一致，如下示例约定数据由number和string组成。

         
         ```ts
         import rpc from '@ohos.rpc'
         class MyParcelable {
           num: number = 0;
           str: string = '';
         
           constructor(num: number, string: string) {
             this.num = num;
             this.str = string;
           }
         
           mySequenceable(num, string): void {
             this.num = num;
             this.str = string;
           }
         
           marshalling(messageSequence: rpc.MessageSequence): boolean {
             messageSequence.writeInt(this.num);
             messageSequence.writeString(this.str);
             return true;
           };
         
           unmarshalling(messageSequence: rpc.MessageSequence): boolean {
             this.num = messageSequence.readInt();
             this.str = messageSequence.readString();
             return true;
           };
         };
         ```
     4. 实现Callee.on监听及Callee.off解除监听。
           如下示例在Ability的onCreate注册MSG_SEND_METHOD监听，在onDestroy取消监听，收到序列化数据后作相应处理并返回。应用开发者根据实际业务需要做相应处理。
           
         ```ts
         import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
         import UIAbility from '@ohos.app.ability.UIAbility';
         import type Want from '@ohos.app.ability.Want';
         import hilog from '@ohos.hilog';
         import Logger from '../utils/Logger';
         import type rpc from '@ohos.rpc';
         import type window from '@ohos.window';
         import type { Caller } from '@ohos.app.ability.UIAbility';
         
         const TAG: string = '[CalleeAbility]';
         const MSG_SEND_METHOD: string = 'CallSendMsg';
         const DOMAIN_NUMBER: number = 0xFF00;
         
         function sendMsgCallback(data: rpc.MessageSequence): rpc.Parcelable {
           hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'CalleeSortFunc called');
         
           // 获取Caller发送的序列化数据
           let receivedData: MyParcelable = new MyParcelable(0, '');
           data.readParcelable(receivedData);
           hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', `receiveData[${receivedData.num}, ${receivedData.str}]`);
           let num: number = receivedData.num;
         
           // 作相应处理
           // 返回序列化数据result给Caller
           return new MyParcelable(num + 1, `send ${receivedData.str} succeed`) as rpc.Parcelable;
         }
         
         export default class CalleeAbility extends UIAbility {
           caller: Caller | undefined;
         
           onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
             try {
               this.callee.on(MSG_SEND_METHOD, sendMsgCallback);
        } catch (error) {
               hilog.error(DOMAIN_NUMBER, TAG, '%{public}s', `Failed to register. Error is ${error}`);
             };
           }
         
           onDestroy(): void {
             try {
               this.callee.off(MSG_SEND_METHOD);
               hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Callee OnDestroy');
               this.releaseCall();
             } catch (error) {
               hilog.error(DOMAIN_NUMBER, TAG, '%{public}s', `Failed to register. Error is ${error}`);
             };
           }
         }
         ```
     
4. 获取Caller接口，访问被调用端UIAbility。
   1. 导入UIAbility模块。
      
       ```ts
       import UIAbility from '@ohos.app.ability.UIAbility';
       ```
   2. 获取Caller通信接口。
       Ability的context属性实现了startAbilityByCall方法，用于获取指定通用组件的Caller通信接口。如下示例通过this.context获取Ability实例的context属性，使用startAbilityByCall拉起Callee被调用端并获取Caller通信接口，注册Caller的onRelease和onRemoteStateChange监听。应用开发者根据实际业务需要做相应处理。

       
       ```ts
       import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
       import { BusinessError } from '@ohos.base';
       import common from '@ohos.app.ability.common';
       import deviceManager from '@ohos.distributedDeviceManager';
       import hilog from '@ohos.hilog';
       import Logger from '../../utils/Logger';
       import promptAction from '@ohos.promptAction';
       import rpc from '@ohos.rpc';
       import Want from '@ohos.app.ability.Want';
       import { BusinessError } from '@ohos.base';
       import { Caller } from '@ohos.app.ability.UIAbility';
       
       const TAG: string = '[Page_CollaborateAbility]';
       const DOMAIN_NUMBER: number = 0xFF00;
       
       let caller: Caller | undefined;
       let context = this.context;
       
       context.startAbilityByCall({
         deviceId: getRemoteDeviceId(),
         bundleName: 'com.samples.stagemodelabilityinteraction',
         abilityName: 'CalleeAbility'
       }).then((data) => {
         if (data !== null) {
           caller = data;
           Logger.info('get remote caller success');
           // 注册caller的release监听
           caller.onRelease((msg) => {
             Logger.info(`remote caller onRelease is called ${msg}`);
           })
           Logger.info('remote caller register OnRelease succeed');
           promptAction.showToast({
             message: $r('app.string.CallerSuccess')
           });
           // 注册caller的协同场景下跨设备组件状态变化监听通知
           try {
             caller.onRemoteStateChange((str) => {
        Logger.info('Remote state changed ' + str);
             });
        } catch (error) {
             Logger.info(`Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
           };
         }
       }).catch((error: BusinessError) => {
         Logger.error(`get remote caller failed with ${error}`);
       });
       ```
       
       getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。
   
5. 向被调用端UIAbility发送约定序列化数据。
   1. 向被调用端发送Parcelable数据有两种方式，一种是不带返回值，一种是获取被调用端返回的数据，method以及序列化数据需要与被调用端协商一致。如下示例调用Call接口，向Callee被调用端发送数据。
      
       ```ts
       import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
       import { BusinessError } from '@ohos.base';
       import Logger from '../utils/Logger';
       
       const MSG_SEND_METHOD: string = 'CallSendMsg';
       
       export default class EntryAbility extends UIAbility {
        // ...
         caller: Caller | undefined;
         async onButtonCall(): Promise<void> {
           try {
             let msg: MyParcelable = new MyParcelable(1, 'origin_Msg');
             if (this.caller) {
               await this.caller.call(MSG_SEND_METHOD, msg);
             }
           } catch (error) {
             Logger.info(`caller call failed with ${error}`);
           };
         }
        // ...
       }
       ```
   2. 如下示例调用CallWithResult接口，向Callee被调用端发送待处理的数据originMsg，并将’CallSendMsg’方法处理完毕的数据赋值给backMsg。
      
        ```ts
        import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
        import rpc from '@ohos.rpc';
        import Logger from '../utils/Logger';
        import type { Caller } from '@ohos.app.ability.UIAbility';
        
        const MSG_SEND_METHOD: string = 'CallSendMsg';
        let originMsg: string = '';
        let backMsg: string = '';
        
        export default class EntryAbility extends UIAbility {
          // ...
          caller: Caller | undefined;
          async onButtonCallWithResult(originMsg: string, backMsg: string): Promise<void> {
            try {
              let msg: MyParcelable = new MyParcelable(1, originMsg);
              if (this.caller) {
                const data = await this.caller.callWithResult(MSG_SEND_METHOD, msg);
                Logger.info('caller callWithResult succeed');
                let result: MyParcelable = new MyParcelable(0, '');
                data.readParcelable(result);
                backMsg = result.str;
                Logger.info(`caller result is [${result.num}, ${result.str}]`);
              }
         } catch (error) {
              Logger.info(`caller callWithResult failed with ${error}`);
            };
          }
            // ...
        }
        ```
   
6. 释放Caller通信接口。
   Caller不再使用后，应用开发者可以通过release接口释放Caller。

   ```ts
   import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
   import Logger from '../utils/Logger';
   import type { Caller } from '@ohos.app.ability.UIAbility';
   
   export default class EntryAbility extends UIAbility {
     caller: Caller | undefined;
     releaseCall(): void {
       try {
         if (this.caller) {
           this.caller.release();
           this.caller = undefined;
         }
         Logger.info('caller release succeed');
       } catch (error) {
         Logger.info(`caller release failed with ${error}`);
       };
     }
   }
   ```

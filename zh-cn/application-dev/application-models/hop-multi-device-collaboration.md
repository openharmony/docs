# 多端协同（仅对系统应用开放）


## 功能描述

多端协同主要包括如下场景：

- [通过跨设备启动UIAbility和ServiceExtensionAbility组件实现多端协同（无返回数据）](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)

- [通过跨设备启动UIAbility组件实现多端协同（获取返回数据）](#通过跨设备启动uiability组件实现多端协同获取返回数据)

- [通过跨设备连接ServiceExtensionAbility组件实现多端协同](#通过跨设备连接serviceextensionability组件实现多端协同)

- [通过跨设备Call调用实现多端协同](#通过跨设备call调用实现多端协同)


## 多端协同流程

多端协同流程如下图所示。

  **图1** 多端协同流程图  
![hop-multi-device-collaboration](figures/hop-multi-device-collaboration.png)


## 约束限制

- 由于“多端协同任务管理”能力尚未具备，开发者当前只能通过开发系统应用获取设备列表，不支持三方应用接入。

- 多端协同需遵循[分布式跨设备组件启动规则](component-startup-rules.md#分布式跨设备组件启动管控)。

- 为了获得最佳体验，使用want传输的数据建议在100KB以下。


## 通过跨设备启动UIAbility和ServiceExtensionAbility组件实现多端协同（无返回数据）

在设备A上通过发起端应用提供的启动按钮，启动设备B上指定的UIAbility。


### 接口说明

  **表1** 跨设备启动API接口功能介绍

| **接口名** | **描述** |
| -------- | -------- |
| startAbility(want:&nbsp;Want,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | 启动UIAbility和ServiceExtensionAbility（callback形式）。 |


### 开发步骤

1. 申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参阅[访问控制授权申请指导](../security/accesstoken-guidelines.md#stage%E6%A8%A1%E5%9E%8B)。

2. 申请数据同步权限，弹框示例代码。
   
   ```ts
   requestPermission() {   
       let context = this.context
       let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']   
       context.requestPermissionsFromUser(permissions).then((data) => {   
           console.info("Succeed to request permission from user with data: "+ JSON.stringify(data))
       }).catch((error) => {       
           console.info("Failed to request permission from user with error: "+ JSON.stringify(error))   
       }) 
   }
   ```

3. 获取目标设备的设备ID。
   
   ```ts
   import deviceManager from '@ohos.distributedHardware.deviceManager';
   
   let dmClass;
   function initDmClass() {
       // 其中createDeviceManager接口为系统API
       deviceManager.createDeviceManager('ohos.samples.demo', (err, dm) => {
           if (err) {
               // ...
               return
           }
           dmClass = dm
       })
   }
   function getRemoteDeviceId() {
       if (typeof dmClass === 'object' && dmClass !== null) {
           let list = dmClass.getTrustedDeviceListSync()
           if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
               console.info('EntryAbility onButtonClick getRemoteDeviceId err: list is null')
               return;
           }
           return list[0].deviceId
       } else {
           console.info('EntryAbility onButtonClick getRemoteDeviceId err: dmClass is null')
       }
   }
   ```

4. 设置目标组件参数，调用startAbility()接口，启动UIAbility或ServiceExtensionAbility。
   
   ```ts
   let want = {
       deviceId: getRemoteDeviceId(), 
       bundleName: 'com.example.myapplication',
       abilityName: 'FuncAbility',
       moduleName: 'module1', // moduleName非必选
   }
   // context为发起端UIAbility的AbilityContext
   this.context.startAbility(want).then(() => {
       // ...
   }).catch((err) => {
       // ...
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

1. 申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参阅[访问控制授权申请指导](../security/accesstoken-guidelines.md#stage%E6%A8%A1%E5%9E%8B)。

2. 申请数据同步权限，弹框示例代码。
   
   ```ts
   requestPermission() {   
       let context = this.context
       let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']   
       context.requestPermissionsFromUser(permissions).then((data) => {   
           console.info("Succeed to request permission from user with data: "+ JSON.stringify(data))
       }).catch((error) => {       
           console.info("Failed to request permission from user with error: "+ JSON.stringify(error))   
       }) 
   }
   ```

3. 在发起端设置目标组件参数，调用startAbilityForResult()接口启动目标端UIAbility，异步回调中的data用于接收目标端UIAbility停止自身后返回给调用方UIAbility的信息。getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。
   
   ```ts
   let want = {
       deviceId: getRemoteDeviceId(), 
       bundleName: 'com.example.myapplication',
       abilityName: 'FuncAbility',
       moduleName: 'module1', // moduleName非必选
   }
   // context为发起端UIAbility的AbilityContext
   this.context.startAbilityForResult(want).then((data) => {
       // ...
   }).catch((err) => {
       // ...
   })
   ```

4. 在目标端UIAbility任务完成后，调用terminateSelfWithResult()方法，将数据返回给发起端的UIAbility。
   
   ```ts
   const RESULT_CODE: number = 1001;
   let abilityResult = {
       resultCode: RESULT_CODE,
       want: {
           bundleName: 'com.example.myapplication',
           abilityName: 'FuncAbility',
           moduleName: 'module1',
       },
   }
   // context为目标端UIAbility的AbilityContext
   this.context.terminateSelfWithResult(abilityResult, (err) => {
       // ...
   });
   ```

5. 发起端UIAbility接收到目标端UIAbility返回的信息，对其进行处理。
   
   ```ts
   const RESULT_CODE: number = 1001;
   
   // ...
   
   // context为调用方UIAbility的AbilityContext
   this.context.startAbilityForResult(want).then((data) => {
       if (data?.resultCode === RESULT_CODE) {
           // 解析目标端UIAbility返回的信息
           let info = data.want?.parameters?.info
           // ...
       }
   }).catch((err) => {
       // ...
   })
   ```


## 通过跨设备连接ServiceExtensionAbility组件实现多端协同

系统应用可以通过[connectServiceExtensionAbility()](../reference/apis/js-apis-ability-context.md#abilitycontextconnectserviceextensionability)跨设备连接一个服务，实现跨设备远程调用。比如：分布式游戏场景，平板作为遥控器，智慧屏作为显示器。


### 接口说明

  **表3** 跨设备连接API接口功能介绍

| 接口名 | 描述 |
| -------- | -------- |
| connectServiceExtensionAbility(want:&nbsp;Want,&nbsp;options:&nbsp;ConnectOptions):&nbsp;number; | 连接ServiceExtensionAbility。 |
| disconnectServiceExtensionAbility(connection:&nbsp;number,&nbsp;callback:AsyncCallback&lt;void&gt;):&nbsp;void; | 断开连接（callback形式）。 |
| disconnectServiceExtensionAbility(connection:&nbsp;number):&nbsp;Promise&lt;void&gt;; | 断开连接（promise形式）。 |


### 开发步骤

1. 在module.json5配置数据同步权限，示例代码如下。
   
   ```json
   {
     "module": {
       "requestPermissions":[  
         {  
           "name" : "ohos.permission.DISTRIBUTED_DATASYNC",
         }
       ]
     }
   }
   ```

2. 申请数据同步权限，弹框示例代码。
   
   ```ts
   requestPermission() {   
       let context = this.context
       let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']   
       context.requestPermissionsFromUser(permissions).then((data) => {   
           console.info("Succeed to request permission from user with data: "+ JSON.stringify(data))
       }).catch((error) => {       
           console.info("Failed to request permission from user with error: "+ JSON.stringify(error))   
       }) 
   }
   ```

3. 如果已有后台服务，请直接进入下一步；如果没有，则[实现一个后台服务](serviceextensionability.md#实现一个后台服务仅对系统应用开放)。

4. 连接一个后台服务。
   - 实现IAbilityConnection接口。IAbilityConnection提供了以下方法供开发者实现：onConnect()是用来处理连接Service成功的回调，onDisconnect()是用来处理Service异常终止的回调，onFailed()是用来处理连接Service失败的回调。
   - 设置目标组件参数，包括目标设备ID、包名、ability名。
   - 调用connectServiceExtensionAbility发起连接。
   - 连接成功，收到目标设备返回的服务句柄。
   - 进行跨设备调用，获得目标端服务返回的结果。
     
      ```ts
      import rpc from '@ohos.rpc';
      
      const REQUEST_CODE = 99;
      let want = {
          "deviceId": getRemoteDeviceId(), 
          "bundleName": "com.example.myapplication",
          "abilityName": "ServiceExtAbility"
      };
      let options = {
          onConnect(elementName, remote) {
              console.info('onConnect callback');
              if (remote === null) {
                  console.info(`onConnect remote is null`);
                  return;
              }
              let option = new rpc.MessageOption();
              let data = new rpc.MessageParcel();
              let reply = new rpc.MessageParcel();
              data.writeInt(1);
              data.writeInt(99);  // 开发者可发送data到目标端应用进行相应操作
      
              // @param code 表示客户端发送的服务请求代码。
              // @param data 表示客户端发送的{@link MessageParcel}对象。
              // @param reply 表示远程服务发送的响应消息对象。
              // @param options 指示操作是同步的还是异步的。
              // 
              // @return 如果操作成功返回{@code true}； 否则返回 {@code false}。
              remote.sendRequest(REQUEST_CODE, data, reply, option).then((ret) => {
                  let msg = reply.readInt();   // 在成功连接的情况下，会收到来自目标端返回的信息（100）
                  console.info(`sendRequest ret:${ret} msg:${msg}`);
              }).catch((error) => {
                  console.info('sendRequest failed');
              });
          },
          onDisconnect(elementName) {
              console.info('onDisconnect callback')
          },
          onFailed(code) {
              console.info('onFailed callback')
          }
      }
      // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
      let connectionId = this.context.connectServiceExtensionAbility(want, options);
      ```

      getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。

5. 断开连接。调用disconnectServiceExtensionAbility()断开与后台服务的连接。
   
   ```ts
   let connectionId = 1 // 在通过connectServiceExtensionAbility绑定服务时返回的Id
   this.context.disconnectServiceExtensionAbility(connectionId).then((data) => {
       console.info('disconnectServiceExtensionAbility success');
   }).catch((error) => {
       console.error('disconnectServiceExtensionAbility failed');
   })
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
| call(method:&nbsp;string,&nbsp;data:&nbsp;rpc.Sequenceable):&nbsp;Promise&lt;void&gt; | 向通用组件Callee发送约定序列化数据。 |
| callWithResult(method:&nbsp;string,&nbsp;data:&nbsp;rpc.Sequenceable):&nbsp;Promise&lt;rpc.MessageParcel&gt; | 向通用组件Callee发送约定序列化数据,&nbsp;并将Callee返回的约定序列化数据带回。 |
| release():&nbsp;void | 释放通用组件的Caller通信接口。 |
| on(type:&nbsp;"release",&nbsp;callback:&nbsp;OnReleaseCallback):&nbsp;void | 注册通用组件通信断开监听通知。 |


### 开发步骤

1. 在module.json5配置数据同步权限，示例代码如下。
   
   ```json
   {
     "module": {
       "requestPermissions":[  
         {  
           "name" : "ohos.permission.DISTRIBUTED_DATASYNC",
         }
       ]
     }
   }
   ```

2. 申请数据同步权限，弹框示例代码。
   
   ```ts
   requestPermission() {   
       let context = this.context
       let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']   
       context.requestPermissionsFromUser(permissions).then((data) => {   
           console.info("Succeed to request permission from user with data: "+ JSON.stringify(data))
       }).catch((error) => {       
           console.info("Failed to request permission from user with error: "+ JSON.stringify(error))   
       }) 
   }
   ```

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
           "srcEntrance": "./ets/CalleeAbility/CalleeAbility.ts",
           "launchType": "singleton",
           "description": "$string:CalleeAbility_desc",
           "icon": "$media:icon",
           "label": "$string:CalleeAbility_label",
           "visible": true
       }]
       ```
   2. 导入UIAbility模块。
      
       ```ts
       import Ability from '@ohos.app.ability.UIAbility'
       ```
   3. 定义约定的序列化数据。
       调用端及被调用端发送接收的数据格式需协商一致，如下示例约定数据由number和string组成。

       
       ```ts
       export default class MySequenceable {
           num: number = 0
           str: string = ""
       
           constructor(num, string) {
               this.num = num
               this.str = string
           }
       
           marshalling(messageParcel) {
               messageParcel.writeInt(this.num)
               messageParcel.writeString(this.str)
               return true
           }
       
           unmarshalling(messageParcel) {
               this.num = messageParcel.readInt()
               this.str = messageParcel.readString()
               return true
           }
       }
       ```
   4. 实现Callee.on监听及Callee.off解除监听。
         如下示例在Ability的onCreate注册MSG_SEND_METHOD监听，在onDestroy取消监听，收到序列化数据后作相应处理并返回。应用开发者根据实际业务需要做相应处理。
         
       ```ts
       const TAG: string = '[CalleeAbility]'
       const MSG_SEND_METHOD: string = 'CallSendMsg'
       
       function sendMsgCallback(data) {
           console.info('CalleeSortFunc called')
       
           // 获取Caller发送的序列化数据
           let receivedData = new MySequenceable(0, '')
           data.readSequenceable(receivedData)
           console.info(`receiveData[${receivedData.num}, ${receivedData.str}]`)
       
           // 作相应处理
           // 返回序列化数据result给Caller
           return new MySequenceable(receivedData.num + 1, `send ${receivedData.str} succeed`)
       }
       
       export default class CalleeAbility extends Ability {
           onCreate(want, launchParam) {
               try {
                   this.callee.on(MSG_SEND_METHOD, sendMsgCallback)
               } catch (error) {
                   console.info(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`)
               }
           }
       
           onDestroy() {
               try {
                   this.callee.off(MSG_SEND_METHOD)
               } catch (error) {
                   console.error(TAG, `${MSG_SEND_METHOD} unregister failed with error ${JSON.stringify(error)}`)
               }
           }
       }
       ```

4. 获取Caller接口，访问被调用端UIAbility。
   1. 导入UIAbility模块。
      
       ```ts
       import Ability from '@ohos.app.ability.UIAbility'
       ```
   2. 获取Caller通信接口。
       Ability的context属性实现了startAbilityByCall方法，用于获取指定通用组件的Caller通信接口。如下示例通过this.context获取Ability实例的context属性，使用startAbilityByCall拉起Callee被调用端并获取Caller通信接口，注册Caller的onRelease监听。应用开发者根据实际业务需要做相应处理。

       
       ```ts
       async onButtonGetRemoteCaller() {
           var caller = undefined
           var context = this.context
       
           context.startAbilityByCall({
               deviceId: getRemoteDeviceId(),
               bundleName: 'com.samples.CallApplication',
               abilityName: 'CalleeAbility'
           }).then((data) => {
               if (data != null) {
                   caller = data
                   console.info('get remote caller success')
                   // 注册caller的release监听
                   caller.onRelease((msg) => {
                       console.info(`remote caller onRelease is called ${msg}`)
                   })
                   console.info('remote caller register OnRelease succeed')
               }
           }).catch((error) => {
               console.error(`get remote caller failed with ${error}`)
           })
       }
       ```

       getRemoteDeviceId方法参照[通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据](#通过跨设备启动uiability和serviceextensionability组件实现多端协同无返回数据)。

5. 向被调用端UIAbility发送约定序列化数据。
   1. 向被调用端发送Sequenceable数据有两种方式，一种是不带返回值，一种是获取被调用端返回的数据，method以及序列化数据需要与被调用端协商一致。如下示例调用Call接口，向Callee被调用端发送数据。
      
       ```ts
       const MSG_SEND_METHOD: string = 'CallSendMsg'
       async onButtonCall() {
           try {
               let msg = new MySequenceable(1, 'origin_Msg')
               await this.caller.call(MSG_SEND_METHOD, msg)
           } catch (error) {
               console.info(`caller call failed with ${error}`)
           }
       }
       ```
   2. 如下示例调用CallWithResult接口，向Callee被调用端发送待处理的数据originMsg，并将’CallSendMsg’方法处理完毕的数据赋值给backMsg。
      
       ```ts
       const MSG_SEND_METHOD: string = 'CallSendMsg'
       originMsg: string = ''
       backMsg: string = ''
       async onButtonCallWithResult(originMsg, backMsg) {
           try {
               let msg = new MySequenceable(1, originMsg)
               const data = await this.caller.callWithResult(MSG_SEND_METHOD, msg)
               console.info('caller callWithResult succeed')
       
               let result = new MySequenceable(0, '')
               data.readSequenceable(result)
               backMsg(result.str)
               console.info(`caller result is [${result.num}, ${result.str}]`)
           } catch (error) {
               console.info(`caller callWithResult failed with ${error}`)
           }
       }
       ```

6. 释放Caller通信接口。
     Caller不再使用后，应用开发者可以通过release接口释放Caller。
     
   ```ts
   releaseCall() {
       try {
           this.caller.release()
           this.caller = undefined
           console.info('caller release succeed')
       } catch (error) {
           console.info(`caller release failed with ${error}`)
       }
   }
   ```

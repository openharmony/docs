# ServiceExtensionContext

ServiceExtensionContext模块是ServiceExtension的上下文环境，继承自ExtensionContext。

ServiceExtensionContext模块提供ServiceExtension具有的能力和接口，包括启动、停止、绑定、解绑Ability。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

ServiceExtensionContext模块是ServiceExtension的上下文环境，继承自ExtensionContext。

## 属性

表示访问应用程序资源的能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| resourceManager | resmgr.ResourceManager; | 是 | 否 | ResourceManager对象。 |

## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

启动Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
  class MainAbility extends ExtensionContext {
      onWindowStageCreate(windowStage) {
          let want = {
              "bundleName": "com.example.myapp",
              "abilityName": "MyAbility"};
          this.context.startAbility(want, (err) => {
          console.log('startAbility result:' + JSON.stringify(err));
          });
      }
  }

  ```

## startAbility

startAbility(want: Want): Promise&lt;void&gt;;

启动Ability。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例：**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
        onWindowStageCreate(windowStage) {
            let want = {
            "bundleName": "com.example.myapp",
            "abilityName": "MyAbility"
            };
        this.context.startAbility(want).then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
        }
    }
  ```

## startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**示例：**
    
  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options, (error) => {
      console.log("error.code = " + error.code)
  })
  ```

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

根据account启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 需要启动的accountId。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startAbilityWithAccount(want, accountId, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

根据account启动Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 需要启动的accountId。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void\> | 是 | 启动Ability的回调函数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

根据account启动Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 需要启动的accountId。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options)
    .then((data) => {
        console.log('---------- startAbilityWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    })
  ```


## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止Ability自身。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
        class MainAbility extends ExtensionContext {
            onWindowStageCreate(windowStage) {
            this.context.terminateSelf((err) => {
              console.log('terminateSelf result:' + JSON.stringify(err));
            });
            }
        }
  

  ```


## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止自身。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 

**示例：**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      this.context.terminateSelf().then((data) => {
        console.log('success:' + JSON.stringify(data));
      }).catch((error) => {
        console.log('failed:' + JSON.stringify(error));
      });
    }
}

  ```

## ServiceExtensionContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

将一个Ability与服务类型的Ability绑定。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 
  | options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | 是 | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | number | 返回一个number，后续根据这个number去断开连接。 | 

**示例：**

  ```js
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "MyAbility"
  };
  let options = {
      onConnect: function(elementName, proxy) {},
      onDisConnect: function(elementName) {},
      onFailed: function(code) {}
  }
  let connection = this.context.connectAbility(want,options);
  ```

## ServiceExtensionContext.connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

使用AbilityInfo.AbilityType.SERVICE模板和account将当前能力连接到一个能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 启动Ability的want信息。 |
| accountId | number | 是 | 需要启动的accountId。 |
| options | ConnectOptions | 否 | 远端对象实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Ability连接的结果code。 |

**示例：**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  const result = this.context.connectAbilityWithAccount(want, accountId, options);
  console.log('----------- connectAbilityResult: ------------', result);
  ```

## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

将一个Ability与绑定的服务类型的Ability解绑。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | connection | number | 是 | 在connectAbility中返回的number。 | 
  | callback | AsyncCallback&lt;void&gt; | 否 | 回调函数，返回接口调用是否成功的结果。 | 

**示例：**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      let connection=1
      this.context.disconnectAbility(connection, (err) => { 
        // connection为connectAbility中的返回值
        console.log('terminateSelf result:' + JSON.stringify(err));
      });
    }
  }

  ```

## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number): Promise&lt;void&gt;;

将一个Ability与绑定的服务类型的Ability解绑。通过Promise返回结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | connection | number | 是 | 在connectAbility中返回的number。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 | 
 
**示例：**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
  class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      let connection=1
      this.context.disconnectAbility(connection).then((data) => { // connection为connectAbility中的返回值
      console.log('success:' + JSON.stringify(data));
      }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
      });
    }
  }

  ```
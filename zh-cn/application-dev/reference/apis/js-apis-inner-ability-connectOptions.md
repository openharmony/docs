# ConnectOptions

在连接指定的后台服务时作为入参，用于接收连接过程中的状态变化，如作为[connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)的入参，连接指定的ServiceExtensionAbility。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

|    名称      | 类型       | 必填   | 说明                        |
| ------------ | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | function | 是    | 建立连接时的回调函数。      |
| onDisconnect<sup>7+</sup> | function | 是    | 断开连接时的回调函数。           |
| onFailed<sup>7+</sup>     | function | 是    | 连接失败时的回调函数。 |

**示例：**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import common from '@ohos.app.ability.common';
  import Want from '@ohos.app.ability.Want';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import bundleManager from '@ohos.bundle.bundleManager';
  import rpc from '@ohos.rpc';

  let connectWant: Want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };

  let connectOptions: common.ConnectOptions = {
    onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {
      console.log(`onConnect elementName: ${elementName}`);
    },
    onDisconnect(elementName: bundleManager.ElementName) {
      console.log(`onDisconnect elementName: ${elementName}`);
    },
    onFailed(code: number) {
      console.error(`onFailed code: ${code}`);
    }
  };


  class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
      let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);
    }
  }
  ```
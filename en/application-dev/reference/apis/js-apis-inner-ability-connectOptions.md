# ConnectOptions

**ConnectOptions** can be used as an input parameter to receive status changes during the connection to a background service. For example, it is used as an input parameter of [connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) to connect to a ServiceExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

|    Name     | Type      | Mandatory  | Description                       |
| ------------ | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | function | Yes   | Callback invoked when a connection is set up.     |
| onDisconnect<sup>7+</sup> | function | Yes   | Callback invoked when a connection is interrupted.          |
| onFailed<sup>7+</sup>     | function | Yes   | Callback invoked when a connection fails.|

**Example**

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

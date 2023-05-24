# ConnectOptions

**ConnectOptions** can be used as an input parameter to receive status changes during the connection to a background service. For example, it is used as an input parameter of [connectServiceExtensionAbility](js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextconnectserviceextensionability) to connect to a ServiceExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type      | Mandatory  | Description                       |
| ------------ | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | function | Yes   | Callback invoked when a connection is set up.     |
| onDisconnect<sup>7+</sup> | function | Yes   | Callback invoked when a connection is interrupted.          |
| onFailed<sup>7+</sup>     | function | Yes   | Callback invoked when a connection fails.|

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };

  let connectOptions: common.ConnectOptions = {
    onConnect(elementName, remote) { 
        console.log('onConnect elementName: ' + elementName);
    },
    onDisconnect(elementName) { 
        console.log('onDisconnect elementName: ' + elementName);
    },
    onFailed(code) { 
        console.error('onFailed code: ' + code);
    }
  };

  let connection = this.context.connectAbility(want, connectOptions);
  ```

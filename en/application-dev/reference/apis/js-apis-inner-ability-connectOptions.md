# ConnectOptions

The **ConnectOptions** module defines the options for connection.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type      | Mandatory  | Description                       |
| ------------ | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | function | Yes   | Callback invoked when the connection is successful.              |
| onDisconnect<sup>7+</sup> | function | Yes   | Callback invoked when the connection fails.              |
| onFailed<sup>7+</sup>     | function | Yes   | Callback invoked when **connectAbility** fails to be called.|

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | ID of the Service ability connected.|

**Example**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connectId = featureAbility.connectAbility(
    {
        deviceId: "",
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

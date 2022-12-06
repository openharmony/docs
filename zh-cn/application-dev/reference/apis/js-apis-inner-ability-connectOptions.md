# ConnectOptions

ConnectOptions类型说明

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 参数名           | 可读|可写 | 类型       | 必填   | 说明                        |
| ------------ | -- | -- | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | 是|否   | function | 是    | 连接成功时的回调函数。               |
| onDisconnect<sup>7+</sup> | 是|否   | function | 是    | 连接失败时的回调函数。               |
| onFailed<sup>7+</sup>     | 是|否   | function | 是    | ConnectAbility调用失败时的回调函数。 |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 连接的ServiceAbilityID。 |

**示例：**

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
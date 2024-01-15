# Connecting to a ServiceAbility


If a ServiceAbility wants to interact with a PageAbility or a ServiceAbility in another application, you must first create a connection by calling **connectAbility()**. This method is defined in the **featureAbility** class for the PageAbility and in the **particleAbility** class for the ServiceAbility. For details about the connection rules, see [Component Startup Rules](component-startup-rules.md). When calling **connectAbility()**, you should pass in a **Want** object containing information about the target ServiceAbility and an **IAbilityConnection** object. **IAbilityConnection** provides the following APIs that you need to implement.


**Table 1** IAbilityConnection APIs

| API| Description|
| -------- | -------- |
| onConnect() | Callback invoked when the ServiceAbility is connected.|
| onDisconnect() | Callback invoked when the ServiceAbility is disconnected.|
| onFailed() | Callback invoked when the connection to the ServiceAbility fails.|


The following sample code enables the PageAbility to create connection callback instances and connect to the local ServiceAbility:

```ts
import rpc from "@ohos.rpc"
import promptAction from '@ohos.promptAction'
import featureAbility from '@ohos.ability.featureAbility'
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import rpc from '@ohos.rpc';
import hilog from '@ohos.hilog';
```
```ts
const LOG_TAG: string = '[Sample_FAModelAbilityDevelop]';
const LOG_DOMAIN: number = 0xFF00;
let option: common.ConnectOptions = {
  onConnect: (element, proxy) => {
    hilog.info(LOG_DOMAIN, LOG_TAG, 'onConnectLocalService onConnectDone element:' + JSON.stringify(element));
    if (proxy === null) {
      promptAction.showToast({
        message: 'connect service failed'
      });
      return;
    }
    let data = rpc.MessageParcel.create()
    let reply = rpc.MessageParcel.create()
    let option = new rpc.MessageOption()
    data.writeInterfaceToken("connect.test.token")
    proxy.sendRequest(0, data, reply, option)
    promptAction.showToast({
      message: 'connect service success'
    });
  },
  onDisconnect: (element) => {
    hilog.info(LOG_DOMAIN, LOG_TAG, `onConnectLocalService onDisconnectDone element:${element}`);
    promptAction.showToast({
      message: 'disconnect service success'
    });
  },
  onFailed: (code) => {
    hilog.info(LOG_DOMAIN, LOG_TAG, `onConnectLocalService onFailed errCode:${code}`);
    promptAction.showToast({
      message: 'connect service failed'
    });
  }
};

let request: Want = {
  bundleName: 'com.samples.famodelabilitydevelop',
  abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
};
let connId = featureAbility.connectAbility(request, option);
hilog.info(LOG_DOMAIN, LOG_TAG, `connectAbility id:${connId}`);
```


When the ServiceAbility is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the ServiceAbility. The system provides a default implementation of **IRemoteObject**. You can extend **rpc.RemoteObject** to implement your own class of **IRemoteObject**.


The following sample code shows how the ServiceAbility returns itself to the caller:

```ts
import rpc from "@ohos.rpc"

class FirstServiceAbilityStub extends rpc.RemoteObject {
  constructor(des: Object) {
    if (typeof des === 'string') {
      super(des)
    } else {
      return
    }
  }

  onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
    console.info(`onRemoteRequest called`)
    if (code === 1) {
      let string = data.readString()
      console.info(`string=${string}`)
      let result = Array.from(string).sort().join('')
      console.info(`result=${result}`)
      reply.writeString(result)
    } else {
      console.info(`unknown request code`)
    }
    return true
  }
}
```

# 连接ServiceAbility


如果ServiceAbility需要与PageAbility或其他应用的ServiceAbility进行交互，则须创建用于连接的Connection。ServiceAbility支持其他Ability通过connectAbility()方法与其进行连接。PageAbility的connectAbility方法定义在featureAbility中，ServiceAbility的connectAbility方法定义在particleAbility中。连接ServiceAbility的规则详见[组件启动规则](component-startup-rules.md)章节。在使用connectAbility()处理回调时，需要传入目标Service的Want与IAbilityConnection的实例。IAbilityConnection提供了以下方法供开发者实现。


  **表1** IAbilityConnection接口说明

| 接口名 | 描述 |
| -------- | -------- |
| onConnect() | 用于处理连接Service成功的回调。 |
| onDisconnect() | 用来处理Service异常死亡的回调。 |
| onFailed() | 用来处理连接Service失败的回调。 |


PageAbility创建连接本地ServiceAbility回调实例的代码以及连接本地ServiceAbility的示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import rpc from '@ohos.rpc';
import Logger from '../../utils/Logger';
```
```ts
let option: common.ConnectOptions = {
  onConnect: (element, proxy) => {
    Logger.info(TAG, `onConnectLocalService onConnectDone element:` + JSON.stringify(element));
    if (proxy === null) {
      promptAction.showToast({
        message: $r('app.string.connect_service_failed_toast')
      });
      return;
    }
    let data = rpc.MessageParcel.create();
    let reply = rpc.MessageParcel.create();
    let option = new rpc.MessageOption();
    data.writeInterfaceToken('connect.test.token');
    proxy.sendRequest(0, data, reply, option);
    promptAction.showToast({
      message: $r('app.string.connect_service_success_toast')
    });
  },
  onDisconnect: (element) => {
    Logger.info(TAG, `onConnectLocalService onDisconnectDone element:${element}`);
    promptAction.showToast({
      message: $r('app.string.disconnect_service_success_toast')
    });
  },
  onFailed: (code) => {
    Logger.info(TAG, `onConnectLocalService onFailed errCode:${code}`);
    promptAction.showToast({
      message: $r('app.string.connect_service_failed_toast')
    });
  }
};

let request: Want = {
  bundleName: 'com.samples.famodelabilitydevelop',
  abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
};
let connId = featureAbility.connectAbility(request, option);
Logger.info(TAG, `onConnectLocalService onFailed errCode:${connId}`);
```


同时，Service侧也需要在onConnect()时返回IRemoteObject，从而定义与Service进行通信的接口。onConnect()需要返回一个IRemoteObject对象。系统提供了IRemoteObject的默认实现，开发者可以通过继承rpc.RemoteObject来创建自定义的实现类。


Service侧把自身的实例返回给调用侧的示例代码如下：

```ts
import type Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import hilog from '@ohos.hilog';

const TAG: string = '[Sample_FAModelAbilityDevelop]';
const domain: number = 0xFF00;

class FirstServiceAbilityStub extends rpc.RemoteObject {
  constructor(des: Object) {
    if (typeof des === 'string') {
      super(des);
    } else {
      return;
    }
  }

  onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
    hilog.info(domain, TAG, 'ServiceAbility onRemoteRequest called');
    if (code === 1) {
      let string = data.readString();
      hilog.info(domain, TAG, `ServiceAbility string=${string}`);
      let result = Array.from(string).sort().join('');
      hilog.info(domain, TAG, `ServiceAbility result=${result}`);
      reply.writeString(result);
    } else {
      hilog.info(domain, TAG, 'ServiceAbility unknown request code');
    }
    return true;
  }
}
...
```

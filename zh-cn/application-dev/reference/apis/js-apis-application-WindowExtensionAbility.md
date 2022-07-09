# 窗口扩展能力
WindowExtensionAbility基于ExtensionAbility，WindowExtensionAbility中展示的内容作为一个控件(AbilityComponent)内容展示在其他应用窗口中，实现在一个窗口中展示多个应用程序内容的功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口为系统接口。
>
>本模块接口仅可在Stage模型下使用。 

## 导入模块

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
```

## 属性

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 名称      | 参数类型 | 可读 | 可写 | 说明                      |
| --------- | -------- | ---- | ---- | ------------------------- |
| context      | [ExtensionContext](js-apis-extension-context.md)   | 是   | 否   | 上下文。      |

## WindowExtensionAbility.onConnect

onConnect(want: Want): rpc.RemoteObject

当窗口扩展组件第一次连接ability时回调。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 当前ability的Want类型信息，包括ability名称、bundle名称等。 |

**返回值：** 
| 类型                                            | 说明                 |
| ----------------------------------------------- | -------------------- |
| [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | 窗口功能的代理对象。 |

**示例：** 

```ts
import rpc from '@ohos.rpc';

class StubTest extends rpc.RemoteObject {
    constructor(des) {
        super(des);
    }
    onRemoteRequest(code, data, reply, option) {
        return true;
    }
    queryLocalInterface(descriptor) {
        return null;
    }
    getInterfaceDescriptor() {
        return "";
    }
    sendRequest(code, data, reply, options) {
        return null;
    }
    getCallingPid() {
        return 1;
    }
    getCallingUid() {
        return 1;
    }
    attachLocalInterface(localInterface, descriptor){}
}

export default class MyWindowExtensionAbility extends WindowExtensionAbility {

  onConnect(want): rpc.RemoteObject {
    console.info('WindowExtAbility onConnect ' + want.abilityName);
    return new StubTest("test");
  }

}
```

## WindowExtensionAbility.onDisconnect

onDisconnect(want: Want): void

当所有连接到窗口扩展组件的ability断开连接时回调。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | 当前Ability的Want类型信息，包括ability名称、bundle名称等。 |


**示例：** 

```ts
export default class MyWindowExtensionAbility extends WindowExtensionAbility {

  onDisconnect(want) {
    console.info('WindowExtAbility onDisconnect ' + want.abilityName);
  }

}
```


## WindowExtensionAbility.onWindowReady

onWindowReady(window: Window): void

当窗口被创建时回调。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| window | [Window](js-apis-window.md) | 是 | 当前窗口实例。 |


**示例：** 

```ts
export default class MyWindowExtensionAbility extends WindowExtensionAbility {

  onWindowReady(window) {
    window.loadContent('WindowExtAbility/pages/index1').then(() => {
      window.getProperties().then((pro) => {
        console.log("WindowExtension " + JSON.stringify(pro));
      })
      window.show();
    })
  }

}
```
# UIServiceHostProxy (系统接口)

UIServiceHostProxy提供代理能力，可以将数据从[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)服务端发送到客户端。


> **说明：**
>
>  - 本模块首批接口从API version 13开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。
>  - 本模块接口为系统接口。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```


## UIServiceHostProxy.sendData

sendData(data: Record\<string, Object>): void

从[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)服务端给客户端发送数据。


**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| data | Record\<string, Object> | 是 | 否 | 待发送到[UIServiceExtension](js-apis-app-ability-uiServiceExtensionAbility-sys.md)客户端的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Not System App. Interface caller is not a system app .                                                       |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { common, UIServiceExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[UiServiceExtensionAbility] ';

export default class MyUiServiceExtensionAbility extends UIServiceExtensionAbility {

  // 数据发送处理
  onData(proxy: common.UIServiceHostProxy, data: Record<string, Object>) {
    console.log(TAG + `onData ${JSON.stringify(data)}`);
    // 定义发送数据内容
    let formData: Record<string, string> = {
      'proxyData': 'proxyData'
    };
    try {
      // 发送数据到UIServiceExtension的服务端
      proxy.sendData(formData);
    } catch (err) {
      console.log(TAG + `sendData failed ${JSON.stringify(err.message)}`);
    }
  }
}
```


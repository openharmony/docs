# @ohos.net.mdns (MDNS管理)

MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import mdns from '@ohos.net.mdns'
```

## mdns.addLocalService<sup>10+</sup>

addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

添加一个mDNS服务，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功添加error为undefined，data为添加到本地的mdns服务信息。      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context as Context, localServiceInfo, (error:BusinessError, data:mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.addLocalService<sup>10+</sup>

addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

添加一个mDNS服务，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | 以Promise形式返回添加的mdns服务信息。 |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService<sup>10+</sup>

removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

移除一个mDNS服务，使用callback方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功移除error为undefined，data为移除本地的mdns服务信息。      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance not found. |
| 2204010 | Send packet failed. |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService<sup>10+</sup>

removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

移除一个mDNS服务. 使用Promise方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | 以Promise形式返回移除的mdns服务信息。 |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance not found. |
| 2204010 | Send packet failed. |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
import mdns from '@ohos.net.mdns'
// 获取context
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.createDiscoveryService<sup>10+</sup>

createDiscoveryService(context: Context, serviceType: string): DiscoveryService

返回一个DiscoveryService对象，该对象用于发现指定服务类型的mDNS服务。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|---------|-----------| ------------------------------------------------------------ |
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceType | string  | 是       | 需要发现的mDNS服务类型。|

**返回值：**

| Type                         | Description                     |
| ----------------------------- |---------------------------------|
| DiscoveryService | 基于指定serviceType和Context的发现服务对象。 |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |

**示例**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let serviceType = "_print._tcp";
let discoveryService : Object = mdns.createDiscoveryService(context as Context, serviceType);
```

## mdns.resolveLocalService<sup>10+</sup>

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

解析一个mDNS服务，使用callback方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功移除error为undefined，data为解析的mdns服务信息。      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.resolveLocalService<sup>10+</sup>

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

解析一个mDNS服务，使用Promise方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-app-ability-uiAbility.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息。      |

**返回值：**

| 类型                              | 说明                                  |
|----------------------------| ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | 以Promise形式返回解析的mDNS服务信息。|

**错误码：**

| 错误码ID      | 错误信息 |
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

> **错误码说明：**
> 以上错误码的详细介绍参见[MDNS错误码](../errorcodes/errorcode-net-mdns.md)。

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
## DiscoveryService<sup>10+</sup>

指定服务类型的发现服务对象。

### startSearchingMDNS<sup>10+</sup>

startSearchingMDNS(): void

开始搜索局域网内的mDNS服务。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();
```

### stopSearchingMDNS<sup>10+</sup>

stopSearchingMDNS(): void

停止搜索局域网内的mDNS服务。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**示例：**

Stage模型示例：

```ts
// 获取context
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.stopSearchingMDNS();
```

### on('discoveryStart')<sup>10+</sup>

on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void

订阅开启监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'discoveryStart'。<br>discoveryStart：开始搜索局域网内的mDNS服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                  | 是        |   mDNS服务的信息和事件错误信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}

// 参考mdns.createDiscoveryService
class DataServiceInfo{
  serviceInfo: mdns.LocalServiceInfo|null = null
  errorCode?: mdns.MdnsError = 0
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStart', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStart')<sup>10+</sup>

off(type: 'discoveryStart', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void

取消开启监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |取消订阅的事件，固定为'discoveryStart'。<br>discoveryStart：开始搜索局域网内的mDNS服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                  | 否        |   mDNS服务的信息和事件错误信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStart', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStart', (data: Data) => {
  console.log(JSON.stringify(data));
});
```

### on('discoveryStop')<sup>10+</sup>

on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void

订阅停止监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'discoveryStop'。<br>discoveryStop：停止搜索局域网内的mDNS服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                 | 是        |   mDNS服务的信息和事件错误信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStop')<sup>10+</sup>

off(type: 'discoveryStop', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void

取消订阅停止监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |取消订阅的事件'discoveryStop'。<br>discoveryStop：停止搜索局域网内的mDNS服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                 | 否        |   mDNS服务的信息和事件错误信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceFound')<sup>10+</sup>

on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void

订阅发现mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'serviceFound'。<br>serviceFound：发现mDNS服务事件。 |
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | 是        |   mDNS服务的信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('serviceFound')<sup>10+</sup>

off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void

取消订阅发现mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |取消订阅的事件，固定为'serviceFound'。<br>serviceFound：发现mDNS服务事件。 |
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | 否        |   mDNS服务的信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceLost')<sup>10+</sup>

on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void

订阅移除mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'serviceLost'。<br>serviceLost：移除mDNS服务事件。 |
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | 是        |   mDNS服务的信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('serviceLost')<sup>10+</sup>

off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void

取消订阅移除mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |取消订阅的事件，固定为'serviceLost'。<br>serviceLost：移除mDNS服务事件。 |
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | 否        |   mDNS服务的信息。      |

**示例：**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// 参考mdns.createDiscoveryService
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## LocalServiceInfo<sup>10+</sup>

mDNS服务信息

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| serviceType   | string                             |  是 |  mDNS服务的类型。格式_\<name>.<_tcp/_udp>，name长度小于63字符并且不能包含字符'.'。  |
| serviceName | string                             |  是 |  mDNS服务的名字。   |
| port            | number           |  否 |  mDNS服务的端口号。           |
| host           |  [NetAddress](js-apis-net-connection.md#netaddress) |  否 |  mDNS服务设备的IP地址。采用设备的IP，添加服务和移除服务时候不生效。               |
| serviceAttribute     | serviceAttribute\<[ServiceAttribute](#serviceattribute)> |  否 |  mDNS服务属性信息。               |

## ServiceAttribute<sup>10+</sup>

mDNS服务属性信息

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| key   | string                             |  是 |  mDNS服务属性键值，键值长度应该小于9个字符。  |
| value | Array\<number>                             |  是 |  mDNS服务属性值。   |

## MdnsError

mDNS错误信息。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称         | 值   | 说明        |
| --------------- | ---- | ----------- |
| INTERNAL_ERROR  | 0    | 内部错误导致操作失败。（暂不支持）  |
| ALREADY_ACTIVE      | 1    | 服务已经存在导致操作失败。（暂不支持） |
| MAX_LIMIT  | 2 | 请求超过最大限制导致操作失败。（暂不支持） |

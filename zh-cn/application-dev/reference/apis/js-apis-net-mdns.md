# @ohos.net.mdns (MDNS管理)

MDNS管理提供管理MDNS的一些基础能力，包括创建本地服务、移除本地服务、解析本地服务、监听本地服务等功能。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import connection from '@ohos.net.mdns'
```
## mdns.addLocalService

function addLocalService(context: Context, serviceInfo: LocalServiceInfo,
                         callback: AsyncCallback<LocalServiceInfo>): void;

添加一个mDNS服务，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功添加error为undefined，data为添加到本地的mdns服务信息      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.addLocalService(context, localServiceInfo, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
});
```

## mdns.addLocalService

function addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise<LocalServiceInfo>;

添加一个mDNS服务，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
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

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.addLocalService(context, localServiceInfo).then(function (data) {
    console.log(JSON.stringify(data))
});
```

## mdns.removeLocalService

function removeLocalService(context: Context, serviceInfo: LocalServiceInfo,
                            callback: AsyncCallback<LocalServiceInfo>): void;

移除一个mDNS服务，使用callback方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功移除error为undefined，data为移除本地的mdns服务信息      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.removeLocalService(context, localServiceInfo, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
});
```

## mdns.removeLocalService

function removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise<LocalServiceInfo>;

移除一个mDNS服务. 使用Promise方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息      |

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
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.removeLocalService(context, localServiceInfo).then(function (data) {
    console.log(JSON.stringify(data))
});
```

## mdns.createDiscoveryService

function createDiscoveryService(context: Context, serviceType: string): DiscoveryService;

返回一个DiscoveryService对象，该对象监听局域网内serviceType类型的LocalServiceInfo服务。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|---------|-----------| ------------------------------------------------------------ |
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceType | string  | Yes       | 需要监听的mDNS服务类型。|

**返回值：**

| Type                         | Description                     |
| ----------------------------- |---------------------------------|
| DiscoveryService | 基于指定serviceType和Context的发现服务。 |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
serviceType = "_print._tcp"
let discoveryService = mdns.createDiscoveryService(context, serviceType);
```

## mdns.resolveLocalService

function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo,
                             callback: AsyncCallback<LocalServiceInfo>): void;

解析一个mDNS服务，使用callback方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|----------------------------------|-----------|-------------------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息      |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | 是        |   回调函数。成功移除error为undefined，data为解析的mdns服务信息      |

**错误码：**

| 错误码ID      | 错误信息 |
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.resolveLocalService(context, localServiceInfo, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
});
```

## mdns.resolveLocalService

function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise<LocalServiceInfo>;

解析一个mDNS服务，使用Promise方式作为异步方法。

**系统能力**: SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| context     | Context                          | 是       | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | 是        |   mDNS服务的信息      |

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

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'

// 获取context
let context = featureAbility.getContext();
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "into type",
    port: 5555,
    host: {
        address: "10.14.**.***",
    },
    serviceAttribute: [{
        key: "111",
        value: [1]
    }]
}

mdns.resolveLocalService(context, localServiceInfo).then(function (data){
    console.log(JSON.stringify(data));
})
```

## DiscoveryService

基于指定serviceType和Context的发现服务。

### startSearchingMDNS

startSearchingMDNS(): void

开启监听指定服务类型的变化。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();
```

### stopSearchingMDNS

stopSearchingMDNS(): void

取消监听指定服务类型的变化。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();
```

### on('discoveryStart')

on(type: 'discoveryStart',
   callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MDNS_ERR}>): void;

订阅开启监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'discoveryStart'。<br>discoveryStart：开始监听本地服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MDNS_ERR](#mdns_err)}>                  | 是        |   mDNS服务的信息      |

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();

discoveryService.on('discoveryStart', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('discoveryStop')

on(type: 'discoveryStop',
   callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MDNS_ERR}>): void;

订阅停止监听mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'discoveryStop'。<br>discoveryStop：停止监听本地服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MDNS_ERR](#mdns_err)}>                 | 是        |   mDNS服务的信息      |

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();

discoveryService.on('discoveryStop', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('serviceFound')

on(type: 'serviceFound', callback: Callback<LocalServiceInfo>): void;

订阅发现mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'serviceFound'。<br>serviceFound：监听发现mDNS服务事件。 |
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MDNS_ERR](#mdns_err)}>                 | 是        |   mDNS服务的信息      |

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();

discoveryService.on('serviceFound', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('serviceLost')

on(type: 'serviceLost', callback: Callback<LocalServiceInfo>): void;

订阅移除mDNS服务的通知。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

**参数：**

| 参数名        | 类型                             | 必填 | 说明                                     |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | 是       |订阅事件，固定为'serviceLost'。<br>serviceLost：监听移除本地服务事件。 |
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | 是        |   mDNS服务的信息      |

**示例：**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();

discoveryService.on('serviceLost', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

## LocalServiceInfo

mDNS服务信息

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| serviceType   | string                             |  是 |  服务的类型。  |
| serviceName | string                             |  是 |  m服务的名字。   |
| port            | number           |  否 |  服务的端口号。           |
| host           |  [NetAddress](js-apis-net-connection.md) |  否 |  mdns服务设备的IP地址。采用设备的IP，添加服务和移除服务时候不生效               |
| serviceAttribute     | serviceAttribute\<[ServiceAttribute](#serviceattribute)> |  是 |  网络类型。               |

## ServiceAttribute

mDNS服务属性信息

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| key   | string                             |  是 |  mDNS服务属性键值。  |
| value | Array<number>                             |  是 |  mDNS服务属性值。   |

## MDNS_ERR

mDNS错误信息。

**系统能力**：SystemCapability.Communication.NetManager.MDNS

| 名称         | 值   | 说明        |
| --------------- | ---- | ----------- |
| INTERNAL_ERROR  | 0    | 内部错误导致操作失败。  |
| ALREADY_ACTIVE      | 1    | 服务已经存在导致操作失败。 |
| MAX_LIMIT  | 2 | 请求超过最大限制导致操作失败。 |
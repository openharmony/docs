# @ohos.net.mdns (mDNS Management)

Multicast DNS (mDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import mdns from '@ohos.net.mdns'
```
## mdns.addLocalService

addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Adds an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Adds an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Removes an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Removes an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

createDiscoveryService(context: Context, serviceType: string): DiscoveryService

Creates a **DiscoveryService** object, which is used to discover mDNS services of the specified type.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|---------|-----------| ------------------------------------------------------------ |
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceType | string  | Yes      | Type of the mDNS services to be discovered.|

**Return value**

| Type                         | Description                     |
| ----------------------------- |---------------------------------|
| DiscoveryService | **DiscoveryService** object used to discover mDNS services of the specified type.|

**Example**

```js
let serviceType = "_print._tcp";

let discoveryService = mdns.createDiscoveryService(context, serviceType);
```

## mdns.resolveLocalService

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Resolves an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Resolves an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
|----------------------------| ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

>**NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

```js
let localServiceInfo = {
    serviceType: "_print._tcp",
    serviceName: "servicename",
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

Defines a **DiscoveryService** object for discovering mDNS services of the specified type.

### startSearchingMDNS

startSearchingMDNS(): void

Searches for mDNS services on the LAN.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();
```

### stopSearchingMDNS

stopSearchingMDNS(): void

Stops searching for mDNS services on the LAN.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

```js
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();
```

### on('discoveryStart')

on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MDNS_ERR}>): void

Enables listening for **discoveryStart** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStart**.<br>**discoveryStart**: event of starting discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MDNS_ERR](#mdns_err)}>                  | Yes       |   Callback used to return the mDNS service and error information.     |

**Example**

```js
// See mdns.createDiscoveryService.
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStart', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('discoveryStop')

on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MDNS_ERR}>): void

Enables listening for **discoveryStop** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStop**.<br>**discoveryStop**: event of stopping discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MDNS_ERR](#mdns_err)}>                 | Yes       |   Callback used to return the mDNS service and error information.     |

**Example**

```js
// See mdns.createDiscoveryService.
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStop', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('serviceFound')

on(type: 'serviceFound', callback: Callback<[LocalServiceInfo](#localserviceinfo)>): void

Enables listening for **serviceFound** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceFound**.<br>**serviceFound**: event indicating an mDNS service is found.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | Yes       |   mDNS service information.     |

**Example**

```js
// See mdns.createDiscoveryService.
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### on('serviceLost')

on(type: 'serviceLost', callback: Callback<[LocalServiceInfo](#localserviceinfo)>): void

Enables listening for **serviceLost** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceLost**.<br>serviceLost: event indicating that an mDNS service is removed.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | Yes       |   mDNS service information.     |

**Example**

```js
// See mdns.createDiscoveryService.
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data) => {
    console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

## LocalServiceInfo

Defines the mDNS service information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| serviceType   | string                             |  Yes|  Type of the mDNS service. The value is in the format of **\_\<name>.\<tcp/udp>**, where **name** contains a maximum of 63 characters excluding periods (.). |
| serviceName | string                             |  Yes|  Name of the mDNS service.  |
| port            | number           |  No|  Port number of the mDNS server.          |
| host           |  [NetAddress](js-apis-net-connection.md#netaddress) |  No|  IP address of the device that provides the mDNS service. The IP address is not effective when an mDNS service is added or removed.              |
| serviceAttribute     | serviceAttribute\<[ServiceAttribute](#serviceattribute)> |  No|  mDNS service attribute information.              |

## ServiceAttribute

Defines the mDNS service attribute information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| key   | string                             |  Yes|  mDNS service attribute key. The value contains a maximum of 9 characters. |
| value | Array\<number>                             |  Yes|  mDNS service attribute value.  |

## MDNS_ERR

Defines the mDNS error information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name        | Value  | Description       |
| --------------- | ---- | ----------- |
| INTERNAL_ERROR  | 0    | Operation failed because of an internal error. |
| ALREADY_ACTIVE      | 1    | Operation failed because the service already exists.|
| MAX_LIMIT  | 2 | Operation failed because the number of requests exceeds the maximum value. (not supported currently)|

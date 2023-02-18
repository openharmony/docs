# @ohos.enterprise.networkManager（网络管理）

本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import networkManager from '@ohos.enterprise.networkManager';
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取获取所有活动的网络接口，使用callback形式返回网络接口名称数组。

**需要权限：** ohos.permission.GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;            | 是    | callback方式返回网络接口名称数组       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getAllNetworkInterfaces(admin, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(JSON.stringify(result));
});
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want): Promise&lt;Array&lt;string&gt;&gt;

获取所有活动的网络接口，使用promise形式返回网络接口名称数组。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise方式返回网络接口名称数组  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getAllNetworkInterfaces(wantTemp).then((result) => {
    console.log(JSON.stringify(result));
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

获取设备IP地址，使用callback形式返回设备IP地址。

**需要权限：** ohos.permission.GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用                  |
| networkInterface    | string     | 是    | 指定网络接口                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | callback方式返回设备IP地址       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getIpAddress(wantTemp, "eth0", (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string): Promise&lt;string&gt;

获取设备IP地址，使用promise形式返回设备IP地址。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |
| networkInterface    | string     | 是    | 指定网络接口                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise方式返回设备IP地址  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getIpAddress(wantTemp, "eth0").then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## networkManager.getMac

getMac(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

获取设备MAC地址，使用callback形式返回设备MAC地址。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理员应用                  |
| networkInterface    | string     | 是    | 指定网络接口                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | callback方式返回设备MAC地址       |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getMac(wantTemp, "eth0", (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## networkManager.getMac

getIpAddress(admin: Want, networkInterface: string): Promise&lt;string&gt;

获取设备MAC地址，使用promise形式返回设备IP地址。

**需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |
| networkInterface    | string     | 是    | 指定网络接口                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise方式返回设备MAC地址  |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getMac(wantTemp, "eth0").then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

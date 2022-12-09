# 设备信息管理

本模块提供企业设备信息管理能力，包括获取设备序列号等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import deviceInfo from '@ohos.enterprise.deviceInfo';
```

## deviceInfo.getDeviceSerial

getDeviceSerial(admin: Want, callback: AsyncCallback&lt;string&gt;): void

获取设备序列号，使用callback形式返回设备序列号。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | callback方式返回设备序列号       |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceSerial(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDeviceSerial

getDeviceSerial(admin: Want): Promise&lt;string&gt;

获取设备序列号，使用callback形式返回设备序列号。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise方式返回设备序列号  |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceSerial(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## deviceInfo.getDisplayVersion

getDisplayVersion(admin: Want, callback: AsyncCallback&lt;string&gt;): void;

获取设备版本号，使用callback形式返回设备版本号。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;string&gt;            | 是    | callback方式返回设备版本号       |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDisplayVersion(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDisplayVersion

getDisplayVersion(admin: Want): Promise&lt;string&gt;

获取设备版本号，使用callback形式返回设备版本号。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise方式返回设备版本号  |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDisplayVersion(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## deviceInfo.getDeviceName

getDeviceName(admin: Want, callback: AsyncCallback&lt;string&gt;): void

获取设备名称，使用callback形式返回设备名称。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;string&gt;              | 是    | callback方式返回设备名称       |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceName(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDeviceName

getDeviceName(admin: Want): Promise&lt;string&gt;

获取设备名称，使用callback形式返回设备名称。

**需要权限：** ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise方式返回设备名称  |

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
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceName(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
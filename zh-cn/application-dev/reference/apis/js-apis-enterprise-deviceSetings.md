# @ohos.enterprise.deviceSettings（设备设置管理）

本模块提供企业设备信息管理能力，包括获取设备息屏时间等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import deviceSettings from '@ohos.enterprise.deviceSettings';
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want, callback: AsyncCallback&lt;number&gt;): void

指定设备管理员应用获取设备息屏时间，使用callback形式返回设备息屏时间。

**需要权限：** ohos.permission.ENTERPRISE_SET_SCREENOFF_TIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| callback | AsyncCallback&lt;number&gt;            | 是    | 回调函数。当接口调用成功，err为null，data为设备息屏时间，否则err为错误对象。       |

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
deviceSettings.getScreenOffTime(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want): Promise&lt;number&gt;

指定设备管理员应用获取设备息屏时间，使用Promise形式返回设备息屏时间。

**需要权限：** ohos.permission.ENTERPRISE_SET_SCREENOFF_TIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回设备息屏时间。  |

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
deviceSettings.getScreenOffTime(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
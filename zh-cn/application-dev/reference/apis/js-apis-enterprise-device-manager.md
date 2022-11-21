# 企业设备管理

本模块提供企业设备管理能力，使设备具备企业场景下所需的定制能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

以异步方法根据给定的包名和类名激活设备管理员应用，使用Callback形式返回是否激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                 |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用            |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息       |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型         |
| callback       | AsyncCallback\<void>                | 是    | callback方式返回是否激活成功 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                           |          
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

**示例**：

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void

以异步方法根据给定的包名和类名激活设备管理员应用，使用Callback形式返回是否激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型                   |
| userId         | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback       | AsyncCallback\<void>                | 是    | callback方式返回是否激活成功           |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                           |          
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

**示例**：

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>

以异步方法根据给定的包名和类名激活设备管理员应用，使用Promise形式返回是否激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型                   |
| userId         | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | Promise形式返回是否激活成功 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                           |          
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

**示例**：

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100)
.catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<void>): void

以异步方法根据给定的包名和类名将设备普通管理员应用去激活，使用Callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                  |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是    | 普通设备管理员应用           |
| callback | AsyncCallback\<void>                | 是    | callback方式返回是否去激活成功 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void

以异步方法根据给定的包名和类名将设备普通管理员应用去激活，使用Callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是    | 普通设备管理员应用                    |
| userId   | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<void>                | 是    | callback方式返回是否去激活成功          |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

以异步方法根据给定的包名和类名将设备普通管理员应用去激活，使用Promise形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名    | 类型                                  | 必填   | 说明                           |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-application-Want.md) | 是    | 普通设备管理员应用                    |
| userId | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | Promise形式返回是否激活成功 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void

以异步方法根据给定的包名将设备超级管理员应用去激活，使用Callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                  |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | 是    | 超级设备管理员应用的包名        |
| callback   | AsyncCallback\<void>    | 是    | callback方式返回是否去激活成功 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableSuperAdmin success");
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<void>

以异步方法根据给定的包名将设备超级管理员应用去激活，使用Promise形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | 是    | 超级设备管理员应用的包名 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | Promise形式返回是否激活成功 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名和类名判断设备管理员应用是否被激活，使用Callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                   |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用              |
| callback | AsyncCallback\<boolean>             | 是    | callback方式返回是否处于激活状态 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                              |          
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名和类名判断设备管理员应用是否被激活，使用Callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                      |
| userId   | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<boolean>             | 是    | callback方式返回是否处于激活状态         |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>

以异步方法根据给定的包名和类名判断设备管理员应用是否被激活，使用Promise形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名    | 类型                                  | 必填   | 说明                           |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                      |
| userId | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                  |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise形式返回是否处于激活状态 |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, 100).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名判断设备超级管理员应用是否被激活，使用Callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                   |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | 是    | 设备管理员应用              |
| callback   | AsyncCallback\<boolean> | 是    | callback方式返回是否处于激活状态 |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.isSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isSuperAdmin

isSuperAdmin(bundleName: String): Promise\<boolean>

以异步方法根据给定的包名判断设备超级管理员应用是否被激活，使用Promise形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| bundleName | String | 是    | 超级设备管理员应用 |

**返回值：**

| 类型                | 说明                  |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise形式返回是否处于激活状态 |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.isSuperAdmin(bundleName).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getDeviceSettingsManager

getDeviceSettingsManager(callback: AsyncCallback&lt;DeviceSettingsManager&gt;): void

获取DeviceSettingsManager对象，使用callback形式返回DeviceSettingsManager对象。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                      | 必填   | 说明                                  |
| -------- | --------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<[DeviceSettingsManager](js-apis-enterpriseDeviceManager-DeviceSettingsManager.md)&gt; | 是    | callback方式返回DeviceSettingsManager对象 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                                         |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error != null) {
        console.log("error code:" + error.code);
        return;
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error) => { 
        if (error != null) {
            console.log("error code:" + error.code);
        }
    });
});
```

## enterpriseDeviceManager.getDeviceSettingsManager

getDeviceSettingsManager(): Promise&lt;DeviceSettingsManager&gt;

获取DeviceSettingsManager对象，使用Promise形式返回DeviceSettingsManager对象。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**返回值：**

| 类型                                   | 说明                                 |
| ------------------------------------ | ---------------------------------- |
| Promise&lt;[DeviceSettingsManager](js-apis-enterpriseDeviceManager-DeviceSettingsManager.md)&gt; | Promise方式返回DeviceSettingsManager对象 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                                         |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).catch((error) => {
        console.log("error code:" + error.code);
    })
}).catch((error) => {
    console.log("error code:" + error.code);
})
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>;): void

设置设备管理员应用的企业信息，使用callback形式返回是否设置成功。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明                     |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息           |
| callback       | AsyncCallback\<void>;               | 是    | callback方式返回是否设置企业信息成功 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                  |          
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("setEnterpriseInfo success");
});
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;

设置设备管理员应用的企业信息，使用Promise形式返回是否设置成功。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明           |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息 |

**返回值：**

| 类型                | 说明                    |
| ----------------- | --------------------- |
| Promise\<void>    | Promise方式返回是否设置企业信息成功 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                  |          
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

获取设备管理员应用的企业信息，使用callback形式返回设备管理员应用的企业信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-application-Want.md)      | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | 是    | callback方式返回设备管理员应用的企业信息 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                  |          
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
enterpriseDeviceManager.getEnterpriseInfo(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log(result.name);
    console.log(result.description);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want): Promise&lt;EnterpriseInfo&gt;

获取设备管理员应用的企业信息，使用Promise形式返回设备管理员应用的企业信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                                       | 说明                        |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise方式返回设备管理员应用的企业信息对象 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 类型      | 说明                                                  |          
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
enterpriseDeviceManager.getEnterpriseInfo(wantTemp).then((result) => {
    console.log(result.name);
    console.log(result.description);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

订阅系统管理事件。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当系统管理事件订阅成功err为null，否则为错误对象。 |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.subscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## enterpriseDeviceManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

订阅系统管理事件。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## enterpriseDeviceManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

取消订阅系统管理事件。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 取消订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当系统管理事件取消订阅成功err为null，否则为错误对象。 |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.unsubscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## enterpriseDeviceManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

取消订阅系统管理事件。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 取消订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## EnterpriseInfo

设备管理员应用的企业信息

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称          | 读写属性 | 类型     | 必填   | 描述                |
| ----------- | ---- | ------ | ---- | ----------------- |
| name        | 只读   | string | 是    | 表示设备管理员应用所属企业的名称。 |
| description | 只读   | string | 是    | 表示设备管理员应用所属企业的描述。 |

## AdminType

设备管理员应用的管理员类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager 

| 名称                | 默认值  | 说明    |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | 普通管理员 |
| ADMIN_TYPE_SUPER  | 0x01 | 超级管理员 |

## ManagedEvent

可订阅系统管理事件。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager 

| 名称                | 默认值  | 说明    |
| ----------------- | ---- | ----- |
| MANAGED_EVENT_BUNDLE_ADDED | 0 | 应用安装事件。 |
| MANAGED_EVENT_BUNDLE_REMOVED  | 1 | 应用卸载事件。 |


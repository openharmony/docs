# @ohos.enterprise.adminManager (企业设备管理)

本模块提供企业设备管理能力，使设备具备企业场景下所需的定制能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import adminManager from '@ohos.enterprise.adminManager';
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

激活当前用户下的指定设备管理员应用，使用Callback形式返回是否激活成功。其中超级管理员应用只能在管理员用户下激活。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                 |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。            |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息。      |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型。         |
| callback       | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void

激活指定用户下的指定设备管理员应用，使用callback形式返回是否激活成功。其中超级管理员应用只能在管理员用户下被激活。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。                      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息。                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型。                   |
| userId         | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback       | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>

如果调用接口时传入了可选参数userId，则激活指定用户下的指定设备管理员应用，否则激活当前用户下的指定设备管理员应用，使用Promise形式返回是否激活成功。其中超级管理员应用只能在管理员用户下被激活。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。                      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息。                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理员类型。                   |
| userId         | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | 无返回结果的Promise对象。当激活设备管理员应用失败时会抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100)
.catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<void>): void

将当前用户下的指定普通管理员应用去激活，使用callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                  |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | 是    | 普通设备管理员应用。           |
| callback | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void

将指定用户下的指定普通管理员应用去激活，使用callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | 是    | 普通设备管理员应用。                    |
| userId   | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。        |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

如果调用接口时传入了可选参数userId，则将指定用户下的指定普通管理员应用去激活，否则将当前用户下的指定普通管理员应用去激活，使用Promise形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名    | 类型                                  | 必填   | 说明                           |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-app-ability-want.md) | 是    | 普通设备管理员应用。                    |
| userId | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | 无返回结果的Promise对象。当去激活普通管理员应用失败时会抛出错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, 100).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void

根据bundleName将管理员用户下的超级管理员应用去激活，使用callback形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                  |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | 是    | 超级设备管理员应用的包名。        |
| callback   | AsyncCallback\<void>    | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                           |   
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**示例**：

```js
let bundleName = "com.example.myapplication";
adminManager.disableSuperAdmin(bundleName, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableSuperAdmin success");
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<void>

根据bundleName将管理员用户下的超级管理员应用去激活，使用Promise形式返回是否去激活成功。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | 是    | 超级设备管理员应用的包名。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | 无返回结果的Promise对象。当去激活超级管理员应用失败时会抛出错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**示例**：

```js
let bundleName = "com.example.myapplication";
adminManager.disableSuperAdmin(bundleName).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

查询当前用户下的指定设备管理员应用是否被激活，使用callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                   |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。             |
| callback | AsyncCallback\<boolean>             | 是    | 回调函数，当接口调用成功，err为null，data为boolean值，true表示当前用户下的指定设备管理员应用被激活，false表示当前用户下的指定设备管理员应用未激活，否则err为错误对象。 |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

查询指定用户下的指定设备管理员应用是否被激活，使用callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。                      |
| userId   | number                              | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<boolean>             | 是    | 回调函数，当接口调用成功，err为null，data为boolean值，true表示当前用户下的指定设备管理员应用被激活，false表示当前用户下的指定设备管理员应用未激活，否则err为错误对象。      |

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>

如果调用接口时传入参数userId，则查询指定用户下的设备管理员应用是否被激活，否则判断当前用户下的设备管理员应用是否被激活，使用Promise形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名    | 类型                                  | 必填   | 说明                           |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。                      |
| userId | number                              | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型               | 说明                |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise对象, 返回true表示指定的管理员应用被激活，返回false表示指定的管理员应用未激活。|

**示例**：

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, 100).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

根据bundleName查询管理员用户下的超级管理员应用是否被激活，使用callback形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                   |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | 是    | 设备管理员应用。              |
| callback   | AsyncCallback\<boolean> | 是    | 回调函数，当接口调用成功，err为null，data为boolean类型值，true表示当前用户下的指定设备管理员应用被激活，false表示当前用户下的指定设备管理员应用未激活，否则err为错误对象。 |

**示例**：

```js
let bundleName = "com.example.myapplication";
adminManager.isSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String): Promise\<boolean>

根据bundleName查询管理员用户下的超级管理员应用是否被激活，使用Promise形式返回是否处于激活状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数**：

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| bundleName | String | 是    | 超级设备管理员应用。 |

**返回值：**

| 错误码ID           | 错误信息               |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise对象, 返回true表示指定的超级管理员应用被激活，返回false表示指定的超级管理员应用未激活。 |

**示例**：

```js
let bundleName = "com.example.myapplication";
adminManager.isSuperAdmin(bundleName).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>;): void

设置指定设备管理员应用的企业信息，使用callback形式返回是否设置成功。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明                     |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。                |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息。           |
| callback       | AsyncCallback\<void>;               | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

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
adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("setEnterpriseInfo success");
});
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;

设置指定设备管理员应用的企业信息，使用Promise形式返回是否设置成功。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明           |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理员应用的企业信息 |

**返回值：**

| 类型                | 说明                    |
| ----------------- | --------------------- |
| Promise\<void>    | 无返回结果的Promise对象。当设置设备管理员应用企业信息失败时会抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

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
adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

获取指定设备管理员应用的企业信息，使用callback形式返回设备管理员应用的企业信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-app-ability-want.md)      | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | 是    | 回调函数，当接口调用成功，err为null，data为设备管理员应用的企业信息，否则err为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
adminManager.getEnterpriseInfo(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log(result.name);
    console.log(result.description);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want): Promise&lt;EnterpriseInfo&gt;

获取指定设备管理员应用的企业信息，使用Promise形式返回设备管理员应用的企业信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                                       | 说明                        |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise对象，返回指定设备管理员应用的企业信息。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

**示例：**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
adminManager.getEnterpriseInfo(wantTemp).then((result) => {
    console.log(result.name);
    console.log(result.description);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

指定设备管理员应用订阅系统管理事件。使用callback形式返回结果。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

|错误码ID | 错误信息                                                |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.subscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

指定设备管理员应用订阅系统管理事件。使用Promise形式返回结果。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理员应用订阅系统事件失败时会抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

指定设备管理员应用取消订阅系统管理事件。使用callback形式返回结果。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 取消订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.unsubscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

指定设备管理员应用取消订阅系统管理事件。使用Promise形式返回结果。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | 是 | 取消订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理员应用取消订阅系统管理时间失败时会抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## EnterpriseInfo

设备管理员应用的企业信息

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 可读 | 可写   | 说明                            |
| ----------- | --------| ---- | ----- | ------------------------------- |
| name        | string   | 是   | 否    | 表示设备管理员应用所属企业的名称。 |
| description | string   | 是   | 否    | 表示设备管理员应用所属企业的描述。 |

## AdminType

设备管理员应用的管理员类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | 普通管理员 |
| ADMIN_TYPE_SUPER  | 0x01 | 超级管理员 |

## ManagedEvent

可订阅系统管理事件。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称                        | 值  | 说明           |
| -------------------------- | ---- | ------------- |
| MANAGED_EVENT_BUNDLE_ADDED | 0    | 应用安装事件。 |
| MANAGED_EVENT_BUNDLE_REMOVED | 1  | 应用卸载事件。 |


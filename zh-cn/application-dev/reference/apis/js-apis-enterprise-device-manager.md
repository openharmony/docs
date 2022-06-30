# 企业设备管理

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```


## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名和类名激活设备管理员应用，使用Callback形式返回是否激活成功。

**需要权限：**
ohos.permission.MANAGE_ADMIN

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名         | 类型                                | 必填 | 说明                                                  |
| -------------- | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是   | 设备管理员应用                                        |
| enterpriseInfo | [EnterpriseInfo](#EnterpriseInfo)   | 是   | 设备管理员应用的企业信息                              |
| type           | [AdminType](#AdminType)             | 是   | 激活的设备管理员类型                                  |
| userId         | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback       | AsyncCallback\<boolean>             | 是   | callback方式返回是否激活成功                          |

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
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return; 
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<boolean>

以异步方法根据给定的包名和类名激活设备管理员应用，使用Promise形式返回是否激活成功。

**需要权限：**
ohos.permission.MANAGE_ADMIN

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名         | 类型                                | 必填 | 说明                                                  |
| -------------- | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是   | 设备管理员应用                                        |
| enterpriseInfo | [EnterpriseInfo](#EnterpriseInfo)   | 是   | 设备管理员应用的企业信息                              |
| type           | [AdminType](#AdminType)             | 是   | 激活的设备管理员类型                                  |
| userId         | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise形式返回是否激活成功 |

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
.then((result) => {
	console.log("result is " + result);
}).catch(error => {
	console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId?: number, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名和类名将设备普通管理员应用去激活，使用Callback形式返回是否去激活成功。

**需要权限：**
ohos.permission.MANAGE_ADMIN

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名   | 类型                                | 必填 | 说明                                                  |
| -------- | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是   | 普通设备管理员应用                                    |
| userId   | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<boolean>             | 是   | callback方式返回是否去激活成功                        |

**示例**：

```js
let wantTemp = {
	bundleName: "bundleName",
	abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return; 
    }
    console.log("result is " + result);
});
```



## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<boolean>

以异步方法根据给定的包名和类名将设备普通管理员应用去激活，使用Promise形式返回是否去激活成功。

**需要权限：**
ohos.permission.MANAGE_ADMIN

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名 | 类型                                | 必填 | 说明                                                  |
| ------ | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin  | [Want](js-apis-application-Want.md) | 是   | 普通设备管理员应用                                    |
| userId | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise形式返回是否激活成功 |

**示例**：

```js
let wantTemp = {
	bundleName: "bundleName",
	abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100).then((result) => {
	console.log("result is " + result);
}).catch(error => {
	console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名将设备超级管理员应用去激活，使用Callback形式返回是否去激活成功。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名        | 类型                      | 必填   | 说明                  |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | 是    | 超级设备管理员应用的包名        |
| callback   | AsyncCallback\<boolean> | 是    | callback方式返回是否去激活成功 |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return; 
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<boolean>

以异步方法根据给定的包名将设备超级管理员应用去激活，使用Promise形式返回是否去激活成功。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名        | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | 是    | 超级设备管理员应用的包名 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise形式返回是否激活成功 |

**示例**：

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName).then((result) => {
	console.log("result is " + result);
}).catch(error => {
	console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number, callback: AsyncCallback\<boolean>): void

以异步方法根据给定的包名和类名判断设备管理员应用是否被激活，使用Callback形式返回是否处于激活状态。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名   | 类型                                | 必填 | 说明                                                  |
| -------- | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin    | [Want](js-apis-application-Want.md) | 是   | 设备管理员应用                                        |
| userId   | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<boolean>             | 是   | callback方式返回是否处于激活状态                      |

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

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数**：

| 参数名 | 类型                                | 必填 | 说明                                                  |
| ------ | ----------------------------------- | ---- | ----------------------------------------------------- |
| admin  | [Want](js-apis-application-Want.md) | 是   | 设备管理员应用                                        |
| userId | number                              | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

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

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

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

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

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

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                      | 必填   | 说明                                  |
| -------- | --------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<DeviceSettingsManager&gt; | 是    | callback方式返回DeviceSettingsManager对象 |

**示例：**

```js
let wantTemp = {
	bundleName: "bundleName",
	abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error != null) {
        console.log("error occurs" + error);
        return; 
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error, value) => { 
        if (error != null) {
            console.log(error);
        } else {
            console.log(value);
        }
    });
});
```


## enterpriseDeviceManager.getDeviceSettingsManager

getDeviceSettingsManager(): Promise&lt;DeviceSettingsManager&gt;

获取DeviceSettingsManager对象，使用Promise形式返回DeviceSettingsManager对象。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**返回值：**

| 类型                                   | 说明                                 |
| ------------------------------------ | ---------------------------------- |
| Promise&lt;DeviceSettingsManager&gt; | Promise方式返回DeviceSettingsManager对象 |

**示例：**

```js
let wantTemp = {
	bundleName: "bundleName",
	abilityName: "abilityName",
};
mgr.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).then((value) => {
        console.log(value);
    }).catch((error) => {
        console.log(error);
    })
}).catch((error) => {
    console.log(error);
})
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback&lt;boolean&gt;): void

设置设备管理员应用的企业信息，使用callback形式返回是否设置成功。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数：**

| 参数名            | 类型                                  | 必填   | 说明                     |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用                |
| enterpriseInfo | [EnterpriseInfo](#EnterpriseInfo)   | 是    | 设备管理员应用的企业信息           |
| callback       | AsyncCallback\<boolean&gt;          | 是    | callback方式返回是否设置企业信息成功 |

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
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo)
.then((result) => {
	console.log("result is " + result);
}).catch(error => {
	console.log("error occurs" + error);
});
```


## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise&lt;boolean&gt;

设置设备管理员应用的企业信息，使用Promise形式返回是否设置成功。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数：**

| 参数名            | 类型                                  | 必填   | 说明           |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用      |
| enterpriseInfo | [EnterpriseInfo](#EnterpriseInfo)   | 是    | 设备管理员应用的企业信息 |

**返回值：**

| 类型                 | 说明                    |
| ------------------ | --------------------- |
| Promise\<boolean>; | Promise方式返回是否设置企业信息成功 |

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
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo)
.then((result) => {
	console.log("result is " + result);
}).catch(error => {
	console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

获取设备管理员应用的企业信息，使用callback形式返回设备管理员应用的企业信息。

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-application-Want.md)      | 是    | 设备管理员应用                  |
| callback | AsyncCallback&lt;[EnterpriseInfo](#EnterpriseInfo)&gt; | 是    | callback方式返回设备管理员应用的企业信息 |

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

**系统能力：**
SystemCapability.Customation.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用 |

**返回值：**

| 类型                                       | 说明                        |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#EnterpriseInfo)&gt; | Promise方式返回设备管理员应用的企业信息对象 |

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

## EnterpriseInfo

设备管理员应用的企业信息

**系统能力：**
以下各项对应系统能力均为SystemCapability.Customation.EnterpriseDeviceManager
| 名称          | 读写属性 | 类型     | 必填   | 描述                |
| ----------- | ---- | ------ | ---- | ----------------- |
| name        | 只读   | string | 是    | 表示设备管理员应用所属企业的名称。 |
| description | 只读   | string | 是    | 表示设备管理员应用所属企业的描述。 |


## AdminType

设备管理员应用的管理员类型。

**系统能力：**
以下各项对应系统能力均为SystemCapability.Customation.EnterpriseDeviceManager
| 名称                | 默认值  | 说明    |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | 普通管理员 |
| ADMIN_TYPE_SUPER  | 0x01 | 超级管理员 |

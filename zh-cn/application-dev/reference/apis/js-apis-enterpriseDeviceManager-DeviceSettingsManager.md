# DeviceSettingsManager

> 说明：本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

这个类提供管理Settings的API，仅企业设备管理员应用才能调用。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**示例：**

```js
let deviceSettingsManager : enterpriseDeviceManager.DeviceSettingsManager
```

## DeviceSettingsManager.setDateTime

setDateTime(admin: Want, time: number, callback: AsyncCallback<void>): void;

设置系统时间，使用callback形式返回结果。

**需要权限：** ohos.permission.EDM_MANAGE_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用 |
| time  | number | 是 | 时间戳(ms) |
| callback | AsyncCallback<void> | 是 | callback形式返回结果 |

**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000, (error, value) => { 
        if (error) {
            console.log(error);
        } else {
            console.log(value);
        }
    });
}).catch((error) => {
    console.log(error);
})
```

## DeviceSettingsManager.setDateTime

setDateTime(admin: Want, time: number): Promise<void>;

设置系统时间，使用Promise形式返回。

**需要权限：** ohos.permission.EDM_MANAGE_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | 是    | 设备管理员应用 |
| time  | number | 是 | 时间戳(ms) |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise<void> | 返回Promise对象 |


**示例：**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).then((value) => {
        console.log(value);
    }).catch((error) => {
        console.log(error);
    })
}).catch((error) => {
    console.log(error);
})
```

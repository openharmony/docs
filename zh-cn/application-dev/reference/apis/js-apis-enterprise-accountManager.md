# @ohos.enterprise.accountManager（帐户管理）

本模块提供设备帐户管理能力，包括禁止创建本地用户等。仅企业设备管理员应用才能调用。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口需激活为[设备管理员应用](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后才能调用，实现相应功能。

## 导入模块

```js
import accountManager from '@ohos.enterprise.accountManager';
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback&lt;void&gt;): void

指定设备管理员应用禁止创建本地用户接口，使用callback形式返回设置结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理员应用。                  |
| disallow    | boolean     | 是    | 是否禁止创建本地用户，true表示禁止创建本地用户，false表示允许创建本地用户。                  |
| callback | AsyncCallback&lt;void&gt;            | 是    | 回调函数。当接口调用成功，err为null，否则为错误对象。       |

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
accountManager.disallowAddLocalAccount(wantTemp, true, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean): Promise&lt;void&gt;

指定设备管理员应用禁止创建本地用户，使用Promise形式返回设置结果。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理员应用。 |
| disallow    | boolean     | 是    | 是否禁止创建本地用户，true表示禁止创建本地用户，false表示允许创建本地用户。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当禁止创建本地用户失败时抛出错误对象。 |

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
accountManager.disallowAddLocalAccount(wantTemp, true).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

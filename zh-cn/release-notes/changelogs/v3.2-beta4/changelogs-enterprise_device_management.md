# 定制子系统ChangeLog

OpenHarmony 3.2.8.3 版本相较于OpenHarmony 3.2.8.1版本，定制子系统的API变更如下：

## cl.Customization.1 企业设备管理模块名称变更

从Opeharmonny 3.2.8.3版本开始，将"@ohos.enterpriseDeviceManager.d.ts"改为"@ohos.enterprise.adminManager.d.ts"，开发者需要根据以下说明对应用进行适配。

**变更影响**

在Opeharmonny 3.2.8.3之前版本已开发的应用，需要进行适配动才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

| 原接口                             | 新接口                              |
| ---------------------------------  | ---------------------------------- |
| @ohos.enterpriseDeviceManager.d.ts  | @ohos.enterprise.adminManager.d.ts |

**适配指导**

如上所述，仅将老接口平移到了新的namespace中，所以可以通过修改import来解决适配问题：

如原先接口使用了@ohos.enterpriseDeviceManager：

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```

可以通过直接修改import，来切换到新的namespace上：

```js
import enterpriseDeviceManager from '@ohos.enterprise.adminManager';
```

## cl.Customization.2 enterpriseDeviceManager/DeviceSettingsManager.d.ts模块变更

从Opeharmonny 3.2.8.3版本开始，将enterpriseDeviceManager/DeviceSettingsManager.d.ts更改为"ohos.enterprise.dateTimeManager.d.ts"。

**变更影响**

在Opeharmonny 3.2.8.3之前版本已开发的应用，需要进行适配动才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

| 原接口                | 原接口类型             | 新接口              | 新接口类型                |
| ---------------------------------  | --------- |  ---------------------------------- | ----- |
| enterpriseDeviceManager/DeviceSettingsManager.d.ts | interface | @ohos.enterprise.dateTimeManager.d.ts | namespace |

**适配指导**

若原先使用的enterpriseDeviceManager/DeviceSettingsManager.d.ts的setDateTime接口。

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager'

let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error) => {
        if (error) {
            console.log("error code:" + error.code + " error message:" + error.message);
        }
    });
});
```

需要import新的namespace进行适配。

```js
import dateTimeManager from '@ohos.enterprise.dateTimeManager'

let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
dateTimeManager.setDateTime(wantTemp, 1526003846000, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
})
```

## cl.Customization.3 systemapi变更

从Opeharmonny 3.2.8.3版本开始，企业设备管理所有接口变更为systemapi。

**变更影响**

所有接口只允许系统应用调用，非系统应用无法调用接口。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId: number, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId?: number): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, callback: AsyncCallback<**boolean**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback<**boolean**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, userId?: number): Promise<**boolean**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** getEnterpriseInfo(admin: Want, callback: AsyncCallback<**EnterpriseInfo**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** getEnterpriseInfo(admin: Want): Promise<**EnterpriseInfo**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** isSuperAdmin(bundleName: String, callback: AsyncCallback<**boolean**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** isSuperAdmin(bundleName: String): Promise<**boolean**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **interface** EnterpriseInfo | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **enum** AdminType | systemapi     |
| @ohos.enterprise.adminManager        | adminManager        | **enum** ManagedEvent | systemapi     |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number, callback: AsyncCallback<**void**>): void; | systemapi     |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number): Promise<**void**>; | systemapi     |

## cl.Customization.4 接口权限变更

从Opeharmonny 3.2.8.3版本开始，部分接口新增权限校验。

**变更影响**

在Opeharmonny 3.2.8.3之前版本已开发的应用，需要持有相应权限，否则无法正常调用接口。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 新增权限 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback<**void**>): void; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback<**void**>): void; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise<**void**>; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, callback: AsyncCallback<**void**>): void; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId: number, callback: AsyncCallback<**void**>): void; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId?: number): Promise<**void**>; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String, callback: AsyncCallback<**void**>): void; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String): Promise<**void**>; | ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN     |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback<**void**>): void; | ohos.permission.SET_ENTERPRISE_INFO     |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise<**void**>; | ohos.permission.SET_ENTERPRISE_INFO     |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT     |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT     |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT     |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT     |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number, callback: AsyncCallback<**void**>): void; | ohos.permission.ENTERPRISE_SET_DATETIME     |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number): Promise<**void**>; | ohos.permission.ENTERPRISE_SET_DATETIME     |

**适配指导**

调用以上接口，需要申请相应的权限才能正常调用。

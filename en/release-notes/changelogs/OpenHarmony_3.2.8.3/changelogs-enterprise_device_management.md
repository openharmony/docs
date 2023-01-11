# Customization Subsystem ChangeLog

Compared with OpenHarmony 3.2.8.1, OpenHarmony 3.2.8.3 has the following API changes in the customization subsystem:

## cl.Customization.1 Change of the Enterprise Device Management Module Name

Beginning from OpenHarmony 3.2.8.3, **@ohos.enterpriseDeviceManager.d.ts** is changed to **@ohos.enterprise.adminManager.d.ts**. You need to adapt your applications according to the following information.

**Change Impacts**

The application developed based on OpenHarmony earlier than 3.2.8.3 must be adapted so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

| Original API                            | New API                             |
| ---------------------------------  | ---------------------------------- |
| @ohos.enterpriseDeviceManager.d.ts  | @ohos.enterprise.adminManager.d.ts |

**Adaptation Guide**

The original APIs are only migrated to the new namespace. Therefore, you can modify **import** to solve the adaptation problem.

If the original API uses **@ohos.enterpriseDeviceManager**:

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```

You can directly modify **import** to switch to the new namespace:

```js
import enterpriseDeviceManager from '@ohos.enterprise.adminManager';
```

## cl.Customization.2 enterpriseDeviceManager/DeviceSettingsManager.d.ts Module Change

Beginning from OpenHarmony 3.2.8.3, **enterpriseDeviceManager/DeviceSettingsManager.d.ts** is changed to **ohos.enterprise.dateTimeManager.d.ts**.

**Change Impacts**

The application developed based on OpenHarmony earlier than 3.2.8.3 must be adapted so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

| Original API               | Original API Type            | New API             | New API Type               |
| ---------------------------------  | --------- |  ---------------------------------- | ----- |
| enterpriseDeviceManager/DeviceSettingsManager.d.ts | interface | @ohos.enterprise.dateTimeManager.d.ts | namespace |

**Adaptation Guide**

If the **setDateTime** API of **enterpriseDeviceManager/DeviceSettingsManager.d.ts** is used:

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

You need to import the new namespace for adaptation:

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

## cl.Customization.3 System API Change

Beginning from OpenHarmony 3.2.8.3, all enterprise device management APIs are changed to system APIs.

**Change Impacts**

All APIs can be called only by system applications.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId: number, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableAdmin(admin: Want, userId?: number): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** disableSuperAdmin(bundleName: String): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, callback: AsyncCallback<**boolean**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback<**boolean**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** isAdminEnabled(admin: Want, userId?: number): Promise<**boolean**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** getEnterpriseInfo(admin: Want, callback: AsyncCallback<**EnterpriseInfo**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** getEnterpriseInfo(admin: Want): Promise<**EnterpriseInfo**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** isSuperAdmin(bundleName: String, callback: AsyncCallback<**boolean**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** isSuperAdmin(bundleName: String): Promise<**boolean**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** subscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **function** unsubscribeManagedEvent(admin: Want, managedEvents: Array<**ManagedEvent**>): Promise<**void**>; | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **interface** EnterpriseInfo | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **enum** AdminType | Changed to a system API    |
| @ohos.enterprise.adminManager        | adminManager        | **enum** ManagedEvent | Changed to a system API    |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number, callback: AsyncCallback<**void**>): void; | Changed to a system API    |
| @ohos.enterprise.dataTimeManager        | dateTimeManager        | **function** setDateTime(admin: Want, time: number): Promise<**void**>; | Changed to a system API    |

## cl.Customization.4 API Permission Change

Beginning from OpenHarmony 3.2.8.3, permission verification is required for some APIs.

**Change Impacts**

The application developed based on OpenHarmony earlier than 3.2.8.3 must have the corresponding permission so that it can properly call these APIs.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enumeration/Constant                                         | New Permission|
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

**Adaptation Guide**

Apply for the corresponding permission to call these APIs properly.

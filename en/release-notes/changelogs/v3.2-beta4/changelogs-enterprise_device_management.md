# Customization Subsystem ChangeLog

## cl.Customization.1 Change of the Enterprise Device Management Module Name

Changed **@ohos.enterpriseDeviceManager.d.ts** to **@ohos.enterprise.adminManager.d.ts**.

**Change Impact**

The application developed based on OpenHarmony earlier than 3.2.8.3 must be adapted so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

| Original API                            | New API                             |
| ---------------------------------  | ---------------------------------- |
| @ohos.enterpriseDeviceManager.d.ts  | @ohos.enterprise.adminManager.d.ts |

**Adaptation Guide**

The original APIs are only moved to the new namespace. Therefore, you can modify **import** to solve the adaptation problem.

If the original API uses **@ohos.enterpriseDeviceManager**:

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```

You can modify **import** to switch to the new namespace:

```js
import enterpriseDeviceManager from '@ohos.enterprise.adminManager';
```

## cl.Customization.2 enterpriseDeviceManager/DeviceSettingsManager.d.ts Module Change

Changed **enterpriseDeviceManager/DeviceSettingsManager.d.ts** to **ohos.enterprise.dateTimeManager.d.ts**.

**Change Impact**

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

Changed all enterprise device management APIs to system APIs.

**Change Impact**

All APIs can be called only by system applications.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
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

## cl.Customization.4 API Permission Change

Added permission verification for some APIs.

**Change Impact**

The application developed based on OpenHarmony earlier than 3.2.8.3 must have the corresponding permission so that it can properly call these APIs.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | New Permission|
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

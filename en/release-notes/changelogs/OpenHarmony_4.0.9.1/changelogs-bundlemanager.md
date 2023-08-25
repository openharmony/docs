# Bundle Management Subsystem Changelog
## cl.bundlemanager.1 Bottom Layer Implementation of getAllBundleInfo in @ohos.bundle.d.ts Changed

The **getAllBundleInfo** API in the **@ohos.bundle.d.ts** file is marked as deprecated. On the image with **targetAPILevel** set to API 9 or later, the returned data list is empty.

**Change Impact**

After an update to the new image version, the calling of **getAllBundleInfo** in **@ohos.bundle.d.ts** is successful. However, the returned data list is empty. To obtain the bundle information, call **getAllBundleInfo** in the **@ohos.bundle.bundleManager.d.ts** file.

**Key API/Component Changes**

The bottom-layer implementation is changed. The result value of **getAllBundleInfo** in **@ohos.bundle.d.ts** is empty.

**Adaptation Guide**

If your application uses **getAllBundleInfo** in **@ohos.bundle.d.ts**, replace it with **getAllBundleInfo** in **@ohos.bundle.bundleManager.d.ts**. For details about how to use the new API, see [API Reference](../../../application-dev/reference/apis/js-apis-bundleManager.md#bundlemanagergetallbundleinfo).
```ets
import bundleManager from '@ohos.bundle.bundleManager';
```

## cl.bundlemanager.2 Bottom Layer Implementation of getAllApplicationInfo in @ohos.bundle.d.ts Changed

The **getAllApplicationInfo** API in the **@ohos.bundle.d.ts** file is marked as deprecated. On the image with **targetAPILevel** set to API 9 or later, the returned data list is empty.

**Change Impact**

After an update to the new image version, the calling of **getAllApplicationInfo** in **@ohos.bundle.d.ts** is successful. However, the returned data list is empty. To obtain the application information, call **getAllApplicationInfo** in the **@ohos.bundle.bundleManager.d.ts** file.

**Key API/Component Changes**

The bottom-layer implementation is changed. The result value of **getAllApplicationInfo** in **@ohos.bundle.d.ts** is empty.

**Adaptation Guide**

If your application uses **getAllApplicationInfo** in **@ohos.bundle.d.ts**, replace it with **getAllApplicationInfo** in **@ohos.bundle.bundleManager.d.ts**. For details about how to use the new API, see [API Reference](../../../application-dev/reference/apis/js-apis-bundleManager.md#bundlemanagergetallapplicationinfo).
```ets
import bundleManager from '@ohos.bundle.bundleManager';
```

## cl.bundlemanager.3 Permission on getAllBundleInfo in @ohos.bundle.bundleManager.d.ts Changed

The APIs for obtaining the application list require authorization from the end user.
Therefore, the permission on **getAllBundleInfo** in **@ohos.bundle.bundleManager.d.ts** is changed to **ohos.permission.GET_INSTALLED_BUNDLE_LIST**.

**Change Impact**

After an update to the new image version, you must have the **ohos.permission.GET_INSTALLED_BUNDLE_LIST** permission when calling **getAllBundleInfo**. Otherwise, the call fails.

**Key API/Component Changes**

The permission on **getAllBundleInfo** in **@ohos.bundle.bundleManager.d.ts** is changed to **ohos.permission.GET_INSTALLED_BUNDLE_LIST**.

**Adaptation Guide**

Add the **ohos.permission.GET_INSTALLED_BUNDLE_LIST** permission to the configuration file of the application. This permission is of the **user_grant** type and is not authorized by default during application installation. You must display a dialog box to ask the permission from the user or use pre-authorization. For details about how to display a dialog box to ask for permission, see [Requesting User Authorization](../../../application-dev/security/accesstoken-guidelines.md#requesting-user-authorization). For details about how to use pre-authorization, see [Pre-authorizing user_grant Permissions](../../../application-dev/security/accesstoken-guidelines.md#pre-authorizing-user_grant-permissions).

## cl.bundlemanager.4 Permission on getAllApplicationInfo in @ohos.bundle.bundleManager.d.ts Changed

The APIs for obtaining the application list require authorization from the end user.
Therefore, the permission on **getAllApplicationInfo** in **@ohos.bundle.bundleManager.d.ts** is changed to **ohos.permission.GET_INSTALLED_BUNDLE_LIST**.

**Change Impact**

After an update to the new image version, you must have the **ohos.permission.GET_INSTALLED_BUNDLE_LIST** permission when calling **getAllApplicationInfo**. Otherwise, the call fails.

**Key API/Component Changes**

The permission on **getAllApplicationInfo** in **@ohos.bundle.bundleManager.d.ts** is changed to **ohos.permission.GET_INSTALLED_BUNDLE_LIST**.

**Adaptation Guide**

Add the **ohos.permission.GET_INSTALLED_BUNDLE_LIST** permission to the configuration file of the application. This permission is of the **user_grant** type and is not authorized by default during application installation. You must display a dialog box to ask the permission from the user or use pre-authorization. For details about how to display a dialog box to ask for permission, see [Requesting User Authorization](../../../application-dev/security/accesstoken-guidelines.md#requesting-user-authorization). For details about how to use pre-authorization, see [Pre-authorizing user_grant Permissions](../../../application-dev/security/accesstoken-guidelines.md#pre-authorizing-user_grant-permissions).

## cl.bundlemanager.5 getSpecifiedDistributionType Moved from @ohos.bundle.installer.d.ts to @ohos.bundle.bundleManager.d.ts

The **getSpecifiedDistributionType** API is moved from **@ohos.bundle.installer.d.ts** to **@ohos.bundle.bundleManager.d.ts**.

**Change Impact**

After an update to the new SDK version, the **getSpecifiedDistributionType** API in **@ohos.bundle.installer.d.ts** is moved to **@ohos.bundle.bundleManager.d.ts**.

**Key API/Component Changes**

The **getSpecifiedDistributionType** API in **@ohos.bundle.installer.d.ts** is moved to **@ohos.bundle.bundleManager.d.ts**.

**Adaptation Guide**

To use **getSpecifiedDistributionType**, import the **bundleManager** module.

```ets
import bundleManager form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.6 getAdditionalInfo Moved from @ohos.bundle.installer.d.ts to @ohos.bundle.bundleManager.d.ts

The **getAdditionalInfo** API is moved from **@ohos.bundle.installer.d.ts** to **@ohos.bundle.bundleManager.d.ts**.

**Change Impact**

After an update to the new SDK version, the **getAdditionalInfo** API in **@ohos.bundle.installer.d.ts** is moved to **@ohos.bundle.bundleManager.d.ts**.

**Key API/Component Changes**

The **getAdditionalInfo** API is moved from **@ohos.bundle.installer.d.ts** to **@ohos.bundle.bundleManager.d.ts**.

**Adaptation Guide**

To use **getAdditionalInfo**, import the **bundleManager** module.

```ets
import bundleManager form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.7 proxyDatas Renamed proxyData in the module.json5 File

**proxyDatas** is renamed **proxyData**.

**Change Impact**

After an update to the new SDK version, **proxyDatas** is **renamed proxyData**. If your application is not adapted, the build will fail.

**Key API/Component Changes**

**proxyDatas** is renamed **proxyData**.

**Adaptation Guide**

Replace **proxyDatas** with **proxyData**. The content of **proxyDatas** does not need to be changed.


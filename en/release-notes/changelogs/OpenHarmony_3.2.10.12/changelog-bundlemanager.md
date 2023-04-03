# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deleted the atomicService Tag from the app.json File
The **atomicService** tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete the **atomicService** tag from your code.

## cl.bundlemanager.2 Added the bundleType Tag to the app.json File
The **bundleType** tag is added to the **app.json** file.

**Change Impact**<br>
For an existing ability with [installationFree](../../../application-dev/quick-start/module-configuration-file.md) set to **true**, **bundleType** must be set to **atomicService** in the **app.json** file. Otherwise, the packaging fails.

**Adaptation Guide**<br>
Add the [bundleType](../../../application-dev/quick-start/app-configuration-file.md) tag. This tag can be left blank. The default value is **app**. The setting of this tag and the [installationFree](../../../application-dev/quick-start/module-configuration-file.md) field in the **module.json** file must meet the following rules:
- If **bundleType** is **app**, **installationFree** must be set to **false**.
- If **bundleType** is **atomicService**, **installationFree** must be set to **true**.

## cl.bundlemanager.3 Deleted the split Field from the ApplicationInfo Struct

The **split** field is deleted from the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct.

**Change Impact**<br>
If the **split** field is used in your code, the compilation fails.

**Key API/Component Changes**<br>
The **split** field is deleted from the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct.

**Adaptation Guide**<br>
Delete the **split** field from the **ApplicationInfo** struct of your code. The stage model always forcibly splits bundles.

## cl.bundlemanager.4 Deleted the atomicServiceModuleType Field from the HapModuleInfo Struct

The **atomicServiceModuleType** field is deleted from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct.

**Change Impact**<br>
If the **atomicServiceModuleType** field is used in your code, the compilation fails.

**Key API/Component Changes**<br>
The **atomicServiceModuleType** field is deleted from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct.

**Adaptation Guide**<br>
Record the setting of the **atomicServiceModuleType** field, delete it from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct, and set the **moduleType** field in the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct to the recorded value.

## cl.bundlemanager.5 Deleted the AtomicServiceModuleType Enumerated Value

The **atomicServiceModuleType** field is deleted from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct.

**Change Impact**<br>
If the **atomicServiceModuleType** field is used in your code, the compilation fails.

**Key API/Component Changes**<br>
The **atomicServiceModuleType** field is deleted from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct.

**Adaptation Guide**<br>
Record the setting of the **atomicServiceModuleType** field, delete it from the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct, and set the **moduleType** field in the [HapModuleInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) struct to the recorded value.

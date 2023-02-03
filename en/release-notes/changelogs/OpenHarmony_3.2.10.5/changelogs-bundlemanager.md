# Bundle Manager Subsystem ChangeLog

## cl.bundlemanager.1 Field Change of the ApplicationInfo Struct in API Version 9

The **entryDir** field is deleted from the **ApplicationInfo** struct [[bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/monthly_20221018/api/bundleManager/applicationInfo.d.ts)] in API version 9.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 must adapt to the new modules and APIs.

**Key API/Component Changes**

The following table describes the changed fields in the **ApplicationInfo** struct.

| Deleted Field| Added or Changed Field in API Version 9| Type|
| --- | --- | --- |
| entryDir | None | string |

**Adaptation Guide**

When importing the bundle management query module, delete the **entryDir** field from the **ApplicationInfo** struct of API version 9.

## cl.bundlemanager.2 Field Change of the HapModuleInfo Struct in API Version 9

The **moduleSourceDir** field is deleted from the **HapModuleInfo** struct [[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/monthly_20221018/api/bundleManager/hapModuleInfo.d.ts)] in API version 9.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 must adapt to the new modules and APIs.

**Key API/Component Changes**

The following table describes the changed fields in the **HapModuleInfo** struct.

| Deleted Field| Added or Changed Field in API Version 9| Type|
| --- | --- | --- |
| moduleSourceDir | None | string |

**Adaptation Guide**

When importing the bundle manager query module, delete the **moduleSourceDir** field from the **HapModuleInfo** struct of API version 9.  
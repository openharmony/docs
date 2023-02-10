# Bundle Manager Subsystem ChangeLog

## cl.bundlemanager.1 Field Change of the ApplicationInfo Structure in API Version 9

The **ApplicationInfo** structure [[bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/applicationInfo.d.ts)] in API version 9 has field changes, with the **systemApp** field being added and the **entryDir** field being deleted.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs.

**Key API/Component Changes**

The following table describes the changed fields in the **ApplicationInfo** structure.

| Deleted Field    | Added or Changed Field in API Version 9| Type   |
| -------- | -------------- | ------- |
| None      | systemApp      | boolean |
| entryDir | None            | string  |

**Adaptation Guide**

Import the bundle manager query module and use the **systemApp** field in the **ApplicationInfo** structure of API version 9. If the **entryDir** field is used, change the field because it is redundant in features where HAP decompression is not required.

## cl.bundlemanager.2 Field Change of the HapModuleInfo Structure in API Version 9

The **moduleSourceDir** field is deleted from the **HapModuleInfo** structure [[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/hapModuleInfo.d.ts)] in API version 9.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs.

**Key API/Component Changes**

The following table describes the changed fields in the **HapModuleInfo** structure.

| Deleted Field           | Added or Changed Field in API Version 9| Type  |
| --------------- | -------------- | ------ |
| moduleSourceDir | None            | string |

**Adaptation Guide**

Import the bundle manager query module and do not use the **moduleSourceDir** field in the **HapModuleInfo** structure of API version 9. If the **moduleSourceDir** field is used, change the field because it is redundant in features where HAP decompression is not required.

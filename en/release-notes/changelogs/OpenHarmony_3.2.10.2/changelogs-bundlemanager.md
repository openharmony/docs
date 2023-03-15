# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Field Change of the ApplicationInfo Struct in API Version 9

The **ApplicationInfo** struct [bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) in API version 9 has field changes, with the **systemApp** field being added and the **entryDir** field being deleted.

**Change Impact**<br>
There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs.

**Key API/Component Changes**<br>
The following table describes the changed fields in the **ApplicationInfo** struct.
| Deleted Field| Added or Changed Field in API Version 9| Type|
| --- | --- | --- |
| N/A| systemApp | boolean |
| entryDir | N/A | string |

**Adaptation Guide**<br>
Import the bundle manager query module and use the **systemApp** field in the **ApplicationInfo** struct of API version 9. If the **entryDir** field is used, change the field because it is redundant in features where HAP decompression is not required.

## cl.bundlemanager.2 Field Change of the HapModuleInfo Struct in API Version 9

The **moduleSourceDir** field is deleted from the **HapModuleInfo** struct [bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) in API version 9.

**Change Impact**<br>
There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs.

**Key API/Component Changes**<br>
The following table describes the changed fields in the **HapModuleInfo** struct.
| Deleted Field| Added or Changed Field in API Version 9| Type|
| --- | --- | --- |
| moduleSourceDir | N/A | string |

**Adaptation Guide**<br>
Import the bundle manager query module and do not use the **moduleSourceDir** field in the **HapModuleInfo** struct of API version 9. If the **moduleSourceDir** field is used, change the field because it is redundant in features where HAP decompression is not required.

# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deleted the pageModule Field from the Routing Table Configuration File

**Access Level**

Public API

**Reason for Deletion**

In the overall routing table solution design, the **pageModule** field is not required in the routing table configuration file **routerMap.json**. Therefore, this field is deleted.

**Change Impact**

This change is a non-compatible change. If the **pageModule** field is configured in the routing table configuration file, the JSON schema verification fails, causing the build to fail. The build also fails if the **pageModule** field in the **RouterItem** struct is used, which is defined in the **HapModuleInfo.d.ts** file of the bundle manager module.

**API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.20

**Key API/Component Changes**

The **pageModule** field is deleted from the route table configuration file **routerMap.json**, and the **pageModule** field is deleted from the **RouterItem** struct in the **HapModuleInfo.d.ts** file.

**Adaptation Guide**

Delete the **pageModule** field from the route table configuration file, and delete the **pageModule** field from the **RouterItem** struct.

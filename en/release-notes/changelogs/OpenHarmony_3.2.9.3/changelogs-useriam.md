# User IAM Subsystem Changelog

## cl.useriam.1 Deletion of API9 GetVesion

Deleted the **GetVersion()** API.

**Change Impact**

The **GetVersion()** API cannot be used from this version.

**Key API/Component Changes**

|   Module     |     Class    |     Method/Attribute/Enum/Constant     |    Change Type    |
| ---------------------- | ------------------- | ------------------------- | ------------------------ |
| ohos.userIAM.userAuth | function | getVersion() : number | Deleted|

**Adaptation Guide**

Delete the use of **GetVersion()**.

## cl.useriam.2 Change of the API8 GetVesion() Return Value

Changed the return value of **GetVersion()** (in API version 8) from **0** to **1**.

**Change Impact**

If the application verifies the return value of **GetVersion()** (API version 8), the verification fails.

**Key API/Component Changes**

The return value of **GetVersion()** (in API version 8) is changed from **0** to **1**.

**Adaptation Guide**

Delete the use of **GetVersion()** (API version 8) because this API has been deprecated.

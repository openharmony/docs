# User IAM Subsystem Changelog

## cl.useriam.1 API9 Result Value Change

Changed the return value **ResultCodeV9** to **UserAuthResultCode** for API9.

**Change Impact**

Applications developed based on earlier versions are not affected. For the applications developed from this version, the class name of the error code needs to be adapted. Otherwise, the service logic is affected.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Change the class name for invoking the authentication result code from **ResultCode** to **UserAuthResultCode**.

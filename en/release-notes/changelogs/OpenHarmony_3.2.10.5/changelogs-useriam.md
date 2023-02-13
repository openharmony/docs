# User IAM Subsystem ChangeLog

## cl.useriam.1 API9 Authentication Result Code Class Name Change

The name of the authentication result code class of user IAM API version 9 is changed from **ResultCode** to **UserAuthResultCode**.

**Change Impacts**

Applications developed based on earlier versions are not affected. For the applications developed from this version, the class name of the error code needs to be adapted. Otherwise, the service logic is affected.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Change the class name for invoking the authentication result code from **ResultCode** to **UserAuthResultCode**.

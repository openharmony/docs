# User IAM Subsystem ChangeLog

## cl.useriam.1 API Exception Handling Change

Certain user IAM APIs use service logic return values to indicate error information, which does not comply with the API error code specifications of OpenHarmony. The following changes are made in API version 9:

An error message is returned by throwing an exception.

**Change Impact**

Applications developed based on earlier versions are not affected. If your application uses API version 9 or later, you need to adapt the change in the way for APIs to return error information. Otherwise, service logic will be affected.

**Key API/Component Changes**

To implement unified exception handling, certain IAM APIs are deprecated and replaced by new APIs. The newly added APIs support unified error code handling specifications and function the same as the original APIs.

|   Module     |     Class    |     Method/Attribute/Enum/Constant     |    Change Type    |
| ---------------------- | ------------------- | ------------------------- | ------------------------ |
| ohos.userIAM.userAuth | UserAuth | constructor() | Deprecated|
| ohos.userIAM.userAuth | UserAuth | getVersion() : number | Deprecated|
| ohos.userIAM.userAuth | UserAuth | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number | Deprecated|
| ohos.userIAM.userAuth | UserAuth | auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array | Deprecated|
| ohos.userIAM.userAuth | UserAuth | cancelAuth(contextID : Uint8Array) : number | Deprecated|
| ohos.userIAM.userAuth | IUserAuthCallback | onResult: (result : number, extraInfo : AuthResult) => void | Deprecated|
| ohos.userIAM.userAuth | IUserAuthCallback | onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void | Deprecated|
| ohos.userIAM.userAuth | AuthResult | AuthResult {<br>token ?: Uint8Array; <br>remainTimes ?: number; <br>freezingTime ?: number;} | Deprecated|
| ohos.userIAM.userAuth | Enum| ResultCode {<br>SUCCESS = 0, <br>FAIL = 1, <br>GENERAL_ERROR = 2, <br>CANCELED = 3, <br>TIMEOUT = 4, <br>TYPE_NOT_SUPPORT = 5, <br>TRUST_LEVEL_NOT_SUPPORT = 6, <br>BUSY = 7, <br>INVALID_PARAMETERS = 8, <br>LOCKED = 9, <br>NOT_ENROLLED = 10,} | Deprecated|
| ohos.userIAM.userAuth | type | AuthEventKey = "result" | Added|
| ohos.userIAM.userAuth | type | EventInfo = AuthResultInfo | Added|
| ohos.userIAM.userAuth | AuthResultInfo | AuthResultInfo {<br>result : number; <br>token ?: Uint8Array; <br>remainAttempts ?: number; <br>lockoutDuration ?: number;} | Added|
| ohos.userIAM.userAuth | TipInfo | TipInfo {<br>module : number; <br>tip : number;} | Added|
| ohos.userIAM.userAuth | AuthInstance | AuthInstance {<br>on: (name: AuthEventKey, callback: AuthEvent) => void; <br>off: (name: AuthEventKey) => void; <br>start: () => void; <br>cancel: () => void;} | Added|
| ohos.userIAM.userAuth | Enum| ResultCodeV9 {<br>SUCCESS = 12500000, <br>FAIL = 12500001, <br>GENERAL_ERROR = 12500002, <br>CANCELED = 12500003, <br>TIMEOUT = 12500004, <br>TYPE_NOT_SUPPORT = 12500005, <br>TRUST_LEVEL_NOT_SUPPORT = 12500006, <br>BUSY = 12500007, <br>LOCKED = 12500009, <br>NOT_ENROLLED = 12500010,} | Added|
| ohos.userIAM.userAuth | function | getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel) : AuthInstance | Added|
| ohos.userIAM.userAuth | function | getVersion() : number | Added|
| ohos.userIAM.userAuth | function | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : void | Added|
| ohos.userIAM.faceAuth | FaceAuthManager | setSurfaceId(surfaceId : string) : ResultCode | Deleted|
| ohos.userIAM.faceAuth | Enum| ResultCode {<br>SUCCESS = 0, <br>FAIL = 1,} | Deleted|
| ohos.userIAM.faceAuth | FaceAuthManager | setSurfaceId(surfaceId: string) : void | Added|

**Adaptation Guide**

The following uses **getVersion** as an example:

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

try {
    let version = userIAM_userAuth.getVersion();
    console.info("auth version = " + version);
} catch (error) {
    console.info("get version failed, error = " + error);
}
```

For more information about the APIs, see [User Authentication](../../../application-dev/reference/apis/js-apis-useriam-userauth.md) and [Facial Authentication](../../../application-dev/reference/apis/js-apis-useriam-faceauth.md).

## cl.useriam.2 API Invoking Permission Change

Some user IAM APIs can only be called by system applications, and system application runtime authentication is required. The following changes are made in API version 9:

Added the service logic for checking whether an application is a system application to the **setSurfaceId** API of the facial authentication module. Non-system applications cannot call this API.

**Change Impact**

Applications developed based on earlier versions are not affected.

**Key API/Component Changes**

The service logic for checking whether an application is a system application is added to **setSurfaceId()** . Error code **202** will be returned if the API is called by a non-system application.

**Adaptation Guide**

Change the **app-feature** field to **hos_system_app** in the **UnsgnedReleasedProfileTemplate.json** file in [developtools_hapsigner](https://gitee.com/openharmony/developtools_hapsigner/tree/master/dist). Then, the signed application is a system application.

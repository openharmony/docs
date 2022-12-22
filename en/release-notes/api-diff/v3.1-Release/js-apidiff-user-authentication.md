# JS API Changes of the User IAM Subsystem

The table below lists the APIs changes of the user IAM subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.userIAM.userAuth | AuthTrustLevel | ATL4 = 40000 | Added|
| ohos.userIAM.userAuth | AuthTrustLevel | ATL3 = 30000 | Added|
| ohos.userIAM.userAuth | AuthTrustLevel | ATL2 = 20000 | Added|
| ohos.userIAM.userAuth | AuthTrustLevel | ATL1 = 10000 | Added|
| ohos.userIAM.userAuth | UserAuthType | FINGERPRINT = 4 | Added|
| ohos.userIAM.userAuth | UserAuthType | FACE = 2 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_TOO_FAST = 4 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_PARTIAL = 3 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_DIRTY = 1 | Added|
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_GOOD = 0 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_NOT_DETECTED = 11 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_POOR_GAZE = 10 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_MUCH_MOTION = 9 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_LEFT = 8 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_RIGHT = 7 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_LOW = 6 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_HIGH = 5 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_FAR = 4 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_CLOSE = 3 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_DARK = 2 | Added|
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_BRIGHT = 1 | Added|
| ohos.userIAM.userAuth | ResultCode | NOT_ENROLLED = 10 | Added|
| ohos.userIAM.userAuth | ResultCode | LOCKED = 9 | Added|
| ohos.userIAM.userAuth | ResultCode | INVALID_PARAMETERS = 8 | Added|
| ohos.userIAM.userAuth | ResultCode | BUSY = 7 | Added|
| ohos.userIAM.userAuth | ResultCode | TRUST_LEVEL_NOT_SUPPORT = 6 | Added|
| ohos.userIAM.userAuth | ResultCode | TYPE_NOT_SUPPORT = 5 | Added|
| ohos.userIAM.userAuth | ResultCode | TIMEOUT = 4 | Added|
| ohos.userIAM.userAuth | ResultCode | CANCELED = 3 | Added|
| ohos.userIAM.userAuth | ResultCode | GENERAL_ERROR = 2 | Added|
| ohos.userIAM.userAuth | ResultCode | FAIL = 1 | Added|
| ohos.userIAM.userAuth | ResultCode | SUCCESS = 0 | Added|
| ohos.userIAM.userAuth | AuthResult | freezingTime ?: number; | Added|
| ohos.userIAM.userAuth | AuthResult | remainTimes ?: number; | Added|
| ohos.userIAM.userAuth | AuthResult | token ?: Uint8Array; | Added|
| ohos.userIAM.userAuth | IUserAuthCallback | onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void; | Added|
| ohos.userIAM.userAuth | IUserAuthCallback | onResult: (result : number, extraInfo : AuthResult) => void; | Added|
| ohos.userIAM.userAuth | UserAuth | cancelAuth(contextID : Uint8Array) : number; | Added|
| ohos.userIAM.userAuth | UserAuth | auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array; | Added|
| ohos.userIAM.userAuth | UserAuth | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number; | Added|
| ohos.userIAM.userAuth | UserAuth | getVersion() : number; | Added|
| ohos.userIAM.userAuth | UserAuth | constructor(); | Added|
| ohos.userIAM.userAuth | userAuth | function getAuthenticator(): Authenticator; | Added|
| ohos.userIAM.userAuth | Authenticator | execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void;<br>execute(type: AuthType, level: SecureLevel): Promise\<number>; | Added|
| ohos.userIAM.userAuth | AuthenticationResult | GENERAL_ERROR = 100 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | NOT_ENROLLED = 8 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | LOCKED = 7 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | INVALID_PARAMETERS = 6 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | BUSY = 5 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | CAMERA_FAIL = 4 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | TIMEOUT = 3 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | CANCELED = 2 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | COMPARE_FAILURE = 1 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | SUCCESS = 0 | Added|
| ohos.userIAM.userAuth | AuthenticationResult | NO_SUPPORT = -1 | Added|

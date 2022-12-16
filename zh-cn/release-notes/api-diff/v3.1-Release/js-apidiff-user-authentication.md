# 用户身份认证子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，用户身份认证子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.userIAM.userAuth | AuthTrustLevel | ATL4 = 40000 | 新增 |
| ohos.userIAM.userAuth | AuthTrustLevel | ATL3 = 30000 | 新增 |
| ohos.userIAM.userAuth | AuthTrustLevel | ATL2 = 20000 | 新增 |
| ohos.userIAM.userAuth | AuthTrustLevel | ATL1 = 10000 | 新增 |
| ohos.userIAM.userAuth | UserAuthType | FINGERPRINT = 4 | 新增 |
| ohos.userIAM.userAuth | UserAuthType | FACE = 2 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_TOO_FAST = 4 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_PARTIAL = 3 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_DIRTY = 1 | 新增 |
| ohos.userIAM.userAuth | FingerprintTips | FINGERPRINT_AUTH_TIP_GOOD = 0 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_NOT_DETECTED = 11 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_POOR_GAZE = 10 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_MUCH_MOTION = 9 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_LEFT = 8 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_RIGHT = 7 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_LOW = 6 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_HIGH = 5 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_FAR = 4 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_CLOSE = 3 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_DARK = 2 | 新增 |
| ohos.userIAM.userAuth | FaceTips | FACE_AUTH_TIP_TOO_BRIGHT = 1 | 新增 |
| ohos.userIAM.userAuth | ResultCode | NOT_ENROLLED = 10 | 新增 |
| ohos.userIAM.userAuth | ResultCode | LOCKED = 9 | 新增 |
| ohos.userIAM.userAuth | ResultCode | INVALID_PARAMETERS = 8 | 新增 |
| ohos.userIAM.userAuth | ResultCode | BUSY = 7 | 新增 |
| ohos.userIAM.userAuth | ResultCode | TRUST_LEVEL_NOT_SUPPORT = 6 | 新增 |
| ohos.userIAM.userAuth | ResultCode | TYPE_NOT_SUPPORT = 5 | 新增 |
| ohos.userIAM.userAuth | ResultCode | TIMEOUT = 4 | 新增 |
| ohos.userIAM.userAuth | ResultCode | CANCELED = 3 | 新增 |
| ohos.userIAM.userAuth | ResultCode | GENERAL_ERROR = 2 | 新增 |
| ohos.userIAM.userAuth | ResultCode | FAIL = 1 | 新增 |
| ohos.userIAM.userAuth | ResultCode | SUCCESS = 0 | 新增 |
| ohos.userIAM.userAuth | AuthResult | freezingTime ?: number; | 新增 |
| ohos.userIAM.userAuth | AuthResult | remainTimes ?: number; | 新增 |
| ohos.userIAM.userAuth | AuthResult | token ?: Uint8Array; | 新增 |
| ohos.userIAM.userAuth | IUserAuthCallback | onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void; | 新增 |
| ohos.userIAM.userAuth | IUserAuthCallback | onResult: (result : number, extraInfo : AuthResult) => void; | 新增 |
| ohos.userIAM.userAuth | UserAuth | cancelAuth(contextID : Uint8Array) : number; | 新增 |
| ohos.userIAM.userAuth | UserAuth | auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array; | 新增 |
| ohos.userIAM.userAuth | UserAuth | getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number; | 新增 |
| ohos.userIAM.userAuth | UserAuth | getVersion() : number; | 新增 |
| ohos.userIAM.userAuth | UserAuth | constructor(); | 新增 |
| ohos.userIAM.userAuth | userAuth | function getAuthenticator(): Authenticator; | 新增 |
| ohos.userIAM.userAuth | Authenticator | execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void;<br>execute(type: AuthType, level: SecureLevel): Promise\<number>; | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | GENERAL_ERROR = 100 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | NOT_ENROLLED = 8 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | LOCKED = 7 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | INVALID_PARAMETERS = 6 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | BUSY = 5 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | CAMERA_FAIL = 4 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | TIMEOUT = 3 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | CANCELED = 2 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | COMPARE_FAILURE = 1 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | SUCCESS = 0 | 新增 |
| ohos.userIAM.userAuth | AuthenticationResult | NO_SUPPORT = -1 | 新增 |

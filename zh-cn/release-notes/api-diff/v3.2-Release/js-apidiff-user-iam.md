| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AuthResultInfo;<br>方法or属性：token ?: Uint8Array;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：FaceAuthManager;<br>方法or属性：constructor();|@ohos.userIAM.faceAuth.d.ts|
|新增|NA|类名：FaceAuthManager;<br>方法or属性：setSurfaceId(surfaceId: string): void;|@ohos.userIAM.faceAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：type AuthEventKey = "result" \| "tip";|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：type EventInfo = AuthResultInfo \| TipInfo;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：function getAvailableStatus(authType: UserAuthType, authTrustLevel: AuthTrustLevel): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：userAuth;<br>方法or属性：function getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthEvent;<br>方法or属性：callback(result: EventInfo): void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthResultInfo;<br>方法or属性：result: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthResultInfo;<br>方法or属性：remainAttempts ?: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthResultInfo;<br>方法or属性：lockoutDuration ?: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：TipInfo;<br>方法or属性：module: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：TipInfo;<br>方法or属性：tip: number;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthInstance;<br>方法or属性：on: (name: AuthEventKey, callback: AuthEvent) => void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthInstance;<br>方法or属性：off: (name: AuthEventKey) => void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthInstance;<br>方法or属性：start: () => void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：AuthInstance;<br>方法or属性：cancel: () => void;|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：SUCCESS = 12500000|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：FAIL = 12500001|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：GENERAL_ERROR = 12500002|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：CANCELED = 12500003|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：TIMEOUT = 12500004|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：TYPE_NOT_SUPPORT = 12500005|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：TRUST_LEVEL_NOT_SUPPORT = 12500006|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：BUSY = 12500007|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：LOCKED = 12500009|@ohos.userIAM.userAuth.d.ts|
|新增|NA|类名：UserAuthResultCode;<br>方法or属性：NOT_ENROLLED = 12500010|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthenticationResult;<br>方法or属性：export enum AuthenticationResult<br>旧版本信息：|类名：AuthenticationResult;<br>方法or属性：export enum AuthenticationResult<br>新版本信息：8<br>代替接口： ohos.userIAM.userAuth.ResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：Authenticator;<br>方法or属性：interface Authenticator<br>旧版本信息：|类名：Authenticator;<br>方法or属性：interface Authenticator<br>新版本信息：8<br>代替接口：|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：Authenticator;<br>方法or属性：execute(type: AuthType, level: SecureLevel): Promise\<number>;<br>旧版本信息：|类名：Authenticator;<br>方法or属性：execute(type: AuthType, level: SecureLevel): Promise\<number>;<br>新版本信息：8<br>代替接口：|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：class UserAuth<br>旧版本信息：|类名：UserAuth;<br>方法or属性：class UserAuth<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：constructor();<br>旧版本信息：|类名：UserAuth;<br>方法or属性：constructor();<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.getAuthInstance|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：getVersion(): number;<br>旧版本信息：|类名：UserAuth;<br>方法or属性：getVersion(): number;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.getVersion|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：getAvailableStatus(authType: UserAuthType, authTrustLevel: AuthTrustLevel): number;<br>旧版本信息：|类名：UserAuth;<br>方法or属性：getAvailableStatus(authType: UserAuthType, authTrustLevel: AuthTrustLevel): number;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.getAvailableStatus|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;<br>旧版本信息：|类名：UserAuth;<br>方法or属性：auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthInstance.start|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：UserAuth;<br>方法or属性：cancelAuth(contextID: Uint8Array): number;<br>旧版本信息：|类名：UserAuth;<br>方法or属性：cancelAuth(contextID: Uint8Array): number;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthInstance.cancel|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：IUserAuthCallback;<br>方法or属性：interface IUserAuthCallback<br>旧版本信息：|类名：IUserAuthCallback;<br>方法or属性：interface IUserAuthCallback<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthEvent|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：IUserAuthCallback;<br>方法or属性：onResult: (result: number, extraInfo: AuthResult) => void;<br>旧版本信息：|类名：IUserAuthCallback;<br>方法or属性：onResult: (result: number, extraInfo: AuthResult) => void;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthEvent.callback|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：IUserAuthCallback;<br>方法or属性：onAcquireInfo ?: (module: number, acquire: number, extraInfo: any) => void;<br>旧版本信息：|类名：IUserAuthCallback;<br>方法or属性：onAcquireInfo ?: (module: number, acquire: number, extraInfo: any) => void;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthEvent.callback|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthResult;<br>方法or属性：interface AuthResult<br>旧版本信息：|类名：AuthResult;<br>方法or属性：interface AuthResult<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthResultInfo|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthResult;<br>方法or属性：token ?: Uint8Array;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：token ?: Uint8Array;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthResultInfo|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthResult;<br>方法or属性：remainTimes ?: number;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：remainTimes ?: number;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthResultInfo|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：AuthResult;<br>方法or属性：freezingTime ?: number;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：freezingTime ?: number;<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.AuthResultInfo|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：enum ResultCode<br>旧版本信息：|类名：ResultCode;<br>方法or属性：enum ResultCode<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：SUCCESS = 0<br>旧版本信息：|类名：ResultCode;<br>方法or属性：SUCCESS = 0<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：FAIL = 1<br>旧版本信息：|类名：ResultCode;<br>方法or属性：FAIL = 1<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：GENERAL_ERROR = 2<br>旧版本信息：|类名：ResultCode;<br>方法or属性：GENERAL_ERROR = 2<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：CANCELED = 3<br>旧版本信息：|类名：ResultCode;<br>方法or属性：CANCELED = 3<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：TIMEOUT = 4<br>旧版本信息：|类名：ResultCode;<br>方法or属性：TIMEOUT = 4<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：TYPE_NOT_SUPPORT = 5<br>旧版本信息：|类名：ResultCode;<br>方法or属性：TYPE_NOT_SUPPORT = 5<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：TRUST_LEVEL_NOT_SUPPORT = 6<br>旧版本信息：|类名：ResultCode;<br>方法or属性：TRUST_LEVEL_NOT_SUPPORT = 6<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：BUSY = 7<br>旧版本信息：|类名：ResultCode;<br>方法or属性：BUSY = 7<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：INVALID_PARAMETERS = 8<br>旧版本信息：|类名：ResultCode;<br>方法or属性：INVALID_PARAMETERS = 8<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：LOCKED = 9<br>旧版本信息：|类名：ResultCode;<br>方法or属性：LOCKED = 9<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|废弃版本有变化|类名：ResultCode;<br>方法or属性：NOT_ENROLLED = 10<br>旧版本信息：|类名：ResultCode;<br>方法or属性：NOT_ENROLLED = 10<br>新版本信息：9<br>代替接口： ohos.userIAM.userAuth.UserAuthResultCode|@ohos.userIAM.userAuth.d.ts|
|权限有变化|类名：userAuth;<br>方法or属性：declare userAuth<br>旧版本信息：ohos.permission.ACCESS_BIOMETRIC|类名：userAuth;<br>方法or属性：declare userAuth<br>新版本信息：|@ohos.userIAM.userAuth.d.ts|
|权限有变化|类名：Authenticator;<br>方法or属性：execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：Authenticator;<br>方法or属性：execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.ACCESS_BIOMETRIC|@ohos.userIAM.userAuth.d.ts|
|权限有变化|类名：UserAuth;<br>方法or属性：getVersion(): number;<br>旧版本信息：|类名：UserAuth;<br>方法or属性：getVersion(): number;<br>新版本信息：ohos.permission.ACCESS_BIOMETRIC|@ohos.userIAM.userAuth.d.ts|
|type有变化|类名：AuthResult;<br>方法or属性：token ?: Uint8Array;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：token ?: Uint8Array;<br>新版本信息：Uint8Array|@ohos.userIAM.userAuth.d.ts|
|type有变化|类名：AuthResult;<br>方法or属性：remainTimes ?: number;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：remainTimes ?: number;<br>新版本信息：number|@ohos.userIAM.userAuth.d.ts|
|type有变化|类名：AuthResult;<br>方法or属性：freezingTime ?: number;<br>旧版本信息：|类名：AuthResult;<br>方法or属性：freezingTime ?: number;<br>新版本信息：number|@ohos.userIAM.userAuth.d.ts|

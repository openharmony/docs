# @ohos.userIAM.userAuth    
提供用户认证能力，可应用于设备解锁、支付、应用登录等身份认证场景。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import userAuth from '@ohos.userIAM.userAuth'    
```  
    
## AuthenticationResult<sup>(deprecated)</sup>    
表示认证结果的枚举。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.userIAM.userAuth.ResultCode替代。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_SUPPORT<sup>(deprecated)</sup> | -1 | 从API version 6 开始支持，从API version 8 开始废弃。<br>设备不支持当前的认证方式。 |  
| SUCCESS<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 8 开始废弃。<br>认证成功。 |  
| COMPARE_FAILURE<sup>(deprecated)</sup> | 1 | 从API version 6 开始支持，从API version 8 开始废弃。<br>比对失败。 |  
| CANCELED<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 8 开始废弃。<br>用户取消认证。 |  
| TIMEOUT<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 8 开始废弃。<br>认证超时。 |  
| CAMERA_FAIL<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 8 开始废弃。<br>开启相机失败。 |  
| BUSY<sup>(deprecated)</sup> | 5 | 从API version 6 开始支持，从API version 8 开始废弃。<br>认证服务忙，请稍后重试。 |  
| INVALID_PARAMETERS<sup>(deprecated)</sup> | 6 | 从API version 6 开始支持，从API version 8 开始废弃。<br>认证参数无效。 |  
| LOCKED<sup>(deprecated)</sup> | 7 | 从API version 6 开始支持，从API version 8 开始废弃。<br>认证失败次数过多，已锁定。 |  
| NOT_ENROLLED<sup>(deprecated)</sup> | 8 | 从API version 6 开始支持，从API version 8 开始废弃。<br>未录入认证凭据。 |  
| GENERAL_ERROR<sup>(deprecated)</sup> | 100 | 从API version 6 开始支持，从API version 8 开始废弃。<br>其他错误。 |  
    
## AuthType<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| ALL |  |  
| FACE_ONLY |  |  
    
## SecureLevel<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| S1 |  |  
| S2 |  |  
| S3 |  |  
| S4 |  |  
    
## Authenticator<sup>(deprecated)</sup>    
认证器对象。    
从API version 6 开始支持，从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### execute<sup>(deprecated)</sup>    
执行用户认证，使用callback方式作为异步方法。  
 **调用形式：**     
- execute(type: AuthType, level: SecureLevel, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | AuthType | true | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |  
| level<sup>(deprecated)</sup> | SecureLevel | true | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 | |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
let authenticator = userIAM_userAuth.getAuthenticator();authenticator.execute('FACE_ONLY', 'S2', (error, code)=>{  if (code === userIAM_userAuth.ResultCode.SUCCESS) {    console.info('auth success');    return;  }  console.error('auth fail, code = ' + code);});    
```    
  
    
### execute<sup>(deprecated)</sup>    
执行用户认证，使用promise方式作为异步方法。  
 **调用形式：**     
- execute(type: AuthType, level: SecureLevel): Promise\<number>  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | AuthType | true | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |  
| level<sup>(deprecated)</sup> | SecureLevel | true | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回携带一个number的Promise。number为认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
try {  
  let authenticator = userIAM_userAuth.getAuthenticator();  
  authenticator.execute('FACE_ONLY', 'S2').then((code)=>{  
    console.info('auth success');  
  })  
} catch (error) {  
  console.error('auth fail, code = ' + error);  
}  
    
```    
  
    
## getAuthenticator<sup>(deprecated)</sup>    
获取Authenticator对象，用于执行用户身份认证。  
 **调用形式：**     
- getAuthenticator(): Authenticator  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Authenticator | 认证器对象。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';    let authenticator = userIAM_userAuth.getAuthenticator();    
```    
  
    
## UserAuth<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.AuthInstance替代。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### getVersion<sup>(deprecated)</sup>    
获取认证器的版本信息。  
 **调用形式：**     
- getVersion(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.userIAM.userAuth.getVersion。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 认证器版本信息。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
let auth = new userIAM_userAuth.UserAuth();let version = auth.getVersion();console.info('auth version = ' + version);    
```    
  
    
### getAvailableStatus<sup>(deprecated)</sup>    
查询指定类型和等级的认证能力是否支持。  
 **调用形式：**     
- getAvailableStatus(authType: UserAuthType, authTrustLevel: AuthTrustLevel): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.userIAM.userAuth.getAvailableStatus。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType<sup>(deprecated)</sup> | UserAuthType | true | 认证类型，当前支持FACE和FINGERPRINT。 |  
| authTrustLevel<sup>(deprecated)</sup> | AuthTrustLevel | true | 认证信任等级。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 查询结果，结果为SUCCESS时表示支持，其他返回值参见[ResultCode](#resultcodedeprecated)。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
let auth = new userIAM_userAuth.UserAuth();  
let checkCode = auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);  
if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {  
  console.info('check auth support success');  
} else {  
  console.error('check auth support fail, code = ' + checkCode);  
}  
    
```    
  
    
### auth<sup>(deprecated)</sup>    
执行用户认证，使用回调函数返回结果。  
 **调用形式：**     
- auth(       challenge: Uint8Array,       authType: UserAuthType,       authTrustLevel: AuthTrustLevel,       callback: IUserAuthCallback     ): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.userIAM.userAuth.AuthInstance.start。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| challenge<sup>(deprecated)</sup> | Uint8Array | true | 挑战值，可以传Uint8Array([])。 |  
| authType<sup>(deprecated)</sup> | UserAuthType | true | 认证类型，当前支持FACE和FINGERPRINT。 |  
| authTrustLevel<sup>(deprecated)</sup> | AuthTrustLevel | true | 认证信任等级。 |  
| callback<sup>(deprecated)</sup> | IUserAuthCallback | true | 回调函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | ContextId，作为取消认证[cancelAuth](#cancelauthdeprecated)接口的入参。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
let auth = new userIAM_userAuth.UserAuth();  
let challenge = new Uint8Array([]);  
auth.auth(challenge, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {  
  onResult: (result, extraInfo) => {  
    try {  
      console.info('auth onResult result = ' + result);  
      console.info('auth onResult extraInfo = ' + JSON.stringify(extraInfo));  
      if (result == userIAM_userAuth.ResultCode.SUCCESS) {  
        // 此处添加认证成功逻辑  
      } else {  
        // 此处添加认证失败逻辑  
      }  
    } catch (e) {  
      console.info('auth onResult error = ' + e);  
    }  
  }  
});  
    
```    
  
    
### cancelAuth<sup>(deprecated)</sup>    
表示通过contextID取消本次认证操作。  
 **调用形式：**     
- cancelAuth(contextID: Uint8Array): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.userIAM.userAuth.AuthInstance.cancel。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contextID<sup>(deprecated)</sup> | Uint8Array | true | 上下文的标识，通过[auth](#authdeprecated)接口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 取消认证的结果，结果为SUCCESS时表示取消成功，其他返回值参见[ResultCode](#resultcodedeprecated)。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
// contextId可通过auth接口获取，此处直接定义  
let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);  
let auth = new userIAM_userAuth.UserAuth();  
let cancelCode = auth.cancelAuth(contextId);  
if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {  
  console.info('cancel auth success');  
} else {  
  console.error('cancel auth fail');  
}  
    
```    
  
    
## IUserAuthCallback<sup>(deprecated)</sup>    
返回认证结果的回调对象。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.AuthEvent替代。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onResult<sup>(deprecated)</sup> | (result: number, extraInfo: AuthResult) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.AuthEvent.callback替代。<br>回调函数，返回认证结果。 |  
| onAcquireInfo<sup>(deprecated)</sup> | (module: number, acquire: number, extraInfo: any) => void | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.AuthEvent.callback替代。<br>回调函数，返回认证过程中的提示信息，非必须实现。 |  
    
## AuthResult<sup>(deprecated)</sup>    
表示认证结果的对象。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.AuthResultInfo替代。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | Uint8Array | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>认证通过的令牌信息。 |  
| remainTimes<sup>(deprecated)</sup> | number | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>剩余的认证操作次数。 |  
| freezingTime<sup>(deprecated)</sup> | number | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>认证操作的冻结时间。 |  
    
## ResultCode<sup>(deprecated)</sup>    
表示返回码的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.userIAM.userAuth.UserAuthResultCode替代。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>执行成功。 |  
| FAIL<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>认证失败。 |  
| GENERAL_ERROR<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>操作通用错误。 |  
| CANCELED<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。<br>操作取消。 |  
| TIMEOUT<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。<br>操作超时。 |  
| TYPE_NOT_SUPPORT<sup>(deprecated)</sup> | 5 | 从API version 8 开始支持，从API version 9 开始废弃。<br>不支持的认证类型。 |  
| TRUST_LEVEL_NOT_SUPPORT<sup>(deprecated)</sup> | 6 | 从API version 8 开始支持，从API version 9 开始废弃。<br>不支持的认证等级。 |  
| BUSY<sup>(deprecated)</sup> | 7 | 从API version 8 开始支持，从API version 9 开始废弃。<br>忙碌状态。 |  
| INVALID_PARAMETERS<sup>(deprecated)</sup> | 8 | 从API version 8 开始支持，从API version 9 开始废弃。<br>无效参数。 |  
| LOCKED<sup>(deprecated)</sup> | 9 | 从API version 8 开始支持，从API version 9 开始废弃。<br>认证器已锁定。 |  
| NOT_ENROLLED<sup>(deprecated)</sup> | 10 | 从API version 8 开始支持，从API version 9 开始废弃。<br>用户未录入认证信息。 |  
    
## FaceTips<sup>(8+)</sup>    
表示人脸认证过程中提示码的枚举。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FACE_AUTH_TIP_TOO_BRIGHT | 1 | 光线太强，获取的图像太亮。 |  
| FACE_AUTH_TIP_TOO_DARK | 2 | 光线太暗，获取的图像太暗。 |  
| FACE_AUTH_TIP_TOO_CLOSE | 3 | 人脸距离设备过近。 |  
| FACE_AUTH_TIP_TOO_FAR | 4 | 人脸距离设备过远。 |  
| FACE_AUTH_TIP_TOO_HIGH | 5 | 设备太高，仅获取到人脸上部。 |  
| FACE_AUTH_TIP_TOO_LOW | 6 | 设备太低，仅获取到人脸下部。 |  
| FACE_AUTH_TIP_TOO_RIGHT | 7 | 设备太靠右，仅获取到人脸右部。 |  
| FACE_AUTH_TIP_TOO_LEFT | 8 | 设备太靠左，仅获取到人脸左部。 |  
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9 | 在图像采集过程中，用户人脸移动太快。 |  
| FACE_AUTH_TIP_POOR_GAZE | 10 | 没有正视摄像头。 |  
| FACE_AUTH_TIP_NOT_DETECTED | 11 | 没有检测到人脸信息。 |  
    
## FingerprintTips<sup>(8+)</sup>    
表示指纹认证过程中提示码的枚举。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FINGERPRINT_AUTH_TIP_GOOD | 0 | 获取的指纹图像良好。 |  
| FINGERPRINT_AUTH_TIP_DIRTY | 1 | 由于传感器上可疑或检测到的污垢，指纹图像噪音过大。 |  
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2 | 由于检测到的情况，指纹图像噪声太大，无法处理。 |  
| FINGERPRINT_AUTH_TIP_PARTIAL | 3 | 仅检测到部分指纹图像。 |  
| FINGERPRINT_AUTH_TIP_TOO_FAST | 4 | 快速移动，指纹图像不完整。 |  
| FINGERPRINT_AUTH_TIP_TOO_SLOW | 5 | 缺少运动，指纹图像无法读取。 |  
    
## UserAuthType<sup>(8+)</sup>    
表示身份认证的凭据类型枚举。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PIN<sup>(10+)</sup> | 1 | 口令认证。 |  
| FACE | 2 | 人脸认证。 |  
| FINGERPRINT | 4 | 指纹认证。 |  
    
## AuthTrustLevel<sup>(8+)</sup>    
表示认证结果的信任等级枚举。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ATL1 | 10000 | 认证结果的信任等级级别1，代表该认证方案能够识别用户个体，有一定的活体检测能力。常用的业务场景有业务风控、一般个人数据查询等。 |  
| ATL2 | 20000 | 认证结果的信任等级级别2，代表该认证方案能够精确识别用户个体，有一定的活体检测能力。常用的业务场景有维持设备解锁状态，应用登录等。 |  
| ATL3 | 30000 | 认证结果的信任等级级别3，代表该认证方案能够精确识别用户个体，有较强的活体检测能力。常用的业务场景有设备解锁等。 |  
| ATL4 | 40000 | 认证结果的信任等级级别4，代表该认证方案能够高精度的识别用户个体，有很强的活体检测能力。常用的业务场景有小额支付等。 |  
    
## AuthEventKey<sup>(9+)</sup>    
表示认证事件类型的关键字，作为[on](#ondeprecated)接口的的参数。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| result | [on](#ondeprecated)接口第一个参数为"result"时，[callback](#callback9)回调返回认证的结果信息。 |  
| tip | [on](#ondeprecated)接口第一个参数为"tip"时，[callback](#callback9)回调返回认证操作中的提示信息。 |  
    
## EventInfo<sup>(9+)</sup>    
表示认证过程中事件信息的类型。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| AuthResultInfo | 获取到的认证结果信息。 |  
| TipInfo | 认证过程中的提示信息。 |  
    
## AuthEvent<sup>(9+)</sup>    
认证接口的异步回调对象。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### callback<sup>(9+)</sup>    
通过该回调获取认证结果信息或认证过程中的提示信息。  
 **调用形式：**     
- callback(result: EventInfo): void  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| result | EventInfo | true | 返回的认证结果信息或提示信息。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);  
let authType = userIAM_userAuth.UserAuthType.FACE;  
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;  
// 通过callback获取认证结果  
try {  
  let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);  
  auth.on('result', {  
    callback: (result: userIAM_userAuth.AuthResultInfo) => {  
      console.log('authV9 result ' + result.result);  
      console.log('authV9 token ' + result.token);  
      console.log('authV9 remainAttempts ' + result.remainAttempts);  
      console.log('authV9 lockoutDuration ' + result.lockoutDuration);  
    }  
  } as userIAM_userAuth.AuthEvent);  
  auth.start();  
  console.log('authV9 start success');  
} catch (error) {  
  console.log('authV9 error = ' + error);  
  // do error  
}  
// 通过callback获取认证过程中的提示信息  
try {  
  let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);  
  auth.on('tip', {  
    callback : (result : userIAM_userAuth.TipInfo) => {  
      switch (result.tip) {  
        case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:  
          // do something;  
        case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:  
          // do something;  
        default:  
          // do others  
      }  
    }  
  } as userIAM_userAuth.AuthEvent);  
  auth.start();  
  console.log('authV9 start success');  
} catch (error) {  
  console.log('authV9 error = ' + error);  
  // do error  
}  
    
```    
  
    
## AuthResultInfo<sup>(9+)</sup>    
表示认证结果信息。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(9+)</sup> | number | false | true | 认证结果。 |  
| token<sup>(9+)</sup> | Uint8Array | false | false | 用户身份认证通过的凭证。 |  
| remainAttempts<sup>(9+)</sup> | number | false | false | 剩余的认证尝试次数。 |  
| lockoutDuration<sup>(9+)</sup> | number | false | false | 认证操作的锁定时长，时间单位为毫秒ms。<span style="letter-spacing: 0px;">认证操作的锁定时长，时间单位为毫秒ms。</span> |  
    
## TipInfo<sup>(9+)</sup>    
表示认证过程中的提示信息。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| module<sup>(9+)</sup> | number | false | true | 发送提示信息的模块标识。 |  
| tip<sup>(9+)</sup> | number | false | true | 认证过程提示信息。 |  
    
## AuthInstance<sup>(deprecated)</sup>    
执行用户认证的对象。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.userIAM.userAuth.UserAuthInstance替代。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| on<sup>(deprecated)</sup> | (name: AuthEventKey, callback: AuthEvent) => void | false | true | 从API version 9 开始支持，从API version 10 开始废弃。<br>订阅指定类型的用户认证事件。 |  
| off<sup>(deprecated)</sup> | (name: AuthEventKey) => void | false | true | 从API version 9 开始支持，从API version 10 开始废弃。<br>取消订阅特定类型的认证事件。 |  
| start<sup>(deprecated)</sup> | () => void | false | true | 从API version 9 开始支持，从API version 10 开始废弃。需要权限：ohos.permission.ACCESS_BIOMETRIC<br>开始认证。 |  
| cancel<sup>(deprecated)</sup> | () => void | false | true | 从API version 9 开始支持，从API version 10 开始废弃。需要权限：ohos.permission.ACCESS_BIOMETRIC<br>取消认证。 |  
    
## getAvailableStatus<sup>(9+)</sup>    
查询指定类型和等级的认证能力是否支持。  
 **调用形式：**     
- getAvailableStatus(authType: UserAuthType, authTrustLevel: AuthTrustLevel): void  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType | UserAuthType | true | 认证类型。从 API version 11 开始支持PIN查询。 |  
| authTrustLevel | AuthTrustLevel | true | 认证信任等级。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
| 12500005 | The authentication type is not supported. |  
| 12500006 | The authentication trust level is not supported. |  
| 12500010 | The type of credential has not been enrolled. |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
try {  
  userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);  
  console.info('current auth trust level is supported');  
} catch (error) {  
  console.info('current auth trust level is not supported, error = ' + error);  
}  
    
```    
  
    
## getAuthInstance<sup>(deprecated)</sup>    
获取AuthInstance对象，用于执行用户身份认证。  
 **调用形式：**     
- getAuthInstance(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel): AuthInstance  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.userIAM.userAuth.getUserAuthInstance。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| challenge<sup>(deprecated)</sup> | Uint8Array | true | 挑战值，最大长度为32字节，可以传Uint8Array([])。 |  
| authType<sup>(deprecated)</sup> | UserAuthType | true | 认证类型，当前支持FACE和FINGERPRINT。 |  
| authTrustLevel<sup>(deprecated)</sup> | AuthTrustLevel | true | 认证信任等级。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AuthInstance | 认证器对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
| 12500005 | The authentication type is not supported. |  
| 12500006 | The authentication trust level is not supported. |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);  
let authType = userIAM_userAuth.UserAuthType.FACE;  
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;  
  
try {  
  let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);  
  console.info('let auth instance success');  
} catch (error) {  
  console.info('get auth instance success failed, error = ' + error);  
}  
    
```    
  
    
## AuthParam<sup>(10+)</sup>    
用户认证相关参数。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| challenge<sup>(10+)</sup> | Uint8Array | false | true | 挑战值，用来防重放攻击。最大长度为32字节，可传Uint8Array([])。 |  
| authType<sup>(10+)</sup> | UserAuthType[] | false | true | 认证类型列表，用来指定用户认证界面提供的认证方法。 |  
| authTrustLevel<sup>(10+)</sup> | AuthTrustLevel | false | true | 认证信任等级。 |  
    
## WidgetParam<sup>(10+)</sup>    
用户认证界面配置相关参数。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title<sup>(10+)</sup> | string | false | true | 用户认证界面的标题，最大长度为500字符。 |  
| navigationButtonText<sup>(10+)</sup> | string | false | false | 导航按键的说明文本，最大长度为60字符。仅在单指纹、单人脸场景下支持。 |  
    
## UserAuthResult<sup>(10+)</sup>    
用户认证结果。当认证结果为成功时，返回认证类型和认证通过的令牌信息。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(10+)</sup> | number | false | true | 用户认证结果。若结果为成功返回0，若失败返回相应错误码，错误码详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)。 |  
| token<sup>(10+)</sup> | Uint8Array | false | false | 当认证结果为成功时，返回认证通过的令牌信息。 |  
| authType<sup>(10+)</sup> | UserAuthType | false | false | 当认证结果为成功时，返回认证类型。 |  
    
## IAuthCallback<sup>(10+)</sup>    
返回认证结果的回调对象。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### onResult<sup>(10+)</sup>    
回调函数，返回认证结果。  
 **调用形式：**     
- onResult(result: UserAuthResult): void  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| result | UserAuthResult | true | 认证结果。 |  
    
 **示例代码：**   
```ts    
import userIAM_userAuth from '@ohos.userIAM.userAuth';  
  
let auth = new userIAM_userAuth.UserAuth();  
let challenge = new Uint8Array([]);  
auth.auth(challenge, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {  
  onResult: (result, extraInfo) => {  
    try {  
      console.info('auth onResult result = ' + result);  
      console.info('auth onResult extraInfo = ' + JSON.stringify(extraInfo));  
      if (result == userIAM_userAuth.ResultCode.SUCCESS) {  
        // 此处添加认证成功逻辑  
      }  else {  
        // 此处添加认证失败逻辑  
      }  
    } catch (e) {  
      console.info('auth onResult error = ' + e);  
    }  
  }  
});  
    
```    
  
    
## UserAuthInstance<sup>(10+)</sup>    
用于执行用户身份认证，并支持使用统一用户身份认证组件。使用以下接口前，都需要先通过[getUserAuthInstance](#getuserauthinstance10)方法获取UserAuthInstance对象。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### on('result')<sup>(10+)</sup>    
订阅用户身份认证结果。  
 **调用形式：**     
    
- on(type: 'result', callback: IAuthCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，表明该事件用来返回认证结果。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证接口的回调函数，用于返回认证结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const authParam : userAuth.AuthParam = {  
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),  
  authType: [userAuth.UserAuthType.PIN],  
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,  
};  
const widgetParam :userAuth.WidgetParam = {  
  title: '请输入密码',  
};  
try {  
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);  
  console.log('get userAuth instance success');  
  userAuthInstance.on('result', {  
    onResult (result) {  
      console.log('userAuthInstance callback result = ' + JSON.stringify(result));  
    }  
  });  
  console.log('auth on success');  
} catch (error) {  
  console.log('auth catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
### off('result')<sup>(10+)</sup>    
取消订阅用户身份认证结果。  
 **调用形式：**     
    
- off(type: 'result', callback?: IAuthCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，表明该事件用来返回认证结果。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证接口的回调函数，用于返回认证结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const authParam : userAuth.AuthParam = {  
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),  
  authType: [userAuth.UserAuthType.PIN],  
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,  
};  
const widgetParam :userAuth.WidgetParam = {  
  title: '请输入密码',  
};  
try {  
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);  
  console.log('get userAuth instance success');  
  userAuthInstance.off('result', {  
    onResult (result) {  
      console.log('auth off result: ' + JSON.stringify(result));  
    }  
  });  
  console.log('auth off success');  
} catch (error) {  
  console.log('auth catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
### start<sup>(10+)</sup>    
开始认证。  
 **调用形式：**     
- start(): void  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 401 | Incorrect parameters. |  
| 12500001 | Authentication failed. |  
| 12500002 | General operation error. |  
| 12500003 | The operation is canceled. |  
| 12500004 | The operation is time-out. |  
| 12500005 | The authentication type is not supported. |  
| 12500006 | The authentication trust level is not supported. |  
| 12500007 | The authentication task is busy. |  
| 12500009 | The authenticator is locked. |  
| 12500010 | The type of credential has not been enrolled. |  
| 12500011 | The authentication is canceled from widget's navigation button. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const authParam : userAuth.AuthParam = {  
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),  
  authType: [userAuth.UserAuthType.PIN],  
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,  
};  
const widgetParam :userAuth.WidgetParam = {  
  title: '请输入密码',  
};  
try {  
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);  
  console.log('get userAuth instance success');  
  userAuthInstance.start();  
  console.log('auth start success');  
} catch (error) {  
  console.log('auth catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
### cancel<sup>(10+)</sup>    
取消认证。  
 **调用形式：**     
- cancel(): void  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.ACCESS_BIOMETRIC    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const authParam : userAuth.AuthParam = {  
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),  
  authType: [userAuth.UserAuthType.PIN],  
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,  
};  
const widgetParam :userAuth.WidgetParam = {  
  title: '请输入密码',  
};  
try {  
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);  
  console.log('get userAuth instance success');  
  userAuthInstance.cancel();  
  console.log('auth cancel success');  
} catch (error) {  
  console.log('auth catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
## getUserAuthInstance<sup>(10+)</sup>    
获取[UserAuthInstance](#userauthinstance10)对象，用于执行用户身份认证，并支持使用统一用户身份认证组件。  
 **调用形式：**     
- getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance  
  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authParam | AuthParam | true | 用户认证相关参数。 |  
| widgetParam | WidgetParam | true | 用户认证界面配置相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UserAuthInstance | 支持用户界面的认证器对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
| 12500005 | The authentication type is not supported. |  
| 12500006 | The authentication trust level is not supported. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const authParam : userAuth.AuthParam = {  
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),  
  authType: [userAuth.UserAuthType.PIN],  
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,  
};  
const widgetParam :userAuth.WidgetParam = {  
  title: '请输入密码',  
};  
try {  
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);  
  console.log('get userAuth instance success');  
} catch (error) {  
  console.log('auth catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
## UserAuthResultCode<sup>(9+)</sup>    
表示返回码的枚举。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 12500000 | 执行成功。 |  
| FAIL | 12500001 | 认证失败。 |  
| GENERAL_ERROR | 12500002 | 操作通用错误。 |  
| CANCELED | 12500003 | 操作取消。 |  
| TIMEOUT | 12500004 | 操作超时。 |  
| TYPE_NOT_SUPPORT | 12500005 | 不支持的认证类型。 |  
| TRUST_LEVEL_NOT_SUPPORT | 12500006 | 不支持的认证等级。 |  
| BUSY | 12500007 | 忙碌状态。 |  
| LOCKED | 12500009 | 认证器已锁定。 |  
| NOT_ENROLLED | 12500010 | 用户未录入认证信息。 |  
| CANCELED_FROM_WIDGET<sup>(10+)</sup> | 12500011 | 当前的认证操作被用户从组件取消。返回这个错误码，表示使用应用自定义认证。 |  

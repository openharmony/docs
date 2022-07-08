# 用户认证

提供用户认证能力，可应用于设备解锁、支付、应用登录等身份认证场景。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## 完整示例

```js
// API version 8
import userIAM_userAuth from '@ohos.userIAM.userAuth';
let auth = new userIAM_userAuth.UserAuth();

export default {
    getVersion() {
        console.info("start get version");
        let version = this.auth.getVersion();
        console.info("auth version = " + version);
    },

    startAuth() {
        console.info("start auth");
        this.auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                try {
                    console.info("auth onResult result = " + result);
                    console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
                    if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                        // 此处添加认证成功逻辑
                    }  else {
                        // 此处添加认证失败逻辑
                    }
                } catch (e) {
                    console.info("auth onResult error = " + e);
                }
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                try {
                    console.info("auth onAcquireInfo module = " + module);
                    console.info("auth onAcquireInfo acquire = " + acquire);
                    console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
                } catch (e) {
                    console.info("auth onAcquireInfo error = " + e);
                }
            }
        });
    },

    checkAuthSupport() {
        console.info("start check auth support");
        let checkCode = this.auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
            console.info("check auth support success");
            // 此处添加支持指定类型认证的逻辑
        } else {
            console.error("check auth support fail, code = " + checkCode);
            // 此处添加不支持指定类型认证的逻辑
        }
    },

    cancelAuth() {
        console.info("start cancel auth");
        // contextId通过auth接口获取
        let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                console.info("auth onResult result = " + result);
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                console.info("auth onAcquireInfo module = " + module);
            }
        });
        let cancelCode = this.auth.cancel(contextId);
        if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```

```js
// API version 6
import userIAM_userAuth from '@ohos.userIAM.userAuth';

export default {
    startAuth() {
        console.info("start auth");
        let auth = userIAM_userAuth.getAuthenticator();
        auth.execute("FACE_ONLY", "S2").then((code)=>{
            console.info("auth success");
            // 此处添加认证成功逻辑
        }).catch((code)=>{
            console.error("auth fail, code = " + code);
            // 此处添加认证失败逻辑
        });
    }
}
```


## UserAuth<sup>8+</sup>

认证器的对象。

### constructor<sup>8+</sup>

constructor()

表示获取的认证器对象。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型                   | 说明                 |
| ---------------------- | -------------------- |
| [UserAuth](#userauth8) | UserAuth认证器对象。 |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  ```

### getVersion<sup>8+</sup>

getVersion() : number

表示获取的认证器版本信息。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 获取的认证器版本信息。 |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  let version = auth.getVersion();
  console.info("auth version = " + version);
  ```

### getAvailableStatus<sup>8+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

表示检查指定的认证等级的认证能力是否可用。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型，当前只支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证结果的信任等级。       |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 获取指定的认证等级的认证能力是否可用的检查结果，返回值参见[ResultCode](#resultcode8)。 |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  let checkCode = auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
  if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
      console.info("check auth support success");
      // 此处添加支持指定类型认证的逻辑
  } else {
      console.error("check auth support fail, code = " + checkCode);
      // 此处添加不支持指定类型认证的逻辑
  }
  ```

### auth<sup>8+</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

表示执行用户认证，使用callback方式作为异步方法。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                                     | 必填 | 说明                     |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | 是   | 挑战值，可以填null。     |
| authType       | [UserAuthType](#userauthtype8)           | 是   | 认证类型，当前支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | 是   | 信任等级。               |
| callback       | [IUserAuthCallback](#iuserauthcallback8) | 是   | 回调函数。               |

**返回值：**

| 类型       | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | ContextId，作为取消认证[cancelAuth](#cancelauth8)接口的入参。 |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
          try {
              console.info("auth onResult result = " + result);
              console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
              if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                  // 此处添加认证成功逻辑
              } else {
                  // 此处添加认证失败逻辑
              }
          } catch (e) {
              console.info("auth onResult error = " + e);
          }
      }
  });
  ```

### cancelAuth<sup>8+</sup>

cancelAuth(contextID : Uint8Array) : number

表示通过contextID取消本次认证操作。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型       | 必填 | 说明                                       |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | 是   | 上下文ID信息，通过[auth](#auth8)接口获得。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 取消本次认证操作的结果。 |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  // contextId可通过auth接口获取，此处直接定义
  let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);
  let cancelCode = auth.cancel(contextId);
  if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
      console.info("cancel auth success");
  } else {
      console.error("cancel auth fail");
  }
  ```

## IUserAuthCallback<sup>8+</sup>

认证过程中回调结果的对象。

### onResult<sup>8+</sup>

onResult: (result : number, extraInfo : AuthResult) => void

表示在认证操作中，获取认证结果。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                       | 必填 | 说明                                                         |
| --------- | -------------------------- | ---- | ------------------------------------------------------------ |
| result    | number                     | 是   | 认证结果，参见[ResultCode](#resultcode8)。                   |
| extraInfo | [AuthResult](#authresult8) | 是   | 扩展信息，不同情况下的具体信息，<br/>如果身份验证通过，则在extrainfo中返回用户认证令牌，<br/>如果身份验证失败，则在extrainfo中返回剩余的用户认证次数，<br/>如果身份验证执行器被锁定，则在extrainfo中返回冻结时间。 |


**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
          try {
              console.info("auth onResult result = " + result);
              console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
              if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                  // 此处添加认证成功逻辑
              }  else {
                  // 此处添加认证失败逻辑
              }
          } catch (e) {
              console.info("auth onResult error = " + e);
          }
      },

      onAcquireInfo: (module, acquire, extraInfo) => {
          try {
              console.info("auth onAcquireInfo module = " + module);
              console.info("auth onAcquireInfo acquire = " + acquire);
              console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
          } catch (e) {
              console.info("auth onAcquireInfo error = " + e);
          }
      }
  });
  ```

### onAcquireInfo<sup>8+</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

表示在认证过程中，获取提示码信息，非必须实现。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | 是   | 认证执行器的类型。             |
| acquire   | number | 是   | 认证执行器认证过程的交互信息。 |
| extraInfo | any    | 是   | 预留字段。                     |

**示例：**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
          try {
              console.info("auth onResult result = " + result);
              console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
              if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                  // 此处添加认证成功逻辑
              }  else {
                  // 此处添加认证失败逻辑
              }
          } catch (e) {
              console.info("auth onResult error = " + e);
          }
      },

      onAcquireInfo: (module, acquire, extraInfo) => {
          try {
              console.info("auth onAcquireInfo module = " + module);
              console.info("auth onAcquireInfo acquire = " + acquire);
              console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
          } catch (e) {
              console.info("auth onAcquireInfo error = " + e);
          }
      }
  });
  ```

## AuthResult<sup>8+</sup>

表示认证结果的对象。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 参数类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| token        | Uint8Array | 否   | 身份认证令牌。       |
| remainTimes  | number     | 否   | 剩余的认证操作次数。 |
| freezingTime | number     | 否   | 认证操作的冻结时间。 |

## ResultCode<sup>8+</sup>

表示执行结果的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                    | 默认值 | 描述                 |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | 执行成功。           |
| FAIL                    | 1      | 执行失败。           |
| GENERAL_ERROR           | 2      | 操作通用错误。       |
| CANCELED                | 3      | 操作取消。           |
| TIMEOUT                 | 4      | 操作超时。           |
| TYPE_NOT_SUPPORT        | 5      | 不支持的认证类型。   |
| TRUST_LEVEL_NOT_SUPPORT | 6      | 不支持的认证等级。   |
| BUSY                    | 7      | 忙碌状态。           |
| INVALID_PARAMETERS      | 8      | 无效参数。           |
| LOCKED                  | 9      | 认证器已锁定。       |
| NOT_ENROLLED            | 10     | 用户未录入认证信息。 |


## FaceTips<sup>8+</sup>

表示人脸认证过程中提示码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                          | 默认值 | 描述                                 |
| ----------------------------- | ------ | ------------------------------------ |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1      | 光线太强，获取的图像太亮。           |
| FACE_AUTH_TIP_TOO_DARK        | 2      | 光线太暗，获取的图像太暗。           |
| FACE_AUTH_TIP_TOO_CLOSE       | 3      | 人脸距离设备过近。                   |
| FACE_AUTH_TIP_TOO_FAR         | 4      | 人脸距离设备过远。                   |
| FACE_AUTH_TIP_TOO_HIGH        | 5      | 设备太高，仅获取到人脸上部。         |
| FACE_AUTH_TIP_TOO_LOW         | 6      | 设备太低，仅获取到人脸下部。         |
| FACE_AUTH_TIP_TOO_RIGHT       | 7      | 设备太靠右，仅获取到人脸右部。       |
| FACE_AUTH_TIP_TOO_LEFT        | 8      | 设备太靠左，仅获取到人脸左部。       |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9      | 在图像采集过程中，用户人脸移动太快。 |
| FACE_AUTH_TIP_POOR_GAZE       | 10     | 没有正视摄像头。                     |
| FACE_AUTH_TIP_NOT_DETECTED    | 11     | 没有检测到人脸信息。                 |


## FingerprintTips<sup>8+</sup>

表示指纹认证过程中提示码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                              | 默认值 | 描述                                               |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | 获取的指纹图像良好。                               |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | 由于传感器上可疑或检测到的污垢，指纹图像噪音过大。 |
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | 由于检测到的情况，指纹图像噪声太大，无法处理。     |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | 仅检测到部分指纹图像。                             |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | 快速移动，指纹图像不完整。                         |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | 缺少运动，指纹图像无法读取。                       |


## UserAuthType<sup>8+</sup>

表示身份认证的凭据类型枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称        | 默认值 | 描述       |
| ----------- | ------ | ---------- |
| FACE        | 2      | 人脸认证。 |
| FINGERPRINT | 4      | 指纹认证。 |

## AuthTrustLevel<sup>8+</sup>

表示认证结果的信任等级枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称 | 默认值 | 描述                      |
| ---- | ------ | ------------------------- |
| ATL1 | 10000  | 认证结果的信任等级级别1。 |
| ATL2 | 20000  | 认证结果的信任等级级别2。 |
| ATL3 | 30000  | 认证结果的信任等级级别3。 |
| ATL4 | 40000  | 认证结果的信任等级级别4。 |

## userIAM_userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

> **说明：**
> 从 API Version 8 开始废弃，建议使用[constructor](#constructor8)替代。

获取Authenticator对象，用于执行用户身份认证。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**
| 类型                                      | 说明         |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | 认证器对象。 |

**示例：**
  ```js
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[UserAuth](#userauth8)替代。

认证器对象。


### execute<sup>(deprecated)</sup>

execute(type: string, level: string, callback: AsyncCallback&lt;number&gt;): void

> **说明：**
> 从 API Version 8 开始废弃，建议使用[auth](#auth8)替代。

执行用户认证，使用callback方式作为异步方法。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | 是   | 认证类型，当前只支持FACE_ONLY。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
| level    | string                      | 是   | 安全级别，对应认证的安全级别，有效值为S1（最低）、S2、S3、S4（最高）。<br/>具备3D人脸识别能力的设备支持S3及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持S2及以下安全级别的认证。 |
| callback | AsyncCallback&lt;number&gt; | 否   | 回调函数。                                                   |

 callback返回值：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 表示认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**
  ```js
  authenticator.execute("FACE_ONLY", "S2", (code)=>{
      if (code == userIAM_userAuth.AuthenticationResult.SUCCESS) {
          console.info("auth success");
          return;
      }
      console.error("auth fail, code = " + code);
  })
  ```


### execute<sup>(deprecated)</sup>

execute(type:string, level:string): Promise&lt;number&gt;

> **说明：**
> 从 API Version 8 开始废弃，建议使用[auth](#auth8)替代。

执行用户认证，使用promise方式作为异步方法。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**
| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 认证类型，当前只支持FACE_ONLY。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
| level  | string | 是   | 安全级别，对应认证的安全级别，有效值为S1（最低）、S2、S3、S4（最高）。<br/>具备3D人脸识别能力的设备支持S3及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持S2及以下安全级别的认证。 |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回携带一个number的Promise。number&nbsp;为认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**

```js
let authenticator = userIAM_userAuth.getAuthenticator();
authenticator.execute("FACE_ONLY", "S2").then((code)=>{
    console.info("auth success");
}).catch((code)=>{
    console.error("auth fail, code = " + code);
});
```

## AuthenticationResult<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[ResultCode](#resultcode8)替代。

表示认证结果的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称               | 默认值 | 描述                       |
| ------------------ | ------ | -------------------------- |
| NO_SUPPORT         | -1     | 设备不支持当前的认证方式。 |
| SUCCESS            | 0      | 认证成功。                 |
| COMPARE_FAILURE    | 1      | 比对失败。                 |
| CANCELED           | 2      | 用户取消认证。             |
| TIMEOUT            | 3      | 认证超时。                 |
| CAMERA_FAIL        | 4      | 开启相机失败。             |
| BUSY               | 5      | 认证服务忙，请稍后重试。   |
| INVALID_PARAMETERS | 6      | 认证参数无效。             |
| LOCKED             | 7      | 认证失败次数过多，已锁定。 |
| NOT_ENROLLED       | 8      | 未录入认证凭据。           |
| GENERAL_ERROR      | 100    | 其他错误。                 |
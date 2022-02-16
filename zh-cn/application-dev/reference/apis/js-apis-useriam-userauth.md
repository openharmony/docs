# 用户认证

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## 系统能力

SystemCapability.UserIAM.UserAuth

## 权限列表

ohos.permission.ACCESS_BIOMETRIC


## 完整示例

```
import userIAM_userAuth from '@ohos.userIAM.userAuth';

export default {
    startAuth() {
        console.info("start auth");
        let tipCallback = (tip)=>{
            console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
                tip.tipEvent + ") info(" + tip.tipInfo + ")");
            // 此处添加提示信息显示逻辑
        };
        let auth = userIAM_userAuth.getAuthenticator();
        auth.on("tip", tipCallback);
        auth.execute("FACE_ONLY", "S2").then((code)=>{
            auth.off("tip", tipCallback);
            console.info("auth success");
            // 此处添加认证成功逻辑
        }).catch((code)=>{
            auth.off("tip", tipCallback);
            console.error("auth fail, code = " + code);
            // 此处添加认证失败逻辑
        });
    },

    checkAuthSupport() {
        console.info("start check auth support");
        let auth = userIAM_userAuth.getAuthenticator();
        let checkCode = auth.checkAvailability("FACE_ONLY", "S2");
        if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
            console.info("check auth support success");
            // 此处添加支持指定类型认证的逻辑
        } else {
            console.error("check auth support fail, code = " + checkCode);
            // 此处添加不支持指定类型认证的逻辑
        }
    },

    cancelAuth() {
        console.info("start cancel auth");
        let auth = userIAM_userAuth.getAuthenticator();
        let cancelCode = auth.cancel();
        if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```


## userIAM_userAuth.getAuthenticator

getAuthenticator(): Authenticator

获取Authenticator对象，用于执行用户身份认证。<sup>6+</sup>

获取Authenticator对象，用于检测设备身份认证能力、执行和取消用户身份认证，获取认证过程中的提示信息。<sup>7+</sup>

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [Authenticator](#authenticator) | 认证器对象。 |

- 示例：
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```


## Authenticator

认证器对象。


### execute

execute(type: string, level: string, callback: AsyncCallback&lt;number&gt;): void

执行用户认证，使用callback方式作为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 认证类型，当前只支持FACE_ONLY。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
  | level | string | 是 | 安全级别，对应认证的安全级别，有效值为S1（最低）、S2、S3、S4（最高）。<br/>具备3D人脸识别能力的设备支持S3及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持S2及以下安全级别的认证。 |
  | callback | AsyncCallback&lt;number&gt; | 否 | 回调函数。 |

  callback返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 表示认证结果，参见[AuthenticationResult](#authenticationresult)。 |

- 示例：
  ```
  authenticator.execute("FACE_ONLY", "S2", (code)=>{
      if (code == userIAM_userAuth.AuthenticationResult.SUCCESS) {
          console.info("auth success");
          return;
      }
      console.error("auth fail, code = " + code);
  })
  ```


### execute

execute(type:string, level:string): Promise&lt;number&gt;

执行用户认证，使用promise方式作为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 认证类型，当前只支持FACE_ONLY。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
  | level | string | 是 | 安全级别，对应认证的安全级别，有效值为S1（最低）、S2、S3、S4（最高）。<br/>具备3D人脸识别能力的设备支持S3及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持S2及以下安全级别的认证。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回携带一个number的Promise。number&nbsp;为认证结果，参见[AuthenticationResult](#authenticationresult)。 |

- 示例
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  authenticator.execute("FACE_ONLY", "S2").then((code)=>{
      authenticator.off("tip", tipCallback);
      console.info("auth success");
  }).catch((code)=>{
      authenticator.off("tip", tipCallback);
      console.error("auth fail, code = " + code);
  });
  ```


### cancel<sup>7+</sup>

cancel(): number

取消当前的认证流程。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回取消当前认证的结果，参见[Result](#result7)。 |

- 示例：
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  let cancelCode = authenticator.cancel();
  if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
      console.info("cancel auth success");
  } else {
      console.error("cancel auth fail");
  }
  ```


### checkAvailability<sup>7+</sup>

checkAvailability(type: AuthType, level: SecureLevel): number

根据指定的认证类型、安全等级，检测当前设备是否支持相应的认证能力。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 认证类型，当前只支持FACE_ONLY。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
  | level | string | 是 | 安全级别，对应认证的安全级别，有效值为S1（最低）、S2、S3、S4（最高）。<br/>具备3D人脸识别能力的设备支持S3及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持S2及以下安全级别的认证。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回检测当前设备认证能力的结果，参见[CheckAvailabilityResult](#checkavailabilityresult7)。 |

- 示例：
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  let checkCode = authenticator.checkAvailability("FACE_ONLY", "S2");
  if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
      console.info("check auth support success");
  } else {
      console.error("check auth support fail, code = " + checkCode);
  }
  ```


### on<sup>7+</sup>

on(type: "tip", callback: Callback&lt;Tip&gt;) : void;

订阅指定类型的事件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，当前只支持"tip"。在认证服务发送提示信息给调用者时，会触发此事件。 |
  | callback | Callback&lt;Tip&gt; | 是 | 事件发生时的回调，当前只支持以Tip为参数的回调函数。 |

- 示例：
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  let tipCallback = (tip)=>{
      console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode +") event(" +
          tip.tipEvent + ") info(" + tip.tipInfo + ")");
  };
  authenticator.on("tip", tipCallback);
  ```


### off<sup>7+</sup>

off(type: "tip", callback?: Callback&lt;Tip&gt;) : void;

取消订阅指定类型的事件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 事件类型，当前只支持"tip"。 |
  | callback | Callback&lt;Tip&gt; | 否 | 取消订阅的回调函数，当前只支持以Tip为参数的回调函数。如未指定此参数，同事件类型的所有回调都会被取消。 |

- 示例：
  ```
  let authenticator = userIAM_userAuth.getAuthenticator();
  let tipCallback = (tip)=>{
      console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
          tip.tipEvent + ") info(" + tip.tipInfo + ")");
  };
  // 取消订阅指定回调
  authenticator.off("tip", tipCallback);
  
  // 取消订阅所有回调
  authenticator.off("tip");
  ```


## AuthenticationResult

表示认证结果的枚举。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| NO_SUPPORT | -1 | 设备不支持当前的认证方式。 |
| SUCCESS | 0 | 认证成功。 |
| COMPARE_FAILURE | 1 | 比对失败。 |
| CANCELED | 2 | 用户取消认证。 |
| TIMEOUT | 3 | 认证超时。 |
| CAMERA_FAIL | 4 | 开启相机失败。 |
| BUSY | 5 | 认证服务忙，请稍后重试。 |
| INVALID_PARAMETERS | 6 | 认证参数无效。 |
| LOCKED | 7 | 认证失败次数过多，已锁定。 |
| NOT_ENROLLED | 8 | 未录入认证凭据。 |
| GENERAL_ERROR | 100 | 其他错误。 |


## Tip<sup>7+</sup>

表示认证过程中提示信息的对象。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errorCode | number | 是 | 是否成功获取到提示信息，参考[Result](#result7)。 |
| tipEvent | number | 是 | 认证提示事件,&nbsp;参考[TipEvent](#tipevent7)。当前只支持RESULT、ACQUIRE。 |
| tipCode | number | 是 | 认证提示的事件提示码。<br/>-&nbsp;当tipEvent为RESULT时，含义为认证结果，参考[AuthenticationResult](#authenticationresult)。<br/>-&nbsp;当tipEvent为ACQUIRE时，含义为提示信息，参考[TipCode](#tipcode7)。 |
| tipInfo | string | 是 | 认证提示的事件提示码的描述信息。 |


## Result<sup>7+</sup>

表示执行结果的枚举。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| SUCCESS | 0 | 执行成功。 |
| FAILED | 1 | 执行失败。 |


## CheckAvailabilityResult<sup>7+</sup>

表示检测设备认证能力结果的枚举。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| SUPPORTED | 0 | 设备支持指定的认证类型和认证安全等级。 |
| AUTH_TYPE_NOT_SUPPORT | 1 | 设备不支持指定的认证类型。 |
| SECURE_LEVEL_NOT_SUPPORT | 2 | 设备不支持指定的认证安全等级。 |
| DISTRIBUTED_AUTH_NOT_SUPPORT | 3 | 设备不支持分布式认证。 |
| NOT_ENROLLED | 4 | 设备中认证凭据未录入。 |
| PARAM_NUM_ERROR | 5 | 参数个数错误。 |


## TipEvent<sup>7+</sup>

表示认证过程中提示事件的枚举。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| RESULT | 1 | 录入或认证结果。 |
| CANCEL | 2 | 录入或认证取消。 |
| ACQUIRE | 3 | 录入或认证过程中提示。 |
| BUSY | 4 | 录入或认证功能被占用。 |
| OUT_OF_MEM | 5 | 内存不足。 |
| FACE_ID | 6 | 人脸认证凭据索引号。 |


## TipCode<sup>7+</sup>

表示认证过程中提示码的枚举。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| FACE_AUTH_TIP_TOO_BRIGHT | 1 | 光线太强，获取的图像太亮。 |
| FACE_AUTH_TIP_TOO_DARK | 2 | 光线太暗，获取的图像太暗。 |
| FACE_AUTH_TIP_TOO_CLOSE | 3 | 人脸距离设备过近。 |
| FACE_AUTH_TIP_TOO_FAR | 4 | 人脸距离设备过远。 |
| FACE_AUTH_TIP_TOO_HIGH | 5 | 设备太高，仅获取到的人脸上部。 |
| FACE_AUTH_TIP_TOO_LOW | 6 | 设备太低，仅获取到的人脸下部。 |
| FACE_AUTH_TIP_TOO_RIGHT | 7 | 设备太靠右，仅获取到的人脸右部。 |
| FACE_AUTH_TIP_TOO_LEFT | 8 | 设备太靠左，仅获取到的人脸左部。 |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9 | 在图像采集过程中，用户人脸移动太快。 |
| FACE_AUTH_TIP_POOR_GAZE | 10 | 没有正视摄像头。 |
| FACE_AUTH_TIP_NOT_DETECTED | 11 | 没有检测到人脸信息。 |

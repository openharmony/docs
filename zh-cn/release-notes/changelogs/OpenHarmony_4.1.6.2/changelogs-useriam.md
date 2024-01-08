# 用户IAM子系统废弃说明

## cl.useriam.1 AuthEvent接口废弃

**访问级别**

公开接口

**废弃原因**

为了统一用户在系统上的身份认证体验，所有应用在进行用户身份认证时，需要使用更换为新方案，使用系统提供的用户身份认证控件。原有方案相关接口废弃。

**废弃影响**

该变更为兼容性变更。后续应用一样可以继续使用。

**API Level**

8

**废弃发生版本**

从OpenHarmony SDK 4.1.6.2开始。

**废弃的接口/组件**

| 接口声明 | 废弃说明 | 替换接口 |
|---------|----------|--------|
| interface AuthEvent | 不再支持，请使用新接口IAuthCallback | interface IAuthCallback |
| callback(result: EventInfo): void | 不再支持，请使用新接口IAuthCallback中的onResult | method onResult |
| field AuthEventKey | 不再支持 | 无 |
| type EventInfo | 不再支持，请使用新接口IAuthCallback中的UserAuthResult | interface UserAuthResult |
| interface AuthResultInfo | 不再支持 | 无 |
| field result | 不再支持，请使用UserAuthResult中的result | field result |
| field token | 不再支持，请使用UserAuthResult中的token | field token |
| field remainAttempts | 不再支持 | 无 |
| field lockoutDuration | 不再支持 | 无 |
| interface TipInfo | 不再支持 | 无 |
| field module | 不再支持 | 无 |
| field tip | 不再支持 | 无 |
| enum_class FingerprintTips | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_TOO_SLOW | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_TOO_FAST | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_PARTIAL | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_INSUFFICIENT | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_DIRTY | 不再支持 | 无 |
| enum_instance FINGERPRINT_AUTH_TIP_GOOD | 不再支持 | 无 |
| enum_class FaceTips | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_BRIGHT | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_DARK | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_CLOSE | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_FAR | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_HIGH | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_LOW | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_RIGHT | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_LEFT | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_TOO_MUCH_MOTION | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_POOR_GAZE | 不再支持 | 无 |
| enum_instance FACE_AUTH_TIP_NOT_DETECTED | 不再支持 | 无 |

**适配指导**

以AuthEvent接口中的callback回调函数替换为IAuthCallback的onResult回调函数为例，示例代码如下：

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('result', {
    // API9通过AuthEvent接口中的callback回调函数获取认证结果
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
  console.error('authV9 error = ' + error);
  // do error
}
```

```js
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
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onResult获取到认证结果。
  userAuthInstance.on('result', {
    // API10通过IAuthCallback的onResult回调函数获取认证结果
    onResult (result) {
      console.log('userAuthInstance callback result = ' + JSON.stringify(result));
    }
  });
  console.log('auth on success');
} catch (error) {
  console.error('auth catch error: ' + JSON.stringify(error));
}
```

更多接口的示例代码可参考[用户认证API文档](../../../application-dev/reference/apis/js-apis-useriam-userauth.md)和[人脸认证API文档](../../../application-dev/reference/apis/js-apis-useriam-faceauth.md)。

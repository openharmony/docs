# @ohos.userIAM.userAccessCtrl (用户访问控制)(系统接口)

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

提供用户访问控制能力，用于应用查询和配置用户身份认证策略、校验用户身份认证结果。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { userAccessCtrl } from '@kit.UserAuthenticationKit';
```

## AuthTokenType

认证令牌类型。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**系统接口**：此接口为系统接口。

| 名称                      | 值   | 说明       |
| ------------------------ | ---- | ---------- |
| TOKEN_TYPE_LOCAL_AUTH    | 0    | 身份验证令牌基于本地认证结果签发。 |
| TOKEN_TYPE_LOCAL_RESIGN  | 1    | 身份验证令牌基于复用的身份认证结果重新签发。 |
| TOKEN_TYPE_COAUTH        | 2    | 身份验证令牌基于多个设备协同认证结果签发。 |

## AuthToken

表示校验通过返回解析的AuthToken数据结果。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**系统接口**：此接口为系统接口。

| 名称           | 类型                               | 只读 | 可选 | 说明                                       |
| -------------- | ---------------------------------- | ----- | ----- |------------------------------------------------------------ |
| challenge | Uint8Array | 否 | 否 |认证随机挑战。|
| authTrustLevel | [userAuth.AuthTrustLevel](js-apis-useriam-userauth.md#authtrustlevel8) | 否 | 否 |认证信任等级。|
| authType | [userAuth.UserAuthType](js-apis-useriam-userauth.md#userauthtype8) | 否 | 否  |身份认证的凭据类型。|
| tokenType | [AuthTokenType](#authtokentype) | 否 | 否 |认证令牌类型。|
| userId | number | 否 | 否  |用户ID。|
| timeInterval | bigint | 否  | 否  |自AuthToken签发至当前的时间，以毫秒表示。|
| secureUid | bigint    | 否  | 是  |安全用户ID。|
| enrolledId | bigint   | 否  | 是  |凭据注册ID。|
| credentialId | bigint | 否  | 是  |匹配上的凭据ID。|


## userAccessCtrl.verifyAuthToken

verifyAuthToken(authToken: Uint8Array, allowableDuration: number): Promise\<AuthToken>

验证认证令牌。

**需要权限**：ohos.permission.USE_USER_ACCESS_MANAGER

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                        | 必填 | 说明       |
| ---------- | --------------------------- | ---- | ---------- |
| authToken | Uint8Array | 是   | 需要被验证的AuthToken。最大长度为1024。 |
| allowableDuration  | number  | 是   | 从AuthToken签发起允许认证的时间间隔，以毫秒表示。有效时长值应大于0，最大值为86400000毫秒。 |

**返回值：**

| 类型                                      | 说明         |
| ----------------------------------------- | ------------ |
| Promise\<[AuthToken](#authtoken)> | Promise对象，返回解析后的AuthToken。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 201      | Permission denied.        |
| 202      | Permission denied. Called by non-system application. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.    |
| 12500002 | General operation error.                |
| 12500015 | AuthToken integrity check failed.     |
| 12500016 | AuthToken has expired.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAccessCtrl } from '@kit.UserAuthenticationKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const allowableDuration: number = 5000;
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };

  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onResult获取到认证结果。
  userAuthInstance.on('result', {
    onResult (result) {
        if (!result.token) {
            console.error('userAuthInstance callback result.token is null');
            return;
        }
        // 发起 AuthToken 验证请求。
        userAccessCtrl.verifyAuthToken(result.token, allowableDuration)
            .then((retAuthToken: userAccessCtrl.AuthToken) => {
                Object.keys(retAuthToken).forEach((key) => {
                    console.info(`retAuthToken key:${key}, value:${retAuthToken[key]}`);
                })
            }).catch ((error: BusinessError) => {
                console.error(`verify authToken error. Code is ${error?.code}, message is ${error?.message}`);
            })
    }
  });
  console.info('auth on success');
  // 启动认证。
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```
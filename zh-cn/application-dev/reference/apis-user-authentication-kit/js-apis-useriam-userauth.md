# @ohos.userIAM.userAuth (用户认证)

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

提供用户认证能力，应用于设备解锁、支付、应用登录等场景。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
```

## 常量

| 名称        | 值   | 说明       |
| ----------- | ---- | ---------- |
| MAX_ALLOWABLE_REUSE_DURATION<sup>12+</sup>    | 300000   | 复用解锁认证结果最大有效时长，值为300000毫秒。<br/> **系统能力：** SystemCapability.UserIAM.UserAuth.Core <br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## UserAuthTipCode<sup>20+</sup>

表示身份认证中间状态。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                | 值   | 说明       |
| -----------        | ---- | ---------- |
| COMPARE_FAILURE    | 1    | 认证失败。 |
| TIMEOUT            | 2    | 认证超时。 |
| TEMPORARILY_LOCKED | 3    | 临时冻结。 |
| PERMANENTLY_LOCKED | 4    | 永久冻结。 |
| WIDGET_LOADED      | 5    | 身份认证界面加载完毕。 |
| WIDGET_RELEASED    | 6    | 当前的身份认证界面退出，切换其他认证界面或身份认证控件关闭。 |
| COMPARE_FAILURE_WITH_FROZEN    | 7    | 认证失败并触发了认证冻结。 |

## EnrolledState<sup>12+</sup>

用户注册凭据的状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 类型    | 只读 | 可选 | 说明                 |
| ------------ | ---------- | ---- | ---- | -------------------- |
| credentialDigest       | number | 否   |  否 | 注册的凭据摘要，在凭据增加时随机生成。|
| credentialCount        | number | 否   |  否 | 注册的凭据数量。       |

## ReuseMode<sup>12+</sup>

复用解锁认证结果的模式。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称        | 值   | 说明       |
| ----------- | ---- | ---------- |
| AUTH_TYPE_RELEVANT    | 1   | 与认证类型相关，只有当设备解锁认证结果在有效时间内，并且设备解锁的认证类型匹配上本次认证指定认证类型之一时，可以复用该结果。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| AUTH_TYPE_IRRELEVANT  | 2   | 与认证类型无关，设备解锁认证结果在有效时间内，可以重复使用。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CALLER_IRRELEVANT_AUTH_TYPE_RELEVANT<sup>14+</sup>    | 3   | 与认证类型相关，任意身份认证（包括设备解锁）结果在有效时间内，并且身份认证的认证类型匹配上本次认证指定认证类型之一时，可以复用该结果。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| CALLER_IRRELEVANT_AUTH_TYPE_IRRELEVANT<sup>14+</sup>  | 4   | 与认证类型无关，任意身份认证（包括设备解锁）结果在有效时间内，可以重复使用。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |

## ReuseUnlockResult<sup>12+</sup>

复用解锁认证结果。
> **说明**：
>
> 如果身份认证解锁（包括设备解锁）后，在有效时间内凭据发生了变化，身份认证的结果依然可以复用，认证结果中返回当前实际的EnrolledState。若复用认证结果时，之前认证时所使用的身份认证凭据已经被删除，如果删除的是人脸、指纹，则认证结果依然可以复用，只是返回的EnrolledState中credentialCount和credentialDigest均为0；如果删除的是锁屏口令，则此次复用会失败。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| reuseMode        | [ReuseMode](#reusemode12) | 是   | 复用解锁认证结果的模式。       |
| reuseDuration    | number | 是   | 允许复用解锁认证结果的有效时长，有效时长的值应大于0，最大值为[MAX_ALLOWABLE_REUSE_DURATION](#常量)。 |

## userAuth.getEnrolledState<sup>12+</sup>

getEnrolledState(authType : UserAuthType): EnrolledState

查询凭据注册的状态，以检测用户注册凭据的变更。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型。|

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| [EnrolledState](#enrolledstate12) | 当查询成功时，返回值为用户注册凭据的状态。|

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500010 | The type of credential has not been enrolled. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enrolledState = userAuth.getEnrolledState(userAuth.UserAuthType.FACE);
  console.info(`get current enrolled state success, enrolledState = ${JSON.stringify(enrolledState)}`);
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`get current enrolled state failed, Code is ${err?.code}, message is ${err?.message}`);
}
```

## AuthParam<sup>10+</sup>

用户认证相关参数。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称           | 类型                               | 必填 | 说明                                                         |
| -------------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| challenge      | Uint8Array                         | 是   | 随机挑战值，可用于防重放攻击。最大长度为32字节，可传Uint8Array([])。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| authType       | [UserAuthType](#userauthtype8)[]   | 是   | 认证类型列表，用来指定用户认证界面提供的认证方法。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 期望达到的认证可信等级。典型操作需要的身份认证可写等级，以及身份认证可信等级的划分请参见[认证可信等级划分原则](../../security/UserAuthenticationKit/user-authentication-overview.md#生物认证可信等级划分原则)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| reuseUnlockResult<sup>12+</sup> | [ReuseUnlockResult](#reuseunlockresult12) | 否   |表示可以复用解锁认证的结果。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| skipLockedBiometricAuth<sup>20+</sup> | boolean | 否   | 是否跳过已禁用的认证方式自动切换至其它方式的认证，true表示已跳过，false表示未跳过，若无可切换的认证方式则关闭控件，返回认证冻结错误码。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## WidgetParam<sup>10+</sup>

用户认证界面配置相关参数。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                 | 类型                                | 必填 | 说明                                                         |
| -------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| title                | string                              | 是   | 用户认证界面的标题，建议传入认证目的，例如用于支付、登录应用等，不支持传空字串，最大长度为500字符。 <br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| navigationButtonText | string                              | 否   | 导航按键的说明文本，最大长度为60字符。在单指纹、单人脸场景下支持，从API 18开始，增加支持人脸+指纹场景。 <br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| uiContext<sup>18+</sup>            | Context               | 否   | 以模应用方式显示身份认证对话框，仅支持在2in1设备上使用，如果没有此参数或其他类型的设备，身份认证对话框将以模系统方式显示。 <br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|

## UserAuthResult<sup>10+</sup>

用户认证结果。认证成功时，返回认证类型和认证成功的令牌信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称     | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| result   | number                         | 是   | 用户认证结果。若成功返回SUCCESS，若失败返回相应错误码，参见[UserAuthResultCode](#userauthresultcode9)。 |
| token    | Uint8Array                     | 否   | 认证成功时，返回认证成功的令牌信息。                  |
| authType | [UserAuthType](#userauthtype8) | 否   | 认证成功时，返回认证类型。                           |
| enrolledState<sup>12+</sup> | [EnrolledState](#enrolledstate12) | 否   |  认证成功时，返回注册凭据的状态。|

## IAuthCallback<sup>10+</sup>

返回认证结果的回调对象。

### onResult<sup>10+</sup>

onResult(result: UserAuthResult): void

回调函数，返回认证结果。认证成功时，可以通过UserAuthResult获取到认证成功的令牌信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| result | [UserAuthResult](#userauthresult10) | 是   | 认证结果。 |

**示例1：**

发起用户认证，采用认证可信等级≥ATL3的锁屏口令认证，获取认证结果：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**示例2：**

发起用户认证，采用认证可信等级≥ATL3的锁屏口令+认证类型相关+复用设备解锁最大有效时长认证，获取认证结果。

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

let reuseUnlockResult: userAuth.ReuseUnlockResult = {
  reuseMode: userAuth.ReuseMode.AUTH_TYPE_RELEVANT,
  reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
}
try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    reuseUnlockResult: reuseUnlockResult,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onResult获取到认证结果。
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**示例3：**

发起用户认证，采用认证可信等级≥ATL3的锁屏口令+任意应用认证类型相关+复用任意应用最大有效时长认证，获取认证结果。

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

let reuseUnlockResult: userAuth.ReuseUnlockResult = {
  reuseMode: userAuth.ReuseMode.CALLER_IRRELEVANT_AUTH_TYPE_RELEVANT,
  reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
}
try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    reuseUnlockResult: reuseUnlockResult,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onResult获取到认证结果。
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## AuthTipInfo<sup>20+</sup>

用户认证中间状态。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称     | 类型                                  | 只读 | 可选 | 说明                              |
| -------- | ------------------------------------ | ---- | ---- | ------------------------------------ |
| tipType | [UserAuthType](#userauthtype8)        |  否  |  否  | 中间状态对应的认证类型。 |
| tipCode | [UserAuthTipCode](#userauthtipcode20) |  否  |  否  | 中间状态值。|

## AuthTipCallback<sup>20+</sup>

type AuthTipCallback = (authTipInfo: AuthTipInfo) => void

回调函数，返回认证中间状态。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | -----------------------------------| ---- | ---------- |
| authTipInfo | [AuthTipInfo](#authtipinfo20)   | 是   | 认证中间状态。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onAuthTip获取到认证中间状态。
  userAuthInstance.on('authTip', (authTipInfo: userAuth.AuthTipInfo) => {
    console.info(`userAuthInstance callback authTipInfo = ${JSON.stringify(authTipInfo)}`);
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## UserAuthInstance<sup>10+</sup>

用于执行用户身份认证，并支持使用统一用户身份认证控件。
使用以下接口前，需先通过[getUserAuthInstance](#userauthgetuserauthinstance10)方法获取UserAuthInstance对象。

### on<sup>10+</sup>

on(type: 'result', callback: IAuthCallback): void

订阅用户身份认证的结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                       |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| type     | 'result'                          | 是   | 订阅事件类型，表明该事件用来返回认证结果。 |
| callback | [IAuthCallback](#iauthcallback10) | 是   | 认证接口的回调函数，用于返回认证结果。     |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**示例1：**

以模系统方式进行用户身份认证。

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**示例2：**

以模应用方式进行用户身份认证。

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

@Entry
@Component
struct Index {
  modelApplicationAuth(): void {
    try {
      const rand = cryptoFramework.createRandom();
      const len: number = 16;
      let randData: Uint8Array | null = null;
      let retryCount = 0;
      while(retryCount < 3){
        randData = rand?.generateRandomSync(len)?.data;
        if(randData){
          break;
        }
        retryCount++;
      }
      if(!randData){
        return;
      }
      const authParam: userAuth.AuthParam = {
        challenge: randData,
        authType: [userAuth.UserAuthType.PIN],
        authTrustLevel: userAuth.AuthTrustLevel.ATL3,
      };
      const uiContext: UIContext = this.getUIContext();
      const context: Context | undefined = uiContext.getHostContext();
      const widgetParam: userAuth.WidgetParam = {
        title: '请输入密码',
        uiContext: context,
      };
      const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
      console.info('get userAuth instance success');
      // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onResult获取到认证结果。
      userAuthInstance.on('result', {
        onResult (result) {
          console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
        }
      });
      console.info('auth on success');
      userAuthInstance.start();
      console.info('auth start success');
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
    }
  }

  build() {
    Column() {
      Button('start auth')
        .onClick(() => {
          this.modelApplicationAuth();
        })
    }
  }
}
```

### off<sup>10+</sup>

off(type: 'result', callback?: IAuthCallback): void

取消订阅用户身份认证的结果。

> **说明**：
> 
> 需要使用已经成功订阅事件的[UserAuthInstance](#userauthinstance10)对象调用该接口进行取消订阅。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                       |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| type     | 'result'                          | 是   | 订阅事件类型，表明该事件用来返回认证结果。 |
| callback | [IAuthCallback](#iauthcallback10) | 否   | 认证接口的回调函数，用于返回认证结果。     |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
  userAuthInstance.off('result', {
    onResult (result) {
      console.info(`auth off result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth off success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### start<sup>10+</sup>

start(): void

开始认证。

> **说明：**
> 每个UserAuthInstance只能进行一次认证，需要再次认证时，必须重新获取UserAuthInstance。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC 或 ohos.permission.USER_AUTH_FROM_BACKGROUND（仅向系统应用开放）

从API 20开始，仅系统应用可以通过申请ohos.permission.USER_AUTH_FROM_BACKGROUND，在后台发起认证。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                                         |
| -------- | ------------------------------------------------ |
| 201      | Permission denied. Possible causes:1.No permission to access biometric. 2.No permission to start authentication from background.|
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 12500002 | General operation error.                         |
| 12500003 | Authentication canceled.                         |
| 12500005 | The authentication type is not supported.        |
| 12500006 | The authentication trust level is not supported. |
| 12500009 | Authentication is locked out.                    |
| 12500010 | The type of credential has not been enrolled.    |
| 12500011 | Switched to the customized authentication process.   |
| 12500013 | Operation failed because of PIN expired. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### cancel<sup>10+</sup>

cancel(): void

取消认证。

> **说明**：
>
> 此时UserAuthInstance必须是正在进行认证的对象。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 201      | Permission denied. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 12500002 | General operation error.        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  const authParam : userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能调用cancel()接口。
  userAuthInstance.start();
  console.info('auth start success');
  userAuthInstance.cancel();
  console.info('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### on<sup>20+</sup>

on(type: 'authTip', callback: AuthTipCallback): void

订阅身份认证中间状态。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型           | 必填 | 说明                                       |
| -------- | ------------- | ---- | ------------------------------------------ |
| type     | string        | 是   | 订阅事件类型，支持的事件为'authTip'，当[start()](#start10)调用完成，发起身份认证，触发该事件。 |
| callback | [AuthTipCallback](#authtipcallback20) | 是   | 认证接口的回调函数，用于返回认证中间状态。     |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 12500002 | General operation error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
  // 需要调用UserAuthInstance的start()接口，启动认证后，才能通过onAuthTip获取到认证中间状态。
  userAuthInstance.on('authTip', (authTipInfo: userAuth.AuthTipInfo) => {
    console.info(`userAuthInstance callback authTipInfo = ${JSON.stringify(authTipInfo)}`);
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### off<sup>20+</sup>

off(type: 'authTip', callback?: AuthTipCallback): void

取消订阅用户身份认证中间状态。

> **说明**：
> 
> 需要使用已经成功订阅事件的[UserAuthInstance](#userauthinstance10)对象调用该接口进行取消订阅。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型           | 必填 | 说明                                       |
| -------- | ------------- | ---- | ------------------------------------------ |
| type     | string        | 是   | 取消订阅的事件类型，支持的事件为'authTip'，当[start()](#start10)调用完成，发起身份认证并调用[on()](#on20)订阅该事件后，调用该方法可取消订阅，不会再触发该事件。 |
| callback | [AuthTipCallback](#authtipcallback20) | 否   | 认证接口的回调函数，用于返回认证中间状态。 当不传该参数时默认值为调用[on()](#on20)接口时传递的参数值。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 12500002 | General operation error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
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
  userAuthInstance.off('authTip', (authTipInfo: userAuth.AuthTipInfo) => {
    console.info(`userAuthInstance callback authTipInfo = ${JSON.stringify(authTipInfo)}`);
  });
  console.info('auth off success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## userAuth.getUserAuthInstance<sup>10+</sup>

getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance

获取[UserAuthInstance](#userauthinstance10)对象，执行用户身份认证，并支持使用统一用户身份认证控件。

> **说明：**
> 每个UserAuthInstance只能进行一次认证，需要再次认证时，必须重新获取UserAuthInstance。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名      | 类型                          | 必填 | 说明                       |
| ----------- | ----------------------------- | ---- | -------------------------- |
| authParam   | [AuthParam](#authparam10)      | 是   | 用户认证相关参数。         |
| widgetParam | [WidgetParam](#widgetparam10) | 是   | 用户认证界面配置相关参数。 |

**返回值：**

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| [UserAuthInstance](#userauthinstance10) | 支持用户界面的认证器对象。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息                                         |
| -------- | ------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.   |
| 12500002 | General operation error.                         |
| 12500005 | The authentication type is not supported.        |
| 12500006 | The authentication trust level is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  let randData: Uint8Array | null = null;
  let retryCount = 0;
  while(retryCount < 3){
    randData = rand?.generateRandomSync(len)?.data;
    if(randData){
      break;
    }
    retryCount++;
  }
  if(!randData){
    return;
  }
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## AuthResultInfo<sup>(deprecated)</sup>

表示认证结果信息，用于描述认证结果。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| result        | number | 是   | 认证结果。       |
| token        | Uint8Array | 否   | 用户身份认证通过的凭证。 |
| remainAttempts  | number     | 否   | 剩余的认证尝试次数。 |
| lockoutDuration | number     | 否   | 认证操作的锁定时长，时间单位为毫秒ms。 |

## TipInfo<sup>(deprecated)</sup>

表示认证过程中的提示信息，用于提供认证过程的反馈。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core。

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| module        | number | 是   | 发送提示信息的模块标识。       |
| tip        | number | 是   | 认证过程提示信息。       |

## EventInfo<sup>(deprecated)</sup>

type EventInfo = AuthResultInfo | TipInfo

表示认证过程中事件信息的类型。

该类型为下表类型取值中的联合类型。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃，请使用[UserAuthResult](#userauthresult10)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core。

| 类型    | 说明                       |
| --------- | ----------------------- |
| [AuthResultInfo](#authresultinfodeprecated)    | 获取到的认证结果信息。  |
| [TipInfo](#tipinfodeprecated)    | 认证过程中的提示信息。      |

## AuthEventKey<sup>(deprecated)</sup>

type AuthEventKey = 'result' | 'tip'

表示认证事件类型的关键字，作为[on](#ondeprecated)接口的参数。

该类型为下表类型取值中的联合类型。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core。

| 类型       | 说明                    |
| ---------- | ----------------------- |
| 'result' | [on](#ondeprecated)接口第一个参数为"result"时，[callback](#callbackdeprecated)回调返回认证的结果信息。 |
| 'tip'    | [on](#ondeprecated)接口第一个参数为"tip"时，[callback](#callbackdeprecated)回调返回认证操作中的提示信息。 |

## AuthEvent<sup>(deprecated)</sup>

认证接口的异步回调对象。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃，请使用[IAuthCallback](#iauthcallback10)替代。

### callback<sup>(deprecated)</sup>

callback(result : EventInfo) : void

通过该回调获取认证结果信息或认证过程中的提示信息。

> **说明：**
> 从 API version 9 开始支持，从 API version 11 开始废弃，请使用[onResult](#onresult10)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                       | 必填 | 说明                           |
| --------- | -------------------------- | ---- | ------------------------------ |
| result    | [EventInfo](#eventinfodeprecated)     | 是   | 返回的认证结果信息或提示信息。  |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
// 通过callback获取认证结果。
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error.
}
// 通过callback获取认证过程中的提示信息。
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('tip', {
    callback : (result : userAuth.TipInfo) => {
      switch (result.tip) {
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
          // do something;
          break;
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
          // do something;
          break;
        default:
          // do others.
      }
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error.
}
```

## AuthInstance<sup>(deprecated)</sup>

执行用户认证的对象。

> **说明：**
> 从 API version 9 开始支持，从 API version 10 开始废弃，请使用[UserAuthInstance](#userauthinstance10)替代。

### on<sup>(deprecated)</sup>

on : (name : AuthEventKey, callback : AuthEvent) => void

订阅指定类型的用户认证事件。

> **说明：**
> - 从 API version 9 开始支持，从 API version 10 开始废弃。
> - 使用获取到的[AuthInstance](#authinstancedeprecated)对象调用该接口进行订阅。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                        | 必填 | 说明                       |
| --------- | -------------------------- | ---- | ------------------------- |
| name  | [AuthEventKey](#autheventkeydeprecated) | 是   | 表示认证事件类型，取值为"result"时，回调函数返回认证结果；取值为"tip"时，回调函数返回认证过程中的提示信息。 |
| callback  | [AuthEvent](#autheventdeprecated)   | 是   | 认证接口的回调函数，用于返回认证结果或认证过程中的提示信息。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Parameter error. |
| 12500002 | General operation error. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  // 订阅认证结果。
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  });
  // 订阅认证过程中的提示信息。
  auth.on('tip', {
    callback : (result : userAuth.TipInfo) => {
      switch (result.tip) {
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
          // do something;
          break;
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
          // do something;
          break;
        default:
          // do others.
      }
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error.
}
```

### off<sup>(deprecated)</sup>

off : (name : AuthEventKey) => void

取消订阅特定类型的认证事件。

> **说明：**
> - 从 API version 9 开始支持，从 API version 10 开始废弃。
> - 需要使用已经成功订阅事件的[AuthInstance](#authinstancedeprecated)对象调用该接口进行取消订阅。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称    | 类型                        | 必填 | 说明                       |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | [AuthEventKey](#autheventkeydeprecated)      | 是   | 表示认证事件类型，取值为"result"时，取消订阅认证结果；取值为"tip"时，取消订阅认证过程中的提示信息。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Parameter error. |
| 12500002 | General operation error. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  // 订阅认证结果。
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  });
  // 取消订阅结果。
  auth.off('result');
  console.info('cancel subscribe authentication event success');
} catch (error) {
  console.error(`cancel subscribe authentication event failed, error = ${error}`);
  // do error.
}
```

### start<sup>(deprecated)</sup>

start : () => void

开始认证。

> **说明：**
> - 从 API version 9 开始支持，从 API version 10 开始废弃。
> - 使用获取到的[AuthInstance](#authinstancedeprecated)对象调用该接口进行认证。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission denied. |
| 401 | Parameter error. |
| 12500001 | Authentication failed. |
| 12500002 | General operation error. |
| 12500003 | The operation is canceled. |
| 12500004 | The operation is time-out.  |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500007 | The authentication task is busy. |
| 12500009 | The authenticator is locked. |
| 12500010 | The type of credential has not been enrolled. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.start();
  console.info('authV9 start auth success');
} catch (error) {
  console.error(`authV9 start auth failed, error = ${error}`);
}
```

### cancel<sup>(deprecated)</sup>

cancel : () => void

取消认证。

> **说明：**
>
> - 从 API version 9 开始支持，从 API version 10 开始废弃。
> - 使用获取到的[AuthInstance](#authinstancedeprecated)对象调用该接口进行取消认证，此[AuthInstance](#authinstancedeprecated)需要是正在进行认证的对象。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission denied. |
| 401 | Parameter error. |
| 12500002 | General operation error. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.cancel();
  console.info('cancel auth success');
} catch (error) {
  console.error(`cancel auth failed, error = ${error}`);
}
```

## userAuth.getAuthInstance<sup>(deprecated)</sup>

getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel): AuthInstance

获取AuthInstance对象，用于执行用户身份认证。

> **说明：**
>
> - 从 API version 9 开始支持，从 API version 10 开始废弃，请使用[getUserAuthInstance](#userauthgetuserauthinstance10)替代。
> - 每个AuthInstance只能进行一次认证，若需要再次进行认证则需重新获取AuthInstance。


**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                                     | 必填 | 说明                     |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | 是   | 挑战值，最大长度为32字节，可以传Uint8Array([])。 |
| authType       | [UserAuthType](#userauthtype8)           | 是   | 认证类型，当前支持FACE和FINGERPRINT。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | 是   | 认证信任等级。               |

**返回值：**

| 类型                                    | 说明         |
| --------------------------------------- | ------------ |
| [AuthInstance](#authinstancedeprecated) | 认证器对象。 |

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Parameter error. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  console.info('let auth instance success');
} catch (error) {
  console.error(`get auth instance success failed, error = ${error}`);
}
```

## userAuth.getAvailableStatus<sup>9+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void

查询指定类型和等级的认证能力是否支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型。从 API version 11 开始支持PIN查询。|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证信任等级。       |

> **错误码返回顺序说明：**
>
> - 如果未注册对应执行器，系统不支持该认证能力，需返回12500005。
> - 如果已注册对应执行器，功能未禁用，但认证安全等级低于业务指定时，需返回12500006。
> - 如果已注册对应执行器，功能未禁用，但用户未注册凭据时，需返回12500010。
> - 如果已注册对应执行器，功能未禁用，但密码过期时，需返回12500013。

> **注意：**
> - 若用户注册的锁屏口令是4位PIN时，其认证可信等级为ATL3，调用该接口查询是否支持ATL4级别的密码认证时，需返回12500010。

**错误码：**

以下错误码的详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500010 | The type of credential has not been enrolled. |
| 12500013 | Operation failed because of PIN expired. |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  userAuth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL3);
  console.info('current auth trust level is supported');
} catch (error) {
  console.error(`current auth trust level is not supported, error = ${error}`);
}
```

## UserAuthResultCode<sup>9+</sup>

表示返回码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                    |   值   | 说明                 |
| ----------------------- | ------ | -------------------- |
| SUCCESS                          | 12500000      | 执行成功。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| FAIL                             | 12500001      | 认证失败。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| GENERAL_ERROR                    | 12500002      | 操作通用错误。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CANCELED                         | 12500003      | 认证取消。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| TIMEOUT                          | 12500004      | 认证超时。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| TYPE_NOT_SUPPORT                 | 12500005      | 认证类型不支持。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| TRUST_LEVEL_NOT_SUPPORT          | 12500006      | 认证等级不支持。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| BUSY                             | 12500007      | 系统繁忙。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| INVALID_PARAMETERS<sup>20+</sup> | 12500008      | 参数校验失败。<br/> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。  |
| LOCKED                           | 12500009      | 认证器已锁定。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |
| NOT_ENROLLED                     | 12500010      | 用户未录入指定的系统身份认证凭据。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CANCELED_FROM_WIDGET<sup>10+</sup> | 12500011 | 用户取消了系统认证方式，选择应用自定义认证。需调用者拉起自定义认证界面。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PIN_EXPIRED<sup>12+</sup> | 12500013 | 当前的认证操作执行失败。返回这个错误码，表示系统锁屏口令过期。<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## UserAuth<sup>(deprecated)</sup>

认证器对象。

### constructor<sup>(deprecated)</sup>

constructor()

创建认证器对象。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，请使用[getAuthInstance](#userauthgetauthinstancedeprecated)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

获取认证器的版本信息。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 认证器版本信息。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let version = auth.getVersion();
console.info(`auth version = ${version}`);
```

### getAvailableStatus<sup>(deprecated)</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

查询指定类型和等级的认证能力是否支持。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，请使用[getAvailableStatus](#userauthgetavailablestatus9)替代。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型，当前支持FACE和FINGERPRINT。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证信任等级。       |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 查询结果，结果为SUCCESS时表示支持，其他返回值参见[ResultCode](#resultcodedeprecated)。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let checkCode = auth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1);
if (checkCode == userAuth.ResultCode.SUCCESS) {
  console.info('check auth support success');
} else {
  console.error(`check auth support fail, code = ${checkCode}`);
}
```

### auth<sup>(deprecated)</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

执行用户认证，使用回调函数返回结果。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[start](#startdeprecated)代替。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                                     | 必填 | 说明                     |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | 是   | 挑战值，可以传Uint8Array([])。 |
| authType       | [UserAuthType](#userauthtype8)           | 是   | 认证类型，当前支持FACE和FINGERPRINT。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | 是   | 认证信任等级。             |
| callback       | [IUserAuthCallback](#iuserauthcallbackdeprecated) | 是   | 回调函数。        |

**返回值：**

| 类型       | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | ContextId，作为取消认证[cancelAuth](#cancelauthdeprecated)接口的入参。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // 此处添加认证成功逻辑。
      } else {
        // 此处添加认证失败逻辑。
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  }
});
```

### cancelAuth<sup>(deprecated)</sup>

cancelAuth(contextID : Uint8Array) : number

表示通过contextID取消本次认证。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[cancel](#canceldeprecated)代替。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型       | 必填 | 说明                                       |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | 是   | 上下文的标识，通过[auth](#authdeprecated)接口获取。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 取消认证的结果，结果为SUCCESS时表示取消成功，其他返回值参见[ResultCode](#resultcodedeprecated)。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

// contextId可通过auth接口获取，此处直接定义。
let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);
let auth = new userAuth.UserAuth();
let cancelCode = auth.cancelAuth(contextId);
if (cancelCode == userAuth.ResultCode.SUCCESS) {
  console.info('cancel auth success');
} else {
  console.error('cancel auth fail');
}
```

## IUserAuthCallback<sup>(deprecated)</sup>

返回认证结果的回调对象。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[AuthEvent](#autheventdeprecated)代替。

### onResult<sup>(deprecated)</sup>

onResult: (result : number, extraInfo : AuthResult) => void

回调函数，返回认证结果。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[callback](#callbackdeprecated)代替。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                       | 必填 | 说明        |
| --------- | -------------------------- | ---- | ------------------------------------------------ |
| result    | number           | 是   | 认证结果，参见[ResultCode](#resultcodedeprecated)。 |
| extraInfo | [AuthResult](#authresultdeprecated) | 是   | 扩展信息，不同情况下的具体信息，<br/>如果身份验证通过，则在extraInfo中返回用户认证令牌，<br/>如果身份验证失败，则在extraInfo中返回剩余的用户认证次数，<br/>如果身份验证执行器被锁定，则在extraInfo中返回冻结时间。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // 此处添加认证成功逻辑。
      }  else {
        // 此处添加认证失败逻辑。
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  }
});
```

### onAcquireInfo<sup>(deprecated)</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

回调函数，返回认证过程中的提示信息，非必须实现。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[callback](#callbackdeprecated)代替。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | 是   | 发送提示信息的模块标识。             |
| acquire   | number | 是   | 认证执过程中的提示信息。 |
| extraInfo | any    | 是   | 预留字段。                     |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // 此处添加认证成功逻辑。
      }  else {
        // 此处添加认证失败逻辑。
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  },
  onAcquireInfo: (module, acquire, extraInfo : userAuth.AuthResult) => {
    try {
      console.info(`auth onAcquireInfo module = ${module}`);
      console.info(`auth onAcquireInfo acquire = ${acquire}`);
      console.info(`auth onAcquireInfo extraInfo = ${JSON.stringify(extraInfo)}`);
    } catch (error) {
      console.error(`auth onAcquireInfo error = ${error}`);
    }
  }
});
```

## AuthResult<sup>(deprecated)</sup>

表示认证结果的对象。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[AuthResultInfo](#authresultinfodeprecated)代替。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------|
| token        | Uint8Array | 否   | 认证成功的令牌信息。 |
| remainTimes  | number     | 否   | 剩余的认证操作次数。 |
| freezingTime | number     | 否   | 认证操作的冻结时间。 |

## ResultCode<sup>(deprecated)</sup>

表示返回码的枚举。

> **说明：**
> 从 API version 9 开始废弃，建议使用[UserAuthResultCode](#userauthresultcode9)代替。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                    | 值 | 说明                 |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | 执行成功。           |
| FAIL                    | 1      | 认证失败。           |
| GENERAL_ERROR           | 2      | 操作通用错误。       |
| CANCELED                | 3      | 操作取消。           |
| TIMEOUT                 | 4      | 操作超时。           |
| TYPE_NOT_SUPPORT        | 5      | 不支持的认证类型。   |
| TRUST_LEVEL_NOT_SUPPORT | 6      | 不支持的认证等级。   |
| BUSY                    | 7      | 忙碌状态。           |
| INVALID_PARAMETERS      | 8      | 无效参数。           |
| LOCKED                  | 9      | 认证器已锁定。       |
| NOT_ENROLLED            | 10     | 用户未录入认证信息。 |

## FaceTips<sup>(deprecated)</sup>

表示人脸认证过程中提示码的枚举。

> **说明：**
> 从 API version 8 开始支持，从 API version 11 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                          |   值   |    说明                             |
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


## FingerprintTips<sup>(deprecated)</sup>

表示指纹认证过程中提示码的枚举。

> **说明：**
> 从 API version 8 开始支持，从 API version 11 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                              |   值   | 说明                                               |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | 获取的指纹图像良好。                               |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | 由于传感器上可疑或检测到的污垢，指纹图像噪音过大。 |
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | 由于检测到的情况，指纹图像噪声太大，无法处理。     |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | 仅检测到部分指纹图像。                             |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | 快速移动，指纹图像不完整。                         |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | 缺少运动，指纹图像无法读取。                       |


## UserAuthType<sup>8+</sup>

表示身份认证的凭据类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称        | 值   | 说明       |
| ----------- | ---- | ---------- |
| PIN<sup>10+</sup>         | 1    | 口令认证。 |
| FACE        | 2    | 人脸认证。 |
| FINGERPRINT | 4    | 指纹认证。 |

## AuthTrustLevel<sup>8+</sup>

表示认证结果的信任等级枚举。

典型场景及举例可参考[认证可信等级划分原则](../../security/UserAuthenticationKit/user-authentication-overview.md#生物认证可信等级划分原则)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称 | 值    | 说明                                                         |
| ---- | ----- | ------------------------------------------------------------ |
| ATL1 | 10000 | 认证结果的信任等级级别1，表示该认证方案能够识别用户个体，具备一定的活体检测能力。适用于业务风控、一般个人数据查询等场景。 |
| ATL2 | 20000 | 认证结果的信任等级级别2，表示该认证方案能够精确识别用户个体，具备一定的活体检测能力。适用于维持设备解锁状态、应用登录等场景。|
| ATL3 | 30000 | 认证结果的信任等级级别3，表示该认证方案能够精确识别用户个体，具备较强的活体检测能力。适用于设备解锁等场景。|
| ATL4 | 40000 | 认证结果的信任等级级别4，表示该认证方案能够高精度的识别用户个体，具备很强的活体检测能力。适用于小额支付等场景。|

## SecureLevel<sup>(deprecated)</sup>

type SecureLevel = string

表示认证的安全级别。

**原子化服务API：** 从 API version 6 开始支持，从 API version 8 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| string | 表示类型为字符，认证的安全级别包括：`'S1'` \| `'S2'`\|`'S3'`\|`'S4'`。 <br/>\- `'S1'`：认证结果的信任等级级别1，代表该认证方案能够识别用户个体，有一定的活体检测能力。常用的业务场景有业务风控、一般个人数据查询等。 <br/>\- `'S2'`：认证结果的信任等级级别2，代表该认证方案能够精确识别用户个体，有一定的活体检测能力。常用的业务场景有维持设备解锁状态，应用登录等。 <br/>\- `'S3'`：认证结果的信任等级级别3，代表该认证方案能够精确识别用户个体，有较强的活体检测能力。常用的业务场景有设备解锁等。 <br/>\- `'S4'`：认证结果的信任等级级别4，代表该认证方案能够高精度的识别用户个体，有很强的活体检测能力。常用的业务场景有小额支付等。 |

## AuthType<sup>(deprecated)</sup>

type AuthType = string

表示认证类型。

**原子化服务API：** 从 API version 6 开始支持，从 API version 8 开始废弃。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| string  | 表示认证类型为字符，认证类型包括：`'ALL'`\|`'FACE_ONLY'`。<br/>\- `'ALL'`：预留参数，当前版本暂不支持ALL类型的认证。<br/>\- `'FACE_ONLY'`：人脸认证。 |

## userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

获取Authenticator对象，用于执行用户身份认证。

> **说明：**
> 从 API version 8 开始废弃，建议使用[constructor](#constructordeprecated)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型                                      | 说明         |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | 认证器对象。 |

**示例：**
  ```ts
  import { userAuth } from '@kit.UserAuthenticationKit';
  
  let authenticator = userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

认证器对象。

> **说明：**
> 从 API version 8 开始废弃，建议使用[UserAuth](#userauthdeprecated)替代。

### execute<sup>(deprecated)</sup>

execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void

执行用户认证，使用callback方式作为异步方法。

> **说明：**
> 从 API version 8 开始废弃，建议使用[auth](#authdeprecated)替代。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                                                                    |
| -------- | --------------------------- | ---- |-----------------------------------------------------------------------------------------------------------------------|
| type     | AuthType                      | 是   | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数。当前版本暂不支持ALL类型的认证。                                                                 |
| level    | SecureLevel  | 是   | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。number表示认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let authenticator = userAuth.getAuthenticator();
authenticator.execute('FACE_ONLY', 'S2', (error, code)=>{
  if (code === userAuth.ResultCode.SUCCESS) {
    console.info('auth success');
    return;
  }
  console.error(`auth fail, code = ${code}`);
});
```


### execute<sup>(deprecated)</sup>

execute(type : AuthType, level : SecureLevel): Promise&lt;number&gt;

执行用户认证，使用promise方式作为异步方法。

> **说明：**
> 从 API version 8 开始废弃，建议使用[auth](#authdeprecated)替代。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                                                                    |
| ------ | ------ | ---- |-----------------------------------------------------------------------------------------------------------------------|
| type   | AuthType | 是   | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数。当前版本暂不支持ALL类型的认证。                                                                 |
| level  | SecureLevel | 是   | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回携带一个number的Promise。number&nbsp;为认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  let authenticator = userAuth.getAuthenticator();
  authenticator.execute('FACE_ONLY', 'S2').then((code)=>{
    console.info('auth success');
  })
} catch (error) {
  console.error(`auth fail, code = ${error}`);
}
```

## AuthenticationResult<sup>(deprecated)</sup>

表示认证结果的枚举。

> **说明：**
> 从 API version 8 开始废弃，建议使用[ResultCode](#resultcodedeprecated)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称               |   值   | 说明                       |
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


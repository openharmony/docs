# 用户身份认证访问控制开发指导

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

场景介绍及相关概念说明请参考[用户身份认证访问控制简介](huks-identity-authentication-overview.md)。

## 开发步骤

### 生成密钥

指定指纹访问控制类型及相关属性。

生成或导入密钥时，在密钥属性集中需指定三个参数：用户认证类型[HuksUserAuthType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksuserauthtype9)、授权访问类型[HuksAuthAccessType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthaccesstype9)、挑战值类型[HuksChallengeType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukschallengetype9)。

```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

/*
 * 确定密钥别名和封装密钥属性参数集。
 */
let keyAlias = 'test_sm4_key_alias';
let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    // 指定密钥身份认证的类型：指纹。
    tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
    value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
  }, {
    // 指定密钥安全授权的类型（失效类型）：新录入生物特征（指纹）后无效。
    tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
    value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
  }, {
    // 指定挑战值的类型：默认类型。
    tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
    value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
  }];

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

/*
 * 生成密钥。
 */
async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`promise: enter generateKeyItem`);
  try {
    await huks.generateKeyItem(keyAlias, huksOptions)
      .then(() => {
        console.info(`promise: generateKeyItem success`);
      }).catch((error: BusinessError) => {
        console.error(`promise: generateKeyItem failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid`);
  }
}

async function TestGenKeyForFingerprintAccessControl() {
  await generateKeyItem(keyAlias, huksOptions);
}
```

### 传入认证令牌

发起指纹认证获取认证令牌，进行数据操作。
   
```ts
/*
 * 以下以SM4 128密钥为例。
 */
import { huks } from '@kit.UniversalKeystoreKit';
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from "@kit.BasicServicesKit";
import { cryptoFramework } from '@kit.CryptoArchitectureKit'

/*
 * 确定密钥别名和封装密钥属性参数集。
 */
let IV = cryptoFramework.createRandom().generateRandomSync(16).data;
let srcKeyAlias = 'test_sm4_key_alias';
let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
let handle: number;
let challenge: Uint8Array;
let fingerAuthToken: Uint8Array;
let finishOutData: Uint8Array;
let authType = userAuth.UserAuthType.FINGERPRINT;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
/* 集成生成密钥参数集&加密参数集。 */
let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: IV,
  }
];
/* 加密参数集。 */
let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

/* 初始化HUKS中的会话，获取挑战值。 */
async function initSession(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`promise: enter initSession`);
  try {
    await huks.initSession(keyAlias, huksOptions)
      .then((data) => {
        handle = data.handle;
        if (data.challenge != undefined) {
          challenge = data.challenge as Uint8Array;
        }
        console.info(`promise: initSession success`);
      }).catch((error: BusinessError) => {
        console.error(`promise: initSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: initSession input arg invalid`);
  }
}

/* 调用UserIAM拉起指纹认证，触发HUKS的访问控制流程。 */
function userIAMAuthFinger(huksChallenge: Uint8Array) {
  // 获取认证对象。
  let authTypeList: userAuth.UserAuthType[] = [authType];
  const authParam: userAuth.AuthParam = {
    challenge: huksChallenge,
    authType: authTypeList,
    authTrustLevel: userAuth.AuthTrustLevel.ATL1
  };
  const widgetParam: userAuth.WidgetParam = {
    title: '请输入密码',
  };
  let auth: userAuth.UserAuthInstance;
  let err: BusinessError;
  try {
    auth = userAuth.getUserAuthInstance(authParam, widgetParam);
    console.info("get auth instance success");
  } catch (error) {
    err = error as BusinessError;
    console.error(`get auth instance failed, errCode : ${err.code}, errMsg : ${err.message}`);
    return;
  }
  // 订阅认证结果。
  try {
    auth.on("result", {
      onResult(result) {
        console.info(`[HUKS] -> [IAM]  userAuthInstance callback result =
          ${result.result}, ${result.token}, ${result.authType}, ${result.enrolledState}`);
        fingerAuthToken = result.token;
      }
    });
    console.log("subscribe authentication event success");
  } catch (error) {
    err = error as BusinessError;
    console.error(`subscribe authentication event failed, errCode : ${err.code}, errMsg : ${err.message}`);
  }
  // 开始认证。
  try {
    auth.start();
    console.info("authV9 start auth success");
  } catch (error) {
    err = error as BusinessError;
    console.error(`authV9 start auth failed, errCode : ${err.code}, errMsg : ${err.message}`);
  }
}

async function updateSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array) {
  console.info(`enter promise doUpdate`);
  try {
    await huks.updateSession(handle, huksOptions, token)
      .then((data) => {
        let outData = data.outData as Uint8Array;
        console.info(`promise: updateSession success, data = ${Uint8ArrayToString(outData)}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: updateSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: updateSession input arg invalid`);
  }
}

async function finishSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array) {
  console.info(`enter promise doFinish`);
  try {
    await huks.finishSession(handle, huksOptions, token)
      .then((data) => {
        finishOutData = data.outData as Uint8Array;
        console.info(`promise: finishSession success, data = ${Uint8ArrayToString(finishOutData)}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: finishSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: finishSession input arg invalid`);
  }
}

/* 进行数据操作。 */
async function testSm4Cipher() {
  huksOptions.inData = StringToUint8Array(cipherInData);
  /* 传入认证令牌。 */
  await updateSession(handle, huksOptions, fingerAuthToken);
  /* 传入认证令牌。 */
  await finishSession(handle, huksOptions, fingerAuthToken);
  if (Uint8ArrayToString(finishOutData) == cipherInData) {
    console.info('test finish encrypt error ');
  } else {
    console.info('test finish encrypt success');
  }
}

async function testAuthControl() {
  /* 初始化密钥会话获取挑战值。 */
  await initSession(srcKeyAlias, huksOptions);
  /* 调用userIAM进行身份认证。 */
  /* 需要在超时10秒之前完成指纹认证。 */
  userIAMAuthFinger(challenge);
  setTimeout(() => {
    testSm4Cipher();
  }, 10 * 1000);
}
```
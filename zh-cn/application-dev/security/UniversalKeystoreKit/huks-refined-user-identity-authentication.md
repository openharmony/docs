# 细粒度用户身份认证访问控制开发指导

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

细粒度用户身份认证访问控制是基于已有用户身份认证访问控制的扩展，提供了基于生物特征和锁屏密码二次身份认证的细粒度访问控制能力，允许设置密钥在加密、解密、签名、验签、密钥协商、密钥派生的单个或多个场景时是否需要进行身份验证。

比如，业务需要使用HUKS密钥加密保存账号密码信息等数据，要求在加密的时候不进行指纹等身份认证，解密的时候需要进行指纹等身份认证，这时就需要依赖HUKS提供细粒度的二次身份认证访问控制机制。

使用该功能仅需在密钥生成阶段，通过额外指定用于细粒度用户身份认证访问控制的HuksTag：HUKS_TAG_KEY_AUTH_PURPOSE，来指定在某种算法用途的情况下需要使用用户身份认证访问控制能力。

> **说明：**
> 对于对称加解密场景，仅AES/CBC、AES/GCM、SM4/CBC模式支持细粒度访问控制。

## 开发步骤

### 生成密钥
指定指纹类型的访问控制及相关属性，指定HUKS_TAG_KEY_AUTH_PURPOSE值。
   
```ts
import { huks } from "@kit.UniversalKeystoreKit";
import { BusinessError } from "@kit.BasicServicesKit";

/*
 * 确定密钥别名和封装密钥属性参数集。
 */
let keyAlias = 'test_sm4_key_alias';
let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
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
    tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
    value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
    value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
  }, {
    tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
    value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }
];
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

### 使用密钥
加密时不需要用户身份认证访问控制，解密时需要进行用户身份认证访问控制。
   
```ts
import { huks } from "@kit.UniversalKeystoreKit";
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from "@kit.BasicServicesKit";
import { cryptoFramework } from '@kit.CryptoArchitectureKit'

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

/*
 * 确定密钥别名和封装密钥属性参数集。
 */
let keyAlias = 'test_sm4_key_alias';
let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string'; // 明文数据。
let IV = cryptoFramework.createRandom().generateRandomSync(16).data;
let handle = 0;
let cipherText: Uint8Array; // 加密后的密文数据。
let fingerAuthToken: Uint8Array;
let challenge: Uint8Array;
let authType = userAuth.UserAuthType.FINGERPRINT;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
/* 加密参数集。 */
let propertiesEncrypt: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: IV,
  }
];
let encryptOptions: huks.HuksOptions = {
  properties: propertiesEncrypt,
  inData: new Uint8Array(new Array())
}
/* 解密参数集。 */
let propertiesDecrypt: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: IV,
  }
]
let decryptOptions: huks.HuksOptions = {
  properties: propertiesDecrypt,
  inData: new Uint8Array(new Array())
}

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

async function finishSession(handle: number, huksOptions: huks.HuksOptions, token?: Uint8Array) {
  console.info(`promise: enter finishSession`);
  try {
    await huks.finishSession(handle, huksOptions, token)
      .then((data) => {
        cipherText = data.outData as Uint8Array;
        console.info(`promise: finishSession success, data = ${Uint8ArrayToString(cipherText)}`);
      }).catch((error: BusinessError) => {
        console.error(`promise: finishSession failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: finishSession input arg invalid`);
  }
}

async function finishDecrypt(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array) {
  await finishSession(handle, huksOptions, token)
}

async function userIAMAuthFinger(huksChallenge: Uint8Array) {
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
    auth = await userAuth.getUserAuthInstance(authParam, widgetParam)
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
    console.info("subscribe authentication event success");
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
    console.info(`authV9 start auth failed, errCode : ${err.code}, errMsg : ${err.message}`);
  }
}

/* 1.加密时不需要用户身份认证访问控制。 */
async function testSm4Encrypt() {
  console.info(`enter testSm4Encrypt`);
  /* 初始化密钥会话获取挑战值。 */
  await initSession(keyAlias, encryptOptions);
  /* 加密。 */
  encryptOptions.inData = StringToUint8Array(cipherInData);
  await finishSession(handle, encryptOptions);
}

/* 2.解密时需要进行用户身份认证访问控制。 */
async function testSm4Decrypt() {
  console.info(`enter testSm4Decrypt`);
  /* 初始化密钥会话获取挑战值。 */
  await initSession(keyAlias, decryptOptions);
  /* 调用userIAM进行身份认证。 */
  userIAMAuthFinger(challenge);
  setTimeout(() => {
    /* 认证成功后进行解密，需要传入Auth获取到的authToken值。 */
    /* 需要在超时10秒之前完成指纹认证。 */
    decryptOptions.inData = cipherText;
    finishDecrypt(handle, decryptOptions, fingerAuthToken);
  }, 10 * 1000)
}

async function testSm4EncryptDecrypt() {
  await testSm4Encrypt();
  await testSm4Decrypt();
}
```
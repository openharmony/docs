# 用户身份认证访问控制开发指导

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--SE: @HighLowWorld-->
<!--TSE: @wxy1234564846-->

场景介绍及相关概念说明请参考[用户身份认证访问控制简介](huks-identity-authentication-overview.md)。

## 开发步骤

1. 生成密钥，指定指纹访问控制类型及相关属性。
   生成或导入密钥时，在密钥属性集中需指定三个参数：用户认证类型[HuksUserAuthType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksuserauthtype9)、授权访问类型[HuksAuthAccessType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthaccesstype9)、挑战值类型[HuksChallengeType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukschallengetype9)。

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/*
* 确定密钥别名和封装密钥属性参数集
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
},
  // 指定密钥身份认证的类型：指纹。
  {
    tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
    value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
  },
  // 指定密钥安全授权的类型（失效类型）：新录入生物特征（指纹）后无效。
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
    value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
  },
  // 指定挑战值的类型：默认类型。
  {
    tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
    value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
  }];

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

/*
 * 生成密钥
 */
class throwObject {
  isThrow: boolean = false
}

function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
  return new Promise<void>((resolve, reject) => {
    try {
      huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}

async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise generateKeyItem`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await generateKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: generateKeyItem failed, ` + JSON.stringify(error));
        }
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ` + JSON.stringify(error));
  }
}

async function TestGenKeyForFingerprintAccessControl() {
  await publicGenKeyFunc(keyAlias, huksOptions);
}
```

2. 初始化密钥会话，发起指纹认证获取认证令牌。
   
```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { userAuth } from '@kit.UserAuthenticationKit';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let IV = '1234567890123456'; // 此处为样例代码，实际使用需采用随机值。
let srcKeyAlias = 'test_sm4_key_alias';
let handle: number;
let challenge: Uint8Array;
let fingerAuthToken: Uint8Array;
let authType = userAuth.UserAuthType.FINGERPRINT;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
/* 集成生成密钥参数集 & 加密参数集 */
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
  value: StringToUint8Array(IV),
}];

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

class throwObject {
  isThrow: boolean = false
}

function initSession(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
  return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
    try {
      huks.initSession(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}
/* 初始化HUKS中的会话，获取挑战值 */
async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doInit`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await initSession(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
        handle = data.handle;
        challenge = data.challenge as Uint8Array;
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doInit failed, ` + JSON.stringify(error));
        }
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, ` + JSON.stringify(error));
  }
}
/* 调用UserIAM拉起指纹认证，触发HUKS的访问控制流程 */
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
  try {
    auth = userAuth.getUserAuthInstance(authParam, widgetParam);
    console.info("get auth instance success");
  } catch (error) {
    console.error("get auth instance failed" + JSON.stringify(error));
    return;
  }
  // 订阅认证结果。
  try {
    auth.on("result", {
      onResult(result) {
        console.info("[HUKS] -> [IAM]  userAuthInstance callback result = " + JSON.stringify(result));
        fingerAuthToken = result.token;
      }
    });
    console.log("subscribe authentication event success");
  } catch (error) {
    console.error("subscribe authentication event failed, " + JSON.stringify(error));
  }
  // 开始认证。
  try {
    auth.start();
    console.info("authV9 start auth success");
  } catch (error) {
    console.error("authV9 start auth failed, error = " + JSON.stringify(error));
  }
}

async function testInitAndAuthFinger() {
  /* 初始化密钥会话获取挑战值 */
  await publicInitFunc(srcKeyAlias, huksOptions);
  /* 调用userIAM进行身份认证 */
  userIAMAuthFinger(challenge);
}
```

3. 传入认证令牌进行数据操作。
   
```ts
/*
* 以下以SM4 128密钥为例
*/
import { huks } from '@kit.UniversalKeystoreKit';

/*
* 确定封装密钥属性参数集
*/
let IV = '1234567890123456'; // 此处为样例代码，实际使用需采用随机值。
let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
let handle: number;
let fingerAuthToken: Uint8Array;
let finishOutData: Uint8Array;

class throwObject {
  isThrow: boolean = false;
}

/* 集成生成密钥参数集 & 加密参数集 */
class propertyEncryptType {
  tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
  value: huks.HuksKeyAlg | huks.HuksKeyPurpose | huks.HuksKeySize | huks.HuksKeyPadding | huks.HuksCipherMode
    | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_SM4;
}

let propertiesEncrypt: propertyEncryptType[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM4,
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
  },
  {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV),
  }
]
let encryptOptions: huks.HuksOptions = {
  properties: propertiesEncrypt,
  inData: new Uint8Array(new Array())
}

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(dataArray: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < dataArray.length; i++) {
    dataString += String.fromCharCode(dataArray[i]);
  }
  return dataString;
}

function updateSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array, throwObject: throwObject) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.updateSession(handle, huksOptions, token, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}

async function publicUpdateFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doUpdate`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await updateSession(handle, huksOptions, token, throwObject)
      .then((data) => {
        console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doUpdate failed, ` + JSON.stringify(error));
        }
      });
  } catch (error) {
    console.error(`promise: doUpdate input arg invalid, ` + JSON.stringify(error));
  }
}

function finishSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array, throwObject: throwObject) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.finishSession(handle, huksOptions, token, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObject.isThrow = true;
      throw (error as Error);
    }
  });
}

async function publicFinishFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doFinish`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await finishSession(handle, huksOptions, token, throwObject)
      .then((data) => {
        finishOutData = data.outData as Uint8Array;
        console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doFinish failed, ` + JSON.stringify(error));
        }
      });
  } catch (error) {
    console.error(`promise: doFinish input arg invalid, ` + JSON.stringify(error));
  }
}

async function testSm4Cipher() {
  encryptOptions.inData = StringToUint8Array(cipherInData);
  /* 传入认证令牌 */
  await publicUpdateFunc(handle, fingerAuthToken, encryptOptions);
  /* 传入认证令牌 */
  await publicFinishFunc(handle, fingerAuthToken, encryptOptions);
  if (Uint8ArrayToString(finishOutData) == cipherInData) {
    console.info('test finish encrypt error ');
  } else {
    console.info('test finish encrypt success');
  }
}
```

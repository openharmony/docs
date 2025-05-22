# HUKS Access Control Development


For details about scenarios and related concepts, see [HUKS Access Control Overview](huks-identity-authentication-overview.md).


## How to Develop

1. Generate a key, enable fingerprint authentication for key access, and set related parameters.
   When a key is generated or imported, set [HuksUserAuthType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksuserauthtype9), [HuksAuthAccessType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksauthaccesstype9), and [HuksChallengeType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukschallengetype9).

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/*
* Set the key alias and encapsulate the key property set.
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
  // Set HuksUserAuthType to fingerprint authentication.
  {
    tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
    value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
  },
  // Set HuksAuthAccessType to HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL, which invalidates the key when a new biometric feature (fingerprint) is enrolled.
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
    value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
  },
  // Use the default challenge type.
  {
    tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
    value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
  }];

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

/*
 * Generate a key.
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

2. Initialize a key session to initiate fingerprint authentication. If the authentication is successful, an authentication token (**AuthToken**) is returned.
   
```ts
import { huks } from '@kit.UniversalKeystoreKit';
import { userAuth } from '@kit.UserAuthenticationKit';

/*
 * Set the key alias and encapsulate the key property set.
 */
let IV = '1234567890123456';
let srcKeyAlias = 'test_sm4_key_alias';
let handle: number;
let challenge: Uint8Array;
let fingerAuthToken: Uint8Array;
let authType = userAuth.UserAuthType.FINGERPRINT;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
/* Set the key generation parameter set and key encryption parameter set. */
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
/* Initialize the session in the HUKS and obtain the challenge value. */
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
/* Call UserIAM to start fingerprint authentication and trigger the access control process in HUKS. */
function userIAMAuthFinger(huksChallenge: Uint8Array) {
  // Obtain an authentication object.
  let authTypeList: userAuth.UserAuthType[] = [authType];
  const authParam: userAuth.AuthParam = {
    challenge: huksChallenge,
    authType: authTypeList,
    authTrustLevel: userAuth.AuthTrustLevel.ATL1
  };
  const widgetParam: userAuth.WidgetParam = {
    title: 'Enter password',
  };
  let auth: userAuth.UserAuthInstance;
  try {
    auth = userAuth.getUserAuthInstance(authParam, widgetParam);
    console.info("get auth instance success");
  } catch (error) {
    console.error("get auth instance failed" + JSON.stringify(error));
    return;
  }
  // Subscribe to the authentication result.
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
  // Start user authentication.
  try {
    auth.start();
    console.info("authV9 start auth success");
  } catch (error) {
    console.error("authV9 start auth failed, error = " + JSON.stringify(error));
  }
}

async function testInitAndAuthFinger() {
  /* Initialize the key session to obtain a challenge. */
  await publicInitFunc(srcKeyAlias, huksOptions);
  /* Invoke userIAM to perform user identity authentication. */
  userIAMAuthFinger(challenge);
}
```

3. Pass in **AuthToken** to perform data operations.
   
```ts
/*
* The following uses a 128-bit SM4 key as an example.
*/
import { huks } from '@kit.UniversalKeystoreKit';

/*
* Determine the key property set to be encapsulated.
*/
let IV = '1234567890123456';
let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
let handle: number;
let fingerAuthToken: Uint8Array;
let finishOutData: Uint8Array;

class throwObject {
  isThrow: boolean = false;
}

/* Set the key generation parameter set and key encryption parameter set. */
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
  /* Pass in AuthToken. */
  await publicUpdateFunc(handle, fingerAuthToken, encryptOptions);
  /* Pass in AuthToken. */
  await publicFinishFunc(handle, fingerAuthToken, encryptOptions);
  if (finishOutData === StringToUint8Array(cipherInData)) {
    console.info('test finish encrypt error ');
  } else {
    console.info('test finish encrypt success');
  }
}
```

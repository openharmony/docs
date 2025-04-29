# 细粒度用户身份认证访问控制开发指导

细粒度用户身份认证访问控制是基于已有用户身份认证访问控制的扩展，提供了基于生物特征和锁屏密码二次身份认证的细粒度访问控制能力，允许设置密钥在加密、解密、签名、验签、密钥协商、密钥派生的单个或多个场景时是否需要进行身份验证。

比如，业务需要使用HUKS密钥加密保存账号密码信息等数据，要求在加密的时候不进行指纹等身份认证，解密的时候需要进行指纹等身份认证，这是就需要依赖HUKS提供细粒度的二次身份认证访问控制机制。

使用该功能仅需在密钥生成阶段，通过额外指定用于细粒度用户身份认证访问控制的HuksTag：HUKS_TAG_KEY_AUTH_PURPOSE，来指定在某种算法用途的情况下需要使用用户身份认证访问控制能力。

> **说明：**
> 对于对称加解密场景，仅AES/CBC、AES/GCM、SM4/CBC模式支持细粒度访问控制。

## 开发步骤

1. 生成密钥，指定指纹类型的访问控制及相关属性，指定HUKS_TAG_KEY_AUTH_PURPOSE值。
   
    ```ts
    import { huks } from "@kit.UniversalKeystoreKit";
    
    /*
     * 确定密钥别名和封装密钥属性参数集
     */
    let keyAlias = 'test_sm4_key_alias';
    
    class throwObject {
      isThrow: boolean = false;
    }
    
    let properties: Array<huks.HuksParam> = [
      {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_SM4,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_CBC,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
        value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
      },
      {
        tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
        value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
      },
      {
        tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
        value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
      },
      {
        tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
      }
    ];
    
    let huksOptions: huks.HuksOptions = {
      properties: properties,
      inData: new Uint8Array(new Array())
    }
    
    /*
     * 生成密钥
     */
    async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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
              console.error(`promise: generateKeyItem failed` + JSON.stringify(error));
            }
          });
      } catch (error) {
        console.error(`promise: generateKeyItem input arg invalid` + JSON.stringify(error));
      }
    }
    
    async function TestGenKeyForFingerprintAccessControl() {
      await publicGenKeyFunc(keyAlias, huksOptions);
    }
    ```

2. 使用密钥，加密时不需要用户身份认证访问控制。
   
    ```ts
    import { huks } from "@kit.UniversalKeystoreKit";
    
    class HuksProperties {
      tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
      value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyPadding | huks.HuksCipherMode
        | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_ECC;
    }
    
    /*
     * 确定密钥别名和封装密钥属性参数集
     */
    let keyAlias = 'test_sm4_key_alias';
    let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string'; // 明文数据。
    let IV = '1234567890123456'; // 此处为样例代码，实际使用需采用随机值。
    let handle = 0;
    let cipherText: Uint8Array; // 加密后的密文数据。
    
    function StringToUint8Array(str: string) {
      let arr: number[] = [];
      for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
      }
      return new Uint8Array(arr);
    }
    
    /* 集成生成密钥参数集 & 加密参数集 */
    let propertiesEncrypt: HuksProperties[] = [
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
    ];
    let encryptOptions: huks.HuksOptions = {
      properties: propertiesEncrypt,
      inData: new Uint8Array(new Array())
    }
    
    class throwObject1 {
      isThrow: boolean = false;
    }
    
    function initSession(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject1) {
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
    
    async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
      console.info(`enter promise doInit`);
      let throwObject: throwObject1 = { isThrow: false };
      try {
        await initSession(keyAlias, huksOptions, throwObject)
          .then((data) => {
            console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle as number;
          })
          .catch((error: Error) => {
            if (throwObject.isThrow) {
              throw (error as Error);
            } else {
              console.error(`promise: doInit failed` + JSON.stringify(error));
            }
          });
      } catch (error) {
        console.error(`promise: doInit input arg invalid` + JSON.stringify(error));
      }
    }
    
    function finishSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject1) {
      return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
          huks.finishSession(handle, huksOptions, (error, data) => {
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
    
    async function publicFinishFunc(handle: number, huksOptions: huks.HuksOptions) {
      console.info(`enter promise doFinish`);
      let throwObject: throwObject1 = { isThrow: false };
      try {
        await finishSession(handle, huksOptions, throwObject)
          .then((data) => {
            cipherText = data.outData as Uint8Array;
            console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
          })
          .catch((error: Error) => {
            if (throwObject.isThrow) {
              throw (error as Error);
            } else {
              console.error(`promise: doFinish failed` + JSON.stringify(error));
            }
          });
      } catch (error) {
        console.error(`promise: doFinish input arg invalid` + JSON.stringify(error));
      }
    }
    
    async function testSm4Cipher() {
      /* 初始化密钥会话获取挑战值 */
      await publicInitFunc(keyAlias, encryptOptions);
      /* 加密 */
      encryptOptions.inData = StringToUint8Array(cipherInData);
      await publicFinishFunc(handle, encryptOptions);
    }
    ```

3. 使用密钥，解密时需要进行用户身份认证访问控制。
   
    ```ts
    import { huks } from "@kit.UniversalKeystoreKit";
    import { userAuth } from '@kit.UserAuthenticationKit';
    import { BusinessError } from "@kit.BasicServicesKit";
    
    let keyAlias = 'test_sm4_key_alias';
    let IV = '1234567890123456'; // 此处为样例代码，实际使用需采用随机值。
    let handle = 0;
    let cipherText: Uint8Array; // 密文数据。
    /*
    * 确定封装密钥属性参数集
    */
    let finishOutData: Uint8Array; // 解密后的明文数据。
    let fingerAuthToken: Uint8Array;
    let challenge: Uint8Array;
    let authType = userAuth.UserAuthType.FINGERPRINT;
    let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
    
    class throwObject {
      isThrow: boolean = false;
    }
    
    function StringToUint8Array(str: string) {
      let arr: number[] = [];
      for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
      }
      return new Uint8Array(arr);
    }
    
    /* 集成生成密钥参数集 & 加密参数集 */
    class propertyDecryptType {
      tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
      value: huks.HuksKeyAlg | huks.HuksKeyPurpose | huks.HuksKeySize | huks.HuksKeyPadding | huks.HuksCipherMode
        | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_SM4
    }
    
    let propertiesDecrypt: propertyDecryptType[] = [
      {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_SM4,
      },
      {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
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
    let decryptOptions: huks.HuksOptions = {
      properties: propertiesDecrypt,
      inData: new Uint8Array(new Array())
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
          .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
              throw (error as Error);
            } else {
              console.error(`promise: doInit failed` + JSON.stringify(error));
            }
          });
      } catch (error) {
        console.error(`promise: doInit input arg invalid` + JSON.stringify(error));
      }
    }
    
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
        console.info("subscribe authentication event success");
      } catch (error) {
        console.error("subscribe authentication event failed " + JSON.stringify(error));
      }
      // 开始认证。
      try {
        auth.start();
        console.info("authV9 start auth success");
      } catch (error) {
        console.error("authV9 start auth failed, error = " + JSON.stringify(error));
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
          .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
              throw (error as Error);
            } else {
              console.error(`promise: doFinish failed` + JSON.stringify(error));
            }
          });
      } catch (error) {
        console.error(`promise: doFinish input arg invalid` + JSON.stringify(error));
      }
    }
    
    async function testSm4CipherInit() {
      /* 初始化密钥会话获取挑战值 */
      await publicInitFunc(keyAlias, decryptOptions);
      /* 调用userIAM进行身份认证 */
      userIAMAuthFinger(challenge);
    }
    
    async function testSm4CipherFinish() {
      /* 认证成功后进行解密, 需要传入Auth获取到的authToken值 */
      decryptOptions.inData = cipherText;
      await publicFinishFunc(handle, fingerAuthToken, decryptOptions);
    }
    ```

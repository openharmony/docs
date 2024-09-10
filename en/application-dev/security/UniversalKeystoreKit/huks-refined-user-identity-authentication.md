# Refined Key Access Control Development

As an extension of the access control based on user identity authentication, the refined key access control provides fine-grained access control capabilities via secondary identity authentication based on biometric features and lock screen passwords. You can set whether identity authentication is required for a key in one or more scenarios such as encryption, decryption, signing, signature verification, key agreement, and key derivation.

For example, a service needs to use a HUKS key to encrypt the account password information. In this scenario, identity authentication is not required in encryption but required in decryption. To achieve this purpose, you can use the refined access control feature provided by HUKS.

To implement this feature, you only need to set **HuksTag** to **HUKS_TAG_KEY_AUTH_PURPOSE**.

> **NOTE**<br>
> For symmetric encryption and decryption, only the AES/CBC, AES/GCM, and SM4/CBC modes support fine-grained access control.

## How to Develop

1. Generate a key, set HuksUserAuthType to fingerprint authentication, and set other parameters including **HUKS_TAG_KEY_AUTH_PURPOSE**.
   
   ```ts
   import { huks } from "@kit.UniversalKeystoreKit";
   /*
    * Set the key alias and encapsulate the key property set.
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
    * Generate a key.
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
               throw(error as Error);
           }
       });
   }
   async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
       console.info(`enter promise generateKeyItem`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await generateKeyItem(keyAlias, huksOptions, throwObject)
           .then((data) => {
               console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: Error) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
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

2. Use the key. User identity authentication is not required when the key is used for encryption.
   
   ```ts
   import { huks } from "@kit.UniversalKeystoreKit";
   class HuksProperties {
       tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
       value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyPadding | huks.HuksCipherMode 
           | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_ECC;
   }
   /*
    * Set the key alias and encapsulate the key property set.
    */
   let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string'; // Plaintext
   let IV = '1234567890123456';
   let handle = 0;
   let cipherText: Uint8Array; // Ciphertext after encryption.
   function StringToUint8Array(str: string) {
       let arr: number[] = [];
       for (let i = 0, j = str.length; i < j; ++i) {
           arr.push(str.charCodeAt(i));
       }
       return new Uint8Array(arr);
   }
   /* Set the key generation parameter set and key encryption parameter set. */
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
   class throwObject1{
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
       /* Initialize the key session to obtain a challenge. */
       await publicInitFunc(keyAlias, encryptOptions);
       /** Encryption */
       encryptOptions.inData = StringToUint8Array(cipherInData);
       await publicFinishFunc(handle, encryptOptions);
   }
   ```

3. Use the key. User identity authentication is required when the key is used for decryption.
   
   ```ts
    import { huks } from "@kit.UniversalKeystoreKit";
    import { userAuth } from '@kit.UserAuthenticationKit';
    import { BusinessError } from "@kit.BasicServicesKit"

    let keyAlias = 'test_sm4_key_alias';
    let IV = '1234567890123456';
    let handle = 0;
    let cipherText: Uint8Array; // Data in ciphertext.
    /*
    * Determine the key property set to be encapsulated.
    */
    let finishOutData: Uint8Array; // Plaintext after decryption.
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
    /* Set the key generation parameter set and key encryption parameter set. */
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
                throw(error as Error);
            }
        });
    }
    async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter promise doInit`);
    let throwObject: throwObject = {isThrow: false};
    try {
        await initSession(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle;
            challenge = data.challenge as Uint8Array;
        })
        .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
            throw(error as Error);
            } else {
            console.error(`promise: doInit failed` + JSON.stringify(error));
            }
        });
    } catch (error) {
        console.error(`promise: doInit input arg invalid` + JSON.stringify(error));
    }
    }
    function userIAMAuthFinger(huksChallenge: Uint8Array) {
    // Obtain an authentication object.
    let authTypeList:userAuth.UserAuthType[]= [ authType ];
    const authParam:userAuth.AuthParam = {
        challenge: huksChallenge,
        authType: authTypeList,
        authTrustLevel: userAuth.AuthTrustLevel.ATL1
    };
    const widgetParam:userAuth.WidgetParam = {
        title: 'Enter password',
    };
    let auth : userAuth.UserAuthInstance;
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
        console.info("subscribe authentication event success");
    } catch (error) {
        console.error("subscribe authentication event failed " + JSON.stringify(error));
    }
    // Start user authentication.
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
        throw(error as Error);
        }
    });
    }
    async function publicFinishFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
    console.info(`enter promise doFinish`);
    let throwObject: throwObject = {isThrow: false};
    try {
        await finishSession(handle, huksOptions, token, throwObject)
        .then ((data) => {
            finishOutData = data.outData as Uint8Array;
            console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`promise: doFinish failed` + JSON.stringify(error));
            }
        });
    } catch (error) {
        console.error(`promise: doFinish input arg invalid` + JSON.stringify(error));
    }
    }
    async function testSm4Cipher() {
    /* Initialize the key session to obtain a challenge. */
    await publicInitFunc(keyAlias, decryptOptions);
    /* Invoke userIAM to perform user identity authentication. */
    userIAMAuthFinger(challenge);
    /* Perform decryption after the authentication is successful. The **authToken** value returned after the authentication needs to be passed in. */
    decryptOptions.inData = StringToUint8Array(cipherText);
    await publicFinishFunc(handle, fingerAuthToken, decryptOptions);
    }
   ```

# Key Agreement (ArkTS)


This topic walks you through on how to agree on a 256-bit X25519 key that is used only in HUKS. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).


## How to Develop

**Key Generation**

Generate an asymmetric key for device A and device B each. For details, see [Key Generation](huks-key-generation-overview.md) or [Key Import](huks-key-import-overview.md).

The optional parameter **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** specifies how a derived key or a key generated after key agreement is stored.

- **HUKS_STORAGE_ONLY_USED_IN_HUKS**: The key is stored and managed by HUKS.

- **HUKS_STORAGE_KEY_EXPORT_ALLOWED** (default): The key is directly exported to the service and not managed by HUKS.

**Key Export**

Export the public key of the asymmetric key pair of device A and device B. For details, see [Key Export](huks-export-key-arkts.md).

**Key Agreement**

Perform key agreement using the public key of the peer device and private key of the local device (that is, public key of device B and private key of device A for device A, and public key of device A and private key of device B for device B) to produce a shared secrete key.

**Key Deletion**

Delete the keys from device A and device B when the keys are not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).

```ts
/*
 * Agree on a 256-bit X25519 key. This example uses promise-based APIs.
 */
 import huks from '@ohos.security.huks';
 import { BusinessError } from '@ohos.base';
 /*
  * Set the key alias and encapsulate the key property set.
  */
 let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
 let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
 let agreeX25519InData = 'AgreeX25519TestIndata';
 let finishOutData: Uint8Array;
 let handle: number;
 let exportKey: Uint8Array;
 let exportKeyFirst: Uint8Array;
 let exportKeySecond: Uint8Array;
 /* Set the parameter set used for generating the key. */
 let properties: Array<huks.HuksParam> = new Array();
 properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_X25519,
 }
 properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
 }
 properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256,
 }
 properties[3] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
 }
 properties[4] = {
     tag: huks.HuksTag.HUKS_TAG_PADDING,
     value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
 }
 properties[5] = {
     tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
     value: huks.HuksCipherMode.HUKS_MODE_CBC,
 }
 properties[6] = {
     tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
     value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
 }
 let HuksOptions: huks.HuksOptions = {
     properties: properties,
     inData: new Uint8Array(new Array())
 }
 /* Set the parameter set for the first key agreement. */
 let finishProperties: Array<huks.HuksParam> = new Array();
 finishProperties[0] = {
     tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
     value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
 }
 finishProperties[1] = {
     tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
     value: true
 }
 finishProperties[2] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_AES,
 }
 finishProperties[3] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
 }
 finishProperties[4] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value:
     huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
     huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
 }
 finishProperties[5] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
 }
 finishProperties[6] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
     value: StringToUint8Array(srcKeyAliasFirst+ 'final'),
 }
 finishProperties[7] = {
     tag: huks.HuksTag.HUKS_TAG_PADDING,
     value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
 }
 finishProperties[8] = {
     tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
     value: huks.HuksCipherMode.HUKS_MODE_ECB,
 }
 let finishOptionsFirst: huks.HuksOptions = {
     properties: finishProperties,
     inData: StringToUint8Array(agreeX25519InData)
 }
 /* Set the parameter set for the second key agreement. */
 let finishPropertiesSecond = [...finishProperties]
 finishPropertiesSecond[6] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAliasSecond + 'final'),
 }
 let finishOptionsSecond: huks.HuksOptions = {
     properties: finishPropertiesSecond,
     inData: StringToUint8Array(agreeX25519InData)
 }
 function StringToUint8Array(str:string) {
     let arr: number[] = new Array();
     for (let i = 0, j = str.length; i < j; ++i) {
         arr.push(str.charCodeAt(i));
     }
 return new Uint8Array(arr);
 }
 class throwObject {
     isThrow: boolean = false
 }
 /* Generate a key. */
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
             throw(error as Error);
         }
     });
 }
 /* Call generateKeyItem to generate a key. */
 async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise generateKeyItem`);
     let throwObject:throwObject = {isThrow: false};
     try {
         await generateKeyItem(keyAlias, huksOptions, throwObject)
         .then((data) => {
             console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: generateKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: generateKeyItem input arg invalid` + error);
     }
 }
 /* Initializes a key session, which returns a session handle (mandatory) and a challenge (optional). */
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
 /* Call initSession. A session handle is returned. */
 async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doInit`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await initSession(keyAlias, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
             handle = data.handle;
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doInit failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doInit input arg invalid` + error);
     }
 }
 /* Call updateSession multiple times to process data by segment and output the processed data. */
 function updateSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject)  {
     return new Promise<huks.HuksReturnResult>((resolve, reject) => {
         try {
             huks.updateSession(handle, huksOptions, (error, data) => {
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
 /* Call updateSession to perform key agreement. */
 async function publicUpdateFunc(handle: number, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doUpdate`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await updateSession(handle, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doUpdate failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doUpdate input arg invalid` + error);
     }
 }
 /* Finish the key session to output the shared secret key. */
 function finishSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
     return new Promise<huks.HuksReturnResult>((resolve, reject) => {
         try {
             huks.finishSession(handle, huksOptions, (error, data) =>{
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
 /* Call finishSession to finish the operation. */
 async function publicFinishFunc(handle: number, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doFinish`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await finishSession(handle, huksOptions, throwObject)
         .then ((data) => {
             finishOutData = data.outData as Uint8Array;
             console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doFinish failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doFinish input arg invalid` + error);
     }
 }
 /* Export a key. */
 function exportKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
     return new Promise<huks.HuksReturnResult>((resolve, reject) => {
         try {
             huks.exportKeyItem(keyAlias, huksOptions, (error, data) => {
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
 /* Call exportKeyItem to export the public key. */
 async function publicExportKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise export`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await exportKeyItem(keyAlias, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);
             exportKey = data.outData as Uint8Array;
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: exportKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: exportKeyItem input arg invalid` + error);
     }
 }
 /* Delete the keys. */
 function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
     return new Promise<void>((resolve, reject) => {
         try {
             huks.deleteKeyItem(keyAlias, huksOptions, (error, data) => {
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
 /* Call deleteKeyItem to delete a key. */
 async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise deleteKeyItem`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await deleteKeyItem(keyAlias, huksOptions, throwObject)
         .then ((data) => {
            console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
         })
         .catch((error :BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: deleteKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: deleteKeyItem input arg invalid` + error);
     }
 }
 async function testAgree() {
     /* 1. Set the key alias srcKeyAliasFirst for device A and srcKeyAliasSecond for device B, and parameters for generating the key pairs. */
     /* 2. Generate an asymmetric key pair for device A. */
     await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
     /* 3. Generate an asymmetric key pair for device B. */
     await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);
     /* 4. Export the public keys of the key pairs of device A and device B. */
     await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
     exportKeyFirst = exportKey;
     await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
     exportKeySecond = exportKey;
     /* 5. Perform key agreement (Init-Update-Finish) for device A. */
     await publicInitFunc(srcKeyAliasFirst, HuksOptions);
     HuksOptions.inData = exportKeySecond;
     await publicUpdateFunc(handle, HuksOptions);
     await publicFinishFunc(handle, finishOptionsFirst);
     /* 5. Perform key agreement (Init-Update-Finish) for device B. */
     await publicInitFunc(srcKeyAliasSecond, HuksOptions);
     HuksOptions.inData = exportKeyFirst;
     await publicUpdateFunc(handle, HuksOptions);
     await publicFinishFunc(handle, finishOptionsSecond);
     /* 6. Delete keys from device A and device B. */
     await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
     await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
 }
```

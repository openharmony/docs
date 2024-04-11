# Key Derivation (ArkTS)


This topic walks you through on how to derive a 256-bit key using HKDF. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).


## How to Develop

**Key Generation**

1. Set the key alias.

2. Initialize the key property set. The optional parameter **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** specifies how a derived key is stored.
   - **HUKS_STORAGE_ONLY_USED_IN_HUKS**: The key is stored and managed by HUKS.
   - **HUKS_STORAGE_KEY_EXPORT_ALLOWED** (default): The key is directly exported to the service and not managed by HUKS.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Key Derivation**

1. Obtain the key alias and set the **HuksOptions** parameter.

2. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

3. Use [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9) to process data.

4. Use [OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_finishsession) to derive a key.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).

```ts
/*
 * Derive a 256-bit key using HKDF. This example uses promise-based APIs.
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
/*
 * Set the key alias and encapsulate the key property set.
 */
let srcKeyAlias = "hkdf_Key";
let deriveHkdfInData = "deriveHkdfTestIndata";
let handle:number;
let finishOutData:Uint8Array;
let HuksKeyDeriveKeySize = 32;
/* Set the parameter set used for key generation. */
let properties:Array<huks.HuksParam> = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
let huksOptions:huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}
/* Set the parameter set used for init(). */
let initProperties:Array<huks.HuksParam> = new Array();
initProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
}
initProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}
initProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
initProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
    value: HuksKeyDeriveKeySize,
}
let initOptions:huks.HuksOptions = {
    properties: initProperties,
    inData: new Uint8Array(new Array())
}
/* Set the parameter set used for finish(). */
let finishProperties:Array<huks.HuksParam> = new Array();
finishProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
finishProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true,
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
    value: StringToUint8Array(srcKeyAlias),
}
finishProperties[7] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
finishProperties[8] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
let finishOptions:huks.HuksOptions = {
    properties: finishProperties,
    inData: new Uint8Array(new Array())
}
function StringToUint8Array(str:String) {
    let arr:number[]=new Array();
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}
class throwObject{
    isThrow=false;
}
function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, (error, data)=> {
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
async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise generateKeyItem`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await generateKeyItem(keyAlias, huksOptions, throwObject)
        .then((data) => {
            console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
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
function initSession(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, (error, data)=> {
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
async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doInit`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await initSession(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle;
        })
        .catch((error:BusinessError) => {
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
function updateSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksOptions>((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, (error, data)=> {
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
async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doUpdate`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await updateSession(handle, huksOptions, throwObject)
        .then ((data) => {
            console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
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
function finishSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, (error, data)=> {
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
async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doFinish`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await finishSession(handle, huksOptions, throwObject)
        .then ((data) => {
            finishOutData = data.outData as Uint8Array;
            console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
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
function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, (error, data)=> {
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
async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise deleteKeyItem`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await deleteKeyItem(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`promise: deleteKeyItem failed` + error);
            }
        });
    } catch (error) {
        console.error(`promise: deletKeeyItem input arg invalid` + error);
    }
}
async function testDerive() {
    /* Generate a key. */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);
    /* Perform key derivation. */
    await publicInitFunc(srcKeyAlias, initOptions);
    initOptions.inData = StringToUint8Array(deriveHkdfInData);
    await publicUpdateFunc(handle, initOptions);
    await publicFinishFunc(handle, finishOptions);
    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```

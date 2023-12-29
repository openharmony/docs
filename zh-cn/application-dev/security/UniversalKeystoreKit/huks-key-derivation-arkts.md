# 密钥派生(ArkTS)


以HKDF256密钥为例，完成密钥派生。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。


## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集，可指定参数TAG(可选)，HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG：
   - HUKS_STORAGE_ONLY_USED_IN_HUKS：表示由该密钥派生出的密钥存储于HUKS中，由HUKS进行托管。
   - HUKS_STORAGE_KEY_EXPORT_ALLOWED(默认)：表示由该密钥派生出的密钥直接导出给业务方，HUKS不对其进行托管服务。

3. 调用[generateKeyItem](../../reference/apis/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**密钥派生**

1. 获取密钥别名、指定对应的属性参数HuksOptions。

2. 调用[initSession](../../reference/apis/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

3. 调用[updateSession](../../reference/apis/js-apis-huks.md#huksupdatesession9)更新密钥会话。

4. 调用[finishSession](../../reference/apis/js-apis-huks.md#huksfinishsession9)结束密钥会话，完成派生。

**删除密钥**

当密钥废弃不用时，需要调用[deleteKeyItem](../../reference/apis/js-apis-huks.md#huksdeletekeyitem9)删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。

```ts
/*
 * 以下以HKDF256密钥的Promise操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
/*
 * 确定密钥别名和封装密钥属性参数集
 */
let srcKeyAlias = "hkdf_Key";
let deriveHkdfInData = "deriveHkdfTestIndata";
let handle:number;
let finishOutData:Uint8Array;
let HuksKeyDeriveKeySize = 32;
/* 集成生成密钥参数集 */
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
/* 集成init时密钥参数集 */
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
/* 集成finish时密钥参数集 */
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
    /* 生成密钥 */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);
    /* 进行派生操作 */
    await publicInitFunc(srcKeyAlias, initOptions);
    initOptions.inData = StringToUint8Array(deriveHkdfInData);
    await publicUpdateFunc(handle, initOptions);
    await publicFinishFunc(handle, finishOptions);
    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```

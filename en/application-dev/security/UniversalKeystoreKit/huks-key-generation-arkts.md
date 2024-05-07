# Generating a Key (ArkTS)


This topic walks you through on how to randomly generate a DH key. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).


## How to Develop

1. Set the alias (**keyAlias**) of the key to generate.
   - The key alias cannot exceed 64 bytes.
   - For the keys generated for different services, HUKS isolates the storage paths based on the service identity information to prevent conflicts caused by the same key alias.

2. Initialize the key property set. Encapsulate key properties in [HuksParam](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) and use a **HuksParam** array to assign values to the **properties** field of [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions).
   The key property set must contain [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg), [HuksKeySize](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeysize), and [HuksKeyPurpose](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose). That is, **TAG**, **HUKS_TAG_ALGORITHM**, **HUKS_TAG_PURPOSE**, and **HUKS_TAG_KEY_SIZE** are mandatory.

3. Use [huks.generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key based on the key alias and key properties specified.

> **NOTE**<br>
> If the service uses the same key alias to call the HUKS API to generate a key again, HUKS will generate a new key and overwrite the historical key file.


```ts
/* Generate a DH key. */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC;
}
/* 1. Set the key alias. */
let keyAlias = 'dh_key';
/* 2. Initialize the key property set. */
let properties1: HuksProperties[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_DH
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048
    },
    {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
];
let huksOptions: huks.HuksOptions = {
    properties: properties1,
    inData: new Uint8Array(new Array())
}
/* 3. Generate a key. */
function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions){
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
            throw (error as Error);
        }
    });
}
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter promise generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
        .then((data) => {
            console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            console.error(`promise: generateKeyItem failed` + error);
        });
    } catch (error) {
        console.error(`promise: generateKeyItem input arg invalid` + error);
    }
}
async function TestGenKey() {
    await publicGenKeyFunc(keyAlias, huksOptions);
}
```

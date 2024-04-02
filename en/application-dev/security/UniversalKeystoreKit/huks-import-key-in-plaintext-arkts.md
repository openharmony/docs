# Importing a Key in Plaintext (ArkTS)


This topic walks you through on how to import an AES 256-bit key. For details about the scenarios and supported algorithm specifications, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms).


## How to Develop

1. Set the alias **keyAlias** of the key to import.
   The key alias cannot exceed 64 bytes.

2. Encapsulate the key property set and key material.
   - The key property set must contain [HuksKeyAlg](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeyalg), [HuksKeySize](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeysize), and [HuksKeyPurpose](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukskeypurpose).
   - The key material must comply with the [HUKS key material format](huks-concepts.md#key-material-format) and is used to fill the **inData** field of [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions) in Uint8Array format.

3. Use [huks.importKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksimportkeyitem9) to import the key.

```ts
/* Import an AES 256-bit key in plaintext. This example uses callback-based APIs. */
import huks from '@ohos.security.huks'
/* Key material */
let plainTextSize32 = new Uint8Array([
    0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba, 0xca,
    0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9
]);
/* 1. Set the key alias. */
let keyAlias = 'AES256Alias_sample';
/* 2. Encapsulate the key property set and key material. */
class propertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose = huks.HuksKeyAlg.HUKS_ALG_RSA;
}
let properties: propertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value:huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    },
]
let options: huks.HuksOptions = {
    properties: properties,
    inData: plainTextSize32
};
/* 3. Import the key in plaintext. */
try {
    huks.importKeyItem(keyAlias, options, (error, data) => {
        if (error) {
            console.error(`callback: importKeyItem failed` + error);
        } else {
            console.info(`callback: importKeyItem success`);
        }
    });
} catch (error) {
    console.error(`callback: importKeyItem input arg invalid` + error);
}
```


## Verification

Use [huks.isKeyItemExist](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksiskeyitemexist9) to check whether the key exists. If the key exists, the key is successfully imported.

```ts
import huks from '@ohos.security.huks';
let keyAlias = 'AES256Alias_sample';
let isKeyExist = false;
class keyPropertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg = huks.HuksKeyAlg.HUKS_ALG_RSA;
}
let keyProperties: keyPropertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
]
let huksOptions: huks.HuksOptions = {
    properties: keyProperties, // It cannot be empty.
    inData: new Uint8Array(new Array()) // It cannot be empty.
}
try {
    huks.isKeyItemExist(keyAlias, huksOptions, (error, data) => {
        if (error) {
            console.error(`callback: isKeyItemExist failed` + error);
        } else {
            if (data !== null && data.valueOf() !== null) {
                isKeyExist = data.valueOf();
                console.info(`callback: isKeyItemExist success, isKeyExist = ${isKeyExist}`);
            }
        }
    });
} catch (error) {
    console.error(`callback: isKeyItemExist input arg invalid` + error);
}
```

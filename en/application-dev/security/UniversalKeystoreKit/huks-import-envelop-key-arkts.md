# Importing a Key Using a Digital Envelope (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=13bb74d44fd56945b2b502ec07cedd46734751f0 translatedAt=2026-08-13T08:22:38.868Z pushedAt=2026-08-13T10:20:24.685Z -->

The [digital envelope](huks-key-import-overview.md#digital-envelope-import) feature is supported since API version 23.

The following uses how to import RSA and AES keys using digital envelope as an example. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms). **The DSA algorithm is not supported for key import using digital envelope.**

To import keys using digital envelope, you need to use the [HUKS_TAG_UNWRAP_ALGORITHM_SUITE](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) tag whose value is [HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksunwrapsuite9).

When importing a key pair of an asymmetric key using digital envelope, you need to add the [HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) tag and encapsulate the public key in X.509 DER format into the tag. Only key pairs can be imported for asymmetric keys.

## How to Develop

1. Device A (service side) generates an SM4 key (**cipherSm4**).

2. Device A uses the generated SM4 key to encrypt the key to be imported (**importKey**) in ECB/NoPadding mode, obtaining the encrypted key **enImportKey** = Encrypt(**cipherSm4**, **importKey**).

3. Device B (key importer) exports the SM2 public key. Device A receives the key.

4. Device A uses the received SM2 public key to encrypt the generated SM4 key (**enSm4** is set to **Encrypt(Sm2, cipherSm4)**).

5. Device A sends the digital envelope data to device B.

6. Device B uses [importWrappedKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksimportwrappedkeyitem9) to import the digital envelope key. If the key to be imported is a symmetric key, you only need to encrypt the raw key in this step. If the key pair of an asymmetric key is imported, encapsulate the public key in DER format and place it in [HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag).

> **NOTE**
>
> If the peer device is not an OpenHarmony device and does not support the key management service, the following requirements must be met when constructing the digital envelope data:
>
> - The SM2 encryption result is combined in the C1C3C2 order, where C1x and C1y each occupy 32 bytes.
>
> - The SM2 encryption result uses the ASN.1 format, where bigint is stored in big-endian order.

### RSA

```ts
import { BusinessError } from "@kit.BasicServicesKit";
import { huks } from "@kit.UniversalKeystoreKit";

function intToUint8Array(value: number): Uint8Array
{
  const buffer = new ArrayBuffer(4);
  const view = new DataView(buffer);
  view.setUint32(0, value, true);
  return new Uint8Array(buffer);
}

function concatUint8Arrays(arrays: Uint8Array[]): Uint8Array
{
  const totalLength = arrays.reduce((sum, arr) => sum + arr.length, 0);
  const result = new Uint8Array(totalLength);
  let offset = 0;
  for (const arr of arrays) {
    result.set(arr, offset);
    offset += arr.length;
  }
  return result;
}

let wrappingParamSetSm2: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }
];
let option: huks.HuksOptions = { properties: wrappingParamSetSm2 };

let sm4PlainData = new Uint8Array([
  0xb9, 0xef, 0x35, 0x49, 0xb7, 0x00, 0x91, 0x58, 0x0c, 0x6f, 0x43, 0x28, 0xf8, 0x95, 0x1c, 0x02,
]);

let enParamSm2: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }
];

let enOption: huks.HuksOptions = {
  properties: enParamSm2,
  inData: sm4PlainData
};

let cipherData: Uint8Array;
let handle: number;

async function EnvelopRsaTest()
{
  let wrappingKeyAlias = "WrappedKey";
  await huks.generateKeyItem(wrappingKeyAlias, option)

  // Use the generated SM2 key to encrypt the SM4 key.
  await huks.initSession(wrappingKeyAlias, enOption)
    .then((data) => {
      handle = data.handle;
    }).catch((error: BusinessError) => {
      console.error('decrypt init fail, errorCode: ${error.code}')
    })
  await huks.finishSession(handle, enOption)
    .then((data) => {
      console.info('encrypt success')
      cipherData = data.outData as Uint8Array
    }).catch((error: BusinessError) => {
      console.error(`encrypt finish fail, errorCode: ${error.code}`)
    })

  let enDataRsa: Uint8Array = new Uint8Array([
    0x4a, 0xce, 0x89, 0xa6, 0xda, 0x85, 0x6d, 0x56, 0xb3, 0xab, 0xc9, 0x70, 0x5e, 0x3f, 0xb6, 0x0e,
    0x07, 0xdf, 0xdf, 0x9c, 0xb3, 0x05, 0xd4, 0x8d, 0xc0, 0xac, 0x9b, 0x13, 0x3d, 0x1b, 0xdb, 0xa0,
    0x46, 0x1a, 0xc8, 0x82, 0x80, 0xe0, 0x2a, 0x28, 0x34, 0xa6, 0x4a, 0x97, 0x91, 0x58, 0xc8, 0x8c,
    0x0f, 0xa2, 0xeb, 0xe1, 0xf8, 0x37, 0x54, 0x99, 0x7e, 0xa1, 0xce, 0x1e, 0xf3, 0x8b, 0x8c, 0x8d,
    0xec, 0x58, 0xb7, 0x32, 0x29, 0x36, 0x34, 0x46, 0x92, 0x67, 0x09, 0xb3, 0xb4, 0xb3, 0x74, 0x3a,
    0x77, 0x99, 0xd7, 0x4b, 0x1f, 0xf6, 0xa6, 0xb0, 0x99, 0x3d, 0x3e, 0x92, 0xba, 0xcf, 0x83, 0xd0,
    0x1e, 0x18, 0x68, 0x1a, 0xb5, 0xfe, 0x18, 0x6d, 0x9d, 0xc2, 0x39, 0x48, 0x2e, 0x52, 0xfc, 0x33,
    0x16, 0xb0, 0x58, 0xd5, 0xdf, 0x84, 0xbe, 0xfe, 0xe1, 0xfa, 0xa9, 0x65, 0x34, 0xb8, 0x97, 0xa3,
    0x9a, 0x45, 0x8a, 0x40, 0x4b, 0x09, 0xdf, 0x1c, 0x48, 0x57, 0x3f, 0xb2, 0x1f, 0xf3, 0x21, 0x7d,
    0xa8, 0xa5, 0xed, 0xe1, 0x61, 0x2f, 0xe0, 0xda, 0xae, 0x15, 0x22, 0x18, 0xf6, 0x84, 0x7d, 0x39,
    0xae, 0x35, 0x49, 0xec, 0xd8, 0x66, 0xff, 0x65, 0x7d, 0xd9, 0x74, 0x19, 0xad, 0x26, 0x64, 0xc0,
    0x2d, 0x93, 0xf5, 0x83, 0x7d, 0x8d, 0x98, 0x35, 0x2e, 0x67, 0xf9, 0xc0, 0xb1, 0xd7, 0x2b, 0xb5,
    0x49, 0x98, 0x3a, 0x31, 0xa0, 0x66, 0x71, 0x6e, 0x09, 0x70, 0xef, 0x56, 0x14, 0x9e, 0xb8, 0xd2,
    0x17, 0x99, 0x44, 0x69, 0xcd, 0x3d, 0xcb, 0x3c, 0xfe, 0xbe, 0x72, 0xc0, 0x43, 0x29, 0x86, 0x70,
    0x9d, 0xa3, 0xc0, 0x68, 0xf6, 0x7e, 0x48, 0x2c, 0x4e, 0x48, 0xe0, 0xf6, 0xa9, 0xcb, 0x28, 0x63,
    0xe8, 0x33, 0xfc, 0xb4, 0x1a, 0x06, 0xf4, 0x13, 0x20, 0xfd, 0x90, 0x90, 0x1c, 0x25, 0xd7, 0xf8,
  ]);

  let publicKey: Uint8Array = new Uint8Array([
    0x30, 0x82, 0x01, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02, 0x82, 0x01, 0x01,
    0x00, 0xa2, 0xd2, 0x3c, 0xe9, 0x87, 0x8b, 0x48, 0x34, 0xdd, 0x41, 0xe0, 0x65, 0x39, 0xcc, 0xea,
    0x25, 0x25, 0xa6, 0x9e, 0x9f, 0x20, 0xc6, 0x13, 0x9f, 0xb2, 0xa7, 0xf3, 0x77, 0x69, 0xfd, 0xa9,
    0xbd, 0xe8, 0x2c, 0xf3, 0x87, 0x3a, 0xc0, 0x2a, 0x01, 0x1f, 0x8d, 0x0f, 0x59, 0x28, 0x34, 0xfb,
    0xe3, 0x8d, 0x9b, 0xa1, 0xe0, 0xe4, 0x60, 0x7d, 0x20, 0x19, 0x49, 0x6f, 0x13, 0x5e, 0xae, 0x3e,
    0x4d, 0x6c, 0x31, 0x6c, 0x0b, 0x90, 0xf8, 0xd2, 0xf3, 0x45, 0x4f, 0x3b, 0x9f, 0x8e, 0x3b, 0x77,
    0x20, 0x9e, 0x54, 0xec, 0x7b, 0x54, 0x15, 0xf0, 0x09, 0x8f, 0x5a, 0xf9, 0x87, 0x9a, 0x27, 0x23,
    0x99, 0x64, 0x4d, 0x8c, 0x80, 0x5c, 0x2e, 0xee, 0xc3, 0x57, 0x6e, 0x3d, 0x91, 0xfb, 0x77, 0x67,
    0x3b, 0x8a, 0xed, 0x01, 0xb5, 0x91, 0x33, 0xa1, 0xaa, 0xb2, 0x0d, 0x49, 0x25, 0x7c, 0x4d, 0x42,
    0xde, 0xfb, 0xcd, 0xd6, 0x48, 0xb8, 0xce, 0xe7, 0x22, 0x71, 0x43, 0x54, 0x2c, 0x6b, 0xbb, 0xbf,
    0x63, 0xdc, 0xea, 0x6f, 0x77, 0x81, 0xe9, 0x07, 0xe0, 0x18, 0xb3, 0x1e, 0x78, 0x4b, 0xbc, 0x17,
    0x77, 0x62, 0x25, 0xd9, 0xe7, 0x23, 0x6c, 0x80, 0xad, 0xdc, 0x51, 0x18, 0x1b, 0x33, 0x56, 0x59,
    0x15, 0x43, 0xcf, 0x51, 0xd9, 0xbc, 0x6d, 0xf7, 0x68, 0xd1, 0xe8, 0xbf, 0x41, 0x36, 0xd1, 0x30,
    0x92, 0x7b, 0x48, 0xd1, 0x00, 0xe2, 0x9d, 0x8e, 0x94, 0xee, 0x20, 0x2a, 0x18, 0xb1, 0x04, 0xba,
    0xe7, 0x19, 0xdc, 0x69, 0x36, 0xf7, 0x34, 0x4b, 0x16, 0x10, 0x10, 0x2a, 0x46, 0x1c, 0x4e, 0x6e,
    0x62, 0xe1, 0x25, 0x79, 0xd5, 0x5c, 0xf3, 0x9a, 0xeb, 0x1f, 0x3d, 0x82, 0xa3, 0xaa, 0x79, 0xde,
    0x23, 0xa1, 0x2b, 0x50, 0x6d, 0x68, 0x3e, 0x77, 0x33, 0xe0, 0xc9, 0x18, 0xbc, 0x65, 0x58, 0x63,
    0x7b, 0x02, 0x03, 0x01, 0x00, 0x01,
  ]);

  let paramRsa: Array<huks.HuksParam> = [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_RSA
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_ECB
    },
    {
      tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
      value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING
    },
    {
      tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
      value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR
    },
    {
      tag: huks.HuksTag.HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA,
      value: publicKey
    }];
  let impRsaOption: huks.HuksOptions = {
    properties: paramRsa
  };

  let wrapDataLen = intToUint8Array(enDataRsa.length);
  let ciLen = intToUint8Array(cipherData.length);
  impRsaOption.inData = concatUint8Arrays([ciLen, cipherData, wrapDataLen, enDataRsa]);

  await huks.importWrappedKeyItem("importRsa", wrappingKeyAlias, impRsaOption)
    .then((data) => {
      console.info('import success')
    }).catch((error: BusinessError) => {
      console.error(`import fail, errorCode: ${error.code}`)
    });
}
```

### AES

```ts
import { BusinessError } from "@kit.BasicServicesKit";
import { huks } from "@kit.UniversalKeystoreKit";

function intToUint8Array(value: number): Uint8Array
{
  const buffer = new ArrayBuffer(4);
  const view = new DataView(buffer);
  view.setUint32(0, value, true);
  return new Uint8Array(buffer);
}

function concatUint8Arrays(arrays: Uint8Array[]): Uint8Array
{
  const totalLength = arrays.reduce((sum, arr) => sum + arr.length, 0);
  const result = new Uint8Array(totalLength);
  let offset = 0;
  for (const arr of arrays) {
    result.set(arr, offset);
    offset += arr.length;
  }
  return result;
}

let wrappingParamSetSm2: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }
];
let option: huks.HuksOptions = { properties: wrappingParamSetSm2 };

let sm4PlainData = new Uint8Array([
  0xb9, 0xef, 0x35, 0x49, 0xb7, 0x00, 0x91, 0x58, 0x0c, 0x6f, 0x43, 0x28, 0xf8, 0x95, 0x1c, 0x02,
]);

let enParamSm2: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }
];

let enOption: huks.HuksOptions = {
  properties: enParamSm2,
  inData: sm4PlainData
};

let cipherData: Uint8Array;
let handle: number;

async function EnvelopAesTest()
{
  let wrappingKeyAlias = "WrappedKey";
  await huks.generateKeyItem(wrappingKeyAlias, option)

  // Use the generated SM2 key to encrypt the SM4 key.
  await huks.initSession(wrappingKeyAlias, enOption)
    .then((data) => {
      handle = data.handle;
    }).catch((error: BusinessError) => {
      console.error('decrypt init fail')
    });
  await huks.finishSession(handle, enOption)
    .then((data) => {
      cipherData = data.outData as Uint8Array
    }).catch((error: BusinessError) => {
      console.error(`encrypt finish fail,errorCode: ${error.code}`)
    });

  let paramSetAes: Array<huks.HuksParam> = [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
      tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
      value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    },
    {
      tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
      value: huks.HuksCipherMode.HUKS_MODE_CBC
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
    },
    {
      tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
      value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING
    }];

  let enDataAes = new Uint8Array([
    0xa5, 0xa4, 0xef, 0x4b, 0x87, 0x69, 0xf1, 0xd0, 0x7c, 0xd0, 0x55, 0x9a, 0xe0, 0xb8, 0x8c, 0x36,
  ]);

  let impAesOption: huks.HuksOptions = { properties: paramSetAes }

  let wrapDataLen = intToUint8Array(enDataAes.length);
  let ciLen = intToUint8Array(cipherData.length);
  impAesOption.inData = concatUint8Arrays([ciLen, cipherData, wrapDataLen, enDataAes]);

  await huks.importWrappedKeyItem("importAes", wrappingKeyAlias, impAesOption)
    .then((data) => {
      console.info('import success')
    }).catch((error: BusinessError) => {
      console.error(`import fail, errorCode: ${error.code}`)
    });
}
```
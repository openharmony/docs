# Anonymous Key Attestation (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3780eaa820092ee975c32f64eb288f44d3471751 translatedAt=2026-08-13T08:23:58.032Z pushedAt=2026-08-13T10:20:24.710Z -->

Ensure network connection during the operation.

## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initializes a parameter set.

   The parameters in the `properties` field of [HuksOptions](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksoptions) must include the [HUKS_TAG_ATTESTATION_CHALLENGE](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) property. Optional parameters include the [HUKS_TAG_ATTESTATION_ID_VERSION_INFO](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) and [HUKS_TAG_ATTESTATION_ID_ALIAS](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) properties.

3. Generate an asymmetric key. For details, see [Key Generation](huks-key-generation-overview.md).

4. Use [anonAttestKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksanonattestkeyitem11) with the key alias and parameter set to perform key attestation.

## Development Case

<!-- @[anonymous_key_proof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/AnonymousKeyProof/entry/src/main/ets/pages/AnonymousKeyProof.ets) -->

``` TypeScript
/*
 * Perform anonymous key attestation. This example uses promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAliasString = 'key anon attest';
let aliasString = keyAliasString;
let aliasUint8 = stringToUint8Array(keyAliasString);
let securityLevel = stringToUint8Array('sec_level');
let challenge = stringToUint8Array('challenge_data');
let versionInfo = stringToUint8Array('version_info');
let anonAttestCertChain: string[];

class ThrowObject {
  public isThrow: boolean = false;
}

/* Encapsulate the key parameter set. */
let genKeyProperties: huks.HuksParam[] = [
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
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
  },
  {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  },
  {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS
  },
  {
    tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
    value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
  },
  {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }
]
let genOptions: huks.HuksOptions = {
  properties: genKeyProperties
};

/* 2. Encapsulate the parameter set for key attestation. */
let anonAttestKeyProperties: huks.HuksParam[] = [
  {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
    value: securityLevel
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
    value: challenge
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
    value: versionInfo
  },
  {
    tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
    value: aliasUint8
  }
]
let huksOptions: huks.HuksOptions = {
  properties: anonAttestKeyProperties
};

function stringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: ThrowObject) {
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

/* 3. Generate a key. */
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise generateKeyItem`);
  let throwObject: ThrowObject = { isThrow: false };
  try {
    await generateKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* 4. Attest the key. */
function anonAttestKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: ThrowObject) {
  return new Promise<huks.HuksReturnResult>((resolve, reject) => {
    try {
      huks.anonAttestKeyItem(keyAlias, huksOptions, (error, data) => {
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

async function publicAnonAttestKey(keyAlias: string, huksOptions: huks.HuksOptions): Promise<string> {
  console.info(`enter promise anonAttestKeyItem`);
  let throwObject: ThrowObject = { isThrow: false };
  try {
    await anonAttestKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: anonAttestKeyItem success, data = ${JSON.stringify(data)}`);
        if (data !== null && data.certChains !== null) {
          anonAttestCertChain = data.certChains as string[];
        }
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: anonAttestKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
    return 'Success';
  } catch (error) {
    console.error(`promise: anonAttestKeyItem input arg invalid, ${JSON.stringify(error)}`);
    return 'Failed';
  }
}

async function anonAttestKeyTest(): Promise<string> {
  await publicGenKeyFunc(aliasString, genOptions);
  let ret = await publicAnonAttestKey(aliasString, huksOptions);
  console.info('anon attest certChain data: ' + anonAttestCertChain)
  return ret;
}
```
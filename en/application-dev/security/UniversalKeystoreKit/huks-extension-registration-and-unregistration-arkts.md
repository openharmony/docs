# Registering and Unregistering a Provider (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=0ba19944010f554da5cb768c4438838cb424056c translatedAt=2026-08-13T08:21:36.313Z pushedAt=2026-08-13T10:20:24.680Z -->

From API version 22, **huksExternalCrypto** provides the APIs for registering and unregistering a Provider.

## Registering a Provider

### How to Develop

1. Construct registration parameters. You need to pass [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag).

2. Call [registerProvider](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoregisterprovider).

### Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function registerProvider(): Promise<void> {
  try {
    /* 1. Construct registration parameters. */
    const providerName = "testProvider";
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
        value: StringToUint8Array("CryptoExtension")
      }
    ];

    /* 2. Call registerProvider. */
    await huksExternalCrypto.registerProvider(providerName, extProperties)
      .then(() => {
        console.info('promise: registerProvider success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: registerProvider failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: registerProvider input arg invalid.');
  }
}

async function TestRegisterProvider() {
  await registerProvider();
}
```

## Registering a Provider and Registering a UIExtensionAbility

### How to Develop

1. Construct registration parameters. You need to pass [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag).

2. Construct UI registration parameters. You need to pass [HUKS_EXT_CRYPTO_TAG_ABILITY_INFO](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag), whose value is a JSON string containing two fields: abilityName and index. abilityName is the name field in module.json5 of the UIExtensionAbility, and its length must not exceed 128 bytes. The length of the index value must not exceed 512 bytes, and its value should be a resourceId. A CryptoExtension can register up to 10 UIExtensionAbilities.

3. Call [registerProvider](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptoregisterprovider) to register.

### Development Example

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function registerProvider(): Promise<void> {
  try {
    /* 1. Construct the registration parameter `ability name`. */
    const providerName = "testProvider";
    /* 2. Construct `ability info`. */
    const abilityInfo = '[' +
      '{"abilityName":"UiAbility1","index":""},' +
      '{"abilityName":"UiAbility2","index":"string2"}]';
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
        value: StringToUint8Array("CryptoExtension")
      }, {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_INFO,
        value: StringToUint8Array(abilityInfo)
      }
    ];

    /* 3. Call `registerProvider`. */
    await huksExternalCrypto.registerProvider(providerName, extProperties)
      .then(() => {
        console.info('promise: registerProvider success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: registerProvider failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: registerProvider input arg invalid.');
  }
}

async function TestRegisterProvider() {
  await registerProvider();
}
```

## Unregistering a Provider

### How to Develop

1. Construct unregistration parameters. To unregister a single ability, you need to pass [HUKS_EXT_CRYPTO_TAG_ABILITY_NAME](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptotag). This parameter does not need to be passed for batch unregistration.

2. Call [unregisterProvider](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptounregisterprovider).

**Single unregistration**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

function StringToUint8Array(str: string) {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function unregisterProvider(): Promise<void> {
  try {
    /* 1. Construct unregistration parameters. */
    const providerName = "testProvider";
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [
      {
        tag: huksExternalCrypto.HuksExternalCryptoTag.HUKS_EXT_CRYPTO_TAG_ABILITY_NAME,
        value: StringToUint8Array("CryptoExtension")
      }
    ];

    /* 2. Call unregisterProvider. */
    await huksExternalCrypto.unregisterProvider(providerName, extProperties)
      .then(() => {
        console.info('promise: unregisterProvider success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: unregisterProvider failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: unregisterProvider input arg invalid.');
  }
}

async function TestRegisterProvider() {
  await unregisterProvider();
}
```

**Batch unregistration**

```ts
import { huksExternalCrypto } from '@kit.UniversalKeystoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function unregisterProvider(): Promise<void> {
  try {
    /* 1. Construct unregistration parameters. */
    const providerName = "testProvider";
    const extProperties: Array<huksExternalCrypto.HuksExternalCryptoParam> = [];

    /* 2. Call unregisterProvider. */
    await huksExternalCrypto.unregisterProvider(providerName, extProperties)
      .then(() => {
        console.info('promise: unregisterProvider success.');
      }).catch((error: BusinessError) => {
        console.error(`promise: unregisterProvider failed, errCode : ${error.code}, errMsg : ${error.message}`);
      });
  } catch (error) {
    console.error('promise: unregisterProvider input arg invalid.');
  }
}

async function TestRegisterProvider() {
  await unregisterProvider();
}
```
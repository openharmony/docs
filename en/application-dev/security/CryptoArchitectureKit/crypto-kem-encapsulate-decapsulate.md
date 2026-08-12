# Key Encapsulation and Decapsulation Using KEM (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:43:17.521Z pushedAt=2026-07-15T09:44:33.395Z -->

Starting from API version 26.0.0, key encapsulation and decapsulation using the Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM) algorithm is supported. For the corresponding algorithm specifications, see [KEM Encapsulation and Decapsulation Algorithm Specifications](#algorithm-specifications).

ML-KEM is a lattice-based post-quantum key encapsulation mechanism used to securely negotiate a shared secret over an insecure channel. The encapsulating party uses the public key to generate a shared secret and an encapsulated key, while the decapsulating party uses the private key and the encapsulated key to recover the same shared secret.

## Algorithm Specifications

| Algorithm | KEM Value | API Version |
| --------- | --------------------- | ----------- |
| ML-KEM | ML_KEM_512   | 26.0.0+ |
| ML-KEM | ML_KEM_768   | 26.0.0+ |
| ML-KEM | ML_KEM_1024  | 26.0.0+ |

## How to Develop

**Encapsulation**

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate an asymmetric key pair (**KeyPair**) with the ML-KEM algorithm.

2. Call [cryptoFramework.createKem](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekem) with the algorithm parameter set to **KemAlgNameId.ML_KEM_768** to create a Kem instance.

3. Call [Kem.encapsulate](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#encapsulate) to perform key encapsulation based on the passed-in public key (**KeyPair.pubKey**), which returns the encapsulation result ([KemEncapResult](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#kemencapresult)).

   [KemEncapResult](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#kemencapresult) contains **sharedSecret** (shared secret) and **wrappedKey** (encapsulated key). The encapsulating party retains **sharedSecret** and sends **wrappedKey** to the decapsulating party. When the **ikme** parameter is passed as **null**, the algorithm library internally generates a random ephemeral key.

**Decapsulation**

1. Call [cryptoFramework.createKem](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekem) and specify the algorithm parameter as **KemAlgNameId.ML_KEM_768** to create a Kem instance.

2. Call [Kem.decapsulate](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#decapsulate) to perform key decapsulation based on the passed-in private key (**KeyPair.priKey**) and the encapsulated key (**wrappedKey**), which returns the shared secret.

The shared secret obtained from decapsulation should be consistent with the shared secret generated during encapsulation.

## Development Examples

- Asynchronous method example:

  <!-- @[kem_encapsulate_decapsulate_await_test](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/KemEncapsulateDecapsulate/entry/src/main/ets/pages/Await.ets) -->

  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  
  namespace Kem {
    export async function kemDecapsulateAwait() {
      let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
      let keyPair = await asyKeyGenerator.generateKeyPair();
      let kem : cryptoFramework.Kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
      try {
        let encapResult : cryptoFramework.KemEncapResult = await kem.encapsulate(keyPair.pubKey, null);
        let sharedSecret : Uint8Array = await kem.decapsulate(keyPair.priKey, encapResult.wrappedKey);
        console.info('decapsulate success');
        console.info('sharedSecret length: ' + sharedSecret.length);
        return 'Success';
      } catch (err) {
        let e: BusinessError = err as BusinessError;
        console.error(`decapsulate failed: errCode: ${e.code}, errMsg: ${e.message}`);
        return 'Failed';
      }
    }
  }
  ```

- Synchronous method example:

  <!-- @[kem_encapsulate_decapsulate_sync_test](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/KemEncapsulateDecapsulate/entry/src/main/ets/pages/Sync.ets) -->

  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  
  namespace Kem {
    export function kemDecapsulateSync() {
      let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
      let keyPair = asyKeyGenerator.generateKeyPairSync();
      let kem : cryptoFramework.Kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
      try {
        let encapResult : cryptoFramework.KemEncapResult= kem.encapsulateSync(keyPair.pubKey, null);
        let sharedSecret : Uint8Array = kem.decapsulateSync(keyPair.priKey, encapResult.wrappedKey);
        console.info('decapsulateSync success');
        console.info('sharedSecret length: ' + sharedSecret.length);
        return 'Success';
      } catch (err) {
        let e: BusinessError = err as BusinessError;
        console.error(`decapsulateSync failed: errCode: ${e.code}, errMsg: ${e.message}`);
        return 'Failed';
      }
    }
  }
  ```

  <!--no_check-->
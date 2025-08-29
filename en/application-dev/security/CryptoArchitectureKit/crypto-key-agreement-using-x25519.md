# Key Agreement Using X25519 (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [X25519](crypto-key-agreement-overview.md#x25519).

## How to Develop

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator), [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1), and [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to generate an X25519 asymmetric key pair (**KeyPair**).
   In addition to the example in this topic, [X25519](crypto-asym-key-generation-conversion-spec.md#x25519) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an X25519 asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createKeyAgreement](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekeyagreement) with the string parameter **'X25519'** to create an X25519 key agreement (**KeyAgreement**) instance.

3. Call [KeyAgreement.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret-1) to perform key agreement with the specified private key (**KeyPair.priKey**) and public key (**KeyPair.pubKey**), and return the shared secret.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function x25519Await() {
    // The public and private key pair data is transferred from an external system.
    let pubKeyArray = new Uint8Array([48, 42, 48, 5, 6, 3, 43, 101, 110, 3, 33, 0, 36, 98, 216, 106, 74, 99, 179, 203, 81, 145, 147, 101, 139, 57, 74, 225, 119, 196, 207, 0, 50, 232, 93, 147, 188, 21, 225, 228, 54, 251, 230, 52]);
    let priKeyArray = new Uint8Array([48, 46, 2, 1, 0, 48, 5, 6, 3, 43, 101, 110, 4, 34, 4, 32, 112, 65, 156, 73, 65, 89, 183, 39, 119, 229, 110, 12, 192, 237, 186, 153, 21, 122, 28, 176, 248, 108, 22, 242, 239, 179, 106, 175, 85, 65, 214, 90]);
    let keyGen = cryptoFramework.createAsyKeyGenerator('X25519');
    // Key pair A transferred from an external system.
    let keyPairA = await keyGen.convertKey({ data: pubKeyArray }, { data: priKeyArray });
    // Key pair B generated internally.
    let keyPairB = await keyGen.generateKeyPair();
    let keyAgreement = cryptoFramework.createKeyAgreement('X25519');
    // Use the public key of A and the private key of B to perform key agreement.
    let secret1 = await keyAgreement.generateSecret(keyPairB.priKey, keyPairA.pubKey);
    // Use the private key of A and the public key of B to perform key agreement.
    let secret2 = await keyAgreement.generateSecret(keyPairA.priKey, keyPairB.pubKey);
    // The two key agreement results should be the same.
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('x25519 success');
      console.info('x25519 output is ' + secret1.data);
    } else {
      console.error('x25519 result is not equal');
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function x25519AgreementSync() {
    // The public and private key pair data is transferred from an external system.
    let pubKeyArray = new Uint8Array([48, 42, 48, 5, 6, 3, 43, 101, 110, 3, 33, 0, 36, 98, 216, 106, 74, 99, 179, 203, 81, 145, 147, 101, 139, 57, 74, 225, 119, 196, 207, 0, 50, 232, 93, 147, 188, 21, 225, 228, 54, 251, 230, 52]);
    let priKeyArray = new Uint8Array([48, 46, 2, 1, 0, 48, 5, 6, 3, 43, 101, 110, 4, 34, 4, 32, 112, 65, 156, 73, 65, 89, 183, 39, 119, 229, 110, 12, 192, 237, 186, 153, 21, 122, 28, 176, 248, 108, 22, 242, 239, 179, 106, 175, 85, 65, 214, 90]);
    let keyGen = cryptoFramework.createAsyKeyGenerator('X25519');
    // Key pair A transferred from an external system.
    let keyPairA = keyGen.convertKeySync({ data: pubKeyArray }, { data: priKeyArray });
    // Key pair B generated internally.
    let keyPairB = keyGen.generateKeyPairSync();
    let keyAgreement = cryptoFramework.createKeyAgreement('X25519');
    // Use the public key of A and the private key of B to perform key agreement.
    let secret1 = keyAgreement.generateSecretSync(keyPairB.priKey, keyPairA.pubKey);
    // Use the private key of A and the public key of B to perform key agreement.
    let secret2 = keyAgreement.generateSecretSync(keyPairA.priKey, keyPairB.pubKey);
    // The two key agreement results should be the same.
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('x25519 success');
      console.info('x25519 output is ' + secret1.data);
    } else {
      console.error('x25519 result is not equal');
    }
  }
  ```

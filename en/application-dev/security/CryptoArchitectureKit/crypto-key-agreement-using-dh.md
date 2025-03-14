# Key Agreement Using DH


For details about the algorithm specifications, see [DH](crypto-key-agreement-overview.md#dh).


## How to Develop

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a DH asymmetric key pair (**KeyPair**) with the named DH group **modp1536**.
   In addition to the example in this topic, [DH](crypto-asym-key-generation-conversion-spec.md#dh) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate a DH asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createKeyAgreement](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekeyagreement) with the string parameter **'DH_modp1536'** to create a key agreement (**KeyAgreement**) instance.

3. Call [KeyAgreement.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret-1) to perform key agreement with the specified private key (**KeyPair.priKey**) and public key (**KeyPair.pubKey**), and return the shared secret.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function dhAwait() {
    let keyGen = cryptoFramework.createAsyKeyGenerator('DH_modp1536');
    // Randomly generate public-private key pair A.
    let keyPairA = await keyGen.generateKeyPair();
    // Randomly generate public-private key pair B with the same specifications.
    let keyPairB = await keyGen.generateKeyPair();
    let keyAgreement = cryptoFramework.createKeyAgreement('DH_modp1536');
    // Use the public key of A and the private key of B to perform key agreement.
    let secret1 = await keyAgreement.generateSecret(keyPairB.priKey, keyPairA.pubKey);
    // Use the private key of A and the public key of B to perform key agreement.
    let secret2 = await keyAgreement.generateSecret(keyPairA.priKey, keyPairB.pubKey);
    // The two key agreement results should be the same.
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('DH success');
      console.info('DH output is ' + secret1.data);
    } else {
      console.error('DH result is not equal');
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function dhAgreementSync() {
    let keyGen = cryptoFramework.createAsyKeyGenerator('DH_modp1536');
    // Randomly generate public-private key pair A.
    let keyPairA = keyGen.generateKeyPairSync();
    // Randomly generate public-private key pair B with the same specifications.
    let keyPairB = keyGen.generateKeyPairSync();
    let keyAgreement = cryptoFramework.createKeyAgreement('DH_modp1536');
    // Use the public key of A and the private key of B to perform key agreement.
    let secret1 = keyAgreement.generateSecretSync(keyPairB.priKey, keyPairA.pubKey);
    // Use the private key of A and the public key of B to perform key agreement.
    let secret2 = keyAgreement.generateSecretSync(keyPairA.priKey, keyPairB.pubKey);
    // The two key agreement results should be the same.
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('DH success');
      console.info('DH output is ' + secret1.data);
    } else {
      console.error('DH result is not equal');
    }
  }
  ```

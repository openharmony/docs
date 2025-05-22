# Randomly Generating an Asymmetric Key Pair (ArkTS)

This topic uses RSA and SM2 as an example to describe how to generate an asymmetric key pair (**KeyPair**) and obtain the binary data.

The **KeyPair** object created can be used for subsequent encryption and decryption operations, and the binary data can be used for key storage and transfer.

## Randomly Generating an RSA Key Pair

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'RSA1024|PRIMES_2'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 1024-bit RSA key with two primes.

2. Call [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to randomly generate an asymmetric key pair (**KeyPair**).
   
   The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

3. Call [PubKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the public key, and call [PriKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the private key.

- Example: Randomly generate an RSA key pair (using promise-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function generateAsyKey() {
    // Create an AsyKeyGenerator instance.
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
    // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
    let keyGenPromise = rsaGenerator.generateKeyPair();
    keyGenPromise.then(keyPair => {
      let pubKey = keyPair.pubKey;
      let priKey = keyPair.priKey;
      // Obtain the binary data of the asymmetric key pair.
      let pkBlob = pubKey.getEncoded();
      let skBlob = priKey.getEncoded();
      console.info('pk bin data' + pkBlob.data);
      console.info('sk bin data' + skBlob.data);
    });
  }
  ```

- Example: Randomly generate an RSA key pair (using the synchronous API [generateKeyPairSync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypairsync12)).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function generateAsyKeySync() {
    // Create an AsyKeyGenerator instance.
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
    // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
    try {
      let keyPair = rsaGenerator.generateKeyPairSync();
      if (keyPair !== null) {
        let pubKey = keyPair.pubKey;
        let priKey = keyPair.priKey;
        // Obtain the binary data of the asymmetric key pair.
        let pkBlob = pubKey.getEncoded();
        let skBlob = priKey.getEncoded();
        console.info('pk bin data' + pkBlob.data);
        console.info('sk bin data' + skBlob.data);
      } else {
        console.error("[Sync]: get key pair result fail!");
      }
    } catch (e) {
      console.error(`get key pair failed, ${e.code}, ${e.message}`);
    }
  }
  ```

## Randomly Generating an SM2 Key Pair

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'SM2_256'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit SM2 key pair.

2. Call [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to randomly generate an asymmetric key pair (**KeyPair**).
   
   The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

3. Call [PubKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the public key, and call [PriKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the private key.

- Example: Randomly generate an SM2 key pair (using promise-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function generateSM2Key() {
    // Create an AsyKeyGenerator instance.
    let sm2Generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
    let keyGenPromise = sm2Generator.generateKeyPair();
    keyGenPromise.then(keyPair => {
      let pubKey = keyPair.pubKey;
      let priKey = keyPair.priKey;
      // Obtain the binary data of the asymmetric key pair.
      let pkBlob = pubKey.getEncoded();
      let skBlob = priKey.getEncoded();
      console.info('pk bin data' + pkBlob.data);
      console.info('sk bin data' + skBlob.data);
    });
  }
  ```

- Example: Randomly generate an SM2 key pair (using the synchronous API [generateKeyPairSync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypairsync12)).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function generateSM2KeySync() {
    // Create an AsyKeyGenerator instance.
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
    try {
      let keyPair = rsaGenerator.generateKeyPairSync();
      if (keyPair !== null) {
        let pubKey = keyPair.pubKey;
        let priKey = keyPair.priKey;
        // Obtain the binary data of the asymmetric key pair.
        let pkBlob = pubKey.getEncoded();
        let skBlob = priKey.getEncoded();
        console.info('pk bin data' + pkBlob.data);
        console.info('sk bin data' + skBlob.data);
      } else {
        console.error("[Sync]: get key pair result fail!");
      }
    } catch (e) {
      console.error(`get key pair failed, ${e.code}, ${e.message}`);
    }
  }
  ```

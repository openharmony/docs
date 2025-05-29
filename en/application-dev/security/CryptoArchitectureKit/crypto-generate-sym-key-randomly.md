# Randomly Generating a Symmetric Key (ArkTS)


This topic uses AES and SM4 as an example to describe how to generate a symmetric key and obtain the binary data.


The symmetric key (**SymKey**) object created can be used for subsequent encryption and decryption operations, and the binary data can be used for key storage and transfer.


## Randomly Generating an AES Key

For details about the algorithm specifications, see [AES](crypto-sym-key-generation-conversion-spec.md#aes).

1. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) with the string parameter **'AES256'** to create a symmetric key generator (**SymKeyGenerator**) object for a 256-bit AES key.

2. Call [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to randomly generate a symmetric key (**SymKey**) object.

3. Call [SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the key.

- Example: Randomly generate a 256-bit AES key (using promise-based APIs).

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testGenerateAesKey() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
    // Use SymKeyGenerator to randomly generate a symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKey();
    promiseSymKey.then(key => {
      // Obtain the binary data of the symmetric key and output a 256-bit key, which is of 32 bytes.
      let encodedKey = key.getEncoded();
      console.info('key hex:' + encodedKey.data);
    });
  }
  ```

- Example using synchronous API [generateSymKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkeysync12):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testSyncGenerateAesKey() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
    // Use SymKeyGenerator to randomly generate a symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKeySync();
    // Obtain the binary data of the symmetric key and output a 256-bit key, which is of 32 bytes.
    let encodedKey = promiseSymKey.getEncoded();
    console.info('key hex:' + encodedKey.data);
  }
  ```


## Randomly Generating an SM4 Key

For details about the algorithm specifications, see [SM4](crypto-sym-key-generation-conversion-spec.md#sm4).

1. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) with the string parameter **'SM4_128'** to create a symmetric key generator (**SymKeyGenerator**) object for a 128-bit SM4 key.
   If you need to use other algorithms, modify the string parameter.

2. Call [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to randomly generate a symmetric key (**SymKey**) object.

3. Call [SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the key.

- Example: Randomly generate a 128-bit SM4 key (using promise-based APIs).

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testGenerateSM4Key() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    // Use SymKeyGenerator to randomly generate a symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKey();
    promiseSymKey.then(key => {
      // Obtain the binary data of the symmetric key and output a 128-bit byte stream, which is of 16 bytes.
      let encodedKey = key.getEncoded();
      console.info('key hex:' + encodedKey.data);
    });
  }
  ```

- Example using synchronous API [generateSymKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkeysync12):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testSyncGenerateSm4Key() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    // Use SymKeyGenerator to randomly generate a symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKeySync();
    // Obtain the binary data of the symmetric key and output a 128-bit byte stream, which is of 16 bytes.
    let encodedKey = promiseSymKey.getEncoded();
    console.info('key hex:' + encodedKey.data);
  }
  ```

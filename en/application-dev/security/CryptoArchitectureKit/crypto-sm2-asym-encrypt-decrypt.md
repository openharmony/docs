# Encryption and Decryption with an SM2 Asymmetric Key Pair


For details about the algorithm specifications, see [SM2](crypto-asym-encrypt-decrypt-spec.md#sm2).


**Encryption**


1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to create a 256-bit SM2 asymmetric key pair (**KeyPair**). The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).
   
   In addition to the example in this topic, [SM2](crypto-asym-key-generation-conversion-spec.md#sm2) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an SM2 asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'SM2_256|SM3'** to create a **Cipher** instance. The key type is **SM2_256**, and the MD algorithm is **SM3**.

3. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption) and **key** to **KeyPair.PubKey** (the key used for encryption).
   
   No encryption parameter is required for asymmetric key pairs. Therefore, pass in **null** in **params**.

4. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to pass in the plaintext and encrypt it.
   
   - The output of **Cipher.doFinal** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.
   - If a large amount of data is to be encrypted, you can call **Cipher.doFinal** multiple times to pass in the data by segment.


**Decryption**


1. If SM2 is used, the **Cipher** instance cannot be initialized repeatedly. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) to create a new **Cipher** instance.

2. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption) and **key** to **KeyPair.PriKey** (the key used for decryption). If SM2 is used, no decryption parameter is required. Therefore, pass in **null** in **params**.

3. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to pass in the ciphertext and decrypt it.


- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  // Encrypt the message.
  async function encryptMessagePromise(publicKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM2_256|SM3');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, publicKey, null);
    let encryptData = await cipher.doFinal(plainText);
    return encryptData;
  }
  // Decrypt the message.
  async function decryptMessagePromise(privateKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM2_256|SM3');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, privateKey, null);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  // Generate an SM2 key pair.
  async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
    let sm2Generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    let keyPair = await sm2Generator.convertKey(pubKeyBlob, priKeyBlob);
    console.info('convertKey success');
    return keyPair;
  }
  async function main() {
    let pkData = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45, 3, 66, 0, 4, 90, 3, 58, 157, 190, 248, 76, 7, 132, 200, 151, 208, 112, 230, 96, 140, 90, 238, 211, 155, 128, 109, 248, 40, 83, 214, 78, 42, 104, 106, 55, 148, 249, 35, 61, 32, 221, 135, 143, 100, 45, 97, 194, 176, 52, 73, 136, 174, 40, 70, 70, 34, 103, 103, 161, 99, 27, 187, 13, 187, 109, 244, 13, 7]);
    let skData = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 54, 41, 239, 240, 63, 188, 134, 113, 31, 102, 149, 203, 245, 89, 15, 15, 47, 202, 170, 60, 38, 154, 28, 169, 189, 100, 251, 76, 112, 223, 156, 159, 160, 10, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45]);
    let keyPair = await genKeyPairByData(pkData, skData);
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    let message = 'This is a test';
    // Decode the string into a Uint8Array in UTF-8 format.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessagePromise(pubKey, plainText);
    let decryptText = await decryptMessagePromise(priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok');
      // Encode the Uint8Array into a string in UTF-8 format.
      let messageDecrypted = buffer.from(decryptText.data).toString('utf-8');
      console.info('decrypted result string:' + messageDecrypted);
    } else {
      console.error('decrypt failed');
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  // Encrypt the message.
  function encryptMessage(publicKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM2_256|SM3');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, publicKey, null);
    let encryptData = cipher.doFinalSync(plainText);
    return encryptData;
  }
  // Decrypt the message.
  function decryptMessage(privateKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM2_256|SM3');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, privateKey, null);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  // Generate an SM2 key pair.
  function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
    let sm2Generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    let keyPair = sm2Generator.convertKeySync(pubKeyBlob, priKeyBlob);
    console.info('convertKeySync success');
    return keyPair;
  }
  function main() {
    let pkData = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45, 3, 66, 0, 4, 90, 3, 58, 157, 190, 248, 76, 7, 132, 200, 151, 208, 112, 230, 96, 140, 90, 238, 211, 155, 128, 109, 248, 40, 83, 214, 78, 42, 104, 106, 55, 148, 249, 35, 61, 32, 221, 135, 143, 100, 45, 97, 194, 176, 52, 73, 136, 174, 40, 70, 70, 34, 103, 103, 161, 99, 27, 187, 13, 187, 109, 244, 13, 7]);
    let skData = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 54, 41, 239, 240, 63, 188, 134, 113, 31, 102, 149, 203, 245, 89, 15, 15, 47, 202, 170, 60, 38, 154, 28, 169, 189, 100, 251, 76, 112, 223, 156, 159, 160, 10, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45]);
    let keyPair = genKeyPairByData(pkData, skData);
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    let message = 'This is a test';
    // Decode the string into a Uint8Array in UTF-8 format.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessage(pubKey, plainText);
    let decryptText = decryptMessage(priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok');
      // Encode the Uint8Array into a string in UTF-8 format.
      let messageDecrypted = buffer.from(decryptText.data).toString('utf-8');
      console.info('decrypted result string:' + messageDecrypted);
    } else {
      console.error('decrypt failed');
    }
  }
  ```

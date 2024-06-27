# Encryption and Decryption by Segment with an RSA Asymmetric Key Pair


For details about the algorithm specifications, see [RSA](crypto-asym-encrypt-decrypt-spec.md#rsa).


**Encryption**


1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 1024-bit RSA asymmetric key pair (**KeyPair**) with two primes. The number of primes is not specified by default. The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).
   
   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'RSA1024|PKCS1'** to create a **Cipher** instance for encryption. The key type is **RSA1024**, and the padding mode is **PKCS1**.

3. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption) and **key** to **KeyPair.PubKey** (the key used for encryption).

4. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) multiple times to pass in the plaintext and encrypt it by segment.
   
   The output of **doFinal** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.

   In this example, the plaintext is split by 64 bytes and encrypted multiple times by a 1024-bit key. A 128-byte ciphertext is generated each time.


**Decryption**


1. If RSA is used, the **Cipher** instance cannot be initialized repeatedly. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) to create a new **Cipher** instance.

2. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption) and **key** to **KeyPair.PriKey** (the key used for decryption). When PKCS1 mode is used, pass in **null** in **params**.

3. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) multiple times to pass in the ciphertext and decrypt it by segment.


- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // Encrypt the message by segment.
  async function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen ) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen );
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Split the plaintext by 64 bytes and cyclically call doFinal() to encrypt the plaintext using a 1024-bit key. A 128-byte ciphertext is generated each time.
      let updateOutput = await cipher.doFinal(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // Decrypt the message by segment.
  async function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // Length of the ciphertext = Number of key bits/8
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Split the ciphertext by 128 bytes, decrypt the ciphertext, and combine the plaintext obtained each time.
      let updateOutput = await decoder.doFinal(updateMessageBlob);
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  async function rsaEncryptLongMessage() {
    let message = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024");  // Create an AsyKeyGenerator object.
    let keyPair = await asyKeyGenerator.generateKeyPair(); // Randomly generate an RSA key pair.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await rsaEncryptBySegment(keyPair.pubKey, plainText);
    let decryptText = await rsaDecryptBySegment(keyPair.priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed');
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // Encrypt the message by segment.
  function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen ) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen );
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Split the plaintext by 64 bytes and cyclically call doFinal() to encrypt the plaintext using a 1024-bit key. The ciphertext of 128 bytes is generated each time.
      let updateOutput = cipher.doFinalSync(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // Decrypt the message by segment.
  function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // Length of the ciphertext = Number of key bits/8
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Split the ciphertext by 128 bytes, decrypt the ciphertext, and combine the plaintext obtained each time.
      let updateOutput = decoder.doFinalSync(updateMessageBlob);
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  async function main() {
    let message = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024");  // Create an AsyKeyGenerator object.
    let keyPair = await asyKeyGenerator.generateKeyPair(); // Randomly generate an RSA key pair.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = rsaEncryptBySegment(keyPair.pubKey, plainText);
    let decryptText = rsaDecryptBySegment(keyPair.priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed');
    }
  }
  ```

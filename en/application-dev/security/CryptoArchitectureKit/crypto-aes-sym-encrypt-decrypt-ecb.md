# Encryption and Decryption with an AES Symmetric Key (ECB Mode) (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details, see [AES](crypto-sym-encrypt-decrypt-spec.md#aes).

**Encryption**

1. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to generate a 128-bit AES symmetric key (**SymKey**).
   
   For details about how to generate an AES symmetric key, see the following example. To learn more, see [Symmetric Key Generation and Conversion Specifications: AES](crypto-sym-key-generation-conversion-spec.md#aes) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'AES128|ECB|PKCS7'** to create a **Cipher** instance for encryption. The key type is **AES128**, block cipher mode is **ECB**, and the padding mode is **PKCS7**.

3. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption), **key** to **SymKey** (the key for encryption), and **params** to **null** for the ECB mode.

4. If a small amount of data is to be encrypted, you can use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) after **Cipher.init** to obtain the encrypted data.

**Decryption**

1. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'AES128|ECB|PKCS7'** to create a **Cipher** instance for decryption. The key type is **AES128**, block cipher mode is **ECB**, and the padding mode is **PKCS7**.

2. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption), **key** to **SymKey** (the key for decryption), and **params** to **null** for the ECB mode.

3. If a small amount of data is to be decrypted, you can use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) after **Cipher.init** to obtain the decrypted data.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  // Encrypt the message.
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null); // If ECB mode is used, set params to null.
    let cipherData = await cipher.doFinal(plainText);
    return cipherData;
  }
  // Decrypt the message.
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null); // If ECB mode is used, set params to null.
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }

  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }

  async function aesECB() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = await genSymKeyByData(keyData);
      let message = "This is a test";
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = await encryptMessagePromise(symKey, plainText);
      let decryptText = await decryptMessagePromise(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed');
      }
    } catch (error) {
      console.error(`AES ECB "${error}", error code: ${error.code}`);
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  // Encrypt the message.
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null); // If ECB mode is used, set params to null.
    let cipherData = cipher.doFinalSync(plainText);
    return cipherData;
  }
  // Decrypt the message.
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null); // If ECB mode is used, set params to null.
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }

  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync success');
    return symKey;
  }

  function main() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = genSymKeyByData(keyData);
      let message = "This is a test";
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = encryptMessage(symKey, plainText);
      let decryptText = decryptMessage(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed');
      }
    } catch (error) {
      console.error(`AES ECB "${error}", error code: ${error.code}`);
    }
  }
  ```

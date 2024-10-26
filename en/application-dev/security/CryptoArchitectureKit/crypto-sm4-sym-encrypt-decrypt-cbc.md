# Encryption and Decryption with an SM4 Symmetric Key (CBC Mode) (ArkTS)


For details about the algorithm specifications, see [SM4](crypto-sym-encrypt-decrypt-spec.md#sm4).

**Encryption**


1. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to generate a 128-bit SM4 symmetric key (**SymKey**).
   
   In addition to the example in this topic, [SM4](crypto-sym-key-generation-conversion-spec.md#sm4) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly.md) may help you better understand how to generate an SM4 symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'SM4_128|CBC|PKCS7'** to create a **Cipher** instance. The key type is **SM4_128**, block cipher mode is **CBC**, and the padding mode is **PKCS7**.

3. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption), **key** to **SymKey** (the key for encryption), and **params** to **IvParamsSpec** corresponding to the CBC mode.

4. Use [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) to pass in the data to be encrypted (plaintext).
   
   - If a small amount of data is to be encrypted, you can use **Cipher.doFinal** immediately after **Cipher.init**.
   - If a large amount of data is to be encrypted, you can call **Cipher.update** multiple times to pass in the data by segment.

5. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the encrypted data.
   
   - If data has been passed in by **Cipher.update**, pass in **null** in the **data** parameter of **Cipher.doFinal**.
   - The output of **Cipher.doFinal** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.


**Decryption**


1. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption), **key** to **SymKey** (the key for decryption), and **params** to **IvParamsSpec** corresponding to the CBC mode.

2. Use [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) to pass in the data to be decrypted (ciphertext).

3. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the decrypted data.


- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function genIvParamsSpec() {
    let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
    let dataIv = new Uint8Array(arr);
    let ivBlob: cryptoFramework.DataBlob = { data: dataIv };
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: "IvParamsSpec",
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  // Encrypt the message.
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|CBC|PKCS7');
    let iv = genIvParamsSpec();
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let encryptData = await cipher.doFinal(plainText);
    return encryptData;
  }
  // Decrypt the message.
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|CBC|PKCS7');
    let iv = genIvParamsSpec();
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let symGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    let symKey = await symGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function main() {
    try {
      let keyData = new Uint8Array([7, 154, 52, 176, 4, 236, 150, 43, 237, 9, 145, 166, 141, 174, 224, 131]);
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
      console.error(`SM4 "${error}", error code: ${error.code}`);
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function genIvParamsSpec() {
    let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
    let dataIv = new Uint8Array(arr);
    let ivBlob: cryptoFramework.DataBlob = { data: dataIv };
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: "IvParamsSpec",
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  // Encrypt the message.
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|CBC|PKCS7');
    let iv = genIvParamsSpec();
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let encryptData = cipher.doFinalSync(plainText);
    return encryptData;
  }
  // Decrypt the message.
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|CBC|PKCS7');
    let iv = genIvParamsSpec();
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let symGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    let symKey = symGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function main() {
    try {
      let keyData = new Uint8Array([7, 154, 52, 176, 4, 236, 150, 43, 237, 9, 145, 166, 141, 174, 224, 131]);
      let symKey = await genSymKeyByData(keyData);
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
      console.error(`SM4 "${error}", error code: ${error.code}`);
    }
  }
  ```

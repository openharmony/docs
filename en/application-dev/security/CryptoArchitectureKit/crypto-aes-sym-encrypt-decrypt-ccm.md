# Encryption and Decryption with an AES Symmetric Key (CCM Mode) (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details, see [AES](crypto-sym-encrypt-decrypt-spec.md#aes).

**Encryption**

1. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to generate a 128-bit AES symmetric key (**SymKey**).
   
   In addition to the example in this topic, [AES](crypto-sym-key-generation-conversion-spec.md#aes) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly.md) may help you better understand how to generate an AES symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'AES128|CCM'** to create a **Cipher** instance for encryption. The key type is AES128, and the block cipher mode is CCM.

3. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption), **key** to **SymKey**, and **params** to **CcmParamsSpec** corresponding to the CCM mode.

4. Call [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) to pass in the data to be encrypted (plaintext).

   Currently, there is no length limit for a single update. You can call **Cipher.update** based on the data volume.
  
   > **NOTE**<br>
   > The CCM mode does not support segment-based encryption and decryption.

5. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the encrypted data.
   - If data has been passed in by **Cipher.update**, pass in **null** in this step.
   - The output of **Cipher.doFinal** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.

6. Obtain [CcmParamsSpec.authTag](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ccmparamsspec) as the authentication information for decryption.

    In CCM mode, the algorithm library supports only 12-byte **authTag**, which is used for initialization authentication during decryption. In the following example, **authTag** is of 12 bytes.

**Decryption**

1. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'AES128|CCM'** to create a **Cipher** instance for decryption. The key type is AES128, and the block cipher mode is CCM.

2. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption), **key** to **SymKey**, and **params** to **CcmParamsSpec** corresponding to the CCM mode.

3. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the decrypted data.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function genCcmParamsSpec() {
    let rand: cryptoFramework.Random = cryptoFramework.createRandom();
    let ivBlob: cryptoFramework.DataBlob = rand.generateRandomSync(7);
    let aadBlob: cryptoFramework.DataBlob = rand.generateRandomSync(8);
    let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 12 bytes
    let dataTag = new Uint8Array(arr);
    let tagBlob: cryptoFramework.DataBlob = {
      data: dataTag
    };
    // Obtain the CCM authTag from the Cipher.doFinal result in encryption and fill it in the params parameter of Cipher.init in decryption.
    let ccmParamsSpec: cryptoFramework.CcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "CcmParamsSpec"
    };
    return ccmParamsSpec;
  }
  let ccmParams = genCcmParamsSpec();

  // Encrypt the message.
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, ccmParams);
    let encryptUpdate = await cipher.update(plainText);
    // In CCM mode, pass in null in Cipher.doFinal in encryption. Obtain the tag data and fill it in the ccmParams object.
    ccmParams.authTag = await cipher.doFinal(null);
    return encryptUpdate;
  }
  // Decrypt the message.
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CCM');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, ccmParams);
    let decryptUpdate = await decoder.doFinal(cipherText);
    return decryptUpdate;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function main() {
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
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';


  function genCcmParamsSpec() {
    let rand: cryptoFramework.Random = cryptoFramework.createRandom();
    let ivBlob: cryptoFramework.DataBlob = rand.generateRandomSync(7);
    let aadBlob: cryptoFramework.DataBlob = rand.generateRandomSync(8);
    let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 12 bytes
    let dataTag = new Uint8Array(arr);
    let tagBlob: cryptoFramework.DataBlob = {
      data: dataTag
    };
    // Obtain the CCM authTag from the Cipher.doFinal result in encryption and fill it in the params parameter of Cipher.init in decryption.
    let ccmParamsSpec: cryptoFramework.CcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "CcmParamsSpec"
    };
    return ccmParamsSpec;
  }

  let ccmParams = genCcmParamsSpec();

  // Encrypt the message.
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, ccmParams);
    let encryptUpdate = cipher.updateSync(plainText);
    // In CCM mode, pass in null in Cipher.doFinal in encryption. Obtain the tag data and fill it in the ccmParams object.
    ccmParams.authTag = cipher.doFinalSync(null);
    return encryptUpdate;
  }
  // Decrypt the message.
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CCM');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, ccmParams);
    let decryptUpdate = decoder.doFinalSync(cipherText);
    return decryptUpdate;
  }
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync success');
    return symKey;
  }
  function main() {
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
  }
  ```

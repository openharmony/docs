# Encryption and Decryption by Segment with an SM4 Symmetric Key (GCM Mode) (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [SM4](crypto-sym-encrypt-decrypt-spec.md#sm4).

**Encryption**

1. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1) to generate a 128-bit SM4 symmetric key (**SymKey**).
   
   In addition to the example in this topic, [SM4](crypto-sym-key-generation-conversion-spec.md#sm4) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly.md) may help you better understand how to generate an SM4 symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'SM4_128|GCM|PKCS7'** to create a **Cipher** instance for encryption. The key type is **SM4_128**, block cipher mode is **GCM**, and the padding mode is **PKCS7**.

3. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption), **key** to **SymKey** (the key for encryption), and **params** to **GcmParamsSpec** corresponding to the GCM mode.

4. Set the size of the data to be passed in each time to 20 bytes, and call [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) multiple times to pass in the data (plaintext) to be encrypted.
   
   - Currently, the amount of data to be passed in by a single **update()** is not limited. You can determine how to pass in data based on the data volume.
   - You are advised to check the result of each **update()**. If the result is not **null**, obtain the data and combine the data segments into complete ciphertext. The **update()** result may vary with the key specifications.
      
      If a block cipher mode (ECB or CBC) is used, data is encrypted and output based on the block size. That is, if the data of an **update()** operation matches the block size, the ciphertext is output. Otherwise, **null** is output, and the plaintext will be combined with the input data of the next **update()** to form a block. When **doFinal** is called, the unencrypted data is padded to the block size based on the specified padding mode, and then encrypted. The **update()** API works in the same way in decryption.

      If a stream cipher mode (CTR or OFB) is used, the ciphertext length is usually the same as the plaintext length.

5. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the encrypted data.
   
   - If data has been passed in by **update()**, pass in **null** in the **data** parameter of **Cipher.doFinal**.
   - The output of **doFinal** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.

6. Obtain [GcmParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#gcmparamsspec).authTag as the authentication information for decryption.
   
   In GCM mode, extract the last 16 bytes from the encrypted data as the authentication information for initializing the **Cipher** instance in decryption. In the example, **authTag** is of 16 bytes.

**Decryption**

1. Call [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'SM4_128|GCM|PKCS7'** to create a **Cipher** instance for decryption. The key type is **SM4_128**, block cipher mode is **GCM**, and the padding mode is **PKCS7**.

2. Call [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption), **key** to **SymKey** (the key for decryption), and **params** to **GcmParamsSpec** corresponding to the GCM mode.

3. Set the size of the data to be passed in each time to 20 bytes, and call [Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1) multiple times to pass in the data (ciphertext) to be decrypted.

4. Call [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to obtain the decrypted data.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }

  function genGcmParamsSpec() {
    let ivBlob = generateRandom(12);
    let arr = [1, 2, 3, 4, 5, 6, 7, 8]; // 8 bytes
    let dataAad = new Uint8Array(arr);
    let aadBlob: cryptoFramework.DataBlob = { data: dataAad };
    arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
    let dataTag = new Uint8Array(arr);
    let tagBlob: cryptoFramework.DataBlob = {
      data: dataTag
    }; // The GCM authTag is obtained by doFinal() in encryption and passed in params of init() in decryption.
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "GcmParamsSpec"
    };
    return gcmParamsSpec;
  }
  let gcmParams = genGcmParamsSpec();
  // Encrypt the message by segment.
  async function encryptMessageUpdateBySegment(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += updateLength) {
      let updateMessage = plainText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      let updateOutput = await cipher.update(updateMessageBlob);
      // Combine the result of each update() to obtain the ciphertext. In certain cases, the doFinal() result also needs to be combined, which depends on the cipher block mode
      // and padding mode you use. In this example, the GCM mode is used, and the doFinal() result contains authTag but not ciphertext. Therefore, there is no need to combine the doFinal() result.
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    gcmParams.authTag = await cipher.doFinal(null);
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // Decrypt the message by segment.
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += updateLength) {
      let updateMessage = cipherText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      let updateOutput = await decoder.update(updateMessageBlob);
      // Combine the update() results to obtain the plaintext.
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptData = await decoder.doFinal(null);
    if (decryptData === null) {
      console.info('GCM decrypt success, decryptData is null');
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let sm4Generator = cryptoFramework.createSymKeyGenerator('SM4_128');
    let symKey = await sm4Generator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function sm4() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = await genSymKeyByData(keyData);
    let message = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // The message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessageUpdateBySegment(symKey, plainText);
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

  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }

  function genGcmParamsSpec() {
    let ivBlob = generateRandom(12); // 12 bytes
    let arr = [1, 2, 3, 4, 5, 6, 7, 8]; // 8 bytes
    let dataAad = new Uint8Array(arr);
    let aadBlob: cryptoFramework.DataBlob = { data: dataAad };
    arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
    let dataTag = new Uint8Array(arr);
    let tagBlob: cryptoFramework.DataBlob = {
      data: dataTag
    }; // The GCM authTag is obtained by doFinal() in encryption and passed in params of init() in decryption.
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "GcmParamsSpec"
    };
    return gcmParamsSpec;
  }
  let gcmParams = genGcmParamsSpec();
  // Encrypt the message by segment.
  function encryptMessageUpdateBySegment(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += updateLength) {
      let updateMessage = plainText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      let updateOutput = cipher.updateSync(updateMessageBlob);
      // Combine the result of each update() to obtain the ciphertext. In certain cases, the doFinal() result also needs to be combined, which depends on the cipher block mode
      // and padding mode you use. In this example, the GCM mode is used, and the doFinal() result contains authTag but not ciphertext. Therefore, there is no need to combine the doFinal() result.
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    gcmParams.authTag = cipher.doFinalSync(null);
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // Decrypt the message by segment.
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += updateLength) {
      let updateMessage = cipherText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      let updateOutput = decoder.updateSync(updateMessageBlob);
      // Combine the update() results to obtain the plaintext.
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptData = decoder.doFinalSync(null);
    if (decryptData === null) {
      console.info('GCM decrypt success, decryptData is null');
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let sm4Generator = cryptoFramework.createSymKeyGenerator('SM4_128');
    let symKey = sm4Generator.convertKeySync(symKeyBlob);
    console.info('convertKeySync success');
    return symKey;
  }
  function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = genSymKeyByData(keyData);
    let message = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // The message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessageUpdateBySegment(symKey, plainText);
    let decryptText = decryptMessage(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed');
    }
  }

  ```

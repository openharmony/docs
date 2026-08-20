# 使用AES对称密钥加解密(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

对应的算法规格请查看[对称密钥加解密算法规格：AES](crypto-encryption-decryption.md#aes)。

## 使用AES对称密钥（GCM模式）加解密

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。然后调用[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)生成对称密钥。
   
   如何生成AES对称密钥，开发者可以参考以下示例，并结合[对称密钥生成和转换规格：AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|GCM'，创建对称密钥类型为AES128、分组模式为GCM的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和GCM模式对应的加密参数（GcmParamsSpec），以初始化加密Cipher实例。

4. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。
   
   当前单次update无长度限制，开发者可根据数据量调用update。

   - 当数据量较小时，可以在init完成后直接调用doFinal。
   - 当数据量较大时，可以多次调用update，即分段加解密，请参考[使用aes对称密钥gcm模式分段加解密](crypto-aes-sym-encrypt-decrypt.md#使用aes对称密钥gcm模式分段加解密)。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。注意，由于已使用update传入数据，此处data传入null。doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

6. 读取[GcmParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#gcmparamsspec).authTag作为解密的认证信息。

   > **说明：**
   >
   > 在GCM模式下，一次加密流程中，将每次update和最后doFinal的结果拼接起来，会得到“密文 + authTag”，authTag为末尾的16字节。其余部分均为密文。如果doFinal的data参数传入null，则doFinal的结果就是authTag。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|GCM'，创建对称密钥类型为AES128、分组模式为GCM的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和GCM模式对应的解密参数（GcmParamsSpec），初始化解密Cipher实例。

3. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（密文）。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（GCM模式）解密失败返回错误码17630001可参考[使用AES-GCM算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-gcm算法解密时调用dofinal失败)

- 异步方法示例：

  <!-- @[gcm_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_gcm_encryption_decryption/aes_gcm_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
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
    };
    // GCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: 'GcmParamsSpec'
    };
    return gcmParamsSpec;
  }
  
  let gcmParams = genGcmParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|GCM');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let encryptUpdate = await cipher.update(plainText);
    // gcm模式加密doFinal时传入空，获得tag数据，并更新至gcmParams对象中。
    gcmParams.authTag = await cipher.doFinal(null);
    return encryptUpdate;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|GCM');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let decryptUpdate = await decoder.update(cipherText);
    // gcm模式解密doFinal时传入空，验证init时传入的tag数据，如果验证失败会抛出异常。
    let decryptData = await decoder.doFinal(null);
    if (decryptData == null) {
      console.info('GCM decrypt result: success, decryptData is null.');
    }
    return decryptUpdate;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = await genSymKeyByData(keyData);
    let message = 'This is a test';
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessagePromise(symKey, plainText);
    let decryptText = await decryptMessagePromise(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[gcm_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_gcm_encryption_decryption/aes_gcm_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
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
    };
    // GCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: 'GcmParamsSpec'
    };
    return gcmParamsSpec;
  }
  
  let gcmParams = genGcmParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|GCM');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let encryptUpdate = cipher.updateSync(plainText);
    // gcm模式加密doFinal时传入空，获得tag数据，并更新至gcmParams对象中。
    gcmParams.authTag = cipher.doFinalSync(null);
    return encryptUpdate;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|GCM');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let decryptUpdate = decoder.updateSync(cipherText);
    // gcm模式解密doFinal时传入空，验证init时传入的tag数据，如果验证失败会抛出异常。
    let decryptData = decoder.doFinalSync(null);
    if (decryptData == null) {
      console.info('GCM decrypt result: success, decryptData is null.');
    }
    return decryptUpdate;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = genSymKeyByData(keyData);
    let message = 'This is a test';
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessage(symKey, plainText);
    let decryptText = decryptMessage(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

## 使用AES对称密钥（CCM模式）加解密

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)进行理解，参考文档与当前示例可能存在入参差异，请注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CCM'，创建对称密钥为AES128、分组模式为CCM的Cipher实例，用于执行加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定密钥（SymKey）和CCM模式对应的加密参数（CcmParamsSpec），初始化加密Cipher实例。

4. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。

   当前单次update没有长度限制，开发者可以根据数据量决定如何调用update。
  
   > **说明：**
   >
   > CCM模式不支持分段加解密。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)获取加密后的数据。
   - 由于已通过update传入数据，此处传入null。
   - doFinal输出结果可能为null，访问具体数据前，需先判断结果是否为null，以避免异常。

6. 读取[CcmParamsSpec.authTag](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ccmparamsspec)作为解密的认证信息。

   > **说明：**
   >
   > 在CCM模式下，一次加密流程中，将每次update和最后doFinal的结果拼接起来，会得到“密文 + authTag”, authTag为末尾的12字节。其余部分均为密文。如果doFinal的data参数传入null，则doFinal的结果就是authTag。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CCM'，创建对称密钥为AES128、分组模式为CCM的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定密钥（SymKey）和CCM模式对应的解密参数（CcmParamsSpec），初始化解密Cipher实例。

3. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（CCM模式）解密失败返回错误码17630001可参考[使用AES-CCM算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-ccm算法解密时调用dofinal失败)

- 异步方法示例：
  <!-- @[ccm_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ccm_encryption_decryption/aes_ccm_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
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
    // CCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
    let ccmParamsSpec: cryptoFramework.CcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: 'CcmParamsSpec'
    };
    return ccmParamsSpec;
  }
  
  let ccmParams = genCcmParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, ccmParams);
    let encryptUpdate = await cipher.update(plainText);
    // ccm模式加密doFinal时传入空，获得tag数据，并更新至ccmParams对象中。
    ccmParams.authTag = await cipher.doFinal(null);
    return encryptUpdate;
  }
  
  // 解密消息
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
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = await genSymKeyByData(keyData);
    let message = 'This is a test';
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessagePromise(symKey, plainText);
    let decryptText = await decryptMessagePromise(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

- 同步方法示例：
  <!-- @[ccm_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ccm_encryption_decryption/aes_ccm_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
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
    // CCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
    let ccmParamsSpec: cryptoFramework.CcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: 'CcmParamsSpec'
    };
    return ccmParamsSpec;
  }
  
  let ccmParams = genCcmParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, ccmParams);
    let encryptUpdate = cipher.updateSync(plainText);
    // ccm模式加密doFinal时传入空，获得tag数据，并更新至ccmParams对象中。
    ccmParams.authTag = cipher.doFinalSync(null);
    return encryptUpdate;
  }
  
  // 解密消息
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
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = genSymKeyByData(keyData);
    let message = 'This is a test';
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessage(symKey, plainText);
    let decryptText = decryptMessage(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

## 使用AES对称密钥（CCM模式）参数为AeadParamsSpec加解密

从API版本26.0.0开始，[AES](crypto-encryption-decryption.md#aes)对称密钥（CCM模式）的加解密支持使用AeadParamsSpec参数。

当用户不希望显式保存authTag或用户需要指定authTag的长度时，使用AeadParamsSpec参数。

**密钥生成**

调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合对称密钥生成和转换规格：[AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)进行理解，参考文档与当前示例可能存在入参差异，请注意区分。


**加密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CCM'，创建对称密钥为AES128、分组模式为CCM的Cipher实例，用于执行加密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定密钥（SymKey）和CCM模式对应的加密参数（AeadParamsSpec），初始化加密Cipher实例。

3. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)获取加密后的数据。

   > **说明：**
   >
   > 当前使用AeadParamsSpec参数，CCM模式下update与doFinal只能调用其中一个进行加密。且每个方法只能调用一次。
   > 
   > 使用AeadParamsSpec初始化Cipher实例，身份认证标签（authTag）自动拼接在密文后，不需要单独保存。
   >
   > 在使用AeadParamsSpec结构的CCM模式下，tagLen支持4、6、8、10、12、14和16，如果不传默认为12，单位均为字节。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CCM'，创建对称密钥为AES128、分组模式为CCM的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定密钥（SymKey）和CCM模式对应的解密参数（AeadParamsSpec），初始化解密Cipher实例。

3. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（CCM模式）解密失败返回错误码17630001可参考[使用AES-CCM算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-ccm算法解密时调用dofinal失败)

- 异步方法示例：
  <!-- @[new_ccm_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ccm_encryption_decryption/aes_new_ccm_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function genCcmAeadParamsSpec() {
    let nonce = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]; // 12 bytes
    let nonceValue = new Uint8Array(nonce);
    let aad = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]; // 12 bytes
    let aadValue = new Uint8Array(aad);
    let aeadParamsSpec: cryptoFramework.AeadParamsSpec = {
        nonce: nonceValue,
        authenticatedData: aadValue,
        algName: 'AeadParamsSpec'
    };
    return aeadParamsSpec;
  }
  
    let aeadParams = genCcmAeadParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, aeadParams);
    let encryptUpdate = await cipher.doFinal(plainText);
    return encryptUpdate;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CCM');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, aeadParams);
    let decryptUpdate = await decoder.doFinal(cipherText);
    return decryptUpdate;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  export async function main() : Promise<string> {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = await genSymKeyByData(keyData);
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = await encryptMessagePromise(symKey, plainText);
      let decryptText = await decryptMessagePromise(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
      return 'success';
    } catch (error) {
      console.error('decrypt failed. error: ' + error);
      return 'fail';
    }
  }
  ```

- 同步方法示例：
  <!-- @[new_ccm_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ccm_encryption_decryption/aes_new_ccm_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function genCcmAeadParamsSpec() {
    let nonce = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]; // 12 bytes
    let nonceValue = new Uint8Array(nonce);
    let aad = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]; // 12 bytes
    let aadValue = new Uint8Array(aad);
    let aeadParamsSpec: cryptoFramework.AeadParamsSpec = {
        nonce: nonceValue,
        authenticatedData: aadValue,
        algName: 'AeadParamsSpec'
    };
    return aeadParamsSpec;
  }
  
    let aeadParams = genCcmAeadParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CCM');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, aeadParams);
    let encryptUpdate = cipher.doFinalSync(plainText);
    return encryptUpdate;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CCM');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, aeadParams);
    let decryptUpdate = decoder.doFinalSync(cipherText);
    return decryptUpdate;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  export function main() : string {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = genSymKeyByData(keyData);
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = encryptMessage(symKey, plainText);
      let decryptText = decryptMessage(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
      return 'success';
    } catch (error) {
      console.error('decrypt failed. error: ' + error);
      return 'fail';
    }
  }
  ```

## 使用AES对称密钥（CBC模式）加解密

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CBC|PKCS7'，创建对称密钥类型为AES128、分组模式为CBC、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和CBC模式对应的加密参数（IvParamsSpec），初始化加密Cipher实例。

4. 当加密内容长度较短时，可以直接调用 [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) 而无需调用update，以获取加密后的数据。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CBC|PKCS7'，创建对称密钥类型为AES128、分组模式为CBC、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和CBC模式对应的解密参数（IvParamsSpec），初始化解密Cipher实例。

3. 当解密内容长度较短时，可以省略调用update，直接调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（CBC模式）解密失败返回错误码17630001可参考[使用AES-CBC算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-cbc算法解密时调用dofinal失败)

- 异步方法示例：
  <!-- @[cbc_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_cbc_encryption_decryption/aes_cbc_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(16);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CBC|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = await cipher.doFinal(plainText);
    return cipherData;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CBC|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function aesCBC() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = await genSymKeyByData(keyData);
      let message = 'This is a test';
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
      console.error(`AES CBC failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

- 同步方法示例：
  <!-- @[cbc_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_cbc_encryption_decryption/aes_cbc_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(16);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|CBC|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = cipher.doFinalSync(plainText);
    return cipherData;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|CBC|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function main() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = genSymKeyByData(keyData);
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = encryptMessage(symKey, plainText);
      let decryptText = decryptMessage(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
    } catch (error) {
      console.error(`AES CBC failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

 ## 使用AES对称密钥（ECB模式）加解密

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可以参考以下示例，并结合[对称密钥生成和转换规格：AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)进行理解。参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|ECB|PKCS7'，创建对称密钥类型为AES128、分组模式为ECB、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey），ECB模式Params为空，初始化加密Cipher实例。

4. 加密内容较短时，可以不调用update，直接调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|ECB|PKCS7'，创建对称密钥类型为AES128、分组模式为ECB、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey），ECB模式Params为空，初始化解密Cipher实例。

3. 解密内容较短时，可以不调用update，直接调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（ECB模式）解密失败返回错误码17630001可参考[使用AES-ECB算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-ecb算法解密时调用dofinal失败)

- 异步方法示例：

  <!-- @[ecb_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ecb_encryption_decryption/aes_ecb_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null);
    let cipherData = await cipher.doFinal(plainText);
    return cipherData;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function aesECB() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = await genSymKeyByData(keyData);
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = await encryptMessagePromise(symKey, plainText);
      let decryptText = await decryptMessagePromise(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
    } catch (error) {
      console.error(`AES ECB failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

- 同步方法示例：

  <!-- @[ecb_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_ecb_encryption_decryption/aes_ecb_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null);
    let cipherData = cipher.doFinalSync(plainText);
    return cipherData;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|ECB|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function aesECBSync() {
    try {
      let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
      let symKey = genSymKeyByData(keyData);
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = encryptMessage(symKey, plainText);
      let decryptText = decryptMessage(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
    } catch (error) {
      console.error(`AES ECB failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

## 使用AES对称密钥（GCM模式）分段加解密

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|GCM|PKCS7'，创建对称密钥类型为AES128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和GCM模式对应的加密参数（GcmParamsSpec），初始化加密Cipher实例。

4. 将一次传入数据量设置为20字节，多次调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。
   
   - 当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。
   - 建议开发者对每次update的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文。因为在不同的模式下，update的结果可能会受到不同影响。
      
      1）例如ECB和CBC模式，始终以分组作为基本单位进行加密，并输出本次更新产生的加密分组结果。即当本次更新操作凑满一个分组时就输出密文，未凑满则本次更新输出null，将未加密的数据与下次输入的数据拼接后再凑分组输出。最后在doFinal时，将未加密的数据根据指定的填充模式进行填充，再输出剩余的加密结果。解密过程中的update操作同理。

      2）对于流加密模式，如CTR和OFB模式，密文长度等于明文长度。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。
   
   - 由于已通过update传入数据，此处传入null。
   - 在访问doFinal输出结果前，需先判断结果是否为null，避免产生异常。

6. 读取[GcmParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#gcmparamsspec).authTag作为解密认证信息。

   > **说明：**
   >
   > 在GCM模式下，一次加密流程中，将每次update和最后doFinal的结果拼接起来，会得到“密文 + authTag”，authTag为末尾的16字节。其余部分均为密文。如果doFinal的data参数传入null，则doFinal的结果就是authTag。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|GCM|PKCS7'，创建对称密钥类型为AES128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和GCM模式对应的解密参数（GcmParamsSpec），初始化解密Cipher实例。

3. 将一次传入数据量设置为20字节，多次调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（密文）。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

AES（GCM模式）解密失败返回错误码17630001可参考[使用AES-GCM算法解密时调用doFinal失败](../../reference/apis-crypto-architecture-kit/errorcode-crypto-framework.md#使用aes-gcm算法解密时调用dofinal失败)

- 异步方法示例：

  <!-- @[gcm_seg_encrypt_decrypt_aes_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_gcm_seg_encryption_decryption/aes_gcm_seg_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
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
      algName: 'GcmParamsSpec'
    };
    return gcmParamsSpec;
  }
  
  let gcmParams = genGcmParamsSpec();
  
  // 分段加密消息
  async function encryptMessageUpdateBySegment(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // 假设以20字节为单位进行分段update，实际并无要求
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += updateLength) {
      let updateMessage = plainText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      let updateOutput = await cipher.update(updateMessageBlob);
      // 把update的结果拼接起来，得到密文（有些情况下还需拼接doFinal的结果，这取决于分组模式
      // 和填充模式，本例中GCM模式的doFinal结果只包含authTag而不含密文，所以不需要拼接）
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    gcmParams.authTag = await cipher.doFinal(null);
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  
  // 分段解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|GCM|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // 假设以20字节为单位进行分段update，实际并无要求
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += updateLength) {
      let updateMessage = cipherText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      let updateOutput = await decoder.update(updateMessageBlob);
      // 把update的结果拼接起来，得到明文
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptData = await decoder.doFinal(null);
    if (decryptData == null) {
      console.info('GCM decrypt result: success, decryptData is null.');
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function aes() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = await genSymKeyByData(keyData);
    let message = 'aaaaa.....bbbbb.....ccccc.....ddddd.....eee'; // 假设信息总共43字节，根据utf-8解码后，也是43字节
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessageUpdateBySegment(symKey, plainText);
    let decryptText = await decryptMessagePromise(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[gcm_seg_encrypt_decrypt_aes_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_gcm_seg_encryption_decryption/aes_gcm_seg_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
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
      algName: 'GcmParamsSpec'
    };
    return gcmParamsSpec;
  }
  
  let gcmParams = genGcmParamsSpec();
  
  // 分段加密消息
  function encryptMessageUpdateBySegment(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // 假设以20字节为单位进行分段update，实际并无要求
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += updateLength) {
      let updateMessage = plainText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      let updateOutput = cipher.updateSync(updateMessageBlob);
      // 把update的结果拼接起来，得到密文（有些情况下还需拼接doFinal的结果，这取决于分组模式
      // 和填充模式，本例中GCM模式的doFinal结果只包含authTag而不含密文，所以不需要拼接）
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    gcmParams.authTag = cipher.doFinalSync(null);
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  
  // 分段解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|GCM|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let updateLength = 20; // 假设以20字节为单位进行分段update，实际并无要求
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += updateLength) {
      let updateMessage = cipherText.data.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      let updateOutput = decoder.updateSync(updateMessageBlob);
      // 把update的结果拼接起来，得到明文
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptData = decoder.doFinalSync(null);
    if (decryptData == null) {
      console.info('GCM decrypt result: success, decryptData is null.');
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function main() {
    let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
    let symKey = genSymKeyByData(keyData);
    let message = 'aaaaa.....bbbbb.....ccccc.....ddddd.....eee'; // 假设信息总共43字节，根据utf-8解码后，也是43字节
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessageUpdateBySegment(symKey, plainText);
    let decryptText = decryptMessage(symKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

## 使用AES对称密钥（XTS模式）加解密

从API版本26.0.0开始，[AES](crypto-encryption-decryption.md#aes)对称密钥加解密支持使用XTS分组模式。

**密钥生成**

调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为256位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合对称密钥生成和转换规格：[AES](crypto-key-generation-conversion.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

   > **说明：**
   >
   > AES对称密钥（XTS模式）加解密时，对称密钥长度需要是标准AES密钥的2倍。且只支持创建AES-128、AES-256的cipher实例进行加解密。
   >
   > 示例代码中创建AES256的对称密钥，AES128的cipher实例进行加解密。

**加密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|XTS'，创建对称密钥类型为AES128、分组模式为XTS的Cipher实例，用于完成加密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和XTS模式对应的加密参数（IvParamsSpec），初始化加密Cipher实例。

3. 当加密内容长度较短时，可以直接调用 [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) 而无需调用update，以获取加密后的数据。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|XTS'，创建对称密钥类型为AES128、分组模式为XTS的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和XTS模式对应的解密参数（IvParamsSpec），初始化解密Cipher实例。

3. 当解密内容长度较短时，可以省略调用update，直接调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

- 异步方法示例：
  <!-- @[xts_encrypt_decrypt_aes_symkey_asynchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_xts_encryption_decryption/aes_xts_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(16);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|XTS');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = await cipher.doFinal(plainText);
    return cipherData;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|XTS');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  
  export async function aesXTS() : Promise<string> {
    try {
      let symGenerator = cryptoFramework.createSymKeyGenerator('AES256')
      let symKey = await symGenerator.generateSymKey()
      let message = 'This is a xts encrypt decrypt test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = await encryptMessagePromise(symKey, plainText);
      let decryptText = await decryptMessagePromise(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed');
      }
      return 'success';
    } catch (error) {
      console.error('xts decrypt failed. error: ' + error);
      return 'fail';
    }
  }
  ```

- 同步方法示例：
  <!-- @[xts_encrypt_decrypt_aes_symkey_synchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceAesArkTs/entry/src/main/ets/pages/aes_xts_encryption_decryption/aes_xts_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(16);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('AES128|XTS');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = cipher.doFinalSync(plainText);
    return cipherData;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('AES128|XTS');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  
  export function aesXTS() : string {
    try {
      let symGenerator = cryptoFramework.createSymKeyGenerator('AES256')
      let symKey = symGenerator.generateSymKeySync()
      let message = 'This is a xts encrypt decrypt test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      let encryptText = encryptMessage(symKey, plainText);
      let decryptText = decryptMessage(symKey, encryptText);
      if (plainText.data.toString() === decryptText.data.toString()) {
        console.info('decrypt ok.');
        console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
      } else {
        console.error('decrypt failed.');
      }
      return 'success';
    } catch (error) {
      console.error('xts decrypt failed. error: ' + error);
      return 'fail';
    }
  }
  ```







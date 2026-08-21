# 使用RC2对称密钥（CBC模式）加解密(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

从API版本26.0.0开始，算法库支持RC2对称密钥加解密。

对应的算法规格请参见[对称密钥加解密算法规格：RC2](crypto-encryption-decryption.md#rc2)。

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)或[SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1)，生成密钥算法为RC2、密钥长度在8位～1024位范围内（如RC2_128）的对称密钥（SymKey）。
   
   如何生成RC2对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：RC2](crypto-key-generation-conversion.md#rc2)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)/[指定二进制数据转换对称密钥](crypto-convert-binary-data-to-sym-key.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数（如'RC2|CBC|PKCS7'），创建对称密钥类型为RC2、分组模式为CBC、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和CBC模式对应的加密参数（IvParamsSpec，IV长度为8字节），初始化加密Cipher实例。

4. 当加密内容长度较短时，可以直接调用 [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) 而无需调用update，以获取加密后的数据。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数（如'RC2|CBC|PKCS7'），创建对称密钥类型为RC2、分组模式为CBC、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和CBC模式对应的解密参数（IvParamsSpec），初始化解密Cipher实例。

3. 当解密内容长度较短时，可以省略调用update，直接调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

- 异步方法示例：
  <!-- @[cbc_encrypt_decrypt_rc2_symkey_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceArkTs/entry/src/main/ets/pages/rc2_cbc_encryption_decryption/rc2_cbc_encryption_decryption_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(8);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RC2|CBC|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = await cipher.doFinal(plainText);
    return cipherData;
  }
  
  // 解密消息
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RC2|CBC|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let rc2Generator = cryptoFramework.createSymKeyGenerator('RC2');
    let symKey = await rc2Generator.convertKey(symKeyBlob);
    console.info('convertKey result: success.');
    return symKey;
  }
  
  async function rc2CBC() {
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
      console.error(`RC2 CBC failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

- 同步方法示例：
  <!-- @[cbc_encrypt_decrypt_rc2_symkey_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceArkTs/entry/src/main/ets/pages/rc2_cbc_encryption_decryption/rc2_cbc_encryption_decryption_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function generateRandom(len: number) {
    let rand = cryptoFramework.createRandom();
    let generateRandSync = rand.generateRandomSync(len);
    return generateRandSync;
  }
  
  function genIvParamsSpec() {
    let ivBlob = generateRandom(8);
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: 'IvParamsSpec',
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  
  let iv = genIvParamsSpec();
  
  // 加密消息
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RC2|CBC|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
    let cipherData = cipher.doFinalSync(plainText);
    return cipherData;
  }
  
  // 解密消息
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RC2|CBC|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let rc2Generator = cryptoFramework.createSymKeyGenerator('RC2');
    let symKey = rc2Generator.convertKeySync(symKeyBlob);
    console.info('convertKeySync result: success.');
    return symKey;
  }
  
  function rc2CBC() {
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
      console.error(`RC2 CBC failed: errCode: ${error.code}, message: ${error.message}`);
    }
  }
  ```

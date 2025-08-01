# 使用SM4对称密钥（GCM模式）加解密(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

对应的算法规格请查看[对称密钥加解密算法规格：SM4](crypto-sym-encrypt-decrypt-spec.md#sm4)。

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为SM4、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成SM4对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：SM4](crypto-sym-key-generation-conversion-spec.md#sm4)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'SM4_128|GCM|PKCS7'，创建对称密钥类型为SM4_128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和GCM模式对应的加密参数（GcmParamsSpec），初始化加密Cipher实例。

4. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。
   
   当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

   - 当数据量较小时，可以在init完成后直接调用doFinal。
   - 当数据量较大时，可以多次调用update，即[分段加解密](crypto-sm4-sym-encrypt-decrypt-gcm-by-segment.md)。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。
   - 由于已使用update传入数据，此处data传入null。
   - doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

6. 读取[GcmParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#gcmparamsspec).authTag作为解密的认证信息。
   在GCM模式下，需要从加密后的数据中取出末尾16字节，作为解密时初始化的认证信息。示例中authTag恰好为16字节。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'SM4_128|GCM|PKCS7'，创建对称密钥类型为SM4_128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和GCM模式对应的解密参数（GcmParamsSpec），初始化解密Cipher实例。

3. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（密文）。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

- 异步方法示例：

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
    }; 
    // GCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中。
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "GcmParamsSpec"
    };
    return gcmParamsSpec;
  }

  let gcmParams = genGcmParamsSpec();

  // 加密消息。
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let encryptUpdate = await cipher.update(plainText);
    // gcm模式加密doFinal时传入空，获得tag数据，并更新至gcmParams对象中。
    gcmParams.authTag = await cipher.doFinal(null);
    return encryptUpdate;
  }
  // 解密消息。
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let decryptUpdate = await decoder.update(cipherText);
    // gcm模式解密doFinal时传入空，验证init时传入的tag数据，如果验证失败会抛出异常。
    let decryptData = await decoder.doFinal(null);
    if (decryptData === null) {
      console.info('GCM decrypt success, decryptData is null');
    }
    return decryptUpdate;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let sm4Generator = cryptoFramework.createSymKeyGenerator('SM4_128');
    let symKey = await sm4Generator.convertKey(symKeyBlob);
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

- 同步方法示例：

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
    };
    // GCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中。
    let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "GcmParamsSpec"
    };
    return gcmParamsSpec;
  }

  let gcmParams = genGcmParamsSpec();

  // 加密消息。
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
    let encryptUpdate = cipher.updateSync(plainText);
    // gcm模式加密doFinal时传入空，获得tag数据，并更新至gcmParams对象中。
    gcmParams.authTag = cipher.doFinalSync(null);
    return encryptUpdate;
  }
  // 解密消息。
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('SM4_128|GCM|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, gcmParams);
    let decryptUpdate = decoder.updateSync(cipherText);
    // gcm模式解密doFinal时传入空，验证init时传入的tag数据，如果验证失败会抛出异常。
    let decryptData = decoder.doFinalSync(null);
    if (decryptData === null) {
      console.info('GCM decrypt success, decryptData is null');
    }
    return decryptUpdate;
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
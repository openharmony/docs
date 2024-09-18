# 使用AES对称密钥（CCM模式）加解密(ArkTS)


对应的算法规格请查看[对称密钥加解密算法规格：AES](crypto-sym-encrypt-decrypt-spec.md#aes)。


**加密**


1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：AES](crypto-sym-key-generation-conversion-spec.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CCM'，创建对称密钥类型为AES128、分组模式为CCM的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和CCM模式对应的加密参数（CcmParamsSpec），初始化加密Cipher实例。

4. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。
   
   当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。
    - CCM模式不支持分段加解密。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。
   - 由于已使用update传入数据，此处data传入null。
   - doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

6. 读取[CcmParamsSpec.authTag](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ccmparamsspec)作为解密的认证信息。
   在CCM模式下，需要从加密后的数据中取出末尾12字节，作为解密时初始化的认证信息。示例中authTag恰好为12字节。


**解密**


1. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和CCM模式对应的解密参数（CcmParamsSpec），初始化解密Cipher实例。

2. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。


- 异步方法示例：

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
    // CCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
    let ccmParamsSpec: cryptoFramework.CcmParamsSpec = {
      iv: ivBlob,
      aad: aadBlob,
      authTag: tagBlob,
      algName: "CcmParamsSpec"
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
      algName: "CcmParamsSpec"
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
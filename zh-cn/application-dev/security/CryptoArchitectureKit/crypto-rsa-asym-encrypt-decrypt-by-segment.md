# 使用RSA非对称密钥分段加解密(ArkTS)

对应的算法规格请查看[非对称密钥加解密算法规格：RSA](crypto-asym-encrypt-decrypt-spec.md#rsa)。

**加密**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成RSA密钥类型为RSA1024、素数个数为2（不填默认）的非对称密钥对（KeyPair）。KeyPair对象中包括公钥PubKey、私钥PriKey。

   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'RSA1024|PKCS1'，创建非对称密钥类型为RSA1024、填充模式为PKCS1的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（CryptoMode.ENCRYPT_MODE），指定加密密钥（KeyPair.PubKey），初始化加密Cipher实例。

4. 多次调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入明文，获取加密后的数据。

   doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

   此处将明文按64个字节一组拆分，多次加密。使用1024位密钥，每次将生成128字节密文。
   > **说明：**
   > 非对称密钥的分段加解密是指当明文大于单次加解密支持的数据长度时，需要将待加解密数据分为合适长度的数据段，并对每个数据段执行加解密操作。详细介绍可见[非对称分段加解密介绍](crypto-encrypt-decrypt-by-segment.md#非对称加解密)。

**解密**

1. 由于RSA算法的Cipher实例不支持重复init操作，需要调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，重新生成Cipher实例。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（CryptoMode.DECRYPT_MODE），指定解密密钥（KeyPair.PriKey）初始化解密Cipher实例。PKCS1模式无加密参数，直接传入null。

3. 多次调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入密文，获取解密后的数据。

- 异步方法示例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // 分段加密消息。
  async function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen ) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen );
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将原文按64字符进行拆分，循环调用doFinal进行加密，使用1024bit密钥时，每次加密生成128字节长度的密文。
      let updateOutput = await cipher.doFinal(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // 分段解密消息。
  async function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // RSA密钥每次加密生成的密文字节长度计算方式：密钥位数/8。
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将密文按128字节进行拆分解密，得到原文后进行拼接。
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
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024"); // 创建非对称密钥生成器对象。
    let keyPair = await asyKeyGenerator.generateKeyPair(); // 随机生成RSA密钥。
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

- 同步方法示例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // 分段加密消息。
  function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen ) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen );
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将原文按64字符进行拆分，循环调用doFinal进行加密，使用1024bit密钥时，每次加密生成128字节长度的密文。
      let updateOutput = cipher.doFinalSync(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  // 分段解密消息。
  function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // RSA密钥每次加密生成的密文字节长度计算方式：密钥位数/8。
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将密文按128字节进行拆分解密，得到原文后进行拼接。
      let updateOutput = decoder.doFinalSync(updateMessageBlob);
      let mergeText = new Uint8Array(decryptText.length + updateOutput.data.length);
      mergeText.set(decryptText);
      mergeText.set(updateOutput.data, decryptText.length);
      decryptText = mergeText;
    }
    let decryptBlob: cryptoFramework.DataBlob = { data: decryptText };
    return decryptBlob;
  }
  function main() {
    let message = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024"); // 创建非对称密钥生成器对象。
    let keyPair = asyKeyGenerator.generateKeyPairSync(); // 随机生成RSA密钥。
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
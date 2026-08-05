# 使用RSA非对称密钥加解密(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

对应的算法规格请查看[非对称密钥加解密算法规格：RSA](crypto-encryption-decryption.md#rsa)。

## 使用RSA非对称密钥（PKCS1模式）加解密

**加密**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成RSA密钥类型为RSA1024、素数个数为2的非对称密钥对（KeyPair）。KeyPair对象中包括公钥PubKey、私钥PriKey。

   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'RSA1024|PKCS1'，创建非对称密钥类型为RSA1024、填充模式为PKCS1的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（KeyPair.PubKey），初始化加密Cipher实例。

   非对称密钥无加密参数，直接传入null。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入明文，获取加密后的数据。

   - doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。
   - 当数据量较大时，可以多次调用doFinal，即[分段加解密](crypto-rsa-asym-encrypt-decrypt.md#使用rsa非对称密钥分段加解密)。

**解密**

1. 由于RSA算法的Cipher实例不支持重复init操作，需要调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，重新生成Cipher实例。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（KeyPair.PriKey）初始化解密Cipher实例。PKCS1模式无加密参数，直接传入null。

3. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入密文，获取解密后的数据。

- 异步方法示例：

  <!-- @[rsa_pkcs1_encrypt_decrypt_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_pkcs1/RSAPKCS1Async.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 加密消息
  async function encryptMessagePromise(publicKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, publicKey, null);
    let encryptData = await cipher.doFinal(plainText);
    return encryptData;
  }
  
  // 解密消息
  async function decryptMessagePromise(privateKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, privateKey, null);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  
  // 生成RSA密钥对
  async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
    console.info('convertKey result: success.');
    return keyPair;
  }
  
  async function main() {
    let pkData =
      new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
        2, 129, 129, 0, 197, 64, 10, 198, 14, 110, 65, 92, 206, 35, 28, 123, 153, 24, 134, 255, 145, 74, 42, 173, 40, 215,
        146, 58, 143, 46, 10, 195, 154, 160, 69, 196, 220, 152, 179, 44, 111, 200, 84, 78, 215, 73, 210, 181, 12, 29, 70,
        68, 36, 135, 153, 89, 230, 202, 130, 212, 111, 243, 234, 92, 131, 62, 145, 50, 73, 48, 104, 245, 46, 70, 45, 157,
        147, 143, 140, 162, 156, 216, 220, 49, 121, 142, 194, 33, 223, 201, 0, 16, 163, 210, 240, 118, 92, 147, 121, 220,
        17, 114, 24, 52, 125, 135, 176, 88, 21, 83, 86, 17, 156, 88, 250, 48, 79, 86, 128, 248, 105, 208, 133, 140, 13,
        153, 164, 191, 136, 164, 44, 53, 2, 3, 1, 0, 1]);
    let skData =
      new Uint8Array([48, 130, 2, 119, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 97, 48,
        130, 2, 93, 2, 1, 0, 2, 129, 129, 0, 197, 64, 10, 198, 14, 110, 65, 92, 206, 35, 28, 123, 153, 24, 134, 255, 145,
        74, 42, 173, 40, 215, 146, 58, 143, 46, 10, 195, 154, 160, 69, 196, 220, 152, 179, 44, 111, 200, 84, 78, 215, 73,
        210, 181, 12, 29, 70, 68, 36, 135, 153, 89, 230, 202, 130, 212, 111, 243, 234, 92, 131, 62, 145, 50, 73, 48, 104,
        245, 46, 70, 45, 157, 147, 143, 140, 162, 156, 216, 220, 49, 121, 142, 194, 33, 223, 201, 0, 16, 163, 210, 240,
        118, 92, 147, 121, 220, 17, 114, 24, 52, 125, 135, 176, 88, 21, 83, 86, 17, 156, 88, 250, 48, 79, 86, 128, 248,
        105, 208, 133, 140, 13, 153, 164, 191, 136, 164, 44, 53, 2, 3, 1, 0, 1, 2, 129, 128, 70, 75, 184, 139, 53, 1, 94,
        17, 240, 244, 218, 101, 193, 253, 215, 190, 164, 204, 197, 192, 200, 89, 107, 39, 171, 119, 65, 38, 204, 168, 105,
        180, 234, 217, 16, 161, 185, 132, 175, 103, 25, 154, 153, 153, 36, 36, 26, 178, 150, 66, 45, 8, 185, 19, 90, 228,
        210, 177, 30, 200, 177, 141, 78, 184, 248, 59, 113, 154, 145, 73, 160, 24, 73, 157, 86, 207, 186, 32, 95, 200,
        106, 252, 107, 69, 170, 193, 216, 196, 181, 142, 74, 203, 15, 18, 89, 228, 152, 19, 239, 21, 233, 98, 121, 214,
        57, 187, 111, 239, 223, 248, 199, 70, 223, 108, 108, 113, 234, 144, 155, 95, 246, 144, 244, 122, 39, 55, 127, 81,
        2, 65, 0, 246, 96, 188, 0, 0, 104, 221, 105, 139, 144, 63, 175, 209, 87, 179, 162, 88, 192, 99, 82, 125, 53, 54,
        48, 70, 245, 239, 37, 15, 242, 247, 84, 115, 187, 196, 95, 156, 40, 165, 60, 64, 102, 13, 229, 243, 2, 149, 0,
        232, 226, 221, 192, 95, 11, 12, 208, 5, 181, 98, 62, 210, 190, 141, 235, 2, 65, 0, 204, 244, 34, 10, 105, 80, 76,
        116, 163, 35, 231, 168, 187, 206, 189, 101, 215, 103, 80, 115, 86, 11, 34, 127, 203, 114, 84, 188, 121, 174, 169,
        31, 142, 2, 182, 27, 140, 225, 157, 227, 71, 98, 15, 203, 187, 213, 5, 190, 20, 121, 8, 30, 193, 100, 232, 101,
        141, 8, 124, 20, 29, 78, 6, 95, 2, 65, 0, 204, 43, 225, 224, 6, 118, 224, 117, 100, 200, 199, 94, 70, 23, 109,
        175, 173, 232, 208, 230, 61, 8, 105, 189, 156, 48, 150, 91, 154, 89, 248, 136, 173, 215, 254, 166, 84, 220, 130,
        1, 234, 68, 40, 100, 84, 251, 224, 202, 254, 51, 115, 28, 198, 38, 124, 25, 175, 129, 94, 199, 61, 17, 216, 189,
        2, 64, 72, 230, 129, 129, 48, 138, 134, 87, 106, 123, 231, 247, 165, 173, 216, 194, 115, 198, 228, 223, 209, 120,
        46, 114, 68, 92, 75, 117, 170, 214, 140, 131, 147, 208, 181, 19, 193, 157, 178, 186, 87, 246, 178, 101, 166, 79,
        20, 54, 211, 51, 101, 199, 2, 197, 48, 192, 134, 84, 193, 69, 170, 82, 201, 131, 2, 65, 0, 213, 165, 55, 166, 131,
        210, 195, 56, 250, 147, 195, 61, 205, 208, 189, 185, 40, 52, 50, 119, 137, 23, 246, 46, 220, 108, 52, 23, 152,
        154, 94, 32, 144, 195, 184, 249, 21, 168, 12, 57, 222, 18, 60, 117, 81, 157, 72, 30, 155, 190, 165, 242, 228, 139,
        240, 184, 145, 170, 103, 210, 160, 161, 135, 13]);
    let keyPair = await genKeyPairByData(pkData, skData);
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    let message = 'This is a test';
    // 把字符串按utf-8解码为Uint8Array
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await encryptMessagePromise(pubKey, plainText);
    let decryptText = await decryptMessagePromise(priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      // 把Uint8Array按utf-8编码为字符串
      let messageDecrypted = buffer.from(decryptText.data).toString('utf-8');
      console.info('decrypted result string: ' + messageDecrypted);
    } else {
      console.error('decrypt failed.');
    }
  }
  ```


- 同步方法示例：

  <!-- @[rsa_pkcs1_encrypt_decrypt_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_pkcs1/RSAPKCS1Sync.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 加密消息
  function encryptMessage(publicKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, publicKey, null);
    let encryptData = cipher.doFinalSync(plainText);
    return encryptData;
  }
  
  // 解密消息
  function decryptMessage(privateKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, privateKey, null);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  
  // 生成RSA密钥对
  function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    let keyPair = rsaGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
    console.info('convertKeySync result: success.');
    return keyPair;
  }
  
  function main() {
    let pkData =
      new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
        2, 129, 129, 0, 197, 64, 10, 198, 14, 110, 65, 92, 206, 35, 28, 123, 153, 24, 134, 255, 145, 74, 42, 173, 40, 215,
        146, 58, 143, 46, 10, 195, 154, 160, 69, 196, 220, 152, 179, 44, 111, 200, 84, 78, 215, 73, 210, 181, 12, 29, 70,
        68, 36, 135, 153, 89, 230, 202, 130, 212, 111, 243, 234, 92, 131, 62, 145, 50, 73, 48, 104, 245, 46, 70, 45, 157,
        147, 143, 140, 162, 156, 216, 220, 49, 121, 142, 194, 33, 223, 201, 0, 16, 163, 210, 240, 118, 92, 147, 121, 220,
        17, 114, 24, 52, 125, 135, 176, 88, 21, 83, 86, 17, 156, 88, 250, 48, 79, 86, 128, 248, 105, 208, 133, 140, 13,
        153, 164, 191, 136, 164, 44, 53, 2, 3, 1, 0, 1]);
    let skData =
      new Uint8Array([48, 130, 2, 119, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 97, 48,
        130, 2, 93, 2, 1, 0, 2, 129, 129, 0, 197, 64, 10, 198, 14, 110, 65, 92, 206, 35, 28, 123, 153, 24, 134, 255, 145,
        74, 42, 173, 40, 215, 146, 58, 143, 46, 10, 195, 154, 160, 69, 196, 220, 152, 179, 44, 111, 200, 84, 78, 215, 73,
        210, 181, 12, 29, 70, 68, 36, 135, 153, 89, 230, 202, 130, 212, 111, 243, 234, 92, 131, 62, 145, 50, 73, 48, 104,
        245, 46, 70, 45, 157, 147, 143, 140, 162, 156, 216, 220, 49, 121, 142, 194, 33, 223, 201, 0, 16, 163, 210, 240,
        118, 92, 147, 121, 220, 17, 114, 24, 52, 125, 135, 176, 88, 21, 83, 86, 17, 156, 88, 250, 48, 79, 86, 128, 248,
        105, 208, 133, 140, 13, 153, 164, 191, 136, 164, 44, 53, 2, 3, 1, 0, 1, 2, 129, 128, 70, 75, 184, 139, 53, 1, 94,
        17, 240, 244, 218, 101, 193, 253, 215, 190, 164, 204, 197, 192, 200, 89, 107, 39, 171, 119, 65, 38, 204, 168, 105,
        180, 234, 217, 16, 161, 185, 132, 175, 103, 25, 154, 153, 153, 36, 36, 26, 178, 150, 66, 45, 8, 185, 19, 90, 228,
        210, 177, 30, 200, 177, 141, 78, 184, 248, 59, 113, 154, 145, 73, 160, 24, 73, 157, 86, 207, 186, 32, 95, 200,
        106, 252, 107, 69, 170, 193, 216, 196, 181, 142, 74, 203, 15, 18, 89, 228, 152, 19, 239, 21, 233, 98, 121, 214,
        57, 187, 111, 239, 223, 248, 199, 70, 223, 108, 108, 113, 234, 144, 155, 95, 246, 144, 244, 122, 39, 55, 127, 81,
        2, 65, 0, 246, 96, 188, 0, 0, 104, 221, 105, 139, 144, 63, 175, 209, 87, 179, 162, 88, 192, 99, 82, 125, 53, 54,
        48, 70, 245, 239, 37, 15, 242, 247, 84, 115, 187, 196, 95, 156, 40, 165, 60, 64, 102, 13, 229, 243, 2, 149, 0,
        232, 226, 221, 192, 95, 11, 12, 208, 5, 181, 98, 62, 210, 190, 141, 235, 2, 65, 0, 204, 244, 34, 10, 105, 80, 76,
        116, 163, 35, 231, 168, 187, 206, 189, 101, 215, 103, 80, 115, 86, 11, 34, 127, 203, 114, 84, 188, 121, 174, 169,
        31, 142, 2, 182, 27, 140, 225, 157, 227, 71, 98, 15, 203, 187, 213, 5, 190, 20, 121, 8, 30, 193, 100, 232, 101,
        141, 8, 124, 20, 29, 78, 6, 95, 2, 65, 0, 204, 43, 225, 224, 6, 118, 224, 117, 100, 200, 199, 94, 70, 23, 109,
        175, 173, 232, 208, 230, 61, 8, 105, 189, 156, 48, 150, 91, 154, 89, 248, 136, 173, 215, 254, 166, 84, 220, 130,
        1, 234, 68, 40, 100, 84, 251, 224, 202, 254, 51, 115, 28, 198, 38, 124, 25, 175, 129, 94, 199, 61, 17, 216, 189,
        2, 64, 72, 230, 129, 129, 48, 138, 134, 87, 106, 123, 231, 247, 165, 173, 216, 194, 115, 198, 228, 223, 209, 120,
        46, 114, 68, 92, 75, 117, 170, 214, 140, 131, 147, 208, 181, 19, 193, 157, 178, 186, 87, 246, 178, 101, 166, 79,
        20, 54, 211, 51, 101, 199, 2, 197, 48, 192, 134, 84, 193, 69, 170, 82, 201, 131, 2, 65, 0, 213, 165, 55, 166, 131,
        210, 195, 56, 250, 147, 195, 61, 205, 208, 189, 185, 40, 52, 50, 119, 137, 23, 246, 46, 220, 108, 52, 23, 152,
        154, 94, 32, 144, 195, 184, 249, 21, 168, 12, 57, 222, 18, 60, 117, 81, 157, 72, 30, 155, 190, 165, 242, 228, 139,
        240, 184, 145, 170, 103, 210, 160, 161, 135, 13]);
    let keyPair = genKeyPairByData(pkData, skData);
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    let message = 'This is a test';
    // 把字符串按utf-8解码为Uint8Array
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = encryptMessage(pubKey, plainText);
    let decryptText = decryptMessage(priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      // 把Uint8Array按utf-8编码为字符串
      let messageDecrypted = buffer.from(decryptText.data).toString('utf-8');
      console.info('decrypted result string: ' + messageDecrypted);
    } else {
      console.error('decrypt failed.');
    }
  }
  ```


## 使用RSA非对称密钥分段加解密

**加密**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成RSA密钥类型为RSA1024、素数个数为2（不填默认）的非对称密钥对（KeyPair）。KeyPair对象中包括公钥PubKey、私钥PriKey。

   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'RSA1024|PKCS1'，创建非对称密钥类型为RSA1024、填充模式为PKCS1的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（KeyPair.PubKey），初始化加密Cipher实例。

4. 多次调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入明文，获取加密后的数据。

   doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

   此处将明文按64个字节一组拆分，多次加密。使用1024位密钥，每次将生成128字节密文。
   > **说明：**
   >
   > 非对称密钥的分段加解密是指当明文大于单次加解密支持的数据长度时，需要将待加解密数据分为合适长度的数据段，并对每个数据段执行加解密操作。详细介绍可见[非对称分段加解密介绍](crypto-encryption-decryption.md#非对称加解密)。

**解密**

1. 由于RSA算法的Cipher实例不支持重复init操作，需要调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，重新生成Cipher实例。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（KeyPair.PriKey）初始化解密Cipher实例。PKCS1模式无加密参数，直接传入null。

3. 多次调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入密文，获取解密后的数据。

- 异步方法示例：

  <!-- @[rsa_segmentation_encrypt_decrypt_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_segmentation/RSASegmentationAsync.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 分段加密消息
  async function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将原文按64字节进行拆分，循环调用doFinal进行加密，使用1024bit密钥时，每次加密生成128字节长度的密文
      let updateOutput = await cipher.doFinal(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  
  // 分段解密消息
  async function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // RSA密钥每次加密生成的密文字节长度计算方式：密钥位数/8
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将密文按128字节进行拆分解密，得到原文后进行拼接
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
    let message = 'This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!';
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024'); // 创建非对称密钥生成器对象
    let keyPair = await asyKeyGenerator.generateKeyPair(); // 随机生成RSA密钥
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = await rsaEncryptBySegment(keyPair.pubKey, plainText);
    let decryptText = await rsaDecryptBySegment(keyPair.priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```


- 同步方法示例：

  <!-- @[rsa_segmentation_encrypt_decrypt_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_segmentation/RSASegmentationSync.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 分段加密消息
  function rsaEncryptBySegment(pubKey: cryptoFramework.PubKey, plainText: cryptoFramework.DataBlob) {
    let cipher = cryptoFramework.createCipher('RSA1024|PKCS1');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
    let plainTextSplitLen = 64;
    let cipherText = new Uint8Array();
    for (let i = 0; i < plainText.data.length; i += plainTextSplitLen) {
      let updateMessage = plainText.data.subarray(i, i + plainTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将原文按64字节进行拆分，循环调用doFinal进行加密，使用1024bit密钥时，每次加密生成128字节长度的密文
      let updateOutput = cipher.doFinalSync(updateMessageBlob);
      let mergeText = new Uint8Array(cipherText.length + updateOutput.data.length);
      mergeText.set(cipherText);
      mergeText.set(updateOutput.data, cipherText.length);
      cipherText = mergeText;
    }
    let cipherBlob: cryptoFramework.DataBlob = { data: cipherText };
    return cipherBlob;
  }
  
  // 分段解密消息
  function rsaDecryptBySegment(priKey: cryptoFramework.PriKey, cipherText: cryptoFramework.DataBlob) {
    let decoder = cryptoFramework.createCipher('RSA1024|PKCS1');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, priKey, null);
    let cipherTextSplitLen = 128; // RSA密钥每次加密生成的密文字节长度计算方式：密钥位数/8
    let decryptText = new Uint8Array();
    for (let i = 0; i < cipherText.data.length; i += cipherTextSplitLen) {
      let updateMessage = cipherText.data.subarray(i, i + cipherTextSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 将密文按128字节进行拆分解密，得到原文后进行拼接
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
    let message = 'This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!';
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024'); // 创建非对称密钥生成器对象
    let keyPair = asyKeyGenerator.generateKeyPairSync(); // 随机生成RSA密钥
    let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
    let encryptText = rsaEncryptBySegment(keyPair.pubKey, plainText);
    let decryptText = rsaDecryptBySegment(keyPair.priKey, encryptText);
    if (plainText.data.toString() === decryptText.data.toString()) {
      console.info('decrypt ok.');
      console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
    } else {
      console.error('decrypt failed.');
    }
  }
  ```

## 使用RSA非对称密钥（PKCS1_OAEP模式）加解密

**加密**

1. 调用[cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10)、[AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair10)，指定密钥参数，生成RSA非对称密钥对（KeyPair）。
   
   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[指定密钥参数生成非对称密钥对](crypto-generate-asym-key-pair-from-key-spec.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1'，创建非对称密钥类型为RSA2048、填充模式为PKCS1_OAEP、摘要算法为SHA256、掩码摘要为MGF1_SHA1的RSA密钥的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（cryptoFramework.CryptoMode.ENCRYPT_MODE），指定加密密钥（KeyPair.PubKey），初始化加密Cipher实例。
   
   非对称密钥无加密参数，直接传入null。

4. 在调用Cipher.doFinal前，调用[Cipher.setCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setcipherspec10)设置PKCS1_OAEP填充参数pSource。调用[Cipher.getCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getcipherspec10)可获得OAEP相关参数。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入明文，获取加密后的数据。

**解密**

1. 由于RSA算法的Cipher实例不支持重复init操作，需要调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，重新生成Cipher实例。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（cryptoFramework.CryptoMode.DECRYPT_MODE），指定解密密钥（KeyPair.PriKey）初始化解密Cipher实例。PKCS1_OAEP模式无额外加密参数，直接传入null。

3. 在调用Cipher.doFinal前，调用[Cipher.setCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setcipherspec10)设置PKCS1_OAEP填充参数pSource，此处需要和加密时设置的保持一致。调用[Cipher.getCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getcipherspec10)可获得OAEP相关参数。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，传入密文，获取解密后的数据。

- 异步方法示例：

  <!-- @[pss_verify_rsa_keypair_sign_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_pkcs1_oaep/RSAPKCS1OAEPAsync.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 根据密钥参数属性构造RSA非对称密钥对密钥参数
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  
  // 生成RSA2048密钥对参数
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn =
      BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    let dIn =
      BigInt('0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1');
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }
  
  async function rsaUseSpecDecryptOAEPPromise() {
    let plan = 'This is a test';
    // 获得RSA密钥对密钥参数对象
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // 根据RSA密钥对参数生成RSA密钥对
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    let cipher = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
    let decoder = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
    // RSA加解密PKCS1-OAEP模式填充字节流P
    let pSource = new Uint8Array([1, 2, 3, 4]);
    let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan, 'utf-8').buffer) };
    // 生成密钥对
    let keyPair = await rsaGeneratorSpec.generateKeyPair();
    // 进行加密操作初始化
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
    // get和set操作可以放在Cipher对象init之后，此处对cipher进行set和get操作
    cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // 比较get出来的P字节流与set进去的P字节流是否一致
    if (retP.toString() != pSource.toString()) {
      console.error('error init pSource ' + retP);
    } else {
      console.info('pSource changed == ' + retP);
    }
    // 进行OAEP其他参数的get操作
    let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info('md == ' + md);
    let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info('mgf == ' + mgf);
    let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info('mgf1Md == ' + mgf1Md);
    let cipherDataBlob = await cipher.doFinal(input);
    // get和set操作可以放在Cipher对象init之前，且与init之后等价，此处对decoder进行set和get操作
    decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // 比较get出来的P字节流与set进去的P字节流是否一致
    if (retP.toString() != pSource.toString()) {
      console.error('error init pSource ' + retP);
    } else {
      console.info('pSource changed == ' + retP);
    }
    // 进行OAEP其他参数的get操作
    md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info('md == ' + md);
    mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info('mgf == ' + mgf);
    mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info('mgf1Md == ' + mgf1Md);
    // 初始化解密操作
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    let decodeData = await decoder.doFinal(cipherDataBlob);
    // 解密成功
    if (decodeData.data.toString() === input.data.toString()) {
      console.info('oaep decrypt result: success.');
    } else {
      console.error('oaep decrypt result: fail.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[pss_verify_rsa_keypair_sign_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceRSA/entry/src/main/ets/pages/rsa_pkcs1_oaep/RSAPKCS1OAEPSync.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // 根据密钥参数属性构造RSA非对称密钥对密钥参数
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  // 生成RSA2048密钥对参数
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn = BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    let dIn = BigInt('0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1');
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }
  function main() {
    let plan = 'This is a test';
    // 获得RSA密钥对密钥参数对象
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // 根据RSA密钥对参数生成RSA密钥对
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    let cipher = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
    let decoder = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
    // RSA加解密PKCS1-OAEP模式填充字节流P
    let pSource = new Uint8Array([1, 2, 3, 4]);
    let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan, 'utf-8').buffer) };
    // 生成密钥对
    let keyPair = rsaGeneratorSpec.generateKeyPairSync();
    // 进行加密操作初始化
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
    // get和set操作可以放在Cipher对象init之后，此处对cipher进行set和get操作
    cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // 比较get出来的P字节流与set进去的P字节流是否一致
    if (retP.toString() != pSource.toString()) {
      console.error('error init pSource ' + retP);
    } else {
      console.info('pSource changed == ' + retP);
    }
    // 进行OAEP其他参数的get操作
    let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info('md == ' + md);
    let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info('mgf == ' + mgf);
    let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info('mgf1Md == ' + mgf1Md);
    let cipherDataBlob = cipher.doFinalSync(input);
    // get和set操作可以放在Cipher对象init之前，且与init之后等价，此处对decoder进行set和get操作
    decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // 比较get出来的P字节流与set进去的P字节流是否一致
    if (retP.toString() != pSource.toString()) {
      console.error('error init pSource ' + retP);
    } else {
      console.info('pSource changed == ' + retP);
    }
    // 进行OAEP其他参数的get操作
    md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info('md == ' + md);
    mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info('mgf == ' + mgf);
    mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info('mgf1Md == ' + mgf1Md);
    // 初始化解密操作
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    let decodeData = decoder.doFinalSync(cipherDataBlob);
    // 解密成功
    if (decodeData.data.toString() === input.data.toString()) {
      console.info('oaep decrypt result: success.');
    } else {
      console.error('oaep decrypt result: fail.');
    }
  }
  ```



# 使用3DES对称密钥加解密(ArkTS)

对应的算法规格请查看[对称密钥加解密算法规格：3DES](crypto-sym-encrypt-decrypt-spec.md#3des)。

## 开发步骤

**加密**

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)和[SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1)，生成密钥算法为3DES、密钥长度为192位的对称密钥（SymKey）。
   
   如何生成3DES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：3DES](crypto-sym-key-generation-conversion-spec.md#3des)和[指定二进制数据转换对称密钥](crypto-convert-binary-data-to-sym-key.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'3DES192|ECB|PKCS7'，创建对称密钥类型为3DES192、分组模式为ECB、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为加密（CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey），初始化加密Cipher实例。
   
   ECB模式无加密参数，传入null。

4. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（明文）。
   
   - 当数据量较小时，可以在init完成后直接调用doFinal。
   - 当数据量较大时，可以多次调用update，即分段加解密。
   - 用户可以自行决定数据量大小。例如，数据量大于20字节时使用update。

5. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。
   
   - 已使用update，data传入null。
   - doFinal输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

**解密**

1. 调用[cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'3DES192|ECB|PKCS7'，创建对称密钥类型为3DES192、分组模式为ECB、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)，设置模式为解密（CryptoMode.DECRYPT_MODE），并指定解密密钥（SymKey）初始化解密Cipher实例。ECB模式无加密参数，调用时直接传入null。

3. 调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)，更新数据（密文）。

4. 调用[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。

## 开发示例

当前示例以ECB分组模式为例，不需要设置加解密参数IV。

如果使用CBC、CTR、OFB、CFB分组模式，需设置加解密参数IV，请参考[设置加解密参数IV](#设置加解密参数iv)，并确保在生成和初始化Cipher实例时正确设置相关参数。

- 异步方法示例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  // 加密消息。
  async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    // 如果使用CBC、CTR、OFB或CFB分组模式，需将此处修改为对应模式，并添加IV作为加解密参数。
    let cipher = cryptoFramework.createCipher('3DES192|ECB|PKCS7');
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null);
    let encryptData = await cipher.doFinal(plainText);
    return encryptData;
  }
  // 解密消息。
  async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    // 如果使用CBC、CTR、OFB或CFB分组模式，需将此处修改为对应模式，并添加加解密参数IV。
    let decoder = cryptoFramework.createCipher('3DES192|ECB|PKCS7');
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null);
    let decryptData = await decoder.doFinal(cipherText);
    return decryptData;
  }
  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let symGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
    let symKey = await symGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function main() {
    let keyData = new Uint8Array([238, 249, 61, 55, 128, 220, 183, 224, 139, 253, 248, 239, 239, 41, 71, 25, 235, 206, 230, 162, 249, 27, 234, 114]);
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

  // 加密消息。
  function encryptMessage(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
    // 如果使用CBC、CTR、OFB或CFB分组模式，需将此处修改为对应模式，并添加加解密参数IV。
    let cipher = cryptoFramework.createCipher('3DES192|ECB|PKCS7');
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null);
    let encryptData = cipher.doFinalSync(plainText);
    return encryptData;
  }
  // 解密消息。
  function decryptMessage(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
    // 对于CBC、CTR、OFB、CFB分组模式，需要将此处修改为对应模式，并添加加解密参数IV。
    let decoder = cryptoFramework.createCipher('3DES192|ECB|PKCS7');
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, null);
    let decryptData = decoder.doFinalSync(cipherText);
    return decryptData;
  }
  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let symGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
    let symKey = symGenerator.convertKeySync(symKeyBlob);
    console.info('convertKeySync success');
    return symKey;
  }
  function main() {
    let keyData = new Uint8Array([238, 249, 61, 55, 128, 220, 183, 224, 139, 253, 248, 239, 239, 41, 71, 25, 235, 206, 230, 162, 249, 27, 234, 114]);
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

### 设置加解密参数IV

下述示例为CBC分组模式，需要设置加解密参数IV。

如果分组模式为CBC、CTR、OFB、CFB，需要参考如下设置加解密参数IV。ECB不需要设置加解密参数IV。

  ```ts
  function genIvParamsSpec() {
    let ivBlob = generateRandom(8); //3DES的 CBC、CFB、OFB、CTR的iv长度为8字节。
    let ivParamsSpec: cryptoFramework.IvParamsSpec = {
      algName: "IvParamsSpec",
      iv: ivBlob
    };
    return ivParamsSpec;
  }
  let iv = genIvParamsSpec();
  let cipher = cryptoFramework.createCipher('3DES192|CBC|PKCS7');
  cipher.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
  // 本段代码只展示CBC、CTR、OFB、CFB分段模式的不同，其他流程请参考开发示例。
  ```

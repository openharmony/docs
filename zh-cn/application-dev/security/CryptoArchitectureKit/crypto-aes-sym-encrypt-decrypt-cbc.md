# 使用AES对称密钥（CBC模式）加解密


对应的算法规格请查看[对称密钥加解密算法规格：AES](crypto-sym-encrypt-decrypt-spec.md#aes)。


**加密**


1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)、[SymKeyGenerator.generateSymKey](../../reference/apis/js-apis-cryptoFramework.md#generatesymkey-1)，生成密钥算法为AES、密钥长度为128位的对称密钥（SymKey）。
   
   如何生成AES对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：AES](crypto-sym-key-generation-conversion-spec.md#aes)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createCipher](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher)，指定字符串参数'AES128|CBC|PKCS7'，创建对称密钥类型为AES128、分组模式为CBC、填充模式为PKCS7的Cipher实例，用于完成加解密操作。

3. 调用[Cipher.init](../../reference/apis/js-apis-cryptoFramework.md#init-1)，设置模式为加密（CryptoMode.ENCRYPT_MODE），指定加密密钥（SymKey）和CBC模式对应的加密参数（IvParamsSpec），初始化加密Cipher实例。

4. 加密内容较短时，可以不调用update，直接调用[Cipher.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-1)，获取加密后的数据。


**解密**


1. 调用[Cipher.init](../../reference/apis/js-apis-cryptoFramework.md#init-1)，设置模式为解密（CryptoMode.DECRYPT_MODE），指定解密密钥（SymKey）和CBC模式对应的解密参数（IvParamsSpec），初始化解密Cipher实例。

2. 解密内容较短时，可以不调用update，直接调用[Cipher.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-1)，获取解密后的数据。


```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import buffer from '@ohos.buffer';

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
// 加密消息
async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
  let cipher = cryptoFramework.createCipher('AES128|CBC|PKCS7');
  let iv = genIvParamsSpec();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
  let cipherData = await cipher.doFinal(plainText);
  return cipherData;
}
// 解密消息
async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
  let decoder = cryptoFramework.createCipher('AES128|CBC|PKCS7');
  let iv = genIvParamsSpec();
  await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
  let decryptData = await decoder.doFinal(cipherText);
  return decryptData;
}

async function genSymKeyByData(symKeyData: Uint8Array) {
  let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
  let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await aesGenerator.convertKey(symKeyBlob);
  console.info('convertKey success');
  return symKey;
}

async function aesCBC() {
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
  console.info('main step success');
}
```

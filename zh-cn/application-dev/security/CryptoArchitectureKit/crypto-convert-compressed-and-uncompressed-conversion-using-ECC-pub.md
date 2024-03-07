# 使用ECC压缩/非压缩公钥格式转换

可通过指定X509格式压缩/非压缩的完整ECC公钥数据，生成公钥对象（PubKey）；也可从公钥对象（PubKey）中，获取X509格式压缩/非压缩的完整ECC公钥数据。  
ECC的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。  
压缩/非压缩格式为要求输入的字符串参数，如需要获取压缩格式，则format定义为："X509|COMPRESSED"，需要获取非压缩格式，则format定义为："X509|UNCOMPRESSED"。


## 将非压缩公钥数据转换为ECC密钥对象

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)，指定字符串参数'ECC_BrainPoolP256r1'，创建密钥算法为ECC、密钥长度为256位的非对称密钥生成器（AsyKeyGenerator）。
2. 调用[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，随机生成非对称密钥对象（KeyPair）。
3. 调用[PubKey.getEncodedDer](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedder12)，获取非压缩公钥数据的字节流。
4. 调用[AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3)，传入获取后的DataBlob对象，生成非对称密钥对象（KeyPair）。
5. 调用[PubKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded)，获取公钥数据的字节流。

```ts
async function eccPubDataToPubKey() {
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.generateKeyPair();
  let returnBlob = keyPair.pubKey.getEncodedDer('X509|UNCOMPRESSED');
  console.info('returnBlob data：' + returnBlob.data);
  let outKeyPair = await generator.convertKey(returnBlob, null);
  let pkBlob = outKeyPair.pubKey.getEncoded();
  console.info('pkBlob data：' + pkBlob.data);
}
```


##  指定非压缩公钥数据转换为压缩公钥数据

1. 指定Uint8Array类型的ECC非压缩公钥数据，封装成DataBlob对象。  
公钥和私钥可只传入其中一个，此处示例以传入非压缩公钥为例。
2. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)，指定字符串参数'ECC_BrainPoolP256r1'，创建密钥算法为ECC、密钥长度为256位的非对称密钥生成器（AsyKeyGenerator）。
3. 调用[AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3)，传入封装后的DataBlob对象，生成非对称密钥对象（KeyPair）。
4. 调用[PubKey.getEncodedDer](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedder12)，设置参数为'X509|COMPRESSED'，获取压缩公钥数据的字节流。

```ts
async function eccPubUncompressedToCompressed() {
  let pkData = new Uint8Array([48, 90, 48, 20, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 9, 43, 36, 3, 3, 2, 8, 1, 1, 7, 3, 66, 0, 4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.convertKey(pubKeyBlob, null);
  let returnBlob = keyPair.pubKey.getEncodedDer('X509|COMPRESSED');
  console.info('returnBlob data：' + returnBlob.data);
}
```
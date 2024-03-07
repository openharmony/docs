# 使用ECC压缩/非压缩点格式转换

以ECC为例：  
可根据压缩/非压缩的点数据，转换为Point对象；也可根据Point对象转换为压缩/非压缩的点数据。  
ECC的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。  
压缩/非压缩格式为要求输入的字符串参数，如需要获取压缩格式，则format定义为："COMPRESSED"，需要获取非压缩格式，则format定义为："UNCOMPRESSED"。


## 指定非压缩点数据转换为压缩点数据

1. 指定Uint8Array类型的ECC非压缩点数据，调用[ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12)，构造[Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10)对象，用于生成点数据。
2. 调用[ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12)，获取压缩点数据。

```ts
function eccPointUncompressedToCompressed() {
  let pkData = new Uint8Array([4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
  console.info('convertPoint success');
  let returnBlob = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'COMPRESSED');
  console.info('returnBlob: ' + returnBlob);
}
```


## 点数据与Point对象相互转换

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)，指定字符串参数'ECC_BrainPoolP256r1'，创建密钥算法为ECC、密钥长度为256位的非对称密钥生成器（AsyKeyGenerator）。
2. 调用[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，随机生成非对称密钥对象（KeyPair）。
3. 调用[PubKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10)，获取ECC算法中，公钥pk的x坐标和y坐标。
4. 构造[Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10)对象，用于生成点数据。
5. 调用[ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12)，获取压缩点数据。
6. 调用[ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12)，获取[Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10)对象。

```ts
async function eccPointCompressedToPoint() {
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.generateKeyPair();
  let eccPkX = keyPair.pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
  let eccPkY = keyPair.pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
  console.info('ECC_PK_X_BN 16：' + eccPkX.toString(16));
  console.info('ECC_PK_Y_BN 16：' + eccPkY.toString(16));
  // 将eccPkX.toString(16)结果放入x，eccPkY.toString(16)结果放入y
  let returnPoint: cryptoFramework.Point = {
    x: BigInt('0x' + eccPkX.toString(16)),
    y: BigInt('0x' + eccPkY.toString(16))
  };
  let returnBlob = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'COMPRESSED');
  console.info('returnBlob: ' + returnBlob);
  let outPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', returnBlob);
  console.info('outPoint: ' + outPoint.x.toString(16));
}
```
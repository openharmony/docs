# 使用ECC压缩/非压缩点格式转换(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
 
支持将压缩/非压缩的点数据转换为Point对象，用于密钥对象生成；也支持将Point对象转换为压缩/非压缩的点数据。  
ECC的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。  
通过传入字符串参数format，可指定需要获取的点数据格式。如果需要获取压缩格式，则指定format为："COMPRESSED"；需要获取非压缩格式，则指定format为："UNCOMPRESSED"。

## 指定非压缩点数据转换为压缩点数据

1. 指定Uint8Array类型的ECC非压缩点数据，调用[ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12)，构造[Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10)对象，用于生成点数据。
2. 调用[ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12)，获取压缩点数据。

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function eccPointUncompressedToCompressed() {
  let pkData = new Uint8Array([4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
  console.info('convertPoint success');
  let returnData = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'COMPRESSED');
  console.info('returnData: ' + returnData); // (因为y为偶数，所以压缩点数据的前缀是02)returnData: 2,143,39,57,249,145,50,63,222,35,70,178,121,202,154,21,146,129,75,76,63,8,195,157,111,40,217,215,148,120,224,205,82
}
```

## 指定压缩点数据获取密钥对象

1. 指定Uint8Array类型的ECC压缩点数据，调用[ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12)，得到[Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10)对象，用于密钥对象生成。
2. 调用[ECCKeyUtil.genECCCommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#genecccommonparamsspec11)，指定曲线名'NID_brainpoolP256r1'，生成ECC的非对称公共密钥参数。
3. 构造[ECCPubKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#eccpubkeyspec10)对象，用于指定ECC算法中公钥包含的参数。ECCPubKeySpec是AsyKeySpec的子类。需要通过参数algName指定算法'ECC'；指定密钥参数类型[AsyKeySpecType.PUBLIC_KEY_SPEC](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#asykeyspectype10)，参数pk指定为得到的point对象。
4. 通过得到的公钥参数，调用[createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10)，创建非对称密钥生成器（AsyKeyGeneratorBySpec）。
5. 调用[AsyKeyGeneratorBySpec.generatePubKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatepubkey10)，得到指定的公钥。
6. 调用[ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12)，得到非压缩点数据。
7. 调用[PubKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10)，获取ECC算法中公钥pk的x坐标。

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function eccPointCompressedToPoint() {
  let pkData = new Uint8Array([2, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82]);
  let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
  console.info('convertPoint success');
  let eccCommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_brainpoolP256r1');
  let eccPubKeySpec: cryptoFramework.ECCPubKeySpec = {
    algName: "ECC",
    specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC,
    params: eccCommonParamsSpec,
    pk: returnPoint
  };
  let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(eccPubKeySpec);
  let pubKey = await generatorBySpec.generatePubKey();
  let returnData = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'UNCOMPRESSED');
  console.info('returnData: ' + returnData); // 4,143,39,57,249,145,50,63,222,35,70,178,121,202,154,21,146,129,75,76,63,8,195,157,111,40,217,215,148,120,224,205,82,83,92,185,21,211,184,5,19,114,33,86,85,228,123,242,206,200,98,178,184,130,35,232,45,5,202,189,11,46,163,156,152
  let eccPkX = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
  console.info('returnPoint x data: ' + returnPoint.x); // 64750044510792891439269945828433327517677381559622384455951527515863444933970
  console.info('ECC_PK_X_BN: ' + eccPkX); // 64750044510792891439269945828433327517677381559622384455951527515863444933970
}
```
# 指定密钥参数生成非对称密钥对

以RSA、ECC为例，根据指定的密钥参数，生成非对称密钥对（KeyPair），并获取密钥参数属性。

该对象可用于后续的加解密等操作。获取的密钥参数属性可用于存储或运输。


## 指定密钥参数生成RSA公钥

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 构造[RSACommonParamsSpec](../../reference/apis/js-apis-cryptoFramework.md#rsacommonparamsspec10)对象，用于指定RSA算法中公私钥包含的公共参数（n）。
   
   RSACommonParamsSpec是AsyKeySpec的子类。需要通过参数algName指定算法'RSA'；指定密钥参数类型AsyKeySpecType.COMMON_PARAMS_SPEC，表示是公私钥中包含的公共参数。

   使用密钥参数生成密钥时，用到的bigint类型需要以大端模式输入，且必须为正数。

2. 创建[RSAPubKeySpec](../../reference/apis/js-apis-cryptoFramework.md#rsapubkeyspec10)对象，用于指定RSA算法中公钥包含的参数（n, pk）。
   
   RSAPubKeySpec是AsyKeySpec的子类。通过参数algName指定算法'RSA'；指定密钥参数类型AsyKeySpecType.PUBLIC_KEY_SPEC，表示是公钥中包含的参数。

3. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)BySpec，将RSAPubKeySpec对象传入，创建非对称密钥生成器（AsyKeyGeneratorBySpec）。

4. 调用[AsyKeyGeneratorBySpec.generatePubKey](../../reference/apis/js-apis-cryptoFramework.md#generatepubkey-1)，获得指定的公钥（PubKey）。

5. 调用[PubKey.getAsyKeySpec](../../reference/apis/js-apis-cryptoFramework.md#getasykeyspec10)，获取模数n和公钥pk（即公钥指数e）。

以使用callback方式根据密钥参数生成RSA公钥为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
// RSA公钥密钥参数生成函数
function genRsaPubKeySpec(nIn: bigint, eIn: bigint): cryptoFramework.RSAPubKeySpec {
  let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
    n: nIn,
    algName: 'RSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
  };
  let rsaPubKeySpec: cryptoFramework.RSAPubKeySpec = {
    params: rsaCommSpec,
    pk: eIn,
    algName: 'RSA',
    specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC
  };
  return rsaPubKeySpec;
}
// 根据密钥参数构造RSA公钥规范对象
function genRsa2048PubKeySpec() {
  let nIn = BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
  let eIn = BigInt('0x010001');
  return genRsaPubKeySpec(nIn, eIn);
}
// 将RSA公钥规格与预期值进行比较
function compareRsaPubKeyBySpec(rsaKeySpec: cryptoFramework.RSAPubKeySpec, n: bigint | string | number, e: bigint | string | number) {
  if (typeof n === 'string' || typeof e === 'string') {
    console.error('type is string');
    return false;
  }
  if (typeof n === 'number' || typeof e === 'number') {
    console.error('type is number');
    return false;
  }
  if (rsaKeySpec.params.n != n) {
    return false;
  }
  if (rsaKeySpec.pk != e) {
    return false;
  }
  return true;
}
// 根据RSA公钥规格生成RSA公钥，获取密钥规格，并与预期值进行比较
function rsaUsePubKeySpecGetCallback() {
  let rsaPubKeySpec = genRsa2048PubKeySpec();
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaPubKeySpec);
  rsaGeneratorSpec.generatePubKey((error, key) => {
    let pubKey = key;
    let nBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_N_BN);
    let eBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_PK_BN);
    if (compareRsaPubKeyBySpec(rsaPubKeySpec, nBN, eBN) != true) {
      AlertDialog.show({ message: 'error pub key big number' });
    } else {
      console.info('n, e in the pubKey are same as the spec.');
    }
    if (error) {
      console.error('generate pubKey error' + 'error code: ' + error.code + 'error message' + error.message);
    }
  });
}
```


## 指定密钥参数生成ECC密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。

1. 构造ECCCommonParamsSpec对象，用于指定ECC算法中公私钥包含的公共参数。
   ECCCommonParamsSpec是AsyKeySpec的子类。需要通过参数algName指定算法'ECC'；指定密钥参数类型AsyKeySpecType.COMMON_PARAMS_SPEC，表示是公私钥中包含的公共参数。

   使用密钥参数生成密钥时，用到的bigint类型需要以大端模式输入，且必须为正数。

2. 创建ECCPubKeySpec对象，用于指定ECC算法中公钥包含的参数。

3. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)BySpec，将ECCPubKeySpec对象传入，创建非对称密钥生成器（AsyKeyGeneratorBySpec）。

4. 调用[AsyKeyGeneratorBySpec.generatePubKey](../../reference/apis/js-apis-cryptoFramework.md#generatepubkey-1)，获得指定的公钥（PubKey）。

5. 调用[PubKey.getAsyKeySpec](../../reference/apis/js-apis-cryptoFramework.md#getasykeyspec10)，获取ECC算法中的各种密钥参数。

以使用Promise方式根据密钥参数生成ECC密钥为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 打印bigint信息
function showBigIntInfo(bnName: string, bnValue: bigint | string | number) {
  if (typeof bnValue === 'string') {
    console.error('type is string');
    return;
  }
  if (typeof bnValue === 'number') {
    console.error('type is number');
    return;
  }
  console.info(bnName + ':');
  console.info('. Decimal: ' + bnValue.toString());
  console.info('. Hexadecimal: ' + bnValue.toString(16));
  console.info('. Length (bits): ' + bnValue.toString(2).length);
}
// 根据关键规范构造EccCommonSpec结构体。EccCommonSpec结构体定义了ECC私钥和公钥的公共参数
function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
  let fieldFp: cryptoFramework.ECFieldFp = {
    fieldType: 'Fp',
    p: BigInt('0xffffffffffffffffffffffffffffffff000000000000000000000001')
  }
  let G: cryptoFramework.Point = {
    x: BigInt('0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21'),
    y: BigInt('0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34')
  }
  let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
    algName: 'ECC',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    field: fieldFp,
    a: BigInt('0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe'),
    b: BigInt('0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4'),
    g: G,
    n: BigInt('0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d'),
    h: 1
  }
  return eccCommonSpec;
}
// 打印ECC密钥规格
function showEccSpecDetailInfo(key: cryptoFramework.PubKey | cryptoFramework.PriKey, keyType: string) {
  console.info('show detail of ' + keyType + ':');
  try {
    let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
    showBigIntInfo('--- p', p); // length is 224, hex : ffffffffffffffffffffffffffffffff000000000000000000000001
    let a = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_A_BN);
    showBigIntInfo('--- a', a); // length is 224, hex : fffffffffffffffffffffffffffffffefffffffffffffffffffffffe
    let b = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_B_BN);
    showBigIntInfo('--- b', b); // length is 224, hex : b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4
    let gX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_X_BN);
    showBigIntInfo('--- gX', gX); // length is 224, hex : b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21
    let gY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_Y_BN);
    showBigIntInfo('--- gY', gY); // length is 224, hex : bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34
    let n = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_N_BN);
    showBigIntInfo('--- n', n); // length is 224, hex : ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d
    let h = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_H_NUM);
    console.warn('--- h: ' + h); // key h: 1
    let fieldType = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_TYPE_STR);
    console.warn('--- field type: ' + fieldType); // key field type: Fp
    let fieldSize = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_SIZE_NUM);
    console.warn('--- field size: ' + fieldSize); // key field size: 224
    let curveName = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
    console.warn('--- curve name: ' + curveName); // key curve name: NID_secp224r1
    if (keyType == 'priKey') {
      let sk = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_SK_BN);
      showBigIntInfo('--- sk', sk);
    } else if (keyType == 'pubKey') {
      let pkX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
      showBigIntInfo('--- pkX', pkX);
      let pkY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
      showBigIntInfo('--- pkY', pkY);
    }
  } catch (error) {
    console.error('getAsyKeySpec error');
    let e: BusinessError = error as BusinessError;
    console.error(`getAsyKeySpec failed, ${e.code}, ${e.message}`);
  }
}
// 根据EccCommonSpec实例生成ECC密钥对，获取密钥规格
function testEccUseCommKeySpecGet() {
  try {
    let commKeySpec = genEccCommonSpec(); // 使用参数属性，构造ECC公私钥公共密钥参数对象
    let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // 使用密钥参数对象创建生成器
    let keyPairPromise = generatorBySpec.generateKeyPair(); // Generate an ECC key pair.
    keyPairPromise.then(keyPair => { // 使用生成器创建ECC密钥对
      showEccSpecDetailInfo(keyPair.priKey, 'priKey'); // 对私钥获取相关密钥参数属性
      showEccSpecDetailInfo(keyPair.pubKey, 'pubKey'); // 对公钥获取相关密钥参数属性
    }).catch((error: BusinessError) => {
      // 逻辑错误等异步异常在此捕获
      console.error('generateComm error');
      console.error('error code: ' + error.code + ', message is: ' + error.message);
    })
  } catch (error) {
    // 参数错误等同步异常在此捕获
    console.error('testEccUseCommSpec error');
    let e: BusinessError = error as BusinessError;
    console.error(`ecc comm spec failed, ${e.code}, ${e.message}`);
  }
}
```

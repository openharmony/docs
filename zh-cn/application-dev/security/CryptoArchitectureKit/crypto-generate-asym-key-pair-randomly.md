# 随机生成非对称密钥对


以RSA和SM2为例，随机生成非对称密钥对（KeyPair），并获得二进制数据。


非对称密钥对可用于后续加解密等操作，二进制数据可用于存储或运输。


## 随机生成RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)，指定字符串参数'RSA1024|PRIMES_2'，创建RSA密钥类型为RSA1024、素数个数为2的非对称密钥生成器（AsyKeyGenerator）。

2. 调用[AsyKeyGenerator.generateKeyPair](../../reference/apis/js-apis-cryptoFramework.md#generatekeypair-1)，随机生成非对称密钥对象（KeyPair）。
   
   KeyPair对象中包括公钥PubKey、私钥PriKey。

3. 调用[PubKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded)和[PriKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded)，分别获取密钥对象的二进制数据。

以使用Promise方式随机生成RSA密钥对为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // 创建一个AsyKeyGenerator实例
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
  // 使用密钥生成器随机生成非对称密钥对
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // 获取非对称密钥对的二进制数据
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  });
}
```


## 随机生成SM2密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：SM2](crypto-asym-key-generation-conversion-spec.md#sm2)。

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)，指定字符串参数'SM2_256'，创建密钥算法为SM2、密钥长度为256位的非对称密钥生成器（AsyKeyGenerator）。

2. 调用[AsyKeyGenerator.generateKeyPair](../../reference/apis/js-apis-cryptoFramework.md#generatekeypair-1)，随机生成非对称密钥对象（KeyPair）。
   
   KeyPair对象中包括公钥PubKey、私钥PriKey。

3. 调用[PubKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded)和[PriKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded)，分别获取密钥对象的二进制数据。

以使用Promise方式随机生成SM2密钥对为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateSM2Key() {
  // 创建一个AsyKeyGenerator实例
  let sm2Generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
  // 使用密钥生成器随机生成非对称密钥对
  let keyGenPromise = sm2Generator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // 获取非对称密钥对的二进制数据
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  });
}
```

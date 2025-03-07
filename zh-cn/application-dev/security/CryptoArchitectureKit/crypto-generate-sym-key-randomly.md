# 随机生成对称密钥(ArkTS)


以AES和SM4为例，随机生成对称密钥（SymKey），并获得二进制数据。


对称密钥对象可用于后续加解密操作，二进制数据可用于存储或运输。


## 随机生成AES密钥

对应的算法规格请查看[对称密钥生成和转换规格：AES](crypto-sym-key-generation-conversion-spec.md#aes)。

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)，指定字符串参数'AES256'，创建密钥算法为AES、密钥长度为256位的对称密钥生成器（SymKeyGenerator）。

2. 调用[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，随机生成对称密钥对象（SymKey）。

3. 调用[SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded)，获取密钥对象的二进制数据。

- 以使用Promise方式随机生成AES密钥为例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testGenerateAesKey() {
    // 创建SymKeyGenerator实例
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
    // 使用密钥生成器随机生成对称密钥
    let promiseSymKey = symKeyGenerator.generateSymKey();
    promiseSymKey.then(key => {
      // 获取对称密钥的二进制数据，输出256位密钥。长度为32字节
      let encodedKey = key.getEncoded();
      console.info('key hex:' + encodedKey.data);
    });
  }
  ```

- 同步方法（调用方法[generateSymKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkeysync12)）：
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testSyncGenerateAesKey() {
    // 创建SymKeyGenerator实例
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
    // 使用密钥生成器随机生成对称密钥
    let promiseSymKey = symKeyGenerator.generateSymKeySync();
    // 获取对称密钥的二进制数据，输出256位密钥。长度为32字节
    let encodedKey = promiseSymKey.getEncoded();
    console.info('key hex:' + encodedKey.data);
  }
  ```


## 随机生成SM4密钥

对应的算法规格请查看[对称密钥生成和转换规格：SM4](crypto-sym-key-generation-conversion-spec.md#sm4)。

1. 调用[cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator)，指定字符串参数'SM4_128'，创建密钥算法为SM4、密钥长度为128位的对称密钥生成器（SymKeyGenerator）。
   如果开发者需要使用其他算法，请注意修改此处入参的字符串参数。

2. 调用[SymKeyGenerator.generateSymKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkey-1)，随机生成对称密钥对象（SymKey）。

3. 调用[SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded)，获取密钥对象的二进制数据。

- 以使用Promise方式随机生成SM4密钥为例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testGenerateSM4Key() {
    // 创建SymKeyGenerator实例
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    // 使用密钥生成器随机生成对称密钥
    let promiseSymKey = symKeyGenerator.generateSymKey();
    promiseSymKey.then(key => {
      // 获取对称密钥的二进制数据，输出128位字节流。长度为16字节
      let encodedKey = key.getEncoded();
      console.info('key hex:' + encodedKey.data);
    });
  }
  ```

- 同步方法（调用方法[generateSymKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesymkeysync12)）：
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function testSyncGenerateSm4Key() {
    // 创建SymKeyGenerator实例
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('SM4_128');
    // 使用密钥生成器随机生成对称密钥
    let promiseSymKey = symKeyGenerator.generateSymKeySync();
    // 获取对称密钥的二进制数据，输出128位字节流。长度为16字节
    let encodedKey = promiseSymKey.getEncoded();
    console.info('key hex:' + encodedKey.data);
  }
  ```

# 使用PBKDF2进行密钥派生(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

对应的算法规格请查看[密钥派生算法规格：PBKDF2](crypto-key-derivation-overview.md#pbkdf2算法)。

## 开发步骤

1. 构造[PBKDF2Spec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pbkdf2spec11)对象，作为密钥派生参数进行密钥派生。

   PBKDF2Spec是[KdfSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#kdfspec11)的子类，需要指定：

   - algName：指定算法'PBKDF2'。
   - password：用于生成派生密钥的原始密码。
      如果使用string类型，需要直接传入用于密钥派生的数据，而不是HexString、base64等字符串类型。同时需要确保该字符串为utf-8编码，否则派生结果会有差异。
   - salt：盐值。
   - iterations：重复运算的次数，需要为正整数。
   - keySize：目标密钥的字节长度，需要为正整数。

2. 调用[cryptoFramework.createKdf](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekdf11)，指定字符串参数'PBKDF2|SHA256'，创建密钥派生算法为PBKDF2、HMAC函数摘要算法为SHA256的密钥派生函数对象（Kdf）。

3. 输入PBKDF2Spec对象，调用[Kdf.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret-2)进行密钥派生。

   Kdf.generateSecret的多种调用形式如表所示。

   | 接口名 | 返回方式 |
   | -------- | -------- |
   | generateSecret(params: KdfSpec, callback: AsyncCallback&lt;DataBlob&gt;): void | callback异步生成。 |
   | generateSecret(params: KdfSpec): Promise&lt;DataBlob&gt; | Promise异步生成。 |
   | generateSecretSync(params: KdfSpec): DataBlob | 同步生成。 |

- 通过await返回结果：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function kdfAwait() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let secret = await kdf.generateSecret(spec);
    console.info("key derivation output is " + secret.data);
  }
  ```

- 通过Promise返回结果：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function kdfPromise() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let kdfPromise = kdf.generateSecret(spec);
    kdfPromise.then((secret) => {
      console.info("key derivation output is " + secret.data);
    }).catch((error: BusinessError) => {
      console.error("key derivation error.");
    });
  }
  ```

- 通过同步方式返回结果：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function kdfSync() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let secret = kdf.generateSecretSync(spec);
    console.info("[Sync]key derivation output is " + secret.data);
  }
  ```

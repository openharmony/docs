# 密钥派生


密钥派生函数（key derivation function）是指使用伪随机函数从秘密值（如主密钥）中导出一个或多个密钥。密钥派生函数可用于将密钥扩展到更长的密钥或获得所需格式的密钥。


比如，当用户输入指定的密码，通过密钥派生函数，可以生成指定长度的密钥。


## 支持的算法与规格

当前仅支持PBKDF2算法。

PBKDF（Password-Based Key Derivation Function）是具有可变计算成本的密钥派生函数；PBKDF2是PKCS系列的标准之一。

PBKDF2是将伪随机函数PRF（Pseudo-Random Function，例如基于散列的[HMAC](crypto-compute-mac.md)），输入密码明文和盐值，重复多次运算来进行密钥派生。

当前支持以字符串参数进行密钥派生，具体的“字符串参数”由“密钥派生函数”和“HMAC函数摘要算法”使用符号“|”拼接而成，用于在创建密钥派生函数生成器时，指定算法规格。
| 密钥派生算法 | HMAC函数摘要算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- | -------- |
| PBKDF2 | SHA1 | PBKDF2\|SHA1 | 11+ | 
| PBKDF2 | SHA224 | PBKDF2\|SHA224 | 11+ | 
| PBKDF2 | SHA256 | PBKDF2\|SHA256 | 11+ | 
| PBKDF2 | SHA384 | PBKDF2\|SHA384 | 11+ | 
| PBKDF2 | SHA512 | PBKDF2\|SHA512 | 11+ | 
| PBKDF2 | SM3 | PBKDF2\|SM3 | 11+ | 


## 开发步骤

1. 构造[PKBDF2Spec](../../reference/apis/js-apis-cryptoFramework.md#pbkdf2spec11)对象，作为密钥派生参数进行密钥派生。
   
   PKBDF2Spec是KdfSpec的子类，需要指定：

   - algName：指定算法'PBKDF2'。
   - password：用于生成派生密钥的原始密码。
      如果使用string类型，需要直接传入用于密钥派生的数据，而不是HexString、base64等字符串类型。同时需要确保该字符串为utf-8编码，否则派生结果会有差异。
   - salt：盐值。
   - iterations：重复运算的次数，需要为正整数。
   - keySize：目标密钥的字节长度，需要为正整数。

2. 调用[cryptoFramework.createKdf](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatekdf11)，指定字符串参数'PBKDF2|SHA256'，创建密钥派生算法为PBKDF2、HMAC函数摘要算法为SHA256的密钥派生函数对象（Kdf）。

3. 输入PKBDF2Spec对象，调用[Kdf.generateSecret](../../reference/apis/js-apis-cryptoFramework.md#generatesecret-2)进行密钥派生。
   
   Kdf.generateSecret的多种调用形式如表所示。
   
   | 接口名 | 返回方式 | 
   | -------- | -------- |
   | generateSecret(params: KdfSpec, callback: AsyncCallback&lt;DataBlob&gt;): void | callback异步生成 | 
   | generateSecret(params: KdfSpec): Promise&lt;DataBlob&gt; | Promise异步生成 | 

- 通过await返回结果：
  ```ts
  import cryptoFramework from '@ohos.security.cryptoFramework';
  
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
  import cryptoFramework from '@ohos.security.cryptoFramework';
  import { BusinessError } from '@ohos.base';
  
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

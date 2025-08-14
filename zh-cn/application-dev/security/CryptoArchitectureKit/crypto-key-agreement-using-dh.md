# 使用DH进行密钥协商(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

对应的算法规格请查看[密钥协商算法规格：DH](crypto-key-agreement-overview.md#dh)。

## 开发步骤

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)生成密钥算法为DH、采用知名安全素数群modp1536的非对称密钥（KeyPair）。
   如何生成DH非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：DH](crypto-asym-key-generation-conversion-spec.md#dh)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createKeyAgreement](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekeyagreement)，指定字符串参数'DH_modp1536'，创建密钥算法为DH、采用知名安全素数群modp1536的密钥协议生成器（KeyAgreement）。

3. 调用[KeyAgreement.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret-1)，基于传入的私钥（KeyPair.priKey）与公钥（KeyPair.pubKey）进行密钥协商，返回共享秘密。

- 异步方法示例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function dhAwait() {
    let keyGen = cryptoFramework.createAsyKeyGenerator('DH_modp1536');
    // 随机生成公私钥对A。
    let keyPairA = await keyGen.generateKeyPair();
    // 随机生成规格一致的公私钥对B。
    let keyPairB = await keyGen.generateKeyPair();
    let keyAgreement = cryptoFramework.createKeyAgreement('DH_modp1536');
    // 使用A的公钥和B的私钥进行密钥协商。
    let secret1 = await keyAgreement.generateSecret(keyPairB.priKey, keyPairA.pubKey);
    // 使用A的私钥和B的公钥进行密钥协商。
    let secret2 = await keyAgreement.generateSecret(keyPairA.priKey, keyPairB.pubKey);
    // 两种协商的结果应当一致。
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('DH success');
      console.info('DH output is ' + secret1.data);
    } else {
      console.error('DH result is not equal');
    }
  }
  ```

- 同步方法示例：

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function dhAgreementSync() {
    let keyGen = cryptoFramework.createAsyKeyGenerator('DH_modp1536');
    // 随机生成公私钥对A。
    let keyPairA = keyGen.generateKeyPairSync();
    // 随机生成规格一致的公私钥对B。
    let keyPairB = keyGen.generateKeyPairSync();
    let keyAgreement = cryptoFramework.createKeyAgreement('DH_modp1536');
    // 使用A的公钥和B的私钥进行密钥协商。
    let secret1 = keyAgreement.generateSecretSync(keyPairB.priKey, keyPairA.pubKey);
    // 使用A的私钥和B的公钥进行密钥协商。
    let secret2 = keyAgreement.generateSecretSync(keyPairA.priKey, keyPairB.pubKey);
    // 两种协商的结果应当一致。
    if (secret1.data.toString() === secret2.data.toString()) {
      console.info('DH success');
      console.info('DH output is ' + secret1.data);
    } else {
      console.error('DH result is not equal');
    }
  }
  ```

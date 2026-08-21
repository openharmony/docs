# 使用ECC密钥对签名验签(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 使用ECC密钥对签名验签（OnlySign和OnlyVerify模式）

从API版本26.0.0开始，签名验签支持OnlySign/OnlyVerify模式。对应的算法规格请查看[签名验签算法规格：ECDSA](crypto-sign-sig-verify-overview.md#ecdsa)。

**签名**

1. 调用[cryptoFramework.createMd](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemd)，指定摘要算法SHA1，生成摘要实例（Md）。

2. 调用[Md.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-6)，传入自定义消息，进行摘要更新计算。单次update长度没有限制。

3. 调用[Md.digest](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#digest)，获取摘要计算结果。

4. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为ECC、曲线类型为ECC224的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。

   如何生成ECC非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：ECC](crypto-key-generation-conversion.md#ecc)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

5. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'ECC|SHA1|OnlySign'，创建非对称密钥类型为ECC、摘要算法为SHA1、签名模式为OnlySign的Sign实例，用于完成签名操作。

6. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

7. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成摘要数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'ECC|SHA1|OnlyVerify'，创建非对称密钥类型为ECC、摘要算法为SHA1、验签模式为OnlyVerify的Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对摘要数据进行验签。

- 异步方法示例：

  <!-- @[ecc_onlysign_onlyverify_signature_verification_asynchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/ecc_onlysign_onlyverify_signature_verification_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'ECC|SHA1|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let signData = await signer.sign(digestBlob);
    return signData;
  }
  
  async function verifyMessagePromise(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'ECC|SHA1|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let res = await verifier.verify(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is ecc onlySign test', 'utf-8').buffer) };
    // 先使用 Md 计算 SHA1 摘要（20字节）
    let md = cryptoFramework.createMd('SHA1');
    await md.update(messageData);
    let digestBlob = await md.digest();
    let keyGenAlg = 'ECC224';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let signData = await signMessagePromise(keyPair.priKey, digestBlob);
    let verifyResult = await verifyMessagePromise(digestBlob, signData, keyPair.pubKey);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```


- 同步方法示例：

  <!-- @[ecc_onlysign_onlyverify_signature_verification_synchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/ecc_onlysign_onlyverify_signature_verification_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function signMessageSync(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'ECC|SHA1|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let signData = signer.signSync(digestBlob);
    return signData;
  }
  
  function verifyMessageSync(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'ECC|SHA1|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let res = verifier.verifySync(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is ecc onlySign test', 'utf-8').buffer) };
    let md = cryptoFramework.createMd('SHA1');
    md.updateSync(messageData);
    let digestBlob = md.digestSync();
    let keyGenAlg = 'ECC224';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let signData = signMessageSync(keyPair.priKey, digestBlob);
    let verifyResult = verifyMessageSync(digestBlob, signData, keyPair.pubKey);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

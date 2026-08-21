# 使用RSA密钥对签名验签(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

对应的算法规格请查看[签名验签算法规格：RSA](crypto-sign-sig-verify-overview.md#rsa)。

## 使用RSA密钥对（PKCS1模式）签名验签

**签名**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为RSA、密钥长度为1024位、素数个数为2的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。
   
   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA1024|PKCS1|SHA256'，创建非对称密钥类型为RSA1024、填充模式为PKCS1、摘要算法为SHA256的Sign实例，用于完成签名操作。

3. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

4. 调用[Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3)，传入待签名的数据。
   
   当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

   - 当待签名的数据较短时，可以在init完成后直接调用sign。
   - 当数据量较大时，可以多次调用update，即[分段签名验签](crypto-rsa-sign-sig-verify.md#使用rsa密钥对pkcs1模式分段签名验签)。

5. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA1024|PKCS1|SHA256'，与签名的Sign实例保持一致。创建Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5)，传入待验证的数据。

   当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

   - 当待签名的数据较短时，可以在init完成后直接调用verify。
   - 当数据量较大时，可以多次调用update，即[分段签名验签](crypto-rsa-sign-sig-verify.md#使用rsa密钥对pkcs1模式分段签名验签)。

4. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对数据进行验签。

- 异步方法示例：

  <!-- @[pkcs1_verify_rsa_keypair_sign_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_signature_validator/rsa_pkcs1_signature_validator_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 完整的明文被拆分为input1和input2
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = 'RSA1024|PKCS1|SHA256';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    await signer.update(input1); // 如果明文较短，可以直接调用sign接口一次性传入
    let signData = await signer.sign(input2);
    return signData;
  }
  
  async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    await verifier.update(input1); // 如果明文较短，可以直接调用verify接口一次性传入
    let res = await verifier.verify(input2, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function main() {
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let signData = await signMessagePromise(keyPair.priKey);
    let verifyResult = await verifyMessagePromise(signData, keyPair.pubKey);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[pkcs1_verify_rsa_keypair_sign_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_signature_validator/rsa_pkcs1_signature_validator_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 完整的明文被拆分为input1和input2
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  
  function signMessageSync(priKey: cryptoFramework.PriKey) {
    let signAlg = 'RSA1024|PKCS1|SHA256';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    signer.updateSync(input1); // 如果明文较短，可以直接调用sign接口一次性传入
    let signData = signer.signSync(input2);
    return signData;
  }
  
  function verifyMessageSync(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    verifier.updateSync(input1); // 如果明文较短，可以直接调用verify接口一次性传入
    let res = verifier.verifySync(input2, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function main() {
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let signData = signMessageSync(keyPair.priKey);
    let verifyResult = verifyMessageSync(signData, keyPair.pubKey);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

## 使用RSA密钥对（PKCS1模式）签名验签（OnlySign和OnlyVerify模式）

从API版本26.0.0开始，签名验签支持OnlyVerify模式。

**签名**

1. 调用[cryptoFramework.createMd](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemd)，指定摘要算法SHA256，生成摘要实例（Md）。

2. 调用[Md.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-6)，传入自定义消息，进行摘要更新计算。单次update长度没有限制。

3. 调用[Md.digest](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#digest)，获取摘要计算结果。

4. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为RSA、密钥长度为1024位、素数个数为2的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。

   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

5. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA1024|PKCS1|SHA256|OnlySign'，创建非对称密钥类型为RSA1024、填充模式为PKCS1、摘要算法为SHA256的Sign实例，用于完成签名操作。

6. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

7. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成摘要数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA1024|PKCS1|SHA256|OnlyVerify'，与签名的Sign实例保持一致。创建Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对摘要数据进行验签。

- 异步方法示例：

  <!-- @[rsa_pkcs1_onlysign_onlyverify_signature_validator_asynchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/rsa_pkcs1_onlysign_onlyverify_signature_validator_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'RSA1024|PKCS1|SHA256|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let signData = await signer.sign(digestBlob);
    return signData;
  }
  
  async function verifyMessagePromise(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let res = await verifier.verify(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is rsa onlySign test', 'utf-8').buffer) };
    // 先使用 Md 计算 SHA256 摘要（32字节）
    let md = cryptoFramework.createMd('SHA256');
    await md.update(messageData);
    let digestBlob = await md.digest();
    let keyGenAlg = 'RSA1024';
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

  <!-- @[rsa_pkcs1_onlysign_onlyverify_signature_validator_synchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/rsa_pkcs1_onlysign_onlyverify_signature_validator_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function signMessageSync(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'RSA1024|PKCS1|SHA256|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let signData = signer.signSync(digestBlob);
    return signData;
  }
  
  function verifyMessageSync(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let res = verifier.verifySync(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is rsa onlySign test', 'utf-8').buffer) };
    // 先使用 Md 计算 SHA256 摘要（32字节）
    let md = cryptoFramework.createMd('SHA256');
    md.updateSync(messageData);
    let digestBlob = md.digestSync();
    let keyGenAlg = 'RSA1024';
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

## 使用RSA密钥对（PKCS1模式）签名及签名恢复

**签名**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为RSA、密钥长度为1024位、素数个数为2的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。
   
   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA1024|PKCS1|NoHash|OnlySign'，创建非对称密钥类型为RSA1024、填充模式为PKCS1、签名模式为OnlySign的Sign实例，用于完成仅签名操作。

3. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

4. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA1024|PKCS1|NoHash|Recover'，与签名的Sign实例保持一致。创建Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.recover](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#recover12)，对数据进行签名恢复。

- 异步方法示例：

  <!-- @[pkcs1_recover_rsa_keypair_sign_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_signature_restoration/rsa_pkcs1_signature_restoration_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 完整的明文被拆分为input1和input2
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = 'RSA1024|PKCS1|NoHash|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let signData = await signer.sign(input1);
    return signData;
  }
  
  async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|NoHash|Recover';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let rawSignData = await verifier.recover(signMessageBlob);
    return rawSignData;
  }
  
  async function main() {
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let signData = await signMessagePromise(keyPair.priKey);
    let rawSignData = await verifyMessagePromise(signData, keyPair.pubKey);
    if (rawSignData != null) {
      console.info('recover result: ' + rawSignData.data);
    } else {
      console.error('get verify recover result: fail!');
    }
  }
  ```

- 同步方法示例：

  <!-- @[pkcs1_recover_rsa_keypair_sign_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_signature_restoration/rsa_pkcs1_signature_restoration_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 完整的明文被拆分为input1和input2
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  
  function signMessageSync(priKey: cryptoFramework.PriKey) {
    let signAlg = 'RSA1024|PKCS1|NoHash|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let signData = signer.signSync(input1);
    return signData;
  }
  
  function verifyMessageSync(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA1024|PKCS1|NoHash|Recover';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let rawSignData = verifier.recoverSync(signMessageBlob);
    return rawSignData;
  }
  
  function main() {
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let signData = signMessageSync(keyPair.priKey);
    let rawSignData = verifyMessageSync(signData, keyPair.pubKey);
    if (rawSignData != null) {
      console.info('recover result: ' + rawSignData.data);
    } else {
      console.error('get verify recover result: fail!');
    }
  }
  ```

## 使用RSA密钥对（PKCS1模式）分段签名验签

**签名**

1. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为RSA、密钥长度为1024位、素数个数为2的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。
   
   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA1024|PKCS1|SHA256'，创建非对称密钥类型为RSA1024、填充模式为PKCS1、摘要算法为SHA256的Sign实例，用于完成签名操作。

3. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

4. 将一次传入数据量设置为64字节，多次调用[Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3)，传入待签名的数据。当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

5. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA1024|PKCS1|SHA256'，与签名的Sign实例保持一致。创建Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5)，传入待验证的数据。当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

4. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对数据进行验签。

- 异步方法示例：

  <!-- @[pkcs1_seg_verify_rsa_keypair_sign_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_segment_signature/rsa_pkcs1_segment_signature_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  async function signMessageBySegment(priKey: cryptoFramework.PriKey, plainText: Uint8Array) {
    let signAlg = 'RSA1024|PKCS1|SHA256';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let textSplitLen = 64; // 自定义的数据拆分长度，此处取64
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      await signer.update(updateMessageBlob);
    }
    // 已通过分段传入所有明文，故此处sign传入null
    let signData = await signer.sign(null);
    return signData;
  }
  
  async function verifyMessageBySegment(pubKey: cryptoFramework.PubKey, plainText: Uint8Array,
    signMessageBlob: cryptoFramework.DataBlob) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let textSplitLen = 64; // 自定义的数据拆分长度，此处取64
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      await verifier.update(updateMessageBlob);
    }
    // 已通过分段传入所有明文，故此处verify第一个参数传入null
    let res = await verifier.verify(null, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function rsaSignatureBySegment() {
    let message = 'This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!';
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let messageData = new Uint8Array(buffer.from(message, 'utf-8').buffer);
    let signData = await signMessageBySegment(keyPair.priKey, messageData);
    let verifyResult = await verifyMessageBySegment(keyPair.pubKey, messageData, signData);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[pkcs1_seg_verify_rsa_keypair_sign_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pkcs1_segment_signature/rsa_pkcs1_segment_signature_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function signMessageBySegment(priKey: cryptoFramework.PriKey, plainText: Uint8Array) {
    let signAlg = 'RSA1024|PKCS1|SHA256';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let textSplitLen = 64; // 自定义的数据拆分长度，此处取64
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      signer.updateSync(updateMessageBlob);
    }
    // 已通过分段传入所有明文，故此处sign传入null
    let signData = signer.signSync(null);
    return signData;
  }
  
  function verifyMessageBySegment(pubKey: cryptoFramework.PubKey, plainText: Uint8Array,
    signMessageBlob: cryptoFramework.DataBlob) {
    let verifyAlg = 'RSA1024|PKCS1|SHA256';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let textSplitLen = 64; // 自定义的数据拆分长度，此处取64
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // 分段update
      verifier.updateSync(updateMessageBlob);
    }
    // 已通过分段传入所有明文，故此处verify第一个参数传入null
    let res = verifier.verifySync(null, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function rsaSignatureBySegment() {
    let message = 'This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!' +
      'This is a long plainText! This is a long plainText! This is a long plainText! This is a long plainText!';
    let keyGenAlg = 'RSA1024';
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let messageData = new Uint8Array(buffer.from(message, 'utf-8').buffer);
    let signData = signMessageBySegment(keyPair.priKey, messageData);
    let verifyResult = verifyMessageBySegment(keyPair.pubKey, messageData, signData);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

## 使用RSA密钥对（PSS模式）签名验签

**签名**

1. 调用[cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10)、[AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair10)，指定密钥参数，生成RSA非对称密钥对（KeyPair）。

   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[指定密钥参数生成非对称密钥对](crypto-generate-asym-key-pair-from-key-spec.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA|PSS|SHA256|MGF1_SHA256'，创建非对称密钥类型为不带长度的RSA、填充模式为PSS、摘要算法为SHA256、掩码算法为MGF1_SHA256的Sign实例，用于完成签名操作。

3. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

4. 调用[Sign.setSignSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setsignspec10)，设置签名参数。此处设置盐值的长度（SignSpecItem.PSS_SALT_LEN_NUM）为32字节。在验签时将校验此数据。

5. 调用[Sign.getSignSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getsignspec10)，获取其他签名参数。

6. 调用[Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3)，传入待签名的数据。当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

7. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA2048|PSS|SHA256|MGF1_SHA256'，创建非对称密钥类型为RSA2048、填充模式为PSS、摘要算法为SHA256、掩码算法为MGF1_SHA256的Verify实例，用于完成验签操作。

2. 调用[Verify.setVerifySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setverifyspec10)，设置签名参数。需要与签名时设置的保持一致。

3. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

4. 调用[Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5)，传入待验证的数据。当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

5. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对数据进行验签。

- 异步方法示例：

  <!-- @[pss_verify_rsa_keypair_sign_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pss_signature_verification/rsa_pss_signature_verification_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 根据密钥参数属性构造RSA非对称密钥对密钥参数
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  
  // 生成RSA2048密钥对参数
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn =
      BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc432' +
        '8daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4' +
        'd933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac' +
        '59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e2' +
        '53f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    let dIn =
      BigInt('0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb3' +
        '06aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8' +
        'bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b275' +
        '06c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde721' +
        '26b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1');
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }
  
  async function verifyMessagePSS() {
    // 完整的明文被拆分为input1和input2
    let messagePart1 = 'This is Sign test plan1';
    let messagePart2 = 'This is Sign test plan2';
    let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(messagePart1, 'utf-8').buffer) };
    let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(messagePart2, 'utf-8').buffer) };
    // 获得RSA密钥对密钥参数对象
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // 构造RSA密钥对生成器
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    // sign和verify均支持RSA密钥带长度/不带长度的写法
    let signer = cryptoFramework.createSign('RSA|PSS|SHA256|MGF1_SHA256');
    let verifier = cryptoFramework.createVerify('RSA2048|PSS|SHA256|MGF1_SHA256');
    let keyPair = await rsaGeneratorSpec.generateKeyPair();
    await signer.init(keyPair.priKey);
    // 在签名初始化后，对PSS参数进行set和get操作
    let setN = 32;
    signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info('SaltLen: ' + saltLen);
    let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info('trailer field: ' + tf);
    let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info('md: ' + md);
    let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info('mgf: ' + mgf);
    let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    console.info('mgf1Md: ' + mgf1Md);
    await signer.update(input1);
    let signMessageBlob = await signer.sign(input2);
    // 在验签初始化前，对PSS参数进行set和get操作
    verifier.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    saltLen = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info('SaltLen: ' + saltLen);
    tf = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info('trailer field: ' + tf);
    md = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info('md: ' + md);
    mgf = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info('mgf: ' + mgf);
    mgf1Md = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    await verifier.init(keyPair.pubKey);
    await verifier.update(input1);
    let verifyResult = await verifier.verify(input2, signMessageBlob);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

- 同步方法示例：

  <!-- @[pss_verify_rsa_keypair_sign_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/rsa_pss_signature_verification/rsa_pss_signature_verification_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  // 根据密钥参数属性构造RSA非对称密钥对密钥参数
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  
  // 生成RSA2048密钥对参数
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn =
      BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc43' +
        '28daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34' +
        'e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa' +
        '7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589' +
        'c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    let dIn =
      BigInt('0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb' +
        '306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283a' +
        'd8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b' +
        '27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdd' +
        'e72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1');
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }
  
  function verifyMessagePSSSync() {
    // 完整的明文被拆分为input1和input2
    let messagePart1 = 'This is Sign test plan1';
    let messagePart2 = 'This is Sign test plan2';
    let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(messagePart1, 'utf-8').buffer) };
    let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(messagePart2, 'utf-8').buffer) };
    // 获得RSA密钥对密钥参数对象
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // 构造RSA密钥对生成器
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    // sign和verify均支持RSA密钥带长度/不带长度的写法
    let signer = cryptoFramework.createSign('RSA|PSS|SHA256|MGF1_SHA256');
    let verifier = cryptoFramework.createVerify('RSA2048|PSS|SHA256|MGF1_SHA256');
    let keyPair = rsaGeneratorSpec.generateKeyPairSync();
    signer.initSync(keyPair.priKey);
    // 在签名初始化后，对PSS参数进行set和get操作
    let setN = 32;
    signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info('SaltLen: ' + saltLen);
    let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info('trailer field: ' + tf);
    let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info('md: ' + md);
    let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info('mgf: ' + mgf);
    let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    console.info('mgf1Md: ' + mgf1Md);
    signer.updateSync(input1);
    let signMessageBlob = signer.signSync(input2);
    // 在验签初始化前，对PSS参数进行set和get操作
    verifier.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    saltLen = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info('SaltLen: ' + saltLen);
    tf = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info('trailer field: ' + tf);
    md = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info('md: ' + md);
    mgf = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info('mgf: ' + mgf);
    mgf1Md = verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    verifier.initSync(keyPair.pubKey);
    verifier.updateSync(input1);
    let verifyResult = verifier.verifySync(input2, signMessageBlob);
    if (verifyResult === true) {
      console.info('verify result: success.');
    } else {
      console.error('verify result: failed.');
    }
  }
  ```

## 使用RSA密钥对（PSS模式）签名验签（OnlySign和OnlyVerify模式）

从API版本26.0.0开始，签名验签支持OnlySign/OnlyVerify模式。

**签名**

1. 调用[cryptoFramework.createMd](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemd)，指定摘要算法SHA256，生成摘要实例（Md）。

2. 调用[Md.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-6)，传入自定义消息，进行摘要更新计算。单次update长度没有限制。

3. 调用[Md.digest](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#digest)，获取摘要计算结果。

4. 调用[cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)、[AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1)，生成密钥算法为RSA、密钥长度为1024位、素数个数为2的非对称密钥对象（KeyPair），包括公钥（PubKey）和私钥（PriKey）。

   如何生成RSA非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

5. 调用[cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign)，指定字符串参数'RSA|PSS|SHA256|MGF1_SHA256|OnlySign'，创建非对称密钥类型为不带长度的RSA、填充模式为PSS、摘要算法为SHA256、掩码算法为MGF1_SHA256，签名模式为OnlySign的Sign实例，用于完成签名操作。

6. 调用[Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3)，使用私钥（PriKey）初始化Sign实例。

7. 调用[Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1)，生成摘要数据签名。

**验签**

1. 调用[cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)，指定字符串参数'RSA|PSS|SHA256|MGF1_SHA256|OnlyVerify'，创建非对称密钥类型为RSA、填充模式为PSS、摘要算法为SHA256、掩码算法为MGF1_SHA256，验签模式为OnlyVerify的Verify实例，用于完成验签操作。

2. 调用[Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5)，使用公钥（PubKey）初始化Verify实例。

3. 调用[Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1)，对摘要数据进行验签。

- 异步方法示例：

  <!-- @[rsa_pss_onlysign_onlyverify_signature_verification_asynchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/rsa_pss_onlysign_onlyverify_signature_verification_asynchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'RSA|PSS|SHA256|MGF1_SHA256|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let signData = await signer.sign(digestBlob);
    return signData;
  }
  
  async function verifyMessagePromise(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA|PSS|SHA256|MGF1_SHA256|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let res = await verifier.verify(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is rsa onlySign test', 'utf-8').buffer) };
    // 先使用 Md 计算 SHA256 摘要（32字节）
    let md = cryptoFramework.createMd('SHA256');
    await md.update(messageData);
    let digestBlob = await md.digest();
    let keyGenAlg = 'RSA1024';
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

  <!-- @[rsa_pss_onlysign_onlyverify_signature_verification_synchronous](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/onlysign_onlyverify_signature_validator/rsa_pss_onlysign_onlyverify_signature_verification_synchronous.ets) -->
  
  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  
  function signMessageSync(priKey: cryptoFramework.PriKey, digestBlob: cryptoFramework.DataBlob) {
    let signAlg = 'RSA|PSS|SHA256|MGF1_SHA256|OnlySign';
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let signData = signer.signSync(digestBlob);
    return signData;
  }
  
  function verifyMessageSync(digestBlob: cryptoFramework.DataBlob, signMessageBlob: cryptoFramework.DataBlob,
    pubKey: cryptoFramework.PubKey) {
    let verifyAlg = 'RSA|PSS|SHA256|MGF1_SHA256|OnlyVerify';
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let res = verifier.verifySync(digestBlob, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function main() {
    let messageData: cryptoFramework.DataBlob =
      { data: new Uint8Array(buffer.from('This is rsa onlySign test', 'utf-8').buffer) };
    // 先使用 Md 计算 SHA256 摘要（32字节）
    let md = cryptoFramework.createMd('SHA256');
    md.updateSync(messageData);
    let digestBlob = md.digestSync();
    let keyGenAlg = 'RSA1024';
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

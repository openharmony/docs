# Signing and Signature Recovery Using an RSA Key Pair (PKCS1 Mode) (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [RSA](crypto-sign-sig-verify-overview.md#rsa).

**Signing**

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 1024-bit RSA key pair (**KeyPair**) with two primes. The **KeyPair** instance consists of a public key (**PubKey**) and a private key (**PriKey**).
   
   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **'RSA1024|PKCS1|SHA256|SignOnly'** to create a **Sign** instance for signing without the MD. The key type is **RSA1024**, the padding mode is **PKCS1**, and the MD algorithm is **SHA256**.

3. Call [Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

4. Call [Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1) to generate a signature.

**Signature Verification**

1. Call [cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'RSA1024|PKCS1|SHA256|Recover'** to create a **Verify** instance. The key parameters must be the same as that used to create the **Sign** instance.

2. Call [Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance using the public key (**PubKey**).

3. Call [Verify.recover](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#recover12) to recover the original data from the signature.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  async function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = "RSA1024|PKCS1|NoHash|OnlySign";
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let signData = await signer.sign(input1);
    return signData;
  }
  async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = "RSA1024|PKCS1|NoHash|Recover";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let rawSignData = await verifier.recover(signMessageBlob);
    return rawSignData;
  }
  async function main() {
    let keyGenAlg = "RSA1024";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let signData = await signMessagePromise(keyPair.priKey);
    let rawSignData = await verifyMessagePromise(signData, keyPair.pubKey);
    if (rawSignData !== null) {
      console.info('recover result: ' + rawSignData.data);
    } else {
      console.error("get verify recover result fail!");
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = "RSA1024|PKCS1|NoHash|OnlySign";
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let signData = signer.signSync(input1);
    return signData;
  }
  function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = "RSA1024|PKCS1|NoHash|Recover";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let rawSignData = verifier.recoverSync(signMessageBlob);
    return rawSignData;
  }
  function main() {
    let keyGenAlg = "RSA1024";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let signData = signMessagePromise(keyPair.priKey);
    let rawSignData = verifyMessagePromise(signData, keyPair.pubKey);
    if (rawSignData !== null) {
      console.info('recover result: ' + rawSignData.data);
    } else {
      console.error("get verify recover result fail!");
    }
  }
  ```

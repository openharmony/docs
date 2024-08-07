# Signing and Signature Verification with an SM2 Key Pair (ArkTS)


For details about the algorithm specifications, see [SM2](crypto-sign-sig-verify-overview.md#sm2).


**Signing**


1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 256-bit key pair (**KeyPair**) using SM2.
   
   In addition to the example in this topic, [SM2](crypto-asym-key-generation-conversion-spec.md#sm2) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an SM2 asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **'SM2_256|SM3'** to create a **Sign** instance. The key type is **SM2_256**, and the MD algorithm is **SM3**.

3. Use [Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

4. Use [Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3) to pass in the data to be signed.
   
   Currently, the amount of data to be passed in by a single **update()** is not limited. You can determine how to pass in data based on the data volume.
   
5. Use [Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-2) to generate a signature.


**Signature Verification**


1. Use [cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'SM2_256|SM3'** to create a **Verify** instance. The key type is **SM2_256**, and MD algorithm is **SM3**.

2. Use [Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance using the public key (**PubKey**).

3. Use [Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5) to pass in the data to be verified.
   
   Currently, the amount of data to be passed in by a single **update()** is not limited. You can determine how to pass in data based on the data volume.
   
4. Use [Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-2) to verify the data signature.


- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // The plaintext is split into input1 and input2.
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  async function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = "SM2_256|SM3";
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    await signer.update(input1); // If the plaintext is short, you can use sign() to pass in the full data at a time.
    let signData = await signer.sign(input2);
    return signData;
  }
  async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = "SM2_256|SM3";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    await verifier.update(input1); // If the plaintext is short, you can use verify() to pass in the full data at a time.
    let res = await verifier.verify(input2, signMessageBlob);
    console.info("verify result is " + res);
    return res;
  }
  async function main() {
    let keyGenAlg = "SM2_256";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let signData = await signMessagePromise(keyPair.priKey);
    let verifyResult = await verifyMessagePromise(signData, keyPair.pubKey);
    if (verifyResult == true) {
      console.info('verify success');
    } else {
      console.error('verify failed');
    }
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // The plaintext is split into input1 and input2.
  let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signAlg = "SM2_256|SM3";
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    signer.updateSync(input1); // If the plaintext is short, you can use sign() to pass in the full data at a time.
    let signData = signer.signSync(input2);
    return signData;
  }
  function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifyAlg = "SM2_256|SM3";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    verifier.updateSync(input1); // If the plaintext is short, you can use verify() to pass in the full data at a time.
    let res = verifier.verifySync(input2, signMessageBlob);
    console.info("verify result is " + res);
    return res;
  }
  async function main() {
    let keyGenAlg = "SM2_256";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let signData = signMessagePromise(keyPair.priKey);
    let verifyResult = verifyMessagePromise(signData, keyPair.pubKey);
    if (verifyResult == true) {
      console.info('verify success');
    } else {
      console.error('verify failed');
    }
  }
  ```

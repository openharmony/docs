# Signing and Signature Verification with an ECDSA Key Pair


For details about the algorithm specifications, see [ECDSA](crypto-sign-sig-verify-overview.md#ecdsa).


**Signing**


1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 256-bit key pair (KeyPair) using ECC.
   
   In addition to the example in this topic, [ECC](crypto-asym-key-generation-conversion-spec.md#ecc) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an ECC asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createSign](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **'ECC256|SHA256'** to create a **Sign** instance. The key type is **ECC256**, and the MD algorithm is **SHA256**.

3. Use [Sign.init](../../reference/apis/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

4. Use [Sign.update](../../reference/apis/js-apis-cryptoFramework.md#update-3) to pass in the data to be signed.
   Currently, the data to be passed in by a single **update()** is not size-bound. You can determine how to pass in data based on the data volume.

5. Use [Sign.sign](../../reference/apis/js-apis-cryptoFramework.md#sign-2) to generate a signature.


**Signature Verification**


1. Use [cryptoFramework.createVerify](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'ECC256|SHA256'** to create a **Verify** instance. The key type is **ECC256**, and MD algorithm is **SHA256**.

2. Use [Verify.init](../../reference/apis/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance using the public key (**PubKey**).

3. Use [Verify.update](../../reference/apis/js-apis-cryptoFramework.md#update-5) to pass in the data to be verified.
   Currently, the data to be passed in by a single **update()** is not size-bound. You can determine how to pass in data based on the data volume.

4. Use [Verify.verify](../../reference/apis/js-apis-cryptoFramework.md#verify-2) to verify the data signature.


```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import buffer from '@ohos.buffer';
// The plaintext is split into input1 and input2.
let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
async function signMessagePromise(priKey: cryptoFramework.PriKey) {
  let signAlg = "ECC256|SHA256";
  let signer = cryptoFramework.createSign(signAlg);
  await signer.init(priKey);
  await signer.update(input1); // If the plaintext is short, you can use sign() to pass in the full data at a time.
  let signData = await signer.sign(input2);
  return signData;
}
async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
  let verifyAlg = "ECC256|SHA256";
  let verifier = cryptoFramework.createVerify(verifyAlg);
  await verifier.init(pubKey);
  await verifier.update(input1); // If the plaintext is short, you can use verify() to pass in the full data at a time.
  let res = await verifier.verify(input2, signMessageBlob);
  console.info("verify result is " + res);
  return res;
}
async function main() {
  let keyGenAlg = "ECC256";
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

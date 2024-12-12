# Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode) (ArkTS)


For details about the algorithm specifications, see [RSA](crypto-sign-sig-verify-overview.md#rsa).


**Signing**


1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 1024-bit RSA key pair (**KeyPair**) with two primes. The **KeyPair** instance consists of a public key (**PubKey**) and a private key (**PriKey**).
   
   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **'RSA1024|PKCS1|SHA256'** to create a **Sign** instance. The key type is RSA1024, the padding mode is **PKCS1**, and the MD algorithm is **SHA256**.

3. Use [Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

4. Set the data length to be passed in each time to 64 bytes, and call [Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3) multiple times to pass in the data to be signed.<br>
   Currently, the amount of data to be passed in by a single **Sign.update()** is not limited. You can determine how to pass in data based on the data volume.

5. Use [Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1) to generate a signature.


**Signature Verification**


1. Use [cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'RSA1024|PKCS1|SHA256'** to create a **Verify** instance. The string parameter must be the same as that used to create the **Sign** instance.

2. Use [Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance using the public key (**PubKey**).

3. Use [Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5) to pass in the data to be verified.<br>
   Currently, the amount of data to be passed in by a single **Verify.update()** is not limited. You can determine how to pass in data based on the data volume.

4. Use [Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1) to verify the data signature.


- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function signMessageBySegment(priKey: cryptoFramework.PriKey, plainText: Uint8Array) {
    let signAlg = "RSA1024|PKCS1|SHA256";
    let signer = cryptoFramework.createSign(signAlg);
    await signer.init(priKey);
    let textSplitLen = 64; // Set the length of the data to be passed in each time. In this example, the value is 64.
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      await signer.update(updateMessageBlob);
    }
    // Pass in null here because all the plaintext has been passed in by segment.
    let signData = await signer.sign(null);
    return signData;
  }
  async function verifyMessagBySegment(pubKey: cryptoFramework.PubKey, plainText: Uint8Array, signMessageBlob: cryptoFramework.DataBlob) {
    let verifyAlg = "RSA1024|PKCS1|SHA256";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    await verifier.init(pubKey);
    let textSplitLen = 64; // Set the length of the data to be passed in each time. In this example, the value is 64.
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      await verifier.update(updateMessageBlob);
    }
    // Pass in null in the first parameter of verify() because all the plaintext has been passed in by segment.
    let res = await verifier.verify(null, signMessageBlob);
    console.info("verify result is " + res);
    return res;
  }
  async function rsaSignatureBySegment() {
    let message = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
    let keyGenAlg = "RSA1024";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = await generator.generateKeyPair();
    let messageData = new Uint8Array(buffer.from(message, 'utf-8').buffer);
    let signData = await signMessageBySegment(keyPair.priKey, messageData);
    let verifyResult = await verifyMessagBySegment(keyPair.pubKey, messageData, signData);
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

  function signMessageBySegment(priKey: cryptoFramework.PriKey, plainText: Uint8Array) {
    let signAlg = "RSA1024|PKCS1|SHA256";
    let signer = cryptoFramework.createSign(signAlg);
    signer.initSync(priKey);
    let textSplitLen = 64; // Set the length of the data to be passed in each time. In this example, the value is 64.
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      signer.updateSync(updateMessageBlob);
    }
    // Pass in null here because all the plaintext has been passed in by segment.
    let signData = signer.signSync(null);
    return signData;
  }
  function verifyMessagBySegment(pubKey: cryptoFramework.PubKey, plainText: Uint8Array, signMessageBlob: cryptoFramework.DataBlob) {
    let verifyAlg = "RSA1024|PKCS1|SHA256";
    let verifier = cryptoFramework.createVerify(verifyAlg);
    verifier.initSync(pubKey);
    let textSplitLen = 64; // Set the length of the data to be passed in each time. In this example, the value is 64.
    for (let i = 0; i < plainText.length; i += textSplitLen) {
      let updateMessage = plainText.subarray(i, i + textSplitLen);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      // Call update() multiple times to pass in data by segment.
      verifier.updateSync(updateMessageBlob);
    }
    // Pass in null in the first parameter of verify() because all the plaintext has been passed in by segment.
    let res = verifier.verifySync(null, signMessageBlob);
    console.info("verify result is " + res);
    return res;
  }
  function rsaSignatureBySegment() {
    let message = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
      "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
    let keyGenAlg = "RSA1024";
    let generator = cryptoFramework.createAsyKeyGenerator(keyGenAlg);
    let keyPair = generator.generateKeyPairSync();
    let messageData = new Uint8Array(buffer.from(message, 'utf-8').buffer);
    let signData = signMessageBySegment(keyPair.priKey, messageData);
    let verifyResult = verifyMessagBySegment(keyPair.pubKey, messageData, signData);
    if (verifyResult == true) {
      console.info('verify success');
    } else {
      console.error('verify failed');
    }
  }
  ```

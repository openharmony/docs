# Signing and Signature Verification with an RSA Key Pair (PSS Mode) (ArkTS)

For details about the algorithm specifications, see [RSA](crypto-sign-sig-verify-overview.md#rsa).

**Signing**

1. Call [cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) and [AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-3) to generate an RSA asymmetric key pair (**KeyPair**) based on the specified key parameters.
   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Generating an Asymmetric Key Pair Based on Key Parameters](crypto-generate-asym-key-pair-from-key-spec.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **'RSA|PSS|SHA256|MGF1_SHA256'** to create a **Sign** instance. As indicated by the string parameter, the key type is RSA without length, the padding mode is **PSS**, the MD algorithm is **SHA256**, and the mask algorithm is **MGF1_SHA256**.

3. Call [Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

4. Call [Sign.setSignSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setsignspec10) to set parameters for signing. In this example, the salt length (**SignSpecItem.PSS_SALT_LEN_NUM**) is set to 32 bytes. The data will be verified in signature verification.

5. Call [Sign.getSignSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getsignspec10) to obtain other parameters for signing.

6. Call [Sign.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-3) to pass in the data to be signed.<br>Currently, the amount of data to be passed in by a single **Sign.update()** is not limited. You can determine how to pass in data based on the data volume.

7. Call [Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1) to generate a signature.

**Signature Verification**

1. Call [cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'RSA2048|PSS|SHA256|MGF1_SHA256'** to create a **Verify** instance. As indicated by the string parameter, the asymmetric key type is **RSA2048**, the padding mode is **PSS**, the MD algorithm is **SHA256**, and mask algorithm is **MGF1_SHA256**.

2. Call [Verify.setVerifySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setverifyspec10) to set the parameters for signature verification. The parameter value must be the same as that set for signing.

3. Call [Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance using the public key (**PubKey**).

4. Call [Verify.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-5) to pass in the data to be verified.<br>Currently, the amount of data to be passed in by a single **Verify.update()** is not limited. You can determine how to pass in data based on the data volume.

5. Call [Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1) to verify the data signature.

- Example (using asynchronous APIs):

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  // Construct the RSA key pair parameter based on the key pair specifications.
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: "RSA",
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: "RSA",
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  // Generate the RSA2048 key pair parameter.
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
    let eIn = BigInt("0x010001");
    let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }

  async function verifyMessagePSS() {
    // The plaintext is split into input1 and input2.
    let plan1 = "This is Sign test plan1";
    let plan2 = "This is Sign test plan2";
    let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan1, 'utf-8').buffer) };
    let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan2, 'utf-8').buffer) };
    // Generate the RSA key pair parameter (Rsa2048KeyPairSpec) object.
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // Create an RSA key pair generator.
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    // Both sign() and verify() support the RSA key with or without the length.
    let signer = cryptoFramework.createSign("RSA|PSS|SHA256|MGF1_SHA256");
    let verifyer = cryptoFramework.createVerify("RSA2048|PSS|SHA256|MGF1_SHA256");
    let keyPair = await rsaGeneratorSpec.generateKeyPair();
    await signer.init(keyPair.priKey);
    // After the Sign instance is initialized, set and obtain the PSS parameters.
    let setN = 32;
    signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info("SaltLen == " + saltLen);
    let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info("trailer field == " + tf);
    let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info("md == " + md);
    let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    await signer.update(input1);
    let signMessageBlob = await signer.sign(input2);
    // Before the Verify instance is initialized, set and get PSS parameters.
    verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info("SaltLen == " + saltLen);
    tf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info("trailer field == " + tf);
    md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info("md == " + md);
    mgf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    mgf1Md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    await verifyer.init(keyPair.pubKey);
    await verifyer.update(input1);
    let verifyResult = await verifyer.verify(input2, signMessageBlob);
    if (verifyResult === true) {
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
  // Construct the RSA key pair parameter based on the key pair specifications.
  function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: "RSA",
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
      params: rsaCommSpec,
      sk: dIn,
      pk: eIn,
      algName: "RSA",
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
    };
    return rsaKeyPairSpec;
  }
  // Generate the RSA2048 key pair parameter.
  function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
    let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
    let eIn = BigInt("0x010001");
    let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
    return genRsaKeyPairSpec(nIn, eIn, dIn);
  }

  function verifyMessagePSS() {
    // The plaintext is split into input1 and input2.
    let plan1 = "This is Sign test plan1";
    let plan2 = "This is Sign test plan2";
    let input1: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan1, 'utf-8').buffer) };
    let input2: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan2, 'utf-8').buffer) };
    // Generate the RSA key pair parameter (Rsa2048KeyPairSpec) object.
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // Create an RSA key pair generator.
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    // Both sign() and verify() support the RSA key with or without the length.
    let signer = cryptoFramework.createSign("RSA|PSS|SHA256|MGF1_SHA256");
    let verifyer = cryptoFramework.createVerify("RSA2048|PSS|SHA256|MGF1_SHA256");
    let keyPair = rsaGeneratorSpec.generateKeyPairSync();
    signer.initSync(keyPair.priKey);
    // After the Sign instance is initialized, set and obtain the PSS parameters.
    let setN = 32;
    signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info("SaltLen == " + saltLen);
    let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info("trailer field == " + tf);
    let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info("md == " + md);
    let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    signer.updateSync(input1);
    let signMessageBlob = signer.signSync(input2);
    // Before the Verify instance is initialized, set and get PSS parameters.
    verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
    saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
    console.info("SaltLen == " + saltLen);
    tf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
    console.info("trailer field == " + tf);
    md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
    console.info("md == " + md);
    mgf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    mgf1Md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
    verifyer.initSync(keyPair.pubKey);
    verifyer.updateSync(input1);
    let verifyResult = verifyer.verifySync(input2, signMessageBlob);
    if (verifyResult === true) {
      console.info('verify success');
    } else {
      console.error('verify failed');
    }
  }
  ```

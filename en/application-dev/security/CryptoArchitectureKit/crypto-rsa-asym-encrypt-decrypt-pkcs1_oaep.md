# Encryption and Decryption with an RSA Asymmetric Key Pair (PKCS1_OAEP)


For details about the algorithm specifications, see [RSA](crypto-asym-encrypt-decrypt-spec.md#rsa).


**Encryption**


1. Use [cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) and [AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-3) to generate an RSA asymmetric key pair (**KeyPair**) based on the specified key parameters.
   
   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Generating an Asymmetric Key Pair Based on Key Parameters](crypto-generate-asym-key-pair-from-key-spec.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1'** to create a **Cipher** instance. The key type is **RSA2048**, padding mode is **PKCS1_OAEP**, MD algorithm is **SHA256**, and mask digest algorithm is **MGF1_SHA1**.

3. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption) and **key** to **KeyPair.PubKey** (the key used for encryption).
   
   No encryption parameter is required for asymmetric key pairs. Therefore, pass in **null** in **params**.

4. Use [Cipher.setCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setcipherspec10) to set the parameter **pSource** for **PKCS1_OAEP** before **Cipher.doFinal** is called. You can use [Cipher.getCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getcipherspec10) to obtain OAEP-related parameters.

5. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to pass in the plaintext and encrypt it.


**Decryption**


1. If RSA is used, the **Cipher** instance cannot be initialized repeatedly. Use [cryptoFramework.createCipher](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) to create a new **Cipher** instance.

2. Use [Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In **Cipher.init**, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption) and **key** to **KeyPair.PriKey** (the key used for decryption). When PKCS1 mode is used, pass in **null** in **params**.

3. Use [Cipher.setCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setcipherspec10) to set the parameter **pSource** for **PKCS1_OAEP** before **Cipher.doFinal** is called. The value of **pSource** must be the same as that set in encryption. You can use [Cipher.getCipherSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getcipherspec10) to obtain OAEP-related parameters.

4. Use [Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1) to pass in the ciphertext and decrypt it.


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
  async function rsaUseSpecDecryptOAEPPromise() {
    let plan = "This is a test";
    // Generate the RSA key pair parameter (Rsa2048KeyPairSpec) object.
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // Generate an RSA key pair based on the RSA key pair parameter.
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    let cipher = cryptoFramework.createCipher("RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1");
    let decoder = cryptoFramework.createCipher("RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1");
    // Set pSource, which defines the encoding input P filled by OAEP.
    let pSource = new Uint8Array([1, 2, 3, 4]);
    let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan, 'utf-8').buffer) };
    // Generate a key pair.
    let keyPair = await rsaGeneratorSpec.generateKeyPair();
    // Initialize the encryption operation.
    await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
    // Set and obtain the Cipher specifications after the initialization.
    cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // Check whether the obtained PSource is the same as the PSource set.
    if (retP.toString() != pSource.toString()) {
      console.error("error init pSource" + retP);
    } else {
      console.info("pSource changed ==" + retP);
    }
    // Obtain other OAEP parameters.
    let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info("md == " + md);
    let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    let cipherDataBlob = await cipher.doFinal(input);
    // The get() and set() operations can be performed before the init() operation of the Cipher object and are equivalent to those after the init() operation. For example, set and get the decoder.
    decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // Check whether the obtained PSource is the same as the PSource set.
    if (retP.toString() != pSource.toString()) {
      console.error("error init pSource" + retP);
    } else {
      console.info("pSource changed ==" + retP);
    }
    // Obtain other OAEP parameters.
    md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info("md == " + md);
    mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    // Initialize the decryption operation.
    await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    let decodeData = await decoder.doFinal(cipherDataBlob);
    // The decryption is successful.
    if (decodeData.data.toString() === input.data.toString()) {
      console.info("oaep decrypt success");
    } else {
      console.error("oaep decrypt fail");
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
  function main() {
    let plan = "This is a test";
    // Generate the RSA key pair parameter (Rsa2048KeyPairSpec) object.
    let rsaKeyPairSpec = genRsa2048KeyPairSpec();
    // Generate an RSA key pair based on the RSA key pair parameter.
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
    let cipher = cryptoFramework.createCipher("RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1");
    let decoder = cryptoFramework.createCipher("RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1");
    // Set pSource, which defines the encoding input P filled by OAEP.
    let pSource = new Uint8Array([1, 2, 3, 4]);
    let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(plan, 'utf-8').buffer) };
    // Generate a key pair.
    let keyPair = rsaGeneratorSpec.generateKeyPairSync();
    // Initialize the encryption operation.
    cipher.initSync(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
    // Set and obtain the Cipher specifications after the initialization.
    cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // Check whether the obtained PSource is the same as the PSource set.
    if (retP.toString() != pSource.toString()) {
      console.error("error init pSource" + retP);
    } else {
      console.info("pSource changed ==" + retP);
    }
    // Obtain other OAEP parameters.
    let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info("md == " + md);
    let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    let cipherDataBlob = cipher.doFinalSync(input);
    // The get() and set() operations can be performed before the init() operation of the Cipher object and are equivalent to those after the init() operation. For example, set and get the decoder.
    decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
    retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
    // Check whether the obtained PSource is the same as the PSource set.
    if (retP.toString() != pSource.toString()) {
      console.error("error init pSource" + retP);
    } else {
      console.info("pSource changed ==" + retP);
    }
    // Obtain other OAEP parameters.
    md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
    console.info("md == " + md);
    mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
    console.info("mgf == " + mgf);
    mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
    console.info("mgf1Md == " + mgf1Md);
    // Initialize the decryption operation.
    decoder.initSync(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    let decodeData = decoder.doFinalSync(cipherDataBlob);
    // The decryption is successful.
    if (decodeData.data.toString() === input.data.toString()) {
      console.info("oaep decrypt success");
    } else {
      console.error("oaep decrypt fail");
    }
  }
  ```

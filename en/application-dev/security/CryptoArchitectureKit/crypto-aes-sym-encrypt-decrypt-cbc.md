# Encryption and Decryption with an AES Symmetric Key (CBC Mode)


For details about the algorithm specifications, see [AES](crypto-sym-encrypt-decrypt-spec.md#aes).


**Encryption**


1. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.generateSymKey](../../reference/apis/js-apis-cryptoFramework.md#generatesymkey-1) to generate a 128-bit AES symmetric key (**SymKey**).
   
   In addition to the example in this topic, [AES](crypto-sym-key-generation-conversion-spec.md#aes) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly.md) may help you better understand how to generate an AES symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [cryptoFramework.createCipher](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatecipher) with the string parameter **'AES128|CBC|PKCS7'** to create a **Cipher** instance. The key type is **AES128**, block cipher mode is **CBC**, and the padding mode is **PKCS7**.

3. Use [Cipher.init](../../reference/apis/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.ENCRYPT_MODE** (encryption), **key** to **SymKey** (the key for encryption), and **params** to **IvParamsSpec** corresponding to the CBC mode.

4. If the data to be encrypted is short, you can use [Cipher.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-1) after **Cipher.init** to obtain the encrypted data.


**Decryption**


1. Use [Cipher.init](../../reference/apis/js-apis-cryptoFramework.md#init-1) to initialize the **Cipher** instance. In the **Cipher.init** API, set **opMode** to **CryptoMode.DECRYPT_MODE** (decryption), **key** to **SymKey** (the key for decryption), and **params** to **IvParamsSpec** corresponding to the CBC mode.

2. If the data to be decrypted is short, you can use [Cipher.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-1) after **Cipher.init** to obtain the decrypted data.


```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import buffer from '@ohos.buffer';

function genIvParamsSpec() {
  let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob: cryptoFramework.DataBlob = { data: dataIv };
  let ivParamsSpec: cryptoFramework.IvParamsSpec = {
    algName: "IvParamsSpec",
    iv: ivBlob
  };
  return ivParamsSpec;
}
// Encrypt the message.
async function encryptMessagePromise(symKey: cryptoFramework.SymKey, plainText: cryptoFramework.DataBlob) {
  let cipher = cryptoFramework.createCipher('AES128|CBC|PKCS7');
  let iv = genIvParamsSpec();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, iv);
  let cipherData = await cipher.doFinal(plainText);
  return cipherData;
}
// Decrypt the message.
async function decryptMessagePromise(symKey: cryptoFramework.SymKey, cipherText: cryptoFramework.DataBlob) {
  let decoder = cryptoFramework.createCipher('AES128|CBC|PKCS7');
  let iv = genIvParamsSpec();
  await decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, symKey, iv);
  let decryptData = await decoder.doFinal(cipherText);
  return decryptData;
}

async function genSymKeyByData(symKeyData: Uint8Array) {
  let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
  let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await aesGenerator.convertKey(symKeyBlob);
  console.info('convertKey success');
  return symKey;
}

async function aesCBC() {
  let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
  let symKey = await genSymKeyByData(keyData);
  let message = "This is a test";
  let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
  let encryptText = await encryptMessagePromise(symKey, plainText);
  let decryptText = await decryptMessagePromise(symKey, encryptText);
  if (plainText.data.toString() === decryptText.data.toString()) {
    console.info('decrypt ok');
    console.info('decrypt plainText: ' + buffer.from(decryptText.data).toString('utf-8'));
  } else {
    console.error('decrypt failed');
  }
  console.info('main step success');
}
```

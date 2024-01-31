# MAC Operation


A message authentication code (MAC) is used to check the authenticity and integrity of a message transmitted between two parties that share a secret key.


A Hash-based Message Authentication Code (HMAC) is a type of MAC involving a hash function and a secret key.


The specified message digest (MD) algorithm is used to generate a MAC based on the shared secret key and the message to be exchanged. The MAC is used to check the integrity of message. HMAC introduces the shared secret key, which ensures data authenticity. The generated MAC has a fixed length.


## Supported Algorithms and Specifications

The **Supported Type** column in the following table lists the algorithm to be used when a **Mac** instance is created.

| MD Algorithm| Supported Type| API Version| 
| -------- | -------- | -------- |
| HASH | SHA1 | 9+ | 
| HASH | SHA224 | 9+ | 
| HASH | SHA256 | 9+ | 
| HASH | SHA384 | 9+ | 
| HASH | SHA512 | 9+ | 
| HASH | SM3 | 10+ | 


## How to Develop

During the HMAC operation, you can use **update()** to pass in all the data at a time or pass in data by segment. The same data will produce the same result no matter how the data is passed. Use the appropriate method based on the data size.

The following provides examples of HMAC operations with different data passing methods.


### HMAC (Passing In Full Data)

1. Use [cryptoFramework.createMac](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatemac) with the MD algorithm SHA256 to create a **Mac** instance.

2. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.convertKey](../../reference/apis/js-apis-cryptoFramework.md#convertkey-1) to generate a 128-bit AES symmetric key (**SymKey**).
   For details, see [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key.md).

3. Use [Mac.init](../../reference/apis/js-apis-cryptoFramework.md#init-6) to initialize the **Mac** instance using the shared symmetric key (**SymKey**).

4. Use [Mac.update](../../reference/apis/js-apis-cryptoFramework.md#update-8) to pass in the full data. The data to be passed in by a single **update()** operation is not size-bound.

5. Use [Mac.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-2) to generate a MAC.

6. Use [Mac.getMacLength](../../reference/apis/js-apis-cryptoFramework.md#getmaclength) to obtain the length of the MAC, in bytes.

Example: Pass in the full data to calculate a MAC using **await**.

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import buffer from '@ohos.buffer';

async function genSymKeyByData(symKeyData: Uint8Array) {
  let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
  let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await aesGenerator.convertKey(symKeyBlob);
  console.info('convertKey success');
  return symKey;
}
async function doHmac() {
  // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
  let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
  let key = await genSymKeyByData(keyData);
  let macAlgName = 'SHA256'; // MD algorithm.
  let message = 'hmacTestMessgae'; // Message to be HMACed.
  let mac = cryptoFramework.createMac(macAlgName);
  await mac.init(key);
  // If the data to be processed is short, use update() to pass in the full data at a time. The data to be passed in by a single **update()** operation is not size-bound.
  await mac.update({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
  let macResult = await mac.doFinal();
  console.info('HMAC result:' + macResult.data);
}
```


### HMAC (Passing In Data by Segment)

1. Use [cryptoFramework.createMac](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatemac) with the MD algorithm SHA256 to create a **Mac** instance.

2. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.convertKey](../../reference/apis/js-apis-cryptoFramework.md#convertkey-1) to generate a 128-bit AES symmetric key (**SymKey**).
   For details, see [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key.md).

3. Use [Mac.init](../../reference/apis/js-apis-cryptoFramework.md#init-7) to initialize the **Mac** instance using the shared symmetric key (**SymKey**).

4. Call [Mac.update](../../reference/apis/js-apis-cryptoFramework.md#update-9) multiple times to pass in 20 bytes each time.

5. Use [Mac.doFinal](../../reference/apis/js-apis-cryptoFramework.md#dofinal-3) to generate a MAC.

6. Use [Mac.getMacLength](../../reference/apis/js-apis-cryptoFramework.md#getmaclength) to obtain the length of the MAC, in bytes.

Example: Pass in data by segment to calculate a MAC using **await**.

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import buffer from '@ohos.buffer';

async function genSymKeyByData(symKeyData: Uint8Array) {
  let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
  let aesGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await aesGenerator.convertKey(symKeyBlob);
  console.info('convertKey success');
  return symKey;
}
async function doLoopHmac() {
  // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
  let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
  let key = await genSymKeyByData(keyData);
  let macAlgName = "SHA256"; // MD algorithm.
  let mac = cryptoFramework.createMac(macAlgName);
  // Assume that the message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";
  let messageData = new Uint8Array(buffer.from(messageText, 'utf-8').buffer);
  let updateLength = 20; // In this example, pass in 20 bytes each time.
  await mac.init(key);
  for (let i = 0; i < messageData.length; i += updateLength) {
    let updateMessage = messageData.subarray(i, i + updateLength);
    let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
    await mac.update(updateMessageBlob);
  }
  let macOutput = await mac.doFinal();
  console.info("HMAC result: " + macOutput.data);
}
```

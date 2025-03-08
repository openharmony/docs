# Generating an HMAC


A message authentication code (MAC) is used to check the authenticity and integrity of a message transmitted between two parties that share a secret key. A Hash-based Message Authentication Code (HMAC) is a type of MAC involving a hash function and a secret key. The generated MAC has a fixed length.



## How to Develop

During the HMAC operation, you can [pass in all the data at a time](#generating-an-hmac-by-passing-in-full-data) or [pass in data by segment](#generating-an-hmac-by-passing-in-data-by-segment). The same data will produce the same result no matter how the data is passed. Use the appropriate method based on the data size.

The following provides examples of HMAC operations with different data passing methods.


### Generating an HMAC by Passing In Full Data

1. Call [cryptoFramework.createMac](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemac) with the MD algorithm **SHA256** to create a **Mac** instance.

2. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1) to generate a symmetric key (**SymKey**) using HMAC.
   For details, see [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key.md).

3. Call [Mac.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-6) to initialize the **Mac** instance using the shared symmetric key (**SymKey**).

4. Call [Mac.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-8) to pass in the full data. The amount of data to be passed in by a single **Mac.update()** call is not limited.

5. Call [Mac.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-2) to generate a MAC.

6. Call [Mac.getMacLength](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getmaclength) to obtain the length of the MAC, in bytes.

- Example: Pass in the full data to generate a MAC using **await**.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function doHmac() {
    // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
    let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
    let key = await genSymKeyByData(keyData);
    let macAlgName = 'SHA256'; // MD algorithm.
    let message = 'hmacTestMessage'; // Message to be HMACed.
    let mac = cryptoFramework.createMac(macAlgName);
    await mac.init(key);
    // If there is a small amount of data to be processed, call update() to pass in all the data at a time. The data to be passed in by a single update() call is not limited.
    await mac.update({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
    let macResult = await mac.doFinal();
    console.info('HMAC result:' + macResult.data);
    let macLen = mac.getMacLength();
    console.info('HMAC len:' + macLen);
  }
  ```

- Example: Pass in the full data to generate a MAC using synchronous APIs.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let symKey =  aesGenerator.convertKeySync(symKeyBlob);
    console.info('[Sync]convertKey success');
    return symKey;
  }
  function doHmacBySync() {
    // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
    let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
    let key = genSymKeyByData(keyData);
    let macAlgName = 'SHA256'; // MD algorithm.
    let message = 'hmacTestMessage'; // Message to be HMACed.
    let mac = cryptoFramework.createMac(macAlgName);
    mac.initSync(key);
    // If there is a small amount of data to be processed, call update() to pass in all the data at a time. The data to be passed in by a single update() call is not limited.
    mac.updateSync({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
    let macResult = mac.doFinalSync();
    console.info('[Sync]HMAC result:' + macResult.data);
    let macLen = mac.getMacLength();
    console.info('HMAC len:' + macLen);
  }
  ```

### Generating an HMAC by Passing In Data by Segment

1. Call [cryptoFramework.createMac](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemac) with the MD algorithm **SHA256** to create a **Mac** instance.

2. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1) to generate a symmetric key (**SymKey**) using HMAC.
   For details, see [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key.md).

3. Call [Mac.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-7) to initialize the **Mac** instance using the shared symmetric key (**SymKey**).

4. Call [Mac.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-9) multiple times to pass in 20 bytes each time.

5. Call [Mac.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-3) to generate a MAC.

6. Call [Mac.getMacLength](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getmaclength) to obtain the length of the MAC, in bytes.

- Example: Pass in data by segment to generate a MAC using **await**.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
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
    // In this example, the message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";
    let messageData = new Uint8Array(buffer.from(messageText, 'utf-8').buffer);
    let updateLength = 20; // Set the data length to be passed in each time to 20 bytes. You can set this parameter as required.
    await mac.init(key);
    for (let i = 0; i < messageData.length; i += updateLength) {
      let updateMessage = messageData.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      await mac.update(updateMessageBlob);
    }
    let macOutput = await mac.doFinal();
    console.info("HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.info('HMAC len:' + macLen);
  }
  ```

- Example: Pass in data by segment to generate a MAC using synchronous APIs.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let symKey = aesGenerator.convertKeySync(symKeyBlob);
    console.info('[Sync]convertKey success');
    return symKey;
  }
  function doLoopHmacBySync() {
    // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
    let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
    let key = genSymKeyByData(keyData);
    let macAlgName = "SHA256"; // MD algorithm.
    let mac = cryptoFramework.createMac(macAlgName);
    // In this example, the message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";
    let messageData = new Uint8Array(buffer.from(messageText, 'utf-8').buffer);
    let updateLength = 20; // Set the data length to be passed in each time to 20 bytes. You can set this parameter as required.
    mac.initSync(key);
    for (let i = 0; i < messageData.length; i += updateLength) {
      let updateMessage = messageData.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      mac.updateSync(updateMessageBlob);
    }
    let macOutput = mac.doFinalSync();
    console.info("[Sync]HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.info('HMAC len:' + macLen);
  }
  ```


### Generating an HMAC by Passing In HmacSpec as a Parameter
1. Call [cryptoFramework.createMac](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemac) with the MAC algorithm set to **HMAC** and MD algorithm set to **SHA256** to create a **MAc** instance.

2. Call [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) and [SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1) to generate a symmetric key (**SymKey**) using HMAC.
   For details, see [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key.md).

3. Call [Mac.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-6) to initialize the **Mac** instance using the shared symmetric key (**SymKey**).

4. Call [Mac.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-8) to pass in the data. The amount of data to be passed in by a single **Mac.update()** call is not limited.

5. Call [Mac.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-2) to generate a MAC.

6. Call [Mac.getMacLength](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getmaclength) to obtain the length of the MAC, in bytes.

- Example: Pass in the full data to generate a MAC using **await**.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function genSymKeyByData(symKeyData: Uint8Array) {
    let symKeyBlob: cryptoFramework.DataBlob = { data: symKeyData };
    let aesGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let symKey = await aesGenerator.convertKey(symKeyBlob);
    console.info('convertKey success');
    return symKey;
  }
  async function doHmac() {
    // Convert the string into a Uint8Array in UTF-8 format and use it as the private key, which is 128 bits (16 bytes).
    let keyData = new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer);
    let key = await genSymKeyByData(keyData);
    let spec: cryptoFramework.HmacSpec = {
        algName: "HMAC",
        mdName: "SHA256",
    };
    let message = 'hmacTestMessage'; // Message to be HMACed.
    let mac = cryptoFramework.createMac(spec);
    await mac.init(key);
    // If there is a small amount of data to be processed, call update() to pass in all the data at a time. The data to be passed in by a single update() call is not limited.
    await mac.update({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
    let macResult = await mac.doFinal();
    console.info('HMAC result:' + macResult.data);
    let macLen = mac.getMacLength();
    console.info('HMAC len:' + macLen);
  }
  ```

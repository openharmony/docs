# MD Operations (ArkTS)

For details about the algorithm specifications, see [Supported Algorithms and Specifications](crypto-generate-message-digest-overview.md#supported-algorithms-and-specifications).

> **NOTE**
> 
> From API version 12, wearable devices support MD operations.

## How to Develop

During the MD operation, you can use **update()** to pass in all the data at a time or pass in data by segment. For the same piece of data, the result will be the same no matter how the data is passed. Use the appropriate method based on the data size.

The following provides examples of MD operations with different data passing methods.


### MD (Passing In Full Data)

1. Use [cryptoFramework.createMd](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemd) with the MD algorithm **SHA256** to create a message digest (**Md**) instance.

2. Use [Md.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-6) to pass in the full data. The amount of data to be passed in by a single **update()** operation is not limited.

3. Use [Md.digest](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#digest) to generate an MD.

4. Use [Md.getMdLength](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getmdlength) to obtain the MD length, in bytes.

- Example: Pass in the full data to calculate an MD using **await**.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function doMd() {
    let mdAlgName = "SHA256"; // Algorithm to use.
    let message = "mdTestMessgae"; // Message to be digested.
    let md = cryptoFramework.createMd(mdAlgName);
    // If the data to be processed is short, use update() to pass in the full data at a time. The amount of data to be passed in by a single **update()** operation is not limited.
    await md.update({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
    let mdResult = await md.digest();
    console.info('Md result:' + mdResult.data);
    let mdLen = md.getMdLength();
    console.info("md len: " + mdLen);
  }
  ```

- Example: Pass in the full data to calculate an MD using a synchronous API.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function doMdBySync() {
    let mdAlgName = "SHA256"; // Algorithm to use.
    let message = "mdTestMessgae"; // Message to be digested.
    let md = cryptoFramework.createMd(mdAlgName);
    // If the data to be processed is short, use update() to pass in the full data at a time. The amount of data to be passed in by a single **update()** operation is not limited.
    md.updateSync({ data: new Uint8Array(buffer.from(message, 'utf-8').buffer) });
    let mdResult = md.digestSync();
    console.info('[Sync]:Md result:' + mdResult.data);
    let mdLen = md.getMdLength();
    console.info("md len: " + mdLen);
  }
  ```

### MD (Passing In Data by Segment)

1. Use [cryptoFramework.createMd](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatemd) with the MD algorithm **SHA256** to create a message digest (**Md**) instance.

2. Call [Md.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-7) multiple times to pass in 20 bytes each time.

3. Use [Md.digest](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#digest-1) to generate an MD.

4. Use [Md.getMdLength](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getmdlength) to obtain the MD length, in bytes.

- Example: Pass in data by segment to calculate an MD using **await**.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function doLoopMd() {
    let mdAlgName = "SHA256"; // Algorithm to use.
    let md = cryptoFramework.createMd(mdAlgName);
    // In this example, the message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";
    let messageData = new Uint8Array(buffer.from(messageText, 'utf-8').buffer);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    for (let i = 0; i < messageData.length; i += updateLength) {
      let updateMessage = messageData.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      await md.update(updateMessageBlob);
    }
    let mdOutput = await md.digest();
    console.info("md result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("md len: " + mdLen);
  }
  ```

- Example: Pass in data by segment to calculate an MD using a synchronous API.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function doLoopMdBySync() {
    let mdAlgName = "SHA256"; // Algorithm to use.
    let md = cryptoFramework.createMd(mdAlgName);
    // In this example, the message is of 43 bytes. After decoded in UTF-8 format, the message is also of 43 bytes.
    let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";
    let messageData = new Uint8Array(buffer.from(messageText, 'utf-8').buffer);
    let updateLength = 20; // Pass in 20 bytes each time. You can set this parameter as required.
    for (let i = 0; i < messageData.length; i += updateLength) {
      let updateMessage = messageData.subarray(i, i + updateLength);
      let updateMessageBlob: cryptoFramework.DataBlob = { data: updateMessage };
      md.updateSync(updateMessageBlob);
    }
    let mdOutput = md.digestSync();
    console.info("[Sync]:md result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("md len: " + mdLen);
  }
  ```

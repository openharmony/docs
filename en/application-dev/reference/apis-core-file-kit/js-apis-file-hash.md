# @ohos.file.hash (File Hash Processing)

The **FileHash** module implements hash processing on files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { hash } from '@kit.CoreFileKit';
```

## Guidelines

Before using the APIs provided by this module to perform operations on a file or directory, obtain the application sandbox path of the file or directory as follows:

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

## hash.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

Calculates a hash value for a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------|
| path      | string | Yes  | Path of the file in the application sandbox.|
| algorithm | string | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|

**Return value**

  | Type                   | Description                        |
  | --------------------- | -------------------------- |
  | Promise&lt;string&gt; | Promise used to return the hash value. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  hash.hash(filePath, "sha256").then((str: string) => {
    console.info("calculate file hash succeed:" + str);
  }).catch((err: BusinessError) => {
    console.error("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## hash.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

Calculates a hash value for a file. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                       | Mandatory| Description                                                        |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | Yes  | Path of the file in the application sandbox.                            |
| algorithm | string                      | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|
| callback  | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the hash value obtained. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + "/test.txt";
  hash.hash(filePath, "sha256", (err: BusinessError, str: string) => {
    if (err) {
      console.error("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("calculate file hash succeed:" + str);
    }
  });
  ```
## hash.createHash<sup>12+</sup>

createHash(algorithm: string): HashStream;

Creates a **HashStream** instance, which can be used to generate a message digest (a hash value) using the given algorithm.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| algorithm | string | Yes | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|

**Return value**

  | Type           | Description        |
  | ------------- | ---------- |
  | [HashStream](#hashstream12) | **HashStream** instance created.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  // pages/xxx.ets
  import { fileIo as fs } from '@kit.CoreFileKit';

  function hashFileWithStream() {
    const filePath = pathDir + "/test.txt";
    // Create a readable stream.
    const rs = fs.createReadStream(filePath);
    // Create a hash stream.
    const hs = hash.createHash('sha256');
    rs.on('data', (emitData) => {
      const data = emitData?.data;
      hs.update(new Uint8Array(data?.split('').map((x: string) => x.charCodeAt(0))).buffer);
    });
    rs.on('close', async () => {
      const hashResult = hs.digest();
      const fileHash = await hash.hash(filePath, 'sha256');
      console.info(`hashResult: ${hashResult}, fileHash: ${fileHash}`);
    });
  }
  ```


## HashStream<sup>12+</sup>

The **HashStream** class is a utility for creating a message digest of data. You can use [createHash](#hashcreatehash12) to create a **HashStream** instance.

### update<sup>12+</sup>

update(data: ArrayBuffer): void

Updates the data for generating a message digest. This API can be called multiple times.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  // Create a hash stream.
  const hs = hash.createHash('sha256');
  hs.update(new Uint8Array('1234567890'?.split('').map((x: string) => x.charCodeAt(0))).buffer);
  hs.update(new Uint8Array('abcdefg'?.split('').map((x: string) => x.charCodeAt(0))).buffer);
  const hashResult = hs.digest();
  // 88A00F46836CD629D0B79DE98532AFDE3AEAD79A5C53E4848102F433046D0106
  console.info(`hashResult: ${hashResult}`);
  ```

### digest<sup>12+</sup>

digest(): string

Generates a message digest.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  // Create a hash stream.
  const hs = hash.createHash('sha256');
  hs.update(new Uint8Array('1234567890'?.split('').map((x: string) => x.charCodeAt(0))).buffer);
  hs.update(new Uint8Array('abcdefg'?.split('').map((x: string) => x.charCodeAt(0))).buffer);
  const hashResult = hs.digest();
  // 88A00F46836CD629D0B79DE98532AFDE3AEAD79A5C53E4848102F433046D0106
  console.info(`hashResult: ${hashResult}`);
  ```

# @ohos.util.stream (Stream Base Class)

The stream module provides APIs to process basic types of streams. With streams, data is read or written by chunk, instead of being loaded to the memory at a time.

There are four fundamental stream types: writable streams ([Writable](#writable)), readable streams ([Readable](#readable)), duplex streams ([Duplex](#duplex)), and transform streams ([Transform](#transform)).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { stream  } from '@kit.ArkTS';
```

## Writable

Stream to which data can be written. A writable stream allows data to be written to a target, which can be a file, an HTTP response, a standard output, another stream, or the like.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type     | Read-Only| Optional | Description       |
| ------- | -------- | ------ | ------ | ----------- |
| writableObjectMode  | boolean   | Yes  | No| Whether the writable stream works in object mode. The value **true** means that the stream is configured in object mode, and **false** means the opposite. Currently, only raw data (string and Uint8Array) is supported, and the return value is **false**.|
| writableHighWatermark | number | Yes| No | High watermark for the data volume in the writable stream buffer. This value is not customizable currently. When you call [write()](#write), if the data volume in the buffer reaches this watermark, [write()](#write) will return **false**. The default value is 16 * 1024, in bytes.|
| writable | boolean | Yes| No | Whether the writable stream is currently writable. The value **true** means that the stream is currently writable, and **false** means that the stream does not accept write operations.|
| writableLength | number | Yes| No | Number of bytes to be written in the buffer of the writable stream.|
| writableCorked | number | Yes | No| Count of cork states of the writable stream. If the value is greater than 0, the writable stream buffers all writes. If the value is **0**, buffering stops. You can call [cork()](#cork) to increment the count by one, call [uncork()](#uncork) to decrement the count by one, and call [end()](#end) to clear the count.|
| writableEnded | boolean | Yes | No| Whether [end()](#end) has been called for the writable stream. This property does not specify whether the data has been flushed. The value **true** means that [end()](#end) has been called, and **false** means the opposite.|
| writableFinished | boolean | Yes | No| Whether data in the writable stream has been flushed. The value **true** means that data in the stream has been flushed, and **false** means the opposite.|

### constructor

constructor()

A constructor used to create a **Writable** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let writableStream = new stream.Writable();
```

### write

write(chunk?: string | Uint8Array, encoding?: string, callback?: Function): boolean

Writes data to the buffer of the stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | No| Data to write. It cannot be **null**, **undefined**, or an empty string.|
| encoding  | string | No  | Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | No  | Callback used to return the result. It is not called by default.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| boolean | Whether there is space in the buffer of the writable stream. The value **true** means that there is still space in the buffer. The value **false** means that the buffer is full, and you are not advised to continue writing data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200035 | The doWrite method has not been implemented. |
| 10200036 | The stream has been ended. |
| 10200037 | The callback is invoked multiple times consecutively. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("Writable chunk is", chunk); // Writable chunk is test
    callback();
  }
}

let writableStream = new TestWritable();
writableStream.write('test', 'utf8');
```

### end

end(chunk?: string | Uint8Array, encoding?: string, callback?: Function): Writable

Ends the writing process in a writable stream. This API uses an asynchronous callback to return the result.

If the value of **writableCorked** is greater than 0, the value is set to **0** and the remaining data in the buffer is output.

If the **chunk** parameter is passed, it is treated as the final data chunk and written using either the **write** or **doWrite** API, based on the current execution context.

If **doWrite** is used for writing, the validity check of the **encoding** parameter depends on **doWrite**.

If **end** is used alone (without **write**) and the **chunk** parameter is passed, the data is written through **doWrite**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | No| Data to write. The default value is **undefined**.|
| encoding  | string | No  | Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | No  | Callback used to return the result.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| [Writable](#writable) | Current **Writable** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200035 | The doWrite method has not been implemented. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("Writable chunk is", chunk);
    callback();
  }
/**
 * Writable chunk is test
 * Writable chunk is finish
 * */
}

let writableStream = new TestWritable();
writableStream.write('test', 'utf8');
writableStream.end('finish', 'utf8', () => {
  console.info("Writable is end"); // Writable is end
});
```

### setDefaultEncoding

setDefaultEncoding(encoding?: string): boolean

Sets the default encoding format for the writable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | No| Default encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the setting is successful; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let writableStream = new TestWritable();
let result = writableStream.setDefaultEncoding('utf8');
console.info("Writable is result", result); // Writable is result true
```

### cork

cork(): boolean

Forces subsequent writes to be buffered. This API is called to optimize the performance of continuous write operations.

After this API is called, the value of **writableCorked** is incremented by one. It is recommended that this API be used in pair with [uncork()](#uncork).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the corked status is successfully set; otherwise, **false** is returned.|

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let writableStream = new TestWritable();
let result = writableStream.cork();
console.info("Writable cork result", result); // Writable cork result true
```

### uncork

uncork(): boolean

Releases the cork state, flushing the buffered data and writing it to the target location.

After this API is called, the value of **writableCorked** is decremented by one. If the value reaches **0**, the stream is no longer in the cork state. Otherwise, the stream is still in the cork state. It is recommended that this API be used in pair with [cork()](#cork).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the corked status is removed; otherwise, **false** is returned.|

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let writableStream = new TestWritable();
writableStream.cork();
writableStream.write('data1', 'utf8');
writableStream.write('data2', 'utf8');
writableStream.uncork();
writableStream.end();
writableStream.on('finish', () => {
  console.info("all Data is End"); // all Data is End
});
```

### on

on(event: string, callback: Callback<emitter.EventData>): void

Registers an event processing callback to listen for different events on the writable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event    | string   | Yes| Type of the event. The following events are supported:| `'drain' `\|`'error'` \|  <br>\- **'close'**: triggered when the call of [end()](#end) is complete and the write operation ends.<br>\- **'drain'**: triggered when the data in the buffer of the writable stream is cleared.<br>\- **'error'**: triggered when an exception occurs in the writable stream.<br>\- **'finish'**: triggered when all data in the buffer is written to the target.|
| callback | Callback\<[emitter.EventData](../apis-basic-services-kit/js-apis-emitter.md#eventdata)\> | Yes| Callback function used to return the event data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback(new Error());
  }
}

let callbackCalled = false;
let writable = new TestWritable();
writable.on('error', () => {
  console.info("Writable event test", callbackCalled.toString()); // Writable event test false
});
writable.write('hello', 'utf8', () => {
});
```

### off

off(event: string, callback?: Callback<emitter.EventData>): void

Unregisters an event processing callback used to listen for different events on the writable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event    | string   | Yes| Type of the event. The following events are supported:| `'drain' `\|`'error'` \|  <br>\- **'close'**: triggered when the call of [end()](#end) is complete and the write operation ends.<br>\- **'drain'**: triggered when the data in the buffer of the writable stream is cleared.<br>\- **'error'**: triggered when an exception occurs in the writable stream.<br>\- **'finish'**: triggered when all data in the buffer is written to the target.|
| callback | Callback\<[emitter.EventData](../apis-basic-services-kit/js-apis-emitter.md#eventdata)\>   | No| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
 }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let writableStream = new TestWritable();
let testListenerCalled = false;
let testListener = () => {
  testListenerCalled = true;
};
writableStream.on('finish', testListener);
writableStream.off('finish');
writableStream.write('test');
writableStream.end();
setTimeout(() => {
  console.info("Writable off test", testListenerCalled.toString()); // Writable off test false
}, 0);
```

### doInitialize

doInitialize(callback: Function): void

You need to implement this API but do not call it directly. It is automatically called during the initialization of the writable stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| callback | Function | Yes| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class MyWritable extends stream.Writable {
  doInitialize(callback: Function) {
    super.doInitialize(callback);
    console.info("Writable doInitialize"); // Writable doInitialize
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    super.doWrite(chunk, encoding, callback);
  }
}

new MyWritable();
```

### doWrite

doWrite(chunk: string | Uint8Array, encoding: string, callback: Function): void

A data write API. You need to implement this API but do not call it directly. This API is automatically called when data is written. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | Yes| Data to write.|
| encoding  | string | Yes  | Encoding format. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | Yes  | Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("Writable chunk is", chunk); // Writable chunk is data
    callback();
  }
}

let writableStream = new TestWritable();
writableStream.write('data', 'utf8');
```

### doWritev

doWritev(chunks: string[] | Uint8Array[], callback: Function): void

A batch data write API. You need to implement this API but do not call it directly. This API is automatically called when data is written. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| chunks    | string[] \|  Uint8Array[] | Yes| Data arrays to write in batches.|
| callback  | Function | Yes| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWritev(chunks: string[] | Uint8Array[], callback: Function) {
    console.info("Writable chunk", chunks);
    callback();
  }
/**
 * Writable chunk data1
 * Writable chunk data2
* */
}

let writableStream = new TestWritable();
writableStream.write('data1', 'utf8');
writableStream.write('data2', 'utf8');
writableStream.uncork();
writableStream.end();
```

## ReadableOptions

Describes the options used in the **Readable** constructor.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Mandatory| Description|
| ---- | -------- | ---- | -------------- |
| encoding | string  | No| Encoding format. If an invalid string is input, an exception is thrown in the **Readable** constructor.<br>The following formats are supported: utf-8, UTF-8, GBK, GB2312, gb2312, GB18030, gb18030, ibm866, iso-8859-2, iso-8859-3, iso-8859-4, iso-8859-5, iso-8859-6, iso-8859-7, iso-8859-8, iso-8859-8-i, iso-8859-10, iso-8859-13, iso-8859-14, iso-8859-15, koi8-r, koi8-u, macintosh, windows-874, windows-1250, windows-1251, windows-1252, windows-1253, windows-1254, windows-1255, windows-1256, windows-1257, windows-1258, gbk, big5, euc-jp, iso-2022-jp, shift_jis, euc-kr, x-mac-cyrillic, utf-16be, and utf-16le.<br>The default value is **'utf-8'**.|

## Readable

Stream from which data can be read. A readable stream is used to read data from a source, such as a file or a network socket.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type     | Read-Only| Optional | Description       |
| ------- | -------- | ------ | ------ | ----------- |
| readableObjectMode  | boolean   | Yes  | No| Whether the readable stream works in object mode. The value **true** means that the stream is configured in object mode, and **false** means the opposite. Currently, only raw data (string and Uint8Array) is supported, and the return value is **false**.|
| readable | boolean | Yes| No | Whether the readable stream is currently readable. The value **true** means that the stream is currently readable, and **false** means that no data is available to read from the stream.|
| readableHighWatermark | number | Yes| No | Maximum amount of data that can be stored in the buffer. The default value is 16 * 1024, in bytes.|
| readableFlowing | boolean \| null | Yes| No | Whether the readable stream is flowing. The value **true** means that the stream is flowing, and **false** means the opposite. The default value is **true**.|
| readableLength | number | Yes| No | Number of bytes in the buffer.|
| readableEncoding | string \| null | Yes| No | Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| readableEnded | boolean | Yes | No| Whether the readable stream ends. The value **true** means that the stream has no more data to read, and **false** means the opposite.|

### constructor

constructor()

A constructor used to create a **Readable** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let readableStream = new stream.Readable();
```

### constructor

constructor(options: ReadableOptions)

A constructor used to create a **Readable** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type| Mandatory| Description|
| ------ | -------- | -------- | -------- |
| options   | [ReadableOptions](#readableoptions)   | Yes| Options in the **Readable** constructor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let option : stream.ReadableOptions = {
  encoding : 'utf-8'
};
let readableStream = new stream.Readable(option);
```

### read

read(size?: number): string | null

Reads data from the buffer of the readable stream and returns the read data. If no data is read, **null** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type| Mandatory| Description|
| ------ | -------- | -------- | -------- |
| size   | number   | No| Number of bytes to read. The default value is **undefined**.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| string \| null | Data read from the readable stream.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200038 | The doRead method has not been implemented. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
readableStream.push('test');
readableStream.pause();
let dataChunk = readableStream.read();
console.info('Readable data is', dataChunk); // Readable data is test
```

### resume

resume(): Readable

Resumes an explicitly paused readable stream. You can use **isPaused** to check whether the stream is paused.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| [Readable](#readable) | Current **Readable** object.|

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
readableStream.resume();
console.info("Readable test resume", !readableStream.isPaused()); // After a successful switching, the log "Readable test resume true" is displayed.
```

### pause

pause(): Readable

Pauses the readable stream in flowing mode. You can use **isPaused** to check whether the stream is paused.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| [Readable](#readable) | Current **Readable** object.|

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
readableStream.pause();
console.info("Readable test pause", readableStream.isPaused()); // Readable test pause true
```

### setEncoding

setEncoding(encoding?: string): boolean

Sets an encoding format for the readable stream.
If the buffer contains data, setting the encoding format is not allowed, and **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | No| Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the setting is successful; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
let result = readableStream.setEncoding('utf8');
console.info("Readable result", result); // Readable result true
```

### isPaused

isPaused(): boolean

Checks whether the readable stream is paused. The stream is paused after [pause()](#pause) is called and resumes from the paused state after [resume()](#resume) is called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the stream is paused; otherwise, **false** is returned.|

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
console.info("Readable isPaused", readableStream.isPaused()); // Readable isPaused false
readableStream.pause();
console.info("Readable isPaused", readableStream.isPaused()); // Readable isPaused true
```

### pipe

pipe(destination: Writable, options?: Object): Writable

Attaches a writable stream to the readable stream to implement automatic data transmission.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| destination | [Writable](#writable) | Yes| Writable stream that receives data.|
| options     | Object | No| Reserved.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Writable](#writable) | Current **Writable** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
    readable.push('test');
    readable.push(null);
  }
}

class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("Readable test pipe", chunk); // Readable test pipe test
    callback();
  }
}

let readable = new TestReadable();
let writable = new TestWritable();
readable.pipe(writable);
```

### unpipe

unpipe(destination?: Writable): Readable

Detaches a writable stream previously attached to the readable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| destination | [Writable](#writable) | No| Writable stream to detach. The default value is **undefined**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Readable](#readable) | Current **Readable** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
    readable.push('test');
    readable.push(null);
  }
}

class TestWritable extends stream.Writable {
  constructor() {
    super();
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let readable = new TestReadable();
let writable = new TestWritable();
readable.pipe(writable);
readable.unpipe(writable);
readable.on('data', () => {
  console.info("Readable test unpipe data event called");
});
// After successful detaching, the data event is not triggered and "Readable test unpipe data event called" is not printed.
```

### on

on(event: string, callback: Callback<emitter.EventData>): void

Registers an event processing callback to listen for different events on the readable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event    | string   | Yes| Type of the event. The following events are supported:| `'data' `\|`'end'` \| `'error'`\|`'readable'`\|`'pause'`\| <br>\- **'close'**: triggered when [push()](#push) is called, with **null** passed in.<br>\- **'data'**: triggered when a data chunk is transferred to a consumer.<br>\- **'end'**: triggered when [push()](#push) is called, with **null** passed in.<br>\- **'error'**: triggered when an exception occurs in the stream.<br>\- **'readable'**: triggered when there is data available to be read from the stream.<br>\- **'pause'**: triggered when [pause()](#pause) is called.<br>\- **'resume'**: triggered when [resume()](#resume) is called.|
| callback | Callback\<[emitter.EventData](../apis-basic-services-kit/js-apis-emitter.md#eventdata)\> | Yes| Callback function used to return the event data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
    throw new Error('Simulated error');
  }
}

let readable = new TestReadable();
readable.push('test');
readable.on('error', () => {
  console.info("error event called"); // error event called
});
```

### off

off(event: string, callback?: Callback<emitter.EventData>): void

Unregisters an event processing callback used to listen for different events on the readable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event    | string   | Yes| Type of the event. The following events are supported:| `'data' `\|`'end'` \| `'error'`\|`'readable'`\|`'pause'`\| <br>\- **'close'**: triggered when [push()](#push) is called, with **null** passed in.<br>\- **'data'**: triggered when a data chunk is transferred to a consumer.<br>\- **'end'**: triggered when [push()](#push) is called, with **null** passed in.<br>\- **'error'**: triggered when an exception occurs in the stream.<br>\- **'readable'**: triggered when there is data available to be read from the stream.<br>\- **'pause'**: triggered when [pause()](#pause) is called.<br>\- **'resume'**: triggered when [resume()](#resume) is called.|
| callback | Callback\<[emitter.EventData](../apis-basic-services-kit/js-apis-emitter.md#eventdata)\>   | No| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readable = new TestReadable();

function read() {
  console.info("read() called");
}

readable.setEncoding('utf8');
readable.on('readable', read);
readable.off('readable');
readable.push('test');
// After off is used to unregister the listening of the readable stream events, the read function is not called and "read() called" is not printed.
```

### doInitialize

doInitialize(callback: Function): void

You need to implement this API. It is called when the readable stream calls [on](#on-1) for the first time. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| callback | Function | Yes| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class MyReadable extends stream.Readable {
  doInitialize(callback: Function) {
    super.doInitialize(callback);
    console.info("Readable doInitialize"); // Readable doInitialize
}

  doRead(size: number) {
  }
}

let myReadable = new MyReadable();
myReadable.on('data', () => {
});
```

### doRead

doRead(size: number): void

A data read API that needs to be implemented in child classes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes| Number of bytes to read. Value range: 0 <= size <= Number.MAX_VALUE|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
    console.info("doRead called"); // doRead called
  }
}

let readable = new TestReadable();
readable.on('data', () => {
});
```

### push

push(chunk:  Uint8Array | string | null, encoding?: string): boolean

Pushes data into the buffer of the readable stream.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| chunk | Uint8Array \| string  \| null | Yes| Data to read.|
| encoding | string | No| Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether there is space in the buffer of the readable stream. The value **true** means that there is still space in the buffer, and **false** means that the buffer is full. If **null** is passed, **false** is always returned, indicating that no data chunk is available for pushing.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readable = new TestReadable();
let testData = 'Hello world';
readable.push(testData);
console.info("Readable push test", readable.readableLength); // Readable push test 11
```

## Duplex

A stream that is both readable and writable. A duplex stream allows data to be transmitted in two directions, that is, data can be read and written.
The **Duplex** class inherits from [Readable](#readable) and supports all the APIs in **Readable**.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type     | Read-Only| Optional | Description       |
| ------- | -------- | ------ | ------ | ----------- |
| writableObjectMode  | boolean   | Yes  | No| Whether the writable side of the duplex stream works in object mode. The value **true** means that the writable side of the stream is configured in object mode, and **false** means the opposite. Currently, only raw data (string and Uint8Array) is supported, and the return value is **false**.|
| writableHighWatermark | number | Yes| No | High watermark for the data volume in the buffer of the duplex stream in write mode. This value is not customizable currently. When you call [write()](#write-1), if the data volume in the buffer reaches this watermark, [write()](#write-1) will return **false**. The default value is 16 * 1024, in bytes.|
| writable | boolean | Yes| No | Whether the duplex stream is currently writable. The value **true** means that the stream is currently writable, and **false** means that the stream does not accept write operations.|
| writableLength | number | Yes| No | Number of bytes to be written in the buffer of the duplex stream.|
| writableCorked | number | Yes | No| Count of cork states of the duplex stream. If the value is greater than 0, the duplex stream buffers all writes. If the value is **0**, buffering stops. You can call [cork()](#cork-1) to increment the count by one, call [uncork()](#uncork-1) to decrement the count by one, and call [end()](#end-1) to clear the count.|
| writableEnded | boolean | Yes | No| Whether [end()](#end-1) has been called for the duplex stream. This property does not specify whether the data has been flushed. The value **true** means that [end()](#end-1) has been called, and **false** means the opposite.|
| writableFinished | boolean | Yes | No| Whether data in the duplex stream has been flushed. The value **true** means that data in the stream has been flushed, and **false** means the opposite.|

### constructor

constructor()

A constructor used to create a **Duplex** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let duplex = new stream.Duplex();
```

### write

write(chunk?: string | Uint8Array, encoding?: string, callback?: Function): boolean

Writes data to the buffer of the stream. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | No| Data to write. It cannot be **null**, **undefined**, or an empty string.|
| encoding  | string | No  | Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | No  | Callback used to return the result. It is not called by default.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| boolean | Whether there is space in the buffer of the writable stream. The value **true** means that there is still space in the buffer. The value **false** means that the buffer is full, and you are not advised to continue writing data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200036 | The stream has been ended. |
| 10200037 | The callback is invoked multiple times consecutively. |
| 10200039 | The doTransform method has not been implemented for a class that inherits from Transform. |

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("duplexStream chunk is", chunk); // duplexStream chunk is test
    callback();
  }
}

let duplexStream = new TestDuplex();
let result = duplexStream.write('test', 'utf8');
console.info("duplexStream result", result); // duplexStream result true
```

### end

end(chunk?: string | Uint8Array, encoding?: string, callback?: Function): Writable

Ends the writing process in a duplex stream. This API uses an asynchronous callback to return the result.

If the value of **writableCorked** is greater than 0, the value is set to **0** and the remaining data in the buffer is output.

If the **chunk** parameter is passed, it is treated as the final data chunk and written using either the **write** or **doWrite** API, based on the current execution context.

If **doWrite** is used for writing, the validity check of the **encoding** parameter depends on **doWrite**.

If **end** is used alone (without **write**) and the **chunk** parameter is passed, the data is written through **doWrite**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | No| Data to write. The default value is **undefined**.|
| encoding  | string | No  | Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | No  | Callback used to return the result. It is not called by default.|

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| [Writable](#writable) | Current **Duplex** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200039 | The doTransform method has not been implemented for a class that inherits from Transform. |

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
  console.info("Duplex chunk is", chunk); // Duplex chunk is test
  callback();
  }
}

let duplexStream = new TestDuplex();
duplexStream.end('test', 'utf8', () => {
  console.info("Duplex is end"); // Duplex is end
});
```

### setDefaultEncoding

setDefaultEncoding(encoding?: string): boolean

Sets the default encoding format for the duplex stream so that characters can be correctly parsed when data is read.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | No| Encoding format. The default value is **'utf8'**. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the setting is successful; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }
}

let duplexStream = new TestDuplex();
let result = duplexStream.setDefaultEncoding('utf8');
console.info("duplexStream is result", result); // duplexStream is result true
```

### cork

cork(): boolean

Forces all written data to be buffered in memory. This API is called to optimize the performance of continuous write operations.

After this API is called, the value of **writableCorked** is incremented by one. It is recommended that this API be used in pair with [uncork()](#uncork-1).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the corked status is successfully set; otherwise, **false** is returned.|

**Example**

```ts
let duplexStream = new stream.Duplex();
let result = duplexStream.cork();
console.info("duplexStream cork result", result); // duplexStream cork result true
```

### uncork

uncork(): boolean

Flushes all data buffered, and writes the data to the target.

After this API is called, the value of **writableCorked** is decremented by one. If the value reaches **0**, the stream is no longer in the cork state. Otherwise, the stream is still in the cork state. It is recommended that this API be used in pair with [cork()](#cork-1).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the corked status is removed; otherwise, **false** is returned.|

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    dataWritten += chunk;
    callback();
  }
}

let dataWritten = '';
let duplexStream = new TestDuplex();
duplexStream.cork();
duplexStream.write('a');
duplexStream.write('b');
duplexStream.uncork();
console.info("Duplex test uncork", dataWritten); // Duplex test uncork ab
```

### doWrite

doWrite(chunk: string | Uint8Array, encoding: string, callback: Function): void

A data write API. You need to implement this API but do not call it directly. This API is automatically called when data is written. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| chunk  | string \| Uint8Array | Yes| Data to write.|
| encoding  | string | Yes  | Encoding format. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | Yes  | Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    console.info("duplexStream chunk is", chunk); // duplexStream chunk is data
    callback();
  }
}

let duplexStream = new TestDuplex();
duplexStream.write('data', 'utf8');
```

### doWritev

doWritev(chunks: string[] | Uint8Array[], callback: Function): void

A batch data write API. You need to implement this API but do not call it directly. This API is automatically called when data is written. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| chunks    | string[] \| Uint8Array[] | Yes| Data arrays to write in batches.|
| callback  | Function | Yes| Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestDuplex extends stream.Duplex {
  constructor() {
    super();
  }

  doRead(size: number) {
  }

  doWrite(chunk: string | Uint8Array, encoding: string, callback: Function) {
    callback();
  }

  doWritev(chunks: string[] | Uint8Array[], callback: Function) {
    console.info("duplexStream chunk", chunks[0]); // duplexStream chunk data1
    callback();
  }
}

let duplexStream = new TestDuplex();
duplexStream.cork();
duplexStream.write('data1', 'utf8');
duplexStream.write('data2', 'utf8');
duplexStream.uncork();
duplexStream.end();
```

## Transform

A special duplex stream that supports data conversion and result output. The **Transform** class inherits from [Duplex](#duplex) and supports all the APIs in **Duplex**.

### constructor

constructor()

A constructor used to create a **Transform** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let transform = new stream.Transform();
```

### doTransform

doTransform(chunk: string, encoding: string, callback: Function): void

Converts or processes input data chunks and uses a callback to notify that the processing is complete.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| chunk  | string | Yes| Data to write.|
| encoding  | string | Yes  | Encoding format. Currently, **'utf8'**, **'gb18030'**, **'gbk'**, and **'gb2312'** are supported.|
| callback  | Function | Yes  | Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestTransform extends stream.Transform {
  constructor() {
    super();
  }

  doTransform(chunk: string, encoding: string, callback: Function) {
    let stringChunk = chunk.toString().toUpperCase();
    console.info("Transform test doTransform", stringChunk); // Transform test doTransform HELLO
    tr.push(stringChunk);
    callback();
  }
}

let tr = new TestTransform();
tr.write("hello");
```

### doFlush

doFlush(callback: Function): void

Called at the end of the stream to process the remaining data. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type    | Mandatory    | Description|
| -------- | -------- | -------- | -------- |
| callback  | Function | Yes  | Callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
class TestTransform extends stream.Transform {
  constructor() {
    super();
  }

  doTransform(chunk: string, encoding: string, callback: Function) {
    callback();
  }

  doFlush(callback: Function) {
    callback(null, 'test');
  }
}

let transform = new TestTransform();
transform.end('my test');
transform.on('data', (data) => {
  console.info("data is", data.data); // data is test
});
```

# Basic Security Capability Development


## What is the maximum number of bytes that can be encrypted at a time in AES GCM mode in HUKS? (API version 9)

**Solution**

In HUKS, a maximum of 64 bytes can be encrypted at a time in AES GCM mode.

**Example**

```
/* Encrypt the key. */
await huks.init(srcKeyAlias, encryptOptions).then((data) => {
 console.info(`test init data: ${JSON.stringify(data)}`);
 handle = data.handle;
}).catch((err) => {
 console.info('test init err information: ' + JSON.stringify(err));
});
encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice (0,64)); // Take 64 bytes.
await huks.update(handle, encryptOptions).then(async (data) => {
 console.info(`test update data ${JSON.stringify(data)}`);
 encryptUpdateResult = Array.from(data.outData);
}).catch((err) => {
 console.info('test update err information: ' + err);
});
encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice (64,80)); // Remaining data
```


## What if garbled characters are returned by Md.digest() of cryptoFramework? (API version 9)

**Symptom**

When **digest()** of **Md** in the **cryptoFramework** module is called, garbled characters are returned.

**Solution**

The DataBlob returned by **digest()** is of the Uint8Array type and needs to be converted into a hexadecimal string before being printed. You can use the online MD5 encryption tool to verify the result.

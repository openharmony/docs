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


## What do I do if garbled characters are returned by Md.digest() of cryptoFramework? (API version 9)

**Symptom**

When **digest()** of **Md** in the **cryptoFramework** module is called, garbled characters are returned.

**Solution**

The DataBlob returned by **digest()** is of the Uint8Array type and needs to be converted into a hexadecimal string before being printed. You can use the online MD5 encryption tool to verify the result.

## How do I customize the text on the options displayed for requesting a permission? (API version 10)

**Solution**

Only **reason** can be customized. The text on the options displayed cannot be customized.

**Reference**

[Workflow for Using Permissions](../security/AccessToken/determine-application-mode.md)

## Are synchronous APIs provided by @ohos.security.cryptoFramework? Will synchronous APIs be provided in the future? (API version 10)

**Solution**

1. Currently, all the JS APIs provided by the cryptoFramework module are implemented in asynchronous mode.

2. Synchronous encryption and decryption APIs will be provided in later versions.

## When and how do I use \<SaveButton>? What are the differences between using \<SaveButton> and using a Picker? (API version 10)

**Solution**

1. You can integrate \<**SaveButton**> into your application and register the **onClick** callback. When a user taps \<**SaveButton**>, the application calls the **mediaLibrary** API in the callback to quickly save an image. During this process, operations such as authorization via a dialog box and selecting the directory for saving the image are not required.
2. You can use this component when your application needs to save images or videos to the media library.
3. This component allows for simpler operations than Pickers, which have to start a system application and have the user select a directory for saving the image or video.

**Reference**

[Security Component Overview](../security/AccessToken/security-component-overview.md)

[SaveButton](../reference/arkui-ts/ts-security-components-savebutton.md)

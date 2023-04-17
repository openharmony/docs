# Globalization Subsystem Changelog

## cl.resourceManager.1 Change in the Meaning of the Return Value for the API Used to Obtain the rawfile Descriptor

Changed the meaning of the return value for the API used to obtain the rawfile descriptor after the non-decompression feature is added in this version. The change in the meaning of the return value, namely, **descriptor: RawFileDescriptor {fd, offset, length}**, is described as follows:

**Before change:**

**fd**: file descriptor for accessing the rawfile.

**offset**: offset for accessing the rawfile. In this case, the value is **0**.

**length**: size of the rawfile to access.

**After change:**

**fd**: file descriptor for accessing the HAP where the rawfile is located.

**offset**: offset of the accessed rawfile relative to the HAP.

**length**: size of the rawfile to access.

**Change Impact**

In versions earlier than 4.0.2.2, the rawfile can be accessed only through **fd**. In version 4.0.2.2 or later, the rawfile can be accessed only through **{fd, offset, and length}**.

**Key API/Component Changes**

| **Original API**                           | 
| ----------------                         | 
| getRawFd(path: string, callback: AsyncCallback\<RawFileDescriptor>): void   | 
| getRawFd(path: string): Promise\<RawFileDescriptor>  |
| getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void|
| getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>|
||

**Sample Code**

The following is an example of calling the **getRawFd** API:
```
try {
    this.context.resourceManager.getRawFd("test.ogg", (error, value) => {
        if (error != null) {
            console.log(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);
        } else {
            let fileDescriptor = {
                fd = value.fd,
                offset = value.offset,
                length = value.length
            }
            this.avPlayer.fdSrc(fileDescriptor); // Take the audio player as an example. When calling fdSrc, pass fileDescriptor in addition to fd.
        }
    });
  } catch (error) {
      console.error(`callback getRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  };
```

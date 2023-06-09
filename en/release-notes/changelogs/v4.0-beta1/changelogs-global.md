# Globalization Subsystem Changelog

## cl.global.1 Runtime Authentication Added for System APIs

The internationalization component of the globalization subsystem adds runtime authentication for system APIs in certain scenarios. The following changes are made in API version 9 and later:
 - Setting the system language, country or region, and area
 - Setting the 24-hour format of the system
 - Adding and removing the preferred language
 - Setting localized numbers

You need to adapt your application based on the following information.

**Change Impact**

APIs involved in the preceding scenarios can be properly called only by system applications that have the **UPDATE_CONFIGURATION** permission.

**Key API/Component Changes**

 - Involved APIs:
   - setSystemLanguage(language: string): void;
   - setSystemRegion(region: string): void;
   - setSystemLocale(locale: string): void;
   - set24HourClock(option: boolean): void;
   - addPreferredLanguage(language: string, index?: number): void;
   - removePreferredLanguage(index: number): void;
   - setUsingLocalDigit(flag: boolean): void;

**Adaptation Guide**

Make sure the application trying to call any of the above APIs is a system application. Non-system applications are not allowed to call the APIs.
An exception will be thrown upon lack of a necessary permission or a call request from a non-system application. The exception can be captured via **try-catch**.

```js
import I18n from '@ohos.i18n'

try {
  I18n.System.setSystemLanguage('zh');
} catch(error) {
  console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
}
```


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

 - Involved APIs:
   - getRawFd(path: string, callback: AsyncCallback\<RawFileDescriptor>): void
   - getRawFd(path: string): Promise\<RawFileDescriptor>
   - getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void
   - getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>

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


## cl.resourceManager.2 Addition of getStringSync and getStringByNameSync APIs

Added the **getStringSync** and **getStringByNameSync** APIs and error codes to obtain and format strings.

| Bundle Name | API |
| --------------- | ---------------------------------------------------- |
| ohos.resourceManager.d.ts | getStringSync(resId: number, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringSync(resource: Resource, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringByNameSync(resName: string, ...args: Array<string \| number>): string; |

**Change Impact**

In versions earlier than 4.0.6.2, only the values of string resources can be directly obtained. In 4.0.6.2 or later, the values of string resources can be formatted based on the input arguments for enhanced query.

The following error codes are added:

9001007 If the resource obtained by resId formatting error.

9001008 If the resource obtained by resName formatting error.

**Sample Code**

The following uses **getStringSync** as an example. Before the change, only example 1 is supported. After the change, both example 1 and example 2 are supported.
```
Example 1:
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
Example 2:
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 787, 98.78);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
```

**Adaptation Guide**
For details, see the API reference.

[API Reference](../../../application-dev/reference/apis/js-apis-resource-manager.md)

[Error Codes](../../../application-dev/reference/errorcodes/errorcode-resource-manager.md)

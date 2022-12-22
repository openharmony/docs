# File Management Development

## Does fileio.rmdir Delete Files Recursively?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

Yes. **fileio.rmdir** deletes files recursively.

## How Do I Create a File That Does Not Exist?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

Use **fileio.open(filePath, 0o100, 0o666)** to create a file that does not exist. The second parameter **0o100** means to create a file if it does not exist. The third parameter **mode** must also be specified.

## What If "call fail callback fail, code: 202, data: json arguments illegal" Is Displayed?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

When the **fileio** module is used to copy files, the file path cannot start with "file:///".

## How Do I Read Files Outside the App Sandbox?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

If the input parameter of the **fileio** API is **path**, only the sandbox directory of the current app obtained from the context can be accessed. To access data in other directories, such as the user data, images, and videos, open the file as the data owner and operate with the file descriptor (FD) returned.

For example, to read or write a file in Media Library, perform the following steps:

1. Use **getFileAssets()** to obtain the **fileAsset** object.

2. Use **fileAsset.open()** to obtain the FD.

3. Use the obtained FD as the **fileIo** API parameter to read and write the file.

## What If the File Contains Garbled Characters?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Read the file content from the buffer, and decode the file content using **util.TextDecoder**.

Example:

```
import util from '@ohos.util' 
async function readFile(path) { 
  let stream = fileio.createStreamSync(path, "r+"); 
  let readOut = await stream.read(new ArrayBuffer(4096)); 
  let textDecoder = new util.TextDecoder("utf-8", { ignoreBOM: true }); 
  let buffer = new Uint8Array(readOut.buffer)
  let readString = textDecoder.decode(buffer, { stream: false }); 
  console.log ("[Demo] File content read: "+ readString);
}
```

## What Should I Do If There is No Return Value or Error Captured After getAlbums Is Called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The **ohos.permission.READ_MEDIA** is required for using **getAlbums()**. In addition, this permission needs user authorization. For details, see [OpenHarmony Permission List] (../security/permission-list.md).

1. Configure the required permission in the **module.json5** file.
     
   ```
   "requestPermissions": [
     {
       "name": "ohos.permission.READ_MEDIA"
     }
   ]
   ```

2. Add the code for user authorization before the **MainAbility.ts -> onWindowStageCreate** page is loaded.
     
   ```
   private requestPermissions() {
   let permissionList: Array<string> = [
     "ohos.permission.READ_MEDIA"
   ];
   this.context.requestPermissionsFromUser(permissionList)
     .then(data => {
       console.info(`request permission data result = ${data.authResults}`)
     })
     .catch(err => {
       console.error(`fail to request permission error:${err}`)
     })
   }
   ```

## What Do I Do If the App Crashes When FetchFileResult() Is called Multiple Times?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Each time after the **FetchFileResult** object is called, call **FetchFileResult.close()** to release and invalidate the **FetchFileResult** object .

## What if An Error Is Reported by IDE When mediaLibrary.getMediaLibrary() Is Called in the Stage Model?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

In the stage model, use **mediaLibrary.getMediaLibrary(context: Context)** to obtain the media library instance.

## How Do I Sort the Data Returned by mediaLibrary.getFileAssets()?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Use the **order** attribute in **[MediaFetchOptions](../reference/apis/js-apis-medialibrary.md#mediafetchoptions7)** to sort the data returned.

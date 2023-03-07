# File Path Management

User data on OpenHarmony is managed by the **mediaLibrary** module in a unified manner. You can use the APIs provided by this module to access and operate the user data.

> **NOTE**
>
> Before developing features, read [MediaLibrary Overview](medialibrary-overview.md) to learn how to obtain a **MediaLibrary** instance and request the permissions to call the APIs of **MediaLibrary**.

To ensure the application running efficiency, most **MediaLibrary** API calls are asynchronous, and both callback and promise modes are provided for these APIs. The following code samples use the promise mode. For details about the APIs, see [MediaLibrary API Reference](../reference/apis/js-apis-medialibrary.md).

## File Formats Supported by Public Directories

Before using file paths for development, learn the file formats supported by each public directory.
> **CAUTION**
>
> The following table lists only the file types that can be identified by the system. In your application development, pay attention to the file formats supported by the corresponding interfaces. <br> For example, only .jpeg and .webp can be used for image encoding, and only .jpg, .png, .gif, .bmp, .webp, and .raw can be used for image decoding.

| Directory  | Directory Type     | Media Type     | Description          | Supported File Format                                              |
| ---------- | ------------- | ------------- | -------------- | ------------------------------------------------------------ |
| Camera/    | DIR_CAMERA    |    VIDEO and   IMAGE      | Directory for storing images and videos taken by the camera. Videos and images can be stored in this directory and its subdirectories.| .bmp / .bm / .gif / .jpg /. jpeg / .jpe / .png / .webp / .raw / .svg / .heif / .mp4 / .3gp / .mpg / .mov / .webm / .mkv |
| Videos/    | DIR_VIDEO     | VIDEO | Dedicated video directory. Only videos can be stored in this directory and its subdirectories.| .mp4 / .3gp / .mpg / .mov / .webm / .mkv                     |
| Pictures/  | DIR_IMAGE     | IMAGE | Dedicated image directory. Only images can be stored in this directory and its subdirectories.| .bmp / .bm / .gif / .jpg /. jpeg / .jpe / .png / .webp / .raw / .svg / .heif |
| Audios/    | DIR_AUDIO     | AUDIO |Dedicated audio directory. Only audio files can be stored in this directory and its subdirectories.| .aac/.mp3/.flac/.wav/.ogg                                    |
| Documents/ | DIR_DOCUMENTS | FILE  |Dedicated file directory. Only files except audios, images, and videos can be stored in this directory and its subdirectories.| -                                                |
| Download/  | DIR_DOWNLOAD  | ALLTYPE       |Directory for storing downloaded files. The types of files in this directory and its subdirectories are not restricted.| -                                                    |

## Obtaining a Public Directory

Different types of files are stored in different public directories. You can call [getPublicDirectory](../reference/apis/js-apis-medialibrary.md#getpublicdirectory8-1) to obtain the public directory that stores files of a certain type.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.READ_MEDIA**.

The following describes how to obtain the public directory that stores camera files.

```ts
async function example(){
  const context = getContext(this);
  let media = mediaLibrary.getMediaLibrary(context);
  let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
  const dicResult = await media.getPublicDirectory(DIR_CAMERA);
  if (dicResult == 'Camera/') {
    console.info('mediaLibraryTest : getPublicDirectory passed');
  } else {
    console.error('mediaLibraryTest : getPublicDirectory failed');
  }
}
```

## Copying Files Between the Application Sandbox and the Public Directory

OpenHarmony provides the application sandbox to minimize the leakage of application data and user privacy information.

Users can access files stored in the public directories through the system applications **Files** and **Gallery**. However, files in the application sandbox can be accessed only by the application itself.

### Copying a File

You can call [mediaLibrary.FileAsset.open](../reference/apis/js-apis-medialibrary.md#open8-1) to open a file in a public directory.

You can call [fs.open](../reference/apis/js-apis-file-fs.md#fsopen) to open a file in the application sandbox. The sandbox directory can be accessed only through the application context.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permissions **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA**.
- You have imported the module [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) in addition to @ohos.multimedia.mediaLibrary.
- The **testFile.txt** file has been created and contains content.

**How to Develop**

1. Call [context.filesDir](../reference/apis/js-apis-file-fs.md) to obtain the directory of the application sandbox.
2. Call **MediaLibrary.getFileAssets** and **FetchFileResult.getFirstObject** to obtain the first file in the result set of the public directory.
3. Call **fs.open** to open the file in the sandbox.
4. Call **fileAsset.open** to open the file in the public directory.
5. Call [fs.copyfile](../reference/apis/js-apis-file-fs.md#fscopyfile) to copy the file.
6. Call **fileAsset.close** and [fs.close](../reference/apis/js-apis-file-fs.md#fsclose) to close the file.

**Example 1: Copying Files from the Public Directory to the Sandbox**

```ts
async function copyPublic2Sandbox() {
  try {
    const context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let sandboxDirPath = context.filesDir;
    let fileKeyObj = mediaLibrary.FileKey;
    let fileAssetFetchOp = {
      selections: fileKeyObj.DISPLAY_NAME + '= ?',
      selectionArgs: ['testFile.txt'],
    };
    let fetchResult = await media.getFileAssets(fileAssetFetchOp);
    let fileAsset = await fetchResult.getFirstObject();

    let fdPub = await fileAsset.open('rw');
    let fdSand = await fs.open(sandboxDirPath + '/testFile.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    await fs.copyFile(fdPub, fdSand.fd);

    await fileAsset.close(fdPub);
    await fs.close(fdSand.fd);

    let content_sand = await fs.readText(sandboxDirPath + '/testFile.txt');
    console.info('content read from sandbox file: ', content_sand)
  } catch (err) {
    console.info('[demo] copyPublic2Sandbox fail, err: ', err);
  }
}
```

**Example 2: Copying a File from the Sandbox to the Public Directory**

```ts
async function copySandbox2Public() {
  const context = getContext(this);
  let media = mediaLibrary.getMediaLibrary(context);
  let sandboxDirPath = context.filesDir;

  let DIR_DOCUMENTS = mediaLibrary.DirectoryType.DIR_DOCUMENTS;
  const publicDirPath = await media.getPublicDirectory(DIR_DOCUMENTS);
  try {
    let fileAsset = await media.createAsset(mediaLibrary.MediaType.FILE, 'testFile02.txt', publicDirPath);
    console.info('createFile successfully, message = ' + fileAsset);
  } catch (err) {
    console.error('createFile failed, message = ' + err);
  }
  try {
    let fileKeyObj = mediaLibrary.FileKey;
    let fileAssetFetchOp = {
      selections: fileKeyObj.DISPLAY_NAME + '= ?',
      selectionArgs: ['testFile02.txt'],
    };
    let fetchResult = await media.getFileAssets(fileAssetFetchOp);
    var fileAsset = await fetchResult.getFirstObject();
  } catch (err) {
    console.error('file asset get failed, message = ' + err);
  }
  let fdPub = await fileAsset.open('rw');
  let fdSand = await fs.open(sandboxDirPath + 'testFile.txt', OpenMode.READ_WRITE);
  await fs.copyFile(fdSand.fd, fdPub);
  await fileAsset.close(fdPub);
  await fs.close(fdSand.fd);
  let fdPubRead = await fileAsset.open('rw');
  try {
    let arrayBuffer = new ArrayBuffer(4096);
    await fs.read(fdPubRead, arrayBuffer);
    var content_pub = String.fromCharCode(...new Uint8Array(arrayBuffer));
    fileAsset.close(fdPubRead);
  } catch (err) {
    console.error('read text failed, message = ', err);
  }
  console.info('content read from public file: ', content_pub);
}
```

### Reading and Writing a File

You can use **FileAsset.open** and **FileAsset.close** of [mediaLibrary](../reference/apis/js-apis-medialibrary.md) to open and close a file, and use **fs.read** and **fs.write** in [file.fs](../reference/apis/js-apis-file-fs.md) to read and write the file.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permissions **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA**.
- You have imported the module [@ohos.file.fs](../reference/apis/js-apis-file-fs.md) in addition to @ohos.multimedia.mediaLibrary.

**How to Develop**

1. Create a file.

```ts
async function example() {
  let mediaType = mediaLibrary.MediaType.FILE;
  let DIR_DOCUMENTS = mediaLibrary.DirectoryType.DIR_DOCUMENTS;
  const context = getContext(this);
  let media = mediaLibrary.getMediaLibrary(context);
  const path = await media.getPublicDirectory(DIR_DOCUMENTS);
  media.createAsset(mediaType, "testFile.text", path).then((asset) => {
    console.info("createAsset successfully:" + JSON.stringify(asset));
  }).catch((err) => {
    console.error("createAsset failed with error: " + err);
  });
}
```

2. Call **FileAsset.open** to open the file.

3. Call [fs.write](../reference/apis/js-apis-file-fs.md#fswrite) to write a string to the file.

4. Call [fs.read](../reference/apis/js-apis-file-fs.md#fsread) to read the file and save the data read in an array buffer.

5. Convert the array buffer to a string.

6. Use **FileAsset.close** to close the file.

**Example 1: Opening an Existing File and Writing Data to It**

```ts
async function writeOnlyPromise() {
  const context = getContext(this);
  let media = mediaLibrary.getMediaLibrary(context);
  let fileKeyObj = mediaLibrary.FileKey;
  let fileAssetFetchOp = {
    selections: fileKeyObj.DISPLAY_NAME + '= ?',
    selectionArgs: ['testFile.txt'],
  };
  let fetchResult = await media.getFileAssets(fileAssetFetchOp);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('fileAssetName: ', fileAsset.displayName);

  try {
    let fd = await fileAsset.open('w');
    console.info('file descriptor: ', fd);
    await fs.write(fd, "Write file test content.");
    await fileAsset.close(fd);
  } catch (err) {
    console.error('write file failed, message = ', err);
  }
}
```

**Example 2: Opening an Existing File and Reading Data from It**

```ts
async function readOnlyPromise() {
  const context = getContext(this);
  let media = mediaLibrary.getMediaLibrary(context);
  let fileKeyObj = mediaLibrary.FileKey;
  let fileAssetFetchOp = {
    selections: fileKeyObj.DISPLAY_NAME + '= ?' ,
    selectionArgs: ['testFile.txt'],
  };
  let fetchResult = await media.getFileAssets(fileAssetFetchOp);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('fileAssetName: ', fileAsset.displayName);

  try {
    let fd = await fileAsset.open('r');
    let arrayBuffer = new ArrayBuffer(4096);
    await fs.read(fd, arrayBuffer);
    let fileContent = String.fromCharCode(...new Uint8Array(arrayBuffer));
    globalThis.fileContent = fileContent;
    globalThis.fileName = fileAsset.displayName;
    console.info('file content: ', fileContent);
    await fileAsset.close(fd);
  } catch (err) {
    console.error('read file failed, message = ', err);
  }
}
```

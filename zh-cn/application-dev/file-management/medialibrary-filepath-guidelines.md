# 文件路径使用指导

Openharmony上用户数据统一由媒体库进行管理，用户数据用户数据可以通过mediaLibrary提供的接口能力进行访问和操作。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[媒体库开发概述](medialibrary-overview.md)，了解如何获取媒体库实例和如何申请媒体库功能开发相关权限。

为了保证应用的运行效率，大部分MediaLibrary调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-medialibrary.md)。

## 公共目录路径支持的文件格式

在使用文件路径进行开发之前，需要了解各公共目录路径支持的文件格式说明。
> **注意：** <br/>
> 下表仅表示系统能识别的文件类型，在具体的开发中，开发者需要关注对应接口支持的文件格式。<br/> 如image编码功能只支持.jpeg和.webp，解码功能只支持.jpg .png .gif .bmp .webp RAW。

| 目录路径   | 目录类型      | 媒体类型      | 说明           | 支持的文件格式                                               |
| ---------- | ------------- | ------------- | -------------- | ------------------------------------------------------------ |
| Camera/    | DIR_CAMERA    |    VIDEO amd   IMAGE      | 相机拍摄图片与录像的存放路径，目录与子目录下可以存放视频，图片类型文件。 | .bmp / .bm / .gif / .jpg /. jpeg / .jpe / .png / .webp / .raw / .svg / .heif / .mp4 / .3gp / .mpg / .mov / .webm / .mkv |
| Videos/    | DIR_VIDEO     | VIDEO | 视频专有目录，目录与子目录下只可以存放视频类型文件。| .mp4 / .3gp / .mpg / .mov / .webm / .mkv                     |
| Pictures/  | DIR_IMAGE     | IMAGE | 图片专有目录，目录与子目录下只可以存放图片类型文件。 | .bmp / .bm / .gif / .jpg /. jpeg / .jpe / .png / .webp / .raw / .svg / .heif |
| Audios/    | DIR_AUDIO     | AUDIO |音频专有目录，目录与子目录下只可以存放音频类型文件。| .aac/.mp3/.flac/.wav/.ogg                                    |
| Documents/ | DIR_DOCUMENTS | FILE  |文档类型目录，目录与子目录下只可以存放音频，图片，视频以外类型文件。| -                                                |
| Download/  | DIR_DOWNLOAD  | ALLTYPE       |下载文件存放目录，目录与子目录下文件类型不受限制。| -                                                    |

## 获取文件保存的公共目录

不同类型的文件会保存到不同的公共目录下，可以通过接口[getPublicDirectory](../reference/apis/js-apis-medialibrary.md#getpublicdirectory8-1)来获取公共目录路径。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读权限"ohos.permission.READ_MEDIA"。

下面以获取Camera文件保存的公共目录为例。

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

## 沙箱与公共路径间文件的复制

OpenHarmony提供应用沙箱机制，增加目录可见性数据访问防线，减少了应用数据和用户隐私信息泄露，建立了更加严格安全的应用沙盒隔离能力。

放在公共路径下的文件，用户可以通过系统应用“文件管理”、“图库”访问，但应用沙箱内的文件，只有应用本身可以访问。

### 复制文件

通过接口[mediaLibrary.FileAsset.open](../reference/apis/js-apis-medialibrary.md#open8-1)可以打开公共路径文件。

通过接口[fs.open](../reference/apis/js-apis-file-fs.md#fsopen)可以打开沙箱路径文件，沙箱路径必须通过应用上下文context进行访问。

**前提条件**

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限"ohos.permission.READ_MEDIA, ohos.permission.WRITE_MEDIA"。
- 除了@ohos.multimedia.mediaLibrary外，还需要导入模块[@ohos.file.fs](../reference/apis/js-apis-file-fs.md)。
- 测试文件 "testFile.txt" 已创建且有文件内容。

**开发步骤**

1. 调用[context.filesDir](../reference/apis/js-apis-file-fs.md)获取应用沙箱路径。
2. 调用MediaLibrary.getFileAssets和FetchFileResult.getFirstObject获取公共目录中的FileAsset实例。
3. 调用fs.open打开沙箱路径文件。
4. 调用fileAsset.open打开公共路径文件。
5. 调用[fs.copyfile](../reference/apis/js-apis-file-fs.md#fscopyfile)复制文件。
6. 调用fileAsset.close和[fs.close](../reference/apis/js-apis-file-fs.md#fsclose)关闭文件。

**示例1 将公共路径文件复制到沙箱路径下**

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

**示例2 将应用沙箱路径文件复制到公共路径**

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

### 读写文件内容

通过[mediaLibrary](../reference/apis/js-apis-medialibrary.md)的接口FileAsset.open和FileAsset.close可以打开和关闭文件。通过[file.fs](../reference/apis/js-apis-file-fs.md)中的接口fs.read和fs.write可以读写文件。

**前提条件**

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限"ohos.permission.READ_MEDIA, ohos.permission.WRITE_MEDIA"。
- 除了@ohos.multimedia.mediaLibrary外，还需要导入模块[@ohos.file.fs](../reference/apis/js-apis-file-fs.md)。

**开发步骤**

1. 创建用于读写示例的文件。

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

2. 使用open打开文件。

3. 使用[fs.write](../reference/apis/js-apis-file-fs.md#fswrite)写入文件，以string形式传入写入数据。

4. 使用[fs.read](../reference/apis/js-apis-file-fs.md#fsread)读取文件，以 ArrayBuffer 形式保存读取结果。

5. 将ArrayBuffer转化为string，以string形式得到文件内容。

6. 使用close关闭文件。

**示例1 打开现有文件、向文件中写入**

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

**示例2 打开现有文件，读取文件内容**

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


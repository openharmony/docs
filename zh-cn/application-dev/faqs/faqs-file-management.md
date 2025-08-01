# 文件管理开发常见问题

## 使用读写权限打开picker返回的uri失败(API 10)

**问题现象**

开发者调用picker接口保存文件返回uri，调用fs.openSync()接口打开该文件时传入了读写权限：fs.OpenMode.READ_WRITE，无法正常打开文件

**原因分析**

调用picker接口保存文件拿到的uri授权为只写，而开发者使用读写的方式打开uri，导致权限不允许，无法进行后续操作

**解决措施**

当前保存文件时，请使用只写方式打开文件uri：

```
fs.openSync(uri, fs.OpenMode.WRITE_ONLY)
```

后续文件选择器打开或保存文件时返回uri将授予读写权限，开发者根据需要进行文件打开与编辑。

## 如何获取系统截屏图片的保存路径(API 9)

**解决措施**

截图图片保存路径：/storage/media/100/local/files/Pictures/Screenshots/


## 如何修改设备中文件目录为可读写权限(API 9)

**问题现象**

使用hdc命令向设备上发送文件时，报错：权限不足。

**解决措施**

输入命令 hdc shell mount -o remount,rw /，正确执行无提示信息。


## 如何实现文件不存在则创建文件(API 9)

**解决措施**

可以通过调用函数fs.open来实现，open(path: string, mode?: number)，指定第二个参数mode为fs.OpenMode.CREATE，表示若文件不存在，则创建文件。


## 如何解决文件的中文乱码问题(API 9)

**解决措施**

读取文件内容的buffer数据后，通过\@ohos.util的TextDecoder对文件内容进行解码。

```
let filePath = getContext(this).filesDir + "/test0.txt";
let stream = fs.createStreamSync(filePath, "r+");
let buffer = new ArrayBuffer(4096)
let readOut = stream.readSync(buffer);
let textDecoder = util.TextDecoder.create('utf-8', { ignoreBOM: true })
let readString = textDecoder.decodeWithStream(new Uint8Array(buffer), { stream: false });
console.log("读取的文件内容：" + readString);
```


## “datashare://”路径使用fs.open可以打开，但使用fs.copyFile会报错(API 9)

**解决措施**

copyfile不支持uri，可以先使用open接口打开datashare uri后，拿到fd后再调用copyfile接口。

```
let file = fs.openSync("datashare://...")
fs.copyFile(file.fd, 'dstPath', 0).then(() => {
  console.info('copyFile success')
}).catch((err) => {
  console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);
})
```


## 如何修改沙箱路径下json文件的指定内容(API 9)

**解决措施**

可以通过以下步骤来完成：

1. 使用fs.openSyn获取json文件的fd。

   ```
   import fs from '@ohos.file.fs';
   let sanFile = fs.open(basePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   let fd = sanFile.fd;
   ```

2. 通过fs.readSync读取json文件内容。

   ```
   // 4096为缓存区大小，可根据读取文件大小自定义
   let buf = new ArrayBuffer(4096);
   fs.readSync(sanFile.fd, buf);
   ```

3. 修改内容。

   ```
   obj.name = 'new name';
   ```

4. 重新写入json文件。

   ```
   fs.writeSync(file.fd, JSON.stringify(obj));
   ```

fs的具体使用可以参考：[@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md)

## 通过fileAccess模块获取的文件路径对应的实际路径是什么(API 9)

适用于Stage模型。

**解决措施**

此类文件是保存在/storage/media/100/local/files目录下，具体位置与文件类型和来源有关。知道文件名时，可在此目录下通过如下命令查找：find . -name [filename]

**参考链接：**  

[应用文件上传下载](../basic-services/request/app-file-upload-download.md)

## 如何监听文件或文件目录的变化(API 10)

**解决措施**

通过fs.createWatcher，可注册监听回调，从而监听文件或者目录的变化。

**参考链接：**  

[@ohos.file.fs](../reference/apis-core-file-kit/js-apis-file-fs.md#fscreatewatcher10)

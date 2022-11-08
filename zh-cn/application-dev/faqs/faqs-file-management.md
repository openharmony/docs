# 文件管理开发常见问题

## fileio.rmdir是递归删除吗？

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

是递归删除。


## 如何实现如果文件不存在则创建文件

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

可以通过调用函数fileio.open(filePath, 0o100, 0o666)来实现，第二个参数0o100表示若文件不存在，则创建文件。使用该选项时必须指定第三个参数 mode。

## 使用fileio进行文件复制，传入沙箱路径报错call fail callback fail, code: 202, data: json arguments illegal）

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

使用fileio模块进行文件复制时，文件路径前缀中不能以“file:///”开头。

## fileIo将数据写入流文件writeSync接口，length传参问题

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

一个中文字符length为3，英文字符为1，当前buffer为string类型时，length项需要开发者手动换算；如果要写入全部内容，可直接忽略length项，length长度超长时会导致接口报错。

## 如何读取应用沙箱之外的文件

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

fileio中接口入参为path时只能是从context获取到的本应用沙箱路径，若要访问其他路径的数据，如公共数据图片视频等，需要通过数据所有者打开文件返回fd进行操作。

比如向mediaLibrary请求读取/写入某文件，然后通过打开代表特定文件的URI后返回的fd进行操作，操作步骤如下：

1. 通过媒体查询获取文件fileAsset对象；

2. 通过fileAsset.open方法返回的fd；

3. 将fd作为fileIo接口参数进行文件读写操作；

## 如何解决文件的中文内容乱码

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

读取文件内容的buffer数据后，通过util.TextDecoder对文件内容进行解码。

示例：

```
import util from '@ohos.util' 
async function readFile(path) { 
  let stream = fileio.createStreamSync(path, "r+"); 
  let readOut = await stream.read(new ArrayBuffer(4096)); 
  let textDecoder = new util.TextDecoder("utf-8", { ignoreBOM: true }); 
  let buffer = new Uint8Array(readOut.buffer)
  let readString = textDecoder.decode(buffer, { stream: false }); 
  console.log("[Demo] 读取的文件内容：" + readString); 
}
```

## 调用媒体库getAlbums方法，没有收到返回，也没有捕获到异常是为什么

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

getAlbums方法需要权限：ohos.permission.READ_MEDIA，从[OpenHarmony权限定义列表](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/permission-list.md)查询知道ohos.permission.READ_MEDIA权限是需要用户授权。

1. 在module.json5中配置权限：
     
   ```
   "requestPermissions": [
     {
       "name": "ohos.permission.READ_MEDIA"
     }
   ]
   ```

2. 在MainAbility.ts -&gt; onWindowStageCreate页面加载前需要增加用户授权代码：
     
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

## 如何解决多次通过媒体库FetchFileResult获取文件应用崩溃 

适用于：OpenHarmonySDK 3.2.5.5版本，API9 Stage模型

通过FetchFileResult.close()方法，在FetchFileResult对象每次调用完，释放并使其失效。

## 在Stage模型下调用mediaLibrary.getMediaLibrary()接口，IDE报错

适用于：OpenHarmonySDK 3.25.5版本，API9 Stage模型

Stage模型下，获取媒体库实例应该调用mediaLibrary.getMediaLibrary(context: Context)。

## 调用mediaLibrary.getFileAssets()接口返回的内容如何排序

适用于：OpenHarmonySDK 3.2.5.5版本，API9 Stage模型

通过[MediaFetchOptions](../reference/apis/js-apis-medialibrary.md#mediafetchoptions7)对象参数里面的order属性进行排序。

<!--no_check-->
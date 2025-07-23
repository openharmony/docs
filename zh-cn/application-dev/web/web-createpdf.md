# 使用Web组件保存前端页面为PDF

从API version 14开始，支持使用Web组件的[createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14)方法，为应用提供了保存前端页面为PDF的功能。

若涉及网络文档获取，需在module.json5中配置网络访问权限。具体添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## 功能概述
通过[createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14)生成实例后，调用`pdfArrayBuffer`方法获取二进制数据流，再使用`fileIo`方法将二进制数据流保存为PDF文件。


## 使用步骤
1.初始化Web组件。
加载指定页面并确保页面渲染完成，可使用`onPageEnd`事件监听。
```ts
Web({ src: 'www.example.com', controller: this.controller })
  .onPageEnd((event) => {
    if (event) {
      console.log('url:' + event.url);
    }
  })
```

2.触发PDF生成。
页面加载完成后调用`createPdf`接口。
```ts
// 方法一：异步callback方式获取
this.controller.createPdf(
  this.pdfConfig,
  (error, result: webview.PdfData) => {
    if (error) {
      console.error("createPdf failed.");
      return;
    } else {
      console.log("createPdf success.");
    }
  })

// 方法二：Promise方式异步获取
this.controller.createPdf(this.pdfConfig)
  .then(result: webview.PdfData) => {
    console.log("createPdf success.");
  })
  .catch(resError => {
    console.error("createPdf failed.");
  })
```

3.保存PDF文件。
调用`pdfArrayBuffer`接口获取PDF二进制数据流，调用`fileIo`方法将二进制数据流保存为PDF文件。
可将`Uint8Array`转换为Blob对象或Base64字符串，以便进行本地存储或网络传输。
```ts
import { fileIo as fs } from '@kit.CoreFileKit';

// 获取沙箱路径，设置pdf文件名
let filePath = context.filesDir + "/test.pdf";
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
// result为createPdf获取的结果
let buffer: Uint8Array = result.pdfArrayBuffer();
fs.write(file.fd, Uint8Array.buffer).then((writeLen: number) => {
  console.info("createPDF write data to file succeed and size is:" + writeLen);
}).catch((err: BusinessError) => {
  console.error("createPDF write data to file failed with error message: " + err.message +
    ", error code: " + err.code);
}).finally(() => {
  fs.closeSync(file);
});
```

## 示例
### 示例1（异步callback方式获取）
通过异步callback的方式调用`createPdf`接口，获取到的result通过`pdfArrayBuffer`接口获取到PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件。
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';


@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }


  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          // 2.触发PDF生成
          this.controller.createPdf(
            this.pdfConfig,
            (error, result: webview.PdfData) => {
              try {
                // 3.保存PDF文件
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  // 关闭file
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            });
        })
      // 1.初始化Web组件
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

### 示例2（Promise方式异步获取）
通过Promise异步的方式调用`createPdf`接口，获取到的result通过`pdfArrayBuffer`接口获取到PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件。
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';


@Entry
@Component
struct Index {
  controller: webview.WebviewController = new webview.WebviewController();
  pdfConfig: webview.PdfConfiguration = {
    width: 8.27,
    height: 11.69,
    marginTop: 0,
    marginBottom: 0,
    marginRight: 0,
    marginLeft: 0,
    shouldPrintBackground: true
  }


  build() {
    Column() {
      Button('SavePDF')
        .onClick(() => {
          // 2.触发PDF生成
          this.controller.createPdf(this.pdfConfig)
            .then((result: webview.PdfData) => {
              try {
                // 3.保存PDF文件
                let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let filePath = context.filesDir + "/test.pdf";
                let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
                fs.write(file.fd, result.pdfArrayBuffer().buffer).then((writeLen: number) => {
                  console.info("createPDF write data to file succeed and size is:" + writeLen);
                }).catch((err: BusinessError) => {
                  console.error("createPDF write data to file failed with error message: " + err.message +
                    ", error code: " + err.code);
                }).finally(() => {
                  // 关闭file
                  fs.closeSync(file);
                });
              } catch (resError) {
                console.error(`ErrorCode: ${(resError as BusinessError).code},  Message: ${(resError as BusinessError).message}`);
              }
            })
        })
      // 1.初始化Web组件
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

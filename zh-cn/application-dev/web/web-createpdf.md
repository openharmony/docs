# 使用Web组件保存前端页面为PDF
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--SE: @handyohos-->
<!--TSE: @ghiker-->

从API version 14开始，支持使用Web组件的[createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14)方法，为应用提供了保存前端页面为PDF的功能。

通过[createPdf](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#createpdf14)生成实例后，调用`pdfArrayBuffer`方法获取二进制数据流，再使用`fileIo`方法将二进制数据流保存为PDF文件。用户可以将前端页面内容保存为PDF以便分享或保存。例如，生成报告、发票等，方便用户保存和传输。

## 需要权限
若涉及网络文档获取，需在module.json5中配置网络访问权限。具体添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```


## callback方式保存PDF
通过callback方式调用`createPdf`接口，获取到的result通过`pdfArrayBuffer`接口取得PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件。
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
          // 触发PDF生成，需要确保页面渲染完成，可使用onPageEnd事件监听
          this.controller.createPdf(
            this.pdfConfig,
            (error, result: webview.PdfData) => {
              try {
                // 获取到的result通过`pdfArrayBuffer`接口取得PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件
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
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```

## Promise方式保存PDF
通过Promise方式调用`createPdf`接口，获取到的result通过`pdfArrayBuffer`接口取得PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件。
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
          // 触发PDF生成，需要确保页面渲染完成，可使用onPageEnd事件监听
          this.controller.createPdf(this.pdfConfig)
            .then((result: webview.PdfData) => {
              try {
                // 获取到的result通过`pdfArrayBuffer`接口取得PDF二进制数据流，最后使用`fileIo`方法将二进制数据流保存为PDF文件
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
      Web({ src: "www.example.com", controller: this.controller })
    }
  }
}
```
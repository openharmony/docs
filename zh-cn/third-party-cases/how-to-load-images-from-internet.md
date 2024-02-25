# 如何请求并加载网络图片

## 场景说明
加载网络图片时，如果直接在Image组件中写入图片的url链接，当网速较慢或者图片较大时，可能导致Image组件加载不出图片。因此，建议使用http接口请求图片数据，等数据返回后通过状态变量实时将图片加载到页面上，这样就能保证图片的渲染。本例将为大家介绍如何实现上述场景。

## 效果呈现
本例效果如下：

![httpforimage](figures/httpforimage.gif)

## 运行环境
- IDE：DevEco Studio 3.1 Beta1
- SDK：Ohos_sdk_public 3.2.11.9 (API Version 9 Release)

## 实现思路
- 使用http请求获取图片数据。
- 通过image.createImageSource()将获取到的数据转化为图片源实例。
- 调用createPixelMap()将图片数据解析为pixelmap。
- 将pixelmap通过状态变量传入Image组件进行渲染显示。

## 开发步骤
1. 申请网络权限。
使用http请求需要先申请网络权限，在module.json5文件中添加以下配置：
    ```json
    "requestPermissions":[
      {
        "name": "ohos.permission.INTERNET",
      },
    ]
    ```
2. 构建UI框架。

    ```ts
    @Entry
    @Component
    struct NetPic {
      // 先创建一个PixelMap状态变量用于接收网络图片数据
      @State image: PixelMap = undefined 
      build() {
        Column({ space: 10 }) {
          Button("获取网络图片")
            .onClick(() => {
              this.httpRequest();
            })
          Image().height(100).width(100)
        }
        .width('100%')
        .height('100%')
        .padding(10)
      }
    }
    ```
3. 先使用http请求获取图片数据，再通过image.createImageSource()将获取到的数据转化为图片源实例，然后调用createPixelMap()将图片数据解析为pixelmap。
    ```ts
    @Entry
    @Component
    struct NetPic {
      // 先创建一个PixelMap状态变量用于接收网络图片
      @State image: PixelMap = undefined 
      // 网络图片请求方法
      httpRequest() { 
        let httpRequest = http.createHttp();
        httpRequest.request(
          //网络图片地址
          "https://images.openharmony.cn/330-%E8%BF%90%E8%90%…%BE/%E6%B4%BB%E5%8A%A8/419/3.2releas-1920-480.jpg", 
          (error, data) => {
            if (error) {
              console.log("error code: " + error.code + ", msg: " + error.message)
            } else {
              let code = data.responseCode
              if (ResponseCode.ResponseCode.OK == code) {
                let res: any = data.result
                //通过获取到的uri创建图片源实例。
                let imageSource = image.createImageSource(res) 
                let options = {
                  // 透明度
                  alphaType: 0, 
                  // 是否可编辑
                  editable: false,
                  // 像素格式
                  pixelFormat: 3, 
                  // 缩略值
                  scaleMode: 1, 
                  // 创建图片大小
                  size: { height: 100, width: 100 }
                } 
                //将图片数据解析为pixelmap，并设置option属性。
                imageSource.createPixelMap(options).then((pixelMap) => { 
                  // 将pixelmap通过状态变量image传递给Image组件，将图片信息加载出来。
                  this.image = pixelMap
                })
              } else {
                console.log("response code: " + code);
              }
            }
          }
        )
      }
      ...
    }
    ```
4. 将状态变量image传递给Image组件，将图片加载出来。
    ```ts
    ...
      build() {
        Column({ space: 10 }) {
          Button("获取网络图片")
            .onClick(() => {
              this.httpRequest();
            })
          // 将状态变量image传递给Image组件，当image获取到图片数据时，可以实时刷新UI
          Image(this.image).height(100).width(100)
        }
        .width('100%')
        .height('100%')
        .padding(10)
      }
    ...
    ```

## 完整代码
本例完整代码如下：
```ts
import http from '@ohos.net.http';
import ResponseCode from '@ohos.net.http';
import image from '@ohos.multimedia.image'

@Entry
@Component
struct NetPic {
  // 先创建一个PixelMap状态变量用于接收网络图片
  @State image: PixelMap = undefined
  // 网络图片请求方法
  httpRequest() {
    let httpRequest = http.createHttp();
    httpRequest.request(
      //网络图片地址
      "https://images.openharmony.cn/330-%E8%BF%90%E8%90%…%BE/%E6%B4%BB%E5%8A%A8/419/3.2releas-1920-480.jpg",
      (error, data) => {
        if (error) {
          console.log("error code: " + error.code + ", msg: " + error.message)
        } else {
          let code = data.responseCode
          if (ResponseCode.ResponseCode.OK == code) {
            let res: any = data.result
            //通过获取到的uri创建图片源实例。
            let imageSource = image.createImageSource(res)
            let options = {
              // 透明度
              alphaType: 0,
              // 是否可编辑
              editable: false,
              // 像素格式
              pixelFormat: 3,
              // 缩略值
              scaleMode: 1,
              // 创建图片大小
              size: { height: 100, width: 100 }
            }
            //将图片数据解析为pixelmap，并设置option属性。
            imageSource.createPixelMap(options).then((pixelMap) => {
              // 将pixelmap通过状态变量image传递给Image组件，将图片信息加载出来。
              this.image = pixelMap
            })
          } else {
            console.log("response code: " + code);
          }
        }
      }
    )
  }

  build() {
    Column({ space: 10 }) {
      Button("获取网络图片")
        .onClick(() => {
          this.httpRequest();
        })
      // 将状态变量image传递给Image组件，当image获取到图片数据时，可以实时刷新UI
      Image(this.image).height(100).width(100)
    }
    .width('100%')
    .height('100%')
    .padding(10)
  }
}
```

## 参考
- [图片处理](../application-dev/reference/apis-image-kit/js-apis-image.md)

- [数据请求](../application-dev/reference/apis-network-kit/js-apis-http.md)

- [权限申请指导](../application-dev/security/AccessToken/declare-permissions.md)
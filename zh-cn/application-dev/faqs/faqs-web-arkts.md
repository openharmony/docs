# ArkUI Web组件（ArkTS）开发常见问题

## Web组件domStorageAccess属性设置

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

设置是否开启文档对象模型存储接口（DOM Storage API）权限，默认未开启，控制web网页中localStorage的使用，对sessionStorage未做控制


## Web组件加载的html页面内如何检测网络状态

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

1. 配置应用权限：ohos.permission.INTERNET 、 ohos.permission.GET_NETWORK_INFO

2. html中通过window.navigator.onLine获取网络状态

## Web组件加载h5页面，首次加载无法设置拼接UserAgent参数

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

默认UserAgent通过WebController获取。一个WebController对象只能控制一个Web组件，且必须在Web组件和WebController绑定后，才能调用WebController上的方法，因此在初次加载前设置默认UserAgent + 自定义字符串拼接，可采用此方式：

1. 使用\@State定义初始userAgent，绑定到Web组件；

2. 在web组件的onUrlLoadIntercept回调中，通过WebController获取默认userAgent，修改Web组件绑定的userAgent。
   参考代码如下：

     
   ```
   @Entry
   @Component
   struct Index {
     private controller: WebController = new WebController()
     @State userAgentPa: string = ''
     build() {
       Row() {
         Column() {
           Web({ src: 'www.example.com', controller: this.controller })
             .width('100%')
             .userAgent(this.userAgentPa)
             .onUrlLoadIntercept((event) => {
               let userAgent = this.controller.getDefaultUserAgent();
               this.userAgentPa = userAgent + ' 111111111'
               console.log("userAgent onUrlLoadIntercept: " + userAgent);
               return false;
             })
         }
         .width('100%').alignItems(HorizontalAlign.Start).backgroundColor(Color.Green)
       }
       .height('100%')
     }
   }
   ```

## 加载Lottie动画的逻辑应该写在onAppear函数中还是应该写在onReady函数中

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

onAppear方法只是定位完Canvas的位置，onReady方法才是测量完成，加载动画的逻辑应该写在onReady函数中。

## 调用deleteJavaScriptRegister后是否需要调用refresh接口

适用于：所有版本

不需要。

## 页面如何传递数据给Web组件

适用于：OpenHarmony SDK 3.2.7.5版本，API9 Stage模型

1. 使用WebController创建两个消息端口。

2. 将消息端口1发送到HTML侧，由HTML侧保存并使用。

3. 将消息端口0在应用侧注册回调事件。

4. 使用应用侧的端口0给HTML侧消息端口1发送消息。

使用参考：[Web组件](../reference/arkui-ts/ts-basic-components-web.md#postmessage9)

<!--no_check-->
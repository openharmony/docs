# Web组件支持画中画
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @gzweioh-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
Web组件提供画中画功能支持，应用可利用W3C标准的Picture-in-Picture API在网页中创建浮动窗口以播放视频，使用户在浏览其他网页或与其他应用交互时，可通过该画中画窗口继续观看视频。  

若使用线上视频资源，则需在配置文件中设置网络权限。权限的添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

```json
// src/main/module.json5
"requestPermissions": [
  {
    "name": "ohos.permission.INTERNET"
  },
]
```

## 约束与限制
1. 当前H264/H265/HLS格式的视频可在创建的画中画窗口中播放。  
2. 画中画窗口的大小调整依据系统能力，具体参照设计指南中的系统特性与能力部分。

## 进入画中画

以仅包含媒体源的video元素和一个用户交互的button元素为例，介绍如何创建一个浮动窗口播放视频，使用户在浏览其他网页或与其他应用交互时，能够通过该画中画窗口持续观看视频。

```html
<!-- 使用时需要自行替换视频链接 -->
<video id="video" src="https://example.com/file.mp4" controls></video>
<button id="togglePipButton">开启画中画</button>
```

HTMLVideoElement接口提供的requestPictureInPicture()方法请求启动画中画，如果系统支持画中画能力，则会以画中画模式显示视频。

```js
togglePipButton.addEventListener("click", async () => {
  try {
    // 请求进入画中画模式
    await video.requestPictureInPicture();
  } catch (err) {
    // 如果画中画模式切换失败，打印错误信息
    console.error("Picture-in-Picture mode failed:", err);
  }
});
```

## 退出画中画

请求退出画中画模式，请使用Document接口的exitPictureInPicture()方法，视频将重新在原始标签页中显示。

```js
// ...
try {
  if (videoElement !== document.pictureInPictureElement) {
    await videoElement.requestPictureInPicture();
  } else {
    await document.exitPictureInPicture();
  }
}
// ...
```

## 监听画中画事件

当用户启动画中画模式播放视频时，会显示一个悬浮窗口用于播放视频。系统规定每次只能播放一个画中画视频。
HTMLVideoElement的enterpictureinpicture事件在HTMLVideoElement成功进入画中画模式时触发，而HTMLVideoElement的leavepictureinpicture事件在HTMLVideoElement成功退出画中画模式时触发。
在监听到这些事件变化时，开发者可以进行相应的处理。


```js
videoElement.addEventListener('enterpictureinpicture', function (event) {
// 视频进入画中画模式。
});

videoElement.addEventListener('leavepictureinpicture', function (event) {
// 视频退出画中画模式。
});
```

## 画中画窗口交互

* 画中画整体窗口控制：  
  支持双击画中画窗口控制放大或缩小窗口尺寸；  
  支持拖拽画中画窗口到屏幕任意位置；  
  支持单击画中画窗口控制画中画控制层UI控件的显示与隐藏。  

* 画中画控制层UI控件：  
  画中画窗口控制层包含“关闭”（关闭画中画窗口）、“恢复”（从画中画窗口恢复到原应用界面）；  
  播放控制包含暂停，播放，前进/后退（默认显示前进/后退UI控件，若原视频不支持前进后退，点击无响应）。
  
  ![web-picture-in-picture](figures/web-picture-in-picture-ui.png)


## 完整示例

支持启动/退出画中画的完整示例如下：

* 应用侧ets代码。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct Index {
    @State videoSrc: Resource = $rawfile('PictureInPicture.html');
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({src: this.videoSrc, controller: this.controller})
      }
    }
  }
  ```

* 前端页面html代码。

  ```html
  <!-- PictureInPicture.html -->
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1.0" />
      <title>Picture-in-Picture Demo</title>
      <style>
          body {
            font-family: Arial, sans-serif;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            margin: 0;
          }
          video {
            width: 60%;
            border: 1px solid #ccc;
            border-radius: 8px;
            margin-bottom: 20px;
          }
          button {
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
          }
      </style>
  </head>
  <body>
  <!-- 使用时需要自行替换视频链接 -->
  <video id="video" src="https://example.com/file.mp4" controls></video>
  <button id="togglePipButton">开启画中画</button>

  <script>
      const video = document.getElementById("video");
      const togglePipButton = document.getElementById("togglePipButton");

      // 如果浏览器不支持画中画功能或被禁用，则隐藏按钮
      togglePipButton.hidden =
        !document.pictureInPictureEnabled || video.disablePictureInPicture;

      // 监听按钮点击事件，切换画中画模式
      togglePipButton.addEventListener("click", async () => {
        try {
          if (document.pictureInPictureElement) {
            // 如果当前处于画中画模式，退出画中画
            await document.exitPictureInPicture();
          } else {
            // 否则，进入画中画模式
            await video.requestPictureInPicture();
          }
        } catch (err) {
          // 如果画中画模式切换失败，打印错误信息
          console.error("Picture-in-Picture mode failed:", err);
        }
      });

      // 监听进入画中画事件
      video.addEventListener("enterpictureinpicture", () => {
        // 更新按钮文本为“退出画中画”
        togglePipButton.textContent = "退出画中画";
      });

      // 监听退出画中画事件
      video.addEventListener("leavepictureinpicture", () => {
        // 更新按钮文本为“开启画中画”
        togglePipButton.textContent = "开启画中画";
      });
  </script>
  </body>
  </html>
  ```

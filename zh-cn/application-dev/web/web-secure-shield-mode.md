# 坚盾守护模式

坚盾守护模式是<!--RP1--><!--RP1End-->提供给高安全需求用户的系统级别安全模式。该模式通过限制设备基础功能，增强安全性，有效抵御远程攻击面的针对性攻击。

## ArkWeb限制的HTML5特性

坚盾守护模式开启时，ArkWeb通过限制以下HTML5特性减少攻击面。

- 禁止使用WebAssembly能力。

- 禁止使用WebGL、WebGL2能力。

- 禁止使用PDF Viewer预览功能。

- 禁止使用MathML能力。

- 禁止使用Web Speech API语音识别能力。

- 禁止使用RTCDataChannel接口。

- 禁止使用MediaDevices.getUserMedia接口提示用户允许访问媒体输入设备。

- 禁止使用Service Worker能力。

- 禁止使用非代理UDP流量，防止WebRTC泄露真实源ip。

- 禁止即时编译（JIT）能力。

## 评估对应用的影响

如果要评估应用在坚盾守护模式下的受影响程度及兼容性，可前往“设置 > 隐私和安全 > 坚盾守护模式”开启该模式。

<!--RP2--><!--RP2End-->

> **说明：**
>
> 如果需要评估调试版本（未上架应用市场）应用的兼容性，需要先开启开发者选项后再开启坚盾守护模式。

运行应用的相应功能后，可通过以下方式确认是否受影响。

- 排查前端代码是否存在WebAssembly相关接口调用，WebAssembly提供了一种在Web上运行C/C++等低级语言编译目标的能力，通常用于游戏、编解码等高性能场景。坚盾守护模式下，无法调用WebAssembly。

- 排查前端代码是否存在WebGL相关接口调用，WebGL提供了3D图形绘制能力，坚盾守护模式下，相关接口无法调用。

- 排查是否有在线显示PDF的功能场景，坚盾守护模式开启下无法在线显示PDF，例如通过loadUrl接口加载pdf链接等场景。

- 排查HTML页面是否存在\<math>标签嵌入的MathML语法，坚盾守护模式下，MathML语法不能正常解析，导致显示异常。

- 排查前端代码是否存在SpeechRecognition（语言识别）、SpeechSynthesis（语音合成）等接口调用，坚盾守护模式下，相关接口无法调用。

- 排查前端代码是否存在RTCDataChannel/createDataChannel等接口调用，该类接口是WebRTC API的特性，可以建立一条双向数据通道的连接，实现WebRTC 中对等端之间的实时数据交换，坚盾守护模式下，相关接口无法调用。

- 排查前端代码是否存在MediaDevices.getUserMedia接口调用，该接口用于向用户请求访问流媒体设备（例如：摄像头、麦克风），坚盾守护模式下，相关接口调用会抛出异常信息“can't use getUserMedia on advancedSecurityMode!”。

- 排查前端代码是否存在ServiceWorker相关接口调用，该机制用于实现离线缓存、网络请求拦截和推送通知等功能，坚盾守护模式下无法创建成功。

- 坚盾守护模式下WebRTC禁止使用非代理UDP传输，涉及到网络连通性，应用需要验证评估WebRTC场景下的网络功能和性能表现。

- JIT涉及性能优化，坚盾守护模式下应用需要评估JS性能表现。
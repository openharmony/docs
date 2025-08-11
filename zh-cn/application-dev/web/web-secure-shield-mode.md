# 坚盾守护模式
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @weixin_41848015-->
<!--SE: @libing23232323-->
<!--TSE: @ghiker-->

坚盾守护模式提供给高安全需求用户的系统级别安全模式。该模式通过限制设备基础功能，增强安全性，有效抵御远程攻击面的针对性攻击。

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

要评估应用在坚盾守护模式下的受影响程度及兼容性，可前往“设置 > 隐私和安全 > 坚盾守护模式”开启。

<!--RP2--><!--RP2End-->

> **说明：**
>
> - 如果需要评估调试版本（未上架应用市场）应用的兼容性，先开启开发者选项，然后开启坚盾守护模式。
> - 可以采用Device Security Kit提供的<!--RP1-->查询设备安全模式(C/C++)能力<!--RP1End-->，判断坚盾守护模式是否开启。

运行应用的相应功能后，可通过以下方式确认是否受影响：

- 排查前端代码是否存在WebAssembly相关接口调用，WebAssembly用于在Web上运行C/C++等低级语言编译代码，坚盾守护模式下无法调用。

- 排查前端代码是否存在WebGL相关接口调用，WebGL提供3D图形绘制能力。在坚盾守护模式下，相关接口无法调用。

- 排查是否有在线显示PDF的功能场景，坚盾守护模式下无法在线显示PDF，例如通过loadUrl加载PDF链接。

- 排查HTML页面是否存在\<math>标签嵌入的MathML语法，坚盾守护模式下，MathML语法无法解析，导致显示异常。

- 排查前端代码是否存在SpeechRecognition（语音识别）、SpeechSynthesis（语音合成）等接口调用，坚盾守护模式下，相关接口无法调用。

- 排查前端代码是否存在RTCDataChannel/createDataChannel等接口调用，该类接口属于WebRTC API，用于建立双向数据通道，实现对等端之间的实时数据交换。坚盾守护模式下，相关接口无法调用。

- 排查前端代码是否存在MediaDevices.getUserMedia接口调用，该接口用于请求访问流媒体设备，如摄像头和麦克风。在坚盾守护模式下，相关接口调用会抛出异常：“can't use getUserMedia on advancedSecurityMode!”

- 排查前端代码是否存在ServiceWorker相关接口调用，该机制实现离线缓存、网络请求拦截和推送通知等功能，在坚盾守护模式下无法创建。

- 在坚盾守护模式下，WebRTC禁止使用非代理UDP传输。应用需验证WebRTC场景下的网络功能和性能。

- 坚盾守护模式下应用需评估JS性能。
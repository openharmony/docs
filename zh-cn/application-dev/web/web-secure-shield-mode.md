# 坚盾守护模式

坚盾守护模式是针对特定高风险用户的整机安全模式，通过限制设备的基本功能，提供更高的安全性，防止针对性的网络攻击。ArkWeb在坚盾守护模式开启时，通过限制HTML5特性减少攻击面。


具体限制特性如下：

1、禁止使用WebAssembly能力。

2、禁止使用WebGL、WebGL2能力。

3、禁止使用PDF viewer预览功能。

4、禁止使用MathML能力。

5、禁止使用Web speech api语音识别能力。

6、禁止使用RTCDataChannel接口。

7、禁止使用MediaDevices.getUserMedia接口。

8、禁止使用service worker能力。

9、禁止使用非代理udp流量，防止webRTC泄露真实源ip。

10、禁止即时编译(JIT)能力。

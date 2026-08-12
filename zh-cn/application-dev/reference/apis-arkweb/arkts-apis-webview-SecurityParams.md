# Class (SecurityParams)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhushengle-->
<!--Designer: @yyyiye-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

安全特性选项配置。该类提供了一组布尔开关，用于控制 ArkWeb 内核中特定 Web 功能的启用状态。通过关闭业务非必需的高风险模块（如 JIT编译、WebAssembly、WebGL 等），可减小攻击面、降低潜在漏洞利用风险。所有属性均为可选，默认 false（不禁用），请根据具体业务场景按需配置。

> **说明：**
>
> 示例效果请以真机运行为准。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## 属性

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| disableJITCompilation | boolean | 否 | 是 | 是否禁用JIT编译。true表示禁用，false表示不禁用。默认值：false。<br>JIT编译是一种将程序代码在运行时动态编译为机器码的技术，V8引擎为了提升代码执行性能，会将热点代码编译为机器码。绝大多数浏览器漏洞（如Type Confusion）都是通过操纵JIT优化过程实现的。禁用后不影响网页功能，对于复杂JS代码性能下降17%左右。建议有条件禁用该特性，对于纯展示类、非计算密集型页面（例如新闻、文档）建议禁用。 |
| disableWebAssembly | boolean | 否 | 是 | 是否禁用WebAssembly。true表示禁用，false表示不禁用。默认值：false。<br>WebAssembly（简称WASM）是一种可移植的二进制指令格式，允许C/C++/Rust等语言编写的代码在浏览器中以接近原生性能运行。编译后的机器码在WASM虚拟机中执行，而WASM容易存在内存安全漏洞。建议根据页面类型决定是否禁用。对于纯展示类、非计算密集型页面（例如新闻、文档）建议禁用；对于依赖视频编解码、复杂加密的网页不建议禁用，禁用后可能影响依赖视频编解码、复杂加密的网页功能。 |
| disableWebGL | boolean | 否 | 是 | 是否禁用WebGL。true表示禁用，false表示不禁用。默认值：false。<br>WebGL允许JavaScript直接调用GPU驱动进行渲染，攻击者可能利用底层驱动漏洞实现沙箱逃逸或远程代码执行，同时WebGL也可能被应用于用户指纹识别攻击。禁用后无法进行3D渲染，部分2D画布退回到CPU渲染，可能帧率下降。金融支付类、即时通讯、政务系统等敏感业务建议禁用。 |
| disablePDFViewer | boolean | 否 | 是 | 是否禁用PDF查看器。true表示禁用，false表示不禁用。默认值：false。<br>内置PDF解析引擎在解析复杂二进制格式和嵌入式脚本时容易存在漏洞，攻击者可构造特殊PDF文件利用字体解析或内存破坏漏洞控制应用主进程。禁用后无法在ArkWeb中加载PDF。非文档办公类App建议禁用，引导用户使用外部应用打开PDF。 |
| disableMathML | boolean | 否 | 是 | 是否禁用MathML。true表示禁用，false表示不禁用。默认值：false。<br>MathML是内核中一个相对陈旧的渲染模块，往往缺乏足够的自动化审计和模糊测试，容易成为侧信道攻击或属性注入跨站脚本攻击（Cross-Site Scripting，XSS）的跳板。建议禁用，禁用后`<math>`标签内容将无法正确解析展示，可能影响极少数未进行JS适配的科学网站公式排版。 |
| disableServiceWorker | boolean | 否 | 是 | 是否禁用Service Worker。true表示禁用，false表示不禁用。默认值：false。<br>Service Worker具有持久化控制权，可在Web页面后台常驻并拦截网络请求。若网页存在XSS漏洞，攻击者可利用其安装恶意Service Worker实施中间人攻击。禁用后失去离线访问功能、Web消息推送无法使用、失去预加载能力。银行、证券等对会话新鲜度要求极高的行业建议禁用。 |
| disableNonProxyUDP | boolean | 否 | 是 | 是否禁用WebRTC非代理UDP。true表示禁用，false表示不禁用。默认值：false。<br>WebRTC开启时可能导致恶意流量绕过代理通道，暴露用户的真实物理IP地址，造成隐私泄露。禁用后强制所有流量走TCP代理会增加延迟，视频通话、实时对讲等功能可能无法建立连接。匿名社交、出海业务、强制代理等场景建议禁用。 |

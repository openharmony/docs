# 日志打印<a name="ZH-CN_TOPIC_0000001163932220"></a>

-   [导入模块](#zh-cn_topic_0000001127284842_s56d19203690d4782bfc74069abb6bd71)
-   [权限列表](#zh-cn_topic_0000001127284842_section11257113618419)
-   [console.debug](#zh-cn_topic_0000001127284842_s298a3cf59a3b470dbb0742706102ced7)
-   [console.log](#zh-cn_topic_0000001127284842_section146351482051)
-   [console.info](#zh-cn_topic_0000001127284842_section93434457711)
-   [console.warn](#zh-cn_topic_0000001127284842_section1363520541678)
-   [console.error](#zh-cn_topic_0000001127284842_section326012551578)
-   [示例](#zh-cn_topic_0000001127284842_section738673813104)

## 导入模块<a name="zh-cn_topic_0000001127284842_s56d19203690d4782bfc74069abb6bd71"></a>

无需导入。

## 权限列表<a name="zh-cn_topic_0000001127284842_section11257113618419"></a>

无

## console.debug<a name="zh-cn_topic_0000001127284842_s298a3cf59a3b470dbb0742706102ced7"></a>

debug\(message: string\): void

打印debug级别的日志信息。

-   参数

    <a name="zh-cn_topic_0000001127284842_t87748b0ba4e648079d53f9deccf4bfb2"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284842_rc5033ad045c14c2e806d59041aab002c"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127284842_acf783ab6043e4ee1a7bb73b73a091e0b"><a name="zh-cn_topic_0000001127284842_acf783ab6043e4ee1a7bb73b73a091e0b"></a><a name="zh-cn_topic_0000001127284842_acf783ab6043e4ee1a7bb73b73a091e0b"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127284842_a6736505551534b819d5a6376065a25f6"><a name="zh-cn_topic_0000001127284842_a6736505551534b819d5a6376065a25f6"></a><a name="zh-cn_topic_0000001127284842_a6736505551534b819d5a6376065a25f6"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127284842_ac15c2a3de0e046af917cf09b48b3b46d"><a name="zh-cn_topic_0000001127284842_ac15c2a3de0e046af917cf09b48b3b46d"></a><a name="zh-cn_topic_0000001127284842_ac15c2a3de0e046af917cf09b48b3b46d"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127284842_aeb94b88e78974288bab1b4940b50c840"><a name="zh-cn_topic_0000001127284842_aeb94b88e78974288bab1b4940b50c840"></a><a name="zh-cn_topic_0000001127284842_aeb94b88e78974288bab1b4940b50c840"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284842_r95c56d5cd62d4b518c3e7a3f158ed7fe"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127284842_a7af41aec9a404f418202d90c61774825"><a name="zh-cn_topic_0000001127284842_a7af41aec9a404f418202d90c61774825"></a><a name="zh-cn_topic_0000001127284842_a7af41aec9a404f418202d90c61774825"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127284842_aed6ae868d61349afa8f0e250108f8e47"><a name="zh-cn_topic_0000001127284842_aed6ae868d61349afa8f0e250108f8e47"></a><a name="zh-cn_topic_0000001127284842_aed6ae868d61349afa8f0e250108f8e47"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127284842_ab72ac8cc02e34da4b717ca144fc521c1"><a name="zh-cn_topic_0000001127284842_ab72ac8cc02e34da4b717ca144fc521c1"></a><a name="zh-cn_topic_0000001127284842_ab72ac8cc02e34da4b717ca144fc521c1"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127284842_ac53e6549d32f413e9c51cd8a53f4650a"><a name="zh-cn_topic_0000001127284842_ac53e6549d32f413e9c51cd8a53f4650a"></a><a name="zh-cn_topic_0000001127284842_ac53e6549d32f413e9c51cd8a53f4650a"></a>表示要打印的文本信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


## console.log<a name="zh-cn_topic_0000001127284842_section146351482051"></a>

log\(message: string\): void

打印log级别的日志信息。

-   参数

    <a name="zh-cn_topic_0000001127284842_table1852992312613"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284842_row953019231468"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127284842_p353020231164"><a name="zh-cn_topic_0000001127284842_p353020231164"></a><a name="zh-cn_topic_0000001127284842_p353020231164"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127284842_p15301423361"><a name="zh-cn_topic_0000001127284842_p15301423361"></a><a name="zh-cn_topic_0000001127284842_p15301423361"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127284842_p853022316618"><a name="zh-cn_topic_0000001127284842_p853022316618"></a><a name="zh-cn_topic_0000001127284842_p853022316618"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127284842_p1953072310614"><a name="zh-cn_topic_0000001127284842_p1953072310614"></a><a name="zh-cn_topic_0000001127284842_p1953072310614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284842_row6530823560"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127284842_p135301231364"><a name="zh-cn_topic_0000001127284842_p135301231364"></a><a name="zh-cn_topic_0000001127284842_p135301231364"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127284842_p15530523265"><a name="zh-cn_topic_0000001127284842_p15530523265"></a><a name="zh-cn_topic_0000001127284842_p15530523265"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127284842_p165301323567"><a name="zh-cn_topic_0000001127284842_p165301323567"></a><a name="zh-cn_topic_0000001127284842_p165301323567"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127284842_p853019231265"><a name="zh-cn_topic_0000001127284842_p853019231265"></a><a name="zh-cn_topic_0000001127284842_p853019231265"></a>表示要打印的文本信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >console.log\(\)打印的是debug级别日志信息。


## console.info<a name="zh-cn_topic_0000001127284842_section93434457711"></a>

info\(message: string\): void

打印info级别的日志信息。

-   参数

    <a name="zh-cn_topic_0000001127284842_table611782915816"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284842_row1211714291989"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127284842_p41174291587"><a name="zh-cn_topic_0000001127284842_p41174291587"></a><a name="zh-cn_topic_0000001127284842_p41174291587"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127284842_p711715295817"><a name="zh-cn_topic_0000001127284842_p711715295817"></a><a name="zh-cn_topic_0000001127284842_p711715295817"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127284842_p101171729289"><a name="zh-cn_topic_0000001127284842_p101171729289"></a><a name="zh-cn_topic_0000001127284842_p101171729289"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127284842_p17117162911815"><a name="zh-cn_topic_0000001127284842_p17117162911815"></a><a name="zh-cn_topic_0000001127284842_p17117162911815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284842_row411762913814"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127284842_p111178291284"><a name="zh-cn_topic_0000001127284842_p111178291284"></a><a name="zh-cn_topic_0000001127284842_p111178291284"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127284842_p91181929284"><a name="zh-cn_topic_0000001127284842_p91181929284"></a><a name="zh-cn_topic_0000001127284842_p91181929284"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127284842_p12118152919810"><a name="zh-cn_topic_0000001127284842_p12118152919810"></a><a name="zh-cn_topic_0000001127284842_p12118152919810"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127284842_p18118112910811"><a name="zh-cn_topic_0000001127284842_p18118112910811"></a><a name="zh-cn_topic_0000001127284842_p18118112910811"></a>表示要打印的文本信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


## console.warn<a name="zh-cn_topic_0000001127284842_section1363520541678"></a>

warn\(message: string\): void

打印warn级别的日志信息。

-   参数

    <a name="zh-cn_topic_0000001127284842_table2396103815819"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284842_row13396183810811"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127284842_p3396153815820"><a name="zh-cn_topic_0000001127284842_p3396153815820"></a><a name="zh-cn_topic_0000001127284842_p3396153815820"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127284842_p13964389819"><a name="zh-cn_topic_0000001127284842_p13964389819"></a><a name="zh-cn_topic_0000001127284842_p13964389819"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127284842_p53961138987"><a name="zh-cn_topic_0000001127284842_p53961138987"></a><a name="zh-cn_topic_0000001127284842_p53961138987"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127284842_p0396238787"><a name="zh-cn_topic_0000001127284842_p0396238787"></a><a name="zh-cn_topic_0000001127284842_p0396238787"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284842_row9396163811811"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127284842_p33966385817"><a name="zh-cn_topic_0000001127284842_p33966385817"></a><a name="zh-cn_topic_0000001127284842_p33966385817"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127284842_p639610381280"><a name="zh-cn_topic_0000001127284842_p639610381280"></a><a name="zh-cn_topic_0000001127284842_p639610381280"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127284842_p0396183816816"><a name="zh-cn_topic_0000001127284842_p0396183816816"></a><a name="zh-cn_topic_0000001127284842_p0396183816816"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127284842_p039613818815"><a name="zh-cn_topic_0000001127284842_p039613818815"></a><a name="zh-cn_topic_0000001127284842_p039613818815"></a>表示要打印的文本信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


## console.error<a name="zh-cn_topic_0000001127284842_section326012551578"></a>

error\(message: string\): void

打印error级别的日志信息。

-   参数

    <a name="zh-cn_topic_0000001127284842_table79914568813"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284842_row899656288"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127284842_p39911567816"><a name="zh-cn_topic_0000001127284842_p39911567816"></a><a name="zh-cn_topic_0000001127284842_p39911567816"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127284842_p099156388"><a name="zh-cn_topic_0000001127284842_p099156388"></a><a name="zh-cn_topic_0000001127284842_p099156388"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127284842_p3992564819"><a name="zh-cn_topic_0000001127284842_p3992564819"></a><a name="zh-cn_topic_0000001127284842_p3992564819"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127284842_p89920561088"><a name="zh-cn_topic_0000001127284842_p89920561088"></a><a name="zh-cn_topic_0000001127284842_p89920561088"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284842_row799956389"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127284842_p699105614811"><a name="zh-cn_topic_0000001127284842_p699105614811"></a><a name="zh-cn_topic_0000001127284842_p699105614811"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127284842_p99925618816"><a name="zh-cn_topic_0000001127284842_p99925618816"></a><a name="zh-cn_topic_0000001127284842_p99925618816"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127284842_p189916561082"><a name="zh-cn_topic_0000001127284842_p189916561082"></a><a name="zh-cn_topic_0000001127284842_p189916561082"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127284842_p799195610812"><a name="zh-cn_topic_0000001127284842_p799195610812"></a><a name="zh-cn_topic_0000001127284842_p799195610812"></a>表示要打印的文本信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="zh-cn_topic_0000001127284842_section738673813104"></a>

```
var versionCode = 1;
console.info('Hello World. The current version code is ' + versionCode);
console.log(`versionCode: ${versionCode}`)
console.log('versionCode:%d.', versionCode);6+
```

在DevEco Studio的底部，切换到“HiLog”窗口。选择当前的设备及进程，日志级别选择Info，搜索内容设置为“Hello World”。此时窗口仅显示符合条件的日志，效果如图所示：

![](figures/打印日志.png)


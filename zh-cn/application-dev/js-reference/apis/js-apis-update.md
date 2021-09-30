# 系统恢复<a name="ZH-CN_TOPIC_0000001164895648"></a>

-   [导入模块](#zh-cn_topic_0000001163565327_section370mcpsimp)
-   [权限列表](#zh-cn_topic_0000001163565327_section373mcpsimp)
-   [方法](#zh-cn_topic_0000001163565327_section1319529172015)
-   [verifyUpdatePackage\(upgradeFile: string, certsFile: string\): void](#zh-cn_topic_0000001163565327_section16874643181519)
-   [rebootAndCleanUserData\(\): Promise<number\>](#zh-cn_topic_0000001163565327_section3242122116516)
-   [rebootAndCleanUserData\(callback: AsyncCallback<number\>\): void](#zh-cn_topic_0000001163565327_section15242102114516)
-   [applyNewVersion\(\): Promise<number\>](#zh-cn_topic_0000001163565327_section129661811195815)
-   [applyNewVersion\(callback: AsyncCallback<number\>\): void](#zh-cn_topic_0000001163565327_section3381192816421)

## 导入模块<a name="zh-cn_topic_0000001163565327_section370mcpsimp"></a>

```
import update from '@ohos.update'
```

## 权限列表<a name="zh-cn_topic_0000001163565327_section373mcpsimp"></a>

无

## 方法<a name="zh-cn_topic_0000001163565327_section1319529172015"></a>

## verifyUpdatePackage\(upgradeFile: string, certsFile: string\): void<a name="zh-cn_topic_0000001163565327_section16874643181519"></a>

升级前检查升级包是否有效。

**参数：**

<a name="zh-cn_topic_0000001163565327_table1987419434154"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163565327_row16875643191511"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163565327_p12875843191519"><a name="zh-cn_topic_0000001163565327_p12875843191519"></a><a name="zh-cn_topic_0000001163565327_p12875843191519"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163565327_p12875194316156"><a name="zh-cn_topic_0000001163565327_p12875194316156"></a><a name="zh-cn_topic_0000001163565327_p12875194316156"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163565327_p12875104312152"><a name="zh-cn_topic_0000001163565327_p12875104312152"></a><a name="zh-cn_topic_0000001163565327_p12875104312152"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163565327_p98751743161513"><a name="zh-cn_topic_0000001163565327_p98751743161513"></a><a name="zh-cn_topic_0000001163565327_p98751743161513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163565327_row19875144311510"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163565327_p17883191212014"><a name="zh-cn_topic_0000001163565327_p17883191212014"></a><a name="zh-cn_topic_0000001163565327_p17883191212014"></a>upgradeFile</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163565327_p0875164318155"><a name="zh-cn_topic_0000001163565327_p0875164318155"></a><a name="zh-cn_topic_0000001163565327_p0875164318155"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163565327_p108751043141517"><a name="zh-cn_topic_0000001163565327_p108751043141517"></a><a name="zh-cn_topic_0000001163565327_p108751043141517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163565327_p1987519439152"><a name="zh-cn_topic_0000001163565327_p1987519439152"></a><a name="zh-cn_topic_0000001163565327_p1987519439152"></a>待校验的升级包路径</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163565327_row194175815171"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163565327_p20957580177"><a name="zh-cn_topic_0000001163565327_p20957580177"></a><a name="zh-cn_topic_0000001163565327_p20957580177"></a>certsFile</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163565327_p1895158171714"><a name="zh-cn_topic_0000001163565327_p1895158171714"></a><a name="zh-cn_topic_0000001163565327_p1895158171714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163565327_p395125851716"><a name="zh-cn_topic_0000001163565327_p395125851716"></a><a name="zh-cn_topic_0000001163565327_p395125851716"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163565327_p129545811714"><a name="zh-cn_topic_0000001163565327_p129545811714"></a><a name="zh-cn_topic_0000001163565327_p129545811714"></a>证书路径</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
var getVar = update.getUpdater();
getVar.on("verifyProgress", function (callback){
    console.info('on verifyProgress ' + callback.percent);
});
getVar.verifyUpdatePackage("XXX", "XXX");
getVar.off("verifyProgress");
```

## rebootAndCleanUserData\(\): Promise<number\><a name="zh-cn_topic_0000001163565327_section3242122116516"></a>

重启设备并清除用户分区数据。

**参数：**

无

**返回值：**

<a name="zh-cn_topic_0000001163565327_table9242921652"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163565327_row724232113519"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163565327_p1224210211454"><a name="zh-cn_topic_0000001163565327_p1224210211454"></a><a name="zh-cn_topic_0000001163565327_p1224210211454"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163565327_p1924210213517"><a name="zh-cn_topic_0000001163565327_p1924210213517"></a><a name="zh-cn_topic_0000001163565327_p1924210213517"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163565327_row6242521053"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163565327_p8242162115510"><a name="zh-cn_topic_0000001163565327_p8242162115510"></a><a name="zh-cn_topic_0000001163565327_p8242162115510"></a>Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163565327_p6242021157"><a name="zh-cn_topic_0000001163565327_p6242021157"></a><a name="zh-cn_topic_0000001163565327_p6242021157"></a>Promise示例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var getVar = update.getUpdater();
p = getVar.rebootAndCleanUserData();
p.then(function (value) {
    console.info("rebootAndCleanUserData promise success: " + value);
}).catch(function (err) {
    console.info("rebootAndCleanUserData promise error: " + err.code);
});
```

## rebootAndCleanUserData\(callback: AsyncCallback<number\>\): void<a name="zh-cn_topic_0000001163565327_section15242102114516"></a>

重启设备并清除用户分区数据。

**参数：**

<a name="zh-cn_topic_0000001163565327_table62421211154"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163565327_row92426211952"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163565327_p124342114519"><a name="zh-cn_topic_0000001163565327_p124342114519"></a><a name="zh-cn_topic_0000001163565327_p124342114519"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163565327_p524315218516"><a name="zh-cn_topic_0000001163565327_p524315218516"></a><a name="zh-cn_topic_0000001163565327_p524315218516"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163565327_p122436211858"><a name="zh-cn_topic_0000001163565327_p122436211858"></a><a name="zh-cn_topic_0000001163565327_p122436211858"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163565327_p1243172118512"><a name="zh-cn_topic_0000001163565327_p1243172118512"></a><a name="zh-cn_topic_0000001163565327_p1243172118512"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163565327_row8243122114510"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163565327_p152435211151"><a name="zh-cn_topic_0000001163565327_p152435211151"></a><a name="zh-cn_topic_0000001163565327_p152435211151"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163565327_p024372115516"><a name="zh-cn_topic_0000001163565327_p024372115516"></a><a name="zh-cn_topic_0000001163565327_p024372115516"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163565327_p1724312217510"><a name="zh-cn_topic_0000001163565327_p1724312217510"></a><a name="zh-cn_topic_0000001163565327_p1724312217510"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163565327_p22435211855"><a name="zh-cn_topic_0000001163565327_p22435211855"></a><a name="zh-cn_topic_0000001163565327_p22435211855"></a>AsyncCallback&lt;number&gt;</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
var getVar = update.getUpdater();
getVar.rebootAndCleanUserData(function (err, data) {
    if (err.code == 0) {
        console.info("rebootAndCleanUserData callback success:" + data)
    } else {
        console.info("rebootAndCleanUserData callback err:" + err.code)
    }
});
```

## applyNewVersion\(\): Promise<number\><a name="zh-cn_topic_0000001163565327_section129661811195815"></a>

重启设备后安装升级包。

**参数：**

无

**返回值：**

<a name="zh-cn_topic_0000001163565327_table14773154913191"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163565327_row877314991912"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163565327_p1077313493199"><a name="zh-cn_topic_0000001163565327_p1077313493199"></a><a name="zh-cn_topic_0000001163565327_p1077313493199"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163565327_p1677411498195"><a name="zh-cn_topic_0000001163565327_p1677411498195"></a><a name="zh-cn_topic_0000001163565327_p1677411498195"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163565327_row1977413496194"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163565327_p67742498197"><a name="zh-cn_topic_0000001163565327_p67742498197"></a><a name="zh-cn_topic_0000001163565327_p67742498197"></a>Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163565327_p4774164916199"><a name="zh-cn_topic_0000001163565327_p4774164916199"></a><a name="zh-cn_topic_0000001163565327_p4774164916199"></a>Promise示例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var getVar = update.getUpdater();
p.then(function (value) {
    console.info("applyNewVersion promise success: " + value);
}).catch(function (err) {
    console.info("applyNewVersion promise error: " + err.code);
});
```

## applyNewVersion\(callback: AsyncCallback<number\>\): void<a name="zh-cn_topic_0000001163565327_section3381192816421"></a>

重启设备后安装升级包。

**参数：**

<a name="zh-cn_topic_0000001163565327_table14473145217456"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163565327_row1052235294518"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163565327_p15522195234514"><a name="zh-cn_topic_0000001163565327_p15522195234514"></a><a name="zh-cn_topic_0000001163565327_p15522195234514"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163565327_p1852285215454"><a name="zh-cn_topic_0000001163565327_p1852285215454"></a><a name="zh-cn_topic_0000001163565327_p1852285215454"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163565327_p125221452154514"><a name="zh-cn_topic_0000001163565327_p125221452154514"></a><a name="zh-cn_topic_0000001163565327_p125221452154514"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163565327_p552214521459"><a name="zh-cn_topic_0000001163565327_p552214521459"></a><a name="zh-cn_topic_0000001163565327_p552214521459"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163565327_row165221352124511"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163565327_p85221523450"><a name="zh-cn_topic_0000001163565327_p85221523450"></a><a name="zh-cn_topic_0000001163565327_p85221523450"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163565327_p1452275204516"><a name="zh-cn_topic_0000001163565327_p1452275204516"></a><a name="zh-cn_topic_0000001163565327_p1452275204516"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163565327_p1152275224511"><a name="zh-cn_topic_0000001163565327_p1152275224511"></a><a name="zh-cn_topic_0000001163565327_p1152275224511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163565327_p175228526455"><a name="zh-cn_topic_0000001163565327_p175228526455"></a><a name="zh-cn_topic_0000001163565327_p175228526455"></a>AsyncCallback&lt;number&gt;</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
var getVar = update.getUpdater();
getVar.applyNewVersion(function (err, data) {
    if (err.code == 0) {
        console.info("applyNewVersion callback success:" + data)
    } else {
        console.info("applyNewVersion callback err:" + err.code)
    }
});
```


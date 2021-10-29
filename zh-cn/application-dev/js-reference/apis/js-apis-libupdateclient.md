# 升级<a name="ZH-CN_TOPIC_0000001209257051"></a>

-   [导入模块](#zh-cn_topic_0000001149710363_section749mcpsimp)
-   [权限列表](#zh-cn_topic_0000001149710363_section752mcpsimp)
-   [getNewVersionInfo\(callback: AsyncCallback<NewVersionInfo\>\): void](#zh-cn_topic_0000001149710363_section755mcpsimp)
-   [getNewVersionInfo\(\): Promise<NewVersionInfo\>](#zh-cn_topic_0000001149710363_section6448163034418)
-   [checkNewVersion\(callback: AsyncCallback<NewVersionInfo\>\): void](#zh-cn_topic_0000001149710363_section817mcpsimp)
-   [checkNewVersion\(\): Promise<NewVersionInfo\>](#zh-cn_topic_0000001149710363_section1849020253364)
-   [verifyUpdatePackage\(upgradeFile: string, certsFile: string\): void](#zh-cn_topic_0000001149710363_section16874643181519)
-   [rebootAndCleanUserData\(\): Promise<number\>](#zh-cn_topic_0000001149710363_section3242122116516)
-   [rebootAndCleanUserData\(callback: AsyncCallback<number\>\): void](#zh-cn_topic_0000001149710363_section15242102114516)
-   [applyNewVersion\(\): Promise<number\>](#zh-cn_topic_0000001149710363_section129661811195815)
-   [applyNewVersion\(callback: AsyncCallback<number\>\): void](#zh-cn_topic_0000001149710363_section3381192816421)
-   [download\(\): void](#zh-cn_topic_0000001149710363_section879mcpsimp)
-   [updater.upgrade\(\):void](#zh-cn_topic_0000001149710363_section894mcpsimp)
-   [setUpdatePolicy\(policy: UpdatePolicy, callback: AsyncCallback<number\>\): void](#zh-cn_topic_0000001149710363_section909mcpsimp)
-   [setUpdatePolicy\(policy: UpdatePolicy\): Promise<number\>](#zh-cn_topic_0000001149710363_section8623195623216)
-   [getUpdatePolicy\(callback: AsyncCallback<UpdatePolicy\>\): void](#zh-cn_topic_0000001149710363_section1572219615412)
-   [getUpdatePolicy\(\): Promise<UpdatePolicy\>](#zh-cn_topic_0000001149710363_section1553973516586)
-   [getUpdater\(upgradeFile: string, updateType?: UpdateTypes\): Updater](#zh-cn_topic_0000001149710363_section24411282249)
-   [getUpdaterForOther\(upgradeFile: string, device: string, updateType?: UpdateTypes\): Updater](#zh-cn_topic_0000001149710363_section13233572411)
-   [getUpdaterFromOther\(upgradeFile: string, device: string, updateType?: UpdateTypes\): Updater](#zh-cn_topic_0000001149710363_section8954144012416)
-   [UpdateTypes](#zh-cn_topic_0000001149710363_section197492318513)
-   [PackageTypes](#zh-cn_topic_0000001149710363_section19316738135716)
-   [InstallMode](#zh-cn_topic_0000001149710363_section15197191318487)
-   [NewVersionStatus](#zh-cn_topic_0000001149710363_section148419085512)
-   [UpdatePolicy](#zh-cn_topic_0000001149710363_section5220623434)
-   [NewVersionInfo](#zh-cn_topic_0000001149710363_section15357856134620)
-   [CheckResult](#zh-cn_topic_0000001149710363_section125591515125819)
-   [DescriptionInfo](#zh-cn_topic_0000001149710363_section6472174588)

升级范围：升级整个OpenHarmony系统，包括内置的资源、预置应用；第三方的应用不在升级的范围。

升级依赖：升级分为SD卡升级和在线升级两种。

-   SD卡升级依赖升级包和SD卡安装。
-   在线升级依赖手机厂商部署的用于管理升级包的服务器。服务器由手机厂商部署，IP由调用者传入，请求的request接口是固定的，由手机厂商开发。

## 导入模块<a name="zh-cn_topic_0000001149710363_section749mcpsimp"></a>

```
import client from '@ohos.update'
```

## 权限列表<a name="zh-cn_topic_0000001149710363_section752mcpsimp"></a>

无

## getNewVersionInfo\(callback: AsyncCallback<NewVersionInfo\>\): void<a name="zh-cn_topic_0000001149710363_section755mcpsimp"></a>

获取新版本信息，使用callback方式作为异步方法。

-   参数

    <a name="zh-cn_topic_0000001149710363_table760mcpsimp"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row767mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p769mcpsimp"><a name="zh-cn_topic_0000001149710363_p769mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p769mcpsimp"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p771mcpsimp"><a name="zh-cn_topic_0000001149710363_p771mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p771mcpsimp"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.79%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p773mcpsimp"><a name="zh-cn_topic_0000001149710363_p773mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p773mcpsimp"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.99%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p775mcpsimp"><a name="zh-cn_topic_0000001149710363_p775mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p775mcpsimp"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row777mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p779mcpsimp"><a name="zh-cn_topic_0000001149710363_p779mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p779mcpsimp"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1954525214352"><a name="zh-cn_topic_0000001149710363_p1954525214352"></a><a name="zh-cn_topic_0000001149710363_p1954525214352"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001149710363_section15357856134620">NewVersionInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.79%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p783mcpsimp"><a name="zh-cn_topic_0000001149710363_p783mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p783mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.99%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p785mcpsimp"><a name="zh-cn_topic_0000001149710363_p785mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p785mcpsimp"></a>回调返回新版本信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    无


-   示例

    ```
    updater.getNewVersionInfo(info => {
      console.log("getNewVersionInfo success  " + info.status);
      console.log(`info versionName = ` + info.result[0].versionName);
      console.log(`info versionCode = ` + info.result[0].versionCode);
      console.log(`info verifyInfo = ` + info.result[0].verifyInfo);
    )};
    ```


## getNewVersionInfo\(\): Promise<NewVersionInfo\><a name="zh-cn_topic_0000001149710363_section6448163034418"></a>

获取新版本信息，使用promise方式作为异步方法。

-   参数

    无


-   返回值

    <a name="zh-cn_topic_0000001149710363_table164481930104417"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row1044953044414"><th class="cellrowborder" valign="top" width="25.369999999999997%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p1444914300449"><a name="zh-cn_topic_0000001149710363_p1444914300449"></a><a name="zh-cn_topic_0000001149710363_p1444914300449"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.63%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p1644933018443"><a name="zh-cn_topic_0000001149710363_p1644933018443"></a><a name="zh-cn_topic_0000001149710363_p1644933018443"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row20449113018443"><td class="cellrowborder" valign="top" width="25.369999999999997%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p2044913018444"><a name="zh-cn_topic_0000001149710363_p2044913018444"></a><a name="zh-cn_topic_0000001149710363_p2044913018444"></a>Promise&lt;<a href="#zh-cn_topic_0000001149710363_section15357856134620">NewVersionInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.63%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p74494308444"><a name="zh-cn_topic_0000001149710363_p74494308444"></a><a name="zh-cn_topic_0000001149710363_p74494308444"></a>Promise，用于异步获取结果</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    var p = updater.getNewVersionInfo();
    p.then(function (value) {
      console.log(`info versionName = ` + value.result[0].versionName);
      console.log(`info versionCode = ` + value.result[0].versionCode);
      console.log(`info verifyInfo = ` + value.result[0].verifyInfo);
    }).catch(function (err) {
      console.log("getNewVersionInfo promise error: " + err.code);
    )};
    ```


## checkNewVersion\(callback: AsyncCallback<NewVersionInfo\>\): void<a name="zh-cn_topic_0000001149710363_section817mcpsimp"></a>

检查新版本，使用callback方式作为异步方法。

-   参数

    <a name="zh-cn_topic_0000001149710363_table822mcpsimp"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row829mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p831mcpsimp"><a name="zh-cn_topic_0000001149710363_p831mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p831mcpsimp"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.45%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p833mcpsimp"><a name="zh-cn_topic_0000001149710363_p833mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p833mcpsimp"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p835mcpsimp"><a name="zh-cn_topic_0000001149710363_p835mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p835mcpsimp"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.63%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p837mcpsimp"><a name="zh-cn_topic_0000001149710363_p837mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p837mcpsimp"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row839mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p841mcpsimp"><a name="zh-cn_topic_0000001149710363_p841mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p841mcpsimp"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.45%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p843mcpsimp"><a name="zh-cn_topic_0000001149710363_p843mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p843mcpsimp"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001149710363_section15357856134620">NewVersionInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p845mcpsimp"><a name="zh-cn_topic_0000001149710363_p845mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p845mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.63%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p847mcpsimp"><a name="zh-cn_topic_0000001149710363_p847mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p847mcpsimp"></a>回调返回新版本信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    无


-   示例

    ```
    updater.checkNewVersion(info => {
      console.log("checkNewVersion success  " + info.status);
      console.log(`info versionName = ` + info.result[0].versionName);
      console.log(`info versionCode = ` + info.result[0].versionCode);
      console.log(`info verifyInfo = ` + info.result[0].verifyInfo);
    )};
    ```


## checkNewVersion\(\): Promise<NewVersionInfo\><a name="zh-cn_topic_0000001149710363_section1849020253364"></a>

检查新版本，使用promise方式作为异步方法。

-   参数

    无


-   返回值

    <a name="zh-cn_topic_0000001149710363_table173437178365"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row13343161773616"><th class="cellrowborder" valign="top" width="25.729999999999997%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p168459165372"><a name="zh-cn_topic_0000001149710363_p168459165372"></a><a name="zh-cn_topic_0000001149710363_p168459165372"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.27%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p16344181743611"><a name="zh-cn_topic_0000001149710363_p16344181743611"></a><a name="zh-cn_topic_0000001149710363_p16344181743611"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row15344917143618"><td class="cellrowborder" valign="top" width="25.729999999999997%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p19845101613379"><a name="zh-cn_topic_0000001149710363_p19845101613379"></a><a name="zh-cn_topic_0000001149710363_p19845101613379"></a>Promise&lt;<a href="#zh-cn_topic_0000001149710363_section15357856134620">NewVersionInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.27%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p434431717364"><a name="zh-cn_topic_0000001149710363_p434431717364"></a><a name="zh-cn_topic_0000001149710363_p434431717364"></a>Promise函数返回新版本信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    var p = updater.checkNewVersion();
    p.then(function (value) {
      console.log(`info versionName = ` + value.result[0].versionName);
      console.log(`info versionCode = ` + value.result[0].versionCode);
      console.log(`info verifyInfo = ` + value.result[0].verifyInfo);
    }).catch(function (err) {
      console.log("checkNewVersion promise error: " + err.code);
    )};
    ```


## verifyUpdatePackage\(upgradeFile: string, certsFile: string\): void<a name="zh-cn_topic_0000001149710363_section16874643181519"></a>

升级前检查升级包是否有效。

-   参数：

    <a name="zh-cn_topic_0000001149710363_table1987419434154"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row16875643191511"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p12875843191519"><a name="zh-cn_topic_0000001149710363_p12875843191519"></a><a name="zh-cn_topic_0000001149710363_p12875843191519"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p12875194316156"><a name="zh-cn_topic_0000001149710363_p12875194316156"></a><a name="zh-cn_topic_0000001149710363_p12875194316156"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p12875104312152"><a name="zh-cn_topic_0000001149710363_p12875104312152"></a><a name="zh-cn_topic_0000001149710363_p12875104312152"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p98751743161513"><a name="zh-cn_topic_0000001149710363_p98751743161513"></a><a name="zh-cn_topic_0000001149710363_p98751743161513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row19875144311510"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p17883191212014"><a name="zh-cn_topic_0000001149710363_p17883191212014"></a><a name="zh-cn_topic_0000001149710363_p17883191212014"></a>upgradeFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p0875164318155"><a name="zh-cn_topic_0000001149710363_p0875164318155"></a><a name="zh-cn_topic_0000001149710363_p0875164318155"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p108751043141517"><a name="zh-cn_topic_0000001149710363_p108751043141517"></a><a name="zh-cn_topic_0000001149710363_p108751043141517"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p1987519439152"><a name="zh-cn_topic_0000001149710363_p1987519439152"></a><a name="zh-cn_topic_0000001149710363_p1987519439152"></a>待校验的升级包路径</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row194175815171"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p20957580177"><a name="zh-cn_topic_0000001149710363_p20957580177"></a><a name="zh-cn_topic_0000001149710363_p20957580177"></a>certsFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1895158171714"><a name="zh-cn_topic_0000001149710363_p1895158171714"></a><a name="zh-cn_topic_0000001149710363_p1895158171714"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p395125851716"><a name="zh-cn_topic_0000001149710363_p395125851716"></a><a name="zh-cn_topic_0000001149710363_p395125851716"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p129545811714"><a name="zh-cn_topic_0000001149710363_p129545811714"></a><a name="zh-cn_topic_0000001149710363_p129545811714"></a>证书路径</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    var getVar = update.getUpdater();
    getVar.on("verifyProgress", function (callback){
        console.info('on verifyProgress ' + callback.percent);
    });
    getVar.verifyUpdatePackage("XXX", "XXX");
    getVar.off("verifyProgress");
    ```


## rebootAndCleanUserData\(\): Promise<number\><a name="zh-cn_topic_0000001149710363_section3242122116516"></a>

重启设备并清除用户分区数据。

-   参数：

    无


-   返回值：

    <a name="zh-cn_topic_0000001149710363_table9242921652"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row724232113519"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p1224210211454"><a name="zh-cn_topic_0000001149710363_p1224210211454"></a><a name="zh-cn_topic_0000001149710363_p1224210211454"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p1924210213517"><a name="zh-cn_topic_0000001149710363_p1924210213517"></a><a name="zh-cn_topic_0000001149710363_p1924210213517"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row6242521053"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p8242162115510"><a name="zh-cn_topic_0000001149710363_p8242162115510"></a><a name="zh-cn_topic_0000001149710363_p8242162115510"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p6242021157"><a name="zh-cn_topic_0000001149710363_p6242021157"></a><a name="zh-cn_topic_0000001149710363_p6242021157"></a>Promise示例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var getVar = update.getUpdater();
    p = getVar.rebootAndCleanUserData();
    p.then(function (value) {
        console.info("rebootAndCleanUserData promise success: " + value);
    }).catch(function (err) {
        console.info("rebootAndCleanUserData promise error: " + err.code);
    });
    ```


## rebootAndCleanUserData\(callback: AsyncCallback<number\>\): void<a name="zh-cn_topic_0000001149710363_section15242102114516"></a>

重启设备并清除用户分区数据。

-   参数：

    <a name="zh-cn_topic_0000001149710363_table62421211154"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row92426211952"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p124342114519"><a name="zh-cn_topic_0000001149710363_p124342114519"></a><a name="zh-cn_topic_0000001149710363_p124342114519"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p524315218516"><a name="zh-cn_topic_0000001149710363_p524315218516"></a><a name="zh-cn_topic_0000001149710363_p524315218516"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p122436211858"><a name="zh-cn_topic_0000001149710363_p122436211858"></a><a name="zh-cn_topic_0000001149710363_p122436211858"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p1243172118512"><a name="zh-cn_topic_0000001149710363_p1243172118512"></a><a name="zh-cn_topic_0000001149710363_p1243172118512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row8243122114510"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p152435211151"><a name="zh-cn_topic_0000001149710363_p152435211151"></a><a name="zh-cn_topic_0000001149710363_p152435211151"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p024372115516"><a name="zh-cn_topic_0000001149710363_p024372115516"></a><a name="zh-cn_topic_0000001149710363_p024372115516"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1724312217510"><a name="zh-cn_topic_0000001149710363_p1724312217510"></a><a name="zh-cn_topic_0000001149710363_p1724312217510"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p22435211855"><a name="zh-cn_topic_0000001149710363_p22435211855"></a><a name="zh-cn_topic_0000001149710363_p22435211855"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    无


-   示例：

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


## applyNewVersion\(\): Promise<number\><a name="zh-cn_topic_0000001149710363_section129661811195815"></a>

重启设备后安装升级包。

-   参数：

    无


-   返回值：

    <a name="zh-cn_topic_0000001149710363_table14773154913191"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row877314991912"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p1077313493199"><a name="zh-cn_topic_0000001149710363_p1077313493199"></a><a name="zh-cn_topic_0000001149710363_p1077313493199"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p1677411498195"><a name="zh-cn_topic_0000001149710363_p1677411498195"></a><a name="zh-cn_topic_0000001149710363_p1677411498195"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1977413496194"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p67742498197"><a name="zh-cn_topic_0000001149710363_p67742498197"></a><a name="zh-cn_topic_0000001149710363_p67742498197"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p4774164916199"><a name="zh-cn_topic_0000001149710363_p4774164916199"></a><a name="zh-cn_topic_0000001149710363_p4774164916199"></a>Promise示例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var getVar = update.getUpdater();
    p.then(function (value) {
        console.info("applyNewVersion promise success: " + value);
    }).catch(function (err) {
        console.info("applyNewVersion promise error: " + err.code);
    });
    ```


## applyNewVersion\(callback: AsyncCallback<number\>\): void<a name="zh-cn_topic_0000001149710363_section3381192816421"></a>

重启设备后安装升级包。

-   参数：

    <a name="zh-cn_topic_0000001149710363_table14473145217456"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row1052235294518"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p15522195234514"><a name="zh-cn_topic_0000001149710363_p15522195234514"></a><a name="zh-cn_topic_0000001149710363_p15522195234514"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p1852285215454"><a name="zh-cn_topic_0000001149710363_p1852285215454"></a><a name="zh-cn_topic_0000001149710363_p1852285215454"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.1899999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p125221452154514"><a name="zh-cn_topic_0000001149710363_p125221452154514"></a><a name="zh-cn_topic_0000001149710363_p125221452154514"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p552214521459"><a name="zh-cn_topic_0000001149710363_p552214521459"></a><a name="zh-cn_topic_0000001149710363_p552214521459"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row165221352124511"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p85221523450"><a name="zh-cn_topic_0000001149710363_p85221523450"></a><a name="zh-cn_topic_0000001149710363_p85221523450"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1452275204516"><a name="zh-cn_topic_0000001149710363_p1452275204516"></a><a name="zh-cn_topic_0000001149710363_p1452275204516"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.1899999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1152275224511"><a name="zh-cn_topic_0000001149710363_p1152275224511"></a><a name="zh-cn_topic_0000001149710363_p1152275224511"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p175228526455"><a name="zh-cn_topic_0000001149710363_p175228526455"></a><a name="zh-cn_topic_0000001149710363_p175228526455"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    无


-   示例：

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


## download\(\): void<a name="zh-cn_topic_0000001149710363_section879mcpsimp"></a>

下载新版本，并监听下载进程。

-   参数

    无


-   返回值

    无


-   示例

```
updater.on("downloadProgress", progress => {
  console.log("downloadProgress on" + progress);
  console.log(`downloadProgress status: ` + progress.status);
  console.log(`downloadProgress percent: ` + progress.percent);
)};
updater.download();
```

## updater.upgrade\(\):void<a name="zh-cn_topic_0000001149710363_section894mcpsimp"></a>

启动升级。

-   参数

    无


-   返回值

    无


-   示例

```
updater.on("upgradeProgress", progress => {
  console.log("upgradeProgress on" + progress);
  console.log(`upgradeProgress status: ` + progress.status);
  console.log(`upgradeProgress percent: ` + progress.percent);
)};
updater.upgrade();
```

## setUpdatePolicy\(policy: UpdatePolicy, callback: AsyncCallback<number\>\): void<a name="zh-cn_topic_0000001149710363_section909mcpsimp"></a>

设置升级策略，使用callback方式作为异步方法。

-   参数

    <a name="zh-cn_topic_0000001149710363_table914mcpsimp"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row921mcpsimp"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p923mcpsimp"><a name="zh-cn_topic_0000001149710363_p923mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p923mcpsimp"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.54%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p925mcpsimp"><a name="zh-cn_topic_0000001149710363_p925mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p925mcpsimp"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.84%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p927mcpsimp"><a name="zh-cn_topic_0000001149710363_p927mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p927mcpsimp"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.62%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p929mcpsimp"><a name="zh-cn_topic_0000001149710363_p929mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p929mcpsimp"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row931mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p933mcpsimp"><a name="zh-cn_topic_0000001149710363_p933mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p933mcpsimp"></a>policy</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.54%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p935mcpsimp"><a name="zh-cn_topic_0000001149710363_p935mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p935mcpsimp"></a><a href="#zh-cn_topic_0000001149710363_section5220623434">UpdatePolicy</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.84%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p937mcpsimp"><a name="zh-cn_topic_0000001149710363_p937mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p937mcpsimp"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p939mcpsimp"><a name="zh-cn_topic_0000001149710363_p939mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p939mcpsimp"></a>设置升级策略</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row940mcpsimp"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p942mcpsimp"><a name="zh-cn_topic_0000001149710363_p942mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p942mcpsimp"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.54%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p944mcpsimp"><a name="zh-cn_topic_0000001149710363_p944mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p944mcpsimp"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.84%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p946mcpsimp"><a name="zh-cn_topic_0000001149710363_p946mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p946mcpsimp"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.62%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p948mcpsimp"><a name="zh-cn_topic_0000001149710363_p948mcpsimp"></a><a name="zh-cn_topic_0000001149710363_p948mcpsimp"></a>回调返回结果</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    无

-   示例

    ```
    // 设置策略
    let policy = {
    autoDownload: false,
    autoDownloadNet: true,
    mode: 2,
    autoUpgradeInterval: [ 2, 3 ],
    autoUpgradeCondition: 2
    }
    updater.setUpdatePolicy(policy, function(result) {
    console.log("setUpdatePolicy ", result)});
    ```


## setUpdatePolicy\(policy: UpdatePolicy\): Promise<number\><a name="zh-cn_topic_0000001149710363_section8623195623216"></a>

设置升级策略，使用promise方式作为异步方法。

-   参数

    <a name="zh-cn_topic_0000001149710363_table1548473711112"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row74859371011"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p13485183712119"><a name="zh-cn_topic_0000001149710363_p13485183712119"></a><a name="zh-cn_topic_0000001149710363_p13485183712119"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.61%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p1448510374119"><a name="zh-cn_topic_0000001149710363_p1448510374119"></a><a name="zh-cn_topic_0000001149710363_p1448510374119"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.7%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p3485173714119"><a name="zh-cn_topic_0000001149710363_p3485173714119"></a><a name="zh-cn_topic_0000001149710363_p3485173714119"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.69%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p74851371318"><a name="zh-cn_topic_0000001149710363_p74851371318"></a><a name="zh-cn_topic_0000001149710363_p74851371318"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row124853371712"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p1348512372113"><a name="zh-cn_topic_0000001149710363_p1348512372113"></a><a name="zh-cn_topic_0000001149710363_p1348512372113"></a>policy</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p148515373120"><a name="zh-cn_topic_0000001149710363_p148515373120"></a><a name="zh-cn_topic_0000001149710363_p148515373120"></a><a href="#zh-cn_topic_0000001149710363_section5220623434">UpdatePolicy</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.7%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p64851372016"><a name="zh-cn_topic_0000001149710363_p64851372016"></a><a name="zh-cn_topic_0000001149710363_p64851372016"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.69%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p848519377117"><a name="zh-cn_topic_0000001149710363_p848519377117"></a><a name="zh-cn_topic_0000001149710363_p848519377117"></a>设置升级策略</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <a name="zh-cn_topic_0000001149710363_table225013268333"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row9250142619338"><th class="cellrowborder" valign="top" width="25.729999999999997%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p1125092613331"><a name="zh-cn_topic_0000001149710363_p1125092613331"></a><a name="zh-cn_topic_0000001149710363_p1125092613331"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.27%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p14250172623317"><a name="zh-cn_topic_0000001149710363_p14250172623317"></a><a name="zh-cn_topic_0000001149710363_p14250172623317"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1250526163319"><td class="cellrowborder" valign="top" width="25.729999999999997%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p52519269334"><a name="zh-cn_topic_0000001149710363_p52519269334"></a><a name="zh-cn_topic_0000001149710363_p52519269334"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.27%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p425122619337"><a name="zh-cn_topic_0000001149710363_p425122619337"></a><a name="zh-cn_topic_0000001149710363_p425122619337"></a>Promise函数返回设置结果</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    let policy = {
    autoDownload: false,
    autoDownloadNet: true,
    mode: 2,
    autoUpgradeInterval: [ 2, 3 ],
    autoUpgradeCondition: 2
    }
    updater.setUpdatePolicy(policy)
    .then(data=>
    console.log('set policy success')
    )
    ```


## getUpdatePolicy\(callback: AsyncCallback<UpdatePolicy\>\): void<a name="zh-cn_topic_0000001149710363_section1572219615412"></a>

获取升级策略信息，使用callback方式作为异步方法。

-   参数

    <a name="zh-cn_topic_0000001149710363_table1045919116515"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row74594110516"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p164592119517"><a name="zh-cn_topic_0000001149710363_p164592119517"></a><a name="zh-cn_topic_0000001149710363_p164592119517"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.14%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p154591611145120"><a name="zh-cn_topic_0000001149710363_p154591611145120"></a><a name="zh-cn_topic_0000001149710363_p154591611145120"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.09%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p154591011145113"><a name="zh-cn_topic_0000001149710363_p154591011145113"></a><a name="zh-cn_topic_0000001149710363_p154591011145113"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.77%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p134591211155120"><a name="zh-cn_topic_0000001149710363_p134591211155120"></a><a name="zh-cn_topic_0000001149710363_p134591211155120"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1945911118511"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p11459911175116"><a name="zh-cn_topic_0000001149710363_p11459911175116"></a><a name="zh-cn_topic_0000001149710363_p11459911175116"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.14%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p107482392566"><a name="zh-cn_topic_0000001149710363_p107482392566"></a><a name="zh-cn_topic_0000001149710363_p107482392566"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001149710363_section5220623434">UpdatePolicy</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.09%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p11459611145113"><a name="zh-cn_topic_0000001149710363_p11459611145113"></a><a name="zh-cn_topic_0000001149710363_p11459611145113"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.77%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p745931135111"><a name="zh-cn_topic_0000001149710363_p745931135111"></a><a name="zh-cn_topic_0000001149710363_p745931135111"></a>回调返回升级策略信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <a name="zh-cn_topic_0000001149710363_table144601411105116"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row194601811125113"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p1546081117518"><a name="zh-cn_topic_0000001149710363_p1546081117518"></a><a name="zh-cn_topic_0000001149710363_p1546081117518"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.42%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p134601611195118"><a name="zh-cn_topic_0000001149710363_p134601611195118"></a><a name="zh-cn_topic_0000001149710363_p134601611195118"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.58%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p8460141111514"><a name="zh-cn_topic_0000001149710363_p8460141111514"></a><a name="zh-cn_topic_0000001149710363_p8460141111514"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row114601119514"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p5460111145117"><a name="zh-cn_topic_0000001149710363_p5460111145117"></a><a name="zh-cn_topic_0000001149710363_p5460111145117"></a>policy</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p1646031112514"><a name="zh-cn_topic_0000001149710363_p1646031112514"></a><a name="zh-cn_topic_0000001149710363_p1646031112514"></a><a href="#zh-cn_topic_0000001149710363_section5220623434">UpdatePolicy</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="64.58%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p846017117515"><a name="zh-cn_topic_0000001149710363_p846017117515"></a><a name="zh-cn_topic_0000001149710363_p846017117515"></a>升级策略信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    updater.getUpdatePolicy(policy => {
      console.log("getUpdatePolicy success");
      console.log(`policy autoDownload = ` + policy.autoDownload);
      console.log(`policy autoDownloadNet = ` + policy.autoDownloadNet);
      console.log(`policy mode = ` + policy.mode);
    )};
    ```


## getUpdatePolicy\(\): Promise<UpdatePolicy\><a name="zh-cn_topic_0000001149710363_section1553973516586"></a>

获取升级策略，通过promise方式作为异步方法。

-   参数

    无


-   返回值

    <a name="zh-cn_topic_0000001149710363_table6460101115114"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row194609117511"><th class="cellrowborder" valign="top" width="24.310000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p144601511115117"><a name="zh-cn_topic_0000001149710363_p144601511115117"></a><a name="zh-cn_topic_0000001149710363_p144601511115117"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="75.69%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p246011113515"><a name="zh-cn_topic_0000001149710363_p246011113515"></a><a name="zh-cn_topic_0000001149710363_p246011113515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row14604110517"><td class="cellrowborder" valign="top" width="24.310000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p1546020116517"><a name="zh-cn_topic_0000001149710363_p1546020116517"></a><a name="zh-cn_topic_0000001149710363_p1546020116517"></a>Promise&lt;<a href="#zh-cn_topic_0000001149710363_section5220623434">UpdatePolicy</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.69%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p15460181120519"><a name="zh-cn_topic_0000001149710363_p15460181120519"></a><a name="zh-cn_topic_0000001149710363_p15460181120519"></a>Promise函数返回升级策略信息</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    p = updater.getUpdatePolicy();
    p.then(function (value) {
      console.log(`info autoDownload = ` + value.autoDownload);
      console.log(`info autoDownloadNet = ` + value.autoDownloadNet);
      console.log(`info mode = ` + value.mode);
    }).catch(function (err) {
      console.log("getUpdatePolicy promise error: " + err.code);
    )};
    ```


## getUpdater\(upgradeFile: string, updateType?: UpdateTypes\): Updater<a name="zh-cn_topic_0000001149710363_section24411282249"></a>

获取本地升级Updater。

-   参数

    <a name="zh-cn_topic_0000001149710363_table290462415391"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row19904152463916"><th class="cellrowborder" valign="top" width="19.5%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p119041924113911"><a name="zh-cn_topic_0000001149710363_p119041924113911"></a><a name="zh-cn_topic_0000001149710363_p119041924113911"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.94%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p18904142463917"><a name="zh-cn_topic_0000001149710363_p18904142463917"></a><a name="zh-cn_topic_0000001149710363_p18904142463917"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.6%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p149041824173910"><a name="zh-cn_topic_0000001149710363_p149041824173910"></a><a name="zh-cn_topic_0000001149710363_p149041824173910"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.96%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p129051124103910"><a name="zh-cn_topic_0000001149710363_p129051124103910"></a><a name="zh-cn_topic_0000001149710363_p129051124103910"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row590512241397"><td class="cellrowborder" valign="top" width="19.5%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p109051242393"><a name="zh-cn_topic_0000001149710363_p109051242393"></a><a name="zh-cn_topic_0000001149710363_p109051242393"></a>upgradeFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p18905182483918"><a name="zh-cn_topic_0000001149710363_p18905182483918"></a><a name="zh-cn_topic_0000001149710363_p18905182483918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p3905624133915"><a name="zh-cn_topic_0000001149710363_p3905624133915"></a><a name="zh-cn_topic_0000001149710363_p3905624133915"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p3905182463918"><a name="zh-cn_topic_0000001149710363_p3905182463918"></a><a name="zh-cn_topic_0000001149710363_p3905182463918"></a>升级文件</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row1905624133914"><td class="cellrowborder" valign="top" width="19.5%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p19905524193920"><a name="zh-cn_topic_0000001149710363_p19905524193920"></a><a name="zh-cn_topic_0000001149710363_p19905524193920"></a>updateType</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p49051524103910"><a name="zh-cn_topic_0000001149710363_p49051524103910"></a><a name="zh-cn_topic_0000001149710363_p49051524103910"></a><a href="#zh-cn_topic_0000001149710363_section197492318513">UpdateTypes</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p09059244399"><a name="zh-cn_topic_0000001149710363_p09059244399"></a><a name="zh-cn_topic_0000001149710363_p09059244399"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p10905624103918"><a name="zh-cn_topic_0000001149710363_p10905624103918"></a><a name="zh-cn_topic_0000001149710363_p10905624103918"></a>升级类型</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <a name="zh-cn_topic_0000001149710363_table1342114992019"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row1634244942012"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p1534217490209"><a name="zh-cn_topic_0000001149710363_p1534217490209"></a><a name="zh-cn_topic_0000001149710363_p1534217490209"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p19342114962016"><a name="zh-cn_topic_0000001149710363_p19342114962016"></a><a name="zh-cn_topic_0000001149710363_p19342114962016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="68%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p434204913204"><a name="zh-cn_topic_0000001149710363_p434204913204"></a><a name="zh-cn_topic_0000001149710363_p434204913204"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1534264915204"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p434234922014"><a name="zh-cn_topic_0000001149710363_p434234922014"></a><a name="zh-cn_topic_0000001149710363_p434234922014"></a>updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p73421049152014"><a name="zh-cn_topic_0000001149710363_p73421049152014"></a><a name="zh-cn_topic_0000001149710363_p73421049152014"></a>Updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p6342164914204"><a name="zh-cn_topic_0000001149710363_p6342164914204"></a><a name="zh-cn_topic_0000001149710363_p6342164914204"></a>升级对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    try {
      page.data.updater = client.getUpdater('/data/updater/updater.zip', 'OTA');
    } catch(error) {
      console.error(" Fail to get updater error: " + error);
    }
    ```


## getUpdaterForOther\(upgradeFile: string, device: string, updateType?: UpdateTypes\): Updater<a name="zh-cn_topic_0000001149710363_section13233572411"></a>

获取升级对象给待升级设备。

-   参数

    <a name="zh-cn_topic_0000001149710363_table7204441154313"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row220444154319"><th class="cellrowborder" valign="top" width="17.48%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p1520474114317"><a name="zh-cn_topic_0000001149710363_p1520474114317"></a><a name="zh-cn_topic_0000001149710363_p1520474114317"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.7%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p72041541154311"><a name="zh-cn_topic_0000001149710363_p72041541154311"></a><a name="zh-cn_topic_0000001149710363_p72041541154311"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.83%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p92041841114315"><a name="zh-cn_topic_0000001149710363_p92041841114315"></a><a name="zh-cn_topic_0000001149710363_p92041841114315"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.989999999999995%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p820464113435"><a name="zh-cn_topic_0000001149710363_p820464113435"></a><a name="zh-cn_topic_0000001149710363_p820464113435"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row82041841184316"><td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p10204241184315"><a name="zh-cn_topic_0000001149710363_p10204241184315"></a><a name="zh-cn_topic_0000001149710363_p10204241184315"></a>upgradeFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1920484134310"><a name="zh-cn_topic_0000001149710363_p1920484134310"></a><a name="zh-cn_topic_0000001149710363_p1920484134310"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p6204164124317"><a name="zh-cn_topic_0000001149710363_p6204164124317"></a><a name="zh-cn_topic_0000001149710363_p6204164124317"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.989999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p20204241154313"><a name="zh-cn_topic_0000001149710363_p20204241154313"></a><a name="zh-cn_topic_0000001149710363_p20204241154313"></a>升级文件</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row10204941114317"><td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p16204154154316"><a name="zh-cn_topic_0000001149710363_p16204154154316"></a><a name="zh-cn_topic_0000001149710363_p16204154154316"></a>device</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p52041541184314"><a name="zh-cn_topic_0000001149710363_p52041541184314"></a><a name="zh-cn_topic_0000001149710363_p52041541184314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p720520413430"><a name="zh-cn_topic_0000001149710363_p720520413430"></a><a name="zh-cn_topic_0000001149710363_p720520413430"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.989999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p020511419433"><a name="zh-cn_topic_0000001149710363_p020511419433"></a><a name="zh-cn_topic_0000001149710363_p020511419433"></a>待升级设备</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row48731254204311"><td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p1858116724416"><a name="zh-cn_topic_0000001149710363_p1858116724416"></a><a name="zh-cn_topic_0000001149710363_p1858116724416"></a>updateType</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p45811718447"><a name="zh-cn_topic_0000001149710363_p45811718447"></a><a name="zh-cn_topic_0000001149710363_p45811718447"></a><a href="#zh-cn_topic_0000001149710363_section197492318513">UpdateTypes</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.83%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p10581137134410"><a name="zh-cn_topic_0000001149710363_p10581137134410"></a><a name="zh-cn_topic_0000001149710363_p10581137134410"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.989999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p2581472442"><a name="zh-cn_topic_0000001149710363_p2581472442"></a><a name="zh-cn_topic_0000001149710363_p2581472442"></a>升级类型</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <a name="zh-cn_topic_0000001149710363_table820513416431"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row19205174114437"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p2020564114312"><a name="zh-cn_topic_0000001149710363_p2020564114312"></a><a name="zh-cn_topic_0000001149710363_p2020564114312"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p202056411439"><a name="zh-cn_topic_0000001149710363_p202056411439"></a><a name="zh-cn_topic_0000001149710363_p202056411439"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="68%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p020594116436"><a name="zh-cn_topic_0000001149710363_p020594116436"></a><a name="zh-cn_topic_0000001149710363_p020594116436"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row11205941154315"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p112054412439"><a name="zh-cn_topic_0000001149710363_p112054412439"></a><a name="zh-cn_topic_0000001149710363_p112054412439"></a>updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p1205134114433"><a name="zh-cn_topic_0000001149710363_p1205134114433"></a><a name="zh-cn_topic_0000001149710363_p1205134114433"></a>Updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p202051416432"><a name="zh-cn_topic_0000001149710363_p202051416432"></a><a name="zh-cn_topic_0000001149710363_p202051416432"></a>升级对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    try {
      page.data.updater = client.getUpdaterForOther('/data/updater/updater.zip', '1234567890', 'OTA');
    } catch(error) {
      console.error(" Fail to get updater error: " + error);
    }
    ```


## getUpdaterFromOther\(upgradeFile: string, device: string, updateType?: UpdateTypes\): Updater<a name="zh-cn_topic_0000001149710363_section8954144012416"></a>

获取其它设备为本设备升级的Updater。

-   参数

    <a name="zh-cn_topic_0000001149710363_table174447715473"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row12445177474"><th class="cellrowborder" valign="top" width="18.81%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p8445475471"><a name="zh-cn_topic_0000001149710363_p8445475471"></a><a name="zh-cn_topic_0000001149710363_p8445475471"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.11%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p344527124710"><a name="zh-cn_topic_0000001149710363_p344527124710"></a><a name="zh-cn_topic_0000001149710363_p344527124710"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p34459712475"><a name="zh-cn_topic_0000001149710363_p34459712475"></a><a name="zh-cn_topic_0000001149710363_p34459712475"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.74%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p11445197174713"><a name="zh-cn_topic_0000001149710363_p11445197174713"></a><a name="zh-cn_topic_0000001149710363_p11445197174713"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1944510712472"><td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p13445197104719"><a name="zh-cn_topic_0000001149710363_p13445197104719"></a><a name="zh-cn_topic_0000001149710363_p13445197104719"></a>upgradeFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p154456720473"><a name="zh-cn_topic_0000001149710363_p154456720473"></a><a name="zh-cn_topic_0000001149710363_p154456720473"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p11445127164715"><a name="zh-cn_topic_0000001149710363_p11445127164715"></a><a name="zh-cn_topic_0000001149710363_p11445127164715"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.74%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p124454711479"><a name="zh-cn_topic_0000001149710363_p124454711479"></a><a name="zh-cn_topic_0000001149710363_p124454711479"></a>升级文件</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row15445147104718"><td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p34451477476"><a name="zh-cn_topic_0000001149710363_p34451477476"></a><a name="zh-cn_topic_0000001149710363_p34451477476"></a>device</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p04451574474"><a name="zh-cn_topic_0000001149710363_p04451574474"></a><a name="zh-cn_topic_0000001149710363_p04451574474"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p16445157154711"><a name="zh-cn_topic_0000001149710363_p16445157154711"></a><a name="zh-cn_topic_0000001149710363_p16445157154711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.74%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p34455717471"><a name="zh-cn_topic_0000001149710363_p34455717471"></a><a name="zh-cn_topic_0000001149710363_p34455717471"></a>待升级设备</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001149710363_row044613744711"><td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p24461716478"><a name="zh-cn_topic_0000001149710363_p24461716478"></a><a name="zh-cn_topic_0000001149710363_p24461716478"></a>updateType</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p7446107134711"><a name="zh-cn_topic_0000001149710363_p7446107134711"></a><a name="zh-cn_topic_0000001149710363_p7446107134711"></a><a href="#zh-cn_topic_0000001149710363_section197492318513">UpdateTypes</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p15446147104718"><a name="zh-cn_topic_0000001149710363_p15446147104718"></a><a name="zh-cn_topic_0000001149710363_p15446147104718"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.74%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p1044697114720"><a name="zh-cn_topic_0000001149710363_p1044697114720"></a><a name="zh-cn_topic_0000001149710363_p1044697114720"></a>升级类型</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值

    <a name="zh-cn_topic_0000001149710363_table194461874479"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row34461376472"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p74469764717"><a name="zh-cn_topic_0000001149710363_p74469764717"></a><a name="zh-cn_topic_0000001149710363_p74469764717"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.42%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p1144697114716"><a name="zh-cn_topic_0000001149710363_p1144697114716"></a><a name="zh-cn_topic_0000001149710363_p1144697114716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.58%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p124467774715"><a name="zh-cn_topic_0000001149710363_p124467774715"></a><a name="zh-cn_topic_0000001149710363_p124467774715"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001149710363_row1344617194713"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p154465714473"><a name="zh-cn_topic_0000001149710363_p154465714473"></a><a name="zh-cn_topic_0000001149710363_p154465714473"></a>updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p344617154720"><a name="zh-cn_topic_0000001149710363_p344617154720"></a><a name="zh-cn_topic_0000001149710363_p344617154720"></a>Updater</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.58%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1544619774711"><a name="zh-cn_topic_0000001149710363_p1544619774711"></a><a name="zh-cn_topic_0000001149710363_p1544619774711"></a>升级对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    try {
      page.data.updater = client.getUpdaterFromOther('/data/updater/updater.zip', '1234567890', 'OTA');
    } catch(error) {
      console.error(" Fail to get updater error: " + error);
    }
    ```


## UpdateTypes<a name="zh-cn_topic_0000001149710363_section197492318513"></a>

升级类型

<a name="zh-cn_topic_0000001149710363_table530272735114"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row6303627105111"><th class="cellrowborder" valign="top" width="28.53%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001149710363_p1130352795114"><a name="zh-cn_topic_0000001149710363_p1130352795114"></a><a name="zh-cn_topic_0000001149710363_p1130352795114"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="71.47%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001149710363_p1303122712513"><a name="zh-cn_topic_0000001149710363_p1303122712513"></a><a name="zh-cn_topic_0000001149710363_p1303122712513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row1430382765112"><td class="cellrowborder" valign="top" width="28.53%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p143031227135113"><a name="zh-cn_topic_0000001149710363_p143031227135113"></a><a name="zh-cn_topic_0000001149710363_p143031227135113"></a>OTA</p>
</td>
<td class="cellrowborder" valign="top" width="71.47%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p143031227165110"><a name="zh-cn_topic_0000001149710363_p143031227165110"></a><a name="zh-cn_topic_0000001149710363_p143031227165110"></a>OTA升级</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row1030312755113"><td class="cellrowborder" valign="top" width="28.53%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001149710363_p130362765110"><a name="zh-cn_topic_0000001149710363_p130362765110"></a><a name="zh-cn_topic_0000001149710363_p130362765110"></a>patch</p>
</td>
<td class="cellrowborder" valign="top" width="71.47%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001149710363_p8303202755110"><a name="zh-cn_topic_0000001149710363_p8303202755110"></a><a name="zh-cn_topic_0000001149710363_p8303202755110"></a>补丁升级</p>
</td>
</tr>
</tbody>
</table>

## PackageTypes<a name="zh-cn_topic_0000001149710363_section19316738135716"></a>

升级包类型

<a name="zh-cn_topic_0000001149710363_table61151313175817"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row141151113175811"><th class="cellrowborder" valign="top" width="26.38%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p1311516132584"><a name="zh-cn_topic_0000001149710363_p1311516132584"></a><a name="zh-cn_topic_0000001149710363_p1311516132584"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p553914166712"><a name="zh-cn_topic_0000001149710363_p553914166712"></a><a name="zh-cn_topic_0000001149710363_p553914166712"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="66.10000000000001%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p011510137589"><a name="zh-cn_topic_0000001149710363_p011510137589"></a><a name="zh-cn_topic_0000001149710363_p011510137589"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row91151713195814"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1327127165912"><a name="zh-cn_topic_0000001149710363_p1327127165912"></a><a name="zh-cn_topic_0000001149710363_p1327127165912"></a>PACKAGE_TYPE_NORMAL</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p1053916161477"><a name="zh-cn_topic_0000001149710363_p1053916161477"></a><a name="zh-cn_topic_0000001149710363_p1053916161477"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p172510795911"><a name="zh-cn_topic_0000001149710363_p172510795911"></a><a name="zh-cn_topic_0000001149710363_p172510795911"></a>通用升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row911618136587"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1324976594"><a name="zh-cn_topic_0000001149710363_p1324976594"></a><a name="zh-cn_topic_0000001149710363_p1324976594"></a>PACKAGE_TYPE_BASE</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p165393161076"><a name="zh-cn_topic_0000001149710363_p165393161076"></a><a name="zh-cn_topic_0000001149710363_p165393161076"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p827775916"><a name="zh-cn_topic_0000001149710363_p827775916"></a><a name="zh-cn_topic_0000001149710363_p827775916"></a>基础升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row149091320125811"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1391012095819"><a name="zh-cn_topic_0000001149710363_p1391012095819"></a><a name="zh-cn_topic_0000001149710363_p1391012095819"></a>PACKAGE_TYPE_CUST</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p753917161677"><a name="zh-cn_topic_0000001149710363_p753917161677"></a><a name="zh-cn_topic_0000001149710363_p753917161677"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p19103205586"><a name="zh-cn_topic_0000001149710363_p19103205586"></a><a name="zh-cn_topic_0000001149710363_p19103205586"></a>定制升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row133885318587"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p13886315588"><a name="zh-cn_topic_0000001149710363_p13886315588"></a><a name="zh-cn_topic_0000001149710363_p13886315588"></a>PACKAGE_TYPE_PRELOAD</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p195397161473"><a name="zh-cn_topic_0000001149710363_p195397161473"></a><a name="zh-cn_topic_0000001149710363_p195397161473"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1338973118589"><a name="zh-cn_topic_0000001149710363_p1338973118589"></a><a name="zh-cn_topic_0000001149710363_p1338973118589"></a>预装升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row953834105813"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1531534165813"><a name="zh-cn_topic_0000001149710363_p1531534165813"></a><a name="zh-cn_topic_0000001149710363_p1531534165813"></a>PACKAGE_TYPE_COTA</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p1453910165719"><a name="zh-cn_topic_0000001149710363_p1453910165719"></a><a name="zh-cn_topic_0000001149710363_p1453910165719"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p175323485818"><a name="zh-cn_topic_0000001149710363_p175323485818"></a><a name="zh-cn_topic_0000001149710363_p175323485818"></a>参数配置升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row4421336165810"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p2042193618581"><a name="zh-cn_topic_0000001149710363_p2042193618581"></a><a name="zh-cn_topic_0000001149710363_p2042193618581"></a>PACKAGE_TYPE_VERSION</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p55399163714"><a name="zh-cn_topic_0000001149710363_p55399163714"></a><a name="zh-cn_topic_0000001149710363_p55399163714"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1542183611587"><a name="zh-cn_topic_0000001149710363_p1542183611587"></a><a name="zh-cn_topic_0000001149710363_p1542183611587"></a>版本升级包</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row330092715811"><td class="cellrowborder" valign="top" width="26.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1630011275580"><a name="zh-cn_topic_0000001149710363_p1630011275580"></a><a name="zh-cn_topic_0000001149710363_p1630011275580"></a>PACKAGE_TYPE_PATCH</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p6539616477"><a name="zh-cn_topic_0000001149710363_p6539616477"></a><a name="zh-cn_topic_0000001149710363_p6539616477"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="66.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p183007277585"><a name="zh-cn_topic_0000001149710363_p183007277585"></a><a name="zh-cn_topic_0000001149710363_p183007277585"></a>补丁包</p>
</td>
</tr>
</tbody>
</table>

## InstallMode<a name="zh-cn_topic_0000001149710363_section15197191318487"></a>

安装模式

<a name="zh-cn_topic_0000001149710363_table1383116488489"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row1183184824812"><th class="cellrowborder" valign="top" width="36.010000000000005%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p13831948164817"><a name="zh-cn_topic_0000001149710363_p13831948164817"></a><a name="zh-cn_topic_0000001149710363_p13831948164817"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21.330000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p10831248204814"><a name="zh-cn_topic_0000001149710363_p10831248204814"></a><a name="zh-cn_topic_0000001149710363_p10831248204814"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.660000000000004%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p1183164884814"><a name="zh-cn_topic_0000001149710363_p1183164884814"></a><a name="zh-cn_topic_0000001149710363_p1183164884814"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row208311148144815"><td class="cellrowborder" valign="top" width="36.010000000000005%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p4831248204815"><a name="zh-cn_topic_0000001149710363_p4831248204815"></a><a name="zh-cn_topic_0000001149710363_p4831248204815"></a>INSTALL_MODE_NORMAL</p>
</td>
<td class="cellrowborder" valign="top" width="21.330000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p8831174804819"><a name="zh-cn_topic_0000001149710363_p8831174804819"></a><a name="zh-cn_topic_0000001149710363_p8831174804819"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="42.660000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p683184814811"><a name="zh-cn_topic_0000001149710363_p683184814811"></a><a name="zh-cn_topic_0000001149710363_p683184814811"></a>正常升级</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row178311448204819"><td class="cellrowborder" valign="top" width="36.010000000000005%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p4831748124812"><a name="zh-cn_topic_0000001149710363_p4831748124812"></a><a name="zh-cn_topic_0000001149710363_p4831748124812"></a>INSTALL_MODE_NIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="21.330000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p12831114811485"><a name="zh-cn_topic_0000001149710363_p12831114811485"></a><a name="zh-cn_topic_0000001149710363_p12831114811485"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="42.660000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1783224816486"><a name="zh-cn_topic_0000001149710363_p1783224816486"></a><a name="zh-cn_topic_0000001149710363_p1783224816486"></a>夜间升级</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row77452017134914"><td class="cellrowborder" valign="top" width="36.010000000000005%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1174615173494"><a name="zh-cn_topic_0000001149710363_p1174615173494"></a><a name="zh-cn_topic_0000001149710363_p1174615173494"></a>INSTALL_MODE_AUTO</p>
</td>
<td class="cellrowborder" valign="top" width="21.330000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p67461417154919"><a name="zh-cn_topic_0000001149710363_p67461417154919"></a><a name="zh-cn_topic_0000001149710363_p67461417154919"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="42.660000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p15746317114914"><a name="zh-cn_topic_0000001149710363_p15746317114914"></a><a name="zh-cn_topic_0000001149710363_p15746317114914"></a>自动升级</p>
</td>
</tr>
</tbody>
</table>

## NewVersionStatus<a name="zh-cn_topic_0000001149710363_section148419085512"></a>

新版本检测状态

<a name="zh-cn_topic_0000001149710363_table108413005516"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row128480155519"><th class="cellrowborder" valign="top" width="38.53%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001149710363_p118430185519"><a name="zh-cn_topic_0000001149710363_p118430185519"></a><a name="zh-cn_topic_0000001149710363_p118430185519"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="13.58%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001149710363_p20841100557"><a name="zh-cn_topic_0000001149710363_p20841100557"></a><a name="zh-cn_topic_0000001149710363_p20841100557"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="47.89%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001149710363_p138419025513"><a name="zh-cn_topic_0000001149710363_p138419025513"></a><a name="zh-cn_topic_0000001149710363_p138419025513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row384903557"><td class="cellrowborder" valign="top" width="38.53%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p68420095511"><a name="zh-cn_topic_0000001149710363_p68420095511"></a><a name="zh-cn_topic_0000001149710363_p68420095511"></a>VERSION_STATUS_ERR</p>
</td>
<td class="cellrowborder" valign="top" width="13.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p28413065515"><a name="zh-cn_topic_0000001149710363_p28413065515"></a><a name="zh-cn_topic_0000001149710363_p28413065515"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="47.89%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p38510011559"><a name="zh-cn_topic_0000001149710363_p38510011559"></a><a name="zh-cn_topic_0000001149710363_p38510011559"></a>检测版本时出错</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row185120175510"><td class="cellrowborder" valign="top" width="38.53%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p7855015513"><a name="zh-cn_topic_0000001149710363_p7855015513"></a><a name="zh-cn_topic_0000001149710363_p7855015513"></a>VERSION_STATUS_NEW</p>
</td>
<td class="cellrowborder" valign="top" width="13.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p108510010554"><a name="zh-cn_topic_0000001149710363_p108510010554"></a><a name="zh-cn_topic_0000001149710363_p108510010554"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="47.89%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1385190105514"><a name="zh-cn_topic_0000001149710363_p1385190105514"></a><a name="zh-cn_topic_0000001149710363_p1385190105514"></a>检测到新版本</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row14851506551"><td class="cellrowborder" valign="top" width="38.53%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p8857045517"><a name="zh-cn_topic_0000001149710363_p8857045517"></a><a name="zh-cn_topic_0000001149710363_p8857045517"></a>VERSION_STATUS_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="13.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p11852008551"><a name="zh-cn_topic_0000001149710363_p11852008551"></a><a name="zh-cn_topic_0000001149710363_p11852008551"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="47.89%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1851309559"><a name="zh-cn_topic_0000001149710363_p1851309559"></a><a name="zh-cn_topic_0000001149710363_p1851309559"></a>没有检测到新版本</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row8934194295520"><td class="cellrowborder" valign="top" width="38.53%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001149710363_p1593424215518"><a name="zh-cn_topic_0000001149710363_p1593424215518"></a><a name="zh-cn_topic_0000001149710363_p1593424215518"></a>VERSION_STATUS_BUSY</p>
</td>
<td class="cellrowborder" valign="top" width="13.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001149710363_p13616191265618"><a name="zh-cn_topic_0000001149710363_p13616191265618"></a><a name="zh-cn_topic_0000001149710363_p13616191265618"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="47.89%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001149710363_p1934194214555"><a name="zh-cn_topic_0000001149710363_p1934194214555"></a><a name="zh-cn_topic_0000001149710363_p1934194214555"></a>检测版本时忙</p>
</td>
</tr>
</tbody>
</table>

## UpdatePolicy<a name="zh-cn_topic_0000001149710363_section5220623434"></a>

升级策略

<a name="zh-cn_topic_0000001149710363_table579433364419"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row279463311449"><th class="cellrowborder" valign="top" width="28.139999999999997%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p18794163310449"><a name="zh-cn_topic_0000001149710363_p18794163310449"></a><a name="zh-cn_topic_0000001149710363_p18794163310449"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.98%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p2794163318449"><a name="zh-cn_topic_0000001149710363_p2794163318449"></a><a name="zh-cn_topic_0000001149710363_p2794163318449"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.809999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p9794733164413"><a name="zh-cn_topic_0000001149710363_p9794733164413"></a><a name="zh-cn_topic_0000001149710363_p9794733164413"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="33.07%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p4794833144417"><a name="zh-cn_topic_0000001149710363_p4794833144417"></a><a name="zh-cn_topic_0000001149710363_p4794833144417"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row1479443315446"><td class="cellrowborder" valign="top" width="28.139999999999997%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p1979423374415"><a name="zh-cn_topic_0000001149710363_p1979423374415"></a><a name="zh-cn_topic_0000001149710363_p1979423374415"></a>autoDownload</p>
</td>
<td class="cellrowborder" valign="top" width="22.98%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p18794133318448"><a name="zh-cn_topic_0000001149710363_p18794133318448"></a><a name="zh-cn_topic_0000001149710363_p18794133318448"></a>bool</p>
</td>
<td class="cellrowborder" valign="top" width="15.809999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p10794123315447"><a name="zh-cn_topic_0000001149710363_p10794123315447"></a><a name="zh-cn_topic_0000001149710363_p10794123315447"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="33.07%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p1579483374415"><a name="zh-cn_topic_0000001149710363_p1579483374415"></a><a name="zh-cn_topic_0000001149710363_p1579483374415"></a>自动升级开关</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row12794193344414"><td class="cellrowborder" valign="top" width="28.139999999999997%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p079510331443"><a name="zh-cn_topic_0000001149710363_p079510331443"></a><a name="zh-cn_topic_0000001149710363_p079510331443"></a>installMode</p>
</td>
<td class="cellrowborder" valign="top" width="22.98%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p979520337445"><a name="zh-cn_topic_0000001149710363_p979520337445"></a><a name="zh-cn_topic_0000001149710363_p979520337445"></a><a href="#zh-cn_topic_0000001149710363_section15197191318487">InstallMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.809999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p57951933194411"><a name="zh-cn_topic_0000001149710363_p57951933194411"></a><a name="zh-cn_topic_0000001149710363_p57951933194411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="33.07%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p17795103304416"><a name="zh-cn_topic_0000001149710363_p17795103304416"></a><a name="zh-cn_topic_0000001149710363_p17795103304416"></a>安装模式</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row11795183310445"><td class="cellrowborder" valign="top" width="28.139999999999997%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p279513312441"><a name="zh-cn_topic_0000001149710363_p279513312441"></a><a name="zh-cn_topic_0000001149710363_p279513312441"></a>autoUpgradeInterval</p>
</td>
<td class="cellrowborder" valign="top" width="22.98%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p197954331445"><a name="zh-cn_topic_0000001149710363_p197954331445"></a><a name="zh-cn_topic_0000001149710363_p197954331445"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="15.809999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p4795333124414"><a name="zh-cn_topic_0000001149710363_p4795333124414"></a><a name="zh-cn_topic_0000001149710363_p4795333124414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="33.07%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p779518337443"><a name="zh-cn_topic_0000001149710363_p779518337443"></a><a name="zh-cn_topic_0000001149710363_p779518337443"></a>自动升级时间段</p>
</td>
</tr>
</tbody>
</table>

## NewVersionInfo<a name="zh-cn_topic_0000001149710363_section15357856134620"></a>

新版本信息

<a name="zh-cn_topic_0000001149710363_table76045215479"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row860195254715"><th class="cellrowborder" valign="top" width="22.39%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p18601452104712"><a name="zh-cn_topic_0000001149710363_p18601452104712"></a><a name="zh-cn_topic_0000001149710363_p18601452104712"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="31.09%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p196185274715"><a name="zh-cn_topic_0000001149710363_p196185274715"></a><a name="zh-cn_topic_0000001149710363_p196185274715"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.89%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p176135264712"><a name="zh-cn_topic_0000001149710363_p176135264712"></a><a name="zh-cn_topic_0000001149710363_p176135264712"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="36.63%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p12611522476"><a name="zh-cn_topic_0000001149710363_p12611522476"></a><a name="zh-cn_topic_0000001149710363_p12611522476"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row156155224715"><td class="cellrowborder" valign="top" width="22.39%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p106125284716"><a name="zh-cn_topic_0000001149710363_p106125284716"></a><a name="zh-cn_topic_0000001149710363_p106125284716"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="31.09%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p17561448483"><a name="zh-cn_topic_0000001149710363_p17561448483"></a><a name="zh-cn_topic_0000001149710363_p17561448483"></a><a href="#zh-cn_topic_0000001149710363_section148419085512">NewVersionStatus</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p126135274720"><a name="zh-cn_topic_0000001149710363_p126135274720"></a><a name="zh-cn_topic_0000001149710363_p126135274720"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="36.63%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p136195254716"><a name="zh-cn_topic_0000001149710363_p136195254716"></a><a name="zh-cn_topic_0000001149710363_p136195254716"></a>升级状态</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row761152154711"><td class="cellrowborder" valign="top" width="22.39%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p1161125214472"><a name="zh-cn_topic_0000001149710363_p1161125214472"></a><a name="zh-cn_topic_0000001149710363_p1161125214472"></a>errMsg</p>
</td>
<td class="cellrowborder" valign="top" width="31.09%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p015910299513"><a name="zh-cn_topic_0000001149710363_p015910299513"></a><a name="zh-cn_topic_0000001149710363_p015910299513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1611252134716"><a name="zh-cn_topic_0000001149710363_p1611252134716"></a><a name="zh-cn_topic_0000001149710363_p1611252134716"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="36.63%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p961852204713"><a name="zh-cn_topic_0000001149710363_p961852204713"></a><a name="zh-cn_topic_0000001149710363_p961852204713"></a>错误信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row1661145274717"><td class="cellrowborder" valign="top" width="22.39%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p661165220473"><a name="zh-cn_topic_0000001149710363_p661165220473"></a><a name="zh-cn_topic_0000001149710363_p661165220473"></a>checkResults</p>
</td>
<td class="cellrowborder" valign="top" width="31.09%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p11617114318495"><a name="zh-cn_topic_0000001149710363_p11617114318495"></a><a name="zh-cn_topic_0000001149710363_p11617114318495"></a>Array&lt;<a href="#zh-cn_topic_0000001149710363_section125591515125819">CheckResult</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p12611252144710"><a name="zh-cn_topic_0000001149710363_p12611252144710"></a><a name="zh-cn_topic_0000001149710363_p12611252144710"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="36.63%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p16155217476"><a name="zh-cn_topic_0000001149710363_p16155217476"></a><a name="zh-cn_topic_0000001149710363_p16155217476"></a>检测结果</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row0251111814490"><td class="cellrowborder" valign="top" width="22.39%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p32522183494"><a name="zh-cn_topic_0000001149710363_p32522183494"></a><a name="zh-cn_topic_0000001149710363_p32522183494"></a>descriptionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="31.09%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p825218186491"><a name="zh-cn_topic_0000001149710363_p825218186491"></a><a name="zh-cn_topic_0000001149710363_p825218186491"></a>Array&lt;<a href="#zh-cn_topic_0000001149710363_section6472174588">DescriptionInfo</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.89%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p725210184494"><a name="zh-cn_topic_0000001149710363_p725210184494"></a><a name="zh-cn_topic_0000001149710363_p725210184494"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="36.63%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p172521418114913"><a name="zh-cn_topic_0000001149710363_p172521418114913"></a><a name="zh-cn_topic_0000001149710363_p172521418114913"></a>描述信息</p>
</td>
</tr>
</tbody>
</table>

## CheckResult<a name="zh-cn_topic_0000001149710363_section125591515125819"></a>

检测结果

<a name="zh-cn_topic_0000001149710363_table13559415125812"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row12559615185818"><th class="cellrowborder" valign="top" width="24.19%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p135591515205811"><a name="zh-cn_topic_0000001149710363_p135591515205811"></a><a name="zh-cn_topic_0000001149710363_p135591515205811"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.48%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p175593154584"><a name="zh-cn_topic_0000001149710363_p175593154584"></a><a name="zh-cn_topic_0000001149710363_p175593154584"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.15%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p1255915159586"><a name="zh-cn_topic_0000001149710363_p1255915159586"></a><a name="zh-cn_topic_0000001149710363_p1255915159586"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.18%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p355921515811"><a name="zh-cn_topic_0000001149710363_p355921515811"></a><a name="zh-cn_topic_0000001149710363_p355921515811"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row055961519583"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p2559191510581"><a name="zh-cn_topic_0000001149710363_p2559191510581"></a><a name="zh-cn_topic_0000001149710363_p2559191510581"></a>versionName</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1919017364112"><a name="zh-cn_topic_0000001149710363_p1919017364112"></a><a name="zh-cn_topic_0000001149710363_p1919017364112"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1556061511587"><a name="zh-cn_topic_0000001149710363_p1556061511587"></a><a name="zh-cn_topic_0000001149710363_p1556061511587"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p205601415115820"><a name="zh-cn_topic_0000001149710363_p205601415115820"></a><a name="zh-cn_topic_0000001149710363_p205601415115820"></a>版本名称</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row13560111514580"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p152189487110"><a name="zh-cn_topic_0000001149710363_p152189487110"></a><a name="zh-cn_topic_0000001149710363_p152189487110"></a>versionCode</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p956021515812"><a name="zh-cn_topic_0000001149710363_p956021515812"></a><a name="zh-cn_topic_0000001149710363_p956021515812"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p165605154582"><a name="zh-cn_topic_0000001149710363_p165605154582"></a><a name="zh-cn_topic_0000001149710363_p165605154582"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p135601515145811"><a name="zh-cn_topic_0000001149710363_p135601515145811"></a><a name="zh-cn_topic_0000001149710363_p135601515145811"></a>版本编码</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row13560151535814"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p16719258918"><a name="zh-cn_topic_0000001149710363_p16719258918"></a><a name="zh-cn_topic_0000001149710363_p16719258918"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p35607156586"><a name="zh-cn_topic_0000001149710363_p35607156586"></a><a name="zh-cn_topic_0000001149710363_p35607156586"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1356018151586"><a name="zh-cn_topic_0000001149710363_p1356018151586"></a><a name="zh-cn_topic_0000001149710363_p1356018151586"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p17560151515581"><a name="zh-cn_topic_0000001149710363_p17560151515581"></a><a name="zh-cn_topic_0000001149710363_p17560151515581"></a>版本大小</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row19560131516582"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p125607151589"><a name="zh-cn_topic_0000001149710363_p125607151589"></a><a name="zh-cn_topic_0000001149710363_p125607151589"></a>verifyInfo</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p165601515115812"><a name="zh-cn_topic_0000001149710363_p165601515115812"></a><a name="zh-cn_topic_0000001149710363_p165601515115812"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p1056031585810"><a name="zh-cn_topic_0000001149710363_p1056031585810"></a><a name="zh-cn_topic_0000001149710363_p1056031585810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p25601915155815"><a name="zh-cn_topic_0000001149710363_p25601915155815"></a><a name="zh-cn_topic_0000001149710363_p25601915155815"></a>版本校验信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row13543030329"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p115445301127"><a name="zh-cn_topic_0000001149710363_p115445301127"></a><a name="zh-cn_topic_0000001149710363_p115445301127"></a>packageType</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p1954453013214"><a name="zh-cn_topic_0000001149710363_p1954453013214"></a><a name="zh-cn_topic_0000001149710363_p1954453013214"></a><a href="#zh-cn_topic_0000001149710363_section19316738135716">PackageTypes</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p954418308213"><a name="zh-cn_topic_0000001149710363_p954418308213"></a><a name="zh-cn_topic_0000001149710363_p954418308213"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p1954413307217"><a name="zh-cn_topic_0000001149710363_p1954413307217"></a><a name="zh-cn_topic_0000001149710363_p1954413307217"></a>版本类型</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row62397341828"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p3239123417216"><a name="zh-cn_topic_0000001149710363_p3239123417216"></a><a name="zh-cn_topic_0000001149710363_p3239123417216"></a>descriptionId</p>
</td>
<td class="cellrowborder" valign="top" width="23.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p11239163414218"><a name="zh-cn_topic_0000001149710363_p11239163414218"></a><a name="zh-cn_topic_0000001149710363_p11239163414218"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p923993420210"><a name="zh-cn_topic_0000001149710363_p923993420210"></a><a name="zh-cn_topic_0000001149710363_p923993420210"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p3240153419219"><a name="zh-cn_topic_0000001149710363_p3240153419219"></a><a name="zh-cn_topic_0000001149710363_p3240153419219"></a>版本描述信息</p>
</td>
</tr>
</tbody>
</table>

## DescriptionInfo<a name="zh-cn_topic_0000001149710363_section6472174588"></a>

版本描述信息

<a name="zh-cn_topic_0000001149710363_table4471817185814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001149710363_row12475176586"><th class="cellrowborder" valign="top" width="24.19%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001149710363_p1471517205811"><a name="zh-cn_topic_0000001149710363_p1471517205811"></a><a name="zh-cn_topic_0000001149710363_p1471517205811"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.07%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001149710363_p1447151725819"><a name="zh-cn_topic_0000001149710363_p1447151725819"></a><a name="zh-cn_topic_0000001149710363_p1447151725819"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.56%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001149710363_p747617205817"><a name="zh-cn_topic_0000001149710363_p747617205817"></a><a name="zh-cn_topic_0000001149710363_p747617205817"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.18%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001149710363_p1147181718583"><a name="zh-cn_topic_0000001149710363_p1147181718583"></a><a name="zh-cn_topic_0000001149710363_p1147181718583"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001149710363_row1147101716584"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p1699717119018"><a name="zh-cn_topic_0000001149710363_p1699717119018"></a><a name="zh-cn_topic_0000001149710363_p1699717119018"></a>descriptionId</p>
</td>
<td class="cellrowborder" valign="top" width="18.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p18539131605"><a name="zh-cn_topic_0000001149710363_p18539131605"></a><a name="zh-cn_topic_0000001149710363_p18539131605"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.56%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p247111712586"><a name="zh-cn_topic_0000001149710363_p247111712586"></a><a name="zh-cn_topic_0000001149710363_p247111712586"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p647181711582"><a name="zh-cn_topic_0000001149710363_p647181711582"></a><a name="zh-cn_topic_0000001149710363_p647181711582"></a>版本versionId信息</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001149710363_row748101735818"><td class="cellrowborder" valign="top" width="24.19%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001149710363_p43301364017"><a name="zh-cn_topic_0000001149710363_p43301364017"></a><a name="zh-cn_topic_0000001149710363_p43301364017"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="18.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001149710363_p248217145813"><a name="zh-cn_topic_0000001149710363_p248217145813"></a><a name="zh-cn_topic_0000001149710363_p248217145813"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.56%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001149710363_p144811171588"><a name="zh-cn_topic_0000001149710363_p144811171588"></a><a name="zh-cn_topic_0000001149710363_p144811171588"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.18%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001149710363_p64851712583"><a name="zh-cn_topic_0000001149710363_p64851712583"></a><a name="zh-cn_topic_0000001149710363_p64851712583"></a>版本changelog信息</p>
</td>
</tr>
</tbody>
</table>


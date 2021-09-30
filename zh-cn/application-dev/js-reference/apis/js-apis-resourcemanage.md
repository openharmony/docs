# 资源管理<a name="ZH-CN_TOPIC_0000001163977082"></a>

-   [导入模块](#zh-cn_topic_0000001163468626_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001163468626_section11257113618419)
-   [resourceManager.getResourceManager](#zh-cn_topic_0000001163468626_section192192415554)
-   [resourceManager.getResourceManager](#zh-cn_topic_0000001163468626_section46989284018)
-   [resourceManager.getResourceManager](#zh-cn_topic_0000001163468626_section0543541673)
-   [resourceManager.getResourceManager](#zh-cn_topic_0000001163468626_section1816951410716)
-   [Direction](#zh-cn_topic_0000001163468626_section099619567453)
-   [DeviceType](#zh-cn_topic_0000001163468626_section4734636131914)
-   [ScreenDensity](#zh-cn_topic_0000001163468626_section7331173812197)
-   [Configuration](#zh-cn_topic_0000001163468626_section12882825611)
    -   [属性](#zh-cn_topic_0000001163468626_section254242964810)

-   [DeviceCapability](#zh-cn_topic_0000001163468626_section7200123494410)
    -   [属性](#zh-cn_topic_0000001163468626_section2201153419440)

-   [ResourceManager](#zh-cn_topic_0000001163468626_section137771134135415)
    -   [getString](#zh-cn_topic_0000001163468626_section9779153419548)
    -   [getString](#zh-cn_topic_0000001163468626_section159261924165411)
    -   [getStringArray](#zh-cn_topic_0000001163468626_section4490132775420)
    -   [getStringArray](#zh-cn_topic_0000001163468626_section1992322017541)
    -   [getMedia](#zh-cn_topic_0000001163468626_section6710152513409)
    -   [getMedia](#zh-cn_topic_0000001163468626_section6711152517409)
    -   [getMediaBase64](#zh-cn_topic_0000001163468626_section11402326194315)
    -   [getMediaBase64](#zh-cn_topic_0000001163468626_section6404726124312)
    -   [getConfiguration](#zh-cn_topic_0000001163468626_section8123152874015)
    -   [getConfiguration](#zh-cn_topic_0000001163468626_section312515284406)
    -   [getDeviceCapability](#zh-cn_topic_0000001163468626_section104951210135017)
    -   [getDeviceCapability](#zh-cn_topic_0000001163468626_section114961410115013)
    -   [getPluralString](#zh-cn_topic_0000001163468626_section1549163064013)
    -   [getPluralString](#zh-cn_topic_0000001163468626_section165183015405)


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="zh-cn_topic_0000001163468626_s56d19203690d4782bfc74069abb6bd71"></a>

```
import resourceManager from '@ohos.resourceManager';
```

## 权限<a name="zh-cn_topic_0000001163468626_section11257113618419"></a>

无

## resourceManager.getResourceManager<a name="zh-cn_topic_0000001163468626_section192192415554"></a>

getResourceManager\(callback: AsyncCallback<ResourceManager\>\): void

获取当前应用的资源管理对象，使用callback形式返回ResourceManager对象。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p7966738914"><a name="zh-cn_topic_0000001163468626_p7966738914"></a><a name="zh-cn_topic_0000001163468626_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p296713699"><a name="zh-cn_topic_0000001163468626_p296713699"></a><a name="zh-cn_topic_0000001163468626_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p196718315911"><a name="zh-cn_topic_0000001163468626_p196718315911"></a><a name="zh-cn_topic_0000001163468626_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p9967231197"><a name="zh-cn_topic_0000001163468626_p9967231197"></a><a name="zh-cn_topic_0000001163468626_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p13838351705"><a name="zh-cn_topic_0000001163468626_p13838351705"></a><a name="zh-cn_topic_0000001163468626_p13838351705"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p11967433914"><a name="zh-cn_topic_0000001163468626_p11967433914"></a><a name="zh-cn_topic_0000001163468626_p11967433914"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001163468626_section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p19671336916"><a name="zh-cn_topic_0000001163468626_p19671336916"></a><a name="zh-cn_topic_0000001163468626_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p69671631796"><a name="zh-cn_topic_0000001163468626_p69671631796"></a><a name="zh-cn_topic_0000001163468626_p69671631796"></a>callback方式返回ResourceManager对象</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        if (error != null) {
            console.log("error occurs" + error);
            return; 
        }
        mgr.getString(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    
    ```


## resourceManager.getResourceManager<a name="zh-cn_topic_0000001163468626_section46989284018"></a>

getResourceManager\(bundleName: string, callback: AsyncCallback<ResourceManager\>\): void

获取指定应用的资源管理对象，使用callback形式返回ResourceManager对象。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table146992288015"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row16994286017"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p196991328500"><a name="zh-cn_topic_0000001163468626_p196991328500"></a><a name="zh-cn_topic_0000001163468626_p196991328500"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p156991028607"><a name="zh-cn_topic_0000001163468626_p156991028607"></a><a name="zh-cn_topic_0000001163468626_p156991028607"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.762631629794225%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p569920281005"><a name="zh-cn_topic_0000001163468626_p569920281005"></a><a name="zh-cn_topic_0000001163468626_p569920281005"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.211670370012556%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p5699428800"><a name="zh-cn_topic_0000001163468626_p5699428800"></a><a name="zh-cn_topic_0000001163468626_p5699428800"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row469912281801"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p46991028909"><a name="zh-cn_topic_0000001163468626_p46991028909"></a><a name="zh-cn_topic_0000001163468626_p46991028909"></a>bundleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p469919282017"><a name="zh-cn_topic_0000001163468626_p469919282017"></a><a name="zh-cn_topic_0000001163468626_p469919282017"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p169982812013"><a name="zh-cn_topic_0000001163468626_p169982812013"></a><a name="zh-cn_topic_0000001163468626_p169982812013"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p569972818014"><a name="zh-cn_topic_0000001163468626_p569972818014"></a><a name="zh-cn_topic_0000001163468626_p569972818014"></a>指定应用的Bundle名称</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row769982815012"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p10188114718716"><a name="zh-cn_topic_0000001163468626_p10188114718716"></a><a name="zh-cn_topic_0000001163468626_p10188114718716"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1518810471873"><a name="zh-cn_topic_0000001163468626_p1518810471873"></a><a name="zh-cn_topic_0000001163468626_p1518810471873"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001163468626_section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p718813478713"><a name="zh-cn_topic_0000001163468626_p718813478713"></a><a name="zh-cn_topic_0000001163468626_p718813478713"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1618844718710"><a name="zh-cn_topic_0000001163468626_p1618844718710"></a><a name="zh-cn_topic_0000001163468626_p1618844718710"></a>callback方式返回ResourceManager对象</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
    }
    ```


## resourceManager.getResourceManager<a name="zh-cn_topic_0000001163468626_section0543541673"></a>

getResourceManager\(\): Promise<ResourceManager\>

获取当前应用的资源管理对象，使用Promise形式返回ResourceManager对象。

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table125442040718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row11545745715"><th class="cellrowborder" valign="top" width="21.19%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p115451947716"><a name="zh-cn_topic_0000001163468626_p115451947716"></a><a name="zh-cn_topic_0000001163468626_p115451947716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.81%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p15451043716"><a name="zh-cn_topic_0000001163468626_p15451043716"></a><a name="zh-cn_topic_0000001163468626_p15451043716"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row55451841670"><td class="cellrowborder" valign="top" width="21.19%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p135451841712"><a name="zh-cn_topic_0000001163468626_p135451841712"></a><a name="zh-cn_topic_0000001163468626_p135451841712"></a>Promise&lt;<a href="#zh-cn_topic_0000001163468626_section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.81%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p954512419714"><a name="zh-cn_topic_0000001163468626_p954512419714"></a><a name="zh-cn_topic_0000001163468626_p954512419714"></a>Promise方式返回资源管理对象</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager().then(mgr => {
        mgr.getString(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }).catch(error => {
        console.log(error);
    });
    ```


## resourceManager.getResourceManager<a name="zh-cn_topic_0000001163468626_section1816951410716"></a>

getResourceManager\(bundleName: string\): Promise<ResourceManager\>

获取指定应用的资源管理对象，使用Promise形式返回ResourceManager对象。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table6169161415710"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row141691914878"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p191691114172"><a name="zh-cn_topic_0000001163468626_p191691114172"></a><a name="zh-cn_topic_0000001163468626_p191691114172"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p91690141774"><a name="zh-cn_topic_0000001163468626_p91690141774"></a><a name="zh-cn_topic_0000001163468626_p91690141774"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p1417013141074"><a name="zh-cn_topic_0000001163468626_p1417013141074"></a><a name="zh-cn_topic_0000001163468626_p1417013141074"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p1117051418716"><a name="zh-cn_topic_0000001163468626_p1117051418716"></a><a name="zh-cn_topic_0000001163468626_p1117051418716"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row1917061417717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p16466037131616"><a name="zh-cn_topic_0000001163468626_p16466037131616"></a><a name="zh-cn_topic_0000001163468626_p16466037131616"></a>bundleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p8466637101620"><a name="zh-cn_topic_0000001163468626_p8466637101620"></a><a name="zh-cn_topic_0000001163468626_p8466637101620"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p446633713162"><a name="zh-cn_topic_0000001163468626_p446633713162"></a><a name="zh-cn_topic_0000001163468626_p446633713162"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1446633701612"><a name="zh-cn_topic_0000001163468626_p1446633701612"></a><a name="zh-cn_topic_0000001163468626_p1446633701612"></a>指定应用的Bundle名称</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table51715149717"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row717151413717"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p917117141075"><a name="zh-cn_topic_0000001163468626_p917117141075"></a><a name="zh-cn_topic_0000001163468626_p917117141075"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p131716141778"><a name="zh-cn_topic_0000001163468626_p131716141778"></a><a name="zh-cn_topic_0000001163468626_p131716141778"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row1417116141579"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p1940551651713"><a name="zh-cn_topic_0000001163468626_p1940551651713"></a><a name="zh-cn_topic_0000001163468626_p1940551651713"></a>Promise&lt;<a href="#zh-cn_topic_0000001163468626_section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p140517164171"><a name="zh-cn_topic_0000001163468626_p140517164171"></a><a name="zh-cn_topic_0000001163468626_p140517164171"></a>Promise方式返回的资源管理对象</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager("com.example.myapplication").then(mgr => {
    
    }).catch(error => {
    
    });
    ```


## Direction<a name="zh-cn_topic_0000001163468626_section099619567453"></a>

用于表示设备屏幕方向。

<a name="zh-cn_topic_0000001163468626_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001163468626_a3d0fc780cc904c1cbab7991251622f65"><a name="zh-cn_topic_0000001163468626_a3d0fc780cc904c1cbab7991251622f65"></a><a name="zh-cn_topic_0000001163468626_a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001163468626_aace9cae4ba0d4939bfa048460f61c3c7"><a name="zh-cn_topic_0000001163468626_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="zh-cn_topic_0000001163468626_aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001163468626_afec895de33f94e3c87ee7acc20190a17"><a name="zh-cn_topic_0000001163468626_afec895de33f94e3c87ee7acc20190a17"></a><a name="zh-cn_topic_0000001163468626_afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163468626_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p26821854218"><a name="zh-cn_topic_0000001163468626_p26821854218"></a><a name="zh-cn_topic_0000001163468626_p26821854218"></a>DIRECTION_VERTICAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p2282152962115"><a name="zh-cn_topic_0000001163468626_p2282152962115"></a><a name="zh-cn_topic_0000001163468626_p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p328012293211"><a name="zh-cn_topic_0000001163468626_p328012293211"></a><a name="zh-cn_topic_0000001163468626_p328012293211"></a>竖屏</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p12106173918219"><a name="zh-cn_topic_0000001163468626_p12106173918219"></a><a name="zh-cn_topic_0000001163468626_p12106173918219"></a>DIRECTION_HORIZONTAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1310553911218"><a name="zh-cn_topic_0000001163468626_p1310553911218"></a><a name="zh-cn_topic_0000001163468626_p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p15865395215"><a name="zh-cn_topic_0000001163468626_p15865395215"></a><a name="zh-cn_topic_0000001163468626_p15865395215"></a>横屏</p>
</td>
</tr>
</tbody>
</table>

## DeviceType<a name="zh-cn_topic_0000001163468626_section4734636131914"></a>

用于表示当前设备类型。

<a name="zh-cn_topic_0000001163468626_table873411360193"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row187341036191911"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001163468626_p19735163661915"><a name="zh-cn_topic_0000001163468626_p19735163661915"></a><a name="zh-cn_topic_0000001163468626_p19735163661915"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001163468626_p12735173661913"><a name="zh-cn_topic_0000001163468626_p12735173661913"></a><a name="zh-cn_topic_0000001163468626_p12735173661913"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001163468626_p12735163611913"><a name="zh-cn_topic_0000001163468626_p12735163611913"></a><a name="zh-cn_topic_0000001163468626_p12735163611913"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163468626_row19735113619194"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p27351736111919"><a name="zh-cn_topic_0000001163468626_p27351736111919"></a><a name="zh-cn_topic_0000001163468626_p27351736111919"></a>DEVICE_TYPE_PHONE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p137351636131917"><a name="zh-cn_topic_0000001163468626_p137351636131917"></a><a name="zh-cn_topic_0000001163468626_p137351636131917"></a>0x00</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p1873543614192"><a name="zh-cn_topic_0000001163468626_p1873543614192"></a><a name="zh-cn_topic_0000001163468626_p1873543614192"></a>手机.</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row1956619491229"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p1456634917225"><a name="zh-cn_topic_0000001163468626_p1456634917225"></a><a name="zh-cn_topic_0000001163468626_p1456634917225"></a>DEVICE_TYPE_TABLET</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1256634982217"><a name="zh-cn_topic_0000001163468626_p1256634982217"></a><a name="zh-cn_topic_0000001163468626_p1256634982217"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p598213916331"><a name="zh-cn_topic_0000001163468626_p598213916331"></a><a name="zh-cn_topic_0000001163468626_p598213916331"></a>平板</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row57811744162211"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p47820449225"><a name="zh-cn_topic_0000001163468626_p47820449225"></a><a name="zh-cn_topic_0000001163468626_p47820449225"></a>DEVICE_TYPE_CAR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1878244417224"><a name="zh-cn_topic_0000001163468626_p1878244417224"></a><a name="zh-cn_topic_0000001163468626_p1878244417224"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p378213446229"><a name="zh-cn_topic_0000001163468626_p378213446229"></a><a name="zh-cn_topic_0000001163468626_p378213446229"></a>汽车</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row578284442218"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p117821445229"><a name="zh-cn_topic_0000001163468626_p117821445229"></a><a name="zh-cn_topic_0000001163468626_p117821445229"></a>DEVICE_TYPE_PC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p137821044172214"><a name="zh-cn_topic_0000001163468626_p137821044172214"></a><a name="zh-cn_topic_0000001163468626_p137821044172214"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p18782124422219"><a name="zh-cn_topic_0000001163468626_p18782124422219"></a><a name="zh-cn_topic_0000001163468626_p18782124422219"></a>电脑</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row84751140142210"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p0475184014225"><a name="zh-cn_topic_0000001163468626_p0475184014225"></a><a name="zh-cn_topic_0000001163468626_p0475184014225"></a>DEVICE_TYPE_TV</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1847519407228"><a name="zh-cn_topic_0000001163468626_p1847519407228"></a><a name="zh-cn_topic_0000001163468626_p1847519407228"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p44757409225"><a name="zh-cn_topic_0000001163468626_p44757409225"></a><a name="zh-cn_topic_0000001163468626_p44757409225"></a>电视</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row9735736161917"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p2073520364190"><a name="zh-cn_topic_0000001163468626_p2073520364190"></a><a name="zh-cn_topic_0000001163468626_p2073520364190"></a>DEVICE_TYPE_WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1273683612191"><a name="zh-cn_topic_0000001163468626_p1273683612191"></a><a name="zh-cn_topic_0000001163468626_p1273683612191"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p1873653617198"><a name="zh-cn_topic_0000001163468626_p1873653617198"></a><a name="zh-cn_topic_0000001163468626_p1873653617198"></a>穿戴</p>
</td>
</tr>
</tbody>
</table>

## ScreenDensity<a name="zh-cn_topic_0000001163468626_section7331173812197"></a>

用于表示当前设备屏幕密度。

<a name="zh-cn_topic_0000001163468626_table203311638181919"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row33311338101917"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001163468626_p733183811195"><a name="zh-cn_topic_0000001163468626_p733183811195"></a><a name="zh-cn_topic_0000001163468626_p733183811195"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.42%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001163468626_p1331163810197"><a name="zh-cn_topic_0000001163468626_p1331163810197"></a><a name="zh-cn_topic_0000001163468626_p1331163810197"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.68%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001163468626_p10331238191920"><a name="zh-cn_topic_0000001163468626_p10331238191920"></a><a name="zh-cn_topic_0000001163468626_p10331238191920"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163468626_row19331163821912"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p133311538131919"><a name="zh-cn_topic_0000001163468626_p133311538131919"></a><a name="zh-cn_topic_0000001163468626_p133311538131919"></a>SCREEN_SDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p833113385195"><a name="zh-cn_topic_0000001163468626_p833113385195"></a><a name="zh-cn_topic_0000001163468626_p833113385195"></a>120</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p1133133881918"><a name="zh-cn_topic_0000001163468626_p1133133881918"></a><a name="zh-cn_topic_0000001163468626_p1133133881918"></a>小规模的屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row1399293473011"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p599213418300"><a name="zh-cn_topic_0000001163468626_p599213418300"></a><a name="zh-cn_topic_0000001163468626_p599213418300"></a>SCREEN_MDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p1099210349304"><a name="zh-cn_topic_0000001163468626_p1099210349304"></a><a name="zh-cn_topic_0000001163468626_p1099210349304"></a>160</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p139921534173016"><a name="zh-cn_topic_0000001163468626_p139921534173016"></a><a name="zh-cn_topic_0000001163468626_p139921534173016"></a>中规模的屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row4841123016304"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p188417305309"><a name="zh-cn_topic_0000001163468626_p188417305309"></a><a name="zh-cn_topic_0000001163468626_p188417305309"></a>SCREEN_LDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p10841193014308"><a name="zh-cn_topic_0000001163468626_p10841193014308"></a><a name="zh-cn_topic_0000001163468626_p10841193014308"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p1084116309304"><a name="zh-cn_topic_0000001163468626_p1084116309304"></a><a name="zh-cn_topic_0000001163468626_p1084116309304"></a>大规模的屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row1784163013302"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p48413309304"><a name="zh-cn_topic_0000001163468626_p48413309304"></a><a name="zh-cn_topic_0000001163468626_p48413309304"></a>SCREEN_XLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p128411930183011"><a name="zh-cn_topic_0000001163468626_p128411930183011"></a><a name="zh-cn_topic_0000001163468626_p128411930183011"></a>320</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p084110301309"><a name="zh-cn_topic_0000001163468626_p084110301309"></a><a name="zh-cn_topic_0000001163468626_p084110301309"></a>特大规模的屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row1084092610308"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p128411926173012"><a name="zh-cn_topic_0000001163468626_p128411926173012"></a><a name="zh-cn_topic_0000001163468626_p128411926173012"></a>SCREEN_XXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p884192693019"><a name="zh-cn_topic_0000001163468626_p884192693019"></a><a name="zh-cn_topic_0000001163468626_p884192693019"></a>480</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p6841226163015"><a name="zh-cn_topic_0000001163468626_p6841226163015"></a><a name="zh-cn_topic_0000001163468626_p6841226163015"></a>超大规模的屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row11331163891916"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163468626_p14331163861914"><a name="zh-cn_topic_0000001163468626_p14331163861914"></a><a name="zh-cn_topic_0000001163468626_p14331163861914"></a>SCREEN_XXXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163468626_p933115383192"><a name="zh-cn_topic_0000001163468626_p933115383192"></a><a name="zh-cn_topic_0000001163468626_p933115383192"></a>640</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163468626_p199356496257"><a name="zh-cn_topic_0000001163468626_p199356496257"></a><a name="zh-cn_topic_0000001163468626_p199356496257"></a>超特大规模的屏幕密度</p>
</td>
</tr>
</tbody>
</table>

## Configuration<a name="zh-cn_topic_0000001163468626_section12882825611"></a>

表示当前设备的状态。

### 属性<a name="zh-cn_topic_0000001163468626_section254242964810"></a>

<a name="zh-cn_topic_0000001163468626_table1459620431636"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001163468626_p1559716434320"><a name="zh-cn_topic_0000001163468626_p1559716434320"></a><a name="zh-cn_topic_0000001163468626_p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001163468626_p3597743539"><a name="zh-cn_topic_0000001163468626_p3597743539"></a><a name="zh-cn_topic_0000001163468626_p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001163468626_p15971343131"><a name="zh-cn_topic_0000001163468626_p15971343131"></a><a name="zh-cn_topic_0000001163468626_p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001163468626_p1459715436311"><a name="zh-cn_topic_0000001163468626_p1459715436311"></a><a name="zh-cn_topic_0000001163468626_p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001163468626_p75975439316"><a name="zh-cn_topic_0000001163468626_p75975439316"></a><a name="zh-cn_topic_0000001163468626_p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163468626_row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163468626_p85976431431"><a name="zh-cn_topic_0000001163468626_p85976431431"></a><a name="zh-cn_topic_0000001163468626_p85976431431"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163468626_p2059710431030"><a name="zh-cn_topic_0000001163468626_p2059710431030"></a><a name="zh-cn_topic_0000001163468626_p2059710431030"></a><a href="#zh-cn_topic_0000001163468626_section099619567453">Direction</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163468626_p1059711439317"><a name="zh-cn_topic_0000001163468626_p1059711439317"></a><a name="zh-cn_topic_0000001163468626_p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163468626_p659715430317"><a name="zh-cn_topic_0000001163468626_p659715430317"></a><a name="zh-cn_topic_0000001163468626_p659715430317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163468626_p2059719436313"><a name="zh-cn_topic_0000001163468626_p2059719436313"></a><a name="zh-cn_topic_0000001163468626_p2059719436313"></a>当前设备屏幕方向</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163468626_p1559710432310"><a name="zh-cn_topic_0000001163468626_p1559710432310"></a><a name="zh-cn_topic_0000001163468626_p1559710432310"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163468626_p16597144318312"><a name="zh-cn_topic_0000001163468626_p16597144318312"></a><a name="zh-cn_topic_0000001163468626_p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163468626_p12597194313317"><a name="zh-cn_topic_0000001163468626_p12597194313317"></a><a name="zh-cn_topic_0000001163468626_p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163468626_p1259710431236"><a name="zh-cn_topic_0000001163468626_p1259710431236"></a><a name="zh-cn_topic_0000001163468626_p1259710431236"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163468626_p10597843034"><a name="zh-cn_topic_0000001163468626_p10597843034"></a><a name="zh-cn_topic_0000001163468626_p10597843034"></a>当前系统语言</p>
</td>
</tr>
</tbody>
</table>

## DeviceCapability<a name="zh-cn_topic_0000001163468626_section7200123494410"></a>

表示设备支持的能力。

### 属性<a name="zh-cn_topic_0000001163468626_section2201153419440"></a>

<a name="zh-cn_topic_0000001163468626_table16201103444414"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row620123444415"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001163468626_p1620163494418"><a name="zh-cn_topic_0000001163468626_p1620163494418"></a><a name="zh-cn_topic_0000001163468626_p1620163494418"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001163468626_p15201434124418"><a name="zh-cn_topic_0000001163468626_p15201434124418"></a><a name="zh-cn_topic_0000001163468626_p15201434124418"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001163468626_p13201123484412"><a name="zh-cn_topic_0000001163468626_p13201123484412"></a><a name="zh-cn_topic_0000001163468626_p13201123484412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001163468626_p1320123412448"><a name="zh-cn_topic_0000001163468626_p1320123412448"></a><a name="zh-cn_topic_0000001163468626_p1320123412448"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001163468626_p9201934134419"><a name="zh-cn_topic_0000001163468626_p9201934134419"></a><a name="zh-cn_topic_0000001163468626_p9201934134419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163468626_row3201103494415"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163468626_p20826502499"><a name="zh-cn_topic_0000001163468626_p20826502499"></a><a name="zh-cn_topic_0000001163468626_p20826502499"></a>screenDensity</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163468626_p120143413448"><a name="zh-cn_topic_0000001163468626_p120143413448"></a><a name="zh-cn_topic_0000001163468626_p120143413448"></a><a href="#zh-cn_topic_0000001163468626_section7331173812197">ScreenDensity</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163468626_p18201334114417"><a name="zh-cn_topic_0000001163468626_p18201334114417"></a><a name="zh-cn_topic_0000001163468626_p18201334114417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163468626_p420113347441"><a name="zh-cn_topic_0000001163468626_p420113347441"></a><a name="zh-cn_topic_0000001163468626_p420113347441"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163468626_p202021934134412"><a name="zh-cn_topic_0000001163468626_p202021934134412"></a><a name="zh-cn_topic_0000001163468626_p202021934134412"></a>当前设备屏幕密度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163468626_row19202113413445"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163468626_p82028341442"><a name="zh-cn_topic_0000001163468626_p82028341442"></a><a name="zh-cn_topic_0000001163468626_p82028341442"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163468626_p62021434104413"><a name="zh-cn_topic_0000001163468626_p62021434104413"></a><a name="zh-cn_topic_0000001163468626_p62021434104413"></a><a href="#zh-cn_topic_0000001163468626_section4734636131914">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163468626_p142021134164413"><a name="zh-cn_topic_0000001163468626_p142021134164413"></a><a name="zh-cn_topic_0000001163468626_p142021134164413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163468626_p22021834104417"><a name="zh-cn_topic_0000001163468626_p22021834104417"></a><a name="zh-cn_topic_0000001163468626_p22021834104417"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163468626_p112021341446"><a name="zh-cn_topic_0000001163468626_p112021341446"></a><a name="zh-cn_topic_0000001163468626_p112021341446"></a>当前设备类型</p>
</td>
</tr>
</tbody>
</table>

## ResourceManager<a name="zh-cn_topic_0000001163468626_section137771134135415"></a>

提供访问应用资源的能力。

### getString<a name="zh-cn_topic_0000001163468626_section9779153419548"></a>

getString\(resId: number, callback: AsyncCallback<string\>\): void

用户获取指定资源ID对应的字符串，使用callback形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table15779123455418"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row37791234125419"><th class="cellrowborder" valign="top" width="9.07%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1778018347547"><a name="zh-cn_topic_0000001163468626_p1778018347547"></a><a name="zh-cn_topic_0000001163468626_p1778018347547"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.48%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p12780113475417"><a name="zh-cn_topic_0000001163468626_p12780113475417"></a><a name="zh-cn_topic_0000001163468626_p12780113475417"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p137801834145410"><a name="zh-cn_topic_0000001163468626_p137801834145410"></a><a name="zh-cn_topic_0000001163468626_p137801834145410"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p1678053465414"><a name="zh-cn_topic_0000001163468626_p1678053465414"></a><a name="zh-cn_topic_0000001163468626_p1678053465414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row478015349541"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1978013410544"><a name="zh-cn_topic_0000001163468626_p1978013410544"></a><a name="zh-cn_topic_0000001163468626_p1978013410544"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p13780123410542"><a name="zh-cn_topic_0000001163468626_p13780123410542"></a><a name="zh-cn_topic_0000001163468626_p13780123410542"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p14780334145419"><a name="zh-cn_topic_0000001163468626_p14780334145419"></a><a name="zh-cn_topic_0000001163468626_p14780334145419"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p97801934185415"><a name="zh-cn_topic_0000001163468626_p97801934185415"></a><a name="zh-cn_topic_0000001163468626_p97801934185415"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row5780334175417"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1780113413548"><a name="zh-cn_topic_0000001163468626_p1780113413548"></a><a name="zh-cn_topic_0000001163468626_p1780113413548"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p5127248143016"><a name="zh-cn_topic_0000001163468626_p5127248143016"></a><a name="zh-cn_topic_0000001163468626_p5127248143016"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p778003485413"><a name="zh-cn_topic_0000001163468626_p778003485413"></a><a name="zh-cn_topic_0000001163468626_p778003485413"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p137801834105419"><a name="zh-cn_topic_0000001163468626_p137801834105419"></a><a name="zh-cn_topic_0000001163468626_p137801834105419"></a>异步回调，用于返回获取的字符串</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getString(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getString<a name="zh-cn_topic_0000001163468626_section159261924165411"></a>

getString\(resId: number\): Promise<string\>

用户获取指定资源ID对应的字符串，使用Promise形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table209261824205420"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row1492722415415"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1692782416547"><a name="zh-cn_topic_0000001163468626_p1692782416547"></a><a name="zh-cn_topic_0000001163468626_p1692782416547"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p189271240541"><a name="zh-cn_topic_0000001163468626_p189271240541"></a><a name="zh-cn_topic_0000001163468626_p189271240541"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p199271824205415"><a name="zh-cn_topic_0000001163468626_p199271824205415"></a><a name="zh-cn_topic_0000001163468626_p199271824205415"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p109270241547"><a name="zh-cn_topic_0000001163468626_p109270241547"></a><a name="zh-cn_topic_0000001163468626_p109270241547"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row2927132413546"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p135781232358"><a name="zh-cn_topic_0000001163468626_p135781232358"></a><a name="zh-cn_topic_0000001163468626_p135781232358"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p195781383513"><a name="zh-cn_topic_0000001163468626_p195781383513"></a><a name="zh-cn_topic_0000001163468626_p195781383513"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p16578439358"><a name="zh-cn_topic_0000001163468626_p16578439358"></a><a name="zh-cn_topic_0000001163468626_p16578439358"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p135783310357"><a name="zh-cn_topic_0000001163468626_p135783310357"></a><a name="zh-cn_topic_0000001163468626_p135783310357"></a>资源ID值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table1492913246542"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row169291824135411"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p15929132485415"><a name="zh-cn_topic_0000001163468626_p15929132485415"></a><a name="zh-cn_topic_0000001163468626_p15929132485415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p392918245541"><a name="zh-cn_topic_0000001163468626_p392918245541"></a><a name="zh-cn_topic_0000001163468626_p392918245541"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row1592992455414"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p179291924135420"><a name="zh-cn_topic_0000001163468626_p179291924135420"></a><a name="zh-cn_topic_0000001163468626_p179291924135420"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p17929142485416"><a name="zh-cn_topic_0000001163468626_p17929142485416"></a><a name="zh-cn_topic_0000001163468626_p17929142485416"></a>资源ID值对应的字符串</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getString(0x1000000).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getStringArray<a name="zh-cn_topic_0000001163468626_section4490132775420"></a>

getStringArray\(resId: number, callback: AsyncCallback<Array<string\>\>\): void

用户获取指定资源ID对应的字符串数组，使用callback形式返回字符串数组。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table104901227185415"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row1849042719548"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p2491727195416"><a name="zh-cn_topic_0000001163468626_p2491727195416"></a><a name="zh-cn_topic_0000001163468626_p2491727195416"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p449122775413"><a name="zh-cn_topic_0000001163468626_p449122775413"></a><a name="zh-cn_topic_0000001163468626_p449122775413"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p549117275549"><a name="zh-cn_topic_0000001163468626_p549117275549"></a><a name="zh-cn_topic_0000001163468626_p549117275549"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p4491152716543"><a name="zh-cn_topic_0000001163468626_p4491152716543"></a><a name="zh-cn_topic_0000001163468626_p4491152716543"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row84911027155414"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1738472410372"><a name="zh-cn_topic_0000001163468626_p1738472410372"></a><a name="zh-cn_topic_0000001163468626_p1738472410372"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1438462419379"><a name="zh-cn_topic_0000001163468626_p1438462419379"></a><a name="zh-cn_topic_0000001163468626_p1438462419379"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p13841524203711"><a name="zh-cn_topic_0000001163468626_p13841524203711"></a><a name="zh-cn_topic_0000001163468626_p13841524203711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p8384142493715"><a name="zh-cn_topic_0000001163468626_p8384142493715"></a><a name="zh-cn_topic_0000001163468626_p8384142493715"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row4491142717542"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p11384142443715"><a name="zh-cn_topic_0000001163468626_p11384142443715"></a><a name="zh-cn_topic_0000001163468626_p11384142443715"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1538472473719"><a name="zh-cn_topic_0000001163468626_p1538472473719"></a><a name="zh-cn_topic_0000001163468626_p1538472473719"></a>AsyncCallback&lt;Array&lt;string&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p18384132473713"><a name="zh-cn_topic_0000001163468626_p18384132473713"></a><a name="zh-cn_topic_0000001163468626_p18384132473713"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p8384132411379"><a name="zh-cn_topic_0000001163468626_p8384132411379"></a><a name="zh-cn_topic_0000001163468626_p8384132411379"></a>异步回调，用于返回获取的字符串数组</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getStringArray(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getStringArray<a name="zh-cn_topic_0000001163468626_section1992322017541"></a>

getStringArray\(resId: number\): Promise<Array<string\>\>

用户获取指定资源ID对应的字符串数组，使用Promise形式返回字符串数组。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table11924132005411"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row13924172017543"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1392442016541"><a name="zh-cn_topic_0000001163468626_p1392442016541"></a><a name="zh-cn_topic_0000001163468626_p1392442016541"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p0924920145417"><a name="zh-cn_topic_0000001163468626_p0924920145417"></a><a name="zh-cn_topic_0000001163468626_p0924920145417"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p392452011549"><a name="zh-cn_topic_0000001163468626_p392452011549"></a><a name="zh-cn_topic_0000001163468626_p392452011549"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p1992492065414"><a name="zh-cn_topic_0000001163468626_p1992492065414"></a><a name="zh-cn_topic_0000001163468626_p1992492065414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row15924220135414"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1451111743917"><a name="zh-cn_topic_0000001163468626_p1451111743917"></a><a name="zh-cn_topic_0000001163468626_p1451111743917"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p9511157113911"><a name="zh-cn_topic_0000001163468626_p9511157113911"></a><a name="zh-cn_topic_0000001163468626_p9511157113911"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p195117718397"><a name="zh-cn_topic_0000001163468626_p195117718397"></a><a name="zh-cn_topic_0000001163468626_p195117718397"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p151119713915"><a name="zh-cn_topic_0000001163468626_p151119713915"></a><a name="zh-cn_topic_0000001163468626_p151119713915"></a>资源ID值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table1492552055418"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row20925132035420"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p10925202010544"><a name="zh-cn_topic_0000001163468626_p10925202010544"></a><a name="zh-cn_topic_0000001163468626_p10925202010544"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p129269201544"><a name="zh-cn_topic_0000001163468626_p129269201544"></a><a name="zh-cn_topic_0000001163468626_p129269201544"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row119261820145419"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p179309445393"><a name="zh-cn_topic_0000001163468626_p179309445393"></a><a name="zh-cn_topic_0000001163468626_p179309445393"></a>Promise&lt;Array&lt;string&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p139301144153915"><a name="zh-cn_topic_0000001163468626_p139301144153915"></a><a name="zh-cn_topic_0000001163468626_p139301144153915"></a>资源ID值对应的字符串数组</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
         mgr.getStringArray(0x1000000).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getMedia<a name="zh-cn_topic_0000001163468626_section6710152513409"></a>

getMedia\(resId: number, callback: AsyncCallback<Uint8Array\>\): void

用户获取指定资源ID对应的媒体文件内容，使用callback形式返回字节数组。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table13710192554016"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row3710152534017"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p47108259406"><a name="zh-cn_topic_0000001163468626_p47108259406"></a><a name="zh-cn_topic_0000001163468626_p47108259406"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p2710102564013"><a name="zh-cn_topic_0000001163468626_p2710102564013"></a><a name="zh-cn_topic_0000001163468626_p2710102564013"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p17710525154014"><a name="zh-cn_topic_0000001163468626_p17710525154014"></a><a name="zh-cn_topic_0000001163468626_p17710525154014"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p771022517402"><a name="zh-cn_topic_0000001163468626_p771022517402"></a><a name="zh-cn_topic_0000001163468626_p771022517402"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row871062544010"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1871016257407"><a name="zh-cn_topic_0000001163468626_p1871016257407"></a><a name="zh-cn_topic_0000001163468626_p1871016257407"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1371002534015"><a name="zh-cn_topic_0000001163468626_p1371002534015"></a><a name="zh-cn_topic_0000001163468626_p1371002534015"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p16711122515403"><a name="zh-cn_topic_0000001163468626_p16711122515403"></a><a name="zh-cn_topic_0000001163468626_p16711122515403"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1271119257400"><a name="zh-cn_topic_0000001163468626_p1271119257400"></a><a name="zh-cn_topic_0000001163468626_p1271119257400"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row1971112524019"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p27111125204017"><a name="zh-cn_topic_0000001163468626_p27111125204017"></a><a name="zh-cn_topic_0000001163468626_p27111125204017"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1371152514409"><a name="zh-cn_topic_0000001163468626_p1371152514409"></a><a name="zh-cn_topic_0000001163468626_p1371152514409"></a>AsyncCallback&lt;Array&lt;Uint8Array&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p13711625124019"><a name="zh-cn_topic_0000001163468626_p13711625124019"></a><a name="zh-cn_topic_0000001163468626_p13711625124019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p8711172511406"><a name="zh-cn_topic_0000001163468626_p8711172511406"></a><a name="zh-cn_topic_0000001163468626_p8711172511406"></a>异步回调，用于返回获取的媒体文件内容</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMedia(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getMedia<a name="zh-cn_topic_0000001163468626_section6711152517409"></a>

getMedia\(resId: number\): Promise<Uint8Array\>

用户获取指定资源ID对应的媒体文件内容，使用Promise形式返回字节数组。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table10711725154015"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row8712225154016"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p371210253407"><a name="zh-cn_topic_0000001163468626_p371210253407"></a><a name="zh-cn_topic_0000001163468626_p371210253407"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p771214253404"><a name="zh-cn_topic_0000001163468626_p771214253404"></a><a name="zh-cn_topic_0000001163468626_p771214253404"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p171242574017"><a name="zh-cn_topic_0000001163468626_p171242574017"></a><a name="zh-cn_topic_0000001163468626_p171242574017"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p6712725114013"><a name="zh-cn_topic_0000001163468626_p6712725114013"></a><a name="zh-cn_topic_0000001163468626_p6712725114013"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row971232544013"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p67126252406"><a name="zh-cn_topic_0000001163468626_p67126252406"></a><a name="zh-cn_topic_0000001163468626_p67126252406"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p12712425114012"><a name="zh-cn_topic_0000001163468626_p12712425114012"></a><a name="zh-cn_topic_0000001163468626_p12712425114012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p19712152511403"><a name="zh-cn_topic_0000001163468626_p19712152511403"></a><a name="zh-cn_topic_0000001163468626_p19712152511403"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p8712162564019"><a name="zh-cn_topic_0000001163468626_p8712162564019"></a><a name="zh-cn_topic_0000001163468626_p8712162564019"></a>资源ID值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table271292534018"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row1971352524020"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p9713925104011"><a name="zh-cn_topic_0000001163468626_p9713925104011"></a><a name="zh-cn_topic_0000001163468626_p9713925104011"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p471352574010"><a name="zh-cn_topic_0000001163468626_p471352574010"></a><a name="zh-cn_topic_0000001163468626_p471352574010"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row9713142554012"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p1071352554019"><a name="zh-cn_topic_0000001163468626_p1071352554019"></a><a name="zh-cn_topic_0000001163468626_p1071352554019"></a>Promise&lt;Array&lt;Uint8Array&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p8713192517405"><a name="zh-cn_topic_0000001163468626_p8713192517405"></a><a name="zh-cn_topic_0000001163468626_p8713192517405"></a>资源ID值对应的媒体文件内容</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMedia(0x1000000).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getMediaBase64<a name="zh-cn_topic_0000001163468626_section11402326194315"></a>

getMediaBase64\(resId: number, callback: AsyncCallback<string\>\): void

用户获取指定资源ID对应的图片资源Base64编码，使用callback形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table1740272614430"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row540272684311"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1340272624311"><a name="zh-cn_topic_0000001163468626_p1340272624311"></a><a name="zh-cn_topic_0000001163468626_p1340272624311"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p8402192617438"><a name="zh-cn_topic_0000001163468626_p8402192617438"></a><a name="zh-cn_topic_0000001163468626_p8402192617438"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p1440222674312"><a name="zh-cn_topic_0000001163468626_p1440222674312"></a><a name="zh-cn_topic_0000001163468626_p1440222674312"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p11403926164312"><a name="zh-cn_topic_0000001163468626_p11403926164312"></a><a name="zh-cn_topic_0000001163468626_p11403926164312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row54031726114310"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p114031326154312"><a name="zh-cn_topic_0000001163468626_p114031326154312"></a><a name="zh-cn_topic_0000001163468626_p114031326154312"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1040382604313"><a name="zh-cn_topic_0000001163468626_p1040382604313"></a><a name="zh-cn_topic_0000001163468626_p1040382604313"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p94035265431"><a name="zh-cn_topic_0000001163468626_p94035265431"></a><a name="zh-cn_topic_0000001163468626_p94035265431"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1140392612434"><a name="zh-cn_topic_0000001163468626_p1140392612434"></a><a name="zh-cn_topic_0000001163468626_p1140392612434"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row12403192615432"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p14031226144319"><a name="zh-cn_topic_0000001163468626_p14031226144319"></a><a name="zh-cn_topic_0000001163468626_p14031226144319"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1740382618433"><a name="zh-cn_topic_0000001163468626_p1740382618433"></a><a name="zh-cn_topic_0000001163468626_p1740382618433"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p144032026104313"><a name="zh-cn_topic_0000001163468626_p144032026104313"></a><a name="zh-cn_topic_0000001163468626_p144032026104313"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p18403142618437"><a name="zh-cn_topic_0000001163468626_p18403142618437"></a><a name="zh-cn_topic_0000001163468626_p18403142618437"></a>异步回调，用于返回获取的图片资源Base64编码</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMediaBase64(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getMediaBase64<a name="zh-cn_topic_0000001163468626_section6404726124312"></a>

getMediaBase64\(resId: number\): Promise<string\>

用户获取指定资源ID对应的图片资源Base64编码，使用Promise形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table1840452674318"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row84041226184317"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p5404926154316"><a name="zh-cn_topic_0000001163468626_p5404926154316"></a><a name="zh-cn_topic_0000001163468626_p5404926154316"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p194048268435"><a name="zh-cn_topic_0000001163468626_p194048268435"></a><a name="zh-cn_topic_0000001163468626_p194048268435"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p184041226104320"><a name="zh-cn_topic_0000001163468626_p184041226104320"></a><a name="zh-cn_topic_0000001163468626_p184041226104320"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p12404726184315"><a name="zh-cn_topic_0000001163468626_p12404726184315"></a><a name="zh-cn_topic_0000001163468626_p12404726184315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row8404126124314"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p104051426104313"><a name="zh-cn_topic_0000001163468626_p104051426104313"></a><a name="zh-cn_topic_0000001163468626_p104051426104313"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p15405172610430"><a name="zh-cn_topic_0000001163468626_p15405172610430"></a><a name="zh-cn_topic_0000001163468626_p15405172610430"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p240582616430"><a name="zh-cn_topic_0000001163468626_p240582616430"></a><a name="zh-cn_topic_0000001163468626_p240582616430"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p124051726104318"><a name="zh-cn_topic_0000001163468626_p124051726104318"></a><a name="zh-cn_topic_0000001163468626_p124051726104318"></a>资源ID值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table1240514269437"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row1240532620433"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p1406202614313"><a name="zh-cn_topic_0000001163468626_p1406202614313"></a><a name="zh-cn_topic_0000001163468626_p1406202614313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p8406226124316"><a name="zh-cn_topic_0000001163468626_p8406226124316"></a><a name="zh-cn_topic_0000001163468626_p8406226124316"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row164065261435"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p5406182612436"><a name="zh-cn_topic_0000001163468626_p5406182612436"></a><a name="zh-cn_topic_0000001163468626_p5406182612436"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p3406182612434"><a name="zh-cn_topic_0000001163468626_p3406182612434"></a><a name="zh-cn_topic_0000001163468626_p3406182612434"></a>资源ID值对应的图片资源Base64编码</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMediaBase64(0x1000000).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getConfiguration<a name="zh-cn_topic_0000001163468626_section8123152874015"></a>

getConfiguration\(callback: AsyncCallback<Configuration\>\): void

用户获取设备的Configuration，使用callback形式返回Configuration对象。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table15123112811401"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row13123102844013"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1812311285406"><a name="zh-cn_topic_0000001163468626_p1812311285406"></a><a name="zh-cn_topic_0000001163468626_p1812311285406"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p101239284409"><a name="zh-cn_topic_0000001163468626_p101239284409"></a><a name="zh-cn_topic_0000001163468626_p101239284409"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p41236289403"><a name="zh-cn_topic_0000001163468626_p41236289403"></a><a name="zh-cn_topic_0000001163468626_p41236289403"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p201231228164019"><a name="zh-cn_topic_0000001163468626_p201231228164019"></a><a name="zh-cn_topic_0000001163468626_p201231228164019"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row141241285400"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p812452814012"><a name="zh-cn_topic_0000001163468626_p812452814012"></a><a name="zh-cn_topic_0000001163468626_p812452814012"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p1412420284405"><a name="zh-cn_topic_0000001163468626_p1412420284405"></a><a name="zh-cn_topic_0000001163468626_p1412420284405"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001163468626_section12882825611">Configuration</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p10124122817403"><a name="zh-cn_topic_0000001163468626_p10124122817403"></a><a name="zh-cn_topic_0000001163468626_p10124122817403"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p161241028184011"><a name="zh-cn_topic_0000001163468626_p161241028184011"></a><a name="zh-cn_topic_0000001163468626_p161241028184011"></a>异步回调，用于返回设备的Configuration</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getConfiguration((error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getConfiguration<a name="zh-cn_topic_0000001163468626_section312515284406"></a>

getConfiguration\(\): Promise<Configuration\>

用户获取设备的Configuration，使用Promise形式返回Configuration对象。

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table12126228134013"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row11126728184016"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p191261028174019"><a name="zh-cn_topic_0000001163468626_p191261028174019"></a><a name="zh-cn_topic_0000001163468626_p191261028174019"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p6126202894018"><a name="zh-cn_topic_0000001163468626_p6126202894018"></a><a name="zh-cn_topic_0000001163468626_p6126202894018"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row8126728174017"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p112718283409"><a name="zh-cn_topic_0000001163468626_p112718283409"></a><a name="zh-cn_topic_0000001163468626_p112718283409"></a>Promise&lt;<a href="#zh-cn_topic_0000001163468626_section12882825611">Configuration</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p1412792864011"><a name="zh-cn_topic_0000001163468626_p1412792864011"></a><a name="zh-cn_topic_0000001163468626_p1412792864011"></a>设备的Configuration</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getConfiguration().then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getDeviceCapability<a name="zh-cn_topic_0000001163468626_section104951210135017"></a>

getDeviceCapability\(callback: AsyncCallback<DeviceCapability\>\): void

用户获取设备的DeviceCapability，使用callback形式返回DeviceCapability对象。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table1495410115014"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row649514108507"><th class="cellrowborder" valign="top" width="8.7%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p54957102501"><a name="zh-cn_topic_0000001163468626_p54957102501"></a><a name="zh-cn_topic_0000001163468626_p54957102501"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.69%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p649531011504"><a name="zh-cn_topic_0000001163468626_p649531011504"></a><a name="zh-cn_topic_0000001163468626_p649531011504"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.319999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p74954109501"><a name="zh-cn_topic_0000001163468626_p74954109501"></a><a name="zh-cn_topic_0000001163468626_p74954109501"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p174951910155019"><a name="zh-cn_topic_0000001163468626_p174951910155019"></a><a name="zh-cn_topic_0000001163468626_p174951910155019"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row11495710115015"><td class="cellrowborder" valign="top" width="8.7%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p154951510185014"><a name="zh-cn_topic_0000001163468626_p154951510185014"></a><a name="zh-cn_topic_0000001163468626_p154951510185014"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.69%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p174955105509"><a name="zh-cn_topic_0000001163468626_p174955105509"></a><a name="zh-cn_topic_0000001163468626_p174955105509"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001163468626_section7200123494410">DeviceCapability</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.319999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p1495121012501"><a name="zh-cn_topic_0000001163468626_p1495121012501"></a><a name="zh-cn_topic_0000001163468626_p1495121012501"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p54969103507"><a name="zh-cn_topic_0000001163468626_p54969103507"></a><a name="zh-cn_topic_0000001163468626_p54969103507"></a>异步回调，用于返回设备的DeviceCapability</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getDeviceCapability((error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getDeviceCapability<a name="zh-cn_topic_0000001163468626_section114961410115013"></a>

getDeviceCapability\(\): Promise<DeviceCapability\>

用户获取设备的DeviceCapability，使用Promise形式返回DeviceCapability对象。

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table17496111015019"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row12496111095010"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p1496101015503"><a name="zh-cn_topic_0000001163468626_p1496101015503"></a><a name="zh-cn_topic_0000001163468626_p1496101015503"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p1496110155013"><a name="zh-cn_topic_0000001163468626_p1496110155013"></a><a name="zh-cn_topic_0000001163468626_p1496110155013"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row10496181065014"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p19497151095012"><a name="zh-cn_topic_0000001163468626_p19497151095012"></a><a name="zh-cn_topic_0000001163468626_p19497151095012"></a>Promise&lt;<a href="#zh-cn_topic_0000001163468626_section7200123494410">DeviceCapability</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p18497141011504"><a name="zh-cn_topic_0000001163468626_p18497141011504"></a><a name="zh-cn_topic_0000001163468626_p18497141011504"></a>设备的DeviceCapability</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getDeviceCapability().then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```


### getPluralString<a name="zh-cn_topic_0000001163468626_section1549163064013"></a>

getPluralString\(resId: number, num: number, callback: AsyncCallback<string\>\): void

根据指定数量获取指定ID字符串表示的单复数字符串，使用callback形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table649330164020"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row6491302400"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1749123034017"><a name="zh-cn_topic_0000001163468626_p1749123034017"></a><a name="zh-cn_topic_0000001163468626_p1749123034017"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p449143064012"><a name="zh-cn_topic_0000001163468626_p449143064012"></a><a name="zh-cn_topic_0000001163468626_p449143064012"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p1349123044017"><a name="zh-cn_topic_0000001163468626_p1349123044017"></a><a name="zh-cn_topic_0000001163468626_p1349123044017"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p11491302408"><a name="zh-cn_topic_0000001163468626_p11491302408"></a><a name="zh-cn_topic_0000001163468626_p11491302408"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row145013054010"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p65073012401"><a name="zh-cn_topic_0000001163468626_p65073012401"></a><a name="zh-cn_topic_0000001163468626_p65073012401"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p11502030124016"><a name="zh-cn_topic_0000001163468626_p11502030124016"></a><a name="zh-cn_topic_0000001163468626_p11502030124016"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p1650330174019"><a name="zh-cn_topic_0000001163468626_p1650330174019"></a><a name="zh-cn_topic_0000001163468626_p1650330174019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1650163034013"><a name="zh-cn_topic_0000001163468626_p1650163034013"></a><a name="zh-cn_topic_0000001163468626_p1650163034013"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row18497201611531"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1949711615318"><a name="zh-cn_topic_0000001163468626_p1949711615318"></a><a name="zh-cn_topic_0000001163468626_p1949711615318"></a>num</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p13497191615532"><a name="zh-cn_topic_0000001163468626_p13497191615532"></a><a name="zh-cn_topic_0000001163468626_p13497191615532"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p9497716125311"><a name="zh-cn_topic_0000001163468626_p9497716125311"></a><a name="zh-cn_topic_0000001163468626_p9497716125311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p249771619536"><a name="zh-cn_topic_0000001163468626_p249771619536"></a><a name="zh-cn_topic_0000001163468626_p249771619536"></a>数量值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row45053011403"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p1650230204016"><a name="zh-cn_topic_0000001163468626_p1650230204016"></a><a name="zh-cn_topic_0000001163468626_p1650230204016"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p165010302401"><a name="zh-cn_topic_0000001163468626_p165010302401"></a><a name="zh-cn_topic_0000001163468626_p165010302401"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p7501530164018"><a name="zh-cn_topic_0000001163468626_p7501530164018"></a><a name="zh-cn_topic_0000001163468626_p7501530164018"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p17501330104012"><a name="zh-cn_topic_0000001163468626_p17501330104012"></a><a name="zh-cn_topic_0000001163468626_p17501330104012"></a>异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getPluralString(0x1000000, 1, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }
    ```


### getPluralString<a name="zh-cn_topic_0000001163468626_section165183015405"></a>

getPluralString\(resId: number, num: number\): Promise<string\>

根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise形式返回字符串。

-   参数：

    <a name="zh-cn_topic_0000001163468626_table105173016408"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row195223064018"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163468626_p1752183064013"><a name="zh-cn_topic_0000001163468626_p1752183064013"></a><a name="zh-cn_topic_0000001163468626_p1752183064013"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163468626_p175273064016"><a name="zh-cn_topic_0000001163468626_p175273064016"></a><a name="zh-cn_topic_0000001163468626_p175273064016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163468626_p1452430124014"><a name="zh-cn_topic_0000001163468626_p1452430124014"></a><a name="zh-cn_topic_0000001163468626_p1452430124014"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163468626_p9525305406"><a name="zh-cn_topic_0000001163468626_p9525305406"></a><a name="zh-cn_topic_0000001163468626_p9525305406"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row65233019409"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p125213301405"><a name="zh-cn_topic_0000001163468626_p125213301405"></a><a name="zh-cn_topic_0000001163468626_p125213301405"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p55293019409"><a name="zh-cn_topic_0000001163468626_p55293019409"></a><a name="zh-cn_topic_0000001163468626_p55293019409"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p553103094019"><a name="zh-cn_topic_0000001163468626_p553103094019"></a><a name="zh-cn_topic_0000001163468626_p553103094019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p1453430124015"><a name="zh-cn_topic_0000001163468626_p1453430124015"></a><a name="zh-cn_topic_0000001163468626_p1453430124015"></a>资源ID值</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163468626_row05323013406"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163468626_p197652617548"><a name="zh-cn_topic_0000001163468626_p197652617548"></a><a name="zh-cn_topic_0000001163468626_p197652617548"></a>num</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163468626_p187651685411"><a name="zh-cn_topic_0000001163468626_p187651685411"></a><a name="zh-cn_topic_0000001163468626_p187651685411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163468626_p776517611543"><a name="zh-cn_topic_0000001163468626_p776517611543"></a><a name="zh-cn_topic_0000001163468626_p776517611543"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163468626_p2076646145413"><a name="zh-cn_topic_0000001163468626_p2076646145413"></a><a name="zh-cn_topic_0000001163468626_p2076646145413"></a>数量值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163468626_table45313011403"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163468626_row554133016401"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163468626_p13549300401"><a name="zh-cn_topic_0000001163468626_p13549300401"></a><a name="zh-cn_topic_0000001163468626_p13549300401"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163468626_p75419307408"><a name="zh-cn_topic_0000001163468626_p75419307408"></a><a name="zh-cn_topic_0000001163468626_p75419307408"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163468626_row1554143094015"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163468626_p115483064019"><a name="zh-cn_topic_0000001163468626_p115483064019"></a><a name="zh-cn_topic_0000001163468626_p115483064019"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163468626_p1965948111118"><a name="zh-cn_topic_0000001163468626_p1965948111118"></a><a name="zh-cn_topic_0000001163468626_p1965948111118"></a>根据提供的数量获取对应ID字符串表示的单复数字符串</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getPluralString(0x1000000, 1).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    }
    ```



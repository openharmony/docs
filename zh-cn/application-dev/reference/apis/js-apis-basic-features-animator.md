# 动画<a name="ZH-CN_TOPIC_0000001127125026"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 6 开始支持。

## 导入模块<a name="s0e7b1e85a4274f58a8206e0b065bd80c"></a>

requestAnimationFrame：无需导入

cancelAnimationFrame：无需导入

createAnimator：

```
import animator from '@ohos.animator';
```

## 权限列表<a name="section11257113618419"></a>

无

## requestAnimationFrame<a name="s298a3cf59a3b470dbb0742706102ced7"></a>

requestAnimationFrame\(handler\[, \[ ...args\]\]\): number

请求动画帧，逐帧回调JS函数。

-   参数

    <a name="t87748b0ba4e648079d53f9deccf4bfb2"></a>
    <table><thead align="left"><tr id="rc5033ad045c14c2e806d59041aab002c"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="acf783ab6043e4ee1a7bb73b73a091e0b"><a name="acf783ab6043e4ee1a7bb73b73a091e0b"></a><a name="acf783ab6043e4ee1a7bb73b73a091e0b"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="a6736505551534b819d5a6376065a25f6"><a name="a6736505551534b819d5a6376065a25f6"></a><a name="a6736505551534b819d5a6376065a25f6"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="ac15c2a3de0e046af917cf09b48b3b46d"><a name="ac15c2a3de0e046af917cf09b48b3b46d"></a><a name="ac15c2a3de0e046af917cf09b48b3b46d"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="aeb94b88e78974288bab1b4940b50c840"><a name="aeb94b88e78974288bab1b4940b50c840"></a><a name="aeb94b88e78974288bab1b4940b50c840"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r95c56d5cd62d4b518c3e7a3f158ed7fe"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="a7af41aec9a404f418202d90c61774825"><a name="a7af41aec9a404f418202d90c61774825"></a><a name="a7af41aec9a404f418202d90c61774825"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="aed6ae868d61349afa8f0e250108f8e47"><a name="aed6ae868d61349afa8f0e250108f8e47"></a><a name="aed6ae868d61349afa8f0e250108f8e47"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="ab72ac8cc02e34da4b717ca144fc521c1"><a name="ab72ac8cc02e34da4b717ca144fc521c1"></a><a name="ab72ac8cc02e34da4b717ca144fc521c1"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="ac53e6549d32f413e9c51cd8a53f4650a"><a name="ac53e6549d32f413e9c51cd8a53f4650a"></a><a name="ac53e6549d32f413e9c51cd8a53f4650a"></a>表示要逐帧回调的函数。requestAnimationFrame函数回调handler函数时会在第一个参数位置传入timestamp时间戳。它表示requestAnimationFrame开始去执行回调函数的时刻。</p>
    </td>
    </tr>
    <tr id="row8497154383016"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1497174316302"><a name="p1497174316302"></a><a name="p1497174316302"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="p1649714393019"><a name="p1649714393019"></a><a name="p1649714393019"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p12498154363014"><a name="p12498154363014"></a><a name="p12498154363014"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p049816437303"><a name="p049816437303"></a><a name="p049816437303"></a>附加参数，函数回调时，他们会作为参数传递给handler。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table1430416594311"></a>
    <table><thead align="left"><tr id="row230485973113"><th class="cellrowborder" valign="top" width="12.18%" id="mcps1.1.3.1.1"><p id="p430405913312"><a name="p430405913312"></a><a name="p430405913312"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.82%" id="mcps1.1.3.1.2"><p id="p830413599312"><a name="p830413599312"></a><a name="p830413599312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row130435914317"><td class="cellrowborder" valign="top" width="12.18%" headers="mcps1.1.3.1.1 "><p id="p4305759143119"><a name="p4305759143119"></a><a name="p4305759143119"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.82%" headers="mcps1.1.3.1.2 "><p id="p130555923110"><a name="p130555923110"></a><a name="p130555923110"></a>requestID请求的ID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- xxx.hml -->
    <div class="container">
      <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
      height: 100%;
    }
    .btn{
      width: 300px;
      margin-top: 40px;
    }
    ```

    ```
    /* xxx.js */
    export default {
      data: {
        requestId: 0,
        startTime: 0,
      },
      beginAnimation() {
        cancelAnimationFrame(this.requestId);
        this.requestId = requestAnimationFrame(this.runAnimation);
      },
      runAnimation(timestamp) {
        if (this.startTime == 0) {
          this.startTime = timestamp;
        }
        var elapsed = timestamp - this.startTime;
        if (elapsed < 500) {
          console.log('callback handler timestamp: ' + timestamp);
          this.requestId = requestAnimationFrame(this.runAnimation);
        }
      }
    }
    ```


## cancelAnimationFrame<a name="section114651915245"></a>

cancelAnimationFrame\(requestId: number\): void

取消动画帧，取消逐帧回调请求。

-   参数

    <a name="table25491571214"></a>
    <table><thead align="left"><tr id="row1954910577117"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="p1854918574119"><a name="p1854918574119"></a><a name="p1854918574119"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="p17549195713119"><a name="p17549195713119"></a><a name="p17549195713119"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="p1654910571912"><a name="p1654910571912"></a><a name="p1654910571912"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p185491057813"><a name="p185491057813"></a><a name="p185491057813"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row05492571017"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p11549057812"><a name="p11549057812"></a><a name="p11549057812"></a>requestId</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="p1454910571915"><a name="p1454910571915"></a><a name="p1454910571915"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p195491657811"><a name="p195491657811"></a><a name="p195491657811"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p165492579116"><a name="p165492579116"></a><a name="p165492579116"></a>逐帧回调函数的标识id。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- xxx.hml -->
    <div class="container">
      <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
      <button type="capsule" class="btn" onclick="beginAnimation">stopAnimation</button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
      height: 100%;
    }
    .btn{
      width: 300px;
      margin-top: 40px;
    }
    ```

    ```
    /* xxx.js */
    export default {
      data: {
        requestId: 0,
        startTime: 0,
      },
      beginAnimation() {
        cancelAnimationFrame(this.requestId);
        this.requestId = requestAnimationFrame(this.runAnimation);
      },
      runAnimation(timestamp) {
        if (this.startTime == 0) {
          this.startTime = timestamp;
        }
        var elapsed = timestamp - this.startTime;
        if (elapsed < 500) {
          console.log('callback handler timestamp: ' + timestamp);
          this.requestId = requestAnimationFrame(this.runAnimation);
        }
      },
      stopAnimation() {
        cancelAnimationFrame(this.requestId);
      }
    }
    ```


## createAnimator<a name="section333714110229"></a>

createAnimator\(options\[...\]\): void

创建动画对象。

-   参数

    <a name="table1210814218489"></a>
    <table><thead align="left"><tr id="row16108162112483"><th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.1.5.1.1"><p id="p9108102124816"><a name="p9108102124816"></a><a name="p9108102124816"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.97%" id="mcps1.1.5.1.2"><p id="p15108921134810"><a name="p15108921134810"></a><a name="p15108921134810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="p610832174811"><a name="p610832174811"></a><a name="p610832174811"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p20109102115481"><a name="p20109102115481"></a><a name="p20109102115481"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111091721194810"><td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p191091121114816"><a name="p191091121114816"></a><a name="p191091121114816"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.1.5.1.2 "><p id="p51091212484"><a name="p51091212484"></a><a name="p51091212484"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p17109112111489"><a name="p17109112111489"></a><a name="p17109112111489"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p9109221104814"><a name="p9109221104814"></a><a name="p9109221104814"></a>表示待创建Animator对象的属性，详情见下表options说明。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   options说明

    <a name="table185831411112210"></a>
    <table><thead align="left"><tr id="row13579511112217"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="p6578111142211"><a name="p6578111142211"></a><a name="p6578111142211"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.2"><p id="p8578811182212"><a name="p8578811182212"></a><a name="p8578811182212"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.5.1.3"><p id="p557961122219"><a name="p557961122219"></a><a name="p557961122219"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p14579101116224"><a name="p14579101116224"></a><a name="p14579101116224"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row125801711102218"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1857912118220"><a name="p1857912118220"></a><a name="p1857912118220"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p45798110229"><a name="p45798110229"></a><a name="p45798110229"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p35793112223"><a name="p35793112223"></a><a name="p35793112223"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p17580011172219"><a name="p17580011172219"></a><a name="p17580011172219"></a>动画播放的时长，单位毫秒，默认为0。</p>
    </td>
    </tr>
    <tr id="row55801511172212"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p14580711152210"><a name="p14580711152210"></a><a name="p14580711152210"></a>easing</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p19580141112217"><a name="p19580141112217"></a><a name="p19580141112217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p658021122212"><a name="p658021122212"></a><a name="p658021122212"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p18580121112212"><a name="p18580121112212"></a><a name="p18580121112212"></a>动画插值曲线，默认为' ease '。</p>
    </td>
    </tr>
    <tr id="row558071118228"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1580111117227"><a name="p1580111117227"></a><a name="p1580111117227"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p6580111102215"><a name="p6580111102215"></a><a name="p6580111102215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p1258016113229"><a name="p1258016113229"></a><a name="p1258016113229"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p858021152215"><a name="p858021152215"></a><a name="p858021152215"></a>动画延时播放时长，单位毫秒，默认为0，即不延时。</p>
    </td>
    </tr>
    <tr id="row1358151113223"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1358119115228"><a name="p1358119115228"></a><a name="p1358119115228"></a>fill</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p15581211132210"><a name="p15581211132210"></a><a name="p15581211132210"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p1458171119226"><a name="p1458171119226"></a><a name="p1458171119226"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p185811411172213"><a name="p185811411172213"></a><a name="p185811411172213"></a>动画启停模式，默认值none，详情见：<a href="../js-based-web-like-development-paradigm/js-components-common-animation.md#p886655314713">animation-fill-mode</a></p>
    </td>
    </tr>
    <tr id="row18581811142219"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p75817112225"><a name="p75817112225"></a><a name="p75817112225"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1258118115221"><a name="p1258118115221"></a><a name="p1258118115221"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p17581211122213"><a name="p17581211122213"></a><a name="p17581211122213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p195811211152214"><a name="p195811211152214"></a><a name="p195811211152214"></a>动画播放模式，默认值normal，详情见：<a href="../js-based-web-like-development-paradigm/js-components-common-animation.md#p2611151295818">animation-direction</a></p>
    </td>
    </tr>
    <tr id="row55821511122210"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p16581171118226"><a name="p16581171118226"></a><a name="p16581171118226"></a>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1582151113228"><a name="p1582151113228"></a><a name="p1582151113228"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p205821311132214"><a name="p205821311132214"></a><a name="p205821311132214"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p1458201118221"><a name="p1458201118221"></a><a name="p1458201118221"></a>动画播放次数，默认值1，设置为0时不播放，设置为-1时无限次播放。</p>
    </td>
    </tr>
    <tr id="row1958211116223"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p205821811152213"><a name="p205821811152213"></a><a name="p205821811152213"></a>begin</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p10582211122219"><a name="p10582211122219"></a><a name="p10582211122219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p758281111223"><a name="p758281111223"></a><a name="p758281111223"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p105820113229"><a name="p105820113229"></a><a name="p105820113229"></a>动画插值起点，不设置时默认为0。</p>
    </td>
    </tr>
    <tr id="row12583191192217"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p55828118227"><a name="p55828118227"></a><a name="p55828118227"></a>end</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1958231192220"><a name="p1958231192220"></a><a name="p1958231192220"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p8582811132216"><a name="p8582811132216"></a><a name="p8582811132216"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p195831211122216"><a name="p195831211122216"></a><a name="p195831211122216"></a>动画插值终点，不设置时默认为1。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   animator支持的接口

    <a name="table10586161118228"></a>
    <table><thead align="left"><tr id="row16584611182210"><th class="cellrowborder" valign="top" width="15.57%" id="mcps1.1.4.1.1"><p id="p658331152213"><a name="p658331152213"></a><a name="p658331152213"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.899999999999999%" id="mcps1.1.4.1.2"><p id="p11583131119222"><a name="p11583131119222"></a><a name="p11583131119222"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.53%" id="mcps1.1.4.1.3"><p id="p6583311102210"><a name="p6583311102210"></a><a name="p6583311102210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2584511152213"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p1658451192210"><a name="p1658451192210"></a><a name="p1658451192210"></a>update</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p458481114225"><a name="p458481114225"></a><a name="p458481114225"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p15584161112214"><a name="p15584161112214"></a><a name="p15584161112214"></a>过程中可以使用这个接口更新动画参数，入参与createAnimator一致。</p>
    </td>
    </tr>
    <tr id="row1758471118228"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p9584181118221"><a name="p9584181118221"></a><a name="p9584181118221"></a>play</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p115841811122215"><a name="p115841811122215"></a><a name="p115841811122215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p758411111224"><a name="p758411111224"></a><a name="p758411111224"></a>开始动画。</p>
    </td>
    </tr>
    <tr id="row155855111221"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p205845117227"><a name="p205845117227"></a><a name="p205845117227"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p1584181122217"><a name="p1584181122217"></a><a name="p1584181122217"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p12585101192212"><a name="p12585101192212"></a><a name="p12585101192212"></a>结束动画。</p>
    </td>
    </tr>
    <tr id="row85851611122215"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p858561115223"><a name="p858561115223"></a><a name="p858561115223"></a>pause</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p3585711102215"><a name="p3585711102215"></a><a name="p3585711102215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p1758510114227"><a name="p1758510114227"></a><a name="p1758510114227"></a>暂停动画。</p>
    </td>
    </tr>
    <tr id="row8585611102219"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p5585201172218"><a name="p5585201172218"></a><a name="p5585201172218"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p458511117225"><a name="p458511117225"></a><a name="p458511117225"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p17585911122213"><a name="p17585911122213"></a><a name="p17585911122213"></a>取消动画。</p>
    </td>
    </tr>
    <tr id="row1358612115227"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p1858571119222"><a name="p1858571119222"></a><a name="p1858571119222"></a>reverse</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p9585161152215"><a name="p9585161152215"></a><a name="p9585161152215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p458641172220"><a name="p458641172220"></a><a name="p458641172220"></a>倒播动画。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   animator支持的事件：

    <a name="table4588511132210"></a>
    <table><thead align="left"><tr id="row19586141116227"><th class="cellrowborder" valign="top" width="15.57%" id="mcps1.1.4.1.1"><p id="p15586101111222"><a name="p15586101111222"></a><a name="p15586101111222"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.899999999999999%" id="mcps1.1.4.1.2"><p id="p1858671142217"><a name="p1858671142217"></a><a name="p1858671142217"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.53%" id="mcps1.1.4.1.3"><p id="p1658681118229"><a name="p1658681118229"></a><a name="p1658681118229"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19587611102214"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p15866114221"><a name="p15866114221"></a><a name="p15866114221"></a>frame</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p135862119221"><a name="p135862119221"></a><a name="p135862119221"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p4586191119224"><a name="p4586191119224"></a><a name="p4586191119224"></a>逐帧插值回调事件，入参为当前帧的插值</p>
    </td>
    </tr>
    <tr id="row15587161162211"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p2058731119223"><a name="p2058731119223"></a><a name="p2058731119223"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p058751172212"><a name="p058751172212"></a><a name="p058751172212"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p1587121102211"><a name="p1587121102211"></a><a name="p1587121102211"></a>动画被强制取消</p>
    </td>
    </tr>
    <tr id="row65871211192213"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p8587141192219"><a name="p8587141192219"></a><a name="p8587141192219"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p8587211152212"><a name="p8587211152212"></a><a name="p8587211152212"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p135870119227"><a name="p135870119227"></a><a name="p135870119227"></a>动画播放完成</p>
    </td>
    </tr>
    <tr id="row175881011182210"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p2587511182210"><a name="p2587511182210"></a><a name="p2587511182210"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p17587511192218"><a name="p17587511192218"></a><a name="p17587511192218"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p10587811202211"><a name="p10587811202211"></a><a name="p10587811202211"></a>动画重新播放</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    <!-- hml -->
    <div class="container">
      <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
      </div>
    </div>
    ```

    ```
    // js
    export default {
      data : {
        divWidth: 200,
        divHeight: 200,
        animator: null
      },
      onInit() {
        var options = {
          duration: 1500,
          easing: 'friction',
          fill: 'forwards',
          iterations: 2,
          begin: 200.0,
          end: 400.0
        };
        this.animator = animator.createAnimator(options);
      },
      Show() {
        var options1 = {
          duration: 2000,
          easing: 'friction',
          fill: 'forwards',
          iterations: 1,
          begin: 200.0,
          end: 400.0
        };
        this.animator.update(options1);
        var _this = this;
        this.animator.onframe = function(value) {
          _this.divWidth = value;
          _this.divHeight = value;
        };
        this.animator.play();
      }
    }
    ```



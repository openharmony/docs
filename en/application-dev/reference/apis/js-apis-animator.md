# Animation<a name="EN-US_TOPIC_0000001127125026"></a>

> **NOTE:**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s0e7b1e85a4274f58a8206e0b065bd80c"></a>

**requestAnimationFrame**: none

**cancelAnimationFrame**: none

**createAnimator**:

```
import animator from '@ohos.animator';
```

## Required Permissions<a name="section11257113618419"></a>

None

## requestAnimationFrame<a name="s298a3cf59a3b470dbb0742706102ced7"></a>

requestAnimationFrame\(handler\[, \[ ...args\]\]\): number

Requests an animation frame.

-   Parameters

    <a name="t87748b0ba4e648079d53f9deccf4bfb2"></a>
    <table><thead align="left"><tr id="rc5033ad045c14c2e806d59041aab002c"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="acf783ab6043e4ee1a7bb73b73a091e0b"><a name="acf783ab6043e4ee1a7bb73b73a091e0b"></a><a name="acf783ab6043e4ee1a7bb73b73a091e0b"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="a6736505551534b819d5a6376065a25f6"><a name="a6736505551534b819d5a6376065a25f6"></a><a name="a6736505551534b819d5a6376065a25f6"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="ac15c2a3de0e046af917cf09b48b3b46d"><a name="ac15c2a3de0e046af917cf09b48b3b46d"></a><a name="ac15c2a3de0e046af917cf09b48b3b46d"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="aeb94b88e78974288bab1b4940b50c840"><a name="aeb94b88e78974288bab1b4940b50c840"></a><a name="aeb94b88e78974288bab1b4940b50c840"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r95c56d5cd62d4b518c3e7a3f158ed7fe"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="a7af41aec9a404f418202d90c61774825"><a name="a7af41aec9a404f418202d90c61774825"></a><a name="a7af41aec9a404f418202d90c61774825"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="aed6ae868d61349afa8f0e250108f8e47"><a name="aed6ae868d61349afa8f0e250108f8e47"></a><a name="aed6ae868d61349afa8f0e250108f8e47"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="ab72ac8cc02e34da4b717ca144fc521c1"><a name="ab72ac8cc02e34da4b717ca144fc521c1"></a><a name="ab72ac8cc02e34da4b717ca144fc521c1"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="ac53e6549d32f413e9c51cd8a53f4650a"><a name="ac53e6549d32f413e9c51cd8a53f4650a"></a><a name="ac53e6549d32f413e9c51cd8a53f4650a"></a>Handler used to request a frame. When <strong id="b83691144121"><a name="b83691144121"></a><a name="b83691144121"></a>requestAnimationFrame</strong> calls the <strong id="b17229515216"><a name="b17229515216"></a><a name="b17229515216"></a>handler</strong>, the timestamp is passed to the first parameter to indicate the time when <strong id="b1559713311312"><a name="b1559713311312"></a><a name="b1559713311312"></a>requestAnimationFrame</strong> starts to execute the callback.</p>
    </td>
    </tr>
    <tr id="row8497154383016"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1497174316302"><a name="p1497174316302"></a><a name="p1497174316302"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="p1649714393019"><a name="p1649714393019"></a><a name="p1649714393019"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p12498154363014"><a name="p12498154363014"></a><a name="p12498154363014"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p049816437303"><a name="p049816437303"></a><a name="p049816437303"></a>Additional parameter, which is passed to the <strong id="b9292174942"><a name="b9292174942"></a><a name="b9292174942"></a>handler</strong> as a parameter during function callback.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1430416594311"></a>
    <table><thead align="left"><tr id="row230485973113"><th class="cellrowborder" valign="top" width="12.18%" id="mcps1.1.3.1.1"><p id="p430405913312"><a name="p430405913312"></a><a name="p430405913312"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.82%" id="mcps1.1.3.1.2"><p id="p830413599312"><a name="p830413599312"></a><a name="p830413599312"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row130435914317"><td class="cellrowborder" valign="top" width="12.18%" headers="mcps1.1.3.1.1 "><p id="p4305759143119"><a name="p4305759143119"></a><a name="p4305759143119"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.82%" headers="mcps1.1.3.1.2 "><p id="p130555923110"><a name="p130555923110"></a><a name="p130555923110"></a>Request ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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

Cancels the animation frame request.

-   Parameters

    <a name="table25491571214"></a>
    <table><thead align="left"><tr id="row1954910577117"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="p1854918574119"><a name="p1854918574119"></a><a name="p1854918574119"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="p17549195713119"><a name="p17549195713119"></a><a name="p17549195713119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="p1654910571912"><a name="p1654910571912"></a><a name="p1654910571912"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p185491057813"><a name="p185491057813"></a><a name="p185491057813"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row05492571017"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p11549057812"><a name="p11549057812"></a><a name="p11549057812"></a>requestId</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="p1454910571915"><a name="p1454910571915"></a><a name="p1454910571915"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p195491657811"><a name="p195491657811"></a><a name="p195491657811"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p165492579116"><a name="p165492579116"></a><a name="p165492579116"></a>ID of the frame request.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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

Creates an animation object.

-   Parameters

    <a name="table1210814218489"></a>
    <table><thead align="left"><tr id="row16108162112483"><th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.1.5.1.1"><p id="p9108102124816"><a name="p9108102124816"></a><a name="p9108102124816"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.97%" id="mcps1.1.5.1.2"><p id="p15108921134810"><a name="p15108921134810"></a><a name="p15108921134810"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="p610832174811"><a name="p610832174811"></a><a name="p610832174811"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p20109102115481"><a name="p20109102115481"></a><a name="p20109102115481"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111091721194810"><td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p191091121114816"><a name="p191091121114816"></a><a name="p191091121114816"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.1.5.1.2 "><p id="p51091212484"><a name="p51091212484"></a><a name="p51091212484"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="p17109112111489"><a name="p17109112111489"></a><a name="p17109112111489"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p9109221104814"><a name="p9109221104814"></a><a name="p9109221104814"></a>Attributes of the <strong id="b12693720715"><a name="b12693720715"></a><a name="b12693720715"></a>Animator</strong> to be created. For details, see the options table.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Description of options

    <a name="table185831411112210"></a>
    <table><thead align="left"><tr id="row13579511112217"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="p6578111142211"><a name="p6578111142211"></a><a name="p6578111142211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.2"><p id="p8578811182212"><a name="p8578811182212"></a><a name="p8578811182212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.5.1.3"><p id="p557961122219"><a name="p557961122219"></a><a name="p557961122219"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="p14579101116224"><a name="p14579101116224"></a><a name="p14579101116224"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row125801711102218"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1857912118220"><a name="p1857912118220"></a><a name="p1857912118220"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p45798110229"><a name="p45798110229"></a><a name="p45798110229"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p35793112223"><a name="p35793112223"></a><a name="p35793112223"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p17580011172219"><a name="p17580011172219"></a><a name="p17580011172219"></a>Duration for playing an animation, in milliseconds. The default value is <strong id="b1125162610819"><a name="b1125162610819"></a><a name="b1125162610819"></a>0</strong>.</p>
    </td>
    </tr>
    <tr id="row55801511172212"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p14580711152210"><a name="p14580711152210"></a><a name="p14580711152210"></a>easing</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p19580141112217"><a name="p19580141112217"></a><a name="p19580141112217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p658021122212"><a name="p658021122212"></a><a name="p658021122212"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p18580121112212"><a name="p18580121112212"></a><a name="p18580121112212"></a>Animation easing curve. The default value is <strong id="b188750351389"><a name="b188750351389"></a><a name="b188750351389"></a>ease</strong>.</p>
    </td>
    </tr>
    <tr id="row558071118228"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1580111117227"><a name="p1580111117227"></a><a name="p1580111117227"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p6580111102215"><a name="p6580111102215"></a><a name="p6580111102215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p1258016113229"><a name="p1258016113229"></a><a name="p1258016113229"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p858021152215"><a name="p858021152215"></a><a name="p858021152215"></a>Animation delay duration, in milliseconds. The default value is <strong id="b76079311298"><a name="b76079311298"></a><a name="b76079311298"></a>0</strong>, indicating that there is no delay.</p>
    </td>
    </tr>
    <tr id="row1358151113223"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p1358119115228"><a name="p1358119115228"></a><a name="p1358119115228"></a>fill</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p15581211132210"><a name="p15581211132210"></a><a name="p15581211132210"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p1458171119226"><a name="p1458171119226"></a><a name="p1458171119226"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p185811411172213"><a name="p185811411172213"></a><a name="p185811411172213"></a>Animation start/stop mode. The default value is <strong id="b758714215913"><a name="b758714215913"></a><a name="b758714215913"></a>none</strong>. For details, see <a href="../../nottoctopics/en-us_topic_0000001173164765.md#p886655314713">animation-fill-mode</a>.</p>
    </td>
    </tr>
    <tr id="row18581811142219"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p75817112225"><a name="p75817112225"></a><a name="p75817112225"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1258118115221"><a name="p1258118115221"></a><a name="p1258118115221"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p17581211122213"><a name="p17581211122213"></a><a name="p17581211122213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p195811211152214"><a name="p195811211152214"></a><a name="p195811211152214"></a>Animation playback mode. The default value is <strong id="b599714386107"><a name="b599714386107"></a><a name="b599714386107"></a>normal</strong>. For details, see <a href="../../nottoctopics/en-us_topic_0000001173164765.md#p2611151295818">animation-direction</a>.</p>
    </td>
    </tr>
    <tr id="row55821511122210"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p16581171118226"><a name="p16581171118226"></a><a name="p16581171118226"></a>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1582151113228"><a name="p1582151113228"></a><a name="p1582151113228"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p205821311132214"><a name="p205821311132214"></a><a name="p205821311132214"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p1458201118221"><a name="p1458201118221"></a><a name="p1458201118221"></a>Number of times that an animation is played. The default value is <strong id="b11868105418107"><a name="b11868105418107"></a><a name="b11868105418107"></a>1</strong>. If this parameter is set to <strong id="b10384143101114"><a name="b10384143101114"></a><a name="b10384143101114"></a>0</strong>, the animation is not played. If this parameter is set to <strong id="b1196115711115"><a name="b1196115711115"></a><a name="b1196115711115"></a>-1</strong>, the animation is played for an unlimited number of times.</p>
    </td>
    </tr>
    <tr id="row1958211116223"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p205821811152213"><a name="p205821811152213"></a><a name="p205821811152213"></a>begin</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p10582211122219"><a name="p10582211122219"></a><a name="p10582211122219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p758281111223"><a name="p758281111223"></a><a name="p758281111223"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p105820113229"><a name="p105820113229"></a><a name="p105820113229"></a>Start point of the animation easing. If this parameter is not set, the default value <strong id="b10935111319129"><a name="b10935111319129"></a><a name="b10935111319129"></a>0</strong> is used.</p>
    </td>
    </tr>
    <tr id="row12583191192217"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="p55828118227"><a name="p55828118227"></a><a name="p55828118227"></a>end</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="p1958231192220"><a name="p1958231192220"></a><a name="p1958231192220"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.3 "><p id="p8582811132216"><a name="p8582811132216"></a><a name="p8582811132216"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="p195831211122216"><a name="p195831211122216"></a><a name="p195831211122216"></a>End point of the animation easing. If this parameter is not set, the default value <strong id="b86451784138"><a name="b86451784138"></a><a name="b86451784138"></a>1</strong> is used.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   animator interfaces

    <a name="table10586161118228"></a>
    <table><thead align="left"><tr id="row16584611182210"><th class="cellrowborder" valign="top" width="15.57%" id="mcps1.1.4.1.1"><p id="p658331152213"><a name="p658331152213"></a><a name="p658331152213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.899999999999999%" id="mcps1.1.4.1.2"><p id="p11583131119222"><a name="p11583131119222"></a><a name="p11583131119222"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.53%" id="mcps1.1.4.1.3"><p id="p6583311102210"><a name="p6583311102210"></a><a name="p6583311102210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2584511152213"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p1658451192210"><a name="p1658451192210"></a><a name="p1658451192210"></a>update</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p458481114225"><a name="p458481114225"></a><a name="p458481114225"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p15584161112214"><a name="p15584161112214"></a><a name="p15584161112214"></a>Updates the animation parameters. The input parameters are the same as those of <strong id="b15428258171314"><a name="b15428258171314"></a><a name="b15428258171314"></a>createAnimator</strong>.</p>
    </td>
    </tr>
    <tr id="row1758471118228"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p9584181118221"><a name="p9584181118221"></a><a name="p9584181118221"></a>play</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p115841811122215"><a name="p115841811122215"></a><a name="p115841811122215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p758411111224"><a name="p758411111224"></a><a name="p758411111224"></a>Starts an animation.</p>
    </td>
    </tr>
    <tr id="row155855111221"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p205845117227"><a name="p205845117227"></a><a name="p205845117227"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p1584181122217"><a name="p1584181122217"></a><a name="p1584181122217"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p12585101192212"><a name="p12585101192212"></a><a name="p12585101192212"></a>Ends an animation.</p>
    </td>
    </tr>
    <tr id="row85851611122215"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p858561115223"><a name="p858561115223"></a><a name="p858561115223"></a>pause</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p3585711102215"><a name="p3585711102215"></a><a name="p3585711102215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p1758510114227"><a name="p1758510114227"></a><a name="p1758510114227"></a>Pauses an animation.</p>
    </td>
    </tr>
    <tr id="row8585611102219"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p5585201172218"><a name="p5585201172218"></a><a name="p5585201172218"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p458511117225"><a name="p458511117225"></a><a name="p458511117225"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p17585911122213"><a name="p17585911122213"></a><a name="p17585911122213"></a>Cancels an animation.</p>
    </td>
    </tr>
    <tr id="row1358612115227"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p1858571119222"><a name="p1858571119222"></a><a name="p1858571119222"></a>reverse</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p9585161152215"><a name="p9585161152215"></a><a name="p9585161152215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p458641172220"><a name="p458641172220"></a><a name="p458641172220"></a>Reverses an animation.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   **animator**  supported events:

    <a name="table4588511132210"></a>
    <table><thead align="left"><tr id="row19586141116227"><th class="cellrowborder" valign="top" width="15.57%" id="mcps1.1.4.1.1"><p id="p15586101111222"><a name="p15586101111222"></a><a name="p15586101111222"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.899999999999999%" id="mcps1.1.4.1.2"><p id="p1858671142217"><a name="p1858671142217"></a><a name="p1858671142217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.53%" id="mcps1.1.4.1.3"><p id="p1658681118229"><a name="p1658681118229"></a><a name="p1658681118229"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19587611102214"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p15866114221"><a name="p15866114221"></a><a name="p15866114221"></a>frame</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p135862119221"><a name="p135862119221"></a><a name="p135862119221"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p4586191119224"><a name="p4586191119224"></a><a name="p4586191119224"></a>The frame is requested.</p>
    </td>
    </tr>
    <tr id="row15587161162211"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p2058731119223"><a name="p2058731119223"></a><a name="p2058731119223"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p058751172212"><a name="p058751172212"></a><a name="p058751172212"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p1587121102211"><a name="p1587121102211"></a><a name="p1587121102211"></a>The animation is forcibly canceled.</p>
    </td>
    </tr>
    <tr id="row65871211192213"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p8587141192219"><a name="p8587141192219"></a><a name="p8587141192219"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p8587211152212"><a name="p8587211152212"></a><a name="p8587211152212"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p135870119227"><a name="p135870119227"></a><a name="p135870119227"></a>The animation playback is complete.</p>
    </td>
    </tr>
    <tr id="row175881011182210"><td class="cellrowborder" valign="top" width="15.57%" headers="mcps1.1.4.1.1 "><p id="p2587511182210"><a name="p2587511182210"></a><a name="p2587511182210"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.899999999999999%" headers="mcps1.1.4.1.2 "><p id="p17587511192218"><a name="p17587511192218"></a><a name="p17587511192218"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.53%" headers="mcps1.1.4.1.3 "><p id="p10587811202211"><a name="p10587811202211"></a><a name="p10587811202211"></a>The animation replays.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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



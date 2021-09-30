# 音频播放<a name="ZH-CN_TOPIC_0000001164295590"></a>

-   [导入模块](#zh-cn_topic_0000001103383404_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001103383404_section11257113618419)
-   [createAudioPlayer\(\)](#zh-cn_topic_0000001103383404_section582314017253)
-   [AudioPlayer](#zh-cn_topic_0000001103383404_section5174142818365)
    -   [属性](#zh-cn_topic_0000001103383404_section4947115405)
    -   [play\(\): void](#zh-cn_topic_0000001103383404_section964512672913)
    -   [pause\(\): void](#zh-cn_topic_0000001103383404_section78173258296)
    -   [stop\(\): void](#zh-cn_topic_0000001103383404_section122114334296)
    -   [seek\(timeMs: number\): void](#zh-cn_topic_0000001103383404_section1387113816298)
    -   [setVolume\(vol: number\): void](#zh-cn_topic_0000001103383404_section164235176552)
    -   [reset\(\): void7+](#zh-cn_topic_0000001103383404_section1473283011356)
    -   [release\(\): void](#zh-cn_topic_0000001103383404_section9224621145512)
    -   [on\(type: string, callback: \(\) =\> void\): void](#zh-cn_topic_0000001103383404_section4486193914193)
    -   [on\(type: string, callback: Callback<number\>\): void](#zh-cn_topic_0000001103383404_section632591014157)
    -   [on\(type: string, callback: ErrorCallback\): void](#zh-cn_topic_0000001103383404_section92241852949)
    -   [事件](#zh-cn_topic_0000001103383404_section1825183472812)

-   [AudioState](#zh-cn_topic_0000001103383404_section5181155710523)

## 导入模块<a name="zh-cn_topic_0000001103383404_s56d19203690d4782bfc74069abb6bd71"></a>

```
import media from '@ohos.multimedia.media';
```

## 权限<a name="zh-cn_topic_0000001103383404_section11257113618419"></a>

无

## createAudioPlayer\(\)<a name="zh-cn_topic_0000001103383404_section582314017253"></a>

创建音频播放的实例。

-   参数：

    无

-   返回值：

<a name="zh-cn_topic_0000001103383404_table482411406254"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row138241940172518"><th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103383404_p28256407257"><a name="zh-cn_topic_0000001103383404_p28256407257"></a><a name="zh-cn_topic_0000001103383404_p28256407257"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="83.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103383404_p1582544017256"><a name="zh-cn_topic_0000001103383404_p1582544017256"></a><a name="zh-cn_topic_0000001103383404_p1582544017256"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103383404_row0825540192520"><td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103383404_p482574042511"><a name="zh-cn_topic_0000001103383404_p482574042511"></a><a name="zh-cn_topic_0000001103383404_p482574042511"></a><a href="#zh-cn_topic_0000001103383404_section5174142818365">AudioPlayer</a></p>
</td>
<td class="cellrowborder" valign="top" width="83.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103383404_p14825194014258"><a name="zh-cn_topic_0000001103383404_p14825194014258"></a><a name="zh-cn_topic_0000001103383404_p14825194014258"></a>返回AudioPlayer类实例，失败时返回null。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var audioplayer = media.createAudioPlayer(); 
```

## AudioPlayer<a name="zh-cn_topic_0000001103383404_section5174142818365"></a>

音频播放管理类，用于管理和播放音频媒体。在调用AudioPlayer的方法前，需要先通过[createAudioPlayer\(\)](#zh-cn_topic_0000001103383404_section582314017253)构建一个AudioPlayer实例。

### 属性<a name="zh-cn_topic_0000001103383404_section4947115405"></a>

<a name="zh-cn_topic_0000001103383404_table92548495595"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row132541749175917"><th class="cellrowborder" valign="top" width="15.8015801580158%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001103383404_p925404965919"><a name="zh-cn_topic_0000001103383404_p925404965919"></a><a name="zh-cn_topic_0000001103383404_p925404965919"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.591959195919593%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001103383404_p325464914599"><a name="zh-cn_topic_0000001103383404_p325464914599"></a><a name="zh-cn_topic_0000001103383404_p325464914599"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.660766076607661%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001103383404_p025484918596"><a name="zh-cn_topic_0000001103383404_p025484918596"></a><a name="zh-cn_topic_0000001103383404_p025484918596"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.29082908290829%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001103383404_p025414499590"><a name="zh-cn_topic_0000001103383404_p025414499590"></a><a name="zh-cn_topic_0000001103383404_p025414499590"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="48.65486548654865%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001103383404_p20254134925912"><a name="zh-cn_topic_0000001103383404_p20254134925912"></a><a name="zh-cn_topic_0000001103383404_p20254134925912"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103383404_row18254849155915"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103383404_p20254204935915"><a name="zh-cn_topic_0000001103383404_p20254204935915"></a><a name="zh-cn_topic_0000001103383404_p20254204935915"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103383404_p1525413497591"><a name="zh-cn_topic_0000001103383404_p1525413497591"></a><a name="zh-cn_topic_0000001103383404_p1525413497591"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103383404_p8254749195914"><a name="zh-cn_topic_0000001103383404_p8254749195914"></a><a name="zh-cn_topic_0000001103383404_p8254749195914"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103383404_p5255549115910"><a name="zh-cn_topic_0000001103383404_p5255549115910"></a><a name="zh-cn_topic_0000001103383404_p5255549115910"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103383404_p72551449145914"><a name="zh-cn_topic_0000001103383404_p72551449145914"></a><a name="zh-cn_topic_0000001103383404_p72551449145914"></a>音频媒体URI，支持当前主流的音频格式(mp4、aac、mp3、ogg)，支持本地绝对路径（file://)</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row10255134945917"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103383404_p82551349125910"><a name="zh-cn_topic_0000001103383404_p82551349125910"></a><a name="zh-cn_topic_0000001103383404_p82551349125910"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103383404_p18255154913598"><a name="zh-cn_topic_0000001103383404_p18255154913598"></a><a name="zh-cn_topic_0000001103383404_p18255154913598"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103383404_p525516497595"><a name="zh-cn_topic_0000001103383404_p525516497595"></a><a name="zh-cn_topic_0000001103383404_p525516497595"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103383404_p2025504917593"><a name="zh-cn_topic_0000001103383404_p2025504917593"></a><a name="zh-cn_topic_0000001103383404_p2025504917593"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103383404_p7255194925919"><a name="zh-cn_topic_0000001103383404_p7255194925919"></a><a name="zh-cn_topic_0000001103383404_p7255194925919"></a>音频循环播放属性，设置为'true'表示循环播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row18256049165911"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103383404_p2256154919590"><a name="zh-cn_topic_0000001103383404_p2256154919590"></a><a name="zh-cn_topic_0000001103383404_p2256154919590"></a>currentTime</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103383404_p10256849165915"><a name="zh-cn_topic_0000001103383404_p10256849165915"></a><a name="zh-cn_topic_0000001103383404_p10256849165915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103383404_p19256149155915"><a name="zh-cn_topic_0000001103383404_p19256149155915"></a><a name="zh-cn_topic_0000001103383404_p19256149155915"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103383404_p3256174935919"><a name="zh-cn_topic_0000001103383404_p3256174935919"></a><a name="zh-cn_topic_0000001103383404_p3256174935919"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103383404_p12256144995913"><a name="zh-cn_topic_0000001103383404_p12256144995913"></a><a name="zh-cn_topic_0000001103383404_p12256144995913"></a>音频的当前播放阶段。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row11256144911598"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103383404_p92561949125910"><a name="zh-cn_topic_0000001103383404_p92561949125910"></a><a name="zh-cn_topic_0000001103383404_p92561949125910"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103383404_p9256124914597"><a name="zh-cn_topic_0000001103383404_p9256124914597"></a><a name="zh-cn_topic_0000001103383404_p9256124914597"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103383404_p1725654915911"><a name="zh-cn_topic_0000001103383404_p1725654915911"></a><a name="zh-cn_topic_0000001103383404_p1725654915911"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103383404_p192562049125910"><a name="zh-cn_topic_0000001103383404_p192562049125910"></a><a name="zh-cn_topic_0000001103383404_p192562049125910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103383404_p125684995913"><a name="zh-cn_topic_0000001103383404_p125684995913"></a><a name="zh-cn_topic_0000001103383404_p125684995913"></a>音频播放的时长。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row6256149115920"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001103383404_p2256144918596"><a name="zh-cn_topic_0000001103383404_p2256144918596"></a><a name="zh-cn_topic_0000001103383404_p2256144918596"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001103383404_p9256144918593"><a name="zh-cn_topic_0000001103383404_p9256144918593"></a><a name="zh-cn_topic_0000001103383404_p9256144918593"></a><a href="#zh-cn_topic_0000001103383404_section5181155710523">AudioState</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001103383404_p102563495592"><a name="zh-cn_topic_0000001103383404_p102563495592"></a><a name="zh-cn_topic_0000001103383404_p102563495592"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001103383404_p625620497594"><a name="zh-cn_topic_0000001103383404_p625620497594"></a><a name="zh-cn_topic_0000001103383404_p625620497594"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001103383404_p162571549195920"><a name="zh-cn_topic_0000001103383404_p162571549195920"></a><a name="zh-cn_topic_0000001103383404_p162571549195920"></a>音频播放的状态。</p>
</td>
</tr>
</tbody>
</table>

### play\(\): void<a name="zh-cn_topic_0000001103383404_section964512672913"></a>

开始播放音频资源。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('play', () => {
      console.log('Playback starts.');
      audioplayer.pause();
    });
    audioplayer.play();
    ```


### pause\(\): void<a name="zh-cn_topic_0000001103383404_section78173258296"></a>

暂停播放音频资源。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('pause', () => {
      console.log('Playback paused.');
    });
    audioplayer.pause();
    ```


### stop\(\): void<a name="zh-cn_topic_0000001103383404_section122114334296"></a>

停止播放音频资源。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('stop',() => {
      console.log('Playback stopped.');
    });
    audioplayer.stop();
    ```


### seek\(timeMs: number\): void<a name="zh-cn_topic_0000001103383404_section1387113816298"></a>

跳转到指定播放位置。

-   参数：

    <a name="zh-cn_topic_0000001103383404_table1442723852917"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row84261138172911"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103383404_p204261938182919"><a name="zh-cn_topic_0000001103383404_p204261938182919"></a><a name="zh-cn_topic_0000001103383404_p204261938182919"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103383404_p1342683842920"><a name="zh-cn_topic_0000001103383404_p1342683842920"></a><a name="zh-cn_topic_0000001103383404_p1342683842920"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103383404_p134260383297"><a name="zh-cn_topic_0000001103383404_p134260383297"></a><a name="zh-cn_topic_0000001103383404_p134260383297"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103383404_p442663832912"><a name="zh-cn_topic_0000001103383404_p442663832912"></a><a name="zh-cn_topic_0000001103383404_p442663832912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103383404_row18427738202910"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p184261338192913"><a name="zh-cn_topic_0000001103383404_p184261338192913"></a><a name="zh-cn_topic_0000001103383404_p184261338192913"></a>timeMs</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p1242643819295"><a name="zh-cn_topic_0000001103383404_p1242643819295"></a><a name="zh-cn_topic_0000001103383404_p1242643819295"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p44261838112918"><a name="zh-cn_topic_0000001103383404_p44261838112918"></a><a name="zh-cn_topic_0000001103383404_p44261838112918"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p16427163812913"><a name="zh-cn_topic_0000001103383404_p16427163812913"></a><a name="zh-cn_topic_0000001103383404_p16427163812913"></a>指定的跳转时间节点。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('timeupdate', (action) => {
      var newTime = audioplayer.currenTime;
      if(newTime >= 30000) {
        console.info('Seek succeeded. New time: ' + newTime);
      } else {
        console.info('Seek failed.');
      }
    });
    audioplayer.seek(30000);
    ```


### setVolume\(vol: number\): void<a name="zh-cn_topic_0000001103383404_section164235176552"></a>

设置音量。

-   参数：

    <a name="zh-cn_topic_0000001103383404_table1242391713555"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row14424217195517"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103383404_p1424917135519"><a name="zh-cn_topic_0000001103383404_p1424917135519"></a><a name="zh-cn_topic_0000001103383404_p1424917135519"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103383404_p10424121795520"><a name="zh-cn_topic_0000001103383404_p10424121795520"></a><a name="zh-cn_topic_0000001103383404_p10424121795520"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103383404_p1042415178559"><a name="zh-cn_topic_0000001103383404_p1042415178559"></a><a name="zh-cn_topic_0000001103383404_p1042415178559"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103383404_p13424717125513"><a name="zh-cn_topic_0000001103383404_p13424717125513"></a><a name="zh-cn_topic_0000001103383404_p13424717125513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103383404_row13424171745513"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p204241517125517"><a name="zh-cn_topic_0000001103383404_p204241517125517"></a><a name="zh-cn_topic_0000001103383404_p204241517125517"></a>vol</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p18424121755517"><a name="zh-cn_topic_0000001103383404_p18424121755517"></a><a name="zh-cn_topic_0000001103383404_p18424121755517"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p2042417176554"><a name="zh-cn_topic_0000001103383404_p2042417176554"></a><a name="zh-cn_topic_0000001103383404_p2042417176554"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p9424171717557"><a name="zh-cn_topic_0000001103383404_p9424171717557"></a><a name="zh-cn_topic_0000001103383404_p9424171717557"></a>指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('volumeChange', () => {
      console.log('Playback volume changed.');
    });
    audioplayer.setVolume(1);
    ```


### reset\(\): void<sup>7+</sup><a name="zh-cn_topic_0000001103383404_section1473283011356"></a>

切换播放音频资源。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audioplay.reset();
    ```


### release\(\): void<a name="zh-cn_topic_0000001103383404_section9224621145512"></a>

释放音频资源。

-   参数：

    无

-   返回值：

    无

-   示例：

```
audioplay.release();
```

### on\(type: string, callback: \(\) =\> void\): void<a name="zh-cn_topic_0000001103383404_section4486193914193"></a>

开始监听音频播放事件。

-   参数：

    <a name="zh-cn_topic_0000001103383404_table173988426207"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row15398042162016"><th class="cellrowborder" valign="top" width="13.239999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103383404_p8398114217208"><a name="zh-cn_topic_0000001103383404_p8398114217208"></a><a name="zh-cn_topic_0000001103383404_p8398114217208"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.36%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103383404_p18398184232010"><a name="zh-cn_topic_0000001103383404_p18398184232010"></a><a name="zh-cn_topic_0000001103383404_p18398184232010"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103383404_p1839884211207"><a name="zh-cn_topic_0000001103383404_p1839884211207"></a><a name="zh-cn_topic_0000001103383404_p1839884211207"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.290000000000006%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103383404_p12399164214204"><a name="zh-cn_topic_0000001103383404_p12399164214204"></a><a name="zh-cn_topic_0000001103383404_p12399164214204"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103383404_row12399042112010"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p2399104292011"><a name="zh-cn_topic_0000001103383404_p2399104292011"></a><a name="zh-cn_topic_0000001103383404_p2399104292011"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.36%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p7399194217203"><a name="zh-cn_topic_0000001103383404_p7399194217203"></a><a name="zh-cn_topic_0000001103383404_p7399194217203"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p23991942102016"><a name="zh-cn_topic_0000001103383404_p23991942102016"></a><a name="zh-cn_topic_0000001103383404_p23991942102016"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.290000000000006%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p153991742142013"><a name="zh-cn_topic_0000001103383404_p153991742142013"></a><a name="zh-cn_topic_0000001103383404_p153991742142013"></a>播放事件回调类型，支持的<a href="#zh-cn_topic_0000001103383404_section1825183472812">事件</a>包括：'play' | 'pause' | 'stop' | 'dataLoad' |'reset'| |'finish' | 'volumeChange'。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103383404_row12630221183811"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p9630192123817"><a name="zh-cn_topic_0000001103383404_p9630192123817"></a><a name="zh-cn_topic_0000001103383404_p9630192123817"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.36%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p289624913915"><a name="zh-cn_topic_0000001103383404_p289624913915"></a><a name="zh-cn_topic_0000001103383404_p289624913915"></a>()=&gt;void</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p14630121163820"><a name="zh-cn_topic_0000001103383404_p14630121163820"></a><a name="zh-cn_topic_0000001103383404_p14630121163820"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.290000000000006%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p662492335319"><a name="zh-cn_topic_0000001103383404_p662492335319"></a><a name="zh-cn_topic_0000001103383404_p662492335319"></a>播放事件回调方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('play', () => {
      console.log('Playback starts.');
    });
    audioplayer.play();
    ```


### on\(type: string, callback: Callback<number\>\): void<a name="zh-cn_topic_0000001103383404_section632591014157"></a>

开始监听音频播放时间戳更新事件。

-   参数：

    <a name="zh-cn_topic_0000001103383404_table15325191001518"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row73258108159"><th class="cellrowborder" valign="top" width="13.239999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103383404_p103252103151"><a name="zh-cn_topic_0000001103383404_p103252103151"></a><a name="zh-cn_topic_0000001103383404_p103252103151"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.36%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103383404_p1432581081519"><a name="zh-cn_topic_0000001103383404_p1432581081519"></a><a name="zh-cn_topic_0000001103383404_p1432581081519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103383404_p63261110171516"><a name="zh-cn_topic_0000001103383404_p63261110171516"></a><a name="zh-cn_topic_0000001103383404_p63261110171516"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.290000000000006%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103383404_p1032611105153"><a name="zh-cn_topic_0000001103383404_p1032611105153"></a><a name="zh-cn_topic_0000001103383404_p1032611105153"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103383404_row16326410151518"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p183262010121514"><a name="zh-cn_topic_0000001103383404_p183262010121514"></a><a name="zh-cn_topic_0000001103383404_p183262010121514"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.36%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p17326151020154"><a name="zh-cn_topic_0000001103383404_p17326151020154"></a><a name="zh-cn_topic_0000001103383404_p17326151020154"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p203261107150"><a name="zh-cn_topic_0000001103383404_p203261107150"></a><a name="zh-cn_topic_0000001103383404_p203261107150"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.290000000000006%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p13261510131520"><a name="zh-cn_topic_0000001103383404_p13261510131520"></a><a name="zh-cn_topic_0000001103383404_p13261510131520"></a>播放事件回调类型，支持的<a href="#zh-cn_topic_0000001103383404_section1825183472812">事件</a>为：'timeUpdate'。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103383404_row0326161061519"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p132601016153"><a name="zh-cn_topic_0000001103383404_p132601016153"></a><a name="zh-cn_topic_0000001103383404_p132601016153"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.36%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p5431133013534"><a name="zh-cn_topic_0000001103383404_p5431133013534"></a><a name="zh-cn_topic_0000001103383404_p5431133013534"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p123261510191514"><a name="zh-cn_topic_0000001103383404_p123261510191514"></a><a name="zh-cn_topic_0000001103383404_p123261510191514"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.290000000000006%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p20326141021519"><a name="zh-cn_topic_0000001103383404_p20326141021519"></a><a name="zh-cn_topic_0000001103383404_p20326141021519"></a>播放事件回调方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file://xxx/sounds.mp4';
    audioplayer.on('timeupdate', (action) => {
      var newTime = audioplayer.currenTime;
      if(newTime >= 30000) {
        console.info('Seek succeeded. New time: ' + newTime);
      } else {
        console.info('Seek failed.');
      }
    });
    audioplayer.seek(30000);
    ```


### on\(type: string, callback: ErrorCallback\): void<a name="zh-cn_topic_0000001103383404_section92241852949"></a>

开始监听音频播放错误事件。

-   参数：

    <a name="zh-cn_topic_0000001103383404_table022416523419"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row112256529412"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103383404_p0225752844"><a name="zh-cn_topic_0000001103383404_p0225752844"></a><a name="zh-cn_topic_0000001103383404_p0225752844"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.8%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103383404_p52258520419"><a name="zh-cn_topic_0000001103383404_p52258520419"></a><a name="zh-cn_topic_0000001103383404_p52258520419"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001103383404_p1622511526412"><a name="zh-cn_topic_0000001103383404_p1622511526412"></a><a name="zh-cn_topic_0000001103383404_p1622511526412"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.959999999999994%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103383404_p6225125211417"><a name="zh-cn_topic_0000001103383404_p6225125211417"></a><a name="zh-cn_topic_0000001103383404_p6225125211417"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001103383404_row2225752043"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p0225152949"><a name="zh-cn_topic_0000001103383404_p0225152949"></a><a name="zh-cn_topic_0000001103383404_p0225152949"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p722565219414"><a name="zh-cn_topic_0000001103383404_p722565219414"></a><a name="zh-cn_topic_0000001103383404_p722565219414"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p122545216416"><a name="zh-cn_topic_0000001103383404_p122545216416"></a><a name="zh-cn_topic_0000001103383404_p122545216416"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.959999999999994%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p5225185217419"><a name="zh-cn_topic_0000001103383404_p5225185217419"></a><a name="zh-cn_topic_0000001103383404_p5225185217419"></a>播放错误事件回调类型'error'。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001103383404_row142257521545"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103383404_p922565214419"><a name="zh-cn_topic_0000001103383404_p922565214419"></a><a name="zh-cn_topic_0000001103383404_p922565214419"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103383404_p349810515716"><a name="zh-cn_topic_0000001103383404_p349810515716"></a><a name="zh-cn_topic_0000001103383404_p349810515716"></a>ErrorCallback</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001103383404_p022510528410"><a name="zh-cn_topic_0000001103383404_p022510528410"></a><a name="zh-cn_topic_0000001103383404_p022510528410"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.959999999999994%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103383404_p72251052344"><a name="zh-cn_topic_0000001103383404_p72251052344"></a><a name="zh-cn_topic_0000001103383404_p72251052344"></a>播放错误事件回调方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audioplayer.src = 'file:///xxx/sounds.mp4';
    audioplayer.on('error', (err) => {
       console.info('error callback info: ' + err);
    });
    audioplayer.setVolume(30000);
    ```


### 事件<a name="zh-cn_topic_0000001103383404_section1825183472812"></a>

AudioPlayer支持订阅以下事件。

<a name="zh-cn_topic_0000001103383404_table169181418553"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row26924142558"><th class="cellrowborder" valign="top" width="21.542154215421544%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001103383404_p2069220147551"><a name="zh-cn_topic_0000001103383404_p2069220147551"></a><a name="zh-cn_topic_0000001103383404_p2069220147551"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.992199219921993%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001103383404_p12692191417558"><a name="zh-cn_topic_0000001103383404_p12692191417558"></a><a name="zh-cn_topic_0000001103383404_p12692191417558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="56.46564656465647%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001103383404_p8692121445517"><a name="zh-cn_topic_0000001103383404_p8692121445517"></a><a name="zh-cn_topic_0000001103383404_p8692121445517"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103383404_row10692171415556"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p176920145554"><a name="zh-cn_topic_0000001103383404_p176920145554"></a><a name="zh-cn_topic_0000001103383404_p176920145554"></a>play</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p169215148554"><a name="zh-cn_topic_0000001103383404_p169215148554"></a><a name="zh-cn_topic_0000001103383404_p169215148554"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p176921014135520"><a name="zh-cn_topic_0000001103383404_p176921014135520"></a><a name="zh-cn_topic_0000001103383404_p176921014135520"></a>完成play方法调用，音频开始播放，触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row66922014195511"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p166924144558"><a name="zh-cn_topic_0000001103383404_p166924144558"></a><a name="zh-cn_topic_0000001103383404_p166924144558"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p1369261410553"><a name="zh-cn_topic_0000001103383404_p1369261410553"></a><a name="zh-cn_topic_0000001103383404_p1369261410553"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p186928147554"><a name="zh-cn_topic_0000001103383404_p186928147554"></a><a name="zh-cn_topic_0000001103383404_p186928147554"></a>完成pause方法调用，音频暂停播放，触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row19692151435518"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p36929145556"><a name="zh-cn_topic_0000001103383404_p36929145556"></a><a name="zh-cn_topic_0000001103383404_p36929145556"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p12692181412556"><a name="zh-cn_topic_0000001103383404_p12692181412556"></a><a name="zh-cn_topic_0000001103383404_p12692181412556"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p176921414175520"><a name="zh-cn_topic_0000001103383404_p176921414175520"></a><a name="zh-cn_topic_0000001103383404_p176921414175520"></a>完成stop方法调用，音频停止播放，触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row471819386316"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p471953813113"><a name="zh-cn_topic_0000001103383404_p471953813113"></a><a name="zh-cn_topic_0000001103383404_p471953813113"></a>reset</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p11719338123110"><a name="zh-cn_topic_0000001103383404_p11719338123110"></a><a name="zh-cn_topic_0000001103383404_p11719338123110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p8719123833111"><a name="zh-cn_topic_0000001103383404_p8719123833111"></a><a name="zh-cn_topic_0000001103383404_p8719123833111"></a>完成reset方法调用，释放音频播放资源，触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row53036474012"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p830454715010"><a name="zh-cn_topic_0000001103383404_p830454715010"></a><a name="zh-cn_topic_0000001103383404_p830454715010"></a>dataLoad</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p73046471703"><a name="zh-cn_topic_0000001103383404_p73046471703"></a><a name="zh-cn_topic_0000001103383404_p73046471703"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p43041247401"><a name="zh-cn_topic_0000001103383404_p43041247401"></a><a name="zh-cn_topic_0000001103383404_p43041247401"></a>完成音频数据加载后触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row126921114175516"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p169271475516"><a name="zh-cn_topic_0000001103383404_p169271475516"></a><a name="zh-cn_topic_0000001103383404_p169271475516"></a>finish</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p106924149554"><a name="zh-cn_topic_0000001103383404_p106924149554"></a><a name="zh-cn_topic_0000001103383404_p106924149554"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p19692161445511"><a name="zh-cn_topic_0000001103383404_p19692161445511"></a><a name="zh-cn_topic_0000001103383404_p19692161445511"></a>完成音频播放后触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row1869318146557"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p769313145553"><a name="zh-cn_topic_0000001103383404_p769313145553"></a><a name="zh-cn_topic_0000001103383404_p769313145553"></a>volumeChange</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p9693814195516"><a name="zh-cn_topic_0000001103383404_p9693814195516"></a><a name="zh-cn_topic_0000001103383404_p9693814195516"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p369321412558"><a name="zh-cn_topic_0000001103383404_p369321412558"></a><a name="zh-cn_topic_0000001103383404_p369321412558"></a>播放音量改变后触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row19142191516210"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p10143151513220"><a name="zh-cn_topic_0000001103383404_p10143151513220"></a><a name="zh-cn_topic_0000001103383404_p10143151513220"></a>timeUpdate</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p614311152215"><a name="zh-cn_topic_0000001103383404_p614311152215"></a><a name="zh-cn_topic_0000001103383404_p614311152215"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p614351513214"><a name="zh-cn_topic_0000001103383404_p614351513214"></a><a name="zh-cn_topic_0000001103383404_p614351513214"></a>完成seek方法调用，音频播放时间戳更新，触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row1469142035618"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001103383404_p18701220185614"><a name="zh-cn_topic_0000001103383404_p18701220185614"></a><a name="zh-cn_topic_0000001103383404_p18701220185614"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001103383404_p27013201562"><a name="zh-cn_topic_0000001103383404_p27013201562"></a><a name="zh-cn_topic_0000001103383404_p27013201562"></a><a href="#zh-cn_topic_0000001103383404_table2584191811710">callback</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001103383404_p8700209561"><a name="zh-cn_topic_0000001103383404_p8700209561"></a><a name="zh-cn_topic_0000001103383404_p8700209561"></a>音频播放中发生错误，触发该事件。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  error事件的参数说明

<a name="zh-cn_topic_0000001103383404_table2584191811710"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row3584101817714"><th class="cellrowborder" valign="top" width="21.62216221622162%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001103383404_p97918291679"><a name="zh-cn_topic_0000001103383404_p97918291679"></a><a name="zh-cn_topic_0000001103383404_p97918291679"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="23.82238223822382%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001103383404_p1579262919717"><a name="zh-cn_topic_0000001103383404_p1579262919717"></a><a name="zh-cn_topic_0000001103383404_p1579262919717"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="54.55545554555455%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001103383404_p1979218299715"><a name="zh-cn_topic_0000001103383404_p1979218299715"></a><a name="zh-cn_topic_0000001103383404_p1979218299715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103383404_row9585171814711"><td class="cellrowborder" valign="top" width="21.62216221622162%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001103383404_p779213291717"><a name="zh-cn_topic_0000001103383404_p779213291717"></a><a name="zh-cn_topic_0000001103383404_p779213291717"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="23.82238223822382%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001103383404_p679202917711"><a name="zh-cn_topic_0000001103383404_p679202917711"></a><a name="zh-cn_topic_0000001103383404_p679202917711"></a>ErrorCallback</p>
</td>
<td class="cellrowborder" valign="top" width="54.55545554555455%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001103383404_p9792142920716"><a name="zh-cn_topic_0000001103383404_p9792142920716"></a><a name="zh-cn_topic_0000001103383404_p9792142920716"></a>错误事件的回调函数。</p>
</td>
</tr>
</tbody>
</table>

## AudioState<a name="zh-cn_topic_0000001103383404_section5181155710523"></a>

音频播放的状态机。

<a name="zh-cn_topic_0000001103383404_table919114616314"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103383404_row31917610318"><th class="cellrowborder" valign="top" width="33.739999999999995%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001103383404_p219196531"><a name="zh-cn_topic_0000001103383404_p219196531"></a><a name="zh-cn_topic_0000001103383404_p219196531"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="66.25999999999999%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001103383404_p14191563313"><a name="zh-cn_topic_0000001103383404_p14191563313"></a><a name="zh-cn_topic_0000001103383404_p14191563313"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001103383404_row3427194315719"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103383404_p642711431172"><a name="zh-cn_topic_0000001103383404_p642711431172"></a><a name="zh-cn_topic_0000001103383404_p642711431172"></a>idle</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103383404_p24281543777"><a name="zh-cn_topic_0000001103383404_p24281543777"></a><a name="zh-cn_topic_0000001103383404_p24281543777"></a>音频播放空闲。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row2019146539"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103383404_p201913617311"><a name="zh-cn_topic_0000001103383404_p201913617311"></a><a name="zh-cn_topic_0000001103383404_p201913617311"></a>playing</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103383404_p81911362316"><a name="zh-cn_topic_0000001103383404_p81911362316"></a><a name="zh-cn_topic_0000001103383404_p81911362316"></a>音频正在播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row11912612316"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103383404_p9191136731"><a name="zh-cn_topic_0000001103383404_p9191136731"></a><a name="zh-cn_topic_0000001103383404_p9191136731"></a>paused</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103383404_p419166738"><a name="zh-cn_topic_0000001103383404_p419166738"></a><a name="zh-cn_topic_0000001103383404_p419166738"></a>音频暂停播放<span>。</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103383404_row111912617314"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001103383404_p9191156333"><a name="zh-cn_topic_0000001103383404_p9191156333"></a><a name="zh-cn_topic_0000001103383404_p9191156333"></a>stopped</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001103383404_p2019215618316"><a name="zh-cn_topic_0000001103383404_p2019215618316"></a><a name="zh-cn_topic_0000001103383404_p2019215618316"></a>音频播放停止。</p>
</td>
</tr>
</tbody>
</table>


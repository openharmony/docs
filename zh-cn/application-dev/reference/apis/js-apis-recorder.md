# 音频录制<a name="ZH-CN_TOPIC_0000001163882216"></a>

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import media from '@ohos.multimedia.media';
```

## 权限<a name="section11257113618419"></a>

无

## createAudioRecorder\(\): AudioRecorder<a name="section582314017253"></a>

创建音频录制的实例来控制音频的录制。

-   参数：

    无

-   返回值

<a name="table482411406254"></a>
<table><thead align="left"><tr id="row138241940172518"><th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.3.1.1"><p id="p28256407257"><a name="p28256407257"></a><a name="p28256407257"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="83.95%" id="mcps1.1.3.1.2"><p id="p1582544017256"><a name="p1582544017256"></a><a name="p1582544017256"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row0825540192520"><td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.3.1.1 "><p id="p482574042511"><a name="p482574042511"></a><a name="p482574042511"></a><a href="#section43944147586">AudioRecorder</a></p>
</td>
<td class="cellrowborder" valign="top" width="83.95%" headers="mcps1.1.3.1.2 "><p id="p14825194014258"><a name="p14825194014258"></a><a name="p14825194014258"></a>返回AudioRecorder类实例，失败时返回null。</p>
</td>
</tr>
</tbody>
</table>

-   示例

```
var audiorecorder = media.createAudioRecorder(); 
```

## AudioRecorder<a name="section43944147586"></a>

音频录制管理类，用于录制音频媒体。在调用AudioRecorder的方法前，需要先通过[createAudioRecorder\(\)](#section582314017253)构建一个AudioRecorder实例。

### prepare\(config: AudioRecorderConfig\): void<a name="section964512672913"></a>

录音准备。

-   参数：

    <a name="table2032961315810"></a>
    <table><thead align="left"><tr id="row1632917131687"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p4329513386"><a name="p4329513386"></a><a name="p4329513386"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.82%" id="mcps1.1.5.1.2"><p id="p132991317820"><a name="p132991317820"></a><a name="p132991317820"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.5.1.3"><p id="p193298131081"><a name="p193298131081"></a><a name="p193298131081"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.62%" id="mcps1.1.5.1.4"><p id="p63309131983"><a name="p63309131983"></a><a name="p63309131983"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row433014131681"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p19330111316810"><a name="p19330111316810"></a><a name="p19330111316810"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.82%" headers="mcps1.1.5.1.2 "><p id="p833014133817"><a name="p833014133817"></a><a name="p833014133817"></a><a href="#section1598043510176">AudioRecorderConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p143301713684"><a name="p143301713684"></a><a name="p143301713684"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.62%" headers="mcps1.1.5.1.4 "><p id="p2330121316816"><a name="p2330121316816"></a><a name="p2330121316816"></a>配置录音的相关参数，包括音频输出URI、编码格式、采样率、声道数等。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    无

-   示例：

    ```
    let audioRecorderConfig = {
        audioEncoder : AAC_LC ,
        audioEncodeBitRate : 22050,
        audioSampleRate : 22050,
        numberOfChannels : 2,
        format : AAC_ADTS,
        uri : 'file:///data/accounts/account_0/appdata/appdata/recorder/test.m4a',
    }
    audiorecorder.prepare(audioRecorderConfig)
    ```


## start\(\): void<a name="section1083114216235"></a>

开始录音。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audiorecorder.start();
    ```


## stop\(\): void<a name="section49857120241"></a>

停止录音。

-   参数：

    无


-   返回值：

    无

-   示例：

    ```
    audiorecorder.stop();
    ```


## release\(\): void<a name="section926421610249"></a>

释放录音资源。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audiorecorder.release();
    ```


## reset\(\): void<a name="section92419614497"></a>

重置录音。

进行重置录音之前，需要先调用stop\(\)停止录音。重置录音之后，需要调用prepare\(\)设置录音配置项，才能再次进行录音。

-   参数：

    无

-   返回值：

    无

-   示例：

    ```
    audiorecorder.reset();
    ```


## on\(type: string, callback: \(\) =\> void\): void<a name="section2882646102611"></a>

开始订阅音频录制事件。

-   参数：

    <a name="table08781840114717"></a>
    <table><thead align="left"><tr id="row1187874011473"><th class="cellrowborder" valign="top" width="11.15%" id="mcps1.1.5.1.1"><p id="p11878144034717"><a name="p11878144034717"></a><a name="p11878144034717"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.629999999999995%" id="mcps1.1.5.1.2"><p id="p148781440124719"><a name="p148781440124719"></a><a name="p148781440124719"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.39%" id="mcps1.1.5.1.3"><p id="p8878154010477"><a name="p8878154010477"></a><a name="p8878154010477"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.83%" id="mcps1.1.5.1.4"><p id="p148789401475"><a name="p148789401475"></a><a name="p148789401475"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14879140124711"><td class="cellrowborder" valign="top" width="11.15%" headers="mcps1.1.5.1.1 "><p id="p16879140174719"><a name="p16879140174719"></a><a name="p16879140174719"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p1287954044719"><a name="p1287954044719"></a><a name="p1287954044719"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.1.5.1.3 "><p id="p587904094714"><a name="p587904094714"></a><a name="p587904094714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.83%" headers="mcps1.1.5.1.4 "><p id="p587913402475"><a name="p587913402475"></a><a name="p587913402475"></a>录制事件回调类型，支持的<a href="#section1162724195816">事件</a>包括：'prepare' | 'start' | 'stop' | 'release' | 'reset'。</p>
    <a name="ul195191244143919"></a><a name="ul195191244143919"></a><ul id="ul195191244143919"><li>'prepare' ：音频录制准备完成后，触发该事件。</li><li>'start' ：音频录制开始后，触发该事件。</li><li>'stop' ：音频录制停止后，触发该事件。</li><li>'release' ：音频录制相关资源释放后，触发该事件。</li><li>'reset'：音频录制重置后，触发该事件。</li></ul>
    </td>
    </tr>
    <tr id="row2879140144716"><td class="cellrowborder" valign="top" width="11.15%" headers="mcps1.1.5.1.1 "><p id="p198791640104711"><a name="p198791640104711"></a><a name="p198791640104711"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p15879124012477"><a name="p15879124012477"></a><a name="p15879124012477"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.1.5.1.3 "><p id="p18791540114710"><a name="p18791540114710"></a><a name="p18791540114710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.83%" headers="mcps1.1.5.1.4 "><p id="p387964054714"><a name="p387964054714"></a><a name="p387964054714"></a>录制事件回调方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    audiorecorder.on('prepare', () => {
      console.log('Preparation succeeded.');
      audiorecorder.start();
    });
    ```


## on\(type: string, callback: ErrorCallback\): void<a name="section0533182210274"></a>

开始订阅音频录制错误事件。

-   参数：

    <a name="table122719489119"></a>
    <table><thead align="left"><tr id="row1027134841112"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p127174818118"><a name="p127174818118"></a><a name="p127174818118"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.8%" id="mcps1.1.5.1.2"><p id="p3271184814111"><a name="p3271184814111"></a><a name="p3271184814111"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p16271204891115"><a name="p16271204891115"></a><a name="p16271204891115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.959999999999994%" id="mcps1.1.5.1.4"><p id="p1727194816118"><a name="p1727194816118"></a><a name="p1727194816118"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22711948131116"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p72711148161110"><a name="p72711148161110"></a><a name="p72711148161110"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.8%" headers="mcps1.1.5.1.2 "><p id="p1271194881116"><a name="p1271194881116"></a><a name="p1271194881116"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p10271134812114"><a name="p10271134812114"></a><a name="p10271134812114"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.959999999999994%" headers="mcps1.1.5.1.4 "><p id="p112711348131114"><a name="p112711348131114"></a><a name="p112711348131114"></a>录制错误事件回调类型'error'。</p>
    <a name="ul12573133610395"></a><a name="ul12573133610395"></a><ul id="ul12573133610395"><li>'error'：音频录制过程中发生错误，触发该事件。</li></ul>
    </td>
    </tr>
    <tr id="row1427114817118"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p02713483112"><a name="p02713483112"></a><a name="p02713483112"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.8%" headers="mcps1.1.5.1.2 "><p id="p4272154815116"><a name="p4272154815116"></a><a name="p4272154815116"></a>ErrorCallback</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p427224841119"><a name="p427224841119"></a><a name="p427224841119"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.959999999999994%" headers="mcps1.1.5.1.4 "><p id="p8272104817117"><a name="p8272104817117"></a><a name="p8272104817117"></a>录制错误事件回调方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无


### 事件<a name="section1162724195816"></a>

AudioRecorder支持订阅以下事件。

<a name="table204671955103010"></a>
<table><thead align="left"><tr id="row24682559308"><th class="cellrowborder" valign="top" width="21.542154215421544%" id="mcps1.1.4.1.1"><p id="p1546816553305"><a name="p1546816553305"></a><a name="p1546816553305"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.992199219921993%" id="mcps1.1.4.1.2"><p id="p3468255183013"><a name="p3468255183013"></a><a name="p3468255183013"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="56.46564656465647%" id="mcps1.1.4.1.3"><p id="p64681055113016"><a name="p64681055113016"></a><a name="p64681055113016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1990882423218"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p7909122418326"><a name="p7909122418326"></a><a name="p7909122418326"></a>prepare</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p390911243329"><a name="p390911243329"></a><a name="p390911243329"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p990918241322"><a name="p990918241322"></a><a name="p990918241322"></a>音频录制准备完成后，触发该事件。</p>
</td>
</tr>
<tr id="row154681551307"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p6468125517309"><a name="p6468125517309"></a><a name="p6468125517309"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p1446818553304"><a name="p1446818553304"></a><a name="p1446818553304"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p546895513019"><a name="p546895513019"></a><a name="p546895513019"></a>音频录制开始后，触发该事件。</p>
</td>
</tr>
<tr id="row6469255163011"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p3469175593010"><a name="p3469175593010"></a><a name="p3469175593010"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p146925518307"><a name="p146925518307"></a><a name="p146925518307"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p946918555309"><a name="p946918555309"></a><a name="p946918555309"></a>音频录制停止后，触发该事件。</p>
</td>
</tr>
<tr id="row0469185516309"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p64695550304"><a name="p64695550304"></a><a name="p64695550304"></a>release</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p1946985523016"><a name="p1946985523016"></a><a name="p1946985523016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p1346985563017"><a name="p1346985563017"></a><a name="p1346985563017"></a>音频录制相关资源释放后，触发该事件。</p>
</td>
</tr>
<tr id="row1323041773517"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p1023111172356"><a name="p1023111172356"></a><a name="p1023111172356"></a>reset</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p10231191743514"><a name="p10231191743514"></a><a name="p10231191743514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p162317171358"><a name="p162317171358"></a><a name="p162317171358"></a>音频录制重置后，触发该事件。</p>
</td>
</tr>
<tr id="row184694551309"><td class="cellrowborder" valign="top" width="21.542154215421544%" headers="mcps1.1.4.1.1 "><p id="p2469105512307"><a name="p2469105512307"></a><a name="p2469105512307"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="p1146975513013"><a name="p1146975513013"></a><a name="p1146975513013"></a><a href="#table1446910551301">callback</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.46564656465647%" headers="mcps1.1.4.1.3 "><p id="p1946985520302"><a name="p1946985520302"></a><a name="p1946985520302"></a>音频录制过程中发生错误，触发该事件。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  error事件的参数说明

<a name="table1446910551301"></a>
<table><thead align="left"><tr id="row34691255163012"><th class="cellrowborder" valign="top" width="21.62216221622162%" id="mcps1.2.4.1.1"><p id="p12469205518302"><a name="p12469205518302"></a><a name="p12469205518302"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="23.82238223822382%" id="mcps1.2.4.1.2"><p id="p1747055563020"><a name="p1747055563020"></a><a name="p1747055563020"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="54.55545554555455%" id="mcps1.2.4.1.3"><p id="p74704550302"><a name="p74704550302"></a><a name="p74704550302"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8470165511307"><td class="cellrowborder" valign="top" width="21.62216221622162%" headers="mcps1.2.4.1.1 "><p id="p154702557309"><a name="p154702557309"></a><a name="p154702557309"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="23.82238223822382%" headers="mcps1.2.4.1.2 "><p id="p54705558301"><a name="p54705558301"></a><a name="p54705558301"></a>ErrorCallback</p>
</td>
<td class="cellrowborder" valign="top" width="54.55545554555455%" headers="mcps1.2.4.1.3 "><p id="p1247055593011"><a name="p1247055593011"></a><a name="p1247055593011"></a>错误事件的回调函数。</p>
</td>
</tr>
</tbody>
</table>

## AudioRecorderConfig<a name="section1598043510176"></a>

表示音频的录音配置。

<a name="table1399124110551"></a>
<table><thead align="left"><tr id="row1599541125511"><th class="cellrowborder" valign="top" width="20.82208220822082%" id="mcps1.1.5.1.1"><p id="p1399241195518"><a name="p1399241195518"></a><a name="p1399241195518"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.482048204820483%" id="mcps1.1.5.1.2"><p id="p1499144115518"><a name="p1499144115518"></a><a name="p1499144115518"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.830683068306831%" id="mcps1.1.5.1.3"><p id="p1699134165515"><a name="p1699134165515"></a><a name="p1699134165515"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.86518651865186%" id="mcps1.1.5.1.4"><p id="p10991341205519"><a name="p10991341205519"></a><a name="p10991341205519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11100341115520"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p2100641125518"><a name="p2100641125518"></a><a name="p2100641125518"></a>audioEncoder</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p1010014175512"><a name="p1010014175512"></a><a name="p1010014175512"></a><a href="#section1994314217178">AudioEncoder</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p11100194165513"><a name="p11100194165513"></a><a name="p11100194165513"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p51001741135514"><a name="p51001741135514"></a><a name="p51001741135514"></a>音频编码格式，默认设置为AAC_LC。</p>
</td>
</tr>
<tr id="row810019418554"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p810094116558"><a name="p810094116558"></a><a name="p810094116558"></a>audioEncodeBitRate</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p20100194145519"><a name="p20100194145519"></a><a name="p20100194145519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p510044185512"><a name="p510044185512"></a><a name="p510044185512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p210014112552"><a name="p210014112552"></a><a name="p210014112552"></a>音频编码比特率，默认值为48000。</p>
</td>
</tr>
<tr id="row8480624165615"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p248013241566"><a name="p248013241566"></a><a name="p248013241566"></a>audioSampleRate</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p548012415614"><a name="p548012415614"></a><a name="p548012415614"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p0560651599"><a name="p0560651599"></a><a name="p0560651599"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p34806249562"><a name="p34806249562"></a><a name="p34806249562"></a>音频采集采样率，默认值为48000。</p>
</td>
</tr>
<tr id="row035412225569"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p2354152219565"><a name="p2354152219565"></a><a name="p2354152219565"></a>numberOfChannels</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p203541221563"><a name="p203541221563"></a><a name="p203541221563"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p141500617911"><a name="p141500617911"></a><a name="p141500617911"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p113546221560"><a name="p113546221560"></a><a name="p113546221560"></a>音频采集声道数，默认值为2。</p>
</td>
</tr>
<tr id="row164481127105611"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p11448927135613"><a name="p11448927135613"></a><a name="p11448927135613"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p9448327125612"><a name="p9448327125612"></a><a name="p9448327125612"></a><a href="#section1335114620172">AudioOutputFormat</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p118868594"><a name="p118868594"></a><a name="p118868594"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p14448132765617"><a name="p14448132765617"></a><a name="p14448132765617"></a>音量输出封装格式，默认设置为MPEG_4。</p>
</td>
</tr>
<tr id="row760613115919"><td class="cellrowborder" valign="top" width="20.82208220822082%" headers="mcps1.1.5.1.1 "><p id="p1260713111391"><a name="p1260713111391"></a><a name="p1260713111391"></a>uri</p>
</td>
<td class="cellrowborder" valign="top" width="20.482048204820483%" headers="mcps1.1.5.1.2 "><p id="p76071911396"><a name="p76071911396"></a><a name="p76071911396"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.830683068306831%" headers="mcps1.1.5.1.3 "><p id="p12221115391"><a name="p12221115391"></a><a name="p12221115391"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.86518651865186%" headers="mcps1.1.5.1.4 "><p id="p1660717111396"><a name="p1660717111396"></a><a name="p1660717111396"></a>音频输出URI。支持：</p>
<a name="ol4480244184818"></a><a name="ol4480244184818"></a><ol id="ol4480244184818"><li>文件的绝对路径：file:///data/data/ohos.xxx.xxx/cache/test.mp4<a name="image1427125519424"></a><a name="image1427125519424"></a><span><img id="image1427125519424" src="figures/zh-cn_image_0000001164217678.png"></span></li><li>文件的fd路径：file://1 (fd number)<p id="p84811244174813"><a name="p84811244174813"></a><a name="p84811244174813"></a></p>
</li></ol>
</td>
</tr>
</tbody>
</table>

## AudioEncoder<a name="section1994314217178"></a>

表示音频编码格式的枚举。

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row204204281782"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1442052817813"><a name="p1442052817813"></a><a name="p1442052817813"></a>AAC_LC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p5421828586"><a name="p5421828586"></a><a name="p5421828586"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p8869544181117"><a name="p8869544181117"></a><a name="p8869544181117"></a>AAC-LC（Advanced Audio Coding Low Complexity）编码格式。</p>
</td>
</tr>
</tbody>
</table>

## AudioOutputFormat<a name="section1335114620172"></a>

表示音频封装格式的枚举。

<a name="table7741621172313"></a>
<table><thead align="left"><tr id="row207411621162313"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p2741921182320"><a name="p2741921182320"></a><a name="p2741921182320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p474122182312"><a name="p474122182312"></a><a name="p474122182312"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p674112182310"><a name="p674112182310"></a><a name="p674112182310"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row67412219231"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p3741172122311"><a name="p3741172122311"></a><a name="p3741172122311"></a>MPEG_4</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p18741102112230"><a name="p18741102112230"></a><a name="p18741102112230"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p14441121172416"><a name="p14441121172416"></a><a name="p14441121172416"></a>封装为MPEG-4格式。</p>
</td>
</tr>
<tr id="row4742172119232"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p9742721172315"><a name="p9742721172315"></a><a name="p9742721172315"></a>AAC_ADTS</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p10742102172317"><a name="p10742102172317"></a><a name="p10742102172317"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1174262110232"><a name="p1174262110232"></a><a name="p1174262110232"></a>封装为ADTS（Audio Data Transport Stream）格式，是AAC音频的传输流格式。</p>
</td>
</tr>
</tbody>
</table>


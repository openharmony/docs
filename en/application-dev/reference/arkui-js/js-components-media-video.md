# video<a name="EN-US_TOPIC_0000001173164749"></a>

The  **<video\>**  component provides a video player.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Configure the following information in the  **config.json**  file:
>    ```
>    "configChanges": ["orientation"]
>    ```

## Permission List<a name="section11257113618419"></a>

## Child Component<a name="sc18e8342b29747dbbd70887cc3c0a22d"></a>

Not supported

## Attribute<a name="s50d82bce96774b86846ab2739d7ce18d"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row174491921121516"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p886612215154"><a name="p886612215154"></a><a name="p886612215154"></a>muted</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p2086602211514"><a name="p2086602211514"></a><a name="p2086602211514"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p17866222171514"><a name="p17866222171514"></a><a name="p17866222171514"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6866102231512"><a name="p6866102231512"></a><a name="p6866102231512"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p58668224150"><a name="p58668224150"></a><a name="p58668224150"></a>Whether a video is muted.</p>
</td>
</tr>
<tr id="row198031871157"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p886615229150"><a name="p886615229150"></a><a name="p886615229150"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p18664223156"><a name="p18664223156"></a><a name="p18664223156"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1786642214154"><a name="p1786642214154"></a><a name="p1786642214154"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p108661922191514"><a name="p108661922191514"></a><a name="p108661922191514"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p28661822121511"><a name="p28661822121511"></a><a name="p28661822121511"></a>Path of the video content to play.</p>
</td>
</tr>
<tr id="row84223141151"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1486615224155"><a name="p1486615224155"></a><a name="p1486615224155"></a>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p8866202219150"><a name="p8866202219150"></a><a name="p8866202219150"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p168661222171510"><a name="p168661222171510"></a><a name="p168661222171510"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1786618220151"><a name="p1786618220151"></a><a name="p1786618220151"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1386610221157"><a name="p1386610221157"></a><a name="p1386610221157"></a>Whether a video is played automatically after being rendered.</p>
</td>
</tr>
<tr id="row4862225151"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p4867112211519"><a name="p4867112211519"></a><a name="p4867112211519"></a>controls</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p486742231516"><a name="p486742231516"></a><a name="p486742231516"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p118671822171510"><a name="p118671822171510"></a><a name="p118671822171510"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p148678225153"><a name="p148678225153"></a><a name="p148678225153"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1286742213153"><a name="p1286742213153"></a><a name="p1286742213153"></a>Whether the control bar is displayed during video playback. If the value is set to <strong id="b6147532141612"><a name="b6147532141612"></a><a name="b6147532141612"></a>false</strong>, the control bar is not displayed. The default value is <strong id="b161341542112813"><a name="b161341542112813"></a><a name="b161341542112813"></a>true</strong>, indicating that the platform can either show or hide the control bar.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="sfbde25405aca4513a9c938f2f339b770"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table772815434205"></a>
<table><thead align="left"><tr id="row8728104352011"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p8728104312012"><a name="p8728104312012"></a><a name="p8728104312012"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p187282438206"><a name="p187282438206"></a><a name="p187282438206"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p12729114318201"><a name="p12729114318201"></a><a name="p12729114318201"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p17729104352013"><a name="p17729104352013"></a><a name="p17729104352013"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p7729104317207"><a name="p7729104317207"></a><a name="p7729104317207"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row117291043172018"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p15729184311209"><a name="p15729184311209"></a><a name="p15729184311209"></a>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p117291543122015"><a name="p117291543122015"></a><a name="p117291543122015"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p672911431201"><a name="p672911431201"></a><a name="p672911431201"></a>contain</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p207294433207"><a name="p207294433207"></a><a name="p207294433207"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1729184392013"><a name="p1729184392013"></a><a name="p1729184392013"></a>Scaling type of the video source. If <strong id="b11860175319429"><a name="b11860175319429"></a><a name="b11860175319429"></a>poster</strong> has been assigned a value, this configuration will affect the scaling type of the video poster. For details about available values, see <a href="#t8eca568266d54af484fec0f84185e923">Table 1</a>.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  object-fit description

<a name="t8eca568266d54af484fec0f84185e923"></a>
<table><thead align="left"><tr id="r9b22bdd1cd2d4050a840c205bd25f5f2"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p id="aaf9dd8d06c5b44b8a13e3c6e17e29493"><a name="aaf9dd8d06c5b44b8a13e3c6e17e29493"></a><a name="aaf9dd8d06c5b44b8a13e3c6e17e29493"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p id="a63d0fe8b723d4ddfa21fc1fbb3e48165"><a name="a63d0fe8b723d4ddfa21fc1fbb3e48165"></a><a name="a63d0fe8b723d4ddfa21fc1fbb3e48165"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="ref689a9f315e4ffea4cd2d1a19bd1773"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="p11586163511379"><a name="p11586163511379"></a><a name="p11586163511379"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="p958611356373"><a name="p958611356373"></a><a name="p958611356373"></a>The video content is resized to fill the display area and its aspect ratio is not retained.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section4181420161817"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row116621079194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p14995128101920"><a name="p14995128101920"></a><a name="p14995128101920"></a>prepared</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1499513871918"><a name="p1499513871918"></a><a name="p1499513871918"></a>{ duration: value }<sup id="sup29931815101312"><a name="sup29931815101312"></a><a name="sup29931815101312"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1399519841911"><a name="p1399519841911"></a><a name="p1399519841911"></a>Triggered when the video preparation is complete. The video duration (in seconds) is obtained from <strong id="b10248010272"><a name="b10248010272"></a><a name="b10248010272"></a>duration</strong>.</p>
</td>
</tr>
<tr id="row76639781919"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1899514821910"><a name="p1899514821910"></a><a name="p1899514821910"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1899516816193"><a name="p1899516816193"></a><a name="p1899516816193"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p8995182197"><a name="p8995182197"></a><a name="p8995182197"></a>Triggered when a video is played.</p>
</td>
</tr>
<tr id="row1066387181915"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1899616891919"><a name="p1899616891919"></a><a name="p1899616891919"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p109962861914"><a name="p109962861914"></a><a name="p109962861914"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1699615891918"><a name="p1699615891918"></a><a name="p1699615891918"></a>Triggered when a video is paused.</p>
</td>
</tr>
<tr id="row1131820251916"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p59966831917"><a name="p59966831917"></a><a name="p59966831917"></a>finish</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1799619831915"><a name="p1799619831915"></a><a name="p1799619831915"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p199688111910"><a name="p199688111910"></a><a name="p199688111910"></a>Triggered when the video playback is finished.</p>
</td>
</tr>
<tr id="row11318921194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p09964811192"><a name="p09964811192"></a><a name="p09964811192"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p999616871916"><a name="p999616871916"></a><a name="p999616871916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p399615871913"><a name="p399615871913"></a><a name="p399615871913"></a>Triggered when the playback fails.</p>
</td>
</tr>
<tr id="row143184219194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p109962812198"><a name="p109962812198"></a><a name="p109962812198"></a>seeking</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p6996118201915"><a name="p6996118201915"></a><a name="p6996118201915"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1599615891917"><a name="p1599615891917"></a><a name="p1599615891917"></a>Triggered to report the time (in seconds) when the progress bar is being dragged.</p>
</td>
</tr>
<tr id="row1637115611818"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p149964831912"><a name="p149964831912"></a><a name="p149964831912"></a>seeked</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19996182197"><a name="p19996182197"></a><a name="p19996182197"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p109961085199"><a name="p109961085199"></a><a name="p109961085199"></a>Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar.</p>
</td>
</tr>
<tr id="row1766775361814"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p129965831916"><a name="p129965831916"></a><a name="p129965831916"></a>timeupdate</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p4996386196"><a name="p4996386196"></a><a name="p4996386196"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p179976820190"><a name="p179976820190"></a><a name="p179976820190"></a>Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="s557cc2f457ff42a193807500adae2f91"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="t0b0d71e0664f479d9fbcfe2cf45b34a0"></a>
<table><thead align="left"><tr id="r80520812e64447b7a841590ba3d1ecf9"><th class="cellrowborder" valign="top" width="28.000000000000004%" id="mcps1.1.4.1.1"><p id="ab440f3031e7242d1a1ee00ba387b151f"><a name="ab440f3031e7242d1a1ee00ba387b151f"></a><a name="ab440f3031e7242d1a1ee00ba387b151f"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="42%" id="mcps1.1.4.1.2"><p id="a1e28b7e4cdc84e9eacc51b8ce51590df"><a name="a1e28b7e4cdc84e9eacc51b8ce51590df"></a><a name="a1e28b7e4cdc84e9eacc51b8ce51590df"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.1.4.1.3"><p id="ad91f1de026e24e60b0fe5078f4226f65"><a name="ad91f1de026e24e60b0fe5078f4226f65"></a><a name="ad91f1de026e24e60b0fe5078f4226f65"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="rab3c226807734a8d874bf83c939d52ad"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="ac317a80879064915a1a09cef7e3070d2"><a name="ac317a80879064915a1a09cef7e3070d2"></a><a name="ac317a80879064915a1a09cef7e3070d2"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="a1589994065b74673b39ff67b72e3ec82"><a name="a1589994065b74673b39ff67b72e3ec82"></a><a name="a1589994065b74673b39ff67b72e3ec82"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="ad610eacf0ae748a0bd0611c6bd10d49d"><a name="ad610eacf0ae748a0bd0611c6bd10d49d"></a><a name="ad610eacf0ae748a0bd0611c6bd10d49d"></a>Starts playing a video.</p>
</td>
</tr>
<tr id="r74d47c5360ae4f87936bde197795b0e5"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="a5488606f848644c1b250b35137b770f9"><a name="a5488606f848644c1b250b35137b770f9"></a><a name="a5488606f848644c1b250b35137b770f9"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="a715471504ba24456b9c69a09898e8025"><a name="a715471504ba24456b9c69a09898e8025"></a><a name="a715471504ba24456b9c69a09898e8025"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="a4d7fc26ada3c4c9b86818e40259494e6"><a name="a4d7fc26ada3c4c9b86818e40259494e6"></a><a name="a4d7fc26ada3c4c9b86818e40259494e6"></a>Pauses a video.</p>
</td>
</tr>
<tr id="rc1629488abde4974938cc5c17937dbc6"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="a74f637bafd5348bb96414961031ca01d"><a name="a74f637bafd5348bb96414961031ca01d"></a><a name="a74f637bafd5348bb96414961031ca01d"></a>setCurrentTime</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="a65bc7bf0576a4e47bff523bd15ca560c"><a name="a65bc7bf0576a4e47bff523bd15ca560c"></a><a name="a65bc7bf0576a4e47bff523bd15ca560c"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="a421ac9c67d5444338709bb7be34d06ec"><a name="a421ac9c67d5444338709bb7be34d06ec"></a><a name="a421ac9c67d5444338709bb7be34d06ec"></a>Sets the video playback position, in seconds.</p>
</td>
</tr>
</tbody>
</table>


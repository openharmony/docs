# Animation Styles<a name="EN-US_TOPIC_0000001173164765"></a>

Components support dynamic rotation, translation, and scaling effects. These effects can be set in the  **style**  attribute or CSS files.

<a name="table1863253974"></a>
<table><thead align="left"><tr id="row786315538710"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.5.1.1"><p id="p108631953175"><a name="p108631953175"></a><a name="p108631953175"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p1486365316710"><a name="p1486365316710"></a><a name="p1486365316710"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p138637531275"><a name="p138637531275"></a><a name="p138637531275"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="37%" id="mcps1.1.5.1.4"><p id="p17863053878"><a name="p17863053878"></a><a name="p17863053878"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row178631153474"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p4863105311717"><a name="p4863105311717"></a><a name="p4863105311717"></a>transform-origin</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p19520834194416"><a name="p19520834194416"></a><a name="p19520834194416"></a>string<sup id="sup18345114116209"><a name="sup18345114116209"></a><a name="sup18345114116209"></a>6+</sup> | &lt;percentage&gt; | &lt;length&gt; string<sup id="sup126042215219"><a name="sup126042215219"></a><a name="sup126042215219"></a>6+</sup> | &lt;percentage&gt; | &lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1986319537716"><a name="p1986319537716"></a><a name="p1986319537716"></a>center center</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p6867140201912"><a name="p6867140201912"></a><a name="p6867140201912"></a>Origin position of the transformed element. The unit can be px or a percentage (relative to the animation target component). If only one value is specified, the other value is <strong id="b18297190153111"><a name="b18297190153111"></a><a name="b18297190153111"></a>50%</strong>. The available values for the first string are <strong id="b76212170322"><a name="b76212170322"></a><a name="b76212170322"></a>left</strong>, <strong id="b56420192323"><a name="b56420192323"></a><a name="b56420192323"></a>center</strong>, and <strong id="b641019164323"><a name="b641019164323"></a><a name="b641019164323"></a>right</strong>. The available values for the second string are <strong id="b11194144433213"><a name="b11194144433213"></a><a name="b11194144433213"></a>top</strong>, <strong id="b15762430323"><a name="b15762430323"></a><a name="b15762430323"></a>center</strong>, and <strong id="b7648942183213"><a name="b7648942183213"></a><a name="b7648942183213"></a>bottom</strong>.</p>
<p id="p11863165316720"><a name="p11863165316720"></a><a name="p11863165316720"></a>Example:</p>
<p id="p146961332184513"><a name="p146961332184513"></a><a name="p146961332184513"></a>transform-origin: 200px 30%</p>
<p id="p12696232144513"><a name="p12696232144513"></a><a name="p12696232144513"></a>transform-origin: 100px top</p>
<p id="p14231729142211"><a name="p14231729142211"></a><a name="p14231729142211"></a>transform-origin: center center</p>
</td>
</tr>
<tr id="row486314531779"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p28641953175"><a name="p28641953175"></a><a name="p28641953175"></a>transform</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1286475313710"><a name="p1286475313710"></a><a name="p1286475313710"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p8864155311715"><a name="p8864155311715"></a><a name="p8864155311715"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p52158111929"><a name="p52158111929"></a><a name="p52158111929"></a>Translation, rotation, and scaling attributes.</p>
<p id="p1286415319715"><a name="p1286415319715"></a><a name="p1286415319715"></a>For details, see <a href="#table28802443315">Table 1</a>.</p>
</td>
</tr>
<tr id="row185145292179"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p2515142916172"><a name="p2515142916172"></a><a name="p2515142916172"></a>animation<sup id="sup17981125732213"><a name="sup17981125732213"></a><a name="sup17981125732213"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p105152029111712"><a name="p105152029111712"></a><a name="p105152029111712"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p125157290172"><a name="p125157290172"></a><a name="p125157290172"></a>0s ease 0s 1 normal none running none</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p1515152915179"><a name="p1515152915179"></a><a name="p1515152915179"></a>Animation attributes in the format of <strong id="b277520213360"><a name="b277520213360"></a><a name="b277520213360"></a>duration | timing-function | delay | iteration-count | direction | fill-mode | play-state | name</strong>. The order of the parameters is not specified, but the <strong id="b41781226144019"><a name="b41781226144019"></a><a name="b41781226144019"></a>duration</strong> and <strong id="b97790287409"><a name="b97790287409"></a><a name="b97790287409"></a>delay</strong> parameters are parsed based on where they are placed.</p>
</td>
</tr>
<tr id="row14864453877"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p88641753677"><a name="p88641753677"></a><a name="p88641753677"></a>animation-name</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p20864853870"><a name="p20864853870"></a><a name="p20864853870"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p158644534715"><a name="p158644534715"></a><a name="p158644534715"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p58645531719"><a name="p58645531719"></a><a name="p58645531719"></a>@keyframes rule. For details, see <a href="#t48a722bba37a44c883ed4e046a4cf82e">Table 2</a>.</p>
</td>
</tr>
<tr id="row8864125319718"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p128646539711"><a name="p128646539711"></a><a name="p128646539711"></a>animation-delay</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1486418539720"><a name="p1486418539720"></a><a name="p1486418539720"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p086445317716"><a name="p086445317716"></a><a name="p086445317716"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p1864135310710"><a name="p1864135310710"></a><a name="p1864135310710"></a>Delay for playing the animation, in ms or s, for example, <strong id="b293531415419"><a name="b293531415419"></a><a name="b293531415419"></a>1000 ms</strong> or <strong id="b583541616540"><a name="b583541616540"></a><a name="b583541616540"></a>1s</strong>. The default unit is ms.</p>
</td>
</tr>
<tr id="row11864135314712"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p1586435311713"><a name="p1586435311713"></a><a name="p1586435311713"></a>animation-duration</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p16864135316714"><a name="p16864135316714"></a><a name="p16864135316714"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p148641753971"><a name="p148641753971"></a><a name="p148641753971"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p342192073412"><a name="p342192073412"></a><a name="p342192073412"></a>Animation duration, in ms or s, for example, <strong id="b12381105114557"><a name="b12381105114557"></a><a name="b12381105114557"></a>1000 ms</strong> or <strong id="b19208554135519"><a name="b19208554135519"></a><a name="b19208554135519"></a>1s</strong>. The default unit is ms.</p>
<div class="note" id="note11257121119511"><a name="note11257121119511"></a><a name="note11257121119511"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p126422011184410"><a name="p126422011184410"></a><a name="p126422011184410"></a><strong id="b926872271012"><a name="b926872271012"></a><a name="b926872271012"></a>animation-duration</strong> must be specified. Otherwise, the duration is <strong id="b0902710165718"><a name="b0902710165718"></a><a name="b0902710165718"></a>0</strong>, which means the animation will not be played.</p>
</div></div>
</td>
</tr>
<tr id="row12864253377"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p138641353779"><a name="p138641353779"></a><a name="p138641353779"></a>animation-iteration-count</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p68642532717"><a name="p68642532717"></a><a name="p68642532717"></a>number | infinite</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p9864195312710"><a name="p9864195312710"></a><a name="p9864195312710"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p138641653475"><a name="p138641653475"></a><a name="p138641653475"></a>Number of times that an animation is played. The animation is played once by default. You can set the value to <strong id="b1292791613197"><a name="b1292791613197"></a><a name="b1292791613197"></a>infinite</strong> to play the animation infinitely.</p>
</td>
</tr>
<tr id="row17864453976"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p158650537712"><a name="p158650537712"></a><a name="p158650537712"></a>animation-timing-function</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p19865185313717"><a name="p19865185313717"></a><a name="p19865185313717"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p686514531178"><a name="p686514531178"></a><a name="p686514531178"></a>ease</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p38652531974"><a name="p38652531974"></a><a name="p38652531974"></a>Speed curve of an animation, which makes the animation more fluent.</p>
<p id="p586513531377"><a name="p586513531377"></a><a name="p586513531377"></a>Available values are as follows:</p>
<a name="ul104958313219"></a><a name="ul104958313219"></a><ul id="ul104958313219"><li><strong id="b18699201511716"><a name="b18699201511716"></a><a name="b18699201511716"></a>linear</strong>: The animation speed keeps unchanged.</li><li><strong id="b144551743373"><a name="b144551743373"></a><a name="b144551743373"></a>ease</strong>: The animation starts at a low speed and then accelerates. It slows down before the animation ends. <strong id="b55701863912"><a name="b55701863912"></a><a name="b55701863912"></a>cubic-bezier(0.25, 0.1, 0.25, 1.0)</strong> </li><li><strong id="b115717510818"><a name="b115717510818"></a><a name="b115717510818"></a>ease-in</strong>: The animation starts at a low speed. <strong id="b161691025131118"><a name="b161691025131118"></a><a name="b161691025131118"></a>cubic-bezier(0.42, 0.0, 1.0, 1.0)</strong></li><li><strong id="b1069413125146"><a name="b1069413125146"></a><a name="b1069413125146"></a>ease-out</strong>: The animation ends at a low speed. <strong id="b18657220191111"><a name="b18657220191111"></a><a name="b18657220191111"></a>cubic-bezier(0.0, 0.0, 0.58, 1.0)</strong></li><li><strong id="b1540172812147"><a name="b1540172812147"></a><a name="b1540172812147"></a>ease-in-out</strong>: The animation starts and ends at a low speed. <strong id="b13968449121017"><a name="b13968449121017"></a><a name="b13968449121017"></a>cubic-bezier(0.42, 0.0, 0.58, 1.0)</strong></li><li><strong id="b752771711716"><a name="b752771711716"></a><a name="b752771711716"></a>friction</strong>: Damping curve, <strong id="b1142194217138"><a name="b1142194217138"></a><a name="b1142194217138"></a>cubic-bezier(0.2, 0.0, 0.2, 1.0)</strong> </li><li><strong id="b19750154161716"><a name="b19750154161716"></a><a name="b19750154161716"></a>extreme-deceleration</strong>: Extreme deceleration curve, <strong id="b5678937171412"><a name="b5678937171412"></a><a name="b5678937171412"></a>cubic-bezier(0.0, 0.0, 0.0, 1.0) curve</strong> </li><li><strong id="b1555123841813"><a name="b1555123841813"></a><a name="b1555123841813"></a>sharp</strong>: Sharp curve, <strong id="b667512256157"><a name="b667512256157"></a><a name="b667512256157"></a>cubic-bezier(0.33, 0.0, 0.67, 1.0)</strong> </li><li><strong id="b655994931814"><a name="b655994931814"></a><a name="b655994931814"></a>rhythm</strong>: Rhythm curve, <strong id="b4933030141514"><a name="b4933030141514"></a><a name="b4933030141514"></a>cubic-bezier(0.7, 0.0, 0.2, 1.0)</strong> </li><li><strong id="b13383205711181"><a name="b13383205711181"></a><a name="b13383205711181"></a>smooth</strong>: Smooth curve, <strong id="b223183816152"><a name="b223183816152"></a><a name="b223183816152"></a>cubic-bezier(0.4, 0.0, 0.4, 1.0)</strong> </li><li><strong id="b787022161914"><a name="b787022161914"></a><a name="b787022161914"></a>cubic-bezier</strong>: You can customize an animation speed curve in the <strong id="b2993184561819"><a name="b2993184561819"></a><a name="b2993184561819"></a>cubic-bezier()</strong> function. The x and y values of each input parameter must be between 0 and 1. </li><li>steps: step curve <sup id="sup757555611248"><a name="sup757555611248"></a><a name="sup757555611248"></a>6+</sup>. Syntax: steps(number[, end|start]); The number parameter is mandatory. The value must be a positive integer. The second parameter is optional. It indicates that the start point or end point of each interval changes step by step. The value can be end or start. The default value is end.</li></ul>
</td>
</tr>
<tr id="row14611141219587"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p2611151295818"><a name="p2611151295818"></a><a name="p2611151295818"></a>animation-direction<sup id="sup3648049121713"><a name="sup3648049121713"></a><a name="sup3648049121713"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p8611111210580"><a name="p8611111210580"></a><a name="p8611111210580"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p2611412105816"><a name="p2611412105816"></a><a name="p2611412105816"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p5611151219588"><a name="p5611151219588"></a><a name="p5611151219588"></a>Mode of playing the animation.</p>
<a name="ul7721141717012"></a><a name="ul7721141717012"></a><ul id="ul7721141717012"><li><strong id="b1422164554111"><a name="b1422164554111"></a><a name="b1422164554111"></a>normal</strong>: Plays the animation in forward loop mode.</li><li><strong id="b1428234804114"><a name="b1428234804114"></a><a name="b1428234804114"></a>reverse</strong>: Plays the animation in reverse loop mode.</li><li><strong id="b17968124924117"><a name="b17968124924117"></a><a name="b17968124924117"></a>alternate</strong>: Plays the animation in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in backward direction.</li><li><strong id="b14529185618411"><a name="b14529185618411"></a><a name="b14529185618411"></a>alternate-reverse</strong>: Plays the animation in reverse-alternating loop mode. When the animation is played for an odd number of times, the playback is in backward direction. When the animation is played for an even number of times, the playback is in forward direction.</li></ul>
</td>
</tr>
<tr id="row1686675319718"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p886655314713"><a name="p886655314713"></a><a name="p886655314713"></a>animation-fill-mode</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p386625318718"><a name="p386625318718"></a><a name="p386625318718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p158661153171"><a name="p158661153171"></a><a name="p158661153171"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p48661353174"><a name="p48661353174"></a><a name="p48661353174"></a>Start and end styles of the animation</p>
<a name="ul6388194816"></a><a name="ul6388194816"></a><ul id="ul6388194816"><li><strong id="b14268971763"><a name="b14268971763"></a><a name="b14268971763"></a>none</strong>: No style is applied to the target before or after the animation is executed.</li><li><strong id="b103612812616"><a name="b103612812616"></a><a name="b103612812616"></a>forwards</strong>: The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed.</li><li><strong id="b1317920599414"><a name="b1317920599414"></a><a name="b1317920599414"></a>backwards</strong><sup id="sup1418295917413"><a name="sup1418295917413"></a><a name="sup1418295917413"></a>6+</sup>: The animation uses the value defined in the first key frame during the <strong id="b10185155914111"><a name="b10185155914111"></a><a name="b10185155914111"></a>animation-delay</strong>. When <strong id="b01276510428"><a name="b01276510428"></a><a name="b01276510428"></a>animation-direction</strong> is set to <strong id="b51365584211"><a name="b51365584211"></a><a name="b51365584211"></a>normal</strong> or <strong id="b51417564214"><a name="b51417564214"></a><a name="b51417564214"></a>alternate</strong>, the value in the <strong id="b7144751425"><a name="b7144751425"></a><a name="b7144751425"></a>from</strong> key frame is used. When <strong id="b914716516425"><a name="b914716516425"></a><a name="b914716516425"></a>animation-direction</strong> is set to <strong id="b1815118564213"><a name="b1815118564213"></a><a name="b1815118564213"></a>reverse</strong> or <strong id="b8154115194213"><a name="b8154115194213"></a><a name="b8154115194213"></a>alternate-reverse</strong>, the value in the <strong id="b1615895114213"><a name="b1615895114213"></a><a name="b1615895114213"></a>to</strong> key frame is used..</li><li><strong id="b178594774211"><a name="b178594774211"></a><a name="b178594774211"></a>both</strong><sup id="sup1986387164219"><a name="sup1986387164219"></a><a name="sup1986387164219"></a>6+</sup>: The animation follows the <strong id="b186712710421"><a name="b186712710421"></a><a name="b186712710421"></a>forwards</strong> and <strong id="b198704712427"><a name="b198704712427"></a><a name="b198704712427"></a>backwards</strong> rules.</li></ul>
</td>
</tr>
<tr id="row5395759219"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p93951251929"><a name="p93951251929"></a><a name="p93951251929"></a>animation-play-state<sup id="sup492164917239"><a name="sup492164917239"></a><a name="sup492164917239"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p3395351723"><a name="p3395351723"></a><a name="p3395351723"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1939545727"><a name="p1939545727"></a><a name="p1939545727"></a>running</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p173951158217"><a name="p173951158217"></a><a name="p173951158217"></a>Current state of the animation.</p>
<a name="ul1857213301839"></a><a name="ul1857213301839"></a><ul id="ul1857213301839"><li><strong id="b1939112212426"><a name="b1939112212426"></a><a name="b1939112212426"></a>paused</strong>: paused</li><li><strong id="b1330054124217"><a name="b1330054124217"></a><a name="b1330054124217"></a>running</strong>: playing</li></ul>
</td>
</tr>
<tr id="row37171701451"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.5.1.1 "><p id="p177174010450"><a name="p177174010450"></a><a name="p177174010450"></a>transition<sup id="sup5232112211383"><a name="sup5232112211383"></a><a name="sup5232112211383"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p197175014510"><a name="p197175014510"></a><a name="p197175014510"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p187171018459"><a name="p187171018459"></a><a name="p187171018459"></a>all 0 ease 0</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.1.5.1.4 "><p id="p11717160134515"><a name="p11717160134515"></a><a name="p11717160134515"></a>Transition effect when the component status is switched. The following four attributes can be set through the <strong id="b748822284311"><a name="b748822284311"></a><a name="b748822284311"></a>transition</strong> attribute:</p>
<a name="ul17509159164618"></a><a name="ul17509159164618"></a><ul id="ul17509159164618"><li><strong id="b191110295432"><a name="b191110295432"></a><a name="b191110295432"></a>transition-property</strong>: name of the CSS property for setting the transition effect. Currently, the width, height, and background color are supported.</li><li><strong id="b75073523433"><a name="b75073523433"></a><a name="b75073523433"></a>transition-duration</strong>: duration required for completing the transition effect, in seconds.</li><li><strong id="b79011164411"><a name="b79011164411"></a><a name="b79011164411"></a>transition-timing-function</strong>: time curve of the transition effect. The curve provided by the style animation is supported.</li><li><strong id="b04480263441"><a name="b04480263441"></a><a name="b04480263441"></a>transition-delay</strong>: delay for starting the transition effect, in seconds.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  1**  Methods of the  **transform**  attribute

<a name="table28802443315"></a>
<table><thead align="left"><tr id="row88808448314"><th class="cellrowborder" valign="top" width="18.04%" id="mcps1.2.4.1.1"><p id="p88808441132"><a name="p88808441132"></a><a name="p88808441132"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="27.71%" id="mcps1.2.4.1.2"><p id="p16880244334"><a name="p16880244334"></a><a name="p16880244334"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="54.25%" id="mcps1.2.4.1.3"><p id="p198802443316"><a name="p198802443316"></a><a name="p198802443316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row118991421721"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1489911424212"><a name="p1489911424212"></a><a name="p1489911424212"></a>none<sup id="sup1967602632417"><a name="sup1967602632417"></a><a name="sup1967602632417"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p2089924219219"><a name="p2089924219219"></a><a name="p2089924219219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p1389911421925"><a name="p1389911421925"></a><a name="p1389911421925"></a>No conversion is performed.</p>
</td>
</tr>
<tr id="row7676184815318"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p136778482035"><a name="p136778482035"></a><a name="p136778482035"></a>matrix<sup id="sup4601727102410"><a name="sup4601727102410"></a><a name="sup4601727102410"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p46778481138"><a name="p46778481138"></a><a name="p46778481138"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p1067774812320"><a name="p1067774812320"></a><a name="p1067774812320"></a>A matrix of six values, which represent scaleX, skewY, skewX, scaleY, translateX, translateY.</p>
</td>
</tr>
<tr id="row148261231616"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p6826939618"><a name="p6826939618"></a><a name="p6826939618"></a>matrix3d<sup id="sup934382819242"><a name="sup934382819242"></a><a name="sup934382819242"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p108261231861"><a name="p108261231861"></a><a name="p108261231861"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p4826233618"><a name="p4826233618"></a><a name="p4826233618"></a>A 4x4 matrix of 16 values.</p>
</td>
</tr>
<tr id="row1588011441433"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1188018441039"><a name="p1188018441039"></a><a name="p1188018441039"></a>translate</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p288015447310"><a name="p288015447310"></a><a name="p288015447310"></a>&lt;length&gt;<span id="ph168318101405"><a name="ph168318101405"></a><a name="ph168318101405"></a>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p98811441934"><a name="p98811441934"></a><a name="p98811441934"></a>Moves an element along the x-axis and y-axis.</p>
</td>
</tr>
<tr id="row1587109072"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p658717916714"><a name="p658717916714"></a><a name="p658717916714"></a>translate3d<sup id="sup1636232912416"><a name="sup1636232912416"></a><a name="sup1636232912416"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p1858749477"><a name="p1858749477"></a><a name="p1858749477"></a>&lt;length&gt;| &lt;percent&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p75871991872"><a name="p75871991872"></a><a name="p75871991872"></a>Three input parameters, indicating the translation distance of the x-axis, y-axis, and z-axis, respectively.</p>
</td>
</tr>
<tr id="row088154420311"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1688124420315"><a name="p1688124420315"></a><a name="p1688124420315"></a>translateX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p208813441237"><a name="p208813441237"></a><a name="p208813441237"></a>&lt;length&gt;<span id="ph108741224400"><a name="ph108741224400"></a><a name="ph108741224400"></a>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p688112441132"><a name="p688112441132"></a><a name="p688112441132"></a>Moves an element along the x-axis.</p>
</td>
</tr>
<tr id="row08816441839"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1588110447311"><a name="p1588110447311"></a><a name="p1588110447311"></a>translateY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p288118441533"><a name="p288118441533"></a><a name="p288118441533"></a>&lt;length&gt;<span id="ph2207350401"><a name="ph2207350401"></a><a name="ph2207350401"></a>| &lt;percent&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p38818447314"><a name="p38818447314"></a><a name="p38818447314"></a>Moves an element along the y-axis.</p>
</td>
</tr>
<tr id="row88403013913"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p10840170391"><a name="p10840170391"></a><a name="p10840170391"></a>translateZ<sup id="sup1710163082419"><a name="sup1710163082419"></a><a name="sup1710163082419"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p88408010916"><a name="p88408010916"></a><a name="p88408010916"></a>&lt;length&gt;| &lt;percent&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p1984090492"><a name="p1984090492"></a><a name="p1984090492"></a>Translation distance of the z-axis</p>
</td>
</tr>
<tr id="row288111441037"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p988164419317"><a name="p988164419317"></a><a name="p988164419317"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p0881744132"><a name="p0881744132"></a><a name="p0881744132"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p5881114412312"><a name="p5881114412312"></a><a name="p5881114412312"></a>Changes the size of an element. You need to set the target width and height on the x-axis and y-axis.</p>
</td>
</tr>
<tr id="row5893240595"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p88936401595"><a name="p88936401595"></a><a name="p88936401595"></a>scale3d<sup id="sup177701631152416"><a name="sup177701631152416"></a><a name="sup177701631152416"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p18937401991"><a name="p18937401991"></a><a name="p18937401991"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p1089317401198"><a name="p1089317401198"></a><a name="p1089317401198"></a>Three input parameters, indicating the scale ratio of the x-axis, y-axis, and z-axis, respectively.</p>
</td>
</tr>
<tr id="row088117445315"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p7881164417311"><a name="p7881164417311"></a><a name="p7881164417311"></a>scaleX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p128816446311"><a name="p128816446311"></a><a name="p128816446311"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p388112446310"><a name="p388112446310"></a><a name="p388112446310"></a>Changes the element width.</p>
</td>
</tr>
<tr id="row78813444315"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1988144419319"><a name="p1988144419319"></a><a name="p1988144419319"></a>scaleY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p2881124416314"><a name="p2881124416314"></a><a name="p2881124416314"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p128815441936"><a name="p128815441936"></a><a name="p128815441936"></a>Changes the element height.</p>
</td>
</tr>
<tr id="row19226926101018"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1022752614102"><a name="p1022752614102"></a><a name="p1022752614102"></a>scaleZ<sup id="sup25801633192410"><a name="sup25801633192410"></a><a name="sup25801633192410"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p1822742616107"><a name="p1822742616107"></a><a name="p1822742616107"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p3227142611100"><a name="p3227142611100"></a><a name="p3227142611100"></a>Scale ratio of the z-axis.</p>
</td>
</tr>
<tr id="row1488114441539"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1888104411314"><a name="p1888104411314"></a><a name="p1888104411314"></a>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p168825447318"><a name="p168825447318"></a><a name="p168825447318"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup id="sup579512297266"><a name="sup579512297266"></a><a name="sup579512297266"></a>6+</sup> | &lt;turn&gt;<sup id="sup819119310267"><a name="sup819119310267"></a><a name="sup819119310267"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p8882194415317"><a name="p8882194415317"></a><a name="p8882194415317"></a>Rotates an element. <span id="ph146515256413"><a name="ph146515256413"></a><a name="ph146515256413"></a>You can set the element to rotate around its x-axis or y-axis.</span></p>
</td>
</tr>
<tr id="row227313741118"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p162731074115"><a name="p162731074115"></a><a name="p162731074115"></a>rotate3d<sup id="sup75616348243"><a name="sup75616348243"></a><a name="sup75616348243"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p2273177114"><a name="p2273177114"></a><a name="p2273177114"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p927318720114"><a name="p927318720114"></a><a name="p927318720114"></a>Four input parameters: The first three parameters are the rotation vectors of the x-axis, y-axis, and z-axis, and the fourth parameter is the rotation angle.</p>
</td>
</tr>
<tr id="row188821744736"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p7882744632"><a name="p7882744632"></a><a name="p7882744632"></a>rotateX</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p78821744632"><a name="p78821744632"></a><a name="p78821744632"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup id="sup1349763518269"><a name="sup1349763518269"></a><a name="sup1349763518269"></a>6+</sup> | &lt;turn&gt;<sup id="sup315743792618"><a name="sup315743792618"></a><a name="sup315743792618"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p588217441134"><a name="p588217441134"></a><a name="p588217441134"></a>Rotates an element around the x-axis.</p>
</td>
</tr>
<tr id="row1488294410320"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p108826442034"><a name="p108826442034"></a><a name="p108826442034"></a>rotateY</p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p388213445311"><a name="p388213445311"></a><a name="p388213445311"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt;<sup id="sup136713509264"><a name="sup136713509264"></a><a name="sup136713509264"></a>6+</sup> | &lt;turn&gt;<sup id="sup16487751122612"><a name="sup16487751122612"></a><a name="sup16487751122612"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p8882544638"><a name="p8882544638"></a><a name="p8882544638"></a>Rotates an element around the y-axis.</p>
</td>
</tr>
<tr id="row25591113181511"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p195609136152"><a name="p195609136152"></a><a name="p195609136152"></a>rotateZ<sup id="sup93037363243"><a name="sup93037363243"></a><a name="sup93037363243"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p25601136154"><a name="p25601136154"></a><a name="p25601136154"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p956014135155"><a name="p956014135155"></a><a name="p956014135155"></a>Rotation angle in the z-axis direction.</p>
</td>
</tr>
<tr id="row113601458141519"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p2036055818158"><a name="p2036055818158"></a><a name="p2036055818158"></a>skew<sup id="sup156881037172418"><a name="sup156881037172418"></a><a name="sup156881037172418"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p1936055816154"><a name="p1936055816154"></a><a name="p1936055816154"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p2360558151514"><a name="p2360558151514"></a><a name="p2360558151514"></a>Two input parameters, indicating the 2D skew angle of the x-axis and y-axis, respectively.</p>
</td>
</tr>
<tr id="row1419525191617"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p11195185151618"><a name="p11195185151618"></a><a name="p11195185151618"></a>skewX<sup id="sup95893383244"><a name="sup95893383244"></a><a name="sup95893383244"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p101951954163"><a name="p101951954163"></a><a name="p101951954163"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p019510511168"><a name="p019510511168"></a><a name="p019510511168"></a>2D skew angle of the x-axis.</p>
</td>
</tr>
<tr id="row1339081010166"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p239018103166"><a name="p239018103166"></a><a name="p239018103166"></a>skewY<sup id="sup16994402243"><a name="sup16994402243"></a><a name="sup16994402243"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p83901110191616"><a name="p83901110191616"></a><a name="p83901110191616"></a>&lt;deg&gt; | &lt;rad&gt; | &lt;grad&gt; | &lt;turn&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p1139013100165"><a name="p1139013100165"></a><a name="p1139013100165"></a>2D skew angle of the y-axis.</p>
</td>
</tr>
<tr id="row15186755191516"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p8186125512157"><a name="p8186125512157"></a><a name="p8186125512157"></a>perspective<sup id="sup12201741102411"><a name="sup12201741102411"></a><a name="sup12201741102411"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.71%" headers="mcps1.2.4.1.2 "><p id="p618610552153"><a name="p618610552153"></a><a name="p618610552153"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="54.25%" headers="mcps1.2.4.1.3 "><p id="p818755519156"><a name="p818755519156"></a><a name="p818755519156"></a>Distance from the lens to the element's surface in the 3D perspective scenario.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Attributes available for the @keyframes rule

<a name="t48a722bba37a44c883ed4e046a4cf82e"></a>
<table><thead align="left"><tr id="r856a9393ccf4423ba47ec1b9ed96bb8e"><th class="cellrowborder" valign="top" width="24.242424242424242%" id="mcps1.2.5.1.1"><p id="ae7a02418e61f4e1db82e64f0e2f1c09e"><a name="ae7a02418e61f4e1db82e64f0e2f1c09e"></a><a name="ae7a02418e61f4e1db82e64f0e2f1c09e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.2.5.1.2"><p id="a4cee3e18cb724963be38ac53355b7b4d"><a name="a4cee3e18cb724963be38ac53355b7b4d"></a><a name="a4cee3e18cb724963be38ac53355b7b4d"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.13131313131313%" id="mcps1.2.5.1.3"><p id="a3e0026aad554469d964bbc102a8eaadb"><a name="a3e0026aad554469d964bbc102a8eaadb"></a><a name="a3e0026aad554469d964bbc102a8eaadb"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="46.464646464646464%" id="mcps1.2.5.1.4"><p id="a2b58cc16430e4420b7e9ab323cab292d"><a name="a2b58cc16430e4420b7e9ab323cab292d"></a><a name="a2b58cc16430e4420b7e9ab323cab292d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r452ea683f0af4624a69c836abfcdc440"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="a5eb36c26384742ba9e99adc2493de600"><a name="a5eb36c26384742ba9e99adc2493de600"></a><a name="a5eb36c26384742ba9e99adc2493de600"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="abc67b94bfbcb4d64a00cfe2e1e372b6d"><a name="abc67b94bfbcb4d64a00cfe2e1e372b6d"></a><a name="abc67b94bfbcb4d64a00cfe2e1e372b6d"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="ab027f70b389742bbb69fa1665a1aaaf6"><a name="ab027f70b389742bbb69fa1665a1aaaf6"></a><a name="ab027f70b389742bbb69fa1665a1aaaf6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="a2a9535e7a520474eaa5ca78ca61ca148"><a name="a2a9535e7a520474eaa5ca78ca61ca148"></a><a name="a2a9535e7a520474eaa5ca78ca61ca148"></a>Background color applied to the component after the animation is played.</p>
</td>
</tr>
<tr id="rb2e92403cacf4ce283fd5e3c625635c5"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="afd219ea8c1384a3c84d4e7ca09be073c"><a name="afd219ea8c1384a3c84d4e7ca09be073c"></a><a name="afd219ea8c1384a3c84d4e7ca09be073c"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="a89cf6dcf06954b37a77fb21ff2140188"><a name="a89cf6dcf06954b37a77fb21ff2140188"></a><a name="a89cf6dcf06954b37a77fb21ff2140188"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="a2718c52ec5574f49a263ccd45d448656"><a name="a2718c52ec5574f49a263ccd45d448656"></a><a name="a2718c52ec5574f49a263ccd45d448656"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="a6bcdedbaaa87470cae3e3beea1b67aad"><a name="a6bcdedbaaa87470cae3e3beea1b67aad"></a><a name="a6bcdedbaaa87470cae3e3beea1b67aad"></a>Opacity value applied to the component after the animation is played. The value ranges from <strong id="b1144151018012"><a name="b1144151018012"></a><a name="b1144151018012"></a>0</strong> to <strong id="b291916111108"><a name="b291916111108"></a><a name="b291916111108"></a>1</strong>. The default value is <strong id="b52858406505"><a name="b52858406505"></a><a name="b52858406505"></a>1</strong>.</p>
</td>
</tr>
<tr id="row13625142317305"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="p116261023163017"><a name="p116261023163017"></a><a name="p116261023163017"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="p5647133543013"><a name="p5647133543013"></a><a name="p5647133543013"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="p13626202319305"><a name="p13626202319305"></a><a name="p13626202319305"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="p562617236301"><a name="p562617236301"></a><a name="p562617236301"></a>Width value applied to the component after the animation is played.</p>
</td>
</tr>
<tr id="rf77cedb94a3c4c9a8556a2a2a3876997"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="a2f05af1c56e34ed4aa900b467dcf3bb7"><a name="a2f05af1c56e34ed4aa900b467dcf3bb7"></a><a name="a2f05af1c56e34ed4aa900b467dcf3bb7"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="af3cdb37ab1cc46ac823bee3784909613"><a name="af3cdb37ab1cc46ac823bee3784909613"></a><a name="af3cdb37ab1cc46ac823bee3784909613"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="a35aa8df3690b4b169f67360826114e7f"><a name="a35aa8df3690b4b169f67360826114e7f"></a><a name="a35aa8df3690b4b169f67360826114e7f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="a0ecbff2f02ac42ffb797b9bcae919003"><a name="a0ecbff2f02ac42ffb797b9bcae919003"></a><a name="a0ecbff2f02ac42ffb797b9bcae919003"></a>Height value applied to the component after the animation is played.</p>
</td>
</tr>
<tr id="r43ece702a1c945f08cd7eb195b5faac3"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="aa51ca83ead4c4c00b078f3d2c1e7e66b"><a name="aa51ca83ead4c4c00b078f3d2c1e7e66b"></a><a name="aa51ca83ead4c4c00b078f3d2c1e7e66b"></a>transform</p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="a44aec140ddba46b19c96be3ef58468c6"><a name="a44aec140ddba46b19c96be3ef58468c6"></a><a name="a44aec140ddba46b19c96be3ef58468c6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="af2ea25b4333d490d9723dec6c6d1709f"><a name="af2ea25b4333d490d9723dec6c6d1709f"></a><a name="af2ea25b4333d490d9723dec6c6d1709f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="adff3debf36764e5c868ca9823663cd5b"><a name="adff3debf36764e5c868ca9823663cd5b"></a><a name="adff3debf36764e5c868ca9823663cd5b"></a>Transformation type applied to a component. For details, see <a href="#table28802443315">Table 1</a>.</p>
</td>
</tr>
<tr id="row1745310341966"><td class="cellrowborder" valign="top" width="24.242424242424242%" headers="mcps1.2.5.1.1 "><p id="p6453634366"><a name="p6453634366"></a><a name="p6453634366"></a>background-position<sup id="sup736717438275"><a name="sup736717438275"></a><a name="sup736717438275"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.2.5.1.2 "><p id="p1552710366310"><a name="p1552710366310"></a><a name="p1552710366310"></a>string | &lt;percentage&gt; | &lt;length&gt; string | &lt;percentage&gt; | &lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.13131313131313%" headers="mcps1.2.5.1.3 "><p id="p34533341167"><a name="p34533341167"></a><a name="p34533341167"></a>50% 50%</p>
</td>
<td class="cellrowborder" valign="top" width="46.464646464646464%" headers="mcps1.2.5.1.4 "><p id="p14867144143014"><a name="p14867144143014"></a><a name="p14867144143014"></a>Set the background image for a window. The unit can be percentage or px. The first value indicates the horizontal position, and the second value indicates the vertical position. If only one value is specified, the other value is <strong id="b726314471500"><a name="b726314471500"></a><a name="b726314471500"></a>50%</strong>. The available values for the first string are <strong id="b13819621155112"><a name="b13819621155112"></a><a name="b13819621155112"></a>left</strong>, <strong id="b188192021185113"><a name="b188192021185113"></a><a name="b188192021185113"></a>center</strong>, and <strong id="b14819132110512"><a name="b14819132110512"></a><a name="b14819132110512"></a>right</strong>. The available values for the second string are <strong id="b18203211511"><a name="b18203211511"></a><a name="b18203211511"></a>top</strong>, <strong id="b1182002113513"><a name="b1182002113513"></a><a name="b1182002113513"></a>center</strong>, and <strong id="b1882072165113"><a name="b1882072165113"></a><a name="b1882072165113"></a>bottom</strong>.</p>
<p id="p1345315341569"><a name="p1345315341569"></a><a name="p1345315341569"></a>Example:</p>
<a name="ul19908143113422"></a><a name="ul19908143113422"></a><ul id="ul19908143113422"><li>background-position: 200px 30%</li><li>background-position: 100px top</li><li>background-position: center center</li></ul>
</td>
</tr>
</tbody>
</table>

If there is no default value for when an animation will start or end, use  **from**  and  **to**  to specify the start and end of the display.  You can use a percentage value to specify an intermediate state of the animation.<sup>6+</sup>  The following is an example:

```
<div class="container">
  <div class="rect">
  </div>
</div>
```

```
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.rect{
  width: 200px;
  height: 200px;
  background-color: #f76160;
  animation: Go 3s infinite;
}
@keyframes Go
{
  from {
    background-color: #f76160;
    transform:translate(100px) rotate(0deg) scale(1.0);
  }
  /* Specify the intermediate state of the animation by a percentage value.6+ */
  50% {
    background-color: #f76160;
    transform:translate(100px) rotate(60deg) scale(1.3);
  }
  to {
    background-color: #09ba07;
    transform:translate(100px) rotate(180deg) scale(2.0);
  }
}
```

![](figures/en-us_image_0000001173324797.gif)

```
<!-- xxx.hml -->
<div class="container">
  <div class="simpleAnimation simpleSize" style="animation-play-state: {{playState}}"></div>
  <text onclick="toggleState">animation-play-state: {{playState}}</text>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.simpleSize {
  background-color: blue;
  width: 100px;
  height: 100px;
}
.simpleAnimation {
  animation: simpleFrames 9s;
}
@keyframes simpleFrames {
  from { transform: translateX(0px); }
  to { transform: translateX(100px); }
}
```

```
// xxx.js
export default {
  data: {
    title: "",
    playState: "running"
  },
  toggleState() {
    if (this.playState ===  "running") {
      this.playState = "paused";
    } else {
      this.playState = "running";
    }
  }
}
```

![](figures/en-us_image_0000001173324797.gif)

```
<!-- xxx.hml -->
<div id='img' class="img"></div>
```

```
/* xxx.css */
.img {
  width: 294px;
  height: 233px;
  background-image: url('common/heartBeat.jpg');
  background-repeat: no-repeat;
  background-position: 0% 0%;
  background-size: 900%;
  animation-name: heartBeating;
  animation-duration: 1s;
  animation-delay: 0s;
  animation-fill-mode: forwards;
  animation-iteration-count: -1;
  animation-timing-function: steps(8, end);
}

@keyframes heartBeating {
  from { background-position: 0% 0%;}
  to { background-position: 100% 0%;}
}
```

```
<!-- xxx.hml -->
<div class="container">
  <div class="content"></div>
</div>
```

```
/* xxx.css */
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}
.content { /* Component state 1 */
    height: 200px;
    width: 200px;
    background-color: red;
    transition: all 5s ease 0s;
}
.content:active { /* Component state 2 */
    height: 400px;
    width: 400px;
    background-color: blue;
    transition: all 5s linear 0s;
}
```

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The @keyframes rule with  **from**  and  **to**  defined cannot be dynamically bound to an element.
>The following figure shows the meanings of end and start in the steps function.
>![](figures/en-us_image_0000001127125220.png)


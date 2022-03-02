# Universal Methods<a name="EN-US_TOPIC_0000001127284884"></a>

After a component is assigned the  **id**  attribute, you can use the ID to obtain the component objects and call functions.

## animate<a name="section16276192233016"></a>

animate\( keyframes: Keyframes, options: Options\): void

-   Name

    <a name="table207325467357"></a>
    <table><thead align="left"><tr id="row5732104653513"><th class="cellrowborder" valign="top" width="19.18%" id="mcps1.1.5.1.1"><p id="p117329469352"><a name="p117329469352"></a><a name="p117329469352"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.119999999999997%" id="mcps1.1.5.1.2"><p id="p1973274653510"><a name="p1973274653510"></a><a name="p1973274653510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p11732246113511"><a name="p11732246113511"></a><a name="p11732246113511"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p97321467354"><a name="p97321467354"></a><a name="p97321467354"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row147321246193511"><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p id="p8732046113512"><a name="p8732046113512"></a><a name="p8732046113512"></a>keyframes</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.5.1.2 "><p id="p116741612411"><a name="p116741612411"></a><a name="p116741612411"></a><a href="#table13611943164319">keyframes</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p87327464352"><a name="p87327464352"></a><a name="p87327464352"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p1373214633517"><a name="p1373214633517"></a><a name="p1373214633517"></a>Sets the animation style.</p>
    </td>
    </tr>
    <tr id="row915193384018"><td class="cellrowborder" valign="top" width="19.18%" headers="mcps1.1.5.1.1 "><p id="p1715163354018"><a name="p1715163354018"></a><a name="p1715163354018"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.5.1.2 "><p id="p12167331404"><a name="p12167331404"></a><a name="p12167331404"></a><a href="js-components-common-methods.md#table1519818133494">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p21683315407"><a name="p21683315407"></a><a name="p21683315407"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p11199113144912"><a name="p11199113144912"></a><a name="p11199113144912"></a>Array of objects used to set animation attributes. For details, see <a href="#table703167514">Options</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  keyframes

    <a name="table13611943164319"></a>
    <table><thead align="left"><tr id="row1336113436432"><th class="cellrowborder" valign="top" width="30.503050305030506%" id="mcps1.2.4.1.1"><p id="p7362144324319"><a name="p7362144324319"></a><a name="p7362144324319"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.642664266426646%" id="mcps1.2.4.1.2"><p id="p036214434433"><a name="p036214434433"></a><a name="p036214434433"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.85428542854285%" id="mcps1.2.4.1.3"><p id="p83621243114317"><a name="p83621243114317"></a><a name="p83621243114317"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20362164374316"><td class="cellrowborder" valign="top" width="30.503050305030506%" headers="mcps1.2.4.1.1 "><p id="p6225171713440"><a name="p6225171713440"></a><a name="p6225171713440"></a>frames</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.642664266426646%" headers="mcps1.2.4.1.2 "><p id="p6362174354317"><a name="p6362174354317"></a><a name="p6362174354317"></a>Array&lt;Style&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.85428542854285%" headers="mcps1.2.4.1.3 "><p id="p2036224318436"><a name="p2036224318436"></a><a name="p2036224318436"></a>Array of objects used to set animation attributes. For details about style attributes, see <a href="#table15168543143">Style attributes</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  2**  Style attributes

    <a name="table15168543143"></a>
    <table><thead align="left"><tr id="row13169194318413"><th class="cellrowborder" valign="top" width="22.91%" id="mcps1.2.5.1.1"><p id="p716934319412"><a name="p716934319412"></a><a name="p716934319412"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.2.5.1.2"><p id="p1169943747"><a name="p1169943747"></a><a name="p1169943747"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.52%" id="mcps1.2.5.1.3"><p id="p016914431944"><a name="p016914431944"></a><a name="p016914431944"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.9%" id="mcps1.2.5.1.4"><p id="p121698431749"><a name="p121698431749"></a><a name="p121698431749"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row216917436416"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p7169194314415"><a name="p7169194314415"></a><a name="p7169194314415"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p1169114318415"><a name="p1169114318415"></a><a name="p1169114318415"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p13169184311417"><a name="p13169184311417"></a><a name="p13169184311417"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p10169124310419"><a name="p10169124310419"></a><a name="p10169124310419"></a>Width set for the component during playback of the animation.</p>
    </td>
    </tr>
    <tr id="row14169243944"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p11169843247"><a name="p11169843247"></a><a name="p11169843247"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p17169943549"><a name="p17169943549"></a><a name="p17169943549"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p916914315414"><a name="p916914315414"></a><a name="p916914315414"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p1116914431443"><a name="p1116914431443"></a><a name="p1116914431443"></a>Height set for the component during playback of the animation.</p>
    </td>
    </tr>
    <tr id="row1116914437411"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p19169194319412"><a name="p19169194319412"></a><a name="p19169194319412"></a>backgroundColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p616918431944"><a name="p616918431944"></a><a name="p616918431944"></a>&lt;color&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p11691443346"><a name="p11691443346"></a><a name="p11691443346"></a>none</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p14170174320411"><a name="p14170174320411"></a><a name="p14170174320411"></a>Background color set for the component during playback of the animation.</p>
    </td>
    </tr>
    <tr id="row51701643441"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p10170243842"><a name="p10170243842"></a><a name="p10170243842"></a>opacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p19170114316414"><a name="p19170114316414"></a><a name="p19170114316414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p11701743249"><a name="p11701743249"></a><a name="p11701743249"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p8170243142"><a name="p8170243142"></a><a name="p8170243142"></a>Opacity set for the component. The value ranges from <strong id="b76363459372"><a name="b76363459372"></a><a name="b76363459372"></a>0</strong> to <strong id="b1964116457373"><a name="b1964116457373"></a><a name="b1964116457373"></a>1</strong>.</p>
    </td>
    </tr>
    <tr id="row18170243149"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p31702431445"><a name="p31702431445"></a><a name="p31702431445"></a>backgroundPosition</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p20170243143"><a name="p20170243143"></a><a name="p20170243143"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p1017020431447"><a name="p1017020431447"></a><a name="p1017020431447"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p1217094313411"><a name="p1217094313411"></a><a name="p1217094313411"></a>The value format is <strong id="b49364643719"><a name="b49364643719"></a><a name="b49364643719"></a>x y</strong>, in percentage or pixels.</p>
    <p id="p61701543144"><a name="p61701543144"></a><a name="p61701543144"></a>The first value indicates the horizontal position, and the second value indicates the vertical position.</p>
    <p id="p917084315410"><a name="p917084315410"></a><a name="p917084315410"></a>If only one value is specified, the other value is <strong id="b2860446193717"><a name="b2860446193717"></a><a name="b2860446193717"></a>50%</strong> by default.</p>
    </td>
    </tr>
    <tr id="row10170243447"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p10170243545"><a name="p10170243545"></a><a name="p10170243545"></a>transformOrigin</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p1717018432049"><a name="p1717018432049"></a><a name="p1717018432049"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p11704431548"><a name="p11704431548"></a><a name="p11704431548"></a>'center center'</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p3170643446"><a name="p3170643446"></a><a name="p3170643446"></a>Origin position of the transformed element.</p>
    <p id="p817012431349"><a name="p817012431349"></a><a name="p817012431349"></a>The first value indicates the x-axis position. The value can be <strong id="b20914191218395"><a name="b20914191218395"></a><a name="b20914191218395"></a>left</strong>, <strong id="b16915141233913"><a name="b16915141233913"></a><a name="b16915141233913"></a>center</strong>, <strong id="b1591571233911"><a name="b1591571233911"></a><a name="b1591571233911"></a>right</strong>, a length, or a percentage.</p>
    <p id="p13170144310411"><a name="p13170144310411"></a><a name="p13170144310411"></a>The second value indicates the y-axis position. The value can be <strong id="b15935411173916"><a name="b15935411173916"></a><a name="b15935411173916"></a>top</strong>, <strong id="b994031111394"><a name="b994031111394"></a><a name="b994031111394"></a>center</strong>, <strong id="b19411111163910"><a name="b19411111163910"></a><a name="b19411111163910"></a>bottom</strong>, a length, or a percentage.</p>
    </td>
    </tr>
    <tr id="row201701443642"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p1017094315419"><a name="p1017094315419"></a><a name="p1017094315419"></a>transform</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p12170043049"><a name="p12170043049"></a><a name="p12170043049"></a><a href="js-components-common-animation.md#table28802443315">Transform</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p14171243748"><a name="p14171243748"></a><a name="p14171243748"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="p18171174315410"><a name="p18171174315410"></a><a name="p18171174315410"></a>Transformation type set for a transformed element.</p>
    </td>
    </tr>
    <tr id="row181715431943"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="p91710436416"><a name="p91710436416"></a><a name="p91710436416"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="p317164312412"><a name="p317164312412"></a><a name="p317164312412"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="p1171154312414"><a name="p1171154312414"></a><a name="p1171154312414"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><a name="ul1017119439418"></a><a name="ul1017119439418"></a><ul id="ul1017119439418"><li>The value of <strong id="b0754154863713"><a name="b0754154863713"></a><a name="b0754154863713"></a>offset</strong> must be within (0.0,1.0] and sorted in ascending order if it is provided.</li><li>If there are only two frames, <strong id="b10139164983712"><a name="b10139164983712"></a><a name="b10139164983712"></a>offset</strong> can be left empty.</li><li>If there are more than two frames, <strong id="b97100207390"><a name="b97100207390"></a><a name="b97100207390"></a>offset</strong> is mandatory.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  3**  Options description

    <a name="table703167514"></a>
    <table><thead align="left"><tr id="row2008161451"><th class="cellrowborder" valign="top" width="18.89%" id="mcps1.2.5.1.1"><p id="p604163517"><a name="p604163517"></a><a name="p604163517"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.560000000000002%" id="mcps1.2.5.1.2"><p id="p1207161254"><a name="p1207161254"></a><a name="p1207161254"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.22%" id="mcps1.2.5.1.3"><p id="p1200161752"><a name="p1200161752"></a><a name="p1200161752"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.33%" id="mcps1.2.5.1.4"><p id="p11111167510"><a name="p11111167510"></a><a name="p11111167510"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row71161610512"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p151131617520"><a name="p151131617520"></a><a name="p151131617520"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p17141617518"><a name="p17141617518"></a><a name="p17141617518"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p611816450"><a name="p611816450"></a><a name="p611816450"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p1011161458"><a name="p1011161458"></a><a name="p1011161458"></a>Duration for playing the animation, in milliseconds.</p>
    </td>
    </tr>
    <tr id="row31121616517"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p1211316658"><a name="p1211316658"></a><a name="p1211316658"></a>easing</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p101616757"><a name="p101616757"></a><a name="p101616757"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p91131618515"><a name="p91131618515"></a><a name="p91131618515"></a>linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p1615165512"><a name="p1615165512"></a><a name="p1615165512"></a>Time curve of the animation. For details about the supported types, see <a href="#table12317161054">Available values of the easing attribute</a>.</p>
    </td>
    </tr>
    <tr id="row161816758"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p615163514"><a name="p615163514"></a><a name="p615163514"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p8116161512"><a name="p8116161512"></a><a name="p8116161512"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p1111163514"><a name="p1111163514"></a><a name="p1111163514"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p131616659"><a name="p131616659"></a><a name="p131616659"></a>Delay for the animation start. The default value indicates no delay.</p>
    </td>
    </tr>
    <tr id="row4117165514"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p61016252"><a name="p61016252"></a><a name="p61016252"></a>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p152316953"><a name="p152316953"></a><a name="p152316953"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p18281617510"><a name="p18281617510"></a><a name="p18281617510"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p32201615513"><a name="p32201615513"></a><a name="p32201615513"></a>Number of times the animation will be played. <strong id="b1119019523812"><a name="b1119019523812"></a><a name="b1119019523812"></a>number</strong> indicates a fixed number of playback operations, and <strong id="b319110563816"><a name="b319110563816"></a><a name="b319110563816"></a>Infinity</strong> indicates an unlimited number of playback operations.</p>
    </td>
    </tr>
    <tr id="row8215166510"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p182131611511"><a name="p182131611511"></a><a name="p182131611511"></a>direction<sup id="sup325161155"><a name="sup325161155"></a><a name="sup325161155"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p18215161656"><a name="p18215161656"></a><a name="p18215161656"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p1827167510"><a name="p1827167510"></a><a name="p1827167510"></a>normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p9281612515"><a name="p9281612515"></a><a name="p9281612515"></a>Mode of playing the animation.</p>
    <p id="p132101617517"><a name="p132101617517"></a><a name="p132101617517"></a><strong id="b661265611817"><a name="b661265611817"></a><a name="b661265611817"></a>normal</strong>: Plays the animation in forward loop mode.</p>
    <p id="p3215161154"><a name="p3215161154"></a><a name="p3215161154"></a><strong id="b315117564199"><a name="b315117564199"></a><a name="b315117564199"></a>reverse</strong>: Plays the animation in reverse loop mode.</p>
    <p id="p1321816454"><a name="p1321816454"></a><a name="p1321816454"></a><strong id="b01883517209"><a name="b01883517209"></a><a name="b01883517209"></a>alternate</strong>: Plays the animation in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in backward direction. </p>
    <p id="p22181618510"><a name="p22181618510"></a><a name="p22181618510"></a><strong id="b1122444132810"><a name="b1122444132810"></a><a name="b1122444132810"></a>alternate-reverse</strong>: Plays the animation in reverse-alternating loop mode. When the animation is played for an odd number of times, the playback is in backward direction. When the animation is played for an even number of times, the playback is in forward direction. </p>
    </td>
    </tr>
    <tr id="row1229163512"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="p32111618513"><a name="p32111618513"></a><a name="p32111618513"></a>fill</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="p622161515"><a name="p622161515"></a><a name="p622161515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="p1424162520"><a name="p1424162520"></a><a name="p1424162520"></a>none</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="p102171619515"><a name="p102171619515"></a><a name="p102171619515"></a>Start and end styles of the animation.</p>
    <p id="p14220167520"><a name="p14220167520"></a><a name="p14220167520"></a><strong id="b95102196241659"><a name="b95102196241659"></a><a name="b95102196241659"></a>none</strong>: No style is applied to the target before or after the animation is executed.</p>
    <p id="p202916355"><a name="p202916355"></a><a name="p202916355"></a><strong id="b60720248341659"><a name="b60720248341659"></a><a name="b60720248341659"></a>forwards</strong>: The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed.</p>
    <p id="p17211168516"><a name="p17211168516"></a><a name="p17211168516"></a><strong id="b46810291047"><a name="b46810291047"></a><a name="b46810291047"></a>backwards</strong><sup id="sup138811738182"><a name="sup138811738182"></a><a name="sup138811738182"></a>6+</sup>: The animation uses the value defined in the first key frame during the <strong id="b835517106516"><a name="b835517106516"></a><a name="b835517106516"></a>animation-delay</strong>. When <strong id="b133698551511"><a name="b133698551511"></a><a name="b133698551511"></a>animation-direction</strong> is set to <strong id="b2327558755"><a name="b2327558755"></a><a name="b2327558755"></a>normal</strong> or <strong id="b1599365910513"><a name="b1599365910513"></a><a name="b1599365910513"></a>alternate</strong>, the value in the <strong id="b451431119612"><a name="b451431119612"></a><a name="b451431119612"></a>from</strong> key frame is used. When <strong id="b167462211565"><a name="b167462211565"></a><a name="b167462211565"></a>animation-direction</strong> is set to <strong id="b122791361617"><a name="b122791361617"></a><a name="b122791361617"></a>reverse</strong> or <strong id="b63560395611"><a name="b63560395611"></a><a name="b63560395611"></a>alternate-reverse</strong>, the value in the <strong id="b19219491061"><a name="b19219491061"></a><a name="b19219491061"></a>to</strong> key frame is used.</p>
    <p id="p13201614513"><a name="p13201614513"></a><a name="p13201614513"></a><strong id="b13700558762"><a name="b13700558762"></a><a name="b13700558762"></a>both</strong><sup id="sup1588111341817"><a name="sup1588111341817"></a><a name="sup1588111341817"></a>6+</sup>: The animation follows the <strong id="b693012181778"><a name="b693012181778"></a><a name="b693012181778"></a>forwards</strong> and <strong id="b991216202075"><a name="b991216202075"></a><a name="b991216202075"></a>backwards</strong> rules.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  4**  Available values of the easing attribute

    <a name="table12317161054"></a>
    <table><thead align="left"><tr id="row731161656"><th class="cellrowborder" valign="top" width="37.940000000000005%" id="mcps1.2.3.1.1"><p id="p1317161058"><a name="p1317161058"></a><a name="p1317161058"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.06%" id="mcps1.2.3.1.2"><p id="p163016458"><a name="p163016458"></a><a name="p163016458"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7371610517"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p19313165510"><a name="p19313165510"></a><a name="p19313165510"></a>linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p163716759"><a name="p163716759"></a><a name="p163716759"></a>The animation speed keeps unchanged.</p>
    </td>
    </tr>
    <tr id="row133616555"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p1320161259"><a name="p1320161259"></a><a name="p1320161259"></a>ease-in</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p531216355"><a name="p531216355"></a><a name="p531216355"></a>The animation starts at a low speed. <strong id="b378417512383"><a name="b378417512383"></a><a name="b378417512383"></a>cubic-bezier(0.42, 0.0, 1.0, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row2316163512"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p1036162513"><a name="p1036162513"></a><a name="p1036162513"></a>ease-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p14310161158"><a name="p14310161158"></a><a name="p14310161158"></a>The animation ends at a low speed. <strong id="b715465119387"><a name="b715465119387"></a><a name="b715465119387"></a>cubic-bezier(0.0, 0.0, 0.58, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row14314160513"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p7361613513"><a name="p7361613513"></a><a name="p7361613513"></a>ease-in-out</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p194111615511"><a name="p194111615511"></a><a name="p194111615511"></a>The animation starts and ends at a low speed. <strong id="b1526650183812"><a name="b1526650183812"></a><a name="b1526650183812"></a>cubic-bezier(0.42, 0.0, 0.58, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row1415161357"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p5411166515"><a name="p5411166515"></a><a name="p5411166515"></a>friction</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p84316652"><a name="p84316652"></a><a name="p84316652"></a>Damping curve, <strong id="b2065404720381"><a name="b2065404720381"></a><a name="b2065404720381"></a>cubic-bezier(0.2, 0.0, 0.2, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row645164513"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p17416167514"><a name="p17416167514"></a><a name="p17416167514"></a>extreme-deceleration</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p164316255"><a name="p164316255"></a><a name="p164316255"></a>Extreme deceleration curve, <strong id="b84625466389"><a name="b84625466389"></a><a name="b84625466389"></a>cubic-bezier(0.0, 0.0, 0.0, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row11419161458"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p6411619517"><a name="p6411619517"></a><a name="p6411619517"></a>sharp</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p4414161554"><a name="p4414161554"></a><a name="p4414161554"></a>Sharp curve, <strong id="b13866045193817"><a name="b13866045193817"></a><a name="b13866045193817"></a>cubic-bezier(0.33, 0.0, 0.67, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row4461613518"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p20591614514"><a name="p20591614514"></a><a name="p20591614514"></a>rhythm</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p551416955"><a name="p551416955"></a><a name="p551416955"></a>Rhythm curve, <strong id="b1230104513388"><a name="b1230104513388"></a><a name="b1230104513388"></a>cubic-bezier(0.7, 0.0, 0.2, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row951716752"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p105181619510"><a name="p105181619510"></a><a name="p105181619510"></a>smooth</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p1251416256"><a name="p1251416256"></a><a name="p1251416256"></a>Smooth curve, <strong id="b8396144416387"><a name="b8396144416387"></a><a name="b8396144416387"></a>cubic-bezier(0.4, 0.0, 0.4, 1.0)</strong>.</p>
    </td>
    </tr>
    <tr id="row954162052"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p15501614511"><a name="p15501614511"></a><a name="p15501614511"></a>cubic-bezier(x1, y1, x2, y2)</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p195121611510"><a name="p195121611510"></a><a name="p195121611510"></a>You can customize an animation speed curve in the <strong id="b55061643143812"><a name="b55061643143812"></a><a name="b55061643143812"></a>cubic-bezier()</strong> function. The x and y values of each input parameter must be between 0 and 1.</p>
    </td>
    </tr>
    <tr id="row1557166519"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="p175151613512"><a name="p175151613512"></a><a name="p175151613512"></a>steps(number, step-position)<sup id="sup165201613515"><a name="sup165201613515"></a><a name="sup165201613515"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="p17510161150"><a name="p17510161150"></a><a name="p17510161150"></a>Step curve.</p>
    <p id="p1359161455"><a name="p1359161455"></a><a name="p1359161455"></a>The <strong id="b1284724173817"><a name="b1284724173817"></a><a name="b1284724173817"></a>number</strong> must be set and only an integer is supported.</p>
    <p id="p15519162512"><a name="p15519162512"></a><a name="p15519162512"></a><strong id="b1076620494398"><a name="b1076620494398"></a><a name="b1076620494398"></a>step-position</strong> is optional. It can be set to <strong id="b8772949153918"><a name="b8772949153918"></a><a name="b8772949153918"></a>start</strong> or <strong id="b377374953915"><a name="b377374953915"></a><a name="b377374953915"></a>end</strong>. The default value is <strong id="b177731949163918"><a name="b177731949163918"></a><a name="b177731949163918"></a>end</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    The  **animation**  attributes are as follows.

    <a name="table86771854185317"></a>
    <table><thead align="left"><tr id="row206778544533"><th class="cellrowborder" valign="top" width="16.48%" id="mcps1.1.4.1.1"><p id="p18677115418539"><a name="p18677115418539"></a><a name="p18677115418539"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.46%" id="mcps1.1.4.1.2"><p id="p86775543533"><a name="p86775543533"></a><a name="p86775543533"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.06%" id="mcps1.1.4.1.3"><p id="p56771154115317"><a name="p56771154115317"></a><a name="p56771154115317"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5677654105311"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="p2677654175313"><a name="p2677654175313"></a><a name="p2677654175313"></a>finished</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="p367785419539"><a name="p367785419539"></a><a name="p367785419539"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="p8677254205313"><a name="p8677254205313"></a><a name="p8677254205313"></a>Read-only attribute, which indicates whether the animation playback is complete.</p>
    </td>
    </tr>
    <tr id="row206771154145317"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="p1967725418536"><a name="p1967725418536"></a><a name="p1967725418536"></a>pending</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="p15677185415319"><a name="p15677185415319"></a><a name="p15677185415319"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="p11678185413534"><a name="p11678185413534"></a><a name="p11678185413534"></a>Read-only attribute, which indicates whether the animation is waiting for the completion of other asynchronous operations (for example, start an animation with a delay).</p>
    </td>
    </tr>
    <tr id="row14678254135314"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="p767855414537"><a name="p767855414537"></a><a name="p767855414537"></a>playState</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="p46789542539"><a name="p46789542539"></a><a name="p46789542539"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="p767885475320"><a name="p767885475320"></a><a name="p767885475320"></a>Read-write attribute, which indicates the playback status of the animation:</p>
    <a name="ul467812544531"></a><a name="ul467812544531"></a><ul id="ul467812544531"><li><strong id="b111155323383"><a name="b111155323383"></a><a name="b111155323383"></a>idle</strong>: The animation is not running (playback ended or not started).</li><li><strong id="b16562194011527"><a name="b16562194011527"></a><a name="b16562194011527"></a>running</strong>: The animation is running.</li><li><strong id="b1262634712524"><a name="b1262634712524"></a><a name="b1262634712524"></a>paused</strong>: The animation is paused.</li><li><strong id="b9892827103810"><a name="b9892827103810"></a><a name="b9892827103810"></a>finished</strong>: Animation playback ends.</li></ul>
    </td>
    </tr>
    <tr id="row167835416535"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="p1467835495319"><a name="p1467835495319"></a><a name="p1467835495319"></a>startTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="p5678554175311"><a name="p5678554175311"></a><a name="p5678554175311"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="p1667855415532"><a name="p1667855415532"></a><a name="p1667855415532"></a>Read-write attribute, which indicates the animation start time. This attribute is similar to <strong id="b20841169134017"><a name="b20841169134017"></a><a name="b20841169134017"></a>delay</strong> in the <strong id="b1684113915405"><a name="b1684113915405"></a><a name="b1684113915405"></a>options</strong> attribute.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Methods for animation

    <a name="table186781154155316"></a>
    <table><thead align="left"><tr id="row067825410537"><th class="cellrowborder" valign="top" width="30.86%" id="mcps1.1.4.1.1"><p id="p17678454155319"><a name="p17678454155319"></a><a name="p17678454155319"></a>Method</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.58%" id="mcps1.1.4.1.2"><p id="p1967935445311"><a name="p1967935445311"></a><a name="p1967935445311"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.56%" id="mcps1.1.4.1.3"><p id="p10679154105313"><a name="p10679154105313"></a><a name="p10679154105313"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row116791054135314"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="p1967935416536"><a name="p1967935416536"></a><a name="p1967935416536"></a>play</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="p16679205416532"><a name="p16679205416532"></a><a name="p16679205416532"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p967912541534"><a name="p967912541534"></a><a name="p967912541534"></a>Plays the animation.</p>
    </td>
    </tr>
    <tr id="row146791354155316"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="p067911546534"><a name="p067911546534"></a><a name="p067911546534"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="p7679105413534"><a name="p7679105413534"></a><a name="p7679105413534"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p12679135412530"><a name="p12679135412530"></a><a name="p12679135412530"></a>Ends the animation.</p>
    </td>
    </tr>
    <tr id="row1679175419539"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="p17679354205318"><a name="p17679354205318"></a><a name="p17679354205318"></a>pause</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="p967975445319"><a name="p967975445319"></a><a name="p967975445319"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p15679155425319"><a name="p15679155425319"></a><a name="p15679155425319"></a>Pauses the animation.</p>
    </td>
    </tr>
    <tr id="row206791654125318"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="p12679135485318"><a name="p12679135485318"></a><a name="p12679135485318"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="p14679154115317"><a name="p14679154115317"></a><a name="p14679154115317"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p96791254105312"><a name="p96791254105312"></a><a name="p96791254105312"></a>Cancels the animation.</p>
    </td>
    </tr>
    <tr id="row14679254155310"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="p967918543539"><a name="p967918543539"></a><a name="p967918543539"></a>reverse</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="p13680195475311"><a name="p13680195475311"></a><a name="p13680195475311"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p66803548537"><a name="p66803548537"></a><a name="p66803548537"></a>Plays the animation in reverse.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Events for animation

    <a name="table4680554175314"></a>
    <table><thead align="left"><tr id="row1768055445313"><th class="cellrowborder" valign="top" width="20.79%" id="mcps1.1.3.1.1"><p id="p1968016548530"><a name="p1968016548530"></a><a name="p1968016548530"></a>Event</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.21000000000001%" id="mcps1.1.3.1.2"><p id="p196801454195314"><a name="p196801454195314"></a><a name="p196801454195314"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1568010543534"><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p id="p1268075419535"><a name="p1268075419535"></a><a name="p1268075419535"></a>start<sup id="sup6680135435314"><a name="sup6680135435314"></a><a name="sup6680135435314"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p id="p5680554185315"><a name="p5680554185315"></a><a name="p5680554185315"></a>The animation starts.</p>
    </td>
    </tr>
    <tr id="row96801854175315"><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p id="p86802054135311"><a name="p86802054135311"></a><a name="p86802054135311"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p id="p2068055455314"><a name="p2068055455314"></a><a name="p2068055455314"></a>The animation is forcibly canceled.</p>
    </td>
    </tr>
    <tr id="row1268010544532"><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p id="p17680185445314"><a name="p17680185445314"></a><a name="p17680185445314"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p id="p56802054195316"><a name="p56802054195316"></a><a name="p56802054195316"></a>The animation playback is complete.</p>
    </td>
    </tr>
    <tr id="row1268016540533"><td class="cellrowborder" valign="top" width="20.79%" headers="mcps1.1.3.1.1 "><p id="p15681165425316"><a name="p15681165425316"></a><a name="p15681165425316"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.21000000000001%" headers="mcps1.1.3.1.2 "><p id="p6681205418538"><a name="p6681205418538"></a><a name="p6681205418538"></a>The animation repeats.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div id="idName" class="box"></div>
      <div class="buttonBox">
        <button @click="start">
          start
        </button>
        <button @click="cancel">
          cancels
        </button>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
    }
    .box{
      width: 200px;
      height: 200px;
      background-color: #ff0000;
      margin-top: 30px;
    }
    .buttonBox{
      margin-top: 30px;
      width: 250px;
      justify-content: space-between;
    }
    button{
      background-color: #8e8b89;
      color: white;
      width: 100px;
      height: 40px;
      font-size: 24px;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default{
      data:{
        animation:'',
      },
      onInit(){
      },
      onShow(){
        var options = {
          duration: 1500,
          easing: 'friction',
          delay: 500,
          fill: 'forwards',
          iterations: 2,
          direction: 'normal',
        };
        var frames = [
          {transform: {translate: '-120px -0px'}, opacity: 0.1, offset: 0.0},
          {transform: {translate: '120px 0px'}, opacity: 1.0, offset: 1.0}
        ];
        this.animation = this.$element('idName').animate(frames, options);
        // handle finish event
        this.animation.onfinish = function(){
          prompt.showToast({
            message: "The animation is finished."
          });
        };
        // handle cancel event
        this.animation.oncancel = function(){
          prompt.showToast({
            message: "The animation is canceled."
          });
        };
        // handle repeat event
        this.animation.onrepeat = function(){
           prompt.showToast({
              message: "The animation is repeated."
           });
        };
      },
      start(){
        this.animation.play();
      },
      cancel(){
        this.animation.cancel();
      }
    }
    ```

    ![](figures/animationapi-4.gif)


## getBoundingClientRect<a name="section11967381328"></a>

getBoundingClientRect\(\):  [ <Rect\>](#table1650917111414)

Obtains the size of the element and its position relative to the window.

-   Return values

    **Table  5**  Rect attributes<sup>6+</sup>

    <a name="table1650917111414"></a>
    <table><thead align="left"><tr id="row950910718147"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1850919701410"><a name="p1850919701410"></a><a name="p1850919701410"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1250915711417"><a name="p1250915711417"></a><a name="p1250915711417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p05091715144"><a name="p05091715144"></a><a name="p05091715144"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row550917701419"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2050911714144"><a name="p2050911714144"></a><a name="p2050911714144"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1550914717144"><a name="p1550914717144"></a><a name="p1550914717144"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p105091477141"><a name="p105091477141"></a><a name="p105091477141"></a>Width of an element.</p>
    </td>
    </tr>
    <tr id="row450913719141"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p850919761418"><a name="p850919761418"></a><a name="p850919761418"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p135098712142"><a name="p135098712142"></a><a name="p135098712142"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p65099718144"><a name="p65099718144"></a><a name="p65099718144"></a>Height of an element.</p>
    </td>
    </tr>
    <tr id="row155090751416"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p115093712147"><a name="p115093712147"></a><a name="p115093712147"></a>left</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1051057171411"><a name="p1051057171411"></a><a name="p1051057171411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1051016719148"><a name="p1051016719148"></a><a name="p1051016719148"></a>Offset between the left boundary of the element and the window.</p>
    </td>
    </tr>
    <tr id="row351016710149"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15101377145"><a name="p15101377145"></a><a name="p15101377145"></a>top</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1151019710142"><a name="p1151019710142"></a><a name="p1151019710142"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6510172148"><a name="p6510172148"></a><a name="p6510172148"></a>Offset between the upper boundary of the element and the window.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // xxx.js
    var rect = this.$element('id').getBoundingClientRect();
    console.info(`current element position is ${rect.left}, ${rect.top}`);
    ```


## createIntersectionObserver<a name="section7425195215615"></a>

createIntersectionObserver\(param?:  ObserverParam):Observer

Gets notified of the visibility of an element on the current page.

-   Name

    <a name="table567561815123"></a>
    <table><thead align="left"><tr id="row15675201881219"><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.5.1.1"><p id="p126751318151215"><a name="p126751318151215"></a><a name="p126751318151215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.1%" id="mcps1.1.5.1.2"><p id="p12675818131212"><a name="p12675818131212"></a><a name="p12675818131212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p9675111861212"><a name="p9675111861212"></a><a name="p9675111861212"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p56751118111216"><a name="p56751118111216"></a><a name="p56751118111216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row126751718121213"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p id="p46751418151217"><a name="p46751418151217"></a><a name="p46751418151217"></a>param</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="p176751018141220"><a name="p176751018141220"></a><a name="p176751018141220"></a><a href="#table1335524911817">ObserverParam</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1667561821211"><a name="p1667561821211"></a><a name="p1667561821211"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p116759187124"><a name="p116759187124"></a><a name="p116759187124"></a>Obtains the observer callback.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  6**  ObserverParam attributes<sup>6+</sup>

    <a name="table1335524911817"></a>
    <table><thead align="left"><tr id="row18355104917180"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p43551349141810"><a name="p43551349141810"></a><a name="p43551349141810"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p5355164914188"><a name="p5355164914188"></a><a name="p5355164914188"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p33551849111811"><a name="p33551849111811"></a><a name="p33551849111811"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1335512499188"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p143553491189"><a name="p143553491189"></a><a name="p143553491189"></a>ratios</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p183553494182"><a name="p183553494182"></a><a name="p183553494182"></a>Array&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p153551949101819"><a name="p153551949101819"></a><a name="p153551949101819"></a>When the component is out of the range or is less than the range, the observer callback is triggered.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    **Table  7**  Methods supported by the Observer object<sup>6+</sup>

    <a name="table4506633141711"></a>
    <table><thead align="left"><tr id="row4507163301712"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p55074331172"><a name="p55074331172"></a><a name="p55074331172"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p8507033151711"><a name="p8507033151711"></a><a name="p8507033151711"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1650743315176"><a name="p1650743315176"></a><a name="p1650743315176"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row550783311177"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1050793319175"><a name="p1050793319175"></a><a name="p1050793319175"></a>observe</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p650713351713"><a name="p650713351713"></a><a name="p650713351713"></a>callback: function</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p750713361718"><a name="p750713361718"></a><a name="p750713361718"></a>Subscribes to events of the observed object. The callback method is called when the value is greater than or less than the threshold.</p>
    </td>
    </tr>
    <tr id="row25071033191712"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1350712333172"><a name="p1350712333172"></a><a name="p1350712333172"></a>unobserve</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p115071333121720"><a name="p115071333121720"></a><a name="p115071333121720"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6507183311710"><a name="p6507183311710"></a><a name="p6507183311710"></a>Unsubscribes from events of the observed object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // xxx.js
    let observer = this.$element('broad').createIntersectionObserver({
      ratios: [0.2, 0.5], // number
    });
    
    observer.observe((isVisible, ratio)=> {
        console.info('this element is ' + isVisible + 'ratio is ' + ratio)
    })
    
    observer.unobserve()
    ```


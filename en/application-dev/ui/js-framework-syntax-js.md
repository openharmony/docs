# JavaScript<a name="EN-US_TOPIC_0000001173164729"></a>

You can use a  **.js**  file to define the service logic of an HML page. The JS UI framework supports the JavaScript language that conforms to the ECMAScript specification. With dynamic typing, JavaScript can make your application more expressive with a flexible design. The following describes the JavaScript compilation and running.

## Syntax<a name="s6ca2e99746664509961f65b82d11ab58"></a>

The ES6 syntax is supported. 

-   **Module declaration**

    Import functionality modules.

    ```
    import router from '@system.router';
    ```

-   **Code reference**

    Import JavaScript code.

    ```
    import utils from '../../common/utils.js';
    ```


## Objects<a name="s7493791622a248fbb2e03703149bb3b5"></a>

-   **Application Object**

    <a name="tc5261f21b7014f6cbe17d3ef51b9e1a9"></a>
    <table><thead align="left"><tr id="r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="ae816119c3e0143c892512012c7927037"><a name="ae816119c3e0143c892512012c7927037"></a><a name="ae816119c3e0143c892512012c7927037"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="ab72e901bb3ef4657b303513b8fa5ec1f"><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="ae95f3df496fc41939ac6c1cf74aef9d8"><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r170881741fb347fa9bc5ac3a33382a9b"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="a9a70780b9fd8468d98a7c107ee67d8d8"><a name="a9a70780b9fd8468d98a7c107ee67d8d8"></a><a name="a9a70780b9fd8468d98a7c107ee67d8d8"></a>$def</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="ace202d9f2dd547c8ab8693954af5d616"><a name="ace202d9f2dd547c8ab8693954af5d616"></a><a name="ace202d9f2dd547c8ab8693954af5d616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="a08a4d55b01864b2fa866f6431cd322de"><a name="a08a4d55b01864b2fa866f6431cd322de"></a><a name="a08a4d55b01864b2fa866f6431cd322de"></a>Object that is exposed in the <strong id="b1245054215141"><a name="b1245054215141"></a><a name="b1245054215141"></a>app.js</strong> file and obtained by <strong id="b466541113154"><a name="b466541113154"></a><a name="b466541113154"></a>this.$app.$def</strong>.</p>
    <div class="note" id="note23038122918"><a name="note23038122918"></a><a name="note23038122918"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p73038121790"><a name="p73038121790"></a><a name="p73038121790"></a>Application objects do not support data binding. Data update should be triggered on the UI.</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

    Example Code

    ```
    // app.js
    export default {
      onCreate() {
        console.info('Application onCreate');
      },
      onDestroy() {
        console.info('Application onDestroy');
      },
      globalData: {
        appData: 'appData',
        appVersion: '2.0',
      },
      globalMethod() {
        console.info('This is a global method!');
        this.globalData.appVersion = '3.0';
      }
    };
    ```

    ```
    // index.js
    export default {
      data: {
        appData: 'localData',
        appVersion:'1.0',
      },
      onInit() {
        this.appData = this.$app.$def.globalData.appData;
        this.appVersion = this.$app.$def.globalData.appVersion;
      },
      invokeGlobalMethod() {
        this.$app.$def.globalMethod();
      },
      getAppVersion() {
        this.appVersion = this.$app.$def.globalData.appVersion;
      }
    }
    ```

-   **Page objects**

    <a name="table8514281151"></a>
    <table><thead align="left"><tr id="row2511928359"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="p1951028754"><a name="p1951028754"></a><a name="p1951028754"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.71%" id="mcps1.1.4.1.2"><p id="p1351228252"><a name="p1351228252"></a><a name="p1351228252"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.66%" id="mcps1.1.4.1.3"><p id="p651112815519"><a name="p651112815519"></a><a name="p651112815519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1651228855"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p115421323762"><a name="p115421323762"></a><a name="p115421323762"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p05120283516"><a name="p05120283516"></a><a name="p05120283516"></a>Object/Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p61056578507"><a name="p61056578507"></a><a name="p61056578507"></a>Data model of the page. If the attribute is of the function type, the return value must be of the object type. The attribute name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (<strong id="b430716571284"><a name="b430716571284"></a><a name="b430716571284"></a>for</strong>, <strong id="b1341785992814"><a name="b1341785992814"></a><a name="b1341785992814"></a>if</strong>, <strong id="b11287152152914"><a name="b11287152152914"></a><a name="b11287152152914"></a>show</strong>, and <strong id="b15341857297"><a name="b15341857297"></a><a name="b15341857297"></a>tid</strong>).</p>
    <p id="p95116281350"><a name="p95116281350"></a><a name="p95116281350"></a>Do not use this attribute and <strong id="b166710411103"><a name="b166710411103"></a><a name="b166710411103"></a>private</strong> or <strong id="b3689175611101"><a name="b3689175611101"></a><a name="b3689175611101"></a>public</strong> at the same time.</p>
    </td>
    </tr>
    <tr id="row2991343201512"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p1873818536545"><a name="p1873818536545"></a><a name="p1873818536545"></a>$refs</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p1073815318541"><a name="p1073815318541"></a><a name="p1073815318541"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p7879941512"><a name="p7879941512"></a><a name="p7879941512"></a>DOM elements or child component instances that have registered the <strong id="b230018334315"><a name="b230018334315"></a><a name="b230018334315"></a>ref</strong> attribute. For example code, see <a href="#section1560185062215">Obtaining a DOM element</a>.</p>
    </td>
    </tr>
    <tr id="row340610191094"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p240712191998"><a name="p240712191998"></a><a name="p240712191998"></a>private</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p1840710194916"><a name="p1840710194916"></a><a name="p1840710194916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p17407161911917"><a name="p17407161911917"></a><a name="p17407161911917"></a>Data model of the page. Private data attribute can be modified only on the current page.</p>
    </td>
    </tr>
    <tr id="row594316386514"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p99441138554"><a name="p99441138554"></a><a name="p99441138554"></a>public</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p994419381151"><a name="p994419381151"></a><a name="p994419381151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p2094418381153"><a name="p2094418381153"></a><a name="p2094418381153"></a>Data model of the page. Behaviors of public data attributes are the same as those of the <strong id="b17852928193814"><a name="b17852928193814"></a><a name="b17852928193814"></a>data</strong> attribute.</p>
    </td>
    </tr>
    <tr id="row638815278598"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p139903755910"><a name="p139903755910"></a><a name="p139903755910"></a>props</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p4258153555911"><a name="p4258153555911"></a><a name="p4258153555911"></a>Array/Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p12388227105918"><a name="p12388227105918"></a><a name="p12388227105918"></a>Used for communication between components. This attribute can be transferred to components via <strong id="b1374684104018"><a name="b1374684104018"></a><a name="b1374684104018"></a>&lt;tag xxxx='value'&gt;</strong>. A <strong id="b967863454012"><a name="b967863454012"></a><a name="b967863454012"></a>props</strong> name must be in lowercase and cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (<strong id="b36181719414"><a name="b36181719414"></a><a name="b36181719414"></a>for</strong>, <strong id="b18297336418"><a name="b18297336418"></a><a name="b18297336418"></a>if</strong>, <strong id="b350916444117"><a name="b350916444117"></a><a name="b350916444117"></a>show</strong>, and <strong id="b123692654113"><a name="b123692654113"></a><a name="b123692654113"></a>tid</strong>). Currently, <strong id="b1660371715416"><a name="b1660371715416"></a><a name="b1660371715416"></a>props</strong> does not support functions. For details, see <a href="../nottoctopics/en-us_topic_0000001173164675.md">Custom Components</a>.</p>
    </td>
    </tr>
    <tr id="row14421201293417"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p144221012173416"><a name="p144221012173416"></a><a name="p144221012173416"></a>computed</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="p164221412163412"><a name="p164221412163412"></a><a name="p164221412163412"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="p6422712153413"><a name="p6422712153413"></a><a name="p6422712153413"></a>Used for pre-processing an object for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words. For details, see <a href="../nottoctopics/en-us_topic_0000001173164675.md">Custom Components</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Functions<a name="s4e1ff24ec78e41948502d8977d24e44c"></a>

-   **Data functions**

    <a name="td998a97f34c44c86876d2e1aee646bc6"></a>
    <table><thead align="left"><tr id="r41906fbf818041e089ab60c9d410de72"><th class="cellrowborder" valign="top" width="11.361136113611362%" id="mcps1.1.4.1.1"><p id="a44385457c0224b7aa0af4b8aaa5fec41"><a name="a44385457c0224b7aa0af4b8aaa5fec41"></a><a name="a44385457c0224b7aa0af4b8aaa5fec41"></a>Function</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.53165316531653%" id="mcps1.1.4.1.2"><p id="a21e0645662414f9893af7ff3a6e24e92"><a name="a21e0645662414f9893af7ff3a6e24e92"></a><a name="a21e0645662414f9893af7ff3a6e24e92"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.10721072107211%" id="mcps1.1.4.1.3"><p id="add5a5e57df3a4d47a09a8f3ef2a28088"><a name="add5a5e57df3a4d47a09a8f3ef2a28088"></a><a name="add5a5e57df3a4d47a09a8f3ef2a28088"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="rcba2037b58704ed9bef75b912b96eb80"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="a75bccc07529343469aad71db98e70b1a"><a name="a75bccc07529343469aad71db98e70b1a"></a><a name="a75bccc07529343469aad71db98e70b1a"></a>$set</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="a53419b7e4fde4993b3ab35ad3312c4da"><a name="a53419b7e4fde4993b3ab35ad3312c4da"></a><a name="a53419b7e4fde4993b3ab35ad3312c4da"></a>key: string, value: any</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="p84781851442"><a name="p84781851442"></a><a name="p84781851442"></a>Adds an attribute or modifies an existing attribute.</p>
    <p id="ae55e2b1d9401454c8555cbb419068829"><a name="ae55e2b1d9401454c8555cbb419068829"></a><a name="ae55e2b1d9401454c8555cbb419068829"></a>Usage:</p>
    <p id="a266dfd3b1b384811b4e7d9a39350e3bc"><a name="a266dfd3b1b384811b4e7d9a39350e3bc"></a><a name="a266dfd3b1b384811b4e7d9a39350e3bc"></a><strong id="b102214303161"><a name="b102214303161"></a><a name="b102214303161"></a>this.$set('</strong><em id="i153502112176"><a name="i153502112176"></a><a name="i153502112176"></a>key</em><strong id="b4382163315169"><a name="b4382163315169"></a><a name="b4382163315169"></a>',</strong><em id="i1278985981612"><a name="i1278985981612"></a><a name="i1278985981612"></a>value</em><strong id="b14689536171618"><a name="b14689536171618"></a><a name="b14689536171618"></a>)</strong>: Add an attribute.</p>
    </td>
    </tr>
    <tr id="r189d027189d842a1baf1a5d91a9af901"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="a4ee9a900fc454f66a628f210f2e50548"><a name="a4ee9a900fc454f66a628f210f2e50548"></a><a name="a4ee9a900fc454f66a628f210f2e50548"></a>$delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="a2e9d28b0f19d4cabbcc1b464bbd9993a"><a name="a2e9d28b0f19d4cabbcc1b464bbd9993a"></a><a name="a2e9d28b0f19d4cabbcc1b464bbd9993a"></a>key: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="p18897453134313"><a name="p18897453134313"></a><a name="p18897453134313"></a>Deletes an attribute.</p>
    <p id="a1e9c2271da5e4cd89dcd6b73c1b3b69d"><a name="a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a><a name="a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a>Usage:</p>
    <p id="a628cc2f32b9247b091f5d37ab0a58fdb"><a name="a628cc2f32b9247b091f5d37ab0a58fdb"></a><a name="a628cc2f32b9247b091f5d37ab0a58fdb"></a><strong id="b14701107171715"><a name="b14701107171715"></a><a name="b14701107171715"></a>this.$delete('</strong><em id="i2460141971715"><a name="i2460141971715"></a><a name="i2460141971715"></a>key</em><strong id="b121011116141712"><a name="b121011116141712"></a><a name="b121011116141712"></a>')</strong>: Delete an attribute.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Example Code

    ```
    export default {
      data: {
        keyMap: {
          OS: 'OpenHarmony',
          Version: '2.0',
        },
      },
      getAppVersion() {
        this.$set('keyMap.Version', '3.0');
        console.info("keyMap.Version = " + this.keyMap.Version); // keyMap.Version = 3.0
    
        this.$delete('keyMap');
        console.info("keyMap.Version = " + this.keyMap); // log print: keyMap.Version = undefined
      }
    }
    ```

-   **Public functions**

    <a name="te12ef71dd85347738d3670aaa9934476"></a>
    <table><thead align="left"><tr id="r7c071c236183461dbd8e78bce0073401"><th class="cellrowborder" valign="top" width="13.469999999999999%" id="mcps1.1.4.1.1"><p id="a4abb4994ac12403f88c36b8b34a739ec"><a name="a4abb4994ac12403f88c36b8b34a739ec"></a><a name="a4abb4994ac12403f88c36b8b34a739ec"></a>Function</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.4.1.2"><p id="aeac2f3bdee564731ace449ab67008c2c"><a name="aeac2f3bdee564731ace449ab67008c2c"></a><a name="aeac2f3bdee564731ace449ab67008c2c"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.62%" id="mcps1.1.4.1.3"><p id="af669c9f192954747ba61f011dcb6b1c7"><a name="af669c9f192954747ba61f011dcb6b1c7"></a><a name="af669c9f192954747ba61f011dcb6b1c7"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r786add9633394d2f8d72020f28465c87"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a6cce84705d514809ac0511d69f5605e1"><a name="a6cce84705d514809ac0511d69f5605e1"></a><a name="a6cce84705d514809ac0511d69f5605e1"></a>$element</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="ad13b3f17bec14af0859875ac75376e14"><a name="ad13b3f17bec14af0859875ac75376e14"></a><a name="ad13b3f17bec14af0859875ac75376e14"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p103681425164412"><a name="p103681425164412"></a><a name="p103681425164412"></a>Obtains the component with a specified ID. If no ID is specified, the root component is returned. For example code, see <a href="#section1560185062215">Obtaining a DOM element</a>.</p>
    <p id="a49e65fad6f094d049706c2514e8a47a9"><a name="a49e65fad6f094d049706c2514e8a47a9"></a><a name="a49e65fad6f094d049706c2514e8a47a9"></a>Usage:</p>
    <p id="a7e59962ba3154456be9a71581364ce92"><a name="a7e59962ba3154456be9a71581364ce92"></a><a name="a7e59962ba3154456be9a71581364ce92"></a><strong id="b1778371312186"><a name="b1778371312186"></a><a name="b1778371312186"></a>&lt;div id='</strong><em id="i9616171712187"><a name="i9616171712187"></a><a name="i9616171712187"></a>xxx</em><strong id="b18768154181"><a name="b18768154181"></a><a name="b18768154181"></a>'&gt;&lt;/div&gt;</strong></p>
    <a name="u338f4836774844dcbeba6ee5218a1151"></a><a name="u338f4836774844dcbeba6ee5218a1151"></a><ul id="u338f4836774844dcbeba6ee5218a1151"><li><strong id="b05751419837"><a name="b05751419837"></a><a name="b05751419837"></a>this.$element('</strong><em id="i189720245314"><a name="i189720245314"></a><a name="i189720245314"></a>xxx</em><strong id="b2658122119319"><a name="b2658122119319"></a><a name="b2658122119319"></a>')</strong>: Obtain the component whose ID is <em id="i195201110185318"><a name="i195201110185318"></a><a name="i195201110185318"></a>xxx</em>.</li><li><strong id="b1029113281236"><a name="b1029113281236"></a><a name="b1029113281236"></a>this.$element()</strong>: Obtain the root component.</li></ul>
    </td>
    </tr>
    <tr id="row1276482485914"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="p476514248597"><a name="p476514248597"></a><a name="p476514248597"></a>$rootElement</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="p107653240596"><a name="p107653240596"></a><a name="p107653240596"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p137655241599"><a name="p137655241599"></a><a name="p137655241599"></a>Obtains the root element.</p>
    <p id="p0499149904"><a name="p0499149904"></a><a name="p0499149904"></a>Usage: this.$rootElement().scrollTo({ duration: 500, position: 300 }), which scrolls the page by 300 px within 500 ms.</p>
    </td>
    </tr>
    <tr id="re1d5191790fb423282a8c381b317e0e6"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a87cad2551d564814a85a0459673a967c"><a name="a87cad2551d564814a85a0459673a967c"></a><a name="a87cad2551d564814a85a0459673a967c"></a>$root</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="aad1f4153e71544fb8b4e25d08e3787ca"><a name="aad1f4153e71544fb8b4e25d08e3787ca"></a><a name="aad1f4153e71544fb8b4e25d08e3787ca"></a>N/A</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="aff829908cf8d49948c1e736e4a88e3ac"><a name="aff829908cf8d49948c1e736e4a88e3ac"></a><a name="aff829908cf8d49948c1e736e4a88e3ac"></a>Obtains the root <strong id="b4935191919418"><a name="b4935191919418"></a><a name="b4935191919418"></a>ViewModel</strong> instance. For example code, see <a href="#section13798143717421">Obtaining the ViewModel</a>.</p>
    </td>
    </tr>
    <tr id="rd577efbcfc104ac2b5bed88fc9dd0cfb"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a680ff354c19f4d67a88b6eb45203b6d4"><a name="a680ff354c19f4d67a88b6eb45203b6d4"></a><a name="a680ff354c19f4d67a88b6eb45203b6d4"></a>$parent</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="aae2cc49b962347fba8f7dc43a1a6e072"><a name="aae2cc49b962347fba8f7dc43a1a6e072"></a><a name="aae2cc49b962347fba8f7dc43a1a6e072"></a>N/A</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="af3075c6896404f13a5c93929aa713125"><a name="af3075c6896404f13a5c93929aa713125"></a><a name="af3075c6896404f13a5c93929aa713125"></a>Obtains the parent <strong id="b11983132316413"><a name="b11983132316413"></a><a name="b11983132316413"></a>ViewModel</strong> instance. For example code, see <a href="#section13798143717421">Obtaining the ViewModel</a>.</p>
    </td>
    </tr>
    <tr id="rb96318b2fb9e4e8ea74dfb280e8fb804"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a31ac11bf6d6b477cbc1fb446d5207d0d"><a name="a31ac11bf6d6b477cbc1fb446d5207d0d"></a><a name="a31ac11bf6d6b477cbc1fb446d5207d0d"></a>$child</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="a7ea3339724db43a0b0ba574ac621f83e"><a name="a7ea3339724db43a0b0ba574ac621f83e"></a><a name="a7ea3339724db43a0b0ba574ac621f83e"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p999210407446"><a name="p999210407446"></a><a name="p999210407446"></a>Obtains the <strong id="b39768121254"><a name="b39768121254"></a><a name="b39768121254"></a>ViewModel</strong> instance of a custom child component with a specified ID. For example code, see <a href="#section13798143717421">Obtaining the ViewModel</a>.</p>
    <p id="p112537114516"><a name="p112537114516"></a><a name="p112537114516"></a>Usage:</p>
    <p id="a39f9c0db073641e5bcbcfc824769ae61"><a name="a39f9c0db073641e5bcbcfc824769ae61"></a><a name="a39f9c0db073641e5bcbcfc824769ae61"></a><strong id="b1130414126616"><a name="b1130414126616"></a><a name="b1130414126616"></a>this.$child('</strong><em id="i19634170616"><a name="i19634170616"></a><a name="i19634170616"></a>xxx</em><strong id="b64849141767"><a name="b64849141767"></a><a name="b64849141767"></a>')</strong>: Obtain the <strong id="b378518252611"><a name="b378518252611"></a><a name="b378518252611"></a>ViewModel</strong> instance of a custom child component whose ID is <em id="i1521313124719"><a name="i1521313124719"></a><a name="i1521313124719"></a>xxx</em>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   **Event function**

    <a name="table106771249184219"></a>
    <table><thead align="left"><tr id="row66781249104214"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="p15678249144218"><a name="p15678249144218"></a><a name="p15678249144218"></a>Function</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="p17678049114213"><a name="p17678049114213"></a><a name="p17678049114213"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="p26786495424"><a name="p26786495424"></a><a name="p26786495424"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row267864944212"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="p067834919421"><a name="p067834919421"></a><a name="p067834919421"></a>$watch</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="p11678194920424"><a name="p11678194920424"></a><a name="p11678194920424"></a>data: string, callback: string | Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="p1678104913426"><a name="p1678104913426"></a><a name="p1678104913426"></a>Listens for attribute changes. If the value of the <strong id="b102761759204314"><a name="b102761759204314"></a><a name="b102761759204314"></a>data</strong> attribute changes, the bound event is triggered. For details, see <a href="../nottoctopics/en-us_topic_0000001173164675.md">Custom Components</a>.</p>
    <p id="p174621629124617"><a name="p174621629124617"></a><a name="p174621629124617"></a>Usage:</p>
    <p id="p1173814312460"><a name="p1173814312460"></a><a name="p1173814312460"></a><strong id="b26791338201017"><a name="b26791338201017"></a><a name="b26791338201017"></a>this.$watch('</strong><em id="i1751741018116"><a name="i1751741018116"></a><a name="i1751741018116"></a>key</em><strong id="b111878516117"><a name="b111878516117"></a><a name="b111878516117"></a>',</strong> <em id="i38794851120"><a name="i38794851120"></a><a name="i38794851120"></a>callback</em><strong id="b13989360116"><a name="b13989360116"></a><a name="b13989360116"></a>)</strong></p>
    </td>
    </tr>
    </tbody>
    </table>

-   **Page function**

    <a name="table4927155523714"></a>
    <table><thead align="left"><tr id="row4927255113714"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="p192765520376"><a name="p192765520376"></a><a name="p192765520376"></a>Function</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="p1192715550377"><a name="p1192715550377"></a><a name="p1192715550377"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="p49275555370"><a name="p49275555370"></a><a name="p49275555370"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1692716552379"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="p199274556371"><a name="p199274556371"></a><a name="p199274556371"></a>scrollTo<sup id="sup17224503390"><a name="sup17224503390"></a><a name="sup17224503390"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="p792745512375"><a name="p792745512375"></a><a name="p792745512375"></a>scrollPageParam: <a href="#table131981833173916">ScrollPageParam</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="p1292735517377"><a name="p1292735517377"></a><a name="p1292735517377"></a>Scrolls the page to the target position. You can specify the position using the ID selector or scrolling distance.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  ScrollPageParam<sup>6+</sup>

    <a name="table131981833173916"></a>
    <table><thead align="left"><tr id="row31992331399"><th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.1"><p id="p16199113383917"><a name="p16199113383917"></a><a name="p16199113383917"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.45745425457454%" id="mcps1.2.5.1.2"><p id="p519953314398"><a name="p519953314398"></a><a name="p519953314398"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.88871112888711%" id="mcps1.2.5.1.3"><p id="p556391215143"><a name="p556391215143"></a><a name="p556391215143"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.4"><p id="p19199163393916"><a name="p19199163393916"></a><a name="p19199163393916"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12199173303914"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p8199203363916"><a name="p8199203363916"></a><a name="p8199203363916"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p11991833133916"><a name="p11991833133916"></a><a name="p11991833133916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p115641312111410"><a name="p115641312111410"></a><a name="p115641312111410"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1319943319395"><a name="p1319943319395"></a><a name="p1319943319395"></a>Position to scroll to.</p>
    </td>
    </tr>
    <tr id="row161991633143919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p41991333163919"><a name="p41991333163919"></a><a name="p41991333163919"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p1619918334392"><a name="p1619918334392"></a><a name="p1619918334392"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p756451219146"><a name="p756451219146"></a><a name="p756451219146"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1419943363915"><a name="p1419943363915"></a><a name="p1419943363915"></a>ID of the element to be scrolled to.</p>
    </td>
    </tr>
    <tr id="row191992033183919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p1919993316390"><a name="p1919993316390"></a><a name="p1919993316390"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p9199183363916"><a name="p9199183363916"></a><a name="p9199183363916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p5564181218144"><a name="p5564181218144"></a><a name="p5564181218144"></a>300</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p3199233133920"><a name="p3199233133920"></a><a name="p3199233133920"></a>Scrolling duration, in milliseconds.</p>
    </td>
    </tr>
    <tr id="row2019933315396"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p13199733133915"><a name="p13199733133915"></a><a name="p13199733133915"></a>timingFunction</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p0199173373919"><a name="p0199173373919"></a><a name="p0199173373919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p10564171212141"><a name="p10564171212141"></a><a name="p10564171212141"></a>ease</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1919903313394"><a name="p1919903313394"></a><a name="p1919903313394"></a>Animation curve for scrolling. Available option:</p>
    <p id="p158650537712"><a name="p158650537712"></a><a name="p158650537712"></a><a href="../nottoctopics/en-us_topic_0000001173164765.md">animation-timing-function</a></p>
    </td>
    </tr>
    <tr id="row110635616428"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p6107856124211"><a name="p6107856124211"></a><a name="p6107856124211"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p20107195674214"><a name="p20107195674214"></a><a name="p20107195674214"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p20564151211419"><a name="p20564151211419"></a><a name="p20564151211419"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1107155694210"><a name="p1107155694210"></a><a name="p1107155694210"></a>Callback to be invoked when the scrolling is complete.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Example:

    ```
    this.$rootElement.scrollTo({position: 0})
    this.$rootElement.scrollTo({id: 'id', duration: 200, timingFunction: 'ease-in', complete: ()=>void})
    ```


## Obtaining a DOM Element<a name="section1560185062215"></a>

1.  Use  **$refs**  to obtain a DOM element.

    ```
    <!-- index.hml -->
    <div class="container">
      <image-animator class="image-player" ref="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
    </div>
    ```

    ```
    // index.js
    export default {
      data: {
        images: [
          { src: '/common/frame1.png' },
          { src: '/common/frame2.png' },
          { src: '/common/frame3.png' },
        ],
      },
      handleClick() {
        const animator = this.$refs.animator; // Obtain the DOM element whose $refs attribute is animator.
        const state = animator.getState();
        if (state === 'paused') {
          animator.resume();
        } else if (state === 'stopped') {
          animator.start();
        } else {
          animator.pause();
        }
      },
    };
    ```

2.  Call  **$element**  to obtain a DOM element.

    ```
    <!-- index.hml -->
    <div class="container">
      <image-animator class="image-player" id="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
    </div>
    ```

    ```
    // index.js
    export default {
      data: {
        images: [
          { src: '/common/frame1.png' },
          { src: '/common/frame2.png' },
          { src: '/common/frame3.png' },
        ],
      },
      handleClick() {
        const animator = this.$element('animator'); // Obtain the DOM element whose ID is animator.
        const state = animator.getState();
        if (state === 'paused') {
          animator.resume();
        } else if (state === 'stopped') {
          animator.start();
        } else {
          animator.pause();
        }
      },
    };
    ```


## Obtaining the ViewModel<a name="section13798143717421"></a>

The following shows files of the root page:

```
<!-- root.hml -->
<element name='parentComp' src='../../common/component/parent/parent.hml'></element>
<div class="container">
  <div class="container">
    <text>{{text}}</text>
    <parentComp></parentComp>
  </div>
</div>
```

```
// root.js
export default {
  data: {
    text: 'I am a root!',
  },
}
```

Customize the parent component.

```
<!-- parent.hml -->
<element name='childComp' src='../child/child.hml'></element>
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="parentClicked">Click this parent component</text>
  <text class="text-style" if="{{show}}">Hello parent component!</text>
  <childComp id = "selfDefineChild"></childComp>
</div>
```

```
// parent.js
export default {
  data: {
    show: false,
    text: 'I am the parent component!',
  },
  parentClicked () {
    this.show = !this.show;
    console.info('parent component get parent text');
    console.info(`${this.$parent().text}`);
    console.info("The parent component gets the child function.");
    console.info(`${this.$child('selfDefineChild').childClicked()}`);
  },
}
```

Customize the child component.

```
<!-- child.hml -->
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="childClicked">Child component clicked</text>
  <text class="text-style" if="{{show}}">Hello child component</text>
</div>
```

```
// child.js
export default {
  data: {
    show: false,
    text: 'I am the child component!',
  },
  childClicked () {
    this.show = !this.show;
    console.info('child component get parent text');
    console.info('${this.$parent().text}');
    console.info('child component get root text');
    console.info('${this.$root().text}');
  },
}
```


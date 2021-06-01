# JavaScript<a name="EN-US_TOPIC_0000001115814808"></a>

-   [Syntax](#en-us_topic_0000001058562835_s6ca2e99746664509961f65b82d11ab58)
-   [Object](#en-us_topic_0000001058562835_s7493791622a248fbb2e03703149bb3b5)
-   [Function](#en-us_topic_0000001058562835_s4e1ff24ec78e41948502d8977d24e44c)
-   [Obtaining a DOM element](#en-us_topic_0000001058562835_section1560185062215)
-   [Obtaining the ViewModel](#en-us_topic_0000001058562835_section13798143717421)
-   [Lifecycle Functions](#en-us_topic_0000001058562835_s962b82fb67304ec9a50fb06ffa977560)

You can use a  **.js**  file to define the service logic of an HML page. The JS UI framework supports the JavaScript language that conforms to the ECMAScript specification. With dynamic typing, JavaScript can make your application more expressive with a flexible design. The following describes the JavaScript compilation and running.

## Syntax<a name="en-us_topic_0000001058562835_s6ca2e99746664509961f65b82d11ab58"></a>

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


## Object<a name="en-us_topic_0000001058562835_s7493791622a248fbb2e03703149bb3b5"></a>

-   **Application object**

    <a name="en-us_topic_0000001058562835_tc5261f21b7014f6cbe17d3ef51b9e1a9"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058562835_ae816119c3e0143c892512012c7927037"><a name="en-us_topic_0000001058562835_ae816119c3e0143c892512012c7927037"></a><a name="en-us_topic_0000001058562835_ae816119c3e0143c892512012c7927037"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"><a name="en-us_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="en-us_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"><a name="en-us_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="en-us_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_r170881741fb347fa9bc5ac3a33382a9b"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"><a name="en-us_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"></a><a name="en-us_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"></a>$def</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"><a name="en-us_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"></a><a name="en-us_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"><a name="en-us_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"></a><a name="en-us_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"></a>Object that is exposed in the <strong id="en-us_topic_0000001058562835_b1245054215141"><a name="en-us_topic_0000001058562835_b1245054215141"></a><a name="en-us_topic_0000001058562835_b1245054215141"></a>app.js</strong> file and obtained by <strong id="en-us_topic_0000001058562835_b466541113154"><a name="en-us_topic_0000001058562835_b466541113154"></a><a name="en-us_topic_0000001058562835_b466541113154"></a>this.$app.$def</strong>.</p>
    <div class="note" id="en-us_topic_0000001058562835_note23038122918"><a name="en-us_topic_0000001058562835_note23038122918"></a><a name="en-us_topic_0000001058562835_note23038122918"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058562835_p73038121790"><a name="en-us_topic_0000001058562835_p73038121790"></a><a name="en-us_topic_0000001058562835_p73038121790"></a>Application objects do not support data binding. Data update should be triggered on the UI.</p>
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
        console.info('AceApplication onCreate');
      },
      onDestroy() {
        console.info('AceApplication onDestroy');
      },
      globalData: {
        appData: 'appData',
        appVersion: '2.0',
      },
      globalMethod () {
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

    <a name="en-us_topic_0000001058562835_table8514281151"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_row2511928359"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058562835_p1951028754"><a name="en-us_topic_0000001058562835_p1951028754"></a><a name="en-us_topic_0000001058562835_p1951028754"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.71%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058562835_p1351228252"><a name="en-us_topic_0000001058562835_p1351228252"></a><a name="en-us_topic_0000001058562835_p1351228252"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.66%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058562835_p651112815519"><a name="en-us_topic_0000001058562835_p651112815519"></a><a name="en-us_topic_0000001058562835_p651112815519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_row1651228855"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p115421323762"><a name="en-us_topic_0000001058562835_p115421323762"></a><a name="en-us_topic_0000001058562835_p115421323762"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p05120283516"><a name="en-us_topic_0000001058562835_p05120283516"></a><a name="en-us_topic_0000001058562835_p05120283516"></a>Object/Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p61056578507"><a name="en-us_topic_0000001058562835_p61056578507"></a><a name="en-us_topic_0000001058562835_p61056578507"></a>Data model of the page. If the attribute is of the function type, the return value must be of the object type. The attribute name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (<strong id="en-us_topic_0000001058562835_b430716571284"><a name="en-us_topic_0000001058562835_b430716571284"></a><a name="en-us_topic_0000001058562835_b430716571284"></a>for</strong>, <strong id="en-us_topic_0000001058562835_b1341785992814"><a name="en-us_topic_0000001058562835_b1341785992814"></a><a name="en-us_topic_0000001058562835_b1341785992814"></a>if</strong>, <strong id="en-us_topic_0000001058562835_b11287152152914"><a name="en-us_topic_0000001058562835_b11287152152914"></a><a name="en-us_topic_0000001058562835_b11287152152914"></a>show</strong>, and <strong id="en-us_topic_0000001058562835_b15341857297"><a name="en-us_topic_0000001058562835_b15341857297"></a><a name="en-us_topic_0000001058562835_b15341857297"></a>tid</strong>).</p>
    <p id="en-us_topic_0000001058562835_p95116281350"><a name="en-us_topic_0000001058562835_p95116281350"></a><a name="en-us_topic_0000001058562835_p95116281350"></a>Do not use this attribute and <strong id="en-us_topic_0000001058562835_b166710411103"><a name="en-us_topic_0000001058562835_b166710411103"></a><a name="en-us_topic_0000001058562835_b166710411103"></a>private</strong> or <strong id="en-us_topic_0000001058562835_b3689175611101"><a name="en-us_topic_0000001058562835_b3689175611101"></a><a name="en-us_topic_0000001058562835_b3689175611101"></a>public</strong> at the same time.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row2991343201512"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p1873818536545"><a name="en-us_topic_0000001058562835_p1873818536545"></a><a name="en-us_topic_0000001058562835_p1873818536545"></a>$refs</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p1073815318541"><a name="en-us_topic_0000001058562835_p1073815318541"></a><a name="en-us_topic_0000001058562835_p1073815318541"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p7879941512"><a name="en-us_topic_0000001058562835_p7879941512"></a><a name="en-us_topic_0000001058562835_p7879941512"></a>DOM elements or child component instances that have registered the <strong id="en-us_topic_0000001058562835_b230018334315"><a name="en-us_topic_0000001058562835_b230018334315"></a><a name="en-us_topic_0000001058562835_b230018334315"></a>ref</strong> attribute. For example code, see <a href="#en-us_topic_0000001058562835_section1560185062215">Obtaining a DOM element</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row340610191094"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p240712191998"><a name="en-us_topic_0000001058562835_p240712191998"></a><a name="en-us_topic_0000001058562835_p240712191998"></a>private</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p1840710194916"><a name="en-us_topic_0000001058562835_p1840710194916"></a><a name="en-us_topic_0000001058562835_p1840710194916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p17407161911917"><a name="en-us_topic_0000001058562835_p17407161911917"></a><a name="en-us_topic_0000001058562835_p17407161911917"></a>Data model of the page. Private data attribute can be modified only on the current page.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row594316386514"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p99441138554"><a name="en-us_topic_0000001058562835_p99441138554"></a><a name="en-us_topic_0000001058562835_p99441138554"></a>public</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p994419381151"><a name="en-us_topic_0000001058562835_p994419381151"></a><a name="en-us_topic_0000001058562835_p994419381151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p2094418381153"><a name="en-us_topic_0000001058562835_p2094418381153"></a><a name="en-us_topic_0000001058562835_p2094418381153"></a>Data model of the page. Behaviors of public data attributes are the same as those of the <strong id="en-us_topic_0000001058562835_b17852928193814"><a name="en-us_topic_0000001058562835_b17852928193814"></a><a name="en-us_topic_0000001058562835_b17852928193814"></a>data</strong> attribute.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row638815278598"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p139903755910"><a name="en-us_topic_0000001058562835_p139903755910"></a><a name="en-us_topic_0000001058562835_p139903755910"></a>props</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p4258153555911"><a name="en-us_topic_0000001058562835_p4258153555911"></a><a name="en-us_topic_0000001058562835_p4258153555911"></a>Array/Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p12388227105918"><a name="en-us_topic_0000001058562835_p12388227105918"></a><a name="en-us_topic_0000001058562835_p12388227105918"></a>Used for communication between components. This attribute can be transferred to components via <strong id="en-us_topic_0000001058562835_b1374684104018"><a name="en-us_topic_0000001058562835_b1374684104018"></a><a name="en-us_topic_0000001058562835_b1374684104018"></a>&lt;tag xxxx='value'&gt;</strong>. A <strong id="en-us_topic_0000001058562835_b967863454012"><a name="en-us_topic_0000001058562835_b967863454012"></a><a name="en-us_topic_0000001058562835_b967863454012"></a>props</strong> name must be in lowercase and cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (<strong id="en-us_topic_0000001058562835_b36181719414"><a name="en-us_topic_0000001058562835_b36181719414"></a><a name="en-us_topic_0000001058562835_b36181719414"></a>for</strong>, <strong id="en-us_topic_0000001058562835_b18297336418"><a name="en-us_topic_0000001058562835_b18297336418"></a><a name="en-us_topic_0000001058562835_b18297336418"></a>if</strong>, <strong id="en-us_topic_0000001058562835_b350916444117"><a name="en-us_topic_0000001058562835_b350916444117"></a><a name="en-us_topic_0000001058562835_b350916444117"></a>show</strong>, and <strong id="en-us_topic_0000001058562835_b123692654113"><a name="en-us_topic_0000001058562835_b123692654113"></a><a name="en-us_topic_0000001058562835_b123692654113"></a>tid</strong>). Currently, <strong id="en-us_topic_0000001058562835_b1660371715416"><a name="en-us_topic_0000001058562835_b1660371715416"></a><a name="en-us_topic_0000001058562835_b1660371715416"></a>props</strong> does not support functions. For details, see <a href="props.md#EN-US_TOPIC_0000001162414643">Custom Components</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row14421201293417"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562835_p144221012173416"><a name="en-us_topic_0000001058562835_p144221012173416"></a><a name="en-us_topic_0000001058562835_p144221012173416"></a>computed</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562835_p164221412163412"><a name="en-us_topic_0000001058562835_p164221412163412"></a><a name="en-us_topic_0000001058562835_p164221412163412"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.66%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562835_p6422712153413"><a name="en-us_topic_0000001058562835_p6422712153413"></a><a name="en-us_topic_0000001058562835_p6422712153413"></a>Used for pre-processing an object for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words. For details, see <a href="props.md#EN-US_TOPIC_0000001162414643">Custom Components</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Function<a name="en-us_topic_0000001058562835_s4e1ff24ec78e41948502d8977d24e44c"></a>

-   **Data functions**

    <a name="en-us_topic_0000001058562835_td998a97f34c44c86876d2e1aee646bc6"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_r41906fbf818041e089ab60c9d410de72"><th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"><a name="en-us_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"></a><a name="en-us_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"><a name="en-us_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"></a><a name="en-us_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.549999999999999%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"><a name="en-us_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"></a><a name="en-us_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.449999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"><a name="en-us_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"></a><a name="en-us_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_rcba2037b58704ed9bef75b912b96eb80"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"><a name="en-us_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"></a><a name="en-us_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"></a>$set</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"><a name="en-us_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"></a><a name="en-us_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"><a name="en-us_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"></a><a name="en-us_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"></a>key: string</p>
    <p id="en-us_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"><a name="en-us_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"></a><a name="en-us_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"></a>value: any</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.449999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_p84781851442"><a name="en-us_topic_0000001058562835_p84781851442"></a><a name="en-us_topic_0000001058562835_p84781851442"></a>Adds an attribute or modifies an existing attribute.</p>
    <p id="en-us_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"><a name="en-us_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"></a><a name="en-us_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"></a>Usage:</p>
    <p id="en-us_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"><a name="en-us_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"></a><a name="en-us_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"></a><strong id="en-us_topic_0000001058562835_b102214303161"><a name="en-us_topic_0000001058562835_b102214303161"></a><a name="en-us_topic_0000001058562835_b102214303161"></a>this.$set('</strong><em id="en-us_topic_0000001058562835_i153502112176"><a name="en-us_topic_0000001058562835_i153502112176"></a><a name="en-us_topic_0000001058562835_i153502112176"></a>key</em><strong id="en-us_topic_0000001058562835_b4382163315169"><a name="en-us_topic_0000001058562835_b4382163315169"></a><a name="en-us_topic_0000001058562835_b4382163315169"></a>',</strong><em id="en-us_topic_0000001058562835_i1278985981612"><a name="en-us_topic_0000001058562835_i1278985981612"></a><a name="en-us_topic_0000001058562835_i1278985981612"></a>value</em><strong id="en-us_topic_0000001058562835_b14689536171618"><a name="en-us_topic_0000001058562835_b14689536171618"></a><a name="en-us_topic_0000001058562835_b14689536171618"></a>)</strong>: Add an attribute.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_r189d027189d842a1baf1a5d91a9af901"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"><a name="en-us_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"></a><a name="en-us_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"></a>$delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"><a name="en-us_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"></a><a name="en-us_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"><a name="en-us_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a><a name="en-us_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a>key: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.449999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_p18897453134313"><a name="en-us_topic_0000001058562835_p18897453134313"></a><a name="en-us_topic_0000001058562835_p18897453134313"></a>Deletes an attribute.</p>
    <p id="en-us_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"><a name="en-us_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a><a name="en-us_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a>Usage:</p>
    <p id="en-us_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"><a name="en-us_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"></a><a name="en-us_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"></a><strong id="en-us_topic_0000001058562835_b14701107171715"><a name="en-us_topic_0000001058562835_b14701107171715"></a><a name="en-us_topic_0000001058562835_b14701107171715"></a>this.$delete('</strong><em id="en-us_topic_0000001058562835_i2460141971715"><a name="en-us_topic_0000001058562835_i2460141971715"></a><a name="en-us_topic_0000001058562835_i2460141971715"></a>key</em><strong id="en-us_topic_0000001058562835_b121011116141712"><a name="en-us_topic_0000001058562835_b121011116141712"></a><a name="en-us_topic_0000001058562835_b121011116141712"></a>')</strong>: Delete an attribute.</p>
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

    <a name="en-us_topic_0000001058562835_te12ef71dd85347738d3670aaa9934476"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_r7c071c236183461dbd8e78bce0073401"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"><a name="en-us_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"></a><a name="en-us_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"><a name="en-us_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"></a><a name="en-us_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"><a name="en-us_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"></a><a name="en-us_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="67%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"><a name="en-us_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"></a><a name="en-us_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_r786add9633394d2f8d72020f28465c87"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"><a name="en-us_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"></a><a name="en-us_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"></a>$element</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"><a name="en-us_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"></a><a name="en-us_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"><a name="en-us_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"></a><a name="en-us_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"></a>id: string <em id="en-us_topic_0000001058562835_i9271132133818"><a name="en-us_topic_0000001058562835_i9271132133818"></a><a name="en-us_topic_0000001058562835_i9271132133818"></a>Component ID</em></p>
    </td>
    <td class="cellrowborder" valign="top" width="67%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_p103681425164412"><a name="en-us_topic_0000001058562835_p103681425164412"></a><a name="en-us_topic_0000001058562835_p103681425164412"></a>Obtains the component with a specified ID. If no ID is specified, the root component is returned. For example code, see <a href="#en-us_topic_0000001058562835_section1560185062215">Obtaining a DOM element</a>.</p>
    <p id="en-us_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"><a name="en-us_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"></a><a name="en-us_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"></a>Usage:</p>
    <p id="en-us_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"><a name="en-us_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"></a><a name="en-us_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"></a><strong id="en-us_topic_0000001058562835_b1778371312186"><a name="en-us_topic_0000001058562835_b1778371312186"></a><a name="en-us_topic_0000001058562835_b1778371312186"></a>&lt;div id='</strong><em id="en-us_topic_0000001058562835_i9616171712187"><a name="en-us_topic_0000001058562835_i9616171712187"></a><a name="en-us_topic_0000001058562835_i9616171712187"></a>xxx</em><strong id="en-us_topic_0000001058562835_b18768154181"><a name="en-us_topic_0000001058562835_b18768154181"></a><a name="en-us_topic_0000001058562835_b18768154181"></a>'&gt;&lt;/div&gt;</strong></p>
    <a name="en-us_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"></a><a name="en-us_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"></a><ul id="en-us_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"><li><strong id="en-us_topic_0000001058562835_b05751419837"><a name="en-us_topic_0000001058562835_b05751419837"></a><a name="en-us_topic_0000001058562835_b05751419837"></a>this.$element('</strong><em id="en-us_topic_0000001058562835_i189720245314"><a name="en-us_topic_0000001058562835_i189720245314"></a><a name="en-us_topic_0000001058562835_i189720245314"></a>xxx</em><strong id="en-us_topic_0000001058562835_b2658122119319"><a name="en-us_topic_0000001058562835_b2658122119319"></a><a name="en-us_topic_0000001058562835_b2658122119319"></a>')</strong>: Obtain the component whose ID is <em id="en-us_topic_0000001058562835_i195201110185318"><a name="en-us_topic_0000001058562835_i195201110185318"></a><a name="en-us_topic_0000001058562835_i195201110185318"></a>xxx</em>.</li><li><strong id="en-us_topic_0000001058562835_b1029113281236"><a name="en-us_topic_0000001058562835_b1029113281236"></a><a name="en-us_topic_0000001058562835_b1029113281236"></a>this.$element()</strong>: Obtain the root component.</li></ul>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_re1d5191790fb423282a8c381b317e0e6"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"><a name="en-us_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"></a><a name="en-us_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"></a>$root</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"><a name="en-us_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"></a><a name="en-us_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"><a name="en-us_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"></a><a name="en-us_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"></a>N/A</p>
    </td>
    <td class="cellrowborder" valign="top" width="67%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"><a name="en-us_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"></a><a name="en-us_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"></a>Obtains the root <strong id="en-us_topic_0000001058562835_b4935191919418"><a name="en-us_topic_0000001058562835_b4935191919418"></a><a name="en-us_topic_0000001058562835_b4935191919418"></a>ViewModel</strong> instance. For example code, see <a href="#en-us_topic_0000001058562835_section13798143717421">Obtaining the ViewModel</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_rd577efbcfc104ac2b5bed88fc9dd0cfb"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"><a name="en-us_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"></a><a name="en-us_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"></a>$parent</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"><a name="en-us_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"></a><a name="en-us_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"><a name="en-us_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"></a><a name="en-us_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"></a>N/A</p>
    </td>
    <td class="cellrowborder" valign="top" width="67%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"><a name="en-us_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"></a><a name="en-us_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"></a>Obtains the parent <strong id="en-us_topic_0000001058562835_b11983132316413"><a name="en-us_topic_0000001058562835_b11983132316413"></a><a name="en-us_topic_0000001058562835_b11983132316413"></a>ViewModel</strong> instance. For example code, see <a href="#en-us_topic_0000001058562835_section13798143717421">Obtaining the ViewModel</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_rb96318b2fb9e4e8ea74dfb280e8fb804"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"><a name="en-us_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"></a><a name="en-us_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"></a>$child</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"><a name="en-us_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"></a><a name="en-us_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"><a name="en-us_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"></a><a name="en-us_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"></a>id: string <em id="en-us_topic_0000001058562835_i14953120124516"><a name="en-us_topic_0000001058562835_i14953120124516"></a><a name="en-us_topic_0000001058562835_i14953120124516"></a>Component ID</em></p>
    </td>
    <td class="cellrowborder" valign="top" width="67%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_p999210407446"><a name="en-us_topic_0000001058562835_p999210407446"></a><a name="en-us_topic_0000001058562835_p999210407446"></a>Obtains the <strong id="en-us_topic_0000001058562835_b39768121254"><a name="en-us_topic_0000001058562835_b39768121254"></a><a name="en-us_topic_0000001058562835_b39768121254"></a>ViewModel</strong> instance of a custom child component with a specified ID. For example code, see <a href="#en-us_topic_0000001058562835_section13798143717421">Obtaining the ViewModel</a>.</p>
    <p id="en-us_topic_0000001058562835_p112537114516"><a name="en-us_topic_0000001058562835_p112537114516"></a><a name="en-us_topic_0000001058562835_p112537114516"></a>Usage:</p>
    <p id="en-us_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"><a name="en-us_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"></a><a name="en-us_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"></a><strong id="en-us_topic_0000001058562835_b1130414126616"><a name="en-us_topic_0000001058562835_b1130414126616"></a><a name="en-us_topic_0000001058562835_b1130414126616"></a>this.$child('</strong><em id="en-us_topic_0000001058562835_i19634170616"><a name="en-us_topic_0000001058562835_i19634170616"></a><a name="en-us_topic_0000001058562835_i19634170616"></a>xxx</em><strong id="en-us_topic_0000001058562835_b64849141767"><a name="en-us_topic_0000001058562835_b64849141767"></a><a name="en-us_topic_0000001058562835_b64849141767"></a>')</strong>: Obtain the <strong id="en-us_topic_0000001058562835_b378518252611"><a name="en-us_topic_0000001058562835_b378518252611"></a><a name="en-us_topic_0000001058562835_b378518252611"></a>ViewModel</strong> instance of a custom child component whose ID is <em id="en-us_topic_0000001058562835_i1521313124719"><a name="en-us_topic_0000001058562835_i1521313124719"></a><a name="en-us_topic_0000001058562835_i1521313124719"></a>xxx</em>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   **Event function**

    <a name="en-us_topic_0000001058562835_table106771249184219"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_row66781249104214"><th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562835_p15678249144218"><a name="en-us_topic_0000001058562835_p15678249144218"></a><a name="en-us_topic_0000001058562835_p15678249144218"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562835_p2678194911424"><a name="en-us_topic_0000001058562835_p2678194911424"></a><a name="en-us_topic_0000001058562835_p2678194911424"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.52%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562835_p17678049114213"><a name="en-us_topic_0000001058562835_p17678049114213"></a><a name="en-us_topic_0000001058562835_p17678049114213"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.480000000000004%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562835_p26786495424"><a name="en-us_topic_0000001058562835_p26786495424"></a><a name="en-us_topic_0000001058562835_p26786495424"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_row267864944212"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562835_p067834919421"><a name="en-us_topic_0000001058562835_p067834919421"></a><a name="en-us_topic_0000001058562835_p067834919421"></a>$watch</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562835_p1967834911420"><a name="en-us_topic_0000001058562835_p1967834911420"></a><a name="en-us_topic_0000001058562835_p1967834911420"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.52%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562835_p11678194920424"><a name="en-us_topic_0000001058562835_p11678194920424"></a><a name="en-us_topic_0000001058562835_p11678194920424"></a>data: string</p>
    <p id="en-us_topic_0000001058562835_p27811112011"><a name="en-us_topic_0000001058562835_p27811112011"></a><a name="en-us_topic_0000001058562835_p27811112011"></a>callback: function name. The callback has two parameters. The first one is the new attribute value, and the second is the original value.</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562835_p1678104913426"><a name="en-us_topic_0000001058562835_p1678104913426"></a><a name="en-us_topic_0000001058562835_p1678104913426"></a>Listens for attribute changes. If the value of the <strong id="en-us_topic_0000001058562835_b102761759204314"><a name="en-us_topic_0000001058562835_b102761759204314"></a><a name="en-us_topic_0000001058562835_b102761759204314"></a>data</strong> attribute changes, the bound event is triggered. For details, see <a href="props.md#EN-US_TOPIC_0000001162414643">Custom Components</a>.</p>
    <p id="en-us_topic_0000001058562835_p174621629124617"><a name="en-us_topic_0000001058562835_p174621629124617"></a><a name="en-us_topic_0000001058562835_p174621629124617"></a>Usage:</p>
    <p id="en-us_topic_0000001058562835_p1173814312460"><a name="en-us_topic_0000001058562835_p1173814312460"></a><a name="en-us_topic_0000001058562835_p1173814312460"></a><strong id="en-us_topic_0000001058562835_b26791338201017"><a name="en-us_topic_0000001058562835_b26791338201017"></a><a name="en-us_topic_0000001058562835_b26791338201017"></a>this.$watch('</strong><em id="en-us_topic_0000001058562835_i1751741018116"><a name="en-us_topic_0000001058562835_i1751741018116"></a><a name="en-us_topic_0000001058562835_i1751741018116"></a>key</em><strong id="en-us_topic_0000001058562835_b111878516117"><a name="en-us_topic_0000001058562835_b111878516117"></a><a name="en-us_topic_0000001058562835_b111878516117"></a>',</strong> <em id="en-us_topic_0000001058562835_i38794851120"><a name="en-us_topic_0000001058562835_i38794851120"></a><a name="en-us_topic_0000001058562835_i38794851120"></a>callback</em><strong id="en-us_topic_0000001058562835_b13989360116"><a name="en-us_topic_0000001058562835_b13989360116"></a><a name="en-us_topic_0000001058562835_b13989360116"></a>)</strong></p>
    </td>
    </tr>
    </tbody>
    </table>


## Obtaining a DOM element<a name="en-us_topic_0000001058562835_section1560185062215"></a>

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


## Obtaining the ViewModel<a name="en-us_topic_0000001058562835_section13798143717421"></a>

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

## Lifecycle Functions<a name="en-us_topic_0000001058562835_s962b82fb67304ec9a50fb06ffa977560"></a>

-   **Page lifecycle**

    <a name="en-us_topic_0000001058562835_t7208da80646145cb86b25df20f52a5d4"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_r4bc39237158f4199b86d18d0784b005d"><th class="cellrowborder" valign="top" width="18.029999999999998%" id="mcps1.1.7.1.1"><p id="en-us_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"><a name="en-us_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"></a><a name="en-us_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.97%" id="mcps1.1.7.1.2"><p id="en-us_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"><a name="en-us_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"></a><a name="en-us_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.7.1.3"><p id="en-us_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"><a name="en-us_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"></a><a name="en-us_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.7.1.4"><p id="en-us_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"><a name="en-us_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"></a><a name="en-us_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"></a>Return Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.7.1.5"><p id="en-us_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"><a name="en-us_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"></a><a name="en-us_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="35%" id="mcps1.1.7.1.6"><p id="en-us_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"><a name="en-us_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"></a><a name="en-us_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"></a>Called When</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_rb52da1ffb529417c9f0290d1f122a87e"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"><a name="en-us_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"></a><a name="en-us_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"></a>onInit</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"><a name="en-us_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"></a><a name="en-us_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"><a name="en-us_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"></a><a name="en-us_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"><a name="en-us_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"></a><a name="en-us_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"><a name="en-us_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"></a><a name="en-us_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"></a>Listens for page initialization.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"><a name="en-us_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"></a><a name="en-us_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"></a>Page initialization is complete. This function is called only once in a lifecycle.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_r57dd28dbf8a243cdad002d8599eda15f"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"><a name="en-us_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"></a><a name="en-us_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"></a>onReady</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"><a name="en-us_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"></a><a name="en-us_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"><a name="en-us_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"></a><a name="en-us_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"><a name="en-us_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"></a><a name="en-us_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"><a name="en-us_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"></a><a name="en-us_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"></a>Listens for page creation.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"><a name="en-us_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"></a><a name="en-us_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"></a>A page is created. This function is called only once in a lifecycle.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_r1dd8a5bfd50043eeb2fff708e728a9fa"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"><a name="en-us_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"></a><a name="en-us_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"></a>onShow</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"><a name="en-us_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"></a><a name="en-us_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"><a name="en-us_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"></a><a name="en-us_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"><a name="en-us_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"></a><a name="en-us_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"><a name="en-us_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"></a><a name="en-us_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"></a>Listens for page display.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"><a name="en-us_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"></a><a name="en-us_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"></a>The page is displayed.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_r4247056b80864bb7ab5678341dc8c29a"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"><a name="en-us_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"></a><a name="en-us_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"></a>onHide</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"><a name="en-us_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"></a><a name="en-us_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"><a name="en-us_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"></a><a name="en-us_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"><a name="en-us_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"></a><a name="en-us_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"><a name="en-us_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"></a><a name="en-us_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"></a>Listens for page disappearance.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"><a name="en-us_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"></a><a name="en-us_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"></a>The page disappears.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_ra205abdcebf94a5583cdbd422211dd4b"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"><a name="en-us_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"></a><a name="en-us_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"></a>onDestroy</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"><a name="en-us_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"></a><a name="en-us_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"><a name="en-us_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"></a><a name="en-us_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"><a name="en-us_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"></a><a name="en-us_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"><a name="en-us_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"></a><a name="en-us_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"></a>Listens for page destruction.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"><a name="en-us_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"></a><a name="en-us_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"></a>The page is destroyed.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_r8c29065ea9334b37bd69e3d967d00eb2"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"><a name="en-us_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"></a><a name="en-us_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"></a>onBackPress</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"><a name="en-us_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"></a><a name="en-us_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"><a name="en-us_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"></a><a name="en-us_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"><a name="en-us_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"></a><a name="en-us_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"></a>Boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"><a name="en-us_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"></a><a name="en-us_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"></a>Listens for the back button action.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"><a name="en-us_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"></a><a name="en-us_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"></a>The back button is tapped.</p>
    <a name="en-us_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"></a><a name="en-us_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"></a><ul id="en-us_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"><li><strong id="en-us_topic_0000001058562835_b1099882274318"><a name="en-us_topic_0000001058562835_b1099882274318"></a><a name="en-us_topic_0000001058562835_b1099882274318"></a>true</strong> means that the page processes the return logic.</li><li><strong id="en-us_topic_0000001058562835_b24732354439"><a name="en-us_topic_0000001058562835_b24732354439"></a><a name="en-us_topic_0000001058562835_b24732354439"></a>false</strong> means that the default return logic is used.</li><li>If no value is returned, the default return logic is used.</li></ul>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row73484412715"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_p9479151716"><a name="en-us_topic_0000001058562835_p9479151716"></a><a name="en-us_topic_0000001058562835_p9479151716"></a>onActive()<sup id="en-us_topic_0000001058562835_sup2479151478"><a name="en-us_topic_0000001058562835_sup2479151478"></a><a name="en-us_topic_0000001058562835_sup2479151478"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_p44795511715"><a name="en-us_topic_0000001058562835_p44795511715"></a><a name="en-us_topic_0000001058562835_p44795511715"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_p1479652717"><a name="en-us_topic_0000001058562835_p1479652717"></a><a name="en-us_topic_0000001058562835_p1479652717"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_p14479451712"><a name="en-us_topic_0000001058562835_p14479451712"></a><a name="en-us_topic_0000001058562835_p14479451712"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_p17479551871"><a name="en-us_topic_0000001058562835_p17479551871"></a><a name="en-us_topic_0000001058562835_p17479551871"></a>Listens for age activation.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_p124801651476"><a name="en-us_topic_0000001058562835_p124801651476"></a><a name="en-us_topic_0000001058562835_p124801651476"></a>The page is activated.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row87561847563"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_p575744115618"><a name="en-us_topic_0000001058562835_p575744115618"></a><a name="en-us_topic_0000001058562835_p575744115618"></a>onInactive()<sup id="en-us_topic_0000001058562835_sup1689453314352"><a name="en-us_topic_0000001058562835_sup1689453314352"></a><a name="en-us_topic_0000001058562835_sup1689453314352"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_p77571843566"><a name="en-us_topic_0000001058562835_p77571843566"></a><a name="en-us_topic_0000001058562835_p77571843566"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_p177571745568"><a name="en-us_topic_0000001058562835_p177571745568"></a><a name="en-us_topic_0000001058562835_p177571745568"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_p1775734125612"><a name="en-us_topic_0000001058562835_p1775734125612"></a><a name="en-us_topic_0000001058562835_p1775734125612"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_p137575475615"><a name="en-us_topic_0000001058562835_p137575475615"></a><a name="en-us_topic_0000001058562835_p137575475615"></a>Listens for page suspension.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_p197577417562"><a name="en-us_topic_0000001058562835_p197577417562"></a><a name="en-us_topic_0000001058562835_p197577417562"></a>The page is suspended.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_row33231032142114"><td class="cellrowborder" valign="top" width="18.029999999999998%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_p18323163215216"><a name="en-us_topic_0000001058562835_p18323163215216"></a><a name="en-us_topic_0000001058562835_p18323163215216"></a>onNewRequest()<sup id="en-us_topic_0000001058562835_sup13778137173514"><a name="en-us_topic_0000001058562835_sup13778137173514"></a><a name="en-us_topic_0000001058562835_sup13778137173514"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.97%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_p12323143202115"><a name="en-us_topic_0000001058562835_p12323143202115"></a><a name="en-us_topic_0000001058562835_p12323143202115"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_p103231732192111"><a name="en-us_topic_0000001058562835_p103231732192111"></a><a name="en-us_topic_0000001058562835_p103231732192111"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_p832353215215"><a name="en-us_topic_0000001058562835_p832353215215"></a><a name="en-us_topic_0000001058562835_p832353215215"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_p10324123232120"><a name="en-us_topic_0000001058562835_p10324123232120"></a><a name="en-us_topic_0000001058562835_p10324123232120"></a>Listens for a new FA request.</p>
    </td>
    <td class="cellrowborder" valign="top" width="35%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_p2324432152120"><a name="en-us_topic_0000001058562835_p2324432152120"></a><a name="en-us_topic_0000001058562835_p2324432152120"></a>The FA has been started and a new request is received.</p>
    </td>
    </tr>
    </tbody>
    </table>

    The lifecycle functions of page A are called in the following sequence:

    -   Open page A: onInit\(\) -\> onReady\(\) -\> onShow\(\) -\> onActive\(\)
    -   Open page B on page A: onInactive\(\) -\> onHide\(\)
    -   Go back to page A from page B: onShow\(\) -\> onActive\(\)
    -   Exit page A: onBackPress\(\) -\> onInactive\(\) -\> onHide\(\) -\> onDestroy\(\)
    -   Hide page A: onInactive\(\) -\> onHide\(\)
    -   Show background page A on the foreground: onShow\(\)

-   **Application lifecycle**

    <a name="en-us_topic_0000001058562835_tca9d892b58db4855a2c0dced267fd7f0"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562835_r400fd9d50fba4a3ea8c141401ddee795"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.7.1.1"><p id="en-us_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"><a name="en-us_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"></a><a name="en-us_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.1.7.1.2"><p id="en-us_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"><a name="en-us_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"></a><a name="en-us_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.1.7.1.3"><p id="en-us_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"><a name="en-us_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"></a><a name="en-us_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.891089108910892%" id="mcps1.1.7.1.4"><p id="en-us_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"><a name="en-us_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"></a><a name="en-us_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"></a>Return Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.7.1.5"><p id="en-us_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"><a name="en-us_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"></a><a name="en-us_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.7.1.6"><p id="en-us_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"><a name="en-us_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"></a><a name="en-us_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"></a>Called When</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562835_r447ec21f8d584378ab37e935ce6aaeac"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"><a name="en-us_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"></a><a name="en-us_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"></a>onCreate</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"><a name="en-us_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"></a><a name="en-us_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"><a name="en-us_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"></a><a name="en-us_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.891089108910892%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"><a name="en-us_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"></a><a name="en-us_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"><a name="en-us_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"></a><a name="en-us_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"></a>Listens for application creation.</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"><a name="en-us_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"></a><a name="en-us_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"></a>The application is created.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562835_rd1427aa6bfba4386b3c82e875f93c78d"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.1 "><p id="en-us_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"><a name="en-us_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"></a><a name="en-us_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"></a>onDestroy</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.2 "><p id="en-us_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"><a name="en-us_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"></a><a name="en-us_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.3 "><p id="en-us_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"><a name="en-us_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"></a><a name="en-us_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.891089108910892%" headers="mcps1.1.7.1.4 "><p id="en-us_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"><a name="en-us_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"></a><a name="en-us_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.5 "><p id="en-us_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"><a name="en-us_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"></a><a name="en-us_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"></a>Listens for application exit.</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.7.1.6 "><p id="en-us_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"><a name="en-us_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"></a><a name="en-us_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"></a>The application exits.</p>
    </td>
    </tr>
    </tbody>
    </table>



# JS语法参考<a name="ZH-CN_TOPIC_0000001209412117"></a>

-   [语法](#zh-cn_topic_0000001173164729_s6ca2e99746664509961f65b82d11ab58)
-   [对象](#zh-cn_topic_0000001173164729_s7493791622a248fbb2e03703149bb3b5)
-   [方法](#zh-cn_topic_0000001173164729_s4e1ff24ec78e41948502d8977d24e44c)
-   [获取DOM元素](#zh-cn_topic_0000001173164729_section1560185062215)
-   [获取ViewModel](#zh-cn_topic_0000001173164729_section13798143717421)

JS文件用来定义HML页面的业务逻辑，支持ECMA规范的JavaScript语言。基于JavaScript语言的动态化能力，可以使应用更加富有表现力，具备更加灵活的设计能力。下面讲述JS文件的编译和运行的支持情况。

## 语法<a name="zh-cn_topic_0000001173164729_s6ca2e99746664509961f65b82d11ab58"></a>

支持ES6语法。

-   模块声明

    使用import方法引入功能模块：

    ```
    import router from '@system.router';
    ```

-   代码引用

    使用import方法导入js代码：

    ```
    import utils from '../../common/utils.js';
    ```


## 对象<a name="zh-cn_topic_0000001173164729_s7493791622a248fbb2e03703149bb3b5"></a>

-   应用对象

    <a name="zh-cn_topic_0000001173164729_tc5261f21b7014f6cbe17d3ef51b9e1a9"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_ae816119c3e0143c892512012c7927037"><a name="zh-cn_topic_0000001173164729_ae816119c3e0143c892512012c7927037"></a><a name="zh-cn_topic_0000001173164729_ae816119c3e0143c892512012c7927037"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_ab72e901bb3ef4657b303513b8fa5ec1f"><a name="zh-cn_topic_0000001173164729_ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="zh-cn_topic_0000001173164729_ab72e901bb3ef4657b303513b8fa5ec1f"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_ae95f3df496fc41939ac6c1cf74aef9d8"><a name="zh-cn_topic_0000001173164729_ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="zh-cn_topic_0000001173164729_ae95f3df496fc41939ac6c1cf74aef9d8"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_r170881741fb347fa9bc5ac3a33382a9b"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a9a70780b9fd8468d98a7c107ee67d8d8"><a name="zh-cn_topic_0000001173164729_a9a70780b9fd8468d98a7c107ee67d8d8"></a><a name="zh-cn_topic_0000001173164729_a9a70780b9fd8468d98a7c107ee67d8d8"></a>$def</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_ace202d9f2dd547c8ab8693954af5d616"><a name="zh-cn_topic_0000001173164729_ace202d9f2dd547c8ab8693954af5d616"></a><a name="zh-cn_topic_0000001173164729_ace202d9f2dd547c8ab8693954af5d616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_a08a4d55b01864b2fa866f6431cd322de"><a name="zh-cn_topic_0000001173164729_a08a4d55b01864b2fa866f6431cd322de"></a><a name="zh-cn_topic_0000001173164729_a08a4d55b01864b2fa866f6431cd322de"></a>使用this.$app.$def获取在app.js中暴露的对象。</p>
    <div class="note" id="zh-cn_topic_0000001173164729_note23038122918"><a name="zh-cn_topic_0000001173164729_note23038122918"></a><a name="zh-cn_topic_0000001173164729_note23038122918"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173164729_p73038121790"><a name="zh-cn_topic_0000001173164729_p73038121790"></a><a name="zh-cn_topic_0000001173164729_p73038121790"></a>应用对象不支持数据绑定，需主动触发UI更新。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

    示例代码

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
      globalMethod() {
        console.info('This is a global method!');
        this.globalData.appVersion = '3.0';
      }
    };
    ```

    ```
    // index.js页面逻辑代码
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

-   页面对象

    <a name="zh-cn_topic_0000001173164729_table8514281151"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_row2511928359"><th class="cellrowborder" valign="top" width="16.36%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_p1951028754"><a name="zh-cn_topic_0000001173164729_p1951028754"></a><a name="zh-cn_topic_0000001173164729_p1951028754"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.54%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_p1351228252"><a name="zh-cn_topic_0000001173164729_p1351228252"></a><a name="zh-cn_topic_0000001173164729_p1351228252"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.10000000000001%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_p651112815519"><a name="zh-cn_topic_0000001173164729_p651112815519"></a><a name="zh-cn_topic_0000001173164729_p651112815519"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_row1651228855"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p115421323762"><a name="zh-cn_topic_0000001173164729_p115421323762"></a><a name="zh-cn_topic_0000001173164729_p115421323762"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p05120283516"><a name="zh-cn_topic_0000001173164729_p05120283516"></a><a name="zh-cn_topic_0000001173164729_p05120283516"></a>Object/Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p61056578507"><a name="zh-cn_topic_0000001173164729_p61056578507"></a><a name="zh-cn_topic_0000001173164729_p61056578507"></a>页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for, if, show, tid。</p>
    <p id="zh-cn_topic_0000001173164729_p95116281350"><a name="zh-cn_topic_0000001173164729_p95116281350"></a><a name="zh-cn_topic_0000001173164729_p95116281350"></a>data与private和public不能重合使用。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row2991343201512"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p1873818536545"><a name="zh-cn_topic_0000001173164729_p1873818536545"></a><a name="zh-cn_topic_0000001173164729_p1873818536545"></a>$refs</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p1073815318541"><a name="zh-cn_topic_0000001173164729_p1073815318541"></a><a name="zh-cn_topic_0000001173164729_p1073815318541"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p7879941512"><a name="zh-cn_topic_0000001173164729_p7879941512"></a><a name="zh-cn_topic_0000001173164729_p7879941512"></a>持有注册过ref 属性的DOM元素或子组件实例的对象。示例见<a href="#zh-cn_topic_0000001173164729_section1560185062215">获取DOM元素</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row340610191094"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p240712191998"><a name="zh-cn_topic_0000001173164729_p240712191998"></a><a name="zh-cn_topic_0000001173164729_p240712191998"></a>private</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p1840710194916"><a name="zh-cn_topic_0000001173164729_p1840710194916"></a><a name="zh-cn_topic_0000001173164729_p1840710194916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p17407161911917"><a name="zh-cn_topic_0000001173164729_p17407161911917"></a><a name="zh-cn_topic_0000001173164729_p17407161911917"></a>页面的数据模型，private下的数据属性只能由当前页面修改。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row594316386514"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p99441138554"><a name="zh-cn_topic_0000001173164729_p99441138554"></a><a name="zh-cn_topic_0000001173164729_p99441138554"></a>public</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p994419381151"><a name="zh-cn_topic_0000001173164729_p994419381151"></a><a name="zh-cn_topic_0000001173164729_p994419381151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p2094418381153"><a name="zh-cn_topic_0000001173164729_p2094418381153"></a><a name="zh-cn_topic_0000001173164729_p2094418381153"></a>页面的数据模型，public下的数据属性的行为与data保持一致。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row638815278598"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p139903755910"><a name="zh-cn_topic_0000001173164729_p139903755910"></a><a name="zh-cn_topic_0000001173164729_p139903755910"></a>props</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p4258153555911"><a name="zh-cn_topic_0000001173164729_p4258153555911"></a><a name="zh-cn_topic_0000001173164729_p4258153555911"></a>Array/Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p12388227105918"><a name="zh-cn_topic_0000001173164729_p12388227105918"></a><a name="zh-cn_topic_0000001173164729_p12388227105918"></a>props用于组件之间的通信，可以通过&lt;tag xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for, if, show, tid。目前props的数据类型不支持Function。示例见<a href="component/js-components-custom-props.md#ZH-CN_TOPIC_0000001209252183">自定义组件</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row14421201293417"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p144221012173416"><a name="zh-cn_topic_0000001173164729_p144221012173416"></a><a name="zh-cn_topic_0000001173164729_p144221012173416"></a>computed</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p164221412163412"><a name="zh-cn_topic_0000001173164729_p164221412163412"></a><a name="zh-cn_topic_0000001173164729_p164221412163412"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p6422712153413"><a name="zh-cn_topic_0000001173164729_p6422712153413"></a><a name="zh-cn_topic_0000001173164729_p6422712153413"></a>用于在读取或设置进行预先处理，计算属性的结果会被缓存。计算属性名不能以$或_开头，不要使用保留字。示例见<a href="component/js-components-custom-props.md#ZH-CN_TOPIC_0000001209252183">自定义组件</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="zh-cn_topic_0000001173164729_s4e1ff24ec78e41948502d8977d24e44c"></a>

-   数据方法

    <a name="zh-cn_topic_0000001173164729_td998a97f34c44c86876d2e1aee646bc6"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_r41906fbf818041e089ab60c9d410de72"><th class="cellrowborder" valign="top" width="11.361136113611362%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_a44385457c0224b7aa0af4b8aaa5fec41"><a name="zh-cn_topic_0000001173164729_a44385457c0224b7aa0af4b8aaa5fec41"></a><a name="zh-cn_topic_0000001173164729_a44385457c0224b7aa0af4b8aaa5fec41"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.53165316531653%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_a21e0645662414f9893af7ff3a6e24e92"><a name="zh-cn_topic_0000001173164729_a21e0645662414f9893af7ff3a6e24e92"></a><a name="zh-cn_topic_0000001173164729_a21e0645662414f9893af7ff3a6e24e92"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.10721072107211%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_add5a5e57df3a4d47a09a8f3ef2a28088"><a name="zh-cn_topic_0000001173164729_add5a5e57df3a4d47a09a8f3ef2a28088"></a><a name="zh-cn_topic_0000001173164729_add5a5e57df3a4d47a09a8f3ef2a28088"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_rcba2037b58704ed9bef75b912b96eb80"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a75bccc07529343469aad71db98e70b1a"><a name="zh-cn_topic_0000001173164729_a75bccc07529343469aad71db98e70b1a"></a><a name="zh-cn_topic_0000001173164729_a75bccc07529343469aad71db98e70b1a"></a>$set</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_a53419b7e4fde4993b3ab35ad3312c4da"><a name="zh-cn_topic_0000001173164729_a53419b7e4fde4993b3ab35ad3312c4da"></a><a name="zh-cn_topic_0000001173164729_a53419b7e4fde4993b3ab35ad3312c4da"></a>key: string, value: any</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p84781851442"><a name="zh-cn_topic_0000001173164729_p84781851442"></a><a name="zh-cn_topic_0000001173164729_p84781851442"></a>添加新的数据属性或者修改已有数据属性。</p>
    <p id="zh-cn_topic_0000001173164729_ae55e2b1d9401454c8555cbb419068829"><a name="zh-cn_topic_0000001173164729_ae55e2b1d9401454c8555cbb419068829"></a><a name="zh-cn_topic_0000001173164729_ae55e2b1d9401454c8555cbb419068829"></a>用法：</p>
    <p id="zh-cn_topic_0000001173164729_a266dfd3b1b384811b4e7d9a39350e3bc"><a name="zh-cn_topic_0000001173164729_a266dfd3b1b384811b4e7d9a39350e3bc"></a><a name="zh-cn_topic_0000001173164729_a266dfd3b1b384811b4e7d9a39350e3bc"></a>this.$set('key',value)：添加数据属性。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_r189d027189d842a1baf1a5d91a9af901"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a4ee9a900fc454f66a628f210f2e50548"><a name="zh-cn_topic_0000001173164729_a4ee9a900fc454f66a628f210f2e50548"></a><a name="zh-cn_topic_0000001173164729_a4ee9a900fc454f66a628f210f2e50548"></a>$delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_a2e9d28b0f19d4cabbcc1b464bbd9993a"><a name="zh-cn_topic_0000001173164729_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a><a name="zh-cn_topic_0000001173164729_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a>key: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p18897453134313"><a name="zh-cn_topic_0000001173164729_p18897453134313"></a><a name="zh-cn_topic_0000001173164729_p18897453134313"></a>删除数据属性。</p>
    <p id="zh-cn_topic_0000001173164729_a1e9c2271da5e4cd89dcd6b73c1b3b69d"><a name="zh-cn_topic_0000001173164729_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a><a name="zh-cn_topic_0000001173164729_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a>用法：</p>
    <p id="zh-cn_topic_0000001173164729_a628cc2f32b9247b091f5d37ab0a58fdb"><a name="zh-cn_topic_0000001173164729_a628cc2f32b9247b091f5d37ab0a58fdb"></a><a name="zh-cn_topic_0000001173164729_a628cc2f32b9247b091f5d37ab0a58fdb"></a>this.$delete('key')：删除数据属性。</p>
    </td>
    </tr>
    </tbody>
    </table>

    示例代码

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

-   公共方法

    <a name="zh-cn_topic_0000001173164729_te12ef71dd85347738d3670aaa9934476"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_r7c071c236183461dbd8e78bce0073401"><th class="cellrowborder" valign="top" width="13.469999999999999%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_a4abb4994ac12403f88c36b8b34a739ec"><a name="zh-cn_topic_0000001173164729_a4abb4994ac12403f88c36b8b34a739ec"></a><a name="zh-cn_topic_0000001173164729_a4abb4994ac12403f88c36b8b34a739ec"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_aeac2f3bdee564731ace449ab67008c2c"><a name="zh-cn_topic_0000001173164729_aeac2f3bdee564731ace449ab67008c2c"></a><a name="zh-cn_topic_0000001173164729_aeac2f3bdee564731ace449ab67008c2c"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.62%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_af669c9f192954747ba61f011dcb6b1c7"><a name="zh-cn_topic_0000001173164729_af669c9f192954747ba61f011dcb6b1c7"></a><a name="zh-cn_topic_0000001173164729_af669c9f192954747ba61f011dcb6b1c7"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_r786add9633394d2f8d72020f28465c87"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a6cce84705d514809ac0511d69f5605e1"><a name="zh-cn_topic_0000001173164729_a6cce84705d514809ac0511d69f5605e1"></a><a name="zh-cn_topic_0000001173164729_a6cce84705d514809ac0511d69f5605e1"></a>$element</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_ad13b3f17bec14af0859875ac75376e14"><a name="zh-cn_topic_0000001173164729_ad13b3f17bec14af0859875ac75376e14"></a><a name="zh-cn_topic_0000001173164729_ad13b3f17bec14af0859875ac75376e14"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p103681425164412"><a name="zh-cn_topic_0000001173164729_p103681425164412"></a><a name="zh-cn_topic_0000001173164729_p103681425164412"></a>获得指定id的组件对象，如果无指定id，则返回根组件对象。示例见<a href="#zh-cn_topic_0000001173164729_section1560185062215">获取DOM元素</a>。</p>
    <p id="zh-cn_topic_0000001173164729_a49e65fad6f094d049706c2514e8a47a9"><a name="zh-cn_topic_0000001173164729_a49e65fad6f094d049706c2514e8a47a9"></a><a name="zh-cn_topic_0000001173164729_a49e65fad6f094d049706c2514e8a47a9"></a>用法：</p>
    <p id="zh-cn_topic_0000001173164729_a7e59962ba3154456be9a71581364ce92"><a name="zh-cn_topic_0000001173164729_a7e59962ba3154456be9a71581364ce92"></a><a name="zh-cn_topic_0000001173164729_a7e59962ba3154456be9a71581364ce92"></a>&lt;div id='xxx'&gt;&lt;/div&gt;</p>
    <a name="zh-cn_topic_0000001173164729_u338f4836774844dcbeba6ee5218a1151"></a><a name="zh-cn_topic_0000001173164729_u338f4836774844dcbeba6ee5218a1151"></a><ul id="zh-cn_topic_0000001173164729_u338f4836774844dcbeba6ee5218a1151"><li>this.$element('xxx')：获得id为xxx的组件对象。</li><li>this.$element()：获得根组件对象。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row1276482485914"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p476514248597"><a name="zh-cn_topic_0000001173164729_p476514248597"></a><a name="zh-cn_topic_0000001173164729_p476514248597"></a>$rootElement</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p107653240596"><a name="zh-cn_topic_0000001173164729_p107653240596"></a><a name="zh-cn_topic_0000001173164729_p107653240596"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p137655241599"><a name="zh-cn_topic_0000001173164729_p137655241599"></a><a name="zh-cn_topic_0000001173164729_p137655241599"></a>获取根组件对象。</p>
    <p id="zh-cn_topic_0000001173164729_p0499149904"><a name="zh-cn_topic_0000001173164729_p0499149904"></a><a name="zh-cn_topic_0000001173164729_p0499149904"></a>用法：this.$rootElement().scrollTo({ duration: 500, position: 300 }), 页面在500ms内滚动300px。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_re1d5191790fb423282a8c381b317e0e6"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a87cad2551d564814a85a0459673a967c"><a name="zh-cn_topic_0000001173164729_a87cad2551d564814a85a0459673a967c"></a><a name="zh-cn_topic_0000001173164729_a87cad2551d564814a85a0459673a967c"></a>$root</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_aad1f4153e71544fb8b4e25d08e3787ca"><a name="zh-cn_topic_0000001173164729_aad1f4153e71544fb8b4e25d08e3787ca"></a><a name="zh-cn_topic_0000001173164729_aad1f4153e71544fb8b4e25d08e3787ca"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_aff829908cf8d49948c1e736e4a88e3ac"><a name="zh-cn_topic_0000001173164729_aff829908cf8d49948c1e736e4a88e3ac"></a><a name="zh-cn_topic_0000001173164729_aff829908cf8d49948c1e736e4a88e3ac"></a>获得顶级ViewModel实例。<a href="#zh-cn_topic_0000001173164729_section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_rd577efbcfc104ac2b5bed88fc9dd0cfb"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a680ff354c19f4d67a88b6eb45203b6d4"><a name="zh-cn_topic_0000001173164729_a680ff354c19f4d67a88b6eb45203b6d4"></a><a name="zh-cn_topic_0000001173164729_a680ff354c19f4d67a88b6eb45203b6d4"></a>$parent</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_aae2cc49b962347fba8f7dc43a1a6e072"><a name="zh-cn_topic_0000001173164729_aae2cc49b962347fba8f7dc43a1a6e072"></a><a name="zh-cn_topic_0000001173164729_aae2cc49b962347fba8f7dc43a1a6e072"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_af3075c6896404f13a5c93929aa713125"><a name="zh-cn_topic_0000001173164729_af3075c6896404f13a5c93929aa713125"></a><a name="zh-cn_topic_0000001173164729_af3075c6896404f13a5c93929aa713125"></a>获得父级ViewModel实例。<a href="#zh-cn_topic_0000001173164729_section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_rb96318b2fb9e4e8ea74dfb280e8fb804"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_a31ac11bf6d6b477cbc1fb446d5207d0d"><a name="zh-cn_topic_0000001173164729_a31ac11bf6d6b477cbc1fb446d5207d0d"></a><a name="zh-cn_topic_0000001173164729_a31ac11bf6d6b477cbc1fb446d5207d0d"></a>$child</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_a7ea3339724db43a0b0ba574ac621f83e"><a name="zh-cn_topic_0000001173164729_a7ea3339724db43a0b0ba574ac621f83e"></a><a name="zh-cn_topic_0000001173164729_a7ea3339724db43a0b0ba574ac621f83e"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p999210407446"><a name="zh-cn_topic_0000001173164729_p999210407446"></a><a name="zh-cn_topic_0000001173164729_p999210407446"></a>获得指定id的子级自定义组件的ViewModel实例。<a href="#zh-cn_topic_0000001173164729_section13798143717421">获取ViewModel</a>示例。</p>
    <p id="zh-cn_topic_0000001173164729_p112537114516"><a name="zh-cn_topic_0000001173164729_p112537114516"></a><a name="zh-cn_topic_0000001173164729_p112537114516"></a>用法：</p>
    <p id="zh-cn_topic_0000001173164729_a39f9c0db073641e5bcbcfc824769ae61"><a name="zh-cn_topic_0000001173164729_a39f9c0db073641e5bcbcfc824769ae61"></a><a name="zh-cn_topic_0000001173164729_a39f9c0db073641e5bcbcfc824769ae61"></a>this.$child('xxx') ：获取id为xxx的子级自定义组件的ViewModel实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   事件方法

    <a name="zh-cn_topic_0000001173164729_table106771249184219"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_row66781249104214"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_p15678249144218"><a name="zh-cn_topic_0000001173164729_p15678249144218"></a><a name="zh-cn_topic_0000001173164729_p15678249144218"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_p17678049114213"><a name="zh-cn_topic_0000001173164729_p17678049114213"></a><a name="zh-cn_topic_0000001173164729_p17678049114213"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_p26786495424"><a name="zh-cn_topic_0000001173164729_p26786495424"></a><a name="zh-cn_topic_0000001173164729_p26786495424"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_row267864944212"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p067834919421"><a name="zh-cn_topic_0000001173164729_p067834919421"></a><a name="zh-cn_topic_0000001173164729_p067834919421"></a>$watch</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p11678194920424"><a name="zh-cn_topic_0000001173164729_p11678194920424"></a><a name="zh-cn_topic_0000001173164729_p11678194920424"></a>data: string, callback: string | Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p1678104913426"><a name="zh-cn_topic_0000001173164729_p1678104913426"></a><a name="zh-cn_topic_0000001173164729_p1678104913426"></a>观察data中的属性变化，如果属性值改变，触发绑定的事件。示例见<a href="component/js-components-custom-props.md#ZH-CN_TOPIC_0000001209252183">自定义组件</a>。</p>
    <p id="zh-cn_topic_0000001173164729_p174621629124617"><a name="zh-cn_topic_0000001173164729_p174621629124617"></a><a name="zh-cn_topic_0000001173164729_p174621629124617"></a>用法：</p>
    <p id="zh-cn_topic_0000001173164729_p1173814312460"><a name="zh-cn_topic_0000001173164729_p1173814312460"></a><a name="zh-cn_topic_0000001173164729_p1173814312460"></a>this.$watch('key', callback)</p>
    </td>
    </tr>
    </tbody>
    </table>

-   页面方法

    <a name="zh-cn_topic_0000001173164729_table4927155523714"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_row4927255113714"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164729_p192765520376"><a name="zh-cn_topic_0000001173164729_p192765520376"></a><a name="zh-cn_topic_0000001173164729_p192765520376"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164729_p1192715550377"><a name="zh-cn_topic_0000001173164729_p1192715550377"></a><a name="zh-cn_topic_0000001173164729_p1192715550377"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164729_p49275555370"><a name="zh-cn_topic_0000001173164729_p49275555370"></a><a name="zh-cn_topic_0000001173164729_p49275555370"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_row1692716552379"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164729_p199274556371"><a name="zh-cn_topic_0000001173164729_p199274556371"></a><a name="zh-cn_topic_0000001173164729_p199274556371"></a>scrollTo<sup id="zh-cn_topic_0000001173164729_sup17224503390"><a name="zh-cn_topic_0000001173164729_sup17224503390"></a><a name="zh-cn_topic_0000001173164729_sup17224503390"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164729_p792745512375"><a name="zh-cn_topic_0000001173164729_p792745512375"></a><a name="zh-cn_topic_0000001173164729_p792745512375"></a>scrollPageParam: <a href="#zh-cn_topic_0000001173164729_table131981833173916">ScrollPageParam</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164729_p1292735517377"><a name="zh-cn_topic_0000001173164729_p1292735517377"></a><a name="zh-cn_topic_0000001173164729_p1292735517377"></a>将页面滚动到目标位置，可以通过ID选择器指定或者滚动距离指定。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  ScrollPageParam<sup>6+</sup>

    <a name="zh-cn_topic_0000001173164729_table131981833173916"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173164729_row31992331399"><th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001173164729_p16199113383917"><a name="zh-cn_topic_0000001173164729_p16199113383917"></a><a name="zh-cn_topic_0000001173164729_p16199113383917"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.45745425457454%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001173164729_p519953314398"><a name="zh-cn_topic_0000001173164729_p519953314398"></a><a name="zh-cn_topic_0000001173164729_p519953314398"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.88871112888711%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001173164729_p556391215143"><a name="zh-cn_topic_0000001173164729_p556391215143"></a><a name="zh-cn_topic_0000001173164729_p556391215143"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001173164729_p19199163393916"><a name="zh-cn_topic_0000001173164729_p19199163393916"></a><a name="zh-cn_topic_0000001173164729_p19199163393916"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173164729_row12199173303914"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001173164729_p8199203363916"><a name="zh-cn_topic_0000001173164729_p8199203363916"></a><a name="zh-cn_topic_0000001173164729_p8199203363916"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001173164729_p11991833133916"><a name="zh-cn_topic_0000001173164729_p11991833133916"></a><a name="zh-cn_topic_0000001173164729_p11991833133916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001173164729_p115641312111410"><a name="zh-cn_topic_0000001173164729_p115641312111410"></a><a name="zh-cn_topic_0000001173164729_p115641312111410"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001173164729_p1319943319395"><a name="zh-cn_topic_0000001173164729_p1319943319395"></a><a name="zh-cn_topic_0000001173164729_p1319943319395"></a>指定滚动位置。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row161991633143919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001173164729_p41991333163919"><a name="zh-cn_topic_0000001173164729_p41991333163919"></a><a name="zh-cn_topic_0000001173164729_p41991333163919"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001173164729_p1619918334392"><a name="zh-cn_topic_0000001173164729_p1619918334392"></a><a name="zh-cn_topic_0000001173164729_p1619918334392"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001173164729_p756451219146"><a name="zh-cn_topic_0000001173164729_p756451219146"></a><a name="zh-cn_topic_0000001173164729_p756451219146"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001173164729_p1419943363915"><a name="zh-cn_topic_0000001173164729_p1419943363915"></a><a name="zh-cn_topic_0000001173164729_p1419943363915"></a>指定需要滚动到的元素id。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row191992033183919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001173164729_p1919993316390"><a name="zh-cn_topic_0000001173164729_p1919993316390"></a><a name="zh-cn_topic_0000001173164729_p1919993316390"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001173164729_p9199183363916"><a name="zh-cn_topic_0000001173164729_p9199183363916"></a><a name="zh-cn_topic_0000001173164729_p9199183363916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001173164729_p5564181218144"><a name="zh-cn_topic_0000001173164729_p5564181218144"></a><a name="zh-cn_topic_0000001173164729_p5564181218144"></a>300</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001173164729_p3199233133920"><a name="zh-cn_topic_0000001173164729_p3199233133920"></a><a name="zh-cn_topic_0000001173164729_p3199233133920"></a>指定滚动时长，单位为毫秒。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row2019933315396"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001173164729_p13199733133915"><a name="zh-cn_topic_0000001173164729_p13199733133915"></a><a name="zh-cn_topic_0000001173164729_p13199733133915"></a>timingFunction</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001173164729_p0199173373919"><a name="zh-cn_topic_0000001173164729_p0199173373919"></a><a name="zh-cn_topic_0000001173164729_p0199173373919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001173164729_p10564171212141"><a name="zh-cn_topic_0000001173164729_p10564171212141"></a><a name="zh-cn_topic_0000001173164729_p10564171212141"></a>ease</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001173164729_p1919903313394"><a name="zh-cn_topic_0000001173164729_p1919903313394"></a><a name="zh-cn_topic_0000001173164729_p1919903313394"></a>指定滚动动画曲线，可选值参考</p>
    <p id="zh-cn_topic_0000001173164729_p158650537712"><a name="zh-cn_topic_0000001173164729_p158650537712"></a><a name="zh-cn_topic_0000001173164729_p158650537712"></a><a href="component/js-components-common-animation.md#ZH-CN_TOPIC_0000001164130754">animation-timing-function</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173164729_row110635616428"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001173164729_p6107856124211"><a name="zh-cn_topic_0000001173164729_p6107856124211"></a><a name="zh-cn_topic_0000001173164729_p6107856124211"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001173164729_p20107195674214"><a name="zh-cn_topic_0000001173164729_p20107195674214"></a><a name="zh-cn_topic_0000001173164729_p20107195674214"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001173164729_p20564151211419"><a name="zh-cn_topic_0000001173164729_p20564151211419"></a><a name="zh-cn_topic_0000001173164729_p20564151211419"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001173164729_p1107155694210"><a name="zh-cn_topic_0000001173164729_p1107155694210"></a><a name="zh-cn_topic_0000001173164729_p1107155694210"></a>指定滚动完成后需要执行的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    示例：

    ```
    this.$rootElement.scrollTo({position: 0})
    this.$rootElement.scrollTo({id: 'id', duration: 200, timingFunction: 'ease-in', complete: ()=>void})
    ```


## 获取DOM元素<a name="zh-cn_topic_0000001173164729_section1560185062215"></a>

1.  通过$refs获取DOM元素

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
        const animator = this.$refs.animator; // 获取ref属性为animator的DOM元素
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

2.  通过$element获取DOM元素

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
        const animator = this.$element('animator'); // 获取id属性为animator的DOM元素
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


## 获取ViewModel<a name="zh-cn_topic_0000001173164729_section13798143717421"></a>

根节点所在页面：

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
    text: 'I am root!',
  },
}
```

自定义parent组件：

```
<!-- parent.hml -->
<element name='childComp' src='../child/child.hml'></element>
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="parentClicked">parent component click</text>
  <text class="text-style" if="{{show}}">hello parent component!</text>
  <childComp id = "selfDefineChild"></childComp>
</div>
```

```
// parent.js
export default {
  data: {
    show: false,
    text: 'I am parent component!',
  },
  parentClicked () {
    this.show = !this.show;
    console.info('parent component get parent text');
    console.info(`${this.$parent().text}`);
    console.info("parent component get child function");
    console.info(`${this.$child('selfDefineChild').childClicked()}`);
  },
}
```

自定义child组件：

```
<!-- child.hml -->
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="childClicked">child component clicked</text>
  <text class="text-style" if="{{show}}">hello child component</text>
</div>
```

```
// child.js
export default {
  data: {
    show: false,
    text: 'I am child component!',
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


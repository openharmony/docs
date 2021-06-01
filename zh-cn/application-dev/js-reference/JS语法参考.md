# JS语法参考<a name="ZH-CN_TOPIC_0000001115814808"></a>

-   [语法](#zh-cn_topic_0000001058562835_s6ca2e99746664509961f65b82d11ab58)
-   [对象](#zh-cn_topic_0000001058562835_s7493791622a248fbb2e03703149bb3b5)
-   [方法](#zh-cn_topic_0000001058562835_s4e1ff24ec78e41948502d8977d24e44c)
-   [获取DOM元素](#zh-cn_topic_0000001058562835_section1560185062215)
-   [获取ViewModel](#zh-cn_topic_0000001058562835_section13798143717421)
-   [生命周期接口](#zh-cn_topic_0000001058562835_s962b82fb67304ec9a50fb06ffa977560)

JS文件用来定义HML页面的业务逻辑，支持ECMA规范的JavaScript语言。基于JavaScript语言的动态化能力，可以使应用更加富有表现力，具备更加灵活的设计。下面讲述JS文件的编译和运行的支持情况。

## 语法<a name="zh-cn_topic_0000001058562835_s6ca2e99746664509961f65b82d11ab58"></a>

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


## 对象<a name="zh-cn_topic_0000001058562835_s7493791622a248fbb2e03703149bb3b5"></a>

-   应用对象

    <a name="zh-cn_topic_0000001058562835_tc5261f21b7014f6cbe17d3ef51b9e1a9"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001058562835_ae816119c3e0143c892512012c7927037"><a name="zh-cn_topic_0000001058562835_ae816119c3e0143c892512012c7927037"></a><a name="zh-cn_topic_0000001058562835_ae816119c3e0143c892512012c7927037"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"><a name="zh-cn_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="zh-cn_topic_0000001058562835_ab72e901bb3ef4657b303513b8fa5ec1f"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"><a name="zh-cn_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="zh-cn_topic_0000001058562835_ae95f3df496fc41939ac6c1cf74aef9d8"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_r170881741fb347fa9bc5ac3a33382a9b"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"><a name="zh-cn_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"></a><a name="zh-cn_topic_0000001058562835_a9a70780b9fd8468d98a7c107ee67d8d8"></a>$def</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"><a name="zh-cn_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"></a><a name="zh-cn_topic_0000001058562835_ace202d9f2dd547c8ab8693954af5d616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"><a name="zh-cn_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"></a><a name="zh-cn_topic_0000001058562835_a08a4d55b01864b2fa866f6431cd322de"></a>使用this.$app.$def获取在app.js中暴露的对象。</p>
    <div class="note" id="zh-cn_topic_0000001058562835_note23038122918"><a name="zh-cn_topic_0000001058562835_note23038122918"></a><a name="zh-cn_topic_0000001058562835_note23038122918"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001058562835_p73038121790"><a name="zh-cn_topic_0000001058562835_p73038121790"></a><a name="zh-cn_topic_0000001058562835_p73038121790"></a>应用对象不支持数据绑定，需主动触发UI更新。</p>
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
      globalMethod () {
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

    <a name="zh-cn_topic_0000001058562835_table8514281151"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_row2511928359"><th class="cellrowborder" valign="top" width="16.36%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001058562835_p1951028754"><a name="zh-cn_topic_0000001058562835_p1951028754"></a><a name="zh-cn_topic_0000001058562835_p1951028754"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.54%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001058562835_p1351228252"><a name="zh-cn_topic_0000001058562835_p1351228252"></a><a name="zh-cn_topic_0000001058562835_p1351228252"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.10000000000001%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001058562835_p651112815519"><a name="zh-cn_topic_0000001058562835_p651112815519"></a><a name="zh-cn_topic_0000001058562835_p651112815519"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_row1651228855"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p115421323762"><a name="zh-cn_topic_0000001058562835_p115421323762"></a><a name="zh-cn_topic_0000001058562835_p115421323762"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p05120283516"><a name="zh-cn_topic_0000001058562835_p05120283516"></a><a name="zh-cn_topic_0000001058562835_p05120283516"></a>Object/Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p61056578507"><a name="zh-cn_topic_0000001058562835_p61056578507"></a><a name="zh-cn_topic_0000001058562835_p61056578507"></a>页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for, if, show, tid。</p>
    <p id="zh-cn_topic_0000001058562835_p95116281350"><a name="zh-cn_topic_0000001058562835_p95116281350"></a><a name="zh-cn_topic_0000001058562835_p95116281350"></a>data与private和public不能重合使用。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row2991343201512"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p1873818536545"><a name="zh-cn_topic_0000001058562835_p1873818536545"></a><a name="zh-cn_topic_0000001058562835_p1873818536545"></a>$refs</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p1073815318541"><a name="zh-cn_topic_0000001058562835_p1073815318541"></a><a name="zh-cn_topic_0000001058562835_p1073815318541"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p7879941512"><a name="zh-cn_topic_0000001058562835_p7879941512"></a><a name="zh-cn_topic_0000001058562835_p7879941512"></a>持有注册过ref 属性的DOM元素或子组件实例的对象。示例见<a href="#zh-cn_topic_0000001058562835_section1560185062215">获取DOM元素</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row340610191094"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p240712191998"><a name="zh-cn_topic_0000001058562835_p240712191998"></a><a name="zh-cn_topic_0000001058562835_p240712191998"></a>private</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p1840710194916"><a name="zh-cn_topic_0000001058562835_p1840710194916"></a><a name="zh-cn_topic_0000001058562835_p1840710194916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p17407161911917"><a name="zh-cn_topic_0000001058562835_p17407161911917"></a><a name="zh-cn_topic_0000001058562835_p17407161911917"></a>页面的数据模型，private下的数据属性只能由当前页面修改。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row594316386514"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p99441138554"><a name="zh-cn_topic_0000001058562835_p99441138554"></a><a name="zh-cn_topic_0000001058562835_p99441138554"></a>public</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p994419381151"><a name="zh-cn_topic_0000001058562835_p994419381151"></a><a name="zh-cn_topic_0000001058562835_p994419381151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p2094418381153"><a name="zh-cn_topic_0000001058562835_p2094418381153"></a><a name="zh-cn_topic_0000001058562835_p2094418381153"></a>页面的数据模型，public下的数据属性的行为与data保持一致。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row638815278598"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p139903755910"><a name="zh-cn_topic_0000001058562835_p139903755910"></a><a name="zh-cn_topic_0000001058562835_p139903755910"></a>props</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p4258153555911"><a name="zh-cn_topic_0000001058562835_p4258153555911"></a><a name="zh-cn_topic_0000001058562835_p4258153555911"></a>Array/Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p12388227105918"><a name="zh-cn_topic_0000001058562835_p12388227105918"></a><a name="zh-cn_topic_0000001058562835_p12388227105918"></a>props用于组件之间的通信，可以通过&lt;tag xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for, if, show, tid。目前props的数据类型不支持Function。示例见<a href="Props.md#ZH-CN_TOPIC_0000001162414643">自定义组件</a>。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row14421201293417"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001058562835_p144221012173416"><a name="zh-cn_topic_0000001058562835_p144221012173416"></a><a name="zh-cn_topic_0000001058562835_p144221012173416"></a>computed</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001058562835_p164221412163412"><a name="zh-cn_topic_0000001058562835_p164221412163412"></a><a name="zh-cn_topic_0000001058562835_p164221412163412"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001058562835_p6422712153413"><a name="zh-cn_topic_0000001058562835_p6422712153413"></a><a name="zh-cn_topic_0000001058562835_p6422712153413"></a>用于在读取或设置进行预先处理，计算属性的结果会被缓存。计算属性名不能以$或_开头，不要使用保留字。示例见<a href="Props.md#ZH-CN_TOPIC_0000001162414643">自定义组件</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="zh-cn_topic_0000001058562835_s4e1ff24ec78e41948502d8977d24e44c"></a>

-   数据方法

    <a name="zh-cn_topic_0000001058562835_td998a97f34c44c86876d2e1aee646bc6"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_r41906fbf818041e089ab60c9d410de72"><th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"><a name="zh-cn_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"></a><a name="zh-cn_topic_0000001058562835_a44385457c0224b7aa0af4b8aaa5fec41"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"><a name="zh-cn_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"></a><a name="zh-cn_topic_0000001058562835_a046fbd024fd74d9ca4aba0c61d024c22"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.549999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"><a name="zh-cn_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"></a><a name="zh-cn_topic_0000001058562835_a21e0645662414f9893af7ff3a6e24e92"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.449999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"><a name="zh-cn_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"></a><a name="zh-cn_topic_0000001058562835_add5a5e57df3a4d47a09a8f3ef2a28088"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_rcba2037b58704ed9bef75b912b96eb80"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"><a name="zh-cn_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"></a><a name="zh-cn_topic_0000001058562835_a75bccc07529343469aad71db98e70b1a"></a>$set</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"><a name="zh-cn_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"></a><a name="zh-cn_topic_0000001058562835_ab48936d2b9ea4082bb768ccca20ca48a"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"><a name="zh-cn_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"></a><a name="zh-cn_topic_0000001058562835_a53419b7e4fde4993b3ab35ad3312c4da"></a>key: string</p>
    <p id="zh-cn_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"><a name="zh-cn_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"></a><a name="zh-cn_topic_0000001058562835_ae1a85e69d8434c6987a2599c36b53b01"></a>value: any</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.449999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_p84781851442"><a name="zh-cn_topic_0000001058562835_p84781851442"></a><a name="zh-cn_topic_0000001058562835_p84781851442"></a>添加新的数据属性或者修改已有数据属性。</p>
    <p id="zh-cn_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"><a name="zh-cn_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"></a><a name="zh-cn_topic_0000001058562835_ae55e2b1d9401454c8555cbb419068829"></a>用法：</p>
    <p id="zh-cn_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"><a name="zh-cn_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"></a><a name="zh-cn_topic_0000001058562835_a266dfd3b1b384811b4e7d9a39350e3bc"></a>this.$set('key',value)：添加数据属性。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_r189d027189d842a1baf1a5d91a9af901"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"><a name="zh-cn_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"></a><a name="zh-cn_topic_0000001058562835_a4ee9a900fc454f66a628f210f2e50548"></a>$delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"><a name="zh-cn_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"></a><a name="zh-cn_topic_0000001058562835_a7b8b3383fb794c4890d7d3737ac43479"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"><a name="zh-cn_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a><a name="zh-cn_topic_0000001058562835_a2e9d28b0f19d4cabbcc1b464bbd9993a"></a>key: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.449999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_p18897453134313"><a name="zh-cn_topic_0000001058562835_p18897453134313"></a><a name="zh-cn_topic_0000001058562835_p18897453134313"></a>删除数据属性。</p>
    <p id="zh-cn_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"><a name="zh-cn_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a><a name="zh-cn_topic_0000001058562835_a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a>用法：</p>
    <p id="zh-cn_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"><a name="zh-cn_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"></a><a name="zh-cn_topic_0000001058562835_a628cc2f32b9247b091f5d37ab0a58fdb"></a>this.$delete('key')：删除数据属性。</p>
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

    <a name="zh-cn_topic_0000001058562835_te12ef71dd85347738d3670aaa9934476"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_r7c071c236183461dbd8e78bce0073401"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"><a name="zh-cn_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"></a><a name="zh-cn_topic_0000001058562835_a4abb4994ac12403f88c36b8b34a739ec"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.91%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"><a name="zh-cn_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"></a><a name="zh-cn_topic_0000001058562835_abb7baa4b7f9a4e068d85d3fd731987cf"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.85%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"><a name="zh-cn_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"></a><a name="zh-cn_topic_0000001058562835_aeac2f3bdee564731ace449ab67008c2c"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"><a name="zh-cn_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"></a><a name="zh-cn_topic_0000001058562835_af669c9f192954747ba61f011dcb6b1c7"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_r786add9633394d2f8d72020f28465c87"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"><a name="zh-cn_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"></a><a name="zh-cn_topic_0000001058562835_a6cce84705d514809ac0511d69f5605e1"></a>$element</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"><a name="zh-cn_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"></a><a name="zh-cn_topic_0000001058562835_a153d48111c7048b39b2e8664841816ee"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.85%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"><a name="zh-cn_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"></a><a name="zh-cn_topic_0000001058562835_ad13b3f17bec14af0859875ac75376e14"></a>id: string 组件id</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_p103681425164412"><a name="zh-cn_topic_0000001058562835_p103681425164412"></a><a name="zh-cn_topic_0000001058562835_p103681425164412"></a>获得指定id的组件对象，如果无指定id，则返回根组件对象。示例见<a href="#zh-cn_topic_0000001058562835_section1560185062215">获取DOM元素</a>。</p>
    <p id="zh-cn_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"><a name="zh-cn_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"></a><a name="zh-cn_topic_0000001058562835_a49e65fad6f094d049706c2514e8a47a9"></a>用法：</p>
    <p id="zh-cn_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"><a name="zh-cn_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"></a><a name="zh-cn_topic_0000001058562835_a7e59962ba3154456be9a71581364ce92"></a>&lt;div id='xxx'&gt;&lt;/div&gt;</p>
    <a name="zh-cn_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"></a><a name="zh-cn_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"></a><ul id="zh-cn_topic_0000001058562835_u338f4836774844dcbeba6ee5218a1151"><li>this.$element('xxx')：获得id为xxx的组件对象。</li><li>this.$element()：获得根组件对象。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_re1d5191790fb423282a8c381b317e0e6"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"><a name="zh-cn_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"></a><a name="zh-cn_topic_0000001058562835_a87cad2551d564814a85a0459673a967c"></a>$root</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"><a name="zh-cn_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"></a><a name="zh-cn_topic_0000001058562835_a67c6c5db8a024d8686cc25a61916e04b"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.85%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"><a name="zh-cn_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"></a><a name="zh-cn_topic_0000001058562835_aad1f4153e71544fb8b4e25d08e3787ca"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"><a name="zh-cn_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"></a><a name="zh-cn_topic_0000001058562835_aff829908cf8d49948c1e736e4a88e3ac"></a>获得顶级ViewModel实例。<a href="#zh-cn_topic_0000001058562835_section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_rd577efbcfc104ac2b5bed88fc9dd0cfb"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"><a name="zh-cn_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"></a><a name="zh-cn_topic_0000001058562835_a680ff354c19f4d67a88b6eb45203b6d4"></a>$parent</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"><a name="zh-cn_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"></a><a name="zh-cn_topic_0000001058562835_a067141aedc7248f0b812aa5146d0dfb6"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.85%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"><a name="zh-cn_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"></a><a name="zh-cn_topic_0000001058562835_aae2cc49b962347fba8f7dc43a1a6e072"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"><a name="zh-cn_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"></a><a name="zh-cn_topic_0000001058562835_af3075c6896404f13a5c93929aa713125"></a>获得父级ViewModel实例。<a href="#zh-cn_topic_0000001058562835_section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_rb96318b2fb9e4e8ea74dfb280e8fb804"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"><a name="zh-cn_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"></a><a name="zh-cn_topic_0000001058562835_a31ac11bf6d6b477cbc1fb446d5207d0d"></a>$child</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"><a name="zh-cn_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"></a><a name="zh-cn_topic_0000001058562835_a88a0d3ac894342b696f8d0c7ec4607ae"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.85%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"><a name="zh-cn_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"></a><a name="zh-cn_topic_0000001058562835_a7ea3339724db43a0b0ba574ac621f83e"></a>id: string 组件id</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_p999210407446"><a name="zh-cn_topic_0000001058562835_p999210407446"></a><a name="zh-cn_topic_0000001058562835_p999210407446"></a>获得指定id的子级自定义组件的ViewModel实例。<a href="#zh-cn_topic_0000001058562835_section13798143717421">获取ViewModel</a>示例。</p>
    <p id="zh-cn_topic_0000001058562835_p112537114516"><a name="zh-cn_topic_0000001058562835_p112537114516"></a><a name="zh-cn_topic_0000001058562835_p112537114516"></a>用法：</p>
    <p id="zh-cn_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"><a name="zh-cn_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"></a><a name="zh-cn_topic_0000001058562835_a39f9c0db073641e5bcbcfc824769ae61"></a>this.$child('xxx') ：获取id为xxx的子级自定义组件的ViewModel实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   事件方法

    <a name="zh-cn_topic_0000001058562835_table106771249184219"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_row66781249104214"><th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001058562835_p15678249144218"><a name="zh-cn_topic_0000001058562835_p15678249144218"></a><a name="zh-cn_topic_0000001058562835_p15678249144218"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001058562835_p2678194911424"><a name="zh-cn_topic_0000001058562835_p2678194911424"></a><a name="zh-cn_topic_0000001058562835_p2678194911424"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.569999999999997%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001058562835_p17678049114213"><a name="zh-cn_topic_0000001058562835_p17678049114213"></a><a name="zh-cn_topic_0000001058562835_p17678049114213"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="46%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001058562835_p26786495424"><a name="zh-cn_topic_0000001058562835_p26786495424"></a><a name="zh-cn_topic_0000001058562835_p26786495424"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_row267864944212"><td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001058562835_p067834919421"><a name="zh-cn_topic_0000001058562835_p067834919421"></a><a name="zh-cn_topic_0000001058562835_p067834919421"></a>$watch</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001058562835_p1967834911420"><a name="zh-cn_topic_0000001058562835_p1967834911420"></a><a name="zh-cn_topic_0000001058562835_p1967834911420"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.569999999999997%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001058562835_p11678194920424"><a name="zh-cn_topic_0000001058562835_p11678194920424"></a><a name="zh-cn_topic_0000001058562835_p11678194920424"></a>data: string</p>
    <p id="zh-cn_topic_0000001058562835_p27811112011"><a name="zh-cn_topic_0000001058562835_p27811112011"></a><a name="zh-cn_topic_0000001058562835_p27811112011"></a>callback: 函数名，回调函数里有两个参数，第一个参数为属性新值，第二个参数为属性旧值</p>
    </td>
    <td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001058562835_p1678104913426"><a name="zh-cn_topic_0000001058562835_p1678104913426"></a><a name="zh-cn_topic_0000001058562835_p1678104913426"></a>观察data中的属性变化，如果属性值改变，触发绑定的事件。示例见<a href="Props.md#ZH-CN_TOPIC_0000001162414643">自定义组件</a>。</p>
    <p id="zh-cn_topic_0000001058562835_p174621629124617"><a name="zh-cn_topic_0000001058562835_p174621629124617"></a><a name="zh-cn_topic_0000001058562835_p174621629124617"></a>用法：</p>
    <p id="zh-cn_topic_0000001058562835_p1173814312460"><a name="zh-cn_topic_0000001058562835_p1173814312460"></a><a name="zh-cn_topic_0000001058562835_p1173814312460"></a>this.$watch('key', callback)</p>
    </td>
    </tr>
    </tbody>
    </table>


## 获取DOM元素<a name="zh-cn_topic_0000001058562835_section1560185062215"></a>

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

2.  通过$element 方法获取DOM元素

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


## 获取ViewModel<a name="zh-cn_topic_0000001058562835_section13798143717421"></a>

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

## 生命周期接口<a name="zh-cn_topic_0000001058562835_s962b82fb67304ec9a50fb06ffa977560"></a>

-   页面生命周期

    <a name="zh-cn_topic_0000001058562835_t7208da80646145cb86b25df20f52a5d4"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_r4bc39237158f4199b86d18d0784b005d"><th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.7.1.1"><p id="zh-cn_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"><a name="zh-cn_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"></a><a name="zh-cn_topic_0000001058562835_aa7d8254f7b0f495e8a38fc76d3508fc4"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.7.1.2"><p id="zh-cn_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"><a name="zh-cn_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"></a><a name="zh-cn_topic_0000001058562835_a037ba3feced74d36ae28ca2414da39a2"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.45%" id="mcps1.1.7.1.3"><p id="zh-cn_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"><a name="zh-cn_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"></a><a name="zh-cn_topic_0000001058562835_a2f9474fba8744940be4972dfd54bde01"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.639999999999999%" id="mcps1.1.7.1.4"><p id="zh-cn_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"><a name="zh-cn_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"></a><a name="zh-cn_topic_0000001058562835_a491437a8ca3f47e0bb37f7284418b16e"></a>返回值</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.42%" id="mcps1.1.7.1.5"><p id="zh-cn_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"><a name="zh-cn_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"></a><a name="zh-cn_topic_0000001058562835_aac19d68c24f6444095fd09939256ea10"></a>描述</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.58%" id="mcps1.1.7.1.6"><p id="zh-cn_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"><a name="zh-cn_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"></a><a name="zh-cn_topic_0000001058562835_a80a1ef722e3f4008961e97ea3db877ef"></a>触发时机</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_rb52da1ffb529417c9f0290d1f122a87e"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"><a name="zh-cn_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"></a><a name="zh-cn_topic_0000001058562835_acd1fd04acf1f4b789a178ecc66e8c27c"></a>onInit</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"><a name="zh-cn_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"></a><a name="zh-cn_topic_0000001058562835_a86ee0c2879d744c9a7c81908ddc5be08"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"><a name="zh-cn_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"></a><a name="zh-cn_topic_0000001058562835_a084dc9808c36441d906785b3210895f3"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"><a name="zh-cn_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"></a><a name="zh-cn_topic_0000001058562835_a59982537a58e482c916b3de00cfd9f1a"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"><a name="zh-cn_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"></a><a name="zh-cn_topic_0000001058562835_a50617b80389e45b58dd015e4db4ac094"></a>页面初始化</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"><a name="zh-cn_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"></a><a name="zh-cn_topic_0000001058562835_a2e9c8d05ae0e4155b98a25a02bf54b9b"></a>页面数据初始化完成时触发，只触发一次。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_r57dd28dbf8a243cdad002d8599eda15f"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"><a name="zh-cn_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"></a><a name="zh-cn_topic_0000001058562835_af6a0fe8473a54e71be833ea3c4135328"></a>onReady</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"><a name="zh-cn_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"></a><a name="zh-cn_topic_0000001058562835_a5d96ae01ba73452e9aef97a5547c5df9"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"><a name="zh-cn_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"></a><a name="zh-cn_topic_0000001058562835_a8bff6c6a424e4158ae7331c854f4cf83"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"><a name="zh-cn_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"></a><a name="zh-cn_topic_0000001058562835_a601e141766114b2ea6d1ad223eb7614f"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"><a name="zh-cn_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"></a><a name="zh-cn_topic_0000001058562835_aa80d3cebd7f64e97ac348b8f034efc04"></a>页面创建完成</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"><a name="zh-cn_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"></a><a name="zh-cn_topic_0000001058562835_a2e00e7dee8164661b4244c4a34ae9b2c"></a>页面创建完成时触发，只触发一次。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_r1dd8a5bfd50043eeb2fff708e728a9fa"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"><a name="zh-cn_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"></a><a name="zh-cn_topic_0000001058562835_ae46609ef4ad2444fb4befc1ac552eb88"></a>onShow</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"><a name="zh-cn_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"></a><a name="zh-cn_topic_0000001058562835_a4b3c794964514f988757cd639964b7a8"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"><a name="zh-cn_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"></a><a name="zh-cn_topic_0000001058562835_ab0efc9d24ca348368170390c9b1bb3d1"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"><a name="zh-cn_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"></a><a name="zh-cn_topic_0000001058562835_a6574c77788444fa29d72cf91d190b820"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"><a name="zh-cn_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"></a><a name="zh-cn_topic_0000001058562835_a147a1ab39d2043f2a22c62b3483335b6"></a>页面显示</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"><a name="zh-cn_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"></a><a name="zh-cn_topic_0000001058562835_a23c4cbd18ad24bd8a496dbc487dd5400"></a>页面显示时触发。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_r4247056b80864bb7ab5678341dc8c29a"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"><a name="zh-cn_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"></a><a name="zh-cn_topic_0000001058562835_a973949fa33de41ca9a53c43e98b47f63"></a>onHide</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"><a name="zh-cn_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"></a><a name="zh-cn_topic_0000001058562835_a245d96bb028641d492503489b54c4c2c"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"><a name="zh-cn_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"></a><a name="zh-cn_topic_0000001058562835_abe097ffbf5144a91a4856c56aa5f15e6"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"><a name="zh-cn_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"></a><a name="zh-cn_topic_0000001058562835_a0d98f4d13f614b9296702f3f3d75641d"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"><a name="zh-cn_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"></a><a name="zh-cn_topic_0000001058562835_a169e08a844b2452d85acfaca01ea20ee"></a>页面消失</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"><a name="zh-cn_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"></a><a name="zh-cn_topic_0000001058562835_ae54d3a1f653c495ba8950e82c0fb3db4"></a>页面消失时触发。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_ra205abdcebf94a5583cdbd422211dd4b"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"><a name="zh-cn_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"></a><a name="zh-cn_topic_0000001058562835_aeb5a3893eb974dd88a762adc8077ed54"></a>onDestroy</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"><a name="zh-cn_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"></a><a name="zh-cn_topic_0000001058562835_a3b98923b60554564b67d28a3ac2bb562"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"><a name="zh-cn_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"></a><a name="zh-cn_topic_0000001058562835_acb0528d7ebe3422f9c173bf7354b82b0"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"><a name="zh-cn_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"></a><a name="zh-cn_topic_0000001058562835_a5ae53b15e9f9475cbc505f21741ce1f8"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"><a name="zh-cn_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"></a><a name="zh-cn_topic_0000001058562835_a1f2cd15604434b1f8c1ad075db3ec76d"></a>页面销毁</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"><a name="zh-cn_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"></a><a name="zh-cn_topic_0000001058562835_aab6fb684fd454b41a6f701628f9c2307"></a>页面销毁时触发。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_r8c29065ea9334b37bd69e3d967d00eb2"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"><a name="zh-cn_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"></a><a name="zh-cn_topic_0000001058562835_adb577f9b58394c39987fb4f9b6715c27"></a>onBackPress</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"><a name="zh-cn_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"></a><a name="zh-cn_topic_0000001058562835_abc299879a34642c896aceeef25ac6d8c"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"><a name="zh-cn_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"></a><a name="zh-cn_topic_0000001058562835_ad6002f27508740dc9d2e9e70a4a88eb1"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"><a name="zh-cn_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"></a><a name="zh-cn_topic_0000001058562835_ac1e8b293216840febce4cb1e5246feb5"></a>Boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"><a name="zh-cn_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"></a><a name="zh-cn_topic_0000001058562835_a95b85747b7f545b68d28846eba6d73f8"></a>返回按钮动作</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"><a name="zh-cn_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"></a><a name="zh-cn_topic_0000001058562835_a710515458aac45948cf7dc711198b2ed"></a>当用户点击返回按钮时触发。</p>
    <a name="zh-cn_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"></a><a name="zh-cn_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"></a><ul id="zh-cn_topic_0000001058562835_ub2ffbaf74d7d44a390d441db5fa5d440"><li>返回true表示页面自己处理返回逻辑。</li><li>返回false表示使用默认的返回逻辑。</li><li>不返回值会作为false处理。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row73484412715"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_p9479151716"><a name="zh-cn_topic_0000001058562835_p9479151716"></a><a name="zh-cn_topic_0000001058562835_p9479151716"></a>onActive()<sup id="zh-cn_topic_0000001058562835_sup2479151478"><a name="zh-cn_topic_0000001058562835_sup2479151478"></a><a name="zh-cn_topic_0000001058562835_sup2479151478"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_p44795511715"><a name="zh-cn_topic_0000001058562835_p44795511715"></a><a name="zh-cn_topic_0000001058562835_p44795511715"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_p1479652717"><a name="zh-cn_topic_0000001058562835_p1479652717"></a><a name="zh-cn_topic_0000001058562835_p1479652717"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_p14479451712"><a name="zh-cn_topic_0000001058562835_p14479451712"></a><a name="zh-cn_topic_0000001058562835_p14479451712"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_p17479551871"><a name="zh-cn_topic_0000001058562835_p17479551871"></a><a name="zh-cn_topic_0000001058562835_p17479551871"></a>页面激活</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_p124801651476"><a name="zh-cn_topic_0000001058562835_p124801651476"></a><a name="zh-cn_topic_0000001058562835_p124801651476"></a>页面激活时触发。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row87561847563"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_p575744115618"><a name="zh-cn_topic_0000001058562835_p575744115618"></a><a name="zh-cn_topic_0000001058562835_p575744115618"></a>onInactive()<sup id="zh-cn_topic_0000001058562835_sup1689453314352"><a name="zh-cn_topic_0000001058562835_sup1689453314352"></a><a name="zh-cn_topic_0000001058562835_sup1689453314352"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_p77571843566"><a name="zh-cn_topic_0000001058562835_p77571843566"></a><a name="zh-cn_topic_0000001058562835_p77571843566"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_p177571745568"><a name="zh-cn_topic_0000001058562835_p177571745568"></a><a name="zh-cn_topic_0000001058562835_p177571745568"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_p1775734125612"><a name="zh-cn_topic_0000001058562835_p1775734125612"></a><a name="zh-cn_topic_0000001058562835_p1775734125612"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_p137575475615"><a name="zh-cn_topic_0000001058562835_p137575475615"></a><a name="zh-cn_topic_0000001058562835_p137575475615"></a>页面暂停</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_p197577417562"><a name="zh-cn_topic_0000001058562835_p197577417562"></a><a name="zh-cn_topic_0000001058562835_p197577417562"></a>页面暂停时触发。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_row33231032142114"><td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_p18323163215216"><a name="zh-cn_topic_0000001058562835_p18323163215216"></a><a name="zh-cn_topic_0000001058562835_p18323163215216"></a>onNewRequest()<sup id="zh-cn_topic_0000001058562835_sup13778137173514"><a name="zh-cn_topic_0000001058562835_sup13778137173514"></a><a name="zh-cn_topic_0000001058562835_sup13778137173514"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_p12323143202115"><a name="zh-cn_topic_0000001058562835_p12323143202115"></a><a name="zh-cn_topic_0000001058562835_p12323143202115"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.45%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_p103231732192111"><a name="zh-cn_topic_0000001058562835_p103231732192111"></a><a name="zh-cn_topic_0000001058562835_p103231732192111"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.639999999999999%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_p832353215215"><a name="zh-cn_topic_0000001058562835_p832353215215"></a><a name="zh-cn_topic_0000001058562835_p832353215215"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.42%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_p10324123232120"><a name="zh-cn_topic_0000001058562835_p10324123232120"></a><a name="zh-cn_topic_0000001058562835_p10324123232120"></a>FA重新请求</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.58%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_p2324432152120"><a name="zh-cn_topic_0000001058562835_p2324432152120"></a><a name="zh-cn_topic_0000001058562835_p2324432152120"></a>该回调当FA已经启动时收到新的请求后触发。</p>
    </td>
    </tr>
    </tbody>
    </table>

    页面A的生命周期接口的调用顺序

    -   打开页面A：onInit\(\) -\> onReady\(\) -\> onShow\(\) -\> onActive\(\)
    -   在页面A打开页面B：onInactive\(\) -\> onHide\(\)
    -   从页面B返回页面A：onShow\(\) -\> onActive\(\)
    -   退出页面A：onBackPress\(\) -\> onInactive\(\) -\> onHide\(\) -\> onDestroy\(\)
    -   页面隐藏到后台运行：onInactive\(\) -\> onHide\(\)
    -   页面从后台运行恢复到前台：onShow\(\)

-   应用生命周期

    <a name="zh-cn_topic_0000001058562835_tca9d892b58db4855a2c0dced267fd7f0"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001058562835_r400fd9d50fba4a3ea8c141401ddee795"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.7.1.1"><p id="zh-cn_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"><a name="zh-cn_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"></a><a name="zh-cn_topic_0000001058562835_a0a1ab6a5ff1845bba9aa2fd5e1898a59"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.1.7.1.2"><p id="zh-cn_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"><a name="zh-cn_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"></a><a name="zh-cn_topic_0000001058562835_a943e38bad4da4720996661cf3ff5518b"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.861386138613863%" id="mcps1.1.7.1.3"><p id="zh-cn_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"><a name="zh-cn_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"></a><a name="zh-cn_topic_0000001058562835_ae3d702c5498542c39a0ef6c818c97375"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.891089108910892%" id="mcps1.1.7.1.4"><p id="zh-cn_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"><a name="zh-cn_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"></a><a name="zh-cn_topic_0000001058562835_a4de4a12da16d4c4d887a6777f0be68cd"></a>返回值</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.7.1.5"><p id="zh-cn_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"><a name="zh-cn_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"></a><a name="zh-cn_topic_0000001058562835_a32600841a8ef4b66bb6f5147ed8e7002"></a>描述</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.7.1.6"><p id="zh-cn_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"><a name="zh-cn_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"></a><a name="zh-cn_topic_0000001058562835_a312bd20f0c5f46f4b5a1119e7310849e"></a>触发时机</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001058562835_r447ec21f8d584378ab37e935ce6aaeac"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"><a name="zh-cn_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"></a><a name="zh-cn_topic_0000001058562835_a6909c5378aaa4bb9bd556227c0d395a5"></a>onCreate</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"><a name="zh-cn_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"></a><a name="zh-cn_topic_0000001058562835_ae4b9dc8eadec4055b81295dc6a84de31"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"><a name="zh-cn_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"></a><a name="zh-cn_topic_0000001058562835_a90eb4416b3634253acb70822ebf4d786"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.891089108910892%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"><a name="zh-cn_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"></a><a name="zh-cn_topic_0000001058562835_aefd9c62af6c541ad93252b8157241603"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"><a name="zh-cn_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"></a><a name="zh-cn_topic_0000001058562835_ad6eb36056b30459c9ef95a00129d8244"></a>应用创建</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"><a name="zh-cn_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"></a><a name="zh-cn_topic_0000001058562835_ac241fb7562cc44ec8ba5a8ddcbec01d0"></a>当应用创建时调用。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001058562835_rd1427aa6bfba4386b3c82e875f93c78d"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"><a name="zh-cn_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"></a><a name="zh-cn_topic_0000001058562835_a67cdbd870e4a47e59417485332b082d1"></a>onDestroy</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"><a name="zh-cn_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"></a><a name="zh-cn_topic_0000001058562835_a06bc15e70d6a41438a42a34ad3fb7af9"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.861386138613863%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"><a name="zh-cn_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"></a><a name="zh-cn_topic_0000001058562835_aa2809330917b440db6d524450e5237d2"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.891089108910892%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"><a name="zh-cn_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"></a><a name="zh-cn_topic_0000001058562835_a4c17dfc84f954bc9b4fe2c28e3a1168c"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"><a name="zh-cn_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"></a><a name="zh-cn_topic_0000001058562835_ad5e603c57feb448aa66f0caa91a1f760"></a>应用退出</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"><a name="zh-cn_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"></a><a name="zh-cn_topic_0000001058562835_a7d8db18e9e75433fbfe08f8f014c9da9"></a>当应用退出时触发。</p>
    </td>
    </tr>
    </tbody>
    </table>



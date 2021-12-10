# JS语法参考<a name="ZH-CN_TOPIC_0000001173164729"></a>

JS文件用来定义HML页面的业务逻辑，支持ECMA规范的JavaScript语言。基于JavaScript语言的动态化能力，可以使应用更加富有表现力，具备更加灵活的设计能力。下面讲述JS文件的编译和运行的支持情况。

## 语法<a name="s6ca2e99746664509961f65b82d11ab58"></a>

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


## 对象<a name="s7493791622a248fbb2e03703149bb3b5"></a>

-   应用对象

    <a name="tc5261f21b7014f6cbe17d3ef51b9e1a9"></a>
    <table><thead align="left"><tr id="r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="ae816119c3e0143c892512012c7927037"><a name="ae816119c3e0143c892512012c7927037"></a><a name="ae816119c3e0143c892512012c7927037"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="ab72e901bb3ef4657b303513b8fa5ec1f"><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="ae95f3df496fc41939ac6c1cf74aef9d8"><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r170881741fb347fa9bc5ac3a33382a9b"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="a9a70780b9fd8468d98a7c107ee67d8d8"><a name="a9a70780b9fd8468d98a7c107ee67d8d8"></a><a name="a9a70780b9fd8468d98a7c107ee67d8d8"></a>$def</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="ace202d9f2dd547c8ab8693954af5d616"><a name="ace202d9f2dd547c8ab8693954af5d616"></a><a name="ace202d9f2dd547c8ab8693954af5d616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="a08a4d55b01864b2fa866f6431cd322de"><a name="a08a4d55b01864b2fa866f6431cd322de"></a><a name="a08a4d55b01864b2fa866f6431cd322de"></a>使用this.$app.$def获取在app.js中暴露的对象。</p>
    <div class="note" id="note23038122918"><a name="note23038122918"></a><a name="note23038122918"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p73038121790"><a name="p73038121790"></a><a name="p73038121790"></a>应用对象不支持数据绑定，需主动触发UI更新。</p>
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

    <a name="table8514281151"></a>
    <table><thead align="left"><tr id="row2511928359"><th class="cellrowborder" valign="top" width="16.36%" id="mcps1.1.4.1.1"><p id="p1951028754"><a name="p1951028754"></a><a name="p1951028754"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.54%" id="mcps1.1.4.1.2"><p id="p1351228252"><a name="p1351228252"></a><a name="p1351228252"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.10000000000001%" id="mcps1.1.4.1.3"><p id="p651112815519"><a name="p651112815519"></a><a name="p651112815519"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1651228855"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p115421323762"><a name="p115421323762"></a><a name="p115421323762"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p05120283516"><a name="p05120283516"></a><a name="p05120283516"></a>Object/Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p61056578507"><a name="p61056578507"></a><a name="p61056578507"></a>页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for, if, show, tid。</p>
    <p id="p95116281350"><a name="p95116281350"></a><a name="p95116281350"></a>data与private和public不能重合使用。</p>
    </td>
    </tr>
    <tr id="row2991343201512"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p1873818536545"><a name="p1873818536545"></a><a name="p1873818536545"></a>$refs</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p1073815318541"><a name="p1073815318541"></a><a name="p1073815318541"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p7879941512"><a name="p7879941512"></a><a name="p7879941512"></a>持有注册过ref 属性的DOM元素或子组件实例的对象。示例见<a href="#section1560185062215">获取DOM元素</a>。</p>
    </td>
    </tr>
    <tr id="row340610191094"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p240712191998"><a name="p240712191998"></a><a name="p240712191998"></a>private</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p1840710194916"><a name="p1840710194916"></a><a name="p1840710194916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p17407161911917"><a name="p17407161911917"></a><a name="p17407161911917"></a>页面的数据模型，private下的数据属性只能由当前页面修改。</p>
    </td>
    </tr>
    <tr id="row594316386514"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p99441138554"><a name="p99441138554"></a><a name="p99441138554"></a>public</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p994419381151"><a name="p994419381151"></a><a name="p994419381151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p2094418381153"><a name="p2094418381153"></a><a name="p2094418381153"></a>页面的数据模型，public下的数据属性的行为与data保持一致。</p>
    </td>
    </tr>
    <tr id="row638815278598"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p139903755910"><a name="p139903755910"></a><a name="p139903755910"></a>props</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p4258153555911"><a name="p4258153555911"></a><a name="p4258153555911"></a>Array/Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p12388227105918"><a name="p12388227105918"></a><a name="p12388227105918"></a>props用于组件之间的通信，可以通过&lt;tag xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for, if, show, tid。目前props的数据类型不支持Function。示例见<a href="js-components-custom-props.md">自定义组件</a>。</p>
    </td>
    </tr>
    <tr id="row14421201293417"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.4.1.1 "><p id="p144221012173416"><a name="p144221012173416"></a><a name="p144221012173416"></a>computed</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.2 "><p id="p164221412163412"><a name="p164221412163412"></a><a name="p164221412163412"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.10000000000001%" headers="mcps1.1.4.1.3 "><p id="p6422712153413"><a name="p6422712153413"></a><a name="p6422712153413"></a>用于在读取或设置进行预先处理，计算属性的结果会被缓存。计算属性名不能以$或_开头，不要使用保留字。示例见<a href="js-components-custom-props.md">自定义组件</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="s4e1ff24ec78e41948502d8977d24e44c"></a>

-   数据方法

    <a name="td998a97f34c44c86876d2e1aee646bc6"></a>
    <table><thead align="left"><tr id="r41906fbf818041e089ab60c9d410de72"><th class="cellrowborder" valign="top" width="11.361136113611362%" id="mcps1.1.4.1.1"><p id="a44385457c0224b7aa0af4b8aaa5fec41"><a name="a44385457c0224b7aa0af4b8aaa5fec41"></a><a name="a44385457c0224b7aa0af4b8aaa5fec41"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.53165316531653%" id="mcps1.1.4.1.2"><p id="a21e0645662414f9893af7ff3a6e24e92"><a name="a21e0645662414f9893af7ff3a6e24e92"></a><a name="a21e0645662414f9893af7ff3a6e24e92"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.10721072107211%" id="mcps1.1.4.1.3"><p id="add5a5e57df3a4d47a09a8f3ef2a28088"><a name="add5a5e57df3a4d47a09a8f3ef2a28088"></a><a name="add5a5e57df3a4d47a09a8f3ef2a28088"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="rcba2037b58704ed9bef75b912b96eb80"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="a75bccc07529343469aad71db98e70b1a"><a name="a75bccc07529343469aad71db98e70b1a"></a><a name="a75bccc07529343469aad71db98e70b1a"></a>$set</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="a53419b7e4fde4993b3ab35ad3312c4da"><a name="a53419b7e4fde4993b3ab35ad3312c4da"></a><a name="a53419b7e4fde4993b3ab35ad3312c4da"></a>key: string, value: any</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="p84781851442"><a name="p84781851442"></a><a name="p84781851442"></a>添加新的数据属性或者修改已有数据属性。</p>
    <p id="ae55e2b1d9401454c8555cbb419068829"><a name="ae55e2b1d9401454c8555cbb419068829"></a><a name="ae55e2b1d9401454c8555cbb419068829"></a>用法：</p>
    <p id="a266dfd3b1b384811b4e7d9a39350e3bc"><a name="a266dfd3b1b384811b4e7d9a39350e3bc"></a><a name="a266dfd3b1b384811b4e7d9a39350e3bc"></a>this.$set('key',value)：添加数据属性。</p>
    </td>
    </tr>
    <tr id="r189d027189d842a1baf1a5d91a9af901"><td class="cellrowborder" valign="top" width="11.361136113611362%" headers="mcps1.1.4.1.1 "><p id="a4ee9a900fc454f66a628f210f2e50548"><a name="a4ee9a900fc454f66a628f210f2e50548"></a><a name="a4ee9a900fc454f66a628f210f2e50548"></a>$delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.53165316531653%" headers="mcps1.1.4.1.2 "><p id="a2e9d28b0f19d4cabbcc1b464bbd9993a"><a name="a2e9d28b0f19d4cabbcc1b464bbd9993a"></a><a name="a2e9d28b0f19d4cabbcc1b464bbd9993a"></a>key: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.10721072107211%" headers="mcps1.1.4.1.3 "><p id="p18897453134313"><a name="p18897453134313"></a><a name="p18897453134313"></a>删除数据属性。</p>
    <p id="a1e9c2271da5e4cd89dcd6b73c1b3b69d"><a name="a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a><a name="a1e9c2271da5e4cd89dcd6b73c1b3b69d"></a>用法：</p>
    <p id="a628cc2f32b9247b091f5d37ab0a58fdb"><a name="a628cc2f32b9247b091f5d37ab0a58fdb"></a><a name="a628cc2f32b9247b091f5d37ab0a58fdb"></a>this.$delete('key')：删除数据属性。</p>
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

    <a name="te12ef71dd85347738d3670aaa9934476"></a>
    <table><thead align="left"><tr id="r7c071c236183461dbd8e78bce0073401"><th class="cellrowborder" valign="top" width="13.469999999999999%" id="mcps1.1.4.1.1"><p id="a4abb4994ac12403f88c36b8b34a739ec"><a name="a4abb4994ac12403f88c36b8b34a739ec"></a><a name="a4abb4994ac12403f88c36b8b34a739ec"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.91%" id="mcps1.1.4.1.2"><p id="aeac2f3bdee564731ace449ab67008c2c"><a name="aeac2f3bdee564731ace449ab67008c2c"></a><a name="aeac2f3bdee564731ace449ab67008c2c"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.62%" id="mcps1.1.4.1.3"><p id="af669c9f192954747ba61f011dcb6b1c7"><a name="af669c9f192954747ba61f011dcb6b1c7"></a><a name="af669c9f192954747ba61f011dcb6b1c7"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r786add9633394d2f8d72020f28465c87"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a6cce84705d514809ac0511d69f5605e1"><a name="a6cce84705d514809ac0511d69f5605e1"></a><a name="a6cce84705d514809ac0511d69f5605e1"></a>$element</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="ad13b3f17bec14af0859875ac75376e14"><a name="ad13b3f17bec14af0859875ac75376e14"></a><a name="ad13b3f17bec14af0859875ac75376e14"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p103681425164412"><a name="p103681425164412"></a><a name="p103681425164412"></a>获得指定id的组件对象，如果无指定id，则返回根组件对象。示例见<a href="#section1560185062215">获取DOM元素</a>。</p>
    <p id="a49e65fad6f094d049706c2514e8a47a9"><a name="a49e65fad6f094d049706c2514e8a47a9"></a><a name="a49e65fad6f094d049706c2514e8a47a9"></a>用法：</p>
    <p id="a7e59962ba3154456be9a71581364ce92"><a name="a7e59962ba3154456be9a71581364ce92"></a><a name="a7e59962ba3154456be9a71581364ce92"></a>&lt;div id='xxx'&gt;&lt;/div&gt;</p>
    <a name="u338f4836774844dcbeba6ee5218a1151"></a><a name="u338f4836774844dcbeba6ee5218a1151"></a><ul id="u338f4836774844dcbeba6ee5218a1151"><li>this.$element('xxx')：获得id为xxx的组件对象。</li><li>this.$element()：获得根组件对象。</li></ul>
    </td>
    </tr>
    <tr id="row1276482485914"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="p476514248597"><a name="p476514248597"></a><a name="p476514248597"></a>$rootElement</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="p107653240596"><a name="p107653240596"></a><a name="p107653240596"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p137655241599"><a name="p137655241599"></a><a name="p137655241599"></a>获取根组件对象。</p>
    <p id="p0499149904"><a name="p0499149904"></a><a name="p0499149904"></a>用法：this.$rootElement().scrollTo({ duration: 500, position: 300 }), 页面在500ms内滚动300px。</p>
    </td>
    </tr>
    <tr id="re1d5191790fb423282a8c381b317e0e6"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a87cad2551d564814a85a0459673a967c"><a name="a87cad2551d564814a85a0459673a967c"></a><a name="a87cad2551d564814a85a0459673a967c"></a>$root</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="aad1f4153e71544fb8b4e25d08e3787ca"><a name="aad1f4153e71544fb8b4e25d08e3787ca"></a><a name="aad1f4153e71544fb8b4e25d08e3787ca"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="aff829908cf8d49948c1e736e4a88e3ac"><a name="aff829908cf8d49948c1e736e4a88e3ac"></a><a name="aff829908cf8d49948c1e736e4a88e3ac"></a>获得顶级ViewModel实例。<a href="#section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="rd577efbcfc104ac2b5bed88fc9dd0cfb"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a680ff354c19f4d67a88b6eb45203b6d4"><a name="a680ff354c19f4d67a88b6eb45203b6d4"></a><a name="a680ff354c19f4d67a88b6eb45203b6d4"></a>$parent</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="aae2cc49b962347fba8f7dc43a1a6e072"><a name="aae2cc49b962347fba8f7dc43a1a6e072"></a><a name="aae2cc49b962347fba8f7dc43a1a6e072"></a>无</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="af3075c6896404f13a5c93929aa713125"><a name="af3075c6896404f13a5c93929aa713125"></a><a name="af3075c6896404f13a5c93929aa713125"></a>获得父级ViewModel实例。<a href="#section13798143717421">获取ViewModel</a>示例。</p>
    </td>
    </tr>
    <tr id="rb96318b2fb9e4e8ea74dfb280e8fb804"><td class="cellrowborder" valign="top" width="13.469999999999999%" headers="mcps1.1.4.1.1 "><p id="a31ac11bf6d6b477cbc1fb446d5207d0d"><a name="a31ac11bf6d6b477cbc1fb446d5207d0d"></a><a name="a31ac11bf6d6b477cbc1fb446d5207d0d"></a>$child</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.91%" headers="mcps1.1.4.1.2 "><p id="a7ea3339724db43a0b0ba574ac621f83e"><a name="a7ea3339724db43a0b0ba574ac621f83e"></a><a name="a7ea3339724db43a0b0ba574ac621f83e"></a>id: string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.62%" headers="mcps1.1.4.1.3 "><p id="p999210407446"><a name="p999210407446"></a><a name="p999210407446"></a>获得指定id的子级自定义组件的ViewModel实例。<a href="#section13798143717421">获取ViewModel</a>示例。</p>
    <p id="p112537114516"><a name="p112537114516"></a><a name="p112537114516"></a>用法：</p>
    <p id="a39f9c0db073641e5bcbcfc824769ae61"><a name="a39f9c0db073641e5bcbcfc824769ae61"></a><a name="a39f9c0db073641e5bcbcfc824769ae61"></a>this.$child('xxx') ：获取id为xxx的子级自定义组件的ViewModel实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   事件方法

    <a name="table106771249184219"></a>
    <table><thead align="left"><tr id="row66781249104214"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="p15678249144218"><a name="p15678249144218"></a><a name="p15678249144218"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="p17678049114213"><a name="p17678049114213"></a><a name="p17678049114213"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="p26786495424"><a name="p26786495424"></a><a name="p26786495424"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row267864944212"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="p067834919421"><a name="p067834919421"></a><a name="p067834919421"></a>$watch</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="p11678194920424"><a name="p11678194920424"></a><a name="p11678194920424"></a>data: string, callback: string | Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="p1678104913426"><a name="p1678104913426"></a><a name="p1678104913426"></a>观察data中的属性变化，如果属性值改变，触发绑定的事件。示例见<a href="js-components-custom-props.md">自定义组件</a>。</p>
    <p id="p174621629124617"><a name="p174621629124617"></a><a name="p174621629124617"></a>用法：</p>
    <p id="p1173814312460"><a name="p1173814312460"></a><a name="p1173814312460"></a>this.$watch('key', callback)</p>
    </td>
    </tr>
    </tbody>
    </table>

-   页面方法

    <a name="table4927155523714"></a>
    <table><thead align="left"><tr id="row4927255113714"><th class="cellrowborder" valign="top" width="13.28%" id="mcps1.1.4.1.1"><p id="p192765520376"><a name="p192765520376"></a><a name="p192765520376"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.29%" id="mcps1.1.4.1.2"><p id="p1192715550377"><a name="p1192715550377"></a><a name="p1192715550377"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.43%" id="mcps1.1.4.1.3"><p id="p49275555370"><a name="p49275555370"></a><a name="p49275555370"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1692716552379"><td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.1.4.1.1 "><p id="p199274556371"><a name="p199274556371"></a><a name="p199274556371"></a>scrollTo<sup id="sup17224503390"><a name="sup17224503390"></a><a name="sup17224503390"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="35.29%" headers="mcps1.1.4.1.2 "><p id="p792745512375"><a name="p792745512375"></a><a name="p792745512375"></a>scrollPageParam: <a href="#table131981833173916">ScrollPageParam</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="51.43%" headers="mcps1.1.4.1.3 "><p id="p1292735517377"><a name="p1292735517377"></a><a name="p1292735517377"></a>将页面滚动到目标位置，可以通过ID选择器指定或者滚动距离指定。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  ScrollPageParam<sup>6+</sup>

    <a name="table131981833173916"></a>
    <table><thead align="left"><tr id="row31992331399"><th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.1"><p id="p16199113383917"><a name="p16199113383917"></a><a name="p16199113383917"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.45745425457454%" id="mcps1.2.5.1.2"><p id="p519953314398"><a name="p519953314398"></a><a name="p519953314398"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.88871112888711%" id="mcps1.2.5.1.3"><p id="p556391215143"><a name="p556391215143"></a><a name="p556391215143"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.826917308269174%" id="mcps1.2.5.1.4"><p id="p19199163393916"><a name="p19199163393916"></a><a name="p19199163393916"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12199173303914"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p8199203363916"><a name="p8199203363916"></a><a name="p8199203363916"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p11991833133916"><a name="p11991833133916"></a><a name="p11991833133916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p115641312111410"><a name="p115641312111410"></a><a name="p115641312111410"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1319943319395"><a name="p1319943319395"></a><a name="p1319943319395"></a>指定滚动位置。</p>
    </td>
    </tr>
    <tr id="row161991633143919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p41991333163919"><a name="p41991333163919"></a><a name="p41991333163919"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p1619918334392"><a name="p1619918334392"></a><a name="p1619918334392"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p756451219146"><a name="p756451219146"></a><a name="p756451219146"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1419943363915"><a name="p1419943363915"></a><a name="p1419943363915"></a>指定需要滚动到的元素id。</p>
    </td>
    </tr>
    <tr id="row191992033183919"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p1919993316390"><a name="p1919993316390"></a><a name="p1919993316390"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p9199183363916"><a name="p9199183363916"></a><a name="p9199183363916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p5564181218144"><a name="p5564181218144"></a><a name="p5564181218144"></a>300</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p3199233133920"><a name="p3199233133920"></a><a name="p3199233133920"></a>指定滚动时长，单位为毫秒。</p>
    </td>
    </tr>
    <tr id="row2019933315396"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p13199733133915"><a name="p13199733133915"></a><a name="p13199733133915"></a>timingFunction</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p0199173373919"><a name="p0199173373919"></a><a name="p0199173373919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p10564171212141"><a name="p10564171212141"></a><a name="p10564171212141"></a>ease</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1919903313394"><a name="p1919903313394"></a><a name="p1919903313394"></a>指定滚动动画曲线，可选值参考</p>
    <p id="p158650537712"><a name="p158650537712"></a><a name="p158650537712"></a><a href="js-components-common-animation.md">animation-timing-function</a>。</p>
    </td>
    </tr>
    <tr id="row110635616428"><td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.1 "><p id="p6107856124211"><a name="p6107856124211"></a><a name="p6107856124211"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.45745425457454%" headers="mcps1.2.5.1.2 "><p id="p20107195674214"><a name="p20107195674214"></a><a name="p20107195674214"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.88871112888711%" headers="mcps1.2.5.1.3 "><p id="p20564151211419"><a name="p20564151211419"></a><a name="p20564151211419"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.826917308269174%" headers="mcps1.2.5.1.4 "><p id="p1107155694210"><a name="p1107155694210"></a><a name="p1107155694210"></a>指定滚动完成后需要执行的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    示例：

    ```
    this.$rootElement.scrollTo({position: 0})
    this.$rootElement.scrollTo({id: 'id', duration: 200, timingFunction: 'ease-in', complete: ()=>void})
    ```


## 获取DOM元素<a name="section1560185062215"></a>

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


## 获取ViewModel<a name="section13798143717421"></a>

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


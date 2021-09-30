# 页面路由<a name="ZH-CN_TOPIC_0000001209412149"></a>

-   [导入模块](#zh-cn_topic_0000001127125008_s0e7b1e85a4274f58a8206e0b065bd80c)
-   [权限列表](#zh-cn_topic_0000001127125008_section11257113618419)
-   [router.push](#zh-cn_topic_0000001127125008_s938bf8d664f9475485e83d445c0eeeae)
-   [router.replace](#zh-cn_topic_0000001127125008_s6d485e6ae3064996a4de2f407bc4287d)
-   [router.back](#zh-cn_topic_0000001127125008_s3f958a02dde141e69b7f02f22fb2e401)
-   [router.clear](#zh-cn_topic_0000001127125008_sa5c3dfd1bb0d4b43906c3d770d6ab2d9)
-   [router.getLength](#zh-cn_topic_0000001127125008_s3f121f4005934fda9a1830a909c92c25)
-   [router.getState](#zh-cn_topic_0000001127125008_s8843a443a12048e68e33f586aee8dc34)
-   [router.enableAlertBeforeBackPage6+](#zh-cn_topic_0000001127125008_section54535465226)
-   [router.disableAlertBeforeBackPage6+](#zh-cn_topic_0000001127125008_section08671236103317)

>![](../../public_sys-resources/icon-notice.gif) **须知：** 
>页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。

## 导入模块<a name="zh-cn_topic_0000001127125008_s0e7b1e85a4274f58a8206e0b065bd80c"></a>

```
import router from '@system.router';
```

## 权限列表<a name="zh-cn_topic_0000001127125008_section11257113618419"></a>

无

## router.push<a name="zh-cn_topic_0000001127125008_s938bf8d664f9475485e83d445c0eeeae"></a>

push\(Object\): void

跳转到应用内的指定页面。

-   参数

    <a name="zh-cn_topic_0000001127125008_t382f5b6619614d1b91de120862492040"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_r6739653f3ffd40a78caee6fdbf769957"><th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125008_a9c0eb79224544625b5727db432b60400"><a name="zh-cn_topic_0000001127125008_a9c0eb79224544625b5727db432b60400"></a><a name="zh-cn_topic_0000001127125008_a9c0eb79224544625b5727db432b60400"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.33%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125008_adde2d39df4c94fa6a0cd5d789edcb54c"><a name="zh-cn_topic_0000001127125008_adde2d39df4c94fa6a0cd5d789edcb54c"></a><a name="zh-cn_topic_0000001127125008_adde2d39df4c94fa6a0cd5d789edcb54c"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.03%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125008_a2413542f57b8404f9608a8fd82389d58"><a name="zh-cn_topic_0000001127125008_a2413542f57b8404f9608a8fd82389d58"></a><a name="zh-cn_topic_0000001127125008_a2413542f57b8404f9608a8fd82389d58"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="68.49%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125008_abb0e5e4afbab40679842c9fd5d3059a7"><a name="zh-cn_topic_0000001127125008_abb0e5e4afbab40679842c9fd5d3059a7"></a><a name="zh-cn_topic_0000001127125008_abb0e5e4afbab40679842c9fd5d3059a7"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_re4567a735be2433c92768a242fb60d3e"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_a7df856838e2f40b7825eea82b992e1bb"><a name="zh-cn_topic_0000001127125008_a7df856838e2f40b7825eea82b992e1bb"></a><a name="zh-cn_topic_0000001127125008_a7df856838e2f40b7825eea82b992e1bb"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_a7b29f6b362f94f9d94c43a1974a183bf"><a name="zh-cn_topic_0000001127125008_a7b29f6b362f94f9d94c43a1974a183bf"></a><a name="zh-cn_topic_0000001127125008_a7b29f6b362f94f9d94c43a1974a183bf"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.03%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_a5f2b65a2289c46fdb759d2bd154aa414"><a name="zh-cn_topic_0000001127125008_a5f2b65a2289c46fdb759d2bd154aa414"></a><a name="zh-cn_topic_0000001127125008_a5f2b65a2289c46fdb759d2bd154aa414"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="68.49%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_a7c61031878fe4accae87a2f6c74b3b89"><a name="zh-cn_topic_0000001127125008_a7c61031878fe4accae87a2f6c74b3b89"></a><a name="zh-cn_topic_0000001127125008_a7c61031878fe4accae87a2f6c74b3b89"></a>表示目标页面的uri，可以用以下两种格式：</p>
    <a name="zh-cn_topic_0000001127125008_ul1495111211908"></a><a name="zh-cn_topic_0000001127125008_ul1495111211908"></a><ul id="zh-cn_topic_0000001127125008_ul1495111211908"><li>页面绝对路径，由配置文件中pages列表提供，例如：<a name="zh-cn_topic_0000001127125008_ul067818331541"></a><a name="zh-cn_topic_0000001127125008_ul067818331541"></a><ul id="zh-cn_topic_0000001127125008_ul067818331541"><li>pages/index/index</li><li>pages/detail/detail</li></ul>
    </li><li>特殊值，如果uri的值是"/"，则跳转到首页。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row1411921117196"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p172681322102310"><a name="zh-cn_topic_0000001127125008_p172681322102310"></a><a name="zh-cn_topic_0000001127125008_p172681322102310"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p0268102210236"><a name="zh-cn_topic_0000001127125008_p0268102210236"></a><a name="zh-cn_topic_0000001127125008_p0268102210236"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.03%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p8268132242318"><a name="zh-cn_topic_0000001127125008_p8268132242318"></a><a name="zh-cn_topic_0000001127125008_p8268132242318"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="68.49%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p13268162222310"><a name="zh-cn_topic_0000001127125008_p13268162222310"></a><a name="zh-cn_topic_0000001127125008_p13268162222310"></a>跳转时要同时传递到目标页面的数据，跳转到目标页面后，参数可以在页面中直接使用，如this.data1(data1为跳转时params参数中的key值)。如果目标页面中已有该字段，则其值会被传入的字段值覆盖。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // 在当前页面中
    export default {
      pushPage() {
        router.push({
          uri: 'pages/routerpage2/routerpage2',
          params: {
    	data1: 'message',
            data2: {
              data3: [123, 456, 789]
    	},
          },
        });
      }
    }
    // 在routerpage2页面中
    export default {
      data: {
        data1: 'default',
        data2: {
          data3: [1, 2, 3]
        }
      },
      onInit() {
        console.info('showData1:' + this.data1);
        console.info('showData3:' + this.data2.data3);
      }
    }
    ```

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >页面路由栈支持的最大Page数量为32。


## router.replace<a name="zh-cn_topic_0000001127125008_s6d485e6ae3064996a4de2f407bc4287d"></a>

replace\(Object\): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

-   参数

    <a name="zh-cn_topic_0000001127125008_t6b1726948831437cb2fabab6c2596bd6"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_rbac962f43cbb4e6da29b30573fcaf9f5"><th class="cellrowborder" valign="top" width="8%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125008_a16d15d7a316a40b19b98fbf3e709b198"><a name="zh-cn_topic_0000001127125008_a16d15d7a316a40b19b98fbf3e709b198"></a><a name="zh-cn_topic_0000001127125008_a16d15d7a316a40b19b98fbf3e709b198"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.040000000000001%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125008_aede000ddf8d44cf3ac35d395531daa72"><a name="zh-cn_topic_0000001127125008_aede000ddf8d44cf3ac35d395531daa72"></a><a name="zh-cn_topic_0000001127125008_aede000ddf8d44cf3ac35d395531daa72"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.959999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125008_af57857a2931e4bae9e1c01e953586b93"><a name="zh-cn_topic_0000001127125008_af57857a2931e4bae9e1c01e953586b93"></a><a name="zh-cn_topic_0000001127125008_af57857a2931e4bae9e1c01e953586b93"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="72%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125008_a69477f180eb04f92be9c7bfad4ea1a22"><a name="zh-cn_topic_0000001127125008_a69477f180eb04f92be9c7bfad4ea1a22"></a><a name="zh-cn_topic_0000001127125008_a69477f180eb04f92be9c7bfad4ea1a22"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_r907dc0ee7ae94b3aa4f42508bee0c51f"><td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_a61f128e79b3d4b6080143f140d8a6f5a"><a name="zh-cn_topic_0000001127125008_a61f128e79b3d4b6080143f140d8a6f5a"></a><a name="zh-cn_topic_0000001127125008_a61f128e79b3d4b6080143f140d8a6f5a"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_aa6161c953b2d4cacb770343bbc7a76b9"><a name="zh-cn_topic_0000001127125008_aa6161c953b2d4cacb770343bbc7a76b9"></a><a name="zh-cn_topic_0000001127125008_aa6161c953b2d4cacb770343bbc7a76b9"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"><a name="zh-cn_topic_0000001127125008_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"></a><a name="zh-cn_topic_0000001127125008_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="72%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_ae5f1acce286d407896f0da896d170c60"><a name="zh-cn_topic_0000001127125008_ae5f1acce286d407896f0da896d170c60"></a><a name="zh-cn_topic_0000001127125008_ae5f1acce286d407896f0da896d170c60"></a>目标页面的uri，可以是以下的两种格式：</p>
    <a name="zh-cn_topic_0000001127125008_ul15140171014517"></a><a name="zh-cn_topic_0000001127125008_ul15140171014517"></a><ul id="zh-cn_topic_0000001127125008_ul15140171014517"><li>页面绝对路径，由配置文件中pages列表提供，例如：<a name="zh-cn_topic_0000001127125008_ul15140810655"></a><a name="zh-cn_topic_0000001127125008_ul15140810655"></a><ul id="zh-cn_topic_0000001127125008_ul15140810655"><li>pages/index/index</li><li>pages/detail/detail</li></ul>
    </li><li>特殊值，如果uri的值是"/"，则跳转到首页。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row43841058103012"><td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p39929943120"><a name="zh-cn_topic_0000001127125008_p39929943120"></a><a name="zh-cn_topic_0000001127125008_p39929943120"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p899219153118"><a name="zh-cn_topic_0000001127125008_p899219153118"></a><a name="zh-cn_topic_0000001127125008_p899219153118"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.959999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p29920903113"><a name="zh-cn_topic_0000001127125008_p29920903113"></a><a name="zh-cn_topic_0000001127125008_p29920903113"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="72%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p2143918144613"><a name="zh-cn_topic_0000001127125008_p2143918144613"></a><a name="zh-cn_topic_0000001127125008_p2143918144613"></a>跳转时要同时传递到目标页面的数据，跳转到目标页面后，参数可以在页面中直接使用，如this.data1(data1为跳转时params参数中的key值)。如果目标页面中已有该字段，则其值会被传入的字段值覆盖。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // 在当前页面中
    export default {
      replacePage() {
        router.replace({
          uri: 'pages/detail/detail',
          params: {
            data1: 'message',
          },
        });
      }
    }
    // 在detail页面中
    export default {
      data: {
        data1: 'default'
      },
      onInit() {
        console.info('showData1:' + this.data1)
      }
    }
    ```


## router.back<a name="zh-cn_topic_0000001127125008_s3f958a02dde141e69b7f02f22fb2e401"></a>

back\(Object\): void

返回上一页面或指定的页面。

-   参数

    <a name="zh-cn_topic_0000001127125008_t8645be119aea4edc9abfe4ac4b1a5457"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_r03b6547f30ab4ad898fe0604563e416f"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125008_a576cd1b8452644d8942cd1c1f478afa4"><a name="zh-cn_topic_0000001127125008_a576cd1b8452644d8942cd1c1f478afa4"></a><a name="zh-cn_topic_0000001127125008_a576cd1b8452644d8942cd1c1f478afa4"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125008_a13d651d4875643ccbcf890ad49a82bdf"><a name="zh-cn_topic_0000001127125008_a13d651d4875643ccbcf890ad49a82bdf"></a><a name="zh-cn_topic_0000001127125008_a13d651d4875643ccbcf890ad49a82bdf"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125008_a114a9b21dba74aaba51710352c28b128"><a name="zh-cn_topic_0000001127125008_a114a9b21dba74aaba51710352c28b128"></a><a name="zh-cn_topic_0000001127125008_a114a9b21dba74aaba51710352c28b128"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125008_a536b7faf84754ec9875bd10c5b1bd9ff"><a name="zh-cn_topic_0000001127125008_a536b7faf84754ec9875bd10c5b1bd9ff"></a><a name="zh-cn_topic_0000001127125008_a536b7faf84754ec9875bd10c5b1bd9ff"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_r121c662a232e4152ba0a678cb7ccc5a9"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_acca6b999d1fb40b28ee2f82f636aef65"><a name="zh-cn_topic_0000001127125008_acca6b999d1fb40b28ee2f82f636aef65"></a><a name="zh-cn_topic_0000001127125008_acca6b999d1fb40b28ee2f82f636aef65"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_a58c83b28fb4649df96c79f922bdb81f3"><a name="zh-cn_topic_0000001127125008_a58c83b28fb4649df96c79f922bdb81f3"></a><a name="zh-cn_topic_0000001127125008_a58c83b28fb4649df96c79f922bdb81f3"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_aff1dee2aad364012ae008c45a9a36392"><a name="zh-cn_topic_0000001127125008_aff1dee2aad364012ae008c45a9a36392"></a><a name="zh-cn_topic_0000001127125008_aff1dee2aad364012ae008c45a9a36392"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_adf355f87a6e545a3b5cdcd5e78fcd8b3"><a name="zh-cn_topic_0000001127125008_adf355f87a6e545a3b5cdcd5e78fcd8b3"></a><a name="zh-cn_topic_0000001127125008_adf355f87a6e545a3b5cdcd5e78fcd8b3"></a>返回到指定uri的界面，如果页面栈上没有uri页面，则不响应该情况。如果uri未设置，则返回上一页。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // index页面
    router.push({
      uri: 'pages/detail/detail',
    });
    
    // detail页面
    router.push({
      uri: 'pages/mall/mall',
    });
    
    // mall页面通过back，将返回detail页面
    router.back();
    // detail页面通过back，将返回index页面
    router.back();
    // 通过back，返回到detail页面
    router.back({uri:'pages/detail/detail'});
    ```

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >示例中的uri字段是页面路由，由配置文件中的pages列表指定。


## router.clear<a name="zh-cn_topic_0000001127125008_sa5c3dfd1bb0d4b43906c3d770d6ab2d9"></a>

clear\(\): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

-   示例

    ```
    router.clear();
    ```


## router.getLength<a name="zh-cn_topic_0000001127125008_s3f121f4005934fda9a1830a909c92c25"></a>

getLength\(\): string

获取当前在页面栈内的页面数量。

-   返回值

    <a name="zh-cn_topic_0000001127125008_t69833877986140cbb7fc7a25b411622b"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_rad0dfd50874c4a9e8509cc0661ecc869"><th class="cellrowborder" valign="top" width="12.920000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001127125008_add584a11aa0e49928b79176951aa21e1"><a name="zh-cn_topic_0000001127125008_add584a11aa0e49928b79176951aa21e1"></a><a name="zh-cn_topic_0000001127125008_add584a11aa0e49928b79176951aa21e1"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.08%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001127125008_af65e00289a1f4616861727b28ffc14f2"><a name="zh-cn_topic_0000001127125008_af65e00289a1f4616861727b28ffc14f2"></a><a name="zh-cn_topic_0000001127125008_af65e00289a1f4616861727b28ffc14f2"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_r12b8d9cc2831480e8f0f16bd0e992b30"><td class="cellrowborder" valign="top" width="12.920000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001127125008_ae731080460894a68b064fba7c893c1e8"><a name="zh-cn_topic_0000001127125008_ae731080460894a68b064fba7c893c1e8"></a><a name="zh-cn_topic_0000001127125008_ae731080460894a68b064fba7c893c1e8"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.08%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001127125008_affc1140bcdf940de8705c921ccd68da5"><a name="zh-cn_topic_0000001127125008_affc1140bcdf940de8705c921ccd68da5"></a><a name="zh-cn_topic_0000001127125008_affc1140bcdf940de8705c921ccd68da5"></a>页面数量，页面栈支持最大数值是32。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var size = router.getLength();
    console.log('pages stack size = ' + size);
    ```


## router.getState<a name="zh-cn_topic_0000001127125008_s8843a443a12048e68e33f586aee8dc34"></a>

getState\(\): <[RouterState](#zh-cn_topic_0000001127125008_tf9e3eb9ef0aa4d9880f996fe6afa6d1b)\>

获取当前页面的状态信息。

-   返回值

    **表 1**  RouterState

    <a name="zh-cn_topic_0000001127125008_tf9e3eb9ef0aa4d9880f996fe6afa6d1b"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_redea81f1cfff4122b733df3049d3d8ba"><th class="cellrowborder" valign="top" width="11%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125008_ac1f54204219e42e58810bacc1e221e3c"><a name="zh-cn_topic_0000001127125008_ac1f54204219e42e58810bacc1e221e3c"></a><a name="zh-cn_topic_0000001127125008_ac1f54204219e42e58810bacc1e221e3c"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125008_a811d9c5a5a2e402bb2d429d14e07af79"><a name="zh-cn_topic_0000001127125008_a811d9c5a5a2e402bb2d429d14e07af79"></a><a name="zh-cn_topic_0000001127125008_a811d9c5a5a2e402bb2d429d14e07af79"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125008_ab0d65ba7195a4b6aa51a1c8be829da4b"><a name="zh-cn_topic_0000001127125008_ab0d65ba7195a4b6aa51a1c8be829da4b"></a><a name="zh-cn_topic_0000001127125008_ab0d65ba7195a4b6aa51a1c8be829da4b"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_r654e450f29d34ba2a43c4baf828242bc"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125008_aa5d3616785ec46b88eab2b7a0c97c4e3"><a name="zh-cn_topic_0000001127125008_aa5d3616785ec46b88eab2b7a0c97c4e3"></a><a name="zh-cn_topic_0000001127125008_aa5d3616785ec46b88eab2b7a0c97c4e3"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125008_aaa82d880dc7d4221b2a65a202a0b34b4"><a name="zh-cn_topic_0000001127125008_aaa82d880dc7d4221b2a65a202a0b34b4"></a><a name="zh-cn_topic_0000001127125008_aaa82d880dc7d4221b2a65a202a0b34b4"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125008_p1979431135"><a name="zh-cn_topic_0000001127125008_p1979431135"></a><a name="zh-cn_topic_0000001127125008_p1979431135"></a>表示当前页面在页面栈中的索引。</p>
    <div class="note" id="zh-cn_topic_0000001127125008_note136715361314"><a name="zh-cn_topic_0000001127125008_note136715361314"></a><a name="zh-cn_topic_0000001127125008_note136715361314"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125008_p1167137132"><a name="zh-cn_topic_0000001127125008_p1167137132"></a><a name="zh-cn_topic_0000001127125008_p1167137132"></a>从栈底到栈顶，index从1开始递增。</p>
    </div></div>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_r5d033b0d902e4a83aaf66db1902c5154"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125008_ae78d89cb022b4505984ae62d800f246c"><a name="zh-cn_topic_0000001127125008_ae78d89cb022b4505984ae62d800f246c"></a><a name="zh-cn_topic_0000001127125008_ae78d89cb022b4505984ae62d800f246c"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125008_a75e18952ce3a4df3a9dd4af9e20f8df1"><a name="zh-cn_topic_0000001127125008_a75e18952ce3a4df3a9dd4af9e20f8df1"></a><a name="zh-cn_topic_0000001127125008_a75e18952ce3a4df3a9dd4af9e20f8df1"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125008_acf2d1680871b4630b121fc51835d5144"><a name="zh-cn_topic_0000001127125008_acf2d1680871b4630b121fc51835d5144"></a><a name="zh-cn_topic_0000001127125008_acf2d1680871b4630b121fc51835d5144"></a>表示当前页面的名称，即对应文件名。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_ra0e0c300267144a5806efae3aaa498b7"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125008_add88e87efa6242f5a1679e71cf3f31a1"><a name="zh-cn_topic_0000001127125008_add88e87efa6242f5a1679e71cf3f31a1"></a><a name="zh-cn_topic_0000001127125008_add88e87efa6242f5a1679e71cf3f31a1"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125008_a92fb0e8fa14446ea91898b2a8867b2ef"><a name="zh-cn_topic_0000001127125008_a92fb0e8fa14446ea91898b2a8867b2ef"></a><a name="zh-cn_topic_0000001127125008_a92fb0e8fa14446ea91898b2a8867b2ef"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125008_a8f4870ec81224a75b82268b19b7c76de"><a name="zh-cn_topic_0000001127125008_a8f4870ec81224a75b82268b19b7c76de"></a><a name="zh-cn_topic_0000001127125008_a8f4870ec81224a75b82268b19b7c76de"></a>表示当前页面的路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var page = router.getState();
    console.log('current index = ' + page.index);
    console.log('current name = ' + page.name);
    console.log('current path = ' + page.path);
    ```


## router.enableAlertBeforeBackPage<sup>6+</sup><a name="zh-cn_topic_0000001127125008_section54535465226"></a>

enableAlertBeforeBackPage\(Object\): void

开启页面返回询问对话框。

-   参数

    <a name="zh-cn_topic_0000001127125008_table2013713511258"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_row11137651102511"><th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125008_p513895122518"><a name="zh-cn_topic_0000001127125008_p513895122518"></a><a name="zh-cn_topic_0000001127125008_p513895122518"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.73%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125008_p9138195115258"><a name="zh-cn_topic_0000001127125008_p9138195115258"></a><a name="zh-cn_topic_0000001127125008_p9138195115258"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.24%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125008_p191381851162514"><a name="zh-cn_topic_0000001127125008_p191381851162514"></a><a name="zh-cn_topic_0000001127125008_p191381851162514"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.88%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125008_p1513812515252"><a name="zh-cn_topic_0000001127125008_p1513812515252"></a><a name="zh-cn_topic_0000001127125008_p1513812515252"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_row2013875118251"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p19138125119252"><a name="zh-cn_topic_0000001127125008_p19138125119252"></a><a name="zh-cn_topic_0000001127125008_p19138125119252"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p1138751172512"><a name="zh-cn_topic_0000001127125008_p1138751172512"></a><a name="zh-cn_topic_0000001127125008_p1138751172512"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p4138651182517"><a name="zh-cn_topic_0000001127125008_p4138651182517"></a><a name="zh-cn_topic_0000001127125008_p4138651182517"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.88%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p93900438261"><a name="zh-cn_topic_0000001127125008_p93900438261"></a><a name="zh-cn_topic_0000001127125008_p93900438261"></a>询问对话框内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row15138551132517"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p15138451162516"><a name="zh-cn_topic_0000001127125008_p15138451162516"></a><a name="zh-cn_topic_0000001127125008_p15138451162516"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p413845120256"><a name="zh-cn_topic_0000001127125008_p413845120256"></a><a name="zh-cn_topic_0000001127125008_p413845120256"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p16138115122510"><a name="zh-cn_topic_0000001127125008_p16138115122510"></a><a name="zh-cn_topic_0000001127125008_p16138115122510"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.88%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p12138451192519"><a name="zh-cn_topic_0000001127125008_p12138451192519"></a><a name="zh-cn_topic_0000001127125008_p12138451192519"></a>接口调用成功的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row171392051182510"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p511719107271"><a name="zh-cn_topic_0000001127125008_p511719107271"></a><a name="zh-cn_topic_0000001127125008_p511719107271"></a>fail</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p913910518259"><a name="zh-cn_topic_0000001127125008_p913910518259"></a><a name="zh-cn_topic_0000001127125008_p913910518259"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p15139125132515"><a name="zh-cn_topic_0000001127125008_p15139125132515"></a><a name="zh-cn_topic_0000001127125008_p15139125132515"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.88%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p10139165115250"><a name="zh-cn_topic_0000001127125008_p10139165115250"></a><a name="zh-cn_topic_0000001127125008_p10139165115250"></a>接口调用失败的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row1958621632720"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p1858691616275"><a name="zh-cn_topic_0000001127125008_p1858691616275"></a><a name="zh-cn_topic_0000001127125008_p1858691616275"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p10586171622715"><a name="zh-cn_topic_0000001127125008_p10586171622715"></a><a name="zh-cn_topic_0000001127125008_p10586171622715"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p158616166272"><a name="zh-cn_topic_0000001127125008_p158616166272"></a><a name="zh-cn_topic_0000001127125008_p158616166272"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.88%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p15586191613271"><a name="zh-cn_topic_0000001127125008_p15586191613271"></a><a name="zh-cn_topic_0000001127125008_p15586191613271"></a>接口调用结束的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    router.enableAlertBeforeBackPage({
      message: 'Message Info',
      success: function() {
        console.log('success');
      },
      fail: function() {
        console.log('fail');
      },
    });
    ```


## router.disableAlertBeforeBackPage<sup>6+</sup><a name="zh-cn_topic_0000001127125008_section08671236103317"></a>

disableAlertBeforeBackPage\(Object\): void

禁用页面返回询问对话框。

-   参数：

    <a name="zh-cn_topic_0000001127125008_table5868103673314"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125008_row1286810361332"><th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125008_p17868133623319"><a name="zh-cn_topic_0000001127125008_p17868133623319"></a><a name="zh-cn_topic_0000001127125008_p17868133623319"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.96%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125008_p1286853611337"><a name="zh-cn_topic_0000001127125008_p1286853611337"></a><a name="zh-cn_topic_0000001127125008_p1286853611337"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125008_p1386873613319"><a name="zh-cn_topic_0000001127125008_p1386873613319"></a><a name="zh-cn_topic_0000001127125008_p1386873613319"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.11%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125008_p9868103633315"><a name="zh-cn_topic_0000001127125008_p9868103633315"></a><a name="zh-cn_topic_0000001127125008_p9868103633315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125008_row68681236103317"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p38681536103317"><a name="zh-cn_topic_0000001127125008_p38681536103317"></a><a name="zh-cn_topic_0000001127125008_p38681536103317"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p19449194212534"><a name="zh-cn_topic_0000001127125008_p19449194212534"></a><a name="zh-cn_topic_0000001127125008_p19449194212534"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p1686943693314"><a name="zh-cn_topic_0000001127125008_p1686943693314"></a><a name="zh-cn_topic_0000001127125008_p1686943693314"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.11%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p086920362331"><a name="zh-cn_topic_0000001127125008_p086920362331"></a><a name="zh-cn_topic_0000001127125008_p086920362331"></a>接口调用成功的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row0869183673320"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p286913367339"><a name="zh-cn_topic_0000001127125008_p286913367339"></a><a name="zh-cn_topic_0000001127125008_p286913367339"></a>fail</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p54408438532"><a name="zh-cn_topic_0000001127125008_p54408438532"></a><a name="zh-cn_topic_0000001127125008_p54408438532"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p1486923633315"><a name="zh-cn_topic_0000001127125008_p1486923633315"></a><a name="zh-cn_topic_0000001127125008_p1486923633315"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.11%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p138698363338"><a name="zh-cn_topic_0000001127125008_p138698363338"></a><a name="zh-cn_topic_0000001127125008_p138698363338"></a>接口调用失败的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125008_row1186903613336"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125008_p88691236153316"><a name="zh-cn_topic_0000001127125008_p88691236153316"></a><a name="zh-cn_topic_0000001127125008_p88691236153316"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125008_p66221444175316"><a name="zh-cn_topic_0000001127125008_p66221444175316"></a><a name="zh-cn_topic_0000001127125008_p66221444175316"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125008_p3869133633316"><a name="zh-cn_topic_0000001127125008_p3869133633316"></a><a name="zh-cn_topic_0000001127125008_p3869133633316"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.11%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125008_p20869203616332"><a name="zh-cn_topic_0000001127125008_p20869203616332"></a><a name="zh-cn_topic_0000001127125008_p20869203616332"></a>接口调用结束的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    router.disableAlertBeforeBackPage({
      success: function() {
        console.log('success');
      },
      fail: function() {
        console.log('fail');
      },
    });
    ```



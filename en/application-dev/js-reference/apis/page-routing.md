# Page Routing<a name="EN-US_TOPIC_0000001115974762"></a>

> **NOTICE:** 
>Page routing APIs can be invoked only after page rendering is complete. Do not call the APIs in  **onInit**  and  **onReady**  when the page is still in the rendering phase.

## Module to Import<a name="en-us_topic_0000001058340511_s0e7b1e85a4274f58a8206e0b065bd80c"></a>

```
import router from '@system.router';
```

## Permission List<a name="en-us_topic_0000001058340511_section11257113618419"></a>

None

## router.push\(OBJECT\)<a name="en-us_topic_0000001058340511_s938bf8d664f9475485e83d445c0eeeae"></a>

Navigates to a specified page in the application based on the page URL and parameters.

-   Parameter

    <a name="en-us_topic_0000001058340511_t382f5b6619614d1b91de120862492040"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058340511_r6739653f3ffd40a78caee6fdbf769957"><th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058340511_a9c0eb79224544625b5727db432b60400"><a name="en-us_topic_0000001058340511_a9c0eb79224544625b5727db432b60400"></a><a name="en-us_topic_0000001058340511_a9c0eb79224544625b5727db432b60400"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.09%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058340511_adde2d39df4c94fa6a0cd5d789edcb54c"><a name="en-us_topic_0000001058340511_adde2d39df4c94fa6a0cd5d789edcb54c"></a><a name="en-us_topic_0000001058340511_adde2d39df4c94fa6a0cd5d789edcb54c"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.09%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058340511_a2413542f57b8404f9608a8fd82389d58"><a name="en-us_topic_0000001058340511_a2413542f57b8404f9608a8fd82389d58"></a><a name="en-us_topic_0000001058340511_a2413542f57b8404f9608a8fd82389d58"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058340511_abb0e5e4afbab40679842c9fd5d3059a7"><a name="en-us_topic_0000001058340511_abb0e5e4afbab40679842c9fd5d3059a7"></a><a name="en-us_topic_0000001058340511_abb0e5e4afbab40679842c9fd5d3059a7"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058340511_re4567a735be2433c92768a242fb60d3e"><td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058340511_a7df856838e2f40b7825eea82b992e1bb"><a name="en-us_topic_0000001058340511_a7df856838e2f40b7825eea82b992e1bb"></a><a name="en-us_topic_0000001058340511_a7df856838e2f40b7825eea82b992e1bb"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058340511_a7b29f6b362f94f9d94c43a1974a183bf"><a name="en-us_topic_0000001058340511_a7b29f6b362f94f9d94c43a1974a183bf"></a><a name="en-us_topic_0000001058340511_a7b29f6b362f94f9d94c43a1974a183bf"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058340511_a5f2b65a2289c46fdb759d2bd154aa414"><a name="en-us_topic_0000001058340511_a5f2b65a2289c46fdb759d2bd154aa414"></a><a name="en-us_topic_0000001058340511_a5f2b65a2289c46fdb759d2bd154aa414"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058340511_a7c61031878fe4accae87a2f6c74b3b89"><a name="en-us_topic_0000001058340511_a7c61031878fe4accae87a2f6c74b3b89"></a><a name="en-us_topic_0000001058340511_a7c61031878fe4accae87a2f6c74b3b89"></a>URI of the destination page, in either of the following formats:</p>
    <a name="en-us_topic_0000001058340511_ul1495111211908"></a><a name="en-us_topic_0000001058340511_ul1495111211908"></a><ul id="en-us_topic_0000001058340511_ul1495111211908"><li>Absolute path of the page. The value is available in  the <strong id="en-us_topic_0000001058340511_b13087524598"><a name="en-us_topic_0000001058340511_b13087524598"></a><a name="en-us_topic_0000001058340511_b13087524598"></a>pages</strong> list in the <strong id="en-us_topic_0000001058340511_b1031317527590"><a name="en-us_topic_0000001058340511_b1031317527590"></a><a name="en-us_topic_0000001058340511_b1031317527590"></a>config.json</strong> file, for example:<a name="en-us_topic_0000001058340511_ul067818331541"></a><a name="en-us_topic_0000001058340511_ul067818331541"></a><ul id="en-us_topic_0000001058340511_ul067818331541"><li>pages/index/index</li><li>pages/detail/detail</li></ul>
    </li><li>Particular path. If the URI is a slash (/), the home page is displayed.</li></ul>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058340511_row1411921117196"><td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058340511_p172681322102310"><a name="en-us_topic_0000001058340511_p172681322102310"></a><a name="en-us_topic_0000001058340511_p172681322102310"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058340511_p0268102210236"><a name="en-us_topic_0000001058340511_p0268102210236"></a><a name="en-us_topic_0000001058340511_p0268102210236"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058340511_p8268132242318"><a name="en-us_topic_0000001058340511_p8268132242318"></a><a name="en-us_topic_0000001058340511_p8268132242318"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058340511_p13268162222310"><a name="en-us_topic_0000001058340511_p13268162222310"></a><a name="en-us_topic_0000001058340511_p13268162222310"></a>Data that needs to be passed to the destination page during navigation. After the destination page is displayed, it can use the passed data, for example, <strong id="en-us_topic_0000001058340511_b450711129286"><a name="en-us_topic_0000001058340511_b450711129286"></a><a name="en-us_topic_0000001058340511_b450711129286"></a>this.data1</strong> (<strong id="en-us_topic_0000001058340511_b105111112132816"><a name="en-us_topic_0000001058340511_b105111112132816"></a><a name="en-us_topic_0000001058340511_b105111112132816"></a>data1</strong> is a key in <strong id="en-us_topic_0000001058340511_b951212125286"><a name="en-us_topic_0000001058340511_b951212125286"></a><a name="en-us_topic_0000001058340511_b951212125286"></a>params</strong>). If there is the same key (for example, <strong id="en-us_topic_0000001058340511_b4486173192819"><a name="en-us_topic_0000001058340511_b4486173192819"></a><a name="en-us_topic_0000001058340511_b4486173192819"></a>data1</strong>) on the destination page, the passed <strong id="en-us_topic_0000001058340511_b148711382820"><a name="en-us_topic_0000001058340511_b148711382820"></a><a name="en-us_topic_0000001058340511_b148711382820"></a>data1</strong> value will overwrite the original value on the destination page.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // Example code for the current page
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
    // Example code for the routerpage2 page
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

    >**NOTE:** 
    >The page routing stack supports a maximum of 32 pages.


## router.replace\(OBJECT\)<a name="en-us_topic_0000001058340511_s6d485e6ae3064996a4de2f407bc4287d"></a>

Replaces the current page with another one in the application and destroys the current page.

-   Parameter

    <a name="en-us_topic_0000001058340511_t6b1726948831437cb2fabab6c2596bd6"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058340511_rbac962f43cbb4e6da29b30573fcaf9f5"><th class="cellrowborder" valign="top" width="8%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058340511_a16d15d7a316a40b19b98fbf3e709b198"><a name="en-us_topic_0000001058340511_a16d15d7a316a40b19b98fbf3e709b198"></a><a name="en-us_topic_0000001058340511_a16d15d7a316a40b19b98fbf3e709b198"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058340511_aede000ddf8d44cf3ac35d395531daa72"><a name="en-us_topic_0000001058340511_aede000ddf8d44cf3ac35d395531daa72"></a><a name="en-us_topic_0000001058340511_aede000ddf8d44cf3ac35d395531daa72"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058340511_af57857a2931e4bae9e1c01e953586b93"><a name="en-us_topic_0000001058340511_af57857a2931e4bae9e1c01e953586b93"></a><a name="en-us_topic_0000001058340511_af57857a2931e4bae9e1c01e953586b93"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="72%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058340511_a69477f180eb04f92be9c7bfad4ea1a22"><a name="en-us_topic_0000001058340511_a69477f180eb04f92be9c7bfad4ea1a22"></a><a name="en-us_topic_0000001058340511_a69477f180eb04f92be9c7bfad4ea1a22"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058340511_r907dc0ee7ae94b3aa4f42508bee0c51f"><td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058340511_a61f128e79b3d4b6080143f140d8a6f5a"><a name="en-us_topic_0000001058340511_a61f128e79b3d4b6080143f140d8a6f5a"></a><a name="en-us_topic_0000001058340511_a61f128e79b3d4b6080143f140d8a6f5a"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058340511_aa6161c953b2d4cacb770343bbc7a76b9"><a name="en-us_topic_0000001058340511_aa6161c953b2d4cacb770343bbc7a76b9"></a><a name="en-us_topic_0000001058340511_aa6161c953b2d4cacb770343bbc7a76b9"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058340511_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"><a name="en-us_topic_0000001058340511_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"></a><a name="en-us_topic_0000001058340511_ab2f2fcd3ccf94852aa2aa7aa4ad8bd6b"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="72%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058340511_ae5f1acce286d407896f0da896d170c60"><a name="en-us_topic_0000001058340511_ae5f1acce286d407896f0da896d170c60"></a><a name="en-us_topic_0000001058340511_ae5f1acce286d407896f0da896d170c60"></a>URI of the destination page, in either of the following formats:</p>
    <a name="en-us_topic_0000001058340511_ul15140171014517"></a><a name="en-us_topic_0000001058340511_ul15140171014517"></a><ul id="en-us_topic_0000001058340511_ul15140171014517"><li>Absolute path of the page. The value is available in the <strong id="en-us_topic_0000001058340511_b20876747250"><a name="en-us_topic_0000001058340511_b20876747250"></a><a name="en-us_topic_0000001058340511_b20876747250"></a>pages</strong> list in the <strong id="en-us_topic_0000001058340511_b78818471951"><a name="en-us_topic_0000001058340511_b78818471951"></a><a name="en-us_topic_0000001058340511_b78818471951"></a>config.json</strong> file, for example:<a name="en-us_topic_0000001058340511_ul15140810655"></a><a name="en-us_topic_0000001058340511_ul15140810655"></a><ul id="en-us_topic_0000001058340511_ul15140810655"><li>pages/index/index</li><li>pages/detail/detail</li></ul>
    </li><li>Particular path. If the URI is a slash (/), the home page is displayed.</li></ul>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058340511_row43841058103012"><td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058340511_p39929943120"><a name="en-us_topic_0000001058340511_p39929943120"></a><a name="en-us_topic_0000001058340511_p39929943120"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058340511_p899219153118"><a name="en-us_topic_0000001058340511_p899219153118"></a><a name="en-us_topic_0000001058340511_p899219153118"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058340511_p29920903113"><a name="en-us_topic_0000001058340511_p29920903113"></a><a name="en-us_topic_0000001058340511_p29920903113"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="72%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058340511_p2143918144613"><a name="en-us_topic_0000001058340511_p2143918144613"></a><a name="en-us_topic_0000001058340511_p2143918144613"></a>Data that needs to be passed to the destination page during navigation. After the destination page is displayed, it can use the passed data, for example, <strong id="en-us_topic_0000001058340511_b68841297286"><a name="en-us_topic_0000001058340511_b68841297286"></a><a name="en-us_topic_0000001058340511_b68841297286"></a>this.data1</strong> (<strong id="en-us_topic_0000001058340511_b108901229122819"><a name="en-us_topic_0000001058340511_b108901229122819"></a><a name="en-us_topic_0000001058340511_b108901229122819"></a>data1</strong> is a key in <strong id="en-us_topic_0000001058340511_b208901529152812"><a name="en-us_topic_0000001058340511_b208901529152812"></a><a name="en-us_topic_0000001058340511_b208901529152812"></a>params</strong>). If there is the same key (for example, <strong id="en-us_topic_0000001058340511_b117818315287"><a name="en-us_topic_0000001058340511_b117818315287"></a><a name="en-us_topic_0000001058340511_b117818315287"></a>data1</strong>) on the destination page, the passed <strong id="en-us_topic_0000001058340511_b157910318288"><a name="en-us_topic_0000001058340511_b157910318288"></a><a name="en-us_topic_0000001058340511_b157910318288"></a>data1</strong> value will overwrite the original value on the destination page.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // Example code for the current page
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
    // Example code for the detail page
    export default {
      data: {
        data1: 'default'
      },
      onInit() {
        console.info('showData1:' + this.data1)
      }
    }
    ```


## router.back\(OBJECT\)<a name="en-us_topic_0000001058340511_s3f958a02dde141e69b7f02f22fb2e401"></a>

Returns to the previous page or a specified page.

-   Parameter

    <a name="en-us_topic_0000001058340511_t8645be119aea4edc9abfe4ac4b1a5457"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058340511_r03b6547f30ab4ad898fe0604563e416f"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058340511_a576cd1b8452644d8942cd1c1f478afa4"><a name="en-us_topic_0000001058340511_a576cd1b8452644d8942cd1c1f478afa4"></a><a name="en-us_topic_0000001058340511_a576cd1b8452644d8942cd1c1f478afa4"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058340511_a13d651d4875643ccbcf890ad49a82bdf"><a name="en-us_topic_0000001058340511_a13d651d4875643ccbcf890ad49a82bdf"></a><a name="en-us_topic_0000001058340511_a13d651d4875643ccbcf890ad49a82bdf"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058340511_a114a9b21dba74aaba51710352c28b128"><a name="en-us_topic_0000001058340511_a114a9b21dba74aaba51710352c28b128"></a><a name="en-us_topic_0000001058340511_a114a9b21dba74aaba51710352c28b128"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058340511_a536b7faf84754ec9875bd10c5b1bd9ff"><a name="en-us_topic_0000001058340511_a536b7faf84754ec9875bd10c5b1bd9ff"></a><a name="en-us_topic_0000001058340511_a536b7faf84754ec9875bd10c5b1bd9ff"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058340511_r121c662a232e4152ba0a678cb7ccc5a9"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058340511_acca6b999d1fb40b28ee2f82f636aef65"><a name="en-us_topic_0000001058340511_acca6b999d1fb40b28ee2f82f636aef65"></a><a name="en-us_topic_0000001058340511_acca6b999d1fb40b28ee2f82f636aef65"></a>uri</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058340511_a58c83b28fb4649df96c79f922bdb81f3"><a name="en-us_topic_0000001058340511_a58c83b28fb4649df96c79f922bdb81f3"></a><a name="en-us_topic_0000001058340511_a58c83b28fb4649df96c79f922bdb81f3"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058340511_aff1dee2aad364012ae008c45a9a36392"><a name="en-us_topic_0000001058340511_aff1dee2aad364012ae008c45a9a36392"></a><a name="en-us_topic_0000001058340511_aff1dee2aad364012ae008c45a9a36392"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058340511_adf355f87a6e545a3b5cdcd5e78fcd8b3"><a name="en-us_topic_0000001058340511_adf355f87a6e545a3b5cdcd5e78fcd8b3"></a><a name="en-us_topic_0000001058340511_adf355f87a6e545a3b5cdcd5e78fcd8b3"></a>URI of the page to return to. If the specified page does not exist in the page stack, the app does not respond. If this parameter is not set, the app returns to the previous page.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // index page
    router.push({
      uri: 'pages/detail/detail',
    });
    
    // detail page
    router.push({
      uri: 'pages/mall/mall',
    });
    
    // Navigate from the mall page to the detail page through router.back().
    router.back();
    // Navigate from the detail page to the index page through router.back().
    router.back();
    // Return to the detail page through router.back().
    router.back({uri:'pages/detail/detail'});
    ```

    > **NOTE:** 
    >In the example, the  **uri**  field indicates the page route, which is specified by the  **pages**  list in the  **config.json**  file.


## router.clear\(\)<a name="en-us_topic_0000001058340511_sa5c3dfd1bb0d4b43906c3d770d6ab2d9"></a>

Clears all historical pages and retains only the current page at the top of the stack.

-   Parameter

    N/A

-   Example

    ```
    router.clear();
    ```


## router.getLength\(\)<a name="en-us_topic_0000001058340511_s3f121f4005934fda9a1830a909c92c25"></a>

Obtains the number of pages in the current stack. 

-   Returned Value

    <a name="en-us_topic_0000001058340511_t69833877986140cbb7fc7a25b411622b"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058340511_rad0dfd50874c4a9e8509cc0661ecc869"><th class="cellrowborder" valign="top" width="12.920000000000002%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001058340511_add584a11aa0e49928b79176951aa21e1"><a name="en-us_topic_0000001058340511_add584a11aa0e49928b79176951aa21e1"></a><a name="en-us_topic_0000001058340511_add584a11aa0e49928b79176951aa21e1"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.08%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001058340511_af65e00289a1f4616861727b28ffc14f2"><a name="en-us_topic_0000001058340511_af65e00289a1f4616861727b28ffc14f2"></a><a name="en-us_topic_0000001058340511_af65e00289a1f4616861727b28ffc14f2"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058340511_r12b8d9cc2831480e8f0f16bd0e992b30"><td class="cellrowborder" valign="top" width="12.920000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001058340511_ae731080460894a68b064fba7c893c1e8"><a name="en-us_topic_0000001058340511_ae731080460894a68b064fba7c893c1e8"></a><a name="en-us_topic_0000001058340511_ae731080460894a68b064fba7c893c1e8"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.08%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001058340511_affc1140bcdf940de8705c921ccd68da5"><a name="en-us_topic_0000001058340511_affc1140bcdf940de8705c921ccd68da5"></a><a name="en-us_topic_0000001058340511_affc1140bcdf940de8705c921ccd68da5"></a>Number of pages in the stack. The maximum value is <strong id="en-us_topic_0000001058340511_b15825419161611"><a name="en-us_topic_0000001058340511_b15825419161611"></a><a name="en-us_topic_0000001058340511_b15825419161611"></a>32</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var size = router.getLength();
    console.log('pages stack size = ' + size);
    ```


## router.getState\(\)<a name="en-us_topic_0000001058340511_s8843a443a12048e68e33f586aee8dc34"></a>

Obtains information about the current page state.

-   Returned Value

    <a name="en-us_topic_0000001058340511_tf9e3eb9ef0aa4d9880f996fe6afa6d1b"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058340511_redea81f1cfff4122b733df3049d3d8ba"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058340511_ac1f54204219e42e58810bacc1e221e3c"><a name="en-us_topic_0000001058340511_ac1f54204219e42e58810bacc1e221e3c"></a><a name="en-us_topic_0000001058340511_ac1f54204219e42e58810bacc1e221e3c"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058340511_a811d9c5a5a2e402bb2d429d14e07af79"><a name="en-us_topic_0000001058340511_a811d9c5a5a2e402bb2d429d14e07af79"></a><a name="en-us_topic_0000001058340511_a811d9c5a5a2e402bb2d429d14e07af79"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058340511_ab0d65ba7195a4b6aa51a1c8be829da4b"><a name="en-us_topic_0000001058340511_ab0d65ba7195a4b6aa51a1c8be829da4b"></a><a name="en-us_topic_0000001058340511_ab0d65ba7195a4b6aa51a1c8be829da4b"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058340511_r654e450f29d34ba2a43c4baf828242bc"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058340511_aa5d3616785ec46b88eab2b7a0c97c4e3"><a name="en-us_topic_0000001058340511_aa5d3616785ec46b88eab2b7a0c97c4e3"></a><a name="en-us_topic_0000001058340511_aa5d3616785ec46b88eab2b7a0c97c4e3"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058340511_aaa82d880dc7d4221b2a65a202a0b34b4"><a name="en-us_topic_0000001058340511_aaa82d880dc7d4221b2a65a202a0b34b4"></a><a name="en-us_topic_0000001058340511_aaa82d880dc7d4221b2a65a202a0b34b4"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058340511_p1979431135"><a name="en-us_topic_0000001058340511_p1979431135"></a><a name="en-us_topic_0000001058340511_p1979431135"></a>Index of the current page in the stack.</p>
    <div class="note" id="en-us_topic_0000001058340511_note136715361314"><a name="en-us_topic_0000001058340511_note136715361314"></a><a name="en-us_topic_0000001058340511_note136715361314"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058340511_p1167137132"><a name="en-us_topic_0000001058340511_p1167137132"></a><a name="en-us_topic_0000001058340511_p1167137132"></a>The index starts from 1 from the bottom to the top of the stack.</p>
    </div></div>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058340511_r5d033b0d902e4a83aaf66db1902c5154"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058340511_ae78d89cb022b4505984ae62d800f246c"><a name="en-us_topic_0000001058340511_ae78d89cb022b4505984ae62d800f246c"></a><a name="en-us_topic_0000001058340511_ae78d89cb022b4505984ae62d800f246c"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058340511_a75e18952ce3a4df3a9dd4af9e20f8df1"><a name="en-us_topic_0000001058340511_a75e18952ce3a4df3a9dd4af9e20f8df1"></a><a name="en-us_topic_0000001058340511_a75e18952ce3a4df3a9dd4af9e20f8df1"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058340511_acf2d1680871b4630b121fc51835d5144"><a name="en-us_topic_0000001058340511_acf2d1680871b4630b121fc51835d5144"></a><a name="en-us_topic_0000001058340511_acf2d1680871b4630b121fc51835d5144"></a>Name of the current page, that is, the file name.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058340511_ra0e0c300267144a5806efae3aaa498b7"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058340511_add88e87efa6242f5a1679e71cf3f31a1"><a name="en-us_topic_0000001058340511_add88e87efa6242f5a1679e71cf3f31a1"></a><a name="en-us_topic_0000001058340511_add88e87efa6242f5a1679e71cf3f31a1"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058340511_a92fb0e8fa14446ea91898b2a8867b2ef"><a name="en-us_topic_0000001058340511_a92fb0e8fa14446ea91898b2a8867b2ef"></a><a name="en-us_topic_0000001058340511_a92fb0e8fa14446ea91898b2a8867b2ef"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="78%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058340511_a8f4870ec81224a75b82268b19b7c76de"><a name="en-us_topic_0000001058340511_a8f4870ec81224a75b82268b19b7c76de"></a><a name="en-us_topic_0000001058340511_a8f4870ec81224a75b82268b19b7c76de"></a>Path of the current page.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var page = router.getState();
    console.log('current index = ' + page.index);
    console.log('current name = ' + page.name);
    console.log('current path = ' + page.path);
    ```



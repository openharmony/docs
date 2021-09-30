# 应用打点<a name="ZH-CN_TOPIC_0000001163949504"></a>

-   [导入模块](#zh-cn_topic_0000001163817362_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001163817362_section11257113618419)
-   [hiAppEvent.write](#zh-cn_topic_0000001163817362_section570630172512)
-   [hiAppEvent.write](#zh-cn_topic_0000001163817362_section0857164934517)
-   [hiAppEvent.configure](#zh-cn_topic_0000001163817362_section5378143772018)
-   [ConfigOption](#zh-cn_topic_0000001163817362_section1877154515916)
-   [EventType](#zh-cn_topic_0000001163817362_section099619567453)
-   [Event](#zh-cn_topic_0000001163817362_section107763162597)
    -   [属性](#zh-cn_topic_0000001163817362_section13128518134118)

-   [Param](#zh-cn_topic_0000001163817362_section382852073116)
    -   [属性](#zh-cn_topic_0000001163817362_section0452193894112)


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001163817362_s56d19203690d4782bfc74069abb6bd71"></a>

```
import hiAppEvent from '@ohos.hiAppEvent';
```

## 权限<a name="zh-cn_topic_0000001163817362_section11257113618419"></a>

无

## hiAppEvent.write<a name="zh-cn_topic_0000001163817362_section570630172512"></a>

write\(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback<void\>\): void

应用事件打点方法，将事件写入到当天的事件文件中，可接收类型为Json对象的事件参数，使用callback方式作为异步回调。

-   参数：

    <a name="zh-cn_topic_0000001163817362_table1054125415456"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row354155454518"><th class="cellrowborder" valign="top" width="15.030000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163817362_p17541135415455"><a name="zh-cn_topic_0000001163817362_p17541135415455"></a><a name="zh-cn_topic_0000001163817362_p17541135415455"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.430000000000003%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163817362_p454195484516"><a name="zh-cn_topic_0000001163817362_p454195484516"></a><a name="zh-cn_topic_0000001163817362_p454195484516"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.870000000000002%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163817362_p115414549454"><a name="zh-cn_topic_0000001163817362_p115414549454"></a><a name="zh-cn_topic_0000001163817362_p115414549454"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.67000000000001%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163817362_p155411354104516"><a name="zh-cn_topic_0000001163817362_p155411354104516"></a><a name="zh-cn_topic_0000001163817362_p155411354104516"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163817362_row6541155413451"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p125411454184516"><a name="zh-cn_topic_0000001163817362_p125411454184516"></a><a name="zh-cn_topic_0000001163817362_p125411454184516"></a>eventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p5541195416452"><a name="zh-cn_topic_0000001163817362_p5541195416452"></a><a name="zh-cn_topic_0000001163817362_p5541195416452"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p754115424514"><a name="zh-cn_topic_0000001163817362_p754115424514"></a><a name="zh-cn_topic_0000001163817362_p754115424514"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p185421054144516"><a name="zh-cn_topic_0000001163817362_p185421054144516"></a><a name="zh-cn_topic_0000001163817362_p185421054144516"></a>应用事件名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163817362_row2542145416459"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p19542185415455"><a name="zh-cn_topic_0000001163817362_p19542185415455"></a><a name="zh-cn_topic_0000001163817362_p19542185415455"></a>eventType</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p20542205474519"><a name="zh-cn_topic_0000001163817362_p20542205474519"></a><a name="zh-cn_topic_0000001163817362_p20542205474519"></a><a href="#zh-cn_topic_0000001163817362_section099619567453">EventType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p1354295494510"><a name="zh-cn_topic_0000001163817362_p1354295494510"></a><a name="zh-cn_topic_0000001163817362_p1354295494510"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p754216544454"><a name="zh-cn_topic_0000001163817362_p754216544454"></a><a name="zh-cn_topic_0000001163817362_p754216544454"></a>应用事件类型。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163817362_row354265418456"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p1354215547452"><a name="zh-cn_topic_0000001163817362_p1354215547452"></a><a name="zh-cn_topic_0000001163817362_p1354215547452"></a>keyValues</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p754225416456"><a name="zh-cn_topic_0000001163817362_p754225416456"></a><a name="zh-cn_topic_0000001163817362_p754225416456"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p55421654124517"><a name="zh-cn_topic_0000001163817362_p55421654124517"></a><a name="zh-cn_topic_0000001163817362_p55421654124517"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p55431154164513"><a name="zh-cn_topic_0000001163817362_p55431154164513"></a><a name="zh-cn_topic_0000001163817362_p55431154164513"></a>应用事件的参数，key类型只能为string，value类型只能为string、number、boolean、Array（数组数据类型只能为string、number、boolean）。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163817362_row87751758579"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p777595810712"><a name="zh-cn_topic_0000001163817362_p777595810712"></a><a name="zh-cn_topic_0000001163817362_p777595810712"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p1577513581719"><a name="zh-cn_topic_0000001163817362_p1577513581719"></a><a name="zh-cn_topic_0000001163817362_p1577513581719"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p157753585718"><a name="zh-cn_topic_0000001163817362_p157753585718"></a><a name="zh-cn_topic_0000001163817362_p157753585718"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p1065434111303"><a name="zh-cn_topic_0000001163817362_p1065434111303"></a><a name="zh-cn_topic_0000001163817362_p1065434111303"></a>回调函数，可以在回调函数中处理接口返回值。</p>
    <a name="zh-cn_topic_0000001163817362_ul182248492307"></a><a name="zh-cn_topic_0000001163817362_ul182248492307"></a><ul id="zh-cn_topic_0000001163817362_ul182248492307"><li>返回值为0表示事件校验成功，事件正常异步写入事件文件；</li><li>大于0表示事件校验存在异常参数，在忽略异常参数后将事件异步写入事件文件；</li><li>小于0表示事件校验失败，不将事件写入事件文件。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"}, (err, value) => {
        if (err) {
            // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
            console.error(`failed to write event because ${err.code}`);
            return;
        }
    
        // 事件写入正常
        console.log(`success to write event: ${value}`);
    });
    ```


## hiAppEvent.write<a name="zh-cn_topic_0000001163817362_section0857164934517"></a>

write\(eventName: string, eventType: EventType, keyValues: object\): Promise<void\>

应用事件打点方法，将事件写入到当天的事件文件中，可接收类型为Json对象的事件参数，使用promise方式作为异步回调。

-   参数：

    <a name="zh-cn_topic_0000001163817362_table11857249104514"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row198584493457"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163817362_p128580494453"><a name="zh-cn_topic_0000001163817362_p128580494453"></a><a name="zh-cn_topic_0000001163817362_p128580494453"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163817362_p2085813494456"><a name="zh-cn_topic_0000001163817362_p2085813494456"></a><a name="zh-cn_topic_0000001163817362_p2085813494456"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163817362_p1285894934516"><a name="zh-cn_topic_0000001163817362_p1285894934516"></a><a name="zh-cn_topic_0000001163817362_p1285894934516"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163817362_p48581849104511"><a name="zh-cn_topic_0000001163817362_p48581849104511"></a><a name="zh-cn_topic_0000001163817362_p48581849104511"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163817362_row98581498450"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p1185884919459"><a name="zh-cn_topic_0000001163817362_p1185884919459"></a><a name="zh-cn_topic_0000001163817362_p1185884919459"></a>eventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p28586495454"><a name="zh-cn_topic_0000001163817362_p28586495454"></a><a name="zh-cn_topic_0000001163817362_p28586495454"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p2858144912459"><a name="zh-cn_topic_0000001163817362_p2858144912459"></a><a name="zh-cn_topic_0000001163817362_p2858144912459"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p8858164984518"><a name="zh-cn_topic_0000001163817362_p8858164984518"></a><a name="zh-cn_topic_0000001163817362_p8858164984518"></a>应用事件名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163817362_row198584495457"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p128583494450"><a name="zh-cn_topic_0000001163817362_p128583494450"></a><a name="zh-cn_topic_0000001163817362_p128583494450"></a>eventType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p13858449194517"><a name="zh-cn_topic_0000001163817362_p13858449194517"></a><a name="zh-cn_topic_0000001163817362_p13858449194517"></a><a href="#zh-cn_topic_0000001163817362_section099619567453">EventType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p1785894934513"><a name="zh-cn_topic_0000001163817362_p1785894934513"></a><a name="zh-cn_topic_0000001163817362_p1785894934513"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p198581349194515"><a name="zh-cn_topic_0000001163817362_p198581349194515"></a><a name="zh-cn_topic_0000001163817362_p198581349194515"></a>应用事件类型。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163817362_row78580497453"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p2085819494459"><a name="zh-cn_topic_0000001163817362_p2085819494459"></a><a name="zh-cn_topic_0000001163817362_p2085819494459"></a>keyValues</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p8859749154519"><a name="zh-cn_topic_0000001163817362_p8859749154519"></a><a name="zh-cn_topic_0000001163817362_p8859749154519"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p1385984964515"><a name="zh-cn_topic_0000001163817362_p1385984964515"></a><a name="zh-cn_topic_0000001163817362_p1385984964515"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p1859114984515"><a name="zh-cn_topic_0000001163817362_p1859114984515"></a><a name="zh-cn_topic_0000001163817362_p1859114984515"></a>应用事件的参数，key类型只能为string，value类型只能为string、number、boolean、Array（数组数据类型只能为string、number、boolean）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163817362_table10811610134713"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row7811410124716"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163817362_p118116107479"><a name="zh-cn_topic_0000001163817362_p118116107479"></a><a name="zh-cn_topic_0000001163817362_p118116107479"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163817362_p8811910124715"><a name="zh-cn_topic_0000001163817362_p8811910124715"></a><a name="zh-cn_topic_0000001163817362_p8811910124715"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163817362_row1181161019479"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163817362_p15811181004712"><a name="zh-cn_topic_0000001163817362_p15811181004712"></a><a name="zh-cn_topic_0000001163817362_p15811181004712"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163817362_p14811710164718"><a name="zh-cn_topic_0000001163817362_p14811710164718"></a><a name="zh-cn_topic_0000001163817362_p14811710164718"></a>Promise实例，可以在其then()、catch()方法中分别对事件写入成功、写入异常的情况进行回调处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"})
        .then((value) => {
            // 事件写入正常
            console.log(`success to write event: ${value}`);
        }).catch((err) => {
            // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
            console.error(`failed to write event because ${err.code}`);
        });
    ```


## hiAppEvent.configure<a name="zh-cn_topic_0000001163817362_section5378143772018"></a>

configure\(config: ConfigOption\): boolean

应用事件打点配置方法，可用于配置打点开关、文件目录存储限额大小等功能。

-   参数：

    <a name="zh-cn_topic_0000001163817362_table1252915782516"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row35293782515"><th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163817362_p35291371251"><a name="zh-cn_topic_0000001163817362_p35291371251"></a><a name="zh-cn_topic_0000001163817362_p35291371251"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.39%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163817362_p75296712250"><a name="zh-cn_topic_0000001163817362_p75296712250"></a><a name="zh-cn_topic_0000001163817362_p75296712250"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163817362_p105291377254"><a name="zh-cn_topic_0000001163817362_p105291377254"></a><a name="zh-cn_topic_0000001163817362_p105291377254"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.2%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163817362_p155291674252"><a name="zh-cn_topic_0000001163817362_p155291674252"></a><a name="zh-cn_topic_0000001163817362_p155291674252"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163817362_row652919711259"><td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p18529970251"><a name="zh-cn_topic_0000001163817362_p18529970251"></a><a name="zh-cn_topic_0000001163817362_p18529970251"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p65296742520"><a name="zh-cn_topic_0000001163817362_p65296742520"></a><a name="zh-cn_topic_0000001163817362_p65296742520"></a><a href="#zh-cn_topic_0000001163817362_section1877154515916">ConfigOption</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p155299792512"><a name="zh-cn_topic_0000001163817362_p155299792512"></a><a name="zh-cn_topic_0000001163817362_p155299792512"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.2%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p38353293497"><a name="zh-cn_topic_0000001163817362_p38353293497"></a><a name="zh-cn_topic_0000001163817362_p38353293497"></a>应用事件打点配置项对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163817362_table253014717256"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row3530471251"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163817362_p195304762520"><a name="zh-cn_topic_0000001163817362_p195304762520"></a><a name="zh-cn_topic_0000001163817362_p195304762520"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163817362_p1353017722518"><a name="zh-cn_topic_0000001163817362_p1353017722518"></a><a name="zh-cn_topic_0000001163817362_p1353017722518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163817362_row2053010792510"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163817362_p155308717259"><a name="zh-cn_topic_0000001163817362_p155308717259"></a><a name="zh-cn_topic_0000001163817362_p155308717259"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163817362_p1953016720258"><a name="zh-cn_topic_0000001163817362_p1953016720258"></a><a name="zh-cn_topic_0000001163817362_p1953016720258"></a>配置结果，true 表示配置成功，false 表示配置失败。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // 配置应用事件打点功能开关
    hiAppEvent.configure({
        disable: true
    });
    
    // 配置事件文件目录存储限额大小
    hiAppEvent.configure({
        maxStorage: '100M'
    });
    ```


## ConfigOption<a name="zh-cn_topic_0000001163817362_section1877154515916"></a>

此接口提供了应用打点的配置选项。

<a name="zh-cn_topic_0000001163817362_t1e7d4d4f9078490d8dcdbb56465b8ab3"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163817362_r85a1aa805727476a8e768b658530fc49"><th class="cellrowborder" valign="top" width="13.08%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163817362_a58cac6e212134a42a245df58d7b6f3a3"><a name="zh-cn_topic_0000001163817362_a58cac6e212134a42a245df58d7b6f3a3"></a><a name="zh-cn_topic_0000001163817362_a58cac6e212134a42a245df58d7b6f3a3"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="10.5%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163817362_ae520989fe4be4482acdfdf2c26d6517d"><a name="zh-cn_topic_0000001163817362_ae520989fe4be4482acdfdf2c26d6517d"></a><a name="zh-cn_topic_0000001163817362_ae520989fe4be4482acdfdf2c26d6517d"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.63%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163817362_a6b396dd84a564272a6f3d4732b4e12fe"><a name="zh-cn_topic_0000001163817362_a6b396dd84a564272a6f3d4732b4e12fe"></a><a name="zh-cn_topic_0000001163817362_a6b396dd84a564272a6f3d4732b4e12fe"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="65.79%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163817362_ae728420f819e42d1b31424ac9747665b"><a name="zh-cn_topic_0000001163817362_ae728420f819e42d1b31424ac9747665b"></a><a name="zh-cn_topic_0000001163817362_ae728420f819e42d1b31424ac9747665b"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163817362_r3e8e2a236aee4030b7f7878cf5bc7537"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_ada6eeced8a7c481dac17cdb7d5c37dce"><a name="zh-cn_topic_0000001163817362_ada6eeced8a7c481dac17cdb7d5c37dce"></a><a name="zh-cn_topic_0000001163817362_ada6eeced8a7c481dac17cdb7d5c37dce"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_a89ee25b3dc1045b5aa724c83751b3c0f"><a name="zh-cn_topic_0000001163817362_a89ee25b3dc1045b5aa724c83751b3c0f"></a><a name="zh-cn_topic_0000001163817362_a89ee25b3dc1045b5aa724c83751b3c0f"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.63%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p936187569"><a name="zh-cn_topic_0000001163817362_p936187569"></a><a name="zh-cn_topic_0000001163817362_p936187569"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="65.79%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_a42ab0decfa2a497782c54a4edfc72b8a"><a name="zh-cn_topic_0000001163817362_a42ab0decfa2a497782c54a4edfc72b8a"></a><a name="zh-cn_topic_0000001163817362_a42ab0decfa2a497782c54a4edfc72b8a"></a>应用打点功能开关。配置值为true表示关闭打点功能，false表示不关闭打点功能。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row860615273611"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163817362_p116072272610"><a name="zh-cn_topic_0000001163817362_p116072272610"></a><a name="zh-cn_topic_0000001163817362_p116072272610"></a>maxStorage</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163817362_p9607727863"><a name="zh-cn_topic_0000001163817362_p9607727863"></a><a name="zh-cn_topic_0000001163817362_p9607727863"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.63%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163817362_p66070271869"><a name="zh-cn_topic_0000001163817362_p66070271869"></a><a name="zh-cn_topic_0000001163817362_p66070271869"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="65.79%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163817362_p96071927366"><a name="zh-cn_topic_0000001163817362_p96071927366"></a><a name="zh-cn_topic_0000001163817362_p96071927366"></a>打点数据本地存储文件所在目录的配额大小，默认限额为“10M”。所在目录大小超出限额后会对目录进行清理操作，会按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出限额时停止。</p>
</td>
</tr>
</tbody>
</table>

## EventType<a name="zh-cn_topic_0000001163817362_section099619567453"></a>

事件类型枚举。

<a name="zh-cn_topic_0000001163817362_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001163817362_a3d0fc780cc904c1cbab7991251622f65"><a name="zh-cn_topic_0000001163817362_a3d0fc780cc904c1cbab7991251622f65"></a><a name="zh-cn_topic_0000001163817362_a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001163817362_aace9cae4ba0d4939bfa048460f61c3c7"><a name="zh-cn_topic_0000001163817362_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="zh-cn_topic_0000001163817362_aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001163817362_afec895de33f94e3c87ee7acc20190a17"><a name="zh-cn_topic_0000001163817362_afec895de33f94e3c87ee7acc20190a17"></a><a name="zh-cn_topic_0000001163817362_afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163817362_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163817362_p13876443113318"><a name="zh-cn_topic_0000001163817362_p13876443113318"></a><a name="zh-cn_topic_0000001163817362_p13876443113318"></a>FAULT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163817362_p2282152962115"><a name="zh-cn_topic_0000001163817362_p2282152962115"></a><a name="zh-cn_topic_0000001163817362_p2282152962115"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163817362_p28751543103312"><a name="zh-cn_topic_0000001163817362_p28751543103312"></a><a name="zh-cn_topic_0000001163817362_p28751543103312"></a>故障类型事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163817362_p68697436338"><a name="zh-cn_topic_0000001163817362_p68697436338"></a><a name="zh-cn_topic_0000001163817362_p68697436338"></a>STATISTIC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163817362_p1310553911218"><a name="zh-cn_topic_0000001163817362_p1310553911218"></a><a name="zh-cn_topic_0000001163817362_p1310553911218"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163817362_p14868114312331"><a name="zh-cn_topic_0000001163817362_p14868114312331"></a><a name="zh-cn_topic_0000001163817362_p14868114312331"></a>统计类型事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row91702048195619"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163817362_p123991673342"><a name="zh-cn_topic_0000001163817362_p123991673342"></a><a name="zh-cn_topic_0000001163817362_p123991673342"></a>SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163817362_p14170114811561"><a name="zh-cn_topic_0000001163817362_p14170114811561"></a><a name="zh-cn_topic_0000001163817362_p14170114811561"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163817362_p1539912793411"><a name="zh-cn_topic_0000001163817362_p1539912793411"></a><a name="zh-cn_topic_0000001163817362_p1539912793411"></a>安全类型事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row717094895612"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001163817362_p10231410193416"><a name="zh-cn_topic_0000001163817362_p10231410193416"></a><a name="zh-cn_topic_0000001163817362_p10231410193416"></a>BEHAVIOR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001163817362_p1817134815569"><a name="zh-cn_topic_0000001163817362_p1817134815569"></a><a name="zh-cn_topic_0000001163817362_p1817134815569"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001163817362_p523171020343"><a name="zh-cn_topic_0000001163817362_p523171020343"></a><a name="zh-cn_topic_0000001163817362_p523171020343"></a>行为类型事件。</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="zh-cn_topic_0000001163817362_section107763162597"></a>

此接口提供了所有预定义事件的事件名称常量。

### 属性<a name="zh-cn_topic_0000001163817362_section13128518134118"></a>

<a name="zh-cn_topic_0000001163817362_table728861911417"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row62887198149"><th class="cellrowborder" valign="top" width="33.550000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001163817362_p928811911410"><a name="zh-cn_topic_0000001163817362_p928811911410"></a><a name="zh-cn_topic_0000001163817362_p928811911410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.6%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001163817362_p8288191916149"><a name="zh-cn_topic_0000001163817362_p8288191916149"></a><a name="zh-cn_topic_0000001163817362_p8288191916149"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.6899999999999995%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001163817362_p14288131911418"><a name="zh-cn_topic_0000001163817362_p14288131911418"></a><a name="zh-cn_topic_0000001163817362_p14288131911418"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.43%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001163817362_p1928861921411"><a name="zh-cn_topic_0000001163817362_p1928861921411"></a><a name="zh-cn_topic_0000001163817362_p1928861921411"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="37.730000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001163817362_p728815191149"><a name="zh-cn_topic_0000001163817362_p728815191149"></a><a name="zh-cn_topic_0000001163817362_p728815191149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163817362_row528891919142"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p3288191991414"><a name="zh-cn_topic_0000001163817362_p3288191991414"></a><a name="zh-cn_topic_0000001163817362_p3288191991414"></a>USER_LOGIN</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p3288121901418"><a name="zh-cn_topic_0000001163817362_p3288121901418"></a><a name="zh-cn_topic_0000001163817362_p3288121901418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p182881319191414"><a name="zh-cn_topic_0000001163817362_p182881319191414"></a><a name="zh-cn_topic_0000001163817362_p182881319191414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p1928801914148"><a name="zh-cn_topic_0000001163817362_p1928801914148"></a><a name="zh-cn_topic_0000001163817362_p1928801914148"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p1428811192144"><a name="zh-cn_topic_0000001163817362_p1428811192144"></a><a name="zh-cn_topic_0000001163817362_p1428811192144"></a>用户登录事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row72571514202916"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p18257151413298"><a name="zh-cn_topic_0000001163817362_p18257151413298"></a><a name="zh-cn_topic_0000001163817362_p18257151413298"></a>USER_LOGOUT</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p3976112512293"><a name="zh-cn_topic_0000001163817362_p3976112512293"></a><a name="zh-cn_topic_0000001163817362_p3976112512293"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p1497682515293"><a name="zh-cn_topic_0000001163817362_p1497682515293"></a><a name="zh-cn_topic_0000001163817362_p1497682515293"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p1697613259298"><a name="zh-cn_topic_0000001163817362_p1697613259298"></a><a name="zh-cn_topic_0000001163817362_p1697613259298"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p162571914162912"><a name="zh-cn_topic_0000001163817362_p162571914162912"></a><a name="zh-cn_topic_0000001163817362_p162571914162912"></a>用户登出事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row37723173299"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p07721917182914"><a name="zh-cn_topic_0000001163817362_p07721917182914"></a><a name="zh-cn_topic_0000001163817362_p07721917182914"></a>DISTRIBUTED_SERVICE_START</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p8324132810299"><a name="zh-cn_topic_0000001163817362_p8324132810299"></a><a name="zh-cn_topic_0000001163817362_p8324132810299"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p20324928192912"><a name="zh-cn_topic_0000001163817362_p20324928192912"></a><a name="zh-cn_topic_0000001163817362_p20324928192912"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p1432413281294"><a name="zh-cn_topic_0000001163817362_p1432413281294"></a><a name="zh-cn_topic_0000001163817362_p1432413281294"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p19772191715296"><a name="zh-cn_topic_0000001163817362_p19772191715296"></a><a name="zh-cn_topic_0000001163817362_p19772191715296"></a>分布式服务启动事件。</p>
</td>
</tr>
</tbody>
</table>

## Param<a name="zh-cn_topic_0000001163817362_section382852073116"></a>

此接口提供了所有预定义参数的参数名称常量。

### 属性<a name="zh-cn_topic_0000001163817362_section0452193894112"></a>

<a name="zh-cn_topic_0000001163817362_table28281220153111"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163817362_row12828192018319"><th class="cellrowborder" valign="top" width="35.24%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001163817362_p1082932073115"><a name="zh-cn_topic_0000001163817362_p1082932073115"></a><a name="zh-cn_topic_0000001163817362_p1082932073115"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.45%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001163817362_p14829920163113"><a name="zh-cn_topic_0000001163817362_p14829920163113"></a><a name="zh-cn_topic_0000001163817362_p14829920163113"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.82%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001163817362_p15829620133110"><a name="zh-cn_topic_0000001163817362_p15829620133110"></a><a name="zh-cn_topic_0000001163817362_p15829620133110"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.540000000000001%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001163817362_p3829192013312"><a name="zh-cn_topic_0000001163817362_p3829192013312"></a><a name="zh-cn_topic_0000001163817362_p3829192013312"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="35.949999999999996%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001163817362_p6829132018315"><a name="zh-cn_topic_0000001163817362_p6829132018315"></a><a name="zh-cn_topic_0000001163817362_p6829132018315"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163817362_row48291920183117"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p9829162043119"><a name="zh-cn_topic_0000001163817362_p9829162043119"></a><a name="zh-cn_topic_0000001163817362_p9829162043119"></a>USER_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p1182912013120"><a name="zh-cn_topic_0000001163817362_p1182912013120"></a><a name="zh-cn_topic_0000001163817362_p1182912013120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p188294201316"><a name="zh-cn_topic_0000001163817362_p188294201316"></a><a name="zh-cn_topic_0000001163817362_p188294201316"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p88297205315"><a name="zh-cn_topic_0000001163817362_p88297205315"></a><a name="zh-cn_topic_0000001163817362_p88297205315"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p4829620183115"><a name="zh-cn_topic_0000001163817362_p4829620183115"></a><a name="zh-cn_topic_0000001163817362_p4829620183115"></a>用户自定义ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row482992011315"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p12829120163115"><a name="zh-cn_topic_0000001163817362_p12829120163115"></a><a name="zh-cn_topic_0000001163817362_p12829120163115"></a>DISTRIBUTED_SERVICE_NAME</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p78291420183111"><a name="zh-cn_topic_0000001163817362_p78291420183111"></a><a name="zh-cn_topic_0000001163817362_p78291420183111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p15829720143116"><a name="zh-cn_topic_0000001163817362_p15829720143116"></a><a name="zh-cn_topic_0000001163817362_p15829720143116"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p18291920133110"><a name="zh-cn_topic_0000001163817362_p18291920133110"></a><a name="zh-cn_topic_0000001163817362_p18291920133110"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p882916205315"><a name="zh-cn_topic_0000001163817362_p882916205315"></a><a name="zh-cn_topic_0000001163817362_p882916205315"></a>分布式服务名称。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001163817362_row9829112019318"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001163817362_p8829220163110"><a name="zh-cn_topic_0000001163817362_p8829220163110"></a><a name="zh-cn_topic_0000001163817362_p8829220163110"></a>DISTRIBUTED_SERVICE_INSTANCE_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001163817362_p98299202316"><a name="zh-cn_topic_0000001163817362_p98299202316"></a><a name="zh-cn_topic_0000001163817362_p98299202316"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001163817362_p2829142017310"><a name="zh-cn_topic_0000001163817362_p2829142017310"></a><a name="zh-cn_topic_0000001163817362_p2829142017310"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001163817362_p2829152073111"><a name="zh-cn_topic_0000001163817362_p2829152073111"></a><a name="zh-cn_topic_0000001163817362_p2829152073111"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001163817362_p15829132023112"><a name="zh-cn_topic_0000001163817362_p15829132023112"></a><a name="zh-cn_topic_0000001163817362_p15829132023112"></a>分布式服务实例ID。</p>
</td>
</tr>
</tbody>
</table>


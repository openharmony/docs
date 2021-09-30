# 国际化（I18n）<a name="ZH-CN_TOPIC_0000001209575571"></a>

-   [导入模块](#zh-cn_topic_0000001163490118_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001163490118_section11257113618419)
-   [i18n.getDisplayLanguage](#zh-cn_topic_0000001163490118_section4734636131914)
-   [i18n.getDisplayCountry](#zh-cn_topic_0000001163490118_section156643561735)
-   [i18n.getSystemLanugage](#zh-cn_topic_0000001163490118_section25111622174311)
-   [i18n.getSystemRegion](#zh-cn_topic_0000001163490118_section65121922114312)
-   [i18n.getSystemLocale](#zh-cn_topic_0000001163490118_section10514122204316)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001163490118_s56d19203690d4782bfc74069abb6bd71"></a>

```
import i18n from '@ohos.i18n';
```

## 权限<a name="zh-cn_topic_0000001163490118_section11257113618419"></a>

无

## i18n.getDisplayLanguage<a name="zh-cn_topic_0000001163490118_section4734636131914"></a>

getDisplayLanguage\(language: string, locale: string, sentenceCase?: boolean\): string

获取指定语言的本地化显示文本。

-   参数：

    <a name="zh-cn_topic_0000001163490118_table8262171319013"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row726281313010"><th class="cellrowborder" valign="top" width="14.92%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163490118_p426217131016"><a name="zh-cn_topic_0000001163490118_p426217131016"></a><a name="zh-cn_topic_0000001163490118_p426217131016"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.5%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163490118_p42622131804"><a name="zh-cn_topic_0000001163490118_p42622131804"></a><a name="zh-cn_topic_0000001163490118_p42622131804"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163490118_p208801115312"><a name="zh-cn_topic_0000001163490118_p208801115312"></a><a name="zh-cn_topic_0000001163490118_p208801115312"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163490118_p926251313010"><a name="zh-cn_topic_0000001163490118_p926251313010"></a><a name="zh-cn_topic_0000001163490118_p926251313010"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row42621713304"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p0262813102"><a name="zh-cn_topic_0000001163490118_p0262813102"></a><a name="zh-cn_topic_0000001163490118_p0262813102"></a>language</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p1926261314016"><a name="zh-cn_topic_0000001163490118_p1926261314016"></a><a name="zh-cn_topic_0000001163490118_p1926261314016"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p088011110311"><a name="zh-cn_topic_0000001163490118_p088011110311"></a><a name="zh-cn_topic_0000001163490118_p088011110311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p152627133014"><a name="zh-cn_topic_0000001163490118_p152627133014"></a><a name="zh-cn_topic_0000001163490118_p152627133014"></a><span>指定语言</span></p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163490118_row15880755501"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p1348011161519"><a name="zh-cn_topic_0000001163490118_p1348011161519"></a><a name="zh-cn_topic_0000001163490118_p1348011161519"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p68801855808"><a name="zh-cn_topic_0000001163490118_p68801855808"></a><a name="zh-cn_topic_0000001163490118_p68801855808"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p1188014118315"><a name="zh-cn_topic_0000001163490118_p1188014118315"></a><a name="zh-cn_topic_0000001163490118_p1188014118315"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p78803551506"><a name="zh-cn_topic_0000001163490118_p78803551506"></a><a name="zh-cn_topic_0000001163490118_p78803551506"></a>显示指定语言的区域ID</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163490118_row109041353904"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p199055531001"><a name="zh-cn_topic_0000001163490118_p199055531001"></a><a name="zh-cn_topic_0000001163490118_p199055531001"></a>sentenceCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p59058531015"><a name="zh-cn_topic_0000001163490118_p59058531015"></a><a name="zh-cn_topic_0000001163490118_p59058531015"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p1888021103111"><a name="zh-cn_topic_0000001163490118_p1888021103111"></a><a name="zh-cn_topic_0000001163490118_p1888021103111"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p199051053209"><a name="zh-cn_topic_0000001163490118_p199051053209"></a><a name="zh-cn_topic_0000001163490118_p199051053209"></a>本地化显示文本是否要首字母大写</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163490118_table0483117706"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row6483417306"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163490118_p7483617903"><a name="zh-cn_topic_0000001163490118_p7483617903"></a><a name="zh-cn_topic_0000001163490118_p7483617903"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163490118_p14835171705"><a name="zh-cn_topic_0000001163490118_p14835171705"></a><a name="zh-cn_topic_0000001163490118_p14835171705"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row8483111717020"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163490118_p1248320178013"><a name="zh-cn_topic_0000001163490118_p1248320178013"></a><a name="zh-cn_topic_0000001163490118_p1248320178013"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163490118_p24836172000"><a name="zh-cn_topic_0000001163490118_p24836172000"></a><a name="zh-cn_topic_0000001163490118_p24836172000"></a><span>指定语言的本地化显示文本</span></p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    i18n.getDisplayLanguage("zh", "en-GB", true);
    i18n.getDisplayLanguage("zh", "en-GB");
    ```


## i18n.getDisplayCountry<a name="zh-cn_topic_0000001163490118_section156643561735"></a>

getDisplayCountry\(country: string, locale: string, sentenceCase?: boolean\): string

获取指定国家的本地化显示文本。

-   参数：

    <a name="zh-cn_topic_0000001163490118_table566415619320"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row86656561632"><th class="cellrowborder" valign="top" width="14.92%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001163490118_p366595612316"><a name="zh-cn_topic_0000001163490118_p366595612316"></a><a name="zh-cn_topic_0000001163490118_p366595612316"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.5%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001163490118_p766513561836"><a name="zh-cn_topic_0000001163490118_p766513561836"></a><a name="zh-cn_topic_0000001163490118_p766513561836"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001163490118_p5380185513302"><a name="zh-cn_topic_0000001163490118_p5380185513302"></a><a name="zh-cn_topic_0000001163490118_p5380185513302"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001163490118_p466585612312"><a name="zh-cn_topic_0000001163490118_p466585612312"></a><a name="zh-cn_topic_0000001163490118_p466585612312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row196651356536"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p1666515564316"><a name="zh-cn_topic_0000001163490118_p1666515564316"></a><a name="zh-cn_topic_0000001163490118_p1666515564316"></a>country</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p19665135612319"><a name="zh-cn_topic_0000001163490118_p19665135612319"></a><a name="zh-cn_topic_0000001163490118_p19665135612319"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p13380155519303"><a name="zh-cn_topic_0000001163490118_p13380155519303"></a><a name="zh-cn_topic_0000001163490118_p13380155519303"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p15665205611310"><a name="zh-cn_topic_0000001163490118_p15665205611310"></a><a name="zh-cn_topic_0000001163490118_p15665205611310"></a><span>指定</span>国家</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163490118_row1766595615310"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p16651156431"><a name="zh-cn_topic_0000001163490118_p16651156431"></a><a name="zh-cn_topic_0000001163490118_p16651156431"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p6665656936"><a name="zh-cn_topic_0000001163490118_p6665656936"></a><a name="zh-cn_topic_0000001163490118_p6665656936"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p638045563019"><a name="zh-cn_topic_0000001163490118_p638045563019"></a><a name="zh-cn_topic_0000001163490118_p638045563019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p18665456932"><a name="zh-cn_topic_0000001163490118_p18665456932"></a><a name="zh-cn_topic_0000001163490118_p18665456932"></a>显示指定国家的区域ID</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001163490118_row186658561436"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001163490118_p146650564311"><a name="zh-cn_topic_0000001163490118_p146650564311"></a><a name="zh-cn_topic_0000001163490118_p146650564311"></a>sentenceCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001163490118_p466510566311"><a name="zh-cn_topic_0000001163490118_p466510566311"></a><a name="zh-cn_topic_0000001163490118_p466510566311"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001163490118_p143800551304"><a name="zh-cn_topic_0000001163490118_p143800551304"></a><a name="zh-cn_topic_0000001163490118_p143800551304"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001163490118_p13665145612315"><a name="zh-cn_topic_0000001163490118_p13665145612315"></a><a name="zh-cn_topic_0000001163490118_p13665145612315"></a>本地化显示文本是否要首字母大写</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001163490118_table14665145616317"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row46651556932"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163490118_p366535611320"><a name="zh-cn_topic_0000001163490118_p366535611320"></a><a name="zh-cn_topic_0000001163490118_p366535611320"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163490118_p066512561431"><a name="zh-cn_topic_0000001163490118_p066512561431"></a><a name="zh-cn_topic_0000001163490118_p066512561431"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row4665115614318"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163490118_p1766615561337"><a name="zh-cn_topic_0000001163490118_p1766615561337"></a><a name="zh-cn_topic_0000001163490118_p1766615561337"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163490118_p18666185614320"><a name="zh-cn_topic_0000001163490118_p18666185614320"></a><a name="zh-cn_topic_0000001163490118_p18666185614320"></a><span>指定国家的本地化显示文本</span></p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    i18n.getDisplayCountry("zh-CN", "en-GB", true);
    i18n.getDisplayCountry("zh-CN", "en-GB");
    ```


## i18n.getSystemLanugage<a name="zh-cn_topic_0000001163490118_section25111622174311"></a>

getSystemLanguage\(\): string

获取系统语言。

-   返回值：

    <a name="zh-cn_topic_0000001163490118_table10512322154313"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row35125225432"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163490118_p251212225435"><a name="zh-cn_topic_0000001163490118_p251212225435"></a><a name="zh-cn_topic_0000001163490118_p251212225435"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163490118_p10512132211433"><a name="zh-cn_topic_0000001163490118_p10512132211433"></a><a name="zh-cn_topic_0000001163490118_p10512132211433"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row451262234310"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163490118_p155122222439"><a name="zh-cn_topic_0000001163490118_p155122222439"></a><a name="zh-cn_topic_0000001163490118_p155122222439"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163490118_p651218222432"><a name="zh-cn_topic_0000001163490118_p651218222432"></a><a name="zh-cn_topic_0000001163490118_p651218222432"></a><span>系统语言ID</span></p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    i18n.getSystemLanguage();
    ```


## i18n.getSystemRegion<a name="zh-cn_topic_0000001163490118_section65121922114312"></a>

getSystemRegion\(\): string

获取系统地区。

-   返回值：

    <a name="zh-cn_topic_0000001163490118_table145141228431"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row85141522184310"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163490118_p75141722184315"><a name="zh-cn_topic_0000001163490118_p75141722184315"></a><a name="zh-cn_topic_0000001163490118_p75141722184315"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163490118_p651482224315"><a name="zh-cn_topic_0000001163490118_p651482224315"></a><a name="zh-cn_topic_0000001163490118_p651482224315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row1051442244317"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163490118_p7514222164318"><a name="zh-cn_topic_0000001163490118_p7514222164318"></a><a name="zh-cn_topic_0000001163490118_p7514222164318"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163490118_p11514522104314"><a name="zh-cn_topic_0000001163490118_p11514522104314"></a><a name="zh-cn_topic_0000001163490118_p11514522104314"></a>系统地区ID</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    i18n.getSystemRegion();
    ```


## i18n.getSystemLocale<a name="zh-cn_topic_0000001163490118_section10514122204316"></a>

getSystemLocale\(\): string

获取系统区域。

-   返回值：

    <a name="zh-cn_topic_0000001163490118_table11515122294317"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001163490118_row15515422144313"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001163490118_p205151722194316"><a name="zh-cn_topic_0000001163490118_p205151722194316"></a><a name="zh-cn_topic_0000001163490118_p205151722194316"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001163490118_p12515132211434"><a name="zh-cn_topic_0000001163490118_p12515132211434"></a><a name="zh-cn_topic_0000001163490118_p12515132211434"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001163490118_row551612214432"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001163490118_p8516142217436"><a name="zh-cn_topic_0000001163490118_p8516142217436"></a><a name="zh-cn_topic_0000001163490118_p8516142217436"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001163490118_p45163224436"><a name="zh-cn_topic_0000001163490118_p45163224436"></a><a name="zh-cn_topic_0000001163490118_p45163224436"></a>系统区域ID</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    i18n.getSystemLocale();
    ```



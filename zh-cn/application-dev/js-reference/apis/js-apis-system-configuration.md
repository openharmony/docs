# 应用配置<a name="ZH-CN_TOPIC_0000001164130782"></a>

## 导入模块<a name="zh-cn_topic_0000001173324675_section15536249155915"></a>

```
import configuration from '@system.configuration';
```

## 权限列表<a name="zh-cn_topic_0000001173324675_section8152081004"></a>

无

## configuration.getLocale<a name="zh-cn_topic_0000001173324675_section8389829903"></a>

getLocale\(\): <[LocaleResponse](#zh-cn_topic_0000001173324675_table1544853546)\>

获取应用当前的语言和地区。默认与系统的语言和地区同步。

-   返回值

    **表 1**  LocaleResponse

    <a name="zh-cn_topic_0000001173324675_table1544853546"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173324675_row1670755549"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324675_p57013505413"><a name="zh-cn_topic_0000001173324675_p57013505413"></a><a name="zh-cn_topic_0000001173324675_p57013505413"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5012501250125%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324675_p9706511540"><a name="zh-cn_topic_0000001173324675_p9706511540"></a><a name="zh-cn_topic_0000001173324675_p9706511540"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.72697269726973%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324675_p16701957548"><a name="zh-cn_topic_0000001173324675_p16701957548"></a><a name="zh-cn_topic_0000001173324675_p16701957548"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173324675_row15709513545"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324675_p1370154548"><a name="zh-cn_topic_0000001173324675_p1370154548"></a><a name="zh-cn_topic_0000001173324675_p1370154548"></a>language</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324675_p19701653545"><a name="zh-cn_topic_0000001173324675_p19701653545"></a><a name="zh-cn_topic_0000001173324675_p19701653545"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324675_p37010510548"><a name="zh-cn_topic_0000001173324675_p37010510548"></a><a name="zh-cn_topic_0000001173324675_p37010510548"></a>语言。例如：zh。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324675_row970165135413"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324675_p97055105414"><a name="zh-cn_topic_0000001173324675_p97055105414"></a><a name="zh-cn_topic_0000001173324675_p97055105414"></a>countryOrRegion</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324675_p1770175115413"><a name="zh-cn_topic_0000001173324675_p1770175115413"></a><a name="zh-cn_topic_0000001173324675_p1770175115413"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324675_p77015518544"><a name="zh-cn_topic_0000001173324675_p77015518544"></a><a name="zh-cn_topic_0000001173324675_p77015518544"></a>国家或地区。例如：CN。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324675_row6332114185611"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324675_p53321542567"><a name="zh-cn_topic_0000001173324675_p53321542567"></a><a name="zh-cn_topic_0000001173324675_p53321542567"></a>dir</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324675_p1433216410564"><a name="zh-cn_topic_0000001173324675_p1433216410564"></a><a name="zh-cn_topic_0000001173324675_p1433216410564"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324675_p33321417565"><a name="zh-cn_topic_0000001173324675_p33321417565"></a><a name="zh-cn_topic_0000001173324675_p33321417565"></a>文字布局方向。取值范围：</p>
    <a name="zh-cn_topic_0000001173324675_ul1861816241119"></a><a name="zh-cn_topic_0000001173324675_ul1861816241119"></a><ul id="zh-cn_topic_0000001173324675_ul1861816241119"><li>ltr：从左到右；</li><li>rtl：从右到左。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324675_row165137101137"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324675_p1351311101333"><a name="zh-cn_topic_0000001173324675_p1351311101333"></a><a name="zh-cn_topic_0000001173324675_p1351311101333"></a>unicodeSetting<sup id="zh-cn_topic_0000001173324675_sup1646171814502"><a name="zh-cn_topic_0000001173324675_sup1646171814502"></a><a name="zh-cn_topic_0000001173324675_sup1646171814502"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324675_p1513121019313"><a name="zh-cn_topic_0000001173324675_p1513121019313"></a><a name="zh-cn_topic_0000001173324675_p1513121019313"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324675_p849701364"><a name="zh-cn_topic_0000001173324675_p849701364"></a><a name="zh-cn_topic_0000001173324675_p849701364"></a>语言环境定义的Unicode语言环境键集，如果此语言环境没有特定键集，则返回空集。</p>
    <p id="zh-cn_topic_0000001173324675_p16513111012314"><a name="zh-cn_topic_0000001173324675_p16513111012314"></a><a name="zh-cn_topic_0000001173324675_p16513111012314"></a>例如：{"nu":"arab"}，表示当前环境下的数字采用阿拉伯语的数字。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const localeInfo = configuration.getLocale();
    console.info(localeInfo.language);
    ```



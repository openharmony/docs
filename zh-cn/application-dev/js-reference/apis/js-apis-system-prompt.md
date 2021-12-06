# 弹窗<a name="ZH-CN_TOPIC_0000001209252185"></a>

## 导入模块<a name="zh-cn_topic_0000001127125010_s1fada83813e64efcbc67e970ced86588"></a>

```
import prompt from '@system.prompt';
```

## 权限列表<a name="zh-cn_topic_0000001127125010_section11257113618419"></a>

无

## prompt.showToast<a name="zh-cn_topic_0000001127125010_sc34d255befcf467dab069802dc9e54d8"></a>

showToast\(Object\): void

显示文本弹窗。

-   参数

    <a name="zh-cn_topic_0000001127125010_t1618141057434ca885c1586184c502e2"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125010_r351c10438fad40de99efc195cc88296f"><th class="cellrowborder" valign="top" width="16.73%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125010_a1056691df28b470d9af0c2c2f964ff8f"><a name="zh-cn_topic_0000001127125010_a1056691df28b470d9af0c2c2f964ff8f"></a><a name="zh-cn_topic_0000001127125010_a1056691df28b470d9af0c2c2f964ff8f"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.27%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125010_aed30d84405424c6cb5cabbbdbe3e35a7"><a name="zh-cn_topic_0000001127125010_aed30d84405424c6cb5cabbbdbe3e35a7"></a><a name="zh-cn_topic_0000001127125010_aed30d84405424c6cb5cabbbdbe3e35a7"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125010_a854ad49fdbd34a1eb98a5757d01f7cfa"><a name="zh-cn_topic_0000001127125010_a854ad49fdbd34a1eb98a5757d01f7cfa"></a><a name="zh-cn_topic_0000001127125010_a854ad49fdbd34a1eb98a5757d01f7cfa"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125010_a34deb96a6ac2414eb11e2a7dd2142ebb"><a name="zh-cn_topic_0000001127125010_a34deb96a6ac2414eb11e2a7dd2142ebb"></a><a name="zh-cn_topic_0000001127125010_a34deb96a6ac2414eb11e2a7dd2142ebb"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125010_rae51f5fc5bda4e5992851196bad62e8e"><td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_ab4df9faf190145219b091959f5a62082"><a name="zh-cn_topic_0000001127125010_ab4df9faf190145219b091959f5a62082"></a><a name="zh-cn_topic_0000001127125010_ab4df9faf190145219b091959f5a62082"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.27%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_a0dad7be0aa3f4033bc91bb4f4331d843"><a name="zh-cn_topic_0000001127125010_a0dad7be0aa3f4033bc91bb4f4331d843"></a><a name="zh-cn_topic_0000001127125010_a0dad7be0aa3f4033bc91bb4f4331d843"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_a8e32b2d4bba64516b56edaf8d6bdfdfa"><a name="zh-cn_topic_0000001127125010_a8e32b2d4bba64516b56edaf8d6bdfdfa"></a><a name="zh-cn_topic_0000001127125010_a8e32b2d4bba64516b56edaf8d6bdfdfa"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_a4b2f4463435a4e1c96e831bca8bb40a3"><a name="zh-cn_topic_0000001127125010_a4b2f4463435a4e1c96e831bca8bb40a3"></a><a name="zh-cn_topic_0000001127125010_a4b2f4463435a4e1c96e831bca8bb40a3"></a>显示的文本信息。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_r4d2b81c5265a4d2e9029ea49c12f3cda"><td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_ae2ee7c33807f4c8fa9d454ca7fa679cb"><a name="zh-cn_topic_0000001127125010_ae2ee7c33807f4c8fa9d454ca7fa679cb"></a><a name="zh-cn_topic_0000001127125010_ae2ee7c33807f4c8fa9d454ca7fa679cb"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.27%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_aa3100e4a607749cba360f4386b71ada5"><a name="zh-cn_topic_0000001127125010_aa3100e4a607749cba360f4386b71ada5"></a><a name="zh-cn_topic_0000001127125010_aa3100e4a607749cba360f4386b71ada5"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_ab40203ebb13b4cd5a86d428fa5db381b"><a name="zh-cn_topic_0000001127125010_ab40203ebb13b4cd5a86d428fa5db381b"></a><a name="zh-cn_topic_0000001127125010_ab40203ebb13b4cd5a86d428fa5db381b"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_aac09f7fe897d4a80ab7160590b544e39"><a name="zh-cn_topic_0000001127125010_aac09f7fe897d4a80ab7160590b544e39"></a><a name="zh-cn_topic_0000001127125010_aac09f7fe897d4a80ab7160590b544e39"></a>默认值1500ms，建议区间：1500ms-10000ms。</p>
    <div class="note" id="zh-cn_topic_0000001127125010_note116191623191316"><a name="zh-cn_topic_0000001127125010_note116191623191316"></a><a name="zh-cn_topic_0000001127125010_note116191623191316"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125010_p1961942320133"><a name="zh-cn_topic_0000001127125010_p1961942320133"></a><a name="zh-cn_topic_0000001127125010_p1961942320133"></a>若小于1500ms则取默认值，最大取值为10000ms。</p>
    </div></div>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_row62011935366"><td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p182018316365"><a name="zh-cn_topic_0000001127125010_p182018316365"></a><a name="zh-cn_topic_0000001127125010_p182018316365"></a>[bottom]<sup id="zh-cn_topic_0000001127125010_sup11448750123910"><a name="zh-cn_topic_0000001127125010_sup11448750123910"></a><a name="zh-cn_topic_0000001127125010_sup11448750123910"></a><span>5+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.27%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p82011839362"><a name="zh-cn_topic_0000001127125010_p82011839362"></a><a name="zh-cn_topic_0000001127125010_p82011839362"></a>&lt;length&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p82021136362"><a name="zh-cn_topic_0000001127125010_p82021136362"></a><a name="zh-cn_topic_0000001127125010_p82021136362"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p1120212312365"><a name="zh-cn_topic_0000001127125010_p1120212312365"></a><a name="zh-cn_topic_0000001127125010_p1120212312365"></a>设置弹窗边框距离屏幕底部的位置。</p>
    <div class="note" id="zh-cn_topic_0000001127125010_note1834105155712"><a name="zh-cn_topic_0000001127125010_note1834105155712"></a><a name="zh-cn_topic_0000001127125010_note1834105155712"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125010_p10341651115711"><a name="zh-cn_topic_0000001127125010_p10341651115711"></a><a name="zh-cn_topic_0000001127125010_p10341651115711"></a>仅手机和平板设备支持。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    prompt.showToast({
      message: 'Message Info',
      duration: 2000,
    });
    ```


## prompt.showDialog<a name="zh-cn_topic_0000001127125010_sc6babedb391e4de9af1189ebc9ff5e69"></a>

showDialog\(\): void

在页面内显示对话框。

-   参数

    <a name="zh-cn_topic_0000001127125010_t629832d7ad1f4f7e9ed380a6320a133e"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125010_r166e1186bdbf45fe9775955b02b5e0cf"><th class="cellrowborder" valign="top" width="13.089999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125010_a274fde9345af4ec29d72d801d1c9463b"><a name="zh-cn_topic_0000001127125010_a274fde9345af4ec29d72d801d1c9463b"></a><a name="zh-cn_topic_0000001127125010_a274fde9345af4ec29d72d801d1c9463b"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.91%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125010_af6f12ca9f0dd44e98ee58e6dcc3a1edf"><a name="zh-cn_topic_0000001127125010_af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a><a name="zh-cn_topic_0000001127125010_af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125010_a48d51a6c05b9412b82b6b2a70fd7825b"><a name="zh-cn_topic_0000001127125010_a48d51a6c05b9412b82b6b2a70fd7825b"></a><a name="zh-cn_topic_0000001127125010_a48d51a6c05b9412b82b6b2a70fd7825b"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="65%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125010_afd08fb662a564651bc3cedbb9a05c0a5"><a name="zh-cn_topic_0000001127125010_afd08fb662a564651bc3cedbb9a05c0a5"></a><a name="zh-cn_topic_0000001127125010_afd08fb662a564651bc3cedbb9a05c0a5"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125010_r868a28f8acc34af4916dd4ed453ebd09"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_a2714800437f24825bf30c198dc6aad56"><a name="zh-cn_topic_0000001127125010_a2714800437f24825bf30c198dc6aad56"></a><a name="zh-cn_topic_0000001127125010_a2714800437f24825bf30c198dc6aad56"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_a2620a53c20cc4d26af71b5eba3846e19"><a name="zh-cn_topic_0000001127125010_a2620a53c20cc4d26af71b5eba3846e19"></a><a name="zh-cn_topic_0000001127125010_a2620a53c20cc4d26af71b5eba3846e19"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_af7aacc8736d34a8ca12fb007d74fb110"><a name="zh-cn_topic_0000001127125010_af7aacc8736d34a8ca12fb007d74fb110"></a><a name="zh-cn_topic_0000001127125010_af7aacc8736d34a8ca12fb007d74fb110"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_a3c44052f536c4baead681acbce5dc790"><a name="zh-cn_topic_0000001127125010_a3c44052f536c4baead681acbce5dc790"></a><a name="zh-cn_topic_0000001127125010_a3c44052f536c4baead681acbce5dc790"></a>标题文本。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_r7d02820c4eaa48febfa636322c50c07f"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_af30a62497b5a41ad930718e1980632d9"><a name="zh-cn_topic_0000001127125010_af30a62497b5a41ad930718e1980632d9"></a><a name="zh-cn_topic_0000001127125010_af30a62497b5a41ad930718e1980632d9"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_a942a00c302c842269dd974188e8d72cf"><a name="zh-cn_topic_0000001127125010_a942a00c302c842269dd974188e8d72cf"></a><a name="zh-cn_topic_0000001127125010_a942a00c302c842269dd974188e8d72cf"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_aea0eec373d7d4fe8807a4e3c300487fb"><a name="zh-cn_topic_0000001127125010_aea0eec373d7d4fe8807a4e3c300487fb"></a><a name="zh-cn_topic_0000001127125010_aea0eec373d7d4fe8807a4e3c300487fb"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_ae42b17323a00403ca1682cb29424b935"><a name="zh-cn_topic_0000001127125010_ae42b17323a00403ca1682cb29424b935"></a><a name="zh-cn_topic_0000001127125010_ae42b17323a00403ca1682cb29424b935"></a>内容文本。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_r9051c3a4fdfd4242bbbba1362a30c32b"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_ad7a64f8d6a414ce992ee8ad5b737d820"><a name="zh-cn_topic_0000001127125010_ad7a64f8d6a414ce992ee8ad5b737d820"></a><a name="zh-cn_topic_0000001127125010_ad7a64f8d6a414ce992ee8ad5b737d820"></a>buttons</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_ae4ecdedd56eb4bb3a113aa7945576bfc"><a name="zh-cn_topic_0000001127125010_ae4ecdedd56eb4bb3a113aa7945576bfc"></a><a name="zh-cn_topic_0000001127125010_ae4ecdedd56eb4bb3a113aa7945576bfc"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_a348857f0f8674fa88b08c4b43cf59923"><a name="zh-cn_topic_0000001127125010_a348857f0f8674fa88b08c4b43cf59923"></a><a name="zh-cn_topic_0000001127125010_a348857f0f8674fa88b08c4b43cf59923"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_ab6529e91fe1d4adc8cb3fa2e531369a9"><a name="zh-cn_topic_0000001127125010_ab6529e91fe1d4adc8cb3fa2e531369a9"></a><a name="zh-cn_topic_0000001127125010_ab6529e91fe1d4adc8cb3fa2e531369a9"></a>对话框中按钮的数组，结构为：{text:'button', color: '#666666'}，支持1-3个按钮。其中第一个为positiveButton；第二个为negativeButton；第三个为neutralButton。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_rf2d176102f6547949a74deb1746d440e"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_abe7e018a2dac47079db426b424b2031f"><a name="zh-cn_topic_0000001127125010_abe7e018a2dac47079db426b424b2031f"></a><a name="zh-cn_topic_0000001127125010_abe7e018a2dac47079db426b424b2031f"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_a9061f42dad6d4ed8a81a147022ce7c68"><a name="zh-cn_topic_0000001127125010_a9061f42dad6d4ed8a81a147022ce7c68"></a><a name="zh-cn_topic_0000001127125010_a9061f42dad6d4ed8a81a147022ce7c68"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_a05153a00a5ae4a2992deb337387d9cfc"><a name="zh-cn_topic_0000001127125010_a05153a00a5ae4a2992deb337387d9cfc"></a><a name="zh-cn_topic_0000001127125010_a05153a00a5ae4a2992deb337387d9cfc"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_a986abb2e067742f3b9fe575e7cbd0224"><a name="zh-cn_topic_0000001127125010_a986abb2e067742f3b9fe575e7cbd0224"></a><a name="zh-cn_topic_0000001127125010_a986abb2e067742f3b9fe575e7cbd0224"></a>接口调用成功的回调函数，返回值如<a href="#zh-cn_topic_0000001127125010_t5f0df2fad0544e3eb458936109014414">success返回值</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_r26d54c4b23944b7bb7950c87b836b1c2"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_af1a6df8907754b7b95f6a7dd6eef3f81"><a name="zh-cn_topic_0000001127125010_af1a6df8907754b7b95f6a7dd6eef3f81"></a><a name="zh-cn_topic_0000001127125010_af1a6df8907754b7b95f6a7dd6eef3f81"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_ac8d3e854d1034a9da3f463f1d045c06f"><a name="zh-cn_topic_0000001127125010_ac8d3e854d1034a9da3f463f1d045c06f"></a><a name="zh-cn_topic_0000001127125010_ac8d3e854d1034a9da3f463f1d045c06f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_a5aa033ed47de41c6890699434eb179ab"><a name="zh-cn_topic_0000001127125010_a5aa033ed47de41c6890699434eb179ab"></a><a name="zh-cn_topic_0000001127125010_a5aa033ed47de41c6890699434eb179ab"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_a08b61cefc2cb4fed83e6ef32d9056fa7"><a name="zh-cn_topic_0000001127125010_a08b61cefc2cb4fed83e6ef32d9056fa7"></a><a name="zh-cn_topic_0000001127125010_a08b61cefc2cb4fed83e6ef32d9056fa7"></a>取消调用此接口的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_r5bd94b2812be49fc9cc884b39815638c"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_ad7700957c924489f840d376805d97d02"><a name="zh-cn_topic_0000001127125010_ad7700957c924489f840d376805d97d02"></a><a name="zh-cn_topic_0000001127125010_ad7700957c924489f840d376805d97d02"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_a3b1e01fd33a04147894a7eb481c6896f"><a name="zh-cn_topic_0000001127125010_a3b1e01fd33a04147894a7eb481c6896f"></a><a name="zh-cn_topic_0000001127125010_a3b1e01fd33a04147894a7eb481c6896f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_a22ea63d9206e4496a5164158a4e4aa31"><a name="zh-cn_topic_0000001127125010_a22ea63d9206e4496a5164158a4e4aa31"></a><a name="zh-cn_topic_0000001127125010_a22ea63d9206e4496a5164158a4e4aa31"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_afcf4c75ba59a40c39e0b848df14c4b51"><a name="zh-cn_topic_0000001127125010_afcf4c75ba59a40c39e0b848df14c4b51"></a><a name="zh-cn_topic_0000001127125010_afcf4c75ba59a40c39e0b848df14c4b51"></a>弹框退出时的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    success返回值：

    <a name="zh-cn_topic_0000001127125010_t5f0df2fad0544e3eb458936109014414"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125010_rbe130c794ee1413ea7c736dac2a65bbd"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125010_a289c783f320744f18414bb29a696abba"><a name="zh-cn_topic_0000001127125010_a289c783f320744f18414bb29a696abba"></a><a name="zh-cn_topic_0000001127125010_a289c783f320744f18414bb29a696abba"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125010_a0ec0f99d9e094c5b9d097dde27508798"><a name="zh-cn_topic_0000001127125010_a0ec0f99d9e094c5b9d097dde27508798"></a><a name="zh-cn_topic_0000001127125010_a0ec0f99d9e094c5b9d097dde27508798"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="75%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125010_a57a576be84d146c38aa95aefcad0e486"><a name="zh-cn_topic_0000001127125010_a57a576be84d146c38aa95aefcad0e486"></a><a name="zh-cn_topic_0000001127125010_a57a576be84d146c38aa95aefcad0e486"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125010_r7a357c830bd44c65bfee22ddf64e4710"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125010_a4417e83cb4b14c418eeaeff7669c77cd"><a name="zh-cn_topic_0000001127125010_a4417e83cb4b14c418eeaeff7669c77cd"></a><a name="zh-cn_topic_0000001127125010_a4417e83cb4b14c418eeaeff7669c77cd"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125010_a27d628021f0f4a8f91b9a59bd00f7584"><a name="zh-cn_topic_0000001127125010_a27d628021f0f4a8f91b9a59bd00f7584"></a><a name="zh-cn_topic_0000001127125010_a27d628021f0f4a8f91b9a59bd00f7584"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="75%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125010_aab61e7c297034494ab27e6ca91102568"><a name="zh-cn_topic_0000001127125010_aab61e7c297034494ab27e6ca91102568"></a><a name="zh-cn_topic_0000001127125010_aab61e7c297034494ab27e6ca91102568"></a>选中按钮在buttons数组中的索引。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    prompt.showDialog({
      title: 'Title Info',
      message: 'Message Info',
      buttons: [
        {
          text: 'button',
          color: '#666666',
        },
      ],
      success: function(data) {
        console.log('dialog success callback，click button : ' + data.index);
      },
      cancel: function() {
        console.log('dialog cancel callback');
      },
    });
    ```


## prompt.showActionMenu<sup>6+</sup><a name="zh-cn_topic_0000001127125010_section151752203513"></a>

showActionMenu\(Object\): void

显示操作菜单。

-   参数

    <a name="zh-cn_topic_0000001127125010_table71817293515"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125010_row61820263513"><th class="cellrowborder" valign="top" width="13.089999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125010_p518192173514"><a name="zh-cn_topic_0000001127125010_p518192173514"></a><a name="zh-cn_topic_0000001127125010_p518192173514"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.8%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125010_p518132193511"><a name="zh-cn_topic_0000001127125010_p518132193511"></a><a name="zh-cn_topic_0000001127125010_p518132193511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.46%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125010_p91872143516"><a name="zh-cn_topic_0000001127125010_p91872143516"></a><a name="zh-cn_topic_0000001127125010_p91872143516"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125010_p10188253515"><a name="zh-cn_topic_0000001127125010_p10188253515"></a><a name="zh-cn_topic_0000001127125010_p10188253515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125010_row10181213517"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p41822163517"><a name="zh-cn_topic_0000001127125010_p41822163517"></a><a name="zh-cn_topic_0000001127125010_p41822163517"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p1419923354"><a name="zh-cn_topic_0000001127125010_p1419923354"></a><a name="zh-cn_topic_0000001127125010_p1419923354"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p1419927355"><a name="zh-cn_topic_0000001127125010_p1419927355"></a><a name="zh-cn_topic_0000001127125010_p1419927355"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p201915217358"><a name="zh-cn_topic_0000001127125010_p201915217358"></a><a name="zh-cn_topic_0000001127125010_p201915217358"></a>标题文本。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_row61902173517"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p101914223513"><a name="zh-cn_topic_0000001127125010_p101914223513"></a><a name="zh-cn_topic_0000001127125010_p101914223513"></a>buttons</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p4191122359"><a name="zh-cn_topic_0000001127125010_p4191122359"></a><a name="zh-cn_topic_0000001127125010_p4191122359"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p101992133516"><a name="zh-cn_topic_0000001127125010_p101992133516"></a><a name="zh-cn_topic_0000001127125010_p101992133516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p191911293517"><a name="zh-cn_topic_0000001127125010_p191911293517"></a><a name="zh-cn_topic_0000001127125010_p191911293517"></a>对话框中按钮的数组，结构为：{text:'button', color: '#666666'}，支持1-6个按钮。大于6个按钮时弹窗不显示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_row14194216353"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p720192133513"><a name="zh-cn_topic_0000001127125010_p720192133513"></a><a name="zh-cn_topic_0000001127125010_p720192133513"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p102012103515"><a name="zh-cn_topic_0000001127125010_p102012103515"></a><a name="zh-cn_topic_0000001127125010_p102012103515"></a>(data: <a href="#zh-cn_topic_0000001127125010_table14215283515">TapIndex</a>) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p52082183517"><a name="zh-cn_topic_0000001127125010_p52082183517"></a><a name="zh-cn_topic_0000001127125010_p52082183517"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p920321358"><a name="zh-cn_topic_0000001127125010_p920321358"></a><a name="zh-cn_topic_0000001127125010_p920321358"></a>接口调用成功的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_row120528354"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p15201253516"><a name="zh-cn_topic_0000001127125010_p15201253516"></a><a name="zh-cn_topic_0000001127125010_p15201253516"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p22213478481"><a name="zh-cn_topic_0000001127125010_p22213478481"></a><a name="zh-cn_topic_0000001127125010_p22213478481"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p32010212359"><a name="zh-cn_topic_0000001127125010_p32010212359"></a><a name="zh-cn_topic_0000001127125010_p32010212359"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p5205218353"><a name="zh-cn_topic_0000001127125010_p5205218353"></a><a name="zh-cn_topic_0000001127125010_p5205218353"></a>接口调用失败的回调函数。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127125010_row1320520356"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125010_p18206219351"><a name="zh-cn_topic_0000001127125010_p18206219351"></a><a name="zh-cn_topic_0000001127125010_p18206219351"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125010_p1870474764820"><a name="zh-cn_topic_0000001127125010_p1870474764820"></a><a name="zh-cn_topic_0000001127125010_p1870474764820"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125010_p112119212353"><a name="zh-cn_topic_0000001127125010_p112119212353"></a><a name="zh-cn_topic_0000001127125010_p112119212353"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125010_p192110273519"><a name="zh-cn_topic_0000001127125010_p192110273519"></a><a name="zh-cn_topic_0000001127125010_p192110273519"></a>接口调用结束的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  TapIndex

    <a name="zh-cn_topic_0000001127125010_table14215283515"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127125010_row20211228358"><th class="cellrowborder" valign="top" width="13%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125010_p92112215358"><a name="zh-cn_topic_0000001127125010_p92112215358"></a><a name="zh-cn_topic_0000001127125010_p92112215358"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125010_p12112216351"><a name="zh-cn_topic_0000001127125010_p12112216351"></a><a name="zh-cn_topic_0000001127125010_p12112216351"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="75%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125010_p7211420357"><a name="zh-cn_topic_0000001127125010_p7211420357"></a><a name="zh-cn_topic_0000001127125010_p7211420357"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127125010_row162172113511"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125010_p6218203514"><a name="zh-cn_topic_0000001127125010_p6218203514"></a><a name="zh-cn_topic_0000001127125010_p6218203514"></a>tapIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125010_p32220217352"><a name="zh-cn_topic_0000001127125010_p32220217352"></a><a name="zh-cn_topic_0000001127125010_p32220217352"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="75%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125010_p16221326352"><a name="zh-cn_topic_0000001127125010_p16221326352"></a><a name="zh-cn_topic_0000001127125010_p16221326352"></a>选中按钮在buttons数组中的索引，从0开始。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    prompt.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666',
        },
        {
          text: 'item2',
          color: '#000000',
        },
      ],
      success: function(data) {
        console.log('dialog success callback，click button : ' + data.tapIndex);
      },
      fail: function(data) {
        console.log('dialog fail callback' + data.errMsg);
      },
    });
    ```



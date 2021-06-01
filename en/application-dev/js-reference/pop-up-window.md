# Pop-up Window<a name="EN-US_TOPIC_0000001162494633"></a>

-   [Module to Import](#en-us_topic_0000001059340516_s1fada83813e64efcbc67e970ced86588)
-   [Permission List](#en-us_topic_0000001059340516_section11257113618419)
-   [prompt.showToast\(OBJECT\)](#en-us_topic_0000001059340516_sc34d255befcf467dab069802dc9e54d8)
-   [prompt.showDialog\(OBJECT\)](#en-us_topic_0000001059340516_sc6babedb391e4de9af1189ebc9ff5e69)

## Module to Import<a name="en-us_topic_0000001059340516_s1fada83813e64efcbc67e970ced86588"></a>

```
import prompt from '@system.prompt';
```

## Permission List<a name="en-us_topic_0000001059340516_section11257113618419"></a>

None

## prompt.showToast\(OBJECT\)<a name="en-us_topic_0000001059340516_sc34d255befcf467dab069802dc9e54d8"></a>

Displays the toast dialog box.

-   Parameter

    <a name="en-us_topic_0000001059340516_t1618141057434ca885c1586184c502e2"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001059340516_r351c10438fad40de99efc195cc88296f"><th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001059340516_a1056691df28b470d9af0c2c2f964ff8f"><a name="en-us_topic_0000001059340516_a1056691df28b470d9af0c2c2f964ff8f"></a><a name="en-us_topic_0000001059340516_a1056691df28b470d9af0c2c2f964ff8f"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001059340516_aed30d84405424c6cb5cabbbdbe3e35a7"><a name="en-us_topic_0000001059340516_aed30d84405424c6cb5cabbbdbe3e35a7"></a><a name="en-us_topic_0000001059340516_aed30d84405424c6cb5cabbbdbe3e35a7"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001059340516_a854ad49fdbd34a1eb98a5757d01f7cfa"><a name="en-us_topic_0000001059340516_a854ad49fdbd34a1eb98a5757d01f7cfa"></a><a name="en-us_topic_0000001059340516_a854ad49fdbd34a1eb98a5757d01f7cfa"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="62%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001059340516_a34deb96a6ac2414eb11e2a7dd2142ebb"><a name="en-us_topic_0000001059340516_a34deb96a6ac2414eb11e2a7dd2142ebb"></a><a name="en-us_topic_0000001059340516_a34deb96a6ac2414eb11e2a7dd2142ebb"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001059340516_rae51f5fc5bda4e5992851196bad62e8e"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_ab4df9faf190145219b091959f5a62082"><a name="en-us_topic_0000001059340516_ab4df9faf190145219b091959f5a62082"></a><a name="en-us_topic_0000001059340516_ab4df9faf190145219b091959f5a62082"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_a0dad7be0aa3f4033bc91bb4f4331d843"><a name="en-us_topic_0000001059340516_a0dad7be0aa3f4033bc91bb4f4331d843"></a><a name="en-us_topic_0000001059340516_a0dad7be0aa3f4033bc91bb4f4331d843"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_a8e32b2d4bba64516b56edaf8d6bdfdfa"><a name="en-us_topic_0000001059340516_a8e32b2d4bba64516b56edaf8d6bdfdfa"></a><a name="en-us_topic_0000001059340516_a8e32b2d4bba64516b56edaf8d6bdfdfa"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_a4b2f4463435a4e1c96e831bca8bb40a3"><a name="en-us_topic_0000001059340516_a4b2f4463435a4e1c96e831bca8bb40a3"></a><a name="en-us_topic_0000001059340516_a4b2f4463435a4e1c96e831bca8bb40a3"></a>Text to display.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_r4d2b81c5265a4d2e9029ea49c12f3cda"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_ae2ee7c33807f4c8fa9d454ca7fa679cb"><a name="en-us_topic_0000001059340516_ae2ee7c33807f4c8fa9d454ca7fa679cb"></a><a name="en-us_topic_0000001059340516_ae2ee7c33807f4c8fa9d454ca7fa679cb"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_aa3100e4a607749cba360f4386b71ada5"><a name="en-us_topic_0000001059340516_aa3100e4a607749cba360f4386b71ada5"></a><a name="en-us_topic_0000001059340516_aa3100e4a607749cba360f4386b71ada5"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_ab40203ebb13b4cd5a86d428fa5db381b"><a name="en-us_topic_0000001059340516_ab40203ebb13b4cd5a86d428fa5db381b"></a><a name="en-us_topic_0000001059340516_ab40203ebb13b4cd5a86d428fa5db381b"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_aac09f7fe897d4a80ab7160590b544e39"><a name="en-us_topic_0000001059340516_aac09f7fe897d4a80ab7160590b544e39"></a><a name="en-us_topic_0000001059340516_aac09f7fe897d4a80ab7160590b544e39"></a>Duration of the toast dialog box. The default value is <strong id="en-us_topic_0000001059340516_b9361121192413"><a name="en-us_topic_0000001059340516_b9361121192413"></a><a name="en-us_topic_0000001059340516_b9361121192413"></a>1500</strong>. The recommended value ranges from 1500 ms to 10000 ms.</p>
    <div class="note" id="en-us_topic_0000001059340516_note116191623191316"><a name="en-us_topic_0000001059340516_note116191623191316"></a><a name="en-us_topic_0000001059340516_note116191623191316"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059340516_p1961942320133"><a name="en-us_topic_0000001059340516_p1961942320133"></a><a name="en-us_topic_0000001059340516_p1961942320133"></a>A value less than 1500 is automatically changed to 1500. The maximum value is 10000 ms.</p>
    </div></div>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_row62011935366"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_p182018316365"><a name="en-us_topic_0000001059340516_p182018316365"></a><a name="en-us_topic_0000001059340516_p182018316365"></a>[bottom]<sup id="en-us_topic_0000001059340516_sup11448750123910"><a name="en-us_topic_0000001059340516_sup11448750123910"></a><a name="en-us_topic_0000001059340516_sup11448750123910"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_p82011839362"><a name="en-us_topic_0000001059340516_p82011839362"></a><a name="en-us_topic_0000001059340516_p82011839362"></a>&lt;length&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_p82021136362"><a name="en-us_topic_0000001059340516_p82021136362"></a><a name="en-us_topic_0000001059340516_p82021136362"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_p1120212312365"><a name="en-us_topic_0000001059340516_p1120212312365"></a><a name="en-us_topic_0000001059340516_p1120212312365"></a>Distance between the dialog border and the bottom of the screen.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    prompt.showToast({
      message: 'Message Info',
      duration: 2000,
    });
    ```


## prompt.showDialog\(OBJECT\)<a name="en-us_topic_0000001059340516_sc6babedb391e4de9af1189ebc9ff5e69"></a>

Displays the dialog box.

-   Parameter

    <a name="en-us_topic_0000001059340516_t629832d7ad1f4f7e9ed380a6320a133e"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001059340516_r166e1186bdbf45fe9775955b02b5e0cf"><th class="cellrowborder" valign="top" width="13.089999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001059340516_a274fde9345af4ec29d72d801d1c9463b"><a name="en-us_topic_0000001059340516_a274fde9345af4ec29d72d801d1c9463b"></a><a name="en-us_topic_0000001059340516_a274fde9345af4ec29d72d801d1c9463b"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.91%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001059340516_af6f12ca9f0dd44e98ee58e6dcc3a1edf"><a name="en-us_topic_0000001059340516_af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a><a name="en-us_topic_0000001059340516_af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001059340516_a48d51a6c05b9412b82b6b2a70fd7825b"><a name="en-us_topic_0000001059340516_a48d51a6c05b9412b82b6b2a70fd7825b"></a><a name="en-us_topic_0000001059340516_a48d51a6c05b9412b82b6b2a70fd7825b"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="65%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001059340516_afd08fb662a564651bc3cedbb9a05c0a5"><a name="en-us_topic_0000001059340516_afd08fb662a564651bc3cedbb9a05c0a5"></a><a name="en-us_topic_0000001059340516_afd08fb662a564651bc3cedbb9a05c0a5"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001059340516_r868a28f8acc34af4916dd4ed453ebd09"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_a2714800437f24825bf30c198dc6aad56"><a name="en-us_topic_0000001059340516_a2714800437f24825bf30c198dc6aad56"></a><a name="en-us_topic_0000001059340516_a2714800437f24825bf30c198dc6aad56"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_a2620a53c20cc4d26af71b5eba3846e19"><a name="en-us_topic_0000001059340516_a2620a53c20cc4d26af71b5eba3846e19"></a><a name="en-us_topic_0000001059340516_a2620a53c20cc4d26af71b5eba3846e19"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_af7aacc8736d34a8ca12fb007d74fb110"><a name="en-us_topic_0000001059340516_af7aacc8736d34a8ca12fb007d74fb110"></a><a name="en-us_topic_0000001059340516_af7aacc8736d34a8ca12fb007d74fb110"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_a3c44052f536c4baead681acbce5dc790"><a name="en-us_topic_0000001059340516_a3c44052f536c4baead681acbce5dc790"></a><a name="en-us_topic_0000001059340516_a3c44052f536c4baead681acbce5dc790"></a>Title of the text to display.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_r7d02820c4eaa48febfa636322c50c07f"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_af30a62497b5a41ad930718e1980632d9"><a name="en-us_topic_0000001059340516_af30a62497b5a41ad930718e1980632d9"></a><a name="en-us_topic_0000001059340516_af30a62497b5a41ad930718e1980632d9"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_a942a00c302c842269dd974188e8d72cf"><a name="en-us_topic_0000001059340516_a942a00c302c842269dd974188e8d72cf"></a><a name="en-us_topic_0000001059340516_a942a00c302c842269dd974188e8d72cf"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_aea0eec373d7d4fe8807a4e3c300487fb"><a name="en-us_topic_0000001059340516_aea0eec373d7d4fe8807a4e3c300487fb"></a><a name="en-us_topic_0000001059340516_aea0eec373d7d4fe8807a4e3c300487fb"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_ae42b17323a00403ca1682cb29424b935"><a name="en-us_topic_0000001059340516_ae42b17323a00403ca1682cb29424b935"></a><a name="en-us_topic_0000001059340516_ae42b17323a00403ca1682cb29424b935"></a>Text body.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_r9051c3a4fdfd4242bbbba1362a30c32b"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_ad7a64f8d6a414ce992ee8ad5b737d820"><a name="en-us_topic_0000001059340516_ad7a64f8d6a414ce992ee8ad5b737d820"></a><a name="en-us_topic_0000001059340516_ad7a64f8d6a414ce992ee8ad5b737d820"></a>buttons</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_ae4ecdedd56eb4bb3a113aa7945576bfc"><a name="en-us_topic_0000001059340516_ae4ecdedd56eb4bb3a113aa7945576bfc"></a><a name="en-us_topic_0000001059340516_ae4ecdedd56eb4bb3a113aa7945576bfc"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_a348857f0f8674fa88b08c4b43cf59923"><a name="en-us_topic_0000001059340516_a348857f0f8674fa88b08c4b43cf59923"></a><a name="en-us_topic_0000001059340516_a348857f0f8674fa88b08c4b43cf59923"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_ab6529e91fe1d4adc8cb3fa2e531369a9"><a name="en-us_topic_0000001059340516_ab6529e91fe1d4adc8cb3fa2e531369a9"></a><a name="en-us_topic_0000001059340516_ab6529e91fe1d4adc8cb3fa2e531369a9"></a>Array of buttons in the dialog box. The array structure is <strong id="en-us_topic_0000001059340516_b12386125113268"><a name="en-us_topic_0000001059340516_b12386125113268"></a><a name="en-us_topic_0000001059340516_b12386125113268"></a>{text:'button', color: '#666666'}</strong>. One to three buttons are supported. The first button is of the <strong id="en-us_topic_0000001059340516_b192581358288"><a name="en-us_topic_0000001059340516_b192581358288"></a><a name="en-us_topic_0000001059340516_b192581358288"></a>positiveButton</strong> type, the second is of the <strong id="en-us_topic_0000001059340516_b117326710282"><a name="en-us_topic_0000001059340516_b117326710282"></a><a name="en-us_topic_0000001059340516_b117326710282"></a>negativeButton</strong> type, and the third is of the <strong id="en-us_topic_0000001059340516_b4971171010297"><a name="en-us_topic_0000001059340516_b4971171010297"></a><a name="en-us_topic_0000001059340516_b4971171010297"></a>neutralButton</strong> type.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_rf2d176102f6547949a74deb1746d440e"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_abe7e018a2dac47079db426b424b2031f"><a name="en-us_topic_0000001059340516_abe7e018a2dac47079db426b424b2031f"></a><a name="en-us_topic_0000001059340516_abe7e018a2dac47079db426b424b2031f"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_a9061f42dad6d4ed8a81a147022ce7c68"><a name="en-us_topic_0000001059340516_a9061f42dad6d4ed8a81a147022ce7c68"></a><a name="en-us_topic_0000001059340516_a9061f42dad6d4ed8a81a147022ce7c68"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_a05153a00a5ae4a2992deb337387d9cfc"><a name="en-us_topic_0000001059340516_a05153a00a5ae4a2992deb337387d9cfc"></a><a name="en-us_topic_0000001059340516_a05153a00a5ae4a2992deb337387d9cfc"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_a986abb2e067742f3b9fe575e7cbd0224"><a name="en-us_topic_0000001059340516_a986abb2e067742f3b9fe575e7cbd0224"></a><a name="en-us_topic_0000001059340516_a986abb2e067742f3b9fe575e7cbd0224"></a>Called when the dialog box is displayed. For the return value, see <a href="#en-us_topic_0000001059340516_t5f0df2fad0544e3eb458936109014414">the value that will be returned when the dialog box is displayed</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_r26d54c4b23944b7bb7950c87b836b1c2"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_af1a6df8907754b7b95f6a7dd6eef3f81"><a name="en-us_topic_0000001059340516_af1a6df8907754b7b95f6a7dd6eef3f81"></a><a name="en-us_topic_0000001059340516_af1a6df8907754b7b95f6a7dd6eef3f81"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_ac8d3e854d1034a9da3f463f1d045c06f"><a name="en-us_topic_0000001059340516_ac8d3e854d1034a9da3f463f1d045c06f"></a><a name="en-us_topic_0000001059340516_ac8d3e854d1034a9da3f463f1d045c06f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_a5aa033ed47de41c6890699434eb179ab"><a name="en-us_topic_0000001059340516_a5aa033ed47de41c6890699434eb179ab"></a><a name="en-us_topic_0000001059340516_a5aa033ed47de41c6890699434eb179ab"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_a08b61cefc2cb4fed83e6ef32d9056fa7"><a name="en-us_topic_0000001059340516_a08b61cefc2cb4fed83e6ef32d9056fa7"></a><a name="en-us_topic_0000001059340516_a08b61cefc2cb4fed83e6ef32d9056fa7"></a>Called when the operation is cancelled.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059340516_r5bd94b2812be49fc9cc884b39815638c"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001059340516_ad7700957c924489f840d376805d97d02"><a name="en-us_topic_0000001059340516_ad7700957c924489f840d376805d97d02"></a><a name="en-us_topic_0000001059340516_ad7700957c924489f840d376805d97d02"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001059340516_a3b1e01fd33a04147894a7eb481c6896f"><a name="en-us_topic_0000001059340516_a3b1e01fd33a04147894a7eb481c6896f"></a><a name="en-us_topic_0000001059340516_a3b1e01fd33a04147894a7eb481c6896f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001059340516_a22ea63d9206e4496a5164158a4e4aa31"><a name="en-us_topic_0000001059340516_a22ea63d9206e4496a5164158a4e4aa31"></a><a name="en-us_topic_0000001059340516_a22ea63d9206e4496a5164158a4e4aa31"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001059340516_afcf4c75ba59a40c39e0b848df14c4b51"><a name="en-us_topic_0000001059340516_afcf4c75ba59a40c39e0b848df14c4b51"></a><a name="en-us_topic_0000001059340516_afcf4c75ba59a40c39e0b848df14c4b51"></a>Called when the dialog box is closed.</p>
    </td>
    </tr>
    </tbody>
    </table>

    The following value will be returned when the dialog box is displayed.

    <a name="en-us_topic_0000001059340516_t5f0df2fad0544e3eb458936109014414"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001059340516_rbe130c794ee1413ea7c736dac2a65bbd"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001059340516_a289c783f320744f18414bb29a696abba"><a name="en-us_topic_0000001059340516_a289c783f320744f18414bb29a696abba"></a><a name="en-us_topic_0000001059340516_a289c783f320744f18414bb29a696abba"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001059340516_a0ec0f99d9e094c5b9d097dde27508798"><a name="en-us_topic_0000001059340516_a0ec0f99d9e094c5b9d097dde27508798"></a><a name="en-us_topic_0000001059340516_a0ec0f99d9e094c5b9d097dde27508798"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="75%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001059340516_a57a576be84d146c38aa95aefcad0e486"><a name="en-us_topic_0000001059340516_a57a576be84d146c38aa95aefcad0e486"></a><a name="en-us_topic_0000001059340516_a57a576be84d146c38aa95aefcad0e486"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001059340516_r7a357c830bd44c65bfee22ddf64e4710"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059340516_a4417e83cb4b14c418eeaeff7669c77cd"><a name="en-us_topic_0000001059340516_a4417e83cb4b14c418eeaeff7669c77cd"></a><a name="en-us_topic_0000001059340516_a4417e83cb4b14c418eeaeff7669c77cd"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059340516_a27d628021f0f4a8f91b9a59bd00f7584"><a name="en-us_topic_0000001059340516_a27d628021f0f4a8f91b9a59bd00f7584"></a><a name="en-us_topic_0000001059340516_a27d628021f0f4a8f91b9a59bd00f7584"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="75%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059340516_aab61e7c297034494ab27e6ca91102568"><a name="en-us_topic_0000001059340516_aab61e7c297034494ab27e6ca91102568"></a><a name="en-us_topic_0000001059340516_aab61e7c297034494ab27e6ca91102568"></a>Index of the selected button in the buttons array</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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
        console.log('dialog success callback,click button : ' + data.index);
      },
      cancel: function() {
        console.log('dialog cancel callback');
      },
    });
    ```



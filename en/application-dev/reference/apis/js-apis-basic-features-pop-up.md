# Pop-up Window<a name="EN-US_TOPIC_0000001127125010"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 4. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Module to Import<a name="s1fada83813e64efcbc67e970ced86588"></a>

```
import prompt from '@system.prompt';
```

## Required Permissions<a name="section11257113618419"></a>

None

## prompt.showToast<a name="sc34d255befcf467dab069802dc9e54d8"></a>

showToast\(Object\): void

Displays the toast dialog box.

-   Parameter

    <a name="t1618141057434ca885c1586184c502e2"></a>
    <table><thead align="left"><tr id="r351c10438fad40de99efc195cc88296f"><th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.5.1.1"><p id="a1056691df28b470d9af0c2c2f964ff8f"><a name="a1056691df28b470d9af0c2c2f964ff8f"></a><a name="a1056691df28b470d9af0c2c2f964ff8f"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.000000000000002%" id="mcps1.1.5.1.2"><p id="aed30d84405424c6cb5cabbbdbe3e35a7"><a name="aed30d84405424c6cb5cabbbdbe3e35a7"></a><a name="aed30d84405424c6cb5cabbbdbe3e35a7"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="a854ad49fdbd34a1eb98a5757d01f7cfa"><a name="a854ad49fdbd34a1eb98a5757d01f7cfa"></a><a name="a854ad49fdbd34a1eb98a5757d01f7cfa"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="62%" id="mcps1.1.5.1.4"><p id="a34deb96a6ac2414eb11e2a7dd2142ebb"><a name="a34deb96a6ac2414eb11e2a7dd2142ebb"></a><a name="a34deb96a6ac2414eb11e2a7dd2142ebb"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="rae51f5fc5bda4e5992851196bad62e8e"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="ab4df9faf190145219b091959f5a62082"><a name="ab4df9faf190145219b091959f5a62082"></a><a name="ab4df9faf190145219b091959f5a62082"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="a0dad7be0aa3f4033bc91bb4f4331d843"><a name="a0dad7be0aa3f4033bc91bb4f4331d843"></a><a name="a0dad7be0aa3f4033bc91bb4f4331d843"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="a8e32b2d4bba64516b56edaf8d6bdfdfa"><a name="a8e32b2d4bba64516b56edaf8d6bdfdfa"></a><a name="a8e32b2d4bba64516b56edaf8d6bdfdfa"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="a4b2f4463435a4e1c96e831bca8bb40a3"><a name="a4b2f4463435a4e1c96e831bca8bb40a3"></a><a name="a4b2f4463435a4e1c96e831bca8bb40a3"></a>Text to display.</p>
    </td>
    </tr>
    <tr id="r4d2b81c5265a4d2e9029ea49c12f3cda"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="ae2ee7c33807f4c8fa9d454ca7fa679cb"><a name="ae2ee7c33807f4c8fa9d454ca7fa679cb"></a><a name="ae2ee7c33807f4c8fa9d454ca7fa679cb"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="aa3100e4a607749cba360f4386b71ada5"><a name="aa3100e4a607749cba360f4386b71ada5"></a><a name="aa3100e4a607749cba360f4386b71ada5"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="ab40203ebb13b4cd5a86d428fa5db381b"><a name="ab40203ebb13b4cd5a86d428fa5db381b"></a><a name="ab40203ebb13b4cd5a86d428fa5db381b"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="aac09f7fe897d4a80ab7160590b544e39"><a name="aac09f7fe897d4a80ab7160590b544e39"></a><a name="aac09f7fe897d4a80ab7160590b544e39"></a>Duration of the toast dialog box. The default value is <strong id="b9361121192413"><a name="b9361121192413"></a><a name="b9361121192413"></a>1500</strong>. The recommended value ranges from 1500 ms to 10000 ms.</p>
    <div class="note" id="note116191623191316"><a name="note116191623191316"></a><a name="note116191623191316"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1961942320133"><a name="p1961942320133"></a><a name="p1961942320133"></a>A value less than 1500 is automatically changed to 1500. The maximum value is 10000 ms.</p>
    </div></div>
    </td>
    </tr>
    <tr id="row62011935366"><td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.1 "><p id="p182018316365"><a name="p182018316365"></a><a name="p182018316365"></a>[bottom]<sup id="sup11448750123910"><a name="sup11448750123910"></a><a name="sup11448750123910"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.000000000000002%" headers="mcps1.1.5.1.2 "><p id="p82011839362"><a name="p82011839362"></a><a name="p82011839362"></a>&lt;length&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="p82021136362"><a name="p82021136362"></a><a name="p82021136362"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62%" headers="mcps1.1.5.1.4 "><p id="p1120212312365"><a name="p1120212312365"></a><a name="p1120212312365"></a>Distance between the dialog border and the bottom of the screen.</p>
    <div class="note" id="note1834105155712"><a name="note1834105155712"></a><a name="note1834105155712"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p10341651115711"><a name="p10341651115711"></a><a name="p10341651115711"></a>This parameter is only supported on phones and tablets.</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {    
      showToast() {        
        prompt.showToast({            
          message: 'Message Info',            
          duration: 2000,        
        });    
      }
    }
    ```


## prompt.showDialog<a name="sc6babedb391e4de9af1189ebc9ff5e69"></a>

showDialog\(\): void

Displays the dialog box.

-   Parameter

    <a name="t629832d7ad1f4f7e9ed380a6320a133e"></a>
    <table><thead align="left"><tr id="r166e1186bdbf45fe9775955b02b5e0cf"><th class="cellrowborder" valign="top" width="13.089999999999998%" id="mcps1.1.5.1.1"><p id="a274fde9345af4ec29d72d801d1c9463b"><a name="a274fde9345af4ec29d72d801d1c9463b"></a><a name="a274fde9345af4ec29d72d801d1c9463b"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.91%" id="mcps1.1.5.1.2"><p id="af6f12ca9f0dd44e98ee58e6dcc3a1edf"><a name="af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a><a name="af6f12ca9f0dd44e98ee58e6dcc3a1edf"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10%" id="mcps1.1.5.1.3"><p id="a48d51a6c05b9412b82b6b2a70fd7825b"><a name="a48d51a6c05b9412b82b6b2a70fd7825b"></a><a name="a48d51a6c05b9412b82b6b2a70fd7825b"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="65%" id="mcps1.1.5.1.4"><p id="afd08fb662a564651bc3cedbb9a05c0a5"><a name="afd08fb662a564651bc3cedbb9a05c0a5"></a><a name="afd08fb662a564651bc3cedbb9a05c0a5"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r868a28f8acc34af4916dd4ed453ebd09"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="a2714800437f24825bf30c198dc6aad56"><a name="a2714800437f24825bf30c198dc6aad56"></a><a name="a2714800437f24825bf30c198dc6aad56"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="a2620a53c20cc4d26af71b5eba3846e19"><a name="a2620a53c20cc4d26af71b5eba3846e19"></a><a name="a2620a53c20cc4d26af71b5eba3846e19"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="af7aacc8736d34a8ca12fb007d74fb110"><a name="af7aacc8736d34a8ca12fb007d74fb110"></a><a name="af7aacc8736d34a8ca12fb007d74fb110"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="a3c44052f536c4baead681acbce5dc790"><a name="a3c44052f536c4baead681acbce5dc790"></a><a name="a3c44052f536c4baead681acbce5dc790"></a>Title of the text to display.</p>
    </td>
    </tr>
    <tr id="r7d02820c4eaa48febfa636322c50c07f"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="af30a62497b5a41ad930718e1980632d9"><a name="af30a62497b5a41ad930718e1980632d9"></a><a name="af30a62497b5a41ad930718e1980632d9"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="a942a00c302c842269dd974188e8d72cf"><a name="a942a00c302c842269dd974188e8d72cf"></a><a name="a942a00c302c842269dd974188e8d72cf"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="aea0eec373d7d4fe8807a4e3c300487fb"><a name="aea0eec373d7d4fe8807a4e3c300487fb"></a><a name="aea0eec373d7d4fe8807a4e3c300487fb"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="ae42b17323a00403ca1682cb29424b935"><a name="ae42b17323a00403ca1682cb29424b935"></a><a name="ae42b17323a00403ca1682cb29424b935"></a>Text body.</p>
    </td>
    </tr>
    <tr id="r9051c3a4fdfd4242bbbba1362a30c32b"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="ad7a64f8d6a414ce992ee8ad5b737d820"><a name="ad7a64f8d6a414ce992ee8ad5b737d820"></a><a name="ad7a64f8d6a414ce992ee8ad5b737d820"></a>buttons</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="ae4ecdedd56eb4bb3a113aa7945576bfc"><a name="ae4ecdedd56eb4bb3a113aa7945576bfc"></a><a name="ae4ecdedd56eb4bb3a113aa7945576bfc"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="a348857f0f8674fa88b08c4b43cf59923"><a name="a348857f0f8674fa88b08c4b43cf59923"></a><a name="a348857f0f8674fa88b08c4b43cf59923"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="ab6529e91fe1d4adc8cb3fa2e531369a9"><a name="ab6529e91fe1d4adc8cb3fa2e531369a9"></a><a name="ab6529e91fe1d4adc8cb3fa2e531369a9"></a>Array of buttons in the dialog box. The array structure is <strong id="b12386125113268"><a name="b12386125113268"></a><a name="b12386125113268"></a>{text:'button', color: '#666666'}</strong>. One to three buttons are supported. The first button is of the <strong id="b192581358288"><a name="b192581358288"></a><a name="b192581358288"></a>positiveButton</strong> type, the second is of the <strong id="b117326710282"><a name="b117326710282"></a><a name="b117326710282"></a>negativeButton</strong> type, and the third is of the <strong id="b4971171010297"><a name="b4971171010297"></a><a name="b4971171010297"></a>neutralButton</strong> type.</p>
    </td>
    </tr>
    <tr id="rf2d176102f6547949a74deb1746d440e"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="abe7e018a2dac47079db426b424b2031f"><a name="abe7e018a2dac47079db426b424b2031f"></a><a name="abe7e018a2dac47079db426b424b2031f"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="a9061f42dad6d4ed8a81a147022ce7c68"><a name="a9061f42dad6d4ed8a81a147022ce7c68"></a><a name="a9061f42dad6d4ed8a81a147022ce7c68"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="a05153a00a5ae4a2992deb337387d9cfc"><a name="a05153a00a5ae4a2992deb337387d9cfc"></a><a name="a05153a00a5ae4a2992deb337387d9cfc"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="a986abb2e067742f3b9fe575e7cbd0224"><a name="a986abb2e067742f3b9fe575e7cbd0224"></a><a name="a986abb2e067742f3b9fe575e7cbd0224"></a>Called when the dialog box is displayed. For the return value, see <a href="#t5f0df2fad0544e3eb458936109014414">return values of the success callback</a>.</p>
    </td>
    </tr>
    <tr id="r26d54c4b23944b7bb7950c87b836b1c2"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="af1a6df8907754b7b95f6a7dd6eef3f81"><a name="af1a6df8907754b7b95f6a7dd6eef3f81"></a><a name="af1a6df8907754b7b95f6a7dd6eef3f81"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="ac8d3e854d1034a9da3f463f1d045c06f"><a name="ac8d3e854d1034a9da3f463f1d045c06f"></a><a name="ac8d3e854d1034a9da3f463f1d045c06f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="a5aa033ed47de41c6890699434eb179ab"><a name="a5aa033ed47de41c6890699434eb179ab"></a><a name="a5aa033ed47de41c6890699434eb179ab"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="a08b61cefc2cb4fed83e6ef32d9056fa7"><a name="a08b61cefc2cb4fed83e6ef32d9056fa7"></a><a name="a08b61cefc2cb4fed83e6ef32d9056fa7"></a>Called when the operation is cancelled.</p>
    </td>
    </tr>
    <tr id="r5bd94b2812be49fc9cc884b39815638c"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="ad7700957c924489f840d376805d97d02"><a name="ad7700957c924489f840d376805d97d02"></a><a name="ad7700957c924489f840d376805d97d02"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.2 "><p id="a3b1e01fd33a04147894a7eb481c6896f"><a name="a3b1e01fd33a04147894a7eb481c6896f"></a><a name="a3b1e01fd33a04147894a7eb481c6896f"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10%" headers="mcps1.1.5.1.3 "><p id="a22ea63d9206e4496a5164158a4e4aa31"><a name="a22ea63d9206e4496a5164158a4e4aa31"></a><a name="a22ea63d9206e4496a5164158a4e4aa31"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="65%" headers="mcps1.1.5.1.4 "><p id="afcf4c75ba59a40c39e0b848df14c4b51"><a name="afcf4c75ba59a40c39e0b848df14c4b51"></a><a name="afcf4c75ba59a40c39e0b848df14c4b51"></a>Called when the dialog box is closed.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Return values of the  **success**  callback

    <a name="t5f0df2fad0544e3eb458936109014414"></a>
    <table><thead align="left"><tr id="rbe130c794ee1413ea7c736dac2a65bbd"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.4.1.1"><p id="a289c783f320744f18414bb29a696abba"><a name="a289c783f320744f18414bb29a696abba"></a><a name="a289c783f320744f18414bb29a696abba"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.1.4.1.2"><p id="a0ec0f99d9e094c5b9d097dde27508798"><a name="a0ec0f99d9e094c5b9d097dde27508798"></a><a name="a0ec0f99d9e094c5b9d097dde27508798"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="75%" id="mcps1.1.4.1.3"><p id="a57a576be84d146c38aa95aefcad0e486"><a name="a57a576be84d146c38aa95aefcad0e486"></a><a name="a57a576be84d146c38aa95aefcad0e486"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r7a357c830bd44c65bfee22ddf64e4710"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.4.1.1 "><p id="a4417e83cb4b14c418eeaeff7669c77cd"><a name="a4417e83cb4b14c418eeaeff7669c77cd"></a><a name="a4417e83cb4b14c418eeaeff7669c77cd"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.4.1.2 "><p id="a27d628021f0f4a8f91b9a59bd00f7584"><a name="a27d628021f0f4a8f91b9a59bd00f7584"></a><a name="a27d628021f0f4a8f91b9a59bd00f7584"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="75%" headers="mcps1.1.4.1.3 "><p id="aab61e7c297034494ab27e6ca91102568"><a name="aab61e7c297034494ab27e6ca91102568"></a><a name="aab61e7c297034494ab27e6ca91102568"></a>Index of the selected button in the buttons array</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {    
      showDialog() {       
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
      }
    }
    ```


## prompt.showActionMenu<sup>6+</sup><a name="section151752203513"></a>

showActionMenu\(Object\): void

Displays the operation menu.

-   Parameters

    <a name="table71817293515"></a>
    <table><thead align="left"><tr id="row61820263513"><th class="cellrowborder" valign="top" width="13.089999999999998%" id="mcps1.1.5.1.1"><p id="p518192173514"><a name="p518192173514"></a><a name="p518192173514"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.8%" id="mcps1.1.5.1.2"><p id="p518132193511"><a name="p518132193511"></a><a name="p518132193511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.46%" id="mcps1.1.5.1.3"><p id="p91872143516"><a name="p91872143516"></a><a name="p91872143516"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.5.1.4"><p id="p10188253515"><a name="p10188253515"></a><a name="p10188253515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10181213517"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="p41822163517"><a name="p41822163517"></a><a name="p41822163517"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="p1419923354"><a name="p1419923354"></a><a name="p1419923354"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="p1419927355"><a name="p1419927355"></a><a name="p1419927355"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p201915217358"><a name="p201915217358"></a><a name="p201915217358"></a>Title of the text to display.</p>
    </td>
    </tr>
    <tr id="row61902173517"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="p101914223513"><a name="p101914223513"></a><a name="p101914223513"></a>buttons</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="p4191122359"><a name="p4191122359"></a><a name="p4191122359"></a>Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="p101992133516"><a name="p101992133516"></a><a name="p101992133516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p191911293517"><a name="p191911293517"></a><a name="p191911293517"></a>Array of buttons in the dialog box. The array structure is <strong id="b195031228114514"><a name="b195031228114514"></a><a name="b195031228114514"></a>{text:'button', color: '#666666'}</strong>. One to six buttons are supported. If there are more than six buttons, the pop-up window will not be displayed.</p>
    </td>
    </tr>
    <tr id="row14194216353"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="p720192133513"><a name="p720192133513"></a><a name="p720192133513"></a>success</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="p102012103515"><a name="p102012103515"></a><a name="p102012103515"></a>(data: <a href="#table14215283515">TapIndex</a>) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="p52082183517"><a name="p52082183517"></a><a name="p52082183517"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p920321358"><a name="p920321358"></a><a name="p920321358"></a>Called when the operation is successful.</p>
    </td>
    </tr>
    <tr id="row120528354"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="p15201253516"><a name="p15201253516"></a><a name="p15201253516"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="p22213478481"><a name="p22213478481"></a><a name="p22213478481"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="p32010212359"><a name="p32010212359"></a><a name="p32010212359"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p5205218353"><a name="p5205218353"></a><a name="p5205218353"></a>Called when the operation fails.</p>
    </td>
    </tr>
    <tr id="row1320520356"><td class="cellrowborder" valign="top" width="13.089999999999998%" headers="mcps1.1.5.1.1 "><p id="p18206219351"><a name="p18206219351"></a><a name="p18206219351"></a>complete</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.5.1.2 "><p id="p1870474764820"><a name="p1870474764820"></a><a name="p1870474764820"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.5.1.3 "><p id="p112119212353"><a name="p112119212353"></a><a name="p112119212353"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p192110273519"><a name="p192110273519"></a><a name="p192110273519"></a>Called when the operation is complete.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  TapIndex

    <a name="table14215283515"></a>
    <table><thead align="left"><tr id="row20211228358"><th class="cellrowborder" valign="top" width="13%" id="mcps1.2.4.1.1"><p id="p92112215358"><a name="p92112215358"></a><a name="p92112215358"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12%" id="mcps1.2.4.1.2"><p id="p12112216351"><a name="p12112216351"></a><a name="p12112216351"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="75%" id="mcps1.2.4.1.3"><p id="p7211420357"><a name="p7211420357"></a><a name="p7211420357"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row162172113511"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.4.1.1 "><p id="p6218203514"><a name="p6218203514"></a><a name="p6218203514"></a>tapIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="12%" headers="mcps1.2.4.1.2 "><p id="p32220217352"><a name="p32220217352"></a><a name="p32220217352"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="75%" headers="mcps1.2.4.1.3 "><p id="p16221326352"><a name="p16221326352"></a><a name="p16221326352"></a>Index of the selected button in the buttons array, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {    
      showActionMenu() {        
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
            console.log('Operation succeeded. Click button: ' + data.tapIndex);            
          },            
          fail: function(data) {                
            console.log('Operation failed' + data.errMsg);            
          },       
        });    
      }
    }
    ```



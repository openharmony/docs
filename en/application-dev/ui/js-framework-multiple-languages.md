# Multi-Language Capability<a name="EN-US_TOPIC_0000001173324681"></a>

Applications designed based on the JS UI framework apply to different countries and regions. With the multi-language capability, you do not need to develop application versions in different languages, and your users can switch between various locales. This also facilitates project maintenance.

You only need to perform operations in  [Resource Files](#section733935013515)  and  [Resource Reference](#section522111116527)  to use the multi-language capability of this framework. For details about how to obtain the current system language, see  [Language Acquisition](#section2872192475310).

## Resource Files<a name="section733935013515"></a>

Resource files store application content in multiple languages. This framework uses JSON files to store resource definitions. Place the resource file of each locale in the  **i18n**  directory described in  [File Organization](js-framework-file.md). 

Resource files should be named in  _language-script-region_**.json**  format. For example, the resource file for Hong Kong Chinese in the traditional script is named  **zh-Hant-HK**. You can omit the region, for example,  **zh-CN**  for simplified Chinese, or omit both the script and region, for example,  **zh**  for Chinese.

```
language[-script-region].json
```

The following table describes the requirements for the qualifiers of resource file names.

**Table  1**  Requirements for qualifier values

<a name="table18887936123715"></a>
<table><thead align="left"><tr id="row1288893623719"><th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001062847941_p933162572513"><a name="en-us_topic_0000001062847941_p933162572513"></a><a name="en-us_topic_0000001062847941_p933162572513"></a>Qualifier Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.7%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001062847941_p0331102502517"><a name="en-us_topic_0000001062847941_p0331102502517"></a><a name="en-us_topic_0000001062847941_p0331102502517"></a>Description and Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row198881636143719"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001062847941_p5331192542519"><a name="en-us_topic_0000001062847941_p5331192542519"></a><a name="en-us_topic_0000001062847941_p5331192542519"></a>Language</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001062847941_p19331625202513"><a name="en-us_topic_0000001062847941_p19331625202513"></a><a name="en-us_topic_0000001062847941_p19331625202513"></a>Indicates the language used by the device. The value consists of two or three lowercase letters, for example, <strong id="en-us_topic_0000001062847941_b576443512210"><a name="en-us_topic_0000001062847941_b576443512210"></a><a name="en-us_topic_0000001062847941_b576443512210"></a>zh</strong> indicates Chinese, <strong id="en-us_topic_0000001062847941_b182198414218"><a name="en-us_topic_0000001062847941_b182198414218"></a><a name="en-us_topic_0000001062847941_b182198414218"></a>en</strong> indicates English, and <strong id="en-us_topic_0000001062847941_b157701569717"><a name="en-us_topic_0000001062847941_b157701569717"></a><a name="en-us_topic_0000001062847941_b157701569717"></a>mai</strong> indicates Maithili.</p>
<p id="en-us_topic_0000001062847941_p633232516255"><a name="en-us_topic_0000001062847941_p633232516255"></a><a name="en-us_topic_0000001062847941_p633232516255"></a>For details about the value range, refer to <strong id="en-us_topic_0000001062847941_b4332142515256"><a name="en-us_topic_0000001062847941_b4332142515256"></a><a name="en-us_topic_0000001062847941_b4332142515256"></a>ISO 639</strong> (codes for the representation of names of languages).</p>
</td>
</tr>
<tr id="row5888133693714"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001062847941_p14332112518252"><a name="en-us_topic_0000001062847941_p14332112518252"></a><a name="en-us_topic_0000001062847941_p14332112518252"></a>Script</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001062847941_p9332192522510"><a name="en-us_topic_0000001062847941_p9332192522510"></a><a name="en-us_topic_0000001062847941_p9332192522510"></a>Indicates the script type used by the device. The value starts with one uppercase letter followed by three lowercase letters, for example, <strong id="en-us_topic_0000001062847941_b61243486306"><a name="en-us_topic_0000001062847941_b61243486306"></a><a name="en-us_topic_0000001062847941_b61243486306"></a>Hans</strong> indicates simplified Chinese and <strong id="en-us_topic_0000001062847941_b1643275214309"><a name="en-us_topic_0000001062847941_b1643275214309"></a><a name="en-us_topic_0000001062847941_b1643275214309"></a>Hant</strong> indicates traditional Chinese.</p>
<p id="en-us_topic_0000001062847941_p20332152582517"><a name="en-us_topic_0000001062847941_p20332152582517"></a><a name="en-us_topic_0000001062847941_p20332152582517"></a>For details about the value range, refer to <strong id="en-us_topic_0000001062847941_b986482862513"><a name="en-us_topic_0000001062847941_b986482862513"></a><a name="en-us_topic_0000001062847941_b986482862513"></a>ISO 15924</strong> (codes for the representation of names of scripts).</p>
</td>
</tr>
<tr id="row1888143616376"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001062847941_p18332825152513"><a name="en-us_topic_0000001062847941_p18332825152513"></a><a name="en-us_topic_0000001062847941_p18332825152513"></a>Country/Region</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001062847941_p133212251255"><a name="en-us_topic_0000001062847941_p133212251255"></a><a name="en-us_topic_0000001062847941_p133212251255"></a>Indicates the country or region where a user is located. The value consists of two or three uppercase letters or three digits, for example, <strong id="en-us_topic_0000001062847941_b12684139103216"><a name="en-us_topic_0000001062847941_b12684139103216"></a><a name="en-us_topic_0000001062847941_b12684139103216"></a>CN</strong> indicates China and <strong id="en-us_topic_0000001062847941_b2349716183218"><a name="en-us_topic_0000001062847941_b2349716183218"></a><a name="en-us_topic_0000001062847941_b2349716183218"></a>GB</strong> indicates the United Kingdom.</p>
<p id="en-us_topic_0000001062847941_p5332925172513"><a name="en-us_topic_0000001062847941_p5332925172513"></a><a name="en-us_topic_0000001062847941_p5332925172513"></a>For details about the value range, refer to <strong id="en-us_topic_0000001062847941_b633242532515"><a name="en-us_topic_0000001062847941_b633242532515"></a><a name="en-us_topic_0000001062847941_b633242532515"></a>ISO 3166-1</strong> (codes for the representation of names of countries and their subdivisions).</p>
</td>
</tr>
</tbody>
</table>

If there is no resource file of the locale that matches the system language, content in the  **en-US.json**  file will be used by default.

The format of the resource file content is as follows:

en-US.json

```
{
    "strings": {
        "hello": "Hello world!",
        "object": "Object parameter substitution-{name}",
        "array": "Array type parameter substitution-{0}",
        "symbol": "@#$%^&*()_+-={}[]\\|:;\"'<>,./?"
    },

    "files": {
        "image": "image/en_picture.PNG"
    }
}
```

Different languages have different matching rules for singular and plural forms. In the resource file,  **zero**,  **one**,  **two**,  **few**,  **many**, and  **other**  are used to define the string content in different singular and plural forms. For example, there is only the  **other**  scenario in Chinese since the language does not have singular and plural forms.  **one**  and  **other**  scenarios are applicable to English. All six scenarios are needed for Arabic.

The following example takes  **en-US.json**  and  **ar-AE.json**  as examples:

en-US.json

```
{
    "strings": {
        "people": {
            "one": "one person",
            "other": "{count} people"
        }
    }
}
```

ar-AE.json

```
{
    "strings": {
        "people": {
            "zero": "لا أحد",
            "one": "وحده",
            "two": "اثنان",
            "few": "ستة اشخاص",
            "many": "خمسون شخص",
            "other": "مائة شخص"
        }
    }
}
```

## Resource Reference<a name="section522111116527"></a>

Multi-language syntax used on application development pages \(including simple formatting and singular-plural formatting\) can be used in  **.hml**  or  **.js**  files.

-   Simple formatting

    Use the  **$t**  function to reference to resources of different locales. The  **$t**  function is available for both  **.hml**  and  **.js**  files. The system displays content based on a resource file path specified via  **$t**  and the specified resource file whose locale matches the current system language.

    **Table  2**  Simple formatting

    <a name="table10506333184710"></a>
    <table><thead align="left"><tr id="row1250615336479"><th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.1"><p id="p14506163314479"><a name="p14506163314479"></a><a name="p14506163314479"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.2"><p id="p205076333474"><a name="p205076333474"></a><a name="p205076333474"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.85%" id="mcps1.2.6.1.3"><p id="p250773354718"><a name="p250773354718"></a><a name="p250773354718"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.790000000000001%" id="mcps1.2.6.1.4"><p id="p5742204362716"><a name="p5742204362716"></a><a name="p5742204362716"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.5"><p id="p105079331472"><a name="p105079331472"></a><a name="p105079331472"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1550713344719"><td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.1 "><p id="p185071433174714"><a name="p185071433174714"></a><a name="p185071433174714"></a>$t</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.2 "><p id="p10507193304718"><a name="p10507193304718"></a><a name="p10507193304718"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.85%" headers="mcps1.2.6.1.3 "><p id="p69461437131511"><a name="p69461437131511"></a><a name="p69461437131511"></a>See <a href="#table1161115496137">Table 3</a>.</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.790000000000001%" headers="mcps1.2.6.1.4 "><p id="p1991117447"><a name="p1991117447"></a><a name="p1991117447"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.5 "><p id="p1150753310476"><a name="p1150753310476"></a><a name="p1150753310476"></a>Sets the parameters based on the system language, for example, <strong id="b15165861155"><a name="b15165861155"></a><a name="b15165861155"></a>this.$t('strings.hello')</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  3**  $t function parameters

    <a name="table1161115496137"></a>
    <table><thead align="left"><tr id="row1061274917131"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p166121249131312"><a name="p166121249131312"></a><a name="p166121249131312"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p261213498139"><a name="p261213498139"></a><a name="p261213498139"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p15612124910139"><a name="p15612124910139"></a><a name="p15612124910139"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1061274951318"><a name="p1061274951318"></a><a name="p1061274951318"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15612749191317"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p161215495131"><a name="p161215495131"></a><a name="p161215495131"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p176121049101318"><a name="p176121049101318"></a><a name="p176121049101318"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p8612144917136"><a name="p8612144917136"></a><a name="p8612144917136"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p161254911314"><a name="p161254911314"></a><a name="p161254911314"></a>Path of the language resource key</p>
    </td>
    </tr>
    <tr id="row861264931319"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p15612449181316"><a name="p15612449181316"></a><a name="p15612449181316"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p496164415306"><a name="p496164415306"></a><a name="p496164415306"></a>Array|Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p861284917131"><a name="p861284917131"></a><a name="p861284917131"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p20612194931313"><a name="p20612194931313"></a><a name="p20612194931313"></a>Content used to replace placeholders during runtime. There are two types of placeholders available:</p>
    <a name="ul0124131652619"></a><a name="ul0124131652619"></a><ul id="ul0124131652619"><li>Named placeholder, for example, <strong id="b1393217204415"><a name="b1393217204415"></a><a name="b1393217204415"></a>{name}</strong>. The actual content must be of the object type, for example, <strong id="b1190152717414"><a name="b1190152717414"></a><a name="b1190152717414"></a>$t('strings.object', { name: 'Hello world' })</strong>.</li><li>Digit placeholder, for example, <strong id="b64091832204118"><a name="b64091832204118"></a><a name="b64091832204118"></a>{0}</strong>. The actual content must be of the array type, for example, <strong id="b18296193544116"><a name="b18296193544116"></a><a name="b18296193544116"></a>$t('strings.array', ['Hello world']</strong>.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example code for simple formatting

    ```
    <!-- xxx.hml -->
    <div>
      <!-- Display Hello world! without using a placeholder. -->
      <text>{{ $t('strings.hello') }}</text>
      <!-- Replace named placeholder {name} with Hello world and display it. -->
      <text>{{ $t('strings.object', { name: 'Hello world' }) }}</text>
      <!-- Replace digit placeholder {0} with Hello world and display it. -->
      <text>{{ $t('strings.array', ['Hello world']) }}</text>
      <!-- Obtain the resource content from the .js file and display Hello world. -->
      <text>{{ hello }}</text>
      <!-- Obtain the resource content from the .js file, replace named placeholder {name} with Hello world, and display Substitution in an object: Hello world. -->
      <text>{{ replaceObject }}</text>
      <!-- Obtain the resource content from the .js file, replace digit placeholder {0} with Hello world, and display Substitution in an array: Hello world. -->
      <text>{{ replaceArray }}</text>
    
      <!-- Display the image in the specified file path. -->
      <image src="{{ $t('files.image') }}" class="image"></image>
      <!-- Obtain the image file path from the .js file and display the image. -->
      <image src="{{ replaceSrc }}" class="image"></image>
    </div>
    ```

    ```
    // xxx.js
    // The following example uses the $t function in the .js file.
    export default {
      data: {
        hello: '',
        replaceObject: '',
        replaceArray: '',
        replaceSrc: '',
      },
      onInit() {
        this.hello = this.$t('strings.hello');
        this.replaceObject = this.$t('strings.object', { name: 'Hello world' });
        this.replaceArray = this.$t('strings.array', ['Hello world']);
        this.replaceSrc = this.$t('files.image');
      },   
    }
    ```

-   Singular-plural formatting

    **Table  4**  Singular-plural formatting

    <a name="table12722349115211"></a>
    <table><thead align="left"><tr id="row11723204985215"><th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.1"><p id="p9723749145217"><a name="p9723749145217"></a><a name="p9723749145217"></a>Attribute</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.2"><p id="p1372374910528"><a name="p1372374910528"></a><a name="p1372374910528"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.790000000000003%" id="mcps1.2.6.1.3"><p id="p1272314496527"><a name="p1272314496527"></a><a name="p1272314496527"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.850000000000001%" id="mcps1.2.6.1.4"><p id="p39561320202915"><a name="p39561320202915"></a><a name="p39561320202915"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.12%" id="mcps1.2.6.1.5"><p id="p12723124915528"><a name="p12723124915528"></a><a name="p12723124915528"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167231749155214"><td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.1 "><p id="p15723184945217"><a name="p15723184945217"></a><a name="p15723184945217"></a>$tc</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.2 "><p id="p1372310494525"><a name="p1372310494525"></a><a name="p1372310494525"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.790000000000003%" headers="mcps1.2.6.1.3 "><p id="p3645417495"><a name="p3645417495"></a><a name="p3645417495"></a>See <a href="#table1856962321614">Table 5</a>.</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.850000000000001%" headers="mcps1.2.6.1.4 "><p id="p1589916493474"><a name="p1589916493474"></a><a name="p1589916493474"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.12%" headers="mcps1.2.6.1.5 "><p id="p1080910112617"><a name="p1080910112617"></a><a name="p1080910112617"></a>Converts between the singular and plural forms based on the system language, for example, <strong id="b2975753182417"><a name="b2975753182417"></a><a name="b2975753182417"></a>this.$tc('strings.people')</strong>.</p>
    <div class="note" id="note44962033184817"><a name="note44962033184817"></a><a name="note44962033184817"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1456045614402"><a name="p1456045614402"></a><a name="p1456045614402"></a>The resource content is distinguished by the following JSON keys: <strong id="b682311541227"><a name="b682311541227"></a><a name="b682311541227"></a>zero</strong>, <strong id="b6176092310"><a name="b6176092310"></a><a name="b6176092310"></a>one</strong>, <strong id="b6135846238"><a name="b6135846238"></a><a name="b6135846238"></a>two</strong>, <strong id="b83625772314"><a name="b83625772314"></a><a name="b83625772314"></a>few</strong>, <strong id="b06791310172315"><a name="b06791310172315"></a><a name="b06791310172315"></a>many</strong>, and <strong id="b31161315112320"><a name="b31161315112320"></a><a name="b31161315112320"></a>other</strong>.</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  5**  $tc function parameters

    <a name="table1856962321614"></a>
    <table><thead align="left"><tr id="row13569122391616"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p135698238163"><a name="p135698238163"></a><a name="p135698238163"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p17569152311168"><a name="p17569152311168"></a><a name="p17569152311168"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1569523171613"><a name="p1569523171613"></a><a name="p1569523171613"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p2569192341613"><a name="p2569192341613"></a><a name="p2569192341613"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row056919234163"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p175691923171610"><a name="p175691923171610"></a><a name="p175691923171610"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p11569182319162"><a name="p11569182319162"></a><a name="p11569182319162"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p93611250151616"><a name="p93611250151616"></a><a name="p93611250151616"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p145691323171620"><a name="p145691323171620"></a><a name="p145691323171620"></a>Path of the language resource key</p>
    </td>
    </tr>
    <tr id="row1569142351616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p956911235161"><a name="p956911235161"></a><a name="p956911235161"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7569182321618"><a name="p7569182321618"></a><a name="p7569182321618"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p6377550111614"><a name="p6377550111614"></a><a name="p6377550111614"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1556962371614"><a name="p1556962371614"></a><a name="p1556962371614"></a>Number</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Sample code for singular-plural formatting

    ```
    <!--xxx.hml-->
    <div>
      <!-- When the value 0 is passed, "0 people" matches the Arabic string whose key is zero. -->
      <text>{{ $tc('strings.people', 0) }}</text>
      <!-- When the value 1 is passed, "1 person" matches the Arabic string whose key is one. -->
      <text>{{ $tc('strings.people', 1) }}</text>
      <!-- When the value 2 is passed, "2 people" matches the Arabic string whose key is two. -->
      <text>{{ $tc('strings.people', 2) }}</text>
      <!-- When the value 6 is passed, "6 people" matches the Arabic string whose key is few. -->
      <text>{{ $tc('strings.people', 6) }}</text>
      <!-- When the value 50 is passed, "50 people" matches the Arabic string whose key is many. -->
      <text>{{ $tc('strings.people', 50) }}</text>
      <!-- When the value 100 is passed, "100 people" matches the Arabic string whose key is other. -->
      <text>{{ $tc('strings.people', 100) }}</text>
    </div>
    ```


## Language Acquisition<a name="section2872192475310"></a>

For details about how to obtain the language, see the  [Application Configuration](../reference/apis/js-apis-basic-features-configuration.md)  section.


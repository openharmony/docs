# 多语言支持<a name="ZH-CN_TOPIC_0000001173324681"></a>

基于开发框架的应用会覆盖多个国家和地区，开发框架支持多语言能力后，可以让应用开发者无需开发多个不同语言的版本，就可以同时支持多种语言的切换，为项目维护带来便利。

开发者仅需要通过[定义资源文件](#section733935013515)和[引用资源](#section522111116527)两个步骤，就可以使用开发框架的多语言能力；如果需要在应用中获取当前系统语言，请参考[获取语言](#section2872192475310)。

## 定义资源文件<a name="section733935013515"></a>

资源文件用于存放应用在多种语言场景下的资源内容，开发框架使用JSON文件保存资源定义。在[文件组织](js-framework-file.md)中指定的i18n文件夹内放置语言资源文件，其中语言资源文件的命名是由语言、文字、国家或地区的限定词通过中划线连接组成，其中文字和国家或地区可以省略，如zh-Hant-HK（中国香港地区使用的繁体中文）、zh-CN（中国使用的简体中文）、zh（中文）。命名规则如下：

```
language[-script-region].json
```

限定词的取值需符合下表要求。

**表 1**  限定词取值要求

<a name="table18887936123715"></a>
<table><thead align="left"><tr id="row1288893623719"><th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001062847941_p933162572513"><a name="zh-cn_topic_0000001062847941_p933162572513"></a><a name="zh-cn_topic_0000001062847941_p933162572513"></a>限定词类型</p>
</th>
<th class="cellrowborder" valign="top" width="83.7%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001062847941_p0331102502517"><a name="zh-cn_topic_0000001062847941_p0331102502517"></a><a name="zh-cn_topic_0000001062847941_p0331102502517"></a>含义与取值说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row198881636143719"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001062847941_p5331192542519"><a name="zh-cn_topic_0000001062847941_p5331192542519"></a><a name="zh-cn_topic_0000001062847941_p5331192542519"></a>语言</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001062847941_p19331625202513"><a name="zh-cn_topic_0000001062847941_p19331625202513"></a><a name="zh-cn_topic_0000001062847941_p19331625202513"></a>表示设备使用的语言类型，由2~3个小写字母组成。例如：zh表示中文，en表示英语，mai表示迈蒂利语。</p>
<p id="zh-cn_topic_0000001062847941_p633232516255"><a name="zh-cn_topic_0000001062847941_p633232516255"></a><a name="zh-cn_topic_0000001062847941_p633232516255"></a>详细取值范围，请查阅<strong id="zh-cn_topic_0000001062847941_b4332142515256"><a name="zh-cn_topic_0000001062847941_b4332142515256"></a><a name="zh-cn_topic_0000001062847941_b4332142515256"></a>ISO 639</strong>（ISO制定的语言编码标准）。</p>
</td>
</tr>
<tr id="row5888133693714"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001062847941_p14332112518252"><a name="zh-cn_topic_0000001062847941_p14332112518252"></a><a name="zh-cn_topic_0000001062847941_p14332112518252"></a>文字</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001062847941_p9332192522510"><a name="zh-cn_topic_0000001062847941_p9332192522510"></a><a name="zh-cn_topic_0000001062847941_p9332192522510"></a>表示设备使用的文字类型，由1个大写字母（首字母）和3个小写字母组成。例如：Hans表示简体中文，Hant表示繁体中文。</p>
<p id="zh-cn_topic_0000001062847941_p20332152582517"><a name="zh-cn_topic_0000001062847941_p20332152582517"></a><a name="zh-cn_topic_0000001062847941_p20332152582517"></a>详细取值范围，请查阅<strong id="zh-cn_topic_0000001062847941_b16332162512255"><a name="zh-cn_topic_0000001062847941_b16332162512255"></a><a name="zh-cn_topic_0000001062847941_b16332162512255"></a>ISO 15924</strong>（ISO制定的文字编码标准）。</p>
</td>
</tr>
<tr id="row1888143616376"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001062847941_p18332825152513"><a name="zh-cn_topic_0000001062847941_p18332825152513"></a><a name="zh-cn_topic_0000001062847941_p18332825152513"></a>国家或地区</p>
</td>
<td class="cellrowborder" valign="top" width="83.7%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001062847941_p133212251255"><a name="zh-cn_topic_0000001062847941_p133212251255"></a><a name="zh-cn_topic_0000001062847941_p133212251255"></a>表示用户所在的国家或地区，由2~3个大写字母或者3个数字组成。例如：CN表示中国，GB表示英国。</p>
<p id="zh-cn_topic_0000001062847941_p5332925172513"><a name="zh-cn_topic_0000001062847941_p5332925172513"></a><a name="zh-cn_topic_0000001062847941_p5332925172513"></a>详细取值范围，请查阅<strong id="zh-cn_topic_0000001062847941_b633242532515"><a name="zh-cn_topic_0000001062847941_b633242532515"></a><a name="zh-cn_topic_0000001062847941_b633242532515"></a>ISO 3166-1</strong>（ISO制定的国家和地区编码标准）。</p>
</td>
</tr>
</tbody>
</table>

当开发框架无法在应用中找到系统语言的资源文件时，默认使用en-US.json中的资源内容。

资源文件内容格式如下：

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

由于不同语言针对单复数有不同的匹配规则，在资源文件中使用“zero”“one”“two”“few”“many”“other”定义不同单复数场景下的词条内容。例如中文不区分单复数，仅存在“other”场景；英文存在“one”、“other”场景；阿拉伯语存在上述6种场景。

以en-US.json和ar-AE.json为例，资源文件内容格式如下：

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

## 引用资源<a name="section522111116527"></a>

在应用开发的页面中使用多语言的语法，包含简单格式化和单复数格式化两种，都可以在hml或js中使用。

-   简单格式化方法

    在应用中使用$t方法引用资源，$t既可以在hml中使用，也可以在js中使用。系统将根据当前语言环境和指定的资源路径（通过$t的path参数设置），显示对应语言的资源文件中的内容。

    **表 2**  简单格式化

    <a name="table10506333184710"></a>
    <table><thead align="left"><tr id="row1250615336479"><th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.1"><p id="p14506163314479"><a name="p14506163314479"></a><a name="p14506163314479"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.040000000000001%" id="mcps1.2.6.1.2"><p id="p205076333474"><a name="p205076333474"></a><a name="p205076333474"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="24%" id="mcps1.2.6.1.3"><p id="p250773354718"><a name="p250773354718"></a><a name="p250773354718"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.600000000000001%" id="mcps1.2.6.1.4"><p id="p5742204362716"><a name="p5742204362716"></a><a name="p5742204362716"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.12%" id="mcps1.2.6.1.5"><p id="p105079331472"><a name="p105079331472"></a><a name="p105079331472"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1550713344719"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.1 "><p id="p185071433174714"><a name="p185071433174714"></a><a name="p185071433174714"></a>$t</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.040000000000001%" headers="mcps1.2.6.1.2 "><p id="p10507193304718"><a name="p10507193304718"></a><a name="p10507193304718"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="24%" headers="mcps1.2.6.1.3 "><p id="p69461437131511"><a name="p69461437131511"></a><a name="p69461437131511"></a>请见<a href="#table1161115496137">表3</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="13.600000000000001%" headers="mcps1.2.6.1.4 "><p id="p1991117447"><a name="p1991117447"></a><a name="p1991117447"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.12%" headers="mcps1.2.6.1.5 "><p id="p1150753310476"><a name="p1150753310476"></a><a name="p1150753310476"></a>根据系统语言完成简单的替换：this.$t('strings.hello')</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 3**  $t参数说明

    <a name="table1161115496137"></a>
    <table><thead align="left"><tr id="row1061274917131"><th class="cellrowborder" valign="top" width="12%" id="mcps1.2.5.1.1"><p id="p166121249131312"><a name="p166121249131312"></a><a name="p166121249131312"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.119999999999997%" id="mcps1.2.5.1.2"><p id="p261213498139"><a name="p261213498139"></a><a name="p261213498139"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.32%" id="mcps1.2.5.1.3"><p id="p15612124910139"><a name="p15612124910139"></a><a name="p15612124910139"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.56%" id="mcps1.2.5.1.4"><p id="p1061274951318"><a name="p1061274951318"></a><a name="p1061274951318"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15612749191317"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.2.5.1.1 "><p id="p161215495131"><a name="p161215495131"></a><a name="p161215495131"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.2.5.1.2 "><p id="p176121049101318"><a name="p176121049101318"></a><a name="p176121049101318"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.2.5.1.3 "><p id="p8612144917136"><a name="p8612144917136"></a><a name="p8612144917136"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.56%" headers="mcps1.2.5.1.4 "><p id="p161254911314"><a name="p161254911314"></a><a name="p161254911314"></a>资源路径</p>
    </td>
    </tr>
    <tr id="row861264931319"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.2.5.1.1 "><p id="p15612449181316"><a name="p15612449181316"></a><a name="p15612449181316"></a>params</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.2.5.1.2 "><p id="p496164415306"><a name="p496164415306"></a><a name="p496164415306"></a>Array|Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.2.5.1.3 "><p id="p861284917131"><a name="p861284917131"></a><a name="p861284917131"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.56%" headers="mcps1.2.5.1.4 "><p id="p20612194931313"><a name="p20612194931313"></a><a name="p20612194931313"></a>运行时用来替换占位符的实际内容，占位符分为两种：</p>
    <a name="ul0124131652619"></a><a name="ul0124131652619"></a><ul id="ul0124131652619"><li>具名占位符，例如{name}。实际内容必须用Object类型指定，例如：$t('strings.object', <strong id="b1013035383112"><a name="b1013035383112"></a><a name="b1013035383112"></a>{ name: 'Hello world' }</strong>)。</li><li>数字占位符，例如{0}。实际内容必须用Array类型指定，例如：$t('strings.array', <strong id="b0314143473110"><a name="b0314143473110"></a><a name="b0314143473110"></a>['Hello world']</strong>)。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   简单格式化示例代码

    ```
    <!-- xxx.hml -->
    <div>
      <!-- 不使用占位符，text中显示“Hello world!” -->
      <text>{{ $t('strings.hello') }}</text>
      <!-- 具名占位符格式，运行时将占位符{name}替换为“Hello world” -->
      <text>{{ $t('strings.object', { name: 'Hello world' }) }}</text>
      <!-- 数字占位符格式，运行时将占位符{0}替换为“Hello world” -->
      <text>{{ $t('strings.array', ['Hello world']) }}</text>
      <!-- 先在js中获取资源内容，再在text中显示“Hello world” -->
      <text>{{ hello }}</text>
      <!-- 先在js中获取资源内容，并将占位符{name}替换为“Hello world”，再在text中显示“Object parameter substitution-Hello world” -->
      <text>{{ replaceObject }}</text>
      <!-- 先在js中获取资源内容，并将占位符{0}替换为“Hello world”，再在text中显示“Array type parameter substitution-Hello world” -->
      <text>{{ replaceArray }}</text>
    
      <!-- 获取图片路径 -->
      <image src="{{ $t('files.image') }}" class="image"></image>
      <!-- 先在js中获取图片路径，再在image中显示图片 -->
      <image src="{{ replaceSrc }}" class="image"></image>
    </div>
    ```

    ```
    // xxx.js
    // 下面为在js文件中的使用方法。
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

-   单复数格式化方法

    **表 4**  单复数格式化

    <a name="table12722349115211"></a>
    <table><thead align="left"><tr id="row11723204985215"><th class="cellrowborder" valign="top" width="7.68%" id="mcps1.2.6.1.1"><p id="p9723749145217"><a name="p9723749145217"></a><a name="p9723749145217"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.28%" id="mcps1.2.6.1.2"><p id="p1372374910528"><a name="p1372374910528"></a><a name="p1372374910528"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.84%" id="mcps1.2.6.1.3"><p id="p1272314496527"><a name="p1272314496527"></a><a name="p1272314496527"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.2.6.1.4"><p id="p39561320202915"><a name="p39561320202915"></a><a name="p39561320202915"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.199999999999996%" id="mcps1.2.6.1.5"><p id="p12723124915528"><a name="p12723124915528"></a><a name="p12723124915528"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167231749155214"><td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.2.6.1.1 "><p id="p15723184945217"><a name="p15723184945217"></a><a name="p15723184945217"></a>$tc</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.28%" headers="mcps1.2.6.1.2 "><p id="p1372310494525"><a name="p1372310494525"></a><a name="p1372310494525"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.84%" headers="mcps1.2.6.1.3 "><p id="p3645417495"><a name="p3645417495"></a><a name="p3645417495"></a>请见<a href="#table1856962321614">表5</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.2.6.1.4 "><p id="p1589916493474"><a name="p1589916493474"></a><a name="p1589916493474"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.199999999999996%" headers="mcps1.2.6.1.5 "><p id="p1080910112617"><a name="p1080910112617"></a><a name="p1080910112617"></a>根据系统语言完成单复数替换：this.$tc('strings.people')</p>
    <div class="note" id="note44962033184817"><a name="note44962033184817"></a><a name="note44962033184817"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1456045614402"><a name="p1456045614402"></a><a name="p1456045614402"></a>定义资源的内容通过json格式的key为“zero”、“one”、“two”、“few”、“many”和“other”区分。</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>

    **表 5**  $tc参数说明

    <a name="table1856962321614"></a>
    <table><thead align="left"><tr id="row13569122391616"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p135698238163"><a name="p135698238163"></a><a name="p135698238163"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p17569152311168"><a name="p17569152311168"></a><a name="p17569152311168"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1569523171613"><a name="p1569523171613"></a><a name="p1569523171613"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p2569192341613"><a name="p2569192341613"></a><a name="p2569192341613"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row056919234163"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p175691923171610"><a name="p175691923171610"></a><a name="p175691923171610"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p11569182319162"><a name="p11569182319162"></a><a name="p11569182319162"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p93611250151616"><a name="p93611250151616"></a><a name="p93611250151616"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p145691323171620"><a name="p145691323171620"></a><a name="p145691323171620"></a>资源路径</p>
    </td>
    </tr>
    <tr id="row1569142351616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p956911235161"><a name="p956911235161"></a><a name="p956911235161"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7569182321618"><a name="p7569182321618"></a><a name="p7569182321618"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p6377550111614"><a name="p6377550111614"></a><a name="p6377550111614"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1556962371614"><a name="p1556962371614"></a><a name="p1556962371614"></a>要表达的值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   单复数格式化示例代码

    ```
    <!--xxx.hml-->
    <div>
      <!-- 传递数值为0时： "0 people" 阿拉伯语中此处匹配key为zero的词条-->
      <text>{{ $tc('strings.people', 0) }}</text>
      <!-- 传递数值为1时： "one person" 阿拉伯语中此处匹配key为one的词条-->
      <text>{{ $tc('strings.people', 1) }}</text>
      <!-- 传递数值为2时： "2 people" 阿拉伯语中此处匹配key为two的词条-->
      <text>{{ $tc('strings.people', 2) }}</text>
      <!-- 传递数值为6时： "6 people" 阿拉伯语中此处匹配key为few的词条-->
      <text>{{ $tc('strings.people', 6) }}</text>
      <!-- 传递数值为50时： "50 people" 阿拉伯语中此处匹配key为many的词条-->
      <text>{{ $tc('strings.people', 50) }}</text>
      <!-- 传递数值为100时： "100 people" 阿拉伯语中此处匹配key为other的词条-->
      <text>{{ $tc('strings.people', 100) }}</text>
    </div>
    ```


## 获取语言<a name="section2872192475310"></a>

获取语言功能请参考[应用配置](../apis/js-apis-basic-features-configuration.md)。


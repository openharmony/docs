# 多语言支持

基于开发框架的应用会覆盖多个国家和地区，开发框架支持多语言能力后，可以让应用开发者无需开发多个不同语言的版本，就可以同时支持多种语言的切换，为项目维护带来便利。


开发者仅需要通过[定义资源文件](#定义资源文件)和[引用资源](#引用资源)两个步骤，就可以使用开发框架的多语言能力；如果需要在应用中获取当前系统语言，请参考[获取语言](#获取语言)。


## 定义资源文件

资源文件用于存放应用在多种语言场景下的资源内容，开发框架使用JSON文件保存资源定义。在[文件组织](js-framework-file.md)中指定的i18n文件夹内放置语言资源文件，其中语言资源文件的命名是由语言、文字、国家或地区的限定词通过中划线连接组成，其中文字和国家或地区可以省略，如zh-Hant-HK（中国香港地区使用的繁体中文）、zh-CN（中国使用的简体中文）、zh（中文）。命名规则如下：

```
language[-script-region].json
```

限定词的取值需符合下表要求。

表1 限定词取值要求

| 限定词类型 | 含义与取值说明                                  |
| ----- | ---------------------------------------- |
| 语言    | 表示设备使用的语言类型，由2~3个小写字母组成。例如：zh表示中文，en表示英语，mai表示迈蒂利语。<br/>详细取值范围，请查阅ISO&nbsp;639（ISO制定的语言编码标准）。 |
| 文字    | 表示设备使用的文字类型，由1个大写字母（首字母）和3个小写字母组成。例如：Hans表示简体中文，Hant表示繁体中文。<br/>详细取值范围，请查阅ISO&nbsp;15924（ISO制定的文字编码标准）。 |
| 国家或地区 | 表示用户所在的国家或地区，由2~3个大写字母或者3个数字组成。例如：CN表示中国，GB表示英国。<br/>详细取值范围，请查阅ISO&nbsp;3166-1（ISO制定的国家和地区编码标准）。 |

当开发框架无法在应用中找到系统语言的资源文件时，默认使用en-US.json中的资源内容。

资源文件内容格式如下：

en-US.json
```json
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

```json
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

```json
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


## 引用资源

在应用开发的页面中使用多语言的语法，包含简单格式化和单复数格式化两种，都可以在hml或js中使用。

- 简单格式化方法
  在应用中使用$t方法引用资源，$t既可以在hml中使用，也可以在js中使用。系统将根据当前语言环境和指定的资源路径（通过$t的path参数设置），显示对应语言的资源文件中的内容。

  表2 简单格式化

  | 属性 | 类型     | 参数              | 必填 | 描述                                                   |
  | ---- | -------- | ----------------- | ---- | ------------------------------------------------------ |
  | $t   | Function | 请见表 $t参数说明 | 是   | 根据系统语言完成简单的替换：this.$t('strings.hello')。 |

  表3 $t参数说明

  | 参数   | 类型          | 必填 | 描述                                                         |
  | ------ | ------------- | ---- | ------------------------------------------------------------ |
  | path   | string        | 是   | 资源路径。                                                   |
  | params | Array\|Object | 否   | 运行时用来替换占位符的实际内容，占位符分为两种：<br/>- 具名占位符，例如{name}。实际内容必须用Object类型指定，例如：```$t('strings.object', {name:'Hello world'})```。 <br> - 数字占位符，例如{0}。实际内容必须用Array类型指定，例如：```$t('strings.array', [Hello world']```。 |

- 简单格式化示例代码
  ```html
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

  ```js
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

- 单复数格式化方法

  表4 单复数格式化

  | 属性 | 类型     | 参数               | 必填 | 描述                                                         |
  | ---- | -------- | ------------------ | ---- | ------------------------------------------------------------ |
  | $tc  | Function | 请见表 $tc参数说明 | 是   | 根据系统语言完成单复数替换：this.$tc('strings.people')。<br/>> 说明：<br/>>&nbsp;定义资源的内容通过json格式的key为“zero”、“one”、“two”、“few”、“many”和“other”区分。 |

  表5 $tc参数说明

  | 参数  | 类型   | 必填 | 描述         |
  | ----- | ------ | ---- | ------------ |
  | path  | string | 是   | 资源路径。   |
  | count | number | 是   | 要表达的值。 |

- 单复数格式化示例代码
  ```html
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


## 获取语言

获取语言功能请参考[@ohos.app.ability.Configuration (Configuration)](../reference/apis-ability-kit/js-apis-app-ability-configuration.md)。

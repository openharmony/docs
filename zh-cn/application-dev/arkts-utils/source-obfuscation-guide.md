# ArkGuard混淆开启指南

## 开启源码混淆

### 开启混淆步骤
源码混淆能力已在系统中集成，可通过以下方式在DevEco Studio开启使用。

* 开启混淆开关  
    在本模块`build-profile.json5`配置文件中的`arkOptions.obfuscation.ruleOptions`字段中，通过`enable`字段配置是否开启混淆。
    ```
    "arkOptions": {
      "obfuscation": {
        "ruleOptions": {
          "enable": true,
          "files": ["./obfuscation-rules.txt"],
        }
      }
    }
    ```

* 配置混淆规则  
    打开混淆开关，仅开启默认混淆功能，默认混淆范围为局部变量和参数。如需开启更多混淆功能，请在`files`字段指定的混淆配置文件`obfuscation-rules.txt`中进行选项配置。需要注意的是，不同版本的DevEco Studio，`obfuscation-rules.txt`文件中的默认值可能会有所不同。

    以DevEco Studio5.0.3.600及更高版本为例，混淆配置文件如下所示，该配置内容表示开启属性名称混淆、顶层作用域名称混淆、文件名混淆及导入导出名称混淆功能：
    ```
    -enable-property-obfuscation
    -enable-toplevel-obfuscation
    -enable-filename-obfuscation
    -enable-export-obfuscation
    ```

    开发者还可以使用`#`在混淆规则文件中进行注释，每行以`#`开头的文本会被当做是注释。使用方法如下，`#`后为注释内容：
    ```
    # options:
    -enable-property-obfuscation
    -enable-toplevel-obfuscation
    -enable-filename-obfuscation
    # -enable-export-obfuscation
    -keep-property-name # white list for dynamic property names
    ```

    混淆选项的配置推荐参考[混淆选项配置指导](#混淆选项配置指导)，混淆过程中涉及的所有配置文件的详情介绍请参考[三种混淆配置文件](#三种混淆配置文件)。

* 指定release编译  
    源码混淆仅支持release编译，不支持debug编译。开启混淆开关后，release编译会进行混淆，debug编译则不会。开发者可参考[指定构建模式](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916)查看和修改构建模式。

    > **注意：**
    >
    > release编译与debug编译的区别不仅限于混淆。若要明确应用行为差异是否由混淆引起，应通过开启或关闭混淆开关进行排查，而不是仅通过切换编译模式。

> **说明：**
>
> 1. 在DevEco Studio5.0.3.600之前，新建工程的默认设置是开启代码混淆，自动对API 10及更高版本的Stage模型进行混淆。
> 2. 在DevEco Studio5.0.3.600及之后，新建工程的默认设置为关闭代码混淆。若需开启混淆，需将模块的`build-profile.json5`文件的`ruleOptions.enable`字段设置为true。
> 3. 混淆规则配置文件`obfuscation-rules.txt`默认开启了四项推荐的混淆选项：`-enable-property-obfuscation`、`-enable-toplevel-obfuscation`、`-enable-filename-obfuscation`和`-enable-export-obfuscation`，开发者可以根据需要进一步修改混淆配置。

### 三种混淆配置文件
* `obfuscation-rules.txt`  
    HAP、HAR及HSP模块的`build-profile.json5`配置文件中均有`arkOptions.obfuscation.ruleOptions.files`字段，用于指定在编译本模块时需要生效的混淆规则，新建工程时会创建默认文件`obfuscation-rules.txt`。

* `consumer-rules.txt`  
    对于HAR和HSP模块，在`build-profile.json5`中额外有一个`arkOptions.obfuscation.consumerFiles`字段，**用于指定当本包被依赖时，期望在当前编译流程生效的混淆规则**，新建HAR或HSP模块时会创建默认文件`consumer-rules.txt`。它与`obfuscation-rules.txt`的区别是：**`obfuscation-rules.txt`在编译本模块时生效，`consumer-rules.txt`在编译依赖本模块的其他模块时生效**。
    ```
    "arkOptions": {
      "obfuscation": {
        "ruleOptions": {
          "enable": true,
          "files": ["./obfuscation-rules.txt"],
        }
        "consumerFiles": ["./consumer-rules.txt"]
      }
    }
    ```

* `obfuscation.txt`  
    不同于以上两种开发者可自行修改的配置文件，`obfuscation.txt`是在编译构建HAR或HSP时根据`consumer-rules.txt`和依赖模块的混淆规则文件自动生成的文件，它作为一种编译产物存在于发布的HAR或HSP包中。在其他应用依赖该发布包时，会合并其中的混淆规则应用于当前编译流程。`obfuscation.txt`内容的生成及合并逻辑请参考[混淆规则合并策略](source-obfuscation.md#混淆规则合并策略)。

  > **说明**：
  >
  > 针对三方库中`obfuscation.txt`文件，只有在模块的`oh-package.json5`文件中依赖三方库时，三方库中的`obfuscation.txt`文件才会生效。如果在工程的`oh-package.json5`文件中进行依赖，则三方库的`obfuscation.txt`文件不会生效。

下表简要总结了三种配置文件的差异：

| 配置文件（示例） | 配置类型 |  是否可修改配置  |  是否影响本模块的混淆  |  是否影响其他模块的混淆  |
| --- | --- | --- | --- | --- |
| obfuscation-rules.txt | 自定义  | 是 | 是 | 否 |
| consumer-rules.txt    | 自定义  | 是 | 否 | 是 |
| obfuscation.txt       | 编译产物 | 不涉及，构建HAR或HSP时自动生成。 | 不涉及 | 是 |

### 混淆选项配置指导
1. 开启`-enable-toplevel-obfuscation`选项，如果代码中有globalThis访问全局变量，会出现访问失败的情况，需要使用`-keep-global-name`来保留此全局变量名称。
2. 待上述选项应用适配成功后，开启`-enable-property-obfuscation`选项。此选项开启后以下场景需要适配：
    1. 若代码中存在静态定义、动态访问的情况，或动态定义、静态访问的情况，需要使用`-keep-property-name`保留属性名称。示例：
        ```
        // 静态定义，动态访问：属性名在对象定义时是静态的，但访问时通过动态构建属性名（通常使用字符串拼接）来访问
        const obj = {
          staticName: value  // 静态定义属性
        };
        const fieldName = 'static' + 'Name';  // 动态构建属性名
        console.log(obj[fieldName]);  // 使用方括号语法动态访问属性
        ```
        ```
        // 动态定义，静态访问：属性名通过动态表达式在对象定义时确定，但访问时直接使用点语法（假设你知道属性名的结果）
        const obj = {
          [dynamicExpression]: value  // 动态定义属性
        };
        console.log(obj.dynamicPropertyName);  // 使用点语法静态访问属性
        ```
    2. 若代码中使用点语法访问未在ArkTS/TS/JS代码中定义的字段，比如访问native实现的so库，字段固定的json文件与数据库等场景：
        1. 若在代码中引用so库的api，如```import testNapi from 'library.so';testNapi.foo();```需要使用`-keep-property-name` foo保留属性名称。
        2. 若在代码中使用json文件中的字段，需要使用`-keep-property-name`保留json文件中的字段名称。
        3. 若在代码中使用数据库相关的字段，需要使用`-keep-property-name`保留数据库中的字段名称。
    3. 若构建HAR模块并发布给其他模块使用的场景，要在HAR模块中的consumer-rules.txt文件中将不能被二次混淆的属性使用`-keep-property-name`保留。consumer-rules.txt文件在构建HAR时会生成obfuscation.txt文件。此HAR被其它模块依赖时，Deveco Studio会解析obfuscation.txt文件，读取文件中的白名单。
    4. 验证应用功能，排查遗漏的场景。若应用出现功能异常，依据混淆后的报错栈从对应的[中间产物](#查看混淆效果)中找到报错行的代码，排查需要配置的白名单并使用`-keep-property-name`进行保留。
3. 待上述选项应用适配成功后，开启`-enable-export-obfuscation`选项。此选项开启后以下场景需要适配：
    1. 若构建HSP模块，它会提供接口及其属性给其它模块调用，因此需要将对外接口使用`-keep-global-name`来保留、将对外暴露的class/interface等语法中的属性使用`-keep-property-name`保留。
    2. 若构建HAR模块并发布给其他模块使用的场景，要在HAR模块中的obfuscation-rules.txt文件中将对外接口使用`-keep-global-name`来保留，将对外暴露的class/interface等语法中的属性使用`-keep-property-name`保留。
    3. 若在代码中引用so库的api，如```import { napiA } from 'library.so'```；需要使用`-keep-global-name` napiA保留so接口名称。
    4. 验证应用功能以及模块被依赖时的接口调用功能，排查遗漏的场景。若应用出现功能异常，依据混淆后的报错栈从对应的[中间产物](#查看混淆效果)中找到报错行的代码，排查需要配置的白名单并进行保留。
4. 待上述选项应用适配成功后，开启`-enable-filename-obfuscation`选项。此选项开启后以下场景需要适配：
    1. 若代码中有动态import语句，如```const path = './filePath'; import(path)```，会出现文件引用失败的情况，需要使用`-keep-file-name` filePath来保留这个文件名。
    2. 若应用中有描述路由表信息的[routerMap配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/module-configuration-file#routermap%E6%A0%87%E7%AD%BE)，其中的pageSourceFile字段标记页面在模块的路径，需要使用`-keep-file-name`来保留这个路径。
    3. 若代码中有传入ohmUrl进行页面跳转，如```router.pushUrl({url: '@bundle:com.example.routerPage/Library/Index')```，使用`-keep-file-name`来保留这个路径。
    4. 验证应用功能，排查遗漏的场景。若应用出现功能异常，且报错栈中的路径为混淆后的路径，可以在模块中的`build/default/[...]/release/obfuscation/nameCache.json`文件中查询到原始路径，进而找到源码文件。另外，[插件hstack](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-command-line-hstack)支持自动还原混淆后的报错堆栈。在定位到需要保留的路径后，使用`-keep-file-name`来保留此路径。

### 说明
* 目前不支持在hvigor构建流程中插入自定义混淆插件。
* 混淆的HAR包被某模块依赖，若该模块开启混淆，则HAR包会被二次混淆。

## 查看混淆效果

在混淆结束后会生成中间产物，因此可以在编译产物build目录中找到混淆后的中间产物以查看混淆效果，同时可以找到混淆生成的名称映射表及系统API白名单文件。

* 混淆后的文件目录：`build/default/[...]/release/模块名`。
* 混淆名称映射表及系统API白名单目录：`build/default/[...]/release/obfuscation`。
  * 名称映射表文件：nameCache.json，该文件记录了源码名称混淆的映射关系。
  * 系统API白名单文件：systemApiCache.json，该文件记录了SDK中的接口与属性名称，工程源码中与其重名的元素不会被混淆。

  ![build-product](figures/build-product.png)

## 报错栈还原

经过混淆的应用程序，代码名称会发生更改，导致crash时打印的报错栈难以理解。开发人员可使用DevEco Studio命令工具Command Line Tools中的[hstack插件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-command-line-hstack)来还原源码堆栈，进而分析问题。  
反混淆工具需要使用应用编译过程中生成的sourceMaps.map文件以及混淆名称映射文件nameCache.json文件，请本地备份这些文件。

![obfuscation-product](figures/obfuscation-product.png)
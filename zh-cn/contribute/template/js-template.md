# API接口说明模板

## 总体写作说明

> **说明**：<br/>所有的写作说明，在完成写作后，都要删除。

|      | 说明项                            | 细则                                                         |
| ---- | --------------------------------- | ------------------------------------------------------------ |
| 1    | 客户化写作基本要求                | **写作中，请变身开发者，对于开发者使用该API时所需的使用场景、参数选取原则、开发建议/经验、示例等信息进行清晰描述，达到指导开发者顺利使用本API进行开发的目标。** |
| 2    | 上传路径                          | markdown文件：docs/zh-cn/application-dev/reference/apis<br>图片路径：docs/zh-cn/application-dev/reference/apis/figures，并在markdown文件中通过路径\![]\(figures/xxx.jpg)或\![]\(figures/xxx.png)引用。 |
| 3    | 文件命名                          | 一个d.ts对应一个js api文档，文件名称应与模块名称保持一致，格式为：**js-apis-模块名.md**。<br/>示例：<br/>媒体@ohos.multimedia.audio，文件命名为：js-apis-audio.md<br/>电话@ohos.telephony.sms，文件命名为：js-apis-sms.md |
| 4    | 目录修改                          | 新增文件，需要修改对应的Readme，即`docs/zh-cn/application-dev/reference/apis/Readme-CN.md`。<br/>目录按字母顺序排列。 |
| 5    | 文档结构                          | - 模块说明<br/>- 起始版本说明<br/>- 导入模块/使用说明<br/>- 接口（属性、常量、方法、枚举、自定义类型）<br/>  描述顺序和代码保持一致，如果某些接口具有逻辑顺序，请注意排列。 |
| 6   | 异步接口说明（callback、Promise） | 对于callback、Promise在方法描述、参数说明、返回值说明的具体描述要求如下：<br/>**callback**的固定句式：<br/>方法介绍：xxx（方法描述）。使用callback异步回调。<br/>参数说明：<br/>**callback\<boolean>**：回调函数。返回true表示xxx；返回false表示xxx。<br/>**callback\<Object>**：回调函数，返回xxx。例如”回调函数，返回音频采集器对象。“<br/>**AsyncCallback\<void>**：回调函数。当具体的操作（视具体接口功能描述）成功，err为undefined，否则为错误对象。<br/>**AsyncCallback\<Object x>**：回调函数。当具体的操作（视具体接口功能描述）成功，err为undefined，data为获取到的Object x；否则为错误对象。<br/>**Promise**的固定句式：<br/>方法介绍：xxx（方法描述）。使用Promise异步回调。<br/>参数说明：<br/>**Promise\<boolean>**：Promise对象。返回true表示xxx；返回false表示xxx。<br/>**Promise\<Object>**：Promise对象，返回xxx。例如”Promise对象，返回音频采集器对象。“<br/>**Promise\<void>**：Promise对象，无返回结果。 |
| 7   | 示例代码语言                      | 所有的示例代码采用代码块的样式，并标记开发语言。<br/>JS和eTS通用的标注`js`；仅eTS可用的，标注`ts`。 |
| 8   | 链接写法                          | 格式：[链接文字]\(链接内容)<br/>跨文件夹链接：[指南]\(\.\./../xxx/xxx.md)，一个`../`表示上移一层文件夹。<br/>页面内链接：[接口A<sup>7+</sup>]\(#xxxa7)，页面内链接和需要链接到的标题保持一致，全小写无特殊符号无标签。 |

## d.ts标签与文档字段的对应关系

以下字段，除版本说明外，均需下沉到每一个接口中。

如果是属性、interface表格，字段全表统一无差异，可统一写在表格上方；如果有一个不一致，需全部拆开，写到每一行的“说明”里。

| d.ts的标签 | 含义 | 文档字段 |
| ---------- | ---- | ------- |
| @since | 版本说明 | 1. 每个模块要有起始版本说明，使用引用语法“>”对接口的起始版本进行说明。接口没有标记的，默认与模块同一个起始版本。<br/>2. 已有模块新增接口使用\<sup>标签标记对应版本号。写法：`<sup>版本号+</sup>`<br/> 例如`<sup>7+</sup>`<br/> 示例：API 6已有的模块，在API 7新增了一个属性字段，则在属性后加标记，即newAttribute<sup>7+</sup>。<br/>如果新增了一个方法，则在方法标题后增加标记，即 sim.getSimIccId<sup>7+</sup>，interface、class、枚举等同理。<br/>**需要注意的特殊情况**：因匿名对象整改，导致部分接口出现外层元素版本号高于内层元素版本号情况。为避免开发者困惑，需要在此类“接口描述”处统一增加说明：为规范匿名对象的定义，API XX版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。 |
| @deprecated | 废弃说明 | 废弃内容不能直接删去，上标标注(deprecated)，起始版本和废弃版本均使用引用语法“>”说明。<br/>示例：abandonmentMethod<sup>(deprecated) </sup><br/>> 从API version 4 开始支持，从API version 7 开始废弃，建议使用[newMethod]\(#newmethod)替代。|
| @FAModelOnly / @StageModelOnly | 模型约束 | **模型约束**：此接口仅可在FA模型下使用。 <br/> **模型约束**：此接口仅可在Stage模型下使用。 |
| @form | 卡片能力 | **卡片能力**：从API version x开始，该接口支持在ArkTS卡片中使用。 |
| @atomicservice | 原子化服务是否可用 | **原子化服务API**：从API version x开始，该接口支持在原子化服务中使用。 |
| @systemapi | 系统接口 | **系统接口**：此接口为系统接口。 |
| @syscap | 系统能力 | **系统能力**：SystemCapability.xxx.xxx |  1. 如果仅涉及一个权限，格式：<br/>    **需要权限**：ohos.permission.xxxx   <br/>2. 如果该接口涉及多个权限，则采用“和、或”进行分割，格式：<br/>    **需要权限**：ohos.permission.A 和 ohos.permission.B<br/>    **需要权限：**：ohos.permission.A 或 ohos.permission.B |
| @permission | 权限 |  1. 如果仅涉及一个权限，格式：<br/>    **需要权限**：ohos.permission.xxxx   <br/>2. 如果该接口涉及多个权限，则采用“和、或”进行分割，格式：<br/>    **需要权限**：ohos.permission.A 和 ohos.permission.B<br/>    **需要权限**：ohos.permission.A 或 ohos.permission.B <br/>3. 涉及版本变更时，“需要权限”后跟当前版本的权限要求，历史版本的权限要求换行按列表描述，样例：<br/>**需要权限**：ohos.permission.A <br/>- 在API x-(y-1)时，需要申请权限ohos.permission.A和B。<br/>- 从API y开始，仅需申请ohos.permission.A。<br/>4. 仅在某些固定场景下，需要申请权限。“需要权限”后跟d.ts的@permission保持一致，再补充情况说明，分为两类情况，当情况较为简单时，可采用括号补充描述；当情况较为复杂时，换行描述。<br/>样例1：<br/> **需要权限**：ohos.permission.A（仅当创建窗口类型为AA时需要申请）<br/>样例2：<br/> **需要权限**：ohos.permission.A<br/>- 当应用处于xx情况时，需要同步申请ohos.permission.B。<br/>- 当应用处于yy情况时，无需申请任何权限。|
| @extends | 继承 |  带有该标签或实际存在extends关系但未带该标签时，在相关描述处应明确说明“xxx继承自xxx（提供链接）。” |
| @装饰器名称 | 装饰器类型 | 若Class/Interface/属性被装饰器修饰，则需要在相关描述处明确说明“**装饰器类型**：@装饰器名称”，例如“**装饰器类型**：@Sendable”。|

下面进入具体每个API的写作。

***

# 文档标题

> *写作说明*
>
> 1. **文档标题**：作为文档标题，要求使用中文短语概括本模块功能；但如果部分概念使用英文更便于开发者理解，可以直接使用。如Ability、SIM卡管理等。
> 2. **标题层级**：文档标题为一级标题，使用`# `；namespace下的属性字段、function、class、interface、enum、type为二级标题，使用`## `；class下的属性、function为三级标题，使用`### `。
> 3. **起始版本说明**：使用markdown的引用语法“>”对接口的起始版本进行说明，说明后需要换行。<br/>版本说明统一放在模块描述之后。一个模块只会有一个起始版本。<br/>采用标准句式：“本模块首批接口从API version x开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。”x需要修改为对应的版本号。

模块描述。此处对该模块的定义、功能、使用场景、使用建议进行描述，采用如下固定句式。

（模块介绍，可选）xxx是xxx。

（功能描述，必选）xxx模块提供xxx能力，包括xxx、xxx等。——当模块名不够语义化时，推荐此句式。

或 本模块提供xxx能力，包括xxx、xxx等。——当模块名已经表达了清晰的语义时，推荐此句式。

（使用场景，可选）当需要xxx时，使用本模块接口xxx。

（使用建议或注意事项，可选）本模块接口可与xxx联合使用，以提升开发效率……。

**举例1**：“后台任务管理模块”的模块描述示例

本模块提供后台任务管理能力。
当应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend），或长时任务避免进入挂起状态。

**举例2**：“拨打电话模块”的模块描述示例

本模块提供呼叫管理能力，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。
如需订阅通话状态，请使用observer.on('callStateChange')。

**举例3**：“分布式数据管理模块”的模块描述示例

分布式数据管理模块为应用程序提供不同设备间数据库的分布式协同能力。
通过调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增加、删除、修改、查询、同步等操作。

**举例4**：“线性容器ArrayList模块”的模块描述示例

ArrayList是一种线性数据结构，底层基于数组实现。ArrayList会根据实际需要动态调整容量，每次扩容增加50%。
ArrayList和Vector相似，都是基于数组实现。它们都可以动态调整容量，但Vector每次扩容增加1倍。
ArrayList和LinkedList相比，ArrayList的随机访问效率更高。但由于ArrayList的增删操作会影响数组内其他元素的移动，LinkedList的增加和删除操作效率更高。
当需要频繁读取集合中的元素时，推荐使用ArrayList。



> **说明：**<br/>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

> *写作说明*
>
> 1. 根据实际情况填写导入模块。采用代码段的样式，给出import语句。
>
> 2. 如果没有导入模块，将“导入模块”修改为“使用说明”。<br/>使用说明案例：<br/>
>    在使用AbilityContext的功能前，需要通过\[getContext()]\(链接到对应的接口说明文件中.md)先获取Context对象。
>
> ```js
>    import { featureAbility } from '@kit.AbilityKit';
>    let context = featureAbility.getContext();
> ```

```js
import { call } from '@kit.TelephonyKit';
```

## 属性

> *写作说明*
>
> 1. 可选，如果没有属性可删除此二级标题。
>
> 2. 类型如果为自定义类型，需要建立链接到对应的interface或enum中。
>
> 3. 对于只读属性：d.ts中标有`readonly`字样。如果取值为有特殊含义的有限值，需要在说明里枚举，或是通过类型链接到对应枚举类型。
>
> 4. 对于可选属性：如果仅支持固定字段，需要进行说明。如该属性定义时，带有?，即为可选。
>
> 5. 若属性被装饰器修饰，则需要在“说明”中明确具体的“装饰器类型”。

**系统能力**：SystemCapability.xxx.xxx（必选）

| 名称             | 类型                                      | 只读 | 可选 | 说明                                       |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| pluggedType      | [BatteryPluggedType](#batterypluggedtype) | 是   | 否   | 表示当前设备连接的充电器类型。 <br>**装饰器类型：** @Trance            |
| isBatteryPresent | boolean                                   | 是   | 否   | 表示当前设备是否支持电池或者电池是否在位。 |

## 常量

> *写作说明*
>
> 1. 可选，如果没有常量可删除此二级标题，对应d.ts中的const。
> 2. 部分const用于定义只读变量，无对应值，此时表格为：名称、类型、只读、说明，四列。
> 3. 类型如果为自定义类型，需要建立链接到对应的interface或enum中。

**系统能力**：SystemCapability.xxx.xxx（必选）

| 名称             | 类型                                |  值      | 说明                                       |
| ---------------- | -----------------------------------| -------- | ------------------------------------------ |
| uid              | number                             | 1        | 进程的用户标识。                           |
| pid              | number                             | 2        | 当前进程的pid。                            |

## 方法

> *写作说明*
>
> 1. 可选，如果没有可删除。如果有多个方法，请分多个二级内容描述，并使用“##”自行新建二级标题。
>
> 2. 二级标题名为方法名，采用导入类.方法名，如果是订阅方法，需要在方法名加上对应的订阅事件。
>
>    示例： sim.getSimIccId
>    订阅方法：sim.on('exampleEvent')
>
> 3. **方法具体调用形式**：和d.ts保持一致，需要包括关键字（static、abstract、set、get等）、参数类型、参数名、返回值类型。
>
>    示例：
>    
>    getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void
>
>       abstract makeNode(uiContext: UIContext): FrameNode | null
>
>    注意1：尖括号<>可能会被识别为标签，导致界面显示失效，可增加一个\，以保证界面正常显示，如“\\<>”或使用转义字符\&lt; \&gt; 。
>
>    注意2：如果set和get关键字声明的方法成对出现，名称相同。则共用同一标题，顺序描述方法具体调用形式、标签、参数、返回值等说明。建议set方法在前，get方法在后。请参考[backgroundColor](../../application-dev/reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor)。
>
> 4. **方法描述**：对方法实现的功能进行描述，包括其使用的前提条件（*如：在xx方法调用后才能调用、需要确保网络已连接……*）、使用之后的影响（*如：调用该接口后再进行xx将不起效*）、**权限限制**、**系统能力**等。
>
> 5. **异步方法描述**：存在大量异步方法，其返回方式需要在方法描述处进行说明。具体写法参考总体写作说明第14项。
>
> 6. **表格内换行**：markdown语法中，换行采用特殊标记\<br>

*（在此处给出方法的具体调用形式。如果存在关键字需说明）* 方法名称(参数1名称：参数1类型，参数2名称：参数2类型，……)：返回值类型

在此处给出方法描述。说明请参考上述写作说明第4、5点。

**模型约束**：此接口仅可在FA模型下使用。（如不涉及可删除）

**系统接口**：此接口为系统接口。（如不涉及可删除）

**需要权限**：ohos.permission.xxx（如不涉及可删除）

**系统能力**：SystemCapability.xxx.xxx（必选）

**参数**：（可选，如不涉及可删除）

| 参数名       | 类型                                          | 必填 | 说明                                                         |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| parameterOne | number \| string \| [CustomType](#classinterface) | 是   | 参数描述（包括参数的含义与用途、什么场景下使用该参数、选取建议、参数间关联关系等）。<br/>参数取值说明（包括取值范围、单位、默认值、取值原则或建议值；边界值涉及限制/异常时，需讲明具体场景；如果有固定格式，需要给出格式样例，尤其是URI）。<br/>自定义类型需要进行建链说明。 |
| callback     | Callback\<Array<[CustomType](#classinterface)>>   | 否   | 参数描述。可选参数需要说明不填写该参数的后果。<br/>如：不填该参数则取消该type对应的所有回调。<br/>callback写法参考总体写作说明第14项。 |

**返回值**：（可选，如不涉及可删除）

| 类型                                       | 说明                                            |
| ------------------------------------------ | ----------------------------------------------- |
| string                                     | 返回值描述。需包含以下内容：<br/>1. 取到返回值之后，可以用来做什么。<br/>2. 返回值如果可枚举，需枚举说明返回值意义。<br/>3. 返回值如果为某个具体值/格式，需和实际实现保持一致。  |
| Promise\<Array<[CustomType](#classinterface)>> | 返回值描述。Promise写法参考总体写作说明第14项。 |

**错误码**：（可选，如不涉及可删除）

以下错误码的详细介绍请参见[ohos.window(窗口)错误码]()。*（链接到对应模块的“错误码参考”文档）*

| 错误码ID | 错误信息（此处仅提供错误抛出的关键信息） |
| -------- | ---------------------------------------- |
| 1300001  | This is repeat operation.                |
| 1300002  | This window state is abnormally.         |

**示例：**

```js
// 必选项。

// 所有的示例代码需要进行自检，确保运行结果符合预期。
// 不能出现缺符号、变量前后不一致等低错。
// 所有使用到的变量要进行声明。
// 接口传参异常时，需验证代码能否捕获错误，抛出对应错误码。

// 不允许直接写参数名，必须是可使用、易替代的实际用例。如果非用户自定义填写，需通过注释进行说明。
// 例如：let result = xxx.createExample(parameterOne); // parameterOne由扫描自动获取

// 注释要精简、突出要点。需提供注释的典型场景还有：
// 1. 当代码不能说明变量命名的具体含义，或不能说明代码逻辑时，必须提供注释。
// 2. 涉及到复杂算法或特殊语法时，必须提供注释。
```

## on/off订阅方法

> *写作说明*
>
> 1. 与[方法](#方法)要求一致，以下仅作差异项说明。
>
> 2. 二级标题名为方法名，采用导入类.方法名，需要在方法名加上对应的订阅事件。
>    示例：sim.on('exampleEvent') 、on('play' | 'pause' | 'stop' | 'reset')
>
> 3. **方法具体调用形式**：和d.ts保持一致，需要包括参数类型、事件名、参数名、返回值类型。
>    示例：on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void
>    注意：尖括号<>可能会被识别为标签，导致界面显示失效，可增加一个\，以保证界面正常显示，如“\\<>”或使用转义字符\&lt; \&gt; 。

*（在此处给出方法的具体调用形式。如果是静态方法需说明）* 方法名称(参数1名称：参数1类型，参数2名称：参数2类型，……)：返回值类型

在此处给出方法描述。说明请参考上述写作说明第4、5点。

**模型约束**：此接口仅可在FA模型下使用。（如不涉及可删除）

**系统接口**：此接口为系统接口。（如不涉及可删除）

**需要权限**：ohos.permission.xxx（如不涉及可删除）

**系统能力**：SystemCapability.xxx.xxx（必选）

**参数：**（可选，如不涉及可删除）

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | 是   | 事件描述，需要说明触发时机。如一个方法涉及多个事件，需要分开说明。<br/>**示例1（单个）：**<br/>事件回调类型，支持的事件为`'play'`，当`play()`调用完成，音频开始播放，触发该事件。<br/>**示例2（多个）：**<br/>事件回调类型，支持的事件包括：`'play'` \| `'dataLoad' `\|`'finish'`。<br/>\- `'play'`：完成`play()`调用，音频开始播放，触发该事件。<br/>\- `'dataLoad'`：完成音频数据加载后触发该事件，即src属性设置完成后触发该事件。<br/>\- `'finish'`：完成音频播放后触发该事件。 |
| callback | Callback\<[CustomType](#classinterface)> | 否   | 参数描述。与[方法](#方法)要求一致。                          |

**返回值：**（可选，如不涉及可删除）

| 类型   | 说明                                  |
| ------ | ------------------------------------- |
| string | 返回值描述。与[方法](#方法)要求一致。 |

**示例：**

```js
// 必选项。与方法要求一致。

// 所有的示例代码需要进行自检。
// 不能出现缺符号、变量前后不一致等低错。
// 所有使用到的变量要进行声明。

// 不允许直接写参数名，必须是可使用、易替代的实际用例。如果非用户自定义填写，需通过注释进行说明。
// 例如：let result = xxx.createExample(parameterOne); // parameterOne由扫描自动获取

// 注释要精简、突出要点。需提供注释的典型场景还有：
// 1. 当代码不能说明变量命名的具体含义，或不能说明代码逻辑时，必须提供注释。
// 2. 涉及到复杂算法或特殊语法时，必须提供注释。
```

## Class/Interface

> *写作说明*
>
> 1. 可选，如果没有可删除。如果有多个，请分多个二级内容描述，并使用“##”自行新建二级标题。
>
> 2. 二级标题名为class、interface的名称。
>
> 3. 如果该API中，既有属性，又有方法，需要先进行属性的写作，并使用“###”三级标题。
>    如果该API中，只有属性，那么不需要新建三级标题，直接使用表格陈列属性。
>
> 4. 若Class/Interface被装饰器修饰，则需要说明“装饰器类型”。

类描述/interface描述。如果有使用限制，需要在这个地方说明。比方说，是否有前提条件，是否需要通过什么方法先构造一个实例。

**装饰器类型：** @Sendable

### 属性

> *写作说明*
>
> 除标题使用三级标题外，其余要求同[属性](#属性)，如仅有属性，可删除“属性”小标题，直接写interface名称作为二级标题。

### Class/Interface中的方法

> *写作说明*
>
> 1. 标题名为方法名，使用**三级标题，没有前缀**。如果是订阅方法，需要在方法名加上对应的订阅事件。
>    示例： getSimIccId
>    订阅方法：on('exampleEvent')
> 2. 其余与[方法](#方法)要求一致，不再重复。

## 枚举

> *写作说明*
>
> 1. 可选，如果没有可删除。如果有多个枚举，请分多个二级内容描述，并使用“##”自行新建二级标题。
>
> 2. 二级标题名为实际枚举名，比方说 BatteryHealthState 。

在此处给出该枚举类型的简要描述。如：表示连接的充电器类型的枚举。

**系统能力**：SystemCapability.xxx.xxx（必选）

| 名称 | 值   | 说明                       |
| ---- | ---- | -------------------------- |
| NONE | 1    | 表示连接的充电器类型未知。 |

## Type

> *写作说明*
>
> 1. 可选，如果没有可删除此二级标题，对应d.ts中的type定义。
>
> 2. 当前type分为两种情况，不同情况使用不同模板。
>     
>    - 当type为联合类型、交叉类型，其定义形如：type Xxx = number | string | 'xxx'，或 type AB = InterfaceA & InterfaceB ，参考[模板一](#type模板一)。
>    - 当type的定义为某个函数、interface的别名，形如：type Xxx\<Aaa, Bbb> = (param1: number, param2: string) => void 或是 type Xxx = (param1: number, param2: string)，按函数、interface的模板解释其参数，并在列表前给出type的定义，参考[模板二](#type模板二)。
>
> 3. 如果为取值范围为具体取值，如固定的字符串、枚举值等，需要说明其数据类型和指定取值；如果取值范围为指定类型，需说明是否取类型下任意值，还是有取值范围。
>
> 4. 类型如果为自定义类型，需要建立链接到对应的interface或enum中。


### Type模板一

type Xxx = number | string | 'xxx'  

在此处给出该类型的简要描述。如：表示允许的数据字段类型。

在此处给出该类型实际取值的逻辑。如：取值类型为下表类型中的并集/交集。

**系统能力**：SystemCapability.xxx.xxx（必选）

| 类型      | 说明                          |
| -----------| ---------------------------- |
| number     | 表示值类型为数字，可取任意值。     |
| string     | 表示值类型为字符，可取任意值。     |
| 'xxx'      | 表示xxx（此处写值的含义），值固定为'xxx'字符串。     |

### Type模板二

*（此处以函数别名为例）*

*（在此处给出type的具体定义形式）* type Xxx\<Aaa, Bbb> = (param1: number, param2: string) => Interface1

**系统能力**：SystemCapability.xxx.xxx（必选）

**参数：**（可选，如不涉及可删除）

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| param1    | number                              | 是   | 参数描述。与[方法](#方法)要求一致。          |
| param2 | string | 否   | 参数描述。与[方法](#方法)要求一致。                          |

**返回值：**（可选，如不涉及可删除）

| 类型   | 说明                                  |
| ------ | ------------------------------------- |
| [Interface1](#interface1) | 返回值描述。与[方法](#方法)要求一致。 |

### Type模板三

*（此处以含有多个属性字段的Interface别名为例）*

*（在此处给出type的具体定义形式）*  type Xxx = { aaa: string; bbb?: number; }

**系统能力**：SystemCapability.xxx.xxx（必选）


| 名称   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| aaa | string | 是 | 属性描述。 | 
| bbb | number | 否 | 属性描述。 | 

## API参考写作FAQ
### 问题1：带二级模块的父模块如何写作
> **带二级模块的父模块写作要求：**
>
> 1、在模块概述处，写明本模块的定义/功能。
>
> 2、按正常API模块要求提供API level等相关说明。
>
> 3、以section列举其下包含的二级模块，并提供二级模块定义/功能（注意与二级模块页面的概述保持一致），链接到二级模块。
>
> 4、每个二级模块（section）下，提供d.ts定义中对应的“系统能力”（@syscap）字段。工具链基于该字段为该topic打device-type属性。
>
> 以下为样例。
####  @ohos.arkui.node 
Node将自定义节点的二级模块API组织在一起，方便开发者进行导出使用。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前不支持在预览器中使用自定义节点。

##### BuilderNode

[BuilderNode](./js-apis-arkui-builderNode.md#buildernode)模块提供能够挂载系统组件的自定义节点BuilderNode。不建议将BuilderNode作为子节点挂载到其他自定义节点上。<br/>
**系统能力**：ohos.xxx

##### FrameNode

[FrameNode](./js-apis-arkui-frameNode.md#framenode)模块提供自定义节点FrameNode，表示组件树的实体节点。[NodeController](./js-apis-arkui-nodeController.md#nodecontroller)可通过[BuilderNode](./js-apis-arkui-builderNode.md#buildernode)持有的FrameNode将其挂载到[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)上，也可通过FrameNode获取[RenderNode](./js-apis-arkui-renderNode.md#rendernode)，挂载到其他FrameNode上。<br/>
**系统能力**：ohos.xxx

### 问题2：Class是继承的，只有一个导入模块，这种情况下的SysCap应该写在哪里
>
> 声明方式形如：[EmbeddableUIAbilityContext.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/EmbeddableUIAbilityContext.d.ts)，参考如下样例写作。<br/>
>

#### EmbeddableUIAbilityContext

EmbeddableUIAbilityContext是需要保存状态的[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)所对应的context，继承自[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)。<br/>
EmbeddableUIAbilityContext提供EmbeddableUIAbility的相关配置信息以及操作EmbeddableUIAbility和ServiceExtensionAbility的方法，如启动EmbeddableUIAbility，停止当前EmbeddableUIAbilityContext所属的EmbeddableUIAbility，启动、停止、连接、断开连接ServiceExtensionAbility等。

> **说明：**
>
>  - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。

##### 导入模块

```ts
import { common } from '@kit.AbilityKit';
```
**模型约束**：此接口仅可在Stage模型下使用。<br/>
**系统能力**：SystemCapability.Ability.AbilityRuntime.Core<br/>
**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

### 问题3：接口存在已知bug的写法
>
> 1、对于此类情况，首先需要在《版本说明书》中体现“已知问题”。
>
> 2、在API参考的“接口描述”处，采用固定句式描述接口已知bug"本接口存在已知问题，详情请参见“已知问题”。"
>
> 3、在接口bug修复后，针对所有涉及该接口的文档，统一搜索上述固定句式，删除。
>
#### getStringSync

getStringSync(resId: number, ...args: Array<string | number>): string

获取指定资源ID对应的字符串，并根据args参数对字符串进行格式化，使用同步方式返回。
本接口存在已知问题，详情请参见“已知问题”（链接到《版本说明书》对应的已知问题处）。


## 变更日志

| 变更说明                                                                 | 日期         |
| ----------------------------------------------------------------------- | ------------ |
| 新增被装饰器修饰的Class/Interface/属性写法。 | 2025/09/19|
| 新增“API参考写作FAQ”章节，提供特殊场景的API参考写法及常见问题说明。 | 2025/07/22|
| 精简Promise\<void>固定句式。新写作内容使用新句式；存量内容无需主动整改，表意无问题。 | 2025/06/10 |
| 补充“关于匿名对象整改@since版本号情况的说明”固定句式。 | 2025/06/03 |
| 优化权限的写作规范，可覆盖多种类型的权限描述，适配扫描工具需求。 | 2025/03/12 |
| 增加Type模板三，增加以含有多个属性字段的Interface别名。 | 2025/03/04 |
| 增加示例代码需捕获传参异常的要求。 |  2025/03/03 |
| 针对const定义的只读变量，增加模板。 |   2024/12/31  |
| 1. 修改方法模板，增加static等关键字声明的方法描述说明。 |  2024/05/16  |
| 1. 修改Type模板，除原来的联合类型外，增加交叉类型，以及type作为函数、interface等别名的情况。<br/>2. 修改属性模板，仅针对interface和接口定义而言，明确规则，如果有?，则判定为“可选”。 |  2024/05/10  |
| 1. 修改属性的模板，将“可读”、“可写”、“必填”，统一为“只读”、“必填”。<br/>2. 修改Type的模板，模板修改为“取值范围/说明”，并增加相关说明。<br/>3. 删除自定义类型，合并进class和interface的模板中。 |  2023/02/01  |
| 1. 总体写作说明整理为表格。<br/>2. “图片路径”中，增加图片的引用方式说明。<br/>3. 增加“文档结构”，对文档各节点顺序进行说明。<br/>4. “权限说明”中，增加多权限的描述方式。<br/>5. 增加@FAModelOnly/@StageModelOnly标记在文档的描述方式。<br/>6. 增加异步接口说明（callback、Promise）。<br/>7. 增加示例代码语言的标准和规范。<br/>8. 增加文档链接的标准写法。<br/>9. 增加模块描述的固定句式、示例。<br/>10. 增加“on/off”等订阅方法的说明。<br/>11. 修改@syscap的描述方式，除表格内的差异项，其余保持一致。 <br/>12. 修改@systemapi的描述方式，仅保留“该系统为系统接口。”。<br/>13. 删除MR版本说明。                                                                 |  2022/6/24  |
| 增加错误码说明。                                                          | 2022/10/11  |
| 1. 增加**常量const**、**类型type**的模板。<br/> 2. 修改自定义类型interface的表格，去除“可读、可写”，与d.ts保持一致，增加“必填”。<br/> 3. 针对同时存在起始版本和废弃版本的接口，增加废弃说明的模板。                          |2022/11/22   |

<!--no_check-->
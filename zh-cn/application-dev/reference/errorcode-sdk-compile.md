# SDK编译校验错误码
<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @fang-jinxu-->
<!--Designer: @majiajun518-->
<!--Tester: @RayShih-->
<!--Adviser: @fang-jinxu-->

## 11706006 接口不支持卡片工程 

**错误信息**

XXX can't support form application.

**错误描述**

接口不支持在卡片工程中使用。

**可能原因**

该接口不支持卡片能力。

**处理步骤**

更换方案，调用其他接口。

## 11706007 接口不支持跨平台使用

**错误信息**

XXX can't support crossplatform application.

**错误描述**

接口不支持跨平台使用。

**可能原因**

该接口暂不支持跨平台能力。

**处理步骤**

更换方案，调用其他接口。

## 11706008 FA模型接口在Stage工程中使用

**错误信息**

This API is used only in FA Mode, but the current Mode is Stage.

**错误描述**

当前为Stage工程，但使用的接口为FA模型接口。

**可能原因**

错误的使用当前工程不支持的模型接口。

**处理步骤**

更换为Stage工程支持的接口。

## 11706009 Stage模型接口在FA工程中使用

**错误信息**

This API is used only in Stage Mode, but the current Mode is FA.

**错误描述**

当前为FA工程，但使用的接口为Stage工程接口。

**可能原因**

错误的使用当前工程不支持的模型接口。

**处理步骤**

更换为FA模型支持的接口。

## 11706010 接口不支持在原子化服务中使用

**错误信息**

XXX can't support atomicservice application.

**错误描述**

接口不支持在原子化服务中使用。

**可能原因**

该接口暂不支持原子化服务能力。

**处理步骤**

更换方案，调用其他接口。

## 11706011 接口在低版本设备上运行存在兼容性风险

**错误信息**

The {apiName} API is supported since SDK version {sinceVersion}. However, the current compatible SDK version is {compatibleSdkVersion}.It is recommended to use apiAvailable to safeguard API compatibility.

**错误描述**

应用调用高版本接口在低版本设备上运行，存在兼容性风险。

**可能原因**

调用接口的最低支持SDK版本高于应用的兼容SDK版本。

应用的兼容SDK版本参考工程根目录的build-profile.json5文件中的"compatibleSdkVersion"字段。

**处理步骤**

选择以下任一方案消除兼容性风险：

方案一：使用apiAvailable接口判断当前设备是否支持该API，在支持时调用，不支持时走降级逻辑。

参考API文档说明：[apiAvailable](./apis-basic-services-kit/js-apis-device-info.md#deviceinfoapiavailable)。

方案二：更换为低版本兼容的替代接口。        

## 11706012 @Available接口在低版本设备上运行存在兼容性风险

**错误信息**

The {apiName} API is available since SDK version {sinceVersion}. However, the current compatible SDK version is {compatibleSdkVersion}.It is recommended to use apiAvailable to safeguard API compatibility.

**错误描述**

应用调用@Available标注的高版本接口在低版本设备上运行，存在兼容性风险。

**可能原因**

@Available装饰器中声明的SDK版本高于应用的兼容SDK版本。

应用的兼容SDK版本参考工程根目录的build-profile.json5文件中的"compatibleSdkVersion"字段。

**处理步骤**

选择以下任一方案消除兼容性风险：

方案一：使用apiAvailable接口判断当前设备是否支持该API，在支持时调用，不支持时走降级逻辑。

参考API文档说明：[apiAvailable](./apis-basic-services-kit/js-apis-device-info.md#deviceinfoapiavailable)。

方案二：更换为低版本兼容的替代接口。 

## 11706013 apiAvailable接口参数无效

**错误信息**

1、Invalid parameters for apiAvailable.Only digits and dots are allowed.

2、Invalid parameters for apiAvailable.The api version must be a decimal integer between 1 and 25.The M.S.F format must meet the following requirements: The value must be in the three decimal format, M must be greater than or equal to 26, and S and F must be decimal integers between 0 and 99.

3、Invalid parameters for apiAvailable.The api version must be a decimal integer between 1 and 25.The M.S.F format must meet the following requirements: The value must be in the three decimal format, M must be decimal integers between 1 and 99, and S and F must be decimal integers between 0 and 99.

4、Invalid parameters for apiAvailable.Only digits, dots, and left and right parentheses are allowed.

5、Invalid parameters for apiAvailable.Null and undefined are not allowed for parameters.

6、Invalid parameters for apiAvailable.Only decimal digits are allowed.

**错误描述**

apiAvailable接口参数格式不符合规范，包括：参数包含非法字符、版本号范围越界、M.S.F格式不合规、参数为空或未定义等。

**可能原因**

1、参数中包含了除数字和点以外的非法字符，例如：`apiAvailable("12a3")`、`apiAvailable("12#3")`。

2、整数版本号不在1~25范围内，或M.S.F格式中M小于26，例如：`apiAvailable(0)`、`apiAvailable(26)`、`apiAvailable("25.0.1")`。

3、整数版本号不在1~25范围内，或M.S.F格式中M不在1~99范围内，例如：`apiAvailable("100.0.1")`。

4、参数中包含了除数字、点和括号以外的非法字符，例如：`apiAvailable("12<=v<=15")`。

5、参数传入了null或undefined，例如：`apiAvailable(null)`、`apiAvailable(undefined)`。

6、参数中包含了非十进制数字字符，例如：`apiAvailable("12a")`。

**处理步骤**

1、核对apiAvailable接口的参数格式要求，确认当前参数类型（整数版本号、M.S.F版本号或版本范围表达式）。

2、根据参数类型修正版本号：

 - 整数格式：取值范围为1~25，例如：`apiAvailable(12)`。

 - M.S.F格式：M>=26且M<=99，S和F为0~99的整数，例如：`apiAvailable("26.0.1")`。

 - 版本范围表达式：仅允许使用数字、点和括号，例如：`apiAvailable("26.0.0")`。

3、确保参数不为null或undefined。

4、参考API文档说明：[apiAvailable](./apis-basic-services-kit/js-apis-device-info.md#deviceinfoapiavailable)。

## 11706014 无效版本号

**错误信息**

Invalid {osName} version.

**错误描述**

版本号格式校验失败或版本号未在允许列表中（sdkApiVersionMap.json）。

**可能原因**

1、格式不符合规范：版本号需满足以下格式之一：

 - M.S.F带括号格式：如：6.0.0(20)

 - M.S.F格式，如：26.0.0

2、版本号不在允许列表中：格式正确但未在sdkApiVersionMap.json中匹配到对应条目。

**处理步骤**

1、检查传入的version参数格式是否符合上述两种格式之一。

2、确认使用的SDK版本是否在sdkApiVersionMap.json文件的列表中。

<!--RP1--><!--RP1End-->

## 11706016 @Available装饰器中的版本号无效

**错误信息**

The runtime OS for the current project is {runtimeOS}. The OS version number {versionNumber} is invalid.

**错误描述**

当前项目运行时为{runtimeOS}，@Available装饰器中定义的版本号{versionNumber}无效。

**可能原因**

1、@Available装饰器中的版本号超出了取值范围，例如：`@Available({minApiVersion: "0"})`、`@Available({minApiVersion: "1000"})`。

2、@Available装饰器中的M.S.F格式不符合规范，例如：`@Available({minApiVersion: "26.0"})`、`@Available({minApiVersion: "0.1.2"})`、`@Available({minApiVersion: "26.0.1.0"})`。

3、@Available装饰器中的版本号包含非法字符，例如：`@Available({minApiVersion: "12a"})`、`@Available({minApiVersion: "12#3"})`。

**处理步骤**

1、根据错误信息中的{runtimeOS}确认当前项目的运行时类型，根据{versionNumber}定位@Available装饰器中不合规的版本号。

2、按照运行时的版本号规范修正版本号：

 - 整数格式：取值范围1~999，例如：`@Available({minApiVersion: "12"})`、`@Available({minApiVersion: "26"})`、`@Available({minApiVersion: "100"})`。

 - M.S.F格式：M为1~99的整数，S和F为0~99的整数，例如：`@Available({minApiVersion: "26.0.0"})`。

3、确保版本号不含非法字符，且格式完整（M.S.F必须为三段式）。

4、参考API文档说明：[Available](./apis-basic-services-kit/js-apis-annotation.md#available)。

## 11706017 @Available装饰器中的操作系统名称无效

**错误信息**

The runtime OS for the current project is {runtimeOS}. @Available is not supported on the OS: {osName}.

**错误描述**

当前项目运行时为{runtimeOS}，@Available装饰器中指定的操作系统名称{osName}无效。

**可能原因**

1、@Available装饰器中指定的操作系统名称合法但与项目运行时不匹配，例如：项目运行时为OpenHarmony，但装饰器中指定了`@Available({minApiVersion: "HarmonyOS"})`。

2、@Available装饰器中的操作系统名称拼写错误，例如：`@Available({minApiVersion: "HarmonOS"})`。

3、@Available装饰器中使用了不支持的操作系统名称，例如：`@Available({minApiVersion: "ABC"})`。

**处理步骤**

1、根据错误信息中的{runtimeOS}确认当前项目的运行操作系统，根据{osName}定位@Available装饰器中不合规的操作系统名称。

2、将@Available装饰器中的操作系统名称替换为与项目运行时匹配的正确名称，例如：项目运行时为OpenHarmony时，使用`@Available({minApiVersion: "OpenHarmony"})`。

3、确认操作系统名称拼写正确，且为当前运行时所支持的名称。

4、参考API文档说明：[Available](./apis-basic-services-kit/js-apis-annotation.md#available)。

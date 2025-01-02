# ArkCompiler子系统变更说明

## cl.arkcompiler.1 应用发生OOM时Heapdump产物文件格式变更

**访问级别**

其他

**变更原因**

为了提升应用发生OOM时Heapdump生成dump文件的概率和效率，支撑开发者定位内存泄漏问题：

1. 移除Heapdump在线解析逻辑，产物格式由.heapsnapshot变为.rawheap。

2. rawheap文件解析生成heapsnapshot文件的功能由SDK中集成的rawheap_translator工具提供。

**变更影响**

该变更为不兼容变更。

变更前：应用OOM时Heapdump生成dump文件的格式为.heapsnapshot。

变更后：应用OOM时Heapdump生成dump文件的格式为.rawheap，需要通过调用rawheap_translator工具将rawheap文件解析转换为heapsnapshot文件。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

OpenHarmony的SDK在toolchains目录下新增rawheap_translator工具。

**适配指导**

将当前应用OOM时Heapdump生成的rawheap文件转换成之前的heapsnapshot文件，需要使用设备或SDK中的rawheap_translator工具

工具获取：

当前rawheap_translator工具适配了OHOS、Windows、Linux、MacOS平台：

OHOS平台工具所在路径：/bin/rawheap_translator, 可直接在设备中调用。

Windows、Linux、MacOS平台工具在SDK中获取，所在路径：/toolchains/rawheap_translator。

环境变量设置：

Windows环境变量设置：

在此电脑 > 属性 > 高级系统设置 > 高级 > 环境变量 > Path > 编辑中，将rawheap_translator.exe的所在路径添加到Path中，配置完成后重启电脑。

MacOS环境变量设置：

打开终端工具，输入以下命令并执行：

```
echo $SHELL
```

上述命令执行结果可能为/bin/bash或者/bin/zsh，下面以/bin/bash为例，/bin/zsh同理。执行以下命令，打开.bash_profile文件：

```
vi ~/.bash_profile
```

单击键盘上字母“i”，进入编辑模式，输入以下命令：

```
export PATH=$PATH:<rawheap_translator路径>
```

编辑完成后，单击键盘Esc键退出编辑模式，然后输入“:wq”，单击键盘Enter键保存修改。

执行以下命令，使配置的环境变量生效：

```
source ~/.bash_profile
```

配置完成后重新启动电脑。

使用方法：

工具调用命令：

```
rawheap_translator <rawheap_file>

rawheap_translator <rawheap_file> <heapsnapshot_file>
```

参数列表：

| 选项 | 描述 | 举例 |
| - | - | - |
| <rawheap_file> | 应用OOM时Heapdump生成的rawheap文件路径，例如：/data/log/reliability/resource_leak/memory_leak | 解析目录D:\temp\rawheap下的example.rawheap文件：rawheap_translator D:\temp\example.rawheap |
| <heapsnapshot_file> | 指定解析生成文件的路径和名称，文件后缀必须为heapsnapshot；若不指定则默认为当前路径，文件名自动生成 | 解析目录D:\temp\rawheap下的example.rawheap文件，并在D:\temp\result下生成结果文件result.heapsnapshot：rawheap_translator D:\temp\example.rawheap D:\temp\result\result.heapsnapshot |
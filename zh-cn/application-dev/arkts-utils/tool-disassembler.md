# Disassembler反汇编工具

## 简介

Disassembler是ArkTS反汇编工具，如果开发者需要分析方舟字节码文件（\*.abc）相关问题，可使用Disassembler将字节数据反汇编成可阅读的汇编指令。

工具随DevEco Studio SDK发布，以windows平台为例，Disassembler工具位置为：[DevEco Studio安装目录]\sdk\[SDK版本]\openharmony\toolchains\ark_disasm.exe。

## 命令行说明

反汇编命令：

```
ark_disasm.exe [options] input_file output_file
```

参数说明：

| 参数 | 是否可缺省 | 描述 | 
| -------- | -------- | -------- |
| [options] | 可缺省 | 命令选项，详见下文options选项说明。 | 
| input_file | 不可缺省 | 待反汇编的方舟字节码文件路径。 | 
| output_file | 不可缺省 | 反汇编内容的输出文件路径。 | 

options选项说明：

| 选项 | 是否可缺省 | 是否存在入参 | 描述 | 
| -------- | -------- | -------- | -------- |
| --debug | 可缺省 | 不带参数 | 使能输出调试信息，默认输出到屏幕。 | 
| --debug-file | 可缺省 | 带参数 | 如果使能了--debug，指定调试信息的输出文件。 | 
| --help | 可缺省 | 不带参数 | 打印帮助提示。 | 
| --skip-string-literals | 可缺省 | 不带参数 | 跳过对字符串字面量的反汇编。 | 
| --quiet | 可缺省 | 不带参数 | 使能所有'--skip-'开头的选项。 | 
| --verbose | 可缺省 | 不带参数 | 使能输出额外信息（字节位置、方舟字节码格式、操作码）。 | 
| --version | 可缺省 | 不带参数 | 显示配套方舟字节码文件版本号以及最低支持的方舟字节码文件版本。 | 

## 使用示例

假设已存在方舟字节码文件：test.abc，其源代码如下：

```
let i = 99;
function show(){return i;}
show();
```


执行如下命令，就能生成反汇编文件：test.txt。生成的反汇编文件内带有操作码及格式等信息。

```
ark_disasm.exe test.abc test.txt
```

查看反汇编文件的内容。


```
cat test.txt
```

内容如下：

```
# source binary: test.abc                                                    // 反汇编的方舟字节码文件

.language ECMAScript

# ====================
# LITERALS                                                                   // 字面量数据

0 0x203 { 0 [
	MODULE_REQUEST_ARRAY: {
	};
]}

# ====================
# RECORDS                                                                    // 模块定义数据

.record _ESConcurrentModuleRequestsAnnotation {                              // _开头这些都是固定的模块数据
}

.record test {                                                               // 一个js文件对应一个模块数据，包含了模块的相关信息（在方舟字节码文件中的位置，是否是commonjs ...）
	u8 isCommonjs = 0x0
	u32 moduleRecordIdx = 0x203
	......
}

# ====================
# METHODS                                                                    // 方法定义数据

L_ESSlotNumberAnnotation:
	u32 slotNumberIdx { 0x0 }
.function any test.#*#show(any a0, any a1, any a2) <static> {                // 此方法源码中的show方法，同时这里也说明了，它属于test模块
	ldlexvar 0x0, 0x0
	......
}

L_ESSlotNumberAnnotation:
	u32 slotNumberIdx { 0x3 }
.function any test.func_main_0(any a0, any a1, any a2) <static> {            // 此方法是自动生成的，可以理解成整个js文件就是一个方法，方法名为func_main_0
	newlexenv 0x1
	......
}

# ====================
# STRING                                                                     // 符号表信息

[offset:0x88, name_value:i]
```

使用参数--verbose，可打印偏移量等更多详细信息。


```
ark_disasm.exe --verbose test.abc test.txt
```

此处列出部分示例。

```
.record _ESSlotNumberAnnotation { # offset: 0x00cd, size: 0x0026 (38)                                  // 这里打印了模块在方舟字节码文件中具体的位置和大小
}

.record test { # offset: 0x00f3, size: 0x0098 (152)                                                    // 这里打印了模块在方舟字节码文件中具体的位置
	u32 moduleRecordIdx = 0x203 # offset: 0x0144                                                   // 这里打印了模块信息的位置
}
......
.function any test.#*#show(any a0, any a1, any a2) <static> { # offset: 0x0153, code offset: 0x0245    // 这里打印了方法信息具体的位置和方法中指令的具体位置
#   CODE:
	ldlexvar 0x0, 0x0 # offset: 0x0249, [IMM4_IMM4].........[0x3c 0x00]                            // 这里打印了每条指令的具体位置
	......
}
```

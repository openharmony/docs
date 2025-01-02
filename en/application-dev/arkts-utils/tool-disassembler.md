# Disassembler

## Introduction

Disassembler is an ArkTS disassembly tool. If you need to analyze issues related to Ark bytecode files (\*.abc), you can use Disassembler to disassemble byte data into readable assembly instructions.

The tool is released with the DevEco Studio SDK. Take the Windows platform as an example. The Disassembler tool is stored in [DevEco Studio installation directory]\sdk\[SDK version]\openharmony\toolchains\ark_disasm.exe.

## Commands

Disassembly command:

```
ark_disasm.exe [options] input_file output_file
```

Parameter description

| Option| Left Unspecified Allowed| Description| 
| -------- | -------- | -------- |
| [options] | This parameter can be left unspecified.| Command option. For details, see the following description of options.| 
| input_file | No| Path of the ARK bytecode file to be disassembled.| 
| output_file | No| Output file path of the disassembled content.| 

Description of options

| Option| Left Unspecified Allowed| Argument Carried| Description| 
| -------- | -------- | -------- | -------- |
| --debug | This parameter can be left unspecified.| No| Enables the function of outputting debugging information. By default, debugging information is output to the screen.| 
| --debug-file | This parameter can be left unspecified.| Yes| Specifies the output file of debugging information if --debug is enabled.| 
| --help | This parameter can be left unspecified.| No| Prints help information.| 
| --skip-string-literals | This parameter can be left unspecified.| No| Skips disassembly of string literals.| 
| --quiet | This parameter can be left unspecified.| No| Enables all options starting with '--skip-'.| 
| --verbose | This parameter can be left unspecified.| No| Enables the output of additional information (byte position, ARK bytecode format, and operation code).| 
| --version | This parameter can be left unspecified.| No| Displays the version number of the Ark bytecode file and the earliest supported Ark bytecode file version.| 

## Samples

Assume that the Ark bytecode file test.abc exists. The source code is as follows:

```
let i = 99;
function show(){return i;}
show();
```


Run the following command to generate the disassembly file test.txt: The generated disassembly file contains information such as the operation code and format.

```
ark_disasm.exe test.abc test.txt
```

View the content of the disassembly file.


```
cat test.txt
```

Modify the file as follows:

```
# source binary: test.abc // Disassembled Ark bytecode file

.language ECMAScript

# ====================
# LITERALS // Literal data

0 0x203 { 0 [
	MODULE_REQUEST_ARRAY: {
	};
]}

# ====================
# RECORDS // Module definition data

The data starts with .record _ESConcurrentModuleRequestsAnnotation { // _ and is fixed module data.
}

.record test { // One JS file corresponds to one module data, including the module information (location in the ARK bytecode file, whether it is commonjs...).
	u8 isCommonjs = 0x0
	u32 moduleRecordIdx = 0x203
	......
}

# ====================
# METHODS // Method definition data

L_ESSlotNumberAnnotation:
	u32 slotNumberIdx { 0x0 }
The show method in the source code of the .function any test.#*#show(any a0, any a1, any a2) <static> { // method belongs to the test module.
	ldlexvar 0x0, 0x0
	......
}

L_ESSlotNumberAnnotation:
	u32 slotNumberIdx { 0x3 }
The .function any test.func_main_0(any a0, any a1, any a2) <static> { // method is automatically generated. The entire JS file can be regarded as a method. The method name is func_main_0.
	newlexenv 0x1
	......
}

# ====================
# STRING // Symbol table information

[offset:0x88, name_value:i]
```

Use the --verbose parameter to print more details such as the offset.


```
ark_disasm.exe --verbose test.abc test.txt
```

Some examples are listed here.

```
.record _ESSlotNumberAnnotation { # offset: 0x00cd, size: 0x0026 (38) //: Prints the specific position and size of the module in the ARK bytecode file.
}

.record test {# offset: 0x00f3, size: 0x0098 (152) // The specific position of the module in the ARK bytecode file is displayed.
	u32 moduleRecordIdx = 0x203 # offset: 0x0144 // Location where the module information is printed
}
......
.function any test.#*#show(any a0, any a1, any a2) <static> { # offset: 0x0153, code offset: 0x0245 //: indicates the specific location of the method information and the specific location of the instruction in the method.
#   CODE:
	ldlexvar 0x0, 0x0 # offset: 0x0249, [IMM4_IMM4].........[0x3c 0x00] //: indicates the location of each command.
	......
}
```

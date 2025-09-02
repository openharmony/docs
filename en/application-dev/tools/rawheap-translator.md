# rawheap-translator
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @wanghuan2025-->
<!--Designer: @wanghuan2025-->
<!--Tester: @kir175; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

## When to Use

To facilitate fault locating, your app automatically performs heap dump when the ArkTS memory is out of memory (OOM). This operation saves all object information on the current heap of the VM in a binary file with the suffix .rawheap. You can use the rawheap_translator tool to parse the .rawheap file and generate the .heapsnapshot file. You can import and view the file by [importing heap snapshots offline](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388) in DevEco Studio or the memory tool in the developer tool of the Chrome browser.

## Operation Guide

### How to Obtain

This tool supports the OHOS, Windows, Linux, and MacOS platforms. To obtain the tool, perform the following steps:

- /bin/rawheap_translator (applicable only to OHOS devices)
- Obtain the rawheap_translator package from sdk/default/openharmony/toolchains/ in the SDK. The package is applicable to all platforms.

### Environment Configuration

For the OHOS platform, the rawheap_translator tool is embedded in the system path. Therefore, you can directly use this tool on the terminal.

For a non-OHOS platform, you are advised to place the rawheap_translator tool obtained from the SDK in a stable path and set the path as a system environment variable. In this way, you can directly use the tool on the terminal without specifying the path each time.

The method of configuring environment variables varies according to the operating system. The following provides some configuration examples for your reference.

- Set Windows environment variables (Windows 10 is used as an example).

  1. Right-click This PC and choose Properties from the shortcut menu.
  2. In the displayed window, click the Advanced System Settings tab.
  3. In the displayed window, click Environment Variables on the Advanced tab page.
  4. In the displayed window, double-click the Path variable in the System variables area.
  5. In the displayed window, click New.
  6. Enter the local path for storing the rawheap_translator tool in the text box.
  7. Click OK to close all the displayed windows.
  8. Restart the endpoint.

- Set MacOS environment variables (MacOS 15 is used as an example).

  1. Start the terminal tool and run the following command:

      ```bash
      echo $SHELL
      ```

  2. Perform the following operations based on the command output in step 1:

      a. If the command output is `/bin/bash`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/rawheap_translator' >> ~/.bash_profile
      source ~/.bash_profile
      ```

      b. If the command output is `/bin/zsh`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/rawheap_translator' >> ~/.zshrc
      source ~/.zshrc
      ```

## How to Use

### Parsing Command
```bash
rawheap_translator [rawheap_file] [heapsnapshot_file]
```
### Parameters

| Parameter| Yes| Description|
| -------- | --- | ----------------- |
| [rawheap_file] | Yes| Path of the .rawheap file generated when the application OOM needs to be parsed.|
| [heapsnapshot_file] | No| Path of the heapsnapshot file generated after parsing. The path must have the read and write permissions.<br>If the parameter is not specified, the path of the current command is used by default.<br>The file name extension must be heapsnapshot.

## Examples of Using Parsing Commands

### Parsing Example


On OHOS
The tool path on the OHOS device is /bin/rawheap_translator. You are advised to set the path for generating the heapsnapshot file to /data/local/tmp. Other paths may not have the write permission.
```bash
> /bin/rawheap_translator /data/log/reliability/resource_leak/memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap /data/local/tmp/myapplication-7979-7979.heapsnapshot
```
On Windows
Open the cmd window, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> rawheap_translator.exe memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
On Linux
Go to the path of the .rawheap file, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> ./rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
On macOS
Open the device, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
Reference output:
```bash
[INFO ] ParseVersion            current metadata version is 1.0.0
[INFO ] ParseTypeEnums          total JSType count 214
[INFO ] ParseTypeList           total metadata count 220
[INFO ] SetBitField             set BitField offset 8
[INFO ] SetBitField             set BindingSize offset 32
[INFO ] SetBitField             set Length offset 8
[INFO ] SetBitField             set Data offset 16
[INFO ] ReadVersion             current rawheap version is 1.0.0
[INFO ] RawHeap                 start to translate rawheap
[INFO ] ReadRootTable           root node count 6244
[INFO ] ReadStringTable         string table count 11208
[INFO ] ReadObjTable            section objects count 96432
[INFO ] Translate               success
[INFO ] Serialize               start to serialize
[INFO ] Translate               file save to /data/local/tmp/myapplication-7979-7979.heapsnapshot
```

## File Specifications

The size of the rawheap file and the time required for generating the file are strongly positively correlated with the current ArkTS heap memory size and the number of live objects. When the ArkTS heap memory usage is high and there are a large number of live objects, the generated rawheap file is larger and takes a longer time. You can subscribe to the [resource leak events](../dfx/hiappevent-watcher-resourceleak-events.md) and customize the event processing logic.

Since API version 20, VMs support two types of heap dump.
| Specifications| Features|
| :--- | :--- |
| TRIM_LEVEL_1 | The dump speed is fast, and the generated rawheap file is large.<br>In versions earlier than API version 20, the VM specifications are TRIM_LEVEL_1 by default.|
| TRIM_LEVEL_2 | The dump speed is slow. The size of the generated rawheap file is about 40% smaller than that of TRIM_LEVEL_1.|

To help developers understand the performance and traffic overhead caused by reporting rawheap files to the server, the following table lists the size, generation duration, and parsing duration of rawheap files generated by HeapDump of different specifications under different heap sizes.

|Specifications|Heap Size (MB)|.rawheap File Size (MB)|File Generation Duration (s)|Parsing Duration (s)|
|:---|:---|:---|:---|:---|
| TRIM_LEVEL_1 | 690 | 629 | 2.64 | 14 |
| TRIM_LEVEL_2 | 690 | 376 | 3.47 | 14 |
| TRIM_LEVEL_1 | 653 | 618 | 2.63 | 13 |
| TRIM_LEVEL_2 | 653 | 347 | 3.36 | 13 |
| TRIM_LEVEL_1 | 576 | 563 | 3.63 | 15 |
| TRIM_LEVEL_2 | 576 | 294 | 4.53 | 15 |


## FAQs
### What should I do if the tool version does not match?
**Problem**<br>
During parsing, the following message is displayed: The version of the original heap file 2.0.0 does not match the current original heap file translator. Use the latest translator.
```bash
[INFO ] ParseVersion            current metadata version is 1.0.0
[INFO ] ParseTypeEnums          total JSType count 214
[INFO ] ParseTypeList           total metadata count 220
[INFO ] SetBitField             set BitField offset 8
[INFO ] SetBitField             set BindingSize offset 32
[INFO ] SetBitField             set Length offset 8
[INFO ] SetBitField             set Data offset 16
[INFO ] ReadVersion             current rawheap version is 2.0.0
[ERROR] ParseRawheap            The rawheap file's version 2.0.0 is not matched the current rawheap translator, please use the newest version of the translator!
```
**Cause**<br>
The current tool version is earlier than the rawheap file version.<br>
**Solution**<br>
Upgrade the tool version to 2.0.0.

### What should I do if the file cannot be opened?
**Problem**<br>
Symptom: The message "FileStream: open file failed!" is displayed during parsing.
```bash
[INFO ] ParseVersion            current metadata version is 1.0.0
[INFO ] ParseTypeEnums          total JSType count 214
[INFO ] ParseTypeList           total metadata count 220
[INFO ] SetBitField             set BitField offset 8
[INFO ] SetBitField             set BindingSize offset 32
[INFO ] SetBitField             set Length offset 8
[INFO ] SetBitField             set Data offset 16
[INFO ] ReadVersion             current rawheap version is 1.0.0
[INFO ] RawHeap                 start to translate rawheap
[INFO ] ReadRootTable           root node count 6244
[INFO ] ReadStringTable         string table count 11208
[INFO ] ReadObjTable            section objects count 96432
[INFO ] Translate               success
[ERROR] Initialize              open file failed
```
**Cause**<br>
You do not have the write permission on the specified file path.<br>
**Solution**<br>
Change the path to a path with the write permission.

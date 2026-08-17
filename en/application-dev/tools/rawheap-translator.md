# rawheap-translator

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @wanghuan2022-->
<!--Designer: @wanghuan2022-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=6c248426771c373b5fc9ba4ebb7efbb47b9f2d9a translatedAt=2026-08-13T03:18:21.467Z pushedAt=2026-08-13T06:39:38.682Z -->

## When to Use

To help you locate issues, the app automatically performs HeapDump when ArkTS Out of Memory (OOM) occurs. This operation saves all object information on the current VM heap to a binary file with the .rawheap extension. In addition, you can call [hidebug.dumpJsRawHeapData](https://developer.huawei.com/consumer/en/doc/harmonyos-references/js-apis-hidebug#hidebugdumpjsrawheapdata18) to obtain the rawheap file of the current thread, or use the command [hidumper --mem-jsheap pid [-T tid] --raw](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hidumper#querying-vm-heap-memory) to proactively obtain the rawheap file of a specified process or JS thread. You can use the rawheap_translator tool to parse the .rawheap file and generate a .heapsnapshot file. This file can be imported and viewed through [Heap Snapshot offline import](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388) in DevEco Studio or the memory tool in Chrome DevTools.

## Operation Guide

### How to Obtain

This tool supports Windows, Linux, and macOS platforms. The acquisition methods are as follows:

- **sdk/default/openharmony/toolchains/** in the SDK on all platforms.

### Environment Configuration

It is recommended that you place the rawheap_translator tool obtained from the SDK in a stable path and configure that path as a system environment variable. This way, you can use the tool directly in the terminal without specifying the path each time.

The methods of configuring environment variables vary depending on the system. The following provides some configuration examples for your reference.

- On Windows 10:

  1. Right-click **This PC** and choose **Properties**.

  2. Click **Advanced system settings**.

  3. Click **Environment Variables** on the **Advanced** tab page.

  4. Double-click the **Path** variable in the **System variables** area.

  5. In the displayed window, click **New**.

  6. Enter the path of rawheap_translator stored locally in the new text box.

  7. Click **OK** to close all the displayed windows.

  8. Restart the terminal.

- On macOS 15:

  1. Start the terminal tool and run the following command:

      ```bash
      echo $SHELL
      ```

  2. Perform the following operations based on the command output in step 1:

      a. If **/bin/bash** is displayed, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/rawheap_translator' >> ~/.bash_profile
      source ~/.bash_profile
      ```

      b. If **/bin/zsh** is displayed, run the following command:

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

| Parameter| Mandatory| Description|
| -------- | --- | ----------------- |
| [rawheap_file] | Yes| Path of the .rawheap file generated upon an OOM error of the application to be parsed.|
| [heapsnapshot_file] | No | File path of the generated heapsnapshot file. The path must have read and write permissions.<br>If this parameter is omitted, the default is the path where the command is executed, and the generated file is named hprof_yyyy-MM-dd-HH-mm-ss.heapsnapshot, where yyyy-MM-dd-HH-mm-ss is the time when the file is parsed.<br>If this parameter is specified, the file extension must be heapsnapshot. |

## Using Parsing Commands

### Examples

On Windows

Open the cmd window, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.

```bash
> rawheap_translator.exe memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```

On Linux

Go to the path of the .rawheap file, and run the parsing command to generate the .heapsnapshot file in the current path.

```bash
> rawheap_translator memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```

On macOS

Open the device, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.

```bash
> rawheap_translator memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```

Output example

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

The rawheap-file size and generation time are strongly and positively correlated with the current ArkTS heap size and the number of live objects. When the ArkTS heap memory usage is high and the number of live objects is large, the generated rawheap file is larger and the generation takes longer. You can subscribe to the [resource leak events](../dfx/hiappevent-watcher-resourceleak-events.md) and customize the event processing logic.

Starting from API version 20, the VM supports two HeapDump specifications. For details about switching between them, see [setJsRawHeapTrimLevel](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetjsrawheaptrimlevel20), which sets the trim level for dumping the raw heap snapshot of the VM in the current process.

Starting from API version 22, TRIM_LEVEL_1 mode adds the capability to parse object property names. As a result, the generated rawheap file is larger than before, and the specific increase depends on the number of object property names and the string size.

| Specifications| Features|
| :--- | :--- |
| TRIM_LEVEL_1 | The dump speed is fast, and the generated rawheap file is large.<br>Before API version 20, the VM uses **TRIM_LEVEL_1** by default.|
| TRIM_LEVEL_2 | The dump speed is slower, and the size of the generated rawheap file is about 40% smaller than that of **TRIM_LEVEL_1**.|

To understand the performance and traffic overhead caused by reporting the .rawheap file to the server, you can refer to the following table to obtain the size of the .rawheap file, file generation duration, and file parsing duration of heap dumps of different specifications.

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

**Symptom**<br>
During parsing, the message "The rawheap file's version 2.0.0 is not matched the current rawheap translator, please use the newest version of the translator!" is displayed.

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

**Possible Causes**<br>
The current tool version is earlier than the .rawheap file version.<br>
**Solution**<br>
Upgrade the tool version to 2.0.0.

### What should I do if the file cannot be opened?

**Symptom**<br>
The message "open file failed!" is displayed during parsing.

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

**Possible Causes**<br>
You do not have the write permission on the specified file generation path.<br>
**Solution**<br>
Change the path to a path on which you have the write permission.

### File Parsing Failure

**Problem Symptom**<br>
Tool parsing completes, but the conversion fails and no heapsnapshot file is generated.

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
```

**Cause**<br>
The parsing tool version is too old.<br>
**Solution**<br>
Use [DevEco Studio 6.1.1 Release](https://developer.huawei.com/consumer/en/download/deveco-studio) or a later version.
# rawheap-translator

## When to Use

To facilitate fault locating, applications automatically generate heap dump files in the case of ArkTS OOM errors. The VM scans and saves all object information on the current heap and generates .rawheap files in binary format. You can use the rawheap_translator tool (available in the **toolchains** directory of the SDK) to parse the files and convert them into .heapsnapshot files, which can be opened on [DevEco Studio](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-snapshot-basic-operations-V5#section6760173514388).

## Operation Guide

### How to Obtain

The rawheap_translator tool is compatible with OHOS, Windows, Linux, and macOS. You can obtain it from either of the following directories:

- From the **/bin/rawheap_translator** path on OHOS devices.

- From the **toolchains** directory of the SDK in other platforms.

### Environment Configuration

- On Windows:

  Choose **This PC** > **Properties** > **Advanced system settings** > **Advanced** > **Environment Variables** > **Path** > **Edit**, and input the path of **rawheap_translator.exe**. After that, restart the PC, and run the **hilogtool** command in the cmd window.

- On macOS:

  1. Start the terminal tool and run the following command:

  echo $SHELL

  a. If the command output is **/bin/bash**, open the **.bash_profile** file.

  vi ~/.bash_profile

  b. If the command output is **/bin/zsh**, open the **.zshrc** file.

  vi ~/.zshrc

  2. Press **i** to enter the **Insert** mode.

  3. Add the path of **rawheap_translator.exe**:

  export PATH=$PATH:/path/to/your/rawheap_translator

  4. Press **Esc** to exit the edit mode, and then enter **:wq** and press **Enter** to save the settings and exit.

  5. Run the following command for the environment variable to take effect.

  a. If the **.bash_profile** file is opened in step a, run the following command:

  source ~/.bash_profile

  b. If the **.zshrc** file is opened in step a, run the following command:

  source ~/.zshrc

  6. After the environment variable configuration is finished, restart the PC.


## How to Use

### Parsing Command
```bash
rawheap_translator <rawheap_file> [heapsnapshot_file]
```
### Parameters

| Parameter| Description| Example|
| -------- | ----------------- | ---------------------------------- |
| \<rawheap_file\> | (Mandatory) Path of the .rawheap file generated upon an OOM error:<br>**/data/log/reliability/resource_leak/memory_leak**| Parse the .rawheap file in the specified directory **D:\temp\rawheap**:<br>**rawheap_translator D:\temp\rawheap\xxx.rawheap**<br>Parse the .rawheap file in the current directory:<br>**rawheap_translator xxx.rawheap**|
| [heapsnapshot_file] | (Optional) Specifies the name and path of the generated file. The file name extension must be **heapsnapshot**.<br>If this parameter is not specified, the current path is used by default. An example of the generated file name is **hprof_2024-11-19-21-13-20.heapsnapshot**.| Parse the .rawheap file in the current directory and generate the .heapsnapshot in the specified path **D:\temp**:<br>**rawheap_translator xxx.rawheap D:\temp\xxx.heapsnapshot**<br>Parse the .rawheap file in the current directory and generate the .heapsnapshot in the current directory:<br>**rawheap_translator xxx.rawheap xxx.heapsnapshot**|

## Examples of Using Parsing Commands

### On OHOS

Run the **hdc shell** command to start the parsing tool in **/bin/rawheap_translator**. You are advised to specify the path of the **.heapsnapshot** file to **/data/local/tmp**, as you may not have the write permission on other paths.
```bash
> hdc shell /bin/rawheap_translator /data/log/reliability/resource_leak/memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap /data/local/tmp/myapplication-7979-7979.heapsnapshot
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[INFO] Meta::SetObjTypeBitFieldOffset: offset=72
[INFO] Meta::SetNativatePointerBindingSizeOffset: offset=32
[INFO] RawHeapTranslate::ReadSectionInfo: sectionSize=6
[INFO] Rawheap version is 
[INFO] RawHeapTranslate::Translate: start to read objects
[INFO] RawHeapTranslate::ReadObjTable: read object, cnt=96432
[INFO] RawHeapTranslate::Translate: read objects finish!
[INFO] RawHeapTranslate::ReadStringTable: read string table, cnt=11208
[INFO] RawHeapTranslate::ReadRootTable: find root obj 6244
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: start to build edges!
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: build edges finish!
[INFO] Main: start to serialize!
[INFO] HeapSnapshotJSONSerializer::Serialize begin
[INFO] HeapSnapshotJSONSerializer::Serialize exit
[INFO] Main: translate success! file save to /data/local/tmp/myapplication-7979-7979.heapsnapshot
```

### On Windows
Open the cmd window, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> rawheap_translator.exe memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[INFO] Meta::SetObjTypeBitFieldOffset: offset=72
[INFO] Meta::SetNativatePointerBindingSizeOffset: offset=32
[INFO] RawHeapTranslate::ReadSectionInfo: sectionSize=6
[INFO] Rawheap version is 
[INFO] RawHeapTranslate::Translate: start to read objects
[INFO] RawHeapTranslate::ReadObjTable: read object, cnt=96432
[INFO] RawHeapTranslate::Translate: read objects finish!
[INFO] RawHeapTranslate::ReadStringTable: read string table, cnt=11208
[INFO] RawHeapTranslate::ReadRootTable: find root obj 6244
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: start to build edges!
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: build edges finish!
[INFO] Main: start to serialize!
[INFO] HeapSnapshotJSONSerializer::Serialize begin
[INFO] HeapSnapshotJSONSerializer::Serialize exit
[INFO] Main: translate success! file save to myapplication-7979-7979.heapsnapshot
```

### On Linux
Go to the path of the .rawheap file, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> ./rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[INFO] Meta::SetObjTypeBitFieldOffset: offset=72
[INFO] Meta::SetNativatePointerBindingSizeOffset: offset=32
[INFO] RawHeapTranslate::ReadSectionInfo: sectionSize=6
[INFO] Rawheap version is 
[INFO] RawHeapTranslate::Translate: start to read objects
[INFO] RawHeapTranslate::ReadObjTable: read object, cnt=96432
[INFO] RawHeapTranslate::Translate: read objects finish!
[INFO] RawHeapTranslate::ReadStringTable: read string table, cnt=11208
[INFO] RawHeapTranslate::ReadRootTable: find root obj 6244
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: start to build edges!
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: build edges finish!
[INFO] Main: start to serialize!
[INFO] HeapSnapshotJSONSerializer::Serialize begin
[INFO] HeapSnapshotJSONSerializer::Serialize exit
[INFO] Main: translate success! file save to myapplication-7979-7979.heapsnapshot
```

### On macOS
Open the device, go to the .rawheap file path, and run the parsing command to generate the .heapsnapshot file in the current path.
```bash
> rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[INFO] Meta::SetObjTypeBitFieldOffset: offset=72
[INFO] Meta::SetNativatePointerBindingSizeOffset: offset=32
[INFO] RawHeapTranslate::ReadSectionInfo: sectionSize=6
[INFO] Rawheap version is 
[INFO] RawHeapTranslate::Translate: start to read objects
[INFO] RawHeapTranslate::ReadObjTable: read object, cnt=96432
[INFO] RawHeapTranslate::Translate: read objects finish!
[INFO] RawHeapTranslate::ReadStringTable: read string table, cnt=11208
[INFO] RawHeapTranslate::ReadRootTable: find root obj 6244
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: start to build edges!
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: build edges finish!
[INFO] Main: start to serialize!
[INFO] HeapSnapshotJSONSerializer::Serialize begin
[INFO] HeapSnapshotJSONSerializer::Serialize exit
[INFO] Main: translate success! file save to myapplication-7979-7979.heapsnapshot
```

## File Specifications

As shown in the following table, in the OOM scenario, when the ArkTS heap memory usage is high and the number of live objects is large, the time required for generating the .rawheap file is long, and the file size is also large. You can subscribe to the [resource leak events](../dfx/hiappevent-watcher-resourceleak-events.md) and customize the event processing logic.

To determine the performance and traffic overhead caused by reporting the .rawheap file to the server, you can refer to the following table to obtain the size of the compressed .rawheap file. Generally, the compression ratio is 10:1 and varies depending on the compression tool in use.

| ArkTS Heap Memory Size (MB)| Number of Live Objects| File Generation Duration (s)| .rawheap File Size (MB)| Compressed File Size (MB)|
| :---------: | :--------------: | :-----------: | :----------: | :----------: |
| 11.00 | 99812 |  0.08 | 7.00 | 0.77 |
| 25.30 | 250059 |  0.17 | 19.00 | 1.90 |
| 50.40 | 496134 |  0.29 | 38.00 | 3.55 |
| 72.00 | 759037 |  0.49 | 54.00 | 4.77 |
| 104.00 | 47232 |  0.14 | 102.00 | 8.25 |
| 130.00 | 1308804 |  0.92 | 100.00 | 10.40 |
| 152.00 | 1493272 |  1.12 | 117.00 | 11.50 |
| 187.00 | 1838800 |  1.50 | 144.00 | 13.00 |
| 354.00 | 50704 |  0.31 | 352.00 | 27.25 |
| 643.00 | 7772538 |  2.63 | 444.00 | 51.00 |
| 750.00 | 6163456 |  3.64 | 605.00 | 59.55 |


## FAQs
### What should I do if the tool version is too early?
Symptom: The message "The rawheap file's version 2.0.0 is not matched the current rawheap translator, please use the newest version of the translator!" is displayed during parsing.
```bash
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[ERRO] The rawheap file's version 1.1.0 is not matched the current rawheap translator, please use the newest version of the translator!
```
Solution: Upgrade the tool.

### What should I do if I have no permission on the file?
Symptom: The message "FileStream: open file failed!" is displayed during parsing.
```bash
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[INFO] Meta::SetObjTypeBitFieldOffset: offset=72
[INFO] Meta::SetNativatePointerBindingSizeOffset: offset=32
[INFO] RawHeapTranslate::ReadSectionInfo: sectionSize=6
[INFO] Rawheap version is 
[INFO] RawHeapTranslate::Translate: start to read objects
[INFO] RawHeapTranslate::ReadObjTable: read object, cnt=96432
[INFO] RawHeapTranslate::Translate: read objects finish!
[INFO] RawHeapTranslate::ReadStringTable: read string table, cnt=11208
[INFO] RawHeapTranslate::ReadRootTable: find root obj 6244
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: start to build edges!
[INFO] RawHeapTranslate::FillNodesAndBuildEdges: build edges finish!
[INFO] Main: start to serialize!
[ERRO] FielStream: open file failed
```
Solution: Specify a path with the write permission for generating the file. For example, specify the path to **/data/local/tmp**.

# rawheap-translator工具

## 使用场景

为方便开发者定位问题，当前应用在ArkTS内存OOM时会自动进行Heapdump，虚拟机会扫描并保存当前堆上的所有对象信息，生成rawheap文件。该文件以二进制形式保存，开发者可从SDK中toolchains路径下获取rawheap_translator工具进行解析，转换成heapsnapshot文件，可通过[DevEco Studio](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-snapshot-basic-operations-V5#section6760173514388)打开查看。

## 使用指导

### 工具获取

当前工具适配了OHOS、Windows、Linux、MacOS平台，获取方法如下：

- 设备内获取：/bin/rawheap_translator，可在oh设备使用；

- SDK中获取：不同平台工具在SDK路径下toolchains目录获取，可在对应平台下使用。

### 环境配置

- Windows环境变量设置方法

  在此电脑 > 属性 > 高级系统设置 > 高级 > 环境变量 > Path > 编辑 中，将rawheap_translator.exe所在路径添加到 Path，环境变量配置完成后，请重启电脑，即可在cmd窗口执行rawheap_translator命令。

- MacOS环境变量设置方法

  1）打开终端工具，执行以下命令，根据输出结果分别执行不同命令。

  echo $SHELL

  a. 如果输出结果为/bin/bash，则执行以下命令，打开.bash_profile文件。

  vi ~/.bash_profile

  b. 如果输出结果为/bin/zsh，则执行以下命令，打开.zshrc文件。

  vi ~/.zshrc

  2）单击字母“i”，进入Insert模式。

  3）输入以下内容，添加PATH信息。

  export PATH=$PATH:/path/to/your/rawheap_translator

  4）编辑完成后，单击Esc键，退出编辑模式，然后输入“:wq”，单击Enter键保存。

  5）执行以下命令，使配置的环境变量生效。

  a. 如果步骤a时打开的是.bash_profile文件，请执行如下命令：

  source ~/.bash_profile

  b. 如果步骤a时打开的是.zshrc文件，请执行如下命令：

  source ~/.zshrc

  6）环境变量配置完成后，重启电脑。


## 使用方法

### 解析命令
```bash
rawheap_translator <rawheap_file> [heapsnapshot_file]
```
### 参数列表

| 选项 | 描述 | 举例 |
| -------- | ----------------- | ---------------------------------- |
| \<rawheap_file\> | 必选参数，OOM时生成的rawheap文件路径：<br>/data/log/reliability/resource_leak/memory_leak | 解析指定目录(如：D:\temp\rawheap)下的rawheap文件：<br>rawheap_translator D:\temp\rawheap\xxx.rawheap<br>解析当前目录下的rawheap文件：<br>rawheap_translator xxx.rawheap |
| [heapsnapshot_file] | 可选参数，指定生成的文件名称和路径，后缀名必须是heapsnapshot；<br>不指定则默认为当前路径，生成的文件名如：hprof_2024-11-19-21-13-20.heapsnapshot | 解析当前目录下的rawheap文件，并在指定路径(如：D:\temp)下生成的heapsnapshot:<br>rawheap_translator xxx.rawheap D:\temp\xxx.heapsnapshot<br>解析当前目录下的rawheap文件，并在当前路径下生成的heapsnapshot:<br>rawheap_translator xxx.rawheap xxx.heapsnapshot |

## 解析命令示例

### OHOS设备中解析示例

通过hdc shell命令拉起解析工具，设备内工具路径：/bin/rawheap_translator，推荐指定生成heapsnapshot文件路径在/data/local/tmp下，其他路径可能面临没有写权限问题。
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

### Windows系统中解析示例
打开cmd并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
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

### Linux系统中解析示例
进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
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

### MacOS系统中解析示例
打开终端并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
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

## 常见问题
### 工具版本过低
工具解析时，提示：The rawheap file's version 2.0.0 is not matched the current rawheap translator, please use the newest version of the translator!
```bash
[INFO] Main: start to translate rawheap!
[INFO] Meta::ParseVersion: current metadata version is 1.0.0
[INFO] Meta::ParseTypeEnums: parse type enums, size=213
[INFO] Meta::ParseTypeList: parse type list, obj size = 214
[INFO] Meta::ParseTypeLayout: parse type layout, size=1
[INFO] Meta::ParseTypeLayout: parse type desc, size=4
[ERRO] The rawheap file's version 1.1.0 is not matched the current rawheap translator, please use the newest version of the translator!
```
原因：当前工具版本低于rawheap文件版本，升级工具可解决。

### 文件没有权限
工具解析时，提示：FileStream: open file failed!
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
原因：生成文件路径下没有写文件权限，指定到有写权限路径下可解决。参考路径：/data/local/tmp。

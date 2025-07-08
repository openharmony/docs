# rawheap-translator工具

## 使用场景

为方便开发者定位问题，当前应用在ArkTS内存OOM（Out of Memory）时会自动进行Heapdump（由于内存限制，并非总是能够成功完成Heapdump），虚拟机会扫描并保存当前堆上的所有对象信息，生成rawheap文件。该文件以二进制形式保存，开发者可从SDK中toolchains路径下获取rawheap_translator工具进行解析，转换成heapsnapshot文件，可通过[DevEco Studio](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388)或Chrome浏览器打开查看。

## 使用指导

### 工具获取

当前工具适配了OHOS、Windows、Linux和MacOS平台，获取方法如下：

- 设备内获取：/bin/rawheap_translator，可在oh设备使用；
- SDK中获取：不同平台工具在SDK路径下sdk/default/openharmony/toolchains目录下获取rawheap_translator.exe，可在对应平台下使用。

### 环境配置

- Windows环境变量设置方法

  在此电脑 > 属性 > 高级系统设置 > 高级 > 环境变量 > Path > 编辑 中，将rawheap_translator.exe所在路径添加到 Path，环境变量配置完成后，请重启电脑，即可在cmd窗口执行rawheap_translator命令。

- MacOS环境变量设置方法

  1）打开终端工具，执行以下命令。根据输出结果，分别执行不同的命令。

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
| \<rawheap_file\> | 必选参数，OOM时生成的rawheap文件路径：<br>/data/log/reliability/resource_leak/memory_leak | 解析指定目录（如：D:\temp\rawheap）下的rawheap文件：<br>rawheap_translator D:\temp\rawheap\xxx.rawheap<br>解析当前目录下的rawheap文件：<br>rawheap_translator xxx.rawheap |
| [heapsnapshot_file] | 可选参数，指定生成的文件名称和路径，后缀名必须是heapsnapshot；<br>不指定则默认为当前路径，生成的文件名如：hprof_2024-11-19-21-13-20.heapsnapshot | 解析当前目录下的rawheap文件，并在指定路径（如：D:\temp）下生成heapsnapshot：<br>rawheap_translator xxx.rawheap D:\temp\xxx.heapsnapshot<br>解析当前目录下的rawheap文件，并在当前目录下生成heapsnapshot：<br>rawheap_translator xxx.rawheap xxx.heapsnapshot |
> **注意：**
>
> [heapsnapshot_file] 需要指向具有读写权限的路径，如果未指定参数，需要保证当前执行cmd命令时所在目录具有读写权限。<br>
> 以windows为例:
> D:\> ...\rawheap_translator.exe ...\example.rawheap 命令中，需要保证“D:\”路径具有读写权限。

## 解析命令示例

### OHOS设备中解析示例

通过hdc shell命令拉起解析工具，设备内工具路径：/bin/rawheap_translator，推荐指定生成heapsnapshot文件路径为/data/local/tmp，其他路径可能面临没有写权限问题。
```bash
> hdc shell /bin/rawheap_translator /data/log/reliability/resource_leak/memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap /data/local/tmp/myapplication-7979-7979.heapsnapshot
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

### Windows系统中解析示例
打开cmd并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> rawheap_translator.exe memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
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
[INFO ] Translate               file save to myapplication-7979-7979.heapsnapshot
```

### Linux系统中解析示例
进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> ./rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
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
[INFO ] Translate               file save to myapplication-7979-7979.heapsnapshot
```

### MacOS系统中解析示例
打开终端并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
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
[INFO ] Translate               file save to myapplication-7979-7979.heapsnapshot
```

## 文件参考规格

rawheap文件大小、生成耗时，与当前ArkTS堆内存大小、存活对象数量强正相关（如下表所示），因此OOM场景下当ArkTS堆内存占用较大、存活对象数量较多时，生成的rawheap文件耗时会较长，文件也会较大。开发者可订阅[资源泄漏事件](../dfx/hiappevent-watcher-resourceleak-events.md)，自定义事件处理逻辑。

从API version 20开始，虚拟机支持两种规格的rawheap dump；对于API version 20之前版本，虚拟机默认是TRIM_LEVEL_1规格，具体如下：
| 规格 | 特点 |
| :---: | :---: |
| TRIM_LEVEL_1 | dump速度快，生成rawheap文件大，虚拟机默认TRIM_LEVEL_1规格 |
| TRIM_LEVEL_2 | dump速度稍慢，生成rawheap文件相比TRIM_LEVEL_1缩小40%左右 |

为了方便开发者判断上报rawheap文件到服务器所带来的性能和流量开销，下表还给出了在不同的堆大小下，进行rawheap dump生成的rawheap文件大小、生成耗时、解析耗时，仅供开发者参考。

|规格|堆大小（MB）|rawheap文件（MB）|生成耗时（s）|解析耗时（s）|
|:---:|:---:|:---:|:---:|:---:|
| TRIM_LEVEL_1 | 690 | 629 | 2.64 | 14 |
| TRIM_LEVEL_1 | 653 | 618 | 2.63 | 13 |
| TRIM_LEVEL_1 | 576 | 563 | 3.63 | 15 |
| TRIM_LEVEL_2 | 690 | 376 | 3.47 | 14 |
| TRIM_LEVEL_2 | 653 | 347 | 3.36 | 13 |
| TRIM_LEVEL_2 | 576 | 294 | 4.53 | 15 |


## 常见问题
### 工具版本过低
工具解析时，提示：The rawheap file's version 1.1.0 is not matched the current rawheap translator, please use the newest version of the translator!
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
原因：当前工具版本低于rawheap文件版本，升级工具至2.0.0可解决。

### 文件没有权限
工具解析时，提示：open file failed
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
原因：指定生成文件路径下没有写文件权限，指定到有写权限路径下可解决。参考路径：/data/local/tmp。
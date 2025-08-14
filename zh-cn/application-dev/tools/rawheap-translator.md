# rawheap-translator工具
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @wanghuan2025-->
<!--SE: @wanghuan2025-->
<!--TSE: @kir175;@zsw_zhushiwei-->

## 使用场景

为方便开发者定位问题，应用在ArkTS内存OOM（Out of Memory）时会自动进行HeapDump。此操作会将虚拟机当前堆上的所有对象信息保存在后缀为.rawheap的二进制文件中。开发者可使用rawheap_translator工具解析.rawheap文件，生成.heapsnapshot文件。该文件可通过DevEco Studio的[Heap Snapshot离线导入](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388)或Chrome浏览器的开发者工具中的内存工具导入并查看。

## 使用指导

### 工具获取

此工具支持OHOS、Windows、Linux和MacOS平台，获取方法如下：

- 设备内获取：/bin/rawheap_translator，仅适用于OHOS设备。
- SDK中获取：sdk/default/openharmony/toolchains/rawheap_translator，适用于各平台。

### 环境配置

对于OHOS平台，由于其已在系统路径下内置了rawheap_translator工具，因此可以在终端中直接使用此工具。

对于非OHOS平台，建议将从SDK中获取的rawheap_translator工具放置在稳定的路径下，并将该路径配置为系统环境变量。这样可以在终端中直接使用工具，无需每次指定路径。

在不同系统中，环境变量的配置方法存在差异。以下提供一些配置示例，供开发者参考。

- Windows环境变量设置方法（以Windows 10某版本为例）。

  1. 右键点击“此电脑”选择“属性”选项。
  2. 在弹出的窗口中，找到并点击“高级系统设置”标签。
  3. 在弹出的窗口中，找到并点击“高级”页签下的“环境变量”按钮。
  4. 在弹出的窗口中，找到并双击“系统变量”框中的“Path”变量。
  5. 在弹出的窗口中，找到并点击“新建”按钮。
  6. 将本地存放rawheap_translator工具的文件路径填至新建的文本框中。
  7. 点击“确定”按钮关闭所有弹出的窗口。
  8. 重启终端。

- MacOS环境变量设置方法（以MacOS 15某版本为例）。

  1. 打开终端工具，执行以下命令。

      ```bash
      echo $SHELL
      ```

  2. 根据步骤1的返回结果做如下对应处理。

      a. 如果返回结果为`/bin/bash`，则执行以下命令：

      ```bash
      echo 'export PATH=$PATH:/path/to/your/rawheap_translator' >> ~/.bash_profile
      source ~/.bash_profile
      ```

      b. 如果返回结果为`/bin/zsh`，则执行以下命令：

      ```bash
      echo 'export PATH=$PATH:/path/to/your/rawheap_translator' >> ~/.zshrc
      source ~/.zshrc
      ```

## 使用方法

### 解析命令
```bash
rawheap_translator [rawheap_file] [heapsnapshot_file]
```
### 参数列表

| 选项 | 必选 | 描述 |
| -------- | --- | ----------------- |
| [rawheap_file] | 是 | 需要解析的应用OOM时生成的.rawheap文件路径。 |
| [heapsnapshot_file] | 否 | 解析生成的heapsnapshot文件路径，路径必须具有读写权限。<br>参数缺省时，默认为当前执行命令的路径。<br>参数给定时，文件的后缀名必须是heapsnapshot。

## 解析命令示例

### 解析示例


OHOS设备中解析示例
OHOS设备内工具路径：/bin/rawheap_translator，推荐指定生成heapsnapshot文件路径为/data/local/tmp，其他路径可能面临没有写权限问题。
```bash
> /bin/rawheap_translator /data/log/reliability/resource_leak/memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap /data/local/tmp/myapplication-7979-7979.heapsnapshot
```
Windows系统中解析示例
打开cmd并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> rawheap_translator.exe memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
Linux系统中解析示例
进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> ./rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
MacOS系统中解析示例
打开终端并进入rawheap文件路径，调用解析工具命令，指定在当前路径下生成heapsnapshot文件。
```bash
> rawheap_translator memory_leak/memleak-js-com.example.myapplication-7979-7979-20241215191332.rawheap myapplication-7979-7979.heapsnapshot
```
参考输出
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

## 文件参考规格

rawheap文件的大小和生成耗时与当前ArkTS堆内存大小及存活对象数量呈强正相关。当ArkTS堆内存占用较大、存活对象数量较多时，生成的rawheap文件会更大，耗时也会更长。开发者可以订阅[资源泄漏事件](../dfx/hiappevent-watcher-resourceleak-events.md)，自定义事件处理逻辑。

从API version 20开始，虚拟机支持两种规格的HeapDump。
| 规格 | 特点 |
| :--- | :--- |
| TRIM_LEVEL_1 | dump速度快，生成的rawheap文件大。<br>API version 20之前版本，虚拟机默认为TRIM_LEVEL_1规格。 |
| TRIM_LEVEL_2 | dump速度稍慢，生成的rawheap文件大小相比TRIM_LEVEL_1缩小40%左右。 |

为了方便开发者了解上报rawheap文件到服务器所带来的性能和流量开销，下表给出了在不同的堆大小下，不同规格的HeapDump生成的rawheap文件大小、生成耗时、解析耗时的示例，仅供开发者参考。

|规格|堆大小（MB）|rawheap文件（MB）|生成耗时（s）|解析耗时（s）|
|:---|:---|:---|:---|:---|
| TRIM_LEVEL_1 | 690 | 629 | 2.64 | 14 |
| TRIM_LEVEL_2 | 690 | 376 | 3.47 | 14 |
| TRIM_LEVEL_1 | 653 | 618 | 2.63 | 13 |
| TRIM_LEVEL_2 | 653 | 347 | 3.36 | 13 |
| TRIM_LEVEL_1 | 576 | 563 | 3.63 | 15 |
| TRIM_LEVEL_2 | 576 | 294 | 4.53 | 15 |


## 常见问题
### 工具版本不匹配
**问题现象**<br>
工具解析时会提示：原始堆文件的版本 2.0.0 与当前的原始堆文件翻译器不匹配，请使用最新版本的翻译器。
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
**原因**<br>
当前工具版本低于rawheap文件版本。<br>
**解决措施**<br>
升级工具版本至2.0.0可解决此问题。

### 文件无法打开
**问题现象**<br>
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
**原因**<br>
定的生成文件路径没有写入权限。<br>
**解决措施**<br>
更改到有写权限的路径可以解决。
# DFX开发常见问题


## hilog日志如何落盘存储(API 9)

**解决措施**

使用命令：hilog -w start -f ckTest -l 1M -n 5 -m zlib -j 11

文件保存在目录：/data/log/hilog/

参数解释：

```
-w 开启日志落盘任务,start表示开始，stop表示停止。
-f 设置日志文件名
-l 设置单个日志文件大小，单位可以是：B/K/M/G
-n 设置最大日志文件编号，当文件计数超过此编号时，日志文件旋转。范围：【2,1000】
-m 设置日志文件压缩算法
-j 任务ID，范围：[10,0xffffffffff)
更多参数含义请使用hilog --help查看。
```


## Hilog日志如何设置为只打印当前应用的日志(API 9)

**解决措施**

通过hilog命令行工具来过滤保留当前应用的日志日志。

hilog -T xxx 按tag过滤;

hilog –D xxx 按domain过滤;

hilog -e 对日志内容匹配，支持正则式tag, domain, pid都支持多重过滤,组合过滤以及反向过滤。


## 程序打开直接崩溃了，如何定位问题(API 9)

**解决措施**

方法1：通过业务日志打印，定位崩溃的代码位置。

方法2：通过Crash文件查看报错信息，Crash文件路径是：/data/log/faultlog/faultlogger/。


## 应用如何打印日志是使用hilog还是console，hilog接口参数domain的设置范围是什么(API 9)

console是对hilog日志系统的封装，其采用默认参数，主要用于应用开发调试阶段。

推荐使用hilog，可以对日志系统进行分类和统一处理，具体参考文档：[hilog日志系统](../reference/apis-performance-analysis-kit/js-apis-hilog.md)

hilog接口参数domain的取值范围0x0~0xFFFF，建议开发者在应用内根据需要自定义划分。


## hilog日志打印长度限制是多少，是否可以配置(API 9)

日志打印的长度限制为1024个字符，该长度不能配置


## 格式化日志打印时，使用private的作用是什么(API 9)

**问题现象**

C++代码中hilog的格式参数类型为%d或者%s时，日志打印为何显示private

**解决措施**

直接使用%d、%s等格式化参数时，标准系统默认使用private替换真实数据进行打印，防止数据泄露。如果需要打印出真实数据，需要使用%{public}d替换%d或者%{public}s替换%s。


## 如何解决hilog.debug日志无法打印(API 9)

**解决措施**

通过hdc命令 hdc shell hilog -b D开启调试开关


## hilog接口的tag参数是否支持用空格隔开的多个字符串(API 9)

支持。


## hilog如何打印{private}隐私标志的内容(API 9)

**解决措施**

使用命令关闭隐私模式即可。命令如下：hdc shell hilog -p off


## 有关崩溃日志收集和性能问题排查的功能有哪些(API 9)

**问题现象**

有关崩溃日志收集和性能问题排查的功能有哪些

**解决措施**

faultLogger：崩溃日志收集，参考文档：[故障日志获取](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md)

hichecker：问题检测，参考文档：[检测模式](../reference/apis-performance-analysis-kit/js-apis-hichecker.md)

hiTraceMeter：性能打点，参考文档：[性能打点](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)


## 如何控制日志输出(API 9)

**问题现象**

根据不同的环境要求，输出不同的日志信息。

**解决措施**

通过hilog命令调整日志打印级别，输出不同级别的日志信息。命令如下：

hdc shell hilog -L &lt;D/I/W/E/F&gt;


## hilog的TAG长度有限制吗(API 9)

整个tag的长度是32。


## 日志里面的appfreeze文件的怎么查看，要看哪些内容(API 9)

主要查看方向：

1、先看一下Reason是什么事件的；根据不同的Reason下面有大致的检测原理和分析样例。

2、关注MSG有什么信息，根据MSG的信息看一下大致的方向；

3、分析OpenStacktraceCatcher里面的应用栈信息，并且结合流水日志一起确定一下当前在干什么事情；

4、看一下PeerBinderCatcher当前进程是否有对端的binder卡住，如果有跟当前进程相关的同步wait，则会有相应的PeerBinder Stacktrace信息——这个是卡住你当前进程的对端进程的栈信息。

5、还有整机进程的cpu信息和当前进程的内存信息辅助定位。

## 如何查看ArkCompiler出现Error日志时，具体的异常调用栈信息？(API 10)

**解决方案**

Native抛异常，如果需要查看backtrace，需要运行一下命令。

打开异常栈：

```bash
hdc shell param set persist.ark.properties 0x125c
hdc shell reboot
```  
恢复默认值：

```bash
hdc shell param set persist.ark.properties 0x105c
hdc shell reboot
```  

## hdc工具的属性开关有哪些？例如Ark属性开关等(API 10)

**解决方案**

在命令行输入 `hdc shell ark` 可以看到Ark命令行的所有参数和开关。

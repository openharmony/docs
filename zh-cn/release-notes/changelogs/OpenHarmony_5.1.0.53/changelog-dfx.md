# DFX子系统Changelog

## cl.dfx.1 hdc命令file send/file recv文件传输支持创建不存在目录

**访问级别**

其他

**变更原因**

原hdc命令file send/file recv文件传输，不支持创建不存在的目录。

**变更影响**

变更前：hdc命令中file send（发送）、hdc recv（接收）命令指定的目标目录不存在时，操作失败。

变更后：hdc命令中file send（发送）、hdc recv（接收）命令指定的目标目录不存在时，将自动创建不存在目录并进行文件传输。

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

无需适配

## cl.dfx.2 USB调试开关关闭时不再同步关闭hdc无线调试通道

**访问级别**

其他

**变更原因**

设置界面开发人员选项中，当USB调试开关关闭时，无线调试通道同步关闭，此时无法通过无线调试连接到设备进行相关调试，影响开发者调试连接体验。

**变更影响**

变更前：设置界面开发人员选项中，当USB调试开关和无线调试均开启时，执行操作关闭设置界面开发人员选项中的USB调试开关，操作完成后，USB调试通道、无线调试通道将同步关闭，此时将无法通过`hdc tconn <IP>:<PORT>`命令连接到设备。

变更后：设置界面开发人员选项中，当USB调试开关和无线调试均开启时，执行操作关闭设置界面开发人员选项中的USB调试开关，操作完成后，仅USB调试通道关闭，无线调试通道会断开一次，不会关闭，此时可以通过`hdc tconn <IP>:<PORT>`命令连接到设备。

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具、设置界面

**适配指导**

无需适配

## cl.dfx.3 hdc服务进程操作命令新增打印输出

**访问级别**

其他

**变更原因**

hdc工具start命令、kill命令缺少必要的提示输出，开发者无法获取命令操作的结果。

**变更影响**

变更前：使用hdc工具start [-r]命令、kill -r命令操作完成后无提示输出。

变更后：使用hdc工具start [-r]命令、kill -r命令操作完成后新增提示输出进程监听地址信息与启动结束打印，相关命令及返回值如下：

（1）启动hdc服务进程命令：
```shell
hdc start
```
预期返回：
```shell
hdc start server, listening: ::ffff:127.0.0.1:8710
Start server finish
```

（2）关闭并重新启动hdc服务进程命令1：
```shell
hdc kill -r
```
预期返回：
```shell
Kill server finish
hdc start server, listening: ::ffff:127.0.0.1:8710
Start server finish
```

（3）关闭并重新启动hdc服务进程命令2：
```shell
hdc start -r
```
预期返回：
```shell
Kill server finish
hdc start server, listening: ::ffff:127.0.0.1:8710
Start server finish
```

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

如存在读取hdc工具输出的自动化程序，需更改相应的命令输出校验内容。

## cl.dfx.4 hdc客户端针对未连接设备的命令操作更改打印输出

**访问级别**

其他

**变更原因**

hdc工具输出信息勘误。

**变更影响**

变更前：无设备连接时，使用hdc工具执行命令将提示打印：

```bash
Device not founded or connected
```

变更后：无设备连接时，使用hdc工具执行命令将提示打印：

```bash 
Device not found or connected
```

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

如存在读取hdc工具输出的自动化程序，需更改相应的命令输出校验内容。

## cl.dfx.5 hdc客户端在Windows平台使用控制台命令操作支持中文字符

**访问级别**

其他

**变更原因**

hdc工具问题修复，解决使用GBK编码格式的Windows bat脚本中存在中文字符时显示乱码的问题。

**变更影响**

变更前：使用GBK编码格式的Windows bat脚本中存在中文字符时显示乱码。

变更后：使用GBK编码格式的Windows bat脚本中存在中文字符时显示正常。

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

如存在更改字符集以适配hdc中文命令的自动化程序，其命令输入不再需要额外转换字符集。

## cl.dfx.6 hdc服务进程日志本地存储路径变更

**访问级别**

其他

**变更原因**

hdc工具问题修复，解决hdc服务进程日志本地存储路径为临时目录时，需遍历读取全目录路径的相关异常问题。

**变更影响**

| 平台 | 路径（变更前） | 路径（变更后） |
| -------- | -------- | -------- |
| Windows | %temp% <br/> 实际路径参考（实际使用请替换用户名变量） C:\Users\用户名\AppData\Local\Temp |  %temp%\hdc_logs <br/>实际路径参考（实际使用请替换用户名变量）<br/>C:\Users\用户名\AppData\Local\Temp\hdc_logs |
| Linux | /tmp | /tmp/hdc_logs |
| MacOS | $TMPDIR | $TMPDIR/hdc_logs |

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

如存在读取hdc服务进程日志的自动化程序，需更改读取的日志路径。

## cl.dfx.7 hdc服务进程日志本地存储开启压缩

**访问级别**

其他

**变更原因**

hdc工具功能优化，原日志未压缩，日志文件占用空间较大，日志数据密度较小，无法获取有效的问题定位信息。

**变更影响**

变更前：hdc服务进程日志不开启压缩，日志老化文件名称按照：hdc-%Y%m%d-%H%M%S.log格式，最大存储30个文件，单个文件体积最大占用100MB。

变更后：hdc服务进程日志开启压缩，日志老化文件名称按照：hdc-%Y%m%d-%H%M%S.log.tgz格式，最大存储300个文件，单个文件体积最大占用约5~10MB。

**起始API Level**

API16

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

hdc命令行工具

**适配指导**

日志归档文件为`.tgz`类型压缩文件，查看日志时需使用解压工具进行解压查看。

参考解压命令：

```
tar -xvzf hdc-20230202-123456.log.tgz
```
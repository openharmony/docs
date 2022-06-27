# hdc_std使用指导


hdc_std（OpenHarmony Device Connector）是 OpenHarmony 为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/MacOS等系统上与开发机或者模拟器进行交互。


下文将介绍hdc_std的环境准备和常用命令及使用举例。


## 环境准备

**hdc_std 工具获取方式：**

通过OpenHarmony sdk获取，hdc_std在sdk的toolchains目录下。

**使用举例：**

下面以windows侧使用方式举例：

获取windows的sdk，将hdc_std.exe放到磁盘某个位置即可使用。


## 注意事项

- 使用hdc_std，如果出现异常，可以尝试通过hdc_std kill命令杀掉hdc_std服务，或者通过hdc_std start -r命令重启服务进程进行解决。

- 如果出现hdc_std list targets获取不到设备信息，通过任务管理器查看是否有hdc_std进程存在，如果进程存在，可以通过杀掉该进程进行解决。


## option相关的命令

option涉及以下命令：


- **-h/help -v/version**
  用于显示hdc相关的帮助、版本信息。

    **表1** 命令说明
  
  | 返回值 | 返回值说明 | 
  | -------- | -------- |
  | 返回对应信息 | 帮助或者版本信息 | 

  使用方法：

    
  ```
  hdc_std -h / hdc_std help
  ```

    
  ```
  hdc_std -v / hdc_std version
  ```

- **-t key**
  用于连接指定设备标识为key的设备。

    **表2** 命令说明
  
  | 参数 | 参数说明 |
  | -------- | -------- | 
  | key | 为&nbsp;IP地址:port&nbsp;格式，或者USB序列号 | 
  | **返回值** | **返回值说明** | 
  | ①error:&nbsp;device&nbsp;'\*\*\*'&nbsp;not&nbsp;found<br/>②Nothing&nbsp;to&nbsp;do... | ①设备不存在<br/>②附加的命令不存在 | 

  使用方法：

  该option需要与具体的操作命令搭配使用，下面以shell命令举例：

  hdc_std list targets  （获取设备信息）

  hdc_std  -t  _key_  shell  （-t后面添加的_key_ 需要替换为上面查询的设备信息）

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 一台开发机可支持多个设备连接，每个设备有其唯一的设备标识，如果通过网络与设备连接,其标识为IP地址:port格式，如果通过usb连接则标识为设备sn号。该命令需要跟随具体操作命令。


## 查询设备列表的命令

查询设备列表涉及以下命令：

  
```
list targets[-v]
```


显示所有已经连接的目标设备列表


  **表3** 命令说明

| 参数 | 参数说明 | 
| -------- | -------- |
| -v | 添加-v选项，则会打印设备详细信息 | 
| **返回值** | **返回值说明** | 
| ①返回设备信息<br/>②[Empty] | ①已经连接的设备列表信息<br/>②没有查询到设备信息 | 


使用方法：


  
```
hdc_std list targets
```


  
```
hdc_std list targets -v
```


## 服务进程相关命令

服务进程涉及以下命令：


- **target mount**
  以读写模式挂载系统分区。

    **表4** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | 无 | 无 | 
  | **返回值** | **返回值说明** | 
  | ①Mount&nbsp;finish<br/>②返回具体信息 | ①成功情况下返回的信息<br/>②失败情况下的具体信息 | 

  使用方法：

    
  ```
  hdc_std target mount
  ```

- **smode [off]**
  授予后台服务进程root权限， 使用off参数取消授权。

  使用方法：

    
  ```
  hdc_std smode
  ```

    
  ```
  hdc_std smode off
  ```

- **kill [-r]**
  终止服务进程。

    **表5** 命令说明
  
  | 参数 | 参数说明 |
  | -------- | -------- | 
  | -r | 触发服务重启 | 
  | **返回值** | **返回值说明** | 
  | ①Kill&nbsp;server&nbsp;finish<br/>②返回具体信息 | ①成功情况下返回的信息<br/>②失败情况下的具体信息 | 

    使用方法：
    
  ```
  hdc_std kill
  ```

- **start [-r]**
  启动服务进程。

    **表6** 命令说明
  
  | 参数 | 参数说明 |
  | -------- | -------- |
  | -r | 如果服务进程已经启动，-r选项会触发服务进程重新启动 | 
  | **返回值** | **返回值说明** | 
  | 无 | 无 | 

    使用方法：
    
  ```
  hdc_std start
  ```


## 网络相关的命令

网络部分涉及以下命令：


- **tconn host[:port][-remove]**
  通过【ip地址：端口号】来指定连接的设备

    **表7** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | host[:port] | 为IP地址:port格式 | 
  | -remove | 表示断开与指定设备的连接 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法（举例）：

    
  ```
  hdc_std tconn 192.168.0.100:8710
  ```

- **tmode usb**
  执行后设备端对应daemon进程重启，并首先选用usb连接方式。

    **表8** 命令说明
  
  | 参数 | 参数说明 |
  | -------- | -------- |
  | 无 | 无 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法：

    
  ```
  hdc_std tmode usb
  ```

- **tmode port port-number**
  执行后设备端对应daemon进程重启，并优先使用网络方式连接设备，如果连接设备失败，再选择usb连接。

    **表9** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | port-number | listen连接的网络端口号 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法：

    
  ```
  hdc_std tmode port 8710
  ```

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 执行完毕后，远端daemon将会退出并重启，默认启用TCP连接，如果不加上listen端口则listen随机端口。


## 文件相关的命令

文件部分涉及以下命令：


- **file send local remote**
  发送文件至远端设备。

    **表10** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | local | 本地待发送文件路径 | 
  | remote | 远程待接收文件路径 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②返回传输结果 | ①失败情况下的具体信息<br/>②成功传输的结果信息 | 

  使用方法（举例）：

    
  ```
  hdc_std file send E:\a.txt   /data/local/tmp/a.txt
  ```

- **file recv [-a] remote local**
  从远端设备接收文件至本地。

    **表11** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- | 
  | -a | 文件保留时间戳模式 | 
  | local | 本地待接收文件路径 | 
  | remote | 远程待发送文件路径 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法（举例）：

    
  ```
  hdc_std file recv  /data/local/tmp/a.txt   ./a.txt
  ```


## 应用相关的命令

应用部分涉及以下命令：


- **install [-r/-d/-g] _package_**
  安装OpenHarmony APP package。

    **表12** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | package | OpenHarmony应用安装包文件名 | 
  | -r | 替换已存在应用 | 
  | -d | 允许降级安装 | 
  | -g | 应用动态授权 | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法（举例）：

    
  ```
  hdc_std install hwadmin.hap
  ```

- **uninstall [-k] package**
  卸载OpenHarmony应用。

    **表13** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | package | OpenHarmony应用安装包 | 
  | -k | 保留/data/cache | 
  | **返回值** | **返回值说明** | 
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 | 

  使用方法（举例）：

    
  ```
  hdc_std uninstall package
  ```


## 调试相关的命令

调试涉及以下命令：


- **hilog**
  支持抓取log信息。

    **表14** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- | 
  | 无 | 无 | 
  | **返回值** | **返回值说明** | 
  | 返回具体信息 | 抓取的日志信息 | 

  抓取hilog日志：

    
  ```
  hdc_std hilog
  ```

  清理hilog缓存日志：

    
  ```
  hdc_std shell "hilog -r"
  ```

- **shell [_command_]**
  远程执行命令或进入交互命令环境。

    **表15** 命令说明
  
  | 参数 | 参数说明 | 
  | -------- | -------- |
  | command | 需要执行的单次命令 | 
  | **返回值** | **返回值说明** | 
  | 返回具体信息 | shell后面执行命令的结果信息 | 

  使用方法：

    
  ```
  hdc_std shell
  ```


## 常见问题


### hdc_std连接不到设备

- **现象描述**
  执行 "hdc_std list targets"命令后结果为：[Empty]

- **解决方法**
  1. 设备没有被识别：
      在设备管理器中查看是否有hdc设备，在通用串行总线设备中会有“HDC Device”信息。如果没有，hdc无法连接。此时需要断开并重联PC和OpenHarmony设备之间的USB连接，或者烧写最新的镜像。
  2. hdc_std工作异常：
      可以执行"hdc kill"或者"hdc start -r"杀掉hdc服务或者重启hdc服务，然后再执行hdc list targets查看是否已经可以获取设备信息。
  3. hdc_std与设备不匹配：
      如果设备烧写的是最新镜像，hdc_std也需要使用最新版本。


### hdc_std运行不了

- **现象描述**
  点击hdc_std.exe文件无法运行。

- **解决方法**
  hdc_std.exe不需要安装，直接放到磁盘上就能使用，也可以添加到环境变量中。通过打开cmd执行hdc_std命令直接使用。

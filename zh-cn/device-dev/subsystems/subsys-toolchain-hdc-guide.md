# hdc使用指导


hdc（OpenHarmony Device Connector）是 OpenHarmony 为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/MacOS等系统上与开发机或者模拟器进行交互。


下文将介绍hdc的环境准备和常用命令及使用举例。


## 环境准备

**hdc 工具获取方式：**

通过OpenHarmony sdk获取，hdc在sdk的toolchains目录下。

**使用举例：**

下面以windows侧使用方式举例：

获取windows的sdk，将hdc.exe放到磁盘某个位置即可使用。


## 注意事项

- 使用hdc，如果出现异常，可以尝试通过hdc kill命令杀掉hdc服务，或者通过hdc start -r命令重启服务进程进行解决。

- 如果出现hdc list targets获取不到设备信息，通过任务管理器查看是否有hdc进程存在，如果进程存在，可以通过杀掉该进程进行解决。


## option相关的命令

option涉及以下命令：


- **-h/help -v/version**
  用于显示hdc相关的帮助、版本信息。

    **表1** 命令说明

  | 返回值 | 返回值说明|
  | -------- | -------- |
  | 返回对应信息 | 帮助或者版本信息 |

  使用方法：


  ```
  hdc -h / hdc help
  ```


  ```
  hdc -v / hdc version
  ```

- **-l 0-5**
  用于指定运行时日志等级,默认为LOG_INFO。

    **表2** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | 0 | LOG_OFF  |
  | 1 | LOG_FATAL|
  | 2 | LOG_WARN |
  | 3 | LOG_INFO |
  | 4 | LOG_DEBUG|
  | 5 | LOG_ALL  |

  使用方法：

  ```
  hdc -l5 start
  ```

- **-t key**
  用于连接指定设备标识为key的设备。

    **表3** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | key | 为&nbsp;IP地址:port&nbsp;格式，或者USB序列号 |
  | **返回值** | **返回值说明** |
  | ①error:&nbsp;device&nbsp;'\*\*\*'&nbsp;not&nbsp;found<br/>②Nothing&nbsp;to&nbsp;do... | ①设备不存在<br/>②附加的命令不存在 |

  使用方法：

  该option需要与具体的操作命令搭配使用，下面以shell命令举例：

  hdc list targets  （获取设备信息）

  hdc  -t  _key_  shell  （-t后面添加的_key_ 需要替换为上面查询的设备信息）

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 一台开发机可支持多个设备连接，每个设备有其唯一的设备标识，如果通过网络与设备连接,其标识为IP地址:port格式，如果通过USB连接则标识为设备sn号。该命令需要跟随具体操作命令。

- **checkserver**
  用于获取client-server版本。

    **表4** 命令说明

  | 返回值 | 返回值说明|
  | -------- | -------- |
  | Client version:  server version: | client-server版本号 |

  使用方法：

  ```
  hdc checkserver
  ```


## 查询设备列表的命令

查询设备列表涉及以下命令：


```
list targets[-v]
```


显示所有已经连接的目标设备列表


  **表5** 命令说明

| 参数 | 参数说明|
| -------- | -------- |
| -v | 添加-v选项，则会打印设备详细信息 |
| **返回值** | **返回值说明** |
| ①返回设备信息<br/>②[Empty] | ①已经连接的设备列表信息<br/>②没有查询到设备信息 |


使用方法：



```
hdc list targets
```



```
hdc list targets -v
```


## 服务进程相关命令

服务进程涉及以下命令：


- **target mount**
  以读写模式挂载系统分区。

    **表6** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | 无 | 无 |
  | **返回值** | **返回值说明** |
  | ①Mount&nbsp;finish<br/>②返回具体信息 | ①成功情况下返回的信息<br/>②失败情况下的具体信息 |

  使用方法：


  ```
  hdc target mount
  ```

- **target boot**
  设备重启。

  使用方法：


  ```
  hdc target boot
  ```

- **smode [-r]**
  授予后台服务进程root权限， 使用-r参数取消授权。

  使用方法：


  ```
  hdc smode
  ```


  ```
  hdc smode -r
  ```

- **kill [-r]**
  终止服务进程。

    **表7** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | -r | 触发服务重启 |
  | **返回值** | **返回值说明** |
  | ①Kill&nbsp;server&nbsp;finish<br/>②返回具体信息 | ①成功情况下返回的信息<br/>②失败情况下的具体信息 |

    使用方法：

  ```
  hdc kill
  ```

- **start [-r]**
  启动服务进程。

    **表8** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | -r | 如果服务进程已经启动，-r选项会触发服务进程重新启动 |
  | **返回值** | **返回值说明** |
  | 无 | 无 |

    使用方法：

  ```
  hdc start
  ```


## 网络相关的命令

网络部分涉及以下命令：


- **tconn host[:port][-remove]**
  通过【ip地址：端口号】来指定连接的设备

    **表9** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | host[:port] | 为IP地址:port格式 |
  | -remove | 表示断开与指定设备的连接 |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 |

  使用方法（举例）：


  ```
  hdc tconn 192.168.0.100:8710
  ```

- **tmode usb**
  执行后设备端对应daemon进程重启，并首先选用USB连接方式。

    **表10** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | 无 | 无 |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 |

  使用方法：


  ```
  hdc tmode usb
  ```

- **tmode port port-number**
  执行后设备端对应daemon进程重启，并优先使用网络方式连接设备，如果连接设备失败，再选择USB连接。

    **表11** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | port-number | listen连接的网络端口号 |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 |

  使用方法：


  ```
  hdc tmode port 8710
  ```

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 执行完毕后，远端daemon将会退出并重启，默认启用TCP连接，如果不加上listen端口则listen随机端口。

- **fport localnode remotenode**
  端口转发，指定 主机端口 转发数据到 设备侧端口。

  使用方法：


  ```
  hdc fport tcp:1234 tcp:1080
  ```

- **rport remotenode localnode**
  端口转发，指定 设备侧端口 转发数据到 主机端口。

  使用方法：


  ```
  hdc rport tcp:2080 tcp:2345
  ```

- **fport ls**
  列出全部转发端口转发任务。

    **表12** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | 无 | 无 |
  | **返回值** | **返回值说明** |
  | 'tcp:1234 tcp:1080'     [Forward] | 正向端口转发任务 |
  | 'tcp:2080 tcp:2345'     [Reverse] | 反向端口转发任务 |

  使用方法：


  ```
  hdc fport ls
  ```

- **fport rm**
  删除指定端口转发任务。

  使用方法：


  ```
  hdc fport rm tcp:1234 tcp:1080
  ```


## 文件相关的命令

文件部分涉及以下命令：


- **file send local remote**
  发送文件至远端设备。

    **表13** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | local | 本地待发送文件路径 |
  | remote | 远程待接收文件路径 |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②返回传输结果 | ①失败情况下的具体信息<br/>②成功传输的结果信息 |

  使用方法（举例）：


  ```
  hdc file send E:\a.txt   /data/local/tmp/a.txt
  ```

- **file recv [-a] remote local**
  从远端设备接收文件至本地。

    **表14** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | -a | 文件保留时间戳模式 |
  | local | 本地待接收文件路径 |
  | remote | 远程待发送文件路径 |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 |

  使用方法（举例）：


  ```
  hdc file recv  /data/local/tmp/a.txt   ./a.txt
  ```


## 应用相关的命令

应用部分涉及以下命令：


- **install [-r/-d/-g] _package_**
  安装OpenHarmony APP package。

    **表15** 命令说明

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
  hdc install hwadmin.hap
  ```

- **uninstall [-k] package**
  卸载OpenHarmony应用。

    **表16** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | package | OpenHarmony应用安装包 |
  | -k | 保留/data/cache |
  | **返回值** | **返回值说明** |
  | ①返回具体信息<br/>②无 | ①失败情况下的具体信息<br/>②成功情况下无返回值 |

  使用方法（举例）：


  ```
  hdc uninstall package
  ```


## 调试相关的命令

调试涉及以下命令：


- **hilog**
  支持抓取log信息。

    **表17** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | 无 | 无 |
  | **返回值** | **返回值说明** |
  | 返回具体信息 | 抓取的日志信息 |

  抓取hilog日志：


  ```
  hdc hilog
  ```

  清理hilog缓存日志：


  ```
  hdc shell "hilog -r"
  ```

- **shell [_command_]**
  远程执行命令或进入交互命令环境。

    **表18** 命令说明

  | 参数 | 参数说明 |
  | -------- | -------- |
  | command | 需要执行的单次命令 |
  | **返回值** | **返回值说明** |
  | 返回具体信息 | shell后面执行命令的结果信息 |

  使用方法：


  ```
  hdc shell
  ```

- **jpid**
  获取可调试进程列表。

  使用方法：


  ```
  hdc jpid
  ```


## 常见问题


### hdc连接不到设备

- **现象描述**
  执行 "hdc list targets"命令后结果为：[Empty]

- **解决方法**
  1. 设备没有被识别：
      在设备管理器中查看是否有hdc设备，在通用串行总线设备中会有“HDC Device”信息。如果没有，hdc无法连接。此时需要断开并重联PC和OpenHarmony设备之间的USB连接，或者烧写最新的镜像。
  2. hdc工作异常：
      可以执行"hdc kill"或者"hdc start -r"杀掉hdc服务或者重启hdc服务，然后再执行hdc list targets查看是否已经可以获取设备信息。
  3. hdc与设备不匹配：
      如果设备烧写的是最新镜像，hdc也需要使用最新版本。


### hdc运行不了

- **现象描述**
  点击hdc.exe文件无法运行。

- **解决方法**
  1. 运行环境异常：
      linux版本建议ubuntu 18.04以上 64位，其他相近版本也可；libc++.so引用错误请使用ldd/readelf等命令检查库引用 windows版本建议windows10 64位，如果低版本windows winusb库缺失，请使用zadig更新库。对于复合设备，需要使用zadig工具安装libusb-win32驱动。
  2. 如何运行hdc.exe：
      hdc.exe不需要安装，直接放到磁盘上就能使用，也可以添加到环境变量中。通过打开cmd执行hdc命令直接使用。


### hdc client如何远程访问hdc server

- **使用场景**

  本地client指定远程server上的设备，执行hdc命令。

- **连接步骤**
  1. 关闭本地sever：
      ```
      hdc kill
      ```
  2. **-s [ip:]port -m** 启动远程server：
      ```
      hdc -s severIP:8710 -m
      ```
  3. **-s [ip:]port command** 指定server执行指令：
      ```
      hdc -s severIP:8710 list targets
      ```

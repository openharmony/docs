# hdc

hdc（OpenHarmony Device Connector）是为开发人员提供的用于调试的命令行工具，通过该工具可以在windows/linux/mac系统上与真实设备进行交互。

## 环境准备

hdc工具通过OpenHarmony SDK获取，存放于SDK的toolchains目录下，首次使用按照如下提示配置环境变量。

### 配置环境变量HDC_SERVER_PORT

**Windows环境变量设置方法**

在**此电脑 &gt; 属性 &gt; 高级系统设置 &gt; 高级 &gt; 环境变量**中，添加HDC端口变量名为：HDC_SERVER_PORT，变量值可设置为任意未被占用的端口，如7035。

![新建系统变量](figures/hdc_image_001.PNG)

环境变量配置完成后，关闭并重启DevEco Studio。

**macOS环境变量设置方法**

1. 打开终端工具，执行以下命令，根据输出结果分别执行不同命令。

   ```shell
   echo $SHELL 
   ```

   - 如输出结果为/bin/bash，则执行以下命令，打开.bash_profile文件。

      ```shell
      vi ~/.bash_profile
      ```

   - 如输出结果为/bin/zsh，则执行以下命令，打开.zshrc文件。

      ```shell
      vi ~/.zshrc
      ```

2. 单击字母“i”，进入**Insert**模式。
3. 输入以下内容，在PATH路径下添加HDC_SERVER_PORT端口信息。

   ```shell
   HDC_SERVER_PORT=7035
   launchctl setenv HDC_SERVER_PORT $HDC_SERVER_PORT
   export HDC_SERVER_PORT
   ```

4. 编辑完成后，单击**Esc**键，退出编辑模式，然后输入“:wq”，单击**Enter**键保存。
5. 执行以下命令，使配置的环境变量生效。

   - 如果步骤1时打开的是.bash_profile文件，请执行如下命令：

      ```shell
      source ~/.bash_profile
      ```

   - 如果步骤1时打开的是.zshrc文件，请执行如下命令：

      ```shell
      source ~/.zshrc
      ```

6. 环境变量配置完成后，关闭并重启DevEco Studio。

### （可选）配置全局环境变量

> **说明：**
> 如未配置全局环境变量，开发者可通过命令行进入SDK的toolchains目录，在目录中执行hdc相关命令进行调试。

**Windows环境变量设置方法**

在**此电脑 &gt; 属性 &gt; 高级系统设置 &gt; 高级 &gt; 环境变量 &gt; 系统变量**中，将SDK的toolchains完整路径添加到Path变量值中，具体路径信息以SDK**实际配置路径**为准。

以下图示内容以本地SDK的toolchains完整路径<!--RP1-->_/User/username/sdk/openharmony/10/toolchains_<!--RP1End-->为例：

![系统变量](figures/hdc_img_002.PNG)

![编辑环境变量](figures/hdc_image_003.PNG)

**Linux/macOS环境变量设置方法**

1. 打开终端工具，执行以下命令，根据输出结果分别执行不同命令。

   ```shell
   echo $SHELL 
   ```

   - 如输出结果为/bin/bash，则执行以下命令，打开.bash_profile文件。

      ```shell
      vi ~/.bash_profile
      ```

   - 如输出结果为/bin/zsh，则执行以下命令，打开.zshrc文件。

      ```shell
      vi ~/.zshrc
      ```

2. 单击字母“i”，进入**Insert**模式。

3. 输入以下内容，在PATH路径下**增加**SDK路径信息，具体路径信息以SDK**实际配置路径**为准。

   以下内容以本地SDK的toolchains完整路径<!--RP1-->_/User/username/sdk/openharmony/10/toolchains_<!--RP1End-->为例：

   ```shell
   HDC_SDK_PATH=/User/username/sdk/openharmony/10/toolchains
   launchctl setenv HDC_SDK_PATH $HDC_SDK_PATH # 仅MacOS需要在此执行，Linux无须执行
   export PATH=$PATH:$HDC_SDK_PATH
   ```

4. 编辑完成后，单击**Esc**键，退出编辑模式，然后输入“:wq”，单击**Enter**键保存。

5. 执行以下命令，使配置的环境变量生效。

   - 如果步骤1时打开的是.bash_profile文件，请执行如下命令：

      ```shell
      source ~/.bash_profile
      ```

   - 如果步骤1时打开的是.zshrc文件，请执行如下命令：

      ```shell
      source ~/.zshrc
      ```
<!--Del-->
**（Linux可选）开启非root用户USB设备操作权限**

- （临时权限）设置USB设备操作权限最大化

   ```shell
   sudo chmod -R 777 /dev/bus/usb/
   ```

- （永久权限）永久修改USB设备权限

   1. 使用lsusb找出USB设备的vendorID和productID。

   2. 创建一个新的udev规则。

      编辑udev加载规则，用设备的“idVendor”和“idProduct”来替换默认值。

      MODE="0666"来表示USB设备的权限GROUP；GROUP代表用户组，要确保此时登录的系统用户在该用户组中：

        ```shell
        sudo vim /etc/udev/rules.d/90-myusb.rules
        SUBSYSTEMS=="usb", ATTRS{idVendor}=="067b", ATTRS{idProduct}=="2303", GROUP="users", MODE="0666"
        ```

   3. 重启电脑或重新加载udev规则：

        ```shell
        sudo udevadm control --reload
        ```

> **注意：**
> **开启非root用户USB设备操作权限**可以解决Linux环境在非root权限下使用hdc无法找到设备的情况，但权限最大化**可能存在潜在安全问题**，请开发者根据使用场景自行评估是否开启。

## 注意事项

- 使用hdc时如出现异常，可尝试通过hdc kill -r命令杀掉异常进程并重启hdc服务。

- 如出现hdc list targets获取不到设备信息的情况，可通过任务管理器查看是否有hdc进程存在。若进程存在，则通过hdc kill -r命令杀掉该进程并重启hdc服务。

> **说明：**
>
> - 命令行中被[]修饰的参数表示可选参数。
> - 命令行中的参数若是斜体，表示在使用时该参数需替换为具体的信息，例如：file send _local remote_命令中的local和remote，使用时需替换为本地待发送和远端待接收的文件路径。
<!--DelEnd-->

## 开发指导

### 全局option相关命令

| Option | 说明 |
| -------- | -------- |
| -t [key] [command] | 指定连接唯一标识的目标设备。标识可通过命令hdc list targets查询。 | 
| help/-h | 打印hdc帮助信息。 |
| version/-v | 打印hdc版本信息。 |
| -l [level] | 指定运行时日志等级，默认为LOG_INFO。 |
| checkserver | 获取client-server版本。 |

1. 显示hdc相关的帮助信息，命令格式如下：

   ```shell
   hdc -h
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | OpenHarmony device connector(HDC) ...<br/>---------------------------------global commands:----------------------------------<br/>-h/help [verbose]&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Print hdc help, 'verbose' for more other cmds<br/>..._（此处省略详细帮助信息）_ | hdc命令使用帮助信息 | 

   **使用方法：**

   ```shell
   hdc -h
   ```

2. 显示hdc的版本信息，命令格式如下：

   ```shell
   hdc -v
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Ver: X.X.Xa | hdc（SDK）的版本信息 |

   **使用方法：**

   ```shell
   hdc -v
   ```

3. 连接设备时，若仅有一台，无需指定设备标识；若有多台，一次仅能连接一台，每次连接时需要指定连接设备的标识，命令格式如下：

   ```shell
   hdc-t [key] [command]
   ```

   **参数：**
   | 参数名 | 说明 |
   | -------- | -------- |
   | key | IP地址或USB序列号。 |
   | command | hdc支持的命令。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 命令执行返回内容 | 请参考对应命令的返回值 |
   | [Fail]Not match target founded, check connect-key please | 连接的设备不存在 |
   | [Fail]ExecuteCommand need connect-key? | 连接的设备不存在或同时连接多台设备时，未指定连接设备标识 |
   | Unknown operation command... | 不支持的命令 |

   **使用方法**：

   该方法需要与具体的操作命令搭配使用，下面以shell命令举例：

   ```shell
   hdc list targets  // 获取设备信息
   hdc -t [key] shell // -t后面添加的key需要替换为查询到的某一个设备信息，此处COMMAND命令为shell即进入调试命令行
   ```

   > **说明：**
   > 一台用于开发的电脑可连接多个设备，每个设备有唯一的标识。如果通过网络连接设备，标识为IP地址；如果通过usb连接，标识为USB序列号。该命令需要跟随具体的操作命令。

4. 指定运行时日志等级，默认为LOG_INFO，命令格式如下：

   ```shell
   hdc -l [level] [command]
   ```

   **参数：**
   | 参数 | 说明 |
   | -------- | -------- |
   | [level] | 指定运行时日志等级<br/>0：LOG_OFF<br/>1：LOG_FATAL<br/>2：LOG_WARN<br/>3：LOG_INFO<br/>4：LOG_DEBUG<br/>5：LOG_ALL | 
   | command | hdc支持的命令 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 命令执行返回内容 | 请参考对应命令的返回值 |
   | LOG日志信息 | 对应指定的运行时等级日志打印 |

   **使用方法：**

   ```shell
   hdc -l 5 shell ls
   ```

5. 获取client-server版本，命令格式如下：

   ```shell
   hdc checkserver
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Client version: Ver: X.X.Xa, server version: Ver: X.X.Xa | client-server版本号 | 

   **使用方法：**

   ```shell
   hdc checkserver
   ```

### 查询设备列表相关命令

| 命令 | 说明 |
| -------- | -------- |
| list targets [-v] | 查询已连接的所有目标设备，添加-v选项，则会打印设备详细信息。 |

显示所有已连接的设备列表，命令格式如下：

```shell
hdc list targets[-v]
```

**返回值：**
| 返回值 | 说明 |
| -------- | -------- |
| 设备信息 | 已连接的设备列表信息 |
| [Empty] | 没有查询到设备信息 |

**使用方法：**

```shell
hdc list targets
hdc list targets -v
```

### 服务进程相关命令

| 命令 | 说明 |
| -------- | -------- |
| target mount | 读写模式挂载系统分区。（user不可用） |
| target boot | 重启目标设备，查看目标列表可用list targets命令。 |
| smode [-r] | 授予设备端hdc后台服务进程root权限， 使用-r参数取消授权。（user不可用） |
| kill [-r] | 终止hdc服务进程，使用-r参数触发服务进程重新启动。 |
| start [-r] | 启动hdc服务进程，使用-r参数触发服务进程重新启动。 |

1. 以读写模式挂载系统分区，命令格式如下：

   ```shell
   hdc target mount
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Mount finish | 挂载成功 |
   | [Fail]具体失败信息 | 挂载失败 |

   **使用方法：**

   ```shell
   hdc target mount
   ```

2. 授予设备端hdc后台服务进程root权限，命令格式如下：

   ```shell
   hdc smode [-r]
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无返回值 | 授予权限成功 |
   | [Fail]具体失败信息 | 授予权限失败 |

   **使用方法：**

   ```shell
   hdc smode  
   hdc smode -r  // 取消root权限
   ```

3. 终止hdc服务进程，命令格式如下：

   ```shell
   hdc kill [-r]
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Kill server finish | 服务进程终止成功 |
   | [Fail]具体失败信息 | 服务进程终止失败 |

   **使用方法：**

   ```shell
   hdc kill
   hdc kill -r  // 重启并终止服务进程
   ```

4. 启动hdc服务进程，命令格式如下：

   ```shell
   hdc start [-r]
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无返回值 | 服务进程启动成功 |
   | [Fail]具体失败信息 | 服务进程启动失败 |

   **使用方法：**

   ```shell
   hdc start
   hdc start -r // 服务进程启动状态下，触发服务进程重新启动
   ```

### 网络相关命令

| 命令 | 说明 |
| -------- | -------- |
| fport ls | 列出全部转发端口转发任务。 |
| fport _local remote_ | 设置正向端口转发任务：监听“主机端口”，接收请求并进行转发， 转发到“设备端口”。 |
| fport rm _local__remote_ | 删除正向端口转发任务：取消指定的“主机端口”转发。 |
| rport _remote local_ | 设置反向端口转发任务：监听“设备端口”，接收请求并进行转发，转发到“主机端口”。 |
| rport rm _remote local_ | 删除反向端口转发任务：取消指定的“设备端口”转发。 |
| tmode usb | 已连接设备切换为USB连接方式：设备端daemon进程重启，并首先选用USB连接方式。 |
| tmode port [port-number] | 已连接设备切换为网络连接方式：设备端daemon进程重启，并优先使用网络方式连接设备，如果连接设备失败，再选择USB连接。 |
| tconn_ host_[:port] [-remove] | 指定连接设备：通过“IP地址：端口号”来指定连接的设备，使用-remove参数断开连接。 |

1. 列出全部转发端口转发任务，命令格式如下：

   ```shell
   hdc fport ls
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 'tcp:1234 tcp:1080' [Forward] | 正向端口转发任务。 |
   | 'tcp:2080 tcp:2345' [Reverse] | 反向端口转发任务。 |
   | [empty] | 无端口转发任务。 |

   **使用方法：**

   ```shell
   hdc fport ls
   ```

2. 设置正向端口转发任务，执行后将设置指定的“主机端口”转发数据到“设备端口”转发任务，命令格式如下：

   ```shell
   hdc fport local remote
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Forwardport result:OK | 端口转发任务设置正常。 |
   | [Fail]Incorrect forward command | 端口转发任务设置失败，端口转发参数错误。 |
   | [Fail]TCP Port listen failed at XXXX | 端口转发任务设置失败，本地转发端口被占用。 |

   **使用方法：**

   ```shell
   hdc fport tcp:1234 tcp:1080
   ```

3. 删除正向端口转发任务，执行后将指定的“主机端口”转发数据到“设备端口”转发任务删除，命令格式如下：

   ```shell
   hdc fport rm localremote
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Remove forward ruler success, ruler:tcp:XXXX tcp:XXXX | 端口转发任务删除正常。 |
   | [Fail]Remove forward ruler failed, ruler is not exist tcp:XXXX tcp:XXXX | 端口转发任务删除失败，不存在指定的转发任务。 |

   **使用方法：**

   ```shell
   hdc fport rm tcp:1234 tcp:1080
   ```

4. 设置反向端口转发任务，执行后将设置指定的“设备端口”转发数据到“主机端口”转发任务，命令格式如下：

   ```shell
   hdc rport remote local
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Forwardport result:OK | 端口转发任务设置正常。 | 
   | [Fail]Incorrect forward command | 端口转发任务设置失败，端口转发参数错误。 |
   | [Fail]TCP Port listen failed at XXXX | 端口转发任务设置失败，本地转发端口被占用。 |

   **使用方法：**

   ```shell
   hdc rport tcp:1234 tcp:1080
   ```

5. 删除反向端口转发任务，执行后将指定的“设备端口”转发数据到“主机端口”任务删除，命令格式如下：

   ```shell
   hdc rport rm remote local
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Remove forward ruler success, ruler:tcp:XXXX tcp:XXXX | 端口转发任务删除正常。 |
   | [Fail]Remove forward ruler failed, ruler is not exist tcp:XXXX tcp:XXXX | 端口转发任务删除失败，不存在对应的转发任务。 |

   **使用方法：**

   ```shell
   hdc rport rm tcp:1234 tcp:1080
   ```

6. 已连接设备切换为USB连接方式，命令格式如下：

   ```shell
   hdc tmode usb
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无 | 切换成功。 |
   | [Fail]ExecuteCommand need connect-key | 设备列表无网络连接方式设备，无法指定设备切换连接方式。 |

   **使用方法：**

   ```shell
   hdc tmode usb
   ```

7. 已连接设备切换为网络连接方式，命令格式如下：

   ```shell
   hdc tmode port [port-number]
   ```

   **参数：**
   | 参数 | 参数说明 |
   | -------- | -------- |
   | port-number | 监听连接的网络端口号，范围:1~65536。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无 | 切换成功。 |
   | [Fail]ExecuteCommand need connect-key | 切换失败，设备列表无设备，无法指定设备切换连接方式。 |
   | [Fail]Incorrect port range | 端口号超出可设置范围（1~65536）。 |

   **使用方法：**

   ```shell
   hdc tmode port 1234
   ```

   > **注意：**
   > 切换前，请确保条件满足：远端设备与近端执行机处于同一网络，且执行机可ping通远端设备IP。
   >
   > 如不满足以上条件请勿使用该命令进行切换。

   > **说明：**
   > 执行完毕后，远端daemon将会退出并重启，USB连接将会断开，默认启用TCP连接，且仅可通过TCP进行连接，如需恢复USB连接有以下两种方法：
   >
   > （1）执行hdc tconn [ip]:[port]命令进行TCP连接后，执行hdc tmode usb恢复。
   >
   > （2）通过恢复出厂设置恢复。

8. 指定连接的设备，命令格式如下：

   ```shell
   hdc tconn host[:port] [-remove]
   ```

   **参数：**
   | 参数 | 参数说明 |
   | -------- | -------- |
   | host[:port] | 设备IP地址与端口号，格式按照“IP地址：端口号“。 |
   | -remove | 【可选】断开指定设备的连接。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | Connect OK | 连接成功。 |
   | [Info]Target is connected, repeat opration | 设备当前已连接。 |
   | [Fail]Connect failed | 连接失败。 |

   **使用方法：**

   ```shell
   hdc tconn 192.168.0.1:8888
   hdc tconn 192.168.0.1:8888 -remove  // 断开指定网络设备连接
   ```

### 文件相关命令

| 命令 | 说明 |
| -------- | -------- |
| file send _local remote_ | 从本地发送文件至远端设备。 |
| file recv _remote local_ | 从远端设备发送文件至本地。 |

1. 从本地发送文件至远端设备，命令格式如下：

   ```shell
   hdc file send local remote
   ```

   **参数：**
   | 参数名 | 说明 |
   | -------- | -------- |
   | local | 本地待发送的文件路径。 |
   | remote | 远程待接收的文件路径。 |

   **返回值：**

   文件发送成功，返回传输成功的结果信息。文件发送失败，返回传输失败的具体信息。

   **使用方法：**

   ```shell
   hdc file send E:\example.txt /data/local/tmp/example.txt
   ```

2. 从远端设备发送文件至本地，命令格式如下：

   ```shell
   hdc file recv remote local
   ```

   **参数：**
   | 参数名 | 说明 |
   | -------- | -------- |
   | local | 本地待接收的文件路径。 |
   | remote | 远程待发送的文件路径。 |

   **返回值：**

   文件接收成功，返回传输成功的结果信息。文件接收失败，返回传输失败的具体信息。

   **使用方法：**

   ```shell
   hdc file recv  /data/local/tmp/a.txt   ./a.txt
   ```

### 应用相关命令

| 命令 | 说明 |
| -------- | -------- |
| install [-r/-d/-g] _packageFile_ | 安装指定的应用package文件。 |
| uninstall_ packageName_ | 卸载指定的应用包package包名。 |

1. 安装APP package，命令格式如下：

   ```shell
   hdc install [-r/-d/-g] packageFile
   ```

   **参数：**
   | 参数名 | 说明 |
   | -------- | -------- |
   | packageFile | 应用安装包文件名。 |
   | -r | 替换已存在应用。 |
   | -d | 允许降级安装。 |
   | -g | 应用动态授权。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无 | 成功情况下无返回值。 |
   | 具体安装失败原因 | 失败情况下返回具体安装失败信息。 |

   **使用方法：**

   以安装com.example.hello包为例：

   ```shell
   hdc install E:\com.example.hello.hap
   ```

2. 卸载应用，命令格式如下：

   ```shell
   hdc uninstall [-k] packageName
   ```

   **参数：**
   | 参数名 | 说明 |
   | -------- | -------- |
   | packageName | 应用安装包。 |
   | -k | 保留/data/cache。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 无 | 成功情况下无返回值。 |
   | 具体卸载失败原因 | 失败情况下返回具体卸载失败信息。 |

   **使用方法：**

   以卸载com.example.hello包为例：

   ```shell
   hdc uninstall com.example.hello
   ```

### 调试相关命令

| 命令 | 说明 |
| -------- | -------- |
| jpid | 显示可调试应用列表。 | 
| hilog [options] | 打印设备端的日志信息，options表示hilog支持的参数，可通过hdc hilog -h查阅支持的参数列表 。 |
| shell [COMMAND] | 交互命令，COMMAND表示需要执行的单次命令。不同类型或版本的系统支持的COMMAND命令有所差异，可以通过hdc shell ls /system/bin查阅支持的命令列表。 |

1. 抓取log信息，命令格式如下：

   ```shell
   hdc hilog[options]
   ```

   **参数：**
   | 参数 | 说明 |
   | -------- | -------- |
   | [options] | hilog支持的参数，可通过hdc hilog -h查阅支持的参数列表。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 返回具体信息 | 抓取的日志信息。 |

   **使用方法：**

   ```shell
   hdc hilog 
   hdc shell "hilog -r" // 清理hilog缓存日志
   ```

2. 显示可调试应用列表，命令格式如下：

   ```shell
   hdc jpid
   ```

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 应用名列表 | 可调试应用名列表。 |
   | [empty] | 无可调式应用。 |

   **使用方法：**

   ```shell
   hdc jpid
   ```

3. 交互命令，命令格式如下：

   ```shell
   hdc shell [COMMAND]
   ```

   **参数：**
   | 参数 | 说明 |
   | -------- | -------- |
   | [COMMAND] | 调试命令行可用命令，详细可用命令help来获取全部命令提示。 |

   **返回值：**
   | 返回值 | 说明 |
   | -------- | -------- |
   | 交互命令返回内容 | 返回内容详情请参见其他交互命令返回内容。 | 
   | /bin/sh: XXX : inaccessible or not found | 不支持的交互命令。 |

   **使用方法：**

   ```shell
   hdc shell ps -ef  
   hdc shell help -a // 查询全部可用命令
   ```

## 常见场景

### USB连接场景

**环境确认**
| 确认项 | 正常 | 异常处理 |
| -------- | -------- | -------- |
| USB调试选项 | 开启 | 设备的USB调试模式如无法自动开启，请尝试重启设备。 |
| USB数据连接线 | 使用USB数据连接线连接到调试PC的USB接口。 | 如使用低带宽、无数据通信功能的USB连接线可能导致无法识别HDC设备，建议更换官方USB数据连接线。 |
| USB接口 | 主板直出USB接口（台式机为后面板的USB接口，笔记本为机身的USB接口） | 如使用转接头/拓展坞/台式机前面板USB接口，存在带宽低和USB同步异常等问题，会导致频繁断连，推荐使用直连方式连接PC和设备。 |
| hdc环境变量 | 终端命令行输入hdc -h有回显帮助信息内容。 | 参见环境准备章节。 |
| 驱动 | 连接HDC设备后，设备管理器通用串行总线设备存在设备"HDC Device"或"HDC Interface" | 请安装驱动。 |

**连接步骤**

```shell
hdc shell //USB直连需要确认设备非处在tcp连接模式，直接连接即可。
```

### TCP连接场景

**环境确认**
| 确认项 | 正常 | 异常处理 |
| -------- | -------- | -------- |
| 网络连接 | PC、手机设备处于同一网络。 | 连接同一WiFi或手机开启热点。 |
| 网络状态 | telnet ip:port正常，网速稳定。 | 请选择稳定的网络连接方式。 |
| hdc环境变量 | 终端命令行输入hdc -h有回显帮助信息内容。 | 参见环境准备章节。 |

**连接步骤**

1. PC通过USB连接设备。

2. 设置亮屏幕，执行以下命令：

   ```shell
   hdc shell “power-shell setmode 602”
   ```

   保持亮屏状态，避免熄屏导致 wifi断掉；如果此时设备断连，需要重新较快输入tconn连接指令

3. 将设备通过USB模式切换至tcp模式，执行以下命令：

   ```shell
   hdc tmode port 8710//port 后加指定端口号（可自行设置）
   ```

4. 通过tcp连接设备（需要事先知道设备IP），执行以下命令：

   ```shell
   hdc tconn ip:8710
   ```

   ip可在手机查看设备侧的ip地址，端口号为上一步指定的，默认值为8710。

5. 查看已连接设备，执行以下命令：

   ```shell
   hdc list targets
   ```

   返回值为ip:port形式即为连接成功，单台设备可以正常使用hdc命令，多台设备需要-t指定设备使用hdc命令。

6. （可选）TCP模式切换回USB模式,在已连接TCP模式状态下，执行以下命令：

   ```shell
   hdc tmode usb
   ```

   切换后将恢复USB模式。

### 远程连接场景

远程连接结构如图所示。

![远程连接结构图](figures/hdc_image_004.PNG)

**服务端配置**

服务端通过USB连接到对应的HDC设备后执行以下命令：

```shell
hdc kill          // 关闭本地hdc服务
hdc -s ip:8710 -m // 启动网络转发的hdc服务
                  // 其中ip为服务端自身的IP，windows可通过ipconfig查询，unix系统可通过ifconfig查询
                  // 8710为默认端口号，也可设置为其他端口号如：18710
                  // 启动后服务端将打印日志
```

**客户端连接**

客户端连接需要确保可以连通服务端IP地址，满足前述条件后执行以下命令：
```shell
hdc -s ip:8710 [command] // 其中ip为服务端IP，
                         // command可以为任意hdc可用命令，例如list targets
```

### 日志获取场景

**server端日志**

执行以下命令开启日志获取：

```shell
hdc kill ​
hdc -l5 start
```

收集到的完整日志存放路径：

| 平台 | 路径 | 备注 |
| -------- | -------- | -------- |
| Windows | %temp%\hdc.log | 实际路径参考，实际使用请替换用户名变量<br/>C:\Users\用户名\AppData\Local\Temp\hdc.log<br/>**说明：**<br/>Windows的文件路径使用反斜线“\”。 |
| Linux | /tmp/hdc.log | - |
| MacOS | $TMPDIR/hdc.log | - |

**设备端日志**

开启hilog日志工具，获取对应日志，命令如下：

```shell
hdc shell hilog -w start                              // 开启hilog日志落盘
hdc shell ls /data/log/hilog                          // 查看已落盘hilog日志
hdc file recv /data/log/hilog                         // 获取hilog已落盘日志（包含内核日志）
```

## 常见问题

### 设备无法识别

**现象描述**

命令行执行`hdc list targets`命令后，返回结果为`[empty]`。

可通过以下方式排查。

- 情况一：查看设备管理是否显示HDC设备。

  Windows环境：

  在`设备管理器`>`通用串行总线设备`中是否显示`HDC Device`（单一端口设备）或`HDC Interface`（复合端口设备）。

  Linux环境：

  在命令行执行`lsusb`,在返回的内容中查看是否有`HDC Device`（单一端口设备）或`HDC Interface`（复合端口设备）。

  MacOS环境：

  使用`系统信息`或`系统概述`来查看USB设备，步骤如下：

  1. 按住键盘上的Option键，点按菜单。

  2. 选取`系统信息`或`系统概述`。

  3. 在随后出现的窗口中，选择左边的`USB`。

  4. 在随后显示的设备树查看是否有`HDC Device`（单一端口设备）或`HDC Interface`（复合端口设备）。

  **可采取的解决方法**

  以上环境如没有显示HDC设备，则说明无法识别设备，可以根据实际场景尝试以下方法：

  - 使用其他USB物理接口。
  - 更换USB数据连接线。
  - 使用其他计算机调试。
  - 设备开启USB调试模式。
  - 设备出现弹窗点击允许调试。
  - 如可通过TCP模式连接，可执行`hdc tmode usb`命令恢复USB连接。
  - 设备恢复出厂设备。

- 情况二：存在USB设备，但是驱动损坏，显示"HDC Device"⚠警告图标。

  现象描述：该问题常见于Windows环境，现象为`设备管理器`>`通用串行总线设备`中，`HDC Device`显示为黄标警告，且描述信息为该设备无法正常工作。可尝试重新安装驱动解决，如重新安装驱动无法解决，可以尝试更换USB连接数据线/拓展坞/USB接口。

  **重新安装驱动的方法**

  1. 打开`设备管理器`，右键点击存在警告图标的`HDC Device`；

  2. 出现的菜单中点击`更新驱动程序`；

  3. 出现的提示窗口（第1/3个）中，选取`浏览我的电脑以查找驱动程序`；

  4. 出现的提示窗口（第2/3个）中，选取`让我从计算机上的可用驱动程序列表中选取`；

  5. 出现的提示窗口（第3/3个）中，取消勾选`显示兼容硬件`，选择厂商：`WinUSB设备`，选择型号：`WinUSB设备`，选择完成后点击`下一步`按钮。

- 情况三：连接设备时出现`[Fail]Failed to communicate with daemon`。

  现象描述：命令行执行hdc相关命令，执行失败返回`[Fail]Failed to communicate with daemon`。

  可能存在以下原因，可参考排查：

  - hdc SDK与设备不匹配: 如果设备更新到最新版本，可更新hdc（SDK）工具至最新版本。
  - 端口被占用：

    常见于hdc和hdc_std使用同一端口，同时运行时HDC_SERVER_PORT设置的端口互相冲突（未设置则使用默认端口8710，仍然会冲突），注意只运行其中一个。其他软件占用hdc默认端口也会导致该问题发生。

- 情况四：连接设备时出现`Connect server failed`。

  出现该现象，可能有如下原因：

  - **端口抢占**

    解决方法如下：
    1. 排查自带hdc的软件进程。

       包括自带hdc的软件（DevEco Studio、DevEco Testing），如存在请关闭这些软件后再执行hdc相关命令。

    2. 查询HDC端口情况。

       以设置的HDC_SERVER_PORT为8710端口为例，在不同平台查询命令如下：

       Unix：

       ```shell
       netstat -an |grep 8710
       ```

       Windows:

       ```shell
       netstat -an |findstr 8710
       ```

       如存在抢占的软件，可以关闭该软件进程或者更换HDC_SERVER_PORT环境变量为其他端口号。

    3. 排查未关闭的其他版本hdc server

       Windows：

       使用`任务管理器`>`详细信息`查询hdc.exe进程,右键打开文件所在位置，核对位置是否为配置的环境变量中的hdc文件位置，如果不一致，可尝试结束hdc.exe进程(hdc kill或者任务管理器直接结束进程)并重新执行hdc命令。（关闭hdc server后执行hdc命令会重新启动hdc server）

       Unix：

       使用`ps -ef |grep hdc`查询hdc后台server进程，核对进程启动位置是否为配置的环境变量中的hdc文件位置，如果不一致，可尝试结束hdc进程(hdc kill或者kill -9 hdc进程的PID)并重新执行hdc命令。（关闭hdc server后执行hdc命令会重新启动hdc server）

  - **注册表异常**

    解决方法：清理注册表，步骤如下：

    1. 同时按下`Win`+`R`键，启动运行工具，输入栏输入`regedit`打开注册表。
    2. 注册表地址栏输入以下内容并按下`回车`，即可进入USB类设备驱动程序的注册表。

       ```shell
       计算机\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{88bae032-5a81-49f0-bc3d-a4ff138216d6}
       ```

    3. 找到`UpperFilters`键，右键`修改`编辑，**备份**并清空其中数值数据内容（如清空后无法解决问题可依照备份恢复）。
    4. 刷新设备管理器/插拔USB接口/重启计算机。

### hdc无法运行

**现象描述**

使用命令行执行hdc.exe/hdc 二进制文件无法运行。

**可能原因&解决方法**

- 运行环境异常

  Linux运行环境：建议使用Ubuntu18.04及以上64版本，如发送libc++.so引用错误请使用ldd/readelf等命令检查库引用。

  MacOS运行环境：建议使用MacOS 11及以上版本。

  Windows运行环境：建议使用Windows10/Windows11 64位版本，如低版本缺失WinUSB库/驱动，请使用Zadig工具更新。对于符合设备，需要使用Zadig工具安装libusb-win32驱动。[Zadig链接](https://github.com/pbatard/libwdi/releases)

- 运行方式不当：请使用命令行依照正确命令运行hdc工具，而非鼠标双击文件。

### 其他问题排查常用步骤

1. 命令行执行`hdc list targets`查看返回值。
2. 查看`设备管理`是否有`HDC Device`。
3. 执行`hdc kill`关闭server后，执行`hdc -l5 start`收集日志（hdc.log位于执行端TEMP目录，不同平台目录位置存在差异，可参考[日志获取场景](#日志获取场景)）。
4. 通过hdc.log日志定位相关问题。

# 常见问题

## 常见编译问题和解决方法

###  提示“usr/sbin/ninja: invalid option -- w”

- **现象描述：** 编译失败，提示“usr/sbin/ninja: invalid option -- w”。

- **可能原因：** 编译环境中ninja版本太低，不支持--w选项。

- **解决办法：** 卸载环境中ninja和gn，按照[获取工具](../../device-dev/get-code/gettools-ide.md)。

### 提示“/usr/bin/ld: cannot find -lncurses”

- **现象描述：** 编译失败，提示“/usr/bin/ld: cannot find -lncurses”。

- **可能原因：** 编译环境ncurses库缺失。

- **解决办法：**

  ```shell
  sudo apt-get install lib32ncurses5-dev
  ```

### 提示“line 77: mcopy: command not found”

- **现象描述：** 编译失败，提示“line 77: mcopy: command not found”。

- **可能原因：** 编译环境未安装mcopy。

- **解决办法：**

  ```shell
  sudo apt-get install dosfstools mtools
  ```

### 提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”

- **现象描述：** 编译失败，提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”。

- **可能原因：** 当前用户对riscv编译器路径下的文件访问权限不够。

- **解决办法：** 查询gcc_riscv32所在目录。

  ```shell
  which riscv32-unknown-elf-gcc
  ```

  使用chmod命令修改目录权限为755。

### 提示“No module named 'Crypto'”

- **现象描述：** 编译失败，提示“No module named 'Crypto'”。

- **可能原因：** python3未安装Crypto。

- **解决办法：**

  1. 查询Python版本号。

     ```shell
     python3 --version
     ```

  2. 需使用python3.9.2以上版本，然后安装pycryptodome。

     ```shell
     sudo pip3 install pycryptodome
     ```

### 提示“xx.sh : xx unexpected operator”

- **现象描述：** 编译失败：“xx.sh [: xx unexpected operator”。

- **可能原因：** 编译环境shell不是bash。

- **解决办法：**

  ```shell
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```


### 提示“some services are not authenticated. Listed as follow”

- **现象描述：** 编译失败：“some services are not authenticated. Listed as follow”。

- **可能原因：** 报错中列举出来的进程.cfg配置文件中，定义了uid为root或system，而该进程并不在产品定义的高权限进程允许范围内。

- **解决办法：**

  1. 降低进程的权限等级。修改.cfg配置文件中的uid定义，非必需的场景下，不要定义uid为root或system。

     *如果由于实现业务功能需要，进程必须要有root或system权限，只有在联系安全专家评审，通过安全审视后，方可修改产品的高权限进程管控列表，配置文件路径为"`vendor/{公司名称}/{产品名称}/security_config/high_privilege_process_list.json`"。*

     *示例：rk3586的高权限进程配置文件位于`//vendor/hihope/rk3568/security_config/high_privilege_process_list.json`*


### 提示“Error: some services do not match with critical whitelist”

- **现象描述：** 编译失败：“Error: some services do not match with critical whitelist”。

- **可能原因：** 报错中列举出来的进程.cfg配置文件中，定义并使能了critical字段，而该进程未被允许添加critical字段，或该字段配置与白名单中不符。

- **解决办法：**

     移除进程的critical字段或把critical字段第一位置0。修改原服务.cfg配置文件中的critical字段，非必需的场景下，不要使能critical字段。

     关于critical字段的详细使用方法，请参考[服务配置](subsys-boot-init-service.md)。如果由于实现业务功能需要，进程必须要使能critical字段，只有在联系安全专家评审，通过安全审视后，方可修改产品的critical_reboot进程管控白名单`//vendor/{公司名称}/{产品名称}/security_config/critical_reboot_process_list.json`。

     示例：rk3586的critical_reboot进程管控白名单为`//vendor/hihope/rk3568/security_config/critical_reboot_process_list.json`
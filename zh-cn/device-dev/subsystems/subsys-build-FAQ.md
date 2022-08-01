# 常见问题

## 常见编译问题和解决方法

###  编译构建过程中，提示“usr/sbin/ninja: invalid option -- w”

- **现象描述：** 编译失败，提示“usr/sbin/ninja: invalid option -- w”。

- **可能原因：** 编译环境中ninja版本太低，不支持--w选项。

- **解决办法：** 卸载环境中ninja和gn，按照[获取工具](../../device-dev/get-code/gettools-ide.md)。

### 编译构建过程中，提示“/usr/bin/ld: cannot find -lncurses”

- **现象描述：** 编译失败，提示“/usr/bin/ld: cannot find -lncurses”。

- **可能原因：** 编译环境ncurses库缺失。

- **解决办法：**

  ```shell
  sudo apt-get install lib32ncurses5-dev
  ```

### 编译构建过程中，提示“line 77: mcopy: command not found”

- **现象描述：** 编译失败，提示“line 77: mcopy: command not found”。

- **可能原因：** 编译环境未安装mcopy。

- **解决办法：**

  ```shell
  sudo apt-get install dosfstools mtools
  ```

### 编译构建过程中，提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”

- **现象描述：** 编译失败，提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”。

- **可能原因：** 当前用户对riscv编译器路径下的文件访问权限不够。

- **解决办法：** 查询gcc_riscv32所在目录。

  ```shell
  which riscv32-unknown-elf-gcc
  ```

  使用chmod命令修改目录权限为755。

### 编译构建过程中，提示“No module named 'Crypto'”

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

### 编译构建过程中，提示“xx.sh : xx unexpected operator”

- **现象描述：** 编译失败：“xx.sh [: xx unexpected operator”。

- **可能原因：** 编译环境shell不是bash。

- **解决办法：**

  ```shell
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```

  

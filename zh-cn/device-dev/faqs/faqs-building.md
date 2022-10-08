# 编译构建常见问题


## 轻量和小型系统


### 提示“usr/sbin/ninja: invalid option -- w”

- **现象描述：**

  编译失败，提示“usr/sbin/ninja: invalid option -- w”。

- **可能原因：**

  编译环境中ninja版本太低，不支持--w选项。

- **解决办法：**

  卸载环境中ninja和gn，按照[获取工具](../get-code/gettools-ide.md)。


### 提示“/usr/bin/ld: cannot find -lncurses”

- **现象描述：**
  
  编译失败，提示“/usr/bin/ld: cannot find -lncurses”。

- **可能原因：**
  
  编译环境ncurses库缺失。

- **解决办法：**
    
  ```
  sudo apt-get install lib32ncurses5-dev
  ```


### 提示“line 77: mcopy: command not found”

- **现象描述：** 

  编译失败，提示“line 77: mcopy: command not found”。

- **可能原因：**
  
  编译环境未安装mcopy。

- **解决办法：**
    
  ```
  ​sudo apt-get install dosfstools mtools
  ```


### 提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”

- **现象描述：**
  
  编译失败，提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”。

- ​**可能原因：**

  当前用户对riscv编译器路径下的文件访问权限不够。

- ​**解决办法：**

    查询gcc_riscv32所在目录。
    
  ```
  which riscv32-unknown-elf-gcc
  ```

  使用chmod命令修改目录权限为755。


### 提示“No module named 'Crypto'”

- **现象描述：**

  编译失败，提示“No module named 'Crypto'”。

- **可能原因：**

  python3未安装Crypto。

- **解决办法：**

  1. 查询Python版本号。
        
      ```
      python3 --version
      ```
  2. 需使用python3.7以上版本，然后安装pycryptodome。
        
      ```
      sudo pip3 install pycryptodome
      ```


### 提示“xx.sh : xx unexpected operator”

- **现象描述：**

  编译失败：“xx.sh [: xx unexpected operator”。

- **可能原因：**

  编译环境shell不是bash。

- **解决办法：**
    
  ```
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```


### 提示“Could not find a version that satisfies the requirement six&gt;=1.9.0”

- **现象描述**

  编译构建过程中出现以下错误：

    
  ```
  Could not find a version that satisfies the requirement six>=1.9.0
  ```

- **可能原因**

  环境中未安装合适的“six”。

- **解决办法**

  方法1：通过命令“pip3 install six”，在线安装。

  方法2：离线安装。

  通过网页[https://pypi.org/project/six/#files](https://pypi.org/project/six/#files)，下载安装包。

  ![zh-cn_image_0000001251276115](figures/zh-cn_image_0000001251276115.png)

  将源码放置在Linux服务器中，并安装“pip3 install six-1.14.0-py2.py3-none-any.whl”。

  完成上述安装后，重新构建。


### 提示找不到“-lgcc”

- **现象描述**

  编译构建过程中出现以下错误：

    
  ```
  riscv32-unknown-elf-ld: cannot find -lgcc
  ```

- **可能原因**

  交叉编译器gcc_riscv32的PATH添加错误，如下，在"bin"后多添加了一个“/”，应该删除。

    
  ```
  ~/gcc_riscv32/bin/:/data/toolchain/
  ```

- **解决办法**

  重新修改gcc_riscv32的PATH，将多余的“/”删除。

    
  ```
  ~/gcc_riscv32/bin:/data/toolchain/
  ```


### 提示找不到“python”

- **现象描述**

  编译构建过程中出现以下错误：

    
  ```
  -bash: /usr/bin/python: No such file or directory
  ```

- **可能原因**1

  没有装python。

- **解决办法**

  请使用如下命令安装Python，下方以Python3.8为例。

    
  ```
  sudo apt-get install python3.8
  ```

- **可能原因2**

  usr/bin目录下没有python软链接

  ![zh-cn_image_0000001243200677](figures/zh-cn_image_0000001243200677.png)

- **解决办法**

  请运行以下命令添加软链接：

    
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  例：

  ![zh-cn_image_0000001243320787](figures/zh-cn_image_0000001243320787.png)


### 提示找不到“python3”

- **现象描述**

  ![zh-cn_image_0000001251276255](figures/zh-cn_image_0000001251276255.png)

- **可能原因**

  没有装python3。

- **解决办法**

  请使用如下命令安装Python3。

    
  ```
  sudo apt-get install python3.8
  ```

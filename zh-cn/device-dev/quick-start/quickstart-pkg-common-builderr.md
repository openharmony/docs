# 编译异常处理


## Linux编译服务器终端输入不识别的命令时提示“ImportError: No module named apt_pkg”

- **现象描述**
  
  Linux编译服务器终端输入不识别的命令时，提示"ImportError: No module named apt_pkg"。

- **可能原因**
  
  python3 apt安装兼容性问题。

- **解决办法**
  
  执行如下命令重新安装python3-apt。

  
  ```
  sudo apt-get remove  python3-apt
  sudo apt-get install python3-apt
  ```


## 编译构建过程中，提示找不到“python”

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
  
  usr/bin目录下没有python软链接。

  ![faq-python-error](figures/faq-python-error.png)

- **解决办法**
  
  请运行以下命令添加软链接：

  
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  例：

  ![faq-python-add-soft-link](figures/faq-python-add-soft-link.png)


## 编译构建过程中，提示找不到“python3”

- **现象描述**
  
  ![faq-python3-not-found](figures/faq-python3-not-found.png)

- **可能原因**
 
  没有装python3。

- **解决办法**
  
  请使用如下命令安装Python3。

  
  ```
  sudo apt-get install python3.8
  ```


## 安装python3过程中，提示“configure: error: no acceptable C compiler found in $PATH”

- **现象描述**
  
  安装python3过程中出现以下错误：

  
  ```
  configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
  ```

- **可能原因**
  
  环境中未安装“gcc”。

- **解决办法**
  1. 通过命令“apt-get install gcc”在线安装。
  2. 完成后，重新安装python3。


## 安装python3过程中，提示“-bash: make: command not found”

- **现象描述**
  
  安装python3过程中出现以下错误：

  
  ```
  -bash: make: command not found
  ```

- **可能原因**
  
  环境中未安装“make”。

- **解决办法**
  1. 通过命令“apt-get install make”在线安装。
  2. 完成后，重新安装python3。


## 安装python3过程中，提示“No module named '_ctypes'”

- **现象描述**
  
  安装python3过程中出现以下错误：

  
  ```
  ModuleNotFoundError：No module named ‘_ctypes’
  ```

- **可能原因**
  
  环境中未安装“libffi”和“libffi-devel”。

- **解决办法**
  1. 通过命令“apt-get install libffi\* -y”，在线安装。
  2. 完成后，重新安装python3。


## 编译构建过程中，提示“No module named 'Crypto'”

- **现象描述**
  
  编译构建过程中出现以下错误：

  
  ```
  ModuleNotFoundError: No module named 'Crypto'
  ```

- **可能原因**
  
  环境中未安装“Crypto”。

- **解决办法**
  方法1：通过命令“pip3 install Crypto”，在线安装。

  方法2：离线安装。

  通过网页[https://pypi.org/project/pycrypto/#files](https://pypi.org/project/pycrypto/#files)，下载源码。

  ![faq-download-pycrypto](figures/faq-download-pycrypto.png)

  将源码放置在Linux服务器中，解压，并安装“python3 setup.py install”。

  完成上述安装后，重新构建。


## （Hi3861）编译构建过程中，提示“No module named 'ecdsa'”

- **现象描述**
  
  编译构建过程中出现以下错误：

  
  ```
  ModuleNotFoundError：No module named 'ecdsa'
  ```

- **可能原因**
  
  环境中未安装“ecdsa”。

- **解决办法**
  方法1：通过命令“pip3 install ecdsa”，在线安装。

  方法2：离线安装

  通过网页[https://pypi.org/project/ecdsa/#files](https://pypi.org/project/ecdsa/#files)，下载安装包。

  ![faq-download-ecdsa](figures/faq-download-ecdsa.png)

  将安装包放置Linux服务器中，并安装“pip3 install ecdsa-0.15-py2.py3-none-any.whl”。

  完成上述安装后，重新构建。


## （Hi3861）编译构建过程中，提示“Could not find a version that satisfies the requirement six&gt;=1.9.0”

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

  ![faq-download-six](figures/faq-download-six.png)

  将源码放置在Linux服务器中，并安装“pip3 install six-1.14.0-py2.py3-none-any.whl”。

  完成上述安装后，重新构建。


## （Hi3861）编译构建过程中，提示找不到“-lgcc”

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


## （Hi3861）安装kconfiglib时，遇到lsb_release错误

- **现象描述**
  
  安装kconfiglib过程中遇到如下错误打印：

  
  ```
  subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
  ```

- **可能原因**
  
  lsb_release模块基于的python版本与现有python版本不一致。

- **解决办法**
  
  执行"find / -name lsb_release"，找到lsb_release位置并删除，如："sudo rm -rf /usr/bin/lsb_release"。

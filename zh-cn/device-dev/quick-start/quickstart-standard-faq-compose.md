# 编译异常


## Linux编译服务器终端输入不识别的命令时提示“ImportError: No module named apt_pkg”

- **现象描述**
  Linux编译服务器终端输入不识别的命令时，提示"ImportError: No module named apt_pkg"

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
  usr/bin目录下没有python软链接

  ![zh-cn_image_0000001226922322](figures/zh-cn_image_0000001226922322.png)

- **解决办法**
  请运行以下命令添加软链接：

    
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  例：

  ![zh-cn_image_0000001271562453](figures/zh-cn_image_0000001271562453.png)


## 编译构建过程中，提示找不到“python3”

- **现象描述**

  ![zh-cn_image_0000001226602414](figures/zh-cn_image_0000001226602414.png)

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

  ![zh-cn_image_0000001227082334](figures/zh-cn_image_0000001227082334.png)

  将源码放置在Linux服务器中，解压，并安装“python3 setup.py install”。

  完成上述安装后，重新构建。

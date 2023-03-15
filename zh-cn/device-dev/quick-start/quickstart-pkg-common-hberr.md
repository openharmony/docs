# hb安装异常处理


## hb安装过程中出现乱码、段错误

- **现象描述**
  
  执行“python3 -m pip install --user ohos-build”出现乱码、段错误（segmentation fault）。

- **可能原因**
  
  pip版本过低。

- **解决办法**
  
  执行如下命令升级pip。

  
  ```
  python3 -m pip install -U pip
  ```


## hb安装过程中提示"cannot import 'sysconfig' from 'distutils'"

- **现象描述**
  
  执行“python3 -m pip install --user ohos-build”提示"cannot import 'sysconfig' from 'distutils'"

- **可能原因**
  
  缺少distutils模块。

- **解决办法**
  
  执行如下命令安装。

  
  ```
  sudo apt-get install python3.8-distutils
  ```


## hb安装过程中提示"module 'platform' has no attribute 'linux_distribution'"

- **现象描述**

  执行“python3 -m pip install --user ohos-build”提示"module 'platform' has no attribute 'linux_distribution'"

- **可能原因**
  
  python3 pip安装兼容性问题。

- **解决办法**
  
  执行如下命令重新安装pip。

  
  ```
  sudo apt remove python3-pip
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  ```


## hb安装过程中提示"Could not find a version that satisfies the requirement ohos-build"

- **现象描述**

  执行“python3 -m pip install --user ohos-build”提示"Could not find a version that satisfies the requirement ohos-build"

- **可能原因**
  
   可能是网络环境较差导致的安装失败。

- **解决办法**
  1. 请检查网络连接是否正常。如果网络有问题，请修复网络问题后重新安装。
  2. 若网络正常，请尝试指定临时pypi源的方式安装：
     
      ```
      python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
      ```

# 环境搭建常见问题<a name="ZH-CN_TOPIC_0000001215650793"></a>


## 轻量和小型系统<a name="section1742119306399"></a>

### 安装hb过程中，出现乱码、段错误<a name="section36351051193919"></a>

-   **现象描述**

    执行“python3 -m pip install --user ohos-build”出现乱码、段错误（segmentation fault）。


-   **可能原因**

    pip版本过低。

-   **解决办法**

    执行如下命令升级pip。

    ```
    python3 -m pip install -U pip
    ```


### 安装hb过程中，提示"cannot import 'sysconfig' from 'distutils'"<a name="section48221013144011"></a>

-   **现象描述**

    执行“python3 -m pip install --user ohos-build”提示"cannot import 'sysconfig' from 'distutils'"。


-   **可能原因**

    缺少distutils模块。

-   **解决办法**

    执行如下命令安装。

    ```
    sudo apt-get install python3.8-distutils
    ```


### 安装hb过程中，提示"module 'platform' has no attribute 'linux\_distribution'"<a name="section10307193044111"></a>

-   **现象描述**

    执行“python3 -m pip install --user ohos-build”提示"module 'platform' has no attribute 'linux\_distribution'"。


-   **可能原因**

    python3 pip安装兼容性问题。

-   **解决办法**

    执行如下命令重新安装pip。

    ```
    sudo apt remove python3-pip
    curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
    python get-pip.py
    ```


### 安装hb过程中，提示"Could not find a version that satisfies the requirement ohos-build"<a name="section8692735427"></a>

-   **现象描述**

    执行“python3 -m pip install --user ohos-build”提示"Could not find a version that satisfies the requirement ohos-build"


-   **可能原因**

    可能是网络环境较差导致的安装失败。

-   **解决办法**
    1.  请检查网络连接是否正常。如果网络有问题，请修复网络问题后重新安装。
    2.  若网络正常，请尝试指定临时pypi源的方式安装：

        ```
        python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
        ```



### 安装python3过程中，提示“configure: error: no acceptable C compiler found in $PATH”<a name="section870082884217"></a>

-   **现象描述**

    安装python3过程中出现以下错误：

    ```
    configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
    ```

-   **可能原因**

    环境中未安装“gcc”。

-   **解决办法**

    1、通过命令“apt-get install gcc”在线安装。

    2、完成后，重新安装python3。


### 安装python3过程中，提示“-bash: make: command not found”<a name="section198707170455"></a>

-   **现象描述**

    安装python3过程中出现以下错误：

    ```
    -bash: make: command not found
    ```

-   **可能原因**

    环境中未安装“make”。

-   **解决办法**

    1、通过命令“apt-get install make”在线安装。

    2、完成后，重新安装python3。


### 安装python3过程中，提示“zlib not available”<a name="section85401445204518"></a>

-   **现象描述**

    安装python3过程中出现以下错误：

    ```
    zipimport.ZipImportError: can't decompress data; zlib not available
    ```

-   **可能原因**

    环境中未安装“zlib”。

-   **解决办法**

    方法1：通过命令“apt-get install zlib”在线安装。

    方法2：如果软件源中没有该软件，请从“www.zlib.net”下载版本代码，并离线安装。

    ![](figures/download-zlib.png)

    完成下载后，通过以下命令安装：

    ```
    # tar xvf zlib-1.2.11.tar.gz
    # cd zlib-1.2.11
    # ./configure
    # make && make install
    ```

    完成后，重新安装python3。


### 安装python3过程中，提示“No module named '\_ctypes'”<a name="section12202694460"></a>

-   **现象描述**

    安装python3过程中出现以下错误：

    ```
    ModuleNotFoundError：No module named ‘_ctypes’
    ```


-   **可能原因**

    环境中未安装“libffi”和“libffi-devel”。


-   **解决办法**

    1、通过命令“apt-get install libffi\* -y”，在线安装。

    2、完成后，重新安装python3。


### 安装 kconfiglib时，遇到lsb\_release错误<a name="section5803174135115"></a>

-   **现象描述**

    安装kconfiglib过程中遇到如下错误打印：

    ```
    subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
    ```

-   **可能原因**

    lsb\_release模块基于的python版本与现有python版本不一致

-   **解决办法**

    执行"find / -name lsb\_release"，找到lsb\_release位置并删除，如："sudo rm -rf /usr/bin/lsb\_release"


### Linux编译服务器终端输入不识别的命令时提示“ImportError: No module named apt\_pkg”<a name="section510820516515"></a>

-   **现象描述**

    Linux编译服务器终端输入不识别的命令时，提示"ImportError: No module named apt\_pkg"


-   **可能原因**

    python3 apt安装兼容性问题。

-   **解决办法**

    执行如下命令重新安装python3-apt。

    ```
    sudo apt-get remove  python3-apt
    sudo apt-get install python3-apt
    ```



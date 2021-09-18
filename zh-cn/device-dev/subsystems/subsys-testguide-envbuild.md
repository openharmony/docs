

# 环境配置
## 测试框架基础环境依赖

|环境依赖|操作系统|Linux系统扩展组件|python|python插件|NFS Server|HDC|
|------------|------------|------------|------------|------------|------------|------------|
|版本型号|Ubuntu18.04及以上|libreadline-dev|3.7.5版本及以上|pyserial 3.3及以上、paramiko2.7.1及以上、setuptools40.8.0及以上、rsa4.0及以上|haneWIN NFS Server 1.2.50及以上或者 NFSSv4及以上|  1.1.0版本及以上  |
|详细说明|代码编译环境|命令行读取插件|测试框架语言 |pyserial：支持python的串口通信；paramiko：支持python使用SSH协议；setuptools：支持python方便创建和分发python包；rsa：支持python rsa加密   |支持设备通过串口连接| 支持设备通过HDC连接 |

## 安装流程
1. 安装Linux扩展组件readline，安装命令如下：
    ```
    sudo apt-get install libreadline-dev
    ```
    安装成功提示如下：
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    libreadline-dev is already the newest version (7.0-3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```
2. 安装setuptools插件，安装命令如下：
    ```
    pip3 install setuptools
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```
3. 安装paramiko插件，安装命令如下：
    ```
    pip3 install paramiko
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```
4. 安装python的rsa插件，安装命令如下：
    ```
    pip3 install rsa
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```
5. 安装串口插件pyserial，安装命令如下：
    ```
    pip3 install pyserial
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```
6. 如果设备仅支持串口输出测试结果，则需要安装NFS Server
    - Windows环境下安装，例如安装haneWIN NFS Server1.2.50。
    - Linux环境下安装，安装命令如下：
    ```
    sudo apt install nfs-kernel-server
    ```
    安装成功提示如下：
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    nfs-kernel-server is already the newest version (1:1.3.4-2.1ubuntu5.3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```
7. 如果设备支持HDC连接，则需要安装HDC工具，安装流程请参考如下链接

    https://gitee.com/openharmony/developtools_hdc_standard/blob/master/README_zh.md

## 安装环境检查

| 检查项 |操作  |满足环境  |
| --- | --- | --- |
| 检查python安装成功 |命令行窗口执行命令：python --version  |版本不小于3.7.5即可 |
| 检查python扩展插件安装成功 |打开test/xdevice目录，执行run.bat或run.sh| 可进入提示符“>>>”界面即可 |
|检查NFS Server启动状态（被测设备仅支持串口时检测）  |通过串口登录开发板，执行mount命令挂载NFS  |可正常挂载文件目录即可  |
|检查HDC安装成功  |命令行窗口执行命令：hdc_std -v |版本不小于1.1.0即可 |

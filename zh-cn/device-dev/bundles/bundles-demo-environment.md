# 编译环境准备<a name="ZH-CN_TOPIC_0000001071315859"></a>

-   [linux服务器](#section20979554791)
-   [安装Node.js](#section9954105413153)
-   [安装HPM命令行工具](#section15937194904819)
-   [安装python环境](#section1621819180417)
-   [安装文件打包工具](#section77617165913)
-   [安装SCons](#section873135716233)

![](figure/3516dv300.png)

## linux服务器<a name="section20979554791"></a>

准备一台装有Ubuntu 16.04 及以上 64 位系统的linux服务器（当前未完全支持window环境下的编译）。

将linux shell改为bash：

```
ls -l $(which sh)
# 如果指向的不是bash，则按以下方式修改：
# 方法一：执行以下命令，然后选择no
dpkg-reconfigure dash
# 方法二：先删除sh，再重新创建软连接
rm -f /bin/sh
ln -s bash /bin/sh
```

## 安装Node.js<a name="section9954105413153"></a>

推荐安装 Node.js 12.x （包含 npm 6.14.4）或更高版本（推荐 12.13.0+）：

```
sudo apt-get install nodejs
sudo apt-get install npm
```

查看版本：

```
node --version  # 查看nodejs版本
npm --version   # 查看npm版本
```

## 安装HPM命令行工具<a name="section15937194904819"></a>

通过 Node.js 自带的 npm（使用默认的源 https://registry.npmjs.org/ ）安装 hpm-cli 命令行工具：

```
npm install -g @ohos/hpm-cli
```

安装完hpm-cli命令行工具后，执行以下命令可以查看hpm配置：

```
hpm config
```

上述命令执行后将会显示hpm的默认配置，您可以根据实际情况对默认配置进行修改，以下是hpm的常用配置：

```
registry = https://hpm.harmonyos.com              # hpm注册中心地址，下载组件必须
strictSsl = true                                  # 通过https连接时，是否需要校验证书
http_proxy = http://your-proxy-server:port        # 配置HTTP代理
https_proxy = http://your-proxy-server:port       # 配置HTTPS代理
```

hpm-cli的命令介绍可以参考：[hpm操作命令](oem_bundle_standard_des.md)

## 安装python环境<a name="section1621819180417"></a>

需使用python3.7以上版本，采用以下命令进行安装：

```
sudo apt-get install python3.8
sudo apt-get install python3-pip
sudo pip3 install setuptools
sudo pip3 install kconfiglib  # 建议安装kconfiglib 13.2.0+版本
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>上述方式适用Hi3518和Hi3516两种平台，针对Hi3861平台采用以下方式安装python环境：
>```
>sudo apt-get install python3.8
>sudo apt-get install python3-pip
>sudo pip3 install setuptools
>sudo pip3 install kconfiglib  # 建议安装kconfiglib 13.2.0+版本
>sudo pip3 install pycryptodome
>sudo pip3 install six --upgrade --ignore-installed six
>sudo pip3 install ecdsa
>```

如果当前系统中既存在python2又存在python3，参考以下方法将默认python修改为python3：

```
ll `which python`
rm /usr/bin/python
ln -s python3.8 /usr/bin/python
```

## 安装文件打包工具<a name="section77617165913"></a>

采用以下命令进行安装：

```
which mkfs.vfat  # 如果没找到，执行以下命令安装
sudo apt-get install dosfstools
which mcopy  # 如果没找到，执行以下命令安装
sudo apt-get install mtools
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>Hi3518和Hi3516两种平台需要安装打包工具，Hi3861平台不需要。

## 安装SCons<a name="section873135716233"></a>

1.  打开Linux编译服务器终端。
2.  运行如下命令，安装SCons安装包。

    ```
    python3 -m pip install scons
    ```

3.  运行如下命令，查看是否安装成功。如果安装成功，查询结果下图所示。

    ```
    scons -v
    ```

    **图 1**  SCons安装成功界面，版本要求3.0.4以上<a name="fig235815252492"></a>  
    ![](figure/SCons安装成功界面-版本要求3-0-4以上-27.png "SCons安装成功界面-版本要求3-0-4以上-27")


>![](../public_sys-resources/icon-note.gif) **说明：** 
>Hi3861平台需要安装SCons，Hi3518和Hi3516两种平台不需要。


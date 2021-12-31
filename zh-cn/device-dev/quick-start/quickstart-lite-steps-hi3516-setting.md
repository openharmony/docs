# 安装开发板环境<a name="ZH-CN_TOPIC_0000001216693901"></a>

-   [Hi3516工具要求](#section179175261196)
    -   [硬件要求](#section5840424125014)
    -   [软件要求](#section965634210501)

-   [安装Linux服务器工具](#section182916865219)
    -   [安装编译依赖基础软件（仅Ubuntu 20+需要）](#section45512412251)
    -   [安装文件打包工具及Java虚拟机环境](#section16199102083717)


## Hi3516工具要求<a name="section179175261196"></a>

### 硬件要求<a name="section5840424125014"></a>

-   Hi3516DV300 IoT Camera开发板
-   USB转串口线、网线（Linux工作台通过USB转串口线、网线与Hi3516DV300 开发板连接）

### 软件要求<a name="section965634210501"></a>

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>本节描述安装包方式搭建编译环境的操作步骤。如果使用Docker方式安装编译环境，请跳过此章节，直接从[新建应用程序](quickstart-lite-steps-hi3516-application-framework.md)开始操作。

Hi3516开发板对Linux服务器通用环境配置需要的工具及其用途如下表所示。

**表 1**  Linux服务器开发工具及用途

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="62.4%" id="mcps1.2.3.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>开发工具</p>
</th>
<th class="cellrowborder" valign="top" width="37.6%" id="mcps1.2.3.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>用途</p>
</th>
</tr>
</thead>
<tbody><tr id="row14885193315201"><td class="cellrowborder" valign="top" width="62.4%" headers="mcps1.2.3.1.1 "><p id="p137174662119"><a name="p137174662119"></a><a name="p137174662119"></a>编译基础软件包(仅ubuntu 20+需要)</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.2.3.1.2 "><p id="p258814561424"><a name="p258814561424"></a><a name="p258814561424"></a>编译依赖的基础软件包</p>
</td>
</tr>
<tr id="row52253812238"><td class="cellrowborder" valign="top" width="62.4%" headers="mcps1.2.3.1.1 "><p id="p28007392236"><a name="p28007392236"></a><a name="p28007392236"></a>dosfstools、mtools、mtd-utils</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.2.3.1.2 "><p id="p98008390232"><a name="p98008390232"></a><a name="p98008390232"></a>文件打包工具</p>
</td>
</tr>
<tr id="row29204072315"><td class="cellrowborder" valign="top" width="62.4%" headers="mcps1.2.3.1.1 "><p id="p5921190162318"><a name="p5921190162318"></a><a name="p5921190162318"></a>Java 虚拟机环境</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.2.3.1.2 "><p id="p17921110152311"><a name="p17921110152311"></a><a name="p17921110152311"></a>编译、调试和运行Java程序</p>
</td>
</tr>
</tbody>
</table>

## 安装Linux服务器工具<a name="section182916865219"></a>

### 安装编译依赖基础软件（仅Ubuntu 20+需要）<a name="section45512412251"></a>

执行以下命令进行安装：

```
sudo apt-get install build-essential gcc g++ make zlib* libffi-dev
```

### 安装文件打包工具及Java虚拟机环境<a name="section16199102083717"></a>

运行如下命令，安装dosfstools、mtools、mtd-utils、Java运行时环境（JRE）和Java sdk 开发工具包。

```
sudo apt-get install dosfstools mtools mtd-utils default-jre default-jdk
```


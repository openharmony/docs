# Docker编译环境<a name="ZH-CN_TOPIC_0000001055701144"></a>

## Docker环境介绍<a name="section107932281315"></a>

OpenHarmony为开发者提供了两种Docker环境，以帮助开发者快速完成复杂的开发环境准备工作。两种Docker环境及适用场景如下：

-   独立Docker环境：适用于直接基于Ubuntu、Windows操作系统平台进行版本编译的场景。
-   基于HPM的Docker环境：适用于使用HPM工具进行发行版编译的场景。

**表 1**  Docker镜像介绍

<a name="table11986917191214"></a>
<table><thead align="left"><tr id="row149861417121215"><th class="cellrowborder" valign="top" width="15.831583158315832%" id="mcps1.2.6.1.1"><p id="p798611714124"><a name="p798611714124"></a><a name="p798611714124"></a>Docker环境</p>
</th>
<th class="cellrowborder" valign="top" width="13.97139713971397%" id="mcps1.2.6.1.2"><p id="p1698661751219"><a name="p1698661751219"></a><a name="p1698661751219"></a>系统类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.61186118611861%" id="mcps1.2.6.1.3"><p id="p1798671761217"><a name="p1798671761217"></a><a name="p1798671761217"></a>运行平台</p>
</th>
<th class="cellrowborder" valign="top" width="35.8935893589359%" id="mcps1.2.6.1.4"><p id="p20526205414295"><a name="p20526205414295"></a><a name="p20526205414295"></a>Docker镜像仓库</p>
</th>
<th class="cellrowborder" valign="top" width="15.69156915691569%" id="mcps1.2.6.1.5"><p id="p1833001309"><a name="p1833001309"></a><a name="p1833001309"></a>标签</p>
</th>
</tr>
</thead>
<tbody><tr id="row1798661751216"><td class="cellrowborder" rowspan="2" align="center" valign="top" width="15.831583158315832%" headers="mcps1.2.6.1.1 "><p id="p1898631791213"><a name="p1898631791213"></a><a name="p1898631791213"></a>独立 Docker环境</p>
</td>
<td class="cellrowborder" valign="top" width="13.97139713971397%" headers="mcps1.2.6.1.2 "><p id="p1598617177128"><a name="p1598617177128"></a><a name="p1598617177128"></a>轻量和小型系统</p>
</td>
<td class="cellrowborder" valign="top" width="18.61186118611861%" headers="mcps1.2.6.1.3 "><p id="p898614178122"><a name="p898614178122"></a><a name="p898614178122"></a>Ubuntu/Windows</p>
</td>
<td class="cellrowborder" valign="top" width="35.8935893589359%" headers="mcps1.2.6.1.4 "><p id="p12667431305"><a name="p12667431305"></a><a name="p12667431305"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
</td>
<td class="cellrowborder" valign="top" width="15.69156915691569%" headers="mcps1.2.6.1.5 "><p id="p143320173017"><a name="p143320173017"></a><a name="p143320173017"></a>1.0.0</p>
</td>
<tr id="row5986201731214"><td class="cellrowborder" align="center" valign="top" width="15.831583158315832%" headers="mcps1.2.6.1.1 "><p id="p136981216143"><a name="p136981216143"></a><a name="p136981216143"></a>HPM Docker环境</p>
</td>
<td class="cellrowborder" valign="top" width="13.97139713971397%" headers="mcps1.2.6.1.2 "><p id="p969831161416"><a name="p969831161416"></a><a name="p969831161416"></a>轻量和小型系统</p>
</td>
<td class="cellrowborder" valign="top" width="18.61186118611861%" headers="mcps1.2.6.1.3 "><p id="p18821161052214"><a name="p18821161052214"></a><a name="p18821161052214"></a>Ubuntu/Windows</p>
</td>
<td class="cellrowborder" valign="top" width="35.8935893589359%" headers="mcps1.2.6.1.4 "><p id="p1652616548294"><a name="p1652616548294"></a><a name="p1652616548294"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
</td>
<td class="cellrowborder" valign="top" width="15.69156915691569%" headers="mcps1.2.6.1.5 "><p id="p1433130173010"><a name="p1433130173010"></a><a name="p1433130173010"></a>0.0.3</p>
</td>
</tr>
</tbody>
</table>








## 环境准备<a name="section7337134183512"></a>

在使用docker环境前需要先完成以下操作：

1.  安装Docker，Docker安装请参考[官方指导](https://docs.docker.com/engine/install/)。
2.  获取OpenHarmony源码，请参考[获取源码](sourcecode-acquire.md)。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >HPM Docker环境无需单独获取源码。


## 独立Docker环境<a name="section2858536103611"></a>

OpenHarmony的Docker镜像托管在[HuaweiCloud SWR](https://console.huaweicloud.com/swr/?region=cn-south-1#/app/warehouse/warehouseMangeDetail/goldensir/openharmony-docker/openharmony-docker?type=ownImage)上。开发者可以通过该镜像在很大程度上简化编译前的环境配置。下文将介绍具体使用步骤。

### 搭建Docker环境-轻量系统类设备（参考内存≥128KB）和小型系统类设备（参考内存≥1MB）<a name="section319412277287"></a>

1.  获取Docker镜像。

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```

2.  进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。

    ubuntu下执行：

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```

    windows下执行（假设源码目录为D:\\OpenHarmony）：

    ```
    docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```


### 编译源码-轻量系统类设备（参考内存≥128KB）和小型系统类设备（参考内存≥1MB）<a name="section631485163615"></a>

通过如下编译脚本启动轻量系统类设备（参考内存≥128KB）和小型系统类设备（参考内存≥1MB）的编译。下文以Hi3516平台为例说明具体编译步骤。

设置编译路径，选择当前路径。

```
hb set
```

**图 1**  设置编译界面<a name="fig7947145854013"></a>  
![](figure/设置编译界面.png "设置编译界面")

>![](../public_sys-resources/icon-note.gif) **说明：** 
>当前开发板平台和编译界面的对应关系如下：
>-   Hi3861：wifiiot\_hispark\_pegasus@hisilicon
>-   Hi3516：ipcamera\_hispark\_taurus@hisilicon
>-   Hi3518：ipcamera\_hispark\_aries@hisilicon

1.  选择ipcamera\_hispark\_taurus@hisilicon并回车。
2.  执行编译。

    ```
    hb build -f
    ```

3.  查看编译结果。

    编译结果文件生成在out/hispark\_taurus/ipcamera\_hispark\_taurus目录下。


### 搭建Docker环境-标准系统类设备（参考内存≥128MB）<a name="section13585262391"></a>

1.  获取Docker镜像。

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```

2.  进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:1.0.0
    ```


### 编译源码-标准系统类设备（参考内存≥128MB）<a name="section193711513406"></a>

通过如下编译脚本启动标准系统类设备（参考内存≥128MB）的编译。

```
./build.sh --product-name {product_name} --ccache
```

\{product\_name\}为当前版本支持的平台。比如：Hi3516DV300和rk3568等。

编译所生成的文件都归档在out/{device_name}/目录下，结果镜像输出在 out/{device_name}/packages/phone/images/ 目录下。


>![](../public_sys-resources/icon-note.gif) **说明：** 
>退出Docker执行exit命令即可。

## 基于HPM的Docker环境<a name="section485713518337"></a>

docker\_dist是一个[HPM](https://hpm.harmonyos.com/)系统中的模板组件，能够帮助用户快速初始化HPM工程，利用docker镜像来快速编译OpenHarmony发行版，在很大程度上简化了编译前的环境配置。开发者在配置好Ubuntu和[hpm-cli](../hpm-part/hpm-part-development.md)开发环境后，可以通过以下步骤来使用我们提供的Docker环境。

### 搭建Docker环境<a name="section3295842510"></a>

1.  初始化安装模板。在任意工作目录中执行以下命令。

    ```
    hpm init -t @ohos/docker_dist
    ```

2.  修改publishAs。

    因为获取到的是模板类型的包，要把包的类型改为需要的类型。 在当前目录下打开bundle.json文件，把"publishAs"字段的值由"template"改为"distribution"。


### 获取及编译源码<a name="section69141039143518"></a>

执行编译。自动安装docker只能在Ubuntu环境下执行，如果其他环境，需要用户自行安装docker，然后拉取镜像，执行编译。

-   **自动安装docker（Ubuntu环境）**

    以下命令可以帮助用户自动安装docker, 拉取镜像，并且在容器中开始运行对应解决方案的拉取和编译。

    **方式一：**

    命令后接参数指定解决方案，格式如下：

    ```
    hpm run docker solution={product}
    ```

    \{product\}为需编译的解决方案，如：@ohos/hispark\_taurus、@ohos/hispark\_aries、@ohos/hispark\_pegasus。

    **方式二：**

    设置环境变量来选择解决方案，再执行编译命令。

    1.  选择解决方案。

        ```
        export solution={product}
        ```

        \{product\}为需编译的解决方案，如：@ohos/hispark\_taurus、@ohos/hispark\_aries、@ohos/hispark\_pegasus。

    2.  获取源码及执行编译。

        ```
        hpm run docker
        ```

    以上两种方式以@ohos/hispark\_taurus为例，执行成功结果如下：

    ```
    ......
    ohos ipcamera_hispark_taurus build success!
    @ohos/hispark_taurus: distribution building completed.
    ```


-   **自行安装docker（非Ubuntu环境）**

    自行安装docker相关操作如下：

    ```
    # 拉取镜像 
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3# linux环境下的编译 
    hpm run distWithDocker solution={product}
    # windows下的编译，需要配置gitbash 
    hpm config set shellPath "gitbash路径"
    hpm run distWithDocker solution={product}
    ```


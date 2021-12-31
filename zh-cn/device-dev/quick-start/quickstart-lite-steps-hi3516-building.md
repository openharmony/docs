# 编译<a name="ZH-CN_TOPIC_0000001171615520"></a>

下方将介绍如何使用Hi3516开发板进行编译。使用安装包方式与docker方式搭建Ubuntu编译环境，编译步骤相同。

1.  请进入源码根目录，执行如下命令进行编译：

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果使用Docker方式搭建编译环境，请在[获取Docker环境](quickstart-lite-docker-environment.md#section15666113905015)中进入的Docker构建环境中，执行如下命令进行编译。

    ```
    hb set(设置编译路径)
    .（选择当前路径）
    选择ipcamera_hispark_taurus并回车
    hb build -f（执行编译）
    ```

    **图 1**  Hi3516编译设置图例-Docker方式<a name="fig1355483082115"></a>  
    ![](figures/Hi3516编译设置图例-Docker方式.png "Hi3516编译设置图例-Docker方式")

2.  编译结束后，出现“ipcamera\_hispark\_taurus build success”字样，则证明构建成功。

    >![](../public_sys-resources/icon-notice.gif) **须知：** 
    >烧录相关文件获取路径：
    >结果文件：out/hispark\_taurus/ipcamera\_hispark\_taurus。
    >U-boot文件：device/hisilicon/hispark\_taurus/sdk\_liteos/uboot/out/boot/u-boot-hi3516dv300.bin。



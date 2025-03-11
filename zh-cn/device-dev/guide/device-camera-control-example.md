# 应用实例<a name="ZH-CN_TOPIC_0000001055301733"></a>

本示例将运行源码中的camera示例代码，通过本示例可以实现使用开发板进行拍照、录像及预览等功能。

-   本示例源码路径为“applications/sample/camera/media/camera\_sample.cpp”。
-   在运行本示例前需先完成编译烧录、运行镜像等步骤，相关操作请参考[小型系统快速入门](../quick-start/quickstart-overview.md)。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >开发板启动后默认会加载launcher应用，应用的图形界面默认显示在媒体图层上方，会影响camera\_sample的演示结果，因此需要在编译或是打包时去掉launcher应用。
    >**修改方法**：将“build/lite/components/applications.json”中camera\_sample\_app组件的targets中"//applications/sample/camera/launcher:launcher\_hap"整行注释或删除。

-   本示例编译结果路径为“out/hi3516dv300/ipcamera\_hi3516dv300\_liteos/dev\_tools/bin”，为让文件能在单板中执行，可将示例文件通过读卡器复制至TF卡中，或者修改camera\_sample的编译脚本将结果文件复制至rootfs.img中。

    修改源码路径“applications/sample/camera/media/BUILD.gn”中第一处的output\_dir。

    -   修改前：output\_dir = "$root\_out\_dir/dev\_ools"
    -   修改后：output\_dir = "$root\_out\_dir/"

    重新执行源码仓编译并烧写入单板后，可在单板bin目录下找到camera\_sample文件。

    >![](../public_sys-resources/icon-notice.gif) **须知：** 
    >实例运行拍照和录像功能需要插入TF卡\(最大容量支持128GB\)，系统启动后自动将TF卡挂载至/sdcard目录，如果在启动后插入则需要手动挂载。查看拍照和录像内容可将TF卡中内容复制到电脑中进行查看，预览功能无需TF卡。

-   接下来可通过以下步骤运行示例：

1.  通过cd命令进入可执行程序的末端路径，启动camera\_sample，执行命令如下图。

    **图 1**  启动示例<a name="fig380985885020"></a>  
    ![](figures/启动示例.png "启动示例")

    运行后的控制命令如串口打印所示，按s键停止当前操作（包括录像和预览），按q键退出示例程序。

2.  按1进行拍照，拍照的文件格式为jpg，存储在/sdcard，文件名Capture\*。

    **图 2**  输入拍照指令后串口打印日志<a name="fig17819185018384"></a>  
    ![](figures/输入拍照指令后串口打印日志.png "输入拍照指令后串口打印日志")

    若想查看保存文件，可在退出程序后进入文件系统查看，退出后重新进入请回到步骤1。

    **图 3**  查看文件图<a name="fig166391743154619"></a>  
    ![](figures/查看文件图.png "查看文件图")

3.  按2进行录像，录像的文件格式为mp4，存储在/sdcard，文件名Record\*，按s键停止。

    **图 4**  输入录像指令后串口打印日志<a name="fig6340814174317"></a>  
    ![](figures/输入录像指令后串口打印日志.png "输入录像指令后串口打印日志")

4.  按3进行预览，预览图像直接送至显示屏，按s键停止。

    **图 5**  输入预览指令后串口打印日志<a name="fig9658148124414"></a>  
    ![](figures/输入预览指令后串口打印日志.png "输入预览指令后串口打印日志")

    预览效果如下。

    **图 6**  预览效果<a name="fig24541759597"></a>  
    ![](figures/预览效果.jpg "预览效果")

5.  按q键退出。

    **图 7**  输出退出指令后串口打印日志<a name="fig1755682174514"></a>  
    ![](figures/输出退出指令后串口打印日志.png "输出退出指令后串口打印日志")



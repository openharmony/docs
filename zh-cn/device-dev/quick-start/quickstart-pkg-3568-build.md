# 编译


想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建指南](../subsystems/subsys-build-all.md)。


## 前提条件

- 已正确[安装库和工具集](quickstart-pkg-install-package.md)。

- 已正确[安装编译工具](quickstart-pkg-install-tool.md)。

- “Hello World”程序已编写完成。

- 可正常登录Ubuntu环境。


## 操作步骤

方法一：hb编译(请先[安装编译工具](quickstart-pkg-install-tool.md))

在Ubuntu环境下进入源码根目录，执行如下命令进行编译：

1. 设置编译路径。
   
   ```
   hb set
   ```

2. 选择当前路径。
   
   ```
   .
   ```

3. 在hihope下选择rk3568并回车。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
   > 同样的开发板在适配不同的场景时，要采用的编译形态不同（即此处要选择的product不同），请参考[编译形态整体说明](quickstart-appendix-compiledform.md)。

     **图1** RK3568编译设置图例  
  
   ![quickstart-standard-rk3568-build](figures/quickstart-standard-rk3568-build.png)

4. 默认情况下，编译的是32位系统，若不需要调整，则跳过此步骤。
   
   如需编译为64位系统，请执行如下命令：

   
   ```
   hb build --target-cpu arm64
   ```

5. 执行编译。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > - 单独编译一个部件（例如hello），可使用“hb build -T _目标名称_”进行编译。
   > 
   > - 增量编译整个产品，可使用“hb build”进行编译。
   > 
   > - 完整编译整个产品，可使用“hb build -f”进行编译。
   > 
   > 此处以完整编译整个产品为例进行说明。

   
   ```
   hb build -f
   ```

6. 编译结束后，出现“rk3568 build success”字样，则证明构建成功。
   > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
   > 编译结果文件及编译日志文件获取路径：out/rk3568。

方法二：build.sh脚本编译

build.sh脚本编译方式请参考[使用build.sh脚本编译源码](quickstart-pkg-common-build.md#使用buildsh脚本编译源码)。

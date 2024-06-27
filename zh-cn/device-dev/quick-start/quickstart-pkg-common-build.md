# 使用build.sh脚本编译源码


1. 进入源码根目录，执行如下命令进行版本编译。
   
   >编译32位ARM系统：
   
   ```
   ./build.sh --product-name {product_name} --ccache 
   ```

   >编译64位ARM系统：
   
   ```
   ./build.sh --product-name {product_name} --ccache --target-cpu arm64 
   ```
{product_name}为当前支持的平台，比如rk3568。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > _name_为产品名称，例如Hi3516DV300、rk3568等。

2. 检查编译结果。编译完成后，log中显示如下：
   
   ```
   post_process
   =====build name successful.
   ```

     编译所生成的文件都归档在out/{device_name}/目录下，结果镜像输出在out/{device_name}/packages/phone/images/ 目录下。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 其他模块化编译操作，可参见[编译构建指南](../subsystems/subsys-build-all.md)。

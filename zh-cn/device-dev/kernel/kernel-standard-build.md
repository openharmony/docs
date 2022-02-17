# Linux内核编译与构建指导

- [开发示例1](#开发示例1)

## 开发示例1

以hi3516dv300开源开发板+ubuntu x86主机开发环境为例。


使用工程的全量编译命令，编译生成uImage内核镜像


```
./build.sh --product-name Hi3516DV300              # 编译hi3516dv300镜像
    --build-target build_kernel                    # 编译hi3516dv300的uImage内核镜像
    --gn-args linux_kernel_version=\"linux-5.10\"  # 编译指定内核版本
```

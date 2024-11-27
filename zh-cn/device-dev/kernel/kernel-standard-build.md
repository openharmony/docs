# Linux内核编译与构建指导


 **开发示例** 

以rk3568开源开发板+ubuntu x86主机开发环境为例。


使用工程的全量编译命令，编译生成内核镜像


```bash
./build.sh --product-name rk3568					# 编译rk3568镜像版本。
    --gn-args linux_kernel_version="linux-6.6"		# 编译指定内核版本，可选参数。
													# 注意：目前选用linux内核的平台默认linux-6.6参与编译，
													#       当前rk3568完成了Linux-6inux-6.6内核适配，即构建Linux-66不用指定，构建Linux-5.10版本需要该参数指定内核版本，
													#       其他平台在适配完成前都必须添加该参数，指定Linux-5.10内核参与构建。
```

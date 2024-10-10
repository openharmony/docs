# Compiling and Building the Linux Kernel


 **Example**

The following uses the rk3568 board and Ubuntu x86 server as an example.


Perform a full build for the project to generate the kernel image.


```bash
./build.sh --product-name rk3568					# Build the rk3568 image.
    --gn-args linux_kernel_version="linux-6.6"		# Specify the kernel version, optional parameters.
													# Note: Currently, Boards are built with Linux-6.6,
													#       rk3568 has completed the Linux-6.6 kernel adaptation. Thus building Linux-6.6 need not to specify the kernel version, but building Linux-5.10 need.
													#       Other boards must add this kernel version parameter to build with the Linux-5.10 before the adaptation is completed.
```

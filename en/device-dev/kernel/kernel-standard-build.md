# Compiling and Building the Linux Kernel


 **Example**

The following uses the Hi3516D V300 board and Ubuntu x86 server as an example.


Perform a full build for the project to generate the **uImage** kernel image.


```bash
./build.sh --product-name hispark_taurus_standard  # Build the hispark_taurus_standard image.
    --build-target build_kernel                    # Build the uImage kernel image of hispark_taurus_standard.
    --gn-args linux_kernel_version=\"linux-5.10\"  # Specify the kernel version.
```

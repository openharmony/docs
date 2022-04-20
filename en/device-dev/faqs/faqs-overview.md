# FAQs Overview 


FAQs are used to help developers solve problems frequently encountered during development. They cover a wide range of topics.


## Environment setup


### Mini and Small Systems

- [What should I do if garbled characters and segmentation faults occur during hb installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "module 'platform' has no attribute 'linux_distribution'" is displayed during hb installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "configure: error: no acceptable C compiler found in $PATH" is displayed during Python 3 installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "-bash: make: command not found" is displayed during Python 3 installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "zlib not available" is displayed during Python 3 installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "No module named 'Crypto'" is displayed during the build process?](../faqs/faqs-environment-setup.md)

- [What should I do when an error with lsb_release occurs during kconfiglib installation?](../faqs/faqs-environment-setup.md)

- [What should I do if the message "ImportError: No module named apt_pkg" is displayed during the execution of an unidentifiable command?](../faqs/faqs-environment-setup.md)


## Compilation and Building


### Mini and Small Systems

- ["usr/sbin/ninja: invalid option -- w" Displayed During the Build Process](../faqs/faqs-building.md)

- ["/usr/bin/ld: cannot find -lncurses" Displayed During the Build Process](../faqs/faqs-building.md)

- ["line 77: mcopy: command not found" Displayed During the Build Process](../faqs/faqs-building.md)

- ["riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory" Displayed During the Build Process](../faqs/faqs-building.md)

- ["No module named 'Crypto'" Displayed During the Build Process](../faqs/faqs-building.md)

- ["xx.sh : xx unexpected operator" Displayed During the Build Process](../faqs/faqs-building.md)

- ["Could not find a version that satisfies the requirement six>=1.9.0" Displayed During the Build Process](../faqs/faqs-building.md)

- ["cannot find -lgcc" Displayed During the Build Process](../faqs/faqs-building.md)

- [The Message Indicating Python Cannot Be Found Is Displayed During the Build Process](../faqs/faqs-building.md)

- [The Message Indicating Python 3 Cannot Be Found Is Displayed During the Build Process](../faqs/faqs-building.md)


## Burning


### Mini and Small Systems

- ["Error: Opening COMxx: Access denied" Displayed When I Start Burning](../faqs/faqs-burning.md)

- [The Image Failed To Be Burnt](../faqs/faqs-burning.md)

- [No Command Output Is Displayed](../faqs/faqs-burning.md)

- [Windows-based PC Failed to Be Connected to the Board](../faqs/faqs-burning.md)


## Kernel


### Basic Kernel

- [What are the differences between APIs provided by LiteOS-A and LiteOS-M?](../faqs/faqs-kernel.md)

- [How do I analyze thread stack overflow?](../faqs/faqs-kernel.md)


### File System

- [What should I do when the Hi3516 board fails to open the same file in write mode (LiteOS-A)?](../faqs/faqs-kernel.md)


### Chip Adaptation

- [What hardware platforms are supported by the LiteOS kernel?](../faqs/faqs-kernel.md)

- [What chip architectures are supported by the LiteOS kernel?](../faqs/faqs-kernel.md)


### Third-party Components

- [Which third-party components are supported?](../faqs/faqs-kernel.md)

- [What should I do if the key length verification fails when OpenSSL is used?](../faqs/faqs-kernel.md)

- [Does setsockopt support SO_RCVBUF and SO_SNDBUF?](../faqs/faqs-kernel.md)


### Compilation and Linking

- [How do I run an application developed by ARM Linux on LiteOS-A?](../faqs/faqs-kernel.md)

- [What operating system is used for compilation? What compiler is used?](../faqs/faqs-kernel.md)

- [For a third-party component that is independently compiled into a static library and used on LiteOS-M, what should I do when the component's global variable value is incorrect or the system is suspended after the component's function is called?](../faqs/faqs-kernel.md)

- [What should I do if the message "use VFP register arguments, xxx.o does not" is displayed when LiteOS-A generates a target executable file?](../faqs/faqs-kernel.md)

- [What should I do when calling clock_gettime obtains an incorrect time?](../faqs/faqs-kernel.md)


## Porting

- [How Do I Mount the Heap Memory to the Kernel?](../faqs/faqs-transplant.md)


## Startup and Recovery

- [System Startup Interrupted Due to "parse failed!" Error](../faqs/faqs-startup.md)

- [System Restarted Repeatedly](../faqs/faqs-startup.md)

- [Failed to Call the SetParameter or GetParameter API with Correct Parameter Values](../faqs/faqs-startup.md)


## System Applications


### Utils

- [Failure in running the KV store on the LiteOS-A kernel (Hi3516 or Hi3518) due to incorrect path setting for the KV store](../faqs/faqs-system-applications.md)


### Visual Applications

- [Is there a global variable that can be accessed by all pages?](../faqs/faqs-system-applications.md)

- [How do I obtain DOM elements?](../faqs/faqs-system-applications.md)

- [How do I pass values between pages?](../faqs/faqs-system-applications.md)

- [How do I scroll a list to an item?](../faqs/faqs-system-applications.md)

- [Does the <text> component support multiple lines?](../faqs/faqs-system-applications.md)

- [Why is a component not displayed?](../faqs/faqs-system-applications.md)

- [How do I implement scrolling on a page?](../faqs/faqs-system-applications.md)

- [Why do not the left and top attributes take effect?](../faqs/faqs-system-applications.md)

- [Why does not dynamic binding take effect?](../faqs/faqs-system-applications.md)

- [How do I implement relative and absolute positioning?](../faqs/faqs-system-applications.md)

- [How do I display or hide a component?](../faqs/faqs-system-applications.md)

- [What are the precautions for using the Margin attribute?](../faqs/faqs-system-applications.md)

- [What are the precautions for event subscription?](../faqs/faqs-system-applications.md)

- [What are the precautions for using dynamic binding?](../faqs/faqs-system-applications.md)

- [How does the loop attribute take effect for <swiper>?](../faqs/faqs-system-applications.md)

- [What are the precautions for using an array?](../faqs/faqs-system-applications.md)


### hdc

- [Why does hdc_std fail to connect to a device?](../faqs/faqs-system-applications.md)

- [hdc_std fail to run](../faqs/faqs-system-applications.md)

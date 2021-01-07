# Compilation and Building FAQ<a name="EN-US_TOPIC_0000001060804832"></a>

-   [Invalid -- w option](#section1019152312222)
-   [Ncurses library not found](#section21449422618)
-   [Mcopy not found](#section12477184992615)
-   [No riscv file or directory](#section178451337202716)
-   [No Crypto](#section1241481172819)
-   [Unexpected operator](#section3691222152919)

## Invalid -- w option<a name="section1019152312222"></a>

-   **Problem**

    The compilation fails, and  **usr/sbin/ninja: invalid option -- w**  is displayed.

-   **Cause**

    The Ninja version in the compilation environment is outdated and does not support the   **--w**  option.

-   **Solution**

    Uninstall Ninja and GN and follow the instructions provided in  [Tool Acquisition](../get-code/tool-acquisition.md)  to obtain the provided compilation toolchain.


## Ncurses library not found<a name="section21449422618"></a>

-   **Problem**

    The compilation fails, and  **/usr/bin/ld: cannot find -lncurses**  is displayed.

-   **Cause**

    The ncurses library is not installed.

-   **Solution**

    Run  **sudo apt-get install lib32ncurses5-dev**  to install the library.


## Mcopy not found<a name="section12477184992615"></a>

-   **Problem**

    The compilation fails, and  **line 77: mcopy: command not found**  is displayed.

-   **Cause**

    Mcopy is not installed.

-   **Solution**

    Run  **sudo apt-get install dosfstools mtools**  to install mcopy.


## No riscv file or directory<a name="section178451337202716"></a>

-   **Problem**

    The compilation fails, and  **riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory**  is displayed.

-   **Cause**

    Permission is required to access files in the  **riscv**  compiler path.

-   **Solution**

    Run  **which riscv32-unknown-elf-gcc**  and  **chmod 755**  to modify the permission to access the directory where  **hcc\_riscv32**  is located.


## No Crypto<a name="section1241481172819"></a>

-   **Problem**

    The compilation fails, and  **No module named'Crypto loaded**  is displayed.

-   **Cause**

    Crypto is not installed in Python3.

-   **Solution**

    Run  **python3 --version**  to check the Python version. Ensure that the Python version is 3.7 or later and run  **sudo pip3 install pycryptodome**.


## Unexpected operator<a name="section3691222152919"></a>

-   **Problem**

    The compilation fails, and  **xx.sh \[: xx upexpected operator**  is displayed.

-   **Cause**

    The compilation environment is shell instead of bash.

-   **Solution**

    Run the following commands to switch the compilation environment:

    **sudo rm -rf /bin/sh**

    **sudo ln -s /bin/bash /bin/sh**



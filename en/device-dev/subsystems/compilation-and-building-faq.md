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

    The Ninja version in the compilation environment is outdated and does not support the  **--w**  option.

-   **Solution**

    Uninstall Ninja and GN and follow the instructions provided in  [Acquiring Tools](../get-code/acquiring-tools.md)  to obtain the provided compilation toolchain.


## Ncurses library not found<a name="section21449422618"></a>

-   **Problem**

    The compilation fails, and  **/usr/bin/ld: cannot find -lncurses**  is displayed.

-   **Cause**

    The ncurses library is not installed.

-   **Solution**

    ```
    sudo apt-get install lib32ncurses5-dev
    ```


## Mcopy not found<a name="section12477184992615"></a>

-   **Problem**

    The compilation fails, and  **line 77: mcopy: command not found**  is displayed.

-   **Cause**

    Mcopy is not installed.

-   **Solution**

    ```
    ​sudo apt-get install dosfstools mtools
    ```


## No riscv file or directory<a name="section178451337202716"></a>

-   **Problem**

    The compilation fails, and the following information is displayed:  **riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory**.

-   **Cause**

    Permission is required to access files in the  **riscv**  compiler path.

-   **Solution**
    1.  Run the following command to query the directory where  **gcc\_riscv32**  is located:

        ```
        which riscv32-unknown-elf-gcc
        ```

    2.  Run the  **chmod**  command to change the directory permission to  **755**.


## No Crypto<a name="section1241481172819"></a>

-   **Problem**

    The compilation fails, and  **No module named'Crypto loaded**  is displayed.

-   **Cause**

    Crypto is not installed in Python 3.

-   **Solution**
    1.  Run the following command to query the Python version:

        ```
        python3 --version
        ```

    2.  Ensure that Python 3.7 or later is installed, and then run the following command to install pycryptodome:

        ```
        sudo pip3 install pycryptodome
        ```



## Unexpected operator<a name="section3691222152919"></a>

-   **Problem**

    The compilation fails, and  **xx.sh \[: xx unexpected operator**  is displayed.

-   **Cause**

    The compilation environment is shell instead of bash.

-   **Solution**

    ```
    sudo rm -rf /bin/sh
    sudo ln -s /bin/bash /bin/sh
    ```



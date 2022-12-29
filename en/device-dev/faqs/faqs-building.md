# Compilation and Building


## Mini and Small Systems


### "usr/sbin/ninja: invalid option -- w"

- **Symptom**

  The build fails, and **usr/sbin/ninja: invalid option -- w** is displayed.

- **Possible Causes**

  The Ninja version in use does not support the **--w** option.

- **Solution**

  Uninstall Ninja and GN, and [install Ninja and GN of the required version](../get-code/gettools-ide.md).


### "/usr/bin/ld: cannot find -lncurses"

- **Symptom**
  
  The build fails, and **/usr/bin/ld: cannot find -lncurses** is displayed.

- **Possible Causes**
  
  The ncurses library is not installed.

- **Solution**
  
  ```
  sudo apt-get install lib32ncurses5-dev
  ```


### "line 77: mcopy: command not found"

- **Symptom**

  The build fails, and **line 77: mcopy: command not found** is displayed.

- **Possible Causes**
  
  mcopy is not installed.

- **Solution**
  
  ```
  sudo apt-get install dosfstools mtools
  ```


### "riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory"

- **Symptom**
  
  The build fails, and the following information is displayed: <br>**riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory**

- **Possible Causes**

  You do not have the required permission to access files in the RISC-V compiler directory.

- **Solution**

    1. Run the following command to locate **gcc_riscv32**:
    
     ```
     which riscv32-unknown-elf-gcc
     ```

     
  
  2. Run the **chmod** command to change the directory permission to **755**.


### "No module named 'Crypto'"

- **Symptom**

  The build fails, and **No module named 'Crypto'** is displayed.

- **Possible Causes**

  Crypto is not installed in Python3.

- **Solution**

  1. Run the following command to query the Python version:
     
      ```
      python3 --version
      ```
  2. Ensure that Python 3.7 or later is installed, and then run the following command to install pycryptodome:
     
      ```
      sudo pip3 install pycryptodome
      ```


### "xx.sh: xx unexpected operator"

- **Symptom**

  The build fails, and **xx.sh [: xx unexpected operator** is displayed.

- **Possible Causes**

  The build environment shell is not bash.

- **Solution**
  
  ```
  sudo rm -rf /bin/sh
  sudo ln -s /bin/bash /bin/sh
  ```


### "Could not find a version that satisfies the requirement six&gt;=1.9.0"

- **Symptom**

  The following information is displayed during the build process:

  
  ```
  Could not find a version that satisfies the requirement six>=1.9.0
  ```

- **Possible Causes**

  **six** is not installed.

- **Solution**

  Method 1: Run the **pip3 install six** command to install **six** online.

  Method 2: Install **six** offline.

  1. Download the installation package from [PyPI](https://pypi.org/project/six/#files).

  
  ![](figures/en-us_image_0000001251276115.png)
  
  2. Save the source code to the Linux server and run the **pip3 install six-1.14.0-py2.py3-none-any.whl** command to install **six**.
  
  3. Start the build again.


### "cannot find -lgcc"

- **Symptom**

  The following information is displayed during the build process:

  
  ```
  riscv32-unknown-elf-ld: cannot find -lgcc
  ```

- **Possible Causes**

  The gcc_riscv32 path is incorrectly set as follows. There is an extra slash (/) after **bin**.

  
  ```
  ~/gcc_riscv32/bin/:/data/toolchain/
  ```

- **Solution**

  Modify the gcc_riscv32 path as follows:

  
  ```
  ~/gcc_riscv32/bin:/data/toolchain/
  ```


### Failed to Find Python

- **Symptom**

  The following information is displayed during the build process:

  
  ```
  -bash: /usr/bin/python: No such file or directory
  ```

- **Possible Cause 1**

  Python is not installed.

- **Solution**

  Run the following command to install Python. The following uses Python 3.8 as an example.

  
  ```
  sudo apt-get install python3.8
  ```

- **Possible Cause 2**

  The soft link to Python does not exist in the **usr/bin** directory.

  ![](figures/en-us_image_0000001243200677.png)

- **Solution**

  Run the following commands to add the soft link to Python:

  
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  Example:

  ![](figures/en-us_image_0000001243320787.png)


### Failed to Find Python3

- **Symptom**

  ![](figures/en-us_image_0000001251276255.png)

- **Possible Causes**

  Python 3 is not installed.

- **Solution**

  Run the following command to install Python 3:

  
  ```
  sudo apt-get install python3.8
  ```

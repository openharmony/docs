# Fixing Compilation Issues


## What should I do if the message "ImportError: No module named apt_pkg" is displayed during the execution of an unidentifiable command?

- **Symptom**

  The message "ImportError: No module named apt_pkg" is displayed when an unidentifiable command is executed on the Linux server.

- **Possible Causes**

  There is a compatibility issue of python3-apt.

- **Solution**

  Reinstall python3-apt.

  
  ```
  sudo apt-get remove  python3-apt
  sudo apt-get install python3-apt
  ```


## What should I do if the message indicating Python cannot be found is displayed during compilation and building?

- **Symptom**

  The following error occurs during compilation and building:

  
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

  The soft link that points to the Python does not exist in the **usr/bin** directory.

  ![en-us_image_0000001271354745](figures/en-us_image_0000001271354745.png)

- **Solution**

  Run the following commands to add a soft link:

  
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  Example:

  ![en-us_image_0000001227114636](figures/en-us_image_0000001227114636.png)


## What should I do if the message indicating Python 3 cannot be found is displayed during compilation and building?

- **Symptom**

  ![en-us_image_0000001227114640](figures/en-us_image_0000001227114640.png)

- **Possible Causes**

  Python 3 is not installed.

- **Solution**

  Run the following command to install Python 3:

  
  ```
  sudo apt-get install python3.8
  ```


## What should I do if the message "configure: error: no acceptable C compiler found in $PATH" is displayed during Python 3 installation?

- **Symptom**

  The following error occurs during Python 3 installation:

  
  ```
  configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
  ```

- **Possible Causes**

  **gcc** is not installed.

- **Solution**

  1. Run the **apt-get install gcc** command to install **gcc** online.
  2. After the installation, reinstall Python 3.


## What should I do if the message "-bash: make: command not found is displayed" during Python 3 installation?

- **Symptom**

  The following error occurs during Python 3 installation:

  
  ```
  -bash: make: command not found
  ```

- **Possible Causes**

  Make is not installed.

- **Solution**

  1. Run the **apt-get install make** command to install Make online.
  2. After the installation, reinstall Python 3.


## What should I do if the message "No module named '_ctypes'" is displayed during Python 3 installation?

- **Symptom**

  The following error occurs during Python 3 installation:

  
  ```
  ModuleNotFoundError: No module named '_ctypes'
  ```

- **Possible Causes**

  **libffi** and **libffi-devel** are not installed.

- **Solution**

  1. Run the **apt-get install libffi* -y** command to install **libffi** and **libffi-devel** online.
  2. After the installation, reinstall Python 3.


## What should I do if the message "No module named 'Crypto'" is displayed during the build process?

- **Symptom**

  The following error occurs during compilation and building:

  
  ```
  ModuleNotFoundError: No module named 'Crypto'
  ```

- **Possible Causes**

  **Crypto** is not installed.

- **Solution**

  Solution 1: Run the **pip3 install Crypto** command to install **Crypto** online.

  Method 2: Offline installation

  Download the source code from [PyPI](https://pypi.org/project/pycrypto/#files).

  ![en-us_image_0000001226794696](figures/en-us_image_0000001226794696.png)

  Save the source package to the Linux server, decompress the package, and run the **python3 setup.py install** command to install Crypto.

  After the preceding installation is complete, rebuild an environment.


## What should I do if the message "No module named 'ecdsa'" is displayed during the build process? (Hi3861)

- **Symptom**

  The following error occurs during compilation and building:

  
  ```
  ModuleNotFoundError: No module named 'ecdsa'
  ```

- **Possible Causes**

  **ecdsa** is not installed.

- **Solution**

  Solution 1: Run the **pip3 install ecdsa** command to install **ecdsa** online.

  Method 2: Offline installation

  Download the installation package from [PyPI](https://pypi.org/project/ecdsa/#files).

  ![en-us_image_0000001271594753](figures/en-us_image_0000001271594753.png)

  Save the installation package to the Linux server and run the **pip3 install ecdsa-0.15-py2.py3-none-any.whl** command to install ecdsa.

  After the preceding installation is complete, rebuild an environment.


## What should I do if the message "Could not find a version that satisfies the requirement six>=1.9.0" is displayed during the build process? (Hi3861)

- **Symptom**

  The following error occurs during compilation and building:

  
  ```
  Could not find a version that satisfies the requirement six>=1.9.0
  ```

- **Possible Causes**

  **six** is not installed.

- **Solution**

  Solution 1: Run the **pip3 install six** command to install **six** online.

  Method 2: Offline installation

  Download the installation package from [PyPI](https://pypi.org/project/six/#files).

  ![en-us_image_0000001271474573](figures/en-us_image_0000001271474573.png)

  Save the source code to the Linux server and run the **pip3 install six-1.14.0-py2.py3-none-any.whl** command to install **six**.

  After the preceding installation is complete, rebuild an environment.


## What should I do if the message "cannot find -lgcc" is displayed during the build process? (Hi3861)

- **Symptom**

  The following error occurs during compilation and building:

  
  ```
  riscv32-unknown-elf-ld: cannot find -lgcc
  ```

- **Possible Causes**

  The PATH is incorrectly written by **gcc_riscv32**. There is an extra slash (/).

  
  ```
  ~/gcc_riscv32/bin/:/data/toolchain/
  ```

- **Solution**

  Modify the PATH by deleting the slash (/).

  
  ```
  ~/gcc_riscv32/bin:/data/toolchain/
  ```


## What should I do if an lsb_release error occurs during kconfiglib installation? (Hi3861)

- **Symptom**

  The following error occurs during **kconfiglib** installation:

  
  ```
  subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
  ```

- **Possible Causes**

  The Python version matched with the **lsb_release** module is different from the current Python version.

- **Solution**

  Run the **find / -name lsb_release** command, for example, **sudo rm -rf /usr/bin/lsb_release** to locate and delete **lsb_release**.

# Fixing hb Installation Errors


## Garbled characters and segmentation faults occur during hb installation

- **Symptom**
  
  During the execution of **python3 -m pip install --user ohos-build**, garbled characters and segmentation faults occur..

- **Possible Causes**
  
  The pip version does not meet requirements. 

- **Solution**
  
  Run the following command to upgrade pip:

  
  ```
  python3 -m pip install -U pip
  ```


## "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation

- **Symptom**
  
  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>cannot import 'sysconfig' from 'distutils'

- **Possible Causes**
  
  The **distutils** module is unavailable.

- **Solution**
  
  Run the following command to install **distutils**:

  
  ```
  sudo apt-get install python3.8-distutils
  ```


## "module 'platform' has no attribute 'linux_distribution'" is displayed during hb installation

- **Symptom**

  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>module 'platform' has no attribute 'linux_distribution'

- **Possible Causes**
  
  There is a compatibility issue of python3-pip.

- **Solution**
  
  Reinstall pip.

  
  ```
  sudo apt remove python3-pip
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  ```


## "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation

- **Symptom**

  During the execution of **python3 -m pip install --user ohos-build**, the following information is displayed:<br>Could not find a version that satisfies the requirement ohos-build

- **Possible Causes**
  
   The installation fails due to poor network connectivity.

- **Solution**
  1. Ensure that your computer has a good network connection. If the network connection is unstable, rectify the network fault and reinstall hb.
  2. If the network is functional, run the following command to install hb by specifying a temporary PyPI source:
     
      ```
      python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
      ```

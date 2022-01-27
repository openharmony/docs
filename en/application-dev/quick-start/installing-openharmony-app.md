# Installing and Running Your OpenHarmony App



You can install your OpenHarmony app in either of the following methods:


- DevEco Studio: Connect your device where the app is stored to DevEco Studio, and then click ![en-us_image_0000001239855207](figures/en-us_image_0000001239855207.png) to install the app.

- hdc: Run commands to install the app.
  You can manually obtain the hdc tool from the open-source repository. Then, run the tool commands to install an HAP file on the device.

  The tool commands are as follows:

  - App installation
     **install [-r/-d/-g] _package_**

     Example:

     ```
     hdc_std install E:\hwadmin.hap
     ```
  - Log capturing
     **hilog**

     Example:

     ```
     hdc_std hilog
     ```

  For details about how to use hdc and the command format, see [hdc_std Usage Guidelines](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/oem_subsys_toolchain_hdc_guide.md).

# hdc\_std FAQs<a name="EN-US_TOPIC_0000001119447290"></a>

-   [hdc\_std Fails to Connect to a Device](#section1221016541119)
-   [hdc\_std Fails to Run](#section219185710311)

## hdc\_std Fails to Connect to a Device<a name="section1221016541119"></a>

-   **Symptom**

    **\[Empty\]**  is displayed in the output after the  **hdc\_std list targets**  command is run.

-   **Possible Causes and Solutions**
    1.  The device cannot be identified.

        Check whether  **HDC Device**  exists in the universal serial bus device of the device manager. If  **HDC Device**  does not exist, the device cannot be connected. In this case, remove and then insert the device or burn the latest image for the device.

    2.  hdc\_std works improperly.

        Run the  **hdc kill**  or  **hdc start -r**  command to kill or restart the hdc service, and then run the  **hdc list targets**  command to check whether device information is obtained.

        If no device information is obtained, check whether the adb process exists in the task manager. If the adb process exists, kill this process because it may affect the hdc service. After that, run  **hdc kill**  or  **hdc start -r**  and then  **hdc list targets**  again.

    3.  hdc\_std does not match the device.

        If the latest image is burnt for the device, hdc\_std must also be of the latest version. As hdc\_std is updated continuously, obtain hdc\_std of the latest version from the  **developtools\_hdc\_standard**  repository in the  **prebuilt**  directory.



## hdc\_std Fails to Run<a name="section219185710311"></a>

-   **Symptom**

    The  **hdc\_std.exe**  file does not run after being clicked.

-   **Possible Causes and Solutions**

    **hdc\_std.exe**  requires no installation and can be directly used on a disk. It can also be added to environment variables. Open the cmd window and run the  **hdc\_std**  command to use  **hdc\_std.exe**.



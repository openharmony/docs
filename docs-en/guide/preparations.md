# Preparations<a name="EN-US_TOPIC_0000001055087693"></a>

-   [Setting Up the Development Environment](#section1912530122716)
-   [Creating a Project](#section1456035192720)

## Setting Up the Development Environment<a name="section1912530122716"></a>

Download and install DevEco Studio. For details, see the  [HUAWEI DevEco Studio User Guide](https://developer.harmonyos.com/en/docs/documentation/doc-guides/software_install-0000001053582415).

## Creating a Project<a name="section1456035192720"></a>

After DevEco Studio is configured, perform the following steps to create a project. \(The  **smartVision**  project cannot be created by selecting an existing template.\)

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>DevEco Studio of the current version provides only basic development functions. GUI preview on the simulator and code debugging will be supported in the next version.

1.  Start DevEco Studio, choose  **File**  \>  **Project**, select  **Lite Wearable**  for  **Device**  and  **Empty Feature Ability**  for  **Template**, and click  **Next**.

    **Figure  1**  Selecting project template<a name="fig1111842916140"></a>  
    ![](figures/selecting-project-template.png "selecting-project-template")

2.  After the project is created, modify the  **config.json**  file in  **entry**  \>  **src**  \>  **main**.
    1.  Change the value of  **"deviceType"**  to  **"smartVision"**.
    2.  Add the  **"visible"**  attribute to the  **"abilities"**  array and set the attribute value to  **true**.

        ```
        "deviceConfig": {},
        "module": {
            "deviceType": [
                "smartVision" // Set the device type to "smartVision".
            ],
            "distro": {
                "deliveryWithInstall": true,
                "moduleName": "entry",
                "moduleType": "entry"  
             },
             "abilities": [    
                {"name": 
                    "default","icon": 
                    "$media:icon",
                    "label": "airquality",
                    "visible": true, // Add the "visible" attribute and set it to true.
                    "type": "page"    
                }  
            ],
        ```




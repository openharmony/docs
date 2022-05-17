# Vibrator Overview


The vibrator service is built on the native vibrator service, bolstered by the latest capabilities of the vibrator hardware. By innovatively integrating vibration and interaction, the service takes user interaction efficiency and usability to the next level.


## Working Principles

The vibrator is a Misc device that consists of four modules: Vibrator API, Vibrator Framework, Vibrator Service, and HDF layer.

  **Figure 1** Vibrator in Misc devices

![en-us_image_0000001180249428.png](figures/en-us_image_0000001180249428.png)

- Vibrator API: provides basic vibrator APIs, including the APIs for obtaining the vibrator list, querying the vibrator by effect, and triggering and stopping vibration.

- Vibrator Framework: manages the framework layer of the vibrator and communicates with the Misc Device Service.

- Vibrator Service: manages services of vibrators.

- HDF layer: adapts to different devices.


## Constraints

When using a vibrator, you must declare the **ohos.permission.VIBRATE** permission before you can control the vibration effect. The sensitivity level of this permission is **system_grant**.

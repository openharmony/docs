# Vibrator Overview


The vibrator service opens up the latest capabilities of the vibrator hardware to the maximum extent. By expanding the native vibrator service to implement integrated vibration and interaction design, the service delivers an exquisite integrated vibration experience and differentiated experience, and improves user interaction efficiency and usability.


## Working Principles

The vibrator is a Misc device that consists of four modules: Vibrator API, Vibrator Framework, Vibrator Service, and HD_IDL.

  **Figure1** Vibrator in Misc devices
  ![en-us_image_0000001180249428](figures/en-us_image_0000001180249428.png)

- Vibrator API: provides basic vibrator APIs, including the APIs for querying the vibrator list, querying the vibrator by effect, and triggering and stopping vibration.

- Vibrator Framework: manages the framework layer of the vibrator and communicates with the Misc Device Service.

- Vibrator Service: manages services of vibrators.

- HD_IDL: adapts to different devices.


## Constraints

When using a vibrator, you need to declare and obtain the **ohos.permission.VIBRATE** permission first so that you can control the vibration effect.

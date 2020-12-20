# Reverse engineering the notification LED

The leds-qpnp driver performs a pretty wide range of tasks, dealing with flash, WLED (White LEDs aka backlight) and the RGB notification light.

This document focuses on the notification LED, and creating a suitable driver for upstream.

## 1. The current process
Below shows the writes that occur to the PMIC during boot, this data was collected by adding [this commit](https://github.com/calebccff/op6/commit/310ad295625cc2e9b7f369be9cae7e58e87ac388) to the driver.

```
source LED: red,   address: 0xd045, mask: 0x3,  val: 0x1
source LED: red,   address: 0xd047, mask: 0x80, val: 0x80
source LED: green, address: 0xd045, mask: 0x3,  val: 0x1
source LED: green, address: 0xd047, mask: 0x40, val: 0x40
source LED: blue,  address: 0xd045, mask: 0x3,  val: 0x1
source LED: blue,  address: 0xd047, mask: 0x20, val: 0x20
source LED: red,   address: 0xd046, mask: 0x80, val: 0x0
source LED: green, address: 0xd046, mask: 0x40, val: 0x0
source LED: blue,  address: 0xd046, mask: 0x20, val: 0x0
source LED: red,   address: 0xd046, mask: 0x80, val: 0x0
source LED: green, address: 0xd046, mask: 0x40, val: 0x40
source LED: blue,  address: 0xd046, mask: 0x20, val: 0x0
source LED: red,   address: 0xd046, mask: 0x80, val: 0x0
source LED: green, address: 0xd046, mask: 0x40, val: 0x40
source LED: blue,  address: 0xd046, mask: 0x20, val: 0x0
```

Of note, the device was fully charged during this boot, and the green LED turned on and remained on at a fixed brightness.

### So what does that mean?

The `qcom,leds-qpnp` device is defined in DTS as shown below:

```dts
qcom,leds@d000 {
    compatible = "qcom,leds-qpnp";
    reg = <0xd000 0x100>;
    label = "rgb";
    status = "okay";
    
    ...
```
As you can see, the device is located as an offset of `0xd000` from the PMIC. Looking in to the driver we find the following macros:

```c
#define RGB_LED_SRC_SEL(base)		(base + 0x45)
#define RGB_LED_EN_CTL(base)		(base + 0x46)
#define RGB_LED_ATC_CTL(base)		(base + 0x47)
```

As is probably obvious, the address being written to is offset by one of the three addresses defined:

* Source select: 0x45
* Enable <something>: 0x46
* **A**uto **T**rickle **C**harging mode: 0x47

### To summise

- Write a value of 0x01 to SRC_SELect with a mask of 0x03, I believe this selects which PWM device should be used.
- Write a value to ATC, this value seems to depend on the LED colour and is most likely to do with enabling the LED when the device is off but charging, and we do find macros to confirm this:
```c
#define RGB_LED_ENABLE_RED		0x80
#define RGB_LED_ENABLE_GREEN		0x40
#define RGB_LED_ENABLE_BLUE		0x20
```

- Write a value to EN_CTL to enable or disable each LED

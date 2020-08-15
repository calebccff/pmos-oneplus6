# postmarketOS for the OnePlus 6/T

This repo serves as a base for using [my postmarketOS installer](https://gitlab.com/sdm845-mainline/pmtools/-/blob/master/makeinstaller.sh), it's the place to go for releases and to track any issues.

# Instructions

# IMPORTANT

* BEFORE downloading and flashing please get acquinted with [the wiki page](https://wiki.postmarketos.org/wiki/OnePlus_6_(oneplus-enchilada)), specifically note the available features table and the issues section.

**POSTMARKETOS HAS MANY MISSING FEATURES AND IS NOT SUITABLE FOR DAILY USAGE, THIS ZIP IS FOR TESTING/DEVELOPMENT PURPOSES ONLY**

* The battery reporting is broken, do not leave your device unplugged for too long as it will drain the battery and you won't know how much charge is left.

* The device may occasionally boot into crashdump mode shortly after reaching UI, this is a known issue and is most likely caused by some memory being allocated that should be reserved for the modem.

* The display on fajita seems to not turn back on when turned off with the power button, fix in progress

## Download

The latest release will always be available here: https://build.connolly.tech/postmarketOS/Release.

# Install

You can rename the file to pick which slot to flash to, find out your currently active slot by checking the reboot menu in TWRP. It is recommendable to flash to the inactive slot so that you can return to Android by simply switching back. Available slots are: ["a", "b"].

Simply boot into TWRP, flash the zip and reboot, the installer will automatically put you on the right slot and set everything up.

> **PLEASE NOTE:** You can NOT install TWRP or any custom recovery on the slot running postmarketOS, it will not boot due to modifications made by the installer, it will also break postmarketOS.

## PostmarketOS

Currently the postmarketOS on device installer doesn't work on this device, I will hopefully fix this in the future.

For now, the default username is `user` and the default password is `1234`, you can change both of these in settings. Note that you won't be able to unlock the device if you use a non-numeric password.

## Known issues

The gnome software center isn't able to fetch a list of available packages, however it's still possible to search for and install software, e.g. search "2048" for a bit of fun :P

# Switching back
When you're done playing with postmarketOS, switch back to Android by rebooting into bootloader and running the following command:
```
fastboot --set-active=SLOT
```

Where SLOT is the slot with android installed, that will be the opposite slot to the one in the zip file name.

# Creating an issue

If your issue is with software, ie display brightness doesn't work, you must fetch full output logs by running the following command, and attach them to the issue via pastebin or a similar service.

Run the following with your device connected via USB:
```
ssh user@172.16.42.1 dmesg > dmesg.log
```

The command will create a file called `dmesg.log` on your host.

If you have an issue that prevents postmarketOS from booting (nothing appears on your host), please include a detailed description of the problem, if I can't understand or reproduce the problem then I won't be able to help. I may ignore issues that do not meet these requirements.

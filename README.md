# postmarketOS for the OnePlus 6/T

This repo serves as a base for using [my postmarketOS installer](https://gitlab.com/sdm845-mainline/pmtools/-/blob/master/makeinstaller.sh).
Checkout the releases tab for downloads.

# Instructions

# IMPORTANT

* BEFORE downloading and flashing please get acquinted with [the wiki page](https://wiki.postmarketos.org/wiki/OnePlus_6_(oneplus-enchilada)), specifically note the available features table and the issues section.

**POSTMARKETOS HAS MANY MISSING FEATURES AND IS NOT SUITABLE FOR DAILY USAGE, THIS ZIP IS FOR TESTING/DEVELOPMENT PURPOSES ONLY**

* The battery reporting is broken, do not leave your device unplugged for too long as it will drain the battery.

* The device may occasionally boot into crashdump mode shortly before / after recahing UI, this is a known issue.

## Download

Check out the [releases tab](https://github.com/calebccff/pmos-oneplus6/releases).

# Install

You can rename the file to pick which slot to flash to, find out your currently active slot by checking the reboot menu in TWRP. It is recommended to flash to the inactive slot so that you can return to Android by simply switching back. Available slots are: ["a", "b"].

Simply boot into TWRP, flash the zip and reboot, the installer will automatically put you on the right slot and set everything up.

> **PLEASE NOTE:** You can NOT install TWRP or any custom recovery on the slot running postmarketOS, it will not boot due to modifications made by the installer, it will also break postmarketOS.

## Login

Username: `user`<br>
Password: `1234`.

You can change both of these in settings. Note that you won't be able to unlock the device if you use a non-numeric password.

## postmarketOS

In the future, I hope to be able to make use of the postmarketOS setup which will allow you to pick your own username, password etc, however it curently doesn't work due to the nature of how my installer works.

## Known issues

* The gnome software center isn't able to fetch a list of available packages, however it's still possible to search for and install software, e.g. search "2048" for a bit of fun :P

* The keyboard is just the wrong size, I have no idea what causes this and will be looking into a fix. You can try changing the scaling in phosh.

# Switching back
When you're done playing with postmarketOS, switch back to Android by rebooting into bootloader and running the following command:
```
fastboot --set-active=SLOT
```

Where SLOT is the slot with android installed, that will be the opposite slot to the one in the zip file name.

If you wish to keep your postmarketOS install, make sure not to flash any updates from Android as they will overwrite it.

# Creating an issue

If your issue is with software, ie display brightness doesn't work, you must fetch full output logs by running the following command, and attach them to the issue via pastebin or a similar service.

Run the following with your device connected via USB:
```
ssh user@172.16.42.1 dmesg > dmesg.log
```

The command will create a file called `dmesg.log` on your host.

If you have an issue that prevents postmarketOS from booting (nothing appears on your host), please include a detailed description of the problem, if I can't understand or reproduce the problem then I won't be able to help. I may ignore issues that do not meet these requirements.

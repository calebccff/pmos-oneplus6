# postmarketOS for the OnePlus 6/T

[postmarketOS](https://postmarketOS.org) aims to be a completely free and Open Source Linux distro for mobile phones, here I release custom TWRP compatible zips for the OnePlus 6 and 6T to simplify the installation procedure and let you check out Mainline Linux on your phone!

If you want to stay up with the latest development, follow me on Twitter, and join the Discord!

[![Twitter Badge](https://img.shields.io/badge/-Twitter-1ca0f1?style=flat-square&label=%40calebccff&labelColor=1ca0f1&logo=twitter&logoColor=white&link=https://twitter.com/calebccff)](https://twitter.com/calebccff) [![Discord](https://img.shields.io/discord/674261029265604610?label=Discord&style=flat-square&labelColor=7289da)](https://discord.gg/haVG9Ga)

The discord is also bridged [to Telegram](https://t.me/linuxoneplus) and [to Matrix](https://matrix.to/#/#lop-general:connolly.tech).

## Pictures

|<img src="images/appscreen.jpg" width="75%"></img>|<img src="images/neofetch.jpg" width="75%"></img>|
|:--:|:--:|
|*App list*|*Neofetch output*|

# Important Info

BEFORE downloading and flashing please READ THE REST OF THIS README, also acquainted with [the wiki page](https://wiki.postmarketos.org/wiki/OnePlus_6_(oneplus-enchilada)), specifically note the available features table and the issues section.

**These builds are for testing and development and are not expected to be stable**
# Instructions

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

In the future, I hope to be able to make use of the postmarketOS setup which will allow you to pick your own username, password etc, however it curently doesn't support Android devices, we're hoping to change this in the future [(#3)](https://gitlab.com/sdm845-mainline/pmos-installer/-/issues/3).

## Known issues

* The gnome software center isn't able to fetch a list of available packages, however it's still possible to search for and install software, e.g. search "2048" for a bit of fun :P

* The device may occasionally boot into crashdump mode shortly before / after reaching UI, this is a known issue.

# Switching back

When you're done playing with postmarketOS, switch back to Android by rebooting into bootloader and running the following command on your PC:
```
fastboot --set-active=SLOT
```

Where SLOT is the slot with android installed, that will be the opposite slot to the one in the zip file name.

If your Android is **rooted** you can install the [Switch My Slot](https://github.com/gibcheesepuffs/Switch-My-Slot-Android) app to switch to postmarketOS without PC.

If you wish to keep your postmarketOS install, make sure not to flash any updates from Android as they will overwrite it.

# Creating an issue

If your issue is with software, ie display brightness doesn't work, you must fetch full output logs by running the following command, and attach them to the issue via pastebin or a similar service.

Run the following with your device connected via USB:
```
ssh user@172.16.42.1 dmesg > dmesg.log
```

The command will create a file called `dmesg.log` on your host which you should upload to a pastebin service when opening an issue here.

If you have an issue that prevents postmarketOS from booting (nothing appears on your host), please include a detailed description of the problem, if I can't understand or reproduce the problem then I won't be able to help. I may ignore issues that do not meet these requirements.

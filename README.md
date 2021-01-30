# postmarketOS for the OnePlus 6/T

This repo serves as a base for using [my postmarketOS installer](https://gitlab.com/sdm845-mainline/pmtools/-/blob/master/makeinstaller.sh). It is designed to be an easy to use flashable zip to allow people to test out postmarketOS and contribute to userspace development WITHOUT having to have a powerful machine to compile the kernel and build their own image.

If you want to follow along with the development process, <a href="https://twitter.com/calebccff" class="twitter-follow-button" data-show-count="false">Follow @calebccff</a> on Twitter!

You can also [join the Discord server to chat and hang out :D](https://discord.gg/haVG9Ga)


## Pictures

|<img src="images/appscreen.jpg" width="75%"></img>|<img src="images/neofetch.jpg" width="75%"></img>|
|:--:|:--:|
|*App list*|*Neofetch output*|

# Important Info

BEFORE downloading and flashing please get acquainted with [the wiki page](https://wiki.postmarketos.org/wiki/OnePlus_6_(oneplus-enchilada)), specifically note the available features table and the issues section.

**PostmarketOS for this device is missing a lot of important features, this build it meant for testing and development only**
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

In the future, I hope to be able to make use of the postmarketOS setup which will allow you to pick your own username, password etc, however it curently doesn't work due to the nature of how my installer works.

## Known issues

* The gnome software center isn't able to fetch a list of available packages, however it's still possible to search for and install software, e.g. search "2048" for a bit of fun :P

* The device may occasionally boot into crashdump mode shortly before / after reaching UI, this is a known issue.

# Switching back

When you're done playing with postmarketOS, switch back to Android by rebooting into bootloader and running the following command on your PC:
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

The command will create a file called `dmesg.log` on your host which you should upload to a pastebin service when opening an issue here.

If you have an issue that prevents postmarketOS from booting (nothing appears on your host), please include a detailed description of the problem, if I can't understand or reproduce the problem then I won't be able to help. I may ignore issues that do not meet these requirements.

# GIT shit

## Branches:
enchilada-simplefb - initial devicetree added and boots with framebuffer
enchilada-ufs - working on getting ufs based on simplefb

# Device Tree

The `dsi` display notes are configured to use dsi0 and dsi1 for double bandwidth in the mtp device tree.

# Flashing
fastboot boot pmos/linux/kernel-dtb ./pmos/systems/mate/initramfs-oneplus-msm8998 --base 0x0 --page-size 4096

# Building commands

```sh
mkdir -p /tmp/bootimg && cd /tmp/bootimg && unpackbootimg -i ~/.local/var/pmbootstrap/chroot_native/tmp/mainline/boot.img -o . && cp $HOME/pmos/linux/.output/usr/initramfs_data.cpio /tmp/bootimg/ramdisk && mkbootimg --base 0x0 --kernel_offset 0x8000 --ramdisk_offset 0x1000000 --tags_offset 0x100 --pagesize 4096 --second_offset 0xf00000 --kernel boot.img-zImage --ramdisk ramdisk --cmdline "audit=0" -o ~/.local/var/pmbootstrap/chroot_native/tmp/mainline/boot.img && cd - && rm -r /tmp/bootimg
```

```sh
# Compile the kernel
cd ~/pmos/linux
source ~/bin/pmbstrap/helpers/envkernel.sh
make defconfig
make -j13
```

```sh
# Build boot image
export DEVICE="$(pmbootstrap config device)"
export WORK="$(pmbootstrap config work)"
export TEMP="$WORK/chroot_native/tmp/mainline/"
mkdir -p "$TEMP"

cd ~/pmos/linux/.output/arch/arm64/boot
cat Image.gz dts/qcom/sdm845-enchilada.dtb > ~/pmos/linux/.zImage-dtb
cp ~/pmos/linux/.zImage-dtb "$TEMP"/zImage-dtb

#optional - if there's no exported boot image in temp
pmbootstrap export

cp "/tmp/postmarketOS-export/boot.img-$DEVICE" "$TEMP/boot.img"
pmbootstrap chroot

abootimg -u /tmp/mainline/boot.img  -k /tmp/mainline/zImage-dtb
```


Alternate make bootimg:

```sh
pmbootstrap chroot -- mkbootimg-osm0sis \
--kernel "/tmp/mainline/zImage-dtb" \
--ramdisk "/tmp/mainline/initramfs" \
--base "0x80000000" \
--second_offset "0x00f00000" \
--cmdline "console=ttyMSM0 PMOS_NO_OUTPUT_REDIRECT clk_ignore_unused" \
--kernel_offset "0x00008000" \
--ramdisk_offset "0x01000000" \
--tags_offset "0x00000100" \
--pagesize "4096" \
-o "/tmp/mainline/boot.img"
```

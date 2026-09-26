#include <zephyr/dfu/mcuboot.h>
#include <zephyr/kernel.h>

int main(){
    printk("This is the Initial version");
    boot_write_img_confirmed();   
    return 0;
}
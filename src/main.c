#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/dfu/mcuboot.h>

#define APP_VERSION "3.1.0"

int main(void)
{
    printk("\n-------------------------\n");
    printk("Firmware version: %s\n", APP_VERSION);

    if (!boot_is_img_confirmed()) {
        int rc = boot_write_img_confirmed();
        printk("Confirming image: %s (rc=%d)\n", rc == 0 ? "OK" : "FAIL", rc);
    }

    printk("Image confirmed: %s\n", boot_is_img_confirmed() ? "YES" : "NO");

    while (1) {
        printk("[HEARTBEAT] Firmware %s is running\n", APP_VERSION);
        k_sleep(K_SECONDS(5));
    }
    return 0;
}
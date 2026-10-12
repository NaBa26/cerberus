#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/dfu/mcuboot.h>

#define APP_VERSION "3.1.0"

int main(void)
{
    printk("\n-------------------------\n");
    printk("Firmware version: %s\n", APP_VERSION);

    bool confirmed = boot_is_img_confirmed();

    printk("Image confirmed: %s\n",
           confirmed ? "YES" : "NO");

    while (1) {
        printk("[HEARTBEAT] Firmware %s is running\n",
               APP_VERSION);

        k_sleep(K_SECONDS(5));
    }

    return 0;
}

#include <linux/module.h>	 
#include <linux/kernel.h>	 
#include <linux/init.h>	  
#include <linux/acpi.h>
#include <linux/string.h>

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Edson Juliano Drosdeck"); 

MODULE_DESCRIPTION("RFkill to intel bluetooth"); 

MODULE_VERSION("1.0"); 


static int intel_bt_rfkill_add(struct acpi_device *device);
//static int intel_bt_rfkill_remove(struct acpi_device *device, int type);

static const struct acpi_device_id bt_device_ids[] = {
	{ "INT33E3", 0},
	{ "", 0},
};

MODULE_DEVICE_TABLE(acpi, bt_device_ids);


static int intel_bt_rfkill_add(struct acpi_device *device)
{
	return 0;
}

static int intel_bt_rfkill_remove(struct acpi_device *device, int type)
{
	return 0;
}

static struct acpi_driver intel_bt_driver = {
	.name =         "INTEL BT",
	.class =       "INTEL",
       .ids =          bt_device_ids,
	.ops =          {
	 			.add =    intel_bt_rfkill_add,
//				.remove = intel_bt_rfkill_remove,
			},
	.owner =	THIS_MODULE,
	};	



static int __init intel_bt_rfkill_init(void) 
{
	int result;
	result = acpi_bus_register_driver(&intel_bt_driver);
	if (result < 0) {
		ACPI_DEBUG_PRINT((ACPI_DB_ERROR,"Error registering driver\n"));
		return -ENODEV;
	}
	return 0; 
} 

static void __exit intel_bt_rfkill_end(void) 
{ 
} 

module_init(intel_bt_rfkill_init); 
module_exit(intel_bt_rfkill_end); 


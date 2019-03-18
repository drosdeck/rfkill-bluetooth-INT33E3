#include <linux/module.h>	 
#include <linux/kernel.h>	 
#include <linux/init.h>	  
#include <linux/acpi.h>
#include <linux/string.h>

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Edson Juliano Drosdeck"); 

MODULE_DESCRIPTION("RFkill to intel bluetooth"); 

MODULE_VERSION("1.0"); 





static int __init intel_bt_rfkill_init(void) 
{
	return 0; 
} 

static void __exit intel_bt_rfkill_end(void) 
{ 
} 

module_init(intel_bt_rfkill_init); 
module_exit(intel_bt_rfkill_end); 


#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_AUTHOR("I am");

static char* charvar = "module";
static int intvar = 10;

module_param(charvar, charp, S_IRUGO);
module_param(intvar, int, S_IRUGO);

static int __init mod_param_init(void)
{
	printk(KERN_ALERT "\n We are in init function\n");
	printk(KERN_ALERT "\n The value of charvar is %s\n",charvar);
	return 0;
}

static void __exit mod_param_exit(void)
{
	printk(KERN_ALERT "\n GoodBye\n");
}

module_init(mod_param_init);
module_exit(mod_param_exit);

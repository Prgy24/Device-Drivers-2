#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static int Hello_init(void)
{
	printk("\nHello world\n");
	return 0;
}

static void Hello_exit(void)
{
	printk("\nBye world\n");
}

module_init(Hello_init);
module_exit(Hello_exit);


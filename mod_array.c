#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("I AM");

static int arrayparam[3];
static char *chararray;

module_param_array(arrayparam,int,NULL, S_IWUSR | S_IRUSR);
module_param(chararray,charp,S_IWUSR | S_IRUSR);

static int array_init(void)
{

	printk("\nParameter array\n");
	printk("\narray elements are:%d\t%d\t%d\n",arrayparam[0],arrayparam[1],arrayparam[2]);
	printk("\nThe value of character array is:%s\n",chararray);
	return 0;
}

static void array_exit(void)
{
	printk("\nExiting\n");
}

module_init(array_init);
module_exit(array_exit);

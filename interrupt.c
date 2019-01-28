#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/gpio.h>
#include<linux/interrupt.h>
#include<asm-generic/gpio.h>
#include<linux/irqreturn.h>
#include<linux/irq.h>


#define MAJORNO 42
#define NO_MINOR 1
#define SIZE 32
#define GPIO_INT_PIN 115

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PP");


static int irq_num;

	irq_handler_t gpio_handler(int irq, void* dev_id, struct pt_regs *regs)
	{
		printk("\nGot interrupt\n");
		return IRQ_HANDLED;
	}	


static __init int char_dev_init(void)
{
        int ret;

//        devno = MKDEV(MAJORNO,0);

	printk("In init\n");

  /*     ret = register_chrdev_region(devno,NO_MINOR,"testdev");

        if(ret){
                printk("Error registering device number\n");
                return ret;
                }

	printk("Device is registerd successfully\n");
*/
	
			ret = gpio_is_valid(GPIO_INT_PIN);
				if(ret)
				{
					printk("\nInvalid gpio\n");
				}

			ret=gpio_request(GPIO_INT_PIN,"SYS_115");
				if(ret)
				{
					printk("\nError in requesting gpio\n");
				}
				gpio_direction_input(GPIO_INT_PIN);
                               
			ret=gpio_set_debounce(GPIO_INT_PIN,200);
				if(ret)
                                {
                                        printk("\nError in setting debounce\n");
                                }

			irq_num=gpio_to_irq(GPIO_INT_PIN);
				if(irq_num<0)
				{
					printk("\n Error in getting irq number\n");
				}
			ret=request_irq(irq_num,(irq_handler_t) gpio_handler,IRQF_TRIGGER_RISING,"GPIO DEMO",NULL);


        
        return 0;
}


static __exit void char_dev_exit(void){

	printk("In exit\n");
        free_irq(irq_num,NULL);
	gpio_free(GPIO_INT_PIN);
        }

module_init(char_dev_init);
module_exit(char_dev_exit);


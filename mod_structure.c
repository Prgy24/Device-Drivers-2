#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<linux/types.h>
#include<linux/slab.h>

struct cdac{
	char *name;
	char *course;
	int rollno;
	struct list_head list;
	};

static LIST_HEAD(cdac_list);

int simple_init(void)
{
	struct cdac *ptr;
	int i;
	
	for(i=0; i<5; i++)
	{
		struct cdac *person;
		person = kmalloc(sizeof(*person))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _Manager_H_
#define _Manager_H_
typedef struct{
	char name[100];
	char explain[200];
	char weight[20];
	int price;
	int delivery;
}Product;
#endif

int createProduct(Product *s);
int readProduct(Product s);
int updateProduct(Product *s);
int deleteProduct(Product *s);

int selectMenu();

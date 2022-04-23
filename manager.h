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

int readProduct(Product s);
#endif

int listProduct(Product *s, int index);

void saveData(Product *s, int index);
int loadData(Product *s);

void searchProduct(Product *s, int index);
void priceCompare(Product *s, int index);
void locationProduct(Product *s, int index);

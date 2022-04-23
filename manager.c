#include "manager.h"

int listProduct(Product *s, int index){
	printf("\n***************************");			
	for(int i=0; i<index; i++){
		if(s[i].price == -1) continue;
		printf("\n%2d 번째\n", i+1);
		readProduct(s[i]);
	}
	printf("***************************\n");			
}

void saveData(Product *s , int index){
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for(int i=0; i<index; i++){
		if(s[i].price == -1) continue;
		fprintf(fp, "%s %s %s %d %d\n", s[i].name,s[i].explain,s[i].weight,s[i].price,s[i].delivery);
	}
	fclose(fp);
	printf("=>저장됨!\n");
}

int loadData(Product *s){
	int count=0, i=0, enter;
	FILE *fp;
	fp = fopen("product.txt", "rt");

	if(fp==NULL){
		printf("\n=>파일 없음\n");
	return 0;
	}
	else{
		for(; i<100; i++){
			fgets(s[i].name, 100, fp);
			if(feof(fp)) break;
			fscanf(fp, "%d", &enter);
			fgets(s[i].explain, 200, fp);
			fscanf(fp, "%s", s[i].weight);
			fscanf(fp, "%d", &s[i].price);
			fscanf(fp, "%d", &s[i].delivery);
			fscanf(fp, "%d", &enter);
		}
		printf("=> 로딩 성공!\n");
		fclose(fp);
	return i;
	}
}

void searchProduct(Product *s, int index){
	int scnt = 0;
	char search[30];

	getchar();

	printf("검색할 이름? ");
	scanf("%[^\n]s", search);

	for(int i=0; i<index; i++){
		if(s[i].price == -1) continue;
		if(strstr(s[i].name, search)){
			printf("\n%d 번째", i+1);
			readProduct(s[i]);
			scnt++;
		}
	}
	if(scnt==0) printf("\n=> 검색된 데이터 없음!");
		printf("\n");
}

void priceCompare(Product *s, int index){
	int min, max,scntt=0;

	getchar();

	printf("\n최소가격은? : ");
	scanf("%d", &min);
	printf("최대가격은? : ");
	scanf("%d", &max);
	
	for(int i=0; i<index; i++){
		if(s[i].price == -1) continue;
		if(s[i].price >= min && s[i].price <=max ){
			printf("\n%d 번째 ", i+1);
			readProduct(s[i]);
			scntt++;
		}
	}
	if(scntt==0) printf("\n=> 검색된 데이터 없음!");
		printf("\n");
}

void locationProduct(Product *s, int index){
	int scnt = 0;
	char search[30];

	getchar();
	
	#ifdef DEBUG
		printf("\nWarning : 사용자가 상품 설명에 따로 지역을 명시하지 않았을 시에는 지역명이 없을 수 있습니다.\n");
	#endif

	printf("검색할 지역? ");
	scanf("%[^\n]s", search);

	for(int i=0; i<index; i++){
		if(s[i].price == -1) continue;
		if(strstr(s[i].explain, search)){
			printf("\n%d 번째 ", i+1);
			readProduct(s[i]);
			scnt++;
		}
	}
	if(scnt==0) printf("\n=> 검색된 데이터 없음!");
		printf("\n");
}

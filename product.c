#include "product.h"

int selectMenu(){
	int menu;
	printf("\n***제품관리***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 데이터 저장\n");
	printf("6. 제품검색\n");
	printf("7. 가격으로 검색\n");
	printf("8. 지역으로 검색\n");
	printf("0. 종료\n");
	printf("입력하시오 : ");
	scanf("%d", &menu);
	return menu;
}

int readProduct(Product s){
	printf("\n제품명 : %s", s.name);
	printf("제품무게 : %sg\n", s.weight);	
	printf("제품설명 : %s", s.explain);
	printf("제품 가격 : %d\n", s.price);
	if(s.delivery == 1){
		printf("배송방법 : 새벽택배\n");
	}
	else
		printf("배송방법 : 택배배송\n");
	return 1;
}

int createProduct(Product *s){
	getchar();
	printf("\n제품명은? ");
	fgets(s->name, 100, stdin);
	printf("설명은? ");
	fgets(s->explain, 200, stdin);
	printf("무게는? ");
	scanf("%s", s->weight);
	printf("가격은? ");
	scanf("%d", &s->price);
	printf("배송방법? (1:새벽택배/ 2:택배배송)");
	scanf("%d", &s->delivery);
	printf("=> 추가됨!!\n");
	return 1;
}

int updateProduct(Product *s){
	getchar();
	printf("\n새 제품명은? ");
	fgets(s->name, 100, stdin);
	printf("새 설명은? ");
	fgets(s->explain, 200, stdin);
	printf("새 무게는? ");
	scanf("%s", s->weight);
	printf("새 가격은? ");
	scanf("%d", &s->price);
	printf("새 배송방법? (1:새벽택배/ 2:택배배송)");
	scanf("%d", &s->delivery);
	printf("=> 수정됨!!\n");
	return 1;
}

int deleteProduct(Product *s){
	s->name[0] = '\0';
	s->explain[0] = '\0';
	s->weight[0] = '\0';
	s->price = -1;
	s->delivery = -1;
	printf("=> 삭제됨!!\n");
	return 1;
}

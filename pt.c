#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  
#include <stdbool.h>  
int main(){
system("cls");
//int n;
_Bool lev = true;
 typedef struct pNode{
	char a;
	struct pNode *next,*prev;
} pNode;
pNode *cur,*cur2,*head,*top,*p;
p = (pNode*)malloc(sizeof( pNode));
p->prev = NULL;
printf("vvedite vashi slova. TAB + ENTER - vvod zakonchen. ");
scanf("%c",&(p->a));
head = p;
cur = p;
while(lev == true){
p = (pNode*)malloc(sizeof(pNode));
scanf("%c",&(p->a));
p->prev = cur;
cur->next = p;
p->next = NULL;
if(p->a == 9){
	lev = false;
	free(p);
	cur->next =NULL;
}
cur = p;
top = cur;
}

//выведем теперь
cur = head;
int i = 1;
printf("vvedennie slova : \n");
while(cur != NULL){
	printf("%c",cur->a);
	i++;
	cur = cur->next;
}
printf("\n ");
//--------------------------------------------------------УСЛОВИЕ---------------//
// удаление пробелов cпереди------------------------//
cur = head;

while(cur->a == 32){
	cur = cur->next;
	head = cur;
	}

// удаление пробелов лишних-------------------------//

cur = head;
cur2 = cur->next;
while(cur2 != NULL){
	if(cur ->a == 32 && cur2 ->a == 32){
		cur = cur2;
		cur2 = cur2->next;
		cur->prev = cur->prev->prev;
		cur->prev->prev->next = cur;
	} else {cur = cur2;
			cur2 = cur2->next;
		}
}
//выведем после удаления лишних пробелов-----------//
cur = head;
int b = 1;
printf("posle udaleniya probelov : \n");
while(cur != NULL){
	printf("%c",cur->a);
	b++;
	cur = cur->next;
}
printf("\n ");

// УДАЛЕНИЕ КРАЙНИХ СЛОВ---------------------------//

cur = head;
cur2 = top;
int g = 0, q = 0;
while(cur2->a != 32){
	cur2 = cur2->prev;
	top = cur2;
}
while(cur2 != NULL){
	if(cur2->a ==cur->a) g++;
	q++;
	cur = cur->next;
	cur2 = cur2->next;
}
if(g == q){
	cur = cur->next;
	head = cur;
	head->prev = NULL;
	top ->next = NULL;
}


//выведем после удаления крайних слов-----------//
cur = head;
int k = 1;
printf("posle udaleniya krainih slov : \n");
while(cur != NULL){
	printf("%c",cur->a);
	k++;
	cur = cur->next;
}
printf("\n ");

free(p);
system("pause");
	return 0;
}
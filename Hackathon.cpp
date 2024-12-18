#include<stdio.h>
#include<stdlib.h>

//cau truc Node
typedef struct Node{
	int data;
	struct Node* next;
}Node;

//ham tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	return newNode;
}
//them phan tu dau danh sach
void insertToHead(Node** head,int n){
	Node* newNode=createNode(n);
    	newNode->next=*head;
		*head=newNode;
	 printf("Da them %d vao dau danh sach.\n",n);	
}
//them phan tu vao cuoi danh sach
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
	//danh sach rong
	if(*head==NULL){
		*head=newNode;
		return;
	}
	//danh sach khong rong
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newNode;
	 printf("Da them %d vao cuoi danh sach.\n", n);
}
//them phan tu vao vi tri cu the
void insertByPosition(Node** head,int value,int p){
	//tao node can chen
	Node* newNode=createNode(value);
	//position=0
	if(p==0){
		newNode->next=*head;
		*head=newNode;
		return;
	}
	//duyet den truoc vi tri can chen
	Node* tmp=*head;
	for(int i=0;i<p-1&&tmp!=NULL;i++){
		tmp=tmp->next;
	}
	//vi tri chen khong hop le
	if(tmp==NULL){
		printf("Vi tri chen khong hop le\n");
		return;
	}
	//vi tri chen hop le
	newNode->next=tmp->next;
	tmp->next=newNode;
	 printf("Da them %d vao vi tri %d.\n", value,p);
}
//xoa phan tu dau danh sach
void removeAtHead(Node** head){
	//danh sach rong
	if(*head==NULL){
		printf("Danh sach dang rong");
		return;
	}
	//danh sach co node
	Node* tmp=*head;
	*head=(*head)->next;
	free(tmp);
	 printf("Da xoa phan tu dau danh sach\n ");
}
//xoa phan tu cuoi danh sach
void removeAtTail(Node** head){
	//danh sach rong
	if(*head==NULL){
		printf("Danh sach dang rong");
		return;
	}
	//danh sach co node
	Node* tmp=*head;
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	free(tmp->next);
    tmp->next=NULL;
    printf("Da xoa phan tu cuoi danh sach\n ");
}
//xoa phan tu theo gia tri
void removeByValue(Node** head,int value){
	//danh sach rong
	if(*head ==NULL){
		printf("Danh sach rong\n");
		return;
	}
	Node* tmp=*head;
	//gia tri can xoa là node dau tien
	if((*head)->data==value){
		removeAtHead(head);
		return;
	}
	//truong hop khac
	while(tmp->next!=NULL){
		if(tmp->next->data==value){
			Node* x=tmp->next;
			tmp->next=tmp->next->next;
			free(x);
			printf("Da xoa phan tu %d ra khoi danh sach\n ",value);
			return;
		}
		tmp=tmp->next;
	}
	printf("Khong tim duoc phan tu co gia tri %d trong danh sach",value);
}
//in danh sach
void printList(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d->",tmp->data);
		tmp=tmp->next;
	}
	printf("NULL");
}
//tim kiem 
void search(Node** head, int n){
	Node* tmp=*head;
	while(tmp!=NULL){
		if(tmp->data==n){
		    printf("Tim thay gia tri %d trong danh sach\n",n);
			return;	
		}
		tmp=tmp->next;
	}
	printf("Khong tim thay gia tri %d trong danh sach \n",n);
}
//tao menu
void menu(){
	printf("Chon menu\n");
	printf("1.Them phan tu dau danh sach\n");
    printf("2.Them phan tu cuoi danh sach \n");
    printf("3.Chen phan tu vao vi tri cu the\n");
    printf("4.Xoa phan tu dau danh sach\n");
    printf("5.Xoa phan tu cuoi danh sach\n");
    printf("6.Xoa phan tu theo gia tri\n");
    printf("7.Tim kiem phan tu theo gia tri\n");
    printf("8.In danh sach gia tri ra man hinh\n");
    printf("9.Thoat\n");
    printf("Chon chuc nang: ");
}
int main(){
	Node* head=NULL;
		int choice,value,position;
	do{
		menu();
		scanf("%d",&choice);
	   switch(choice){
	   	    case 1:
	   	 	    printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertToHead(&head,value);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertToTail(&head,value);
                break;

            case 3: 
                 printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                 printf("Nhap vi tri can chen: ");
                scanf("%d", &position);
                insertByPosition(&head,value,position);
                break;

            case 4: 
                removeAtHead(&head);
                break;

            case 5: 
                removeAtTail(&head);
                break;
            case 6:
            	printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
            	removeByValue(&head,value);
            	break;
            case 7:
            	printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
            	search(&head,value);
            	break;
            case 8:
            	printList(&head);
            	printf("\n");
            	break;
            case 9: 
                printf("Thoat chuong trinh.\n");
                break;

	   	 default:
	   	 	 printf("Lua chon khong hop le\n");
	   }
	}while(choice!=9);
}

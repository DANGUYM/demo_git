#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct SV
{
	int MSSV;
	char HVT[20];
	char GT[5];
	char DC[20];
	double DTB;
};

struct NODE
{
	SV data;
	NODE* next;
//	NODE *prev;//tam coi no nhu lien ket don, no chi su dung cho dao nguoc thoi!!!
};

struct listNODE
{
	NODE*head;
	NODE*tail;
}ls;

void init(listNODE &ls)
{
	ls.head=ls.tail=NULL;
}

NODE*getNODE(SV sv)
{
	NODE*p=new NODE;
	if(p==NULL)
	{
		return NULL;
	}
	p->data=sv;
	p->next=NULL;
//	p->prev=p->next=NULL;//tam coi no nhu lien ket don, no chi su dung cho dao nguoc thoi!!!
	return p;
}

void addfirst(listNODE &ls, NODE*newNODE)
{
	if(ls.head==NULL) ls.head=ls.tail=newNODE;
	else
	{
		newNODE->next=ls.head;
		ls.head=newNODE;	
	}
}

void addlast(listNODE &ls, NODE*newNODE)
{
	if(ls.head==NULL)
	{
		ls.head=newNODE;
		ls.tail=ls.head;
	}
	else
	{
		ls.tail->next=newNODE;
		ls.tail=newNODE;
	}
}

void addfirstSV(listNODE &ls,SV &sv)
{
	NODE*p=getNODE(sv);
	if(p==NULL)
	{
		return;
	}
	addfirst(ls,p);
}

void addlastSV(listNODE &ls,SV &sv)
{
	NODE*p=getNODE(sv);
	if(p==NULL)
	{
		return;
	}
	addlast(ls,p);
}

void addoneSV(SV &sv)
{ 
	do{
		cout << "nhap ma so sinh vien: ";
		cin >> sv.MSSV;
	}while(sv.MSSV<0);
		cout << "nhap ho ten sinh vien: ";
		fflush(stdin);
		gets(sv.HVT);
		cout << "nhap gioi tinh sinh vien: ";
		fflush(stdin);
		gets(sv.GT);
		cout << "nhap dia chi sinh vien: ";
		fflush(stdin);
		gets(sv.DC);
	do{	
		cout << "nhap diem trung binh sinh vien: ";
		cin >> sv.DTB;
	}while(sv.DTB<0||sv.DTB>10);
}

void addmanyfirstorlastSV(listNODE &ls )
{
	SV sv;
	int n;
	cout <<"nhap so luong sinh vien: ";
	cin >> n;
	NODE*p;
	init(ls);
	for(int i=0;i<n;i++)
	{
		cout << "nhap thong tin sinh vien thu: "<<i+1<<"\n";
		addoneSV(sv);
		p=getNODE(sv);
//		int counter =0;
//		for(NODE*q=ls.head;q!=NULL;q=q->next)
//			{
//				if(p->data.MSSV==q->data.MSSV)
//				{
//					q->data.DTB+=p->data.DTB;
//					counter++;
//				}
//			}
	//	if(counter!=0)
	//	{
	//		cout << "----------them ma bi trung, cap nhat so luong----------\n";
	//	}else
	//	{
			int chon;
			cout << "chon 1 de them dau, chon 2 them cuoi(mac dinh them cuoi): ";
			cin >> chon;
			switch (chon)
			{
				case 1:	addfirstSV(ls,sv);break;
				case 2:	addlastSV(ls,sv);break;
				default: addlastSV(ls,sv);break;			
			}
			p=p->next;
	//	}
	}
}

void displayoneSVbyMSSV(listNODE ls, int b)
{
	cout << "		___danh sach sinh vien___\n";
	cout << "-------------------------------------------------------------\n";
	printf("|%5s|%20s|%5s|%20s|%5s|\n","MSSV","HO VA TEN","PHAI","DIA CHI","DTB");
	cout << "-------------------------------------------------------------\n";
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		if(p->data.MSSV==b)
		{
		printf("|%5d|%20s|%5s|%20s|%5.2f|\n",p->data.MSSV,p->data.HVT,p->data.GT,p->data.DC,p->data.DTB);
		cout << "-------------------------------------------------------------\n";
		}
	}
}

void displayoneSVbyHVT(listNODE ls, char a[20])
{
	cout << "		___danh sach sinh vien___\n";
	cout << "-------------------------------------------------------------\n";
	printf("|%5s|%20s|%5s|%20s|%5s|\n","MSSV","HO VA TEN","PHAI","DIA CHI","DTB");
	cout << "-------------------------------------------------------------\n";
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		if(strcmp(p->data.HVT,a)==0)
		{
		printf("|%5d|%20s|%5s|%20s|%5.2f|\n",p->data.MSSV,p->data.HVT,p->data.GT,p->data.DC,p->data.DTB);
		cout << "-------------------------------------------------------------\n";
		}
	}
}

void displaymanySV(listNODE ls)
{
	cout << "		___danh sach sinh vien___\n";
	cout << "-------------------------------------------------------------\n";
	printf("|%5s|%20s|%5s|%20s|%5s|\n","MSSV","HO VA TEN","PHAI","DIA CHI","DTB");
	cout << "-------------------------------------------------------------\n";
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		printf("|%5d|%20s|%5s|%20s|%5.2f|\n",p->data.MSSV,p->data.HVT,p->data.GT,p->data.DC,p->data.DTB);
		cout << "-------------------------------------------------------------\n";
	}
}

int findhvt(listNODE ls, char a[20])
{
	int i=0;
	NODE *p = ls.head;
	while(p!=NULL)
	{
		if(strcmp(p->data.HVT,a)==0)
		{
		return i;
		}
		p=p->next;
		i++;
	}
	return -1;	
}

void findHVT(listNODE ls,char a[20])
{
	if(findhvt(ls,a)==-1) printf("khong tim thay\n");
	else printf("tim thay o dong thu: %d\n",findhvt(ls,a)+1);
	displayoneSVbyHVT(ls,a);		
}

int findmssv(listNODE ls, int b)
{
	int i=0;
	NODE *p = ls.head;
	while(p!=NULL)
	{
		if(p->data.MSSV==b)
		{
		return i;
		}
		p=p->next;
		i++;
	}
	return -1;	
}

void findMSSV(listNODE ls,int b)
{
	if(findmssv(ls,b)==-1) printf("khong tim thay\n");
	else printf("tim thay o dong thu: %d\n",findmssv(ls,b)+1);	
	displayoneSVbyMSSV(ls,b);
}

void deletefirst(listNODE &ls)
{
	NODE*p=new NODE;
	p=ls.head;
	ls.head=ls.head->next;
	delete p;
}

void deletelast(listNODE &ls)
{
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		if(p->next==ls.tail)
		{
			delete ls.tail;
			p->next=NULL;
			ls.tail=p;
		}
	}
}

void deleteSV(listNODE &ls, int k)
{
	for(NODE*q=ls.head;q!=NULL;q=q->next)
	{
	if(ls.head->data.MSSV==k)
	{
		deletefirst(ls);
		cout << "da xoa\n";
		//displaymanySV(ls);
		//return;
	}
	if(ls.tail->data.MSSV==k)
	{
		deletelast(ls);
		cout << "da xoa\n";
		//displaymanySV(ls);
		//return;
	}
	}
	int counter=0;
	NODE*p=new NODE;
	for(NODE*i=ls.head;i!=NULL;i=i->next)
	{
		if(i->data.MSSV==k)
		{
			counter=1;
			p->next=i->next;
			delete i;
		//	return;
		}
		p=i;
	}
	if(counter!=1)
	{
		cout << "khong tim thay\n";
	}
	return;
}

void sortupDTB(listNODE &ls)
{
	for (NODE*i=ls.head; i!=NULL; i=i->next)
	{
		for (NODE*j=i->next; j!=NULL; j=j->next)
		{
			if (i->data.DTB  > j->data.DTB)
			{
				SV tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}
}

void updateDTB(listNODE ls, int mssv)
{
	double DTB;
	cout << "nhap diem trung binh: ";
	cin >> DTB;
	for (NODE*i= ls.head; i!= NULL; i=i->next)
	{
		if (i->data.MSSV == mssv)
		{
			i->data.DTB = DTB;
		}
	}
}

void listSVover5(listNODE ls)
{
	cout << "		___danh sach sinh vien___\n";
	cout << "-------------------------------------------------------------\n";
	printf("|%5s|%20s|%5s|%20s|%5s|\n","MSSV","HO VA TEN","PHAI","DIA CHI","DTB");
	cout << "-------------------------------------------------------------\n";
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		if(p->data.DTB>=5)
		{
		printf("|%5d|%20s|%5s|%20s|%5.2f|\n",p->data.MSSV,p->data.HVT,p->data.GT,p->data.DC,p->data.DTB);
		cout << "-------------------------------------------------------------\n";
		}
	}
}

int mountsvnam(listNODE ls)
{
	int counter = 0;
	for (NODE *p = ls.head;p != NULL;p=p->next)
	{
		if (strcmp(p->data.GT,"nam") == 0)
		{
			counter++;
		}
	}
	return counter;
}

double agvDTB(listNODE ls)
{
	int counter=0;
	double sum=0;
	for(NODE*p=ls.head;p!=NULL;p=p->next)
	{
		counter++;
		sum=sum+p->data.DTB;
	}
	return sum/counter;
}

//void reverse(listNODE &ls) {
//    NODE *current = ls.head;
//    NODE *prev = NULL;
//    NODE *next = NULL;
//    while (current != NULL) {
//        next = current->next;
//        current->next = prev;
//        prev = current;
//        current = next;
//    }
//    ls.head = prev;
//    displaymanySV(ls);
//}

void reverse(NODE * p) {
	if(p == NULL) {
		return;
	}else{
		reverse(p->next);
		printf("%d ", p->data);
	}
}

void addmidSV(listNODE &ls)
{
	SV sv;
	int x;
	addoneSV(sv);
	cout << "ci tri can them la: ";
	cin >> x;
	NODE *q,*newNODE,*p;
	int counter1=1;
	newNODE=getNODE(sv);
	
	
	int counter2 =0;
		for(NODE*q=ls.head;q!=NULL;q=q->next)
			{
				if(newNODE->data.MSSV==q->data.MSSV)
				{
					q->data.DTB+=newNODE->data.DTB;
					counter2++;
				}
			}
		if(counter2!=0)
		{
			cout << "----------them ma bi trung, cap nhat so luong----------\n";
			return;
		}
	
	
	if(x==1)//them o dau
	{
		newNODE->next=ls.head;
		ls.head=newNODE;//giong ben addfirst
	}
	else
	{
		while(p!=NULL)
		{
			p=q;
			p=p->next;
			counter1++;
		}
		if(p==NULL)//them o duoi
		{
			//giong ben addlast
			ls.tail->next=newNODE;
			ls.tail=newNODE;
		}
		else//them o giua
		{
			newNODE->next=p;
			q->next=newNODE;	
		}
	}
	cout << "danh sach da them:\n";
	displaymanySV(ls);
}

int main(void)
{
	listNODE ls;
	init(ls);
	int tmp;
	do
	{
	cout << "\n	  	_______chuong trinh danh sach sinh vien_______\n";
	cout << "		===============MENU============================\n";
	cout << "		|1.tao listSV (them dau hoac cui, trung sl+1) |\n";
	cout << "		|2.xuat danh sach                             |\n";
	cout << "		|3.tim kiem theo mssv                         |\n";
	cout << "		|4.tim kiem theo hvt                          |\n";
	cout << "		|5.sap xep tang dan theo DTB                  |\n";
	cout << "		|6.cap nhat DTB                               |\n";
	cout << "		|7.danh sach SV DTB >=5                       |\n";
	cout << "		|8.dem so luong SV nam                        |\n";
	cout << "		|9.DTB toan khoa                              |\n";	
	cout << "		|10.xoa sinh vien                             |\n";
	cout << "		|11.them sinh vien                            |\n";
	cout << "		|12.xuat danh sach dao nguoc                  |\n";	
	cout << "		===============================================\n";	
	cout << "		nhap lua chon, chon 0 de thoat: ";
	cin >> tmp;	
	switch(tmp)
    	{
			case 1: addmanyfirstorlastSV(ls); break;
			case 2: displaymanySV(ls); break;
			case 3: int mssv1;
					cout << "nhap MSSV can tim: ";
					cin >> mssv1;
					findMSSV(ls,mssv1); break;
			case 4: char hvt1[20];
					cout << "nhap HVT can tim: ";
					fflush(stdin);
					gets(hvt1);
					findHVT(ls,hvt1); break	;	
			case 5: sortupDTB(ls);
					displaymanySV(ls); break;
			case 6: int mssv2;
					cout << "nhap MSSV can cap nhat: ";
					cin >> mssv2;
					updateDTB(ls,mssv2);
					displaymanySV(ls); break;
			case 7: listSVover5(ls); break;
			case 8: cout << "so luong sinh vien nam la: "<<mountsvnam(ls)<<"\n"; break;
			case 9: cout << "diem trung binh toan khoa la: "<<agvDTB(ls)<<"\n"; break;
			case 10: int mssv3;
					 cout << "nhap ma so sinh vien can xoa: ";
					 cin >> mssv3;
					 deleteSV(ls,mssv3);break;
			case 11: addmidSV(ls); break;
		//	case 12: reverse(ls); break;
			case 12: reverse(ls.head); break;
		}
	}while(tmp!=0);
	return 0;
}
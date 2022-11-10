#include<iostream>
#include<string>
using namespace std;
 
struct SanPham{
	string ten, msp;
	double gia, soluong;
};
 
struct SP{
	SanPham s;
	SP *next;
};
 
typedef struct SP* sp;
 
//Cap phat dong mot node moi 
sp createNode(){
	SanPham s;
	cout << "Nhap thong tin san pham \n";
	cout << "Nhap msp :"; cin >> s.msp;
	cout << "Nhap ten san pham :"; cin.ignore();
	getline(cin, s.ten);
	cout << "Nhap so luong :"; cin >> s.soluong;
	if(s.soluong<0){
	cout<<"So luong am, moi nhap lai:";
	fflush(stdin);
	cin>>s.soluong;
	}
	cout << "Nhap gia :"; cin >> s.gia;
	if(s.gia<0){
	cout<<"Gia am, moi nhap lai:";
	fflush(stdin);
	cin>>s.gia;
	}
	sp p = new SP();
	p->s = s;
	p->next = NULL;
	return p;
}

//them 1 phan tu vao dau danh sach lien ket
void themdau(sp &a){
	sp p = createNode();
	if(a == NULL){
		a = p;
	}
	else{
		p->next = a;
		a = p;
	}
}
 
//Them 1 phan tu vao cuoi dslk
void themcuoi(sp &a){
	sp p = createNode();
	if(a == NULL){
		a = p;
	}
	else{
		sp q = a;
		while(q->next != NULL){
			q = q->next;
		}
		q->next = p;
	}
}
 
//xoa phan tu o dau
void xoadau(sp &a){
	if(a == NULL) return;
	a = a->next;
}
 
//xoa phan tu o cuoi
void xoacuoi(sp &a){
	if(a == NULL) return;
	sp truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}
 
void in(SanPham s){
	cout << "MSP : " << s.msp << endl;
	cout << "Ten SP :" << s.ten << endl;
	cout << "So luong : "  << s.soluong << endl; 
	cout << "Gia : " << s.gia << endl; 
}
 
void inds(sp a){
	cout << "Danh sach san pham :\n";
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
}
 
void sapxep(sp &a){
	for(sp q = a; q->next != NULL; q = q->next){
		sp min = q;
		for(sp tmp = q->next; tmp != NULL; tmp = tmp->next){
			if(tmp->s.gia < min->s.gia){
				min = tmp;
			}
		}
		SanPham p = min->s;
		min->s = q->s;
		q->s = p;
	}
}
void Press(){
	system("pause");
	system("cls");
}
int main(){
	sp head = NULL;
	while(true){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen san pham vao dau danh sach\n";
		cout << "2. Chen san pham vao cuoi danh sach\n";
		cout << "3. Xoa phan tu o dau\n";
		cout << "4. Xoa phan tu o cuoi\n";
		cout << "5. Duyet danh sach lien ket\n";
		cout << "6. Sap xep cac san pham trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			system("cls");
			themdau(head);
			Press();
		}
		else if(lc == 2){
			system("cls");
			themcuoi(head);
			Press();
		}
		else if(lc == 3){
			system("cls");
			xoadau(head);
			Press();
		}
		else if(lc == 4){
			system("cls");
			xoacuoi(head);
			Press();
		}
		else if(lc == 5){
			system("cls");
			inds(head);
			Press();
		}
		else if(lc == 6){
			system("cls");
			sapxep(head);
			Press();
		}
		else if(lc == 0){
			break;
		}
	}
	return 0;
}

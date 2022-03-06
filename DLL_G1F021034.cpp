#include<iostream>
using namespace std;


struct filim{
	string judul, sutradara;
	int tahun_tayang;
	
	filim *prev;
	filim *next;
};

filim *head, *tail, *cur, *newNode, *del, *afterNode ;


void createDoubleLinkedList(string judul, string sutradara, int tahun_t){
	head = new filim();
	head->judul = judul;
	head-> sutradara = sutradara;
	head->tahun_tayang = tahun_t;
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}


int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      
      cur = cur->next;
    }
    return jumlah;
  }
}


void insertFirst(string judul, string sutradara, int tahun_t){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new filim ();
	newNode->judul = judul;
	newNode->sutradara  = sutradara;
	newNode->tahun_tayang = tahun_t;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	}
}

void insertLast(string judul, string sutradara, int tahun_t){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new filim();
	newNode->judul = judul;
	newNode->sutradara = sutradara;
	newNode->tahun_tayang = tahun_t;
	newNode->prev = tail;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
	}
}


void insertAfter(string judul, string sutradara, int tahun_t, int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
	newNode = new filim();
	newNode->judul = judul;
	newNode->sutradara = sutradara;
	newNode->tahun_tayang = tahun_t;

	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	afterNode = cur->next;
	newNode->prev = cur;
	newNode->next = afterNode;
	cur->next =newNode;
	afterNode->prev = newNode;
	}
}


void deleteFirst(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
	  }else{
	del = head;
	head = head->next;
	head->prev = NULL;
	delete del;
	}
}


void deleteLast(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	del = tail;
	tail = tail->prev;
	tail->next =NULL;
	delete del;
	}
}


void deleteAfter(int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
 	 	if( posisi == 1 || posisi == countDoubleLinkedList() ){
      		cout << "Posisi bukan posisi tengah!" << endl;
   		}else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      		cout << "Posisi diluar jangkauan!" << endl;
   		}else{
			int nomor = 1;
			cur = head;
			while(nomor <= posisi -1){
				cur = cur->next;
				nomor++;
				}
			del = cur->next;
			afterNode = del->next;
			cur->next =afterNode;
			afterNode->prev = cur;
			delete del;
		}
	}
}


void printDoubleLinkedList(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
    cout << "\nJumlah Data : " << countDoubleLinkedList() << endl;
    cout << "INFO DATA" << endl;
    cur = head;
    while( cur != NULL ){
     
      cout << "Data : " << cur->tahun_tayang << endl;
      
      cur = cur->next;
    }
  }
}

void searchNode(filim **head, int tahun_t ){
    int currentTT = 2021;
    filim*cur = *head;
    while (cur->next != 0 && currentTT != tahun_t)
    {
        cur = cur->next;
        currentTT++;
    }
    cout << cur->judul << " ditemukan pada tahun ke " << currentTT;
}

int main(){
	
	createDoubleLinkedList("Makmum 2","Guntur Soeharjanto",2021);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst("spiderman no way home", "Jon Watts", 2019);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast("John Wick", "Chad Stahelski", 2014);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Laskar Pelangi", "Riri Riza", 2018, 3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Comic 8", "Anggy Umbara", 2014, 4);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	printDoubleLinkedList();
  	searchNode(&head, 3);
	return 0;
}

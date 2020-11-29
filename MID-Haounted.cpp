#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b;
struct Node{
    int tanggal,tahun;
    char bulan[20];
    char nama[50];
    Node* next,*prev;
} *head,*tail,*curr;

Node* createNode(int tanggal,char* bulan,int tahun,char*nama){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->tanggal = tanggal;
    strcpy(temp->bulan,bulan);
    temp->tahun = tahun;
    strcpy(temp->nama,nama);
    temp->next = temp->prev = NULL;
    return temp;
}

void pushHead(int tanggal,char* bulan,int tahun,char*nama){
    Node* temp = createNode(tanggal,(char*)bulan,tahun,(char*)nama);
    if(!head){
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(int tanggal,char* bulan,int tahun,char*nama){
    Node* temp = createNode(tanggal,(char*)bulan,tahun,(char*)nama);
    if(!head){
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(int tanggal,char* bulan,int tahun,char*nama){
    Node* temp = createNode(tanggal,(char*)bulan,tahun,(char*)nama);
    if(!head){
        head = tail = temp;
    } else if(temp->tahun<head->tahun){
        pushHead(tanggal,(char*)bulan,tahun,(char*)nama);
    } else if(temp->tahun>tail->tahun){
        pushTail(tanggal,(char*)bulan,tahun,(char*)nama);
    } else {
        curr = head;
        while(curr->tahun<temp->tahun){
            curr = curr->next;
        }
        temp->prev = curr->prev;
        temp->next = curr;
        curr->prev->next = temp;
        curr->prev = temp;
    }
}

void printLinkedList(){
    if(!head){
        return;
    } else {
        int i=0;
        curr = head;
        while(curr){
            if(i>b){
            printf("%d %s %d - %s\n",curr->tanggal,curr->bulan,curr->tahun,curr->nama);
            }
            i++;
            curr = curr->next;
        }
    }
}

int main(){
    int a;
    scanf("%d %d",&a,&b);
    int tanggal,tahun;
    char bulan[50];
    char nama[50];
    for(int i=0;i<a;i++){
        scanf("%d %s %d - %[^\n]",&tanggal,bulan,&tahun,nama);
        pushMid(tanggal,(char*)bulan,tahun,(char*)nama);
    }
    printf("Need %d more cure",a-b);
    printLinkedList();
    

}

#ifndef _STACKNODE_H_INCLUDED
#define _STACKNODE_H_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <time.h>
using namespace std;
void instructions (void);


class Stack
{
public:
Stack():tail(0)//, head(0)//записать подругому
{
}

~Stack()
{ cout<<"destructor"<<endl;
/*while(head)
{
tail=head->next;
delete head;
head=tail;
}*/
}
int GetTail(){
int boolka=0;
if(tail!=0) boolka=1;
return (boolka);
}

int Limit(int limit1){
limit=limit1;
int boolka2=0;
if (SizeOfStack==limit) boolka2=1;
//cout<<"Limit! You can't add items";

return (boolka2);
}
int GetLimit()
{
return(limit);
}

// #1
void push(int val)
{
//Node* Temp;
Node* Temp=new Node; //динамически выделяем память на структуру
Temp->elem=val;
if(tail==0)
{
tail=Temp;
}
else
{
//if(RemovingDoubles(int val,Node*)==1){

Temp->next=tail; //тарелочка снизу в стеке
tail=Temp; //самая верхняя тарелочка
//}
}
SizeOfStack++;
}

int top()//вернуть верхнюю тарелочку
{
if(tail==0)
{
// throw std::string("Stack is empty!");
StackIsEmpety();
return(0);
}
return tail->elem;
}

// #2
void pop()
{
if(tail==0)
{
//throw std::string("Stack is empty!");//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//StackIsEmpety();
}
else
{
Node* delptr=tail;//сохраняем адресс ячейки, которую надо очистить
tail=tail->next;//меняем верхнюю тарелочку на следущую(А верхнюю убираем)
SizeOfStack--;
delete delptr;
}
}

// #3
int GetSizeOfStack()
{
print();
cout<<"Size of Stack="<<SizeOfStack<<endl;
return(SizeOfStack);
}

// #4
void print()
{
if(tail==0)
{
//throw string("Stack is empty!");
StackIsEmpety();
}
else
{
for(Node* ptr=tail; ptr!=0; ptr=ptr->next)
{
//CopyStack(ptr);
cout<<ptr->elem<<' ';
}
cout<<'\n';
}
}

//6
void dopip (Stack &St,int ElemRN, int val)
{
if(SizeOfStack<1 || SizeOfStack<ElemRN)return;
Node* ptr;
if (ElemRN==1){
ptr->elem=val;
ptr->next=tail;
tail = ptr;
delete ptr;
SizeOfStack++;
}
else{
Node* ptrBack1=St.tail;
Node* Temp=new Node;
for(int i=1;i<(ElemRN-1);i++)
{
ptrBack1=ptrBack1->next;
}
ptr=ptrBack1->next;
Temp->elem=val;
Temp->next=ptr;
ptrBack1->next=Temp;
SizeOfStack++;
delete ptr; delete ptrBack1;
}
}

//7
void poslepip (Stack &St,int ElemRN, int val)
{
    dopip(St,ElemRN+1,val);
}

void StackIsEmpety()
{
cout<<"Stack is empty!"<<endl;
}

// #5
CopyStack(Stack &St1,Stack &St2){
if(St1.tail!=NULL){
Stack Copy=St1;
Inverse(Copy);
for(Node* ptr=Copy.tail; ptr!=0; ptr=ptr->next)
{
St2.push(Copy.top());
Copy.pop();

}
Copy.RemoveStack();
St2.print();
}
}

// #8
void ReplaceItem(Stack &St, int Zamena, int Zamena2){
int c=0,H;
H: cout<<"Введите элемент, который хотите заменить:";
cin>>Zamena;
cout<<"Введите НОВЫЙ элемент:";
cin>>Zamena2;
for(Node* ptr=St.tail; ptr!=0; ptr=ptr->next)
{
if(ptr->elem==Zamena)
{
ptr->elem=Zamena2;
c=1;
}
if(c==1) break;
}
if(c==0){
cout<<"ТАКОЙ ЭЛЕМЕНТ НЕ НАЙДЕН!!!\n\n";
goto H;
}
}

// #9
void RemoveBringItem (Stack &St,int ElemRN){
int Freak=0;
Node* ptr;
if (ElemRN==1){
ptr=tail;
tail = tail->next;
cout<<"\n"<<ptr->elem<<endl;
delete ptr;
SizeOfStack--;
}
else{
Node* ptrBack1=St.tail;
for(int i=1;i<(ElemRN-1);i++)
{
ptrBack1=ptrBack1->next;
}
ptr=ptrBack1->next;
ptrBack1->next=ptr->next;
SizeOfStack--;
cout<<"\n"<<ptr->elem<<endl;
delete ptr;
}
// cout<<ptr->elem;

}

// #10
void RemoveStack()
{
while(tail!=0)
{
Node* delptr=tail;//сохраняем адресс ячейки, которую надо очистить
tail=tail->next;//меняем верхнюю тарелочку на следущую(А верхнюю убираем)
SizeOfStack--;
delete delptr;
}
}

// #12
void Inverse(Stack &St1){
if(St1.tail!=NULL){
Stack buf=St1;
St1.RemoveStack();
for(Node* ptr=buf.tail; ptr!=NULL; ptr=ptr->next)
{
//cout<<"polina loooooooooooooooooooooooooooooh2\n";
St1.push(buf.top());
buf.pop();
//St2.push(ptr->next);
//cout<<"polina loooooooooooooooooooooooooooooh3\n";
}
buf.RemoveStack();
St1.print();
}
}
// #13
void SumTwoStacks(Stack &St1,Stack &St2)
{Node* ptr1=St1.tail;
for(Node* ptr2=St2.tail; ptr2!=0; ptr2=ptr2->next)
{
ptr1->elem+=ptr2->elem;
ptr1=ptr1->next;
}
}

void MergeTwoStacks(Stack &St1,Stack &St2)
{
St1.limit+=St2.GetLimit();
//St1.SizeOfStack+=St2.GetSizeOfStack();
Stack buf2=St2;
buf2.Inverse(buf2);
for(Node* ptr=buf2.tail; ptr!=NULL; ptr=ptr->next)
{
St1.push(buf2.top());
buf2.pop();
}
}

// #15
void RemovingDoubles(Stack &St){
int Doubles=0,countDoubles=0,nomberEl=0;
Rep:cout<<"Введите двойника которого хотите убрать:";
cin>>Doubles;
for(Node* ptr=St.tail; ptr!=0; ptr=ptr->next)
{
if(Doubles==ptr->elem)countDoubles++;
}
if(countDoubles==0)goto Rep;
while(countDoubles>1){
for(Node* ptr=St.tail; ptr!=0; ptr=ptr->next)
{nomberEl++;
if((Doubles==ptr->elem)&&(countDoubles>1))
{
St.RemoveBringItem(St,nomberEl);
countDoubles--;
/*if(nomberEl==1)nomberEl--;
else nomberEl-=2;*/
nomberEl=0;
break;
}
}
}
cout<<"countDoubles="<<countDoubles<<endl;
St.print();
}


// #17
void RandomEnterStack(Stack &St)
{int i=0;
for( i=0;i<limit;i++) St.push(rand()%10+1);
St.print();
}
/*int RemovingDoubles(int val, Node* Temp){
int boolka3;
if ((Temp->next)==val)
{
boolka3=0;
}
boolka3=1;
}*/

private:
struct Node
{
/*Node():elem(0), next(0)
{
}*/
Node* next=0;
int elem=0;
};
//typedef struct Node tdNode
//Node* head;
Node* tail;
int SizeOfStack=0;
int limit=0;
};





//Распечатка инструкций
void instructions (void)
{
cout<<"Enter choice:\n"
"1 to push a value on the stack\n"
"2 to pop a value off the stack\n"
"3 Узнать размер Stack\n"
"4 Вывести Stack\n"
"5 Копировать Stack\n"
"6 to insert into stack 'before'\n"
"7 to insert into stack 'after' \n"
"8 to replace item\n"
"9 to remove the item and bring it to the screen\n"//?????????????????????Надо ли?
"10 to remove stack\n"
"11 to arrange by key\n"
"12 to invert stack\n"
"13 Сложить Stacks\n"//сложить
"14 merge two stacks\n"//слить
"15 to remove Doubles\n"
"17 random enter\n"
"20 goto Enter Stack.\n"
"n to end program\n";
}

#endif
#include <iostream>
//#include "StackNode.h"

int main(){
setlocale(LC_ALL, "Rus");
class Stack St;
class Stack St2;
int choiceSt;


void runningProgramm(Stack&St,Stack&St2);

N:cout<<"enter number stack (3=EXIT)\n";
cin>>choiceSt;
switch(choiceSt)
{
case 1:
runningProgramm(St,St2);
//cout<<"polina loooooooooooooooooooooooooooooh\n";
goto N;
break;
case 2:
runningProgramm(St2,St);
goto N;
break;
case 3:
break;
default: goto N;
}


return 0;
}

void runningProgramm(Stack &St,Stack &St2)
{
int val=0,count1=0,val2=0,choice, limit,ElemRN=0,bis;;
int Zamena=0,Zamena2=0;
if(St.GetLimit()==0){
cout<<"limit Стека=";
cin>>limit;
St.Limit(limit);
}
instructions();
cin>>choice;
while (choice!=20){
switch (choice)
{
case 1: // заталкивает значение в стек
if(St.GetLimit()==St.GetSizeOfStack()) cout<<"Stack is full! You can't add items!"<<endl;
else{
cout<<"Enter an integer: ";
cin>>val;
St.push(val);
St.print();
cout<<endl;
}
break;
case 2: // выталкивает значение из стека
if (St.GetTail()!=0)
cout<<"The popped value is "<<St.top()<<".\n";
St.pop();
St.print();
break;
case 3://Узнать размер стека
St.GetSizeOfStack();
break;
case 4:
    cout<<"Enter an integer: ";
    cin>>val;

    St.print();
break;
case 5://Копирование стека
St.CopyStack(St,St2);
break;
case 6:
    cout<<"Введите номер элемента\n";
    cin>>ElemRN;
    cout<<"Введите элемент\n";
    cin>>bis;
    St.dopip(St,ElemRN,bis);
    St.print();
break;
case 7:
break;
case 8://Заменить элемент
St.ReplaceItem(St,Zamena,Zamena2);
St.print();
break;
case 9:
if(St.GetSizeOfStack()==0)
{
St.print();
break;
}
REST: cout<<"Введите номер элемента, который хотите удалить:";
cin>>ElemRN;
if((ElemRN>St.GetSizeOfStack())||(ElemRN<1)) goto REST;
St.RemoveBringItem(St,ElemRN);
St.print();
break;
case 10://удалить стек
St.RemoveStack();
break;
case 11:
St.RemoveStack();
break;
case 12://инверсия
St.Inverse(St);

break;
case 13://Сложение стеков
if((St.GetSizeOfStack()!=0)&&(St2.GetSizeOfStack()!=0))
{St.print();
St2.print();
if(St.GetSizeOfStack()>St2.GetSizeOfStack())St.SumTwoStacks(St,St2);
else St.SumTwoStacks(St2,St);
St.print();
St2.print();
}
break;
case 14://Слияние двух стэков
if((St.GetSizeOfStack()!=0)&&(St2.GetSizeOfStack()!=0))
{
St.MergeTwoStacks(St,St2);
}
St.print();
break;
case 15://Удаление двойников
if(St.GetSizeOfStack()>1)St.RemovingDoubles(St);
else cout<<"Стэк содержит менее 2 элементов\n";
break;
case 17:
St.RandomEnterStack(St);
break;


default:
cout<<"Invalid choice.\n\n";
instructions();
// cin>>choice;
break;
}
cout<<"? ";
cin>>choice;
}
}
//Поправки:
//1)Размер стека
//2)Надо ли задавать придел

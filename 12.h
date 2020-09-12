#ifndef 12_H_INCLUDED
#define 12_H_INCLUDED


void dopip (Stack &St,int ElemRN, int val)
{
int Freak=0;
Node* ptr;
if (ElemRN==1){
ptr=tail;
tail = tail->next;
cout«"\n"«ptr->elem«endl;
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
cout«"\n"«ptr->elem«endl;
delete ptr;
}
// cout«ptr->elem;

}

#endif // 12_H_INCLUDED

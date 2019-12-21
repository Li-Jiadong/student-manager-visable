/*
 * statisticcs.h
 *
 *  Created on: Dec 13, 2019
 *      Author: foxfish
 *
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_
bool average(char cmd[]){
	student *p=head;
	int i=0;
	float mave=0,eave=0,cave=0,aave=0;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		mave+=p->math;
		eave+=p->eng;
		cave+=p->cs;
		aave+=p->aver;
	}
	cout<<"��ѧƽ���ɼ�Ϊ:"<<mave/num+1e-6<<endl;
	cout<<"Ӣ��ƽ���ɼ�Ϊ"<<eave/num+1e-6<<endl;
	cout<<"�����ƽ���ɼ�Ϊ:"<<cave/num+1e-6<<endl;
	cout<<"��ƽ���ɼ�Ϊ:"<<aave/num+1e-6<<endl;
	return 1;
}
bool stanum(float score,int &nno,int &nok,int &ng,int &nb){
	if(score>=90) ++nb;
	else if(score>=80) ++ng;
	else if(score>=60) ++nok;
	else ++nno;
	return 1;
}
bool statistics(){
	student *p=head;
	int i=0;
	int mno=0,mok=0,mg=0,mb=0;
	int eno=0,eok=0,eg=0,eb=0;
	int cno=0,cok=0,cg=0,cb=0;
	int ano=0,aok=0,ag=0,ab=0;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		stanum(p->math,mno,mok,mg,mb);
		stanum(p->eng,eno,eok,eg,eb);
		stanum(p->cs,cno,cok,cg,cb);
		stanum(p->aver,ano,aok,ag,ab);
	}
	cout << "��ѧ:\n60�����ϵ�����Ϊ:" << mok + mg + mb << ",(90~100)�ֵ�����Ϊ:" << mb << ",(80~90)�ֵ�����Ϊ" << mg << "��" << endl;
	cout << "(60~80)�ֵ�����Ϊ:" << mok << ",60�����µ�����Ϊ:" << mno << "��" << endl << endl;
	cout << "Ӣ��:\n60�����ϵ�����Ϊ:" << eok + eg + eb << ",(90~100)�ֵ�����Ϊ:" << eb << ",(80~90)�ֵ�����Ϊ" << eg << "��" << endl;
	cout << "(60~80)�ֵ�����Ϊ:" << eok << ",60�����µ�����Ϊ:" << eno << "��" << endl << endl;
	cout << "�����:\n60�����ϵ�����Ϊ:" << cok + cg + cb << ",(90~100)�ֵ�����Ϊ:" << cb << ",(80~90)�ֵ�����Ϊ" << cg << "��" << endl;
	cout << "(60~80)�ֵ�����Ϊ:" << cok << ",60�����µ�����Ϊ:" << cno << "��" << endl << endl;
	cout << "ƽ����:\n60�����ϵ�����Ϊ:" << aok + ag + ab << ",(90~100)�ֵ�����Ϊ:" << ab << ",(80~90)�ֵ�����Ϊ" << ag << "��" << endl;
	cout << "(60~80)�ֵ�����Ϊ:" << aok << ",60�����µ�����Ϊ:" << ano << "��" << endl << endl;
	return 1;
}
bool nodecmp(student *a,student *b,int item,bool order){
	if(item==4){
		if(a->aver==b->aver)
			return (strcmp(a->id,b->id)<0)^order;
		else
			return (a->aver<b->aver)^order;
	}else if(item==1){
		if(a->math==b->math)
			return (strcmp(a->id,b->id)<0)^order;
		else
			return (a->math<b->math)^order;
	}else if(item==2){
		if(a->eng==b->eng)
			return (strcmp(a->id,b->id)<0)^order;
		else
			return (a->eng<b->eng)^order;
	}else if(item==3){
		if(a->cs==b->cs)
			return (strcmp(a->id,b->id)<0)^order;
		else
			return (a->cs<b->cs)^order;
	}
	return 1;
}
void nodeswap(student *a,student *b){
	student temp;

	temp.aver=a->aver;
	temp.cs=a->cs;
	temp.eng=a->eng;
	strcpy_s(temp.id,a->id);
	temp.math=a->math;
	strcpy_s(temp.name,a->name);
	strcpy_s(temp.sex,a->sex);

	a->aver=b->aver;
	a->cs=b->cs;
	a->eng=b->eng;
	strcpy_s(a->id,b->id);
	a->math=b->math;
	strcpy_s(a->name,b->name);
	strcpy_s(a->sex,b->sex);

	b->aver=temp.aver;
	b->cs=temp.cs;
	b->eng=temp.eng;
	strcpy_s(b->id,temp.id);
	b->math=temp.math;
	strcpy_s(b->name,temp.name);
	strcpy_s(b->sex,temp.sex);
}
student* quickmid(int item,bool order,student *h,student *t){
	student key = *h;
	while(h!=t){
		while(h!=t && nodecmp(t,&key,item,!order)){
			t=t->before;
		}
		if(h!=t) nodeswap(h,t);
		while(h!=t && nodecmp(h,&key,item,order)){
			h=h->next;
		}
		if(h!=t) nodeswap(h,t);
	}
	return h;
}
void quicklistsort(int item,bool order,student *h,student *t){
	if(h!=t){
		student *key=quickmid(item,order,h,t);
		if(h!=key)quicklistsort(item,order,h,key->before);
		if(t!=key)quicklistsort(item,order,key->next,t);
	}
}
bool sortlist(int item,bool order){
	quicklistsort(item,order,head->next,tail);
	return 1;
}


#endif /* STATISTICS_H_ */

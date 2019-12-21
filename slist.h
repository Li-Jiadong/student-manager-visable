/*
 * slist.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *
 */

#ifndef SLIST_H_
#define SLIST_H_
bool havedata = 0;
bool list();
student *head=0,*tail=0;
int num=0;
bool create(){
	head=new student();
	tail=head;
	tail->next=0;
	tail->before=0;
	return 1;
}

bool add(){
	char input='y';
	while(1){
		if(input=='y'||input=='Y'){
			//system("clean");
			//list();
			student *s=new student();
			while(1){
				cout<<"������ѧ��:";
				cin>>s->id;
				bool right=1;
				for(int i=0;s->id[i]!=0;++i){
					if(s->id[i]>='0'&&s->id[i]<='9'&&i<10){
					}else{
						cout<<"�������ѧ��Ϊ10λ���ڵ����֣����������롣"<<endl;
						right=0;
						break;
					}
				}
				student *p = head;
				while (p->next!=0){
					p = p->next;
					if (strcmp(p->id, s->id) == 0) {
						cout << "�������ѧ���롰"<<p->name<<"���ظ������������롣" << endl;
						right = 0;
						break;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"����������:";
				cin>>s->name;
				bool right=1;
				for(int i=0;s->name[i]!=0;++i){
					if(i>=20) {
						right=0;
						cout<<"����̫��,���������롣"<<endl;
						break;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"�������Ա�(��/Ů):";
				cin>>s->sex;
				bool right=1;
				//cout << strcmp(s->sex, "��") << " " << strcmp(s->sex, "Ů") << endl;
				//cout << (strcmp(s->sex, "��") && strcmp(s->sex, "Ů")) << endl;
				if(strcmp(s->sex,"��")&&strcmp(s->sex,"Ů")){
					right=0;
					cout<<"�Ա�����������������롣";
				}
				if(right) break;
			}
			while(1){
				cout<<"��������ѧ�ɼ�(0~100):";
				cin>>s->math;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"�������ʹ�������������"<<endl;
				}else{
					if(s->math<0||s->math>100){
						right=0;
						cout<<"���ݷ�Χ��������������"<<endl;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"������Ӣ��ɼ�(0~100):";
				cin>>s->eng;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"�������ʹ�������������"<<endl;
				}else{
					if(s->eng<0||s->eng>100){
						right=0;
						cout<<"���ݷ�Χ��������������"<<endl;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"�����������ɼ�(0~100):";
				cin>>s->cs;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"�������ʹ�������������"<<endl;
				}else{
					if(s->cs<0||s->cs>100){
						right=0;
						cout<<"���ݷ�Χ��������������"<<endl;
					}
				}
				if(right) break;
			}
			s->aver=(s->math+s->eng+s->cs)/3.0+1e-6;
			tail->next=s;
			s->before=tail;
			tail=s;
			tail->next=0;
			havedata = 1;
			cout<<"�Ƿ��������ѧ����Ϣ��(y/n)";
		}else if(input=='n'||input=='N'){
			break;
		}else{
			cout<<"�����������������(y/n):";
		}
		cin>>input;
	}
	return 1;
}
bool list(){//�г���Ϣ����
	student *p=head;
	int i=0;
	title();
	i=1;
	while(p->next!=0){
		//cout<<p->next<<endl;
		p=p->next;
		cout<<i<<"\t";
		cout << setw(10) <<p->id<<"\t";
		cout<<p->name<<"\t";
		cout<<p->sex<<"\t";
		cout << fixed << setprecision(1) <<p->math<<"\t";
		cout << fixed << setprecision(1) <<p->eng<<"\t";
		cout << fixed << setprecision(1) <<p->cs<<"\t";
		cout << fixed << setprecision(1) <<p->aver<<"\t"<<endl;
		++i;
	}
	return 1;
}
bool remove(int n){
	student *p=head;
	int i=0;
	bool find=0;
	while(p->next!=0){
		p=p->next;
		++i;
		if(i==n){
			find=1;
			p->before->next=p->next;
			if(p->next!=0) p->next->before=p->before;
			delete p;
			break;
		}
	}
	if(!find) return 0;
	return 1;
}

bool change(int n,int item){
	student *p = head;
	int i=0;
	bool find=0;
	while(p->next!=0){
		p=p->next;
		i++;
		if(i==n){
			find=1;
			break;
		}
	}
	if(!find) return 0;
	if (item==1) {
		while (1) {
			cout << "������ѧ�����:";
			cin >> p->id;
			bool right = 1;
			for (int i = 0; p->id[i] != 0; ++i) {
				if (p->id[i] >= '0'&&p->id[i] <= '9'&&i < 10) {
				}
				else {
					cout << "������������������" << endl;
					right = 0;
					break;
				}
			}
			student *s = head;
			int tot = 0;
			while (s->next != 0) {
				s = s->next;
				++tot;
				if (tot!=n&&strcmp(s->id,p->id) == 0) {
					cout << "�������ѧ���롰" << s->name << "���ظ������������롣" << endl;
					right = 0;
					break;
				}
			}
			if (right) break;
		}
	}
	else if(item == 2){
		while (1) {
			cout << "������ѧ������:";
			cin >> p->name;
			bool right = 1;
			for (int i = 0; p->name[i] != 0; ++i) {
				if (i >= 20) {
					right = 0;
					cout << "������������������" << endl;
					break;
				}
			}
			if (right) break;
		}
	}
	else if (item == 3) {
		while (1) {
			cout << "������ѧ���Ա�:";
			cin >> p->sex;
			bool right = 1;
			//cout << strcmp(p->sex, "��") << " " << strcmp(p->sex, "Ů") << endl;
			if (strcmp(p->sex,"��") && strcmp(p->sex,"Ů")) {
				right = 0;
				cout << "������������������";
			}
			if (right) break;
		}
	}
	else if(item==4){
		while(1){
			cout<<"��������ѧ�ɼ�(0~100):";
			cin >> p->math;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"�������ʹ�������������"<<endl;
			}else{
				if(p->math<0||p->math>100){
					right=0;
					cout<<"���ݷ�Χ��������������"<<endl;
				}
			}
			if (right) {
				p->aver = (p->math + p->eng + p->cs) / 3.0 + 1e-6;
				break;
			}
			
		}
	}else if(item==5){
		while(1){
			cout<<"������Ӣ��ɼ�(0~100):";
			cin>>p->eng;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"�������ʹ�������������"<<endl;
			}else{
				if(p->eng<0||p->eng>100){
					right=0;
					cout<<"���ݷ�Χ��������������"<<endl;
				}
			}
			if (right) {
				p->aver = (p->math + p->eng + p->cs) / 3.0 + 1e-6;
				break;
			}
		}
	}else if(item==6){
		while(1){
			cout<<"�����������ɼ�(0~100):";
			cin>>p->cs;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"�������ʹ�������������"<<endl;
			}else{
				if(p->cs<0||p->cs>100){
					right=0;
					cout<<"���ݷ�Χ��������������"<<endl;
				}
			}
			if (right) {
				p->aver = (p->math + p->eng + p->cs) / 3.0 + 1e-6;
				break;
			}
		}
	}else return 0;
	return 1;
}


bool search(int n,char in[]){
	student *p=head;
	int i=0;
	bool find=0;
	if(n==1){
		while(p->next!=0){
			p=p->next;
			++i;
			if(!strcmp(p->id,in)){
				cout << "��ѯ���Ϊ:" << endl;
				cout << setw(10) << "ѧ��\t";
				cout << "����\t";
				cout << "�Ա�\t";
				cout << "��ѧ\t";
				cout << "Ӣ��\t";
				cout << "�����\t";
				cout << "ƽ����";
				cout << endl;
				cout<<*p<<endl;
				find=1;
				break;
			}
		}
	}else if(n==2){
		while(p->next!=0){
			p=p->next;
			++i;
			if(!strcmp(p->name,in)){
				if(!find){
					cout << "��ѯ���Ϊ:" << endl;
					cout << setw(10) << "ѧ��\t";
					cout << "����\t";
					cout << "�Ա�\t";
					cout << "��ѧ\t";
					cout << "Ӣ��\t";
					cout << "�����\t";
					cout << "ƽ����";
					cout << endl;
					find=1;
				}
				cout<<*p<<endl;
			}
		}
	}else{
		return 0;
	}
	if(!find) return 0;


	if(n==0){

	}else{

	}
	return 1;
}

#endif /* SLIST_H_ */

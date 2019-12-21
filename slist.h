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
				cout<<"请输入学号:";
				cin>>s->id;
				bool right=1;
				for(int i=0;s->id[i]!=0;++i){
					if(s->id[i]>='0'&&s->id[i]<='9'&&i<10){
					}else{
						cout<<"输入错误，学号为10位以内的数字，请重新输入。"<<endl;
						right=0;
						break;
					}
				}
				student *p = head;
				while (p->next!=0){
					p = p->next;
					if (strcmp(p->id, s->id) == 0) {
						cout << "输入错误，学号与“"<<p->name<<"”重复，请重新输入。" << endl;
						right = 0;
						break;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"请输入姓名:";
				cin>>s->name;
				bool right=1;
				for(int i=0;s->name[i]!=0;++i){
					if(i>=20) {
						right=0;
						cout<<"姓名太长,请重新输入。"<<endl;
						break;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"请输入性别(男/女):";
				cin>>s->sex;
				bool right=1;
				//cout << strcmp(s->sex, "男") << " " << strcmp(s->sex, "女") << endl;
				//cout << (strcmp(s->sex, "男") && strcmp(s->sex, "女")) << endl;
				if(strcmp(s->sex,"男")&&strcmp(s->sex,"女")){
					right=0;
					cout<<"性别输入错误，请重新输入。";
				}
				if(right) break;
			}
			while(1){
				cout<<"请输入数学成绩(0~100):";
				cin>>s->math;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"输入类型错误，请重新输入"<<endl;
				}else{
					if(s->math<0||s->math>100){
						right=0;
						cout<<"数据范围错误，请重新输入"<<endl;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"请输入英语成绩(0~100):";
				cin>>s->eng;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"输入类型错误，请重新输入"<<endl;
				}else{
					if(s->eng<0||s->eng>100){
						right=0;
						cout<<"数据范围错误，请重新输入"<<endl;
					}
				}
				if(right) break;
			}
			while(1){
				cout<<"请输入计算机成绩(0~100):";
				cin>>s->cs;
				bool right=1;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024,'\n');
					right=0;
					cout<<"输入类型错误，请重新输入"<<endl;
				}else{
					if(s->cs<0||s->cs>100){
						right=0;
						cout<<"数据范围错误，请重新输入"<<endl;
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
			cout<<"是否继续输入学生信息？(y/n)";
		}else if(input=='n'||input=='N'){
			break;
		}else{
			cout<<"输入错误，请重新输入(y/n):";
		}
		cin>>input;
	}
	return 1;
}
bool list(){//列出信息函数
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
			cout << "请输入学生序号:";
			cin >> p->id;
			bool right = 1;
			for (int i = 0; p->id[i] != 0; ++i) {
				if (p->id[i] >= '0'&&p->id[i] <= '9'&&i < 10) {
				}
				else {
					cout << "输入有误，请重新输入" << endl;
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
					cout << "输入错误，学号与“" << s->name << "”重复，请重新输入。" << endl;
					right = 0;
					break;
				}
			}
			if (right) break;
		}
	}
	else if(item == 2){
		while (1) {
			cout << "请输入学生姓名:";
			cin >> p->name;
			bool right = 1;
			for (int i = 0; p->name[i] != 0; ++i) {
				if (i >= 20) {
					right = 0;
					cout << "输入有误，请重新输入" << endl;
					break;
				}
			}
			if (right) break;
		}
	}
	else if (item == 3) {
		while (1) {
			cout << "请输入学生性别:";
			cin >> p->sex;
			bool right = 1;
			//cout << strcmp(p->sex, "男") << " " << strcmp(p->sex, "女") << endl;
			if (strcmp(p->sex,"男") && strcmp(p->sex,"女")) {
				right = 0;
				cout << "输入有误，请重新输入";
			}
			if (right) break;
		}
	}
	else if(item==4){
		while(1){
			cout<<"请输入数学成绩(0~100):";
			cin >> p->math;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"输入类型错误，请重新输入"<<endl;
			}else{
				if(p->math<0||p->math>100){
					right=0;
					cout<<"数据范围错误，请重新输入"<<endl;
				}
			}
			if (right) {
				p->aver = (p->math + p->eng + p->cs) / 3.0 + 1e-6;
				break;
			}
			
		}
	}else if(item==5){
		while(1){
			cout<<"请输入英语成绩(0~100):";
			cin>>p->eng;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"输入类型错误，请重新输入"<<endl;
			}else{
				if(p->eng<0||p->eng>100){
					right=0;
					cout<<"数据范围错误，请重新输入"<<endl;
				}
			}
			if (right) {
				p->aver = (p->math + p->eng + p->cs) / 3.0 + 1e-6;
				break;
			}
		}
	}else if(item==6){
		while(1){
			cout<<"请输入计算机成绩(0~100):";
			cin>>p->cs;
			bool right=1;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024,'\n');
				right=0;
				cout<<"输入类型错误，请重新输入"<<endl;
			}else{
				if(p->cs<0||p->cs>100){
					right=0;
					cout<<"数据范围错误，请重新输入"<<endl;
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
				cout << "查询结果为:" << endl;
				cout << setw(10) << "学号\t";
				cout << "姓名\t";
				cout << "性别\t";
				cout << "数学\t";
				cout << "英语\t";
				cout << "计算机\t";
				cout << "平均分";
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
					cout << "查询结果为:" << endl;
					cout << setw(10) << "学号\t";
					cout << "姓名\t";
					cout << "性别\t";
					cout << "数学\t";
					cout << "英语\t";
					cout << "计算机\t";
					cout << "平均分";
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

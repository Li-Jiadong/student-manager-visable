/*
 * iofun.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *      ������Ϣ
 */

#ifndef IOFUNC_H_
#define IOFUNC_H_
fstream datas;
char sourse[100];
bool getfromdata(){
	datas.open("data.stu",ios::in);
	if(datas.fail()){
		datas.close();
		return 0;
	}
	if(datas.peek() == EOF){
		datas.close();
		return 0;
	}
	//data>>num;
//	for(int i=0;i<num;++i){
//		student *s=new student();
//		data>>*s;
//		tail->next=s;
//		tail=s;
//		tail->next=0;
//	}
	while(!datas.eof()){
		student *s=new student();
		datas>>s->id;
		//cout<<"bb"<<endl;
		if(!datas.fail()){
			datas>>s->name>>s->sex;
			datas>>s->math>>s->eng>>s->cs;
			datas>>s->aver;
			tail->next=s;
			s->before=tail;
			tail=s;
			tail->next=0;
			//cout<<tail->next;
			++num;
		}else{
//			cout<<"aa"<<endl;
			datas.clear();
			datas.ignore(1024,'\n');
			delete s;
		}

	}
	datas.close();
	return 1;
}
bool save(){
	datas.open("data.stu",ios::out);
	student *p=head;
	//data<<num<<endl;
	while(p->next!=0){
		p=p->next;
		datas<<*p<<endl;
	}
	datas.close();
	return 1;
}
bool saveas(int cmd){
	cout << "�������ļ���:";
	cin >> sourse;
	if (cmd == 1) {
		strcat_s(sourse, ".txt");
	}
	else if (cmd == 2) {
		strcat_s(sourse, ".xls");
	}
	fstream des;
	des.open(sourse,ios::out);
	if(des.fail()){
		return 0;
	}
	student *p=head;
	if (cmd == 1) {
		des << setw(10) << "ѧ��\t";
		des << "����\t";
		des << "�Ա�\t";
		des << "��ѧ\t";
		des << "Ӣ��\t";
		des << "�����\t";
		des << "ƽ����";
		des << endl;
		while(p->next!=0){
				p=p->next;
				des<<*p<<endl;
		}
		cout << "�ѱ��桰" << sourse << "���ļ���" << endl;
		system("pause");
	}
	else if (cmd == 2) {
		des << "ѧ��\t";
		des << "����\t";
		des << "�Ա�\t";
		des << "��ѧ\t";
		des << "Ӣ��\t";
		des << "�����\t";
		des << "ƽ����";
		des << endl;
		while (p->next != 0) {
			p = p->next;
			des << p->id << "\t"<< p->name << "\t";
			des << p->sex << "\t" << fixed << setprecision(1) << p->math << "\t" << fixed << setprecision(1) << p->eng << "\t" << fixed << setprecision(1) << p->cs << "\t";
			des << fixed << setprecision(1) << p->aver << endl;
		}
		cout << "�ѱ��桰" << sourse << "���ļ���" << endl;
		system("pause");
	}
	
	des.close();
	cin.ignore(1024,'\n');
	return 1;
}
bool strcmd(char *a,char *b,int n){
	char cmd[11];
	for(int i=0;i<n;++i){
		cmd[i]=a[i];
	}
	cmd[n]=0;
	return strcmp(cmd,b);
}
void quit() {
	save();
	exit(0);
}

#endif /* IOFUNC_H_ */

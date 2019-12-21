/*
 * iofun.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *      输入信息
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
	cout << "请输入文件名:";
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
		des << setw(10) << "学号\t";
		des << "姓名\t";
		des << "性别\t";
		des << "数学\t";
		des << "英语\t";
		des << "计算机\t";
		des << "平均分";
		des << endl;
		while(p->next!=0){
				p=p->next;
				des<<*p<<endl;
		}
		cout << "已保存“" << sourse << "”文件。" << endl;
		system("pause");
	}
	else if (cmd == 2) {
		des << "学号\t";
		des << "姓名\t";
		des << "性别\t";
		des << "数学\t";
		des << "英语\t";
		des << "计算机\t";
		des << "平均分";
		des << endl;
		while (p->next != 0) {
			p = p->next;
			des << p->id << "\t"<< p->name << "\t";
			des << p->sex << "\t" << fixed << setprecision(1) << p->math << "\t" << fixed << setprecision(1) << p->eng << "\t" << fixed << setprecision(1) << p->cs << "\t";
			des << fixed << setprecision(1) << p->aver << endl;
		}
		cout << "已保存“" << sourse << "”文件。" << endl;
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

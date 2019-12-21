/*ѧ����Ϣ
 * student.h
 *
 *  Created on: Dec 12, 2019
 *      Author: foxfish
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_
struct student{
	char id[12];//
	char name[22];
	char sex[3];//
	float math,eng,cs;
	float aver;//
	student *next;
	student *before;

	friend bool operator < (student a,student b){
		return a.aver<b.aver;
	}
	friend ifstream& operator >>(ifstream &fin,student *s){
		fin>>s->id>>s->name>>s->sex>>s->math>>s->eng>>s->cs>>s->aver;
		return fin;
	}
	friend istream& operator >>(istream &in,student &s){
		in>>s.id>>s.name>>s.sex>>s.math>>s.eng>>s.cs;
		s.aver=(s.math+s.eng+s.cs)/3+1e-6;
		return in;
	}
	friend ostream& operator <<(ostream &out,student &s){
		out<<setw(10)<<s.id<<"\t"<<s.name<<"\t";
		out<<s.sex<<"\t" << fixed << setprecision(1) <<s.math<<"\t" << fixed << setprecision(1) <<s.eng<<"\t" << fixed << setprecision(1) <<s.cs<<"\t";
		out << fixed << setprecision(1) <<s.aver;
		return out;
	}
	friend ofstream& operator <<(ofstream &out,student &s){
		out<<setw(10)<<s.id<<"\t"<<s.name<<"\t";
		out<<s.sex<<"\t" << fixed << setprecision(1) <<s.math<<"\t" << fixed << setprecision(1) <<s.eng<<"\t" << fixed << setprecision(1) <<s.cs<<"\t";
		out << fixed << setprecision(1) <<s.aver;
		return out;
	}
};

void title(){
	cout<<"���\t";
	cout << setw(10) << "ѧ��\t";
	cout<<"����\t";
	cout<<"�Ա�\t";
	cout<<"��ѧ\t";
	cout<<"Ӣ��\t";
	cout<<"�����\t";
	cout<<"ƽ����";
	cout<<endl;
}
#endif /* STUDENT_H_ */

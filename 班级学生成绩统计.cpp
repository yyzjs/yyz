#include<stdio.h>
#include<stdlib.h>
struct student{
	char name[30];
	char num[30];
	int M;
	int E;
	int CX;
	int LS;
	float credit;
	double GD;
	int p1;
	int p2;
	int p3;
}student[50];
int n;
void Mm(int  *x,int *y,int *z,int *c,struct student[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*x<student[i].M)
		{
			*x=student[i].M;
			*z=i;
		}
		if(*y>student[i].M)
		{
			*y=student[i].M;
			*c=i;
		}
	}
}
void Em(int *x,int *y,int *z,int *c,struct student[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*x<student[i].E)
		{
			*x=student[i].E;
			*z=i;
		}
		if(*y>student[i].E)
		{
			*y=student[i].E;
			*c=i;
		}
	}
}
void Cm(int *x,int *y,int *z,int *c,struct student[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*x<student[i].CX)
		{
			*x=student[i].CX;
			*z=i;
		}
		if(*y>student[i].CX)
		{
			*y=student[i].CX;
			*c=i;
		}
	}
}
void Lm(int *x,int *y,int *z,int *c,struct student[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*x<student[i].LS)
		{
			*x=student[i].LS;
			*z=i;
		}
		if(*y>student[i].LS)
		{
			*y=student[i].LS;
			*c=i;
		}
	}
}
int credit(struct student[],int i)
{
	student[i].credit=0;
	if(student[i].M>=60)
	{
		student[i].credit+=5.5;
	}
	if(student[i].E>=60)
	{
	student[i].credit+=4;
	}
	if(student[i].CX>=60)
	{
		student[i].credit+=3;
	}
	if(student[i].LS>=60)
	{
		student[i].credit+=4;
	}
	return student[i].credit;
}
double GC(struct student[],int i)
{
	double a=2,b=2,c=2,d=2;
	student[i].GD=0;
	if(student[i].M>=60)
		{
		for(int g=0;g<student[i].M-60;g++)
		{
			a+=0.2;
		}
	}
	else
	{
		a=0;
	}
	a=a*5.5;
	if(student[i].E>=60)
			{
		for(int g=0;g<student[i].E-60;g++)
		{
			b+=0.2;
		}
	}
	else 
	{
		b=0;
	}
	b=b*4;
	if(student[i].CX>=60)
			{
		for(int g=0;g<student[i].CX-60;g++)
		{
			c+=0.2;
		}
	}
		else
		{
			c=0;
	}
	c=c*3;
	if(student[i].LS)
			{
		for(int g=0;g<student[i].LS-60;g++)
		{
			d+=0.2;
		}
	}
		else
		{
			d=0;
	}
	d=d*4;
	student[i].GD=(a+b+c+d)/16.5;
	return student[i].GD;
}
void smile(struct student[],int i)
{
	if(student[i].GD>9)
		printf("����\n");
	else if(student[i].GD>7)
		printf("����\n");
	else if(student[i].GD>5)
		printf("�е�\n");
	else if(student[i].GD>3)
		printf("�ϸ�\n");
	else
		printf("���ϸ�\n");
}
void fun(struct student[],int i)
{
	if(student[i].GD>=9)
	{
		if(student[i].credit==16.5)
		{
			printf("%sͬѧ����ۺ�һ�Ƚ�\n",student[i].name);
			student[0].p1++;
		}
		else
		{
			printf("%sͬѧ����ۺ����Ƚ�\n",student[i].name);
			student[0].p3++;
		}
	}
	else if(student[i].GD>=7)
	{
		if(student[i].credit==16.5)
		{
			printf("%sͬѧ����ۺ϶��Ƚ�\n",student[i].name);
			student[0].p2++;
		}
	}
}
double M(struct student[])
{
	int i=0;
	double a=0;
	for(i=0;i<n;i++)
	{
		a+=student[i].M;
	}
	a=a/n;
	return a;
}
double E(struct student[])
{
	int i=0;
	double a=0;
	for(i=0;i<n;i++)
	{
		a+=student[i].E;
	}
	a=a/n;
	return a;
}
	double CX(struct student[])
{
	int i=0;
	double a=0;
	for(i=0;i<n;i++)
	{
		a+=student[i].CX;
	}
	a=a/n;
	return a;
}
	double LS(struct student[])
{
	int i=0;
	double a=0;
	for(i=0;i<n;i++)
	{
		a+=student[i].LS;
	}
	a=a/n;
	return a;
}
int main()
{
	int i;
	student[0].p1=student[0].p2=student[0].p3=0;
	printf("������ѧ������\n");
	scanf("%d",&n);
	printf("���� ѧ�� ���� Ӣ�� ���� ��ɢ\n");
	for(i=0;i<n;i++)
	{
		scanf("%s %s %d %d %d %d",student[i].name,student[i].num,&student[i].M,&student[i].E,&student[i].CX,&student[i].LS);
	 credit(student,i);
	}
	int Mmax=0,Mmin=1000,mi=0,mg=0;
	int *mx,*my,*mz,*mc;
	mz=&mi,mc=&mg;
	mx=&Mmax,my=&Mmin;
	Mm(mx,my,mz,mc,student);
	printf("������߷�Ϊ%d %sͬѧ\n",Mmax,student[mi].name);
	printf("������ͷ�Ϊ%d %sͬѧ\n",Mmin,student[mg].name);
	printf("\n");
	int Emax=0,Emin=1000,ei=0,eg=0;
	int *ex,*ey,*ez,*ec;
	ez=&ei,ec=&eg;
	ex=&Emax,ey=&Emin;
	Em(ex,ey,ez,ec,student);
	printf("Ӣ����߷�Ϊ%d %sͬѧ\n",Emax,student[ei].name);
	printf("Ӣ����ͷ�Ϊ%d %sͬѧ\n",Emin,student[eg].name);
	printf("\n");
	int Cmax=0,Cmin=1000,ci=0,cg=0;
	int *cx,*cy,*cz,*cc;
	cz=&ci,cc=&cg;
	cx=&Cmax,cy=&Cmin;
	Cm(cx,cy,cz,cc,student);
	printf("������߷�Ϊ%d %sͬѧ\n",Emax,student[ci].name);
	printf("������ͷ�Ϊ%d %sͬѧ\n",Emin,student[cg].name);
	printf("\n");
	int Lmax=0,Lmin=1000,li=0,lg=0;
	int *lx,*ly,*lz,*lc;
	lz=&li,lc=&lg;
	lx=&Lmax,ly=&Lmin;
	Lm(lx,ly,lz,lc,student);
	printf("��ɢ��߷�Ϊ%d %sͬѧ\n",Lmax,student[li].name);
	printf("��ɢ��ͷ�Ϊ%d %sͬѧ\n",Lmin,student[lg].name);
	printf("\n");
	printf("��ƽ��ѧ�ּ���Ϊ10,>9Ϊ����,<9&&>7Ϊ����,<7&&>5Ϊ�е�,<5&&>3Ϊ�ϸ�<3���ϸ�\n");
for(int i=0;i<n;i++)
{
	GC(student,i);
	printf("%sͬѧ��ƽ��ѧ�ּ���Ϊ%g\n",student[i].name,GC(student,i));
	 smile(student,i);
	 fun(student,i);
}
printf("����ƽ����Ϊ%g\n",M(student));
printf("Ӣ��ƽ����Ϊ%g\n",E(student));
printf("����ƽ����Ϊ%g\n",CX(student));
printf("��ɢƽ����Ϊ%g\n",LS(student));
	system("pause");
	return 0;
}


#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
		char name[20],pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStok Guncellendi.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nYetersiz Stok";
	    getch();
		
	
}

void stock::refil(int qty)
{
	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
		
	
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{
	cin>>name>>pr>>quant;
	/*cout<<"\n\nEnter the password letter by letter\n";
	
	for(int z=0;z<5;z++)
	{
		
		cin>>pass[z];
		system("cls");
		cout<<"\n\nEnter the password letter by letter\n";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass,"hello")==0)
	{
    cout<<"\nCongrats!!Access Granted!!\n\n";
	cout<<"\nEnter the Name followed By the price and then by the quantity\n"; 	
	cin>>name>>pr>>quant;
}
	else
	cout<<"Access Denied!!";*/
}
void stock::get2()
{
	cin>>name>>quant;
}

void stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void addnew()
{
 //   cout<<"\n\n\nCongrats!!Access Granted!!\n\n";

    system("cls");
	//cout<<"\nEnter the Name followed By the price and then by the quantity\n"; 	
	disp();
	getch();
	system("cls");
	
	cout<<"\nBu Urunden Kac Tane Eklemek Istediginizi Girin: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{
	    /*if(i==0)	
		{
		system("cls");
	}*/
		cout<<"\n\n Urun adi, fiyat ve miktar girin\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nUrun Guncellendi";
		cin.get();


    }
    cout<<"\n\nStok Guncellendi!!";
    

    fout.close();
    cin.get();
    system("cls");
    disp();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nHiçbir Urun Eklenmedi";

}
}




void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     
    
     if(i!=1)
       cout<<"\n\n!!Kayit Bulunamadi!!";
     fio.close();
    cin.get();
    system("cls");
	 disp(); 
	getch();
}
void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tSTOKTAKILER\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nIsim \tUrun Sayisi \t\t\t Fiyat";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Bos Kayit Odasi!!";
	getch();
     }
     fin.close();
    
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nUrun Adini Girin \n"<<endl;
	cin>>temp;
	cout<<"\n\nMiktari Girin: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Kayit Bulunamadi!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();
    
	
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tKaydi Silin";
     cout<<"\n\nUrunun Adini Girin:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tKayit Silindi";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Kayit Bulunamadi!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}
int main()
{
	char pass[10],pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ HOSGELDIN TANKUT TODA ============|";
	getch();
	system("cls");
	cout<<"\n\t\t   STOK KAYDI\n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Tankut Stok  \n\n\t\t ";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nSeciminizi Girin 1:";
	cin>>j;
	if(j==1)
	{
	
	system("cls");
	/*disp();
	
	cout<<"\n\n\n\nEnter the No. of Products that you wish to add: ";
    cin>>n;*/
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t Sifre: ";
	
	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t Sifre: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass,"927468")==1)
	{
    /*cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    getch();*/
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    Urunler MENU\n1. Yeni Urun Ekle \n2. Stoktakileri Goruntule \n3. Tekrar Duzenle \n4. Urunn Sil\n5. Cikis:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Menu Sec :\t";
	cin>>i;
	if(i==1)
	{
		addnew();getch();
	goto dealermenu;
	}

	else if(i==2)
	{
		system("cls");
	disp();getch();goto dealermenu;
	}
	else if(i==3)
	{
		refill();goto dealermenu;
	}
	else if(i==4)
	{
		remove();getch();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tHoscakal";
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\n\nYetkili Degilsiniz\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	exit(0);
}
	}

	getch();
	
}

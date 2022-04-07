#pragma once
#include <windows.h>
class Figura;
class Kwadrat;
int szach(Kwadrat(&stangry)[64], int from, int to, int kolor);
int mat(Kwadrat(&stangry)[64], int kolor);
class Kwadrat
{
private:
	int x;
	int y;
	int nr;

public:
	Kwadrat()
	{
		Figuranapolu = NULL; 
		dozwolenie = 0;
		kolor = 0;
		nr = 0;
		x = 0;
		y = 0;
		obszar.left = 0;
		obszar.top =0;
		obszar.right = 0;
		obszar.bottom = 0;
	}
	void Wczytaj_Dane(int i,int width,int height)
	{
		nr = i;
		x = i%8;
		y = i/8;
		kolor = (x + y) % 2;
		obszar.left = x * width / 8;
		obszar.top = y * height / 8;
		obszar.right = (x + 1) * width / 8;
		obszar.bottom = (y + 1) * height / 8;
		
	}
RECT obszar;
int kolor;
Figura* Figuranapolu;
int dozwolenie;
};
 class Figura
{
public:

	virtual int get_typ() = 0;
	virtual int get_kolor() = 0;
	virtual void zasieg(int pos, Kwadrat(&tablica)[64] )= 0;
};
class Wie¿a:public Figura
{
public:
	static const int typfigury = 2;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	 int get_kolor()  { return  kolor; } 
	 void zasieg(int pos,Kwadrat(&tablica)[64])
	 {
		 int x =pos % 8;
		 int y = pos / 8;
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + y * 8;
			 if (x+j>7){break;}
			 if (tablica[b].Figuranapolu==NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor()!=kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else{break;}
		 }
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + y * 8;
			 if (x - j <0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 } for (int j = 1; j < 8; j++)
		 {
			 int b = x + (y+j) * 8;
			 if (y + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL )
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() !=kolor && szach(tablica, pos, b, kolor)==0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 } for (int j = 1; j < 8; j++)
		 {
			 int b = x + (y - j) * 8;
			 if (y - j <0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) ==0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }

	 }
	 Wie¿a(int k)
	 {
		 kolor = k;
	 }
private:

};
class Pion :public Figura
{
public:
	static const int typfigury = 1;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	 int get_kolor() { return  kolor; }
	 void zasieg(int pos, Kwadrat(&tablica)[64])
	 {
		 int x = pos % 8;
		 int y = pos / 8;
		 if (kolor == 1)
		 {
			 if (tablica[x + (y + 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + (y + 1) * 8, kolor) == 0)
				 {
					 tablica[x + (y + 1) * 8].dozwolenie = 1;
				 }
				 if (y == 1 && tablica[x + (y + 2) * 8].Figuranapolu == NULL&& szach(tablica, pos, x + (y + 2) * 8, kolor) == 0)
				 {
					 tablica[x + (y + 2) * 8].dozwolenie = 1;
				 }
			 } 

			 if (x+1<8)
			 {
				 if (tablica[x + 1 + (y + 1) * 8].Figuranapolu != NULL &&szach(tablica, pos, x + 1 + (y + 1) * 8, kolor) == 0)
				 {
					 if (tablica[x + 1 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor)
					 {
						 tablica[x + 1 + (y + 1) * 8].dozwolenie = 1;
					 }
				 }
			 }
			 if (x-1>-1)
			 {
				 if (tablica[x - 1 + (y + 1) * 8].Figuranapolu != NULL && szach(tablica, pos, x - 1 + (y + 1) * 8, kolor) == 0)
				 {
					 if (tablica[x - 1 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor)
					 {
						 tablica[x - 1 + (y + 1) * 8].dozwolenie = 1;
					 }
				 }
			 }
		 }
		 if (kolor == -1)
		 {
			 if (tablica[x + (y - 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + (y - 1) * 8, kolor) == 0)
				 {
					 tablica[x + (y - 1) * 8].dozwolenie = 1;
				 }
				 if (y == 6 && tablica[x + (y - 2) * 8].Figuranapolu == NULL && szach(tablica, pos, x + (y - 2) * 8, kolor) == 0)
				 {
					 tablica[x + (y - 2) * 8].dozwolenie = 1;
				 }
			 }

			 if (x + 1 < 8)
			 {
				 if (tablica[x + 1 + (y - 1) * 8].Figuranapolu != NULL && szach(tablica, pos, x + 1 + (y - 1) * 8, kolor) == 0)
				 {
					 if (tablica[x + 1 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor)
					 {
						 tablica[x + 1 + (y - 1) * 8].dozwolenie = 1;
					 }
				 }
			 }
			 if (x - 1 > -1)
			 {
				 if (tablica[x - 1 + (y - 1) * 8].Figuranapolu != NULL && szach(tablica, pos, x - 1 + (y - 1) * 8, kolor) == 0)
				 {
					 if (tablica[x - 1 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor)
					 {
						 tablica[x - 1 + (y - 1) * 8].dozwolenie = 1;
					 }
				 }
			 }
		 }




	 }
	Pion(int k)
	{
		kolor = k;
	}
private:

};
class Koñ :public Figura
{
public:
	static const int typfigury = 4;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	int get_kolor() { return  kolor; }
	void zasieg(int pos, Kwadrat(&tablica)[64])
	{
		int x = pos % 8;
		int y = pos / 8;

		if (x + 2 < 8)
		{
			if (y + 1 < 8)
			{
				if (tablica[x + 2 + (y + 1) * 8].Figuranapolu == NULL || tablica[x + 2 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor)
				{
					if (szach(tablica, pos, x + 2 + (y + 1) * 8, kolor) == 0)
					{
						tablica[x + 2 + (y + 1) * 8].dozwolenie = 1;
					}
				}
			}
			if (y - 1 > -1)
			{
				if (tablica[x + 2 + (y - 1) * 8].Figuranapolu == NULL || tablica[x + 2 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor)
				{
					if (szach(tablica, pos, x + 2 + (y - 1) * 8, kolor) == 0)
					{
						tablica[x + 2 + (y - 1) * 8].dozwolenie = 1;
					}
				}
			}
		}
		if (x - 2 > -1)
		{
			if (y + 1 < 8)
			{
				if (tablica[x - 2 + (y + 1) * 8].Figuranapolu == NULL || tablica[x - 2 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor)
				{
					if (szach(tablica, pos, x - 2 + (y + 1) * 8, kolor) == 0)
					{
						tablica[x - 2 + (y + 1) * 8].dozwolenie = 1;
					}
				}
			}
			if (y - 1 > -1)
			{
				if (tablica[x - 2 + (y - 1) * 8].Figuranapolu == NULL || tablica[x - 2 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor)
				{
					if (szach(tablica, pos, x - 2 + (y - 1) * 8, kolor) == 0)
					{
						tablica[x - 2 + (y - 1) * 8].dozwolenie = 1;
					}
				}
			}
		}
	
	if (y + 2 < 8)
	{
		if (x + 1 < 8)
		{
			if (tablica[x + 1 + (y + 2) * 8].Figuranapolu == NULL || tablica[x + 1 + (y + 2) * 8].Figuranapolu->get_kolor() != kolor)
			{
				if (szach(tablica, pos, x + 1 + (y + 2) * 8, kolor) == 0)
				{
					tablica[x + 1 + (y + 2) * 8].dozwolenie = 1;
				}
			}
		}
		if (x - 1 > -1)
		{
			if (tablica[x - 1 + (y + 2) * 8].Figuranapolu == NULL || tablica[x - 1 + (y + 2) * 8].Figuranapolu->get_kolor() != kolor)
			{
				if (szach(tablica, pos, x - 1 + (y + 2) * 8, kolor) == 0)
				{
					tablica[x - 1 + (y + 2) * 8].dozwolenie = 1;
				}
			}
		}
	}

if (y - 2 > -1)
{
	if (x + 1 < 8)
	{
		if (tablica[x + 1 + (y - 2) * 8].Figuranapolu == NULL || tablica[x + 1 + (y - 2) * 8].Figuranapolu->get_kolor() != kolor)
		{
			if (szach(tablica, pos, x + 1 + (y - 2) * 8, kolor) == 0)
			{
				tablica[x + 1 + (y - 2) * 8].dozwolenie = 1;
			}
		}
	}
	if (x - 1 > -1)
	{
		if (tablica[x - 1 + (y - 2) * 8].Figuranapolu == NULL || tablica[x - 1 + (y - 2) * 8].Figuranapolu->get_kolor() != kolor)
		{
			if (szach(tablica, pos, x - 1 + (y - 2) * 8, kolor) == 0)
			{
				tablica[x - 1 + (y - 2) * 8].dozwolenie = 1;
			}
		}
	}
}
	 }
	Koñ(int k)
	{
		kolor = k;
	}
private:

};
class Goniec :public Figura
{
public:
	static const int typfigury = 3;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	 int get_kolor() { return  kolor; }
	 void zasieg(int pos,Kwadrat(&tablica)[64])
	 {
		 int x = pos % 8;
		 int y = pos / 8;
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + (y + j) * 8;
			 if (x + j > 7 ) { break; }
			 if ( y + j > 7) { break; }
			 if (tablica[b].Figuranapolu==NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
				 
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
		
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + (y + j) * 8;
			 if (x - j < 0 ) { break; }
			 if ( y + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
		 
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + (y - j) * 8;
			 if (x + j > 7 ) { break; }
			 if ( y - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
		 
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + (y - j) * 8;
			 if (x - j <0 ) { break; }
			 if ( y - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
	  }
	Goniec(int k)
	{
		kolor = k;
	}
private:

};
class Królowa :public Figura
{
public:
	static const int typfigury = 5;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	 int get_kolor() { return  kolor; }
	 void zasieg(int pos, Kwadrat(&tablica)[64])
	 {
		 int x = pos % 8;
		 int y = pos / 8;
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + (y + j) * 8;
			 if (x + j > 7) { break; }
			 if (y + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }

		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + (y + j) * 8;
			 if (x - j < 0) { break; }
			 if (y + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }

		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + (y - j) * 8;
			 if (x + j > 7) { break; }
			 if (y - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }

		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + (y - j) * 8;
			 if (x - j < 0) { break; }
			 if (y - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x + j + y * 8;
			 if (x + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }
		 for (int j = 1; j < 8; j++)
		 {
			 int b = x - j + y * 8;
			 if (x - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 } for (int j = 1; j < 8; j++)
		 {
			 int b = x + (y + j) * 8;
			 if (y + j > 7) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 } for (int j = 1; j < 8; j++)
		 {
			 int b = x + (y - j) * 8;
			 if (y - j < 0) { break; }
			 if (tablica[b].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, b, kolor) == 0)
				 {
					 tablica[b].dozwolenie = 1;
				 }
			 }
			 else if (tablica[b].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, b, kolor) == 0)
			 {
				 tablica[b].dozwolenie = 1;
				 break;
			 }
			 else { break; }
		 }

	 }
	Królowa(int k)
	{
		kolor = k;
	}
private:

};
class Król :public Figura
{
public:
	static const int typfigury = 6;
	int kolor;
	int get_typ() { return typfigury * kolor; }
	 int get_kolor() { return  kolor; }
	 void zasieg(int pos, Kwadrat(&tablica)[64])
	 {
		 int x = pos % 8;
		 int y = pos / 8;
		 if (x + 1 < 8)
		 {
			 if (tablica[x + 1 + y * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + 1 + y * 8, kolor) == 0)
				 {
					 tablica[x + 1 + y * 8].dozwolenie = 1;
				 }

			 }
			 else if (tablica[x + 1 + y * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x + 1 + y * 8, kolor) == 0)
			 {
				 tablica[x + 1 + y * 8].dozwolenie = 1;
			 }
		 }
		 if (x - 1 > -1)
		 {
			 if (tablica[x - 1 + y * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x - 1 + y * 8, kolor) == 0)
				 {
					 tablica[x - 1 + y * 8].dozwolenie = 1;
				 }

			 }
			 else if (tablica[x - 1 + y * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x - 1 + y * 8, kolor) == 0)
			 {
				 tablica[x - 1 + y * 8].dozwolenie = 1;
			 }
		 }
		 if (y + 1 < 8)
		 {
			 if (tablica[x + (y + 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + (y + 1) * 8, kolor) == 0)
				 {
					 tablica[x + (y + 1) * 8].dozwolenie = 1;
				 }
			 }
			 else if (tablica[x + (y + 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x + (y + 1) * 8, kolor) == 0)
			 {
				 tablica[x + (y + 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (y - 1 > -1)
		 {
			 if (tablica[x + (y - 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + (y - 1) * 8, kolor) == 0)
				 {
					 tablica[x + (y - 1) * 8].dozwolenie = 1;
				 }
			 }
			 else if (tablica[x + (y - 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x + (y - 1) * 8, kolor) == 0)
			 {
				 tablica[x + (y - 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (x + 1 < 8 && y + 1 < 8)
		 {
			 if (tablica[x + 1 + (y + 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + 1 + (y + 1) * 8, kolor) == 0)
				 {
					 tablica[x + 1 + (y + 1) * 8].dozwolenie = 1;
				 }
			 }
			 else if (tablica[x + 1 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x + 1 + (y + 1) * 8, kolor) == 0)
			 {
				 tablica[x + 1 + (y + 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (x - 1 > -1 && y + 1 < 8)
		 {
			 if (tablica[x - 1 + (y + 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x - 1 + (y + 1) * 8, kolor) == 0)
				 {
					 tablica[x - 1 + (y + 1) * 8].dozwolenie = 1;
				 }
			 }
			 else if (tablica[x - 1 + (y + 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x - 1 + (y + 1) * 8, kolor) == 0)
			 {
				 tablica[x - 1 + (y + 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (x - 1 > -1 && y - 1 > -1)
		 {
			 if (tablica[x - 1 + (y - 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x - 1 + (y - 1) * 8, kolor) == 0)
				 {
					 tablica[x - 1 + (y - 1) * 8].dozwolenie = 1;
				 }

			 }
			 else if (tablica[x - 1 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x - 1 + (y - 1) * 8, kolor) == 0)
			 {
				 tablica[x - 1 + (y - 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (x + 1 < 8 && y - 1 > -1)
		 {
			 if (tablica[x + 1 + (y - 1) * 8].Figuranapolu == NULL)
			 {
				 if (szach(tablica, pos, x + 1 + (y - 1) * 8, kolor) == 0)
				 {
					 tablica[x + 1 + (y - 1) * 8].dozwolenie = 1;
				 }
			 }
			 else if (tablica[x + 1 + (y - 1) * 8].Figuranapolu->get_kolor() != kolor && szach(tablica, pos, x + 1 + (y - 1) * 8, kolor) == 0)
			 {
				 tablica[x + 1 + (y - 1) * 8].dozwolenie = 1;
			 }
		 }
		 if (szach(tablica, pos, 100, kolor)==0)
		 {


			 if (tablica[63].Figuranapolu != NULL && tablica[60].Figuranapolu != NULL && tablica[61].Figuranapolu == NULL && tablica[62].Figuranapolu == NULL)
			 {
				 if (tablica[63].Figuranapolu->get_typ() == -2 && tablica[60].Figuranapolu->get_typ() == -6 && szach(tablica, pos, 62, kolor) == 0)
				 {
					 tablica[62].dozwolenie = 1;
				 }
			 }
			 if (tablica[56].Figuranapolu != NULL && tablica[60].Figuranapolu != NULL && tablica[57].Figuranapolu == NULL && tablica[58].Figuranapolu == NULL && tablica[59].Figuranapolu == NULL)
			 {
				 if (tablica[56].Figuranapolu->get_typ() == -2 && tablica[60].Figuranapolu->get_typ() == -6 && szach(tablica, pos, 58, kolor) == 0)
				 {
					 tablica[58].dozwolenie = 1;
				 }
			 }
			 if (tablica[0].Figuranapolu != NULL && tablica[3].Figuranapolu != NULL && tablica[1].Figuranapolu == NULL && tablica[2].Figuranapolu == NULL && kolor == 1)
			 {
				 if (tablica[0].Figuranapolu->get_typ() == 2 && tablica[3].Figuranapolu->get_typ() == 6 && szach(tablica, pos, 1, kolor) == 0)
				 {
					 tablica[1].dozwolenie = 1;
				 }
			 }
			 if (tablica[7].Figuranapolu != NULL && tablica[3].Figuranapolu != NULL && tablica[6].Figuranapolu == NULL && tablica[5].Figuranapolu == NULL && tablica[4].Figuranapolu == NULL && kolor == 1)
			 {
				 if (tablica[7].Figuranapolu->get_typ() == 2 && tablica[3].Figuranapolu->get_typ() == 6 && szach(tablica, pos, 5, kolor) == 0)
				 {
					 tablica[5].dozwolenie = 1;
				 }
			 }
		 }
	 }
	Król(int k)
	{
		kolor = k;
	}
private:

};


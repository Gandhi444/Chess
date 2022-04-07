#include<windowsx.h>
#include <windows.h>
#include "Pieces.h"

int szach(Kwadrat (&stangry)[64],int from,int to,int kolor)
{
	Kwadrat tablica[64];
	for (int i = 0; i < 64; i++)
	{
		tablica[i] = stangry[i];
	}
	if (to < 64)
	{
		tablica[to].Figuranapolu = tablica[from].Figuranapolu;
		tablica[from].Figuranapolu = NULL;
	}
	int kingpos;
	int x=0;
    int y=0;
	int bufor = 0;
	for (int i = 0; i < 64; i++)
	{
		if (tablica[i].Figuranapolu != NULL)
		{


			if (tablica[i].Figuranapolu->get_typ() * kolor == 6)
			{
				kingpos = i;
				x = i % 8;
				y = i / 8;
				break;
			}
		}
	}
	
	for (int j = 1; j < 8; j++)
	{
		int b = x + j + y * 8;
		if (x + j > 7) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor == -2|| tablica[b].Figuranapolu->get_typ() * kolor==-5)
			{
				return 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
    for (int j = 1; j < 8; j++)
	{
		int b = x - j + y * 8;
		if (x - j < 0) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor ==- 2 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;
				break;

			}
			else
			{
				break;
			}
		
		}
	}
	 for (int j = 1; j < 8; j++)
	{
		int b = x + (y + j) * 8;
		if (y + j > 7) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor == -2 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;
				break;

			}
			else
			{
				break;
			}
		}
	}
	 for (int j = 1; j < 8; j++)
	{
		int b = x + (y - j) * 8;
		if (y - j < 0) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor ==- 2 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;
				break;

			}
			else
			{
				break;
			}
		}
	}
	

	for (int j = 1; j < 8; j++)
	{
		int b = x + j + (y + j) * 8;
		if (x + j > 7) { break; }
		if (y + j > 7) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() *kolor==-3 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;

			}
			else
			{
				break;
			}
		}
	}
	for (int j = 1; j < 8; j++)
	{
		int b = x - j + (y + j) * 8;
		if (x - j < 0) { break; }
		if (y + j > 7) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor == -3 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;

			}
			else
			{
				break;
			}
		}
	}

	for (int j = 1; j < 8; j++)
	{
		int b = x + j + (y - j) * 8;
		if (x + j > 7) { break; }
		if (y - j < 0) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor == -3 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;

			}
			else
			{
				break;
			}
		}
	}

	for (int j = 1; j < 8; j++)
	{
		int b = x - j + (y - j) * 8;
		if (x - j < 0) { break; }
		if (y - j < 0) { break; }
		if (tablica[b].Figuranapolu != NULL)
		{
			if (tablica[b].Figuranapolu->get_typ() * kolor == -3 || tablica[b].Figuranapolu->get_typ() * kolor == -5)
			{
				return 1;

			}
			else
			{
				break;
			}
		}
	}
	
	if (x + 2 < 8)
	{
		if (y + 1 < 8)
		{
			if (tablica[x + 2 + (y + 1) * 8].Figuranapolu != NULL)
			{


				if (tablica[x + 2 + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}
		}
		if (y - 1 > -1)
		{
			if (tablica[x + 2 + (y - 1) * 8].Figuranapolu != NULL)
			{


				if (tablica[x + 2 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
				return 1;
				}
			}
		}
	}
	if (x - 2 > -1)
	{
		if (y + 1 < 8)
		{
			if (tablica[x - 2 + (y + 1) * 8].Figuranapolu != NULL)
			{


				if (tablica[x - 2 + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}

		}
		if (y - 1 > -1)
		{
			if (tablica[x - 2 + (y - 1) * 8].Figuranapolu != NULL)
			{


				if (tablica[x - 2 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}

		}
	}

	if (y + 2 < 8)
	{
		if (x + 1 < 8)
		{
			if (tablica[x + 1 + (y + 2) * 8].Figuranapolu != NULL)
			{


				if (tablica[x + 1 + (y + 2) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}
		}
		if (x - 1 > -1)
		{
			if (tablica[x - 1 + (y + 2) * 8].Figuranapolu != NULL)
			{


				if (tablica[x - 1 + (y + 2) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}
		}
	}

	if (y - 2 > -1)
	{
		if (x + 1 < 8)
		{
			if (tablica[x + 1 + (y - 2) * 8].Figuranapolu != NULL)
			{


				if (tablica[x + 1 + (y - 2) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}
		}
		if (x - 1 > -1)
		{
			if (tablica[x - 1 + (y - 2) * 8].Figuranapolu != NULL)
			{


				if (tablica[x - 1 + (y - 2) * 8].Figuranapolu->get_typ() * kolor == -4)
				{
					return 1;
				}
			}
		}
	}
	if (kolor == -1)
	{
		if (y + 1 < 8)
		{
			if (x + 1 < 8)
			{
				if (tablica[x + 1 + (y - 1) * 8].Figuranapolu != NULL)
				{
					if (tablica[x + 1 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -1)
					{
						return 1;
					}
				}
			}
			if (x - 1 > -1)
			{
				if (tablica[x - 1 + (y - 1) * 8].Figuranapolu != NULL)
				{
					if (tablica[x - 1 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -1)
					{
						return 1;
					}
				}
			}
		}
	}
	else
	{
		if (y - 1 >-1)
		{
			if (x + 1 < 8)
			{
				if (tablica[x + 1 + (y + 1) * 8].Figuranapolu != NULL)
				{
					if (tablica[x + 1 + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -1)
					{
						return 1;
					}
				}
			}
			if (x - 1 > -1)
			{
				if (tablica[x - 1 + (y + 1) * 8].Figuranapolu != NULL)
				{
					if (tablica[x - 1 + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -1)
					{
						return 1;
					}
				}
			}
		}
	}
	if (x + 1 < 8)
	{
		if (tablica[x + 1 + y * 8].Figuranapolu != NULL)
		{
			if (tablica[x + 1 + y * 8].Figuranapolu->get_typ()*kolor==-6)
			{
				return 1;
			}
		}
	}
	if (x - 1 >-1)
	{
		if (tablica[x - 1 + y * 8].Figuranapolu != NULL)
		{
			if (tablica[x - 1 + y * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y - 1 >-1)
	{
		if (tablica[x + (y-1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x  + (y-1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y + 1 < 8)
	{
		if (tablica[x + (y + 1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y + 1 < 8 && x+1<8)
	{
		if (tablica[x + 1 + (y + 1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x +1+ (y + 1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y -1 >-1 && x + 1 < 8)
	{
		if (tablica[x + 1 + (y - 1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x + 1 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y - 1 > -1 && x - 1 >-1)
	{
		if (tablica[x - 1 + (y - 1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x - 1 + (y - 1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	if (y + 1 <8 && x - 1 > -1)
	{
		if (tablica[x - 1 + (y + 1) * 8].Figuranapolu != NULL)
		{
			if (tablica[x - 1 + (y + 1) * 8].Figuranapolu->get_typ() * kolor == -6)
			{
				return 1;
			}
		}
	}
	return 0;
};


int mat(Kwadrat(&stangry)[64],int kolor)
{
	Kwadrat tablica[64];
	for (int i = 0; i < 64; i++)
	{
		tablica[i] = stangry[i];
	}
	for (int i = 0; i < 64; i++)
	{
		if (tablica[i].Figuranapolu != NULL && tablica[i].Figuranapolu->get_kolor() == kolor)
		{
			tablica[i].Figuranapolu->zasieg(i, tablica);
		}

	}
	for (int i = 0; i < 64; i++)
	{
		if (tablica[i].dozwolenie == 1)
		{
			return 1;
		}

	}
	return 0;
}
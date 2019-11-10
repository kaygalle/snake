using System;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Timers;
using System.Diagnostics;
namespace Snake{
  class Programm{
    public static void Main(){
      int m=10;
      int x=0;
      int y=0;
      int t=0;// 1-Up 2-Down 3-Left 4-Right
      char [,] map = new char [m,m];
      while(true){
        fillmap(m,map,ref x,ref y);
        move(ref x,ref y,ref t,m);
        Thread.Sleep(200);
        Console.Clear();
        printmap(m,map);
        if(t==5){
          break;
        }
        }
    }
    public static void fillmap(int m,char [,] map,ref int x,ref int y){
      for(int i=0;i<m;i++){
        for(int z=0;z<m;z++){
          if(x==z&&i==y){
            map[i,z]='1';
          }else{
            map[i,z]='0';
          }
        }
        }
      }
    public static void printmap(int m,char [,] map){
      for(int i=0;i<m;i++){
        for(int z=0;z<m;z++){
          Console.Write(map[i,z]);
        }
        Console.WriteLine(" ");
        }
      }
    public static void move(ref int x,ref int y,ref int t,int m){
      if(Console.KeyAvailable){
        ConsoleKeyInfo direct=Console.ReadKey(true);
        if(direct.Key==ConsoleKey.UpArrow){
          if(y>0){
            y--;
            t=1;
          }
        }
        if(direct.Key==ConsoleKey.DownArrow){
          if(y<m-1){
            y++;
            t=2;
          }
        }
        if(direct.Key==ConsoleKey.LeftArrow){
          if(x>0){
            x--;
            t=3;
          }
        }
        if(direct.Key==ConsoleKey.RightArrow){
          if(x<m-1){
            x++;
            t=4;
          }
        }
        if(direct.Key==ConsoleKey.Escape){
          t=5;
        }
      }else{
        if(t==1&&y>0){
          y--;
        }else
        if(t==2&&y<m-1){
          y++;
        }else
        if(t==3&&x>0){
          x--;
        }else
        if(t==4&&x<m-1){
          x++;
        }else
        if(x<m-1&&y<m-1){
          x++;
        }
      }
    }
    }
}